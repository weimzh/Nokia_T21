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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/CLOCK/RTL_0.9/SharkL6_AON_Clock_Control_Register.xls;aon_clk_rf
 *     Revision : 225003
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __AON_CLK_H____
#define __AON_CLK_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AON_CLK_BASE
#define CTL_AON_CLK_BASE                SCI_IOMAP(0x64012000)
#endif

/* registers definitions for CTL_AON_CLK, 0x64012000 */
#define REG_AON_CLK_CGM_AON_APB_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x0020)
#define REG_AON_CLK_CGM_ADI_CFG                             SCI_ADDR(CTL_AON_CLK_BASE, 0x0024)
#define REG_AON_CLK_CGM_AUX0_CFG                            SCI_ADDR(CTL_AON_CLK_BASE, 0x0028)
#define REG_AON_CLK_CGM_AUX1_CFG                            SCI_ADDR(CTL_AON_CLK_BASE, 0x002C)
#define REG_AON_CLK_CGM_AUX2_CFG                            SCI_ADDR(CTL_AON_CLK_BASE, 0x0030)
#define REG_AON_CLK_CGM_PROBE_CFG                           SCI_ADDR(CTL_AON_CLK_BASE, 0x0034)
#define REG_AON_CLK_CGM_PWM0_CFG                            SCI_ADDR(CTL_AON_CLK_BASE, 0x0038)
#define REG_AON_CLK_CGM_PWM1_CFG                            SCI_ADDR(CTL_AON_CLK_BASE, 0x003C)
#define REG_AON_CLK_CGM_PWM2_CFG                            SCI_ADDR(CTL_AON_CLK_BASE, 0x0040)
#define REG_AON_CLK_CGM_PWM3_CFG                            SCI_ADDR(CTL_AON_CLK_BASE, 0x0044)
#define REG_AON_CLK_CGM_EFUSE_CFG                           SCI_ADDR(CTL_AON_CLK_BASE, 0x0048)
#define REG_AON_CLK_CGM_UART0_CFG                           SCI_ADDR(CTL_AON_CLK_BASE, 0x004C)
#define REG_AON_CLK_CGM_UART1_CFG                           SCI_ADDR(CTL_AON_CLK_BASE, 0x0050)
#define REG_AON_CLK_CGM_32K_OUT_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x0054)
#define REG_AON_CLK_CGM_3K2_OUT_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x0058)
#define REG_AON_CLK_CGM_1K_OUT_CFG                          SCI_ADDR(CTL_AON_CLK_BASE, 0x005C)
#define REG_AON_CLK_CGM_THM0_CFG                            SCI_ADDR(CTL_AON_CLK_BASE, 0x0060)
#define REG_AON_CLK_CGM_THM1_CFG                            SCI_ADDR(CTL_AON_CLK_BASE, 0x0064)
#define REG_AON_CLK_CGM_THM2_CFG                            SCI_ADDR(CTL_AON_CLK_BASE, 0x0068)
#define REG_AON_CLK_CGM_CM4_I3C0_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x006C)
#define REG_AON_CLK_CGM_CM4_I3C1_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x0070)
#define REG_AON_CLK_CGM_CM4_SPI_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x0074)
#define REG_AON_CLK_CGM_AON_I2C_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x0078)
#define REG_AON_CLK_CGM_AON_IIS_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x007C)
#define REG_AON_CLK_CGM_SCC_CFG                             SCI_ADDR(CTL_AON_CLK_BASE, 0x0080)
#define REG_AON_CLK_CGM_APCPU_DAP_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x0084)
#define REG_AON_CLK_CGM_APCPU_DAP_MTCK_CFG                  SCI_ADDR(CTL_AON_CLK_BASE, 0x0088)
#define REG_AON_CLK_CGM_APCPU_TS_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x008C)
#define REG_AON_CLK_CGM_DEBUG_TS_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x0090)
#define REG_AON_CLK_CGM_DSI_TEST_S_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x0094)
#define REG_AON_CLK_CGM_RFTI_SBI_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x0098)
#define REG_AON_CLK_CGM_RFTI1_XO_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x009C)
#define REG_AON_CLK_CGM_RFTI_LTH_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00A0)
#define REG_AON_CLK_CGM_RFTI2_XO_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00A4)
#define REG_AON_CLK_CGM_RCO100M_REF_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x00A8)
#define REG_AON_CLK_CGM_RCO100M_FDK_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x00AC)
#define REG_AON_CLK_CGM_DJTAG_TCK_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x00B0)
#define REG_AON_CLK_CGM_DJTAG_TCK_HW_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x00B4)
#define REG_AON_CLK_CGM_SP_AHB_CFG                          SCI_ADDR(CTL_AON_CLK_BASE, 0x00B8)
#define REG_AON_CLK_CGM_TMR_CFG                             SCI_ADDR(CTL_AON_CLK_BASE, 0x00BC)
#define REG_AON_CLK_CGM_DET_32K_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x00C0)
#define REG_AON_CLK_CGM_PMU_CFG                             SCI_ADDR(CTL_AON_CLK_BASE, 0x00C4)
#define REG_AON_CLK_CGM_DEBOUNCE_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00C8)
#define REG_AON_CLK_CGM_APCPU_PMU_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x00CC)
#define REG_AON_CLK_CGM_FUNC_DMA_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00D0)
#define REG_AON_CLK_CGM_TOP_DVFS_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00D4)
#define REG_AON_CLK_CGM_OTG_UTMI_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00D8)
#define REG_AON_CLK_CGM_OTG_REF_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x00DC)
#define REG_AON_CLK_CGM_CSSYS_CFG                           SCI_ADDR(CTL_AON_CLK_BASE, 0x00E0)
#define REG_AON_CLK_CGM_CSSYS_APB_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x00E4)
#define REG_AON_CLK_CGM_AP_AXI_CFG                          SCI_ADDR(CTL_AON_CLK_BASE, 0x00E8)
#define REG_AON_CLK_CGM_AP_MM_CFG                           SCI_ADDR(CTL_AON_CLK_BASE, 0x00EC)
#define REG_AON_CLK_CGM_SDIO2_2X_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00F0)
#define REG_AON_CLK_CGM_SDIO2_1X_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00F4)
#define REG_AON_CLK_CGM_ANALOG_IO_APB_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x00F8)
#define REG_AON_CLK_CGM_DMC_REF_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x00FC)
#define REG_AON_CLK_CGM_USB20_SCAN_ONLY_CFG                 SCI_ADDR(CTL_AON_CLK_BASE, 0x0100)
#define REG_AON_CLK_CGM_EMC_CFG                             SCI_ADDR(CTL_AON_CLK_BASE, 0x0104)
#define REG_AON_CLK_CGM_USB_CFG                             SCI_ADDR(CTL_AON_CLK_BASE, 0x0108)
#define REG_AON_CLK_CGM_AAPC_TEST_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x010C)
#define REG_AON_CLK_CGM_26M_PMU_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x0110)
#define REG_AON_CLK_CGM_CPHY_CFG_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x0114)
#define REG_AON_CLK_CGM_ADI_2ND_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x0118)

