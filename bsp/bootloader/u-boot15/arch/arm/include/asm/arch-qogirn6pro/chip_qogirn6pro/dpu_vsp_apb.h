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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0635_cq_goodcode_202010131505/reg/dpu_vsp/SharkL6Pro_DPU_VSP_APB_Control_Register.xls;DPUVSP_APB_REG
 *     Revision : 248562
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __DPU_VSP_APB_H____
#define __DPU_VSP_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_DPU_VSP_APB_BASE
#define CTL_DPU_VSP_APB_BASE            SCI_IOMAP(0x30100000)
#endif

/* registers definitions for CTL_DPU_VSP_APB, 0x30100000 */
#define REG_DPU_VSP_APB_APB_EB                              SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0000)
#define REG_DPU_VSP_APB_APB_RST                             SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0004)
#define REG_DPU_VSP_APB_DPU_VSP_SYS_LP_CTRL                 SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0008)
#define REG_DPU_VSP_APB_DPU_VSP_SYS_AUTO_SLEEP_CFG          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x000C)
#define REG_DPU_VSP_APB_CLOCK_FREQUENCY_DOWN                SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0010)
#define REG_DPU_VSP_APB_DPU_VSP_SYS_CLK_EN_FRC_OFF          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0014)
#define REG_DPU_VSP_APB_DPU_VSP_SYS_AUTO_GATE_EN            SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0018)
#define REG_DPU_VSP_APB_MISC_CKG_EN                         SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x001C)
#define REG_DPU_VSP_APB_DPI_CKG_SYNC_EN                     SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0020)
#define REG_DPU_VSP_APB_VPU_ASYNC_BRG                       SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0024)
#define REG_DPU_VSP_APB_DISP_ASYNC_BRG                      SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0028)
#define REG_DPU_VSP_APB_AXI2APB_M0_LPC                      SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x002C)
#define REG_DPU_VSP_APB_DPU_M0_LPC                          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0030)
#define REG_DPU_VSP_APB_DPU_M1_LPC                          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0034)
#define REG_DPU_VSP_APB_DPU_MAIN_LPC                        SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0038)
#define REG_DPU_VSP_APB_DPU_S0_LPC                          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x003C)
#define REG_DPU_VSP_APB_VPU_M0_LPC                          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0040)
#define REG_DPU_VSP_APB_VPU_M1_LPC                          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0044)
#define REG_DPU_VSP_APB_VPU_M2_LPC                          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0048)
#define REG_DPU_VSP_APB_VPU_M3_LPC                          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x004C)
#define REG_DPU_VSP_APB_VPU_M4_LPC                          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0050)
#define REG_DPU_VSP_APB_VPU_MAIN_LPC                        SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0054)
#define REG_DPU_VSP_APB_VPU_S0_LPC                          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0058)
#define REG_DPU_VSP_APB_DPU_VSP_ARURGENT                    SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x005C)
#define REG_DPU_VSP_APB_DPU_VSP_QOS0                        SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0060)
#define REG_DPU_VSP_APB_ASYNC_BRIDGE_IDLE_OVERFLOW          SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0068)
#define REG_DPU_VSP_APB_DPU_VSP_AWCACHE                     SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x006C)
#define REG_DPU_VSP_APB_DPU_VSP_ARCACHE                     SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0070)
#define REG_DPU_VSP_APB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_VPU     SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0094)
#define REG_DPU_VSP_APB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP    SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x0098)
#define REG_DPU_VSP_APB_ASYNC_BRIDGE_DEBUG_SIGNAL_R_CFG     SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x009C)
#define REG_DPU_VSP_APB_SYS_RST                             SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x00A0)
#define REG_DPU_VSP_APB_DPU_VSP_QOS_CFG                     SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x00A4)
#define REG_DPU_VSP_APB_DSI0_PHY                            SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x00A8)
#define REG_DPU_VSP_APB_DSI1_PHY                            SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x00AC)
#define REG_DPU_VSP_APB_DSI_PHY_CTRL                        SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x00B0)
#define REG_DPU_VSP_APB_CHIP_ID                             SCI_ADDR(CTL_DPU_VSP_APB_BASE, 0x00B4)

