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


#ifndef __AON_CLK_CORE_H____
#define __AON_CLK_CORE_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AON_CLK_CORE_BASE
#define CTL_AON_CLK_CORE_BASE           SCI_IOMAP(0x402D0200)
#endif

#define REG_AON_CLK_EMC_4X_CFG           SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0020)
#define REG_AON_CLK_EMC_2X_CFG           SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0024)
#define REG_AON_CLK_EMC_1X_CFG           SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0028)
#define REG_AON_CLK_PUB_AHB_CFG          SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x002C)
#define REG_AON_CLK_AON_APB_CFG          SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0030)
#define REG_AON_CLK_ADI_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0034)
#define REG_AON_CLK_AUX0_CFG             SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0038)
#define REG_AON_CLK_AUX1_CFG             SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x003C)
#define REG_AON_CLK_AUX2_CFG             SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0040)
#define REG_AON_CLK_PROBE_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0044)
#define REG_AON_CLK_PWM0_CFG             SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0048)
#define REG_AON_CLK_PWM1_CFG             SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x004C)
#define REG_AON_CLK_PWM2_CFG             SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0050)
#define REG_AON_CLK_PWM3_CFG             SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0054)
#define REG_AON_CLK_EFUSE_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0058)
#define REG_AON_CLK_CM4_UART_CFG         SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x005C)
#define REG_AON_CLK_32K_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0060)
#define REG_AON_CLK_1K_CFG               SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0064)
#define REG_AON_CLK_THM_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0068)
#define REG_AON_CLK_I2C_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x006C)
#define REG_AON_CLK_AVS_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0070)
#define REG_AON_CLK_AUD_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0074)
#define REG_AON_CLK_AUDIF_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0078)
#define REG_AON_CLK_VBC_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x007C)
#define REG_AON_CLK_AUD_IIS_DA0_CFG      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0080)
#define REG_AON_CLK_AUD_IIS0_AD0_CFG     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0084)
#define REG_AON_CLK_AUD_IIS1_AD0_CFG     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0088)
#define REG_AON_CLK_CA7_DAP_CFG          SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x008C)
#define REG_AON_CLK_CA7_DAP_MTCK_CFG     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0090)
#define REG_AON_CLK_CA7_TS_CFG           SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0094)
#define REG_AON_CLK_DJTAG_TCK_CFG        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0098)
#define REG_AON_CLK_CM4_AHB_CFG          SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x009C)
#define REG_AON_CLK_CA5_TS_CFG           SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A0)
#define REG_AON_CLK_FUNCDMA_CFG          SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A4)
#define REG_AON_CLK_EMC_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A8)
#define REG_AON_CLK_CSSYS_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00AC)
#define REG_AON_CLK_CSSYS_CA7_CFG        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B0)
#define REG_AON_CLK_DET_32K_CFG          SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B4)
#define REG_AON_CLK_TMR_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B8)
#define REG_AON_CLK_SDIO0_2X_CFG         SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00BC)
#define REG_AON_CLK_SDIO0_1X_CFG         SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C0)
#define REG_AON_CLK_NANDC_2X_CFG         SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C4)
#define REG_AON_CLK_NANDC_1X_CFG         SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C8)
#define REG_AON_CLK_EMMC_2X_CFG          SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00CC)
#define REG_AON_CLK_EMMC_1X_CFG          SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D0)
#define REG_AON_CLK_WCDMA_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D4)
#define REG_AON_CLK_WCN_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D8)
#define REG_AON_CLK_DSI_TEST_CFG         SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00DC)
#define REG_AON_CLK_AP_HS_SPI_CFG        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00E0)
#define REG_AON_CLK_SERDES_DPHY_APB_CFG  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00E4)
#define REG_AON_CLK_SERDES_DPHY_REF_CFG  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00E8)
#define REG_AON_CLK_SERDES_DPHY_CFG_CFG  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00EC)
#define REG_AON_CLK_ANALOG_APB_CFG       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00F0)
#define REG_AON_CLK_IO_APB_CFG           SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00F4)
#define REG_AON_CLK_DJTAG_TCK_HW_CFG     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00F8)

/* bits definitions for REG_AON_CLK_EMC_4X_CFG, [0x402D0220] */
#define BIT_AON_CLK_EMC_4X_CFG_EMC_4X_DIV(x)                                   ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_EMC_4X_CFG_EMC_4X_SEL(x)                                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_EMC_2X_CFG, [0x402D0224] */

/* bits definitions for REG_AON_CLK_EMC_1X_CFG, [0x402D0228] */

