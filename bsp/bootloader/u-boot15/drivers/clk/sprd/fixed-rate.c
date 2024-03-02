/*
 * Copyright (C) 2010-2011 Canonical Ltd <jeremy.kerr@canonical.com>
 * Copyright (C) 2011-2012 Mike Turquette, Linaro Ltd <mturquette@linaro.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Fixed rate clock implementation
 */

#include "common.h"

/*
 * DOC: basic fixed-rate clock that cannot gate
 *
 * Traits of this clock:
 * prepare - clk_(un)prepare only ensures parents are prepared
 * enable - clk_enable only ensures parents are enabled
 * rate - rate is always a fixed value.  No clk_set_rate support
 * parent - fixed parent.  No clk_set_parent support
 */

static unsigned long clk_fixed_rate_recalc_rate(struct clk_hw *hw,
		unsigned long parent_rate)
{
	return to_sprd_clk_fixed_rate(hw)->fixed_rate;
}

static unsigned long clk_fixed_rate_recalc_accuracy(struct clk_hw *hw,
		unsigned long parent_accuracy)
{
	return to_sprd_clk_fixed_rate(hw)->fixed_accuracy;
}

const struct sprd_clk_ops sprd_clk_fixed_rate_ops = {
	.recalc_rate = clk_fixed_rate_recalc_rate,
	.recalc_accuracy = clk_fixed_rate_recalc_accuracy,
};

/**
 * clk_hw_register_fixed_rate_with_accuracy - register fixed-rate clock with
 * the clock framework
 * @dev: device that is registering this clock
 * @name: name of this clock
 * @parent_name: name of clock's parent
 * @flags: framework-specific flags
 * @fixed_rate: non-adjustable clock rate
 * @fixed_accuracy: non-adjustable clock rate
 */
static int clk_hw_register_fixed_rate_with_accuracy(
		struct sprd_fixed_rate_clk_desc **fixed_rate_desc,
		const char *name, const char *parent_name, unsigned long flags,
		unsigned long fixed_rate, unsigned long fixed_accuracy)
{
	struct sprd_clk_fixed_rate *fixed;
	struct sprd_clk_fixed_rate **clk_clk;
	struct clk_init_data *init;
	struct clk_hw_onecell_data  *hw_clk;

	/* allocate fixed-rate clock */
	fixed = kzalloc(sizeof(*fixed), GFP_KERNEL);
	if (!fixed) {
		return -ENOSYS;
	}

	clk_clk = kzalloc(sizeof(struct sprd_clk_fixed_rate *), GFP_KERNEL);
	if (!clk_clk){
		kfree(fixed);
		return -ENOSYS;
        }

	hw_clk = kzalloc(sizeof(*hw_clk), GFP_KERNEL);
	if (!hw_clk) {
		kfree(fixed);
		kfree(clk_clk);
		return -ENOSYS;
	}

	init = kzalloc(sizeof(*init), GFP_KERNEL);
	if (!init) {
		kfree(fixed);
		kfree(clk_clk);
		kfree(hw_clk);
		return -ENOSYS;
	}

	init->name = name;
	init->ops = &sprd_clk_fixed_rate_ops;
	init->flags = flags | CLK_IS_BASIC;
	init->parent_names = (parent_name ? &parent_name: NULL);
	init->num_parents = (parent_name ? 1 : 0);

	/* struct clk_fixed_rate assignments */
	fixed->fixed_rate = fixed_rate;
	fixed->fixed_accuracy = fixed_accuracy;
	fixed->hw.init = init;

	*clk_clk = fixed;
	hw_clk->hws[0] = &fixed->hw;
	hw_clk->num = 1;

	(*fixed_rate_desc)->clk_clks = clk_clk;
	(*fixed_rate_desc)->num_clk_clks = 1;
	(*fixed_rate_desc)->hw_clks = hw_clk;

	return 0;
}

static int sprd_fixed_rate_clk_probe(struct udevice *dev)
{
	struct sprd_fixed_rate_clk_desc *fixed_rate_desc;
	unsigned long  fixed_rate = dev_read_u32_default(dev, "clock-frequency", 0);
	const char *name = dev_read_string(dev, "clock-output-names");

	fixed_rate_desc = kzalloc(sizeof(*fixed_rate_desc), GFP_KERNEL);
	if (!fixed_rate_desc)
		return -ENOSYS;

	clk_hw_register_fixed_rate_with_accuracy(
		&fixed_rate_desc, name, NULL, CLK_IS_BASIC, fixed_rate, 0);

	dev->priv = fixed_rate_desc;

	return 0;
}

static const struct udevice_id sprd_clk_fixed_rate_match[] = {
	{ .compatible = "fixed-clock",
	  .data = 0 },
	{ /* sentinel */ }
};

U_BOOT_DRIVER(clk_fixed_rate) = {
	.name = "fixed_rate_clock",
	.id = UCLASS_CLK,
	.of_match = sprd_clk_fixed_rate_match,
	.probe = sprd_fixed_rate_clk_probe,
	.priv_auto_alloc_size = sizeof(struct sprd_fixed_rate_clk_desc),
	.ops = &clk_uclass_ops,
};

