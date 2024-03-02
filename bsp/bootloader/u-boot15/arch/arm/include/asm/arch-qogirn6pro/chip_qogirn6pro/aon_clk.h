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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/aon/aon_clk_rf.xls;aon_clk_rf
 *     Revision : 231409
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
#define CTL_AON_CLK_BASE                SCI_IOMAP(0x64920000)
#endif

/* registers definitions for CTL_AON_CLK, 0x64920000 */
#define REG_AON_CLK_CGM_AON_APB_DIV_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0024)
#define REG_AON_CLK_CGM_AON_APB_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0028)
#define REG_AON_CLK_CGM_ADI_SEL_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x0034)
#define REG_AON_CLK_CGM_PWM0_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x0040)
#define REG_AON_CLK_CGM_PWM1_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x004C)
#define REG_AON_CLK_CGM_PWM2_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x0058)
#define REG_AON_CLK_CGM_PWM3_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x0064)
#define REG_AON_CLK_CGM_EFUSE_SEL_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x0070)
#define REG_AON_CLK_CGM_UART0_SEL_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x007C)
#define REG_AON_CLK_CGM_UART1_SEL_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x0088)
#define REG_AON_CLK_CGM_UART2_SEL_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x0094)
#define REG_AON_CLK_CGM_THM0_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00C4)
#define REG_AON_CLK_CGM_THM1_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00D0)
#define REG_AON_CLK_CGM_THM2_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00DC)
#define REG_AON_CLK_CGM_THM3_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x00E8)
#define REG_AON_CLK_CGM_CH_I3C0_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x00F4)
#define REG_AON_CLK_CGM_CH_I3C1_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0100)
#define REG_AON_CLK_CGM_CH_SPI_DIV_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x0108)
#define REG_AON_CLK_CGM_CH_SPI_SEL_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x010C)
#define REG_AON_CLK_CGM_AON_IIS_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0118)
#define REG_AON_CLK_CGM_SCC_SEL_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x0124)
#define REG_AON_CLK_CGM_APCPU_DAP_SEL_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x0130)
#define REG_AON_CLK_CGM_APCPU_TS_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x013C)
#define REG_AON_CLK_CGM_DEBUG_TS_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x0148)
#define REG_AON_CLK_CGM_PRI_SBI_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0154)
#define REG_AON_CLK_CGM_XO_SEL_CFG                          SCI_ADDR(CTL_AON_CLK_BASE, 0x0160)
#define REG_AON_CLK_CGM_RFTI_LTH_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x016C)
#define REG_AON_CLK_CGM_AFC_LTH_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0178)
#define REG_AON_CLK_CGM_RCO100M_FDK_DIV_CFG                 SCI_ADDR(CTL_AON_CLK_BASE, 0x018C)
#define REG_AON_CLK_CGM_RCO60M_FDK_DIV_CFG                  SCI_ADDR(CTL_AON_CLK_BASE, 0x01A4)
#define REG_AON_CLK_CGM_RCO6M_REF_DIV_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x01B0)
#define REG_AON_CLK_CGM_RCO6M_REF_SEL_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x01B4)
#define REG_AON_CLK_CGM_RCO6M_FDK_DIV_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x01BC)
#define REG_AON_CLK_CGM_DJTAG_TCK_SEL_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x01CC)
#define REG_AON_CLK_CGM_SP_AHB_DIV_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x01D4)
#define REG_AON_CLK_CGM_SP_AHB_SEL_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x01D8)
#define REG_AON_CLK_CGM_CH_AHB_DIV_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x01E0)
#define REG_AON_CLK_CGM_CH_AHB_SEL_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x01E4)
#define REG_AON_CLK_CGM_TMR_SEL_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x01F0)
#define REG_AON_CLK_CGM_PMU_SEL_CFG                         SCI_ADDR(CTL_AON_CLK_BASE, 0x0208)
#define REG_AON_CLK_CGM_DEBOUNCE_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x0214)
#define REG_AON_CLK_CGM_APCPU_PMU_SEL_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x0220)
#define REG_AON_CLK_CGM_TOP_DVFS_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x022C)
#define REG_AON_CLK_CGM_PMU_26M_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0238)
#define REG_AON_CLK_CGM_TZPC_DIV_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x0240)
#define REG_AON_CLK_CGM_TZPC_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x0244)
#define REG_AON_CLK_CGM_OTG_REF_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0250)
#define REG_AON_CLK_CGM_CSSYS_DIV_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x0258)
#define REG_AON_CLK_CGM_CSSYS_SEL_CFG                       SCI_ADDR(CTL_AON_CLK_BASE, 0x025C)
#define REG_AON_CLK_CGM_CSSYS_APB_DIV_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x0264)
#define REG_AON_CLK_CGM_SDIO0_2X_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x0270)
#define REG_AON_CLK_CGM_SDIO0_2X_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x0274)
#define REG_AON_CLK_CGM_SDIO0_1X_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x027C)
#define REG_AON_CLK_CGM_SDIO1_2X_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x0288)
#define REG_AON_CLK_CGM_SDIO1_2X_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x028C)
#define REG_AON_CLK_CGM_SDIO1_1X_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x0294)
#define REG_AON_CLK_CGM_SDIO2_2X_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x02A0)
#define REG_AON_CLK_CGM_SDIO2_2X_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x02A4)
#define REG_AON_CLK_CGM_SDIO2_1X_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x02AC)
#define REG_AON_CLK_CGM_SPI0_DIV_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x02B8)
#define REG_AON_CLK_CGM_SPI0_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x02BC)
#define REG_AON_CLK_CGM_SPI1_DIV_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x02C4)
#define REG_AON_CLK_CGM_SPI1_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x02C8)
#define REG_AON_CLK_CGM_SPI2_DIV_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x02D0)
#define REG_AON_CLK_CGM_SPI2_SEL_CFG                        SCI_ADDR(CTL_AON_CLK_BASE, 0x02D4)
#define REG_AON_CLK_CGM_ANALOG_IO_APB_DIV_CFG               SCI_ADDR(CTL_AON_CLK_BASE, 0x02DC)
#define REG_AON_CLK_CGM_ANALOG_IO_APB_SEL_CFG               SCI_ADDR(CTL_AON_CLK_BASE, 0x02E0)
#define REG_AON_CLK_CGM_DMC_REFR_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x02EC)
#define REG_AON_CLK_CGM_USB_CFG_DIV_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x02F4)
#define REG_AON_CLK_CGM_USB_CFG_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x02F8)
#define REG_AON_CLK_CGM_AAPC_TEST_DIV_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x030C)
#define REG_AON_CLK_CGM_USB_SUSPEND_SEL_CFG                 SCI_ADDR(CTL_AON_CLK_BASE, 0x031C)
#define REG_AON_CLK_CGM_UFS_AON_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0328)
#define REG_AON_CLK_CGM_UFS_PCK_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0334)
#define REG_AON_CLK_CGM_AP2EMC_DIV_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x0348)
#define REG_AON_CLK_CGM_AP2EMC_SEL_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x034C)
#define REG_AON_CLK_CGM_APCPU2EMC_DIV_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x0354)
#define REG_AON_CLK_CGM_APCPU2EMC_SEL_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x0358)
#define REG_AON_CLK_CGM_AUDCP2EMC_DIV_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x0360)
#define REG_AON_CLK_CGM_AUDCP2EMC_SEL_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x0364)
#define REG_AON_CLK_CGM_MMHB2EMC_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x036C)
#define REG_AON_CLK_CGM_MMHB2EMC_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x0370)
#define REG_AON_CLK_CGM_MMLL2EMC_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x0378)
#define REG_AON_CLK_CGM_MMLL2EMC_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x037C)
#define REG_AON_CLK_CGM_VPU2EMC_DIV_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0384)
#define REG_AON_CLK_CGM_VPU2EMC_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0388)
#define REG_AON_CLK_CGM_DPU2EMC_DIV_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0390)
#define REG_AON_CLK_CGM_DPU2EMC_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x0394)
#define REG_AON_CLK_CGM_GPU2EMC_DIV_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x039C)
#define REG_AON_CLK_CGM_GPU2EMC_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x03A0)
#define REG_AON_CLK_CGM_DPU12EMC_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x03A8)
#define REG_AON_CLK_CGM_DPU12EMC_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x03AC)
#define REG_AON_CLK_CGM_IPA2EMC_DIV_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x03B4)
#define REG_AON_CLK_CGM_IPA2EMC_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x03B8)
#define REG_AON_CLK_CGM_ISE2EMC_DIV_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x03C0)
#define REG_AON_CLK_CGM_ISE2EMC_SEL_CFG                     SCI_ADDR(CTL_AON_CLK_BASE, 0x03C4)
#define REG_AON_CLK_CGM_PCIE2EMC_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x03CC)
#define REG_AON_CLK_CGM_PCIE2EMC_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x03D0)
#define REG_AON_CLK_CGM_PHYCP2EMC_DIV_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x03D8)
#define REG_AON_CLK_CGM_PHYCP2EMC_SEL_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x03DC)
#define REG_AON_CLK_CGM_PHYCP_ACC2EMC_DIV_CFG               SCI_ADDR(CTL_AON_CLK_BASE, 0x03E4)
#define REG_AON_CLK_CGM_PHYCP_ACC2EMC_SEL_CFG               SCI_ADDR(CTL_AON_CLK_BASE, 0x03E8)
#define REG_AON_CLK_CGM_PSCP2EMC_DIV_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x03F0)
#define REG_AON_CLK_CGM_PSCP2EMC_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x03F4)
#define REG_AON_CLK_CGM_PSCP_ACC2EMC_DIV_CFG                SCI_ADDR(CTL_AON_CLK_BASE, 0x03FC)
#define REG_AON_CLK_CGM_PSCP_ACC2EMC_SEL_CFG                SCI_ADDR(CTL_AON_CLK_BASE, 0x0400)
#define REG_AON_CLK_CGM_AI2EMC_DIV_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x0408)
#define REG_AON_CLK_CGM_AI2EMC_SEL_CFG                      SCI_ADDR(CTL_AON_CLK_BASE, 0x040C)
#define REG_AON_CLK_CGM_IPA2PCIE_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x0418)
#define REG_AON_CLK_CGM_IPA2PHYCP_SEL_CFG                   SCI_ADDR(CTL_AON_CLK_BASE, 0x0424)
#define REG_AON_CLK_CGM_IPA2PSCP_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x0430)
#define REG_AON_CLK_CGM_BISR_26M_SEL_CFG                    SCI_ADDR(CTL_AON_CLK_BASE, 0x043C)
#define REG_AON_CLK_CGM_RCO6M_CALI_SEL_CFG                  SCI_ADDR(CTL_AON_CLK_BASE, 0x0448)
#define REG_AON_CLK_CGM_RCO150M_AUX_DIV_CFG                 SCI_ADDR(CTL_AON_CLK_BASE, 0x0450)
#define REG_AON_CLK_CGM_RCO100M_AUX_DIV_CFG                 SCI_ADDR(CTL_AON_CLK_BASE, 0x045C)
#define REG_AON_CLK_CGM_RCO60M_AUX_DIV_CFG                  SCI_ADDR(CTL_AON_CLK_BASE, 0x0468)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG0               SCI_ADDR(CTL_AON_CLK_BASE, 0x047C)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG1               SCI_ADDR(CTL_AON_CLK_BASE, 0x0480)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG2               SCI_ADDR(CTL_AON_CLK_BASE, 0x0484)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG3               SCI_ADDR(CTL_AON_CLK_BASE, 0x0488)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG4               SCI_ADDR(CTL_AON_CLK_BASE, 0x048C)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG5               SCI_ADDR(CTL_AON_CLK_BASE, 0x0490)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG6               SCI_ADDR(CTL_AON_CLK_BASE, 0x0494)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG7               SCI_ADDR(CTL_AON_CLK_BASE, 0x0498)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG8               SCI_ADDR(CTL_AON_CLK_BASE, 0x049C)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG9               SCI_ADDR(CTL_AON_CLK_BASE, 0x04A0)
#define REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG10              SCI_ADDR(CTL_AON_CLK_BASE, 0x04A4)

