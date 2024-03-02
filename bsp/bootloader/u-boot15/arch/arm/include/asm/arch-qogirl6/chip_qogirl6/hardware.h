/*
 * Copyright (C) 2020 Unigroup Spreadtrum & RDA Technologies Co., Ltd.
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

#ifndef __MMAP_U_SYS_APCPU_CPU_H____
#define __MMAP_U_SYS_APCPU_CPU_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

/* Address Mapping definitions for sub-system U_SYS_APCPU.CPU */
#define SPRD_AON_IRAM32M32_SML_BASE               SCI_IOMAP(0x00000000)
#define SPRD_APCPU_GIC600_BASE                    SCI_IOMAP(0x10000000)
#define SPRD_AP_APB_BASE                          SCI_IOMAP(0x20000000)
#define SPRD_AP_CLK_BASE                          SCI_IOMAP(0x20010000)
#define SPRD_AP_DVFS_BASE                         SCI_IOMAP(0x20014000)
#define SPRD_AP_UART0_BASE                        SCI_IOMAP(0x200a0000)
#define SPRD_AP_UART1_BASE                        SCI_IOMAP(0x200b0000)
#define SPRD_AP_UART2_BASE                        SCI_IOMAP(0x200c0000)
#define SPRD_AP_I2C0_BASE                         SCI_IOMAP(0x200d0000)
#define SPRD_AP_I2C1_BASE                         SCI_IOMAP(0x200e0000)
#define SPRD_AP_I2C2_BASE                         SCI_IOMAP(0x200f0000)
#define SPRD_AP_I2C3_BASE                         SCI_IOMAP(0x20100000)
#define SPRD_AP_I2C4_BASE                         SCI_IOMAP(0x20110000)
#define SPRD_AP_SPI0_HS_BASE                      SCI_IOMAP(0x20120000)
#define SPRD_AP_SPI1_HS_BASE                      SCI_IOMAP(0x20130000)
#define SPRD_AP_SPI2_BASE                         SCI_IOMAP(0x20140000)
#define SPRD_AP_SPI3_BASE                         SCI_IOMAP(0x20150000)
#define SPRD_AP_IIS0_BASE                         SCI_IOMAP(0x20160000)
#define SPRD_AP_IIS1_BASE                         SCI_IOMAP(0x20170000)
#define SPRD_AP_IIS2_BASE                         SCI_IOMAP(0x20180000)
#define SPRD_AP_SIM0_BASE                         SCI_IOMAP(0x20190000)
#define SPRD_AP_SDIO0_BASE                        SCI_IOMAP(0x201a0000)
#define SPRD_AP_SDIO1_BASE                        SCI_IOMAP(0x201b0000)
#define SPRD_AP_SDIO2_BASE                        SCI_IOMAP(0x201c0000)
#define SPRD_AP_EMMC_BASE                         SCI_IOMAP(0x201d0000)
#define SPRD_AP_CE_PUB_BASE                       SCI_IOMAP(0x201e0000)
#define SPRD_AP_CE_SEC_BASE                       SCI_IOMAP(0x201f0000)
#define SPRD_AP_UFS_AES_BASE                      SCI_IOMAP(0x20200000)
#define SPRD_AP_I2C5_BASE                         SCI_IOMAP(0x20210000)
#define SPRD_AP_I2C6_BASE                         SCI_IOMAP(0x20220000)
#define SPRD_AP_AXI_REGU_BASE                     SCI_IOMAP(0x20230000)
#define SPRD_AP_ROM_BASE                          SCI_IOMAP(0x20300000)
#define SPRD_AP_AHB_BASE                          SCI_IOMAP(0x20400000)
#define SPRD_AP_DMA_AMST_BASE                     SCI_IOMAP(0x20410000)
#define SPRD_GPU_APB_BASE                         SCI_IOMAP(0x23000000)
#define SPRD_GPU_DVFS_APB_BASE                    SCI_IOMAP(0x23014000)
#define SPRD_GPU_TRYM_TOPLEVEL_BASE               SCI_IOMAP(0x23100000)
#define SPRD_MM_AHB_REG_BASE                      SCI_IOMAP(0x30000000)
#define SPRD_MM_CKG_REG_BASE                      SCI_IOMAP(0x30010000)
#define SPRD_MM_DVFS_REG_BASE                     SCI_IOMAP(0x30014000)
#define SPRD_MM_AXI_REGU_BASE                     SCI_IOMAP(0x30020000)
#define SPRD_AP_DPU_BASE                          SCI_IOMAP(0x31000000)
#define SPRD_AP_DSI_BASE                          SCI_IOMAP(0x31100000)
#define SPRD_AP_VSP_BASE                          SCI_IOMAP(0x32000000)
#define SPRD_MM_JPG_REG_BASE                      SCI_IOMAP(0x36000000)
#define SPRD_MM_CPP_REG_BASE                      SCI_IOMAP(0x38000000)
#define SPRD_MM_ISP_REG_BASE                      SCI_IOMAP(0x3a000000)
#define SPRD_MM_FD_REG_BASE                       SCI_IOMAP(0x3c000000)
#define SPRD_MM_DCAM_REG_BASE                     SCI_IOMAP(0x3e000000)
#define SPRD_MM_CSI0_REG_BASE                     SCI_IOMAP(0x3e200000)
#define SPRD_MM_CSI1_REG_BASE                     SCI_IOMAP(0x3e300000)
#define SPRD_MM_CSI2_REG_BASE                     SCI_IOMAP(0x3e400000)
#define SPRD_AUDCP_AHB_BASE                       SCI_IOMAP(0x56000000)
#define SPRD_AUDCP_APB_BASE                       SCI_IOMAP(0x5600d000)
#define SPRD_AUDCP_CLK_BASE                       SCI_IOMAP(0x56010000)
#define SPRD_AUDCP_DVFS_APB_BASE                  SCI_IOMAP(0x56014000)
#define SPRD_AUDCP_11DM_BLK0_BASE                 SCI_IOMAP(0x56200000)
#define SPRD_AUDCP_11DM_BLK1_BASE                 SCI_IOMAP(0x56208000)
#define SPRD_AUDCP_PMEM_BASE                      SCI_IOMAP(0x56300000)
#define SPRD_AUDCP_CEVAX_ICU_BASE                 SCI_IOMAP(0x56400000)
#define SPRD_AUDCP_PDM_BASE                       SCI_IOMAP(0x56401000)
#define SPRD_AUDCP_IIS0_BASE                      SCI_IOMAP(0x56403000)
#define SPRD_AUDCP_IIS1_BASE                      SCI_IOMAP(0x56404000)
#define SPRD_AUDCP_IIS2_BASE                      SCI_IOMAP(0x56405000)
#define SPRD_AUDCP_UART_BASE                      SCI_IOMAP(0x56407000)
#define SPRD_AUDCP_AUD_OFLD_DP_BASE               SCI_IOMAP(0x56480000)
#define SPRD_AUDCP_MCDT_BASE                      SCI_IOMAP(0x56490000)
#define SPRD_AUDCP_TMR_ASYNC_CNT0_BASE            SCI_IOMAP(0x56500000)
#define SPRD_AUDCP_TMR_ASYNC_CNT1_BASE            SCI_IOMAP(0x56501000)
#define SPRD_AUDCP_WDG16_BASE                     SCI_IOMAP(0x56503000)
#define SPRD_AUDCP_DMA_64B_AP_BASE                SCI_IOMAP(0x56580000)
#define SPRD_AUDCP_DMA_64B_CP_BASE                SCI_IOMAP(0x56590000)
#define SPRD_AUDCP_SPINLOCK_BASE                  SCI_IOMAP(0x565c0000)
#define SPRD_AUDCP_VBC_BASE                       SCI_IOMAP(0x56700000)
#define SPRD_AUDCP_MCDT_BASE                      SCI_IOMAP(0x56710000)
#define SPRD_AUDCP_DSP_SRC48K_BASE                SCI_IOMAP(0x56720000)
#define SPRD_AUDCP_VBC_IFD_BASE                   SCI_IOMAP(0x56740000)
#define SPRD_AUDCP_AUD_4AD_BASE                   SCI_IOMAP(0x56750000)
#define SPRD_AUDCP_IRAM_BASE                      SCI_IOMAP(0x56800000)
#define SPRD_PUB_RF_PUB_APB_BASE                  SCI_IOMAP(0x60000000)
#define SPRD_PUB_PERF_TRACE_MONITOR_BASE          SCI_IOMAP(0x60040000)
#define SPRD_PUB_RF_DMC_BIST0_APB_BASE            SCI_IOMAP(0x60050000)
#define SPRD_PUB_RF_DMC_BIST1_APB_BASE            SCI_IOMAP(0x60054000)
#define SPRD_PUB_RF_DMC_BIST2_APB_BASE            SCI_IOMAP(0x60058000)
#define SPRD_PUB_RF_PUB_AP_AON_AXI_REGU_BASE      SCI_IOMAP(0x60080000)
#define SPRD_PUB_RF_PUB_PUBCP_AG_AXI_REGU_BASE    SCI_IOMAP(0x60090000)
#define SPRD_PUB_RF_PUB_DPU_DCAM_AXI_REGU_BASE    SCI_IOMAP(0x600a0000)
#define SPRD_PUB_RF_PUB_CROSS_MTX_AXI_REGU_BASE   SCI_IOMAP(0x600b0000)
#define SPRD_PUB_RF_PUB_AHB_BASE                  SCI_IOMAP(0x60200000)
#define SPRD_PUB_RF_PUB_QOSC_AHB_BASE             SCI_IOMAP(0x60210000)
#define SPRD_PUB_DFI_BUSMON_REGCTRL_BASE          SCI_IOMAP(0x60220000)
#define SPRD_PUB_RF_DDR_CTRL_BASE                 SCI_IOMAP(0x60230000)
#define SPRD_PUB_RF_DMC_PHY_SLICE_A_BASE          SCI_IOMAP(0x60231000)
#define SPRD_PUB_RF_DMC_PHY_SLICE_B_BASE          SCI_IOMAP(0x60232000)
#define SPRD_AON_RF_SP_AHB_BASE                   SCI_IOMAP(0x62000000)
#define SPRD_AON_IRAM32M32_SPIRAM_BASE            SCI_IOMAP(0x62010000)
#define SPRD_AON_IRAM32M32_SPDRAM_BASE            SCI_IOMAP(0x62038000)
#define SPRD_AON_EIC_U8_SPGPIO_BASE               SCI_IOMAP(0x62060000)
#define SPRD_AON_EIC_U8_SP_BASE                   SCI_IOMAP(0x62070000)
#define SPRD_AON_WDG16_SP_BASE                    SCI_IOMAP(0x62080000)
#define SPRD_AON_UART_SP0_BASE                    SCI_IOMAP(0x62090000)
#define SPRD_AON_UART_SP1_BASE                    SCI_IOMAP(0x620a0000)
#define SPRD_AON_GPIO_UNIT_BASE                   SCI_IOMAP(0x620b0000)
#define SPRD_AON_I3CM_SP0_BASE                    SCI_IOMAP(0x620c0000)
#define SPRD_AON_I3CM_SP1_BASE                    SCI_IOMAP(0x620d0000)
#define SPRD_AON_SPI_BASE                         SCI_IOMAP(0x620e0000)
#define SPRD_AON_SYST_BASE                        SCI_IOMAP(0x620f0000)
#define SPRD_AON_TMRFULL_SP_BASE                  SCI_IOMAP(0x62100000)
#define SPRD_AON_DMA_BASE                         SCI_IOMAP(0x62110000)
#define SPRD_AON_RF_AON_APB_BASE                  SCI_IOMAP(0x64000000)
#define SPRD_AON_LPSYS_CLK_BASE                   SCI_IOMAP(0x64010000)
#define SPRD_AON_DVFS_BASE                        SCI_IOMAP(0x64014000)
#define SPRD_AON_LPSYS_PMU_APB_BASE               SCI_IOMAP(0x64020000)
#define SPRD_AON_EIC_U8_EXT0_BASE                 SCI_IOMAP(0x64100000)
#define SPRD_AON_EIC_U8_EXT1_BASE                 SCI_IOMAP(0x64110000)
#define SPRD_AON_EIC_U8_EXT2_BASE                 SCI_IOMAP(0x64120000)
#define SPRD_AON_EIC_U8_EXT3_BASE                 SCI_IOMAP(0x64130000)
#define SPRD_AON_EIC_U8_EXT4_BASE                 SCI_IOMAP(0x64140000)
#define SPRD_AON_EIC_U8_EXT5_BASE                 SCI_IOMAP(0x64150000)
#define SPRD_AON_EIC_U8_WTLCP_BASE                SCI_IOMAP(0x64180000)
#define SPRD_AON_EIC_U8_CPALL_BASE                SCI_IOMAP(0x64190000)
#define SPRD_AON_I2C_HW_BASE                      SCI_IOMAP(0x641a0000)
#define SPRD_AON_GPIO_BASE                        SCI_IOMAP(0x641b0000)
#define SPRD_AON_MAILBOX_BASE                     SCI_IOMAP(0x641c0000)
#define SPRD_AON_ADI_MST_BASE                     SCI_IOMAP(0x64200000)
#define SPRD_AON_INTC_AP0_BASE                    SCI_IOMAP(0x64300000)
#define SPRD_AON_INTC_AP1_BASE                    SCI_IOMAP(0x64310000)
#define SPRD_AON_INTC_AP2_BASE                    SCI_IOMAP(0x64320000)
#define SPRD_AON_INTC_AP3_BASE                    SCI_IOMAP(0x64330000)
#define SPRD_AON_INTC_AP4_BASE                    SCI_IOMAP(0x64340000)
#define SPRD_AON_INTC_AP5_BASE                    SCI_IOMAP(0x64350000)
#define SPRD_AON_INTC_WTLCP_BASE                  SCI_IOMAP(0x64370000)
#define SPRD_AON_INTC_LDSP_BASE                   SCI_IOMAP(0x64380000)
#define SPRD_AON_INTC_TGDSP_BASE                  SCI_IOMAP(0x64390000)
#define SPRD_AON_INTC_PUBCP_BASE                  SCI_IOMAP(0x643a0000)
#define SPRD_AON_INTC_AUDCP_BASE                  SCI_IOMAP(0x643b0000)
#define SPRD_AON_RF_EFUSE_APB_BASE                SCI_IOMAP(0x643d0000)
#define SPRD_AON_KPD_BASE                         SCI_IOMAP(0x643e0000)
#define SPRD_AON_PWM_BASE                         SCI_IOMAP(0x643f0000)
#define SPRD_AON_CHIP_RESET_CTRL_BASE             SCI_IOMAP(0x64400000)
#define SPRD_AON_TMRFULL_AP0_BASE                 SCI_IOMAP(0x64420000)
#define SPRD_AON_TMRFULL_AP1_BASE                 SCI_IOMAP(0x64430000)
#define SPRD_AON_TMRFULL_AP2_BASE                 SCI_IOMAP(0x64440000)
#define SPRD_AON_SYST_AP_BASE                     SCI_IOMAP(0x64450000)
#define SPRD_AON_FRT_BASE                         SCI_IOMAP(0x64460000)
#define SPRD_AON_TMRFULL_BASE                     SCI_IOMAP(0x64470000)
#define SPRD_AON_SYST_PCP_BASE                    SCI_IOMAP(0x64480000)
#define SPRD_AON_TMRFULL_PCP_BASE                 SCI_IOMAP(0x64490000)
#define SPRD_AON_THM_TOP0_BASE                    SCI_IOMAP(0x644b0000)
#define SPRD_AON_THM_TOP1_BASE                    SCI_IOMAP(0x644c0000)
#define SPRD_AON_THM_TOP2_BASE                    SCI_IOMAP(0x644d0000)
#define SPRD_AON_WDG16_APCPU_BASE                 SCI_IOMAP(0x644e0000)
#define SPRD_AON_WDG16_AP_BASE                    SCI_IOMAP(0x644f0000)
#define SPRD_AON_WDG16_PCP_BASE                   SCI_IOMAP(0x64500000)
#define SPRD_AON_APB_BUSMON_BASE                  SCI_IOMAP(0x64510000)
#define SPRD_AON_BUSMON_CNT_START_TIMER1_BASE     SCI_IOMAP(0x64520000)
#define SPRD_AON_BUSMON_CNT_START_TIMER2_BASE     SCI_IOMAP(0x64530000)
#define SPRD_ANALOG_ANLG_PHY_G0_BASE              SCI_IOMAP(0x64550000)
#define SPRD_ANALOG_ANLG_PHY_G1_BASE              SCI_IOMAP(0x64560000)
#define SPRD_ANALOG_ANLG_PHY_G2_BASE              SCI_IOMAP(0x64570000)
#define SPRD_ANALOG_ANLG_PHY_G3_BASE              SCI_IOMAP(0x64580000)
#define SPRD_ANALOG_ANLG_PHY_G4_BASE              SCI_IOMAP(0x64590000)
#define SPRD_ANALOG_ANLG_PHY_GC_BASE              SCI_IOMAP(0x645a0000)
#define SPRD_ANALOG_ANLG_PHY_G10_BASE             SCI_IOMAP(0x645b0000)
#define SPRD_AON_ADI_MST_R5P0_BASE                SCI_IOMAP(0x64600000)
#define SPRD_IO_CENTRAL_PIN_REG_BASE              SCI_IOMAP(0x64710000)
#define SPRD_IO_PG1_PIN_REG_BASE                  SCI_IOMAP(0x64710440)
#define SPRD_IO_PG2_PIN_REG_BASE                  SCI_IOMAP(0x64710470)
#define SPRD_IO_PG3_PIN_REG_BASE                  SCI_IOMAP(0x6471050c)
#define SPRD_IO_PG4_PIN_REG_BASE                  SCI_IOMAP(0x647105b4)
#define SPRD_IO_PG5_PIN_REG_BASE                  SCI_IOMAP(0x64710610)
#define SPRD_IO_PG6_PIN_REG_BASE                  SCI_IOMAP(0x647106ec)
#define SPRD_AON_RF_AON_SCC_BASE                  SCI_IOMAP(0x64730000)
#define SPRD_AON_DJTAG_CTRL_BASE                  SCI_IOMAP(0x64740000)
#define SPRD_AON_SERDES_BASE                      SCI_IOMAP(0x64750000)
#define SPRD_AON_IIS_MST_BASE                     SCI_IOMAP(0x64790000)
#define SPRD_AON_TS_PRE_BASE                      SCI_IOMAP(0x647f0000)
#define SPRD_AON_TZPC_BASE                        SCI_IOMAP(0x64800000)
#define SPRD_AON_RF_AON_SLV_FW_BASE               SCI_IOMAP(0x64800000)
#define SPRD_AON_RF_AON_MEM_FW_BASE               SCI_IOMAP(0x64801000)
#define SPRD_AON_RF_AON_MST_SPRD_BASE              SCI_IOMAP(0x64803000)
#define SPRD_AON_RF_AON_REG_FW_BASE               SCI_IOMAP(0x64804000)
#define SPRD_AON_RF_PMU_REG_FW_BASE               SCI_IOMAP(0x64805000)
#define SPRD_AON_EIC_U8_SEC_BASE                  SCI_IOMAP(0x64810000)
#define SPRD_AON_CLK_32K_DET_BASE                 SCI_IOMAP(0x64820000)
#define SPRD_AON_TMRFULL_SEC_BASE                 SCI_IOMAP(0x64840000)
#define SPRD_AON_SEC_CNT_BASE                     SCI_IOMAP(0x64850000)
#define SPRD_AON_WDG16_SEC_BASE                   SCI_IOMAP(0x64860000)
#define SPRD_AON_SEC_GPIO_BASE                    SCI_IOMAP(0x64870000)
#define SPRD_AON_RF_AON_SEC_APB_BASE              SCI_IOMAP(0x64880000)
#define SPRD_AON_RF_AON_DBG_APB_BASE              SCI_IOMAP(0x64890000)
#define SPRD_AON_USB_BASE                         SCI_IOMAP(0x64900000)
#define SPRD_AON_SPINLOCK_AHB_BASE                SCI_IOMAP(0x64910000)
#define SPRD_AON_IRAM32M32_DDRRET_DFS_BASE        SCI_IOMAP(0x65002000)
#define SPRD_AON_IRAM32M32_CR5_BASE               SCI_IOMAP(0x65003400)
#define SPRD_AON_IRAM32M32_DSP_BASE               SCI_IOMAP(0x65004400)
#define SPRD_AON_IRAM32M32_LDSP_BASE              SCI_IOMAP(0x65004c00)
#define SPRD_AON_IRAM32M32_TGDSP_BASE             SCI_IOMAP(0x65007400)
#define SPRD_AON_IRAM32M32_MULMODE_BASE           SCI_IOMAP(0x65008400)
#define SPRD_AON_IRAM32M32_AUD_BASE               SCI_IOMAP(0x65009400)
#define SPRD_AON_IRAM32M32_SMSG_BASE              SCI_IOMAP(0x6500a400)
#define SPRD_AON_IRAM32M32_PUBDEBUG_BASE          SCI_IOMAP(0x6500c400)
#define SPRD_AON_IRAM32M32_WCN_RESERVED_BASE      SCI_IOMAP(0x6500d400)
#define SPRD_AON_IRAM32M32_SW_BASE                SCI_IOMAP(0x6500dc00)
#define SPRD_AON_IRAM32M32_PUBLIC_EFUSE_REPAIR_BASE SCI_IOMAP(0x65014c00)
#define SPRD_AON_IRAM32M32_FW_BASE                SCI_IOMAP(0x65015000)
#define SPRD_AON_IRAM32M32_BASE                   SCI_IOMAP(0x65200000)
#define SPRD_DBG_SOC_CORESIGHT_STM_DATA_BASE      SCI_IOMAP(0x70000000)
#define SPRD_DBG_SOC_CORESIGHT_ROM_TABLE_BASE     SCI_IOMAP(0x7c000000)
#define SPRD_DBG_SOC_CORESIGHT_STM_CFG_BASE       SCI_IOMAP(0x7c001000)
#define SPRD_DBG_SOC_CORESIGHT_FUNNEL_BASE        SCI_IOMAP(0x7c002000)
#define SPRD_DBG_SOC_CORESIGHT_ETF_BASE           SCI_IOMAP(0x7c003000)
#define SPRD_DBG_SOC_CORESIGHT_REPLICATOR_BASE    SCI_IOMAP(0x7c004000)
#define SPRD_DBG_SOC_CORESIGHT_ETR_BASE           SCI_IOMAP(0x7c005000)
#define SPRD_DBG_SOC_CORESIGHT_TPIU_BASE          SCI_IOMAP(0x7c006000)
#define SPRD_DBG_SOC_CORESIGHT_CTI0_BASE          SCI_IOMAP(0x7c007000)
#define SPRD_DBG_SOC_CORESIGHT_CTI1_BASE          SCI_IOMAP(0x7c008000)
#define SPRD_DBG_SOC_TS_BASE                      SCI_IOMAP(0x7c009000)
#define SPRD_DBG_SOC_APB_REG_DBG_SYS__BASE        SCI_IOMAP(0x7c00a000)
#define SPRD_DBG_SOC_CORESIGHT_CTI2_BASE          SCI_IOMAP(0x7c00b000)
#define SPRD_DBG_SOC_CORESIGHT_CTI3_BASE          SCI_IOMAP(0x7c00c000)
#define SPRD_DBG_PUBCP_CR5_BASE                   SCI_IOMAP(0x7c020000)
#define SPRD_DBG_CORINTH_CORESIGHT_ROM_TABLE_BASE SCI_IOMAP(0x7e000000)
#define SPRD_DBG_CORINTH_CORESIGHT_FUNNEL_CORE0_1_2_6__BASE SCI_IOMAP(0x7e001000)
#define SPRD_DBG_CORINTH_CORESIGHT_TMC_CORE0_1_2_6__BASE SCI_IOMAP(0x7e002000)
#define SPRD_DBG_CORINTH_CORESIGHT_TMC_CORE3_4_5_7__BASE SCI_IOMAP(0x7e003000)
#define SPRD_DBG_CORINTH_CORESIGHT_FUNNEL_TO_SOC_BASE SCI_IOMAP(0x7e004000)
#define SPRD_DBG_CORINTH_CORESIGHT_FUNNEL_CORE_3_4_5_7__BASE SCI_IOMAP(0x7e005000)
#define SPRD_DBG_CORINTH_CORESIGHT_ETR_BASE       SCI_IOMAP(0x7e006000)
#define SPRD_DBG_CORINTH_CORESIGHT_REPLICATOR_BASE SCI_IOMAP(0x7e007000)
#define SPRD_DBG_CORINTH_ROM_TABLE_BASE           SCI_IOMAP(0x7f000000)

#endif /* __MMAP_U_SYS_APCPU_CPU_H____ */
