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
#define CTL_AON_CLK_CORE_BASE           SCI_IOMAP(0x32080200)
#endif

/* registers definitions for CTL_AON_CLK_CORE, 0x32080200 */
#define REG_AON_CLK_CORE_CGM_AON_APB_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0020)
#define REG_AON_CLK_CORE_CGM_ADI_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0024)
#define REG_AON_CLK_CORE_CGM_AUX0_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0028)
#define REG_AON_CLK_CORE_CGM_AUX1_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x002C)
#define REG_AON_CLK_CORE_CGM_AUX2_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0030)
#define REG_AON_CLK_CORE_CGM_PROBE_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0034)
#define REG_AON_CLK_CORE_CGM_PWM0_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0038)
#define REG_AON_CLK_CORE_CGM_PWM1_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x003C)
#define REG_AON_CLK_CORE_CGM_PWM2_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0040)
#define REG_AON_CLK_CORE_CGM_PWM3_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0044)
#define REG_AON_CLK_CORE_CGM_EFUSE_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0048)
#define REG_AON_CLK_CORE_CGM_UART0_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x004C)
#define REG_AON_CLK_CORE_CGM_UART1_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0050)
#define REG_AON_CLK_CORE_CGM_32K_OUT_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0054)
#define REG_AON_CLK_CORE_CGM_3K2_OUT_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0058)
#define REG_AON_CLK_CORE_CGM_1K_OUT_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x005C)
#define REG_AON_CLK_CORE_CGM_THM0_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0060)
#define REG_AON_CLK_CORE_CGM_THM1_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0064)
#define REG_AON_CLK_CORE_CGM_THM2_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0068)
#define REG_AON_CLK_CORE_CGM_THM3_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x006C)
#define REG_AON_CLK_CORE_CGM_CM4_I3C0_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0070)
#define REG_AON_CLK_CORE_CGM_CM4_I3C1_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0074)
#define REG_AON_CLK_CORE_CGM_CM4_SPI_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0078)
#define REG_AON_CLK_CORE_CGM_AON_I2C_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x007C)
#define REG_AON_CLK_CORE_CGM_AON_IIS_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0080)
#define REG_AON_CLK_CORE_CGM_SCC_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0084)
#define REG_AON_CLK_CORE_CGM_APCPU_DAP_CFG                  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0088)
#define REG_AON_CLK_CORE_CGM_APCPU_DAP_MTCK_CFG             SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x008C)
#define REG_AON_CLK_CORE_CGM_APCPU_TS_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0090)
#define REG_AON_CLK_CORE_CGM_DEBUG_TS_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0094)
#define REG_AON_CLK_CORE_CGM_DSI_TEST_S_CFG                 SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0098)
#define REG_AON_CLK_CORE_CGM_RFTI_SBI_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x009C)
#define REG_AON_CLK_CORE_CGM_RFTI1_XO_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A0)
#define REG_AON_CLK_CORE_CGM_RFTI_LTH_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A4)
#define REG_AON_CLK_CORE_CGM_RFTI2_XO_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A8)
#define REG_AON_CLK_CORE_CGM_RCO100M_REF_CFG                SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00AC)
#define REG_AON_CLK_CORE_CGM_RCO100M_FDK_CFG                SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B0)
#define REG_AON_CLK_CORE_CGM_DJTAG_TCK_CFG                  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B4)
#define REG_AON_CLK_CORE_CGM_DJTAG_TCK_HW_CFG               SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B8)
#define REG_AON_CLK_CORE_CGM_SP_AHB_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00BC)
#define REG_AON_CLK_CORE_CGM_TMR_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C0)
#define REG_AON_CLK_CORE_CGM_DET_32K_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C4)
#define REG_AON_CLK_CORE_CGM_PMU_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C8)
#define REG_AON_CLK_CORE_CGM_DEBOUNCE_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00CC)
#define REG_AON_CLK_CORE_CGM_APCPU_PMU_CFG                  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D0)
#define REG_AON_CLK_CORE_CGM_FUNC_DMA_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D4)
#define REG_AON_CLK_CORE_CGM_TOP_DVFS_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D8)
#define REG_AON_CLK_CORE_CGM_OTG_UTMI_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00DC)
#define REG_AON_CLK_CORE_CGM_OTG_REF_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00E0)
#define REG_AON_CLK_CORE_CGM_CSSYS_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00E4)
#define REG_AON_CLK_CORE_CGM_CSSYS_PUB_CFG                  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00E8)
#define REG_AON_CLK_CORE_CGM_CSSYS_APB_CFG                  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00EC)
#define REG_AON_CLK_CORE_CGM_AP_AXI_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00F0)
#define REG_AON_CLK_CORE_CGM_AP_MM_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00F4)
#define REG_AON_CLK_CORE_CGM_SDIO2_2X_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00F8)
#define REG_AON_CLK_CORE_CGM_SDIO2_1X_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00FC)
#define REG_AON_CLK_CORE_CGM_ANALOG_IO_APB_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0100)
#define REG_AON_CLK_CORE_CGM_DMC_REF_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0104)
#define REG_AON_CLK_CORE_CGM_USB20_SCAN_ONLY_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0108)
#define REG_AON_CLK_CORE_CGM_EMC_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x010C)
#define REG_AON_CLK_CORE_CGM_USB_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0110)
#define REG_AON_CLK_CORE_CGM_AAPC_TEST_CFG                  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0114)
#define REG_AON_CLK_CORE_CGM_26M_PMU_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0118)
#define REG_AON_CLK_CORE_CGM_CPHY_CFG_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x011C)
#define REG_AON_CLK_CORE_CGM_CSI_PHY_SCAN_ONLY_CFG          SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0120)
#define REG_AON_CLK_CORE_CGM_WCDMA_SLICE_SCAN_ONLY_CFG      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0124)
#define REG_AON_CLK_CORE_CGM_26M_ETC_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0128)

