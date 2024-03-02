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
#define CTL_MM_AHB_BASE                 SCI_IOMAP(0x62200000)
#endif

/* registers definitions for CTL_MM_AHB, 0x62200000 */
#define REG_MM_AHB_AHB_EB                                   SCI_ADDR(CTL_MM_AHB_BASE, 0x0000)
#define REG_MM_AHB_AHB_RST                                  SCI_ADDR(CTL_MM_AHB_BASE, 0x0004)
#define REG_MM_AHB_GEN_CLK_CFG                              SCI_ADDR(CTL_MM_AHB_BASE, 0x0008)
#define REG_MM_AHB_MM_QOS                                   SCI_ADDR(CTL_MM_AHB_BASE, 0x000C)
#define REG_MM_AHB_MM_LP_DISABLE                            SCI_ADDR(CTL_MM_AHB_BASE, 0x0010)
#define REG_MM_AHB_MM_LPC_CTRL_ISP                          SCI_ADDR(CTL_MM_AHB_BASE, 0x0014)
#define REG_MM_AHB_MM_LPC_CTRL_JPG                          SCI_ADDR(CTL_MM_AHB_BASE, 0x0018)
#define REG_MM_AHB_MM_LPC_CTRL_CPP                          SCI_ADDR(CTL_MM_AHB_BASE, 0x001C)
#define REG_MM_AHB_MM_LPC_CTRL_MM_MAIN_MTX_S0               SCI_ADDR(CTL_MM_AHB_BASE, 0x0020)
#define REG_MM_AHB_MM_LPC_CTRL_AXI2AHB_M0                   SCI_ADDR(CTL_MM_AHB_BASE, 0x0024)
#define REG_MM_AHB_MM_LPC_CTRL_DCAM_ASYNC_BDG               SCI_ADDR(CTL_MM_AHB_BASE, 0x0028)
#define REG_MM_AHB_MM_LPC_CTRL_MTX_ASYNC_BDG                SCI_ADDR(CTL_MM_AHB_BASE, 0x002C)
#define REG_MM_AHB_MIPI_CSI_SEL_CTRL                        SCI_ADDR(CTL_MM_AHB_BASE, 0x0030)
#define REG_MM_AHB_MM_0P5_APPEND                            SCI_ADDR(CTL_MM_AHB_BASE, 0x0034)
#define REG_MM_AHB_MM_IP_BUSY                               SCI_ADDR(CTL_MM_AHB_BASE, 0x0038)
#define REG_MM_AHB_MM_AS_BDG_STATE                          SCI_ADDR(CTL_MM_AHB_BASE, 0x003C)
#define REG_MM_AHB_MM_LPC_CTRL_FD                           SCI_ADDR(CTL_MM_AHB_BASE, 0x0040)
#define REG_MM_AHB_MM_LPC_CTRL_SLICE_ISP                    SCI_ADDR(CTL_MM_AHB_BASE, 0x0044)

/* bits definitions for REG_MM_AHB_AHB_EB, [0x62200000] */
#define BIT_MM_AHB_FD_EB                                    ( BIT(10) )
#define BIT_MM_AHB_DVFS_EB                                  ( BIT(9) )
#define BIT_MM_AHB_ISP_AHB_EB                               ( BIT(8) )
#define BIT_MM_AHB_CKG_EB                                   ( BIT(7) )
#define BIT_MM_AHB_CSI0_EB                                  ( BIT(6) )
#define BIT_MM_AHB_CSI1_EB                                  ( BIT(5) )
#define BIT_MM_AHB_CSI2_EB                                  ( BIT(4) )
#define BIT_MM_AHB_ISP_EB                                   ( BIT(3) )
#define BIT_MM_AHB_DCAM_EB                                  ( BIT(2) )
#define BIT_MM_AHB_JPG_EB                                   ( BIT(1) )
#define BIT_MM_AHB_CPP_EB                                   ( BIT(0) )

