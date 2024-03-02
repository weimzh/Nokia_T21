// SPDX-License-Identifier: GPL-2.0
//
// Spreadtrum divider clock driver
//
// Copyright (C) 2017 Spreadtrum, Inc.
// Author: Chunyan Zhang <chunyan.zhang@spreadtrum.com>

#include "div.h"

#define div_mask(width)	((1 << (width)) - 1)

static unsigned int _get_table_div(const struct clk_div_table *table,
				   unsigned int val)
{
	const struct clk_div_table *clkt;

	for (clkt = table; clkt->div; clkt++)
		if (clkt->val == val)
			return clkt->div;
	return 0;
}

static unsigned int _get_div(const struct clk_div_table *table,
			     unsigned int val, unsigned long flags, u8 width)
{
	if (flags & CLK_DIVIDER_ONE_BASED)
		return val;
	if (flags & CLK_DIVIDER_POWER_OF_TWO)
		return 1 << val;
	if (flags & CLK_DIVIDER_MAX_AT_ZERO)
		return val ? val : div_mask(width) + 1;
	if (table)
		return _get_table_div(table, val);
	return val + 1;
}

static bool _is_valid_table_div(const struct clk_div_table *table,
				unsigned int div)
{
	const struct clk_div_table *clkt;

	for (clkt = table; clkt->div; clkt++)
		if (clkt->div == div)
			return true;
	return false;
}

static bool _is_valid_div(const struct clk_div_table *table, unsigned int div,
			  unsigned long flags)
{
	if (flags & CLK_DIVIDER_POWER_OF_TWO)
		return is_power_of_2(div);
	if (table)
		return _is_valid_table_div(table, div);
	return true;
}

static unsigned int _get_table_val(const struct clk_div_table *table,
				   unsigned int div)
{
	const struct clk_div_table *clkt;

	for (clkt = table; clkt->div; clkt++)
		if (clkt->div == div)
			return clkt->val;
	return 0;
}

static unsigned int _get_val(const struct clk_div_table *table,
			     unsigned int div, unsigned long flags, u8 width)
{
	if (flags & CLK_DIVIDER_ONE_BASED)
		return div;
	if (flags & CLK_DIVIDER_POWER_OF_TWO)
		return __ffs(div);
	if (flags & CLK_DIVIDER_MAX_AT_ZERO)
		return (div == div_mask(width) + 1) ? 0 : div;
	if (table)
		return  _get_table_val(table, div);
	return div - 1;
}

int divider_get_val(unsigned long rate, unsigned long parent_rate,
		    const struct clk_div_table *table, u8 width,
		    unsigned long flags)
{
	unsigned int div, value;

	div = DIV_ROUND_UP_ULL((u64)parent_rate, rate);

	if (!_is_valid_div(table, div, flags))
		return -EINVAL;

	value = _get_val(table, div, flags, width);

	return min_t(unsigned int, value, div_mask(width));
}
EXPORT_SYMBOL_GPL(divider_get_val);

unsigned long divider_recalc_rate(struct clk_hw *hw, unsigned long parent_rate,
				  unsigned int val,
				  const struct clk_div_table *table,
				  unsigned long flags, unsigned long width)
{
	unsigned int div;

	div = _get_div(table, val, flags, width);
	if (!div) {
		debug("%s: Zero divisor and CLK_DIVIDER_ALLOW_ZERO not set\n",
			hw->init->name);
		return parent_rate;
	}

	return DIV_ROUND_UP_ULL((u64)parent_rate, div);
}

long sprd_div_helper_round_rate(struct sprd_clk_common *common,
				const struct sprd_div_internal *div,
				unsigned long rate,
				unsigned long *parent_rate)
{
	//return divider_round_rate(&common->hw, rate, parent_rate,
	//			  NULL, div->width, 0);
	return 0;
}
EXPORT_SYMBOL_GPL(sprd_div_helper_round_rate);

static long sprd_div_round_rate(struct clk_hw *hw, unsigned long rate,
				unsigned long *parent_rate)
{
	struct sprd_div *cd = hw_to_sprd_div(hw);

	return sprd_div_helper_round_rate(&cd->common, &cd->div,
					  rate, parent_rate);
}

unsigned long sprd_div_helper_recalc_rate(struct sprd_clk_common *common,
					  const struct sprd_div_internal *div,
					  unsigned long parent_rate)
{
	unsigned long val;
	unsigned int reg;

	reg = readl((void *)(common->reg_base + common->reg  - div->offset));
	val = reg >> div->shift;
	val &= (1 << div->width) - 1;

	return divider_recalc_rate(&common->hw, parent_rate, val, NULL, 0,
				   div->width);
}
EXPORT_SYMBOL_GPL(sprd_div_helper_recalc_rate);

static unsigned long sprd_div_recalc_rate(struct clk_hw *hw,
					  unsigned long parent_rate)
{
	struct sprd_div *cd = hw_to_sprd_div(hw);

	return sprd_div_helper_recalc_rate(&cd->common, &cd->div, parent_rate);
}

int sprd_div_helper_set_rate(const struct sprd_clk_common *common,
			     const struct sprd_div_internal *div,
			     unsigned long rate,
			     unsigned long parent_rate)
{
	unsigned long val;
	unsigned int reg;

	val = divider_get_val(rate, parent_rate, NULL,
			      div->width, 0);

	reg = readl((void *)(common->reg_base + common->reg - div->offset));
	reg &= ~GENMASK(div->width + div->shift - 1, div->shift);

	writel(reg | (val << div->shift),
	       (void *)(common->reg_base + common->reg - div->offset));

	return 0;

}
EXPORT_SYMBOL_GPL(sprd_div_helper_set_rate);

static int sprd_div_set_rate(struct clk_hw *hw, unsigned long rate,
			     unsigned long parent_rate)
{
	struct sprd_div *cd = hw_to_sprd_div(hw);

	return sprd_div_helper_set_rate(&cd->common, &cd->div,
					rate, parent_rate);
}

const struct sprd_clk_ops sprd_div_ops = {
	.recalc_rate = sprd_div_recalc_rate,
	.round_rate = sprd_div_round_rate,
	.set_rate = sprd_div_set_rate,
};
EXPORT_SYMBOL_GPL(sprd_div_ops);

