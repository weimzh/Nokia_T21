/*
 * Copyright (C) 2019 unisoc.com
 *
 * Support notifier train for reset.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __SPRD_RESET_H__
#define __SPRD_RESET_H__

/*
 *Definition of ANA_RST_STATUS(ANA_REG_GLB_POR_OFF_FLAG) register
 *bit13:uvlo+ovlo
 *bit11:uvlo
 *bit9:hard 7s
 *bit7:sw
 *bit5:hw
 *bit3:otp
 * */

#define HWOFF_STATUS_PD                  0x0
#define HWOFF_STATUS_OTP                 0x0008
#define HWOFF_STATUS_HW                  0x0020
#define HWOFF_STATUS_HW_OTP              0x0028
#define HWOFF_STATUS_7S                  0x0200
#define HWOFF_STATUS_7S_OTP              0x0208
#define HWOFF_STATUS_7S_HW               0x0220
#define HWOFF_STATUS_7S_HW_OTP           0x0228
#define HWOFF_STATUS_OVLO                0x2000
#define HWOFF_STATUS_OVLO_OTP            0x2008
#define HWOFF_STATUS_OVLO_HW             0x2020
#define HWOFF_STATUS_OVLO_HW_OTP         0x2028
#define HWOFF_STATUS_OVLO_7S             0x2200
#define HWOFF_STATUS_OVLO_7S_OTP         0x2208
#define HWOFF_STATUS_OVLO_7S_HW          0x2220
#define HWOFF_STATUS_OVLO_7S_HW_OTP      0x2228
#define HWOFF_STATUS_UVLO                0x2800
#define HWOFF_STATUS_UVLO_OTP            0x2808
#define HWOFF_STATUS_UVLO_HW             0x2820
#define HWOFF_STATUS_UVLO_HW_OTP         0x2828
#define HWOFF_STATUS_UVLO_7S             0x2A00
#define HWOFF_STATUS_UVLO_7S_OTP         0x2A08
#define HWOFF_STATUS_UVLO_7S_HW          0x2A20
#define HWOFF_STATUS_UVLO_7S_HW_OTP      0x2A28

enum {
	NOTIFY_RESET_ACTION_NONE = 0,
	NOTIFY_RESET_ACTION_POWEROFF,
	NOTIFY_RESET_ACTION_REBOOT,
};

enum {
	NOTIFY_RESET_POWEROFF_PRIORITY_LAST = 0,
	NOTIFY_RESET_POWEROFF_PRIORITY_RTC,
	NOTIFY_RESET_POWEROFF_PRIORITY_ARCH_OFF,
};

/* TODO: add reboot notifier train */
enum {
	NOTIFY_RESET_REBOOT_PRIORITY_LAST = 0,
	NOTIFY_RESET_REBOOT_PRIORITY_RTC,
	NOTIFY_RESET_REBOOT_PRIORITY_ARCH_OFF,
};

typedef enum {
	NOTIFY_RESET_TYPE_NULL = 0,
	NOTIFY_RESET_TYPE_POWEROFF,
	NOTIFY_RESET_TYPE_REBOOT,
} notify_reset_type;

extern int notifier_reset_register(struct notifier_block *n,
				   notify_reset_type type);
extern int notifier_reset_unregister(struct notifier_block *n,
				     notify_reset_type type);
#endif
