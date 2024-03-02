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

/* registers definitions for CTL_AON_CLK_CORE, 0x402D0200 */
#define REG_AON_CLK_CORE_CGM_EMC_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0020)
#define REG_AON_CLK_CORE_CGM_AON_APB_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0024)
#define REG_AON_CLK_CORE_CGM_ADI_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0028)
#define REG_AON_CLK_CORE_CGM_AUX0_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x002C)
#define REG_AON_CLK_CORE_CGM_AUX1_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0030)
#define REG_AON_CLK_CORE_CGM_AUX2_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0034)
#define REG_AON_CLK_CORE_CGM_PROBE_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0038)
#define REG_AON_CLK_CORE_CGM_PWM0_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x003C)
#define REG_AON_CLK_CORE_CGM_PWM1_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0040)
#define REG_AON_CLK_CORE_CGM_PWM2_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0044)
#define REG_AON_CLK_CORE_CGM_EFUSE_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0048)
#define REG_AON_CLK_CORE_CGM_SP_UART0_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x004C)
#define REG_AON_CLK_CORE_CGM_SP_UART1_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0050)
#define REG_AON_CLK_CORE_CGM_32K_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0054)
#define REG_AON_CLK_CORE_CGM_1K_CFG                         SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0058)
#define REG_AON_CLK_CORE_CGM_THM_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x005C)
#define REG_AON_CLK_CORE_CGM_AUD_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0060)
#define REG_AON_CLK_CORE_CGM_AUDIF_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0064)
#define REG_AON_CLK_CORE_CGM_VBC_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0068)
#define REG_AON_CLK_CORE_CGM_CPU_DAP_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x006C)
#define REG_AON_CLK_CORE_CGM_CPU_DAP_MTCK_CFG               SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0070)
#define REG_AON_CLK_CORE_CGM_CPU_TS_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0074)
#define REG_AON_CLK_CORE_CGM_AUD_IIS_DA0_CFG                SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0078)
#define REG_AON_CLK_CORE_CGM_AUD_IIS0_AD0_CFG               SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x007C)
#define REG_AON_CLK_CORE_CGM_AUD_IIS1_AD0_CFG               SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0080)
#define REG_AON_CLK_CORE_CGM_RTC4M0_REF_CFG                 SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0084)
#define REG_AON_CLK_CORE_CGM_RTC4M0_FDK_CFG                 SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0088)
#define REG_AON_CLK_CORE_CGM_DJTAG_TCK_CFG                  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x008C)
#define REG_AON_CLK_CORE_CGM_SP_AHB_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0090)
#define REG_AON_CLK_CORE_CGM_CA5_TS_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0094)
#define REG_AON_CLK_CORE_CGM_FUNCDMA_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0098)
#define REG_AON_CLK_CORE_CGM_EMC_REF_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x009C)
#define REG_AON_CLK_CORE_CGM_CSSYS_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A0)
#define REG_AON_CLK_CORE_CGM_DET_32K_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A4)
#define REG_AON_CLK_CORE_CGM_PMU_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A8)
#define REG_AON_CLK_CORE_CGM_26M_PMU_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00AC)
#define REG_AON_CLK_CORE_CGM_TMR_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B0)
#define REG_AON_CLK_CORE_CGM_HW_I2C_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B4)
#define REG_AON_CLK_CORE_CGM_SP_I2C0_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B8)
#define REG_AON_CLK_CORE_CGM_SP_I2C1_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00BC)
#define REG_AON_CLK_CORE_CGM_SP_SPI0_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C0)
#define REG_AON_CLK_CORE_CGM_POWER_CPU_CFG                  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C4)
#define REG_AON_CLK_CORE_CGM_AP_AXI_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C8)
#define REG_AON_CLK_CORE_CGM_SDIO0_2X_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00CC)
#define REG_AON_CLK_CORE_CGM_SDIO0_1X_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D0)
#define REG_AON_CLK_CORE_CGM_SDIO1_2X_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D4)
#define REG_AON_CLK_CORE_CGM_SDIO1_1X_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D8)
#define REG_AON_CLK_CORE_CGM_SDIO2_2X_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00DC)
#define REG_AON_CLK_CORE_CGM_SDIO2_1X_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00E0)
#define REG_AON_CLK_CORE_CGM_EMMC_2X_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00E4)
#define REG_AON_CLK_CORE_CGM_EMMC_1X_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00E8)
#define REG_AON_CLK_CORE_CGM_NANDC_2X_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00EC)
#define REG_AON_CLK_CORE_CGM_NANDC_1X_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00F0)
#define REG_AON_CLK_CORE_CGM_DPU_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00F4)
#define REG_AON_CLK_CORE_CGM_DPU_DPI_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00F8)
#define REG_AON_CLK_CORE_CGM_DSI_RXESC_CFG                  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00FC)
#define REG_AON_CLK_CORE_CGM_DSI_LANEBYTE_CFG               SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0100)
#define REG_AON_CLK_CORE_CGM_WCDMA_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0104)
#define REG_AON_CLK_CORE_CGM_OTG_REF_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0108)
#define REG_AON_CLK_CORE_CGM_CPHY_CFG_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x010C)
#define REG_AON_CLK_CORE_CGM_DPHY_REF_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0110)
#define REG_AON_CLK_CORE_CGM_DPHY_CFG_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0114)
#define REG_AON_CLK_CORE_CGM_DSI_TEST_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0118)
#define REG_AON_CLK_CORE_CGM_RFTI_SBI_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x011C)
#define REG_AON_CLK_CORE_CGM_RFTI1_XO_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0120)
#define REG_AON_CLK_CORE_CGM_RFTI_LTH_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0124)
#define REG_AON_CLK_CORE_CGM_RFTI2_XO_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0128)
#define REG_AON_CLK_CORE_CGM_LVDSRF_CALI_CFG                SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x012C)
#define REG_AON_CLK_CORE_CGM_SERDES_DPHY_APB_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0130)
#define REG_AON_CLK_CORE_CGM_SERDES_DPHY_REF_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0134)
#define REG_AON_CLK_CORE_CGM_SERDES_DPHY_CFG_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0138)
#define REG_AON_CLK_CORE_CGM_ANALOG_IO_APB_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x013C)
#define REG_AON_CLK_CORE_CGM_DJTAG_TCK_HW_CFG               SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0140)
#define REG_AON_CLK_CORE_CGM_GPU_CORE_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0144)
#define REG_AON_CLK_CORE_CGM_GPU_SOC_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0148)
#define REG_AON_CLK_CORE_CGM_WCN_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x014C)
#define REG_AON_CLK_CORE_CGM_MM_EMC_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0150)
#define REG_AON_CLK_CORE_CGM_MM_AHB_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0154)
#define REG_AON_CLK_CORE_CGM_BPC_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0158)
#define REG_AON_CLK_CORE_CGM_DCAM_IF_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x015C)
#define REG_AON_CLK_CORE_CGM_ISP_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0160)
#define REG_AON_CLK_CORE_CGM_JPG_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0164)
#define REG_AON_CLK_CORE_CGM_CPP_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0168)
#define REG_AON_CLK_CORE_CGM_SENSOR0_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x016C)
#define REG_AON_CLK_CORE_CGM_SENSOR1_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0170)
#define REG_AON_CLK_CORE_CGM_SENSOR2_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0174)
#define REG_AON_CLK_CORE_CGM_MM_VSP_EMC_CFG                 SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0178)
#define REG_AON_CLK_CORE_CGM_MM_VSP_AHB_CFG                 SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x017C)
#define REG_AON_CLK_CORE_CGM_VSP_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0180)
#define REG_AON_CLK_CORE_CGM_GPU_CORE_FRA_DIV               SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0184)
#define REG_AON_CLK_CORE_CGM_GPU_SOC_FRA_DIV                SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0188)

