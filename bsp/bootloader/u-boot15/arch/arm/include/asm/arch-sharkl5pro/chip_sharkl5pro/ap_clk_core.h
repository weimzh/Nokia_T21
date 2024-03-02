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

#ifndef __AP_CLK_CORE_H____
#define __AP_CLK_CORE_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AP_CLK_CORE_BASE
#define CTL_AP_CLK_CORE_BASE            SCI_IOMAP(0x20200000)
#endif

/* registers definitions for CTL_AP_CLK_CORE, 0x20200000 */
#define REG_AP_CLK_CORE_CGM_AP_APB_CFG                      SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0020)
#define REG_AP_CLK_CORE_CGM_IPI_CFG                         SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0024)
#define REG_AP_CLK_CORE_CGM_UART0_CFG                       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0028)
#define REG_AP_CLK_CORE_CGM_UART1_CFG                       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x002C)
#define REG_AP_CLK_CORE_CGM_UART2_CFG                       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0030)
#define REG_AP_CLK_CORE_CGM_I2C0_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0034)
#define REG_AP_CLK_CORE_CGM_I2C1_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0038)
#define REG_AP_CLK_CORE_CGM_I2C2_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x003C)
#define REG_AP_CLK_CORE_CGM_I2C3_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0040)
#define REG_AP_CLK_CORE_CGM_I2C4_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0044)
#define REG_AP_CLK_CORE_CGM_SPI0_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0048)
#define REG_AP_CLK_CORE_CGM_SPI1_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x004C)
#define REG_AP_CLK_CORE_CGM_SPI2_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0050)
#define REG_AP_CLK_CORE_CGM_SPI3_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0054)
#define REG_AP_CLK_CORE_CGM_IIS0_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0058)
#define REG_AP_CLK_CORE_CGM_IIS1_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x005C)
#define REG_AP_CLK_CORE_CGM_IIS2_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0060)
#define REG_AP_CLK_CORE_CGM_SIM_CFG                         SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0064)
#define REG_AP_CLK_CORE_CGM_CE_CFG                          SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0068)
#define REG_AP_CLK_CORE_CGM_AP_EMMC_32K_CFG                 SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x006C)
#define REG_AP_CLK_CORE_CGM_AP_SDIO0_32K_CFG                SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0070)
#define REG_AP_CLK_CORE_CGM_AP_SDIO1_32K_CFG                SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0074)
#define REG_AP_CLK_CORE_CGM_AP_SDIO2_32K_CFG                SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0078)
#define REG_AP_CLK_CORE_CGM_AP_SIM_32K_CFG                  SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x007C)
#define REG_AP_CLK_CORE_CGM_SDIO0_2X_CFG                    SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0080)
#define REG_AP_CLK_CORE_CGM_SDIO0_1X_CFG                    SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0084)
#define REG_AP_CLK_CORE_CGM_SDIO1_2X_CFG                    SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0088)
#define REG_AP_CLK_CORE_CGM_SDIO1_1X_CFG                    SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x008C)
#define REG_AP_CLK_CORE_CGM_EMMC_2X_CFG                     SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0090)
#define REG_AP_CLK_CORE_CGM_EMMC_1X_CFG                     SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0094)
#define REG_AP_CLK_CORE_CGM_VSP_CFG                         SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0098)
#define REG_AP_CLK_CORE_CGM_DISPC0_CFG                      SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x009C)
#define REG_AP_CLK_CORE_CGM_DISPC0_DPI_CFG                  SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x00A0)
#define REG_AP_CLK_CORE_CGM_DSI_APB_CFG                     SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x00A4)
#define REG_AP_CLK_CORE_CGM_DSI_RXESC_CFG                   SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x00A8)
#define REG_AP_CLK_CORE_CGM_DSI_LANEBYTE_CFG                SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x00AC)
#define REG_AP_CLK_CORE_CGM_VDSP_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x00B0)
#define REG_AP_CLK_CORE_CGM_VDSP_M_CFG                      SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x00B4)
#define REG_AP_CLK_CORE_CGM_DPHY_REF_CFG                    SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x00B8)
#define REG_AP_CLK_CORE_CGM_DPHY_CFG_CFG                    SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x00BC)
#define REG_AP_CLK_CORE_CGM_DSI_PHY_SCAN_ONLY_CFG           SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x00C0)

