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
#define CTL_MM_CLK_CORE_BASE            SCI_IOMAP(0x62100000)
#endif

/* registers definitions for CTL_MM_CLK_CORE, 0x62100000 */
#define REG_MM_CLK_CORE_CGM_MM_AHB_CFG                      SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0020)
#define REG_MM_CLK_CORE_CGM_MM_MTX_CFG                      SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0024)
#define REG_MM_CLK_CORE_CGM_SENSOR0_CFG                     SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0028)
#define REG_MM_CLK_CORE_CGM_SENSOR1_CFG                     SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x002C)
#define REG_MM_CLK_CORE_CGM_SENSOR2_CFG                     SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0030)
#define REG_MM_CLK_CORE_CGM_CPP_CFG                         SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0034)
#define REG_MM_CLK_CORE_CGM_JPG_CFG                         SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0038)
#define REG_MM_CLK_CORE_CGM_FD_CFG                          SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x003C)
#define REG_MM_CLK_CORE_CGM_DCAM_IF_CFG                     SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0040)
#define REG_MM_CLK_CORE_CGM_DCAM_AXI_CFG                    SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0044)
#define REG_MM_CLK_CORE_CGM_ISP_CFG                         SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0048)
#define REG_MM_CLK_CORE_CGM_MIPI_CSI0_CFG                   SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x004C)
#define REG_MM_CLK_CORE_CGM_MIPI_CSI1_CFG                   SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0050)
#define REG_MM_CLK_CORE_CGM_MIPI_CSI2_CFG                   SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0054)
#define REG_MM_CLK_CORE_CGM_CPHY_CFG_CFG                    SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x0058)
#define REG_MM_CLK_CORE_CGM_CSI_PHY_SCAN_ONLY_CFG           SCI_ADDR(CTL_MM_CLK_CORE_BASE, 0x005C)

/* bits definitions for REG_MM_CLK_CORE_CGM_MM_AHB_CFG, [0x62100020] */
#define BIT_MM_CLK_CORE_CGM_MM_AHB_CFG_CGM_MM_AHB_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_MM_MTX_CFG, [0x62100024] */
#define BIT_MM_CLK_CORE_CGM_MM_MTX_CFG_CGM_MM_MTX_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_SENSOR0_CFG, [0x62100028] */
#define BIT_MM_CLK_CORE_CGM_SENSOR0_CFG_CGM_SENSOR0_DIV(x)                   ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_CLK_CORE_CGM_SENSOR0_CFG_CGM_SENSOR0_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_SENSOR1_CFG, [0x6210002C] */
#define BIT_MM_CLK_CORE_CGM_SENSOR1_CFG_CGM_SENSOR1_DIV(x)                   ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_CLK_CORE_CGM_SENSOR1_CFG_CGM_SENSOR1_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_SENSOR2_CFG, [0x62100030] */
#define BIT_MM_CLK_CORE_CGM_SENSOR2_CFG_CGM_SENSOR2_DIV(x)                   ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_CLK_CORE_CGM_SENSOR2_CFG_CGM_SENSOR2_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_CPP_CFG, [0x62100034] */
#define BIT_MM_CLK_CORE_CGM_CPP_CFG_CGM_CPP_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_JPG_CFG, [0x62100038] */
#define BIT_MM_CLK_CORE_CGM_JPG_CFG_CGM_JPG_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_FD_CFG, [0x6210003C] */
#define BIT_MM_CLK_CORE_CGM_FD_CFG_CGM_FD_SEL(x)                             ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_DCAM_IF_CFG, [0x62100040] */
#define BIT_MM_CLK_CORE_CGM_DCAM_IF_CFG_CGM_DCAM_IF_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_DCAM_AXI_CFG, [0x62100044] */
#define BIT_MM_CLK_CORE_CGM_DCAM_AXI_CFG_CGM_DCAM_AXI_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_ISP_CFG, [0x62100048] */
#define BIT_MM_CLK_CORE_CGM_ISP_CFG_CGM_ISP_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_MIPI_CSI0_CFG, [0x6210004C] */
#define BIT_MM_CLK_CORE_CGM_MIPI_CSI0_CFG_CGM_MIPI_CSI0_PAD_SEL              ( BIT(16) )
#define BIT_MM_CLK_CORE_CGM_MIPI_CSI0_CFG_CGM_MIPI_CSI0_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_MIPI_CSI1_CFG, [0x62100050] */
#define BIT_MM_CLK_CORE_CGM_MIPI_CSI1_CFG_CGM_MIPI_CSI1_PAD_SEL              ( BIT(16) )
#define BIT_MM_CLK_CORE_CGM_MIPI_CSI1_CFG_CGM_MIPI_CSI1_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_MIPI_CSI2_CFG, [0x62100054] */
#define BIT_MM_CLK_CORE_CGM_MIPI_CSI2_CFG_CGM_MIPI_CSI2_PAD_SEL              ( BIT(16) )
#define BIT_MM_CLK_CORE_CGM_MIPI_CSI2_CFG_CGM_MIPI_CSI2_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_CLK_CORE_CGM_CPHY_CFG_CFG, [0x62100058] */
#define BIT_MM_CLK_CORE_CGM_CPHY_CFG_CFG_CGM_CPHY_CFG_SEL                    ( BIT(0) )

/* bits definitions for REG_MM_CLK_CORE_CGM_CSI_PHY_SCAN_ONLY_CFG, [0x6210005C] */
#define BIT_MM_CLK_CORE_CGM_CSI_PHY_SCAN_ONLY_CFG_CGM_CSI_PHY_SCAN_ONLY_SEL  ( BIT(0) )

/* vars definitions for controller CTL_MM_CLK_CORE */


#endif /* __MM_CLK_CORE_H____ */