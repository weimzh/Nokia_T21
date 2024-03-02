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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/ap/ap_clk_rf.xls;ap_clk_rf
 *     Revision : 231409
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __AP_CLK_H____
#define __AP_CLK_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AP_CLK_BASE
#define CTL_AP_CLK_BASE                 SCI_IOMAP(0x20010000)
#endif

/* registers definitions for CTL_AP_CLK, 0x20010000 */
#define REG_AP_CLK_CGM_AP_APB_SEL_CFG                       SCI_ADDR(CTL_AP_CLK_BASE, 0x0028)
#define REG_AP_CLK_CGM_AP_AXI_SEL_CFG                       SCI_ADDR(CTL_AP_CLK_BASE, 0x0034)
#define REG_AP_CLK_CGM_AP2EMC_SEL_CFG                       SCI_ADDR(CTL_AP_CLK_BASE, 0x0040)
#define REG_AP_CLK_CGM_UART0_DIV_CFG                        SCI_ADDR(CTL_AP_CLK_BASE, 0x0048)
#define REG_AP_CLK_CGM_UART0_SEL_CFG                        SCI_ADDR(CTL_AP_CLK_BASE, 0x004C)
#define REG_AP_CLK_CGM_UART1_DIV_CFG                        SCI_ADDR(CTL_AP_CLK_BASE, 0x0054)
#define REG_AP_CLK_CGM_UART1_SEL_CFG                        SCI_ADDR(CTL_AP_CLK_BASE, 0x0058)
#define REG_AP_CLK_CGM_UART2_DIV_CFG                        SCI_ADDR(CTL_AP_CLK_BASE, 0x0060)
#define REG_AP_CLK_CGM_UART2_SEL_CFG                        SCI_ADDR(CTL_AP_CLK_BASE, 0x0064)
#define REG_AP_CLK_CGM_UART3_DIV_CFG                        SCI_ADDR(CTL_AP_CLK_BASE, 0x006C)
#define REG_AP_CLK_CGM_UART3_SEL_CFG                        SCI_ADDR(CTL_AP_CLK_BASE, 0x0070)
#define REG_AP_CLK_CGM_I2C0_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0078)
#define REG_AP_CLK_CGM_I2C0_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x007C)
#define REG_AP_CLK_CGM_I2C1_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0084)
#define REG_AP_CLK_CGM_I2C1_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0088)
#define REG_AP_CLK_CGM_I2C2_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0090)
#define REG_AP_CLK_CGM_I2C2_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0094)
#define REG_AP_CLK_CGM_I2C3_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x009C)
#define REG_AP_CLK_CGM_I2C3_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00A0)
#define REG_AP_CLK_CGM_I2C4_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00A8)
#define REG_AP_CLK_CGM_I2C4_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00AC)
#define REG_AP_CLK_CGM_I2C5_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00B4)
#define REG_AP_CLK_CGM_I2C5_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00B8)
#define REG_AP_CLK_CGM_I2C6_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00C0)
#define REG_AP_CLK_CGM_I2C6_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00C4)
#define REG_AP_CLK_CGM_I2C7_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00CC)
#define REG_AP_CLK_CGM_I2C7_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00D0)
#define REG_AP_CLK_CGM_I2C8_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00D8)
#define REG_AP_CLK_CGM_I2C8_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00DC)
#define REG_AP_CLK_CGM_I2C9_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00E4)
#define REG_AP_CLK_CGM_I2C9_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00E8)
#define REG_AP_CLK_CGM_IIS0_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00F0)
#define REG_AP_CLK_CGM_IIS0_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00F4)
#define REG_AP_CLK_CGM_IIS1_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00FC)
#define REG_AP_CLK_CGM_IIS1_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0100)
#define REG_AP_CLK_CGM_IIS2_DIV_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0108)
#define REG_AP_CLK_CGM_IIS2_SEL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x010C)
#define REG_AP_CLK_CGM_CE_SEL_CFG                           SCI_ADDR(CTL_AP_CLK_BASE, 0x0118)
#define REG_AP_CLK_CGM_EMMC_2X_DIV_CFG                      SCI_ADDR(CTL_AP_CLK_BASE, 0x0120)
#define REG_AP_CLK_CGM_EMMC_2X_SEL_CFG                      SCI_ADDR(CTL_AP_CLK_BASE, 0x0124)
#define REG_AP_CLK_CGM_EMMC_1X_DIV_CFG                      SCI_ADDR(CTL_AP_CLK_BASE, 0x012C)
#define REG_AP_CLK_CGM_UFS_TX_DIV_CFG                       SCI_ADDR(CTL_AP_CLK_BASE, 0x0138)
#define REG_AP_CLK_CGM_UFS_TX_SEL_CFG                       SCI_ADDR(CTL_AP_CLK_BASE, 0x013C)
#define REG_AP_CLK_CGM_UFS_RX_DIV_CFG                       SCI_ADDR(CTL_AP_CLK_BASE, 0x0144)
#define REG_AP_CLK_CGM_UFS_RX_SEL_CFG                       SCI_ADDR(CTL_AP_CLK_BASE, 0x0148)
#define REG_AP_CLK_CGM_UFS_RX_1_DIV_CFG                     SCI_ADDR(CTL_AP_CLK_BASE, 0x0150)
#define REG_AP_CLK_CGM_UFS_RX_1_SEL_CFG                     SCI_ADDR(CTL_AP_CLK_BASE, 0x0154)
#define REG_AP_CLK_CGM_UFS_CFG_DIV_CFG                      SCI_ADDR(CTL_AP_CLK_BASE, 0x015C)
#define REG_AP_CLK_CGM_UFS_CFG_SEL_CFG                      SCI_ADDR(CTL_AP_CLK_BASE, 0x0160)
#define REG_AP_CLK_CGM_BUSY_SRC_MONITOR_CFG0                SCI_ADDR(CTL_AP_CLK_BASE, 0x0164)
#define REG_AP_CLK_CGM_BUSY_SRC_MONITOR_CFG1                SCI_ADDR(CTL_AP_CLK_BASE, 0x0168)
#define REG_AP_CLK_CGM_BUSY_SRC_MONITOR_CFG2                SCI_ADDR(CTL_AP_CLK_BASE, 0x016C)
#define REG_AP_CLK_CGM_BUSY_SRC_MONITOR_CFG3                SCI_ADDR(CTL_AP_CLK_BASE, 0x0170)