/* bits definitions for REG_AP_CLK_CORE_CGM_AP_APB_CFG, [0x20200020] */
#define BIT_AP_CLK_CORE_CGM_AP_APB_CFG_CGM_AP_APB_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_IPI_CFG, [0x20200024] */
#define BIT_AP_CLK_CORE_CGM_IPI_CFG_CGM_IPI_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_UART0_CFG, [0x20200028] */
#define BIT_AP_CLK_CORE_CGM_UART0_CFG_CGM_UART0_DIV(x)                       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_UART0_CFG_CGM_UART0_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_UART1_CFG, [0x2020002C] */
#define BIT_AP_CLK_CORE_CGM_UART1_CFG_CGM_UART1_DIV(x)                       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_UART1_CFG_CGM_UART1_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_UART2_CFG, [0x20200030] */
#define BIT_AP_CLK_CORE_CGM_UART2_CFG_CGM_UART2_DIV(x)                       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_UART2_CFG_CGM_UART2_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C0_CFG, [0x20200034] */
#define BIT_AP_CLK_CORE_CGM_I2C0_CFG_CGM_I2C0_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C0_CFG_CGM_I2C0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C1_CFG, [0x20200038] */
#define BIT_AP_CLK_CORE_CGM_I2C1_CFG_CGM_I2C1_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C1_CFG_CGM_I2C1_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C2_CFG, [0x2020003C] */
#define BIT_AP_CLK_CORE_CGM_I2C2_CFG_CGM_I2C2_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C2_CFG_CGM_I2C2_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C3_CFG, [0x20200040] */
#define BIT_AP_CLK_CORE_CGM_I2C3_CFG_CGM_I2C3_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C3_CFG_CGM_I2C3_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C4_CFG, [0x20200044] */
#define BIT_AP_CLK_CORE_CGM_I2C4_CFG_CGM_I2C4_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C4_CFG_CGM_I2C4_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SPI0_CFG, [0x20200048] */
#define BIT_AP_CLK_CORE_CGM_SPI0_CFG_CGM_SPI0_PAD_SEL                        ( BIT(16) )
#define BIT_AP_CLK_CORE_CGM_SPI0_CFG_CGM_SPI0_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_SPI0_CFG_CGM_SPI0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SPI1_CFG, [0x2020004C] */
#define BIT_AP_CLK_CORE_CGM_SPI1_CFG_CGM_SPI1_PAD_SEL                        ( BIT(16) )
#define BIT_AP_CLK_CORE_CGM_SPI1_CFG_CGM_SPI1_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_SPI1_CFG_CGM_SPI1_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SPI2_CFG, [0x20200050] */
#define BIT_AP_CLK_CORE_CGM_SPI2_CFG_CGM_SPI2_PAD_SEL                        ( BIT(16) )
#define BIT_AP_CLK_CORE_CGM_SPI2_CFG_CGM_SPI2_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_SPI2_CFG_CGM_SPI2_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SPI3_CFG, [0x20200054] */
#define BIT_AP_CLK_CORE_CGM_SPI3_CFG_CGM_SPI3_PAD_SEL                        ( BIT(16) )
#define BIT_AP_CLK_CORE_CGM_SPI3_CFG_CGM_SPI3_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_SPI3_CFG_CGM_SPI3_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_IIS0_CFG, [0x20200058] */
#define BIT_AP_CLK_CORE_CGM_IIS0_CFG_CGM_IIS0_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AP_CLK_CORE_CGM_IIS0_CFG_CGM_IIS0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_IIS1_CFG, [0x2020005C] */
#define BIT_AP_CLK_CORE_CGM_IIS1_CFG_CGM_IIS1_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AP_CLK_CORE_CGM_IIS1_CFG_CGM_IIS1_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_IIS2_CFG, [0x20200060] */
#define BIT_AP_CLK_CORE_CGM_IIS2_CFG_CGM_IIS2_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AP_CLK_CORE_CGM_IIS2_CFG_CGM_IIS2_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SIM_CFG, [0x20200064] */
#define BIT_AP_CLK_CORE_CGM_SIM_CFG_CGM_SIM_DIV(x)                           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_SIM_CFG_CGM_SIM_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_CE_CFG, [0x20200068] */
#define BIT_AP_CLK_CORE_CGM_CE_CFG_CGM_CE_SEL(x)                             ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_AP_EMMC_32K_CFG, [0x2020006C] */
#define BIT_AP_CLK_CORE_CGM_AP_EMMC_32K_CFG_CGM_AP_EMMC_32K_SEL              ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_AP_SDIO0_32K_CFG, [0x20200070] */
#define BIT_AP_CLK_CORE_CGM_AP_SDIO0_32K_CFG_CGM_AP_SDIO0_32K_SEL            ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_AP_SDIO1_32K_CFG, [0x20200074] */
#define BIT_AP_CLK_CORE_CGM_AP_SDIO1_32K_CFG_CGM_AP_SDIO1_32K_SEL            ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_AP_SDIO2_32K_CFG, [0x20200078] */
#define BIT_AP_CLK_CORE_CGM_AP_SDIO2_32K_CFG_CGM_AP_SDIO2_32K_SEL            ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_AP_SIM_32K_CFG, [0x2020007C] */
#define BIT_AP_CLK_CORE_CGM_AP_SIM_32K_CFG_CGM_AP_SIM_32K_SEL                ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SDIO0_2X_CFG, [0x20200080] */
#define BIT_AP_CLK_CORE_CGM_SDIO0_2X_CFG_CGM_SDIO0_2X_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SDIO0_1X_CFG, [0x20200084] */

