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


#ifndef ANLG_PHY_G5_H
#define ANLG_PHY_G5_H

#define CTL_BASE_ANLG_PHY_G5 0x634F0000


#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_ANA_BB_SINE_CTRL1      ( CTL_BASE_ANLG_PHY_G5 + 0x0004 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_ANA_BB_SINE_CTRL2      ( CTL_BASE_ANLG_PHY_G5 + 0x0008 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_BB_BG_CTRL             ( CTL_BASE_ANLG_PHY_G5 + 0x000C )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_ANALOG_TEST            ( CTL_BASE_ANLG_PHY_G5 + 0x0010 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL0          ( CTL_BASE_ANLG_PHY_G5 + 0x0014 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL2          ( CTL_BASE_ANLG_PHY_G5 + 0x001C )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL4          ( CTL_BASE_ANLG_PHY_G5 + 0x0024 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL5          ( CTL_BASE_ANLG_PHY_G5 + 0x0028 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL0          ( CTL_BASE_ANLG_PHY_G5 + 0x0030 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL2          ( CTL_BASE_ANLG_PHY_G5 + 0x0038 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL4          ( CTL_BASE_ANLG_PHY_G5 + 0x0040 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL5          ( CTL_BASE_ANLG_PHY_G5 + 0x0044 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL0            ( CTL_BASE_ANLG_PHY_G5 + 0x004C )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL1            ( CTL_BASE_ANLG_PHY_G5 + 0x0050 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL2            ( CTL_BASE_ANLG_PHY_G5 + 0x0054 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL3            ( CTL_BASE_ANLG_PHY_G5 + 0x0058 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL4            ( CTL_BASE_ANLG_PHY_G5 + 0x005C )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL5            ( CTL_BASE_ANLG_PHY_G5 + 0x0060 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL6            ( CTL_BASE_ANLG_PHY_G5 + 0x0064 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_PLL_CLKEN              ( CTL_BASE_ANLG_PHY_G5 + 0x0068 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_AAPC_TEST_0            ( CTL_BASE_ANLG_PHY_G5 + 0x0080 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_WRAP_GLUE_CTRL         ( CTL_BASE_ANLG_PHY_G5 + 0x0084 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_ANA_LVDS_SEL           ( CTL_BASE_ANLG_PHY_G5 + 0x0088 )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_TEST_CLK_CTRL          ( CTL_BASE_ANLG_PHY_G5 + 0x008C )
#define REG_ANLG_PHY_G5_ANALOG_BB_TOP_ANA_DUMMY_1            ( CTL_BASE_ANLG_PHY_G5 + 0x0090 )

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_ANA_BB_SINE_CTRL1 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_REC_26MHZ_0_CUR_SEL(x)      (((x) & 0x3) << 2)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_SINE_DRV_1_SEL              BIT(1)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_SINE_DRV_0_SEL              BIT(0)

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_ANA_BB_SINE_CTRL2 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_CLK26M_RESERVED(x)          (((x) & 0x7FF) << 12)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_REC_26MHZ_SR_0_TRIM(x)      (((x) & 0xF) << 8)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_REC_26MHZ_SR_1_TRIM(x)      (((x) & 0xF) << 4)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_REC_26MHZ_SR_2_TRIM(x)      (((x) & 0xF))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_BB_BG_CTRL */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_BB_BG_RBIAS_MODE            BIT(1)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_BB_CON_BG                   BIT(0)

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_ANALOG_TEST */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_BB_RESERVED(x)              (((x) & 0xFFFF) << 16)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_BB_TESTMUX(x)               (((x) & 0xFFFF))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL0 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL0_RESERVED0(x)  (((x) & 0x3))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL2 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_26M_SEL             BIT(22)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL2_RESERVED4(x)  (((x) & 0x3) << 20)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL2_RESERVED3     BIT(19)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL2_RESERVED2(x)  (((x) & 0x3) << 17)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL2_RESERVED1(x)  (((x) & 0x7) << 14)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL2_RESERVED0(x)  (((x) & 0x1FFF) << 1)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_SINEO_V3_RPLL_CLKOUT_EN     BIT(0)

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL4 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL4_RESERVED0     BIT(0)

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_CTRL5 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_BIST_CTRL(x)        (((x) & 0xFF) << 17)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_BIST_EN             BIT(16)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_V3_RPLL_BIST_CNT(x)         (((x) & 0xFFFF))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL0 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL0_RESERVED0(x)  (((x) & 0x3))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL2 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_26M_SEL             BIT(21)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL2_RESERVED4(x)  (((x) & 0x3) << 19)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL2_RESERVED3     BIT(18)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL2_RESERVED2     BIT(17)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL2_RESERVED1(x)  (((x) & 0x7) << 14)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL2_RESERVED0(x)  (((x) & 0x1FFF) << 1)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_SINEO_NR_RPLL_CLKOUT_EN     BIT(0)

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL4 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL4_RESERVED1     BIT(1)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL4_RESERVED0     BIT(0)

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_CTRL5 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_BIST_CTRL(x)        (((x) & 0xFF) << 17)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_BIST_EN             BIT(16)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_NR_RPLL_BIST_CNT(x)         (((x) & 0xFFFF))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL0 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_N(x)                  (((x) & 0x7FF) << 8)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL0_RESERVED0(x)    (((x) & 0x3) << 6)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_ICP(x)                (((x) & 0x7) << 3)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_SDM_EN                BIT(2)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_MOD_EN                BIT(1)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_DIV_S                 BIT(0)

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL1 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_NINT(x)               (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_KINT(x)               (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL2 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_FREQ_DOUBLE_EN        BIT(23)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL2_RESERVED3       BIT(22)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL2_RESERVED2(x)    (((x) & 0x7) << 19)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_REFCK_SEL             BIT(18)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL2_RESERVED1(x)    (((x) & 0x7) << 15)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_POSTDIV               BIT(14)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL2_RESERVED0(x)    (((x) & 0x3FFF))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL3 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_VCO_TEST_EN           BIT(8)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_SSC_CTRL(x)           (((x) & 0xFF))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL4 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_LPF(x)                (((x) & 0x7) << 13)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_LDO_TRIM(x)           (((x) & 0xF) << 9)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL4_RESERVED1(x)    (((x) & 0x7) << 6)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_FBDIV_EN              BIT(5)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL4_RESERVED0       BIT(4)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CP_OFFSET(x)          (((x) & 0x7) << 1)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CP_EN                 BIT(0)

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL5 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_BIST_CTRL(x)          (((x) & 0xFF) << 17)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_BIST_EN               BIT(16)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_BIST_CNT(x)           (((x) & 0xFFFF))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_CTRL6 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_TYPE_SEL              BIT(17)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_TEST_CLKOUT_EN        BIT(16)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DLPLL_RESERVED(x)           (((x) & 0xFFFF))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_PLL_CLKEN */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_RPLL_TEST_CLK_EN            BIT(1)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_RPLL_TEST_SEL               BIT(0)

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_AAPC_TEST_0 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_AAPC_MAX_RANGE(x)           (((x) & 0x3FFF) << 17)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_AAPC_MIN_RANGE(x)           (((x) & 0x3FFF) << 3)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_AAPC_RSTN                   BIT(2)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_AAPC_GEN_SEL(x)             (((x) & 0x3))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_WRAP_GLUE_CTRL */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_AAPC_STEP_SEL(x)            (((x) & 0xF))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_ANA_LVDS_SEL */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_LVDSRFPLL_V3_REF_SEL(x)     (((x) & 0x3) << 2)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_LVDSRFPLL_NR_REF_SEL(x)     (((x) & 0x3))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_TEST_CLK_CTRL */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_DBG_SEL_CLK26M_RESERVED     BIT(4)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_TEST_CLK_EN                 BIT(3)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_TEST_CLK_OD                 BIT(2)
#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_TEST_CLK_DIV(x)             (((x) & 0x3))

/* REG_ANLG_PHY_G5_ANALOG_BB_TOP_ANA_DUMMY_1 */

#define BIT_ANLG_PHY_G5_ANALOG_BB_TOP_ANALOG_DUMMY_REG(x)         (((x) & 0xFFFFFFFF))


#endif /* ANLG_PHY_G5_H */


