/*
 * An vibrator device/driver
 * Copyright (C) 2019 UNISOC Communication Inc
 * Author: Yongzhi Chen <yongzhi.chen@unisoc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <misc.h>
#include <dm/lists.h>
#include <power/pmic.h>

#define GENMASK(h, l) \
	(((~0UL) << (l)) & (~0UL >> (BITS_PER_LONG - 1 - (h))))

#define CUR_DRV_CAL_SEL			GENMASK(13, 12)
#define SLP_LDOVIBR_PD_EN		BIT(9)
#define LDO_VIBR_PD			BIT(8)
#define SC2730_CUR_DRV_CAL_SEL		0
#define SC2730_SLP_LDOVIBR_PD_EN	BIT(14)
#define SC2730_LDO_VIBR_PD		BIT(13)

struct sc27xx_vibra_data {
	u32 cur_drv_cal_sel;
	u32 slp_pd_en;
	u32 ldo_pd;
};

struct sc27xx_vibra {
	u32 vibra_base;
	struct sc27xx_vibra_data *data;
};

struct sc27xx_vibra_data sc2731_vibra_data = {
	.cur_drv_cal_sel = CUR_DRV_CAL_SEL,
	.slp_pd_en = SLP_LDOVIBR_PD_EN,
	.ldo_pd = LDO_VIBR_PD,
};

struct sc27xx_vibra_data sc2730_vibra_data = {
	.cur_drv_cal_sel = SC2730_CUR_DRV_CAL_SEL,
	.slp_pd_en = SC2730_SLP_LDOVIBR_PD_EN,
	.ldo_pd = SC2730_LDO_VIBR_PD,
};

struct sc27xx_vibra_data sc2721_vibra_data = {
	.cur_drv_cal_sel = CUR_DRV_CAL_SEL,
	.slp_pd_en = SLP_LDOVIBR_PD_EN,
	.ldo_pd = LDO_VIBR_PD,
};

static int sc27xx_vibra_set(struct udevice *dev, bool on)
{
	struct sc27xx_vibra *vibra_priv = dev_get_priv(dev);
	struct sc27xx_vibra_data *data = vibra_priv->data;
	struct udevice *pmic = dev->parent;
	int ret;

	if (on) {
		ret = pmic_clrsetbits(pmic, vibra_priv->vibra_base, data->ldo_pd, 0);
		if (ret != 0)
			return ret;

		return pmic_clrsetbits(pmic, vibra_priv->vibra_base, data->slp_pd_en, 0);
	} else {
		ret = pmic_clrsetbits(pmic, vibra_priv->vibra_base, data->ldo_pd, data->ldo_pd);
		if (ret != 0)
			return ret;

		return pmic_clrsetbits(pmic, vibra_priv->vibra_base, data->slp_pd_en, data->slp_pd_en);
	}
}

static int sc27xx_vibra_hw_init(struct udevice *dev)
{
	struct sc27xx_vibra *vibra_priv = dev_get_priv(dev);
	struct sc27xx_vibra_data *data = vibra_priv->data;
	struct udevice *pmic = dev->parent;

	if (!data->cur_drv_cal_sel)
		return 0;

	return pmic_clrsetbits(pmic, vibra_priv->vibra_base, data->cur_drv_cal_sel, 0);
}

static const struct misc_ops sc27xx_vibra_ops = {
	.set_enabled = sc27xx_vibra_set,
};

static int sc27xx_vibra_probe(struct udevice *dev)
{
	struct sc27xx_vibra *vibra_priv = (struct sc27xx_vibra *)dev_get_priv(dev);

	vibra_priv->vibra_base = (u32)dev_read_addr(dev);
	if (!vibra_priv->vibra_base)
		return -EINVAL;

	if (device_is_compatible(dev->parent, "sprd,sc2721") ||
	    device_is_compatible(dev->parent, "sprd,sc2720"))
		vibra_priv->data = &sc2721_vibra_data;
	else if (device_is_compatible(dev->parent, "sprd,sc2730"))
		vibra_priv->data = &sc2730_vibra_data;
	else if (device_is_compatible(dev->parent, "sprd,sc2731"))
		vibra_priv->data = &sc2731_vibra_data;
	else
		return -ENODEV;

	return sc27xx_vibra_hw_init(dev);
}

U_BOOT_DRIVER(sc27xx_vibrator) = {
	.name = "sc27xx-vibrator",
	.id = UCLASS_MISC,
	.ops = &sc27xx_vibra_ops,
	.priv_auto_alloc_size = sizeof(struct sc27xx_vibra),
	.probe = sc27xx_vibra_probe,
};
