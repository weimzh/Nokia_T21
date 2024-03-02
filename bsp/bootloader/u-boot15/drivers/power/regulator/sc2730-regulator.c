#include <common.h>
#include <errno.h>
#include <dm.h>
#include <power/pmic.h>
#include <power/regulator.h>
#include <asm/io.h>
#include "adc_drvapi.h"
#include "adi_hal_internal.h"
#include <asm/arch/sprd_reg.h>
#include <sprd_adc.h>

#define __ffs(x) (ffs(x) - 1)

#define DCDC_TYPE	2
#define LDO_TYPE	0

struct regulator_desc {
	const char *name;
	int type; /* BIT4: default on/off(0: off, 1: on); BIT0~BIT3: dcdc/ldo type(0: ldo; 2: dcdc) */
	unsigned long pd_set;
	u32 pd_set_bit;
	unsigned long vol_trm;
	u32 vol_trm_bits;
	u32 vol_def;
	u32 vol_sel_cnt;
	u32 vol_sel[2];
};

struct sc2730_regulator_platdata {
	u32 index;
	struct regulator_desc *desc;
};

static struct regulator_desc sc2730_regs_desc[] = {
    {"vddcore", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_CORE_PD,
	ANA_REG_GLB_DCDC_CORE_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8), 800, 2, {0, 3125}},
    {"vddcpu", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_CPU_PD,
	ANA_REG_GLB_DCDC_CPU_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8), 800, 2, {0, 3125}},
    {"vddgpu", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_GPU_PD,
	ANA_REG_GLB_DCDC_GPU_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8), 800, 2, {0, 3125}},
    {"vddmodem", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_MODEM_PD,
	ANA_REG_GLB_DCDC_MODEM_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8), 800, 2, {0, 3125}},
    {"vddmem", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_MEM_PD,
	ANA_REG_GLB_DCDC_MEM_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 1100, 2, {0, 6250}},
    {"vddmemq", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_MEMQ_PD,
	ANA_REG_GLB_DCDC_MEMQ_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8), 600, 2, {0, 3125}},
    {"vddgen0", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_GEN0_PD,
	ANA_REG_GLB_DCDC_GEN0_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 1875, 2, {20, 9375}},
    {"vddgen1", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_GEN1_PD,
	ANA_REG_GLB_DCDC_GEN1_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 1350, 2, {50, 6250}},
    {"vddsram", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_SRAM_PD,
	ANA_REG_GLB_DCDC_SRAM_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8), 800, 2, {0, 3125}},
    {"avdd18", 0x10, ANA_REG_GLB_POWER_PD_SW, BIT_LDO_AVDD18_PD,
	ANA_REG_GLB_LDO_AVDD18_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), 1775, 2, {1175, 10000}},
    {"vddcamio", 0x10, ANA_REG_GLB_LDO_VDDCAMIO_REG0, BIT_LDO_VDDCAMIO_PD,
	ANA_REG_GLB_RESERVED_REG0, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), 1800, 2, {0, 0}},
    {"vddrf18", 0x10, ANA_REG_GLB_LDO_VDDRF1V8_REG0, BIT_LDO_VDDRF1V8_PD,
	ANA_REG_GLB_LDO_VDDRF1V8_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), 1775, 2, {1175, 10000}},
    {"vddwcn", 0x10, ANA_REG_GLB_LDO_VDDWCN_REG0, BIT_LDO_VDDWCN_PD,
	ANA_REG_GLB_LDO_VDDWCN_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), 900, 2, {900, 15000}},
    {"vddcamd1", 0x10, ANA_REG_GLB_LDO_VDDCAMD1_REG0, BIT_LDO_VDDCAMD1_PD,
	ANA_REG_GLB_LDO_VDDCAMD1_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4), 1050, 2, {900, 15000}},
    {"vddcamd0", 0x10, ANA_REG_GLB_LDO_VDDCAMD0_REG0, BIT_LDO_VDDCAMD0_PD,
	ANA_REG_GLB_LDO_VDDCAMD0_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4), 1050, 2, {900, 15000}},
    {"vddrf1v25", 0x10, ANA_REG_GLB_LDO_VRF1V25_REG0, BIT_LDO_VDDRF1V25_PD,
	ANA_REG_GLB_LDO_VDDRF1V25_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4), 1275, 2, {900, 15000}},
    {"avdd12", 0x10, ANA_REG_GLB_LDO_AVDD12_REG0, BIT_LDO_AVDD12_PD,
	ANA_REG_GLB_LDO_AVDD12_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4), 1200, 2, {900, 15000}},
    {"vddcama0", 0x10, ANA_REG_GLB_LDO_VDDCAMA0_REG0, BIT_LDO_VDDCAMA0_PD,
	ANA_REG_GLB_LDO_VDDCAMA0_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 2800, 2, {1200, 10000}},
    {"vddcama1", 0x10, ANA_REG_GLB_LDO_VDDCAMA1_REG0, BIT_LDO_VDDCAMA1_PD,
	ANA_REG_GLB_LDO_VDDCAMA1_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 2800, 2, {1200, 10000}},
    {"vddcammot", 0x10, ANA_REG_GLB_LDO_VDDCAMMOT_REG0, BIT_LDO_VDDCAMMOT_PD,
	ANA_REG_GLB_LDO_VDDCAMMOT_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 3000, 2, {1200, 10000}},
    {"vddsim0", 0x10, ANA_REG_GLB_LDO_VDDSIM0_REG0, BIT_LDO_VDDSIM0_PD,
	ANA_REG_GLB_LDO_VDDSIM0_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 3000, 2, {1200, 10000}},
    {"vddsim1", 0x10, ANA_REG_GLB_LDO_VDDSIM1_REG0, BIT_LDO_VDDSIM1_PD,
	ANA_REG_GLB_LDO_VDDSIM1_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 3000, 2, {1200, 10000}},
    {"vddsim2", 0x10, ANA_REG_GLB_LDO_VDDSIM2_REG0, BIT_LDO_VDDSIM2_PD,
	ANA_REG_GLB_LDO_VDDSIM2_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 3000, 2, {1200, 10000}},
    {"vddemmccore", 0x10, ANA_REG_GLB_LDO_VDDEMMCCORE_REG0, BIT_LDO_VDDEMMCCORE_PD,
	ANA_REG_GLB_LDO_VDDEMMCCORE_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 3000, 2, {1200, 10000}},
    {"vddsdcore", 0x10, ANA_REG_GLB_LDO_VDDSDCORE_REG0, BIT_LDO_VDDSDCORE_PD,
	ANA_REG_GLB_LDO_VDDSDCORE_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 3000, 2, {1200, 10000}},
    {"vddsdio", 0x10, ANA_REG_GLB_LDO_VDDSDIO_REG0, BIT_LDO_VDDSDIO_PD,
	ANA_REG_GLB_LDO_VDDSDIO_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 3000, 2, {1200, 10000}},
    {"vdd28", 0x10, ANA_REG_GLB_POWER_PD_SW, BIT_LDO_VDD28_PD,
	ANA_REG_GLB_LDO_VDD28_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 2800, 2, {1200, 10000}},
    {"vddwifipa", 0x10, ANA_REG_GLB_LDO_VDDWIFIPA_REG0, BIT_LDO_VDDWIFIPA_PD,
	ANA_REG_GLB_LDO_VDDWIFIPA_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 3300, 2, {1200, 10000}},
    {"vdd18_dcxo", 0x10, ANA_REG_GLB_POWER_PD_SW, BIT_LDO_VDD18_DCXO_PD,
	ANA_REG_GLB_LDO_VDD18_DCXO_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 1800, 2, {1200, 10000}},
    {"vddusb33", 0x10, ANA_REG_GLB_LDO_VDDUSB33_REG0, BIT_LDO_VDDUSB33_PD,
	ANA_REG_GLB_LDO_VDDUSB33_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 3300, 2, {1200, 10000}},
    {"vddldo0", 0x10, ANA_REG_GLB_LDO_VDDLDO0_REG0, BIT_LDO_VDDLDO0_PD,
	ANA_REG_GLB_LDO_VDDLDO0_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 2800, 2, {1200, 10000}},
    {"vddldo1", 0x10, ANA_REG_GLB_LDO_VDDLDO1_REG0, BIT_LDO_VDDLDO1_PD,
	ANA_REG_GLB_LDO_VDDLDO1_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 1800, 2, {1200, 10000}},
    {"vddldo2", 0x10, ANA_REG_GLB_LDO_VDDLDO2_REG0, BIT_LDO_VDDLDO2_PD,
	ANA_REG_GLB_LDO_VDDLDO2_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 3300, 2, {1200, 10000}},
    {"vddkpled", 0x10, ANA_REG_GLB_KPLED_CTRL1, BIT_LDO_VDDKPLED_PD,
	ANA_REG_GLB_KPLED_CTRL1, BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14), 3000, 2, {1200, 10000}}
};

