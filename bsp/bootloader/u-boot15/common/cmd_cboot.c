#include <common.h>
#include <command.h>
#include <linux/types.h>
//#include <linux/keypad.h>
//#include <linux/key_code.h>
#include <linux/input.h>
#include <boot_mode.h>
//#include <android_bootimg.h>
//#include <asm/arch/gpio.h>
#include <asm/arch/check_reboot.h>
#include <sprd_battery.h>
#include <logo_bin.h>
#include <chipram_env.h>
//20220511, Added by zhu_jun for the power-on write protect request start
#include <sprd_common_rw.h>
//20220511, Added by zhu_jun for the power-on write protect request end

#ifdef CONFIG_ANDROID_AB
#include <android_ab.h>
#endif

//20220613, Added by zhu_jun for BSP disable UNISOC DIAG port on MP&User version begin
#include <mpflag_def.h>
//20220613, Added by zhu_jun for BSP disable UNISOC DIAG port on MP&User version end
#define HMD_EN_API_FASTBOOT_MODE_OFFSET	(774 * 1024 + 2)//fastboot_mode
extern CBOOT_FUNC s_boot_func_array[CHECK_BOOTMODE_FUN_NUM] ;

extern unsigned int check_key_boot(unsigned char key);
extern void write_sysdump_before_boot(int rst_mode);
extern unsigned char board_key_scan(void);
extern void board_boot_mode_regist(CBOOT_MODE_ENTRY *array);
extern char *bootcause_cmdline;
extern int sprdbat_get_shutdown_charge_flag(void);

int s_boot_mode;

#define USBPHY_VDDUSB33_NORMAL		3300
#define USBPHY_VDDUSB33_FULLSPEED_TUNE	2700

//20220613, Added by zhu_jun for VSI-609 BSP disable UNISOC DIAG port on MP&User version begin
unsigned int is_usb_enum_abandoned = 0;
//20220613, Added by zhu_jun for VSI-609 BSP disable UNISOC DIAG  port on MP&User version end

static const char *g_mode_str[CMD_MAX_MODE] = {
	"UNDEFINED_MODE",
	"POWER_DOWN_DEVICE",
	"NORMAL_MODE",
	"RECOVERY_MODE",
	"FASTBOOT_MODE",
	"ALARM_MODE",
	"CHARGE_MODE",
	"ENGTEST_MODE",
	"WATCHDOG_REBOOT",
	"AP_WATCHDOG_REBOOT",
	"SPECIAL_MODE",
	"UNKNOW_REBOOT_MODE",
	"PANIC_REBOOT",
	"VMM_PANIC_MODE",
	"TOS_PANIC_MODE",
	"EXT_RSTN_REBOOT_MODE",
	"CALIBRATION_MODE",
	"FACTORYTEST_MODE",
	"AUTODLOADER_REBOOT",
	"AUTOTEST_MODE",
	"IQ_REBOOT_MODE",
	"SLEEP_MODE",
	"SPRDISK_MODE",
	"APKMMI_MODE",
	"UPT_MODE",
	"APKMMI_AUTO_MODE",
	"ABNORMAL_REBOOT_MODE",

	"MAX_MODE",
};

int boot_pwr_check(void)
{
	static int total_cnt = 0;

	if (!power_button_pressed())
		total_cnt ++;
	return total_cnt;
}

//20220613, Added by zhu_jun for VSI-609 BSP disable UNISOC DIAG  port on MP&User version begin
int usb_enum_permission_check(void)
{
#ifdef CONFIG_SECBOOT
    is_usb_enum_abandoned = wt_check_mp_flags();
    debugf("usb_enum_permission_check:is_usb_enum_abandoned=%d\n",is_usb_enum_abandoned);
#else
	is_usb_enum_abandoned = 0;
#endif
	return 0;
}
//20220613, Added by zhu_jun for VSI-609 BSP disable UNISOC DIAG  port on MP&User version end

