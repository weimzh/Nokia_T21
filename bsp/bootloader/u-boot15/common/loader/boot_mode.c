#include <common.h>
#include "loader_common.h"
#include <libfdt.h>
#include "dev_tree.h"
#include "secureboot/sec_common.h"
#include "logo_bin.h"
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication begin
#include "oem_fastboot_cmd.h"
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication end

//20220608, Added by zhu_jun for VSI-492 flash userdebug package enter fastboot on efuse locked device begin
#include <chipram_env.h>
//20220608, Added by zhu_jun for VSI-492 flash userdebug package enter fastboot on efuse locked device end

extern unsigned int g_charger_mode;
extern int do_fastboot(void);
extern void lcd_printf(const char *fmt, ...);
void lcd_enable(void);
extern void fastboot_lcd_printf(void);
extern void fastboot_init_power_mode(void);
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
extern int fb_check_reboot_edl(void *ptr);
#endif
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication begin
extern int fastboot_mode_flag;
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication end

//20220608, Added by zhu_jun for [HMDEnterpriseAPI] check miscdata is blocked or unblocked begin
#define MISCDATA_BLOCK_OFFSET		(768 * 1024 + 761)
#define MAGIC_BLOCK_FLAG		{1}
//20220608, Added by zhu_jun for [HMDEnterpriseAPI] check miscdata is blocked or unblocked end

/* HOPERUN_PATCH_BEGIN */
/* 2022-2-22:liuwenhu:MGK-720: IMEI security. */
#define IMEI_MAGIC_CODE_OFFSET (768 * 1024 + 762)
/* HOPERUN_PATCH_END */
//20220607, Added by zhu_jun Block/unblock Device getting into fastboot begin
extern int check_block_fastboot_flag();
//20220607, Added by zhu_jun Block/unblock Device getting into fastboot end
void __attribute__((weak)) fastboot_lcd_printf(void)
{
	lcd_printf("   fastboot mode");
	return;
}

#ifdef CONFIG_AUTOLOAD_MODE

void autoload_mode(void)
{
	struct boot_img_hdr *boot_hdr;
	ulong kernel_size = 0;
	uchar * ramdisk_addr = 0;
	ulong ramdisk_size = 0;
	uchar * dt_addr = 0;
	ulong dt_size = 0;
	struct dt_table *table = NULL;
	uint64_t size = 0;
	struct dt_entry *dt_entry_ptr = NULL;
	uint64_t offset = 0;
	debugf("autoload_mode\n");

#ifndef DEBUG
	stop_watchdog();
#endif

	boot_hdr = malloc(512*4);
	memcpy((void *)boot_hdr,(const void *)BOOTIMG_ADR,512*4);
	if (!memcmp(boot_hdr->magic, BOOT_MAGIC, BOOT_MAGIC_SIZE)) {
		kernel_size = (boot_hdr->kernel_size + (KERNL_PAGE_SIZE-1)) & (~(KERNL_PAGE_SIZE -1));
		ramdisk_addr =  (void *)BOOTIMG_ADR+512*4+kernel_size;
		ramdisk_size = (boot_hdr->ramdisk_size + (KERNL_PAGE_SIZE-1)) & (~(KERNL_PAGE_SIZE -1));
		dt_addr = (void *)BOOTIMG_ADR+512*4+kernel_size+ramdisk_size;
		dt_size = (boot_hdr->dt_size + (KERNL_PAGE_SIZE-1)) & (~(KERNL_PAGE_SIZE -1));
		memcpy((void *)KERNEL_ADR, (const void *)BOOTIMG_ADR+512*4, kernel_size);
		memcpy((void *)RAMDISK_ADR, ramdisk_addr, ramdisk_size);

		table = (struct dt_table*)dt_addr;
		/* Validate the device tree table header */
		if((table->magic != DEV_TREE_MAGIC) || (table->version != DEV_TREE_VERSION)) {
			errorf("Cannot validate Device Tree Table \n");
		}

		/* Calculate the offset of device tree within device tree table */
		dt_entry_ptr = dev_tree_get_entry_ptr(table);
		if(NULL == dt_entry_ptr) {
			errorf("Getting device tree address failed\n");
		}

		memcpy((void *)DT_ADR, dt_addr+dt_entry_ptr->offset, dt_entry_ptr->size);

		debugf("\nthe kernel is loading in the address:0x%x,size is 0x%lx\n", KERNEL_ADR, kernel_size);
		debugf("\nthe ramdisk is loading in the address:0x%x,size is 0x%lx\n", RAMDISK_ADR, ramdisk_size);
		debugf("\nthe dtb is loading in the address:0x%x,size is 0x%lx\n", DT_ADR, dt_entry_ptr->size);
	}
	fdt_initrd_norsvmem(DT_ADR, RAMDISK_ADR, RAMDISK_ADR + boot_hdr->ramdisk_size, 1);
	free(boot_hdr);

	vlx_entry(DT_ADR);

}