/* bits definitions for REG_AON_CLK_CORE_CGM_AON_APB_CFG, [0x32080220] */
#define BIT_AON_CLK_CORE_CGM_AON_APB_CFG_CGM_AON_APB_DIV(x)                           ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_AON_APB_CFG_CGM_AON_APB_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_ADI_CFG, [0x32080224] */
#define BIT_AON_CLK_CORE_CGM_ADI_CFG_CGM_ADI_SEL(x)                                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUX0_CFG, [0x32080228] */
#define BIT_AON_CLK_CORE_CGM_AUX0_CFG_CGM_AUX0_DIV(x)                                 ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_AUX0_CFG_CGM_AUX0_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUX1_CFG, [0x3208022C] */
#define BIT_AON_CLK_CORE_CGM_AUX1_CFG_CGM_AUX1_DIV(x)                                 ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_AUX1_CFG_CGM_AUX1_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUX2_CFG, [0x32080230] */
#define BIT_AON_CLK_CORE_CGM_AUX2_CFG_CGM_AUX2_DIV(x)                                 ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_AUX2_CFG_CGM_AUX2_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PROBE_CFG, [0x32080234] */
#define BIT_AON_CLK_CORE_CGM_PROBE_CFG_CGM_PROBE_DIV(x)                               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_PROBE_CFG_CGM_PROBE_SEL(x)                               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM0_CFG, [0x32080238] */
#define BIT_AON_CLK_CORE_CGM_PWM0_CFG_CGM_PWM0_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM1_CFG, [0x3208023C] */
#define BIT_AON_CLK_CORE_CGM_PWM1_CFG_CGM_PWM1_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM2_CFG, [0x32080240] */
#define BIT_AON_CLK_CORE_CGM_PWM2_CFG_CGM_PWM2_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM3_CFG, [0x32080244] */
#define BIT_AON_CLK_CORE_CGM_PWM3_CFG_CGM_PWM3_SEL(x)                                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_EFUSE_CFG, [0x32080248] */
#define BIT_AON_CLK_CORE_CGM_EFUSE_CFG_CGM_EFUSE_SEL                                  ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_UART0_CFG, [0x3208024C] */
#define BIT_AON_CLK_CORE_CGM_UART0_CFG_CGM_UART0_SEL(x)                               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_UART1_CFG, [0x32080250] */
#define BIT_AON_CLK_CORE_CGM_UART1_CFG_CGM_UART1_SEL(x)                               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_32K_OUT_CFG, [0x32080254] */
#define BIT_AON_CLK_CORE_CGM_32K_OUT_CFG_CGM_32K_OUT_SEL                              ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_3K2_OUT_CFG, [0x32080258] */

