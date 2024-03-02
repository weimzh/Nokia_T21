/*
 *MISCDATA_DEF_H - use field defined on partition of 'miscdata'
 *
 *  Copyright (C) 2021 Unisoc Communications Inc.
 *  History:
 *      Tue Feb 9 10:10:36 2021 zhenxiong.lai
 *      Description
 *        
 */

#ifndef __MISCDATA_DEF_H__
#define __MISCDATA_DEF_H__

/*
 *Verified Boot功能
 *(8K~8K+512)
 *uboot读取miscdata专用
 *(9K~9K+1K) 配置uboot读取loglevel用          	9K~9K+32
 *           配置uboot读取开机模式信息用      			9K+32~9K+64
 *           存放sysdump 开关用         	    	9K+64~9K+288
 *           uboot读取flag专用                  9k+288~9k+352
 *           uboot读取selinux权限检查开关     		9k+352~9k+383
 *           存储虚拟board id用于匹配dtbo     		9k+384~9k+388
 *           下载时获取手机里的版本号用       			9K+512~9K+768
 *           uboot保存时间戳物料判定用        		9K+768~9K+800
 *           记录watchdog使能菜单           		9K+800~9K+832
 *客户自定义区
 *768K- 1024K
 */
#define MISCDATA_VERIFIED_BOOT		(8 * 1024)
#define PDT_INFO_LOCK_FLAG_OFFSET 	(MISCDATA_VERIFIED_BOOT)

/** UBOOT 专用区域 */
#define MISCDATA_UBOOT_BASE			(9 * 1024)

/* loglevel */
#define DEBUG_INFO_OFFSET			MISCDATA_UBOOT_BASE
#define DEBUG_INFO_LEN    			(32)

/* first mode */
#define SET_FIRST_MODE_MAGIC 		(0x53464d00)
#define SET_FIRST_MODE_OFFSET 		(MISCDATA_UBOOT_BASE + 32)
#define SET_FIRST_MDOE_LEN 			(0x4)

/* virtual board id */
#define SET_VIRTUAL_BOARD_ID_MAGIC	(0x5AA50000)
#define SET_VIRTUAL_BOARD_ID_OFFSET	(MISCDATA_UBOOT_BASE + 384)
#define SET_VIRTUAL_BOARD_ID_LEN	(0x4)

/* core0 startup flag */
#define CORE_STARTUP_FLAG_OFFSET	(MISCDATA_UBOOT_BASE + 388)
#define CORE_STARTUP_FLAG_LEN		(0x2)

/* mode startup block flags */
#define STARTUP_BLOCK_FLAG_OFFSET	(MISCDATA_UBOOT_BASE + 390)
#define STARTUP_BLOCK_FLAG_LEN		(0x4)

//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 begin
/* off-mode-charge flag */
#define OFF_MODE_CHARGE_FLAG_OFFSET     (774 * 1024 + 2)
#define OFF_MODE_CHARGE_FLAG_LEN        (0x1)

/* hmd_off_mode_charge flag */
#define HMD_OFF_MODE_CHARGE_FLAG_OFFSET     (774 * 1024 + 3)
#define HMD_OFF_MODE_CHARGE_FLAG_LEN        (0x1)
//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 end

/*wdt enable flags */
#define WDTEN_MAGIC			(0xe551)
#define WDTEN_DATA_OFFSET		(MISCDATA_UBOOT_BASE + 800)
#define WDTEN_DATA_LEN			(0x20)

/*deepsleep wdt enable flags */
#define DSWDTEN_DATA_OFFSET             (MISCDATA_UBOOT_BASE + 832)
#define DSWDTEN_DATA_LEN		(0x20)

/* sysdump */
#define MISCDATA_DUMP_DATA_START 	 (9 * 1024 + 64)///fixme
#define FULLDUMP_PARTITION_MAGIC_LEN (10)


/* usr base */
#define MISCDATA_USR_BASE  		(512 * 1024)

/* ADC数据存储 */
#define ADC_DATA_OFFSET  		(MISCDATA_USR_BASE)
#define ADC_DATA_START  		(ADC_DATA_OFFSET)

/* 保存pac的创建时间 */
#define DATETIME_OFFSET 		(MISCDATA_USR_BASE + 5120)
#define DATETIME_LEN			(0x400)

//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start begin
/*---------------wt  自定义区 768K- 1024K-----------------*/

