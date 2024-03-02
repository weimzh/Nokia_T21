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
#define CTL_MM_AHB_BASE                 SCI_IOMAP(0x60D00000)
#endif

/* registers definitions for CTL_MM_AHB, 0x60D00000 */
#define REG_MM_AHB_AHB_EB                                   SCI_ADDR(CTL_MM_AHB_BASE, 0x0000)
#define REG_MM_AHB_AHB_RST                                  SCI_ADDR(CTL_MM_AHB_BASE, 0x0004)
#define REG_MM_AHB_GEN_CKG_CFG                              SCI_ADDR(CTL_MM_AHB_BASE, 0x0008)
#define REG_MM_AHB_MIPI_CSI2_CTRL                           SCI_ADDR(CTL_MM_AHB_BASE, 0x000C)
#define REG_MM_AHB_QOS_THREHOLD_MM                          SCI_ADDR(CTL_MM_AHB_BASE, 0x0010)
#define REG_MM_AHB_MM_LP_DISABLE                            SCI_ADDR(CTL_MM_AHB_BASE, 0x0014)
#define REG_MM_AHB_MM_LPC_CTRL_DCAM                         SCI_ADDR(CTL_MM_AHB_BASE, 0x0018)
#define REG_MM_AHB_MM_LPC_CTRL_ISP                          SCI_ADDR(CTL_MM_AHB_BASE, 0x001C)
#define REG_MM_AHB_MM_LPC_CTRL_JPG                          SCI_ADDR(CTL_MM_AHB_BASE, 0x0020)
#define REG_MM_AHB_MM_LPC_CTRL_CPP                          SCI_ADDR(CTL_MM_AHB_BASE, 0x0024)
#define REG_MM_AHB_MM_LPC_CTRL_MTX_S0                       SCI_ADDR(CTL_MM_AHB_BASE, 0x0028)

/* bits definitions for REG_MM_AHB_AHB_EB, [0x60D00000] */
#define BIT_MM_AHB_CKG_EB                                   ( BIT(6) )
#define BIT_MM_AHB_JPG_EB                                   ( BIT(5) )
#define BIT_MM_AHB_CSI_S_EB                                 ( BIT(4) )
#define BIT_MM_AHB_CSI_EB                                   ( BIT(3) )
#define BIT_MM_AHB_CPP_EB                                   ( BIT(2) )
#define BIT_MM_AHB_ISP_EB                                   ( BIT(1) )
#define BIT_MM_AHB_DCAM_EB                                  ( BIT(0) )

/* bits definitions for REG_MM_AHB_AHB_RST, [0x60D00004] */
#define BIT_MM_AHB_CPP_SOFT_RST_MASK                        ( BIT(15) )
#define BIT_MM_AHB_JPP_SOFT_RST_MASK                        ( BIT(14) )
#define BIT_MM_AHB_DCAM_SOFT_RST_MASK                       ( BIT(13) )
#define BIT_MM_AHB_CSI_S_SOFT_RST                           ( BIT(12) )
#define BIT_MM_AHB_CSI_SOFT_RST                             ( BIT(11) )
#define BIT_MM_AHB_AXI_MM_MTX_SOFT_RST                      ( BIT(10) )
#define BIT_MM_AHB_CKG_SOFT_RST                             ( BIT(9) )
#define BIT_MM_AHB_JPG_SOFT_RST                             ( BIT(8) )
#define BIT_MM_AHB_ISP_FMCU_SOFT_RST                        ( BIT(7) )
#define BIT_MM_AHB_ISP_CFG_SOFT_RST                         ( BIT(6) )
#define BIT_MM_AHB_ISP_LOG_SOFT_RST                         ( BIT(5) )
#define BIT_MM_AHB_CPP_SOFT_RST                             ( BIT(4) )
#define BIT_MM_AHB_DCAM1_SOFT_RST                           ( BIT(3) )
#define BIT_MM_AHB_DCAM0_SOFT_RST                           ( BIT(2) )
#define BIT_MM_AHB_DCAM_AXIM_SOFT_RST                       ( BIT(1) )
#define BIT_MM_AHB_DCAM_ALL_SOFT_RST                        ( BIT(0) )

/* bits definitions for REG_MM_AHB_GEN_CKG_CFG, [0x60D00008] */
#define BIT_MM_AHB_MIPI_CSI_S_CKG_EN                        ( BIT(5) )
#define BIT_MM_AHB_MIPI_CSI_CKG_EN                          ( BIT(4) )
#define BIT_MM_AHB_ISP_AXI_CKG_EN                           ( BIT(3) )
#define BIT_MM_AHB_SENSOR1_CKG_EN                           ( BIT(2) )
#define BIT_MM_AHB_SENSOR0_CKG_EN                           ( BIT(1) )
#define BIT_MM_AHB_CPHY_CFG_CKG_EN                          ( BIT(0) )

/* bits definitions for REG_MM_AHB_MIPI_CSI2_CTRL, [0x60D0000C] */
#define BIT_MM_AHB_CSI_2P2L_TESTDOUT_MS_SEL                 ( BIT(4) )
#define BIT_MM_AHB_MIPI_CPHY_SEL1(x)                        ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_MM_AHB_MIPI_CPHY_SEL0(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_AHB_QOS_THREHOLD_MM, [0x60D00010] */
#define BIT_MM_AHB_AR_QOS_THREHOLD_MM(x)                    ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_AHB_AW_QOS_THREHOLD_MM(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_MM_AHB_MM_LP_DISABLE, [0x60D00014] */
#define BIT_MM_AHB_CGM_CLK_ISP_AUTO_GATE_EN                 ( BIT(2) )
#define BIT_MM_AHB_CGM_MM_MTX_S0_AUTO_GATE_EN               ( BIT(1) )
#define BIT_MM_AHB_MM_LPC_DISABLE                           ( BIT(0) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_DCAM, [0x60D00018] */
#define BIT_MM_AHB_LP_EB_DCAM                               ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_DCAM(x)                           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_ISP, [0x60D0001C] */
#define BIT_MM_AHB_LP_EB_ISP                                ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_ISP(x)                            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_JPG, [0x60D00020] */
#define BIT_MM_AHB_LP_EB_JPG                                ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_JPG(x)                            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_CPP, [0x60D00024] */
#define BIT_MM_AHB_LP_EB_CPP                                ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_CPP(x)                            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_MTX_S0, [0x60D00028] */
#define BIT_MM_AHB_LP_EB_MTX_S0                             ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_MTX_S0(x)                         ( (x) << 0  & (0x0000FFFF) )

/* vars definitions for controller CTL_MM_AHB */


#endif /* __MM_AHB_H____ */
