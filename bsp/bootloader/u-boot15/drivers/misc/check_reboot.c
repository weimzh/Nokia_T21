#include <common.h>
#include <boot_mode.h>
#include <asm/arch/sprd_reg.h>
#include <asm/arch/common.h>
#include "adi_hal_internal.h"
#include <asm/arch/check_reboot.h>
#include <asm/arch/sprd_debug.h>
#include <sprd_pmic_misc.h>
#include <sprd_log.h>
#include <sprd_common_rw.h>
unsigned reboot_reg = 0;
unsigned sysdump_flag = 0;
unsigned cmd_fastboot=0;
extern int hw_watchdog_rst_pending(void);
extern int is_hw_smpl_enable(void);
extern void power_down_cpu(ulong ignored);
extern char *bootcause_cmdline;
extern int low_bat;

#define   HWRST_RTCSTATUS_USB_FAST_BOOT	(0x66)
static void rtc_domain_reg_write(uint32_t val)
{
#if  !defined(CONFIG_ADIE_SC2713S)  &&  !defined(CONFIG_ADIE_SC2713)
	sci_adi_write(ANA_REG_GLB_RTC_RST1, (~val),(~0)); //clear status reg
	sci_adi_write(ANA_REG_GLB_RTC_RST0, (val),(~0));  //set status reg
#else
	val = val;
#endif
}

static uint32_t rtc_domain_reg_read(void)
{
#if  !defined(CONFIG_ADIE_SC2713S)  &&  !defined(CONFIG_ADIE_SC2713)
	return sci_adi_read(ANA_REG_GLB_RTC_RST2);  //read
#else
	return 0;
#endif
}

