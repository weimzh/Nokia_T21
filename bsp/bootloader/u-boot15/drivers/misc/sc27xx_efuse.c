// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2019 Spreadtrum Communications Inc.

#include <asm-generic/errno.h>
#include <asm/arch/sprd_reg.h>
#include <asm/types.h>
#include <common.h>
#include <misc.h>
#include <spi.h>
#include <dm/device.h>
#include <dm/read.h>
#include <dm/uclass-id.h>

/* Efuse controller registers definition */
#define SC27XX_EFUSE_GLB_CTRL		0x0
#define SC27XX_EFUSE_DATA_RD		0x4
#define SC27XX_EFUSE_DATA_WR		0x8
#define SC27XX_EFUSE_BLOCK_INDEX	0xc
#define SC27XX_EFUSE_MODE_CTRL		0x10
#define SC27XX_EFUSE_STATUS		0x14
#define SC27XX_EFUSE_WR_TIMING_CTRL	0x20
#define SC27XX_EFUSE_RD_TIMING_CTRL	0x24
#define SC27XX_EFUSE_EFUSE_DEB_CTRL	0x28

/* Mask definition for SC27XX_EFUSE_BLOCK_INDEX register */
#define SC27XX_EFUSE_BLOCK_MASK		0x1f

/* Bits definitions for SC27XX_EFUSE_MODE_CTRL register */
#define SC27XX_EFUSE_PG_START		BIT(0)
#define SC27XX_EFUSE_RD_START		BIT(1)
#define SC27XX_EFUSE_CLR_RDDONE		BIT(2)

/* Bits definitions for SC27XX_EFUSE_STATUS register */
#define SC27XX_EFUSE_PGM_BUSY		BIT(0)
#define SC27XX_EFUSE_READ_BUSY		BIT(1)
#define SC27XX_EFUSE_STANDBY		BIT(2)
#define SC27XX_EFUSE_GLOBAL_PROT	BIT(3)
#define SC27XX_EFUSE_RD_DONE		BIT(4)

/* Block number and block width (bytes) definitions */
#define SC27XX_EFUSE_BLOCK_MAX		32

/* workround: Currently, udelay does not implement the interface
 * according to the uboot framework, and temporarily uses the
 * interface tmr_udelay
 */
extern void tmr_udelay (unsigned long usec);

struct sc27xx_efuse {
	struct udevice *dev;
	u32 base;
};

static int sc27xx_efuse_reg_read(struct udevice *dev, u32 reg, u32 *value)
{
	u32 tmp;
	int ret;

	ret = pmic_read(dev->parent, reg, (uint8_t *)&tmp, 0);
	if (ret) {
		dev_err(dev, "uboot sc27xx efuse get fail, ret is %d\n", ret);
		return ret;
	}

	*value = tmp;

	return 0;
}

static int sc27xx_efuse_reg_write(struct udevice *dev, u32 reg, u32 value)
{
	int ret;

	ret = pmic_write(dev->parent, reg, (uint8_t *)&value, 0);
	if (ret)
		dev_err(dev, "uboot sc27xx efuse set fail, ret is [%d]\n", ret);

	return ret;
}

static int sc27xx_efuse_reg_update_bits(struct udevice *dev, u32 reg, u32 clr, u32 set)
{
	return pmic_clrsetbits(dev->parent, reg, clr, set);
}

static int sc27xx_efuse_poll_status(struct udevice *dev, u32 bits)
{
	struct sc27xx_efuse *efuse;
	u32 val, bit_status = 1, count = 3000;
	int ret;

	efuse = (struct sc27xx_efuse *)dev_get_priv(dev);
	if (efuse == NULL)
		return -EINVAL;

	tmr_udelay(200);
	while (bit_status && count--) {
		ret = sc27xx_efuse_reg_read(dev, efuse->base + SC27XX_EFUSE_STATUS, &val);
		bit_status = (~val) & bits;
		tmr_udelay(10);
	}

	if (count <= 0) {
		dev_err(dev, "read sc27xx efuse value timeout\n");
		return -ETIMEDOUT;
	}

	return 0;
}