/* bits definitions for REG_AON_CLK_CORE_CGM_EMC_CFG, [0x402D0220] */
#define BIT_AON_CLK_CORE_CGM_EMC_CFG_CGM_EMC_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AON_APB_CFG, [0x402D0224] */
#define BIT_AON_CLK_CORE_CGM_AON_APB_CFG_CGM_AON_APB_DIV(x)               ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_AON_APB_CFG_CGM_AON_APB_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_ADI_CFG, [0x402D0228] */
#define BIT_AON_CLK_CORE_CGM_ADI_CFG_CGM_ADI_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUX0_CFG, [0x402D022C] */
#define BIT_AON_CLK_CORE_CGM_AUX0_CFG_CGM_AUX0_DIV(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_AUX0_CFG_CGM_AUX0_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUX1_CFG, [0x402D0230] */
#define BIT_AON_CLK_CORE_CGM_AUX1_CFG_CGM_AUX1_DIV(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_AUX1_CFG_CGM_AUX1_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUX2_CFG, [0x402D0234] */
#define BIT_AON_CLK_CORE_CGM_AUX2_CFG_CGM_AUX2_DIV(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_AUX2_CFG_CGM_AUX2_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PROBE_CFG, [0x402D0238] */
#define BIT_AON_CLK_CORE_CGM_PROBE_CFG_CGM_PROBE_DIV(x)                   ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_PROBE_CFG_CGM_PROBE_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM0_CFG, [0x402D023C] */
#define BIT_AON_CLK_CORE_CGM_PWM0_CFG_CGM_PWM0_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM1_CFG, [0x402D0240] */
#define BIT_AON_CLK_CORE_CGM_PWM1_CFG_CGM_PWM1_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM2_CFG, [0x402D0244] */
#define BIT_AON_CLK_CORE_CGM_PWM2_CFG_CGM_PWM2_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_EFUSE_CFG, [0x402D0248] */
#define BIT_AON_CLK_CORE_CGM_EFUSE_CFG_CGM_EFUSE_SEL                      ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SP_UART0_CFG, [0x402D024C] */
#define BIT_AON_CLK_CORE_CGM_SP_UART0_CFG_CGM_SP_UART0_DIV(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CORE_CGM_SP_UART0_CFG_CGM_SP_UART0_SEL(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SP_UART1_CFG, [0x402D0250] */
#define BIT_AON_CLK_CORE_CGM_SP_UART1_CFG_CGM_SP_UART1_DIV(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CORE_CGM_SP_UART1_CFG_CGM_SP_UART1_SEL(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_32K_CFG, [0x402D0254] */