unsigned check_reboot_mode(void)
{
	unsigned rst_mode = 0, reg_rst_mode = 0;
	unsigned hw_rst_mode = ANA_REG_GET(ANA_REG_GLB_POR_SRC_FLAG);

	lr_cause = LR_NORMAL;
	debugf("hw_rst_mode==%x\n", hw_rst_mode);
	reg_rst_mode = hw_rst_mode;
	reg_rst_mode &= (0xffff & BIT_REG_RST_FLG);
	printf("check_reboot_mode:get raw reg_rst_mode is %x\n", reg_rst_mode);
	debugf("check_reboot_mode rtc_domain_reg_read()==%x\n", rtc_domain_reg_read());
	sci_adi_set(ANA_REG_GLB_POR_SRC_FLAG, BIT_REG_SOFT_RST_FLG_CLR);
	sci_adi_set(ANA_REG_GLB_POR_7S_CTRL, BIT_PBINT_FLAG_CLR |
		    BIT_PBINT2_FLAG_CLR | BIT_CHGR_INT_FLAG_CLR |
		    BIT_EXT_RSTN_FLAG_CLR );
	udelay(10);
	sci_adi_clr(ANA_REG_GLB_POR_7S_CTRL, BIT_PBINT_FLAG_CLR|
		    BIT_PBINT2_FLAG_CLR | BIT_CHGR_INT_FLAG_CLR |
		    BIT_EXT_RSTN_FLAG_CLR );
	sci_adi_clr(ANA_REG_GLB_POR_SRC_FLAG, BIT_REG_SOFT_RST_FLG_CLR);

/*for download mode reboot system */
	if(HWRST_RTCSTATUS_DOWNLOAD_BOOT == rtc_domain_reg_read()) {
		debugf("rtc_domain_reg get reboot normal mode \n");
		rtc_domain_reg_write(HWRST_RTCSTATUS_DEFAULT);
		ANA_REG_SET(ANA_REG_GLB_POR_RST_MONITOR, 0); //clear flag
		return CMD_NORMAL_MODE;
	}
/*for download mode reboot system ---- end*/

	reboot_reg = rst_mode = ANA_REG_GET(ANA_REG_GLB_POR_RST_MONITOR);
	sysdump_flag = rst_mode & HWRST_STATUS_SYSDUMPEN;
	printf("check_reboot_mode:get raw rst_mode is %x and sysdump_flag is %x\n",rst_mode,sysdump_flag);
	rst_mode &= 0xFF;
	ANA_REG_SET(ANA_REG_GLB_POR_RST_MONITOR, sysdump_flag | 0); //clear flag

	/* clear the flag which used by modem side in any scenes , prevent some errors */
	ANA_REG_SET(ANA_REG_GLB_WDG_RST_MONITOR, 0);

	debugf("rst_mode==%x\n",rst_mode);
	if(rst_mode == 0x30)
	{
		cmd_fastboot = 1;
	}
	if(HWRST_RTCSTATUS_USB_FAST_BOOT == rtc_domain_reg_read() && rst_mode == 0) {
		debugf("FAST_BOOT rtc_domain_reg get reboot normal mode \n");
		ANA_REG_SET(ANA_REG_GLB_POR_RST_MONITOR, 0); //clear flag
		return CMD_NORMAL_MODE;
	}
	if(hw_watchdog_rst_pending()){
		debugf("hw watchdog rst int pending\n");
		if(rst_mode == HWRST_STATUS_RECOVERY) {
			bootcause_cmdline="Reboot into reocovery";
			return CMD_RECOVERY_MODE;
		} else if(rst_mode == HWRST_STATUS_FASTBOOT)
			{	
				if(1 == low_bat)
					{	
						bootcause_cmdline="Reboot into normal";
						return CMD_NORMAL_MODE;
					}
				else
					return CMD_FASTBOOT_MODE;
			}
		//20220614, Added by zhu_jun for red eio warning screen when dm-verity device corrupted begin
		else if(rst_mode == HWRST_STATUS_DMEIO)
			return CMD_DMEIO_MODE;
		//20220614, Added by zhu_jun for red eio warning screen when dm-verity device corrupted end
		else if(rst_mode == HWRST_STATUS_NORMAL) {
			bootcause_cmdline="Reboot into normal";
			return CMD_NORMAL_MODE;
		} else if(rst_mode == HWRST_STATUS_NORMAL2) {
			bootcause_cmdline="Reboot into normal2";
			return CMD_WATCHDOG_REBOOT;
		} else if(rst_mode == HWRST_STATUS_NORMAL3) {
			bootcause_cmdline="Reboot into normal3";
			return CMD_AP_WATCHDOG_REBOOT;
		} else if(rst_mode == HWRST_STATUS_ALARM) {
			bootcause_cmdline="Reboot into alarm";
			return CMD_ALARM_MODE;
		} else if(rst_mode == HWRST_STATUS_SLEEP) {
			bootcause_cmdline="Reboot into sleep";
			return CMD_SLEEP_MODE;
		} else if(rst_mode == HWRST_STATUS_CALIBRATION) {
			bootcause_cmdline="Reboot into calibration";
			return CMD_CALIBRATION_MODE;
		} else if(rst_mode == HWRST_STATUS_PANIC) {
			lr_cause = LR_ABNORMAL;
			bootcause_cmdline="Reboot into panic";
			return CMD_PANIC_REBOOT;
		} else if(rst_mode == HWRST_STATUS_SPECIAL) {
			bootcause_cmdline="Reboot into special";
			return CMD_SPECIAL_MODE;
		} else if(rst_mode == HWRST_STATUS_AUTODLOADER) {
			lr_cause = LR_ABNORMAL;
			return CMD_AUTODLOADER_REBOOT;
		} else if(rst_mode == HWRST_STATUS_IQMODE) {
			bootcause_cmdline="Reboot into iqmode";
			return CMD_IQ_REBOOT_MODE;
		} else if(rst_mode == HWRST_STATUS_SPRDISK) {
			bootcause_cmdline="Reboot into sprdisk";
			return CMD_SPRDISK_MODE;
		} /*else if(rst_mode == HWRST_STATUS_FACTORYTEST) {
			bootcause_cmdline="Reboot into factorytest";
			return CMD_FACTORYTEST_MODE;
		}*/
#if defined(CONFIG_X86)
		else if(rst_mode == HWRST_STATUS_MOBILEVISOR)
			return CMD_VMM_PANIC_MODE;
		else if(rst_mode == HWRST_STATUS_SECURITY)
			return CMD_TOS_PANIC_MODE;
#elif defined(HWRST_STATUS_SECURITY)
		else if(rst_mode == HWRST_STATUS_SECURITY) {
			lr_cause = LR_ABNORMAL;
			bootcause_cmdline="Reboot into tos_panic";
			return CMD_TOS_PANIC_MODE;
		}
#endif
		else{
			lr_cause = LR_UNKNOWN;
			debugf(" Boot failure triggered by reboot\n");
			bootcause_cmdline="Reboot into abnormal";
			return CMD_ABNORMAL_REBOOT_MODE;
		}
	} else if(reg_rst_mode) {
		printf("register reboot method reg_rst_mode is %x\n", reg_rst_mode);
		if(rst_mode == HWRST_STATUS_RECOVERY) {
			bootcause_cmdline="Reboot into reocovery";
			return CMD_RECOVERY_MODE;
		} else if(rst_mode == HWRST_STATUS_FASTBOOT)
			{	
				if(1 == low_bat)
					{	
						bootcause_cmdline="Reboot into normal";
						return CMD_NORMAL_MODE;
					}
				else
					return CMD_FASTBOOT_MODE;
			}
		else if(rst_mode == HWRST_STATUS_NORMAL) {
			bootcause_cmdline="Reboot into normal";
			return CMD_NORMAL_MODE;
		} else if(rst_mode == HWRST_STATUS_ALARM) {
			bootcause_cmdline="Reboot into alarm";
			return CMD_ALARM_MODE;
		} else if(rst_mode == HWRST_STATUS_SLEEP) {
			bootcause_cmdline="Reboot into sleep";
			return CMD_SLEEP_MODE;
		} else if(rst_mode == HWRST_STATUS_CALIBRATION) {
			bootcause_cmdline="Reboot into calibration";
			return CMD_CALIBRATION_MODE;
		} else if(rst_mode == HWRST_STATUS_PANIC) {
			lr_cause = LR_ABNORMAL;
			bootcause_cmdline="Reboot into panic";
			return CMD_PANIC_REBOOT;
		} else if(rst_mode == HWRST_STATUS_SPECIAL) {
			bootcause_cmdline="Reboot into special";
			return CMD_SPECIAL_MODE;
		} else if(rst_mode == HWRST_STATUS_AUTODLOADER) {
			lr_cause = LR_ABNORMAL;
			return CMD_AUTODLOADER_REBOOT;
		} else if(rst_mode == HWRST_STATUS_IQMODE) {
			bootcause_cmdline="Reboot into iqmode";
			return CMD_IQ_REBOOT_MODE;
		} else if(rst_mode == HWRST_STATUS_SPRDISK) {
			bootcause_cmdline="Reboot into sprdisk";
			return CMD_SPRDISK_MODE;
		} else if(rst_mode == HWRST_STATUS_FACTORYTEST) {
			bootcause_cmdline="Reboot into factorytest";
			return CMD_FACTORYTEST_MODE;
		}
#if defined(CONFIG_X86)
		else if(rst_mode == HWRST_STATUS_MOBILEVISOR)
			return CMD_VMM_PANIC_MODE;
		else if(rst_mode == HWRST_STATUS_SECURITY)
			return CMD_TOS_PANIC_MODE;
#elif defined(HWRST_STATUS_SECURITY)
		else if(rst_mode == HWRST_STATUS_SECURITY) {
			lr_cause = LR_ABNORMAL;
			bootcause_cmdline="Reboot into tos_panic";
			return CMD_TOS_PANIC_MODE;
		}
#endif
	} else {
			printf("is_7s_reset 0x%x, systemdump 0x%x\n", is_7s_reset(), is_7s_reset_for_systemdump());
			debugf("is_hw_smpl_enable %d\n", is_hw_smpl_enable());
			debugf("no hw watchdog rst int pending\n");
			if(is_7s_reset_for_systemdump()) {
				lr_cause = LR_ABNORMAL;
				bootcause_cmdline="7s reset for systemdump";
				return CMD_UNKNOW_REBOOT_MODE;
			} else if(hw_rst_mode & SW_EXT_RSTN_STATUS) {
				lr_cause = LR_LONG_PRESS;
				bootcause_cmdline="Software extern reset status";
				return CMD_EXT_RSTN_REBOOT_MODE;
			} else if(rst_mode == HWRST_STATUS_NORMAL2) {
				lr_cause = LR_UNKNOWN;
				bootcause_cmdline="STATUS_NORMAL2 without watchdog pending";
				return CMD_UNKNOW_REBOOT_MODE;
			} else if(is_7s_reset()) {
				lr_cause = LR_ABNORMAL;
				bootcause_cmdline="7s reset";
				return CMD_NORMAL_MODE;
			}
#ifndef CONFIG_SS_FUNCTION
			else if(is_smpl_bootup()) {
				lr_cause = LR_ABNORMAL;
				bootcause_cmdline="Sudden momentary power loss";
				debugf("SMPL bootup!\n");
				return CMD_NORMAL_MODE;
			}
#endif
			else
				return 0;
	}
}

