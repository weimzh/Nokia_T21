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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/GPU_SYS/SharkL6 GPU APB Control Register.xls;GPU_APB_REG
 *     Revision : 210678
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __GPU_APB_H____
#define __GPU_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_GPU_APB_BASE
#define CTL_GPU_APB_BASE                SCI_IOMAP(0x23000000)
#endif

/* registers definitions for CTL_GPU_APB, 0x23000000 */
#define REG_GPU_APB_APB_RST                                 SCI_ADDR(CTL_GPU_APB_BASE, 0x0000)
#define REG_GPU_APB_CLK_GPU_CORE                            SCI_ADDR(CTL_GPU_APB_BASE, 0x0004)
#define REG_GPU_APB_CLK_GPU_MEM                             SCI_ADDR(CTL_GPU_APB_BASE, 0x0008)
#define REG_GPU_APB_CLK_GPU_SYS                             SCI_ADDR(CTL_GPU_APB_BASE, 0x000C)
#define REG_GPU_APB_GPU_NIC400_QOS                          SCI_ADDR(CTL_GPU_APB_BASE, 0x0010)
#define REG_GPU_APB_LPC_AB_W                                SCI_ADDR(CTL_GPU_APB_BASE, 0x0014)
#define REG_GPU_APB_LPC_M0                                  SCI_ADDR(CTL_GPU_APB_BASE, 0x0018)
#define REG_GPU_APB_LPC_S0                                  SCI_ADDR(CTL_GPU_APB_BASE, 0x001C)
#define REG_GPU_APB_LPC_S1                                  SCI_ADDR(CTL_GPU_APB_BASE, 0x0020)
#define REG_GPU_APB_ASYBC_BRIDGE_TOP_W                      SCI_ADDR(CTL_GPU_APB_BASE, 0x0024)
#define REG_GPU_APB_GONDUL_Q_CHANNEL                        SCI_ADDR(CTL_GPU_APB_BASE, 0x0028)
#define REG_GPU_APB_GONDUL_PDC_CONTROL_STACK0               SCI_ADDR(CTL_GPU_APB_BASE, 0x002C)
#define REG_GPU_APB_GONDUL_PDC_CONTROL_STACK1               SCI_ADDR(CTL_GPU_APB_BASE, 0x0030)
#define REG_GPU_APB_GONDUL_TEXFMTENABLE                     SCI_ADDR(CTL_GPU_APB_BASE, 0x0034)
#define REG_GPU_APB_GONDUL_MISCS                            SCI_ADDR(CTL_GPU_APB_BASE, 0x0038)

/* bits definitions for REG_GPU_APB_APB_RST, [0x23000000] */
#define BIT_GPU_APB_SYS_SOFT_RST_REQ_CORE                   ( BIT(1) )
#define BIT_GPU_APB_GPU_CORE_SOFT_RST                       ( BIT(0) )

/* bits definitions for REG_GPU_APB_CLK_GPU_CORE, [0x23000004] */
#define BIT_GPU_APB_CGM_GPU_CORE_FDIV_DENOM(x)              ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_GPU_APB_CGM_GPU_CORE_FDIV_NUM(x)                ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_GPU_APB_CGM_GPU_CORE_DIV(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_GPU_APB_CGM_GPU_CORE_SEL(x)                     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_GPU_APB_CGM_GPU_CORE_EB                         ( BIT(0) )

/* bits definitions for REG_GPU_APB_CLK_GPU_MEM, [0x23000008] */
#define BIT_GPU_APB_CGM_GPU_MEM_FDIV_DENOM(x)               ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_GPU_APB_CGM_GPU_MEM_FDIV_NUM(x)                 ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_GPU_APB_CGM_GPU_MEM_DIV(x)                      ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_GPU_APB_CGM_GPU_MEM_SEL(x)                      ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_GPU_APB_CGM_GPU_MEM_EB                          ( BIT(0) )

/* bits definitions for REG_GPU_APB_CLK_GPU_SYS, [0x2300000C] */
#define BIT_GPU_APB_CGM_GPU_SYS_DIV(x)                      ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_GPU_APB_CGM_GPU_SYS_EB                          ( BIT(0) )