boot_mode_enum_type get_mode_from_arg(char* mode_name)
{

	printf("cboot:get mode from argument:%s\n",mode_name);
	if(!strcmp(mode_name,"normal"))
		return CMD_NORMAL_MODE;

	if(!strcmp(mode_name,"recovery"))
		return CMD_RECOVERY_MODE;

	if(!strcmp(mode_name,"fastboot"))
		return CMD_FASTBOOT_MODE;

	if(!strcmp(mode_name,"charge"))
		return CMD_CHARGE_MODE;

	if(!strcmp(mode_name,"sprdisk"))
		return CMD_SPRDISK_MODE;

	/*just for debug*/
#ifdef CONFIG_SPRD_SYSDUMP
	if(!strcmp(mode_name,"sysdump"))
		write_sysdump_before_boot(CMD_UNKNOW_REBOOT_MODE);
#endif
	return CMD_UNDEFINED_MODE;

}


unsigned reboot_mode_check(void)
{
	  static unsigned rst_mode = 0;
	   static unsigned check_times = 0;
	   if(!check_times)
	  {
		  rst_mode = check_reboot_mode();
		  check_times++;
	  }
	  debugf("reboot_mode_check rst_mode=0x%x\n",rst_mode);
	  return rst_mode;
}


  // 0 get mode from pc tool
boot_mode_enum_type get_mode_from_pctool(void)
{
	int ret;

	regulator_set_voltage("vddusb33", USBPHY_VDDUSB33_FULLSPEED_TUNE);
	ret = pctool_mode_detect();
	regulator_set_voltage("vddusb33", USBPHY_VDDUSB33_NORMAL);
	if (ret < 0)
		return CMD_UNDEFINED_MODE;
	else {
		bootcause_cmdline="The pctools sends control commands";
		return ret;
	}
}