/* bits definitions for REG_AON_CLK_CORE_CGM_1K_CFG, [0x402D0258] */

/* bits definitions for REG_AON_CLK_CORE_CGM_THM_CFG, [0x402D025C] */
#define BIT_AON_CLK_CORE_CGM_THM_CFG_CGM_THM_SEL                          ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUD_CFG, [0x402D0260] */
#define BIT_AON_CLK_CORE_CGM_AUD_CFG_CGM_AUD_SEL                          ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUDIF_CFG, [0x402D0264] */
#define BIT_AON_CLK_CORE_CGM_AUDIF_CFG_CGM_AUDIF_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_VBC_CFG, [0x402D0268] */
#define BIT_AON_CLK_CORE_CGM_VBC_CFG_CGM_VBC_SEL                          ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CPU_DAP_CFG, [0x402D026C] */
#define BIT_AON_CLK_CORE_CGM_CPU_DAP_CFG_CGM_CPU_DAP_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CPU_DAP_MTCK_CFG, [0x402D0270] */

/* bits definitions for REG_AON_CLK_CORE_CGM_CPU_TS_CFG, [0x402D0274] */
#define BIT_AON_CLK_CORE_CGM_CPU_TS_CFG_CGM_CPU_TS_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUD_IIS_DA0_CFG, [0x402D0278] */

/* bits definitions for REG_AON_CLK_CORE_CGM_AUD_IIS0_AD0_CFG, [0x402D027C] */

/* bits definitions for REG_AON_CLK_CORE_CGM_AUD_IIS1_AD0_CFG, [0x402D0280] */

