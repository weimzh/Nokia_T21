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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/ai/SharkL6Pro_AI_APB_Control_Register.xls;AI_AHB_REG
 *     Revision : 231409
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __AI_APB_H____
#define __AI_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AI_APB_BASE
#define CTL_AI_APB_BASE                 SCI_IOMAP(0x27000000)
#endif

/* registers definitions for CTL_AI_APB, 0x27000000 */
#define REG_AI_APB_APB_EB                                   SCI_ADDR(CTL_AI_APB_BASE, 0x0000)
#define REG_AI_APB_APB_RST                                  SCI_ADDR(CTL_AI_APB_BASE, 0x0004)
#define REG_AI_APB_GEN_CLK_CFG                              SCI_ADDR(CTL_AI_APB_BASE, 0x0008)
#define REG_AI_APB_POWERVR_INT_STATUS                       SCI_ADDR(CTL_AI_APB_BASE, 0x000C)
#define REG_AI_APB_LPC_CFG_MTX_M0                           SCI_ADDR(CTL_AI_APB_BASE, 0x0010)
#define REG_AI_APB_LPC_CFG_MTX_S0                           SCI_ADDR(CTL_AI_APB_BASE, 0x0014)
#define REG_AI_APB_LPC_CFG_MTX_S1                           SCI_ADDR(CTL_AI_APB_BASE, 0x0018)
#define REG_AI_APB_LPC_CFG_MTX_S2                           SCI_ADDR(CTL_AI_APB_BASE, 0x001C)
#define REG_AI_APB_LPC_MAIN_MTX_M0                          SCI_ADDR(CTL_AI_APB_BASE, 0x0020)
#define REG_AI_APB_LPC_MAIN_MTX_M1                          SCI_ADDR(CTL_AI_APB_BASE, 0x0024)
#define REG_AI_APB_LPC_MAIN_MTX_S0                          SCI_ADDR(CTL_AI_APB_BASE, 0x0028)
#define REG_AI_APB_LPC_MAIN_MTX_S1                          SCI_ADDR(CTL_AI_APB_BASE, 0x002C)
#define REG_AI_APB_LPC_MAIN_MTX_MAIN                        SCI_ADDR(CTL_AI_APB_BASE, 0x0030)
#define REG_AI_APB_LPC_AB_TO_DDR                            SCI_ADDR(CTL_AI_APB_BASE, 0x0034)
#define REG_AI_APB_ASYNC_BRIDGE_TO_DDR                      SCI_ADDR(CTL_AI_APB_BASE, 0x0038)
#define REG_AI_APB_AI_QOS_CTRL                              SCI_ADDR(CTL_AI_APB_BASE, 0x003C)
#define REG_AI_APB_LPC_CTRL                                 SCI_ADDR(CTL_AI_APB_BASE, 0x0040)
#define REG_AI_APB_USER_GATE_FORCE_OFF                      SCI_ADDR(CTL_AI_APB_BASE, 0x0044)
#define REG_AI_APB_USER_GATE_AUTO_GATE_EN                   SCI_ADDR(CTL_AI_APB_BASE, 0x0048)
#define REG_AI_APB_AXI_BUSMON_CTRL                          SCI_ADDR(CTL_AI_APB_BASE, 0x004C)
#define REG_AI_APB_ASYNC_BRIDGE_DEBUG_BUS_R                 SCI_ADDR(CTL_AI_APB_BASE, 0x0050)
#define REG_AI_APB_ASYNC_BRIDGE_DEBUG_BUS_W                 SCI_ADDR(CTL_AI_APB_BASE, 0x0054)

/* bits definitions for REG_AI_APB_APB_EB, [0x27000000] */
#define BIT_AI_APB_NIC400_BUSMON_EB                         ( BIT(6) )
#define BIT_AI_APB_AON_TO_OCM_PATH_EB                       ( BIT(5) )
#define BIT_AI_APB_AXI_PMON_EB                              ( BIT(4) )
#define BIT_AI_APB_OCM_EB                                   ( BIT(3) )
#define BIT_AI_APB_DVFS_EB                                  ( BIT(2) )
#define BIT_AI_APB_MTX_APBREG_EB                            ( BIT(1) )
#define BIT_AI_APB_POWERVR_EB                               ( BIT(0) )