#endif

//20220608, Added by zhu_jun for VSI-492 flash userdebug package enter fastboot on efuse locked device begin
int fb_check_secboot_enable(void)
{
#ifdef CONFIG_SECBOOT
	unsigned int t_lcs __attribute__((aligned(4096)));
	unsigned int lcs = 0;
	boot_mode_t bmode;

	bmode = get_boot_role();
	if (BOOTLOADER_MODE_DOWNLOAD == bmode) {
		if (sprd_get_lcs(&lcs) || (5 != lcs)) {
			debugf("secboot was disabled(lcs: %d)\n", lcs);
			return -1;
		}
		debugf("secboot was enabled\n");
	} else if (BOOTLOADER_MODE_LOAD == bmode) {
		if (get_lcs(&t_lcs) || (5 != t_lcs)) {
			debugf("secboot was disabled(t_lcs: %d)\n", t_lcs);
			return -2;
		}
		debugf("secboot was enabled\n");
	}
#else
	if (0) {
	}
#endif
	else {
		debugf("unknown state\n");
		return -3;
	}

	return 0;
}
//20220608, Added by zhu_jun for VSI-492 flash userdebug package enter fastboot on efuse locked device end

void normal_mode(void)
{
//20220726, Added by zhu_jun for disable flash userdebug package enter fastboot on efuse locked device for ATO version begin
#ifndef WT_COMPILE_FACTORY_VERSION
//20220608, Added by zhu_jun for VSI-492 flash userdebug package enter fastboot on efuse locked device begin
#ifndef USER_BUILD
	debugf("this is USERDEBUG_BUILD !\n");
	if((get_lock_status() == VBOOT_STATUS_LOCK) && (fb_check_secboot_enable() == 0)) {
                int sec_time_count = 60;

		debugf("on efuse locked device, flash userdebug package, don't enter normal_mode, will enter fastboot_mode!\n");
                logo_display(LOGO_NORMAL_POWER, BACKLIGHT_ON, LCD_ON);

                lcd_printf("\nOn efuse locked device, flash userdebug package, don't enter normal_mode, will enter fastboot_mode! !!!\n\n");

		while(sec_time_count) {
			mdelay(100);
			sec_time_count --;
                }
		reboot_devices(CMD_FASTBOOT_MODE);
	}
#endif
//20220608, Added by zhu_jun for VSI-492 flash userdebug package enter fastboot on efuse locked device end
#endif
//20220726, Added by zhu_jun for disable flash userdebug package enter fastboot on efuse locked device for ATO version end
#ifndef CONFIG_ZEBU
#ifdef CONFIG_VIBRATOR
	vibrator_hw_init();

	set_vibrator(1);
#endif
#endif
	vlx_nand_boot(BOOT_PART, BACKLIGHT_ON, LCD_ON);
	return;
}

void calibration_mode(void)
{
	debugf("calibration_mode\n");

	stop_watchdog();
	setenv("bootmode", "cali");
#ifdef CONFIG_CALIMODE_USE_BOOTIMG
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_OFF);
#else
	vlx_nand_boot(RECOVERY_PART, BACKLIGHT_OFF, LCD_OFF);
#endif
	return;
}

void autotest_mode(void)
{
	debugf("autotest_mode\n");

	stop_watchdog();
	setenv("bootmode", "autotest");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);
	return;
}

void recovery_mode(void)
{
    debugf("recovery_mode\n");
    stop_watchdog();
    setenv("bootmode", "recovery");
    vlx_nand_boot(RECOVERY_PART, BACKLIGHT_ON, LCD_ON);
    return;

}


void special_mode(void)
{
	debugf("special_mode\n");

	stop_watchdog();
	setenv("bootmode", "special");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);
	return;
}

void iq_mode(void)
{
	debugf("iq_mode\n");
	stop_watchdog();
	setenv("bootmode", "iq");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);
	return;

}

void watchdog_mode(void)
{
	debugf("watchdog_mode\n");
	setenv("bootmode", "wdgreboot");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);
	return;

}

void ap_watchdog_mode(void)
{
	debugf("ap_watchdog_mode\n");
	setenv("bootmode", "apwdgreboot");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);
	return;

}

void unknow_reboot_mode(void)
{
	debugf("unknow_reboot_mode\n");
	stop_watchdog();
	setenv("bootmode", "unknowreboot");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);
	return;

}

void abnormal_reboot_mode(void)
{
	debugf("undefine_reboot_mode\n");
	setenv("bootmode", "abnormalreboot");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);
	return;
}
void panic_reboot_mode(void)
{
	debugf("enter\n");
	setenv("bootmode", "panic");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);
	return;

}

