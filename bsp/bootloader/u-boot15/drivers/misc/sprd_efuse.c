// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2019 Spreadtrum Communications Inc.

#include <asm/types.h>
#include <asm/io.h>
#include <common.h>
#include <clk.h>
#include <dm/device.h>
#include <dm/read.h>
#include <dm/uclass-id.h>
#include <misc.h>

#define SPRD_EFUSE_ALL0_INDEX		0x8
#define SPRD_EFUSE_MODE_CTRL		0xc
#define SPRD_EFUSE_IP_VER		0x14
#define SPRD_EFUSE_CFG0			0x18
#define SPRD_EFUSE_NS_EN		0x20
#define SPRD_EFUSE_NS_ERR_FLAG		0x24
#define SPRD_EFUSE_NS_FLAG_CLR		0x28
#define SPRD_EFUSE_NS_MAGIC_NUM		0x2c
#define SPRD_EFUSE_FW_CFG		0x50
#define SPRD_EFUSE_PW_SWT		0x54
#define SPRD_EFUSE_MEM(val)		(0x1000 + ((val) << 2))

/* bits definitions for register SPRD_EFUSE_MODE_CTRL */
#define SPRD_EFUSE_ALL0_CHECK_START       BIT(0)

/* bits definitions for register SPRD EFUSE_NS_EN */
#define SPRD_NS_VDD_EN			BIT(0)
#define SPRD_NS_AUTO_CHECK_ENABLE	BIT(1)
#define SPRD_DOUBLE_BIT_EN_NS		BIT(2)
#define SPRD_NS_MARGIN_RD_ENABLE	BIT(3)
#define SPRD_NS_LOCK_BIT_WR_EN		BIT(4)

/* bits definitions for register SPRD_EFUSE_NS_ERR_FLAG */
#define SPRD_NS_WORD0_ERR_FLAG		BIT(0)
#define SPRD_NS_WORD1_ERR_FLAG		BIT(1)
#define SPRD_NS_WORD0_PROT_FLAG		BIT(4)
#define SPRD_NS_WORD1_PROT_FLAG		BIT(5)
#define SPRD_NS_PG_EN_WR_FLAG		BIT(8)
#define SPRD_NS_VDD_ON_RD_FLAG		BIT(9)
#define SPRD_NS_BLOCK0_RD_FLAG		BIT(10)
#define SPRD_NS_MAGNUM_WR_FLAG		BIT(11)
#define SPRD_NS_ENK_ERR_FLAG		BIT(12)
#define SPRD_NS_ALL0_CHECK_FLAG		BIT(13)

/* bits definitions for register SPRD_EFUSE_NS_FLAG_CLR */
#define SPRD_NS_WORD0_ERR_CLR		BIT(0)
#define SPRD_NS_WORD1_ERR_CLR		BIT(1)
#define SPRD_NS_WORD0_PROT_CLR		BIT(4)
#define SPRD_NS_WORD1_PROT_CLR		BIT(5)
#define SPRD_NS_PG_EN_WR_CLR		BIT(8)
#define SPRD_NS_VDD_ON_RD_CLR		BIT(9)
#define SPRD_NS_BLOCK0_RD_CLR		BIT(10)
#define SPRD_NS_MAGNUM_WR_CLR		BIT(11)
#define SPRD_NS_ENK_ERR_CLR		BIT(12)
#define SPRD_NS_ALL0_CHECK_CLR		BIT(13)

/* bits definitions for register SPRD_EFUSE_PW_SWT */
#define SPRD_EFS_ENK1_ON		BIT(0)
#define SPRD_EFS_ENK2_ON		BIT(1)
#define SPRD_NS_S_PG_EN			BIT(2)

#define SPRD_NS_EFUSE_MAGIC_NUMBER(x)	((x) & 0xffff)
#define SPRD_EFUSE_MAGIC_NUMBER              0x8810
#define SPRD_ERR_CLR_MASK		0x3fff

extern void tmr_udelay (unsigned long usec);

struct sprd_efuse {
	struct udevice *dev;
	void *base;
};