static int sc2730_dcdc_get_voltage(struct udevice *dev, struct regulator_desc *desc)
{
	struct regulator_desc *regs = desc;
	u32  trim, tmp = 0, mv = 0;
	int ret, shft_trm, cal = 0;

	BUG_ON(regs->vol_sel_cnt > 8);

	if (regs->vol_trm && regs->vol_sel_cnt == 2) {
		shft_trm = __ffs(regs->vol_trm_bits);

		ret = pmic_read(dev, regs->vol_trm, (uint8_t *)&tmp, sizeof(tmp));
		if (ret) {
			dev_err(dev, "%s get voltage failed.\n", regs->name);
			return ret;
		}

		trim = (tmp & regs->vol_trm_bits) >> shft_trm;
		mv = regs->vol_sel[0] + trim * regs->vol_sel[1] / 1000;

		dev_info(dev, "%s %d +%dmv(trim %#x)\n", desc->name, regs->vol_sel[0], (mv - regs->vol_sel[0]), trim);
	}
	return (mv + cal / 1000);
}

static int sc2730_dcdc_set_voltage(struct udevice *dev, struct regulator_desc *desc, int min_mV, int max_mV)
{
	struct regulator_desc *regs = desc;
	int ret, shft_trm, step = 0, i = 0, j = 0, mv = min_mV;

	/* dcdc calibration control bits (default 0) small adjust voltage: 100/32mv ~= 3.125mv */
	shft_trm = __ffs(regs->vol_trm_bits);

	if (regs->vol_sel_cnt == 2) {
		step = regs->vol_sel[1];
		j = DIV_ROUND_UP((mv - regs->vol_sel[0]) * 1000, step);
	}

	dev_info(dev, "regu_dcdc %p (%s) %d = %d %+dmv (trim=%d step=%duv);\n", regs, desc->name,
		   mv, regs->vol_sel[i], mv - regs->vol_sel[i], j, step);

	if (regs->vol_trm && j >= 0 && j <= (regs->vol_trm_bits >> shft_trm)) {
		ret = pmic_clrsetbits(dev, regs->vol_trm,
				regs->vol_trm_bits,
				(j << shft_trm) & (regs->vol_trm_bits));
		if (ret) {
			dev_err(dev, "%s set voltage failed.\n", regs->name);
			return ret;
		}
	}

	return 0;
}

