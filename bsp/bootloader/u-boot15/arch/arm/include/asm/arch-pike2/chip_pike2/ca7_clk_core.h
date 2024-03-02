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

#ifndef __CA7_CLK_CORE_H____
#define __CA7_CLK_CORE_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_CA7_CLK_CORE_BASE
#define CTL_CA7_CLK_CORE_BASE           SCI_IOMAP(0x20E00000)
#endif

/* registers definitions for CTL_CA7_CLK_CORE, 0x20E00000 */
#define REG_CA7_CLK_CORE_CGM_CA7_MCU_CFG                    SCI_ADDR(CTL_CA7_CLK_CORE_BASE, 0x0020)
#define REG_CA7_CLK_CORE_CGM_CA7_CORE_CFG                   SCI_ADDR(CTL_CA7_CLK_CORE_BASE, 0x0024)
#define REG_CA7_CLK_CORE_CGM_CA7_AXI_CFG                    SCI_ADDR(CTL_CA7_CLK_CORE_BASE, 0x0028)
#define REG_CA7_CLK_CORE_CGM_CA7_DBG_CFG                    SCI_ADDR(CTL_CA7_CLK_CORE_BASE, 0x002C)
#define REG_CA7_CLK_CORE_CGM_AXI_EMC_CFG                    SCI_ADDR(CTL_CA7_CLK_CORE_BASE, 0x0030)

/* bits definitions for REG_CA7_CLK_CORE_CGM_CA7_MCU_CFG, [0x20E00020] */
#define BIT_CA7_CLK_CORE_CGM_CA7_MCU_CFG_CGM_CA7_MCU_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_CA7_CLK_CORE_CGM_CA7_CORE_CFG, [0x20E00024] */
#define BIT_CA7_CLK_CORE_CGM_CA7_CORE_CFG_CGM_CA7_CORE_SEL                    ( BIT(0) )

/* bits definitions for REG_CA7_CLK_CORE_CGM_CA7_AXI_CFG, [0x20E00028] */
#define BIT_CA7_CLK_CORE_CGM_CA7_AXI_CFG_CGM_CA7_AXI_SEL                      ( BIT(0) )

/* bits definitions for REG_CA7_CLK_CORE_CGM_CA7_DBG_CFG, [0x20E0002C] */
#define BIT_CA7_CLK_CORE_CGM_CA7_DBG_CFG_CGM_CA7_DBG_SEL                      ( BIT(0) )

/* bits definitions for REG_CA7_CLK_CORE_CGM_AXI_EMC_CFG, [0x20E00030] */

/* vars definitions for controller CTL_CA7_CLK_CORE */


#endif /* __CA7_CLK_CORE_H____ */