/* bits definitions for REG_AON_CLK_CORE_CGM_1K_OUT_CFG, [0x3208025C] */

/* bits definitions for REG_AON_CLK_CORE_CGM_THM0_CFG, [0x32080260] */
#define BIT_AON_CLK_CORE_CGM_THM0_CFG_CGM_THM0_SEL                                    ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_THM1_CFG, [0x32080264] */
#define BIT_AON_CLK_CORE_CGM_THM1_CFG_CGM_THM1_SEL                                    ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_THM2_CFG, [0x32080268] */
#define BIT_AON_CLK_CORE_CGM_THM2_CFG_CGM_THM2_SEL                                    ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_THM3_CFG, [0x3208026C] */
#define BIT_AON_CLK_CORE_CGM_THM3_CFG_CGM_THM3_SEL                                    ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CM4_I3C0_CFG, [0x32080270] */
#define BIT_AON_CLK_CORE_CGM_CM4_I3C0_CFG_CGM_CM4_I3C0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CM4_I3C1_CFG, [0x32080274] */
#define BIT_AON_CLK_CORE_CGM_CM4_I3C1_CFG_CGM_CM4_I3C1_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CM4_SPI_CFG, [0x32080278] */
#define BIT_AON_CLK_CORE_CGM_CM4_SPI_CFG_CGM_CM4_SPI_PAD_SEL                          ( BIT(16) )
#define BIT_AON_CLK_CORE_CGM_CM4_SPI_CFG_CGM_CM4_SPI_DIV(x)                           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CORE_CGM_CM4_SPI_CFG_CGM_CM4_SPI_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AON_I2C_CFG, [0x3208027C] */
#define BIT_AON_CLK_CORE_CGM_AON_I2C_CFG_CGM_AON_I2C_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AON_IIS_CFG, [0x32080280] */
#define BIT_AON_CLK_CORE_CGM_AON_IIS_CFG_CGM_AON_IIS_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SCC_CFG, [0x32080284] */
#define BIT_AON_CLK_CORE_CGM_SCC_CFG_CGM_SCC_SEL(x)                                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_APCPU_DAP_CFG, [0x32080288] */
#define BIT_AON_CLK_CORE_CGM_APCPU_DAP_CFG_CGM_APCPU_DAP_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_APCPU_DAP_MTCK_CFG, [0x3208028C] */
#define BIT_AON_CLK_CORE_CGM_APCPU_DAP_MTCK_CFG_CGM_APCPU_DAP_MTCK_PAD_SEL            ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_APCPU_TS_CFG, [0x32080290] */
#define BIT_AON_CLK_CORE_CGM_APCPU_TS_CFG_CGM_APCPU_TS_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DEBUG_TS_CFG, [0x32080294] */
#define BIT_AON_CLK_CORE_CGM_DEBUG_TS_CFG_CGM_DEBUG_TS_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DSI_TEST_S_CFG, [0x32080298] */
#define BIT_AON_CLK_CORE_CGM_DSI_TEST_S_CFG_CGM_DSI_TEST_S_PAD_SEL                    ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI_SBI_CFG, [0x3208029C] */
#define BIT_AON_CLK_CORE_CGM_RFTI_SBI_CFG_CGM_RFTI_SBI_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI1_XO_CFG, [0x320802A0] */
#define BIT_AON_CLK_CORE_CGM_RFTI1_XO_CFG_CGM_RFTI1_XO_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI_LTH_CFG, [0x320802A4] */
#define BIT_AON_CLK_CORE_CGM_RFTI_LTH_CFG_CGM_RFTI_LTH_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI2_XO_CFG, [0x320802A8] */
#define BIT_AON_CLK_CORE_CGM_RFTI2_XO_CFG_CGM_RFTI2_XO_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RCO100M_REF_CFG, [0x320802AC] */
#define BIT_AON_CLK_CORE_CGM_RCO100M_REF_CFG_CGM_RCO100M_REF_SEL                      ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RCO100M_FDK_CFG, [0x320802B0] */
#define BIT_AON_CLK_CORE_CGM_RCO100M_FDK_CFG_CGM_RCO100M_FDK_SEL                      ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DJTAG_TCK_CFG, [0x320802B4] */
#define BIT_AON_CLK_CORE_CGM_DJTAG_TCK_CFG_CGM_DJTAG_TCK_PAD_SEL                      ( BIT(16) )
#define BIT_AON_CLK_CORE_CGM_DJTAG_TCK_CFG_CGM_DJTAG_TCK_SEL                          ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DJTAG_TCK_HW_CFG, [0x320802B8] */
#define BIT_AON_CLK_CORE_CGM_DJTAG_TCK_HW_CFG_CGM_DJTAG_TCK_HW_PAD_SEL                ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SP_AHB_CFG, [0x320802BC] */
#define BIT_AON_CLK_CORE_CGM_SP_AHB_CFG_CGM_SP_AHB_DIV(x)                             ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_SP_AHB_CFG_CGM_SP_AHB_SEL(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_TMR_CFG, [0x320802C0] */
#define BIT_AON_CLK_CORE_CGM_TMR_CFG_CGM_TMR_SEL(x)                                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DET_32K_CFG, [0x320802C4] */
#define BIT_AON_CLK_CORE_CGM_DET_32K_CFG_CGM_DET_32K_SEL                              ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PMU_CFG, [0x320802C8] */
#define BIT_AON_CLK_CORE_CGM_PMU_CFG_CGM_PMU_SEL(x)                                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DEBOUNCE_CFG, [0x320802CC] */
#define BIT_AON_CLK_CORE_CGM_DEBOUNCE_CFG_CGM_DEBOUNCE_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_APCPU_PMU_CFG, [0x320802D0] */
#define BIT_AON_CLK_CORE_CGM_APCPU_PMU_CFG_CGM_APCPU_PMU_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_FUNC_DMA_CFG, [0x320802D4] */
#define BIT_AON_CLK_CORE_CGM_FUNC_DMA_CFG_CGM_FUNC_DMA_PAD_SEL                        ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_TOP_DVFS_CFG, [0x320802D8] */
#define BIT_AON_CLK_CORE_CGM_TOP_DVFS_CFG_CGM_TOP_DVFS_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_OTG_UTMI_CFG, [0x320802DC] */
#define BIT_AON_CLK_CORE_CGM_OTG_UTMI_CFG_CGM_OTG_UTMI_PAD_SEL                        ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_OTG_REF_CFG, [0x320802E0] */
#define BIT_AON_CLK_CORE_CGM_OTG_REF_CFG_CGM_OTG_REF_SEL                              ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CSSYS_CFG, [0x320802E4] */
#define BIT_AON_CLK_CORE_CGM_CSSYS_CFG_CGM_CSSYS_DIV(x)                               ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_CSSYS_CFG_CGM_CSSYS_SEL(x)                               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CSSYS_PUB_CFG, [0x320802E8] */
#define BIT_AON_CLK_CORE_CGM_CSSYS_PUB_CFG_CGM_CSSYS_PUB_DIV(x)                       ( (x) << 8  & (BIT(8)|BIT(9)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CSSYS_APB_CFG, [0x320802EC] */
#define BIT_AON_CLK_CORE_CGM_CSSYS_APB_CFG_CGM_CSSYS_APB_DIV(x)                       ( (x) << 8  & (BIT(8)|BIT(9)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AP_AXI_CFG, [0x320802F0] */
#define BIT_AON_CLK_CORE_CGM_AP_AXI_CFG_CGM_AP_AXI_SEL(x)                             ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AP_MM_CFG, [0x320802F4] */
#define BIT_AON_CLK_CORE_CGM_AP_MM_CFG_CGM_AP_MM_SEL(x)                               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SDIO2_2X_CFG, [0x320802F8] */
#define BIT_AON_CLK_CORE_CGM_SDIO2_2X_CFG_CGM_SDIO2_2X_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SDIO2_1X_CFG, [0x320802FC] */