/* bits definitions for REG_AP_CLK_CGM_AP_APB_SEL_CFG, [0x20010028] */
#define BIT_AP_CLK_CGM_AP_APB_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_AP_AXI_SEL_CFG, [0x20010034] */
#define BIT_AP_CLK_CGM_AP_AXI_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_AP2EMC_SEL_CFG, [0x20010040] */
#define BIT_AP_CLK_CGM_AP2EMC_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_UART0_DIV_CFG, [0x20010048] */
#define BIT_AP_CLK_CGM_UART0_DIV(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_UART0_SEL_CFG, [0x2001004C] */
#define BIT_AP_CLK_CGM_UART0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UART1_DIV_CFG, [0x20010054] */
#define BIT_AP_CLK_CGM_UART1_DIV(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_UART1_SEL_CFG, [0x20010058] */
#define BIT_AP_CLK_CGM_UART1_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UART2_DIV_CFG, [0x20010060] */
#define BIT_AP_CLK_CGM_UART2_DIV(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_UART2_SEL_CFG, [0x20010064] */
#define BIT_AP_CLK_CGM_UART2_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UART3_DIV_CFG, [0x2001006C] */
#define BIT_AP_CLK_CGM_UART3_DIV(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_UART3_SEL_CFG, [0x20010070] */
#define BIT_AP_CLK_CGM_UART3_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C0_DIV_CFG, [0x20010078] */
#define BIT_AP_CLK_CGM_I2C0_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_I2C0_SEL_CFG, [0x2001007C] */
#define BIT_AP_CLK_CGM_I2C0_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C1_DIV_CFG, [0x20010084] */
#define BIT_AP_CLK_CGM_I2C1_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_I2C1_SEL_CFG, [0x20010088] */
#define BIT_AP_CLK_CGM_I2C1_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C2_DIV_CFG, [0x20010090] */
#define BIT_AP_CLK_CGM_I2C2_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_I2C2_SEL_CFG, [0x20010094] */
#define BIT_AP_CLK_CGM_I2C2_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C3_DIV_CFG, [0x2001009C] */
#define BIT_AP_CLK_CGM_I2C3_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_I2C3_SEL_CFG, [0x200100A0] */
#define BIT_AP_CLK_CGM_I2C3_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C4_DIV_CFG, [0x200100A8] */
#define BIT_AP_CLK_CGM_I2C4_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_I2C4_SEL_CFG, [0x200100AC] */
#define BIT_AP_CLK_CGM_I2C4_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C5_DIV_CFG, [0x200100B4] */
#define BIT_AP_CLK_CGM_I2C5_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_I2C5_SEL_CFG, [0x200100B8] */
#define BIT_AP_CLK_CGM_I2C5_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C6_DIV_CFG, [0x200100C0] */
#define BIT_AP_CLK_CGM_I2C6_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_I2C6_SEL_CFG, [0x200100C4] */
#define BIT_AP_CLK_CGM_I2C6_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C7_DIV_CFG, [0x200100CC] */
#define BIT_AP_CLK_CGM_I2C7_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_I2C7_SEL_CFG, [0x200100D0] */
#define BIT_AP_CLK_CGM_I2C7_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C8_DIV_CFG, [0x200100D8] */
#define BIT_AP_CLK_CGM_I2C8_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_I2C8_SEL_CFG, [0x200100DC] */
#define BIT_AP_CLK_CGM_I2C8_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C9_DIV_CFG, [0x200100E4] */
#define BIT_AP_CLK_CGM_I2C9_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_I2C9_SEL_CFG, [0x200100E8] */
#define BIT_AP_CLK_CGM_I2C9_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_IIS0_DIV_CFG, [0x200100F0] */
#define BIT_AP_CLK_CGM_IIS0_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AP_CLK_CGM_IIS0_SEL_CFG, [0x200100F4] */
#define BIT_AP_CLK_CGM_IIS0_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_IIS1_DIV_CFG, [0x200100FC] */
#define BIT_AP_CLK_CGM_IIS1_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AP_CLK_CGM_IIS1_SEL_CFG, [0x20010100] */
#define BIT_AP_CLK_CGM_IIS1_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_IIS2_DIV_CFG, [0x20010108] */
#define BIT_AP_CLK_CGM_IIS2_DIV(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AP_CLK_CGM_IIS2_SEL_CFG, [0x2001010C] */
#define BIT_AP_CLK_CGM_IIS2_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_CE_SEL_CFG, [0x20010118] */
#define BIT_AP_CLK_CGM_CE_SEL(x)                            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_EMMC_2X_DIV_CFG, [0x20010120] */
#define BIT_AP_CLK_CGM_EMMC_2X_DIV(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_AP_CLK_CGM_EMMC_2X_SEL_CFG, [0x20010124] */
#define BIT_AP_CLK_CGM_EMMC_2X_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_EMMC_1X_DIV_CFG, [0x2001012C] */
#define BIT_AP_CLK_CGM_EMMC_1X_DIV                          ( BIT(0) )

