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

#ifndef __MM_CLK_CORE_H____
#define __MM_CLK_CORE_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_MM_CLK_CORE_BASE
#define CTL_MM_CLK_CORE_BASE            SCI_IOMAP(0x60E00000)
#endif

/* registers definitions for CTL_MM_CLK_CORE, 0x60E00000 */
#define REG_MM_CLK_CORE_CGM_MM_AHB_CFG                      SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0020)
#define REG_MM_CLK_CORE_CGM_SENSOR0_CFG                     SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0024)
#define REG_MM_CLK_CORE_CGM_SENSOR1_CFG                     SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0028)
#define REG_MM_CLK_CORE_CGM_DCAM_IF_CFG                     SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x002C)
#define REG_MM_CLK_CORE_CGM_JPG_CFG                         SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0030)
#define REG_MM_CLK_CORE_CGM_MIPI_CSI_CFG                    SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0034)
#define REG_MM_CLK_CORE_CGM_CPHY_CFG_CFG                    SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0038)
#define REG_MM_CLK_CORE_CGM_MIPI_CSI_S_CFG                  SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x003C)
#define REG_MM_CLK_CORE_CGM_CSI_PHY_SCAN_ONLY_CFG           SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0040)

/* bits definitions for REG_MM_CLK_CORE_CGM_MM_AHB_CFG, [0x60E00020] */
#define BIT_MM_CLK_CORE_CGM_MM_AHB_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_SENSOR0_CFG, [0x60E00024] */
#define BIT_MM_CLK_CORE_CGM_SENSOR0_DIV(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_CLK_CORE_CGM_SENSOR0_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_SENSOR1_CFG, [0x60E00028] */
#define BIT_MM_CLK_CORE_CGM_SENSOR1_DIV(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_CLK_CORE_CGM_SENSOR1_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_DCAM_IF_CFG, [0x60E0002C] */
#define BIT_MM_CLK_CORE_CGM_DCAM_IF_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_JPG_CFG, [0x60E00030] */
#define BIT_MM_CLK_CORE_CGM_JPG_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_MIPI_CSI_CFG, [0x60E00034] */
#define BIT_MM_CLK_CORE_CGM_MIPI_CSI_PAD_SEL                ( BIT(16) )
#define BIT_MM_CLK_CORE_CGM_MIPI_CSI_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_CPHY_CFG_CFG, [0x60E00038] */
#define BIT_MM_CLK_CORE_CGM_CPHY_CFG_SEL                    ( BIT(0) )

/* bits definitions for REG_MM_CLK_CORE_CGM_MIPI_CSI_S_CFG, [0x60E0003C] */
#define BIT_MM_CLK_CORE_CGM_MIPI_CSI_S_PAD_SEL              ( BIT(16) )
#define BIT_MM_CLK_CORE_CGM_MIPI_CSI_S_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_CSI_PHY_SCAN_ONLY_CFG, [0x60E00040] */
#define BIT_MM_CLK_CORE_CGM_CSI_PHY_SCAN_ONLY_SEL           ( BIT(0) )

/* vars definitions for controller CTL_MM_CLK_CORE */


#endif /* __MM_CLK_CORE_H____ */
