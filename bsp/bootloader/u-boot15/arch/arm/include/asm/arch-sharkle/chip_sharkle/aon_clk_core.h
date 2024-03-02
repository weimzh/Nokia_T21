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
#define REG_AON_CLK_CORE_CGM_CM4_UART_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x004C)
#define REG_AON_CLK_CORE_CGM_32K_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0050)
#define REG_AON_CLK_CORE_CGM_1K_CFG                         SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0054)
#define REG_AON_CLK_CORE_CGM_THM0_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0058)
#define REG_AON_CLK_CORE_CGM_THM1_CFG                       SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x005C)
#define REG_AON_CLK_CORE_CGM_AUD_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0060)
#define REG_AON_CLK_CORE_CGM_AUDIF_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0064)
#define REG_AON_CLK_CORE_CGM_VBC_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0068)
#define REG_AON_CLK_CORE_CGM_AUD_IIS_DA0_CFG                SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x006C)
#define REG_AON_CLK_CORE_CGM_AUD_IIS0_AD0_CFG               SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0070)
#define REG_AON_CLK_CORE_CGM_CA53_DAP_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0074)
#define REG_AON_CLK_CORE_CGM_CA53_DAP_MTCK_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0078)
#define REG_AON_CLK_CORE_CGM_CA53_TS_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x007C)
#define REG_AON_CLK_CORE_CGM_DJTAG_TCK_CFG                  SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0080)
#define REG_AON_CLK_CORE_CGM_CM4_AHB_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0084)
#define REG_AON_CLK_CORE_CGM_FUNCDMA_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0088)
#define REG_AON_CLK_CORE_CGM_EMC_REF_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x008C)
#define REG_AON_CLK_CORE_CGM_CSSYS_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0090)
#define REG_AON_CLK_CORE_CGM_TMR_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0094)
#define REG_AON_CLK_CORE_CGM_PMU_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x0098)
#define REG_AON_CLK_CORE_CGM_WCDMA_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x009C)
#define REG_AON_CLK_CORE_CGM_DSI_TEST_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A0)
#define REG_AON_CLK_CORE_CGM_RFTI_SBI_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A4)
#define REG_AON_CLK_CORE_CGM_RFTI1_XO_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00A8)
#define REG_AON_CLK_CORE_CGM_RFTI_LTH_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00AC)
#define REG_AON_CLK_CORE_CGM_RFTI2_XO_CFG                   SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B0)
#define REG_AON_CLK_CORE_CGM_LVDSRF_CALI_CFG                SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B4)
#define REG_AON_CLK_CORE_CGM_SERDES_DPHY_APB_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00B8)
#define REG_AON_CLK_CORE_CGM_SERDES_DPHY_REF_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00BC)
#define REG_AON_CLK_CORE_CGM_SERDES_DPHY_CFG_CFG            SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C0)
#define REG_AON_CLK_CORE_CGM_ANALOG_IO_APB_CFG              SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C4)
#define REG_AON_CLK_CORE_CGM_DJTAG_TCK_HW_CFG               SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00C8)
#define REG_AON_CLK_CORE_CGM_AP_MM_CFG                      SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00CC)
#define REG_AON_CLK_CORE_CGM_AP_AXI_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D0)
#define REG_AON_CLK_CORE_CGM_WCN_CFG                        SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D4)
#define REG_AON_CLK_CORE_CGM_NIC_GPU_CFG                    SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00D8)
#define REG_AON_CLK_CORE_CGM_MM_ISP_CFG                     SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00DC)
#define REG_AON_CLK_CORE_CGM_WTL_BRIDGE_CFG                 SCI_ADDR(CTL_AON_CLK_CORE_BASE, 0x00E0)

/* bits definitions for REG_AON_CLK_CORE_CGM_AON_APB_CFG, [0x402D0220] */
#define BIT_AON_CLK_CORE_CGM_AON_APB_DIV(x)                 ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_AON_APB_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_ADI_CFG, [0x402D0224] */
#define BIT_AON_CLK_CORE_CGM_ADI_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUX0_CFG, [0x402D0228] */
#define BIT_AON_CLK_CORE_CGM_AUX0_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUX1_CFG, [0x402D022C] */
#define BIT_AON_CLK_CORE_CGM_AUX1_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUX2_CFG, [0x402D0230] */
#define BIT_AON_CLK_CORE_CGM_AUX2_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PROBE_CFG, [0x402D0234] */
#define BIT_AON_CLK_CORE_CGM_PROBE_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM0_CFG, [0x402D0238] */
#define BIT_AON_CLK_CORE_CGM_PWM0_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM1_CFG, [0x402D023C] */
#define BIT_AON_CLK_CORE_CGM_PWM1_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM2_CFG, [0x402D0240] */
#define BIT_AON_CLK_CORE_CGM_PWM2_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PWM3_CFG, [0x402D0244] */
#define BIT_AON_CLK_CORE_CGM_PWM3_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_EFUSE_CFG, [0x402D0248] */
#define BIT_AON_CLK_CORE_CGM_EFUSE_SEL                      ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CM4_UART_CFG, [0x402D024C] */
#define BIT_AON_CLK_CORE_CGM_CM4_UART_SEL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_32K_OUT_CFG, [0x402D0250] */
#define BIT_AON_CLK_CORE_CGM_32K_SEL                ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_1K_OUT_CFG, [0x402D0254] */

