// SPDX-License-Identifier: GPL-2.0
//
// Spreadtrum multiplexer clock driver
//
// Copyright (C) 2017 Spreadtrum, Inc.
// Author: Chunyan Zhang <chunyan.zhang@spreadtrum.com>

#include "mux.h"

int sprd_mux_helper_get_parent(const struct sprd_clk_common *common,
			       const struct sprd_mux_ssel *mux)
{
	unsigned int reg;
	unsigned int parent;
	int num_parents;
	int i;

	reg = readl((void *)(common->reg_base + common->reg));
	parent = reg >> mux->shift;
	parent &= (1 << mux->width) - 1;

	if (!mux->table)
		return parent;

	num_parents = clk_hw_get_num_parents(&common->hw);

	for (i = 0; i < num_parents - 1; i++)
		if (parent >= mux->table[i] && parent < mux->table[i + 1])
			return i;

	return num_parents - 1;
}
EXPORT_SYMBOL_GPL(sprd_mux_helper_get_parent);

static int sprd_mux_get_parent(struct clk_hw *hw)
{
	struct sprd_mux *cm = hw_to_sprd_mux(hw);

	return sprd_mux_helper_get_parent(&cm->common, &cm->mux);
}

int sprd_mux_helper_set_parent(const struct sprd_clk_common *common,
			       const struct sprd_mux_ssel *mux,
			       int index)
{
	unsigned int reg;

	if (mux->table)
		index = mux->table[index];

	reg = readl((void *)(common->reg_base + common->reg));
	reg &= ~GENMASK(mux->width + mux->shift - 1, mux->shift);
	writel(reg | (index << mux->shift),
	       (void *)(common->reg_base + common->reg));

	return 0;
}
EXPORT_SYMBOL_GPL(sprd_mux_helper_set_parent);

static int sprd_mux_set_parent(struct clk_hw *hw, u8 index)
{
	struct sprd_mux *cm = hw_to_sprd_mux(hw);

	return sprd_mux_helper_set_parent(&cm->common, &cm->mux, index);
}

const struct sprd_clk_ops sprd_mux_ops = {
	.get_parent = sprd_mux_get_parent,
	.set_parent = sprd_mux_set_parent,
};
EXPORT_SYMBOL_GPL(sprd_mux_ops);

