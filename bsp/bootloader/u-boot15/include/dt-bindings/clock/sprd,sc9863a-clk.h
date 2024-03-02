// SPDX-License-Identifier: (GPL-2.0+ OR MIT)
//
// Spreadtrum SC9860 platform clocks
//
// Copyright (C) 2017, Spreadtrum Communications Inc.

#ifndef _DT_BINDINGS_CLK_SC9860_H_
#define _DT_BINDINGS_CLK_SC9860_H_

#define CLK_FAC_13M		0
#define CLK_FAC_6M5             1
#define CLK_FAC_4M3             2
#define CLK_FAC_2M		3
#define CLK_FAC_1M		4
#define CLK_FAC_250K		5
#define CLK_FAC_RCO25M		6
#define CLK_FAC_RCO4M		7
#define CLK_FAC_RCO2M		8
#define	CLK_MPLL0_GATE		9
#define	CLK_DPLL0_GATE		10
#define	CLK_LPLL_GATE		11
#define	CLK_GPLL_GATE		12
#define	CLK_DPLL1_GATE		13
#define	CLK_MPLL1_GATE		14
#define	CLK_MPLL2_GATE		15
#define CLK_ISPPLL_GATE		16
#define	CLK_PMU_APB_NUM		(CLK_ISPPLL_GATE + 1)

#define	CLK_AUDIO_GATE		0
#define CLK_RPLL		1
#define CLK_RPLL_390M		2
#define CLK_RPLL_260M		3
#define CLK_RPLL_195M		4
#define CLK_RPLL_26M		5
#define CLK_ANLG_PHY_G5_NUM	(CLK_RPLL_26M + 1)

#define CLK_TWPLL		0
#define CLK_TWPLL_768M		1
#define CLK_TWPLL_384M		2
#define CLK_TWPLL_192M		3
#define CLK_TWPLL_96M		4
#define CLK_TWPLL_48M		5
#define CLK_TWPLL_24M		6
#define CLK_TWPLL_12M		7
#define CLK_TWPLL_512M		8
#define CLK_TWPLL_256M		9
#define CLK_TWPLL_128M		10
#define CLK_TWPLL_64M		11
#define CLK_TWPLL_307M2		12
#define CLK_TWPLL_219M4		13
#define CLK_TWPLL_170M6		14
#define CLK_TWPLL_153M6		15
#define CLK_TWPLL_76M8		16
#define CLK_TWPLL_51M2		17
#define CLK_TWPLL_38M4		18
#define CLK_TWPLL_19M2		19
#define CLK_LPLL		20
#define CLK_LPLL_409M6		21
#define CLK_LPLL_245M76		22
#define CLK_GPLL		23
#define CLK_ISPPLL		24
#define CLK_ISPPLL_468M		25
#define CLK_ANLG_PHY_G1_NUM	(CLK_ISPPLL_468M + 1)

#define CLK_DPLL0		0
#define CLK_DPLL1		1
#define CLK_DPLL0_933M		2
#define	CLK_DPLL0_622M3		3
#define CLK_DPLL0_400M		4
#define CLK_DPLL0_266M7		5
#define CLK_DPLL0_123M1		6
#define CLK_DPLL0_50M		7
#define CLK_ANLG_PHY_G7_NUM	(CLK_DPLL0_50M + 1)

#define CLK_MPLL0		0
#define CLK_MPLL1		1
#define CLK_MPLL2		2
#define CLK_MPLL2_675M		3
#define CLK_ANLG_PHY_G4_NUM	(CLK_MPLL2_675M + 1)

#define CLK_AP_APB		0
#define CLK_AP_CE		1
#define CLK_NANDC_ECC		2
#define CLK_NANDC_26M		3
#define CLK_EMMC_32K		4
#define CLK_SDIO0_32K		5
#define CLK_SDIO1_32K		6
#define CLK_SDIO2_32K		7
#define CLK_OTG_UTMI		8
#define CLK_AP_UART0		9
#define CLK_AP_UART1		10
#define CLK_AP_UART2		11
#define CLK_AP_UART3		12
#define CLK_AP_UART4		13
#define CLK_AP_I2C0		14
#define CLK_AP_I2C1		15
#define CLK_AP_I2C2		16
#define CLK_AP_I2C3		17
#define CLK_AP_I2C4		18
#define CLK_AP_I2C5		19
#define CLK_AP_I2C6		20
#define CLK_AP_SPI0		21
#define CLK_AP_SPI1		22
#define CLK_AP_SPI2		23
#define CLK_AP_SPI3		24
#define CLK_AP_IIS0		25
#define CLK_AP_IIS1		26
#define CLK_AP_IIS2		27
#define CLK_SIM0		28
#define CLK_SIM0_32K		29
#define CLK_AP_CLK_NUM		(CLK_SIM0_32K + 1)

