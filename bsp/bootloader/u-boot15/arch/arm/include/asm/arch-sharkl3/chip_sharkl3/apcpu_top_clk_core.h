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

#ifndef __APCPU_TOP_CLK_CORE_H____
#define __APCPU_TOP_CLK_CORE_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_APCPU_TOP_CLK_CORE_BASE
#define CTL_APCPU_TOP_CLK_CORE_BASE     SCI_IOMAP(0x402D0A00)
#endif

/* registers definitions for CTL_APCPU_TOP_CLK_CORE, 0x402D0A00 */
#define REG_APCPU_TOP_CLK_CORE_CGM_CORE0_CFG                SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0020)
#define REG_APCPU_TOP_CLK_CORE_CGM_CORE1_CFG                SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0024)
#define REG_APCPU_TOP_CLK_CORE_CGM_CORE2_CFG                SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0028)
#define REG_APCPU_TOP_CLK_CORE_CGM_CORE3_CFG                SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x002C)
#define REG_APCPU_TOP_CLK_CORE_CGM_CORE4_CFG                SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0030)
#define REG_APCPU_TOP_CLK_CORE_CGM_CORE5_CFG                SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0034)
#define REG_APCPU_TOP_CLK_CORE_CGM_CORE6_CFG                SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0038)
#define REG_APCPU_TOP_CLK_CORE_CGM_CORE7_CFG                SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x003C)
#define REG_APCPU_TOP_CLK_CORE_CGM_SCU_CFG                  SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0040)
#define REG_APCPU_TOP_CLK_CORE_CGM_ACE_CFG                  SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0044)
#define REG_APCPU_TOP_CLK_CORE_CGM_AXI_PERIPH_CFG           SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0048)
#define REG_APCPU_TOP_CLK_CORE_CGM_AXI_ACP_CFG              SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x004C)
#define REG_APCPU_TOP_CLK_CORE_CGM_ATB_CFG                  SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0050)
#define REG_APCPU_TOP_CLK_CORE_CGM_DEBUG_APB_CFG            SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0054)
#define REG_APCPU_TOP_CLK_CORE_CGM_GIC_CFG                  SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x0058)
#define REG_APCPU_TOP_CLK_CORE_CGM_PERIPH_CFG               SCI_ADDR(CTL_APCPU_TOP_CLK_CORE_BASE, 0x005C)

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_CORE0_CFG, [0x402D0A20] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE0_CFG_CGM_CORE0_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE0_CFG_CGM_CORE0_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_CORE1_CFG, [0x402D0A24] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE1_CFG_CGM_CORE1_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE1_CFG_CGM_CORE1_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_CORE2_CFG, [0x402D0A28] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE2_CFG_CGM_CORE2_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE2_CFG_CGM_CORE2_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_CORE3_CFG, [0x402D0A2C] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE3_CFG_CGM_CORE3_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE3_CFG_CGM_CORE3_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_CORE4_CFG, [0x402D0A30] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE4_CFG_CGM_CORE4_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE4_CFG_CGM_CORE4_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_CORE5_CFG, [0x402D0A34] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE5_CFG_CGM_CORE5_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE5_CFG_CGM_CORE5_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_CORE6_CFG, [0x402D0A38] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE6_CFG_CGM_CORE6_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE6_CFG_CGM_CORE6_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_CORE7_CFG, [0x402D0A3C] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE7_CFG_CGM_CORE7_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_CORE7_CFG_CGM_CORE7_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_SCU_CFG, [0x402D0A40] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_SCU_CFG_CGM_SCU_DIV(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_SCU_CFG_CGM_SCU_SEL(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_ACE_CFG, [0x402D0A44] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_ACE_CFG_CGM_ACE_DIV(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_AXI_PERIPH_CFG, [0x402D0A48] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_AXI_PERIPH_CFG_CGM_AXI_PERIPH_DIV(x)  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_AXI_ACP_CFG, [0x402D0A4C] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_AXI_ACP_CFG_CGM_AXI_ACP_DIV(x)        ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_ATB_CFG, [0x402D0A50] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_ATB_CFG_CGM_ATB_DIV(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_ATB_CFG_CGM_ATB_SEL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_DEBUG_APB_CFG, [0x402D0A54] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_DEBUG_APB_CFG_CGM_DEBUG_APB_DIV(x)    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_GIC_CFG, [0x402D0A58] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_GIC_CFG_CGM_GIC_DIV(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_GIC_CFG_CGM_GIC_SEL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_APCPU_TOP_CLK_CORE_CGM_PERIPH_CFG, [0x402D0A5C] */
#define BIT_APCPU_TOP_CLK_CORE_CGM_PERIPH_CFG_CGM_PERIPH_DIV(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_APCPU_TOP_CLK_CORE_CGM_PERIPH_CFG_CGM_PERIPH_SEL(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* vars definitions for controller CTL_APCPU_TOP_CLK_CORE */


#endif /* __APCPU_TOP_CLK_CORE_H____ */