/* bits definitions for REG_AON_CLK_CGM_AON_APB_DIV_CFG, [0x64920024] */
#define BIT_AON_CLK_CGM_AON_APB_DIV(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_AON_APB_SEL_CFG, [0x64920028] */
#define BIT_AON_CLK_CGM_AON_APB_SEL_DFS(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CGM_AON_APB_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_ADI_SEL_CFG, [0x64920034] */
#define BIT_AON_CLK_CGM_ADI_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_PWM0_SEL_CFG, [0x64920040] */
#define BIT_AON_CLK_CGM_PWM0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_PWM1_SEL_CFG, [0x6492004C] */
#define BIT_AON_CLK_CGM_PWM1_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_PWM2_SEL_CFG, [0x64920058] */
#define BIT_AON_CLK_CGM_PWM2_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_PWM3_SEL_CFG, [0x64920064] */
#define BIT_AON_CLK_CGM_PWM3_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_EFUSE_SEL_CFG, [0x64920070] */
#define BIT_AON_CLK_CGM_EFUSE_SEL                           ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_UART0_SEL_CFG, [0x6492007C] */
#define BIT_AON_CLK_CGM_UART0_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_UART1_SEL_CFG, [0x64920088] */
#define BIT_AON_CLK_CGM_UART1_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_UART2_SEL_CFG, [0x64920094] */
#define BIT_AON_CLK_CGM_UART2_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_THM0_SEL_CFG, [0x649200C4] */
#define BIT_AON_CLK_CGM_THM0_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_THM1_SEL_CFG, [0x649200D0] */
#define BIT_AON_CLK_CGM_THM1_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_THM2_SEL_CFG, [0x649200DC] */
#define BIT_AON_CLK_CGM_THM2_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_THM3_SEL_CFG, [0x649200E8] */
#define BIT_AON_CLK_CGM_THM3_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_CH_I3C0_SEL_CFG, [0x649200F4] */
#define BIT_AON_CLK_CGM_CH_I3C0_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_CH_I3C1_SEL_CFG, [0x64920100] */
#define BIT_AON_CLK_CGM_CH_I3C1_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_CH_SPI_DIV_CFG, [0x64920108] */
#define BIT_AON_CLK_CGM_CH_SPI_DIV(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_CH_SPI_SEL_CFG, [0x6492010C] */
#define BIT_AON_CLK_CGM_CH_SPI_PAD_SEL                      ( BIT(16) )
#define BIT_AON_CLK_CGM_CH_SPI_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_AON_IIS_SEL_CFG, [0x64920118] */
#define BIT_AON_CLK_CGM_AON_IIS_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_SCC_SEL_CFG, [0x64920124] */
#define BIT_AON_CLK_CGM_SCC_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_APCPU_DAP_SEL_CFG, [0x64920130] */
#define BIT_AON_CLK_CGM_APCPU_DAP_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_APCPU_TS_SEL_CFG, [0x6492013C] */
#define BIT_AON_CLK_CGM_APCPU_TS_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_DEBUG_TS_SEL_CFG, [0x64920148] */
#define BIT_AON_CLK_CGM_DEBUG_TS_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PRI_SBI_SEL_CFG, [0x64920154] */
#define BIT_AON_CLK_CGM_PRI_SBI_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_XO_SEL_CFG, [0x64920160] */
#define BIT_AON_CLK_CGM_XO_SEL                              ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_RFTI_LTH_SEL_CFG, [0x6492016C] */
#define BIT_AON_CLK_CGM_RFTI_LTH_SEL                        ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_AFC_LTH_SEL_CFG, [0x64920178] */
#define BIT_AON_CLK_CGM_AFC_LTH_SEL                         ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_RCO100M_FDK_DIV_CFG, [0x6492018C] */
#define BIT_AON_CLK_CGM_RCO100M_FDK_DIV(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_CLK_CGM_RCO60M_FDK_DIV_CFG, [0x649201A4] */
#define BIT_AON_CLK_CGM_RCO60M_FDK_DIV(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_CLK_CGM_RCO6M_REF_DIV_CFG, [0x649201B0] */
#define BIT_AON_CLK_CGM_RCO6M_REF_DIV(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_CLK_CGM_RCO6M_REF_SEL_CFG, [0x649201B4] */
#define BIT_AON_CLK_CGM_RCO6M_REF_SEL                       ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_RCO6M_FDK_DIV_CFG, [0x649201BC] */
#define BIT_AON_CLK_CGM_RCO6M_FDK_DIV(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_AON_CLK_CGM_DJTAG_TCK_SEL_CFG, [0x649201CC] */
#define BIT_AON_CLK_CGM_DJTAG_TCK_PAD_SEL                   ( BIT(16) )
#define BIT_AON_CLK_CGM_DJTAG_TCK_SEL                       ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_SP_AHB_DIV_CFG, [0x649201D4] */
#define BIT_AON_CLK_CGM_SP_AHB_DIV(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_SP_AHB_SEL_CFG, [0x649201D8] */
#define BIT_AON_CLK_CGM_SP_AHB_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_CH_AHB_DIV_CFG, [0x649201E0] */
#define BIT_AON_CLK_CGM_CH_AHB_DIV(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_CH_AHB_SEL_CFG, [0x649201E4] */
#define BIT_AON_CLK_CGM_CH_AHB_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_TMR_SEL_CFG, [0x649201F0] */
#define BIT_AON_CLK_CGM_TMR_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PMU_SEL_CFG, [0x64920208] */
#define BIT_AON_CLK_CGM_PMU_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_DEBOUNCE_SEL_CFG, [0x64920214] */
#define BIT_AON_CLK_CGM_DEBOUNCE_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_APCPU_PMU_SEL_CFG, [0x64920220] */
#define BIT_AON_CLK_CGM_APCPU_PMU_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_TOP_DVFS_SEL_CFG, [0x6492022C] */
#define BIT_AON_CLK_CGM_TOP_DVFS_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PMU_26M_SEL_CFG, [0x64920238] */
#define BIT_AON_CLK_CGM_PMU_26M_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_TZPC_DIV_CFG, [0x64920240] */
#define BIT_AON_CLK_CGM_TZPC_DIV(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_TZPC_SEL_CFG, [0x64920244] */
#define BIT_AON_CLK_CGM_TZPC_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_OTG_REF_SEL_CFG, [0x64920250] */
#define BIT_AON_CLK_CGM_OTG_REF_SEL                         ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_CSSYS_DIV_CFG, [0x64920258] */
#define BIT_AON_CLK_CGM_CSSYS_DIV(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_CSSYS_SEL_CFG, [0x6492025C] */
#define BIT_AON_CLK_CGM_CSSYS_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_CSSYS_APB_DIV_CFG, [0x64920264] */
#define BIT_AON_CLK_CGM_CSSYS_APB_DIV(x)                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_SDIO0_2X_DIV_CFG, [0x64920270] */
#define BIT_AON_CLK_CGM_SDIO0_2X_DIV(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_AON_CLK_CGM_SDIO0_2X_SEL_CFG, [0x64920274] */
#define BIT_AON_CLK_CGM_SDIO0_2X_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_SDIO0_1X_DIV_CFG, [0x6492027C] */
#define BIT_AON_CLK_CGM_SDIO0_1X_DIV                        ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_SDIO1_2X_DIV_CFG, [0x64920288] */
#define BIT_AON_CLK_CGM_SDIO1_2X_DIV(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_AON_CLK_CGM_SDIO1_2X_SEL_CFG, [0x6492028C] */
#define BIT_AON_CLK_CGM_SDIO1_2X_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_SDIO1_1X_DIV_CFG, [0x64920294] */
#define BIT_AON_CLK_CGM_SDIO1_1X_DIV                        ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_SDIO2_2X_DIV_CFG, [0x649202A0] */
#define BIT_AON_CLK_CGM_SDIO2_2X_DIV(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_AON_CLK_CGM_SDIO2_2X_SEL_CFG, [0x649202A4] */
#define BIT_AON_CLK_CGM_SDIO2_2X_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_SDIO2_1X_DIV_CFG, [0x649202AC] */
#define BIT_AON_CLK_CGM_SDIO2_1X_DIV                        ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_SPI0_DIV_CFG, [0x649202B8] */
#define BIT_AON_CLK_CGM_SPI0_DIV(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_SPI0_SEL_CFG, [0x649202BC] */
#define BIT_AON_CLK_CGM_SPI0_PAD_SEL                        ( BIT(16) )
#define BIT_AON_CLK_CGM_SPI0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_SPI1_DIV_CFG, [0x649202C4] */
#define BIT_AON_CLK_CGM_SPI1_DIV(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_SPI1_SEL_CFG, [0x649202C8] */
#define BIT_AON_CLK_CGM_SPI1_PAD_SEL                        ( BIT(16) )
#define BIT_AON_CLK_CGM_SPI1_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_SPI2_DIV_CFG, [0x649202D0] */
#define BIT_AON_CLK_CGM_SPI2_DIV(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_SPI2_SEL_CFG, [0x649202D4] */
#define BIT_AON_CLK_CGM_SPI2_PAD_SEL                        ( BIT(16) )
#define BIT_AON_CLK_CGM_SPI2_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_ANALOG_IO_APB_DIV_CFG, [0x649202DC] */
#define BIT_AON_CLK_CGM_ANALOG_IO_APB_DIV(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_ANALOG_IO_APB_SEL_CFG, [0x649202E0] */
#define BIT_AON_CLK_CGM_ANALOG_IO_APB_SEL                   ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_DMC_REFR_SEL_CFG, [0x649202EC] */
#define BIT_AON_CLK_CGM_DMC_REFR_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_USB_CFG_DIV_CFG, [0x649202F4] */
#define BIT_AON_CLK_CGM_USB_CFG_DIV(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_USB_CFG_SEL_CFG, [0x649202F8] */
#define BIT_AON_CLK_CGM_USB_CFG_PAD_SEL                     ( BIT(16) )
#define BIT_AON_CLK_CGM_USB_CFG_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_AAPC_TEST_DIV_CFG, [0x6492030C] */
#define BIT_AON_CLK_CGM_AAPC_TEST_DIV(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_CGM_USB_SUSPEND_SEL_CFG, [0x6492031C] */
#define BIT_AON_CLK_CGM_USB_SUSPEND_SEL                     ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_UFS_AON_SEL_CFG, [0x64920328] */
#define BIT_AON_CLK_CGM_UFS_AON_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_UFS_PCK_SEL_CFG, [0x64920334] */
#define BIT_AON_CLK_CGM_UFS_PCK_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_AP2EMC_DIV_CFG, [0x64920348] */
#define BIT_AON_CLK_CGM_AP2EMC_DIV(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_AP2EMC_SEL_CFG, [0x6492034C] */
#define BIT_AON_CLK_CGM_AP2EMC_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_APCPU2EMC_DIV_CFG, [0x64920354] */
#define BIT_AON_CLK_CGM_APCPU2EMC_DIV(x)                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_APCPU2EMC_SEL_CFG, [0x64920358] */
#define BIT_AON_CLK_CGM_APCPU2EMC_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_AUDCP2EMC_DIV_CFG, [0x64920360] */
#define BIT_AON_CLK_CGM_AUDCP2EMC_DIV(x)                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_AUDCP2EMC_SEL_CFG, [0x64920364] */
#define BIT_AON_CLK_CGM_AUDCP2EMC_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_MMHB2EMC_DIV_CFG, [0x6492036C] */
#define BIT_AON_CLK_CGM_MMHB2EMC_DIV(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_MMHB2EMC_SEL_CFG, [0x64920370] */
#define BIT_AON_CLK_CGM_MMHB2EMC_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_MMLL2EMC_DIV_CFG, [0x64920378] */
#define BIT_AON_CLK_CGM_MMLL2EMC_DIV(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_MMLL2EMC_SEL_CFG, [0x6492037C] */
#define BIT_AON_CLK_CGM_MMLL2EMC_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_VPU2EMC_DIV_CFG, [0x64920384] */
#define BIT_AON_CLK_CGM_VPU2EMC_DIV(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_VPU2EMC_SEL_CFG, [0x64920388] */
#define BIT_AON_CLK_CGM_VPU2EMC_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_DPU2EMC_DIV_CFG, [0x64920390] */
#define BIT_AON_CLK_CGM_DPU2EMC_DIV(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_DPU2EMC_SEL_CFG, [0x64920394] */
#define BIT_AON_CLK_CGM_DPU2EMC_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_GPU2EMC_DIV_CFG, [0x6492039C] */
#define BIT_AON_CLK_CGM_GPU2EMC_DIV(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_GPU2EMC_SEL_CFG, [0x649203A0] */
#define BIT_AON_CLK_CGM_GPU2EMC_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_DPU12EMC_DIV_CFG, [0x649203A8] */
#define BIT_AON_CLK_CGM_DPU12EMC_DIV(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_DPU12EMC_SEL_CFG, [0x649203AC] */
#define BIT_AON_CLK_CGM_DPU12EMC_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_IPA2EMC_DIV_CFG, [0x649203B4] */
#define BIT_AON_CLK_CGM_IPA2EMC_DIV(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_IPA2EMC_SEL_CFG, [0x649203B8] */
#define BIT_AON_CLK_CGM_IPA2EMC_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_ISE2EMC_DIV_CFG, [0x649203C0] */
#define BIT_AON_CLK_CGM_ISE2EMC_DIV(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_ISE2EMC_SEL_CFG, [0x649203C4] */
#define BIT_AON_CLK_CGM_ISE2EMC_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PCIE2EMC_DIV_CFG, [0x649203CC] */
#define BIT_AON_CLK_CGM_PCIE2EMC_DIV(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PCIE2EMC_SEL_CFG, [0x649203D0] */
#define BIT_AON_CLK_CGM_PCIE2EMC_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PHYCP2EMC_DIV_CFG, [0x649203D8] */
#define BIT_AON_CLK_CGM_PHYCP2EMC_DIV(x)                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PHYCP2EMC_SEL_CFG, [0x649203DC] */
#define BIT_AON_CLK_CGM_PHYCP2EMC_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_PHYCP_ACC2EMC_DIV_CFG, [0x649203E4] */
#define BIT_AON_CLK_CGM_PHYCP_ACC2EMC_DIV(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PHYCP_ACC2EMC_SEL_CFG, [0x649203E8] */
#define BIT_AON_CLK_CGM_PHYCP_ACC2EMC_SEL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PSCP2EMC_DIV_CFG, [0x649203F0] */
#define BIT_AON_CLK_CGM_PSCP2EMC_DIV(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PSCP2EMC_SEL_CFG, [0x649203F4] */
#define BIT_AON_CLK_CGM_PSCP2EMC_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_PSCP_ACC2EMC_DIV_CFG, [0x649203FC] */
#define BIT_AON_CLK_CGM_PSCP_ACC2EMC_DIV(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_PSCP_ACC2EMC_SEL_CFG, [0x64920400] */
#define BIT_AON_CLK_CGM_PSCP_ACC2EMC_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_AI2EMC_DIV_CFG, [0x64920408] */
#define BIT_AON_CLK_CGM_AI2EMC_DIV(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_AI2EMC_SEL_CFG, [0x6492040C] */
#define BIT_AON_CLK_CGM_AI2EMC_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_IPA2PCIE_SEL_CFG, [0x64920418] */
#define BIT_AON_CLK_CGM_IPA2PCIE_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_IPA2PHYCP_SEL_CFG, [0x64920424] */
#define BIT_AON_CLK_CGM_IPA2PHYCP_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_IPA2PSCP_SEL_CFG, [0x64920430] */
#define BIT_AON_CLK_CGM_IPA2PSCP_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CGM_BISR_26M_SEL_CFG, [0x6492043C] */
#define BIT_AON_CLK_CGM_BISR_26M_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_RCO6M_CALI_SEL_CFG, [0x64920448] */
#define BIT_AON_CLK_CGM_RCO6M_CALI_SEL                      ( BIT(0) )

