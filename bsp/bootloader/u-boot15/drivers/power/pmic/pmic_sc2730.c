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

#define GENMASK(h, l) \
	(((~0UL) << (l)) & (~0UL >> (BITS_PER_LONG - 1 - (h))))

#define __ffs(x) (ffs(x) - 1)

#define CBANK_VALUE 0x5
#define WR_UNLOCK 0x6e7f
#define TSX_WR_UNLOCK 0x1990
#define TRANS_26M_EN 1
#define DIV_COEF 0x750
#define IB_ZCD_THRESHOLD_MAX 111
#define IB_ZCD_THRESHOLD_MIN 67

static struct {
	int id;
	const char* name;
	int efuse_block_id;
	int efuse_bit_mask;
	int pmic_regs_addr;
	int pmic_regs_mask;
} reinit_node[] = {
	{0, "DCDC_CPU_ZCD", 14, GENMASK(15,9), ANA_REG_GLB_DCDC_CPU_REG2, BITS_DCDC_CPU_ZCD(0x3)},
	{1, "DCDC_GPU_ZCD", 14, GENMASK(15,9), ANA_REG_GLB_DCDC_GPU_REG2, BITS_DCDC_GPU_ZCD(0x3)},
	{2, "DCDC_CORE_ZCD", 14, GENMASK(15,9), ANA_REG_GLB_DCDC_CORE_REG2, BITS_DCDC_CORE_ZCD(0x3)},
	{3, "DCDC_MODEM_ZCD", 14, GENMASK(15,9), ANA_REG_GLB_DCDC_MODEM_REG2, BITS_DCDC_MODEM_ZCD(0x3)},
	{4, "DCDC_MEM_ZCD", 14, GENMASK(15,9), ANA_REG_GLB_DCDC_MEM_REG2, BITS_DCDC_MEM_ZCD(0x3)},
	{5, "DCDC_MEMQ_ZCD", 14, GENMASK(15,9), ANA_REG_GLB_DCDC_MEMQ_REG2, BITS_DCDC_MEMQ_ZCD(0x3)},
	{6, "DCDC_GEN0_ZCD", 14, GENMASK(15,9), ANA_REG_GLB_DCDC_GEN0_REG2, BITS_DCDC_GEN0_ZCD(0x3)},
	{7, "DCDC_GEN1_ZCD", 14, GENMASK(15,9), ANA_REG_GLB_DCDC_GEN1_REG2, BITS_DCDC_GEN1_ZCD(0x3)},
	{8, "DCDC_WPA_ZCD", 14, GENMASK(15,9), ANA_REG_GLB_DCDC_WPA_REG3, BITS_DCDC_WPA_ZCD(0x3)},
	{9, "DCDC_SRAM_ZCD", 14, GENMASK(15,9), ANA_REG_GLB_DCDC_SRAM_REG2, BITS_DCDC_SRAM_ZCD(0x3)},
	{10, "LDO_DCXO_LP", 14, GENMASK(4,1), ANA_REG_GLB_LDO_VDD18_DCXO_REG2, BITS_LDO_VDD18_DCXO_REFTRIM_LP(0xF)},
	{-1, NULL, 0, 0, 0, 0},
};

