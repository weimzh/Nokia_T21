// SPDX-License-Identifier: GPL-2.0
//
// Spreadtrum gate clock driver
//
// Copyright (C) 2017 Spreadtrum, Inc.
// Author: Chunyan Zhang <chunyan.zhang@spreadtrum.com>

#include "gate.h"

static void clk_gate_toggle(const struct sprd_gate *sg, bool en)
{
	const struct sprd_clk_common *common = &sg->common;
	unsigned int reg;
	bool set = sg->flags & CLK_GATE_SET_TO_DISABLE ? true : false;

	set ^= en;

	reg = readl((void *)(common->reg_base + common->reg));

	if (set)
		reg |= sg->enable_mask;
	else
		reg &= ~sg->enable_mask;

	writel(reg, (void *)(common->reg_base + common->reg));
}

static void clk_sc_gate_toggle(const struct sprd_gate *sg, bool en)
{
	const struct sprd_clk_common *common = &sg->common;
	bool set = sg->flags & CLK_GATE_SET_TO_DISABLE ? 1 : 0;
	unsigned int offset;

	set ^= en;

	/*
	 * Each set/clear gate clock has three registers:
	 * common->reg			- base register
	 * common->reg + offset		- set register
	 * common->reg + 2 * offset	- clear register
	 */
	offset = set ? sg->sc_offset : sg->sc_offset * 2;

	writel(sg->enable_mask,
	       (void *)(common->reg_base + common->reg + offset));
}

static int sprd_gate_disable(struct clk_hw *hw)
{
	struct sprd_gate *sg = hw_to_sprd_gate(hw);

	clk_gate_toggle(sg, false);

	return 0;
}

static int sprd_gate_enable(struct clk_hw *hw)
{
	struct sprd_gate *sg = hw_to_sprd_gate(hw);

	clk_gate_toggle(sg, true);

	return 0;
}

static int sprd_sc_gate_disable(struct clk_hw *hw)
{
	struct sprd_gate *sg = hw_to_sprd_gate(hw);

	clk_sc_gate_toggle(sg, false);

	return 0;
}

static int sprd_sc_gate_enable(struct clk_hw *hw)
{
	struct sprd_gate *sg = hw_to_sprd_gate(hw);

	clk_sc_gate_toggle(sg, true);

	return 0;
}

static int sprd_pll_sc_gate_enable(struct clk_hw *hw)
{
	struct sprd_gate *sg = hw_to_sprd_gate(hw);

	clk_sc_gate_toggle(sg, true);
	udelay(sg->udelay);

	return 0;
}

static int sprd_gate_is_enabled(struct clk_hw *hw)
{
	struct sprd_gate *sg = hw_to_sprd_gate(hw);
	struct sprd_clk_common *common = &sg->common;
	unsigned int reg;

	reg = readl((void *)(common->reg_base + common->reg));

	if (sg->flags & CLK_GATE_SET_TO_DISABLE)
		reg ^= sg->enable_mask;

	reg &= sg->enable_mask;

	return reg ? 1 : 0;
}

const struct sprd_clk_ops sprd_gate_ops = {
	.disable	= sprd_gate_disable,
	.enable		= sprd_gate_enable,
	.is_enabled	= sprd_gate_is_enabled,
};
EXPORT_SYMBOL_GPL(sprd_gate_ops);

const struct sprd_clk_ops sprd_sc_gate_ops = {
	.disable	= sprd_sc_gate_disable,
	.enable		= sprd_sc_gate_enable,
	.is_enabled	= sprd_gate_is_enabled,
};
EXPORT_SYMBOL_GPL(sprd_sc_gate_ops);

const struct sprd_clk_ops sprd_pll_sc_gate_ops = {
	.unprepare	= sprd_sc_gate_disable,
	.prepare	= sprd_pll_sc_gate_enable,
};
EXPORT_SYMBOL_GPL(sprd_pll_sc_gate_ops);
