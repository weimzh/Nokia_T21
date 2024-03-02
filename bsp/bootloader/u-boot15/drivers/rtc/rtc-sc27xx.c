/*
 * An RTC device/driver
 * Copyright (C) 2019 UNISOC Communication Inc
 * Author: Xiaopeng Bai<xiaopeng.bai@unisoc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <asm/types.h>
#include <common.h>
#include <rtc.h>
#include <power/pmic.h>
#include <dm/device.h>
#include <dm/read.h>
#include <dm/uclass-id.h>

/* reg addr offset */
#define SPRD_RTC_SEC_CNT_VAL          0x00
#define SPRD_RTC_MIN_CNT_VAL          0x04
#define SPRD_RTC_HOUR_CNT_VAL         0x08
#define SPRD_RTC_DAY_CNT_VAL          0x0c
#define SPRD_RTC_SEC_CNT_UPD          0x10
#define SPRD_RTC_MIN_CNT_UPD          0x14
#define SPRD_RTC_HOUR_CNT_UPD         0x18
#define SPRD_RTC_DAY_CNT_UPD          0x1c
#define SPRD_RTC_SEC_ALM_UPD          0x20
#define SPRD_RTC_MIN_ALM_UPD          0x24
#define SPRD_RTC_HOUR_ALM_UPD         0x28
#define SPRD_RTC_DAY_ALM_UPD          0x2c
#define SPRD_RTC_INT_EN               0x30
#define SPRD_RTC_INT_RAW_STS          0x34
#define SPRD_RTC_INT_CLR              0x38
#define SPRD_RTC_INT_MSK_STS          0x3c
#define SPRD_RTC_SEC_ALM_VAL          0x40
#define SPRD_RTC_MIN_ALM_VAL          0x44
#define SPRD_RTC_HOUR_ALM_VAL         0x48
#define SPRD_RTC_DAY_ALM_VAL          0x4c
#define SPRD_RTC_SPG_VAL              0x50
#define SPRD_RTC_SPG_UPD              0x54
#define SPRD_RTC_SEC_AUX_UPD          0x60
#define SPRD_RTC_MIN_AUX_UPD          0x64
#define SPRD_RTC_HOUR_AUX_UPD         0x68
#define SPRD_RTC_DAY_AUX_UPD          0x6c

/* bit offset */
#define SPRD_RTC_SEC_UPD_EN           BIT(8)
#define SPRD_RTC_MIN_UPD_EN           BIT(9)
#define SPRD_RTC_HOUR_UPD_EN          BIT(10)
#define SPRD_RTC_DAY_UPD_EN           BIT(11)
#define SPRD_RTC_ALMSEC_UPD_EN        BIT(12)
#define SPRD_RTC_ALMMIN_UPD_EN        BIT(13)
#define SPRD_RTC_ALMHOUR_UPD_EN       BIT(14)
#define SPRD_RTC_ALMDAY_UPD_EN        BIT(15)

#define SPRD_RTC_TIME_UPD_MASK (SPRD_RTC_SEC_UPD_EN | SPRD_RTC_MIN_UPD_EN   \
	| SPRD_RTC_HOUR_UPD_EN | SPRD_RTC_DAY_UPD_EN)

#define SPRD_RTC_ALM_UPD_MASK (SPRD_RTC_ALMSEC_UPD_EN | SPRD_RTC_ALMMIN_UPD_EN   \
	| SPRD_RTC_ALMHOUR_UPD_EN | SPRD_RTC_ALMDAY_UPD_EN)

#define SPRD_RTC_INT_ALL_MSK          0xffff

#define SPRD_RTC_SEC_VAL_MASK         0x3f
#define SPRD_RTC_MIN_VAL_MASK         0x3f
#define SPRD_RTC_HOUR_VAL_MASK        0x1f
#define SPRD_RTC_DAY_VAL_MASK         0xffff

#define SPRD_RTC_ALARM_INT            BIT(4)

#define SPRD_RTC_POWEROFF_ALARM       BIT(8)