void reset_to_normal(unsigned reboot_mode)
{
	unsigned rst_mode = 0;

	write_log_last();
#if  !defined(CONFIG_ADIE_SC2713S)  &&  !defined(CONFIG_ADIE_SC2713)
	if (CMD_NORMAL_MODE == reboot_mode) {
		rtc_domain_reg_write(HWRST_RTCSTATUS_DOWNLOAD_BOOT);
		udelay(300);
	}
#endif
	if (reboot_mode ==  CMD_NORMAL_MODE) {
		rst_mode = HWRST_STATUS_NORMAL;
	}

	ANA_REG_SET(ANA_REG_GLB_POR_RST_MONITOR, rst_mode);

	reset_cpu(0);
}
void reboot_devices(unsigned reboot_mode)
{
	unsigned rst_mode = 0;

	write_log_last();
	if(reboot_mode == CMD_RECOVERY_MODE){
		rst_mode = HWRST_STATUS_RECOVERY;
	}else if(reboot_mode == CMD_FASTBOOT_MODE){
		rst_mode = HWRST_STATUS_FASTBOOT;
	}else if(reboot_mode == CMD_NORMAL_MODE){
		rst_mode = HWRST_STATUS_NORMAL;
//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency begin
	}else if(reboot_mode == CMD_AUTODLOADER_REBOOT){
		rst_mode = HWRST_STATUS_AUTODLOADER;
//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency end
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	}else if(reboot_mode == CMD_AUTODLOADER_REBOOT){
		rst_mode = HWRST_STATUS_AUTODLOADER;
#endif
	}else{
		rst_mode = 0;
	}

	ANA_REG_SET(ANA_REG_GLB_POR_RST_MONITOR, rst_mode);

	reset_cpu(0);
}
void power_down_devices(unsigned pd_cmd)
{
	write_log_last();
	power_down_cpu(0);
}

int fastboot_charger_connected(void)
{
	sprd_eic_request(EIC_CHG_INT);

	return !!sprd_eic_get(EIC_CHG_INT);
}

