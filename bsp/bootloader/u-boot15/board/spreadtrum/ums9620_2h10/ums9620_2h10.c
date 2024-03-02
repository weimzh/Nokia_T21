/*
 * (C) Copyright 2014
 * David Feng <fenghua@phytium.com.cn>
 * Sharma Bhupesh <bhupesh.sharma@freescale.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <asm/io.h>
#include <asm/arch/sprd_reg.h>
#include <common.h>
#include <malloc.h>
#include <boot_mode.h>
#include <adi_hal_internal.h>
#include <chipram_env.h>
#include <sprd_adc.h>
#include <sprd_led.h>
#include <sprd_sensor.h>
#include <sprd_battery.h>
#include <sprd_direct_acc_prot.h>
#include <otp_helper.h>
#include <clk.h>
#include "sensor_board_info.h"

#define ADC_CHANNEL_FOR_NV    5
#define WCN_GPIO	54
#define BOARD_ID0_GPIO	133

#define REG_PMU_APB_PWR_STATUS3_DBG 0
DECLARE_GLOBAL_DATA_PTR;
phys_size_t real_ram_size = 0x40000000;

phys_size_t get_real_ram_size(void)
{
        return real_ram_size;
}

void enable_global_clocks(void)
{
	__raw_writel(BIT_AON_APB_MM_EB | BIT_AON_APB_GPU_EB |BIT_AON_APB_AI_EB |
		     BIT_AON_APB_DPU_VSP_EB, REG_AON_APB_APB_EB0 + 0x1000);
	while (__raw_readl(REG_PMU_APB_PWR_STATUS_DBG_6) & BIT_PMU_APB_PD_CAMERA_STATE(~0));
	__raw_writel(BIT_CAMERASYS_GLB_CKG_EN, REG_CAMERASYS_GLB_MM_SYS_EN + 0x1000);
	__raw_writel(BIT_DPU_VSP_APB_CKG_EB, REG_DPU_VSP_APB_APB_EB + 0x1000);
	__raw_writel(BIT_AI_APB_DVFS_EB, REG_AI_APB_APB_EB + 0x1000);
}

static void thm_overheate_en(void)
{
	sci_glb_set(REG_AON_APB_OVERHEAT_CTRL, BIT_AON_APB_THM0_OVERHEAT_ALARM_ADIE_EN |
					BIT_AON_APB_THM1_OVERHEAT_ALARM_ADIE_EN |
					BIT_AON_APB_THM2_OVERHEAT_ALARM_ADIE_EN );
}

static void usb_eye_pattern_set(void)
{
	u32 val;

	val = 0x067bd1c0; //the same as kernel set
	writel(val, REG_ANLG_PHY_G0L_ANALOG_USB20_USB20_TRIMMING);
}

extern int sprd_get_pcbversion(void);
extern void setup_chipram_env(void);
int board_init(void)
{
#ifdef CONFIG_DIRECT_ACC_PROT
	direct_acc_prot_enable();
#endif
	setup_chipram_env();
#ifndef CONFIG_FPGA
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + 0x100;
#ifdef CONFIG_CLK
	clk_init();
#endif
	/*config sensorhub*/
#ifdef CONFIG_SENSOR_HUB_UBOOT
	sprd_sensor_init();
#endif
	ADI_init();
	/*FPGA forbiden*/
	misc_init();
	regulator_init();
	pmic_adc_Init();
	/*FPGA forbiden*/
	pin_init();
	sprd_eic_init();
	sprd_gpio_init();
	sprd_led_init();
	/*FPGA forbiden*/
	sprd_pmu_lowpower_init();
	sci_adi_write(REG_ANA_UMP9622_TSX_CTRL14,
		      BIT_ANA_UMP9622_DCXO_26M_REF_BUF2_DIV_MODE_SEL,
		      BIT_ANA_UMP9622_DCXO_26M_REF_BUF2_DIV_MODE_SEL);
	TDPllRefConfig(1);
	enable_global_clocks();
	thm_overheate_en();
	usb_eye_pattern_set();
	if(sprd_get_pcbversion()) {
		sci_glb_set(REG_AON_APB_APB_EB2, BIT_AON_APB_AON_PWM1_EB);
		__raw_writel(0x10, 0x642e0328);//pwm1 pin func
		__raw_writel(0x82001, 0x642e0728);//pwm1 pin misc
		__raw_writel(0x0, 0x6492004c);//pwm1 clk sel 32k
		__raw_writel(0x7, 0x64034004);
		__raw_writel(0x4, 0x64034008);
		__raw_writel(0x1, 0x64034018);
	}
