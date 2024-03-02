/*
 * Copyright (C) 2019 Unigroup Spreadtrum & RDA Technologies Co., Ltd.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 * updated at 2019-02-11 15:07:05
 *
 */


#ifndef MPLL_PRE_DIV_GEN_H
#define MPLL_PRE_DIV_GEN_H

#define CTL_BASE_MPLL_PRE_DIV_GEN 0x00000000


#define REG_MPLL_PRE_DIV_GEN_SOFT_CNT_DONE0_CFG                ( CTL_BASE_MPLL_PRE_DIV_GEN + 0x0020 )
#define REG_MPLL_PRE_DIV_GEN_PLL_WAIT_SEL0_CFG                 ( CTL_BASE_MPLL_PRE_DIV_GEN + 0x0024 )
#define REG_MPLL_PRE_DIV_GEN_PLL_WAIT_SW_CTL0_CFG              ( CTL_BASE_MPLL_PRE_DIV_GEN + 0x0028 )
#define REG_MPLL_PRE_DIV_GEN_GATE_EN_SEL0_CFG                  ( CTL_BASE_MPLL_PRE_DIV_GEN + 0x0034 )
#define REG_MPLL_PRE_DIV_GEN_GATE_EN_SW_CTL0_CFG               ( CTL_BASE_MPLL_PRE_DIV_GEN + 0x0038 )
#define REG_MPLL_PRE_DIV_GEN_MONITOR_WAIT_EN_STATUS0_CFG       ( CTL_BASE_MPLL_PRE_DIV_GEN + 0x003C )
#define REG_MPLL_PRE_DIV_GEN_MONITOR_GATE_AUTO_EN_STATUS0_CFG  ( CTL_BASE_MPLL_PRE_DIV_GEN + 0x0040 )

/* REG_MPLL_PRE_DIV_GEN_SOFT_CNT_DONE0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_SOFT_CNT_DONE0_CFG_MPLL0_SOFT_CNT_DONE                           BIT(1)
#define BIT_MPLL_PRE_DIV_GEN_SOFT_CNT_DONE0_CFG_MPLL1_SOFT_CNT_DONE                           BIT(0)

/* REG_MPLL_PRE_DIV_GEN_PLL_WAIT_SEL0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_PLL_WAIT_SEL0_CFG_MPLL0_WAIT_AUTO_GATE_SEL                       BIT(1)
#define BIT_MPLL_PRE_DIV_GEN_PLL_WAIT_SEL0_CFG_MPLL1_WAIT_AUTO_GATE_SEL                       BIT(0)

/* REG_MPLL_PRE_DIV_GEN_PLL_WAIT_SW_CTL0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_PLL_WAIT_SW_CTL0_CFG_MPLL0_WAIT_FORCE_EN                         BIT(1)
#define BIT_MPLL_PRE_DIV_GEN_PLL_WAIT_SW_CTL0_CFG_MPLL1_WAIT_FORCE_EN                         BIT(0)

/* REG_MPLL_PRE_DIV_GEN_GATE_EN_SEL0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SEL0_CFG_CGM_MPLL0_1820M_APCPU_AUTO_GATE_SEL             BIT(1)
#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SEL0_CFG_CGM_MPLL1_1378M_APCPU_AUTO_GATE_SEL             BIT(0)

/* REG_MPLL_PRE_DIV_GEN_GATE_EN_SW_CTL0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SW_CTL0_CFG_CGM_MPLL0_1820M_APCPU_FORCE_EN               BIT(1)
#define BIT_MPLL_PRE_DIV_GEN_GATE_EN_SW_CTL0_CFG_CGM_MPLL1_1378M_APCPU_FORCE_EN               BIT(0)

/* REG_MPLL_PRE_DIV_GEN_MONITOR_WAIT_EN_STATUS0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_MONITOR_WAIT_EN_STATUS0_CFG_MONITOR_WAIT_EN_STATUS(x)            (((x) & 0x3))

/* REG_MPLL_PRE_DIV_GEN_MONITOR_GATE_AUTO_EN_STATUS0_CFG */

#define BIT_MPLL_PRE_DIV_GEN_MONITOR_GATE_AUTO_EN_STATUS0_CFG_MONITOR_GATE_AUTO_EN_STATUS(x)  (((x) & 0x3))


#endif /* MPLL_PRE_DIV_GEN_H */


