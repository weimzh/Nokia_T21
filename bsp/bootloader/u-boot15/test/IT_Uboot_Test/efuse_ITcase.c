/*
 * Copyright (C) 2019 Spreadtrum Communications Inc.
 */

#include <asm-generic/errno.h>
#include <asm/arch/sprd_reg.h>
#include <asm/types.h>
#include <dm/device.h>
#include <dm/read.h>
#include <dm/uclass.h>
#include <dm/uclass-id.h>
#include <power/pmic.h>
#include <linux/types.h>
#include <linux/err.h>
#include <common.h>
#include <misc.h>
#include <command.h>
#include <chipram_env.h>

#ifndef UID_START
#define UID_START	0
#endif
#ifndef UID_END
#define UID_END		1
#endif
#ifndef UID_DOUBLE
#define UID_DOUBLE	1
#endif

#define PMIC_BLK_START 	0
#if defined(CONFIG_ADIE_SC2720) || defined(CONFIG_ADIE_SC2730) \
	|| defined(CONFIG_ADIE_SC2731) || defined(CONFIG_ADIE_SC2721)
#define PMIC_BLK_END	32
#elif defined(CONFIG_ADIE_UMP9620)
#define PMIC_BLK_END	64
#endif

int efuse_sc27xx_get_efuse(int argc, char *const argv[])
{
	int ret = 0, testFlag = 0;
	u32 val = 0;
	u32 blk;

	for(blk = PMIC_BLK_START; blk <= PMIC_BLK_END; blk++){
		val = sprd_pmic_efuse_read(blk);
		if(val == 0x0)
			testFlag = 1;
		else
			testFlag = 0;
	}

	if(testFlag == 1){
		debugf("This Pmic IP has not write efuse yet !\r\n");
		return -1;
	}

	return 0;
}

int efuse_sprd_get_efuse(int argc, char *const argv[])
{
	int ret = 0;
	u32 blocks[2] = {0};

#if defined (CONFIG_SPRD_AP_NORMAL_EFUSE)
 	if(get_chipram_env()->mode == BOOTLOADER_MODE_DOWNLOAD){
  		if (sprd_secure_efuse_read(UID_START, UID_START, &blocks[1], UID_DOUBLE)) {
  			return -2;
  		}
  		if (sprd_secure_efuse_read(UID_END, UID_END, &blocks[0], UID_DOUBLE)) {
  			return -2;
             }
  	}else{
		debugf("UID_START: %d, UID_END:%d\r\n",UID_START,UID_END);
  		blocks[1] = sprd_efuse_double_read(UID_START,UID_DOUBLE);
  		blocks[0] = sprd_efuse_double_read(UID_END,UID_DOUBLE);
  	}
#else
	debugf("AP_NORMAL_EFUSE is not defined,use ap_efuse_read interface.\r\n");
  	blocks[0]= sprd_ap_efuse_read(UID_START);
  	blocks[1]= sprd_ap_efuse_read(UID_END);
#endif

	if((blocks[0] == 0x0)&&(blocks[1] == 0x0)){
		debugf("This project has not write aon efuse uid yet!\r\n");
		return -1;
	}

	return 0;
}

U_BOOT_IT_TEST_REGISTER(efuse_tc1000_sprd_get_efuse, efuse_sprd_get_efuse, "This function is read DDie efuse ");
U_BOOT_IT_TEST_REGISTER(efuse_tc1001_sc27xx_get_efuse, efuse_sc27xx_get_efuse, "This function is read PMIC efuse ");