/* bits definitions for REG_AP_CLK_CGM_UFS_TX_DIV_CFG, [0x20010138] */
#define BIT_AP_CLK_CGM_UFS_TX_DIV(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_TX_SEL_CFG, [0x2001013C] */
#define BIT_AP_CLK_CGM_UFS_TX_PAD_SEL                       ( BIT(16) )
#define BIT_AP_CLK_CGM_UFS_TX_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_RX_DIV_CFG, [0x20010144] */
#define BIT_AP_CLK_CGM_UFS_RX_DIV(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_RX_SEL_CFG, [0x20010148] */
#define BIT_AP_CLK_CGM_UFS_RX_PAD_SEL                       ( BIT(16) )
#define BIT_AP_CLK_CGM_UFS_RX_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_RX_1_DIV_CFG, [0x20010150] */
#define BIT_AP_CLK_CGM_UFS_RX_1_DIV(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_RX_1_SEL_CFG, [0x20010154] */
#define BIT_AP_CLK_CGM_UFS_RX_1_PAD_SEL                     ( BIT(16) )
#define BIT_AP_CLK_CGM_UFS_RX_1_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_CFG_DIV_CFG, [0x2001015C] */
#define BIT_AP_CLK_CGM_UFS_CFG_DIV(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_CFG_SEL_CFG, [0x20010160] */
#define BIT_AP_CLK_CGM_UFS_CFG_PAD_SEL                      ( BIT(16) )
#define BIT_AP_CLK_CGM_UFS_CFG_SEL                          ( BIT(0) )

/* bits definitions for REG_AP_CLK_CGM_BUSY_SRC_MONITOR_CFG0, [0x20010164] */
#define BIT_AP_CLK_CGM_BUSY_SRC_MONITOR0(x)                 ( (x) )

/* bits definitions for REG_AP_CLK_CGM_BUSY_SRC_MONITOR_CFG1, [0x20010168] */
#define BIT_AP_CLK_CGM_BUSY_SRC_MONITOR1(x)                 ( (x) )

/* bits definitions for REG_AP_CLK_CGM_BUSY_SRC_MONITOR_CFG2, [0x2001016C] */
#define BIT_AP_CLK_CGM_BUSY_SRC_MONITOR2(x)                 ( (x) )

/* bits definitions for REG_AP_CLK_CGM_BUSY_SRC_MONITOR_CFG3, [0x20010170] */
#define BIT_AP_CLK_CGM_BUSY_SRC_MONITOR3(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* vars definitions for controller CTL_AP_CLK */


#endif /* __AP_CLK_H____ */