/* bits definitions for REG_AON_CLK_CGM_RCO150M_AUX_DIV_CFG, [0x64920450] */
#define BIT_AON_CLK_CGM_RCO150M_AUX_DIV(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_RCO100M_AUX_DIV_CFG, [0x6492045C] */
#define BIT_AON_CLK_CGM_RCO100M_AUX_DIV(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_RCO60M_AUX_DIV_CFG, [0x64920468] */
#define BIT_AON_CLK_CGM_RCO60M_AUX_DIV(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG0, [0x6492047C] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR0(x)                ( (x) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG1, [0x64920480] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR1(x)                ( (x) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG2, [0x64920484] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR2(x)                ( (x) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG3, [0x64920488] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR3(x)                ( (x) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG4, [0x6492048C] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR4(x)                ( (x) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG5, [0x64920490] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR5(x)                ( (x) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG6, [0x64920494] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR6(x)                ( (x) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG7, [0x64920498] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR7(x)                ( (x) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG8, [0x6492049C] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR8(x)                ( (x) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG9, [0x649204A0] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR9(x)                ( (x) )

/* bits definitions for REG_AON_CLK_CGM_BUSY_SRC_MONITOR_CFG10, [0x649204A4] */
#define BIT_AON_CLK_CGM_BUSY_SRC_MONITOR10(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )

/* vars definitions for controller CTL_AON_CLK */


#endif /* __AON_CLK_H____ */