static int sc2730_ldo_get_voltage(struct udevice *dev, struct regulator_desc *desc)
{
	struct regulator_desc *regs = desc;
	u32 vol, trim, tmp = 0;
	int ret, shft;

	if (regs->vol_trm && regs->vol_sel_cnt == 2) {
		shft = __ffs(regs->vol_trm_bits);

		ret = pmic_read(dev, regs->vol_trm, (uint8_t *)&tmp, sizeof(tmp));
		if (ret) {
			dev_err(dev, "%s get voltage failed.\n", regs->name);
			return ret;
		}

		trim = (tmp & regs->vol_trm_bits) >> shft;
		vol = regs->vol_sel[0] * 1000 + trim * regs->vol_sel[1];
		vol /= 1000;

		dev_info(dev, "%s get voltage %dmv(trim %#x)\n", desc->name, vol, trim);

		return vol;
	}

	return -EINVAL;
}

static int sc2730_ldo_set_trimming(struct udevice *dev, struct regulator_desc *desc, int def_vol, int to_vol, int adc_vol)
{
	struct regulator_desc *regs = desc;
	int shft, ctl_vol, ret = -EINVAL;
	u32 trim;

	if (regs->vol_sel_cnt == 2) {
		/* ctl_vol = vol_base + reg[vol_trm] * vol_step  */
		shft = __ffs(regs->vol_trm_bits);
		ctl_vol = (to_vol - (adc_vol - def_vol));

		if (adc_vol > def_vol)
			trim = DIV_ROUND_UP((ctl_vol - regs->vol_sel[0]) * 1000, regs->vol_sel[1]);
		else
			trim = (ctl_vol - regs->vol_sel[0]) * 1000 / regs->vol_sel[1];

		dev_info(dev, "regu_ldo %p (%s) %d = %d %+dmv (trim=%d step=%duv)\n", regs, desc->name,
			ctl_vol, regs->vol_sel[0], ctl_vol - regs->vol_sel[0], trim, regs->vol_sel[1]);

		if (trim <= (regs->vol_trm_bits >> shft)) {
			ret = pmic_clrsetbits(dev, regs->vol_trm,
					regs->vol_trm_bits,
					(trim << shft) & (regs->vol_trm_bits));
			if (ret)
				dev_err(dev, "%s set trimming failed.\n", regs->name);
		}
	}

	return ret;
}