/* bits definitions for REG_MM_AHB_AHB_RST, [0x62200004] */
#define BIT_MM_AHB_FD_SOFT_RST_MASK                         ( BIT(27) )
#define BIT_MM_AHB_FD_SOFT_RST                              ( BIT(26) )
#define BIT_MM_AHB_DVFS_SOFT_RST                            ( BIT(24) )
#define BIT_MM_AHB_DCAM_ALL_SOFT_RST                        ( BIT(23) )
#define BIT_MM_AHB_FD_VAU_SOFT_RST                          ( BIT(22) )
#define BIT_MM_AHB_CPP_VAU_SOFT_RST                         ( BIT(21) )
#define BIT_MM_AHB_JPG_VAU_SOFT_RST                         ( BIT(20) )
#define BIT_MM_AHB_JPG_SOFT_RST_MASK                        ( BIT(19) )
#define BIT_MM_AHB_CPP_SOFT_RST_MASK                        ( BIT(18) )
#define BIT_MM_AHB_MM_MAIN_SOFT_RST                         ( BIT(17) )
#define BIT_MM_AHB_CPP_SOFT_RST                             ( BIT(16) )
#define BIT_MM_AHB_CPP_PATH0_SOFT_RST                       ( BIT(15) )
#define BIT_MM_AHB_CPP_PATH1_SOFT_RST                       ( BIT(14) )
#define BIT_MM_AHB_CPP_DMA_SOFT_RST                         ( BIT(13) )
#define BIT_MM_AHB_ISP_AHB_SOFT_RST                         ( BIT(12) )
#define BIT_MM_AHB_ISP_VAU_SOFT_RST                         ( BIT(11) )
#define BIT_MM_AHB_ISP_SOFT_RST                             ( BIT(10) )
#define BIT_MM_AHB_MIPI_CSI0_SOFT_RST                       ( BIT(9) )
#define BIT_MM_AHB_MIPI_CSI1_SOFT_RST                       ( BIT(8) )
#define BIT_MM_AHB_MIPI_CSI2_SOFT_RST                       ( BIT(7) )
#define BIT_MM_AHB_DCAM_VAU_SOFT_RST                        ( BIT(6) )
#define BIT_MM_AHB_DCAM0_SOFT_RST                           ( BIT(5) )
#define BIT_MM_AHB_DCAM1_SOFT_RST                           ( BIT(4) )
#define BIT_MM_AHB_DCAM2_SOFT_RST                           ( BIT(3) )
#define BIT_MM_AHB_DCAM_AXI_SOFT_RST                        ( BIT(2) )
#define BIT_MM_AHB_JPG_SOFT_RST                             ( BIT(1) )
#define BIT_MM_AHB_CKG_SOFT_RST                             ( BIT(0) )

/* bits definitions for REG_MM_AHB_GEN_CLK_CFG, [0x62200008] */
#define BIT_MM_AHB_CPHY_CFG_CKG_EN                          ( BIT(8) )
#define BIT_MM_AHB_ISP_AXI_CKG_EN                           ( BIT(7) )
#define BIT_MM_AHB_DCAM_AXI_CKG_EN                          ( BIT(6) )
#define BIT_MM_AHB_MIPI_CSI0_CKG_EN                         ( BIT(5) )
#define BIT_MM_AHB_MIPI_CSI1_CKG_EN                         ( BIT(4) )
#define BIT_MM_AHB_MIPI_CSI2_CKG_EN                         ( BIT(3) )
#define BIT_MM_AHB_SENSOR0_CKG_EN                           ( BIT(2) )
#define BIT_MM_AHB_SENSOR1_CKG_EN                           ( BIT(1) )
#define BIT_MM_AHB_SENSOR2_CKG_EN                           ( BIT(0) )

