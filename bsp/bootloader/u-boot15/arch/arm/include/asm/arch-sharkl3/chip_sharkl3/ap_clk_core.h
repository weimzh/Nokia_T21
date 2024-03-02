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
#define REG_AP_CLK_CORE_CGM_AP_APB_CFG                      SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0020)
#define REG_AP_CLK_CORE_CGM_CE_CFG                          SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0024)
#define REG_AP_CLK_CORE_CGM_NANDC_ECC_CFG                   SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0028)
#define REG_AP_CLK_CORE_CGM_NANDC_26M_CFG                   SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x002C)
#define REG_AP_CLK_CORE_CGM_EMMC_32K_CFG                    SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0030)
#define REG_AP_CLK_CORE_CGM_SDIO0_32K_CFG                   SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0034)
#define REG_AP_CLK_CORE_CGM_SDIO1_32K_CFG                   SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0038)
#define REG_AP_CLK_CORE_CGM_SDIO2_32K_CFG                   SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x003C)
#define REG_AP_CLK_CORE_CGM_OTG_UTMI_CFG                    SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0040)
#define REG_AP_CLK_CORE_CGM_UART0_CFG                       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0044)
#define REG_AP_CLK_CORE_CGM_UART1_CFG                       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0048)
#define REG_AP_CLK_CORE_CGM_UART2_CFG                       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x004C)
#define REG_AP_CLK_CORE_CGM_UART3_CFG                       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0050)
#define REG_AP_CLK_CORE_CGM_UART4_CFG                       SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0054)
#define REG_AP_CLK_CORE_CGM_I2C0_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0058)
#define REG_AP_CLK_CORE_CGM_I2C1_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x005C)
#define REG_AP_CLK_CORE_CGM_I2C2_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0060)
#define REG_AP_CLK_CORE_CGM_I2C3_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0064)
#define REG_AP_CLK_CORE_CGM_I2C4_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0068)
#define REG_AP_CLK_CORE_CGM_I2C5_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x006C)
#define REG_AP_CLK_CORE_CGM_I2C6_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0070)
#define REG_AP_CLK_CORE_CGM_SPI0_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0074)
#define REG_AP_CLK_CORE_CGM_SPI1_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0078)
#define REG_AP_CLK_CORE_CGM_SPI2_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x007C)
#define REG_AP_CLK_CORE_CGM_SPI3_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0080)
#define REG_AP_CLK_CORE_CGM_IIS0_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0084)
#define REG_AP_CLK_CORE_CGM_IIS1_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0088)
#define REG_AP_CLK_CORE_CGM_IIS2_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x008C)
#define REG_AP_CLK_CORE_CGM_SIM0_CFG                        SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0090)
#define REG_AP_CLK_CORE_CGM_SIM0_32K_CFG                    SCI_ADDR(CTL_AP_CLK_CORE_BASE, 0x0094)

/* bits definitions for REG_AP_CLK_CORE_CGM_AP_APB_CFG, [0x21500020] */
#define BIT_AP_CLK_CORE_CGM_AP_APB_CFG_CGM_AP_APB_SEL(x)        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_CE_CFG, [0x21500024] */
#define BIT_AP_CLK_CORE_CGM_CE_CFG_CGM_CE_DIV(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_CE_CFG_CGM_CE_SEL                   ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_NANDC_ECC_CFG, [0x21500028] */
#define BIT_AP_CLK_CORE_CGM_NANDC_ECC_CFG_CGM_NANDC_ECC_DIV(x)  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_NANDC_ECC_CFG_CGM_NANDC_ECC_SEL(x)  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_NANDC_26M_CFG, [0x2150002C] */
#define BIT_AP_CLK_CORE_CGM_NANDC_26M_CFG_CGM_NANDC_26M_SEL     ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_EMMC_32K_CFG, [0x21500030] */
#define BIT_AP_CLK_CORE_CGM_EMMC_32K_CFG_CGM_EMMC_32K_SEL       ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SDIO0_32K_CFG, [0x21500034] */
#define BIT_AP_CLK_CORE_CGM_SDIO0_32K_CFG_CGM_SDIO0_32K_SEL     ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SDIO1_32K_CFG, [0x21500038] */
#define BIT_AP_CLK_CORE_CGM_SDIO1_32K_CFG_CGM_SDIO1_32K_SEL     ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SDIO2_32K_CFG, [0x2150003C] */
#define BIT_AP_CLK_CORE_CGM_SDIO2_32K_CFG_CGM_SDIO2_32K_SEL     ( BIT(0) )

/* bits definitions for REG_AP_CLK_CORE_CGM_OTG_UTMI_CFG, [0x21500040] */
#define BIT_AP_CLK_CORE_CGM_OTG_UTMI_CFG_CGM_OTG_UTMI_PAD_SEL   ( BIT(16) )