static void sprd_efuse_prog_power_on(struct sprd_efuse *efuse)
{
	u32 cfg;

	cfg = __raw_readl(efuse->base + SPRD_EFUSE_PW_SWT);
	cfg &= ~SPRD_EFS_ENK2_ON;
	__raw_writel(cfg, efuse->base + SPRD_EFUSE_PW_SWT);
	tmr_udelay(1000);
	cfg |= SPRD_EFS_ENK1_ON;
	__raw_writel(cfg, efuse->base + SPRD_EFUSE_PW_SWT);
	tmr_udelay(1000);
}

static void sprd_efuse_prog_power_off(struct sprd_efuse *efuse)
{
	u32 cfg;

	cfg = __raw_readl(efuse->base + SPRD_EFUSE_PW_SWT);
	cfg &= ~SPRD_EFS_ENK1_ON;
	__raw_writel(cfg, efuse->base + SPRD_EFUSE_PW_SWT);
	tmr_udelay(1000);
	cfg |= SPRD_EFS_ENK2_ON;
	__raw_writel(cfg, efuse->base + SPRD_EFUSE_PW_SWT);
	tmr_udelay(1000);
}

static void sprd_efuse_read_power_on(struct sprd_efuse *efuse)
{
	u32 cfg;

	cfg = __raw_readl(efuse->base + SPRD_EFUSE_NS_EN);
	cfg |= SPRD_NS_VDD_EN;
	__raw_writel(cfg, efuse->base + SPRD_EFUSE_NS_EN);
	tmr_udelay(1000);
}

static void sprd_efuse_read_power_off(struct sprd_efuse *efuse)
{
	u32 cfg;

	cfg = __raw_readl(efuse->base + SPRD_EFUSE_NS_EN);
	cfg &= ~SPRD_NS_VDD_EN;
	__raw_writel(cfg, efuse->base + SPRD_EFUSE_NS_EN);
	tmr_udelay(1000);
}

static void sprd_efuse_prog_lock(struct sprd_efuse *efuse, bool en_lock)
{
	u32 cfg;

	cfg = __raw_readl(efuse->base + SPRD_EFUSE_NS_EN);
	if(en_lock)
		cfg |= SPRD_NS_LOCK_BIT_WR_EN;
	else
		cfg &= ~SPRD_NS_LOCK_BIT_WR_EN;

	__raw_writel(cfg, efuse->base + SPRD_EFUSE_NS_EN);
}

static void sprd_efuse_double(struct sprd_efuse *efuse, bool backup)
{
	u32 cfg;

	cfg = __raw_readl(efuse->base + SPRD_EFUSE_NS_EN);
	if(backup)
		cfg |= SPRD_DOUBLE_BIT_EN_NS;
	else
		cfg &= ~SPRD_DOUBLE_BIT_EN_NS;

	__raw_writel(cfg, efuse->base + SPRD_EFUSE_NS_EN);
}

static void sprd_efuse_auto_check(struct sprd_efuse *efuse, bool en_lock)
{
	u32 cfg;

	cfg = __raw_readl(efuse->base + SPRD_EFUSE_NS_EN);
	if (en_lock)
		cfg |= SPRD_NS_AUTO_CHECK_ENABLE;
	else
		cfg &= ~SPRD_NS_AUTO_CHECK_ENABLE;

	__raw_writel(cfg, efuse->base + SPRD_EFUSE_NS_EN);
}