#define CUSTOM_NV_BASE	(768*1024)

#define READ_MMC_LEN_AUTO -1

/*29~40	SKUID	NOKIA项目例如："600EEA", "600WW"*/
#define MISCDATA_SKUID_OFFSET	29
#define MISCDATA_SKUID_LEN	12
#define MISCDATA_SKUID_ADDR	(CUSTOM_NV_BASE + MISCDATA_SKUID_OFFSET)

/* NOTE:  base addr (768*1024) */
#define    WT_PCBA_CURRENT_TEST   19
#define    WT_WHOLE_CURRENT_TEST    20
#define    WT_COUPLED_TEST    21
#define    WT_RUNIN_START    22
#define    WT_RUNIN_TEST_TIME    25
#define    WT_HW_VERSION    26
#define    WT_SUM_CODE_SWITCH    28
#define    WT_SIMSLOT_OFFSET    41
#define    WT_SIMSLOT_LEN    8    // 12
#define    WT_COUNTRY_CODE    53
#define    WT_COUNTRY_CODE_LEN    32
//20220531,Added by zhu_jun for Set ZeroFlag related property begin
#define    WT_ZEROFLAG_OFFSET   461
#define    WT_ZEROFLAG_LEN   1
//20220531,Added by zhu_jun for Set ZeroFlag related property end
//#define    WT_RESERVED    85

//20220607, Added by zhu_jun Block/unblock Device getting into fastboot and factory reset begin
#define BLOCK_FASTBOOT_MODE_OFFSET	460
#define BLOCK_FASTBOOT_LEN			1
#define BLOCK_FASTBOOT_ADDR			(CUSTOM_NV_BASE + BLOCK_FASTBOOT_MODE_OFFSET)
#define BLOCK_FASTBOOT_FLAG			"1"

#define BLOCK_FACTORY_RESET_OFFSET  459
#define BLOCK_FACTORY_RESET_LEN		1
#define BLOCK_FACTORY_RESET_ADDR	(CUSTOM_NV_BASE + BLOCK_FACTORY_RESET_OFFSET)
#define BLOCK_FACTORY_RESET_FLAG	"1"
//20220607, Added by zhu_jun Block/unblock Device getting into fastboot and factory reset end

//added by dongming, for miscdata india flag, 20221018
#define MISCDATA_INDIA_FLAG_ADDR    768*1024+777
#define MISCDATA_INDIA_FLAG_LEN     1
#define MISCDATA_INDIA_FLAG_TYPE    "miscdata_india_flag"
//end added, 20221018

//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions begin
#define WT_POWP_OFFSET  (770*1024)
#define WT_POWP_LEN     300
//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions end
#define MISCDATA_COLORID_OFFSET	27
#define MISCDATA_COLORID_LEN	     1
#define MISCDATA_COLORID_ADDR	     (CUSTOM_NV_BASE + MISCDATA_COLORID_OFFSET)

//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency begin
#define MISCDATA_EDL_OFFSET	     774
#define MISCDATA_EDL_LEN	     1
#define MISCDATA_EDL_ADDR	     (CUSTOM_NV_BASE + MISCDATA_EDL_OFFSET)
//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency end

//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking begin
#ifdef CONFIG_PCTOOL_AUTHORIZE_HMD
#define HMD_CALI_MODE_SIGNATURE_OFFSET	775*1024
#define HMD_CALI_MODE_SIGNATURE_LEN	256
#define WT_FACTORY_SN_DATA_OFFSET	775*1024 + 256
#define WT_FACTORY_SN_DATA_LEN		32
#endif
//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking end

//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
#define HMD_DOWNLOAD_MODE_SIGNATURE_OFFSET  775*1024 + 289
#define HMD_DOWNLOAD_MODE_SIGNATURE_LEN     344
//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end

//added by dongming, for AGT-685 store the repair signature data
#define HMD_EDL_MODE_SIGNATURE_OFFSET  776*1024
#define HMD_EDL_MODE_SIGNATURE_LEN     344
#define HMD_EDL_MODE_REPAIR_SIGNATURE_TYPE "edl_repair_signature"
//end added by dongming, for AGT-685 store the repair signature data

int oem_repair_read_mmc_ex(const char *type,unsigned char *buf,int len);
int oem_repair_write_mmc_ex(const char *type,unsigned char *buf);
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start end
#endif /* __MISCDATA_DEF_H__ */

