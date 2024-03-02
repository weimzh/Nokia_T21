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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/CLOCK/RTL_0.9/SharkL6_AP_Clock_Control_Register.xls;ap_clk_rf
 *     Revision : 225004
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
#define REG_AP_CLK_CGM_AP_APB_CFG                           SCI_ADDR(CTL_AP_CLK_BASE, 0x0020)
#define REG_AP_CLK_CGM_UART0_CFG                            SCI_ADDR(CTL_AP_CLK_BASE, 0x0024)
#define REG_AP_CLK_CGM_UART1_CFG                            SCI_ADDR(CTL_AP_CLK_BASE, 0x0028)
#define REG_AP_CLK_CGM_UART2_CFG                            SCI_ADDR(CTL_AP_CLK_BASE, 0x002C)
#define REG_AP_CLK_CGM_I2C0_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0030)
#define REG_AP_CLK_CGM_I2C1_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0034)
#define REG_AP_CLK_CGM_I2C2_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0038)
#define REG_AP_CLK_CGM_I2C3_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x003C)
#define REG_AP_CLK_CGM_I2C4_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0040)
#define REG_AP_CLK_CGM_I2C5_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0044)
#define REG_AP_CLK_CGM_I2C6_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0048)
#define REG_AP_CLK_CGM_SPI0_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x004C)
#define REG_AP_CLK_CGM_SPI1_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0050)
#define REG_AP_CLK_CGM_SPI2_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0054)
#define REG_AP_CLK_CGM_SPI3_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0058)
#define REG_AP_CLK_CGM_IIS0_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x005C)
#define REG_AP_CLK_CGM_IIS1_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0060)
#define REG_AP_CLK_CGM_IIS2_CFG                             SCI_ADDR(CTL_AP_CLK_BASE, 0x0064)
#define REG_AP_CLK_CGM_SIM_CFG                              SCI_ADDR(CTL_AP_CLK_BASE, 0x0068)
#define REG_AP_CLK_CGM_CE_CFG                               SCI_ADDR(CTL_AP_CLK_BASE, 0x006C)
#define REG_AP_CLK_CGM_AP_SIM_32K_CFG                       SCI_ADDR(CTL_AP_CLK_BASE, 0x0070)
#define REG_AP_CLK_CGM_SDIO0_2X_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0074)
#define REG_AP_CLK_CGM_SDIO0_1X_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0078)
#define REG_AP_CLK_CGM_SDIO1_2X_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x007C)
#define REG_AP_CLK_CGM_SDIO1_1X_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0080)
#define REG_AP_CLK_CGM_EMMC_2X_CFG                          SCI_ADDR(CTL_AP_CLK_BASE, 0x0084)
#define REG_AP_CLK_CGM_EMMC_1X_CFG                          SCI_ADDR(CTL_AP_CLK_BASE, 0x0088)
#define REG_AP_CLK_CGM_UFS_HCK_CFG                          SCI_ADDR(CTL_AP_CLK_BASE, 0x008C)
#define REG_AP_CLK_CGM_UFS_TX_CFG                           SCI_ADDR(CTL_AP_CLK_BASE, 0x0090)
#define REG_AP_CLK_CGM_UFS_RX_CFG                           SCI_ADDR(CTL_AP_CLK_BASE, 0x0094)
#define REG_AP_CLK_CGM_UFS_RX_1_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x0098)
#define REG_AP_CLK_CGM_UFS_PHY_SCAN_ONLY_CFG                SCI_ADDR(CTL_AP_CLK_BASE, 0x009C)
#define REG_AP_CLK_CGM_UFS_PCK_CFG                          SCI_ADDR(CTL_AP_CLK_BASE, 0x00A0)
#define REG_AP_CLK_CGM_UFS_REF_26M_CFG                      SCI_ADDR(CTL_AP_CLK_BASE, 0x00A4)
#define REG_AP_CLK_CGM_UFS_XTAL_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00A8)
#define REG_AP_CLK_CGM_VSP_CFG                              SCI_ADDR(CTL_AP_CLK_BASE, 0x00AC)
#define REG_AP_CLK_CGM_DISPC0_CFG                           SCI_ADDR(CTL_AP_CLK_BASE, 0x00B0)
#define REG_AP_CLK_CGM_DISPC0_DPI_CFG                       SCI_ADDR(CTL_AP_CLK_BASE, 0x00B4)
#define REG_AP_CLK_CGM_DSI_APB_CFG                          SCI_ADDR(CTL_AP_CLK_BASE, 0x00B8)
#define REG_AP_CLK_CGM_DSI_RXESC_CFG                        SCI_ADDR(CTL_AP_CLK_BASE, 0x00BC)
#define REG_AP_CLK_CGM_DSI_LANEBYTE_CFG                     SCI_ADDR(CTL_AP_CLK_BASE, 0x00C0)
#define REG_AP_CLK_CGM_DPHY_REF_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00C4)
#define REG_AP_CLK_CGM_DPHY_CFG_CFG                         SCI_ADDR(CTL_AP_CLK_BASE, 0x00C8)
#define REG_AP_CLK_CGM_DSI_PHY_SCAN_ONLY_CFG                SCI_ADDR(CTL_AP_CLK_BASE, 0x00CC)