#else
	sci_glb_set(REG_AON_APB_APB_EB1, BIT_AON_APB_ANA_EB);
#endif
	return 0;
}
int dram_init(void)
{
#ifdef CONFIG_DDR_AUTO_DETECT
	ulong sdram_base = CONFIG_SYS_SDRAM_BASE;
	ulong sdram_size = 0;
	chipram_env_t * env = CHIPRAM_ENV_LOCATION;
	if (CHIPRAM_ENV_MAGIC != env->magic) {
		printf("Chipram magic wrong , ddr data may be broken\n");
		return 0;
	}

	real_ram_size = 0;

	if (env->cs_number == 1) {
		real_ram_size += env->cs0_size;
		debugf("dram cs0 size %x\n",env->cs0_size);
	} else if(env->cs_number == 2){
		real_ram_size += env->cs0_size;
		real_ram_size += env->cs1_size;
		debugf("dram cs0 size %x\ndram cs1 size %x\n",env->cs0_size, env->cs1_size);
	}

	//real_ram_size = get_ram_size((volatile void *)sdram_base, real_ram_size);
#else
	real_ram_size = REAL_SDRAM_SIZE;
#endif

	gd->ram_size = PHYS_SDRAM_1_SIZE;

	return 0;
}

#ifdef CONFIG_DUAL_DDR
void dram_init_banksize(void)
{
	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size = PHYS_SDRAM_1_SIZE;
	gd->bd->bi_dram[1].start = PHYS_SDRAM_2;
	gd->bd->bi_dram[1].size = PHYS_SDRAM_2_SIZE;
}
#endif


int misc_init_r(void)
{
	/*reserver for future use*/
	return 0;
}

static void battery_init(void)
{
	sprdchg_common_cfg();
	sprdchg_bq2560x_init();
	sprdbat_init();
}

int board_late_init(void)
{

 boot_mode_t boot_role;
        extern chipram_env_t* get_chipram_env(void);
        chipram_env_t* cr_env = get_chipram_env();
        boot_role = cr_env->mode;

	boot_pwr_check();

#if !defined(CONFIG_FPGA)
#ifdef CONFIG_NAND_BOOT
	//extern int nand_ubi_dev_init(void);
	nand_ubi_dev_init();
	debugf("nand ubi init OK!\n");
#endif
	battery_init();
	debugf("CHG init OK!\n");
#endif
	board_keypad_init();
	return 0;
}


CBOOT_FUNC s_boot_func_array[CHECK_BOOTMODE_FUN_NUM] = {
	/* 0 get mode from bat low*/
	get_mode_from_bat_low,
	/* 1 get mode from sysdump*/
	write_sysdump_before_boot_extend,
	/* 2 get mode from miscdata flag*/
	get_mode_from_miscdata_boot_flag,
	/* 3 get mode from file*/
	get_mode_from_file_extend,
	/* 4 get mode from watch dog*/
	get_mode_from_watchdog,
	/* 5 get mode from alarm register*/
	get_mode_from_alarm_register,
	/* 6 get mode from calibration detect*/
	get_mode_from_pctool,
	/* 7 get mode from charger*/
	get_mode_from_charger,
	/* 8 get mode from keypad*/
	get_mode_from_keypad,
	/* 9 get mode from gpio*/
	get_mode_from_gpio_extend,

	0
};



