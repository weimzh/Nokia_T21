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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/ap/output/ap_ahb_rf/SharkL6Pro AP_AHB_RF Firewall Control Register.xlsx;ap_ahb_rf
 *     Revision : 231409
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __REG_FW_AP_AHB_H____
#define __REG_FW_AP_AHB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_REG_FW_AP_AHB_BASE
#define CTL_REG_FW_AP_AHB_BASE          SCI_IOMAP(0x64809000)
#endif

/* registers definitions for CTL_REG_FW_AP_AHB, 0x64809000 */
#define REG_REG_FW_AP_AHB_REG_RD_CTRL_0                     SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0000)
#define REG_REG_FW_AP_AHB_REG_RD_CTRL_1                     SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0004)
#define REG_REG_FW_AP_AHB_REG_WR_CTRL_0                     SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0008)
#define REG_REG_FW_AP_AHB_REG_WR_CTRL_1                     SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x000C)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY0              SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0010)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY1              SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0014)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY2              SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0018)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY3              SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x001C)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY4              SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0020)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY5              SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0024)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY6              SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0028)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY7              SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x002C)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY8              SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0030)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY9              SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0034)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY10             SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0038)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY11             SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x003C)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY12             SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0040)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY13             SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0044)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY14             SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0048)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY15             SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x004C)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY0                   SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0050)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY1                   SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0054)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY2                   SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0058)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY3                   SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x005C)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY4                   SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0060)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY5                   SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0064)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY6                   SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0068)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY7                   SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x006C)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY8                   SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0070)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY9                   SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0074)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY10                  SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0078)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY11                  SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x007C)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY12                  SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0080)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY13                  SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0084)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY14                  SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x0088)
#define REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY15                  SCI_ADDR(CTL_REG_FW_AP_AHB_BASE, 0x008C)

/* bits definitions for REG_REG_FW_AP_AHB_REG_RD_CTRL_0, [0x64809000] */
#define BIT_REG_FW_AP_AHB_S7_LPC_RD_SEC                     ( BIT(31) )
#define BIT_REG_FW_AP_AHB_S6_LPC_RD_SEC                     ( BIT(30) )
#define BIT_REG_FW_AP_AHB_S5_LPC_RD_SEC                     ( BIT(29) )
#define BIT_REG_FW_AP_AHB_S4_LPC_RD_SEC                     ( BIT(28) )
#define BIT_REG_FW_AP_AHB_S3_LPC_RD_SEC                     ( BIT(27) )
#define BIT_REG_FW_AP_AHB_S2_LPC_RD_SEC                     ( BIT(26) )
#define BIT_REG_FW_AP_AHB_S1_LPC_RD_SEC                     ( BIT(25) )
#define BIT_REG_FW_AP_AHB_S0_LPC_RD_SEC                     ( BIT(24) )
#define BIT_REG_FW_AP_AHB_MAIN_LPC_RD_SEC                   ( BIT(23) )
#define BIT_REG_FW_AP_AHB_M7_LPC_RD_SEC                     ( BIT(22) )
#define BIT_REG_FW_AP_AHB_M6_LPC_RD_SEC                     ( BIT(21) )
#define BIT_REG_FW_AP_AHB_M5_LPC_RD_SEC                     ( BIT(20) )
#define BIT_REG_FW_AP_AHB_M4_LPC_RD_SEC                     ( BIT(19) )
#define BIT_REG_FW_AP_AHB_M3_LPC_RD_SEC                     ( BIT(18) )
#define BIT_REG_FW_AP_AHB_M2_LPC_RD_SEC                     ( BIT(17) )
#define BIT_REG_FW_AP_AHB_M1_LPC_RD_SEC                     ( BIT(16) )
#define BIT_REG_FW_AP_AHB_M0_LPC_RD_SEC                     ( BIT(15) )
#define BIT_REG_FW_AP_AHB_AP_ASYNC_BRG_APCPU_RD_SEC         ( BIT(14) )
#define BIT_REG_FW_AP_AHB_AP_ASYNC_BRG_DDR_RD_SEC           ( BIT(13) )
#define BIT_REG_FW_AP_AHB_AP_ASYNC_BRG_AON_RD_SEC           ( BIT(12) )
#define BIT_REG_FW_AP_AHB_UFSHC_CLK_CTRL_RD_SEC             ( BIT(11) )
#define BIT_REG_FW_AP_AHB_AP_SYS_CLK_EN_FRC_ON_1_RD_SEC     ( BIT(10) )
#define BIT_REG_FW_AP_AHB_AP_SYS_CLK_EN_FRC_ON_0_RD_SEC     ( BIT(9) )
#define BIT_REG_FW_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_1_RD_SEC    ( BIT(8) )
#define BIT_REG_FW_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_0_RD_SEC    ( BIT(7) )
#define BIT_REG_FW_AP_AHB_AHB_EB1_RD_SEC                    ( BIT(6) )
#define BIT_REG_FW_AP_AHB_CLOCK_FREQUENCY_DOWN_RD_SEC       ( BIT(5) )
#define BIT_REG_FW_AP_AHB_HOLDING_PEN_RD_SEC                ( BIT(4) )
#define BIT_REG_FW_AP_AHB_AP_SYS_AUTO_SLEEP_CFG_RD_SEC      ( BIT(3) )
#define BIT_REG_FW_AP_AHB_AP_SYS_FORCE_SLEEP_CFG_RD_SEC     ( BIT(2) )
#define BIT_REG_FW_AP_AHB_AHB_RST_RD_SEC                    ( BIT(1) )
#define BIT_REG_FW_AP_AHB_AHB_EB_RD_SEC                     ( BIT(0) )