/* bits definitions for REG_AON_CLK_CORE_CGM_ANALOG_IO_APB_CFG, [0x32080300] */
#define BIT_AON_CLK_CORE_CGM_ANALOG_IO_APB_CFG_CGM_ANALOG_IO_APB_DIV(x)               ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_ANALOG_IO_APB_CFG_CGM_ANALOG_IO_APB_SEL                  ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DMC_REF_CFG, [0x32080304] */
#define BIT_AON_CLK_CORE_CGM_DMC_REF_CFG_CGM_DMC_REF_SEL(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_USB20_SCAN_ONLY_CFG, [0x32080308] */
#define BIT_AON_CLK_CORE_CGM_USB20_SCAN_ONLY_CFG_CGM_USB20_SCAN_ONLY_SEL              ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_EMC_CFG, [0x3208030C] */
#define BIT_AON_CLK_CORE_CGM_EMC_CFG_CGM_EMC_SEL(x)                                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_USB_CFG, [0x32080310] */
#define BIT_AON_CLK_CORE_CGM_USB_CFG_CGM_USB_PAD_SEL                                  ( BIT(16) )
#define BIT_AON_CLK_CORE_CGM_USB_CFG_CGM_USB_DIV(x)                                   ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_USB_CFG_CGM_USB_SEL(x)                                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AAPC_TEST_CFG, [0x32080314] */
#define BIT_AON_CLK_CORE_CGM_AAPC_TEST_CFG_CGM_AAPC_TEST_DIV(x)                       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CORE_CGM_AAPC_TEST_CFG_CGM_AAPC_TEST_SEL                          ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_26M_PMU_CFG, [0x32080318] */
#define BIT_AON_CLK_CORE_CGM_26M_PMU_CFG_CGM_26M_PMU_SEL                              ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CPHY_CFG_CFG, [0x3208031C] */
#define BIT_AON_CLK_CORE_CGM_CPHY_CFG_CFG_CGM_CPHY_CFG_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CSI_PHY_SCAN_ONLY_CFG, [0x32080320] */
#define BIT_AON_CLK_CORE_CGM_CSI_PHY_SCAN_ONLY_CFG_CGM_CSI_PHY_SCAN_ONLY_SEL          ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_WCDMA_SLICE_SCAN_ONLY_CFG, [0x32080324] */
#define BIT_AON_CLK_CORE_CGM_WCDMA_SLICE_SCAN_ONLY_CFG_CGM_WCDMA_SLICE_SCAN_ONLY_SEL  ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_26M_ETC_CFG, [0x32080328] */
#define BIT_AON_CLK_CORE_CGM_26M_ETC_CFG_CGM_26M_ETC_SEL                             ( BIT(0) )

/* vars definitions for controller CTL_AON_CLK_CORE */


#endif /* __AON_CLK_CORE_H____ */