/* bits definitions for REG_AP_CLK_CORE_CGM_SDIO1_2X_CFG, [0x20200088] */
#define BIT_AP_CLK_CORE_CGM_SDIO1_2X_CFG_CGM_SDIO1_2X_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SDIO1_1X_CFG, [0x2020008C] */

/* bits definitions for REG_AP_CLK_CORE_CGM_EMMC_2X_CFG, [0x20200090] */
#define BIT_AP_CLK_CORE_CGM_EMMC_2X_CFG_CGM_EMMC_2X_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_EMMC_1X_CFG, [0x20200094] */

/* bits definitions for REG_AP_CLK_CORE_CGM_VSP_CFG, [0x20200098] */
#define BIT_AP_CLK_CORE_CGM_VSP_CFG_CGM_VSP_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_DISPC0_CFG, [0x2020009C] */
#define BIT_AP_CLK_CORE_CGM_DISPC0_CFG_CGM_DISPC0_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_DISPC0_DPI_CFG, [0x202000A0] */
#define BIT_AP_CLK_CORE_CGM_DISPC0_DPI_CFG_CGM_DISPC0_DPI_DIV(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_CLK_CORE_CGM_DISPC0_DPI_CFG_CGM_DISPC0_DPI_SEL(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_DSI_APB_CFG, [0x202000A4] */
#define BIT_AP_CLK_CORE_CGM_DSI_APB_CFG_CGM_DSI_APB_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_DSI_RXESC_CFG, [0x202000A8] */
#define BIT_AP_CLK_CORE_CGM_DSI_RXESC_CFG_CGM_DSI_RXESC_PAD_SEL              ( BIT(16) )

/* bits definitions for REG_AP_CLK_CORE_CGM_DSI_LANEBYTE_CFG, [0x202000AC] */
#define BIT_AP_CLK_CORE_CGM_DSI_LANEBYTE_CFG_CGM_DSI_LANEBYTE_PAD_SEL        ( BIT(16) )

/* bits definitions for REG_AP_CLK_CORE_CGM_VDSP_CFG, [0x202000B0] */
#define BIT_AP_CLK_CORE_CGM_VDSP_CFG_CGM_VDSP_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_VDSP_M_CFG, [0x202000B4] */
#define BIT_AP_CLK_CORE_CGM_VDSP_M_CFG_CGM_VDSP_M_DIV(x)                     ( (x) << 8  & (BIT(8)|BIT(9)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_DPHY_REF_CFG, [0x202000B8] */
#define BIT_AP_CLK_CORE_CGM_DPHY_REF_CFG_CGM_DPHY_REF_SEL                    ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_DPHY_CFG_CFG, [0x202000BC] */
#define BIT_AP_CLK_CORE_CGM_DPHY_CFG_CFG_CGM_DPHY_CFG_SEL                    ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_DSI_PHY_SCAN_ONLY_CFG, [0x202000C0] */
#define BIT_AP_CLK_CORE_CGM_DSI_PHY_SCAN_ONLY_CFG_CGM_DSI_PHY_SCAN_ONLY_SEL  ( BIT(0) )

/* vars definitions for controller CTL_AP_CLK_CORE */


#endif /* __AP_CLK_CORE_H____ */