/* bits definitions for REG_AON_CLK_PUB_AHB_CFG, [0x402D022C] */
#define BIT_AON_CLK_PUB_AHB_CFG_PUB_AHB_DIV(x)                                 ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_PUB_AHB_CFG_PUB_AHB_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_AON_APB_CFG, [0x402D0230] */
#define BIT_AON_CLK_AON_APB_CFG_AON_APB_DIV(x)                                 ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_AON_APB_CFG_AON_APB_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_ADI_CFG, [0x402D0234] */
#define BIT_AON_CLK_ADI_CFG_ADI_SEL(x)                                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_AUX0_CFG, [0x402D0238] */
#define BIT_AON_CLK_AUX0_CFG_AUX0_SEL(x)                                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_AUX1_CFG, [0x402D023C] */
#define BIT_AON_CLK_AUX1_CFG_AUX1_SEL(x)                                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_AUX2_CFG, [0x402D0240] */
#define BIT_AON_CLK_AUX2_CFG_AUX2_SEL(x)                                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_PROBE_CFG, [0x402D0244] */
#define BIT_AON_CLK_PROBE_CFG_PROBE_SEL(x)                                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_PWM0_CFG, [0x402D0248] */
#define BIT_AON_CLK_PWM0_CFG_PWM0_SEL(x)                                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_PWM1_CFG, [0x402D024C] */
#define BIT_AON_CLK_PWM1_CFG_PWM1_SEL(x)                                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_PWM2_CFG, [0x402D0250] */
#define BIT_AON_CLK_PWM2_CFG_PWM2_SEL(x)                                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_PWM3_CFG, [0x402D0254] */
#define BIT_AON_CLK_PWM3_CFG_PWM3_SEL(x)                                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_EFUSE_CFG, [0x402D0258] */
#define BIT_AON_CLK_EFUSE_CFG_EFUSE_SEL                                        ( BIT(0) )

/* bits definitions for REG_AON_CLK_CM4_UART_CFG, [0x402D025C] */
#define BIT_AON_CLK_CM4_UART_CFG_CM4_UART_SEL(x)                               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_32K_CFG, [0x402D0260] */
#define BIT_AON_CLK_32K_CFG_32K_SEL                                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_1K_CFG, [0x402D0264] */

/* bits definitions for REG_AON_CLK_THM_CFG, [0x402D0268] */
#define BIT_AON_CLK_THM_CFG_THM_SEL                                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_I2C_CFG, [0x402D026C] */
#define BIT_AON_CLK_I2C_CFG_I2C_SEL(x)                                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )   

/* bits definitions for REG_AON_CLK_AVS_CFG, [0x402D0270] */
#define BIT_AON_CLK_AVS_CFG_AVS_SEL(x)                                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_AUD_CFG, [0x402D0274] */
#define BIT_AON_CLK_AUD_CFG_AUD_SEL                                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_AUDIF_CFG, [0x402D0278] */
#define BIT_AON_CLK_AUDIF_CFG_AUDIF_SEL(x)                                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_VBC_CFG, [0x402D027C] */
#define BIT_AON_CLK_VBC_CFG_VBC_SEL                                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_AUD_IIS_DA0_CFG, [0x402D0280] */
#define BIT_AON_CLK_AUD_IIS_DA0_CFG_AUD_IIS_DA0_PAD_SEL                        ( BIT(16) )

/* bits definitions for REG_AON_CLK_AUD_IIS0_AD0_CFG, [0x402D0284] */
#define BIT_AON_CLK_AUD_IIS0_AD0_CFG_AUD_IIS0_AD0_PAD_SEL                      ( BIT(16) )

/* bits definitions for REG_AON_CLK_AUD_IIS1_AD0_CFG, [0x402D0288] */
#define BIT_AON_CLK_AUD_IIS1_AD0_CFG_AUD_IIS1_AD0_PAD_SEL                      ( BIT(16) )

/* bits definitions for REG_AON_CLK_CA7_DAP_CFG, [0x402D028C] */
#define BIT_AON_CLK_CA7_DAP_CFG_CA7_DAP_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CA7_DAP_MTCK_CFG, [0x402D0290] */
#define BIT_AON_CLK_CA7_DAP_MTCK_CFG_CA7_DAP_MTCK_PAD_SEL                      ( BIT(16) )

/* bits definitions for REG_AON_CLK_CA7_TS_CFG, [0x402D0294] */
#define BIT_AON_CLK_CA7_TS_CFG_CA7_TS_SEL(x)                                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_DJTAG_TCK_CFG, [0x402D0298] */
#define BIT_AON_CLK_DJTAG_TCK_CFG_DJTAG_TCK_PAD_SEL                            ( BIT(16) )
#define BIT_AON_CLK_DJTAG_TCK_CFG_DJTAG_TCK_SEL                                ( BIT(0) )

