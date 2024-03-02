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

#ifndef __MM_AHB_H____
#define __MM_AHB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_MM_AHB_BASE
#define CTL_MM_AHB_BASE                 SCI_IOMAP(0x60800000)
#endif

/* registers definitions for CTL_MM_AHB, 0x60800000 */
#define REG_MM_AHB_AHB_EB                                   SCI_ADDR(CTL_MM_AHB_BASE, 0x0000)
#define REG_MM_AHB_AHB_RST                                  SCI_ADDR(CTL_MM_AHB_BASE, 0x0004)
#define REG_MM_AHB_GEN_CKG_CFG                              SCI_ADDR(CTL_MM_AHB_BASE, 0x0008)
#define REG_MM_AHB_MIPI_CSI2_CTRL                           SCI_ADDR(CTL_MM_AHB_BASE, 0x000C)
#define REG_MM_AHB_CGM_DCAM_FDIV                            SCI_ADDR(CTL_MM_AHB_BASE, 0x0010)
#define REG_MM_AHB_CGM_BPC_FDIV                             SCI_ADDR(CTL_MM_AHB_BASE, 0x0014)
#define REG_MM_AHB_CGM_ISP_FDIV                             SCI_ADDR(CTL_MM_AHB_BASE, 0x0018)
#define REG_MM_AHB_LP_CTRL_DCAM                             SCI_ADDR(CTL_MM_AHB_BASE, 0x001C)
#define REG_MM_AHB_LP_CTRL_ISP                              SCI_ADDR(CTL_MM_AHB_BASE, 0x0020)
#define REG_MM_AHB_LP_CTRL_MM_0                             SCI_ADDR(CTL_MM_AHB_BASE, 0x0024)
#define REG_MM_AHB_LP_CTRL_MM_1                             SCI_ADDR(CTL_MM_AHB_BASE, 0x0028)
#define REG_MM_AHB_LP_CTRL_ASYNC_BRIDGE                     SCI_ADDR(CTL_MM_AHB_BASE, 0x002C)
#define REG_MM_AHB_MTX_MOD_CTRL                             SCI_ADDR(CTL_MM_AHB_BASE, 0x0030)

/* bits definitions for REG_MM_AHB_AHB_EB, [0x60800000] */
#define BIT_MM_AHB_CSI_T_EB                                 ( BIT(5) )
#define BIT_MM_AHB_CSI_S_EB                                 ( BIT(4) )
#define BIT_MM_AHB_CSI_EB                                   ( BIT(3) )
#define BIT_MM_AHB_ISP_EB                                   ( BIT(2) )
#define BIT_MM_AHB_DCAM_EB                                  ( BIT(1) )
#define BIT_MM_AHB_CKG_EB                                   ( BIT(0) )

/* bits definitions for REG_MM_AHB_AHB_RST, [0x60800004] */
#define BIT_MM_AHB_CSI_T_SOFT_RST                           ( BIT(10) )
#define BIT_MM_AHB_CSI_S_SOFT_RST                           ( BIT(9) )
#define BIT_MM_AHB_CSI_SOFT_RST                             ( BIT(8) )
#define BIT_MM_AHB_ISP_LOG_SOFT_RST                         ( BIT(7) )
#define BIT_MM_AHB_DCAM_ALL_SOFT_RST                        ( BIT(6) )
#define BIT_MM_AHB_DCAM_AXIM_SOFT_RST                       ( BIT(5) )
#define BIT_MM_AHB_DCAM2_SOFT_RST                           ( BIT(4) )
#define BIT_MM_AHB_DCAM1_SOFT_RST                           ( BIT(3) )
#define BIT_MM_AHB_DCAM0_SOFT_RST                           ( BIT(2) )
#define BIT_MM_AHB_AXI_MM_EMC_SOFT_RST                      ( BIT(1) )
#define BIT_MM_AHB_CKG_SOFT_RST                             ( BIT(0) )