/* bits definitions for REG_AON_CLK_CORE_CGM_RTC4M0_REF_CFG, [0x402D0284] */
#define BIT_AON_CLK_CORE_CGM_RTC4M0_REF_CFG_CGM_RTC4M0_REF_SEL            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RTC4M0_FDK_CFG, [0x402D0288] */
#define BIT_AON_CLK_CORE_CGM_RTC4M0_FDK_CFG_CGM_RTC4M0_FDK_SEL            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DJTAG_TCK_CFG, [0x402D028C] */
#define BIT_AON_CLK_CORE_CGM_DJTAG_TCK_CFG_CGM_DJTAG_TCK_PAD_SEL          ( BIT(16) )
#define BIT_AON_CLK_CORE_CGM_DJTAG_TCK_CFG_CGM_DJTAG_TCK_SEL              ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SP_AHB_CFG, [0x402D0290] */
#define BIT_AON_CLK_CORE_CGM_SP_AHB_CFG_CGM_SP_AHB_DIV(x)                 ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_SP_AHB_CFG_CGM_SP_AHB_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CA5_TS_CFG, [0x402D0294] */
#define BIT_AON_CLK_CORE_CGM_CA5_TS_CFG_CGM_CA5_TS_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_FUNCDMA_CFG, [0x402D0298] */

/* bits definitions for REG_AON_CLK_CORE_CGM_EMC_REF_CFG, [0x402D029C] */
#define BIT_AON_CLK_CORE_CGM_EMC_REF_CFG_CGM_EMC_REF_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CSSYS_CFG, [0x402D02A0] */
#define BIT_AON_CLK_CORE_CGM_CSSYS_CFG_CGM_CSSYS_DIV(x)                   ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_CSSYS_CFG_CGM_CSSYS_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DET_32K_CFG, [0x402D02A4] */
#define BIT_AON_CLK_CORE_CGM_DET_32K_CFG_CGM_DET_32K_SEL                  ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PMU_CFG, [0x402D02A8] */
#define BIT_AON_CLK_CORE_CGM_PMU_CFG_CGM_PMU_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_26M_PMU_CFG, [0x402D02AC] */
#define BIT_AON_CLK_CORE_CGM_26M_PMU_CFG_CGM_26M_PMU_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_TMR_CFG, [0x402D02B0] */
#define BIT_AON_CLK_CORE_CGM_TMR_CFG_CGM_TMR_SEL                          ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_HW_I2C_CFG, [0x402D02B4] */
#define BIT_AON_CLK_CORE_CGM_HW_I2C_CFG_CGM_HW_I2C_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SP_I2C0_CFG, [0x402D02B8] */
#define BIT_AON_CLK_CORE_CGM_SP_I2C0_CFG_CGM_SP_I2C0_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SP_I2C1_CFG, [0x402D02BC] */
#define BIT_AON_CLK_CORE_CGM_SP_I2C1_CFG_CGM_SP_I2C1_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SP_SPI0_CFG, [0x402D02C0] */
#define BIT_AON_CLK_CORE_CGM_SP_SPI0_CFG_CGM_SP_SPI0_PAD_SEL              ( BIT(16) )
#define BIT_AON_CLK_CORE_CGM_SP_SPI0_CFG_CGM_SP_SPI0_DIV(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CORE_CGM_SP_SPI0_CFG_CGM_SP_SPI0_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_POWER_CPU_CFG, [0x402D02C4] */
#define BIT_AON_CLK_CORE_CGM_POWER_CPU_CFG_CGM_POWER_CPU_SEL(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )
/* bits definitions for REG_AON_CLK_CORE_CGM_AP_AXI_CFG, [0x402D02C8] */
#define BIT_AON_CLK_CORE_CGM_AP_AXI_CFG_CGM_AP_AXI_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )
/* bits definitions for REG_AON_CLK_CORE_CGM_SDIO0_2X_CFG, [0x402D02CC] */
#define BIT_AON_CLK_CORE_CGM_SDIO0_2X_CFG_CGM_SDIO0_2X_SEL(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SDIO0_1X_CFG, [0x402D02D0] */

/* bits definitions for REG_AON_CLK_CORE_CGM_SDIO1_2X_CFG, [0x402D02D4] */
#define BIT_AON_CLK_CORE_CGM_SDIO1_2X_CFG_CGM_SDIO1_2X_SEL(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SDIO1_1X_CFG, [0x402D02D8] */

/* bits definitions for REG_AON_CLK_CORE_CGM_SDIO2_2X_CFG, [0x402D02DC] */
#define BIT_AON_CLK_CORE_CGM_SDIO2_2X_CFG_CGM_SDIO2_2X_SEL(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SDIO2_1X_CFG, [0x402D02E0] */