int sc27xx_efuse_read(struct udevice *dev, int index, int *val, int size)
{
	struct sc27xx_efuse *efuse;
	int ret;

	efuse = (struct sc27xx_efuse *)dev_get_priv(dev);
	if (efuse == NULL)
		return -EINVAL;

	if (index >= SC27XX_EFUSE_BLOCK_MAX)
		return -EINVAL;

	/* Enable the efuse controller. */
	ret = sc27xx_efuse_reg_update_bits(dev, ANA_REG_GLB_ARM_MODULE_EN,
					  BIT_ANA_EFS_EN, BIT_ANA_EFS_EN);
	if (ret)
		return ret;

	/* Clear the read done flag. */
	ret = sc27xx_efuse_reg_update_bits(dev, efuse->base + SC27XX_EFUSE_MODE_CTRL,
				 	 SC27XX_EFUSE_CLR_RDDONE,
				 	 SC27XX_EFUSE_CLR_RDDONE);
	if (ret)
		return ret;

	/*
	 * Before reading, we should ensure the efuse controller is in
	 * standby state.
	 */
	ret = sc27xx_efuse_poll_status(dev, SC27XX_EFUSE_STANDBY);
	if (ret)
		return ret;

	/* Set the block address to be read. */
	ret = sc27xx_efuse_reg_write(dev, efuse->base + SC27XX_EFUSE_BLOCK_INDEX,
				    index & SC27XX_EFUSE_BLOCK_MASK);
	if (ret)
		return ret;

	/* Start reading process from efuse memory. */
	ret = sc27xx_efuse_reg_update_bits(dev, efuse->base + SC27XX_EFUSE_MODE_CTRL,
				           SC27XX_EFUSE_RD_START,
				           SC27XX_EFUSE_RD_START);
	if (ret)
		return ret;

	/*
	 * Polling the read done status to make sure the reading process
	 * is completed, that means the data can be read out now.
	 */
	ret = sc27xx_efuse_poll_status(dev, SC27XX_EFUSE_RD_DONE);
	if (ret)
		return ret;

	/* Read data from efuse memory. */
	ret = sc27xx_efuse_reg_read(dev, efuse->base + SC27XX_EFUSE_DATA_RD, val);
	if (ret)
		return ret;
	debugf("sc27xx efuse blk %d, val 0x%x\n", index, *val);

	/* Clear the read done flag. */
	ret = sc27xx_efuse_reg_update_bits(dev, efuse->base + SC27XX_EFUSE_MODE_CTRL,
				 	 SC27XX_EFUSE_CLR_RDDONE,
				 	 SC27XX_EFUSE_CLR_RDDONE);
	if (ret)
		return ret;

	return sc27xx_efuse_reg_update_bits(dev, ANA_REG_GLB_ARM_MODULE_EN,
					  BIT_ANA_EFS_EN, 0);
}

static int sc27xx_efuse_probe(struct udevice *dev)
{
	struct sc27xx_efuse *efuse_priv;

	efuse_priv = (struct sc27xx_efuse *)dev_get_priv(dev);
	if (efuse_priv == NULL)
		return -ENOMEM;

	efuse_priv->base = (u32)dev_read_addr(dev);
	efuse_priv->dev = dev;

	return 0;
}

static const struct misc_ops sc27xx_efuse_ops = {
	.read = sc27xx_efuse_read,
};

static const struct udevice_id sc27xx_efuse_ids[] = {
	{ .compatible = "sprd,sc2720-efuse" },
	{ }
};

U_BOOT_DRIVER(pmic_efuse) = {
	.name = "pmic_efuse",
	.id = UCLASS_MISC,
	.of_match = sc27xx_efuse_ids,
	.ops = &sc27xx_efuse_ops,
	.priv_auto_alloc_size = sizeof(struct sc27xx_efuse),
	.probe = sc27xx_efuse_probe,
};