/* bits definitions for REG_MM_AHB_GEN_CKG_CFG, [0x60800008] */
#define BIT_MM_AHB_CPHY_CFG_CKG_EN                          ( BIT(8) )
#define BIT_MM_AHB_SENSOR2_CKG_EN                           ( BIT(7) )
#define BIT_MM_AHB_SENSOR1_CKG_EN                           ( BIT(6) )
#define BIT_MM_AHB_SENSOR0_CKG_EN                           ( BIT(5) )
#define BIT_MM_AHB_MIPI_CSI_T_CKG_EN                        ( BIT(4) )
#define BIT_MM_AHB_MIPI_CSI_S_CKG_EN                        ( BIT(3) )
#define BIT_MM_AHB_MIPI_CSI_CKG_EN                          ( BIT(2) )
#define BIT_MM_AHB_ISP_AXI_CKG_EN                           ( BIT(1) )
#define BIT_MM_AHB_DCAM_AXI_CKG_EN                          ( BIT(0) )

/* bits definitions for REG_MM_AHB_MIPI_CSI2_CTRL, [0x6080000C] */
#define BIT_MM_AHB_CSI_2P2L_TESTDOUT_MS_SEL(x)              ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_MM_AHB_MIPI_CPHY_SEL2(x)                        ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_AHB_MIPI_CPHY_SEL1(x)                        ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MM_AHB_MIPI_CPHY_SEL0(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_AHB_CGM_DCAM_FDIV, [0x60800010] */
#define BIT_MM_AHB_CGM_DCAM_FDIV_NUM(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_AHB_CGM_DCAM_FDIV_DENOM(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_MM_AHB_CGM_BPC_FDIV, [0x60800014] */
#define BIT_MM_AHB_CGM_BPC_FDIV_NUM(x)                      ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_AHB_CGM_BPC_FDIV_DENOM(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_MM_AHB_CGM_ISP_FDIV, [0x60800018] */
#define BIT_MM_AHB_CGM_ISP_FDIV_NUM(x)                      ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_AHB_CGM_ISP_FDIV_DENOM(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_MM_AHB_LP_CTRL_DCAM, [0x6080001C] */
#define BIT_MM_AHB_LP_NUM_DCAM(x)                           ( (x) << 16 & (0xFFFF0000) )
#define BIT_MM_AHB_LP_EB_DCAM                               ( BIT(0) )

/* bits definitions for REG_MM_AHB_LP_CTRL_ISP, [0x60800020] */
#define BIT_MM_AHB_LP_NUM_ISP(x)                            ( (x) << 16 & (0xFFFF0000) )
#define BIT_MM_AHB_LP_EB_ISP                                ( BIT(0) )

/* bits definitions for REG_MM_AHB_LP_CTRL_MM_0, [0x60800024] */
#define BIT_MM_AHB_LP_NUM_MM(x)                             ( (x) << 16 & (0xFFFF0000) )
#define BIT_MM_AHB_LP_EB_MM                                 ( BIT(0) )

/* bits definitions for REG_MM_AHB_LP_CTRL_MM_1, [0x60800028] */
#define BIT_MM_AHB_ARQOS_THRESHOLD_MM(x)                    ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_MM_AHB_AWQOS_THRESHOLD_MM(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_AHB_QACTIVE_EB_ISP                           ( BIT(3) )
#define BIT_MM_AHB_QACTIVE_EB_DCAM                          ( BIT(2) )
#define BIT_MM_AHB_CGM_MM_MTX_S0_AUTO_GATE_EN               ( BIT(1) )
#define BIT_MM_AHB_MM_LPC_DISABLE                           ( BIT(0) )

/* bits definitions for REG_MM_AHB_LP_CTRL_ASYNC_BRIDGE, [0x6080002C] */
#define BIT_MM_AHB_LP_NUM_ASYNC_BRIDGE_W(x)                 ( (x) << 16 & (0xFFFF0000) )
#define BIT_MM_AHB_LP_EB_ASYNC_BRIDGE_W                     ( BIT(0) )

/* bits definitions for REG_MM_AHB_MTX_MOD_CTRL, [0x60800030] */
#define BIT_MM_AHB_MOD_CTRL_DCAM_AR(x)                      ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_MM_AHB_MOD_CTRL_DCAM_AW(x)                      ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_MM_AHB_MOD_CTRL_ISP_AR(x)                       ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_MM_AHB_MOD_CTRL_ISP_AW(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* vars definitions for controller CTL_MM_AHB */


#endif /* __MM_AHB_H____ */