static struct {
	int id;
	const char* name;
	int value;
	int pmic_regs_addr;
	int pmic_regs_mask;
} reinit_node_cfg[] = {
	{0, "DCDC_CPU_DTM", 0x2, ANA_REG_GLB_DCDC_CPU_REG0, BITS_DCDC_CPU_DEADTIME(0x3)},
	{1, "DCDC_GPU_DTM", 0x2, ANA_REG_GLB_DCDC_GPU_REG0, BITS_DCDC_GPU_DEADTIME(0x3)},
	{2, "DCDC_CORE_DTM", 0x2, ANA_REG_GLB_DCDC_CORE_REG0, BITS_DCDC_CORE_DEADTIME(0x3)},
	{3, "DCDC_MODEM_DTM", 0x2, ANA_REG_GLB_DCDC_MODEM_REG0, BITS_DCDC_MODEM_DEADTIME(0x3)},
	{4, "DCDC_MEM_DTM", 0x2, ANA_REG_GLB_DCDC_MEM_REG0, BITS_DCDC_MEM_DEADTIME(0x3)},
	{5, "DCDC_MEMQ_DTM", 0x2, ANA_REG_GLB_DCDC_MEMQ_REG0, BITS_DCDC_MEMQ_DEADTIME(0x3)},
	{6, "DCDC_GEN0_DTM", 0x2, ANA_REG_GLB_DCDC_GEN0_REG0, BITS_DCDC_GEN0_DEADTIME(0x3)},
	{7, "DCDC_GEN1_DTM", 0x2, ANA_REG_GLB_DCDC_GEN1_REG0, BITS_DCDC_GEN1_DEADTIME(0x3)},
	{8, "DCDC_SRAM_DTM", 0x2, ANA_REG_GLB_DCDC_SRAM_REG0, BITS_DCDC_SRAM_DEADTIME(0x3)},
	{9, "DCDC_WPA_DTM", 0x3, ANA_REG_GLB_DCDC_WPA_REG0, BITS_DCDC_WPA_DEADTIME(0x3)},
	{10, "DCDC_CPU_CF", 0x1, ANA_REG_GLB_DCDC_CPU_REG1, BITS_DCDC_CPU_CF(0x3)},
	{11, "DCDC_GPU_CF", 0x1, ANA_REG_GLB_DCDC_GPU_REG1, BITS_DCDC_GPU_CF(0x3)},
	{12, "DCDC_MODEM_CF", 0x1, ANA_REG_GLB_DCDC_MODEM_REG1, BITS_DCDC_MODEM_CF(0x3)},
	{13, "DCDC_WPA_CF", 0x1, ANA_REG_GLB_DCDC_WPA_REG0, BITS_DCDC_WPA_CF(0x3)},
	{14, "DCDC_CPU_STBOP", 0x2DF, ANA_REG_GLB_DCDC_CPU_REG2, GENMASK(12,0)},
	{15, "DCDC_GPU_STBOP", 0x2DF, ANA_REG_GLB_DCDC_GPU_REG2, GENMASK(12,0)},
	{16, "DCDC_CORE_STBOP", 0x2D8, ANA_REG_GLB_DCDC_CORE_REG2, GENMASK(12,0)},
	{17, "DCDC_MODEM_STBOP", 0xD9F, ANA_REG_GLB_DCDC_MODEM_REG2, GENMASK(12,0)},
	{18, "DCDC_SRAM_STBOP", 0x2D8, ANA_REG_GLB_DCDC_SRAM_REG2, GENMASK(12,0)},
	{-1, NULL, 0, 0, 0},
};

static const struct pmic_child_info sc2730_regulator_info[] = {
	{ .prefix = "DCDC", .driver = "sc2730-regulator"},
	{ .prefix = "LDO", .driver = "sc2730-regulator"},
	{}
};

static int sc2730_power_control_bind(struct udevice *dev)
{
	int children;
	struct udevice *pmic = dev->parent;

	children = pmic_bind_children(pmic, dev->node, sc2730_regulator_info);
	if (!children)
		dev_err(dev, "%s: %s - no child found\n", __func__, dev->name);

	return 0;
}

U_BOOT_DRIVER(sc2730_power_controler) = {
	.name = "sc2730-power-controler",
	.id = UCLASS_PMIC,
	.bind = sc2730_power_control_bind,
};

static int sc2730_adi_write(struct udevice *dev, u32 reg, u32 value)
{
	int ret;
	u32 wd_addr[2] = {reg, value};

	ret = dm_spi_xfer(dev, 16, &wd_addr[0], NULL, 0);
	if (ret)
		dev_err(dev, "***Warning: write pmic register:0x%08x failed.\n", reg);

	return ret;
}

static int sc2730_adi_read(struct udevice *dev, u32 *reg)
{
	int ret;

	ret = dm_spi_xfer(dev, 16, NULL, reg, 0);
	if (ret)
		dev_err(dev, "***Warning: read pmic register by adi failed.\n");

	return ret;
}

static int sc2730_reload_config(struct udevice *dev)
{
	int i, shft, ib_trim_val, reload_val, ret = 0;
	u32 efuse_val;

	for (i = 0; reinit_node_cfg[i].id != -1; i++) {
		shft = __ffs(reinit_node_cfg[i].pmic_regs_mask);

		ret = pmic_clrsetbits(dev, reinit_node_cfg[i].pmic_regs_addr,
			reinit_node_cfg[i].pmic_regs_mask,
			(reinit_node_cfg[i].value << shft) & (reinit_node_cfg[i].pmic_regs_mask));
		if (ret) {
			dev_err(dev, "reinit node configure id: %d failed.\n", i);
			return ret;
		}
	}

	efuse_val = sprd_pmic_efuse_read(reinit_node[0].efuse_block_id);
	shft = __ffs(reinit_node[0].efuse_bit_mask);

	ib_trim_val = (efuse_val & reinit_node[0].efuse_bit_mask) >> shft;
	shft = __ffs(reinit_node[i].pmic_regs_mask);

	if (ib_trim_val >= IB_ZCD_THRESHOLD_MAX)
		reload_val = 2;
	else if (ib_trim_val <= IB_ZCD_THRESHOLD_MIN)
		reload_val = 0;
	else
		reload_val = 1;

	for (i = 0; reinit_node[i].id <= 9; i++) {
		ret = pmic_clrsetbits(dev, reinit_node[i].pmic_regs_addr,
				reinit_node[i].pmic_regs_mask,
				(reload_val << shft) & (reinit_node[i].pmic_regs_mask));
		if (ret) {
			dev_err(dev, "reinit node id: %d failed.\n", i);
			return ret;
		}
	}

	for (i = 10; reinit_node[i].id != -1; i++) {
		efuse_val = sprd_pmic_efuse_read(reinit_node[i].efuse_block_id);
		shft = __ffs(reinit_node[i].efuse_bit_mask);

		reload_val = (efuse_val & reinit_node[i].efuse_bit_mask) >> shft;
		shft = __ffs(reinit_node[i].pmic_regs_mask);

		ret = pmic_clrsetbits(dev, reinit_node[i].pmic_regs_addr,
				reinit_node[i].pmic_regs_mask,
				(reload_val << shft) & (reinit_node[i].pmic_regs_mask));
		if (ret)
			dev_err(dev, "reinit node id: %d failed.\n", i);
	}

	return ret;
}

