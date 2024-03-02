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
	unsigned long cal_ctl;
	u32 cal_ctl_bits;
	u32 vol_def;
	unsigned long vol_ctl;
	u32 vol_ctl_bits;
	u32 vol_sel_cnt;
	u32 vol_sel[2];
};

struct sc2720_regulator_platdata {
	u32 index;
	struct regulator_desc *desc;
};

static struct regulator_desc sc2720_regs_desc[] = {
	{ "vddcore", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_CORE_PD,
	ANA_REG_GLB_DCDC_CORE_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8), ANA_REG_GLB_DCDC_CH_CTRL, BIT(13)|BIT(14)|BIT(16)|BIT(18)|BIT(19),
	900, 0, 0, 2, {0, 3125} },
	{ "vddgen", 0x12, ANA_REG_GLB_POWER_PD_SW, BIT_DCDC_GEN_PD,
	ANA_REG_GLB_DCDC_GEN_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), ANA_REG_GLB_DCDC_CH_CTRL, BIT(13)|BIT(14)|BIT(16)|BIT(18)|BIT(19),
	1850, 0, 0, 2, {1300, 12500} },
	{ "vddwpa", 0x2, ANA_REG_GLB_DCDC_WPA_REG2, BIT_PD_BUCK_VPA,
	ANA_REG_GLB_DCDC_WPA_VOL, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), 0, BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(18)|BIT(19),
	3400, 0, 0, 2, {400, 25000}},
	{ "avdd18", 0x10, ANA_REG_GLB_POWER_PD_SW, BIT_LDO_AVDD18_PD,
	ANA_REG_GLB_LDO_AVDD18_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	1800, 0, 0, 2, {1400, 12500}},
	{ "vddcamio", 0x0, ANA_REG_GLB_LDO_CAMIO_REG0, BIT_LDO_CAMIO_PD,
	ANA_REG_GLB_LDO_CAMIO_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	1800, 0, 0, 2, {1400, 12500}},
	{ "vddrf18a", 0x10, ANA_REG_GLB_LDO_RF18A_REG0, BIT_LDO_RF18A_PD,
	ANA_REG_GLB_LDO_RF18A_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	1800, 0, 0, 2, {1400, 12500}},
	{ "vddrf18b", 0x00, ANA_REG_GLB_LDO_RF18B_REG0, BIT_LDO_RF18B_PD,
	ANA_REG_GLB_LDO_RF18B_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	1800, 0, 0, 2, {1400, 12500}},
	{ "vddcamd", 0x0, ANA_REG_GLB_LDO_CAMD_REG0, BIT_LDO_CAMD_PD,
	ANA_REG_GLB_LDO_CAMD_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	1200, 0, 0, 2, {800, 12500}},
	{ "vddcon", 0x0, ANA_REG_GLB_LDO_CON_REG0, BIT_LDO_CON_PD,
	ANA_REG_GLB_LDO_CON_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	1200, 0, 0, 2, {800, 12500}},
	{ "vddmem", 0x10, ANA_REG_GLB_POWER_PD_SW, BIT_LDO_MEM_PD,
	ANA_REG_GLB_LDO_MEM_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	1200, 0, 0, 2, {800, 12500}},
	{ "vddsim0", 0x0, ANA_REG_GLB_LDO_SIM0_PD_REG, BIT_LDO_SIM0_PD,
	ANA_REG_GLB_LDO_SIM0_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	3000, 0, 0, 2, {1612, 12500}},
	{ "vddsim1", 0x0, ANA_REG_GLB_LDO_SIM1_PD_REG, BIT_LDO_SIM1_PD,
	ANA_REG_GLB_LDO_SIM1_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	3000, 0, 0, 2, {1612, 12500}},
	{ "vddsim2", 0x0, ANA_REG_GLB_LDO_SIM2_PD_REG, BIT_LDO_SIM2_PD,
	ANA_REG_GLB_LDO_SIM2_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	3000, 0, 0, 2, {1612, 12500}},
	{ "vddcama", 0x0, ANA_REG_GLB_LDO_CAMA_REG0, BIT_LDO_CAMA_PD,
	ANA_REG_GLB_LDO_CAMA_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(9)|BIT(17)|BIT(18)|BIT(20),
	2800, 0, 0, 2, {1612, 12500}},
	{ "vddcammot", 0x0, ANA_REG_GLB_LDO_CAMMOT_REG0, BIT_LDO_CAMMOT_PD,
	ANA_REG_GLB_LDO_CAMMOT_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(9)|BIT(17)|BIT(18)|BIT(20),
	3000, 0, 0, 2, {2000, 12500}},
	{ "vddemmccore", 0x10, ANA_REG_GLB_LDO_EMMCCORE_PD_REG, BIT_LDO_EMMCCORE_PD,
	ANA_REG_GLB_LDO_EMMCCORE_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	3000, 0, 0, 2, {2000, 12500}},
	{ "vddsdcore", 0x10, ANA_REG_GLB_LDO_SD_PD_REG, BIT_LDO_SDCORE_PD,
	ANA_REG_GLB_LDO_SD_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	3000, 0, 0, 2, {2000, 12500}},
	{ "vddsdio", 0x10, ANA_REG_GLB_LDO_SDIO_PD_REG, BIT_LDO_SDIO_PD,
	ANA_REG_GLB_LDO_SDIO_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	3000, 0, 0, 2, {1612, 12500}},
	{ "vdd28", 0x10, ANA_REG_GLB_POWER_PD_SW, BIT_LDO_VDD28_PD,
	ANA_REG_GLB_LDO_VDD28_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	2800, 0, 0, 2, {1612, 12500}},
	{ "vddwifipa", 0x0, ANA_REG_GLB_LDO_WIFIPA_REG0, BIT_LDO_WIFIPA_PD,
	ANA_REG_GLB_LDO_WIFIPA_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	3300, 0, 0, 2, {2100, 12500}},
	{ "vdddcxo", 0x10, ANA_REG_GLB_POWER_PD_SW, BIT_LDO_DCXO_PD,
	ANA_REG_GLB_LDO_DCXO_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	1800, 0, 0, 2, {1500, 12500}},
	{ "vddusb33", 0x10, ANA_REG_GLB_LDO_USB_PD_REG, BIT_LDO_USB33_PD,
	ANA_REG_GLB_LDO_USB_REG1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_DCDC_CH_CTRL, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	3300, 0, 0, 2, {2100, 12500}}
};