/* bits definitions for REG_GPU_APB_GPU_NIC400_QOS, [0x23000010] */
#define BIT_GPU_APB_AWQOS_THRESHOLD_GPU(x)                  ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_GPU_APB_ARQOS_THRESHOLD_GPU(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_GPU_APB_AWQOS_GPU(x)                            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_GPU_APB_ARQOS_GPU(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_GPU_APB_LPC_AB_W, [0x23000014] */
#define BIT_GPU_APB_PU_NUM_AB_W(x)                          ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_GPU_APB_AXI_LP_CTRL_DISABLE                     ( BIT(20) )
#define BIT_GPU_APB_LP_EB_AB_W                              ( BIT(16) )
#define BIT_GPU_APB_LP_NUM_AB_W(x)                          ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_GPU_APB_LPC_M0, [0x23000018] */
#define BIT_GPU_APB_PU_NUM_M0(x)                            ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_GPU_APB_LP_EB_M0                                ( BIT(16) )
#define BIT_GPU_APB_LP_NUM_M0(x)                            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_GPU_APB_LPC_S0, [0x2300001C] */
#define BIT_GPU_APB_PU_NUM_S0(x)                            ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_GPU_APB_LP_EB_S0                                ( BIT(16) )
#define BIT_GPU_APB_LP_NUM_S0(x)                            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_GPU_APB_LPC_S1, [0x23000020] */
#define BIT_GPU_APB_PU_NUM_S1(x)                            ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_GPU_APB_LP_EB_S1                                ( BIT(16) )
#define BIT_GPU_APB_LP_NUM_S1(x)                            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_GPU_APB_ASYBC_BRIDGE_TOP_W, [0x23000024] */
#define BIT_GPU_APB_RST_SUBSYS                              ( BIT(2) )
#define BIT_GPU_APB_BRIDGE_TRANS_IDLE                       ( BIT(1) )
#define BIT_GPU_APB_AXI_DETECTOR_OVERFLOW                   ( BIT(0) )

/* bits definitions for REG_GPU_APB_GONDUL_Q_CHANNEL, [0x23000028] */
#define BIT_GPU_APB_LP_EB_GONDUL                            ( BIT(16) )
#define BIT_GPU_APB_LP_NUM_GONDUL(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_GPU_APB_GONDUL_PDC_CONTROL_STACK0, [0x2300002C] */
#define BIT_GPU_APB_STACK0_MEM_PD_APB_RF                    ( BIT(11) )
#define BIT_GPU_APB_STACK0_MEM_PD_SEL                       ( BIT(10) )
#define BIT_GPU_APB_PDC_PWRUP_INT_ST0                       ( BIT(9) )
#define BIT_GPU_APB_PDC_ISOLATE_N_INT_ST0                   ( BIT(8) )
#define BIT_GPU_APB_CUR_ST_ST0(x)                           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_GPU_APB_NEW_POINT_SEL_ST0                       ( BIT(2) )
#define BIT_GPU_APB_CORE_FORCE_RST_ISO_OFF_ST0              ( BIT(1) )
#define BIT_GPU_APB_FORCE_POWER_ON_ST0                      ( BIT(0) )

/* bits definitions for REG_GPU_APB_GONDUL_PDC_CONTROL_STACK1, [0x23000030] */
#define BIT_GPU_APB_PDC_PWRUP_INT_ST1                       ( BIT(9) )
#define BIT_GPU_APB_PDC_ISOLATE_N_INT_ST1                   ( BIT(8) )
#define BIT_GPU_APB_CUR_ST_ST1(x)                           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_GPU_APB_NEW_POINT_SEL_ST1                       ( BIT(2) )
#define BIT_GPU_APB_CORE_FORCE_RST_ISO_OFF_ST1              ( BIT(1) )
#define BIT_GPU_APB_FORCE_POWER_ON_ST1                      ( BIT(0) )

/* bits definitions for REG_GPU_APB_GONDUL_TEXFMTENABLE, [0x23000034] */
#define BIT_GPU_APB_TEXFMTENABLE(x)                         ( (x) )

/* bits definitions for REG_GPU_APB_GONDUL_MISCS, [0x23000038] */
#define BIT_GPU_APB_CGM_GPU_26M_EN                          ( BIT(31) )
#define BIT_GPU_APB_NIDEN                                   ( BIT(5) )
#define BIT_GPU_APB_DBGEN                                   ( BIT(4) )
#define BIT_GPU_APB_STRIPING_GONDUL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* vars definitions for controller CTL_GPU_APB */


#endif /* __GPU_APB_H____ */
