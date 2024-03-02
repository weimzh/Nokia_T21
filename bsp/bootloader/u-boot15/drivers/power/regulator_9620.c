#include <common.h>
#include <asm/io.h>
#include "adc_drvapi.h"
#include "adi_hal_internal.h"
#include <asm/arch/sprd_reg.h>

#define __ffs(x) (ffs(x) - 1)
#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))

#define WR_UNLOCK 0x6e7f
#define DCDC_WR_UNLOCK 0x2017

#define IB_ZCD_THRESHOLD_MAX	0x9200
#define IB_ZCD_THRESHOLD_MIN	0x6e00

struct regulator_desc {
	const char *name;
	int type; /* 0 for LDO, 1 for DCDC */
	int def_pd; /* 0 for default on, 1 for default pd */
	u32 step_uv;
	u32 offset_mv;
	u32 pd_set;
	u32 pd_set_bit;
	u32 vol_trm;
	u32 vol_trm_bits;
};

struct dcdc_cali_desc {
	int id;
	const char* name;
	int efuse_block_id;
	u32 efuse_bit_mask;
	u32 pmic_regs_addr;
	u32 pmic_regs_mask;
};

static struct dcdc_cali_desc dcdc_zcd_cfg[] = {
	{0, "DCDC_CPU1_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_CPU1_REG2, BIT_DCDC_CPU1_ZCD(0x3)},
	{1, "DCDC_CPU2_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_CPU2_REG2, BIT_DCDC_CPU2_ZCD(0x3)},
	{2, "DCDC_GPU_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_GPU_REG2, BIT_DCDC_GPU_ZCD(0x3)},
	{3, "DCDC_CORE_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_CORE_REG2, BIT_DCDC_CORE_ZCD(0x3)},
	{4, "DCDC_PUB_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_PUB_REG2, BIT_DCDC_PUB_ZCD(0x3)},
	{5, "DCDC_MEM_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_MEM_REG2, BIT_DCDC_MEM_ZCD(0x3)},
	{6, "DCDC_MEMQ_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_MEMQ_REG2, BIT_DCDC_MEMQ_ZCD(0x3)},
	{7, "DCDC_GEN0_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_GEN0_REG2, BIT_DCDC_GEN0_ZCD(0x3)},
	{8, "DCDC_GEN1_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_GEN1_REG2, BIT_DCDC_GEN1_ZCD(0x3)},
	{9, "DCDC_SRAM0_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_SRAM0_REG2, BIT_DCDC_SRAM0_ZCD(0x3)},
	{10, "DCDC_WPA_ZCD", 5, GENMASK(15,9), ANA_REG_GLB_DCDC_WPA_REG3, BIT_DCDC_WPA_ZCD(0x3)}
};

static struct regulator_desc ump9620_regs_desc[] = {
	{"vddcpu1",	0x1,	0x0,	3125,	0,
	ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_CPU1_PD,
	ANA_REG_GLB_DCDC_CPU1_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddcpu2",	0x1,	0x0,	3125,	0,
	ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_CPU2_PD,
	ANA_REG_GLB_DCDC_CPU2_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddgpu",	0x1,	0x0,	3125,	0,
	ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_GPU_PD,
	ANA_REG_GLB_DCDC_GPU_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddcore",	0x1,	0x0,	3125,	0,
	ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_CORE_PD,
	ANA_REG_GLB_DCDC_CORE_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddpub",	0x1,	0x0,	3125,	0,
	ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_PUB_PD,
	ANA_REG_GLB_DCDC_PUB_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddmem",	0x1,	0x0,	6250,	0,
	ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_MEM_PD,
	ANA_REG_GLB_DCDC_MEM_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddmemq",	0x1,	0x0,	3125,	0,
	ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_MEMQ_PD,
	ANA_REG_GLB_DCDC_MEMQ_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddgen0",	0x1,	0x0,	9375,	0,
	ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_GEN0_PD,
	ANA_REG_GLB_DCDC_GEN0_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddgen1",	0x1,	0x0,	6250,	0,
	ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_GEN1_PD,
	ANA_REG_GLB_DCDC_GEN1_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddsram0",	0x1,	0x0,	3125,	0,
	ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_SRAM0_PD,
	ANA_REG_GLB_DCDC_SRAM0_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddwpa",	0x1,	0x0,	14100,	0,
	ANA_REG_GLB_DCDC_WPA_REG2, BIT_DCDC_WPA_PD,
	ANA_REG_GLB_DCDC_WPA_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"avdd18",	0x0,	0x0,	10000,	1175,
	ANA_REG_GLB_POWER_PD_SW, BIT_LDO_AVDD18_PD,
	ANA_REG_GLB_LDO_AVDD18_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)},
	{"vddrf1v8",	0x0,	0x0,	10000,	1175,
	ANA_REG_GLB_LDO_VDDRF1V8_REG0, BIT_LDO_VDDRF1V8_PD,
	ANA_REG_GLB_LDO_VDDRF1V8_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)},
	{"vddwcn",	0x0,	0x0,	15000,	900,
	ANA_REG_GLB_LDO_VDDWCN_REG0, BIT_LDO_VDDWCN_PD,
	ANA_REG_GLB_LDO_VDDWCN_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)},
	{"vddcamd2",	0x0,	0x0,	15000,	900,
	ANA_REG_GLB_LDO_VDDCAMD2_REG0, BIT_LDO_VDDCAMD2_PD,
	ANA_REG_GLB_LDO_VDDCAMD2_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)},
	{"vddcamd1",	0x0,	0x0,	15000,	900,
	ANA_REG_GLB_LDO_VDDCAMD1_REG0, BIT_LDO_VDDCAMD1_PD,
	ANA_REG_GLB_LDO_VDDCAMD1_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)},
	{"vddcamd0",	0x0,	0x0,	15000,	900,
	ANA_REG_GLB_LDO_VDDCAMD0_REG0, BIT_LDO_VDDCAMD0_PD,
	ANA_REG_GLB_LDO_VDDCAMD0_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)},
	{"vddrf0v9",	0x0,	0x0,	15000,	900,
	ANA_REG_GLB_LDO_VDDRF0V9_REG0, BIT_LDO_VDDRF0V9_PD,
	ANA_REG_GLB_LDO_VDDRF0V9_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)},
	{"vddrf1v1",	0x0,	0x0,	15000,	900,
	ANA_REG_GLB_LDO_VDDRF1V1_REG0, BIT_LDO_VDDRF1V1_PD,
	ANA_REG_GLB_LDO_VDDRF1V1_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)},
	{"avdd12",	0x0,	0x0,	15000,	900,
	ANA_REG_GLB_LDO_AVDD12_REG0, BIT_LDO_AVDD12_PD,
	ANA_REG_GLB_LDO_AVDD12_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)},
	{"vddcamio",	0x0,	0x0,	0,	0,
	ANA_REG_GLB_LDO_VDDCAMIO_REG0, BIT_LDO_VDDCAMIO_PD,
	ANA_REG_GLB_RESERVED_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddcama0",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDCAMA0_REG0, BIT_LDO_VDDCAMA0_PD,
	ANA_REG_GLB_LDO_VDDCAMA0_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddcama1",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDCAMA1_REG0, BIT_LDO_VDDCAMA1_PD,
	ANA_REG_GLB_LDO_VDDCAMA1_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddcama2",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDCAMA2_REG0, BIT_LDO_VDDCAMA2_PD,
	ANA_REG_GLB_LDO_VDDCAMA2_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddcammot0",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDCAMMOT0_REG0, BIT_LDO_VDDCAMMOT0_PD,
	ANA_REG_GLB_LDO_VDDCAMMOT0_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddcammot1",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDCAMMOT1_REG0, BIT_LDO_VDDCAMMOT1_PD,
	ANA_REG_GLB_LDO_VDDCAMMOT1_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddsim0",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDSIM0_REG0, BIT_LDO_VDDSIM0_PD,
	ANA_REG_GLB_LDO_VDDSIM0_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddsim1",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDSIM1_REG0, BIT_LDO_VDDSIM1_PD,
	ANA_REG_GLB_LDO_VDDSIM1_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddsim2",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDSIM2_REG0, BIT_LDO_VDDSIM2_PD,
	ANA_REG_GLB_LDO_VDDSIM2_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddemmccore",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDEMMCCORE_REG0, BIT_LDO_VDDEMMCCORE_PD,
	ANA_REG_GLB_LDO_VDDEMMCCORE_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddsdcore",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDSDCORE_REG0, BIT_LDO_VDDSDCORE_PD,
	ANA_REG_GLB_LDO_VDDSDCORE_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddsdio",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDSDIO_REG0, BIT_LDO_VDDSDIO_PD,
	ANA_REG_GLB_LDO_VDDSDIO_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddufs1v2",	0x0,	0x0,	15000,	900,
	ANA_REG_GLB_LDO_VDDUFS1V2_REG0, BIT_LDO_VDDUFS1V2_PD,
	ANA_REG_GLB_LDO_VDDUFS1V2_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)},
	{"vdd28",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_POWER_PD_SW, BIT_LDO_VDD28_PD,
	ANA_REG_GLB_LDO_VDD28_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddwifipa",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDWIFIPA_REG0, BIT_LDO_VDDWIFIPA_PD,
	ANA_REG_GLB_LDO_VDDWIFIPA_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vdddcxo",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_POWER_PD_SW, BIT_LDO_VDD18_DCXO_PD,
	ANA_REG_GLB_LDO_VDD18_DCXO_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddusb33",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDUSB33_REG0, BIT_LDO_VDDUSB33_PD,
	ANA_REG_GLB_LDO_VDDUSB33_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddldo0",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDLDO0_REG0, BIT_LDO_VDDLDO0_PD,
	ANA_REG_GLB_LDO_VDDLDO0_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddldo1",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDLDO1_REG0, BIT_LDO_VDDLDO1_PD,
	ANA_REG_GLB_LDO_VDDLDO1_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddldo2",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDLDO2_REG0, BIT_LDO_VDDLDO2_PD,
	ANA_REG_GLB_LDO_VDDLDO2_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddldo3",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_LDO_VDDLDO3_REG0, BIT_LDO_VDDLDO3_PD,
	ANA_REG_GLB_LDO_VDDLDO3_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddldo4",	0x0,	0x0,	15000,	900,
	ANA_REG_GLB_LDO_VDDLDO4_REG0, BIT_LDO_VDDLDO4_PD,
	ANA_REG_GLB_LDO_VDDLDO4_REG1,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)},
	{"vddvib",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_VIBR_CTRL0, BIT_LDO_VDDVIB_PD,
	ANA_REG_GLB_VIBR_CTRL0,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)},
	{"vddkpled",	0x0,	0x0,	10000,	1200,
	ANA_REG_GLB_KPLED_CTRL1, BIT_LDO_VDDKPLED_PD,
	ANA_REG_GLB_KPLED_CTRL1,
	BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)},
