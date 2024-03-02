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
#include "sprd_dsi.h"

static int dsi_glb_parse_dt(struct dsi_context *ctx)
{
	ctx->base = SPRD_DPU_VSP_DISP_DSI0_PHYS;
	return 0;
}

static int dsi_s_glb_parse_dt(struct dsi_context *ctx)
{
	ctx->base = SPRD_DPU_VSP_DISP_DSI1_PHYS;
	return 0;
}

static void dsi_glb_enable(struct dsi_context *ctx)
{
	sci_glb_set(SPRD_DPU_VSP_APB_REG_PHYS, BIT(1));
}

static void dsi_s_glb_enable(struct dsi_context *ctx)
{
	sci_glb_set(SPRD_DPU_VSP_APB_REG_PHYS, BIT(2));
}

static void dsi_glb_disable(struct dsi_context *ctx)
{
	sci_glb_clr(SPRD_DPU_VSP_APB_REG_PHYS, BIT(1));
}

static void dsi_s_glb_disable(struct dsi_context *ctx)
{
	sci_glb_clr(SPRD_DPU_VSP_APB_REG_PHYS, BIT(2));
}

static void dsi_reset(struct dsi_context *ctx)
{
	sci_glb_set(SPRD_DPU_VSP_APB_REG_PHYS + 0x4, BIT(1));
	udelay(10);
	sci_glb_clr(SPRD_DPU_VSP_APB_REG_PHYS + 0x4, BIT(1));
}

static void dsi_s_reset(struct dsi_context *ctx)
{
	sci_glb_set(SPRD_DPU_VSP_APB_REG_PHYS + 0x4, BIT(2));
	udelay(10);
	sci_glb_clr(SPRD_DPU_VSP_APB_REG_PHYS + 0x4, BIT(2));
}

static void dsi_power_domain(struct dsi_context *ctx, int enable)
{
	sci_glb_clr(REG_PMU_APB_PD_DPU_VSP_CFG_0, BIT(24));
        sci_glb_clr(REG_PMU_APB_PD_DPU_VSP_CFG_0, BIT(25));
	sci_glb_set(SPRD_AON_APB_REG_PHYS, BIT(21));
	udelay(1000);
}

static struct dsi_glb_ops dsi_glb_ops = {
	.parse_dt = dsi_glb_parse_dt,
	.reset = dsi_reset,
	.enable = dsi_glb_enable,
	.disable = dsi_glb_disable,
	.power = dsi_power_domain,
};

static struct dsi_glb_ops dsi_slave_glb_ops = {
	.parse_dt = dsi_s_glb_parse_dt,
	.reset = dsi_s_reset,
	.enable = dsi_s_glb_enable,
	.disable = dsi_s_glb_disable,
	.power = NULL,
};

struct dsi_glb_ops *dsi_glb_ops_attach(void)
{
	return &dsi_glb_ops;
}

struct dsi_glb_ops *dsi_s_glb_ops_attach(void)
{
	return &dsi_slave_glb_ops;
}