#define CLK_EMC			0
#define CLK_AON_APB		1
#define CLK_ADI			2
#define CLK_AUX0		3
#define CLK_AUX1		4
#define CLK_AUX2		5
#define CLK_PROBE		6
#define CLK_PWM0		7
#define CLK_PWM1		8
#define CLK_PWM2		9
#define CLK_AON_THM		10
#define CLK_AUDIF		11
#define CLK_CPU_DAP		12
#define CLK_CPU_TS		13
#define CLK_DJTAG_TCK		14
#define CLK_EMC_REF		15
#define CLK_CSSYS		16
#define CLK_AON_PMU		17
#define CLK_PMU_26M		18
#define CLK_AON_TMR		19
#define CLK_POWER_CPU		20
#define CLK_AP_AXI		21
#define CLK_SDIO0_2X		22
#define CLK_SDIO1_2X		23
#define CLK_SDIO2_2X		24
#define CLK_EMMC_2X		25
#define CLK_DPU			26
#define CLK_DPU_DPI		27
#define CLK_OTG_REF		28
#define CLK_SDPHY_APB		29
#define CLK_ALG_IO_APB		30
#define CLK_GPU_CORE		31
#define CLK_GPU_SOC		32
#define CLK_MM_EMC		33
#define CLK_MM_AHB		34
#define CLK_BPC			35
#define CLK_DCAM_IF		36
#define CLK_ISP			37
#define CLK_JPG			38
#define CLK_CPP			39
#define CLK_SENSOR0		40
#define CLK_SENSOR1		41
#define CLK_SENSOR2		42
#define CLK_MM_VEMC		43
#define CLK_MM_VAHB		44
#define CLK_VSP			45
#define CLK_CORE0		46
#define CLK_CORE1		47
#define CLK_CORE2		48
#define CLK_CORE3		49
#define CLK_CORE4		50
#define CLK_CORE5		51
#define CLK_CORE6		52
#define CLK_CORE7		53
#define CLK_SCU			54
#define CLK_ACE			55
#define CLK_AXI_PERIPH		56
#define CLK_AXI_ACP		57
#define CLK_ATB			58
#define CLK_DEBUG_APB		59
#define CLK_GIC			60
#define CLK_PERIPH		61
#define CLK_AON_CLK_NUM		(CLK_PERIPH + 1)

#define CLK_OTG_EB		0
#define CLK_DMA_EB		1
#define CLK_CE_EB		2
#define CLK_NANDC_EB		3
#define CLK_SDIO0_EB		4
#define CLK_SDIO1_EB		5
#define CLK_SDIO2_EB		6
#define CLK_EMMC_EB		7
#define CLK_EMMC_32K_EB		8
#define CLK_SDIO0_32K_EB	9
#define CLK_SDIO1_32K_EB	10
#define CLK_SDIO2_32K_EB	11
#define CLK_NANDC_26M_EB	12
#define CLK_DMA_EB2		13
#define CLK_CE_EB2		14
#define CLK_AP_AHB_GATE_NUM	(CLK_CE_EB2 + 1)