/* bits definitions for REG_REG_FW_AP_AHB_REG_RD_CTRL_1, [0x64809004] */
#define BIT_REG_FW_AP_AHB_CHIP_ID_RD_SEC                    ( BIT(10) )
#define BIT_REG_FW_AP_AHB_UFSHC_CTRL_STATUS_RD_SEC          ( BIT(9) )
#define BIT_REG_FW_AP_AHB_CACHE_UFS_RD_SEC                  ( BIT(8) )
#define BIT_REG_FW_AP_AHB_CACHE_EMMC_SDIO_RD_SEC            ( BIT(7) )
#define BIT_REG_FW_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_AP_RD_SEC ( BIT(6) )
#define BIT_REG_FW_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP_RD_SEC ( BIT(5) )
#define BIT_REG_FW_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_VDSP_RD_SEC ( BIT(4) )
#define BIT_REG_FW_AP_AHB_ASYNC_BRIDGE_IDLE_OVERFLOW_RD_SEC ( BIT(3) )
#define BIT_REG_FW_AP_AHB_AP_QOS1_RD_SEC                    ( BIT(2) )
#define BIT_REG_FW_AP_AHB_AP_QOS0_RD_SEC                    ( BIT(1) )
#define BIT_REG_FW_AP_AHB_AP_URGENCY_RD_SEC                 ( BIT(0) )

/* bits definitions for REG_REG_FW_AP_AHB_REG_WR_CTRL_0, [0x64809008] */
#define BIT_REG_FW_AP_AHB_S7_LPC_WR_SEC                     ( BIT(31) )
#define BIT_REG_FW_AP_AHB_S6_LPC_WR_SEC                     ( BIT(30) )
#define BIT_REG_FW_AP_AHB_S5_LPC_WR_SEC                     ( BIT(29) )
#define BIT_REG_FW_AP_AHB_S4_LPC_WR_SEC                     ( BIT(28) )
#define BIT_REG_FW_AP_AHB_S3_LPC_WR_SEC                     ( BIT(27) )
#define BIT_REG_FW_AP_AHB_S2_LPC_WR_SEC                     ( BIT(26) )
#define BIT_REG_FW_AP_AHB_S1_LPC_WR_SEC                     ( BIT(25) )
#define BIT_REG_FW_AP_AHB_S0_LPC_WR_SEC                     ( BIT(24) )
#define BIT_REG_FW_AP_AHB_MAIN_LPC_WR_SEC                   ( BIT(23) )
#define BIT_REG_FW_AP_AHB_M7_LPC_WR_SEC                     ( BIT(22) )
#define BIT_REG_FW_AP_AHB_M6_LPC_WR_SEC                     ( BIT(21) )
#define BIT_REG_FW_AP_AHB_M5_LPC_WR_SEC                     ( BIT(20) )
#define BIT_REG_FW_AP_AHB_M4_LPC_WR_SEC                     ( BIT(19) )
#define BIT_REG_FW_AP_AHB_M3_LPC_WR_SEC                     ( BIT(18) )
#define BIT_REG_FW_AP_AHB_M2_LPC_WR_SEC                     ( BIT(17) )
#define BIT_REG_FW_AP_AHB_M1_LPC_WR_SEC                     ( BIT(16) )
#define BIT_REG_FW_AP_AHB_M0_LPC_WR_SEC                     ( BIT(15) )
#define BIT_REG_FW_AP_AHB_AP_ASYNC_BRG_APCPU_WR_SEC         ( BIT(14) )
#define BIT_REG_FW_AP_AHB_AP_ASYNC_BRG_DDR_WR_SEC           ( BIT(13) )
#define BIT_REG_FW_AP_AHB_AP_ASYNC_BRG_AON_WR_SEC           ( BIT(12) )
#define BIT_REG_FW_AP_AHB_UFSHC_CLK_CTRL_WR_SEC             ( BIT(11) )
#define BIT_REG_FW_AP_AHB_AP_SYS_CLK_EN_FRC_ON_1_WR_SEC     ( BIT(10) )
#define BIT_REG_FW_AP_AHB_AP_SYS_CLK_EN_FRC_ON_0_WR_SEC     ( BIT(9) )
#define BIT_REG_FW_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_1_WR_SEC    ( BIT(8) )
#define BIT_REG_FW_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_0_WR_SEC    ( BIT(7) )
#define BIT_REG_FW_AP_AHB_AHB_EB1_WR_SEC                    ( BIT(6) )
#define BIT_REG_FW_AP_AHB_CLOCK_FREQUENCY_DOWN_WR_SEC       ( BIT(5) )
#define BIT_REG_FW_AP_AHB_HOLDING_PEN_WR_SEC                ( BIT(4) )
#define BIT_REG_FW_AP_AHB_AP_SYS_AUTO_SLEEP_CFG_WR_SEC      ( BIT(3) )
#define BIT_REG_FW_AP_AHB_AP_SYS_FORCE_SLEEP_CFG_WR_SEC     ( BIT(2) )
#define BIT_REG_FW_AP_AHB_AHB_RST_WR_SEC                    ( BIT(1) )
#define BIT_REG_FW_AP_AHB_AHB_EB_WR_SEC                     ( BIT(0) )