#ifdef CONFIG_ADIE_UMP9621
	{"vddcpu0",	0x1,	0x0,	3125,	0,
	REG_ANA_UMP9621_POWER_PD_SW, BIT_ANA_UMP9621_DCDC_CPU0_PD,
	REG_ANA_UMP9621_DCDC_CPU0_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddmodem",	0x1,	0x0,	3125,	0,
	REG_ANA_UMP9621_POWER_PD_SW, BIT_ANA_UMP9621_DCDC_MODEM_PD,
	REG_ANA_UMP9621_DCDC_MODEM_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddai",	0x1,	0x1,	3125,	0,
	REG_ANA_UMP9621_POWER_PD_SW, BIT_ANA_UMP9621_DCDC_AI_PD,
	REG_ANA_UMP9621_DCDC_AI_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddsram2",	0x1,	0x0,	3125,	0,
	REG_ANA_UMP9621_POWER_PD_SW, BIT_ANA_UMP9621_DCDC_SRAM2_PD,
	REG_ANA_UMP9621_DCDC_SRAM2_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddsram1",	0x1,	0x0,	3125,	0,
	REG_ANA_UMP9621_POWER_PD_SW, BIT_ANA_UMP9621_DCDC_SRAM1_PD,
	REG_ANA_UMP9621_DCDC_SRAM1_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
	{"vddmm",	0x1,	0x0,	3125,	0,
	REG_ANA_UMP9621_POWER_PD_SW, BIT_ANA_UMP9621_DCDC_MM_PD,
	REG_ANA_UMP9621_DCDC_MM_VOL,
	BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)},
