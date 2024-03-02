// SPDX-License-Identifier: GPL-2.0
//
// Spreadtrum clock infrastructure
//
// Copyright (C) 2019 Unisoc, Inc.
// Author: Chunyan Zhang <chunyan.zhang@spreadtrum.com>
// Author: Xiongpeng Wu <xiongpeng.wu@unisoc.com>

#include "common.h"

const char *clk_hw_get_name(const struct clk_hw *hw)
{
	return hw->init->name;
}
EXPORT_SYMBOL_GPL(clk_hw_get_name);

unsigned int clk_hw_get_num_parents(const struct clk_hw *hw)
{
	return hw->init->num_parents;
}
EXPORT_SYMBOL_GPL(clk_hw_get_num_parents);

unsigned long clk_hw_get_flags(const struct clk_hw *hw)
{
	return hw->init->flags;
}
EXPORT_SYMBOL_GPL(clk_hw_get_flags);

int uclass_find_clk_by_name(enum uclass_id id, const char *name, struct clk *clk)
{
	struct uclass *uc;
	struct udevice *dev;
	int ret;
	int clk_id;
	struct sprd_clk_desc *clk_priv;
	struct sprd_fixed_rate_clk_desc *fixed_rate_priv;
	ulong clk_tag;

	if (!name)
		return -EINVAL;

	assert(clk);
	clk->dev = NULL;

	ret = uclass_get(id, &uc);
	if (ret)
		return ret;

	uclass_foreach_dev(dev, uc) {
		clk_tag = dev_get_driver_data(dev);
		if (clk_tag) {
			clk_priv = dev_get_priv(dev);
			for (clk_id = 0; clk_id < clk_priv->hw_clks->num; clk_id++) {
				if (!strcmp(clk_priv->hw_clks->hws[clk_id]->init->name, name)) {
					clk->dev = dev;
					clk->id = clk_id;
					return 0;
				}
			}
		}
		else {
			fixed_rate_priv = dev_get_priv(dev);
			for (clk_id = 0; clk_id < fixed_rate_priv->hw_clks->num; clk_id++) {
				if (!strcmp(fixed_rate_priv->hw_clks->hws[clk_id]->init->name, name)) {
					clk->dev = dev;
					clk->id = clk_id;
					return 0;
				}
			}
		}
	}

	return -ENODEV;
}

static void sprd_clk_set_regmap(const struct sprd_clk_desc *desc,
				void __iomem *base)
{
	int i;
	struct sprd_clk_common *cclk;

	for (i = 0; i < desc->num_clk_clks; i++) {
		cclk = desc->clk_clks[i];
		if (!cclk)
			continue;

		cclk->reg_base = base;
	}
}

int sprd_clk_regmap_init(struct udevice *dev,
			 const struct sprd_clk_desc *desc)
{
	void __iomem *base;

	base = dev_read_addr_ptr(dev);
	if (base == (void *)FDT_ADDR_T_NONE) {
		debug("%s: Failed to get base address\n", __func__);
		return -EINVAL;
	}
	sprd_clk_set_regmap(desc, base);

	return 0;
}

static ulong sprd_clk_get_rate(struct clk *clk)
{
	struct sprd_clk_desc *desc = dev_get_priv(clk->dev);
	struct clk_hw_onecell_data *hwclks = desc->hw_clks;
	struct clk_hw *hw = hwclks->hws[clk->id];
	unsigned long parent_rate = 0;
	struct clk pclk;
	const char *pname;
	int p_mux;

	if (hw->init->ops->get_parent) {
		p_mux = hw->init->ops->get_parent(hwclks->hws[clk->id]);
		pname = hw->init->parent_names[p_mux];
	} else {
		pname = hw->init->parent_names[0];
	}
	if (pname) {
		if (!uclass_find_clk_by_name(UCLASS_CLK, pname, &pclk))
			parent_rate = clk_get_rate(&pclk);
		else
			parent_rate = 0;
	}

	return hw->init->ops->recalc_rate(hwclks->hws[clk->id], parent_rate);
}

static int sprd_clk_set_rate(struct clk *clk, ulong rate)
{
	struct sprd_clk_desc *desc = dev_get_priv(clk->dev);
	struct clk_hw_onecell_data *hwclks = desc->hw_clks;
	struct clk_hw *hw = hwclks->hws[clk->id];
	unsigned long parent_rate = 0;
	struct clk pclk;
	const char *pname;
	int p_mux;

	if (hw->init->ops->get_parent) {
		p_mux = hw->init->ops->get_parent(hwclks->hws[clk->id]);
		pname = hw->init->parent_names[p_mux];
	} else {
		pname = hw->init->parent_names[0];
	}
	if (pname) {
		if (!uclass_find_clk_by_name(UCLASS_CLK, pname, &pclk))
			parent_rate = clk_get_rate(&pclk);
		else
			parent_rate = 0;
	}

	return hw->init->ops->set_rate(hwclks->hws[clk->id], rate, parent_rate);
}

static int sprd_clk_set_parent(struct clk *clk, struct clk *parent)
{
	struct sprd_clk_desc *desc = dev_get_priv(clk->dev);
	struct clk_hw_onecell_data *hwclks = desc->hw_clks;
	struct clk_hw *hw = hwclks->hws[clk->id];
	struct sprd_clk_desc *pdesc = dev_get_priv(parent->dev);
	struct clk_hw_onecell_data *phwclks = pdesc->hw_clks;
	struct clk_hw *phw = phwclks->hws[parent->id];
	int p_id;

	for (p_id = 0; p_id < hw->init->num_parents; p_id++) {
		if (!strncmp(hw->init->parent_names[p_id], phw->init->name, strlen(phw->init->name)))
			return hw->init->ops->set_parent(hwclks->hws[clk->id], p_id);
	}
	return -ENOSYS;
}

static int sprd_clk_enable(struct clk *clk)
{
	struct sprd_clk_desc *desc = dev_get_priv(clk->dev);
	struct clk_hw_onecell_data *hwclks = desc->hw_clks;
	struct clk_hw *hw = hwclks->hws[clk->id];

	return hw->init->ops->enable(hwclks->hws[clk->id]);
}

static int sprd_clk_disable(struct clk *clk)
{
	struct sprd_clk_desc *desc = dev_get_priv(clk->dev);
	struct clk_hw_onecell_data *hwclks = desc->hw_clks;
	struct clk_hw *hw = hwclks->hws[clk->id];

	return hw->init->ops->disable(hwclks->hws[clk->id]);
}

int clk_init(void)
{
	int index = 0;
	struct udevice *devp;

	while (!uclass_get_device(UCLASS_CLK, index++, &devp));

	return 0;
}

const struct clk_ops clk_uclass_ops = {
	.get_rate = sprd_clk_get_rate,
	.set_rate = sprd_clk_set_rate,
	.set_parent = sprd_clk_set_parent,
	.enable = sprd_clk_enable,
	.disable = sprd_clk_disable,
};


MODULE_LICENSE("GPL v2");