/* bits definitions for REG_DPU_VSP_APB_APB_EB, [0x30100000] */
#define BIT_DPU_VSP_APB_BUSMON_EB                           ( BIT(10) )
#define BIT_DPU_VSP_APB_CKG_EB                              ( BIT(9) )
#define BIT_DPU_VSP_APB_DVFS_EB                             ( BIT(8) )
#define BIT_DPU_VSP_APB_GSP1_EB                             ( BIT(7) )
#define BIT_DPU_VSP_APB_GSP0_EB                             ( BIT(6) )
#define BIT_DPU_VSP_APB_VPU_DEC_EB                          ( BIT(5) )
#define BIT_DPU_VSP_APB_VPU_ENC1_EB                         ( BIT(4) )
#define BIT_DPU_VSP_APB_VPU_ENC0_EB                         ( BIT(3) )
#define BIT_DPU_VSP_APB_DSI1_EB                             ( BIT(2) )
#define BIT_DPU_VSP_APB_DSI0_EB                             ( BIT(1) )
#define BIT_DPU_VSP_APB_DPU_EB                              ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_APB_RST, [0x30100004] */
#define BIT_DPU_VSP_APB_GSP1_VAU_SOFT_RST                   ( BIT(20) )
#define BIT_DPU_VSP_APB_GSP0_VAU_SOFT_RST                   ( BIT(19) )
#define BIT_DPU_VSP_APB_DPU_VAU_SOFT_RST                    ( BIT(18) )
#define BIT_DPU_VSP_APB_VPU_DEC_VAU_SOFT_RST                ( BIT(17) )
#define BIT_DPU_VSP_APB_VPU_ENC1_VAU_SOFT_RST               ( BIT(16) )
#define BIT_DPU_VSP_APB_VPU_ENC0_VAU_SOFT_RST               ( BIT(15) )
#define BIT_DPU_VSP_APB_VPU_DEC_VSP_SOFT_RST                ( BIT(14) )
#define BIT_DPU_VSP_APB_VPU_DEC_VPP_SOFT_RST                ( BIT(13) )
#define BIT_DPU_VSP_APB_VPU_ENC1_VSP_SOFT_RST               ( BIT(12) )
#define BIT_DPU_VSP_APB_VPU_ENC1_VPP_SOFT_RST               ( BIT(11) )
#define BIT_DPU_VSP_APB_VPU_ENC0_VSP_SOFT_RST               ( BIT(10) )
#define BIT_DPU_VSP_APB_VPU_ENC0_VPP_SOFT_RST               ( BIT(9) )
#define BIT_DPU_VSP_APB_DVFS_SOFT_RST                       ( BIT(8) )
#define BIT_DPU_VSP_APB_GSP1_SOFT_RST                       ( BIT(7) )
#define BIT_DPU_VSP_APB_GSP0_SOFT_RST                       ( BIT(6) )
#define BIT_DPU_VSP_APB_VPU_DEC_SOFT_RST                    ( BIT(5) )
#define BIT_DPU_VSP_APB_VPU_ENC1_SOFT_RST                   ( BIT(4) )
#define BIT_DPU_VSP_APB_VPU_ENC0_SOFT_RST                   ( BIT(3) )
#define BIT_DPU_VSP_APB_DSI1_SOFT_RST                       ( BIT(2) )
#define BIT_DPU_VSP_APB_DSI0_SOFT_RST                       ( BIT(1) )
#define BIT_DPU_VSP_APB_DPU_SOFT_RST                        ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_DPU_VSP_SYS_LP_CTRL, [0x30100008] */
#define BIT_DPU_VSP_APB_AXI_LP_CTRL_DISABLE                 ( BIT(1) )

/* bits definitions for REG_DPU_VSP_APB_DPU_VSP_SYS_AUTO_SLEEP_CFG, [0x3010000C] */