static int sc2720_dcdc_get_trimming_step(struct regulator_desc *desc, int to_vol)
{
	return 1000 * 100 / 32;	/*uV */
}

static int sc2720_match_vol(struct regulator_desc *desc, u32 vol)
{
	int i, ds, min_ds = 100, j = -EINVAL;
	struct regulator_desc *regs = desc;

	for (i = 0; i < regs->vol_sel_cnt; i++) {
		ds = (int)(vol - regs->vol_sel[i]);
		if (ds >= 0 && ds < min_ds) {
			min_ds = ds;
			j = i;
		}
	}

	if ((2 == (regs->type & (BIT(4) - 1))) && (j < 0)) {
		for (i = 0; i < regs->vol_sel_cnt; i++) {
			ds = abs(vol - regs->vol_sel[i]);
			if (ds < min_ds) {
				min_ds = ds;
				j = i;
			}
		}
	}

	return j;
}

static int sc2720_dcdc_get_voltage(struct udevice *dev, struct regulator_desc *desc)
{
	struct regulator_desc *regs = desc;
	u32 mv = 0, tmp = 0;
	int ret, i = 0, cal = 0;

	BUG_ON(regs->vol_sel_cnt > 8);

	if (regs->vol_ctl) {
		int shft_ctl = __ffs(regs->vol_ctl_bits);
		int shft_trm = __ffs(regs->vol_trm_bits);

		ret = pmic_read(dev, regs->vol_ctl, (uint8_t *)&tmp, sizeof(tmp));
		if (ret) {
			dev_err(dev, "%s get voltage failed.\n", regs->name);
			return ret;
		}

		i = (tmp & regs->vol_ctl_bits) >> shft_ctl;
		mv = regs->vol_sel[i];

		if (regs->vol_trm) {
			ret = pmic_read(dev, regs->vol_trm, (uint8_t *)&tmp, sizeof(tmp));
			if (ret) {
				dev_err(dev, "%s get voltage failed.\n", regs->name);
				return ret;
			}

			cal = (tmp & regs->vol_trm_bits) >> shft_trm;
			cal *= sc2720_dcdc_get_trimming_step(desc, 0);
		}

		dev_info(dev, "%s %d +%dmv(trim %#x)\n", regs->name, mv, cal / 1000, cal / sc2720_dcdc_get_trimming_step(regs, 0));

	} else if (regs->vol_trm && regs->vol_sel_cnt == 2) {
		u32 trim = 0;
		int shft_trm = __ffs(regs->vol_trm_bits);

		ret = pmic_read(dev, regs->vol_trm, (uint8_t *)&tmp, sizeof(tmp));
		if (ret) {
			dev_err(dev, "%s get voltage failed.\n", regs->name);
			return ret;
		}

		trim = (tmp & regs->vol_trm_bits) >> shft_trm;
		mv = regs->vol_sel[0] + trim * regs->vol_sel[1] / 1000;

		dev_info(dev, "%s %d +%dmv(trim %#x)\n", regs->name, regs->vol_sel[0], (mv - regs->vol_sel[0]), trim);
	}

	return (mv + cal / 1000);
}