static int sc2730_reset_cbank_value(struct udevice *dev)
{
	int ret;
	u16 chip_id_low;
	u32 tmp;

	tmp = ANA_REG_GLB_CHIP_ID_LOW;
	ret = sc2730_adi_read(dev, &tmp);
	if (ret)
		return ret;

	chip_id_low = tmp & 0xffff;

	if (chip_id_low <= 0xb000)
		ret = sc2730_adi_write(dev, ANA_REG_GLB_TSX_CTRL11,
				BITS_DCXO_CORE_CBANK_LP(CBANK_VALUE));

	return ret;
}

static const struct pmic_child_info pmic_children_info[] = {
	{ .prefix = "power-controller", .driver = "sc2730-power-controler"},
	{ .prefix = "gpio-controller", .driver = "pmic_eic_sprd"},
	{ .prefix = "adc", .driver = "pmic_adc"},
	{ .prefix = "efuse", .driver = "pmic_efuse"},
	{ .prefix = "led-controller", .driver = "sprd-bltc"},
	{ .prefix = "vibrator", .driver = "sc27xx-vibrator"},
	{ .prefix = "rtc", .driver = "sprd-rtc"},
	{}
};

static int sc2730_write(struct udevice *dev, uint reg, const uint8_t *buff,
		       int len)
{
	int ret;
	u32 wd_addr, value;

	wd_addr = (u32)reg;
	value = *(u32 *)buff;

	ret = sc2730_adi_write(dev, wd_addr, value);
	if (ret)
		dev_err(dev, "***Warning: write pmic register failed.\n");

	return ret;
}

static int sc2730_read(struct udevice *dev, uint reg, uint8_t *buff, int len)
{
	int ret;
	u32 *tmp = (u32 *)buff, rd_addr = (u32)reg;

	ret = sc2730_adi_read(dev, &rd_addr);
	if (ret) {
		dev_err(dev, "***Warning: read pmic register failed.\n");
		return ret;
	}

	*tmp = rd_addr;
	return ret;
}

static int sc2730_bind(struct udevice *dev)
{
	int children;

	children = pmic_bind_children(dev, dev->node, pmic_children_info);
	if (!children)
		dev_err(dev, "%s: %s - no child found\n", __func__, dev->name);

	return 0;
}

static int sc2730_probe(struct udevice *dev)
{
	int ret;

	sc2730_adi_write(dev, ANA_REG_GLB_PWR_WR_PROT_VALUE, BITS_PWR_WR_PROT_VALUE(WR_UNLOCK));
	sc2730_adi_write(dev, ANA_REG_GLB_TSX_WR_PROT_VALUE, BITS_TSX_WR_PROT_VALUE(TSX_WR_UNLOCK));
	sc2730_adi_write(dev, ANA_REG_GLB_TSX_CTRL12, BITS_DCXO_32K_FRAC_DIV_RATIO_CTRL_HP(DIV_COEF));

	ret = pmic_clrsetbits(dev, ANA_REG_GLB_TSX_CTRL0, 0, BITS_DCXO_26M_REF_OUT_EN(TRANS_26M_EN));
	if (ret) {
		dev_err(dev, "sc2730 probe reg init failed.\n");
		return ret;
	}

	ret = sc2730_reload_config(dev);
	if (ret) {
		dev_err(dev, "sc2730 probe reload config failed.\n");
		return ret;
	}

	ret = sc2730_reset_cbank_value(dev);
	if (ret)
		dev_err(dev, "sc2730 probe reset cbank failed.\n");

	return ret;
}
static struct dm_pmic_ops sc2730_ops = {
	.read = sc2730_read,
	.write = sc2730_write,
};

static const struct udevice_id sc2730_ids[] = {
	{ .compatible = "sprd,sc2730" },
	{ }
};

U_BOOT_DRIVER(sc2730_pmic) = {
	.name = "sc2730_pmic",
	.id = UCLASS_PMIC,
	.of_match = sc2730_ids,
	.bind = sc2730_bind,
	.probe = sc2730_probe,
	.ops = &sc2730_ops,
};