/* bits definitions for REG_AP_CLK_CORE_CGM_UART0_CFG, [0x21500044] */
#define BIT_AP_CLK_CORE_CGM_UART0_CFG_CGM_UART0_DIV(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_UART0_CFG_CGM_UART0_SEL(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_UART1_CFG, [0x21500048] */
#define BIT_AP_CLK_CORE_CGM_UART1_CFG_CGM_UART1_DIV(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_UART1_CFG_CGM_UART1_SEL(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_UART2_CFG, [0x2150004C] */
#define BIT_AP_CLK_CORE_CGM_UART2_CFG_CGM_UART2_DIV(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_UART2_CFG_CGM_UART2_SEL(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_UART3_CFG, [0x21500050] */
#define BIT_AP_CLK_CORE_CGM_UART3_CFG_CGM_UART3_DIV(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_UART3_CFG_CGM_UART3_SEL(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_UART4_CFG, [0x21500054] */
#define BIT_AP_CLK_CORE_CGM_UART4_CFG_CGM_UART4_DIV(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_UART4_CFG_CGM_UART4_SEL(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C0_CFG, [0x21500058] */
#define BIT_AP_CLK_CORE_CGM_I2C0_CFG_CGM_I2C0_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C0_CFG_CGM_I2C0_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C1_CFG, [0x2150005C] */
#define BIT_AP_CLK_CORE_CGM_I2C1_CFG_CGM_I2C1_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C1_CFG_CGM_I2C1_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C2_CFG, [0x21500060] */
#define BIT_AP_CLK_CORE_CGM_I2C2_CFG_CGM_I2C2_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C2_CFG_CGM_I2C2_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C3_CFG, [0x21500064] */
#define BIT_AP_CLK_CORE_CGM_I2C3_CFG_CGM_I2C3_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C3_CFG_CGM_I2C3_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C4_CFG, [0x21500068] */
#define BIT_AP_CLK_CORE_CGM_I2C4_CFG_CGM_I2C4_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C4_CFG_CGM_I2C4_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C5_CFG, [0x2150006C] */
#define BIT_AP_CLK_CORE_CGM_I2C5_CFG_CGM_I2C5_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C5_CFG_CGM_I2C5_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_I2C6_CFG, [0x21500070] */
#define BIT_AP_CLK_CORE_CGM_I2C6_CFG_CGM_I2C6_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_I2C6_CFG_CGM_I2C6_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SPI0_CFG, [0x21500074] */
#define BIT_AP_CLK_CORE_CGM_SPI0_CFG_CGM_SPI0_PAD_SEL           ( BIT(16) )
#define BIT_AP_CLK_CORE_CGM_SPI0_CFG_CGM_SPI0_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_SPI0_CFG_CGM_SPI0_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SPI1_CFG, [0x21500078] */
#define BIT_AP_CLK_CORE_CGM_SPI1_CFG_CGM_SPI1_PAD_SEL           ( BIT(16) )
#define BIT_AP_CLK_CORE_CGM_SPI1_CFG_CGM_SPI1_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_SPI1_CFG_CGM_SPI1_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SPI2_CFG, [0x2150007C] */
#define BIT_AP_CLK_CORE_CGM_SPI2_CFG_CGM_SPI2_PAD_SEL           ( BIT(16) )
#define BIT_AP_CLK_CORE_CGM_SPI2_CFG_CGM_SPI2_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_SPI2_CFG_CGM_SPI2_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SPI3_CFG, [0x21500080] */
#define BIT_AP_CLK_CORE_CGM_SPI3_CFG_CGM_SPI3_PAD_SEL           ( BIT(16) )
#define BIT_AP_CLK_CORE_CGM_SPI3_CFG_CGM_SPI3_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_SPI3_CFG_CGM_SPI3_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_IIS0_CFG, [0x21500084] */
#define BIT_AP_CLK_CORE_CGM_IIS0_CFG_CGM_IIS0_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AP_CLK_CORE_CGM_IIS0_CFG_CGM_IIS0_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_IIS1_CFG, [0x21500088] */
#define BIT_AP_CLK_CORE_CGM_IIS1_CFG_CGM_IIS1_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AP_CLK_CORE_CGM_IIS1_CFG_CGM_IIS1_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_IIS2_CFG, [0x2150008C] */
#define BIT_AP_CLK_CORE_CGM_IIS2_CFG_CGM_IIS2_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AP_CLK_CORE_CGM_IIS2_CFG_CGM_IIS2_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SIM0_CFG, [0x21500090] */
#define BIT_AP_CLK_CORE_CGM_SIM0_CFG_CGM_SIM0_DIV(x)            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_CLK_CORE_CGM_SIM0_CFG_CGM_SIM0_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_CLK_CORE_CGM_SIM0_32K_CFG, [0x21500094] */
#define BIT_AP_CLK_CORE_CGM_SIM0_32K_CFG_CGM_SIM0_32K_SEL       ( BIT(0) )

/* vars definitions for controller CTL_AP_CLK_CORE */


#endif /* __AP_CLK_CORE_H____ */