static int sc2720_dcdc_set_voltage(struct udevice *dev, struct regulator_desc *desc, int min_mV, int max_mV)
{
	struct regulator_desc *regs = desc;
	int ret, i = 0, mv = min_mV;

	if (regs->vol_ctl) {
		/* found the closely vol ctrl bits */
		i = sc2720_match_vol(desc, mv);
		if (i < 0) {
			dev_err(dev, "%s: %s failed to match voltage: %d\n", __func__, desc->name, mv);
			return -EINVAL;
		}
	}

	/* dcdc calibration control bits (default 0) small adjust voltage: 100/32mv ~= 3.125mv */
	{
		int shft_trm, shft_ctl = 0, step = 0, j = 0;

		shft_trm = __ffs(regs->vol_trm_bits);

		if (regs->vol_ctl) {
			shft_ctl = __ffs(regs->vol_ctl_bits);
			step = sc2720_dcdc_get_trimming_step(regs, mv);

			j = (int)(mv - (int)regs->vol_sel[i]) * 1000 / step;
		} else {
			if (regs->vol_sel_cnt == 2) {
				step = regs->vol_sel[1];
				j = DIV_ROUND_UP((mv - regs->vol_sel[0]) * 1000, step);
			}
		}

		dev_info(dev, "regu_dcdc (%s) %d = %d %+dmv (trim=%d step=%duv);\n", regs->name,
			   mv, regs->vol_sel[i], mv - regs->vol_sel[i], j, step);

		if ((regs->vol_trm == regs->vol_ctl) && regs->vol_ctl) {
			if (j >= 0 && j <= (regs->vol_trm_bits >> shft_trm)) {
				ret = pmic_clrsetbits(dev, regs->vol_ctl,
					regs->vol_trm_bits | regs->vol_ctl_bits,
					((j << shft_trm) | (i << shft_ctl)) & (regs->vol_trm_bits | regs->vol_ctl_bits));
				if (ret) {
					dev_err(dev, "%s set voltage failed.\n", regs->name);
					return ret;
				}
			}
		} else {
			if (regs->vol_trm && j >= 0 && j <= (regs->vol_trm_bits >> shft_trm)) {
				ret = pmic_clrsetbits(dev, regs->vol_trm,
						regs->vol_trm_bits,
						(j << shft_trm) & (regs->vol_trm_bits));
				if (ret) {
					dev_err(dev, "%s set voltage failed.\n", regs->name);
					return ret;
				}
			}

			if (regs->vol_ctl) {
				ret = pmic_clrsetbits(dev, regs->vol_ctl,
						regs->vol_ctl_bits,
						(i << shft_ctl) & (regs->vol_ctl_bits));
				if (ret) {
					dev_err(dev, "%s set voltage failed.\n", regs->name);
					return ret;
				}
			}
		}
	}
	return 0;
}

static int sc2720_ldo_get_voltage(struct udevice *dev, struct regulator_desc *desc)
{
	struct regulator_desc *regs = desc;
	int ret, shft;
	u32 vol, trim, tmp = 0;

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

		dev_info(dev, "%s get voltage %dmv(trim %#x)\n", regs->name, vol, trim);

		return vol;
	}

	return -EINVAL;
}