/* bits definitions for REG_MM_AHB_MM_QOS, [0x6220000C] */
#define BIT_MM_AHB_AR_QOS_THRESHOLD_MM(x)                   ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_AHB_AW_QOS_THRESHOLD_MM(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_MM_AHB_MM_LP_DISABLE, [0x62200010] */
#define BIT_MM_AHB_CGM_ISP_AUTO_GATE_SEL                    ( BIT(3) )
#define BIT_MM_AHB_CGM_DCAM_AXI_AUTO_GATE_SEL               ( BIT(2) )
#define BIT_MM_AHB_CGM_MM_MTX_S0_AUTO_GATE_EN               ( BIT(1) )
#define BIT_MM_AHB_MM_LPC_DISABLE                           ( BIT(0) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_ISP, [0x62200014] */
#define BIT_MM_AHB_PU_NUM_ISP(x)                            ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MM_AHB_LP_EB_ISP                                ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_ISP(x)                            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_JPG, [0x62200018] */
#define BIT_MM_AHB_PU_NUM_JPG(x)                            ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MM_AHB_LP_EB_JPG                                ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_JPG(x)                            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_CPP, [0x6220001C] */
#define BIT_MM_AHB_PU_NUM_CPP(x)                            ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MM_AHB_LP_EB_CPP                                ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_CPP(x)                            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_MM_MAIN_MTX_S0, [0x62200020] */
#define BIT_MM_AHB_PU_NUM_MM_MAIN_MTX_S0(x)                 ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MM_AHB_LP_EB_MM_MAIN_MTX_S0                     ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_MM_MAIN_MTX_S0(x)                 ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_AXI2AHB_M0, [0x62200024] */
#define BIT_MM_AHB_PU_NUM_AXI2AHB_M0(x)                     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MM_AHB_LP_EB_AXI2AHB_M0                         ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_AXI2AHB_M0(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_DCAM_ASYNC_BDG, [0x62200028] */
#define BIT_MM_AHB_PU_NUM_DCAM_ASYNC_BDG(x)                 ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MM_AHB_LP_EB_DCAM_ASYNC_BDG                     ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_DCAM_ASYNC_BDG(x)                 ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_MTX_ASYNC_BDG, [0x6220002C] */
#define BIT_MM_AHB_PU_NUM_MTX_ASYNC_BDG(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MM_AHB_LP_EB_MTX_ASYNC_BDG                      ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_MTX_ASYNC_BDG(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MIPI_CSI_SEL_CTRL, [0x62200030] */
#define BIT_MM_AHB_ISP_INT_1_MASK                           ( BIT(27) )
#define BIT_MM_AHB_ISP_INT_0_MASK                           ( BIT(26) )
#define BIT_MM_AHB_DCAM_INT_2_MASK                          ( BIT(25) )
#define BIT_MM_AHB_DCAM_INT_1_MASK                          ( BIT(24) )
#define BIT_MM_AHB_DCAM_INT_0_MASK                          ( BIT(23) )
#define BIT_MM_AHB_CGM_DCAM_IF_FDIV_NUM(x)                  ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_MM_AHB_CGM_DCAM_IF_FDIV_DENOM(x)                ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_MM_AHB_MIPI_CSI_DPHY_C2_SEL0(x)                 ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_MM_AHB_MIPI_CSI_DPHY_C1_SEL1(x)                 ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_MM_AHB_MIPI_CSI_DPHY_C1_SEL0(x)                 ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_MM_AHB_MIPI_CSI_DPHY_C0_SEL1(x)                 ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_AHB_MIPI_CSI_DPHY_C0_SEL0(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_AHB_MM_0P5_APPEND, [0x62200034] */
#define BIT_MM_AHB_CSYSACK_SYNC_SEL_DCAM_AS                 ( BIT(2) )
#define BIT_MM_AHB_CACTIVE_SYNC_SEL_DCAM_AS                 ( BIT(1) )
#define BIT_MM_AHB_ISP_BUSY_LSLP_EN                         ( BIT(0) )

/* bits definitions for REG_MM_AHB_MM_IP_BUSY, [0x62200038] */
#define BIT_MM_AHB_FD_BUSY                                  ( BIT(4) )
#define BIT_MM_AHB_DCAM_BUSY                                ( BIT(3) )
#define BIT_MM_AHB_ISP_BUSY                                 ( BIT(2) )
#define BIT_MM_AHB_JPG_BUSY                                 ( BIT(1) )
#define BIT_MM_AHB_CPP_BUSY                                 ( BIT(0) )

/* bits definitions for REG_MM_AHB_MM_AS_BDG_STATE, [0x6220003C] */
#define BIT_MM_AHB_AXI_DETECTOR_OVERFLOW_MTX_AS             ( BIT(3) )
#define BIT_MM_AHB_AXI_DETECTOR_OVERFLOW_DCAM_AS            ( BIT(2) )
#define BIT_MM_AHB_BRIDGE_TRANS_IDLE_MTX_AS                 ( BIT(1) )
#define BIT_MM_AHB_BRIDGE_TRANS_IDLE_DCAM_AS                ( BIT(0) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_FD, [0x62200040] */
#define BIT_MM_AHB_PU_NUM_FD(x)                             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MM_AHB_LP_EB_FD                                 ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_FD(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_MM_LPC_CTRL_SLICE_ISP, [0x62200044] */
#define BIT_MM_AHB_PU_NUM_SLICE_ISP(x)                      ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_MM_AHB_LP_EB_SLICE_ISP                          ( BIT(16) )
#define BIT_MM_AHB_LP_NUM_SLICE_ISP(x)                      ( (x) << 0  & (0x0000FFFF) )

/* vars definitions for controller CTL_MM_AHB */


#endif /* __MM_AHB_H____ */