void board_boot_mode_regist(CBOOT_MODE_ENTRY *array)
{
	MODE_REGIST(CMD_NORMAL_MODE, normal_mode);
	MODE_REGIST(CMD_RECOVERY_MODE, recovery_mode);
	MODE_REGIST(CMD_FASTBOOT_MODE, fastboot_mode);
	MODE_REGIST(CMD_WATCHDOG_REBOOT, watchdog_mode);
	MODE_REGIST(CMD_AP_WATCHDOG_REBOOT, ap_watchdog_mode);
	MODE_REGIST(CMD_UNKNOW_REBOOT_MODE, unknow_reboot_mode);
	MODE_REGIST(CMD_PANIC_REBOOT, panic_reboot_mode);
	MODE_REGIST(CMD_AUTODLOADER_REBOOT, autodloader_mode);
	MODE_REGIST(CMD_SPECIAL_MODE, special_mode);
	MODE_REGIST(CMD_CHARGE_MODE, charge_mode);
	MODE_REGIST(CMD_ENGTEST_MODE,engtest_mode);
	/*MODE_REGIST(CMD_FACTORYTEST_MODE, factorytest_mode);*/
	MODE_REGIST(CMD_CALIBRATION_MODE, calibration_mode);
	MODE_REGIST(CMD_EXT_RSTN_REBOOT_MODE, normal_mode);
	MODE_REGIST(CMD_IQ_REBOOT_MODE, iq_mode);
	MODE_REGIST(CMD_ALARM_MODE, alarm_mode);
	MODE_REGIST(CMD_SPRDISK_MODE, sprdisk_mode);
	MODE_REGIST(CMD_AUTOTEST_MODE, autotest_mode);
	MODE_REGIST(CMD_APKMMI_MODE, apkmmi_mode);
	MODE_REGIST(CMD_UPT_MODE, upt_mode);
	MODE_REGIST(CMD_ABNORMAL_REBOOT_MODE, abnormal_reboot_mode);
	return ;
}

static const int wcn_crystal_type[] = {
	0,/*TSX*/
	1/*TCXO*/
};

extern int sprd_gpio_request(struct gpio_chip *chip, unsigned offset);
extern int sprd_gpio_direction_input(struct gpio_chip *chip, unsigned offset);
extern int sprd_gpio_get(struct gpio_chip *chip, unsigned offset);

static unsigned int gpio_state(unsigned int GPIO_NUM)
{
	int value = 0 ;

	sprd_gpio_request(NULL, GPIO_NUM);
	sprd_gpio_direction_input(NULL, GPIO_NUM);
	value = sprd_gpio_get(NULL,GPIO_NUM);

	return value > 0;
}

static int get_wcnid(void)
{
	int gpio_val = 0;

	gpio_val |= gpio_state(WCN_GPIO);

	return gpio_val;
}

/* Return wcn crystal type */
int sprd_get_wcn_crystal(void)
{
	int id = get_wcnid();

	return wcn_crystal_type[id];
}

static const int adc2deltanv_table[] = {
	-1, /* reserved */
	-1, /* reserved */
	-1, /* reserved */
	-1, /* reserved */
	-1, /* reserved */
	2, /* hw_ver02.nv */
	0, /* hw_ver00.nv */
	1 /* hw_ver01.nv */
};

static int get_adc_value_board(int channel)
{
	int adc_value = 0,vol= 0 ,level= 0;

	adc_value = pmic_adc_get_value_by_isen(channel,0,15,2000);
	vol = sprd_chan_small_adc_to_vol(channel, 0 , 0 ,adc_value);
	debugf("The voltage is = %d\n",vol);

	if (vol <= 0 || vol >= 1200) {
		errorf("vol is out of ranger [0~1200]\n");
		return -1;
	}

	if (vol >= 9 && vol <= 31)
		level = 0;
	if (vol >= 180 && vol <= 220)
		level = 1;
	if (vol >= 275 && vol <= 325)
		level = 2;
	if (vol >= 446 && vol <= 514)
		level = 3;
	if (vol >= 560 && vol <= 640)
		level = 4;
	if (vol >= 731 && vol <= 829)
		level = 5;
	if (vol >= 883 && vol <= 997)
		level = 6;
	if (vol >= 1054 && vol <= 1186)
		level = 7;

	debugf("level = %d\n",level);

	if(level < 0 || level > 7) {
		errorf("Adc value of rf band if is wrong, the rfboard.id will be set to -1\n");
		return -1;
	}

	return adc2deltanv_table[level];
}

/* Return rf band info */
int sprd_get_bandinfo(void)
{
	int adc_val = 0;

	adc_val = get_adc_value_board(ADC_CHANNEL_FOR_NV);
	debugf("rfboard.id = %d\n", adc_val);

	return adc_val;
}

/* Return boardid info for wcn assert */
int sprd_get_pcbversion(void)
{
	int gpio_val = 0;

	gpio_val |= gpio_state(BOARD_ID0_GPIO);
	debugf("pcbversion = %d\n", gpio_val);

	return gpio_val;
}

#ifdef CONFIG_SENSOR_HUB_UBOOT
int sprd_sensor_bandlist(struct sensor_phypara **sensorlist)
{
	*sensorlist = sensor_board_phylist;
	return sizeof(sensor_board_phylist)/sizeof(sensor_board_phylist[0]);
}
#endif
