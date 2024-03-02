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

static const struct pmic_child_info sc2721_regulator_info[] = {
	{ .prefix = "DCDC", .driver = "sc2721-regulator"},
	{ .prefix = "LDO", .driver = "sc2721-regulator"},
	{}
};

static int sc2721_power_control_bind(struct udevice *dev)
{
	int children;
	struct udevice *pmic = dev->parent;

	children = pmic_bind_children(pmic, dev->node, sc2721_regulator_info);
	if (!children)
		dev_err(dev, "%s: %s - no child found\n", __func__, dev->name);

	return 0;
}

U_BOOT_DRIVER(sc2721_power_controler) = {
	.name = "sc2721-power-controler",
	.id = UCLASS_PMIC,
	.bind = sc2721_power_control_bind,
};

static const struct pmic_child_info pmic_children_info[] = {
	{ .prefix = "power-controller", .driver = "sc2721-power-controler"},
	{ .prefix = "gpio-controller", .driver = "pmic_eic_sprd"},
	{ .prefix = "adc", .driver = "pmic_adc"},
	{ .prefix = "efuse", .driver = "pmic_efuse"},
	{ .prefix = "led-controller", .driver = "sprd-bltc"},
	{ .prefix = "vibrator", .driver = "sc27xx-vibrator"},
	{ .prefix = "rtc", .driver = "sprd-rtc"},
	{}
};

static int sc2721_adi_write(struct udevice *dev, u32 reg, u32 value)
{
	int ret;
	u32 wd_addr[2] = {reg, value};

	ret = dm_spi_xfer(dev, 16, &wd_addr[0], NULL, 0);
	if (ret)
		dev_err(dev, "***Warning: write pmic register:0x%08x failed.\n", reg);

	return ret;
}

static int sc2721_adi_read(struct udevice *dev, u32 *reg)
{
	int ret;

	ret = dm_spi_xfer(dev, 16, NULL, reg, 0);
	if (ret)
		dev_err(dev, "***Warning: read pmic register by adi failed.\n");

	return ret;
}

static int sc2721_write(struct udevice *dev, uint reg, const uint8_t *buff,
		       int len)
{
	int ret;
	u32 wd_addr, value;

	wd_addr = (u32)reg;
	value = *(u32 *)buff;

	ret = sc2721_adi_write(dev, wd_addr, value);
	if (ret)
		dev_err(dev, "***Warning: write pmic register failed.\n");

	return ret;
}

static int sc2721_read(struct udevice *dev, uint reg, uint8_t *buff, int len)
{
	int ret;
	u32 *tmp = (u32 *)buff, rd_addr = (u32)reg;

	ret = sc2721_adi_read(dev, &rd_addr);
	if (ret) {
		dev_err(dev, "***Warning: read pmic register failed.\n");
		return ret;
	}

	*tmp = rd_addr;
	return ret;
}

static int sc2721_bind(struct udevice *dev)
{
	int children;

	children = pmic_bind_children(dev, dev->node, pmic_children_info);
	if (!children)
		dev_err(dev, "%s: %s - no child found\n", __func__, dev->name);

	return 0;
}

static int sc2721_probe(struct udevice *dev)
{
	u32 efuse_data;

	efuse_data = sprd_pmic_efuse_read(16);
	if (efuse_data & BIT(15)) {
		u32 temp = efuse_data & 0x0F;

		sc2721_adi_write(dev, ANA_REG_GLB_LDO_VLG_SEL1, 0x0140);

		if( temp > 2)
			efuse_data = 0xD0 + temp - 2;
		else
			efuse_data = 0xD0;

		sc2721_adi_write(dev, ANA_REG_GLB_DCDC_GEN_REG2,efuse_data);
	} else {
		sc2721_adi_write(dev, ANA_REG_GLB_LDO_VLG_SEL1, 0x07C0);
		sc2721_adi_write(dev, ANA_REG_GLB_DCDC_GEN_REG2, 0x00D6);
	}

	sc2721_adi_write(dev, ANA_REG_GLB_DCDC_WPA_REG3, 0x0891);

	return 0;
}

static struct dm_pmic_ops sc2721_ops = {
	.read = sc2721_read,
	.write = sc2721_write,
};

static const struct udevice_id sc2721_ids[] = {
	{ .compatible = "sprd,sc2721" },
	{ }
};

U_BOOT_DRIVER(sc2721_pmic) = {
	.name = "sc2721_pmic",
	.id = UCLASS_PMIC,
	.of_match = sc2721_ids,
	.bind = sc2721_bind,
	.probe = sc2721_probe,
	.ops = &sc2721_ops,
};