/* bits definitions for REG_AI_APB_APB_RST, [0x27000004] */
#define BIT_AI_APB_POWERVR_RST_STATUS                       ( BIT(3) )
#define BIT_AI_APB_POWERVR_SOFT_RST                         ( BIT(2) )
#define BIT_AI_APB_OCM_SOFT_RST                             ( BIT(1) )
#define BIT_AI_APB_DVFS_SOFT_RST                            ( BIT(0) )

/* bits definitions for REG_AI_APB_GEN_CLK_CFG, [0x27000008] */
#define BIT_AI_APB_POWERVR_TMP_RESERVE                      ( BIT(0) )

/* bits definitions for REG_AI_APB_POWERVR_INT_STATUS, [0x2700000C] */
#define BIT_AI_APB_FINISH_IRQ(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AI_APB_LPC_CFG_MTX_M0, [0x27000010] */
#define BIT_AI_APB_PU_NUM_LPC_CFG_MTX_M0(x)                 ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AI_APB_LP_EB_CFG_MTX_M0                         ( BIT(16) )
#define BIT_AI_APB_LP_NUM_CFG_MTX_M0(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_APB_LPC_CFG_MTX_S0, [0x27000014] */
#define BIT_AI_APB_PU_NUM_LPC_CFG_MTX_S0(x)                 ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AI_APB_LP_EB_CFG_MTX_S0                         ( BIT(16) )
#define BIT_AI_APB_LP_NUM_CFG_MTX_S0(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_APB_LPC_CFG_MTX_S1, [0x27000018] */
#define BIT_AI_APB_PU_NUM_LPC_CFG_MTX_S1(x)                 ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AI_APB_LP_EB_CFG_MTX_S1                         ( BIT(16) )
#define BIT_AI_APB_LP_NUM_CFG_MTX_S1(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_APB_LPC_CFG_MTX_S2, [0x2700001C] */
#define BIT_AI_APB_PU_NUM_LPC_CFG_MTX_S2(x)                 ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AI_APB_LP_EB_CFG_MTX_S2                         ( BIT(16) )
#define BIT_AI_APB_LP_NUM_CFG_MTX_S2(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_APB_LPC_MAIN_MTX_M0, [0x27000020] */
#define BIT_AI_APB_PU_NUM_LPC_MAIN_MTX_M0(x)                ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AI_APB_LP_EB_MAIN_MTX_M0                        ( BIT(16) )
#define BIT_AI_APB_LP_NUM_MAIN_MTX_M0(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_APB_LPC_MAIN_MTX_M1, [0x27000024] */
#define BIT_AI_APB_PU_NUM_LPC_MAIN_MTX_M1(x)                ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AI_APB_LP_EB_MAIN_MTX_M1                        ( BIT(16) )
#define BIT_AI_APB_LP_NUM_MAIN_MTX_M1(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_APB_LPC_MAIN_MTX_S0, [0x27000028] */
#define BIT_AI_APB_PU_NUM_LPC_MAIN_MTX_S0(x)                ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AI_APB_LP_EB_MAIN_MTX_S0                        ( BIT(16) )
#define BIT_AI_APB_LP_NUM_MAIN_MTX_S0(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_APB_LPC_MAIN_MTX_S1, [0x2700002C] */
#define BIT_AI_APB_PU_NUM_LPC_MAIN_MTX_S1(x)                ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AI_APB_LP_EB_MAIN_MTX_S1                        ( BIT(16) )
#define BIT_AI_APB_LP_NUM_MAIN_MTX_S1(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_APB_LPC_MAIN_MTX_MAIN, [0x27000030] */
#define BIT_AI_APB_PU_NUM_LPC_MAIN_MTX_MAIN(x)              ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AI_APB_LP_EB_MAIN_MTX_MAIN                      ( BIT(16) )
#define BIT_AI_APB_LP_NUM_MAIN_MTX_MAIN(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_APB_LPC_AB_TO_DDR, [0x27000034] */
#define BIT_AI_APB_PU_NUM_AB_TO_DDR(x)                      ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AI_APB_LP_EB_AB_TO_DDR                          ( BIT(16) )
#define BIT_AI_APB_LP_NUM_AB_TO_DDR(x)                      ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_APB_ASYNC_BRIDGE_TO_DDR, [0x27000038] */
#define BIT_AI_APB_RST_SUBSYS_AB_TO_DDR                     ( BIT(2) )
#define BIT_AI_APB_BRIDGE_TRANS_IDLE_AB_TO_DDR              ( BIT(1) )
#define BIT_AI_APB_AXI_DETECTOR_OVERFLOW_AB_TO_DDR          ( BIT(0) )