/* bits definitions for REG_AON_CLK_CORE_CGM_EMMC_2X_CFG, [0x402D02E4] */
#define BIT_AON_CLK_CORE_CGM_EMMC_2X_CFG_CGM_EMMC_2X_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_EMMC_1X_CFG, [0x402D02E8] */

/* bits definitions for REG_AON_CLK_CORE_CGM_NANDC_2X_CFG, [0x402D02EC] */
#define BIT_AON_CLK_CORE_CGM_NANDC_2X_CFG_CGM_NANDC_2X_DIV(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_NANDC_2X_CFG_CGM_NANDC_2X_SEL(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_NANDC_1X_CFG, [0x402D02F0] */
#define BIT_AON_CLK_CORE_CGM_NANDC_1X_CFG_CGM_NANDC_1X_DIV                ( BIT(8) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DPU_CFG, [0x402D02F4] */
#define BIT_AON_CLK_CORE_CGM_DPU_CFG_CGM_DPU_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DPU_DPI_CFG, [0x402D02F8] */
#define BIT_AON_CLK_CORE_CGM_DPU_DPI_CFG_CGM_DPU_DPI_DIV(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_DPU_DPI_CFG_CGM_DPU_DPI_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DSI_RXESC_CFG, [0x402D02FC] */

/* bits definitions for REG_AON_CLK_CORE_CGM_DSI_LANEBYTE_CFG, [0x402D0300] */

/* bits definitions for REG_AON_CLK_CORE_CGM_WCDMA_CFG, [0x402D0304] */
#define BIT_AON_CLK_CORE_CGM_WCDMA_CFG_CGM_WCDMA_SEL                      ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_OTG_REF_CFG, [0x402D0308] */
#define BIT_AON_CLK_CORE_CGM_OTG_REF_CFG_CGM_OTG_REF_SEL                  ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CPHY_CFG_CFG, [0x402D030C] */
#define BIT_AON_CLK_CORE_CGM_CPHY_CFG_CFG_CGM_CPHY_CFG_SEL                ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DPHY_REF_CFG, [0x402D0310] */
#define BIT_AON_CLK_CORE_CGM_DPHY_REF_CFG_CGM_DPHY_REF_SEL                ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DPHY_CFG_CFG, [0x402D0314] */
#define BIT_AON_CLK_CORE_CGM_DPHY_CFG_CFG_CGM_DPHY_CFG_SEL                ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DSI_TEST_CFG, [0x402D0318] */

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI_SBI_CFG, [0x402D031C] */
#define BIT_AON_CLK_CORE_CGM_RFTI_SBI_CFG_CGM_RFTI_SBI_SEL(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI1_XO_CFG, [0x402D0320] */
#define BIT_AON_CLK_CORE_CGM_RFTI1_XO_CFG_CGM_RFTI1_XO_SEL                ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI_LTH_CFG, [0x402D0324] */
#define BIT_AON_CLK_CORE_CGM_RFTI_LTH_CFG_CGM_RFTI_LTH_SEL                ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI2_XO_CFG, [0x402D0328] */
#define BIT_AON_CLK_CORE_CGM_RFTI2_XO_CFG_CGM_RFTI2_XO_SEL                ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_LVDSRF_CALI_CFG, [0x402D032C] */
#define BIT_AON_CLK_CORE_CGM_LVDSRF_CALI_CFG_CGM_LVDSRF_CALI_SEL          ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SERDES_DPHY_APB_CFG, [0x402D0330] */
#define BIT_AON_CLK_CORE_CGM_SERDES_DPHY_APB_CFG_CGM_SERDES_DPHY_APB_SEL  ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SERDES_DPHY_REF_CFG, [0x402D0334] */
#define BIT_AON_CLK_CORE_CGM_SERDES_DPHY_REF_CFG_CGM_SERDES_DPHY_REF_SEL  ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SERDES_DPHY_CFG_CFG, [0x402D0338] */
#define BIT_AON_CLK_CORE_CGM_SERDES_DPHY_CFG_CFG_CGM_SERDES_DPHY_CFG_SEL  ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_ANALOG_IO_APB_CFG, [0x402D033C] */
#define BIT_AON_CLK_CORE_CGM_ANALOG_IO_APB_CFG_CGM_ANALOG_IO_APB_DIV(x)   ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_ANALOG_IO_APB_CFG_CGM_ANALOG_IO_APB_SEL(x)   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DJTAG_TCK_HW_CFG, [0x402D0340] */

