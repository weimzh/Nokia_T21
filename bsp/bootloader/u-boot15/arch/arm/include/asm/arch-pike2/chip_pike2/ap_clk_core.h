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
#define CTL_AP_CLK_CORE_BASE            SCI_IOMAP(0x21500000)
#endif

/* registers definitions for CTL_AP_CLK_CORE, 0x21500000 */
#define REG_AP_CLK_AP_AXI_CFG           SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0020)
#define REG_AP_CLK_AP_AHB_CFG           SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0024)
#define REG_AP_CLK_AP_APB_CFG           SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0028)
#define REG_AP_CLK_GSP_CFG              SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x002C)
#define REG_AP_CLK_DISPC0_CFG           SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0030)
#define REG_AP_CLK_DISPC0_DPI_CFG       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0034)
#define REG_AP_CLK_DSI_RXESC_CFG        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0038)
#define REG_AP_CLK_DSI_LANEBYTE_CFG     SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x003C)
#define REG_AP_CLK_DPHY_REF_CFG         SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0040)
#define REG_AP_CLK_DPHY_CFG_CFG         SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0044)
#define REG_AP_CLK_OTG_REF_CFG          SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0048)
#define REG_AP_CLK_OTG_UTMI_CFG         SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x004C)
#define REG_AP_CLK_UART0_CFG            SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0050)
#define REG_AP_CLK_UART1_CFG            SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0054)
#define REG_AP_CLK_I2C0_CFG             SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0058)
#define REG_AP_CLK_I2C1_CFG             SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x005C)
#define REG_AP_CLK_I2C2_CFG             SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0060)
#define REG_AP_CLK_SPI0_CFG             SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0064)
#define REG_AP_CLK_IIS0_CFG             SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0068)
#define REG_AP_CLK_CE_CFG               SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x006C)
#define REG_AP_CLK_AP_EMMC_32K_CFG      SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0070)
#define REG_AP_CLK_AP_SDIO0_32K_CFG     SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0074)
#define REG_AP_CLK_NANDC_ECC_CFG        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0078)
#define REG_AP_CLK_AP_SIM_32K_CFG       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x007C)
#define REG_AP_CLK_AXI_AP_EMC_CFG       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0080)
#define REG_AP_CLK_AXI_DISPC_EMC_CFG    SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0084)
#define REG_AP_CLK_AXI_GSP_CA7_EMC_CFG  SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0088)

/* bits definitions for REG_AP_CLK_AP_AXI_CFG, [0x21500020] */
#define BIT_AP_CLK_AP_AXI_CFG_AP_AXI_SEL(x)                                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_AP_AHB_CFG, [0x21500024] */
#define BIT_AP_CLK_AP_AHB_CFG_AP_AHB_SEL(x)                                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_AP_APB_CFG, [0x21500028] */
#define BIT_AP_CLK_AP_APB_CFG_AP_APB_SEL(x)                                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_GSP_CFG, [0x2150002C] */
#define BIT_AP_CLK_GSP_CFG_GSP_SEL(x)                                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_DISPC0_CFG, [0x21500030] */
#define BIT_AP_CLK_DISPC0_CFG_DISPC0_SEL(x)                                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_DISPC0_DPI_CFG, [0x21500034] */
#define BIT_AP_CLK_DISPC0_DPI_CFG_DISPC0_DPI_DIV(x)                        ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_CLK_DISPC0_DPI_CFG_DISPC0_DPI_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_DSI_RXESC_CFG, [0x21500038] */
#define BIT_AP_CLK_DSI_RXESC_CFG_DSI_RXESC_PAD_SEL                         ( BIT(16) )

/* bits definitions for REG_AP_CLK_DSI_LANEBYTE_CFG, [0x2150003C] */
#define BIT_AP_CLK_DSI_LANEBYTE_CFG_DSI_LANEBYTE_PAD_SEL                   ( BIT(16) )

/* bits definitions for REG_AP_CLK_DPHY_REF_CFG, [0x21500040] */
#define BIT_AP_CLK_DPHY_REF_CFG_DPHY_REF_SEL                               ( BIT(0) )

/* bits definitions for REG_AP_CLK_DPHY_CFG_CFG, [0x21500044] */
#define BIT_AP_CLK_DPHY_CFG_CFG_DPHY_CFG_SEL                               ( BIT(0) )

/* bits definitions for REG_AP_CLK_OTG_REF_CFG, [0x21500048] */
#define BIT_AP_CLK_OTG_REF_CFG_OTG_REF_SEL                                 ( BIT(0) )

/* bits definitions for REG_AP_CLK_OTG_UTMI_CFG, [0x2150004C] */
#define BIT_AP_CLK_OTG_UTMI_CFG_OTG_UTMI_PAD_SEL                           ( BIT(16) )

/* bits definitions for REG_AP_CLK_UART0_CFG, [0x21500050] */
#define BIT_AP_CLK_UART0_CFG_UART0_DIV(x)                                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_UART0_CFG_UART0_SEL(x)                                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_UART1_CFG, [0x21500054] */
#define BIT_AP_CLK_UART1_CFG_UART1_DIV(x)                                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_UART1_CFG_UART1_SEL(x)                                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_I2C0_CFG, [0x21500058] */
#define BIT_AP_CLK_I2C0_CFG_I2C0_DIV(x)                                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_I2C0_CFG_I2C0_SEL(x)                                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_I2C1_CFG, [0x2150005C] */
#define BIT_AP_CLK_I2C1_CFG_I2C1_DIV(x)                                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_I2C1_CFG_I2C1_SEL(x)                                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_I2C2_CFG, [0x21500060] */
#define BIT_AP_CLK_I2C2_CFG_I2C2_DIV(x)                                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_I2C2_CFG_I2C2_SEL(x)                                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_SPI0_CFG, [0x21500064] */
#define BIT_AP_CLK_SPI0_CFG_SPI0_PAD_SEL                                   ( BIT(16) )
#define BIT_AP_CLK_SPI0_CFG_SPI0_DIV(x)                                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_SPI0_CFG_SPI0_SEL(x)                                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_IIS0_CFG, [0x21500068] */
#define BIT_AP_CLK_IIS0_CFG_IIS0_DIV(x)                                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_IIS0_CFG_IIS0_SEL(x)                                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CE_CFG, [0x2150006C] */
#define BIT_AP_CLK_CE_CFG_CE_SEL(x)                                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_AP_EMMC_32K_CFG, [0x21500070] */
#define BIT_AP_CLK_AP_EMMC_32K_CFG_AP_EMMC_32K_SEL                         ( BIT(0) )

/* bits definitions for REG_AP_CLK_AP_SDIO0_32K_CFG, [0x21500074] */
#define BIT_AP_CLK_AP_SDIO0_32K_CFG_AP_SDIO0_32K_SEL                       ( BIT(0) )

/* bits definitions for REG_AP_CLK_NANDC_ECC_CFG, [0x21500078] */
#define BIT_AP_CLK_NANDC_ECC_CFG_NANDC_ECC_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_AP_SIM_32K_CFG, [0x2150007C] */
#define BIT_AP_CLK_AP_SIM_32K_CFG_AP_SIM_32K_SEL                           ( BIT(0) )

/* bits definitions for REG_AP_CLK_AXI_AP_EMC_CFG, [0x21500080] */

/* bits definitions for REG_AP_CLK_AXI_DISPC_EMC_CFG, [0x21500084] */

/* bits definitions for REG_AP_CLK_AXI_GSP_CA7_EMC_CFG, [0x21500088] */

/* vars definitions for controller CTL_AP_CLK_CORE */


#endif /* __AP_CLK_CORE_H____ */
