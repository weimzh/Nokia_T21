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
#include "sprd_dispc.h"
#include "global_dpu_qos.h"

static uint32_t dpu_core_clk[] = {
	256000000,
	307200000,
	384000000,
	409600000,
	512000000,
	614000000
};

static uint32_t dpi_clk_src[] = {
	256000000,
	307200000,
	312500000,
	384000000,
	416700000
};

enum {
	CLK_DPI_FROM_DPHY_DIV6 = 6,
	CLK_DPI_FROM_DPHY_DIV8 = 8,
};

static uint32_t dpi_src_val;

static void dpu_soc_qos_config(void)
{
	unsigned int i, num;

	num = sizeof(dpu_mtx_qos) / sizeof(QOS_REG_T);

	for (i = 0; i < num; i++)
		sci_glb_write(DPU_SOC_QOS_BASE + dpu_mtx_qos[i].offset,
			dpu_mtx_qos[i].value, dpu_mtx_qos[i].mask);
}

static uint8_t calc_dpu_core_clk(void)
{
	return ARRAY_SIZE(dpu_core_clk) - 1;
}

static uint8_t calc_dpi_clk_src(uint32_t pclk)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(dpi_clk_src); i++) {
		if ((dpi_clk_src[i] % pclk) == 0)
			return i;
	}

	pr_err("calc DPI_CLK_SRC failed, use default\n");
	return 0;
}

static void div_to_clk(u32 clk_div)
{
	switch (clk_div) {
	case CLK_DPI_FROM_DPHY_DIV6:
		sci_glb_clr(SPRD_DPU_VSP_APB_REG_PHYS + 0xb0, BIT(3));
		sci_glb_write(SPRD_DPU_VSP_CLK_DPU_VSP_CLK_PHYS + 0x7c, 4, 0xFFFF);
		break;
	case CLK_DPI_FROM_DPHY_DIV8:
		sci_glb_clr(SPRD_DPU_VSP_APB_REG_PHYS + 0xb0, BIT(3));
		sci_glb_write(SPRD_DPU_VSP_CLK_DPU_VSP_CLK_PHYS + 0x7c, 2, 0xFFFF);
		break;
	default:
		pr_err("invalid dpi div value %u\n", clk_div);
		break;
	}
}

static int dispc_clk_init(struct dispc_context *ctx)
{
	uint8_t core_sel = calc_dpu_core_clk();
	uint8_t dpi_sel = calc_dpi_clk_src(ctx->panel->pixel_clk);
	struct panel_info *info = &panel_device;

	pr_info("DPU_CORE_CLK = %u\n", dpu_core_clk[core_sel]);
	pr_info("DPI_CLK_SRC = %u\n", dpi_clk_src[dpi_sel]);


	if (info->dpi_clk_div) {
		pr_info("DPU_CORE_CLK = %u, DPI_CLK_DIV = %d\n",
			dpu_core_clk[core_sel], info->dpi_clk_div);
	} else {
		dpi_src_val = dpi_clk_src[dpi_sel];
		pr_info("DPU_CORE_CLK = %u, DPI_CLK_SRC = %u\n",
			dpu_core_clk[core_sel], dpi_clk_src[dpi_sel]);
	}

	sci_glb_write(SPRD_DPU_VSP_CLK_DPU_VSP_CLK_PHYS + 0x70,
			core_sel, BIT(0) | BIT(1) | BIT(2));

	 if (info->dpi_clk_div) {
		div_to_clk(info->dpi_clk_div);
	} else {
		sci_glb_write(SPRD_DPU_VSP_CLK_DPU_VSP_CLK_PHYS + 0x7C,
			dpi_sel, BIT(0) | BIT(1) | BIT(2));
	}

	sci_glb_write(0x64920394, 1, BIT(0) | BIT(1) | BIT(2));

	return 0;
}

static int dispc_clk_update(struct dispc_context *ctx, int clk_id, int val)
{
	uint32_t div;
	struct panel_info *info = &panel_device;

	if (!info->dpi_clk_div) {
		div = dpi_src_val / val;
		if (dpi_src_val - div * val > (val / 2))
			div++;
		if ((div == 0) || (div > 0x10)) {
			pr_err("invalid dpi clk dividor (%d)\n", div);
			return -1;
		}

		sci_glb_write(SPRD_DPU_VSP_CLK_DPU_VSP_CLK_PHYS + 0x78, (div - 1), 0xf);

		pr_info("the actual dpi_clk = %d\n", dpi_src_val / div);
	}

	return 0;
}

static int dispc_glb_parse_dt(struct dispc_context *ctx)
{
	ctx->base = SPRD_DPU_VSP_DISP_PHYS;

	return 0;
}

static void dispc_glb_enable(struct dispc_context *ctx)
{
	sci_glb_set(SPRD_DPU_VSP_APB_REG_PHYS, BIT(0));
	//sci_glb_clr(REG_TOP_DVFS_APB_DCDC_MM_SW_DVFS_CTRL, BIT(0));
	dpu_soc_qos_config();
}

static void dispc_glb_disable(struct dispc_context *ctx)
{
	sci_glb_clr(SPRD_DPU_VSP_APB_REG_PHYS, BIT(0));
}

static void dispc_reset(struct dispc_context *ctx)
{
	sci_glb_set(SPRD_DPU_VSP_APB_REG_PHYS + 0x4, BIT(0));
	udelay(10);
	sci_glb_clr(SPRD_DPU_VSP_APB_REG_PHYS + 0x4, BIT(0));
}

static void dispc_power_domain(struct dispc_context *ctx, int enable)
{
	sci_glb_clr(REG_PMU_APB_PD_DPU_VSP_CFG_0, BIT(24));
	sci_glb_clr(REG_PMU_APB_PD_DPU_VSP_CFG_0, BIT(25));
}

static struct dispc_clk_ops dispc_clk_ops = {
	.init = dispc_clk_init,
	.update = dispc_clk_update,
};

static struct dispc_glb_ops dispc_glb_ops = {
	.parse_dt = dispc_glb_parse_dt,
	.reset = dispc_reset,
	.enable = dispc_glb_enable,
	.disable = dispc_glb_disable,
	.power = dispc_power_domain,
};

struct dispc_clk_ops *dispc_clk_ops_attach(void)
{
	return &dispc_clk_ops;
}

struct dispc_glb_ops *dispc_glb_ops_attach(void)
{
	return &dispc_glb_ops;
}