boot_mode_enum_type get_mode_from_bat_low(void)
{
#ifndef CONFIG_FPGA       //jump loop
	while(is_bat_low()) {
#ifdef CONFIG_TARGET_SP9853I_10C10
	  if(1) {
#else
	  if(charger_connected()) {
#endif
		  debugf("cboot:low battery,charging...\n");
		  sprdbat_show_lowpower_charge_logo();
#ifndef DEBUG
		  stop_watchdog();
#endif
		  sprdbat_lowbat_chg();
		  mdelay(SPRDBAT_CHG_POLLING_T);
	  }else{
		  debugf("cboot:low battery and shutdown\n");
		  logo_display(LOGO_LOW_VOL, BACKLIGHT_ON, LCD_DISPLAY_ENABLE);
		  mdelay(LOW_VOL_DISPLAY_DELAY_TIME);
		  return CMD_POWER_DOWN_DEVICE;
	  }
	}
#endif
	sprdbat_chg_led(0);
	return CMD_UNDEFINED_MODE;
}

#ifndef CONFIG_ZEBU
boot_mode_enum_type write_sysdump_before_boot_extend(void)
{
	unsigned rst_mode = reboot_mode_check();
	debugf("cboot:write_sysdump_before_boot_extend!!!!\n");
#ifdef CONFIG_SPRD_SYSDUMP
	write_sysdump_before_boot(rst_mode);
#endif
	return CMD_UNDEFINED_MODE;
}
#endif

/* get mode from miscdata */
boot_mode_enum_type get_mode_from_miscdata_boot_flag(void)
{
	boot_mode_enum_type first_mode = read_boot_flag();
	if (first_mode != CMD_UNDEFINED_MODE) {
		bootcause_cmdline="Detect the firsrt_mode flag in the miscdata partition";
		printf("get mode from firstmode field: %s\n", g_mode_str[first_mode]);
		return first_mode;
	} else
		return CMD_UNDEFINED_MODE;
}

/*1 get mode from file, just for recovery mode now*/
boot_mode_enum_type get_mode_from_file_extend(void)
{
	switch (get_mode_from_file()) {
		case CMD_RECOVERY_MODE:
			debugf("cboot:get mode from file:recovery\n");
			bootcause_cmdline="Detect the recovery message in the misc partition";
			return CMD_RECOVERY_MODE;
		default:
			return CMD_UNDEFINED_MODE;
	}
	return CMD_UNDEFINED_MODE;
}

// 2 get mode from watch dog
boot_mode_enum_type get_mode_from_watchdog(void)
{
	unsigned rst_mode = reboot_mode_check();
	int flag;
	switch (rst_mode) {
		case CMD_RECOVERY_MODE:
		case CMD_FASTBOOT_MODE:
		case CMD_NORMAL_MODE:
		case CMD_WATCHDOG_REBOOT:
		case CMD_AP_WATCHDOG_REBOOT:
		case CMD_ABNORMAL_REBOOT_MODE:
		case CMD_UNKNOW_REBOOT_MODE:
		case CMD_PANIC_REBOOT:
		case CMD_AUTODLOADER_REBOOT:
		case CMD_SPECIAL_MODE:
		case CMD_EXT_RSTN_REBOOT_MODE:
		case CMD_IQ_REBOOT_MODE:
		case CMD_SPRDISK_MODE:
		/*case CMD_FACTORYTEST_MODE:*/
		//20220614, Added by zhu_jun for red eio warning screen when dm-verity device corrupted begin
		case CMD_DMEIO_MODE:
		//20220614, Added by zhu_jun for red eio warning screen when dm-verity device corrupted end
			return rst_mode;
		case CMD_ALARM_MODE:
			if ((flag = alarm_flag_check())) {
				debugf("get_mode_from_watchdog flag=%d\n", flag);
				if (flag == 1) {
				  bootcause_cmdline="Watchdog reset pending and poweroff alarm";
				  return CMD_ALARM_MODE;
				}
				else if (flag == 2) {
				  bootcause_cmdline="Watchdog reset pending but Shutdown alarm is abnormal";
				  return CMD_NORMAL_MODE;
				}
			}
		default:
			return CMD_UNDEFINED_MODE;
	}
}

// 3 get mode from alarm register
boot_mode_enum_type  get_mode_from_alarm_register(void)
{
	int flag;

	if (alarm_triggered() && (flag = alarm_flag_check())) {
		debugf("get_mode_from_alarm_register flag=%d\n", flag);
		if (flag == 1) {
			bootcause_cmdline="RTC poweroff alarm expiry";
			return CMD_ALARM_MODE;
		}
		else if (flag == 2) {
			bootcause_cmdline="Shutdown alarm is abnormal";
			return CMD_NORMAL_MODE;
		}
	} else {
		return CMD_UNDEFINED_MODE;
	}
}

extern boot_mode_enum_type board_key_scan_mode_type(void);

/* 4 get mode from charger*/
boot_mode_enum_type  get_mode_from_charger(void)
{
	int flag = 0;
	//20220622, Added by zhu_jun for VSI-772 support VOLUMEDOWN+USB enter fastboot mode in shutdown state begin
	uint32_t key_code = 0;
	volatile int i;
	//20220622, Added by zhu_jun for VSI-772 support VOLUMEDOWN+USB enter fastboot mode in shutdown state end
    boot_mode_enum_type my_type = CMD_UNDEFINED_MODE;

	flag = sprdbat_get_shutdown_charge_flag();
	debugf("get_shutdown_charge_flag flag=%d\n", flag);
	if (charger_connected()) {
		if (flag) {
			debugf("get mode from charger\n");
			bootcause_cmdline="in charging during shutdown the devices";
			
			my_type = board_key_scan_mode_type();
			if ( my_type != CMD_UNDEFINED_MODE ) {
			    return my_type;
			}
			
			 //20220622, Added by zhu_jun for VSI-873 support KEY_VOLUMEUP+USB enter recovery mode in shutdown state on userdebug version end
			//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 begin
			#ifdef OFF_MODE_CHARGE
				unsigned short flag1 = 0;
				char flag2[1] = {0};
				if (common_raw_read("miscdata", HMD_OFF_MODE_CHARGE_FLAG_LEN, HMD_OFF_MODE_CHARGE_FLAG_OFFSET, flag2)) {
					errorf("read hmd_off_mode_charge flag error!\n");
				}

				if(!strncmp(flag2,"0",strlen("0"))){
					if (common_raw_read("miscdata", OFF_MODE_CHARGE_FLAG_LEN, OFF_MODE_CHARGE_FLAG_OFFSET, &flag1)) {
						errorf("read off-mode-charge flag1 error!\n");
					}
				}

				if(flag1 == 0 && !strncmp(flag2,"0",strlen("0"))) {
					debugf("first open device, set 2 mode! poweroff charge!\n");
					flag1 = 2;
					if (common_raw_write("miscdata", OFF_MODE_CHARGE_FLAG_LEN, (uint64_t)0, (uint64_t)OFF_MODE_CHARGE_FLAG_OFFSET, (char *)&flag1)) {
						errorf("write miscdata off-mode-charge flag fail!\n");
					} else {
						debugf("off-mode-charge on now\n");
					}
				}

				if (!strncmp(flag2,"1",strlen("1"))){
					debugf("app off-mode-charge off %d\n", flag1);
					return CMD_NORMAL_MODE;
				}else if (!strncmp(flag2,"2",strlen("2"))){
					debugf("app off-mode-charge on %d\n", flag1);
					return CMD_CHARGE_MODE;
				}else if (flag1 == 1) {
					debugf("off-mode-charge off %d\n", flag1);
					return CMD_NORMAL_MODE;
				} else if (flag1 == 2) {
					debugf("off-mode-charge on %d\n", flag1);
					return CMD_CHARGE_MODE;
				} else {
					errorf("off-mode-charge flag value error!\n");
					return CMD_CHARGE_MODE;
				}
			#else
				return CMD_CHARGE_MODE;
			#endif
		//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 end
		} else {
			bootcause_cmdline="Charger connected";
			return CMD_NORMAL_MODE;
		}
	} else {
		return CMD_UNDEFINED_MODE;
	}
}

/*5 get mode from keypad*/
boot_mode_enum_type  get_mode_from_keypad(void)
{
	uint32_t key_mode = 0;
	uint32_t key_code = 0;
	volatile int i;
	if (boot_pwr_check() >= PWR_KEY_DETECT_CNT) {
		mdelay(50);
		for (i = 0; i < 10; i++) {
			key_code = board_key_scan();
			if(key_code != KEY_RESERVED)
			  break;
		}
		key_mode = check_key_boot(key_code);
		debugf("cboot:get mode from keypad:0x%x\n",key_code);
		//20220615, Added by zhu_jun for long press pwrkey 3s to bootup begin
		while (SCI_GetTickCount()<3000 && !power_button_pressed()) {
			mdelay(50);
		}
		if (SCI_GetTickCount()<3000) {
			debugf("release pwrkey too early(%dms), poweroff!\n",SCI_GetTickCount());
			power_down_devices(0);
		}
		//20220615, Added by zhu_jun for long press pwrkey 3s to bootup end
		switch(key_mode) {
		  case CMD_FASTBOOT_MODE:
			  return  CMD_FASTBOOT_MODE;
		  case CMD_RECOVERY_MODE:
//20220613, Added by zhu_jun for BSP disable enter recovery mode via keys on MP&User version begin
#if !defined(DEBUG) && defined(WT_FINAL_RELEASE)
			  if (check_efused()) {
				  debugf("[%s] fixed recovery mode!\n", __func__);
				  return CMD_NORMAL_MODE;
			  }
#endif
//20220613, Added by zhu_jun for BSP disable enter recovery mode via keys on MP&User version end
		  	  bootcause_cmdline="Keypad trigger to recovery";
			  return CMD_RECOVERY_MODE;
		  /*case CMD_FACTORYTEST_MODE:
		  	  bootcause_cmdline="Keypad trigger to factorytest";
			  return CMD_FACTORYTEST_MODE;*/
		  default:
		  	  bootcause_cmdline="Pbint triggered";
			  return CMD_NORMAL_MODE;
		}
	}else {
		return CMD_UNDEFINED_MODE;
	}
}

// 6 get mode from gpio
boot_mode_enum_type  get_mode_from_gpio_extend(void)
{
	if (get_mode_from_gpio()) {
		bootcause_cmdline="pbint2 triggered";
		debugf("Pbint2 triggered, do normal mode\n");
		return CMD_NORMAL_MODE;
	} else {
		return CMD_UNDEFINED_MODE;
	}
}

/** Start of PayJoy changes. */
uint8_t check_payjoy_flag() {
    uint64_t offset;
    uint8_t val;

    offset = 2048*1024 - 1 - 1000 - 1024 - 10000;
    // read payjoy flag from persistent partition.
    // you may change the actual number of offset according to the size of FRP or persistent partition
    common_raw_read("persist", 1, offset,&val); // call mmc_read
    return val;
}

#if defined CONFIG_ANDROID_AB
int do_selcet_ab(void)
{
	int ret;
	char slot[3];

#if defined (CONFIG_FPGA) && defined (CONFIG_DDR_BOOT)
	ret = 0;
#else
	ret = ab_select_slot();
#endif
	if (ret < 0) {
		errorf("Android boot failed, error %d.\n", ret);
		return -1;
	}

	/* Android standard slot names are 'a', 'b', ... */
	slot[0] = '_';
	slot[1] = BOOT_SLOT_NAME(ret);
	slot[2] = '\0';
	if (setenv("slot", slot)) {
		errorf("set env fail!\n");
		return -2;
	}

	printf("ANDROID: Booting slot%s\n", slot);

	return 0;
}
#endif

//20220511, Added by zhu_jun for the power-on write protect request start
#ifdef CONFIG_EMMC_WP
#define ENABLE_WRITE_PROTECT	1
#define DISABLE_WRITE_PROTECT	0
extern int g_part_protected;
#endif
//20220511, Added by zhu_jun for the power-on write protect request end

int do_cboot(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
	volatile int i;
	boot_mode_enum_type bootmode = CMD_UNDEFINED_MODE;
	CBOOT_MODE_ENTRY boot_mode_array[CMD_MAX_MODE] ={0};
	chipram_env_t* cr_env;

	if(argc > 2)
		return CMD_RET_USAGE;
#ifdef CONFIG_AUTOLOAD_MODE
	autoload_mode();
#endif

#ifdef CONFIG_ANDROID_AB
	cr_env = get_chipram_env();
	if (0x55AA55AA == cr_env->spl_adjust_flag) {
	    /* spl rollback */
	    if(ab_slot_rollback_spl(true) == -1) {
	        return 0;
	    }

	}

	do_selcet_ab();

#endif
	//20220613, Added by zhu_jun for VSI-609 BSP disable UNISOC DIAG  port on MP&User version begin
	usb_enum_permission_check();
	//20220613, Added by zhu_jun for VSI-609 BSP disable UNISOC DIAG  port on MP&User version end

	//20220511, Added by zhu_jun for the power-on write protect request start
	#ifdef CONFIG_EMMC_WP
	if (g_part_protected) {
		if (common_set_powp("protect_data")) {
			errorf("partition protect_data can't be protected,pls check it\n");
			return -1;
		}
		debugf("do cboot pwp success\n");
	}
	#endif
	//20220511, Added by zhu_jun for the power-on write protect request end

#if defined CONFIG_AUTOBOOT
	if (reboot_mode_check() == CMD_AUTODLOADER_REBOOT)
	{
		lr_cause = LR_ABNORMAL;
		autodloader_mode();
	}
	else    {
	#if defined CONFIG_X86
		write_sysdump_before_boot_extend();//if autoboot kernel is crash and reboot,the uboot go to sysdump in x86;
	#endif
		normal_mode();
	}
#endif

#if defined CONFIG_ZEBU || defined CONFIG_FPGA
	normal_mode();
#endif
	boot_pwr_check();
	if (2 == argc) {
		/*argument has the highest priority to determine the boot mode*/
		bootmode = get_mode_from_arg(argv[1]);
	} else {
		for (i = 0;  i < CHECK_BOOTMODE_FUN_NUM; i++) {
			if (0 == s_boot_func_array[i]) {
				bootmode = CMD_POWER_DOWN_DEVICE;
				break;
			}
			bootmode = s_boot_func_array[i]();
			if (CMD_UNDEFINED_MODE == bootmode) {

				continue;
			} else {
				debugf("get boot mode in boot func array[%d]\n",i);
				break;
			}
		}
	}

	board_boot_mode_regist(boot_mode_array);
	/*add by zesheng for hmd enterprise api start*/
	char buffast[1];
	memset(buffast, 0, sizeof(buffast));
	if (0 != common_raw_read("miscdata", (uint64_t)sizeof(char),(uint64_t)HMD_EN_API_FASTBOOT_MODE_OFFSET, buffast)) {
		debugf("zesheng common_raw_read miscdata fial !\n");
	}else{
		if(!strncmp(buffast, "1",1) && (bootmode == CMD_RECOVERY_MODE || bootmode == CMD_FASTBOOT_MODE)){
			debugf("zesheng hmd can not fastboot! status=%s\n",buffast);
			bootmode = CMD_NORMAL_MODE;
		}else{
			debugf("zesheng hmd can fastboot! status=%s\n",buffast);
		}
	}
	/*add by zesheng for hmd enterprise api end*/
    	// Start of PayJoy changes. 
    	// Don't let phone get into fastboot mode by command "adb reboot bootloader" or other ways
    	// if the payjoy flag has been set to 1.
    	if (bootmode == CMD_FASTBOOT_MODE) {
       		 if (1 == check_payjoy_flag()) {
        	    bootmode = CMD_NORMAL_MODE;
        	 }
    	}
    	/* Don't let phone get into recovery mode if the payjoy flag has been set to 1.

        Attention: only prevents users enter recovery mode by command "adb reboot recovery" or
        pressing power and volume buttons, should not affect entering recovery mode by system OTA upgrading
        or factory reset from Settings. That means the bootloader should check payjoy flag in persistent/frp
        partition at first, then check BCB(Bootloader Control Block) in misc partition.

    	if (bootmode == CMD_RECOVERY_MODE) {
       	 if (1 == check_payjoy_flag()){
        	    bootmode = CMD_NORMAL_MODE;
       	 }
    	}
    	*/
    	// End of PayJoy changes.
	printf("enter boot mode %d\n", bootmode);


#ifdef CONFIG_WT_COMPILE_FACTORY_VERSION
       if(bootmode == CMD_CHARGE_MODE) {
               printf("FACTORY_VERSION:plug in usb to boot up\n");
               //normal_mode();
               bootmode = CMD_NORMAL_MODE;
       }
#endif

    s_boot_mode = bootmode;
	printf("enter boot mode %d\n", bootmode);

//Add by jack,20220513,ATO vereion connect usb to power on end
	if ((bootmode > CMD_POWER_DOWN_DEVICE) &&(bootmode < CMD_MAX_MODE)&& (0 != boot_mode_array[bootmode])) {
		write_log();

		boot_mode_array[bootmode]();
	} else {
#ifdef CONFIG_FPGA
		/*FPGA has no power button ,if hasn't detect any mode ,use normal mode*/
		debugf("FPGA use normal mode instead of power down.\n");
		normal_mode();
#else
		debugf("power down device\n");
		write_log();
		power_down_devices(0);
#endif
		while(1);
	}

	  return 0;
}


U_BOOT_CMD(
		  cboot, CONFIG_SYS_MAXARGS, 1, do_cboot,
		  "choose boot mode",
		  "mode: \nrecovery, fastboot, dloader, charge, normal, vlx, caliberation.\n"
		  "cboot could enter a mode specified by the mode descriptor.\n"
		  "it also could enter a proper mode automatically depending on "
		  "the environment\n"
		);

