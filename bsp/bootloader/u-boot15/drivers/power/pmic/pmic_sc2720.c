#include <common.h>
#include <errno.h>
#include <dm.h>
#include <power/pmic.h>
#include <spi.h>
#include <asm/io.h>
#include "adc_drvapi.h"
#include "adi_hal_internal.h"
#include <asm/arch/sprd_reg.h>
#include <sprd_adc.h>

#define __ffs(x) (ffs(x) - 1)
#define GENMASK(h, l) \
	(((~0UL) << (l)) & (~0UL >> (BITS_PER_LONG - 1 - (h))))

#define WR_UNLOCK 0x6e7f

static struct {
	int id;
	const char* name;
	int efuse_block_id;
	int efuse_bit_mask;
	int pmic_regs_addr;
	int pmic_regs_mask;
} reinit_node[] = {
	{0,"DCDC_3M",		0,	GENMASK(11,8),	ANA_REG_GLB_DCDC_CLK_REG0,	BITS_OSC3M_FREQ(0xF)},
	{1,"DCDC_CORE_PFM",	15,	GENMASK(1,0),	ANA_REG_GLB_DCDC_CORE_REG0,	BITS_PFM_VH_VCORE(0x3)},
	{2,"DCDC_GEN_PFM",	15,	GENMASK(3,2),	ANA_REG_GLB_DCDC_GEN_REG0,	BITS_PFM_VH_VGEN(0x3)},
	{3,"DCDC_WPA_PFM",	15,	GENMASK(5,4),	ANA_REG_GLB_DCDC_WPA_REG0,	BITS_PFM_THRESHOLD_VPA(0x3)},
	{4,"RESERVED_RTC",	6,	GENMASK(14,10),	ANA_REG_GLB_RESERVED_REG_RTC,	GENMASK(4,0)},
	{-1,NULL,0,0},
};

static const struct pmic_child_info sc2720_regulator_info[] = {
	{ .prefix = "DCDC", .driver = "sc2720-regulator"},
	{ .prefix = "LDO", .driver = "sc2720-regulator"},
	{}
};

static int sc2720_power_control_bind(struct udevice *dev)
{
	int children;
	struct udevice *pmic = dev->parent;

	children = pmic_bind_children(pmic, dev->node, sc2720_regulator_info);
	if (!children)
		dev_err(dev, "%s: %s - no child found\n", __func__, dev->name);

	return 0;
}

U_BOOT_DRIVER(sc2720_power_controler) = {
	.name = "sc2720-power-controler",
	.id = UCLASS_PMIC,
	.bind = sc2720_power_control_bind,
};

static const struct pmic_child_info pmic_children_info[] = {
	{ .prefix = "power-controller", .driver = "sc2720-power-controler"},
	{ .prefix = "gpio-controller", .driver = "pmic_eic_sprd"},
	{ .prefix = "adc", .driver = "pmic_adc"},
	{ .prefix = "efuse", .driver = "pmic_efuse"},
	{ .prefix = "led-controller", .driver = "sprd-bltc"},
	{ .prefix = "vibrator", .driver = "sc27xx-vibrator"},
	{ .prefix = "rtc", .driver = "sprd-rtc"},
	{}
};

static int sc2720_adi_write(struct udevice *dev, u32 reg, u32 value)
{
	int ret;
	u32 wd_addr[2] = {reg, value};

	ret = dm_spi_xfer(dev, 16, &wd_addr[0], NULL, 0);
	if (ret)
		dev_err(dev, "***Warning: write pmic register:0x%08x failed.\n", reg);

	return ret;
}

static int sc2720_adi_read(struct udevice *dev, u32 *reg)
{
	int ret;

	ret = dm_spi_xfer(dev, 16, NULL, reg, 0);
	if (ret)
		dev_err(dev, "***Warning: read pmic register by adi failed.\n");

	return ret;
}

static int sc2720_write(struct udevice *dev, uint reg, const uint8_t *buff,
		       int len)
{
	int ret;
	u32 wd_addr, value;

	wd_addr = (u32)reg;
	value = *(u32 *)buff;

	ret = sc2720_adi_write(dev, wd_addr, value);
	if (ret)
		dev_err(dev, "***Warning: write pmic register failed.\n");

	return ret;
}

static int sc2720_read(struct udevice *dev, uint reg, uint8_t *buff, int len)
{
	int ret;
	u32 *tmp = (u32 *)buff, rd_addr = (u32)reg;

	ret = sc2720_adi_read(dev, &rd_addr);
	if (ret) {
		dev_err(dev, "***Warning: read pmic register failed.\n");
		return ret;
	}

	*tmp = rd_addr;
	return ret;
}

static int sc2720_bind(struct udevice *dev)
{
	int children;

	children = pmic_bind_children(dev, dev->node, pmic_children_info);
	if (!children)
		dev_err(dev, "%s: %s - no child found\n", __func__, dev->name);

	return 0;
}

static int sc2720_reload_config(struct udevice *dev)
{
	int i, shft, reload_val, ret = 0;
	u32 efuse_val;

	for (i = 0; reinit_node[i].id != -1; i++) {
		efuse_val = sprd_pmic_efuse_read(reinit_node[i].efuse_block_id);
		shft = __ffs(reinit_node[i].efuse_bit_mask);

		reload_val = (efuse_val & reinit_node[i].efuse_bit_mask) >> shft;
		shft = __ffs(reinit_node[i].pmic_regs_mask);

		ret = pmic_clrsetbits(dev, reinit_node[i].pmic_regs_addr,
				reinit_node[i].pmic_regs_mask,
				(reload_val << shft) & (reinit_node[i].pmic_regs_mask));
		if (ret)
			return ret;
	}

	/*
	 * reset DCDC_CORE PFM/PWM for pmic issue workaround
	 * pmic efuse block15[0] 1'.
	 */
	efuse_val = sprd_pmic_efuse_read(15);
	if (efuse_val & BIT(0))
		ret = sc2720_adi_write(dev, ANA_REG_GLB_DCDC_CORE_REG0, 0x1443);

	return ret;
}

static int sc2720_probe(struct udevice *dev)
{
	int ret;

	ret = sc2720_adi_write(dev, ANA_REG_GLB_PWR_WR_PROT_VALUE, BITS_PWR_WR_PROT_VALUE(WR_UNLOCK));
	if (ret) {
		dev_err(dev, "sc2720 probe unlock failed.\n");
		return ret;
	}

	ret = sc2720_reload_config(dev);
	if (ret)
		dev_err(dev, "sc2720 probe reload config failed.\n");

	return ret;
}

static struct dm_pmic_ops sc2720_ops = {
	.read = sc2720_read,
	.write = sc2720_write,
};

static const struct udevice_id sc2720_ids[] = {
	{ .compatible = "sprd,sc2720" },
	{ }
};

U_BOOT_DRIVER(sc2720_pmic) = {
	.name = "sc2720_pmic",
	.id = UCLASS_PMIC,
	.of_match = sc2720_ids,
	.bind = sc2720_bind,
	.probe = sc2720_probe,
	.ops = &sc2720_ops,
};
