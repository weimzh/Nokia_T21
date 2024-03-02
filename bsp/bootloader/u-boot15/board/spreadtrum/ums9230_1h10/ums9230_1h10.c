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
#include "board_id.h"

#define ADC_CHANNEL_FOR_NV    3
#define WCN_GPIO	175

//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically begin
#include "powp_disable.h"
//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically end
//20220511, Added by zhu_jun for the power-on write protect request start
#define ENABLE_WRITE_PROTECT	1
#define DISABLE_WRITE_PROTECT	0
//20220511, Added by zhu_jun for the power-on write protect request end
DECLARE_GLOBAL_DATA_PTR;
phys_size_t real_ram_size = 0x40000000;
//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically begin
int POWP_flag = 0;/*0--protect_disable,1--protect_enable*/
//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically end
int india_version_flag = 0;

phys_size_t get_real_ram_size(void)
{
        return real_ram_size;
}

void enable_global_clocks(void)
{
	u32 val;
        sci_glb_set(REG_AON_APB_APB_EB0, BIT_AON_APB_GPU_EB |
	BIT_AON_APB_MM_EB);
	val = sci_glb_read(REG_PMU_APB_PWR_STATUS_DBG_6);
	udelay(1000);
	while (val & BIT_PMU_APB_PD_MM_STATE(~0));
	sci_glb_set(REG_MM_AHB_AHB_EB, BIT_MM_AHB_CKG_EB);
}

static void thm_overheate_en(void)
{
	sci_glb_set(REG_AON_APB_OVERHEAT_CTRL,
		    BIT_AON_APB_THM0_OVERHEAT_ALARM_ADIE_EN |
		    BIT_AON_APB_THM1_OVERHEAT_ALARM_ADIE_EN |
		    BIT_AON_APB_THM2_OVERHEAT_ALARM_ADIE_EN );
}

extern void setup_chipram_env(void);
extern void usb_uart_mux_config(void);

int board_init(void)
{
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
	/*config serial console*/
#ifdef CONFIG_DM_SERIAL
	serial_init();
	console_init_f();
#endif
	ADI_init();
	/*FPGA forbiden*/
	misc_init();
	regulator_init();
	pmic_adc_Init();
	/*FPGA forbiden*/
	pin_init();
#ifdef CONFIG_USBPINMUX
	usb_uart_mux_config();
#endif
	sprd_eic_init();
	sprd_gpio_init();
	sprd_led_init();
	/*FPGA forbiden*/
	sprd_pmu_lowpower_init();
	TDPllRefConfig(1);
	enable_global_clocks();
	thm_overheate_en();
	/* ufs board need to close sindrv  */
	if (get_bootdevice() == BOOT_DEVICE_UFS) {
		sci_glb_clr(REG_AON_APB_MIPI_CSI_POWER_CTRL,
			    BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_ENA);
		sci_glb_set(REG_AON_APB_MIPI_CSI_POWER_CTRL,
			    BIT_AON_APB_ANALOG_BB_TOP_SINDRV_ENA_AUTO_EN);
	}
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
	sprdchg_sgm41513a_init();
	sprdbat_init();
}

//add for protect protect_data partition
#ifdef CONFIG_EMMC_WP
int g_part_protected = DISABLE_WRITE_PROTECT;
//+hz added,the baiwei 128GB emmc protection problem
extern int is_baiwei_128GB_emmc; //is_baiwei_128GB_emmc
//-hz added,the baiwei 128GB emmc protection problem
void part_protect_init(int enable)
{
#ifndef CONFIG_NAND_BOOT
	if (gd->boot_device != BOOT_DEVICE_EMMC) {
		errorf("write protection is not supported in current device\n");
		g_part_protected = DISABLE_WRITE_PROTECT;
		return;
	}
	if (enable && !is_baiwei_128GB_emmc)
		g_part_protected = ENABLE_WRITE_PROTECT;
	 else
#endif
		g_part_protected = DISABLE_WRITE_PROTECT;
}
#endif
//add for protect protect_data partition  end

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
//20220511, Added by zhu_jun for the power-on write protect request start
#ifdef CONFIG_EMMC_WP
	/* Open PWP here */
//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically begin
	POWP_flag = !powp_verify();
	part_protect_init(POWP_flag);
//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically end
#endif
//20220511, Added by zhu_jun for the power-on write protect request end
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

//20220607, Added by zhu_jun Block/unblock Device getting into fastboot begin
int check_block_fastboot_flag()
{
    char read_buf[64];
    memset(read_buf, 0, sizeof(read_buf));
    oem_repair_read_mmc_ex("block_fastboot_mode", read_buf, BLOCK_FASTBOOT_LEN) ;
    debugf("block fastboot mode, read_buf = %s\n", read_buf);

    return (!strncmp(read_buf, BLOCK_FASTBOOT_FLAG, BLOCK_FASTBOOT_LEN));
}
//20220607, Added by zhu_jun Block/unblock Device getting into fastboot end


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
	//20220614, Added by zhu_jun for red eio warning screen when dm-verity device corrupted begin
	MODE_REGIST(CMD_DMEIO_MODE, dmeio_mode);
	//20220614, Added by zhu_jun for red eio warning screen when dm-verity device corrupted end
	return ;
}