/* bits definitions for REG_AP_CLK_CGM_AP_APB_CFG, [0x20010020] */
#define BIT_AP_CLK_CGM_AP_APB_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UART0_CFG, [0x20010024] */
#define BIT_AP_CLK_CGM_UART0_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_UART0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UART1_CFG, [0x20010028] */
#define BIT_AP_CLK_CGM_UART1_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_UART1_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UART2_CFG, [0x2001002C] */
#define BIT_AP_CLK_CGM_UART2_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_UART2_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C0_CFG, [0x20010030] */
#define BIT_AP_CLK_CGM_I2C0_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_I2C0_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C1_CFG, [0x20010034] */
#define BIT_AP_CLK_CGM_I2C1_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_I2C1_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C2_CFG, [0x20010038] */
#define BIT_AP_CLK_CGM_I2C2_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_I2C2_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C3_CFG, [0x2001003C] */
#define BIT_AP_CLK_CGM_I2C3_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_I2C3_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C4_CFG, [0x20010040] */
#define BIT_AP_CLK_CGM_I2C4_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_I2C4_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C5_CFG, [0x20010044] */
#define BIT_AP_CLK_CGM_I2C5_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_I2C5_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_I2C6_CFG, [0x20010048] */
#define BIT_AP_CLK_CGM_I2C6_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_I2C6_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_SPI0_CFG, [0x2001004C] */
#define BIT_AP_CLK_CGM_SPI0_PAD_SEL                         ( BIT(16) )
#define BIT_AP_CLK_CGM_SPI0_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_SPI0_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_SPI1_CFG, [0x20010050] */
#define BIT_AP_CLK_CGM_SPI1_PAD_SEL                         ( BIT(16) )
#define BIT_AP_CLK_CGM_SPI1_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_SPI1_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_SPI2_CFG, [0x20010054] */
#define BIT_AP_CLK_CGM_SPI2_PAD_SEL                         ( BIT(16) )
#define BIT_AP_CLK_CGM_SPI2_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_SPI2_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_SPI3_CFG, [0x20010058] */
#define BIT_AP_CLK_CGM_SPI3_PAD_SEL                         ( BIT(16) )
#define BIT_AP_CLK_CGM_SPI3_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_SPI3_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_IIS0_CFG, [0x2001005C] */
#define BIT_AP_CLK_CGM_IIS0_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AP_CLK_CGM_IIS0_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_IIS1_CFG, [0x20010060] */
#define BIT_AP_CLK_CGM_IIS1_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AP_CLK_CGM_IIS1_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_IIS2_CFG, [0x20010064] */
#define BIT_AP_CLK_CGM_IIS2_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AP_CLK_CGM_IIS2_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_SIM_CFG, [0x20010068] */
#define BIT_AP_CLK_CGM_SIM_DIV(x)                           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CGM_SIM_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_CE_CFG, [0x2001006C] */
#define BIT_AP_CLK_CGM_CE_SEL(x)                            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_AP_SIM_32K_CFG, [0x20010070] */