/* bits definitions for REG_AON_CLK_CGM_AON_APB_CFG, [0x64012020] */
#define BIT_AON_CLK_CGM_AON_APB_DIV(x)                      ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CGM_AON_APB_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_ADI_CFG, [0x64012024] */
#define BIT_AON_CLK_CGM_ADI_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_AUX0_CFG, [0x64012028] */
#define BIT_AON_CLK_CGM_AUX0_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CGM_AUX0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_CLK_CGM_AUX1_CFG, [0x6401202C] */
#define BIT_AON_CLK_CGM_AUX1_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CGM_AUX1_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_CLK_CGM_AUX2_CFG, [0x64012030] */
#define BIT_AON_CLK_CGM_AUX2_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CGM_AUX2_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_CLK_CGM_PROBE_CFG, [0x64012034] */
#define BIT_AON_CLK_CGM_PROBE_DIV(x)                        ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_CLK_CGM_PROBE_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_CLK_CGM_PWM0_CFG, [0x64012038] */
#define BIT_AON_CLK_CGM_PWM0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_PWM1_CFG, [0x6401203C] */
#define BIT_AON_CLK_CGM_PWM1_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_PWM2_CFG, [0x64012040] */
#define BIT_AON_CLK_CGM_PWM2_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_PWM3_CFG, [0x64012044] */
#define BIT_AON_CLK_CGM_PWM3_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_EFUSE_CFG, [0x64012048] */
#define BIT_AON_CLK_CGM_EFUSE_SEL                           ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_UART0_CFG, [0x6401204C] */
#define BIT_AON_CLK_CGM_UART0_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_UART1_CFG, [0x64012050] */
#define BIT_AON_CLK_CGM_UART1_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_32K_OUT_CFG, [0x64012054] */

