/*
 * Copyright (C) 2018 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <asm/arch/sprd_reg.h>
#include <sprd_glb.h>
#include "sprd_dphy.h"

static int dphy_glb_parse_dt(struct dphy_context *ctx)
{
	ctx->ctrlbase = SPRD_DPU_VSP_DISP_DSI0_PHYS;

	return 0;
}

static int dphy_s_glb_parse_dt(struct dphy_context *ctx)
{
	ctx->ctrlbase = SPRD_DPU_VSP_DISP_DSI1_PHYS;

	return 0;
}

static void dphy_glb_enable(struct dphy_context *ctx)
{
	sci_glb_set(SPRD_DPU_VSP_APB_REG_PHYS + 0x1c,
		BIT(0) | BIT(1));
}

static void dphy_s_glb_enable(struct dphy_context *ctx)
{
	/* dual-dphy use the same pll*/
	sci_glb_set(SPRD_AON_ANLG_PHY_G3_PHYS + 0x64,
		BIT(29) | BIT(30) | BIT(31));
	sci_glb_clr(SPRD_AON_ANLG_PHY_G3_PHYS,
		BIT(1));
	sci_glb_set(SPRD_AON_ANLG_PHY_G3_PHYS,
		BIT(0) | BIT(2));

	sci_glb_set(SPRD_DPU_VSP_APB_REG_PHYS + 0x1c,
		BIT(2) | BIT(3));
}

static void dphy_glb_disable(struct dphy_context *ctx)
{
	sci_glb_clr(SPRD_DPU_VSP_APB_REG_PHYS + 0x1c,
		BIT(0) | BIT(1));
}

static void dphy_s_glb_disable(struct dphy_context *ctx)
{
	sci_glb_clr(SPRD_DPU_VSP_APB_REG_PHYS + 0x1c,
		BIT(2) | BIT(3));
}

static void dphy_power_domain(struct dphy_context *ctx, int enable)
{
/*
	if (enable) {
		sci_glb_clr(REG_PMU_APB_ANALOG_PHY_PD_CFG, BIT_PMU_APB_DSI_PD_REG);
	} else {
		sci_glb_set(REG_PMU_APB_ANALOG_PHY_PD_CFG, BIT_PMU_APB_DSI_PD_REG);
	}
*/
}

static struct dphy_glb_ops dphy_glb_ops = {
	.parse_dt = dphy_glb_parse_dt,
	.enable = dphy_glb_enable,
	.disable = dphy_glb_disable,
	.power = dphy_power_domain,
};

static struct dphy_glb_ops dphy_slave_glb_ops = {
	.parse_dt = dphy_s_glb_parse_dt,
	.enable = dphy_s_glb_enable,
	.disable = dphy_s_glb_disable,
	.power = NULL,
};

struct dphy_glb_ops *dphy_glb_ops_attach(void)
{
	return &dphy_glb_ops;
}

struct dphy_glb_ops *dphy_s_glb_ops_attach(void)
{
	return &dphy_slave_glb_ops;
}
