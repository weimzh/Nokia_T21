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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0635_cq_goodcode_202010131505/reg/camera/SharkL6Pro_MM_AHB_Control_Register.xlsx;MM_AHB_REG
 *     Revision : 248562
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __CAMERASYS_GLB_H____
#define __CAMERASYS_GLB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_CAMERASYS_GLB_BASE
#define CTL_CAMERASYS_GLB_BASE          SCI_IOMAP(0x30000000)
#endif

/* registers definitions for CTL_CAMERASYS_GLB, 0x30000000 */
#define REG_CAMERASYS_GLB_MM_SYS_EN                         SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0000)
#define REG_CAMERASYS_GLB_ISP_BLK_EN                        SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0004)
#define REG_CAMERASYS_GLB_VDSP_BLK_EN                       SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0008)
#define REG_CAMERASYS_GLB_DCAM_BLK_EN                       SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x000C)
#define REG_CAMERASYS_GLB_MM_QOS                            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0010)
#define REG_CAMERASYS_GLB_MM_LP_DISABLE                     SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0014)
#define REG_CAMERASYS_GLB_VDSP_INT_MASK                     SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0018)
#define REG_CAMERASYS_GLB_MM_0P5_APPEND                     SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x001C)
#define REG_CAMERASYS_GLB_MM_IP_BUSY0                       SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0020)
#define REG_CAMERASYS_GLB_MM_IP_BUSY1                       SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0024)
#define REG_CAMERASYS_GLB_MM_AS_BDG_STATE                   SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0028)
#define REG_CAMERASYS_GLB_MM_SYS_CFG_M0_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x002C)
#define REG_CAMERASYS_GLB_MM_SYS_CFG_M1_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0030)
#define REG_CAMERASYS_GLB_MM_SYS_CFG_S0_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0034)
#define REG_CAMERASYS_GLB_MM_SYS_CFG_S1_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0038)
#define REG_CAMERASYS_GLB_MM_SYS_SYS_M0_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x003C)
#define REG_CAMERASYS_GLB_MM_SYS_SYS_M1_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0040)
#define REG_CAMERASYS_GLB_MM_SYS_SYS_M2_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0044)
#define REG_CAMERASYS_GLB_MM_SYS_SYS_M3_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0048)
#define REG_CAMERASYS_GLB_MM_SYS_SYS_S0_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x004C)
#define REG_CAMERASYS_GLB_MM_SYS_SYS_S1_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0050)
#define REG_CAMERASYS_GLB_MM_SYS_ASB_HB_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0054)
#define REG_CAMERASYS_GLB_MM_SYS_ASB_LL_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0058)
#define REG_CAMERASYS_GLB_MM_ISP_BLK_M0_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x005C)
#define REG_CAMERASYS_GLB_MM_ISP_BLK_M1_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0060)
#define REG_CAMERASYS_GLB_MM_ISP_BLK_M2_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0064)
#define REG_CAMERASYS_GLB_MM_ISP_BLK_M3_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0068)
#define REG_CAMERASYS_GLB_MM_ISP_BLK_M4_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x006C)
#define REG_CAMERASYS_GLB_MM_ISP_BLK_S0_LPC_CTRL            SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0070)
#define REG_CAMERASYS_GLB_MM_DCAM_BLK_M0_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0074)
#define REG_CAMERASYS_GLB_MM_DCAM_BLK_M1_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0078)
#define REG_CAMERASYS_GLB_MM_DCAM_BLK_S0_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x007C)
#define REG_CAMERASYS_GLB_MM_VDSP_MST_M0_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0080)
#define REG_CAMERASYS_GLB_MM_VDSP_MST_M1_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0084)
#define REG_CAMERASYS_GLB_MM_VDSP_MST_M2_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0088)
#define REG_CAMERASYS_GLB_MM_VDSP_MST_M3_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x008C)
#define REG_CAMERASYS_GLB_MM_VDSP_MST_S0_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0090)
#define REG_CAMERASYS_GLB_MM_VDSP_MST_S1_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0094)
#define REG_CAMERASYS_GLB_MM_VDSP_SLV_M0_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x0098)
#define REG_CAMERASYS_GLB_MM_VDSP_SLV_M1_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x009C)
#define REG_CAMERASYS_GLB_MM_VDSP_SLV_S0_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00A0)
#define REG_CAMERASYS_GLB_MM_VDSP_SLV_S1_LPC_CTRL           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00A4)
#define REG_CAMERASYS_GLB_MIPI_PHY_SEL                      SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00A8)
#define REG_CAMERASYS_GLB_USER_GATE_FORCE_OFF0              SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00AC)
#define REG_CAMERASYS_GLB_USER_GATE_FORCE_OFF1              SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00B0)
#define REG_CAMERASYS_GLB_USER_GATE_AUTO_GATE_EN0           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00B4)
#define REG_CAMERASYS_GLB_USER_GATE_AUTO_GATE_EN1           SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00B8)
#define REG_CAMERASYS_GLB_VDSP_CORE_CFG                     SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00BC)
#define REG_CAMERASYS_GLB_VDSP_FATAL_INFO_LOW               SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00C0)
#define REG_CAMERASYS_GLB_VDSP_FATAL_INFO_HIGH              SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00C4)
#define REG_CAMERASYS_GLB_DCAM_BLK_SOFT_RST                 SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00C8)
#define REG_CAMERASYS_GLB_ISP_BLK_SOFT_RST                  SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00CC)
#define REG_CAMERASYS_GLB_SYS_SOFT_RST                      SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00D0)
#define REG_CAMERASYS_GLB_VDSP_BLK_SOFTRST                  SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00D4)
#define REG_CAMERASYS_GLB_SYS_LGT_STOP_MASK                 SCI_ADDR(CTL_CAMERASYS_GLB_BASE, 0x00D8)

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_EN, [0x30000000] */
#define BIT_CAMERASYS_GLB_MM_MTX_DATA_EN                    ( BIT(8) )
#define BIT_CAMERASYS_GLB_SYS_TCK_EN                        ( BIT(7) )
#define BIT_CAMERASYS_GLB_SYS_MST_BUSMON_EN                 ( BIT(6) )
#define BIT_CAMERASYS_GLB_SYS_CFG_MTX_BUSMON_EN             ( BIT(5) )
#define BIT_CAMERASYS_GLB_SYS_MTX_CFG_EN                    ( BIT(4) )
#define BIT_CAMERASYS_GLB_DVFS_EN                           ( BIT(3) )
#define BIT_CAMERASYS_GLB_MAILBOX_EN                        ( BIT(2) )
#define BIT_CAMERASYS_GLB_CKG_EN                            ( BIT(1) )
#define BIT_CAMERASYS_GLB_JPG_EN                            ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_ISP_BLK_EN, [0x30000004] */
#define BIT_CAMERASYS_GLB_ISP_TCK_EN                        ( BIT(10) )
#define BIT_CAMERASYS_GLB_ISP_BLK_MST_BUSMON_EN             ( BIT(9) )
#define BIT_CAMERASYS_GLB_DWP_CLK_GATE_DIS                  ( BIT(8) )
#define BIT_CAMERASYS_GLB_ISP_BLK_EN                        ( BIT(7) )
#define BIT_CAMERASYS_GLB_ISP_BLK_CFG_EN                    ( BIT(6) )
#define BIT_CAMERASYS_GLB_ISP_MTX_EN                        ( BIT(5) )
#define BIT_CAMERASYS_GLB_DEWARP_EN                         ( BIT(4) )
#define BIT_CAMERASYS_GLB_FD_EN                             ( BIT(3) )
#define BIT_CAMERASYS_GLB_DEPTH_EN                          ( BIT(2) )
#define BIT_CAMERASYS_GLB_CPP_EN                            ( BIT(1) )
#define BIT_CAMERASYS_GLB_ISP_EN                            ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_VDSP_BLK_EN, [0x30000008] */
#define BIT_CAMERASYS_GLB_IVAU_EN                           ( BIT(12) )
#define BIT_CAMERASYS_GLB_DVAU_EN                           ( BIT(11) )
#define BIT_CAMERASYS_GLB_IDVAU_EN                          ( BIT(10) )
#define BIT_CAMERASYS_GLB_VDSP_MST_BUSMON_EN                ( BIT(9) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_BUSMON_EN                ( BIT(8) )
#define BIT_CAMERASYS_GLB_VDSP_BLK_EN                       ( BIT(7) )
#define BIT_CAMERASYS_GLB_UART_EN                           ( BIT(6) )
#define BIT_CAMERASYS_GLB_VDSP_BLK_CFG_EN                   ( BIT(5) )
#define BIT_CAMERASYS_GLB_VDSP_MTX_DATA                     ( BIT(4) )
#define BIT_CAMERASYS_GLB_VDSP_TCK_EN                       ( BIT(3) )
#define BIT_CAMERASYS_GLB_VDMA_EN                           ( BIT(2) )
#define BIT_CAMERASYS_GLB_VDSP_M_EN                         ( BIT(1) )
#define BIT_CAMERASYS_GLB_VDSP_EN                           ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_DCAM_BLK_EN, [0x3000000C] */
#define BIT_CAMERASYS_GLB_IPA_EN                            ( BIT(16) )
#define BIT_CAMERASYS_GLB_CSI3_EN                           ( BIT(15) )
#define BIT_CAMERASYS_GLB_CSI2_EN                           ( BIT(14) )
#define BIT_CAMERASYS_GLB_CSI1_EN                           ( BIT(13) )
#define BIT_CAMERASYS_GLB_CSI0_EN                           ( BIT(12) )
#define BIT_CAMERASYS_GLB_DCAM_TCK_EN                       ( BIT(11) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_EN                       ( BIT(10) )
#define BIT_CAMERASYS_GLB_SENSOR3_EN                        ( BIT(9) )
#define BIT_CAMERASYS_GLB_SENSOR2_EN                        ( BIT(8) )
#define BIT_CAMERASYS_GLB_SENSOR1_EN                        ( BIT(7) )
#define BIT_CAMERASYS_GLB_SENSOR0_EN                        ( BIT(6) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_CFG_EN                   ( BIT(5) )
#define BIT_CAMERASYS_GLB_DCAM_LITE_MTX_EN                  ( BIT(4) )
#define BIT_CAMERASYS_GLB_DCAM_MTX_EN                       ( BIT(3) )
#define BIT_CAMERASYS_GLB_PHY_CFG_EN                        ( BIT(2) )
#define BIT_CAMERASYS_GLB_DCAM_IF_LITE_EN                   ( BIT(1) )
#define BIT_CAMERASYS_GLB_DCAM_IF_EN                        ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_MM_QOS, [0x30000010] */
#define BIT_CAMERASYS_GLB_AR_QOS_THRESHOLD_MM(x)            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_CAMERASYS_GLB_AW_QOS_THRESHOLD_MM(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_CAMERASYS_GLB_MM_LP_DISABLE, [0x30000014] */
#define BIT_CAMERASYS_GLB_CGM_ISP_AUTO_GATE_SEL             ( BIT(3) )
#define BIT_CAMERASYS_GLB_CGM_DCAM_AXI_AUTO_GATE_SEL        ( BIT(2) )
#define BIT_CAMERASYS_GLB_CGM_MM_MTX_S0_AUTO_GATE_EN        ( BIT(1) )
#define BIT_CAMERASYS_GLB_MM_LPC_DISABLE                    ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_VDSP_INT_MASK, [0x30000018] */
#define BIT_CAMERASYS_GLB_VDSP_MAILBOX_INT_MASK             ( BIT(5) )
#define BIT_CAMERASYS_GLB_VDSP_IDMA_VAU_INT_MASK            ( BIT(4) )
#define BIT_CAMERASYS_GLB_VDSP_MSTD_VAU_INT_MASK            ( BIT(3) )
#define BIT_CAMERASYS_GLB_VDSP_UART_INT_MASK                ( BIT(2) )
#define BIT_CAMERASYS_GLB_VDSP_VDMA_INT_MASK                ( BIT(1) )
#define BIT_CAMERASYS_GLB_VDSP_VDMA_VAU_INT_MASK            ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_MM_0P5_APPEND, [0x3000001C] */
#define BIT_CAMERASYS_GLB_SYS_SRST_BUSY_DCAM2_3             ( BIT(9) )
#define BIT_CAMERASYS_GLB_SYS_SRST_BUSY_DCAM0_1             ( BIT(8) )
#define BIT_CAMERASYS_GLB_SYS_SRST_BUSY_VDMA                ( BIT(7) )
#define BIT_CAMERASYS_GLB_SYS_SRST_BUSY_VDSP                ( BIT(6) )
#define BIT_CAMERASYS_GLB_SYS_SRST_BUSY_DEPTH               ( BIT(5) )
#define BIT_CAMERASYS_GLB_SYS_SRST_BUSY_FD                  ( BIT(4) )
#define BIT_CAMERASYS_GLB_SYS_SRST_BUSY_DEWARP              ( BIT(3) )
#define BIT_CAMERASYS_GLB_SYS_SRST_BUSY_CPP                 ( BIT(2) )
#define BIT_CAMERASYS_GLB_SYS_SRST_BUSY_ISP                 ( BIT(1) )
#define BIT_CAMERASYS_GLB_SYS_SRST_BUSY_JPG                 ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_MM_IP_BUSY0, [0x30000020] */
#define BIT_CAMERASYS_GLB_ISP_BLK_M0_CGM_BUSY_LPC           ( BIT(31) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M1_CGM_BUSY_LPC           ( BIT(30) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M2_CGM_BUSY_LPC           ( BIT(29) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M3_CGM_BUSY_LPC           ( BIT(28) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M4_CGM_BUSY_LPC           ( BIT(27) )
#define BIT_CAMERASYS_GLB_ISP_BLK_S0_CGM_BUSY_LPC           ( BIT(26) )
#define BIT_CAMERASYS_GLB_SYS_M0_CGM_BUSY_LPC               ( BIT(25) )
#define BIT_CAMERASYS_GLB_SYS_M1_CGM_BUSY_LPC               ( BIT(24) )
#define BIT_CAMERASYS_GLB_SYS_M2_CGM_BUSY_LPC               ( BIT(23) )
#define BIT_CAMERASYS_GLB_SYS_M3_CGM_BUSY_LPC               ( BIT(22) )
#define BIT_CAMERASYS_GLB_SYS_S0_CGM_BUSY_LPC               ( BIT(21) )
#define BIT_CAMERASYS_GLB_SYS_S1_CGM_BUSY_LPC               ( BIT(20) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M0_CGM_BUSY_LPC          ( BIT(19) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M1_CGM_BUSY_LPC          ( BIT(18) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M2_CGM_BUSY_LPC          ( BIT(17) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M3_CGM_BUSY_LPC          ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_MST_S0_CGM_BUSY_LPC          ( BIT(15) )
#define BIT_CAMERASYS_GLB_VDSP_MST_S1_CGM_BUSY_LPC          ( BIT(14) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_M0_CGM_BUSY_LPC          ( BIT(13) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_M1_CGM_BUSY_LPC          ( BIT(12) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_S0_CGM_BUSY_LPC          ( BIT(11) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_S1_CGM_BUSY_LPC          ( BIT(10) )
#define BIT_CAMERASYS_GLB_MSTD_VAU_BUSY                     ( BIT(9) )
#define BIT_CAMERASYS_GLB_MSTI_VAU_BUSY                     ( BIT(8) )
#define BIT_CAMERASYS_GLB_VDMA_BUSY                         ( BIT(7) )
#define BIT_CAMERASYS_GLB_DEP_BUSY                          ( BIT(6) )
#define BIT_CAMERASYS_GLB_FD_BUSY                           ( BIT(5) )
#define BIT_CAMERASYS_GLB_DCAM_IF_LITE_BUSY                 ( BIT(4) )
#define BIT_CAMERASYS_GLB_DCAM_IF_BUSY                      ( BIT(3) )
#define BIT_CAMERASYS_GLB_ISP_BUSY                          ( BIT(2) )
#define BIT_CAMERASYS_GLB_JPG_BUSY                          ( BIT(1) )
#define BIT_CAMERASYS_GLB_CPP_BUSY                          ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_MM_IP_BUSY1, [0x30000024] */
#define BIT_CAMERASYS_GLB_ASB_HB_CGM_BUSY_LPC               ( BIT(9) )
#define BIT_CAMERASYS_GLB_ASB_LL_CGM_BUSY_LPC               ( BIT(8) )
#define BIT_CAMERASYS_GLB_CFG_M0_CGM_BUSY_LPC               ( BIT(7) )
#define BIT_CAMERASYS_GLB_CFG_M1_CGM_BUSY_LPC               ( BIT(6) )
#define BIT_CAMERASYS_GLB_CFG_S0_CGM_BUSY_LPC               ( BIT(5) )
#define BIT_CAMERASYS_GLB_CFG_S1_CGM_BUSY_LPC               ( BIT(4) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_M0_CGM_BUSY_LPC          ( BIT(3) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_M1_CGM_BUSY_LPC          ( BIT(2) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_S0_CGM_BUSY_LPC          ( BIT(1) )
#define BIT_CAMERASYS_GLB_IDMA_VAU_BUSY                     ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_MM_AS_BDG_STATE, [0x30000028] */
#define BIT_CAMERASYS_GLB_AXI_DETECTOR_OVERFLOW_LL          ( BIT(3) )
#define BIT_CAMERASYS_GLB_AXI_DETECTOR_OVERFLOW_HB          ( BIT(2) )
#define BIT_CAMERASYS_GLB_BRIDGE_TRANS_IDLE_LL              ( BIT(1) )
#define BIT_CAMERASYS_GLB_BRIDGE_TRANS_IDLE_HB              ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_CFG_M0_LPC_CTRL, [0x3000002C] */
#define BIT_CAMERASYS_GLB_CFG_M0_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_CFG_M0_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_CFG_M0_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_CFG_M1_LPC_CTRL, [0x30000030] */
#define BIT_CAMERASYS_GLB_CFG_M1_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_CFG_M1_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_CFG_M1_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_CFG_S0_LPC_CTRL, [0x30000034] */
#define BIT_CAMERASYS_GLB_CFG_S0_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_CFG_S0_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_CFG_S0_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_CFG_S1_LPC_CTRL, [0x30000038] */
#define BIT_CAMERASYS_GLB_CFG_S1_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_CFG_S1_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_CFG_S1_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_SYS_M0_LPC_CTRL, [0x3000003C] */
#define BIT_CAMERASYS_GLB_SYS_M0_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_SYS_M0_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_SYS_M0_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_SYS_M1_LPC_CTRL, [0x30000040] */
#define BIT_CAMERASYS_GLB_SYS_M1_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_SYS_M1_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_SYS_M1_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_SYS_M2_LPC_CTRL, [0x30000044] */
#define BIT_CAMERASYS_GLB_SYS_M2_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_SYS_M2_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_SYS_M2_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_SYS_M3_LPC_CTRL, [0x30000048] */
#define BIT_CAMERASYS_GLB_SYS_M3_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_SYS_M3_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_SYS_M3_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_SYS_S0_LPC_CTRL, [0x3000004C] */
#define BIT_CAMERASYS_GLB_SYS_S0_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_SYS_S0_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_SYS_S0_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_SYS_S1_LPC_CTRL, [0x30000050] */
#define BIT_CAMERASYS_GLB_SYS_S1_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_SYS_S1_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_SYS_S1_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_ASB_HB_LPC_CTRL, [0x30000054] */
#define BIT_CAMERASYS_GLB_ASB_HB_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_ASB_HB_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_ASB_HB_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_SYS_ASB_LL_LPC_CTRL, [0x30000058] */
#define BIT_CAMERASYS_GLB_ASB_LL_PU_NUM(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_ASB_LL_LP_EB                      ( BIT(16) )
#define BIT_CAMERASYS_GLB_ASB_LL_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_ISP_BLK_M0_LPC_CTRL, [0x3000005C] */
#define BIT_CAMERASYS_GLB_ISP_BLK_M0_PU_NUM(x)              ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M0_LP_EB                  ( BIT(16) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M0_LP_NUM(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_ISP_BLK_M1_LPC_CTRL, [0x30000060] */
#define BIT_CAMERASYS_GLB_ISP_BLK_M1_PU_NUM(x)              ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M1_LP_EB                  ( BIT(16) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M1_LP_NUM(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_ISP_BLK_M2_LPC_CTRL, [0x30000064] */
#define BIT_CAMERASYS_GLB_ISP_BLK_M2_PU_NUM(x)              ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M2_LP_EB                  ( BIT(16) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M2_LP_NUM(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_ISP_BLK_M3_LPC_CTRL, [0x30000068] */
#define BIT_CAMERASYS_GLB_ISP_BLK_M3_PU_NUM(x)              ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M3_LP_EB                  ( BIT(16) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M3_LP_NUM(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_ISP_BLK_M4_LPC_CTRL, [0x3000006C] */
#define BIT_CAMERASYS_GLB_ISP_BLK_M4_PU_NUM(x)              ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M4_LP_EB                  ( BIT(16) )
#define BIT_CAMERASYS_GLB_ISP_BLK_M4_LP_NUM(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_ISP_BLK_S0_LPC_CTRL, [0x30000070] */
#define BIT_CAMERASYS_GLB_ISP_BLK_S0_PU_NUM(x)              ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_ISP_BLK_S0_LP_EB                  ( BIT(16) )
#define BIT_CAMERASYS_GLB_ISP_BLK_S0_LP_NUM(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_DCAM_BLK_M0_LPC_CTRL, [0x30000074] */
#define BIT_CAMERASYS_GLB_DCAM_BLK_M0_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_M0_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_M0_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_DCAM_BLK_M1_LPC_CTRL, [0x30000078] */
#define BIT_CAMERASYS_GLB_DCAM_BLK_M1_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_M1_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_M1_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_DCAM_BLK_S0_LPC_CTRL, [0x3000007C] */
#define BIT_CAMERASYS_GLB_DCAM_BLK_S0_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_S0_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_S0_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_VDSP_MST_M0_LPC_CTRL, [0x30000080] */
#define BIT_CAMERASYS_GLB_VDSP_MST_M0_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M0_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M0_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_VDSP_MST_M1_LPC_CTRL, [0x30000084] */
#define BIT_CAMERASYS_GLB_VDSP_MST_M1_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M1_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M1_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_VDSP_MST_M2_LPC_CTRL, [0x30000088] */
#define BIT_CAMERASYS_GLB_VDSP_MST_M2_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M2_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M2_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_VDSP_MST_M3_LPC_CTRL, [0x3000008C] */
#define BIT_CAMERASYS_GLB_VDSP_MST_M3_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M3_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_MST_M3_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_VDSP_MST_S0_LPC_CTRL, [0x30000090] */
#define BIT_CAMERASYS_GLB_VDSP_MST_S0_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_VDSP_MST_S0_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_MST_S0_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_VDSP_MST_S1_LPC_CTRL, [0x30000094] */
#define BIT_CAMERASYS_GLB_VDSP_MST_S1_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_VDSP_MST_S1_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_MST_S1_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_VDSP_SLV_M0_LPC_CTRL, [0x30000098] */
#define BIT_CAMERASYS_GLB_VDSP_SLV_M0_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_M0_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_M0_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_VDSP_SLV_M1_LPC_CTRL, [0x3000009C] */
#define BIT_CAMERASYS_GLB_VDSP_SLV_M1_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_M1_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_M1_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_VDSP_SLV_S0_LPC_CTRL, [0x300000A0] */
#define BIT_CAMERASYS_GLB_VDSP_SLV_S0_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_S0_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_S0_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MM_VDSP_SLV_S1_LPC_CTRL, [0x300000A4] */
#define BIT_CAMERASYS_GLB_VDSP_SLV_S1_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_S1_LP_EB                 ( BIT(16) )
#define BIT_CAMERASYS_GLB_VDSP_SLV_S1_LP_NUM(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CAMERASYS_GLB_MIPI_PHY_SEL, [0x300000A8] */
#define BIT_CAMERASYS_GLB_MIPI_CSI_CDPHY_C3_SEL(x)          ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BIT_CAMERASYS_GLB_MIPI_CSI_CDPHY_C2_SEL(x)          ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_CAMERASYS_GLB_MIPI_CSI_DPHY_C1_SEL1(x)          ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_CAMERASYS_GLB_MIPI_CSI_DPHY_C1_SEL0(x)          ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_CAMERASYS_GLB_MIPI_CSI_DPHY_C0_SEL1(x)          ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_CAMERASYS_GLB_MIPI_CSI_DPHY_C0_SEL0(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_CAMERASYS_GLB_USER_GATE_FORCE_OFF0, [0x300000AC] */
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_UART_FORCE_OFF         ( BIT(31) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_DVFS_FORCE_OFF         ( BIT(30) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_CKG_FORCE_OFF          ( BIT(29) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_DCAM_BLK_FORCE_OFF     ( BIT(28) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_ISP_BLK_FORCE_OFF      ( BIT(27) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_JPG_FORCE_OFF          ( BIT(26) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_SYS_MTX_FORCE_OFF      ( BIT(25) )
#define BIT_CAMERASYS_GLB_JPG_FR_FORCE_OFF                  ( BIT(24) )
#define BIT_CAMERASYS_GLB_JPG_CFG_FORCE_OFF                 ( BIT(23) )
#define BIT_CAMERASYS_GLB_JPG_JPG_FORCE_OFF                 ( BIT(22) )
#define BIT_CAMERASYS_GLB_MM_MTX_DATA_FR_FORCE_OFF          ( BIT(21) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_CFG_DCAM_BLK_FORCE_OFF   ( BIT(20) )
#define BIT_CAMERASYS_GLB_DCAM_MTX_FR_FORCE_OFF             ( BIT(19) )
#define BIT_CAMERASYS_GLB_CPHY_CFG_FR_FORCE_OFF             ( BIT(18) )
#define BIT_CAMERASYS_GLB_DCAM2_3_AXI_FR_FORCE_OFF          ( BIT(17) )
#define BIT_CAMERASYS_GLB_DCAM2_3_AXI_DCAM2_3_FORCE_OFF     ( BIT(16) )
#define BIT_CAMERASYS_GLB_DCAM2_3_FR_FORCE_OFF              ( BIT(15) )
#define BIT_CAMERASYS_GLB_DCAM0_1_AXI_FR_FORCE_OFF          ( BIT(14) )
#define BIT_CAMERASYS_GLB_DCAM0_1_AXI_DCAM0_1_FORCE_OFF     ( BIT(13) )
#define BIT_CAMERASYS_GLB_DCAM0_1_FR_FORCE_OFF              ( BIT(12) )
#define BIT_CAMERASYS_GLB_FD_FR_FORCE_OFF                   ( BIT(11) )
#define BIT_CAMERASYS_GLB_DEPTH_FR_FORCE_OFF                ( BIT(10) )
#define BIT_CAMERASYS_GLB_CPP_FR_FORCE_OFF                  ( BIT(9) )
#define BIT_CAMERASYS_GLB_ISP_FR_FORCE_OFF                  ( BIT(8) )
#define BIT_CAMERASYS_GLB_UART_FR_FORCE_OFF                 ( BIT(7) )
#define BIT_CAMERASYS_GLB_VDSP_BLK_CFG_FR_FORCE_OFF         ( BIT(6) )
#define BIT_CAMERASYS_GLB_VDSP_BLK_CFG_VDSP_BLK_FORCE_OFF   ( BIT(5) )
#define BIT_CAMERASYS_GLB_VDSP_MTX_DATA_FR_FORCE_OFF        ( BIT(4) )
#define BIT_CAMERASYS_GLB_VDSP_TCK_FR_FORCE_OFF             ( BIT(3) )
#define BIT_CAMERASYS_GLB_VDMA_FR_FORCE_OFF                 ( BIT(2) )
#define BIT_CAMERASYS_GLB_VDSP_M_FR_FORCE_OFF               ( BIT(1) )
#define BIT_CAMERASYS_GLB_VDSP_FR_FORCE_OFF                 ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_USER_GATE_FORCE_OFF1, [0x300000B0] */
#define BIT_CAMERASYS_GLB_TZPC_FR_FORCE_OFF                 ( BIT(11) )
#define BIT_CAMERASYS_GLB_DJTAG_TCK_SYS_FORCE_OFF           ( BIT(10) )
#define BIT_CAMERASYS_GLB_DJTAG_TCK_VDSP_BLK_FORCE_OFF      ( BIT(9) )
#define BIT_CAMERASYS_GLB_DJTAG_TCK_DCAM_BLK_FORCE_OFF      ( BIT(8) )
#define BIT_CAMERASYS_GLB_DJTAG_TCK_ISP_BLK_FORCE_OFF       ( BIT(7) )
#define BIT_CAMERASYS_GLB_SENSOR3_FR_FORCE_OFF              ( BIT(6) )
#define BIT_CAMERASYS_GLB_SENSOR2_FR_FORCE_OFF              ( BIT(5) )
#define BIT_CAMERASYS_GLB_SENSOR1_FR_FORCE_OFF              ( BIT(4) )
#define BIT_CAMERASYS_GLB_SENSOR0_FR_FORCE_OFF              ( BIT(3) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_FR_FORCE_OFF           ( BIT(2) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_ASBR_FORCE_OFF         ( BIT(1) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_MAILBOX_FORCE_OFF      ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_USER_GATE_AUTO_GATE_EN0, [0x300000B4] */
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_UART_AUTO_GATE_EN      ( BIT(31) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_DVFS_AUTO_GATE_EN      ( BIT(30) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_CKG_AUTO_GATE_EN       ( BIT(29) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_DCAM_BLK_AUTO_GATE_EN  ( BIT(28) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_ISP_BLK_AUTO_GATE_EN   ( BIT(27) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_JPG_AUTO_GATE_EN       ( BIT(26) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_SYS_MTX_AUTO_GATE_EN   ( BIT(25) )
#define BIT_CAMERASYS_GLB_JPG_FR_AUTO_GATE_EN               ( BIT(24) )
#define BIT_CAMERASYS_GLB_JPG_CFG_AUTO_GATE_EN              ( BIT(23) )
#define BIT_CAMERASYS_GLB_JPG_JPG_AUTO_GATE_EN              ( BIT(22) )
#define BIT_CAMERASYS_GLB_MM_MTX_DATA_FR_AUTO_GATE_EN       ( BIT(21) )
#define BIT_CAMERASYS_GLB_DCAM_BLK_CFG_DCAM_BLK_AUTO_GATE_EN ( BIT(20) )
#define BIT_CAMERASYS_GLB_DCAM_MTX_FR_AUTO_GATE_EN          ( BIT(19) )
#define BIT_CAMERASYS_GLB_CPHY_CFG_FR_AUTO_GATE_EN          ( BIT(18) )
#define BIT_CAMERASYS_GLB_DCAM2_3_AXI_FR_AUTO_GATE_EN       ( BIT(17) )
#define BIT_CAMERASYS_GLB_DCAM2_3_AXI_DCAM2_3_AUTO_GATE_EN  ( BIT(16) )
#define BIT_CAMERASYS_GLB_DCAM2_3_FR_AUTO_GATE_EN           ( BIT(15) )
#define BIT_CAMERASYS_GLB_DCAM0_1_AXI_FR_AUTO_GATE_EN       ( BIT(14) )
#define BIT_CAMERASYS_GLB_DCAM0_1_AXI_DCAM0_1_AUTO_GATE_EN  ( BIT(13) )
#define BIT_CAMERASYS_GLB_DCAM0_1_FR_AUTO_GATE_EN           ( BIT(12) )
#define BIT_CAMERASYS_GLB_FD_FR_AUTO_GATE_EN                ( BIT(11) )
#define BIT_CAMERASYS_GLB_DEPTH_FR_AUTO_GATE_EN             ( BIT(10) )
#define BIT_CAMERASYS_GLB_CPP_FR_AUTO_GATE_EN               ( BIT(9) )
#define BIT_CAMERASYS_GLB_ISP_FR_AUTO_GATE_EN               ( BIT(8) )
#define BIT_CAMERASYS_GLB_UART_FR_AUTO_GATE_EN              ( BIT(7) )
#define BIT_CAMERASYS_GLB_VDSP_BLK_CFG_FR_AUTO_GATE_EN      ( BIT(6) )
#define BIT_CAMERASYS_GLB_VDSP_BLK_CFG_VDSP_BLK_AUTO_GATE_EN ( BIT(5) )
#define BIT_CAMERASYS_GLB_VDSP_MTX_DATA_FR_AUTO_GATE_EN     ( BIT(4) )
#define BIT_CAMERASYS_GLB_VDSP_TCK_FR_AUTO_GATE_EN          ( BIT(3) )
#define BIT_CAMERASYS_GLB_VDMA_FR_AUTO_GATE_EN              ( BIT(2) )
#define BIT_CAMERASYS_GLB_VDSP_M_FR_AUTO_GATE_EN            ( BIT(1) )
#define BIT_CAMERASYS_GLB_VDSP_FR_AUTO_GATE_EN              ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_USER_GATE_AUTO_GATE_EN1, [0x300000B8] */
#define BIT_CAMERASYS_GLB_TZPC_FR_AUTO_GATE_EN              ( BIT(11) )
#define BIT_CAMERASYS_GLB_DJTAG_TCK_SYS_AUTO_GATE_EN        ( BIT(10) )
#define BIT_CAMERASYS_GLB_DJTAG_TCK_VDSP_BLK_AUTO_GATE_EN   ( BIT(9) )
#define BIT_CAMERASYS_GLB_DJTAG_TCK_DCAM_BLK_AUTO_GATE_EN   ( BIT(8) )
#define BIT_CAMERASYS_GLB_DJTAG_TCK_ISP_BLK_AUTO_GATE_EN    ( BIT(7) )
#define BIT_CAMERASYS_GLB_SENSOR3_FR_AUTO_GATE_EN           ( BIT(6) )
#define BIT_CAMERASYS_GLB_SENSOR2_FR_AUTO_GATE_EN           ( BIT(5) )
#define BIT_CAMERASYS_GLB_SENSOR1_FR_AUTO_GATE_EN           ( BIT(4) )
#define BIT_CAMERASYS_GLB_SENSOR0_FR_AUTO_GATE_EN           ( BIT(3) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_FR_AUTO_GATE_EN        ( BIT(2) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_ASBR_AUTO_GATE_EN      ( BIT(1) )
#define BIT_CAMERASYS_GLB_MM_SYS_CFG_MAILBOX_AUTO_GATE_EN   ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_VDSP_CORE_CFG, [0x300000BC] */
#define BIT_CAMERASYS_GLB_PRID(x)                           ( (x) << 16 & (0xFFFF0000) )
#define BIT_CAMERASYS_GLB_VDSP_PWAITMODE                    ( BIT(12) )
#define BIT_CAMERASYS_GLB_DBGEN                             ( BIT(11) )
#define BIT_CAMERASYS_GLB_NIDEN                             ( BIT(10) )
#define BIT_CAMERASYS_GLB_SPIDEN                            ( BIT(9) )
#define BIT_CAMERASYS_GLB_SPNIDEN                           ( BIT(8) )
#define BIT_CAMERASYS_GLB_VDSP_TRIGOUT_IDMA(x)              ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_CAMERASYS_GLB_VDSP_TRIGIN_IDMA(x)               ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_CAMERASYS_GLB_STAT_VECTOR_SEL                   ( BIT(3) )
#define BIT_CAMERASYS_GLB_RUNSTALLONRESET                   ( BIT(2) )
#define BIT_CAMERASYS_GLB_DCACHE_DRAM_FLUSH(x)              ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_CAMERASYS_GLB_VDSP_FATAL_INFO_LOW, [0x300000C0] */
#define BIT_CAMERASYS_GLB_VDSP_PFAULTINFO_LOW(x)            ( (x) )

/* bits definitions for REG_CAMERASYS_GLB_VDSP_FATAL_INFO_HIGH, [0x300000C4] */
#define BIT_CAMERASYS_GLB_VDSP_PFAULTINFO_HIGH(x)           ( (x) )

/* bits definitions for REG_CAMERASYS_GLB_DCAM_BLK_SOFT_RST, [0x300000C8] */
#define BIT_CAMERASYS_GLB_DCAM0_1_VAU_SOFT_RST              ( BIT(14) )
#define BIT_CAMERASYS_GLB_DCAM2_3_VAU_SOFT_RST              ( BIT(13) )
#define BIT_CAMERASYS_GLB_DCAM2_3_AXI_SOFT_RST              ( BIT(12) )
#define BIT_CAMERASYS_GLB_MIPI_CSI0_SOFT_RST                ( BIT(11) )
#define BIT_CAMERASYS_GLB_MIPI_CSI1_SOFT_RST                ( BIT(10) )
#define BIT_CAMERASYS_GLB_MIPI_CSI2_SOFT_RST                ( BIT(9) )
#define BIT_CAMERASYS_GLB_MIPI_CSI3_SOFT_RST                ( BIT(8) )
#define BIT_CAMERASYS_GLB_DCAM0_SOFT_RST                    ( BIT(7) )
#define BIT_CAMERASYS_GLB_DCAM1_SOFT_RST                    ( BIT(6) )
#define BIT_CAMERASYS_GLB_DCAM2_SOFT_RST                    ( BIT(5) )
#define BIT_CAMERASYS_GLB_DCAM3_SOFT_RST                    ( BIT(4) )
#define BIT_CAMERASYS_GLB_DCAM0_1_AXI_SOFT_RST              ( BIT(3) )
#define BIT_CAMERASYS_GLB_DCAM2_3_ALL_SOFT_RST              ( BIT(2) )
#define BIT_CAMERASYS_GLB_DCAM0_1_ALL_SOFT_RST              ( BIT(1) )
#define BIT_CAMERASYS_GLB_REGU_SOFT_RST                     ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_ISP_BLK_SOFT_RST, [0x300000CC] */
#define BIT_CAMERASYS_GLB_ISP_SOFT_RST                      ( BIT(14) )
#define BIT_CAMERASYS_GLB_ISP_ALL_SOFT                      ( BIT(13) )
#define BIT_CAMERASYS_GLB_ISP_VAU_SOFT_RST                  ( BIT(12) )
#define BIT_CAMERASYS_GLB_CPP_ALL_SOFT_RST                  ( BIT(11) )
#define BIT_CAMERASYS_GLB_CPP_SOFT_RST                      ( BIT(10) )
#define BIT_CAMERASYS_GLB_CPP_VAU_SOFT_RST                  ( BIT(9) )
#define BIT_CAMERASYS_GLB_CPP_PATH0_SOFT_RST                ( BIT(8) )
#define BIT_CAMERASYS_GLB_CPP_PATH1_SOFT_RST                ( BIT(7) )
#define BIT_CAMERASYS_GLB_CPP_DMA_SOFT_RST                  ( BIT(6) )
#define BIT_CAMERASYS_GLB_FD_ALL_SOFT_N                     ( BIT(5) )
#define BIT_CAMERASYS_GLB_FD_SOFT_RST                       ( BIT(4) )
#define BIT_CAMERASYS_GLB_FD_VAU_SOFT_RST                   ( BIT(3) )
#define BIT_CAMERASYS_GLB_DEP_ALL_SOFT_N                    ( BIT(2) )
#define BIT_CAMERASYS_GLB_DEP_SOFT_RST                      ( BIT(1) )
#define BIT_CAMERASYS_GLB_DEP_VAU_SOFT_RST                  ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_SYS_SOFT_RST, [0x300000D0] */
#define BIT_CAMERASYS_GLB_UART_SOFT_RST                     ( BIT(6) )
#define BIT_CAMERASYS_GLB_MAILBOX_SOFT_RST                  ( BIT(5) )
#define BIT_CAMERASYS_GLB_JPG_VAU_SOFT_RST                  ( BIT(4) )
#define BIT_CAMERASYS_GLB_JPG_SOFT_RST                      ( BIT(3) )
#define BIT_CAMERASYS_GLB_SYS_H2P_DB_SOFT_RST               ( BIT(2) )
#define BIT_CAMERASYS_GLB_DVFS_SOFT_RST                     ( BIT(1) )
#define BIT_CAMERASYS_GLB_CKG_SOFT_RST                      ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_VDSP_BLK_SOFTRST, [0x300000D4] */
#define BIT_CAMERASYS_GLB_VDSP_SOFT_RST                     ( BIT(5) )
#define BIT_CAMERASYS_GLB_VDSP_DEBUG_SOFT_RST               ( BIT(4) )
#define BIT_CAMERASYS_GLB_VDSP_IDMA_VAU_SOFT_RST            ( BIT(3) )
#define BIT_CAMERASYS_GLB_VDSP_MSTD_VAU_SOFT_RST            ( BIT(2) )
#define BIT_CAMERASYS_GLB_VDMA_SOFT_RST                     ( BIT(1) )
#define BIT_CAMERASYS_GLB_VDMA_VAU_SOFT_RST                 ( BIT(0) )

/* bits definitions for REG_CAMERASYS_GLB_SYS_LGT_STOP_MASK, [0x300000D8] */
#define BIT_CAMERASYS_GLB_LGT_STP_BUSY_MASK                 ( BIT(0) )

/* vars definitions for controller CTL_CAMERASYS_GLB */


#endif /* __CAMERASYS_GLB_H____ */