#define CLK_ADC_EB		0
#define CLK_FM_EB		1
#define CLK_TPC_EB		2
#define CLK_GPIO_EB		3
#define CLK_PWM0_EB		4
#define CLK_PWM1_EB		5
#define CLK_PWM2_EB		6
#define CLK_PWM3_EB		7
#define CLK_KPD_EB		8
#define CLK_AON_SYST_EB		9
#define CLK_AP_SYST_EB		10
#define CLK_AON_TMR_EB		11
#define CLK_AP_TMR0_EB		12
#define CLK_EFUSE_EB		13
#define CLK_EIC_EB		14
#define CLK_INTC_EB		15
#define CLK_ADI_EB		16
#define CLK_AUDIF_EB		17
#define CLK_AUD_EB		18
#define CLK_VBC_EB		19
#define CLK_PIN_EB		20
#define CLK_IPI_EB		21
#define CLK_SPLK_EB		22
#define CLK_MSPI_EB		23
#define CLK_AP_WDG_EB		24
#define CLK_MM_EB		25
#define CLK_AON_APB_CKG_EB	26
#define CLK_CA53_TS0_EB		27
#define CLK_CA53_TS1_EB		28
#define CLK_CS53_DAP_EB		29
#define CLK_I2C_EB		30
#define CLK_PMU_EB		31
#define CLK_THM_EB		32
#define CLK_AUX0_EB		33
#define CLK_AUX1_EB		34
#define CLK_AUX2_EB		35
#define CLK_PROBE_EB		36
#define CLK_EMC_REF_EB		37
#define CLK_CA53_WDG_EB		38
#define CLK_AP_TMR1_EB		39
#define CLK_AP_TMR2_EB		40
#define CLK_DISP_EMC_EB		41
#define CLK_ZIP_EMC_EB		42
#define CLK_GSP_EMC_EB		43
#define CLK_MM_VSP_EB		44
#define CLK_MDAR_EB		45
#define CLK_RTC4M0_CAL_EB	46
#define CLK_RTC4M1_CAL_EB	47
#define CLK_DJTAG_EB		48
#define CLK_MBOX_EB		49
#define CLK_AON_DMA_EB		50
#define CLK_AON_APB_DEF_EB	51
#define CLK_ORP_JTAG_EB		52
#define CLK_DBG_EB		53
#define CLK_DBG_EMC_EB		54
#define CLK_CROSS_TRIG_EB	55
#define CLK_SERDES_DPHY_EB	56
#define CLK_ARCH_RTC_EB		57
#define CLK_KPD_RTC_EB		58
#define CLK_AON_SYST_RTC_EB	59
#define CLK_AP_SYST_RTC_EB	60
#define CLK_AON_TMR_RTC_EB	61
#define CLK_AP_TMR0_RTC_EB	62
#define CLK_EIC_RTC_EB		63
#define CLK_EIC_RTCDV5_EB	64
#define CLK_AP_WDG_RTC_EB	65
#define CLK_CA53_WDG_RTC_EB	66
#define CLK_THM_RTC_EB		67
#define CLK_ATHMA_RTC_EB	68
#define CLK_GTHMA_RTC_EB	69
#define CLK_ATHMA_RTC_A_EB	70
#define CLK_GTHMA_RTC_A_EB	71
#define CLK_AP_TMR1_RTC_EB	72
#define CLK_AP_TMR2_RTC_EB	73
#define CLK_DXCO_LC_RTC_EB	74
#define CLK_BB_CAL_RTC_EB	75
#define CLK_GNU_EB		76
#define CLK_DISP_EB		77
#define CLK_MM_EMC_EB		78
#define CLK_POWER_CPU_EB	79
#define CLK_HW_I2C_EB		80
#define CLK_MM_VSP_EMC_EB	81
#define CLK_VSP_EB		82
#define CLK_CSSYS_EB		83
#define CLK_DMC_EB		84
#define CLK_ROSC_EB		85
#define CLK_S_D_CFG_EB		86
#define CLK_S_D_REF_EB		87
#define CLK_B_DMA_EB		88
#define CLK_ANLG_EB		89
#define CLK_ANLG_APB_EB		90
#define CLK_BSMTMR_EB		91
#define CLK_AP_AXI_EB		92
#define CLK_AP_INTC0_EB		93
#define CLK_AP_INTC1_EB		94
#define CLK_AP_INTC2_EB		95
#define CLK_AP_INTC3_EB		96
#define CLK_AP_INTC4_EB		97
#define CLK_AP_INTC5_EB		98
#define CLK_SCC_EB		99
#define CLK_DPHY_CFG_EB		100
#define CLK_DPHY_REF_EB		101
#define CLK_CPHY_CFG_EB		102
#define CLK_OTG_REF_EB		103
#define CLK_SERDES_EB		104
#define CLK_AON_AP_EMC_EB	105
#define CLK_AON_APB_GATE_NUM	(CLK_AON_AP_EMC_EB + 1)

#define CLK_MAHB_CKG_EB		0
#define CLK_MDCAM_EB		1
#define CLK_MISP_EB		2
#define CLK_MAHBCSI_EB		3
#define CLK_MCSI_S_EB		4
#define CLK_MCSI_T_EB		5
#define CLK_DCAM_AXI_EB		6
#define CLK_ISP_AXI_EB		7
#define CLK_MCSI_EB		8
#define CLK_MCSI_S_CKG_EB	9
#define CLK_MCSI_T_CKG_EB	10
#define CLK_SENSOR0_EB		11
#define CLK_SENSOR1_EB		12
#define CLK_SENSOR2_EB		13
#define CLK_MCPHY_CFG_EB	14
#define CLK_MM_GATE_NUM		(CLK_MCPHY_CFG_EB + 1)

#define CLK_MIPI_CSI		0
#define CLK_MIPI_CSI_S		1
#define CLK_MIPI_CSI_M		2
#define CLK_MM_CLK_NUM		(CLK_MIPI_CSI_M + 1)

#define CLK_VCKG_EB		0
#define CLK_VVSP_EB		1
#define CLK_VJPG_EB		2
#define CLK_VCPP_EB		3
#define CLK_VSP_AHB_GATE_NUM	(CLK_VCPP_EB + 1)

#define CLK_SIM0_EB		0
#define CLK_IIS0_EB		1
#define CLK_IIS1_EB		2
#define CLK_IIS2_EB		3
#define CLK_SPI0_EB		4
#define CLK_SPI1_EB		5
#define CLK_SPI2_EB		6
#define CLK_I2C0_EB		7
#define CLK_I2C1_EB		8
#define CLK_I2C2_EB		9
#define CLK_I2C3_EB		10
#define CLK_I2C4_EB		11
#define CLK_UART0_EB		12
#define CLK_UART1_EB		13
#define CLK_UART2_EB		14
#define CLK_UART3_EB		15
#define CLK_UART4_EB		16
#define CLK_SIM0_32K_EB		17
#define CLK_SPI3_EB		18
#define CLK_I2C5_EB		19
#define CLK_I2C6_EB		20
#define CLK_AP_APB_GATE_NUM	(CLK_I2C6_EB + 1)

#endif /* _DT_BINDINGS_CLK_SC9860_H_ */