/* Calculate the number of leap years (thru before y) by y */
#define LEAPS_THRU_EVER_BEFORE(y) ((y) / 4 - (y) / 100 + (y) / 400)

/* Whether it is a leap year */
#define IS_LEAP_YEAR(year)    ((!((year) % 4) && ((year) % 100)) || !((year) % 400))

enum sprd_rtc_type {
	SPRD_RTC_TIME,
	SPRD_RTC_ALARM,                  /* for power-off alarm */
	SPRD_RTC_AUX_ALARM,              /* for deep sleep alarm */
};

struct sprd_rtc {
	u32 rtc_base;
};

static const unsigned char rtc_days_in_month[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

static int sprd_rtc_get(struct udevice *rtc_dev, u32 offset, u32 *value)
{
	int ret;
	u32 reg;
	struct sprd_rtc *rtc_priv;
	struct udevice *pmic_dev = dev_get_parent(rtc_dev);

	rtc_priv = (struct sprd_rtc *)dev_get_priv(rtc_dev);
	if (rtc_priv == NULL)
		return -EINVAL;

	reg = rtc_priv->rtc_base + offset;

	ret = pmic_read(pmic_dev, reg, (uint8_t *)value, sizeof(u32));
	if (ret != 0)
		printf("uboot rtc get fail, ret is [%d]\n", ret);

	return ret;
}

static int sprd_rtc_set(struct udevice *rtc_dev, u32 offset, u32 value)
{
	int ret;
	u32 reg;
	struct sprd_rtc *rtc_priv;
	struct udevice *pmic_dev = dev_get_parent(rtc_dev);

	rtc_priv = (struct sprd_rtc *)dev_get_priv(rtc_dev);
	if (rtc_priv == NULL)
		return -EINVAL;

	reg = rtc_priv->rtc_base + offset;

	ret = pmic_write(pmic_dev, reg, (uint8_t *)&value, sizeof(u32));
	if (ret != 0)
		printf("uboot rtc set fail, ret is [%d]\n", ret);

	return ret;
}

static int sprd_rtc_get_secs(struct udevice *rtc_dev, enum sprd_rtc_type type,
			u32 *rtc_secs)
{
	int ret;
	u32 sec_reg, min_reg, hour_reg, day_reg;
	u32 sec, min, hour, day;

	switch (type) {
	case SPRD_RTC_TIME:
		sec_reg = SPRD_RTC_SEC_CNT_VAL;
		min_reg = SPRD_RTC_MIN_CNT_VAL;
		hour_reg = SPRD_RTC_HOUR_CNT_VAL;
		day_reg = SPRD_RTC_DAY_CNT_VAL;
		break;
	case SPRD_RTC_ALARM:
		sec_reg = SPRD_RTC_SEC_ALM_VAL;
		min_reg = SPRD_RTC_MIN_ALM_VAL;
		hour_reg = SPRD_RTC_HOUR_ALM_VAL;
		day_reg = SPRD_RTC_DAY_ALM_VAL;
		break;
	case SPRD_RTC_AUX_ALARM:
		sec_reg = SPRD_RTC_SEC_AUX_UPD;
		min_reg = SPRD_RTC_MIN_AUX_UPD;
		hour_reg = SPRD_RTC_HOUR_AUX_UPD;
		day_reg = SPRD_RTC_DAY_AUX_UPD;
		break;
	default:
		return -EINVAL;
	}

	ret = sprd_rtc_get(rtc_dev, sec_reg, &sec);
	if (ret != 0)
		return ret;

	sec &= SPRD_RTC_SEC_VAL_MASK;

	ret = sprd_rtc_get(rtc_dev, min_reg, &min);
	if (ret != 0)
		return ret;

	min &= SPRD_RTC_MIN_VAL_MASK;

	ret = sprd_rtc_get(rtc_dev, hour_reg, &hour);
	if (ret != 0)
		return ret;

	hour &= SPRD_RTC_HOUR_VAL_MASK;

	ret = sprd_rtc_get(rtc_dev, day_reg, &day);
	if (ret != 0)
		return ret;

	day &= SPRD_RTC_DAY_VAL_MASK;

	*rtc_secs = ((((day * 24) + hour) * 60 + min) * 60 + sec);

	return 0;
}

static int sprd_rtc_set_secs(struct udevice *rtc_dev, enum sprd_rtc_type type,
			u32 secs)
{
	int ret;
	u32 sec_reg, min_reg, hour_reg, day_reg;
	u32 sec, min, hour, day;
	u32 set_mask = 0, int_sts;
	u32 temp;
	u32 delay_us = 20000;
	int timeout_cnt = 10;

	sec = secs % 60;
	temp = (secs - sec) / 60;
	min = temp % 60;
	temp = (temp - min) / 60;
	hour = temp % 24;
	temp = (temp - hour) / 24;
	day = temp;

	switch (type) {
	case SPRD_RTC_TIME:
		sec_reg = SPRD_RTC_SEC_CNT_UPD;
		min_reg = SPRD_RTC_MIN_CNT_UPD;
		hour_reg = SPRD_RTC_HOUR_CNT_UPD;
		day_reg = SPRD_RTC_DAY_CNT_UPD;
		set_mask = SPRD_RTC_TIME_UPD_MASK;
		sprd_rtc_set(rtc_dev, SPRD_RTC_INT_CLR, SPRD_RTC_TIME_UPD_MASK);
		break;
	case SPRD_RTC_ALARM:
		sec_reg = SPRD_RTC_SEC_ALM_UPD;
		min_reg = SPRD_RTC_MIN_ALM_UPD;
		hour_reg = SPRD_RTC_HOUR_ALM_UPD;
		day_reg = SPRD_RTC_DAY_ALM_UPD;
		set_mask = SPRD_RTC_ALM_UPD_MASK;
		sprd_rtc_set(rtc_dev, SPRD_RTC_INT_CLR, SPRD_RTC_ALM_UPD_MASK);
		break;
	case SPRD_RTC_AUX_ALARM:
		sec_reg = SPRD_RTC_SEC_AUX_UPD;
		min_reg = SPRD_RTC_MIN_AUX_UPD;
		hour_reg = SPRD_RTC_HOUR_AUX_UPD;
		day_reg = SPRD_RTC_DAY_AUX_UPD;
		break;
	default:
		return -EINVAL;
	}

	ret = sprd_rtc_set(rtc_dev, sec_reg, sec);
	if (ret != 0)
		return ret;

	ret = sprd_rtc_set(rtc_dev, min_reg, min);
	if (ret != 0)
		return ret;

	ret = sprd_rtc_set(rtc_dev, hour_reg, hour);
	if (ret != 0)
		return ret;

	ret = sprd_rtc_set(rtc_dev, day_reg, day);
	if (ret != 0)
		return ret;

	if (type == SPRD_RTC_AUX_ALARM)
		return 0;

	/* Wait all setting update done */
	do {
		ret = sprd_rtc_get(rtc_dev, SPRD_RTC_INT_RAW_STS, &int_sts);
		if (ret != 0)
			return ret;

		int_sts &= set_mask;

		if (set_mask == int_sts)
			return sprd_rtc_set(rtc_dev, SPRD_RTC_INT_CLR, set_mask);

		udelay(delay_us);
	} while (--timeout_cnt);

	return -ETIMEDOUT;
}

static int sprd_rtc_reset(struct udevice *dev)
{
	sprd_rtc_set(dev, SPRD_RTC_INT_EN, 0);

	sprd_rtc_set_secs(dev, SPRD_RTC_TIME, 0);
	sprd_rtc_set_secs(dev, SPRD_RTC_ALARM, 0);
	sprd_rtc_set_secs(dev, SPRD_RTC_AUX_ALARM, 0);

	sprd_rtc_set(dev, SPRD_RTC_INT_CLR, SPRD_RTC_INT_ALL_MSK);

	return 0;
}

static int sprd_rtc_get_poweroff_alarm(struct udevice *dev, bool check_int, bool *poweroff)
{
	int ret;
	u32 rtc_spg;
	u32 int_sts;

	*poweroff = false;

	if (check_int) {
		ret = sprd_rtc_get(dev, SPRD_RTC_INT_RAW_STS, &int_sts);
		if (ret != 0)
			return ret;

		if (!(int_sts & SPRD_RTC_ALARM_INT))
			return 0;

		sprd_rtc_set(dev, SPRD_RTC_INT_CLR, SPRD_RTC_ALARM_INT);
	}

	ret = sprd_rtc_get(dev, SPRD_RTC_SPG_VAL, &rtc_spg);
	if (ret != 0)
		return ret;

	if (rtc_spg & SPRD_RTC_POWEROFF_ALARM) {
		sprd_rtc_set(dev, SPRD_RTC_SPG_UPD,
			rtc_spg & (~SPRD_RTC_POWEROFF_ALARM));
		*poweroff = true;
	}

	return 0;
}

/* The number of days in the month */
static int sprd_rtc_get_days_of_month(u32 month, u32 year)
{
	int month_days;

	month_days = rtc_days_in_month[month];

	if (month == 1 && IS_LEAP_YEAR(year))
		month_days += 1;

	return month_days;
}

static void sprd_rtc_secs_to_tm(u32 secs, struct rtc_time *tm)
{
	u32 month, year, year_base = 1970;
	int days;
	int newdays;

	days = secs / 86400;
	secs = secs % 86400;

	year = year_base + days / 365;
	days -= (year - year_base) * 365
		+ LEAPS_THRU_EVER_BEFORE(year - 1)
		- LEAPS_THRU_EVER_BEFORE(year_base - 1);
	if (days < 0) {
		year -= 1;
		days += 365 + IS_LEAP_YEAR(year);
	}
	tm->tm_year = year;
	tm->tm_yday = days + 1;

	for (month = 0; month < 11; month++) {
		newdays = days - sprd_rtc_get_days_of_month(month, year);
		if (newdays < 0)
			break;
		days = newdays;
	}

	month++;
	tm->tm_mon = month;
	tm->tm_mday = days + 1;

	tm->tm_hour = secs / 3600;
	secs -= tm->tm_hour * 3600;
	tm->tm_min = secs / 60;
	tm->tm_sec = secs - tm->tm_min * 60;

	tm->tm_isdst = 0;
}

/* Get RTC time (UTC time) */
static int sprd_rtc_get_time(struct udevice *dev, struct rtc_time *time)
{
	int ret;
	u32 secs;

	if (time == NULL)
		return -EINVAL;

	ret = sprd_rtc_get_secs(dev, SPRD_RTC_TIME, &secs);
	if (ret != 0)
		return ret;

	sprd_rtc_secs_to_tm(secs, time);

	return 0;
}

static const struct rtc_ops sprd_rtc_ops = {
	.get = sprd_rtc_get_time,
	.poweroff_alarm = sprd_rtc_get_poweroff_alarm,
	.reset = sprd_rtc_reset,
};

static int sprd_rtc_probe(struct udevice *rtc_dev)
{
	struct sprd_rtc *rtc_priv;

	rtc_priv = (struct sprd_rtc *)dev_get_priv(rtc_dev);
	if (rtc_priv == NULL)
		return -ENOMEM;

	rtc_priv->rtc_base = (u32)dev_read_addr(rtc_dev);

	return 0;
}

static const struct udevice_id sprd_rtc_ids[] = {
	{ .compatible = "sprd,sc27xx-rtc" }
};

U_BOOT_DRIVER(sprd_rtc) = {
	.name = "sprd-rtc",
	.id = UCLASS_RTC,
	.of_match = sprd_rtc_ids,
	.ops = &sprd_rtc_ops,
	.priv_auto_alloc_size = sizeof(struct sprd_rtc),
	.probe = sprd_rtc_probe,
};