/* bits definitions for REG_DPU_VSP_APB_CLOCK_FREQUENCY_DOWN, [0x30100010] */
#define BIT_DPU_VSP_APB_DPU_VSP_APB_AUTO_CONTROL_SEL        ( BIT(3) )
#define BIT_DPU_VSP_APB_DPU_VSP_APB_AUTO_MUX_SEL(x)         ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_DPU_VSP_APB_DPU_VSP_APB_AUTO_MUX_EN             ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_DPU_VSP_SYS_CLK_EN_FRC_OFF, [0x30100014] */
#define BIT_DPU_VSP_APB_DPU_CFG_DSI1_FORCE_OFF              ( BIT(23) )
#define BIT_DPU_VSP_APB_DPU_CFG_DSI0_FORCE_OFF              ( BIT(22) )
#define BIT_DPU_VSP_APB_DPU_CFG_DPU_FORCE_OFF               ( BIT(21) )
#define BIT_DPU_VSP_APB_DPU_CFG_VPU_DEC_FORCE_OFF           ( BIT(20) )
#define BIT_DPU_VSP_APB_DPU_CFG_VPU_ENC1_FORCE_OFF          ( BIT(19) )
#define BIT_DPU_VSP_APB_DPU_CFG_VPU_ENC0_FORCE_OFF          ( BIT(18) )
#define BIT_DPU_VSP_APB_DPU_CFG_GSP1_FORCE_OFF              ( BIT(17) )
#define BIT_DPU_VSP_APB_DPU_CFG_GSP0_FORCE_OFF              ( BIT(16) )
#define BIT_DPU_VSP_APB_DPU_CFG_DVFS_FORCE_OFF              ( BIT(15) )
#define BIT_DPU_VSP_APB_DPU_CFG_CKG_FORCE_OFF               ( BIT(14) )
#define BIT_DPU_VSP_APB_DPHY1_REF_FR_FORCE_OFF              ( BIT(13) )
#define BIT_DPU_VSP_APB_DPHY1_CFG_FR_FORCE_OFF              ( BIT(12) )
#define BIT_DPU_VSP_APB_DPHY0_REF_FR_FORCE_OFF              ( BIT(11) )
#define BIT_DPU_VSP_APB_DPHY0_CFG_FR_FORCE_OFF              ( BIT(10) )
#define BIT_DPU_VSP_APB_VPU_MTX_FR_FORCE_OFF                ( BIT(9) )
#define BIT_DPU_VSP_APB_DPU_CFG_FR_FORCE_OFF                ( BIT(8) )
#define BIT_DPU_VSP_APB_GSP1_FR_FORCE_OFF                   ( BIT(7) )
#define BIT_DPU_VSP_APB_GSP0_FR_FORCE_OFF                   ( BIT(6) )
#define BIT_DPU_VSP_APB_VPU_DEC_FR_FORCE_OFF                ( BIT(5) )
#define BIT_DPU_VSP_APB_VPU_ENC_VPU_ENC1_FORCE_OFF          ( BIT(4) )
#define BIT_DPU_VSP_APB_VPU_ENC_VPU_ENC0_FORCE_OFF          ( BIT(3) )
#define BIT_DPU_VSP_APB_VPU_ENC_FR_FORCE_OFF                ( BIT(2) )
#define BIT_DPU_VSP_APB_DISPC0_DPI_FR_FORCE_OFF             ( BIT(1) )
#define BIT_DPU_VSP_APB_DISPC0_FR_FORCE_OFF                 ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_DPU_VSP_SYS_AUTO_GATE_EN, [0x30100018] */
#define BIT_DPU_VSP_APB_DPU_CFG_DSI1_AUTO_GATE_EN           ( BIT(23) )
#define BIT_DPU_VSP_APB_DPU_CFG_DSI0_AUTO_GATE_EN           ( BIT(22) )
#define BIT_DPU_VSP_APB_DPU_CFG_DPU_AUTO_GATE_EN            ( BIT(21) )
#define BIT_DPU_VSP_APB_DPU_CFG_VPU_DEC_AUTO_GATE_EN        ( BIT(20) )
#define BIT_DPU_VSP_APB_DPU_CFG_VPU_ENC1_AUTO_GATE_EN       ( BIT(19) )
#define BIT_DPU_VSP_APB_DPU_CFG_VPU_ENC0_AUTO_GATE_EN       ( BIT(18) )
#define BIT_DPU_VSP_APB_DPU_CFG_GSP1_AUTO_GATE_EN           ( BIT(17) )
#define BIT_DPU_VSP_APB_DPU_CFG_GSP0_AUTO_GATE_EN           ( BIT(16) )
#define BIT_DPU_VSP_APB_DPU_CFG_DVFS_AUTO_GATE_EN           ( BIT(15) )
#define BIT_DPU_VSP_APB_DPU_CFG_CKG_AUTO_GATE_EN            ( BIT(14) )
#define BIT_DPU_VSP_APB_DPHY1_REF_FR_AUTO_GATE_EN           ( BIT(13) )
#define BIT_DPU_VSP_APB_DPHY1_CFG_FR_AUTO_GATE_EN           ( BIT(12) )
#define BIT_DPU_VSP_APB_DPHY0_REF_FR_AUTO_GATE_EN           ( BIT(11) )
#define BIT_DPU_VSP_APB_DPHY0_CFG_FR_AUTO_GATE_EN           ( BIT(10) )
#define BIT_DPU_VSP_APB_VPU_MTX_FR_AUTO_GATE_EN             ( BIT(9) )
#define BIT_DPU_VSP_APB_DPU_CFG_FR_AUTO_GATE_EN             ( BIT(8) )
#define BIT_DPU_VSP_APB_GSP1_FR_AUTO_GATE_EN                ( BIT(7) )
#define BIT_DPU_VSP_APB_GSP0_FR_AUTO_GATE_EN                ( BIT(6) )
#define BIT_DPU_VSP_APB_VPU_DEC_FR_AUTO_GATE_EN             ( BIT(5) )
#define BIT_DPU_VSP_APB_VPU_ENC_VPU_ENC1_AUTO_GATE_EN       ( BIT(4) )
#define BIT_DPU_VSP_APB_VPU_ENC_VPU_ENC0_AUTO_GATE_EN       ( BIT(3) )
#define BIT_DPU_VSP_APB_VPU_ENC_FR_AUTO_GATE_EN             ( BIT(2) )
#define BIT_DPU_VSP_APB_DISPC0_DPI_FR_AUTO_GATE_EN          ( BIT(1) )
#define BIT_DPU_VSP_APB_DISPC0_FR_AUTO_GATE_EN              ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_MISC_CKG_EN, [0x3010001C] */
#define BIT_DPU_VSP_APB_DPHY1_REF_CKG_EN                    ( BIT(3) )
#define BIT_DPU_VSP_APB_DPHY1_CFG_CKG_EN                    ( BIT(2) )
#define BIT_DPU_VSP_APB_DPHY0_REF_CKG_EN                    ( BIT(1) )
#define BIT_DPU_VSP_APB_DPHY0_CFG_CKG_EN                    ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_DPI_CKG_SYNC_EN, [0x30100020] */
#define BIT_DPU_VSP_APB_DPI_CKG_SYNC_EN                     ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_VPU_ASYNC_BRG, [0x30100024] */
#define BIT_DPU_VSP_APB_VPU_ASYNC_BRG_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_VPU_ASYNC_BRG_LP_NUM(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_DPU_VSP_APB_VPU_ASYNC_BRG_LP_EB                 ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_DISP_ASYNC_BRG, [0x30100028] */
#define BIT_DPU_VSP_APB_DISP_ASYNC_BRG_PU_NUM(x)            ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_DISP_CSYSACK_SYNC_SEL               ( BIT(18) )
#define BIT_DPU_VSP_APB_DISP_CACTIVE_SYNC_SEL               ( BIT(17) )
#define BIT_DPU_VSP_APB_DISP_ASYNC_BRG_LP_NUM(x)            ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_DPU_VSP_APB_DISP_ASYNC_BRG_LP_EB                ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_AXI2APB_M0_LPC, [0x3010002C] */
#define BIT_DPU_VSP_APB_AXI2APB_M0_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_AXI2APB_M0_LP_EB                    ( BIT(16) )
#define BIT_DPU_VSP_APB_AXI2APB_M0_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_DPU_M0_LPC, [0x30100030] */
#define BIT_DPU_VSP_APB_DPU_MTX_M0_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_DPU_MTX_M0_LP_EB                    ( BIT(16) )
#define BIT_DPU_VSP_APB_DPU_MTX_M0_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_DPU_M1_LPC, [0x30100034] */
#define BIT_DPU_VSP_APB_DPU_MTX_M1_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_DPU_MTX_M1_LP_EB                    ( BIT(16) )
#define BIT_DPU_VSP_APB_DPU_MTX_M1_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_DPU_MAIN_LPC, [0x30100038] */
#define BIT_DPU_VSP_APB_DPU_MTX_PU_NUM(x)                   ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_CGM_DPU_MTX_AUTO_GATE_EN            ( BIT(17) )
#define BIT_DPU_VSP_APB_DPU_MTX_LP_EB                       ( BIT(16) )
#define BIT_DPU_VSP_APB_DPU_MTX_LP_NUM(x)                   ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_DPU_S0_LPC, [0x3010003C] */
#define BIT_DPU_VSP_APB_DPU_MTX_S0_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_CGM_DPU_MTX_S0_AUTO_GATE_EN         ( BIT(17) )
#define BIT_DPU_VSP_APB_DPU_MTX_S0_LP_EB                    ( BIT(16) )
#define BIT_DPU_VSP_APB_DPU_MTX_S0_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_VPU_M0_LPC, [0x30100040] */
#define BIT_DPU_VSP_APB_VPU_MTX_M0_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_VPU_MTX_M0_LP_EB                    ( BIT(16) )
#define BIT_DPU_VSP_APB_VPU_MTX_M0_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_VPU_M1_LPC, [0x30100044] */
#define BIT_DPU_VSP_APB_VPU_MTX_M1_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_VPU_MTX_M1_LP_EB                    ( BIT(16) )
#define BIT_DPU_VSP_APB_VPU_MTX_M1_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_VPU_M2_LPC, [0x30100048] */
#define BIT_DPU_VSP_APB_VPU_MTX_M2_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_VPU_MTX_M2_LP_EB                    ( BIT(16) )
#define BIT_DPU_VSP_APB_VPU_MTX_M2_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_VPU_M3_LPC, [0x3010004C] */
#define BIT_DPU_VSP_APB_VPU_MTX_M3_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_VPU_MTX_M3_LP_EB                    ( BIT(16) )
#define BIT_DPU_VSP_APB_VPU_MTX_M3_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_VPU_M4_LPC, [0x30100050] */
#define BIT_DPU_VSP_APB_VPU_MTX_M4_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_VPU_MTX_M4_LP_EB                    ( BIT(16) )
#define BIT_DPU_VSP_APB_VPU_MTX_M4_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_VPU_MAIN_LPC, [0x30100054] */
#define BIT_DPU_VSP_APB_VPU_MTX_PU_NUM(x)                   ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_CGM_VPU_MTX_AUTO_GATE_EN            ( BIT(17) )
#define BIT_DPU_VSP_APB_VPU_MTX_LP_EB                       ( BIT(16) )
#define BIT_DPU_VSP_APB_VPU_MTX_LP_NUM(x)                   ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_VPU_S0_LPC, [0x30100058] */
#define BIT_DPU_VSP_APB_VPU_MTX_S0_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DPU_VSP_APB_CGM_VPU_MTX_S0_AUTO_GATE_EN         ( BIT(17) )
#define BIT_DPU_VSP_APB_VPU_MTX_S0_LP_EB                    ( BIT(16) )
#define BIT_DPU_VSP_APB_VPU_MTX_S0_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_DPU_VSP_APB_DPU_VSP_ARURGENT, [0x3010005C] */
#define BIT_DPU_VSP_APB_ARURGENT_VPU_DEC(x)                 ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_DPU_VSP_APB_AWURGENT_VPU_DEC(x)                 ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_DPU_VSP_APB_ARURGENT_VPU_ENC1(x)                ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_DPU_VSP_APB_AWURGENT_VPU_ENC1(x)                ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DPU_VSP_APB_ARURGENT_VPU_ENC0(x)                ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_DPU_VSP_APB_AWURGENT_VPU_ENC0(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DPU_VSP_APB_DPU_VSP_QOS0, [0x30100060] */
#define BIT_DPU_VSP_APB_ARQOS_THRESHHOLD_DPU0(x)            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DPU_VSP_APB_AWQOS_THRESHHOLD_DPU0(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DPU_VSP_APB_ASYNC_BRIDGE_IDLE_OVERFLOW, [0x30100068] */
#define BIT_DPU_VSP_APB_AXI_DETECTOR_OVERFLOW_DISP          ( BIT(4) )
#define BIT_DPU_VSP_APB_AXI_DETECTOR_OVERFLOW_VPU           ( BIT(3) )
#define BIT_DPU_VSP_APB_BRIDGE_TRANS_IDLE_DISP              ( BIT(1) )
#define BIT_DPU_VSP_APB_BRIDGE_TRANS_IDLE_VPU               ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_DPU_VSP_AWCACHE, [0x3010006C] */
#define BIT_DPU_VSP_APB_VPU_MTX_AWCACHE_M4(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_DPU_VSP_APB_VPU_MTX_AWCACHE_M3(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_DPU_VSP_APB_VPU_MTX_AWCACHE_M2(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DPU_VSP_APB_VPU_MTX_AWCACHE_M1(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DPU_VSP_APB_VPU_MTX_AWCACHE_M0(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DPU_VSP_APB_DPU_VSP_ARCACHE, [0x30100070] */
#define BIT_DPU_VSP_APB_VPU_MTX_ARCACHE_M4(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_DPU_VSP_APB_VPU_MTX_ARCACHE_M3(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_DPU_VSP_APB_VPU_MTX_ARCACHE_M2(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DPU_VSP_APB_VPU_MTX_ARCACHE_M1(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DPU_VSP_APB_VPU_MTX_ARCACHE_M0(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DPU_VSP_APB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_VPU, [0x30100094] */
#define BIT_DPU_VSP_APB_VPU_BRIDGE_DEBUG_SIGNAL_W(x)        ( (x) )

