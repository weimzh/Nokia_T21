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

/*
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0635_cq_goodcode_202010131505/reg/dpu_vsp/dpu_vsp_clk_rf.xls;dpu_vsp_clk_rf
 *     Revision : 248562
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __DPU_VSP_CLK_H____
#define __DPU_VSP_CLK_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_DPU_VSP_CLK_BASE
#define CTL_DPU_VSP_CLK_BASE            SCI_IOMAP(0x30110000)
#endif

/* registers definitions for CTL_DPU_VSP_CLK, 0x30110000 */
#define REG_DPU_VSP_CLK_CGM_DPU_CFG_SEL_CFG                 SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x0028)
#define REG_DPU_VSP_CLK_CGM_VPU_MTX_SEL_CFG                 SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x0034)
#define REG_DPU_VSP_CLK_CGM_VPU_ENC_SEL_CFG                 SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x0040)
#define REG_DPU_VSP_CLK_CGM_VPU_DEC_SEL_CFG                 SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x004C)
#define REG_DPU_VSP_CLK_CGM_GSP0_SEL_CFG                    SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x0058)
#define REG_DPU_VSP_CLK_CGM_GSP1_SEL_CFG                    SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x0064)
#define REG_DPU_VSP_CLK_CGM_DISPC0_SEL_CFG                  SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x0070)
#define REG_DPU_VSP_CLK_CGM_DISPC0_DPI_DIV_CFG              SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x0078)
#define REG_DPU_VSP_CLK_CGM_DISPC0_DPI_SEL_CFG              SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x007C)
#define REG_DPU_VSP_CLK_CGM_BUSY_SRC_MONITOR_CFG0           SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x00B0)
#define REG_DPU_VSP_CLK_CGM_BUSY_SRC_MONITOR_CFG1           SCI_ADDR(CTL_DPU_VSP_CLK_BASE, 0x00B4)

/* bits definitions for REG_DPU_VSP_CLK_CGM_DPU_CFG_SEL_CFG, [0x30110028] */
#define BIT_DPU_VSP_CLK_CGM_DPU_CFG_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DPU_VSP_CLK_CGM_VPU_MTX_SEL_CFG, [0x30110034] */
#define BIT_DPU_VSP_CLK_CGM_VPU_MTX_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DPU_VSP_CLK_CGM_VPU_ENC_SEL_CFG, [0x30110040] */
#define BIT_DPU_VSP_CLK_CGM_VPU_ENC_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DPU_VSP_CLK_CGM_VPU_DEC_SEL_CFG, [0x3011004C] */
#define BIT_DPU_VSP_CLK_CGM_VPU_DEC_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_DPU_VSP_CLK_CGM_GSP0_SEL_CFG, [0x30110058] */
#define BIT_DPU_VSP_CLK_CGM_GSP0_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DPU_VSP_CLK_CGM_GSP1_SEL_CFG, [0x30110064] */
#define BIT_DPU_VSP_CLK_CGM_GSP1_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DPU_VSP_CLK_CGM_DISPC0_SEL_CFG, [0x30110070] */
#define BIT_DPU_VSP_CLK_CGM_DISPC0_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_DPU_VSP_CLK_CGM_DISPC0_DPI_DIV_CFG, [0x30110078] */
#define BIT_DPU_VSP_CLK_CGM_DISPC0_DPI_DIV(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DPU_VSP_CLK_CGM_DISPC0_DPI_SEL_CFG, [0x3011007C] */
#define BIT_DPU_VSP_CLK_CGM_DISPC0_DPI_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_DPU_VSP_CLK_CGM_BUSY_SRC_MONITOR_CFG0, [0x301100B0] */
#define BIT_DPU_VSP_CLK_CGM_BUSY_SRC_MONITOR0(x)            ( (x) )

/* bits definitions for REG_DPU_VSP_CLK_CGM_BUSY_SRC_MONITOR_CFG1, [0x301100B4] */
#define BIT_DPU_VSP_CLK_CGM_BUSY_SRC_MONITOR1(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )

/* vars definitions for controller CTL_DPU_VSP_CLK */


#endif /* __DPU_VSP_CLK_H____ */