static int sc2730_regulator_disable(struct udevice *dev, struct regulator_desc *desc)
{
	if (!desc)
		return -EINVAL;

	return pmic_clrsetbits(dev, desc->pd_set, 0, desc->pd_set_bit);
}

static int sc2730_regulator_enable(struct udevice *dev, struct regulator_desc *desc)
{
	if (!desc)
		return -EINVAL;

	return pmic_clrsetbits(dev, desc->pd_set, desc->pd_set_bit, 0);
}

static int sc2730_regulator_get_enable(struct udevice *dev)
{
	u32 pd_state = 0;
	int shft, ret;
	struct udevice *pmic = dev->parent;
	struct sc2730_regulator_platdata *plat = dev_get_platdata(dev);
	struct regulator_desc *desc = plat->desc;

	if (!desc)
		return -EINVAL;

	shft = __ffs(desc->vol_trm_bits);

	ret = pmic_read(pmic, desc->pd_set, (uint8_t *)&pd_state, sizeof(pd_state));
	if (ret) {
		dev_err(dev, "%s get enable failed.\n", desc->name);
		return ret;
	}

	pd_state &= desc->pd_set_bit;
	pd_state = pd_state >> shft;

	if (!pd_state) {
		dev_info(dev, "The regulator: %s is on.\n", desc->name);
		return 1;
	}
	dev_info(dev, "The regulator: %s is off.\n", desc->name);
	return 0;
}

static int sc2730_regulator_set_enable(struct udevice *dev, bool enable)
{
	struct sc2730_regulator_platdata *plat = dev_get_platdata(dev);
	struct regulator_desc *desc = plat->desc;
	struct udevice *pmic = dev->parent;

	if (!desc)
		return -EINVAL;

	if (enable)
		sc2730_regulator_enable(pmic, desc);
	else
		sc2730_regulator_disable(pmic, desc);

	return 0;
}

static int sc2730_regulator_get_value(struct udevice *dev)
{
	int vdd_type;
	u32 vol = 0;
	struct sc2730_regulator_platdata *plat = dev_get_platdata(dev);
	struct regulator_desc *desc = plat->desc;
	struct udevice *pmic = dev->parent;

	if (!desc)
		return -EINVAL;

	vdd_type = desc->type & (BIT(4) - 1);
	if (vdd_type == DCDC_TYPE)
		vol = sc2730_dcdc_get_voltage(pmic, desc);
	else if (vdd_type == LDO_TYPE)
		vol = sc2730_ldo_get_voltage(pmic, desc);

	return vol * 1000;
}

static int sc2730_regulator_set_value(struct udevice *dev, int uV)
{
	int vdd_type, ret = 0;
	u32 to_vol = uV / 1000;
	struct sc2730_regulator_platdata *plat = dev_get_platdata(dev);
	struct regulator_desc *desc = plat->desc;
	struct udevice *pmic = dev->parent;

	if (!desc)
		return -EINVAL;

	vdd_type = desc->type & (BIT(4) - 1);
	if (vdd_type == DCDC_TYPE)
		ret = sc2730_dcdc_set_voltage(pmic, desc, to_vol, 0);
	else if (vdd_type == LDO_TYPE)
		ret = sc2730_ldo_set_trimming(pmic, desc, 0, to_vol, 0);

	return ret;
}

static const struct dm_regulator_ops sc2730_regulator_ops = {
	.get_value  = sc2730_regulator_get_value,
	.set_value  = sc2730_regulator_set_value,
	.get_enable = sc2730_regulator_get_enable,
	.set_enable = sc2730_regulator_set_enable,
};

static int sc2730_regulator_probe(struct udevice *dev)
{
	int i;
	char *check_name;
	struct sc2730_regulator_platdata *plat = dev_get_platdata(dev);

	check_name = dev_read_string(dev, "regulator-name");

	for (i = 0; i < ARRAY_SIZE(sc2730_regs_desc); i++) {
		if (!strcmp(check_name, sc2730_regs_desc[i].name)) {
			plat->index = i;
			plat->desc = &sc2730_regs_desc[i];
			break;
		}
	}

	if (i == ARRAY_SIZE(sc2730_regs_desc)) {
		dev_err(dev, "The regulator %s is not found in description.\n", check_name);
		BUG();
		return -EINVAL;
	}

	printf("Regulator %s probe successfully.\n", check_name);
	return 0;
}

U_BOOT_DRIVER(sc2730_regulator) = {
	.name  = "sc2730-regulator",
	.id = UCLASS_REGULATOR,
	.probe = sc2730_regulator_probe,
	.ops = &sc2730_regulator_ops,
	.platdata_auto_alloc_size = sizeof(struct sc2730_regulator_platdata),
};