#endif
};

static void dcdc_zcd_cali_cfg()
{
	u32 zcd_val, reg_val, wpa_zcd_val = 3;
	unsigned int i, cnt, shft, efuse_block = 5;

	reg_val = sprd_pmic_efuse_read(efuse_block);
	reg_val &= 0xFE00;

	if (reg_val >= IB_ZCD_THRESHOLD_MAX )
		zcd_val = 2;
	else if (reg_val <= IB_ZCD_THRESHOLD_MIN)
		zcd_val = 0;
	else
		zcd_val = 1;

	cnt = ARRAY_SIZE(dcdc_zcd_cfg) - 1;
	for (i = 0; i < cnt; i++) {
		shft = __ffs(dcdc_zcd_cfg[i].pmic_regs_mask);
		ANA_REG_MSK_OR(dcdc_zcd_cfg[i].pmic_regs_addr,
				zcd_val << shft,
				dcdc_zcd_cfg[i].pmic_regs_mask);
	}

	shft = __ffs(dcdc_zcd_cfg[i].pmic_regs_mask);
	ANA_REG_MSK_OR(dcdc_zcd_cfg[i].pmic_regs_addr,
			wpa_zcd_val << shft,
			dcdc_zcd_cfg[i].pmic_regs_mask);
}

static void dcdc_ripple_cali_cfg()
{
	u32 efuse_pfmad_val, efuse_val;
	unsigned int shft, efuse_block_id = 20;

	efuse_val = sprd_pmic_efuse_read(efuse_block_id);
	efuse_val &= 0xF000;
	efuse_val = efuse_val >> 12;

	ANA_REG_OR(ANA_REG_GLB_DCDC_VLG_SEL0,
		BIT_DCDC_PUB_PFMAD_SW_SEL |
		BIT_DCDC_MEMQ_PFMAD_SW_SEL |
		BIT_DCDC_GPU_PFMAD_SW_SEL |
		BIT_DCDC_CPU2_PFMAD_SW_SEL |
		BIT_DCDC_CORE_PFMAD_SW_SEL |
		BIT_DCDC_GEN1_PFMAD_SW_SEL |
		BIT_DCDC_GEN0_PFMAD_SW_SEL |
		BIT_DCDC_MEM_PFMAD_SW_SEL |
		BIT_DCDC_WPA_PFMAD_SW_SEL
	);

	ANA_REG_OR(ANA_REG_GLB_DCDC_CPU1_REG2, BIT_DCDC_CPU1_PFMAD(0xF));
	ANA_REG_OR(ANA_REG_GLB_DCDC_CPU2_REG2, BIT_DCDC_CPU2_PFMAD(0xF));
	ANA_REG_OR(ANA_REG_GLB_DCDC_GPU_REG2, BIT_DCDC_GPU_PFMAD(0xF));
	ANA_REG_OR(ANA_REG_GLB_DCDC_CORE_REG2, BIT_DCDC_CORE_PFMAD(0xF));
	ANA_REG_OR(ANA_REG_GLB_DCDC_PUB_REG2, BIT_DCDC_PUB_PFMAD(0xF));
	ANA_REG_AND(ANA_REG_GLB_DCDC_WPA_REG3, ~BIT_DCDC_WPA_PFMAD(0xF));

	shft = __ffs(BIT_DCDC_MEM_PFMAD(0xF));
	efuse_pfmad_val = efuse_val + 6;
	ANA_REG_MSK_OR(ANA_REG_GLB_DCDC_MEM_REG2,
			efuse_pfmad_val << shft, BIT_DCDC_MEM_PFMAD(0xF));

	shft = __ffs(BIT_DCDC_MEMQ_PFMAD(0xF));
	efuse_pfmad_val = efuse_val + 1;
	ANA_REG_MSK_OR(ANA_REG_GLB_DCDC_MEMQ_REG2,
			efuse_pfmad_val << shft, BIT_DCDC_MEMQ_PFMAD(0xF));

	shft = __ffs(BIT_DCDC_GEN0_PFMAD(0xF));
	efuse_pfmad_val = efuse_val + 1;
	ANA_REG_MSK_OR(ANA_REG_GLB_DCDC_GEN0_REG2,
			efuse_pfmad_val << shft, BIT_DCDC_GEN0_PFMAD(0xF));

	if (efuse_val >= 3) {
		shft = __ffs(BIT_DCDC_GEN1_PFMAD(0xF));
		efuse_pfmad_val = efuse_val - 3;
		ANA_REG_MSK_OR(ANA_REG_GLB_DCDC_GEN1_REG2,
			efuse_pfmad_val << shft, BIT_DCDC_GEN1_PFMAD(0xF));
	}
}

