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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0550_cq_goodcode_202005181536/reg/ipa/ipa_clk_rf.xls;ipa_clk_rf
 *     Revision : 234058
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __IPA_CLK_H____
#define __IPA_CLK_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_IPA_CLK_BASE
#define CTL_IPA_CLK_BASE                SCI_IOMAP(0x25010000)
#endif

/* registers definitions for CTL_IPA_CLK, 0x25010000 */
#define REG_IPA_CLK_CGM_IPA_AXI_SEL_CFG                     SCI_ADDR(CTL_IPA_CLK_BASE, 0x0028)
#define REG_IPA_CLK_CGM_IPA_APB_DIV_CFG                     SCI_ADDR(CTL_IPA_CLK_BASE, 0x0030)
#define REG_IPA_CLK_CGM_USB_REF_SEL_CFG                     SCI_ADDR(CTL_IPA_CLK_BASE, 0x004C)
#define REG_IPA_CLK_CGM_USB_UTMI_SEL_CFG                    SCI_ADDR(CTL_IPA_CLK_BASE, 0x0058)
#define REG_IPA_CLK_CGM_AP_IPA_AXI_SEL_CFG                  SCI_ADDR(CTL_IPA_CLK_BASE, 0x0064)
#define REG_IPA_CLK_CGM_AP_IPA_APB_DIV_CFG                  SCI_ADDR(CTL_IPA_CLK_BASE, 0x006C)
#define REG_IPA_CLK_CGM_DPU_SEL_CFG                         SCI_ADDR(CTL_IPA_CLK_BASE, 0x007C)
#define REG_IPA_CLK_CGM_DPI_DIV_CFG                         SCI_ADDR(CTL_IPA_CLK_BASE, 0x0084)
#define REG_IPA_CLK_CGM_DPI_SEL_CFG                         SCI_ADDR(CTL_IPA_CLK_BASE, 0x0088)
#define REG_IPA_CLK_CGM_I2S_SEL_CFG                         SCI_ADDR(CTL_IPA_CLK_BASE, 0x0094)
#define REG_IPA_CLK_CGM_USB_153_6M_DIV_CFG                  SCI_ADDR(CTL_IPA_CLK_BASE, 0x00B4)
#define REG_IPA_CLK_CGM_BUSY_SRC_MONITOR_CFG0               SCI_ADDR(CTL_IPA_CLK_BASE, 0x00BC)

/* bits definitions for REG_IPA_CLK_CGM_IPA_AXI_SEL_CFG, [0x25010028] */
#define BIT_IPA_CLK_CGM_IPA_AXI_SEL_DFS(x)                  ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_IPA_CLK_CGM_IPA_AXI_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_IPA_CLK_CGM_IPA_APB_DIV_CFG, [0x25010030] */
#define BIT_IPA_CLK_CGM_IPA_APB_DIV(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_IPA_CLK_CGM_USB_REF_SEL_CFG, [0x2501004C] */
#define BIT_IPA_CLK_CGM_USB_REF_SEL                         ( BIT(0) )

/* bits definitions for REG_IPA_CLK_CGM_USB_UTMI_SEL_CFG, [0x25010058] */
#define BIT_IPA_CLK_CGM_USB_UTMI_PAD_SEL                    ( BIT(16) )

/* bits definitions for REG_IPA_CLK_CGM_AP_IPA_AXI_SEL_CFG, [0x25010064] */
#define BIT_IPA_CLK_CGM_AP_IPA_AXI_SEL                      ( BIT(0) )

/* bits definitions for REG_IPA_CLK_CGM_AP_IPA_APB_DIV_CFG, [0x2501006C] */
#define BIT_IPA_CLK_CGM_AP_IPA_APB_DIV(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_IPA_CLK_CGM_DPU_SEL_CFG, [0x2501007C] */
#define BIT_IPA_CLK_CGM_DPU_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_IPA_CLK_CGM_DPI_DIV_CFG, [0x25010084] */
#define BIT_IPA_CLK_CGM_DPI_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_IPA_CLK_CGM_DPI_SEL_CFG, [0x25010088] */
#define BIT_IPA_CLK_CGM_DPI_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_IPA_CLK_CGM_I2S_SEL_CFG, [0x25010094] */
#define BIT_IPA_CLK_CGM_I2S_PAD_SEL                         ( BIT(16) )

/* bits definitions for REG_IPA_CLK_CGM_USB_153_6M_DIV_CFG, [0x250100B4] */
#define BIT_IPA_CLK_CGM_USB_153_6M_DIV                      ( BIT(0) )

/* bits definitions for REG_IPA_CLK_CGM_BUSY_SRC_MONITOR_CFG0, [0x250100BC] */
#define BIT_IPA_CLK_CGM_BUSY_SRC_MONITOR0(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* vars definitions for controller CTL_IPA_CLK */


#endif /* __IPA_CLK_H____ */