/* bits definitions for REG_AI_APB_AI_QOS_CTRL, [0x2700003C] */
#define BIT_AI_APB_QOS_POWERVR_SEL_SW_AI_MAIN_MTX           ( BIT(16) )
#define BIT_AI_APB_AWQOS_POWERVR_SW_AI_MAIN_MTX(x)          ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AI_APB_ARQOS_POWERVR_SW_AI_MAIN_MTX(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AI_APB_AWQOS_THRESHOLD_AI_MAIN_MTX(x)           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AI_APB_ARQOS_THRESHOLD_AI_MAIN_MTX(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AI_APB_LPC_CTRL, [0x27000040] */
#define BIT_AI_APB_AXI_LP_CTRL_DISABLE                      ( BIT(0) )

/* bits definitions for REG_AI_APB_USER_GATE_FORCE_OFF, [0x27000044] */
#define BIT_AI_APB_DJTAG_TCK_FR_FORCE_OFF                   ( BIT(7) )
#define BIT_AI_APB_TZPC_PFR_FORCE_OFF                       ( BIT(6) )
#define BIT_AI_APB_DVFS_FR_FORCE_OFF                        ( BIT(5) )
#define BIT_AI_APB_OCM_FR_FORCE_OFF                         ( BIT(4) )
#define BIT_AI_APB_CFG_MTX_FR_FORCE_OFF                     ( BIT(3) )
#define BIT_AI_APB_MAIN_MTX_FR_FORCE_OFF                    ( BIT(2) )
#define BIT_AI_APB_POWERVR_BUSMON_FORCE_OFF                 ( BIT(1) )
#define BIT_AI_APB_POWERVR_NNA_FORCE_OFF                    ( BIT(0) )

/* bits definitions for REG_AI_APB_USER_GATE_AUTO_GATE_EN, [0x27000048] */
#define BIT_AI_APB_DJTAG_TCK_FR_AUTO_GATE_EN                ( BIT(7) )
#define BIT_AI_APB_TZPC_PFR_AUTO_GATE_EN                    ( BIT(6) )
#define BIT_AI_APB_DVFS_FR_AUTO_GATE_EN                     ( BIT(5) )
#define BIT_AI_APB_OCM_FR_AUTO_GATE_EN                      ( BIT(4) )
#define BIT_AI_APB_CFG_MTX_FR_AUTO_GATE_EN                  ( BIT(3) )
#define BIT_AI_APB_MAIN_MTX_FR_AUTO_GATE_EN                 ( BIT(2) )
#define BIT_AI_APB_POWERVR_BUSMON_AUTO_GATE_EN              ( BIT(1) )
#define BIT_AI_APB_POWERVR_NNA_AUTO_GATE_EN                 ( BIT(0) )

/* bits definitions for REG_AI_APB_AXI_BUSMON_CTRL, [0x2700004C] */
#define BIT_AI_APB_BUSMON_PERFORM_ACK                       ( BIT(6) )
#define BIT_AI_APB_BUSMON_PERFORM_REQ                       ( BIT(5) )
#define BIT_AI_APB_BUSMON_F_DN_ACK                          ( BIT(4) )
#define BIT_AI_APB_BUSMON_F_DN_REQ                          ( BIT(3) )
#define BIT_AI_APB_BUSMON_F_UP_ACK                          ( BIT(2) )
#define BIT_AI_APB_BUSMON_F_UP_REQ                          ( BIT(1) )
#define BIT_AI_APB_BUSMON_CNT_START                         ( BIT(0) )

/* bits definitions for REG_AI_APB_ASYNC_BRIDGE_DEBUG_BUS_R, [0x27000050] */
#define BIT_AI_APB_BRIDGE_DEBUG_SIGNAL_R(x)                 ( (x) )

/* bits definitions for REG_AI_APB_ASYNC_BRIDGE_DEBUG_BUS_W, [0x27000054] */
#define BIT_AI_APB_BRIDGE_DEBUG_SIGNAL_W(x)                 ( (x) )

/* vars definitions for controller CTL_AI_APB */


#endif /* __AI_APB_H____ */