//20220614, Added by zhu_jun for red eio warning screen when dm-verity device corrupted begin
void dmeio_mode(void)
{
	debugf("enter\n");
	fastboot_init_power_mode();
	stop_watchdog();
	setenv("bootmode", "dmeio_mode");
	logo_display(LOGO_NORMAL_POWER, BACKLIGHT_ON, LCD_ON);
	display_state_verified_eio_red();
	debugf("power down device\n");
        write_log();
        power_down_devices(0);
}
//20220614, Added by zhu_jun for red eio warning screen when dm-verity device corrupted end

/* IMEI security. */
void display_imei_status()
{
    uint32_t imei_magic_code = 0;
    uint32_t target_magic_code = 0x18578571;
    uint32_t clear_magic_code = 0x01010101;

    //get magic code from MISCDATA
    if (common_raw_read("miscdata", sizeof(uint32_t), IMEI_MAGIC_CODE_OFFSET, &imei_magic_code)) {
	    errorf("read miscdata fail on offset 0x%x.\n", IMEI_MAGIC_CODE_OFFSET);
	    return;
    }

    debugf("IMEI magic code:0x%x-0x%x\n", imei_magic_code, target_magic_code);

    if (!memcmp(&target_magic_code, &imei_magic_code, sizeof(uint32_t))) {
        //match
        lcd_printf("\n   Data have been corrupted, enter fastboot mode.");
    
        //clear it.
        common_raw_write("miscdata", (uint64_t)4, (uint64_t)0, IMEI_MAGIC_CODE_OFFSET, &clear_magic_code);
    } else {
        debugf("IMEI magic code mismatch:0x%x\n", imei_magic_code);
    }

    return;
}
/* IMEI security end */
/** Start of PayJoy changes. */
extern uint8_t check_payjoy_flag() ;

void fastboot_mode(void)
{
	//20220607, Added by zhu_jun Block/unblock Device getting into fastboot begin
	if(check_block_fastboot_flag()){
		reboot_devices(CMD_NORMAL_MODE);
		while(1);
		return;
	}
	//20220607, Added by zhu_jun Block/unblock Device getting into fastboot end
	debugf("enter\n");
	/** Start of PayJoy changes. */
    	// Don't let phone get into fastboot mode by command "adb reboot bootloader" or other ways
    	// if the payjoy flag has been set to 1.

    	if (1 == check_payjoy_flag()) {
        	normal_mode();
        	return;
    	}

    	/** End of PayJoy changes. */
	fastboot_init_power_mode();
	stop_watchdog();
	setenv("bootmode", "fastboot");
#ifdef CONFIG_SPLASH_SCREEN
	logo_display(LOGO_NORMAL_POWER, BACKLIGHT_ON, LCD_ON);
#ifdef CONFIG_VIBRATOR
	vibrator_hw_init();
	set_vibrator(1);
#endif
	fastboot_lcd_printf();
	mdelay(400);
#ifdef CONFIG_VIBRATOR
	set_vibrator(0);
#endif
#endif
	//MMU_DisableIDCM();
#if (defined CONFIG_X86) && (defined CONFIG_MOBILEVISOR) && (defined CONFIG_SPRD_SOC_SP9853I)
	tos_start_notify();
#endif
#ifdef CONFIG_SECBOOT
	if (get_lock_status() == VBOOT_STATUS_UNLOCK){
		debugf("INFO: LOCK FLAG IS : UNLOCK!!!\n");
		lcd_printf("\n   INFO: LOCK FLAG IS : UNLOCK!!!\n");
	}
	get_secboot_base_from_dt();
#endif

    /* IMEI security. */
    display_imei_status();
    /* IMEI security end */
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication begin
	if (get_lock_status() == VBOOT_STATUS_UNLOCK){
                 fastboot_mode_flag = MODE_FASTBOOT_FLASH;
	}
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication end

	//20220608, Added by zhu_jun for [HMDEnterpriseAPI] check miscdata is blocked or unblocked begin
	debugf("check miscdata is blocked or unblocked.\n");
	char tmp[] = MAGIC_BLOCK_FLAG, buf[1] = {0};
	uint64_t offset = MISCDATA_BLOCK_OFFSET;
	int length = 1;
	if (common_raw_read("miscdata", (uint64_t)length, offset, buf)) {
		errorf("read miscdata %d fail on offset %lld.\n", length, offset);
		return;
	}
	/* miscdata offset(0xC02F9) value is 1, blocked: enter normal mode.
	   miscdata offset(0xC02F9) value is 0, unblocked: enter fastboot mode.
	*/
	if (!memcmp(tmp, buf, sizeof(buf))) {
		debugf("msicdata blocked flag:%x, do not enter fastboot, normal boot.\n", *(int *)buf);
		reboot_devices(CMD_NORMAL_MODE);
	}
	//20220608, Added by zhu_jun for [HMDEnterpriseAPI] check miscdata is blocked or unblocked end
	do_fastboot();

	return;
}