static void dcxo_cali_init()
{
	ANA_REG_SET(REG_ANA_UMP9622_TSX_WR_PROT_VALUE, BIT_ANA_UMP9622_TSX_WR_PROT_VALUE(0x1990));
	ANA_REG_SET(REG_ANA_UMP9622_TSX_CTRL10, 0x54);
	ANA_REG_SET(REG_ANA_UMP9622_TSX_CTRL5, 0x18);
	ANA_REG_SET(REG_ANA_UMP9622_TSX_CTRL6, 0x14);
	ANA_REG_SET(REG_ANA_UMP9622_TSX_CTRL13, 0x875);
}

struct regulator_desc *regulator_get(const char *id)
{
	unsigned int i;

	if(!id)
		return NULL;

	for (i = 0; i < ARRAY_SIZE(ump9620_regs_desc); i++) {
		if (!strcmp(id, ump9620_regs_desc[i].name))
			return &ump9620_regs_desc[i];
	}

	printf("The regulator %s is not found.\n", id);

	return NULL;
}

int regulator_enable(const char con_id[])
{
	struct regulator_desc *desc = regulator_get(con_id);

	if (desc)
		ANA_REG_BIC(desc->pd_set, desc->pd_set_bit);

	return 0;
}

int regulator_disable(const char con_id[])
{
	struct regulator_desc *desc = regulator_get(con_id);

	if (desc)
		ANA_REG_OR(desc->pd_set, desc->pd_set_bit);

	return 0;
}