/* bits definitions for REG_REG_FW_AP_AHB_REG_WR_CTRL_1, [0x6480900C] */
#define BIT_REG_FW_AP_AHB_CHIP_ID_WR_SEC                    ( BIT(10) )
#define BIT_REG_FW_AP_AHB_UFSHC_CTRL_STATUS_WR_SEC          ( BIT(9) )
#define BIT_REG_FW_AP_AHB_CACHE_UFS_WR_SEC                  ( BIT(8) )
#define BIT_REG_FW_AP_AHB_CACHE_EMMC_SDIO_WR_SEC            ( BIT(7) )
#define BIT_REG_FW_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_AP_WR_SEC ( BIT(6) )
#define BIT_REG_FW_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP_WR_SEC ( BIT(5) )
#define BIT_REG_FW_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_VDSP_WR_SEC ( BIT(4) )
#define BIT_REG_FW_AP_AHB_ASYNC_BRIDGE_IDLE_OVERFLOW_WR_SEC ( BIT(3) )
#define BIT_REG_FW_AP_AHB_AP_QOS1_WR_SEC                    ( BIT(2) )
#define BIT_REG_FW_AP_AHB_AP_QOS0_WR_SEC                    ( BIT(1) )
#define BIT_REG_FW_AP_AHB_AP_URGENCY_WR_SEC                 ( BIT(0) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY0, [0x64809010] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY0(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY1, [0x64809014] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY1(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY2, [0x64809018] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY2(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY3, [0x6480901C] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY3(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY4, [0x64809020] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY4(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY5, [0x64809024] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY5(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY6, [0x64809028] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY6(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY7, [0x6480902C] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY7(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY8, [0x64809030] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY8(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY9, [0x64809034] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY9(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY10, [0x64809038] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY10(x)          ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY11, [0x6480903C] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY11(x)          ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY12, [0x64809040] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY12(x)          ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY13, [0x64809044] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY13(x)          ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY14, [0x64809048] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY14(x)          ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY15, [0x6480904C] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ADDR_ARRAY15(x)          ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY0, [0x64809050] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY0(x)                ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY1, [0x64809054] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY1(x)                ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY2, [0x64809058] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY2(x)                ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY3, [0x6480905C] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY3(x)                ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY4, [0x64809060] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY4(x)                ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY5, [0x64809064] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY5(x)                ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY6, [0x64809068] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY6(x)                ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY7, [0x6480906C] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY7(x)                ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY8, [0x64809070] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY8(x)                ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY9, [0x64809074] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY9(x)                ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY10, [0x64809078] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY10(x)               ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY11, [0x6480907C] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY11(x)               ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY12, [0x64809080] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY12(x)               ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY13, [0x64809084] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY13(x)               ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY14, [0x64809088] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY14(x)               ( (x) )

/* bits definitions for REG_REG_FW_AP_AHB_BIT_CTRL_ARRAY15, [0x6480908C] */
#define BIT_REG_FW_AP_AHB_BIT_CTRL_ARRAY15(x)               ( (x) )

/* vars definitions for controller CTL_REG_FW_AP_AHB */


#endif /* __REG_FW_AP_AHB_H____ */