#ifdef CONFIG_ERASE_SPL_AUTO_DOWNLOAD
/**
 * If the SPL is erased, the romcode will enter the download process.
 * Notice: SPL must download.
 */
int erase_spl_enter_download_mode(void)
{
	stop_watchdog();
	if (0 != common_raw_erase("splloader", (uint64_t)0, (uint64_t)0)) {
		debugf("erase partition splloader fail!\n");
		return -1;
	} else {
		if (0 != common_raw_erase("splloader_bak", (uint64_t)0, (uint64_t)0)) {
			debugf("erase partition splloader_bak fail!\n");
			return -2;
		} else {
			debugf("erase partition splloader and splloader_bak ok\n");
			reboot_devices(CMD_NORMAL_MODE);
			while(1);
		}
	}

	return 0;
}
#endif

//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency begin
unsigned char check_fastboot_edl(void)
{
	int ret = 0;
	unsigned char edl_ret = 0;

	ret = oem_repair_read_mmc_ex("fastboot_reboot_edl", &edl_ret, MISCDATA_EDL_LEN);
	debugf("ret:%d, edl_ret:%d\n",ret, edl_ret);
	//debugf("edl_ret:%d\n",edl_ret);

	return edl_ret;
}

void clear_fastboot_edl(void)
{
	int ret = 0;
	unsigned char edl_set[2] = {0};
        printf("%s !!!\n", __func__);
	ret = oem_repair_write_mmc_ex("fastboot_reboot_edl", edl_set);
	debugf("ret:%d\n",ret);
}
//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency end
void autodloader_mode(void)
{
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	/* disable to use 'adb reboot autodloader' */
	if (fb_check_reboot_edl(NULL)) {
		printf("adb reboot autodloader was disabled\n");
		reboot_devices(CMD_NORMAL_MODE);
		while(1);
		return;
	}
#endif

//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency begin
#ifdef WT_FINAL_RELEASE
	if(!wt_check_download_permission()){
		reboot_devices(CMD_NORMAL_MODE);
		while(1);
		return;
	}
#endif
//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency end

	debugf("Enter autodloader mode\n");

#ifndef DEBUG
	stop_watchdog();
#endif

#ifdef CONFIG_ERASE_SPL_AUTO_DOWNLOAD
	if (0 != erase_spl_enter_download_mode()) {
		debugf("erase partition splloader and splloader_bak fail!\n");
		debugf("enter old autodloader_mode!\n");
	}
#endif

#if (defined CONFIG_X86) && (defined CONFIG_MOBILEVISOR) && (defined CONFIG_SPRD_SOC_SP9853I)
	tos_start_notify();
#endif

#ifdef CONFIG_SECBOOT
	get_secboot_base_from_dt();
#endif
	/* remap iram */
	//autodlader_remap();
	/* main handler receive and jump */
	autodloader_mainhandler();

	/*reach here means error happened*/
	return;
}

void charge_mode(void)
{
	debugf("enter\n");

	stop_watchdog();
	g_charger_mode = 1;
	setenv("bootmode", "charger");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_ON, LCD_ON);

}

void engtest_mode(void)
{
	printf("enter\n");
	stop_watchdog();
	setenv("bootmode", "engtest");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);

}


void alarm_mode(void)
{
	debugf("enter\n");
	setenv("bootmode", "alarm");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);

}

/* dont support factorytest mode anymore */
#if 0
void factorytest_mode(void)
{
    debugf("factorytest enter\n");
    stop_watchdog();
    setenv("bootmode", "factorytest");
#ifdef CONFIG_CALIMODE_USE_BOOTIMG
	vlx_nand_boot(BOOT_PART, BACKLIGHT_ON, LCD_ON);
#else
	vlx_nand_boot(RECOVERY_PART, BACKLIGHT_ON, LCD_ON);
#endif
    return;
}
#endif

void sprdisk_mode(void)
{
	debugf("enter\n");
	stop_watchdog();
	setenv("bootmode", "sprdisk");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_OFF, LCD_ON);

}

void apkmmi_mode(void)
{
	debugf("enter\n");
	stop_watchdog();
	setenv("bootmode", "apkmmi_mode");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_ON, LCD_ON);
}

void upt_mode(void)
{
	debugf("enter\n");
	stop_watchdog();
	setenv("bootmode", "upt_mode");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_ON, LCD_ON);
}

void apkmmi_auto_mode(void)
{
	debugf("enter\n");
	stop_watchdog();
	setenv("bootmode", "apkmmi_auto_mode");
	vlx_nand_boot(BOOT_PART, BACKLIGHT_ON, LCD_ON);
}