static const int wcn_crystal_type[] = {
	0,/*TCXO*/
	1/*TSX*/
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
	unsigned int gpio_val = 0;

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
	6, /* india sku4 + nfc 			15k */
	5, /* india sku3 wifionly 		30k */
	4, /* india sku1 row 			39k */
	3, /* sku4 row + nfc 			10k */
	2, /* sku3 wifionly 			24k */
	1, /* hw_ver01.nv  sku1 row 	56k */
	0 /* hw_ver00.nv   sku2 latam 	47k */
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
	
	// sku4 row + nfc 20uA*10k=200mV
	if (vol >= 100 && vol <= 256) {
		debugf("vol: %d sku4 row + nfc\n", vol);
		if(india_version_flag)
			level = 1;
		else
			level = 4;
	}
	
	// india sku4 row + nfc 20uA*15k=300mV
	if (vol >= 260 && vol <= 390) {
		debugf("vol: %d india sku4 row + nfc\n", vol);
		level = 1;
	}
	
	// sku3 wifionly 20uA*24k=480mV
	if (vol >= 400 && vol <= 550) {
		debugf("vol: %d sku3 wifionly\n", vol);
		if(india_version_flag)
			level = 2;
		else
			level = 5;
	}

	// india sku3 row + nfc 20uA*30k=600mV
	if (vol >= 552 && vol <= 690) {
		debugf("vol: %d india sku3 row + nfc\n", vol);
		level = 2;
	}

	// india sku1 row + nfc 20uA*39k=780mV
	if (vol >= 700 && vol <= 830) {
		debugf("vol: %d india sku1 row + nfc\n", vol);
		level = 3;
	}
	
	// sku2 latam 20uA*47k=940mV
	if (vol >= 840 && vol <= 1010) {
		debugf("vol: %d sku2 latam\n", vol);
		level = 7;
	}
	
	// sku1 row 20uA*56k=1120mV
	if (vol >= 1020 && vol <= 1186) {
		debugf("vol: %d sku1 row\n", vol);
		if(india_version_flag)
			level = 3;
		else
			level = 6;
	}

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
	unsigned int adc_val = 0;

	adc_val = get_adc_value_board(ADC_CHANNEL_FOR_NV);
	debugf("rfboard.id = %d\n", adc_val);

	return adc_val;
}

//20220512, Added by zhu_jun for boardid start
static int search_boardid(int gpio_value)
{
	int length;
	int i,boardid = 0;

	length = sizeof(board_id_arr)/sizeof(board_id_arr[0]);

	for(i = 0;i < length ;i++)
	{
		if(gpio_value == board_id_arr[i].board_gpio_value)
		{
		    boardid = i;
		    break;
		}
	}

	if(i == length)
	{
		boardid = i - 1;
		debugf("WT board_id unknown\n");
	}
	return boardid;
}

int  target_get_boardid()
{
	int get_board_gpio_value = 0;
	int boardid = 0;
	int rfboard_id = 0;
	
	rfboard_id = sprd_get_bandinfo();
	
	get_board_gpio_value =(rfboard_id <<4)|(gpio_state(WT_GPIO_BOARD_ID3)<<2)|(gpio_state(WT_GPIO_BOARD_ID2)<<1)|(gpio_state(WT_GPIO_BOARD_ID1));//ID3 ID2 ID1
	debugf("WT get_board_gpio_value=%x  \n", get_board_gpio_value);

	//get_board_gpio_value = (~get_board_gpio_value)&0x1f;
	boardid = search_boardid(get_board_gpio_value);
	//debugf("WT boardid=%x  \n", boardid);
	return boardid;
}
//20220512, Added by zhu_jun for boardid end

//20220602,Added by zhu_jun for suport fastboot command:fastboot getvar boardid begin
char *target_get_boardname(void)
{
	return board_id_arr[target_get_boardid()].board_name;
}
//20220602,Added by zhu_jun for suport fastboot command:fastboot getvar boardid end

//20220521, Added by zhu_jun for hardware id start

static int search_hardwareid(int gpio_value)
{
	int length;
	int i,hardwareid = 0;

	length = sizeof(hardware_id_arr)/sizeof(hardware_id_arr[0]);

	for(i = 0;i < length ;i++)
	{
		if(gpio_value == hardware_id_arr[i].hardware_gpio_value)
		{
		    hardwareid = i;
		    break;
		}
	}

	if(i == length)
	{
		hardwareid = i - 1;
		debugf("WT board_id unknown\n");
	}
	return hardwareid;
}

int sprd_get_hardwareid_info(void)
{
	int get_hardwareid_gpio_value = 0;
	int hardwareid = 0;

	get_hardwareid_gpio_value = (gpio_state(WT_GPIO_BOARD_ID4)<<1)|(gpio_state(WT_GPIO_BOARD_ID5));// ID4 ID5
	debugf("get_hardwareid_gpio_value = %d\n", get_hardwareid_gpio_value);

	hardwareid = search_hardwareid(get_hardwareid_gpio_value);
	
	return hardwareid;
}
//20220521, Added by zhu_jun for hardware id end

#ifdef CONFIG_SENSOR_HUB_UBOOT
int sprd_sensor_bandlist(struct sensor_phypara **sensorlist)
{
	*sensorlist = sensor_board_phylist;
	return sizeof(sensor_board_phylist)/sizeof(sensor_board_phylist[0]);
}
#endif