/* bits definitions for REG_AON_CLK_CORE_CGM_THM0_CFG, [0x402D0258] */
#define BIT_AON_CLK_CORE_CGM_THM0_SEL                       ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_THM1_CFG, [0x402D025C] */
#define BIT_AON_CLK_CORE_CGM_THM1_SEL                       ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUD_CFG, [0x402D0260] */
#define BIT_AON_CLK_CORE_CGM_AUD_SEL                        ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUDIF_CFG, [0x402D0264] */
#define BIT_AON_CLK_CORE_CGM_AUDIF_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_VBC_CFG, [0x402D0268] */
#define BIT_AON_CLK_CORE_CGM_VBC_SEL                        ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUD_IIS_DA0_CFG, [0x402D026C] */
#define BIT_AON_CLK_CORE_CGM_AUD_IIS_DA0_PAD_SEL            ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AUD_IIS0_AD0_CFG, [0x402D0270] */
#define BIT_AON_CLK_CORE_CGM_AUD_IIS0_AD0_PAD_SEL           ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CA53_DAP_CFG, [0x402D0274] */
#define BIT_AON_CLK_CORE_CGM_CA53_DAP_SEL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CA53_DAP_MTCK_CFG, [0x402D0278] */
#define BIT_AON_CLK_CORE_CGM_CA53_DAP_MTCK_PAD_SEL          ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CA53_TS_CFG, [0x402D027C] */
#define BIT_AON_CLK_CORE_CGM_CA53_TS_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DJTAG_TCK_CFG, [0x402D0280] */
#define BIT_AON_CLK_CORE_CGM_DJTAG_TCK_PAD_SEL              ( BIT(16) )
#define BIT_AON_CLK_CORE_CGM_DJTAG_TCK_SEL                  ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CM4_AHB_CFG, [0x402D0284] */
#define BIT_AON_CLK_CORE_CGM_CM4_AHB_DIV(x)                 ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_CM4_AHB_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_FUNCDMA_CFG, [0x402D0288] */
#define BIT_AON_CLK_CORE_CGM_FUNCDMA_PAD_SEL                ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_EMC_REF_CFG, [0x402D028C] */
#define BIT_AON_CLK_CORE_CGM_EMC_REF_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_CSSYS_CFG, [0x402D0290] */
#define BIT_AON_CLK_CORE_CGM_CSSYS_DIV(x)                   ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_CSSYS_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_TMR_CFG, [0x402D0294] */
#define BIT_AON_CLK_CORE_CGM_TMR_SEL                        ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_PMU_CFG, [0x402D0298] */
#define BIT_AON_CLK_CORE_CGM_PMU_SEL                        ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_WCDMA_CFG, [0x402D029C] */
#define BIT_AON_CLK_CORE_CGM_WCDMA_SEL                      ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DSI_TEST_CFG, [0x402D02A0] */
#define BIT_AON_CLK_CORE_CGM_DSI_TEST_PAD_SEL               ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI_SBI_CFG, [0x402D02A4] */
#define BIT_AON_CLK_CORE_CGM_RFTI_SBI_SEL(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI1_XO_CFG, [0x402D02A8] */
#define BIT_AON_CLK_CORE_CGM_RFTI1_XO_SEL                   ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI_LTH_CFG, [0x402D02AC] */
#define BIT_AON_CLK_CORE_CGM_RFTI_LTH_SEL                   ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_RFTI2_XO_CFG, [0x402D02B0] */
#define BIT_AON_CLK_CORE_CGM_RFTI2_XO_SEL                   ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_LVDSRF_CALI_CFG, [0x402D02B4] */
#define BIT_AON_CLK_CORE_CGM_LVDSRF_CALI_SEL                ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SERDES_DPHY_APB_CFG, [0x402D02B8] */
#define BIT_AON_CLK_CORE_CGM_SERDES_DPHY_APB_SEL            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SERDES_DPHY_REF_CFG, [0x402D02BC] */
#define BIT_AON_CLK_CORE_CGM_SERDES_DPHY_REF_SEL            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_SERDES_DPHY_CFG_CFG, [0x402D02C0] */
#define BIT_AON_CLK_CORE_CGM_SERDES_DPHY_CFG_SEL            ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_ANALOG_IO_APB_CFG, [0x402D02C4] */
#define BIT_AON_CLK_CORE_CGM_ANALOG_IO_APB_DIV(x)           ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_ANALOG_IO_APB_SEL              ( BIT(0) )

/* bits definitions for REG_AON_CLK_CORE_CGM_DJTAG_TCK_HW_CFG, [0x402D02C8] */
#define BIT_AON_CLK_CORE_CGM_DJTAG_TCK_HW_PAD_SEL           ( BIT(16) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AP_MM_CFG, [0x402D02CC] */
#define BIT_AON_CLK_CORE_CGM_AP_MM_DIV(x)                   ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_AP_MM_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_AP_AXI_CFG, [0x402D02D0] */
#define BIT_AON_CLK_CORE_CGM_AP_AXI_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_WCN_CFG, [0x402D02D4] */
#define BIT_AON_CLK_CORE_CGM_WCN_DIV(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CORE_CGM_WCN_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_NIC_GPU_CFG, [0x402D02D8] */
#define BIT_AON_CLK_CORE_CGM_NIC_GPU_DIV(x)                 ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_CLK_CORE_CGM_NIC_GPU_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_MM_ISP_CFG, [0x402D02DC] */
#define BIT_AON_CLK_CORE_CGM_MM_ISP_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_CLK_CORE_CGM_WTL_BRIDGE_CFG, [0x402D02E0] */
#define BIT_AON_CLK_CORE_CGM_WTL_BRIDGE_DIV(x)              ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_CLK_CORE_CGM_WTL_BRIDGE_SEL(x)              ( (x) << 0  & (BIT(0)|BIT(1)) )

/* vars definitions for controller CTL_AON_CLK_CORE */


#endif /* __AON_CLK_CORE_H____ */