static int sc2720_ldo_set_trimming(struct udevice *dev, struct regulator_desc *desc, int def_vol, int to_vol, int adc_vol)
{
	struct regulator_desc *regs = desc;
	int ret = -EINVAL;

	if (!regs->vol_ctl && regs->vol_sel_cnt == 2) {
		int shft, ctl_vol;
		u32 trim = 0;

		/* ctl_vol = vol_base + reg[vol_trm] * vol_step  */
		shft = __ffs(regs->vol_trm_bits);
		ctl_vol = (to_vol - (adc_vol - def_vol));

		if (adc_vol > def_vol)
			trim = DIV_ROUND_UP((ctl_vol - regs->vol_sel[0]) * 1000, regs->vol_sel[1]);
		else
			trim = ((ctl_vol - regs->vol_sel[0]) * 1000 / regs->vol_sel[1]);

		dev_info(dev, "regu_ldo (%s) %d = %d %+dmv (trim=%d step=%duv)\n", regs->name,
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

static int sc2720_regulator_disable(struct udevice *dev, struct regulator_desc *desc)
{
	if (!desc)
		return -EINVAL;

	return pmic_clrsetbits(dev, desc->pd_set, 0, desc->pd_set_bit);
}

static int sc2720_regulator_enable(struct udevice *dev, struct regulator_desc *desc)
{
	if (!desc)
		return -EINVAL;

	return pmic_clrsetbits(dev, desc->pd_set, desc->pd_set_bit, 0);
}

static int sc2720_regulator_get_enable(struct udevice *dev)
{
	u32 pd_state = 0;
	int shft, ret;
	struct udevice *pmic = dev->parent;
	struct sc2720_regulator_platdata *plat = dev_get_platdata(dev);
	struct regulator_desc *desc = plat->desc;

	if (!desc)
		return -EINVAL;

	shft = __ffs(desc->vol_trm_bits);

	ret = pmic_read(pmic, desc->pd_set, (uint8_t *)&pd_state, sizeof(pd_state));
	if (ret) {
		dev_err(dev, "%s get enable failed.\n", desc->name);
		return -EINVAL;
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

static int sc2720_regulator_set_enable(struct udevice *dev, bool enable)
{
	struct sc2720_regulator_platdata *plat = dev_get_platdata(dev);
	struct regulator_desc *desc = plat->desc;
	struct udevice *pmic = dev->parent;

	if (!desc)
		return -EINVAL;

	if (enable)
		sc2720_regulator_enable(pmic, desc);
	else
		sc2720_regulator_disable(pmic, desc);

	return 0;
}

static int sc2720_regulator_get_value(struct udevice *dev)
{
	int vdd_type;
	u32 vol = 0;
	struct sc2720_regulator_platdata *plat = dev_get_platdata(dev);
	struct regulator_desc *desc = plat->desc;
	struct udevice *pmic = dev->parent;

	if (!desc)
		return -EINVAL;

	vdd_type = desc->type & (BIT(4) - 1);
	if (vdd_type == DCDC_TYPE)
		vol = sc2720_dcdc_get_voltage(pmic, desc);
	else if (vdd_type == LDO_TYPE)
		vol = sc2720_ldo_get_voltage(pmic, desc);

	return vol * 1000;
}

static int sc2720_regulator_set_value(struct udevice *dev, int uV)
{
	int vdd_type, ret = 0;
	u32 to_vol = uV / 1000;
	struct sc2720_regulator_platdata *plat = dev_get_platdata(dev);
	struct regulator_desc *desc = plat->desc;
	struct udevice *pmic = dev->parent;

	if (!desc)
		return -EINVAL;

	vdd_type = desc->type & (BIT(4) - 1);
	if (vdd_type == DCDC_TYPE)
		ret = sc2720_dcdc_set_voltage(pmic, desc, to_vol, 0);
	else if (vdd_type == LDO_TYPE)
		ret = sc2720_ldo_set_trimming(pmic, desc, 0, to_vol, 0);

	return ret;
}

static const struct dm_regulator_ops sc2720_regulator_ops = {
	.get_value  = sc2720_regulator_get_value,
	.set_value  = sc2720_regulator_set_value,
	.get_enable = sc2720_regulator_get_enable,
	.set_enable = sc2720_regulator_set_enable,
};

static int sc2720_regulator_probe(struct udevice *dev)
{
	int i;
	char *check_name;
	struct sc2720_regulator_platdata *plat = dev_get_platdata(dev);

	check_name = dev_read_string(dev, "regulator-name");

	for (i = 0; i < ARRAY_SIZE(sc2720_regs_desc); i++) {
		if (!strcmp(check_name, sc2720_regs_desc[i].name)) {
			plat->index = i;
			plat->desc = &sc2720_regs_desc[i];
			break;
		}
	}

	if (i == ARRAY_SIZE(sc2720_regs_desc)) {
		dev_err(dev, "The regulator %s is not found in description.\n", check_name);
		BUG();
		return -EINVAL;
	}

	printf("Regulator %s probe successfully.\n", check_name);
	return 0;
}

U_BOOT_DRIVER(sc2720_regulator) = {
	.name  = "sc2720-regulator",
	.id = UCLASS_REGULATOR,
	.probe = sc2720_regulator_probe,
	.ops = &sc2720_regulator_ops,
	.platdata_auto_alloc_size = sizeof(struct sc2720_regulator_platdata),
};