/* bits definitions for REG_AON_CLK_CGM_3K2_OUT_CFG, [0x64012058] */

/* bits definitions for REG_AON_CLK_CGM_1K_OUT_CFG, [0x6401205C] */

/* bits definitions for REG_AON_CLK_CGM_THM0_CFG, [0x64012060] */
#define BIT_AON_CLK_CGM_THM0_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_THM1_CFG, [0x64012064] */
#define BIT_AON_CLK_CGM_THM1_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_THM2_CFG, [0x64012068] */
#define BIT_AON_CLK_CGM_THM2_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_CM4_I3C0_CFG, [0x6401206C] */
#define BIT_AON_CLK_CGM_CM4_I3C0_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_CM4_I3C1_CFG, [0x64012070] */
#define BIT_AON_CLK_CGM_CM4_I3C1_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_CM4_SPI_CFG, [0x64012074] */
#define BIT_AON_CLK_CGM_CM4_SPI_PAD_SEL                     ( BIT(16) )
#define BIT_AON_CLK_CGM_CM4_SPI_DIV(x)                      ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CGM_CM4_SPI_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_AON_I2C_CFG, [0x64012078] */
#define BIT_AON_CLK_CGM_AON_I2C_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_AON_IIS_CFG, [0x6401207C] */
#define BIT_AON_CLK_CGM_AON_IIS_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_SCC_CFG, [0x64012080] */
#define BIT_AON_CLK_CGM_SCC_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_APCPU_DAP_CFG, [0x64012084] */
#define BIT_AON_CLK_CGM_APCPU_DAP_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_APCPU_DAP_MTCK_CFG, [0x64012088] */
#define BIT_AON_CLK_CGM_APCPU_DAP_MTCK_PAD_SEL              ( BIT(16) )

/* bits definitions for REG_AON_CLK_CGM_APCPU_TS_CFG, [0x6401208C] */
#define BIT_AON_CLK_CGM_APCPU_TS_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_DEBUG_TS_CFG, [0x64012090] */
#define BIT_AON_CLK_CGM_DEBUG_TS_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_DSI_TEST_S_CFG, [0x64012094] */
#define BIT_AON_CLK_CGM_DSI_TEST_S_PAD_SEL                  ( BIT(16) )

/* bits definitions for REG_AON_CLK_CGM_RFTI_SBI_CFG, [0x64012098] */
#define BIT_AON_CLK_CGM_RFTI_SBI_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_RFTI1_XO_CFG, [0x6401209C] */

/* bits definitions for REG_AON_CLK_CGM_RFTI_LTH_CFG, [0x640120A0] */

/* bits definitions for REG_AON_CLK_CGM_RFTI2_XO_CFG, [0x640120A4] */

/* bits definitions for REG_AON_CLK_CGM_RCO100M_REF_CFG, [0x640120A8] */

/* bits definitions for REG_AON_CLK_CGM_RCO100M_FDK_CFG, [0x640120AC] */

/* bits definitions for REG_AON_CLK_CGM_DJTAG_TCK_CFG, [0x640120B0] */
#define BIT_AON_CLK_CGM_DJTAG_TCK_PAD_SEL                   ( BIT(16) )
#define BIT_AON_CLK_CGM_DJTAG_TCK_SEL                       ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_DJTAG_TCK_HW_CFG, [0x640120B4] */
#define BIT_AON_CLK_CGM_DJTAG_TCK_HW_PAD_SEL                ( BIT(16) )

