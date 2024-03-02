/*
 *  storage_type_ITcase.c - For IT testing
 *
 *  Copyright (C) 2020 Unisoc Communications Inc.
 *  History:
 *      2020/7/9 zhe.wang1
 *      Description
 */
#include <common.h>
#include <asm/io.h>
#include <asm/arch/sprd_reg.h>
#include "adi_hal_internal.h"
#include <asm/arch/common.h>
#include <otp_helper.h>
#include <sprd_pmic_misc.h>
#include <chipram_env.h>

int uboot_storage_type_detect_test(int argc, char *const argv[])
{
	uint32_t bootdevice = 0;
#if defined(CONFIG_BLK_DEV_BOOT)
	bootdevice = get_bootdevice();
	if (bootdevice == BOOT_DEVICE_UFS)
		debugf("storage_type is UFS\n");
	else if (bootdevice == BOOT_DEVICE_EMMC)
		debugf("storage_type is EMMC\n");
#else
	debugf("WARNING: CONFIG_BLK_DEV_BOOT: Automatic detection macro is not open in this device\n");
#endif
	return 0;
}

U_BOOT_IT_TEST_REGISTER(uboot_storage_type_detect_test_tc1000, uboot_storage_type_detect_test,
			"This is used to detect which kind of storage device");
