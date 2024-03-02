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

#ifndef __MM_AHB_RF_H____
#define __MM_AHB_RF_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_MM_AHB_RF_BASE
#define CTL_MM_AHB_RF_BASE                 SCI_IOMAP(0x60D00000)
#endif

/* registers definitions for CTL_MM_AHB, 0x60D00000 */
#define REG_MM_AHB_RF_AHB_EB                                   SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0000)
#define REG_MM_AHB_RF_AHB_RST                                  SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0004)
#define REG_MM_AHB_RF_GEN_CKG_CFG                              SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0008)
#define REG_MM_AHB_RF_MIPI_CSI2_CTRL                           SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x000C)
#define REG_MM_AHB_RF_ISP_QOS_CTRL                             SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0010)
#define REG_MM_AHB_RF_CAM_MTX_LPC_CTRL                         SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0014)
#define REG_MM_AHB_RF_VSP_MTX_LPC_CTRL_M0                      SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0018)
#define REG_MM_AHB_RF_VSP_MTX_LPC_CTRL_M1                      SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x001C)
#define REG_MM_AHB_RF_VSP_MTX_LPC_CTRL_S0                      SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0020)
#define REG_MM_AHB_RF_MM_MTX_LPC_STAT                          SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0024)
#define REG_MM_AHB_RF_MM_LIGHT_SLEEP_CTRL                      SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0028)
#define REG_MM_AHB_RF_CAM_MTX_LPC_CTRL_M0                      SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x002C)
#define REG_MM_AHB_RF_CAM_MTX_LPC_CTRL_M1                      SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0030)
#define REG_MM_AHB_RF_VSP_MTX_LPC_CTRL_GPV                     SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0034)
#define REG_MM_AHB_RF_MM_DUMMY_REG_0                           SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x0038)
#define REG_MM_AHB_RF_MM_DUMMY_REG_1                           SCI_ADDR(CTL_MM_AHB_RF_BASE, 0x003C)

/* bits definitions for REG_MM_AHB_RF_AHB_EB, [0x60D00000] */
#define BIT_MM_AHB_RF_VSP_MTX_QOS_AHB_EB                       ( BIT(6) )
#define BIT_MM_AHB_RF_CKG_EB                                   ( BIT(5) )
#define BIT_MM_AHB_RF_JPG_EB                                   ( BIT(4) )
#define BIT_MM_AHB_RF_CSI_EB                                   ( BIT(3) )
#define BIT_MM_AHB_RF_VSP_EB                                   ( BIT(2) )
#define BIT_MM_AHB_RF_ISP_EB                                   ( BIT(1) )
#define BIT_MM_AHB_RF_DCAM_EB                                  ( BIT(0) )

/* bits definitions for REG_MM_AHB_RF_AHB_RST, [0x60D00004] */
#define BIT_MM_AHB_RF_AXI_VSP_MTX_SOFT_RST                     ( BIT(12) )
#define BIT_MM_AHB_RF_AXI_CAM_MTX_SOFT_RST                     ( BIT(11) )
#define BIT_MM_AHB_RF_AHB_CKG_SOFT_RST                         ( BIT(10) )
#define BIT_MM_AHB_RF_APB_CSI_SOFT_RST                         ( BIT(9) )
#define BIT_MM_AHB_RF_JPG_SOFT_RST                             ( BIT(8) )
#define BIT_MM_AHB_RF_VSP_SOFT_RST                             ( BIT(7) )
#define BIT_MM_AHB_RF_ISP_CFG_SOFT_RST                         ( BIT(6) )
#define BIT_MM_AHB_RF_ISP_LOG_SOFT_RST                         ( BIT(5) )
#define BIT_MM_AHB_RF_DCAM_ROT_SOFT_RST                        ( BIT(4) )
#define BIT_MM_AHB_RF_DCAM_CAM2_SOFT_RST                       ( BIT(3) )
#define BIT_MM_AHB_RF_DCAM_CAM1_SOFT_RST                       ( BIT(2) )
#define BIT_MM_AHB_RF_DCAM_CAM0_SOFT_RST                       ( BIT(1) )
#define BIT_MM_AHB_RF_DCAM_SOFT_RST                            ( BIT(0) )

/* bits definitions for REG_MM_AHB_RF_GEN_CKG_CFG, [0x60D00008] */
#define BIT_MM_AHB_RF_MIPI_CSI_CKG_EN                          ( BIT(4) )
#define BIT_MM_AHB_RF_DCAM_AXI_CKG_EN                          ( BIT(3) )
#define BIT_MM_AHB_RF_ISP_AXI_CKG_EN                           ( BIT(2) )
#define BIT_MM_AHB_RF_SENSOR0_CKG_EN                           ( BIT(1) )
#define BIT_MM_AHB_RF_CPHY_CFG_CKG_EN                          ( BIT(0) )

/* bits definitions for REG_MM_AHB_RF_MIPI_CSI2_CTRL, [0x60D0000C] */
#define BIT_MM_AHB_RF_MIPI_CPHY_SEL                            ( BIT(0) )