/* bits definitions for REG_AON_CLK_CM4_AHB_CFG, [0x402D029C] */
#define BIT_AON_CLK_CM4_AHB_CFG_CM4_AHB_DIV(x)                                 ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CM4_AHB_CFG_CM4_AHB_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CA5_TS_CFG, [0x402D02A0] */
#define BIT_AON_CLK_CA5_TS_CFG_CA5_TS_SEL(x)                                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_FUNCDMA_CFG, [0x402D02A4] */
#define BIT_AON_CLK_FUNCDMA_CFG_FUNCDMA_PAD_SEL                                ( BIT(16) )

/* bits definitions for REG_AON_CLK_EMC_REF_CFG, [0x402D02A8] */
#define BIT_AON_CLK_EMC_REF_CFG_EMC_REF_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CSSYS_CFG, [0x402D02AC] */
#define BIT_AON_CLK_CSSYS_CFG_CSSYS_DIV(x)                                     ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CSSYS_CFG_CSSYS_SEL(x)                                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CSSYS_CA7_CFG, [0x402D02B0] */
#define BIT_AON_CLK_CSSYS_CA7_CFG_CSSYS_CA7_DIV                                ( BIT(8) )

/* bits definitions for REG_AON_CLK_DET_32K_CFG, [0x402D02B4] */
#define BIT_AON_CLK_DET_32K_CFG_DET_32K_SEL                                    ( BIT(0) )

/* bits definitions for REG_AON_CLK_TMR_CFG, [0x402D02B8] */
#define BIT_AON_CLK_TMR_CFG_TMR_SEL                                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_SDIO0_2X_CFG, [0x402D02BC] */
#define BIT_AON_CLK_SDIO0_2X_CFG_SDIO0_2X_SEL(x)                               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_SDIO0_1X_CFG, [0x402D02C0] */

/* bits definitions for REG_AON_CLK_NANDC_2X_CFG, [0x402D02C4] */
#define BIT_AON_CLK_NANDC_2X_CFG_NANDC_2X_SEL(x)                               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_NANDC_1X_CFG, [0x402D02C8] */

/* bits definitions for REG_AON_CLK_EMMC_2X_CFG, [0x402D02CC] */
#define BIT_AON_CLK_EMMC_2X_CFG_EMMC_2X_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_EMMC_1X_CFG, [0x402D02D0] */

/* bits definitions for REG_AON_CLK_WCDMA_CFG, [0x402D02D4] */
#define BIT_AON_CLK_WCDMA_CFG_WCDMA_SEL                                        ( BIT(0) )

/* bits definitions for REG_AON_CLK_WCN_CFG, [0x402D02D8] */
#define BIT_AON_CLK_WCN_CFG_WCN_DIV(x)                                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_WCN_CFG_WCN_SEL(x)                                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_DSI_TEST_CFG, [0x402D02DC] */
#define BIT_AON_CLK_DSI_TEST_CFG_DSI_TEST_PAD_SEL                              ( BIT(16) )

/* bits definitions for REG_AON_CLK_AP_HS_SPI_CFG, [0x402D02E0] */
#define BIT_AON_CLK_AP_HS_SPI_CFG_AP_HS_SPI_PAD_SEL                            ( BIT(16) )
#define BIT_AON_CLK_AP_HS_SPI_CFG_AP_HS_SPI_DIV(x)                             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_AP_HS_SPI_CFG_AP_HS_SPI_SEL(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_SERDES_DPHY_APB_CFG, [0x402D02E4] */
#define BIT_AON_CLK_SERDES_DPHY_APB_CFG_SERDES_DPHY_APB_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_SERDES_DPHY_REF_CFG, [0x402D02E8] */
#define BIT_AON_CLK_SERDES_DPHY_REF_CFG_SERDES_DPHY_REF_SEL                    ( BIT(0) )

/* bits definitions for REG_AON_CLK_SERDES_DPHY_CFG_CFG, [0x402D02EC] */
#define BIT_AON_CLK_SERDES_DPHY_CFG_CFG_SERDES_DPHY_CFG_SEL                    ( BIT(0) )

/* bits definitions for REG_AON_CLK_ANALOG_APB_CFG, [0x402D02F0] */
#define BIT_AON_CLK_ANALOG_APB_CFG_ANALOG_APB_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_IO_APB_CFG, [0x402D02F4] */
#define BIT_AON_CLK_IO_APB_CFG_IO_APB_DIV(x)                                   ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_IO_APB_CFG_IO_APB_SEL(x)                                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_DJTAG_TCK_HW_CFG, [0x402D02F8] */
#define BIT_AON_CLK_DJTAG_TCK_HW_CFG_DJTAG_TCK_HW_PAD_SEL                      ( BIT(16) )

/* vars definitions for controller CTL_AON_CLK_CORE */


#endif /* __AON_CLK_CORE_H____ */