/* bits definitions for REG_AP_CLK_CGM_SDIO0_2X_CFG, [0x20010074] */
#define BIT_AP_CLK_CGM_SDIO0_2X_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_SDIO0_1X_CFG, [0x20010078] */

/* bits definitions for REG_AP_CLK_CGM_SDIO1_2X_CFG, [0x2001007C] */
#define BIT_AP_CLK_CGM_SDIO1_2X_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_SDIO1_1X_CFG, [0x20010080] */

/* bits definitions for REG_AP_CLK_CGM_EMMC_2X_CFG, [0x20010084] */
#define BIT_AP_CLK_CGM_EMMC_2X_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_EMMC_1X_CFG, [0x20010088] */

/* bits definitions for REG_AP_CLK_CGM_UFS_HCK_CFG, [0x2001008C] */
#define BIT_AP_CLK_CGM_UFS_HCK_DIV(x)                       ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AP_CLK_CGM_UFS_HCK_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_TX_CFG, [0x20010090] */
#define BIT_AP_CLK_CGM_UFS_TX_PAD_SEL                       ( BIT(16) )
#define BIT_AP_CLK_CGM_UFS_TX_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_RX_CFG, [0x20010094] */
#define BIT_AP_CLK_CGM_UFS_RX_PAD_SEL                       ( BIT(16) )
#define BIT_AP_CLK_CGM_UFS_RX_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_RX_1_CFG, [0x20010098] */
#define BIT_AP_CLK_CGM_UFS_RX_1_PAD_SEL                     ( BIT(16) )
#define BIT_AP_CLK_CGM_UFS_RX_1_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_PHY_SCAN_ONLY_CFG, [0x2001009C] */

/* bits definitions for REG_AP_CLK_CGM_UFS_PCK_CFG, [0x200100A0] */
#define BIT_AP_CLK_CGM_UFS_PCK_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_UFS_REF_26M_CFG, [0x200100A4] */

/* bits definitions for REG_AP_CLK_CGM_UFS_XTAL_CFG, [0x200100A8] */

/* bits definitions for REG_AP_CLK_CGM_VSP_CFG, [0x200100AC] */
#define BIT_AP_CLK_CGM_VSP_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_DISPC0_CFG, [0x200100B0] */
#define BIT_AP_CLK_CGM_DISPC0_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_DISPC0_DPI_CFG, [0x200100B4] */
#define BIT_AP_CLK_CGM_DISPC0_DPI_DIV(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_CLK_CGM_DISPC0_DPI_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CGM_DSI_APB_CFG, [0x200100B8] */
#define BIT_AP_CLK_CGM_DSI_APB_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CGM_DSI_RXESC_CFG, [0x200100BC] */
#define BIT_AP_CLK_CGM_DSI_RXESC_PAD_SEL                    ( BIT(16) )

/* bits definitions for REG_AP_CLK_CGM_DSI_LANEBYTE_CFG, [0x200100C0] */
#define BIT_AP_CLK_CGM_DSI_LANEBYTE_PAD_SEL                 ( BIT(16) )

/* bits definitions for REG_AP_CLK_CGM_DPHY_REF_CFG, [0x200100C4] */

/* bits definitions for REG_AP_CLK_CGM_DPHY_CFG_CFG, [0x200100C8] */

/* bits definitions for REG_AP_CLK_CGM_DSI_PHY_SCAN_ONLY_CFG, [0x200100CC] */

/* vars definitions for controller CTL_AP_CLK */


#endif /* __AP_CLK_H____ */