/* bits definitions for REG_MM_AHB_RF_ISP_QOS_CTRL, [0x60D00010] */
#define BIT_MM_AHB_RF_ISP_ARQOS(x)                             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_AHB_RF_ISP_AWQOS(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_MM_AHB_RF_CAM_MTX_LPC_CTRL, [0x60D00014] */
#define BIT_MM_AHB_RF_CAM_MTX_LPC_FORCE                        ( BIT(17) )
#define BIT_MM_AHB_RF_CAM_MTX_LPC_EB                           ( BIT(16) )
#define BIT_MM_AHB_RF_CAM_MTX_LPC_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_RF_VSP_MTX_LPC_CTRL_M0, [0x60D00018] */
#define BIT_MM_AHB_RF_VSP_MTX_M0_LPC_FORCE                     ( BIT(17) )
#define BIT_MM_AHB_RF_VSP_MTX_M0_LPC_EB                        ( BIT(16) )
#define BIT_MM_AHB_RF_VSP_MTX_M0_LPC_NUM(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_RF_VSP_MTX_LPC_CTRL_M1, [0x60D0001C] */
#define BIT_MM_AHB_RF_VSP_MTX_M1_LPC_FORCE                     ( BIT(17) )
#define BIT_MM_AHB_RF_VSP_MTX_M1_LPC_EB                        ( BIT(16) )
#define BIT_MM_AHB_RF_VSP_MTX_M1_LPC_NUM(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_RF_VSP_MTX_LPC_CTRL_S0, [0x60D00020] */
#define BIT_MM_AHB_RF_VSP_MTX_S0_LPC_FORCE                     ( BIT(17) )
#define BIT_MM_AHB_RF_VSP_MTX_S0_LPC_EB                        ( BIT(16) )
#define BIT_MM_AHB_RF_VSP_MTX_S0_LPC_NUM(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_RF_MM_MTX_LPC_STAT, [0x60D00024] */
#define BIT_MM_AHB_RF_VSP_MTX_S0_FORCE_ACK                     ( BIT(13) )
#define BIT_MM_AHB_RF_VSP_MTX_GPV_FORCE_ACK                    ( BIT(12) )
#define BIT_MM_AHB_RF_VSP_MTX_M1_FORCE_ACK                     ( BIT(11) )
#define BIT_MM_AHB_RF_VSP_MTX_M0_FORCE_ACK                     ( BIT(10) )
#define BIT_MM_AHB_RF_CAM_MTX_LPC_FORCE_ACK                    ( BIT(9) )
#define BIT_MM_AHB_RF_CAM_MTX_M1_FORCE_ACK                     ( BIT(8) )
#define BIT_MM_AHB_RF_CAM_MTX_M0_FORCE_ACK                     ( BIT(7) )
#define BIT_MM_AHB_RF_VSP_MTX_S0_LPC_STAT                      ( BIT(6) )
#define BIT_MM_AHB_RF_VSP_MTX_GPV_LPC_STAT                     ( BIT(5) )
#define BIT_MM_AHB_RF_VSP_MTX_M1_LPC_STAT                      ( BIT(4) )
#define BIT_MM_AHB_RF_VSP_MTX_M0_LPC_STAT                      ( BIT(3) )
#define BIT_MM_AHB_RF_CAM_MTX_M1_LPC_STAT                      ( BIT(2) )
#define BIT_MM_AHB_RF_CAM_MTX_M0_LPC_STAT                      ( BIT(1) )
#define BIT_MM_AHB_RF_CAM_MTX_LPC_STAT                         ( BIT(0) )

/* bits definitions for REG_MM_AHB_RF_MM_LIGHT_SLEEP_CTRL, [0x60D00028] */
#define BIT_MM_AHB_RF_REG_CAM_MTX_AUTO_CTRL_EN                 ( BIT(13) )
#define BIT_MM_AHB_RF_REG_CAM_MTX_LP_DISABLE                   ( BIT(10) )
#define BIT_MM_AHB_RF_REG_CAM_MTX_FRC_LSLP_M0                  ( BIT(9) )
#define BIT_MM_AHB_RF_REG_CAM_MTX_FRC_LSLP_M1                  ( BIT(8) )
#define BIT_MM_AHB_RF_REG_VSP_MTX_AUTO_CTRL_EN                 ( BIT(5) )
#define BIT_MM_AHB_RF_REG_VSP_MTX_LP_DISABLE                   ( BIT(2) )
#define BIT_MM_AHB_RF_REG_VSP_MTX_FRC_LSLP_M0                  ( BIT(1) )
#define BIT_MM_AHB_RF_REG_VSP_MTX_FRC_LSLP_M1                  ( BIT(0) )

/* bits definitions for REG_MM_AHB_RF_CAM_MTX_LPC_CTRL_M0, [0x60D0002C] */
#define BIT_MM_AHB_RF_CAM_MTX_M0_LPC_FORCE                     ( BIT(17) )
#define BIT_MM_AHB_RF_CAM_MTX_M0_LPC_EB                        ( BIT(16) )
#define BIT_MM_AHB_RF_CAM_MTX_M0_LPC_NUM(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_RF_CAM_MTX_LPC_CTRL_M1, [0x60D00030] */
#define BIT_MM_AHB_RF_CAM_MTX_M1_LPC_FORCE                     ( BIT(17) )
#define BIT_MM_AHB_RF_CAM_MTX_M1_LPC_EB                        ( BIT(16) )
#define BIT_MM_AHB_RF_CAM_MTX_M1_LPC_NUM(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_RF_VSP_MTX_LPC_CTRL_GPV, [0x60D00034] */
#define BIT_MM_AHB_RF_VSP_MTX_GPV_LPC_FORCE                    ( BIT(17) )
#define BIT_MM_AHB_RF_VSP_MTX_GPV_LPC_EB                       ( BIT(16) )
#define BIT_MM_AHB_RF_VSP_MTX_GPV_LPC_NUM(x)                   ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_AHB_RF_MM_DUMMY_REG_0, [0x60D00038] */
#define BIT_MM_AHB_RF_MM_DUMMY_REG_0(x)                        ( (x) )

/* bits definitions for REG_MM_AHB_RF_MM_DUMMY_REG_1, [0x60D0003C] */
#define BIT_MM_AHB_RF_MM_DUMMY_REG_1(x)                        ( (x) )

/* vars definitions for controller CTL_MM_AHB */


#endif /* __MM_AHB_RF_H____ */
