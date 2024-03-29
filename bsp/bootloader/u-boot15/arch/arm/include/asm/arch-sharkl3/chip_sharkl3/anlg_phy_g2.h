/*
 * Copyright (C) 2018 Unigroup Spreadtrum & RDA Technologies Co., Ltd.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 ********************************************************************
 * Auto generated c code from ASIC Documentation, PLEASE DONOT EDIT *
 ********************************************************************
 */

#ifndef __ANLG_PHY_G2_H____
#define __ANLG_PHY_G2_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_ANLG_PHY_G2_BASE
#define CTL_ANLG_PHY_G2_BASE            SCI_IOMAP(0x40353000)
#endif

/* registers definitions for CTL_ANLG_PHY_G2, 0x40353000 */
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPIO_CLK_CTRL        SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0000)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL0          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0004)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL1          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0008)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL2          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x000C)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL3          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0010)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL4          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0014)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL5          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0018)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL6          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x001C)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL0           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0020)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL1           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0024)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL2           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0028)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL3           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x002C)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL4           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0030)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL0           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0038)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL1           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x003C)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL2           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0040)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL3           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0044)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL4           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0048)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL0          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0050)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL1          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0054)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL2          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0058)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL3          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x005C)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL4          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0060)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_ANA_PLL_RSVD         SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0068)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_PLL_TO_CSI_CLK_CRTL  SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x007C)
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_REG_SEL_CFG_0        SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0080)

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPIO_CLK_CTRL, [0x40353000] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPIO_CLK_IN_CTRL     ( BIT(3) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPIO_CLK_OUT_CTRL(x) ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL0, [0x40353004] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_MACRO_TYPE(x)  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_REG_VERSION(x) ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_N(x)           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_ICP(x)         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_SDM_EN         ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_MOD_EN         ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV_S          ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL1, [0x40353008] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_NINT(x)        ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_KINT(x)        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL2, [0x4035300C] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_LOCK_DONE      ( BIT(31) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_FREQ_DOUBLE_EN ( BIT(27) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_RST            ( BIT(25) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_PD             ( BIT(24) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_REF_SEL(x)     ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV7_EN        ( BIT(7) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV5_EN        ( BIT(5) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV3_EN        ( BIT(3) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV2_EN        ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV1_EN        ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CLKOUT_EN      ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL3, [0x40353010] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_RESERVED(x)    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_SSC_CTRL(x)    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL4, [0x40353014] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_BIST_EN        ( BIT(16) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_BIST_CNT(x)    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL5, [0x40353018] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_R2_SEL(x)      ( (x) << 30 & (BIT(30)|BIT(31)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_R3_SEL(x)      ( (x) << 28 & (BIT(28)|BIT(29)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_C1_SEL(x)      ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_C2_SEL(x)      ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_LDO_TRIM(x)    ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_KVCO_SEL(x)    ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CP_OFFSET(x)   ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCO_BANK_SEL(x) ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_MODE(x)   ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCO_TEST_EN    ( BIT(7) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCO_TEST_INT   ( BIT(6) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCO_TEST_INTSEL(x) ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CP_EN          ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_FBDIV_EN       ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCOBUF_EN      ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL6, [0x4035301C] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCTRLH_SEL(x)  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCTRLL_SEL(x)  ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_INI(x)    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCTRL_HIGH     ( BIT(14) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCTRL_LOW      ( BIT(13) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_OUT(x)    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_WAITCNT(x) ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_FREQ_DIFF_EN   ( BIT(5) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_RG_CLOSELOOP_EN ( BIT(4) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_POLARITY  ( BIT(3) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_CPPD      ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_DONE      ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_TRIG      ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL0, [0x40353020] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_MACRO_TYPE(x)   ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_REG_VERSION(x)  ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_N(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_IBIAS(x)        ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_LPF(x)          ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_SDM_EN          ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_MOD_EN          ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_DIV_S           ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL1, [0x40353024] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_NINT(x)         ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_KINT(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL2, [0x40353028] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_LOCK_DONE       ( BIT(31) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_RST             ( BIT(25) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_PD              ( BIT(24) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_REF_SEL(x)      ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_DIV5_EN         ( BIT(5) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_DIV3_EN         ( BIT(3) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_DIV2_EN         ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_DIV1_EN         ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CLKOUT_EN       ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL3, [0x4035302C] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_RESERVED(x)     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_SSC_CTRL(x)     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL4, [0x40353030] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_BIST_EN         ( BIT(16) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_BIST_CNT(x)     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL0, [0x40353038] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_MACRO_TYPE(x)   ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_REG_VERSION(x)  ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_N(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_IBIAS(x)        ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_LPF(x)          ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_SDM_EN          ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_MOD_EN          ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_DIV_S           ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL1, [0x4035303C] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_NINT(x)         ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_KINT(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL2, [0x40353040] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_LOCK_DONE       ( BIT(31) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_RST             ( BIT(25) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_PD              ( BIT(24) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_REF_SEL         ( BIT(20) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_POSTDIV         ( BIT(16) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CLKOUT_EN       ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL3, [0x40353044] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_RESERVED(x)     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_SSC_CTRL(x)     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL4, [0x40353048] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_BIST_EN         ( BIT(16) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_BIST_CNT(x)     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL0, [0x40353050] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_MACRO_TYPE(x)   ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_REG_VERSION(x)  ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_N(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_IBIAS(x)        ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_LPF(x)          ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_SDM_EN          ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_MOD_EN          ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_DIV_S           ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL1, [0x40353054] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_NINT(x)         ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_KINT(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL2, [0x40353058] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_LOCK_DONE       ( BIT(31) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_RST             ( BIT(25) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_PD              ( BIT(24) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_REF_SEL         ( BIT(20) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_POSTDIV         ( BIT(16) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_DIV3_EN         ( BIT(3) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_DIV2_EN         ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_DIV1_EN         ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_CLKOUT_EN       ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL3, [0x4035305C] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_RESERVED(x)     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_SSC_CTRL(x)     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL4, [0x40353060] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_BIST_EN         ( BIT(16) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_BIST_CNT(x)     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_ANA_PLL_RSVD, [0x40353068] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_ANALOG_PLL_RESERVED(x) ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_PLL_TO_CSI_CLK_CRTL, [0x4035307C] */
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_CSI_TXBITCLK_SEL(x)  ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_PLL_CK2CSI_EN        ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_PLL_TOP_REG_SEL_CFG_0, [0x40353080] */
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_PD     ( BIT(25) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_RST    ( BIT(24) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_REF_SEL ( BIT(23) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV7_EN ( BIT(22) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV5_EN ( BIT(21) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV3_EN ( BIT(20) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV2_EN ( BIT(19) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV1_EN ( BIT(18) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_CLKOUT_EN ( BIT(17) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_PD      ( BIT(16) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_RST     ( BIT(15) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_REF_SEL ( BIT(14) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV5_EN ( BIT(13) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV3_EN ( BIT(12) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV2_EN ( BIT(11) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV1_EN ( BIT(10) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_CLKOUT_EN ( BIT(9) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_GPLL_PD      ( BIT(8) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_GPLL_RST     ( BIT(7) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_GPLL_CLKOUT_EN ( BIT(6) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_PD      ( BIT(5) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_RST     ( BIT(4) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_DIV3_EN ( BIT(3) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_DIV2_EN ( BIT(2) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_DIV1_EN ( BIT(1) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_CLKOUT_EN ( BIT(0) )

/* vars definitions for controller CTL_ANLG_PHY_G2 */


#endif /* __ANLG_PHY_G2_H____ */