unsigned int regulator_get_voltage(const char con_id[])
{
	unsigned int vol;
	u32 reg_val;
	int shft;
	struct regulator_desc *desc = regulator_get(con_id);

	if (!desc)
		return 0;

	shft = __ffs(desc->vol_trm_bits);
	reg_val = ANA_REG_GET(desc->vol_trm);
	reg_val = (reg_val & desc->vol_trm_bits) >> shft;

	vol = desc->offset_mv * 1000 + reg_val * desc->step_uv;
	vol /= 1000;
	printf("Get %s voltage: %dmv, reg_val: 0x%08x.\n", con_id, vol, reg_val);

	return vol;
}

int regulator_set_voltage(const char con_id[], int vol_mv)
{
	unsigned int vol_tmp, shft;
	u32 reg_val;
	struct regulator_desc *desc = regulator_get(con_id);

	if (!desc || vol_mv < 0)
		return -1;
	if (vol_mv < desc->offset_mv)
		return -1;

	shft = __ffs(desc->vol_trm_bits);
	vol_tmp = vol_mv - desc->offset_mv;
	reg_val = DIV_ROUND_UP(vol_tmp * 1000, desc->step_uv);
	if (reg_val > (desc->vol_trm_bits >> shft))
		return -1;

	ANA_REG_MSK_OR(desc->vol_trm, reg_val << shft, desc->vol_trm_bits);
	reg_val = ANA_REG_GET(desc->vol_trm);
	printf("Set %s voltage: %dmv, reg_val: 0x%08x.\n", con_id, vol_mv, reg_val);

	return 0;
}

int regulator_pmic_init(void)
{
	ANA_REG_SET(ANA_REG_GLB_PWR_WR_PROT_VALUE, BITS_PWR_WR_PROT_VALUE(WR_UNLOCK));
	ANA_REG_SET(ANA_REG_GLB_DCDC_WR_PROT_VALUE, BIT_DCDC_WR_PROT_VALUE(DCDC_WR_UNLOCK));
	dcdc_zcd_cali_cfg();
	dcdc_ripple_cali_cfg();
	dcxo_cali_init();
	return 0;
}