/* bits definitions for REG_DPU_VSP_APB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP, [0x30100098] */
#define BIT_DPU_VSP_APB_DISP_BRIDGE_DEBUG_SIGNAL_W(x)       ( (x) )

/* bits definitions for REG_DPU_VSP_APB_ASYNC_BRIDGE_DEBUG_SIGNAL_R_CFG, [0x3010009C] */
#define BIT_DPU_VSP_APB_CFG_BRIDGE_DEBUG_SIGNAL_R(x)        ( (x) )

/* bits definitions for REG_DPU_VSP_APB_SYS_RST, [0x301000A0] */
#define BIT_DPU_VSP_APB_SYS_SOFT_RST_REQ_GSP1               ( BIT(5) )
#define BIT_DPU_VSP_APB_SYS_SOFT_RST_REQ_GSP0               ( BIT(4) )
#define BIT_DPU_VSP_APB_SYS_SOFT_RST_REQ_VPU_DEC            ( BIT(3) )
#define BIT_DPU_VSP_APB_SYS_SOFT_RST_REQ_VPU_ENC1           ( BIT(2) )
#define BIT_DPU_VSP_APB_SYS_SOFT_RST_REQ_VPU_ENC0           ( BIT(1) )
#define BIT_DPU_VSP_APB_SYS_SOFT_RST_REQ_DISP               ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_DPU_VSP_QOS_CFG, [0x301000A4] */
#define BIT_DPU_VSP_APB_DISP1_FRAME_LINE_SEL_FOR_DDR_DFS    ( BIT(11) )
#define BIT_DPU_VSP_APB_DISP1_FRAME_LINE_SEL_FOR_DVFS       ( BIT(10) )
#define BIT_DPU_VSP_APB_DISP0_FRAME_LINE_SEL_FOR_DDR_DFS    ( BIT(9) )
#define BIT_DPU_VSP_APB_DISP0_FRAME_LINE_SEL_FOR_DVFS       ( BIT(8) )