/* bits definitions for REG_AON_CLK_CGM_SP_AHB_CFG, [0x640120B8] */
#define BIT_AON_CLK_CGM_SP_AHB_DIV(x)                       ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CGM_SP_AHB_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_TMR_CFG, [0x640120BC] */
#define BIT_AON_CLK_CGM_TMR_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_DET_32K_CFG, [0x640120C0] */

/* bits definitions for REG_AON_CLK_CGM_PMU_CFG, [0x640120C4] */
#define BIT_AON_CLK_CGM_PMU_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_DEBOUNCE_CFG, [0x640120C8] */
#define BIT_AON_CLK_CGM_DEBOUNCE_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_APCPU_PMU_CFG, [0x640120CC] */
#define BIT_AON_CLK_CGM_APCPU_PMU_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_FUNC_DMA_CFG, [0x640120D0] */
#define BIT_AON_CLK_CGM_FUNC_DMA_PAD_SEL                    ( BIT(16) )

/* bits definitions for REG_AON_CLK_CGM_TOP_DVFS_CFG, [0x640120D4] */
#define BIT_AON_CLK_CGM_TOP_DVFS_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_OTG_UTMI_CFG, [0x640120D8] */
#define BIT_AON_CLK_CGM_OTG_UTMI_PAD_SEL                    ( BIT(16) )

/* bits definitions for REG_AON_CLK_CGM_OTG_REF_CFG, [0x640120DC] */
#define BIT_AON_CLK_CGM_OTG_REF_SEL                         ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_CSSYS_CFG, [0x640120E0] */
#define BIT_AON_CLK_CGM_CSSYS_DIV(x)                        ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CGM_CSSYS_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_CSSYS_APB_CFG, [0x640120E4] */
#define BIT_AON_CLK_CGM_CSSYS_APB_DIV(x)                    ( (x) << 8  & (BIT(8)|BIT(9)) )

/* bits definitions for REG_AON_CLK_CGM_AP_AXI_CFG, [0x640120E8] */
#define BIT_AON_CLK_CGM_AP_AXI_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_AP_MM_CFG, [0x640120EC] */
#define BIT_AON_CLK_CGM_AP_MM_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_SDIO2_2X_CFG, [0x640120F0] */
#define BIT_AON_CLK_CGM_SDIO2_2X_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_SDIO2_1X_CFG, [0x640120F4] */

/* bits definitions for REG_AON_CLK_CGM_ANALOG_IO_APB_CFG, [0x640120F8] */
#define BIT_AON_CLK_CGM_ANALOG_IO_APB_DIV(x)                ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CGM_ANALOG_IO_APB_SEL                   ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_DMC_REF_CFG, [0x640120FC] */
#define BIT_AON_CLK_CGM_DMC_REF_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_USB20_SCAN_ONLY_CFG, [0x64012100] */

/* bits definitions for REG_AON_CLK_CGM_EMC_CFG, [0x64012104] */
#define BIT_AON_CLK_CGM_EMC_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_USB_CFG, [0x64012108] */
#define BIT_AON_CLK_CGM_USB_PAD_SEL                         ( BIT(16) )
#define BIT_AON_CLK_CGM_USB_DIV(x)                          ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CGM_USB_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_AAPC_TEST_CFG, [0x6401210C] */
#define BIT_AON_CLK_CGM_AAPC_TEST_DIV(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for REG_AON_CLK_CGM_26M_PMU_CFG, [0x64012110] */
#define BIT_AON_CLK_CGM_26M_PMU_SEL                         ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_CPHY_CFG_CFG, [0x64012114] */

/* bits definitions for REG_AON_CLK_CGM_ADI_2ND_CFG, [0x64012118] */
#define BIT_AON_CLK_CGM_ADI_2ND_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* vars definitions for controller CTL_AON_CLK */


#endif /* __AON_CLK_H____ */