static int sprd_efuse_raw_prog(struct sprd_efuse *efuse, u32 blk, u32 val,
			       bool backup, bool lock)
{
	u32 cfg;
	int ret;

	__raw_writel(SPRD_NS_EFUSE_MAGIC_NUMBER(SPRD_EFUSE_MAGIC_NUMBER),
			    efuse->base + SPRD_EFUSE_NS_MAGIC_NUM);
	sprd_efuse_prog_power_on(efuse);
	__raw_writel(SPRD_ERR_CLR_MASK, efuse->base + SPRD_EFUSE_NS_FLAG_CLR);
	cfg = __raw_readl(efuse->base + SPRD_EFUSE_PW_SWT);
	cfg |= SPRD_NS_S_PG_EN;
	__raw_writel(cfg, efuse->base + SPRD_EFUSE_PW_SWT);

	sprd_efuse_double(efuse, backup);
	sprd_efuse_auto_check(efuse, true);
	__raw_writel(val, efuse->base + SPRD_EFUSE_MEM(blk));
	sprd_efuse_auto_check(efuse, false);
	sprd_efuse_double(efuse, false);
	ret = __raw_readl(efuse->base + SPRD_EFUSE_NS_ERR_FLAG);
	if (!ret) {
		sprd_efuse_prog_lock(efuse, lock);
		__raw_writel(0x0, efuse->base + SPRD_EFUSE_MEM(blk));
		sprd_efuse_prog_lock(efuse, false);
	}
	__raw_writel(SPRD_ERR_CLR_MASK, efuse->base + SPRD_EFUSE_NS_FLAG_CLR);

	cfg = __raw_readl(efuse->base + SPRD_EFUSE_PW_SWT);
	cfg &= ~SPRD_NS_S_PG_EN;
	__raw_writel(cfg, efuse->base + SPRD_EFUSE_PW_SWT);
	sprd_efuse_prog_power_off(efuse);
	__raw_writel(0, efuse->base + SPRD_EFUSE_NS_MAGIC_NUM);

	debugf("sprd efuse prog blk %d, ret 0x%x, val 0x%08x\n", blk, ret, val);
	return ret;
}

static u32 sprd_efuse_raw_read(struct sprd_efuse *efuse, int blk, int *data, bool backup)
{
	int ret;

	sprd_efuse_read_power_on(efuse);
	__raw_writel(SPRD_ERR_CLR_MASK, efuse->base + SPRD_EFUSE_NS_FLAG_CLR);
	sprd_efuse_double(efuse, backup);

	*data = __raw_readl(efuse->base + SPRD_EFUSE_MEM(blk));
	sprd_efuse_double(efuse, false);
	sprd_efuse_read_power_off(efuse);

	ret = __raw_readl(efuse->base + SPRD_EFUSE_NS_ERR_FLAG);
	if (ret) {
		dev_err(dev, "sprd read efuse error 0x%x", ret);
		__raw_writel(SPRD_ERR_CLR_MASK, efuse->base + SPRD_EFUSE_NS_FLAG_CLR);
		*data = 0;
	}
	debugf("sprd efuse read blk %d, ret 0x%x, val 0x%08x\n", blk, ret, *data);

	return ret;
}

int sprd_efuse_read(struct udevice *dev, int offset, int *val, int en)
{
	struct sprd_efuse *efuse = dev_get_priv(dev);

	return sprd_efuse_raw_read(efuse, offset, val, en);
}

int sprd_efuse_write(struct udevice *dev, int offset, int val, int en)
{
	struct sprd_efuse *efuse = dev_get_priv(dev);

	return sprd_efuse_raw_prog(efuse, offset, val, false, false);
}

static int sprd_efuse_probe(struct udevice *dev)
{
	struct sprd_efuse *efuse;
	struct clk clk;
	int ret;

	efuse = (struct sprd_efuse *)dev_get_priv(dev);
	if (efuse == NULL)
		return -ENOMEM;

	ret  = clk_get_by_name(dev, "enable", &clk);
	if (ret) {
		dev_err(dev, "Can't get sprd efuse clock: %d\n",ret);
		return ret;
	}
	ret = clk_enable(&clk);
	if (ret) {
		dev_err(dev, "failed enable sprd efuse clock: %d\n",ret);
		return ret;
	}

	efuse->base = dev_read_addr_ptr(dev);
	efuse->dev = dev;
	return 0;
}

static const struct misc_ops sprd_efuse_ops = {
	.read = sprd_efuse_read,
};

static const struct udevice_id sprd_efuse_ids[] = {
	{ .compatible = "sprd,pike2-efuse"},
	{ .compatible = "sprd,sharkle-efuse"},
	{ .compatible = "sprd,sharkl3-efuse"},
	{ .compatible = "sprd,sharkl5pro-efuse"},

	{ }
};

U_BOOT_DRIVER(sprd_efuse) = {
	.name = "sprd_efuse",
	.id = UCLASS_MISC,
	.of_match = sprd_efuse_ids,
	.ops = &sprd_efuse_ops,
	.priv_auto_alloc_size = sizeof(struct sprd_efuse),
	.probe = sprd_efuse_probe,
};