/* bits definitions for REG_DPU_VSP_APB_DSI0_PHY, [0x301000A8] */
#define BIT_DPU_VSP_APB_MIPI_DSI0_RESERVED(x)               ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_DPU_VSP_APB_MIPI_DSI0_TX_RCTL(x)                ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_DPU_VSP_APB_MIPI_DSI0_TRIMBG(x)                 ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)) )
#define BIT_DPU_VSP_APB_MIPI_DSI0_IF_SEL                    ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_DSI1_PHY, [0x301000AC] */
#define BIT_DPU_VSP_APB_MIPI_DSI1_RESERVED(x)               ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_DPU_VSP_APB_MIPI_DSI1_TX_RCTL(x)                ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_DPU_VSP_APB_MIPI_DSI1_TRIMBG(x)                 ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)) )
#define BIT_DPU_VSP_APB_MIPI_DSI1_IF_SEL                    ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_DSI_PHY_CTRL, [0x301000B0] */
#define BIT_DPU_VSP_APB_MIPI_DPHY_S_DIV6CLK_GATE_EN         ( BIT(4) )
#define BIT_DPU_VSP_APB_MIPI_DPHY_M_DIV6CLK_GATE_EN         ( BIT(3) )
#define BIT_DPU_VSP_APB_MIPI_DPHY_LANE_MODE                 ( BIT(2) )
#define BIT_DPU_VSP_APB_MIPI_DPHY_S_ENABLE                  ( BIT(1) )
#define BIT_DPU_VSP_APB_MIPI_DPHY_M_ENABLE                  ( BIT(0) )

/* bits definitions for REG_DPU_VSP_APB_CHIP_ID, [0x301000B4] */
#define BIT_DPU_VSP_APB_CHIP_ID(x)                          ( (x) )

/* vars definitions for controller CTL_DPU_VSP_APB */


#endif /* __DPU_VSP_APB_H____ */