/* bits definitions for REG_AON_CLK_CORE_CGM_GPU_CORE_CFG, [0x402D0344] */
#define BIT_AON_CLK_CORE_CGM_GPU_CORE_CFG_CGM_GPU_CORE_DIV(x)             ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_GPU_CORE_CFG_CGM_GPU_CORE_SEL(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_GPU_SOC_CFG, [0x402D0348] */
#define BIT_AON_CLK_CORE_CGM_GPU_SOC_CFG_CGM_GPU_SOC_DIV(x)               ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_GPU_SOC_CFG_CGM_GPU_SOC_SEL(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_WCN_CFG, [0x402D034C] */
#define BIT_AON_CLK_CORE_CGM_WCN_CFG_CGM_WCN_DIV(x)                       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CORE_CGM_WCN_CFG_CGM_WCN_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_MM_EMC_CFG, [0x402D0350] */
#define BIT_AON_CLK_CORE_CGM_MM_EMC_CFG_CGM_MM_EMC_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_MM_AHB_CFG, [0x402D0354] */
#define BIT_AON_CLK_CORE_CGM_MM_AHB_CFG_CGM_MM_AHB_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_BPC_CFG, [0x402D0358] */
#define BIT_AON_CLK_CORE_CGM_BPC_CFG_CGM_BPC_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DCAM_IF_CFG, [0x402D035C] */
#define BIT_AON_CLK_CORE_CGM_DCAM_IF_CFG_CGM_DCAM_IF_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_ISP_CFG, [0x402D0360] */
#define BIT_AON_CLK_CORE_CGM_ISP_CFG_CGM_ISP_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_JPG_CFG, [0x402D0364] */
#define BIT_AON_CLK_CORE_CGM_JPG_CFG_CGM_JPG_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CPP_CFG, [0x402D0368] */
#define BIT_AON_CLK_CORE_CGM_CPP_CFG_CGM_CPP_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SENSOR0_CFG, [0x402D036C] */
#define BIT_AON_CLK_CORE_CGM_SENSOR0_CFG_CGM_SENSOR0_DIV(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CORE_CGM_SENSOR0_CFG_CGM_SENSOR0_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SENSOR1_CFG, [0x402D0370] */
#define BIT_AON_CLK_CORE_CGM_SENSOR1_CFG_CGM_SENSOR1_DIV(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CORE_CGM_SENSOR1_CFG_CGM_SENSOR1_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SENSOR2_CFG, [0x402D0374] */
#define BIT_AON_CLK_CORE_CGM_SENSOR2_CFG_CGM_SENSOR2_DIV(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CORE_CGM_SENSOR2_CFG_CGM_SENSOR2_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_MM_VSP_EMC_CFG, [0x402D0378] */
#define BIT_AON_CLK_CORE_CGM_MM_VSP_EMC_CFG_CGM_MM_VSP_EMC_SEL(x)         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_MM_VSP_AHB_CFG, [0x402D037C] */
#define BIT_AON_CLK_CORE_CGM_MM_VSP_AHB_CFG_CGM_MM_VSP_AHB_SEL(x)         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_VSP_CFG, [0x402D0380] */
#define BIT_AON_CLK_CORE_CGM_VSP_CFG_CGM_VSP_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_GPU_CORE_FRA_DIV, [0x402D0384] */
#define BIT_AON_CLK_CORE_CGM_GPU_CORE_FRA_DIV_CGM_GPU_CORE_FRA_DIV(x)     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_GPU_SOC_FRA_DIV, [0x402D0388] */
#define BIT_AON_CLK_CORE_CGM_GPU_SOC_FRA_DIV_CGM_GPU_SOC_FRA_DIV(x)       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* vars definitions for controller CTL_AON_CLK_CORE */


#endif /* __AON_CLK_CORE_H____ */

