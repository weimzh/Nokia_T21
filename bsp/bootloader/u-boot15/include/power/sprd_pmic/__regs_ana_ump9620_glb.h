/*
 * Copyright (C) 2020 UNISOC Technologies Co., Ltd.
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


#ifndef _UMP9620_GLB_H
#define _UMP9620_GLB_H

#define CTL_BASE_ANA_GLB		ANA_REGS_GLB_BASE

#define ANA_REG_GLB_CHIP_ID_LOW                         (CTL_BASE_ANA_GLB + 0x0000)
#define ANA_REG_GLB_CHIP_ID_HIGH                        (CTL_BASE_ANA_GLB + 0x0004)
#define ANA_REG_GLB_MODULE_EN0                          (CTL_BASE_ANA_GLB + 0x0008)
#define ANA_REG_GLB_ARM_CLK_EN0                         (CTL_BASE_ANA_GLB + 0x000C)
#define ANA_REG_GLB_RTC_CLK_EN0                         (CTL_BASE_ANA_GLB + 0x0010)
#define ANA_REG_GLB_SOFT_RST0                           (CTL_BASE_ANA_GLB + 0x0014)
#define ANA_REG_GLB_SOFT_RST1                           (CTL_BASE_ANA_GLB + 0x0018)
#define ANA_REG_GLB_POWER_PD_SW                         (CTL_BASE_ANA_GLB + 0x001C)
#define ANA_REG_GLB_POWER_PD_HW                         (CTL_BASE_ANA_GLB + 0x0020)
#define ANA_REG_GLB_SOFT_RST_HW                         (CTL_BASE_ANA_GLB + 0x0024)
#define ANA_REG_GLB_AUXAD_VSS_CTRL                      (CTL_BASE_ANA_GLB + 0x0028)
#define ANA_REG_GLB_ADI_ACK_BIT_OPT_CTRL                (CTL_BASE_ANA_GLB + 0x002C)
#define ANA_REG_GLB_RESERVED_REG1                       (CTL_BASE_ANA_GLB + 0x0030)
#define ANA_REG_GLB_RESERVED_REG2                       (CTL_BASE_ANA_GLB + 0x0034)
#define ANA_REG_GLB_DCDC_CPU2_REG0                      (CTL_BASE_ANA_GLB + 0x0038)
#define ANA_REG_GLB_DCDC_CPU2_REG1                      (CTL_BASE_ANA_GLB + 0x003C)
#define ANA_REG_GLB_DCDC_CPU2_REG2                      (CTL_BASE_ANA_GLB + 0x0040)
#define ANA_REG_GLB_DCDC_CPU2_VOL                       (CTL_BASE_ANA_GLB + 0x0044)
#define ANA_REG_GLB_DCDC_GPU_REG0                       (CTL_BASE_ANA_GLB + 0x0048)
#define ANA_REG_GLB_DCDC_GPU_REG1                       (CTL_BASE_ANA_GLB + 0x004C)
#define ANA_REG_GLB_DCDC_GPU_REG2                       (CTL_BASE_ANA_GLB + 0x0050)
#define ANA_REG_GLB_DCDC_GPU_VOL                        (CTL_BASE_ANA_GLB + 0x0054)
#define ANA_REG_GLB_DCDC_CORE_REG0                      (CTL_BASE_ANA_GLB + 0x0058)
#define ANA_REG_GLB_DCDC_CORE_REG1                      (CTL_BASE_ANA_GLB + 0x005C)
#define ANA_REG_GLB_DCDC_CORE_REG2                      (CTL_BASE_ANA_GLB + 0x0060)
#define ANA_REG_GLB_DCDC_CORE_VOL                       (CTL_BASE_ANA_GLB + 0x0064)
#define ANA_REG_GLB_DCDC_PUB_REG0                       (CTL_BASE_ANA_GLB + 0x0068)
#define ANA_REG_GLB_DCDC_PUB_REG1                       (CTL_BASE_ANA_GLB + 0x006C)
#define ANA_REG_GLB_DCDC_PUB_REG2                       (CTL_BASE_ANA_GLB + 0x0070)
#define ANA_REG_GLB_DCDC_PUB_VOL                        (CTL_BASE_ANA_GLB + 0x0074)
#define ANA_REG_GLB_DCDC_MEM_REG0                       (CTL_BASE_ANA_GLB + 0x0078)
#define ANA_REG_GLB_DCDC_MEM_REG1                       (CTL_BASE_ANA_GLB + 0x007C)
#define ANA_REG_GLB_DCDC_MEM_REG2                       (CTL_BASE_ANA_GLB + 0x0080)
#define ANA_REG_GLB_DCDC_MEM_VOL                        (CTL_BASE_ANA_GLB + 0x0084)
#define ANA_REG_GLB_DCDC_MEMQ_REG0                      (CTL_BASE_ANA_GLB + 0x0088)
#define ANA_REG_GLB_DCDC_MEMQ_REG1                      (CTL_BASE_ANA_GLB + 0x008C)
#define ANA_REG_GLB_DCDC_MEMQ_REG2                      (CTL_BASE_ANA_GLB + 0x0090)
#define ANA_REG_GLB_DCDC_MEMQ_VOL                       (CTL_BASE_ANA_GLB + 0x0094)
#define ANA_REG_GLB_DCDC_GEN0_REG0                      (CTL_BASE_ANA_GLB + 0x0098)
#define ANA_REG_GLB_DCDC_GEN0_REG1                      (CTL_BASE_ANA_GLB + 0x009C)
#define ANA_REG_GLB_DCDC_GEN0_REG2                      (CTL_BASE_ANA_GLB + 0x00A0)
#define ANA_REG_GLB_DCDC_GEN0_VOL                       (CTL_BASE_ANA_GLB + 0x00A4)
#define ANA_REG_GLB_DCDC_GEN1_REG0                      (CTL_BASE_ANA_GLB + 0x00A8)
#define ANA_REG_GLB_DCDC_GEN1_REG1                      (CTL_BASE_ANA_GLB + 0x00AC)
#define ANA_REG_GLB_DCDC_GEN1_REG2                      (CTL_BASE_ANA_GLB + 0x00B0)
#define ANA_REG_GLB_DCDC_GEN1_VOL                       (CTL_BASE_ANA_GLB + 0x00B4)
#define ANA_REG_GLB_DCDC_WPA_REG0                       (CTL_BASE_ANA_GLB + 0x00B8)
#define ANA_REG_GLB_DCDC_WPA_REG1                       (CTL_BASE_ANA_GLB + 0x00BC)
#define ANA_REG_GLB_DCDC_WPA_REG2                       (CTL_BASE_ANA_GLB + 0x00C0)
#define ANA_REG_GLB_DCDC_WPA_REG3                       (CTL_BASE_ANA_GLB + 0x00C4)
#define ANA_REG_GLB_DCDC_WPA_VOL                        (CTL_BASE_ANA_GLB + 0x00C8)
#define ANA_REG_GLB_DCDC_WPA_DCMB                       (CTL_BASE_ANA_GLB + 0x00CC)
#define ANA_REG_GLB_DCDC_SRAM0_REG0                     (CTL_BASE_ANA_GLB + 0x00D0)
#define ANA_REG_GLB_DCDC_SRAM0_REG1                     (CTL_BASE_ANA_GLB + 0x00D4)
#define ANA_REG_GLB_DCDC_SRAM0_REG2                     (CTL_BASE_ANA_GLB + 0x00D8)
#define ANA_REG_GLB_DCDC_SRAM0_VOL                      (CTL_BASE_ANA_GLB + 0x00DC)
#define ANA_REG_GLB_RESERVED_REG43                      (CTL_BASE_ANA_GLB + 0x00E0)
#define ANA_REG_GLB_DCDC_CH_CTRL                        (CTL_BASE_ANA_GLB + 0x00E4)
#define ANA_REG_GLB_DCDC_CTRL                           (CTL_BASE_ANA_GLB + 0x00E8)
#define ANA_REG_GLB_DCDC_CLK_CTRL                       (CTL_BASE_ANA_GLB + 0x00EC)
#define ANA_REG_GLB_RESERVED_REG3                       (CTL_BASE_ANA_GLB + 0x00F0)
#define ANA_REG_GLB_RESERVED_REG4                       (CTL_BASE_ANA_GLB + 0x00F4)
#define ANA_REG_GLB_RESERVED_REG6                       (CTL_BASE_ANA_GLB + 0x00F8)
#define ANA_REG_GLB_RESERVED_REG7                       (CTL_BASE_ANA_GLB + 0x00FC)
#define ANA_REG_GLB_RESERVED_REG5                       (CTL_BASE_ANA_GLB + 0x0100)
#define ANA_REG_GLB_LDO_AVDD18_REG1                     (CTL_BASE_ANA_GLB + 0x0104)
#define ANA_REG_GLB_LDO_AVDD18_REG2                     (CTL_BASE_ANA_GLB + 0x0108)
#define ANA_REG_GLB_LDO_VDDRF1V8_REG0                   (CTL_BASE_ANA_GLB + 0x010C)
#define ANA_REG_GLB_LDO_VDDRF1V8_REG1                   (CTL_BASE_ANA_GLB + 0x0110)
#define ANA_REG_GLB_LDO_VDDRF1V8_REG2                   (CTL_BASE_ANA_GLB + 0x0114)
#define ANA_REG_GLB_LDO_VDDCAMIO_REG0                   (CTL_BASE_ANA_GLB + 0x0118)
#define ANA_REG_GLB_LDO_VDDWCN_REG0                     (CTL_BASE_ANA_GLB + 0x011C)
#define ANA_REG_GLB_LDO_VDDWCN_REG1                     (CTL_BASE_ANA_GLB + 0x0120)
#define ANA_REG_GLB_LDO_VDDWCN_REG2                     (CTL_BASE_ANA_GLB + 0x0124)
#define ANA_REG_GLB_LDO_VDDCAMD1_REG0                   (CTL_BASE_ANA_GLB + 0x0128)
#define ANA_REG_GLB_LDO_VDDCAMD1_REG1                   (CTL_BASE_ANA_GLB + 0x012C)
#define ANA_REG_GLB_LDO_VDDCAMD1_REG2                   (CTL_BASE_ANA_GLB + 0x0130)
#define ANA_REG_GLB_LDO_VDDCAMD0_REG0                   (CTL_BASE_ANA_GLB + 0x0134)
#define ANA_REG_GLB_LDO_VDDCAMD0_REG1                   (CTL_BASE_ANA_GLB + 0x0138)
#define ANA_REG_GLB_LDO_VDDCAMD0_REG2                   (CTL_BASE_ANA_GLB + 0x013C)
#define ANA_REG_GLB_LDO_VDDCAMMOT1_REG0                 (CTL_BASE_ANA_GLB + 0x0140)
#define ANA_REG_GLB_LDO_VDDCAMMOT1_REG1                 (CTL_BASE_ANA_GLB + 0x0144)
#define ANA_REG_GLB_LDO_VDDCAMMOT1_REG2                 (CTL_BASE_ANA_GLB + 0x0148)
#define ANA_REG_GLB_LDO_AVDD12_REG0                     (CTL_BASE_ANA_GLB + 0x014C)
#define ANA_REG_GLB_LDO_AVDD12_REG1                     (CTL_BASE_ANA_GLB + 0x0150)
#define ANA_REG_GLB_LDO_AVDD12_REG2                     (CTL_BASE_ANA_GLB + 0x0154)
#define ANA_REG_GLB_LDO_VDDCAMA0_REG0                   (CTL_BASE_ANA_GLB + 0x0158)
#define ANA_REG_GLB_LDO_VDDCAMA0_REG1                   (CTL_BASE_ANA_GLB + 0x015C)
#define ANA_REG_GLB_LDO_VDDCAMA0_REG2                   (CTL_BASE_ANA_GLB + 0x0160)
#define ANA_REG_GLB_LDO_VDDCAMA1_REG0                   (CTL_BASE_ANA_GLB + 0x0164)
#define ANA_REG_GLB_LDO_VDDCAMA1_REG1                   (CTL_BASE_ANA_GLB + 0x0168)
#define ANA_REG_GLB_LDO_VDDCAMA1_REG2                   (CTL_BASE_ANA_GLB + 0x016C)
#define ANA_REG_GLB_LDO_VDDCAMMOT0_REG0                 (CTL_BASE_ANA_GLB + 0x0170)
#define ANA_REG_GLB_LDO_VDDCAMMOT0_REG1                 (CTL_BASE_ANA_GLB + 0x0174)
#define ANA_REG_GLB_LDO_VDDCAMMOT0_REG2                 (CTL_BASE_ANA_GLB + 0x0178)
#define ANA_REG_GLB_LDO_VDDSIM0_REG0                    (CTL_BASE_ANA_GLB + 0x017C)
#define ANA_REG_GLB_LDO_VDDSIM0_REG1                    (CTL_BASE_ANA_GLB + 0x0180)
#define ANA_REG_GLB_LDO_VDDSIM0_REG2                    (CTL_BASE_ANA_GLB + 0x0184)
#define ANA_REG_GLB_LDO_VDDSIM1_REG0                    (CTL_BASE_ANA_GLB + 0x0188)
#define ANA_REG_GLB_LDO_VDDSIM1_REG1                    (CTL_BASE_ANA_GLB + 0x018C)
#define ANA_REG_GLB_LDO_VDDSIM1_REG2                    (CTL_BASE_ANA_GLB + 0x0190)
#define ANA_REG_GLB_LDO_VDDSIM2_REG0                    (CTL_BASE_ANA_GLB + 0x0194)
#define ANA_REG_GLB_LDO_VDDSIM2_REG1                    (CTL_BASE_ANA_GLB + 0x0198)
#define ANA_REG_GLB_LDO_VDDSIM2_REG2                    (CTL_BASE_ANA_GLB + 0x019C)
#define ANA_REG_GLB_LDO_VDDEMMCCORE_REG0                (CTL_BASE_ANA_GLB + 0x01A0)
#define ANA_REG_GLB_LDO_VDDEMMCCORE_REG1                (CTL_BASE_ANA_GLB + 0x01A4)
#define ANA_REG_GLB_LDO_VDDEMMCCORE_REG2                (CTL_BASE_ANA_GLB + 0x01A8)
#define ANA_REG_GLB_LDO_VDDSDCORE_REG0                  (CTL_BASE_ANA_GLB + 0x01AC)
#define ANA_REG_GLB_LDO_VDDSDCORE_REG1                  (CTL_BASE_ANA_GLB + 0x01B0)
#define ANA_REG_GLB_LDO_VDDSDCORE_REG2                  (CTL_BASE_ANA_GLB + 0x01B4)
#define ANA_REG_GLB_LDO_VDDSDIO_REG0                    (CTL_BASE_ANA_GLB + 0x01B8)
#define ANA_REG_GLB_LDO_VDDSDIO_REG1                    (CTL_BASE_ANA_GLB + 0x01BC)
#define ANA_REG_GLB_LDO_VDDSDIO_REG2                    (CTL_BASE_ANA_GLB + 0x01C0)
#define ANA_REG_GLB_LDO_VDD28_REG0                      (CTL_BASE_ANA_GLB + 0x01C4)
#define ANA_REG_GLB_LDO_VDD28_REG1                      (CTL_BASE_ANA_GLB + 0x01C8)
#define ANA_REG_GLB_LDO_VDD28_REG2                      (CTL_BASE_ANA_GLB + 0x01CC)
#define ANA_REG_GLB_LDO_VDDWIFIPA_REG0                  (CTL_BASE_ANA_GLB + 0x01D0)
#define ANA_REG_GLB_LDO_VDDWIFIPA_REG1                  (CTL_BASE_ANA_GLB + 0x01D4)
#define ANA_REG_GLB_LDO_VDDWIFIPA_REG2                  (CTL_BASE_ANA_GLB + 0x01D8)
#define ANA_REG_GLB_RESERVED_REG9                       (CTL_BASE_ANA_GLB + 0x01DC)
#define ANA_REG_GLB_LDO_VDD18_DCXO_REG1                 (CTL_BASE_ANA_GLB + 0x01E0)
#define ANA_REG_GLB_LDO_VDD18_DCXO_REG2                 (CTL_BASE_ANA_GLB + 0x01E4)
#define ANA_REG_GLB_LDO_VDDUSB33_REG0                   (CTL_BASE_ANA_GLB + 0x01E8)
#define ANA_REG_GLB_LDO_VDDUSB33_REG1                   (CTL_BASE_ANA_GLB + 0x01EC)
#define ANA_REG_GLB_LDO_VDDUSB33_REG2                   (CTL_BASE_ANA_GLB + 0x01F0)
#define ANA_REG_GLB_LDO_VDDLDO0_REG0                    (CTL_BASE_ANA_GLB + 0x01F4)
#define ANA_REG_GLB_LDO_VDDLDO0_REG1                    (CTL_BASE_ANA_GLB + 0x01F8)
#define ANA_REG_GLB_LDO_VDDLDO0_REG2                    (CTL_BASE_ANA_GLB + 0x01FC)
#define ANA_REG_GLB_LDO_VDDLDO1_REG0                    (CTL_BASE_ANA_GLB + 0x0200)
#define ANA_REG_GLB_LDO_VDDLDO1_REG1                    (CTL_BASE_ANA_GLB + 0x0204)
#define ANA_REG_GLB_LDO_VDDLDO1_REG2                    (CTL_BASE_ANA_GLB + 0x0208)
#define ANA_REG_GLB_LDO_VDDLDO2_REG0                    (CTL_BASE_ANA_GLB + 0x020C)
#define ANA_REG_GLB_LDO_VDDLDO2_REG1                    (CTL_BASE_ANA_GLB + 0x0210)
#define ANA_REG_GLB_LDO_VDDLDO2_REG2                    (CTL_BASE_ANA_GLB + 0x0214)
#define ANA_REG_GLB_LDO_RTC_CTRL                        (CTL_BASE_ANA_GLB + 0x0228)
#define ANA_REG_GLB_LDO_CH_CTRL                         (CTL_BASE_ANA_GLB + 0x022C)
#define ANA_REG_GLB_RESERVED_REG12                      (CTL_BASE_ANA_GLB + 0x0230)
#define ANA_REG_GLB_RESERVED_REG13                      (CTL_BASE_ANA_GLB + 0x0234)
#define ANA_REG_GLB_RESERVED_REG14                      (CTL_BASE_ANA_GLB + 0x0238)
#define ANA_REG_GLB_RESERVED_REG15                      (CTL_BASE_ANA_GLB + 0x023C)
#define ANA_REG_GLB_RESERVED_REG16                      (CTL_BASE_ANA_GLB + 0x0240)
#define ANA_REG_GLB_RESERVED_REG17                      (CTL_BASE_ANA_GLB + 0x0244)
#define ANA_REG_GLB_SLP_CTRL                            (CTL_BASE_ANA_GLB + 0x0248)
#define ANA_REG_GLB_SLP_DCDC_PD_CTRL                    (CTL_BASE_ANA_GLB + 0x024C)
#define ANA_REG_GLB_SLP_LDO_PD_CTRL0                    (CTL_BASE_ANA_GLB + 0x0250)
#define ANA_REG_GLB_SLP_LDO_PD_CTRL1                    (CTL_BASE_ANA_GLB + 0x0254)
#define ANA_REG_GLB_SLP_DCDC_LP_CTRL                    (CTL_BASE_ANA_GLB + 0x0258)
#define ANA_REG_GLB_SLP_LDO_LP_CTRL0                    (CTL_BASE_ANA_GLB + 0x025C)
#define ANA_REG_GLB_SLP_LDO_LP_CTRL1                    (CTL_BASE_ANA_GLB + 0x0260)
#define ANA_REG_GLB_DCDC_CORE_SLP_CTRL0                 (CTL_BASE_ANA_GLB + 0x0264)
#define ANA_REG_GLB_DCDC_CORE_SLP_CTRL1                 (CTL_BASE_ANA_GLB + 0x0268)
#define ANA_REG_GLB_DCDC_GPU_SLP_CTRL0                  (CTL_BASE_ANA_GLB + 0x026C)
#define ANA_REG_GLB_DCDC_GPU_SLP_CTRL1                  (CTL_BASE_ANA_GLB + 0x0270)
#define ANA_REG_GLB_RESERVED_REG18                      (CTL_BASE_ANA_GLB + 0x0274)
#define ANA_REG_GLB_RESERVED_REG19                      (CTL_BASE_ANA_GLB + 0x0278)
#define ANA_REG_GLB_DCDC_PUB_SLP_CTRL0                  (CTL_BASE_ANA_GLB + 0x027C)
#define ANA_REG_GLB_DCDC_PUB_SLP_CTRL1                  (CTL_BASE_ANA_GLB + 0x0280)
#define ANA_REG_GLB_DCDC_SRAM0_SLP_CTRL0                (CTL_BASE_ANA_GLB + 0x0284)
#define ANA_REG_GLB_DCDC_SRAM0_SLP_CTRL1                (CTL_BASE_ANA_GLB + 0x0288)
#define ANA_REG_GLB_DCDC_XTL_EN                         (CTL_BASE_ANA_GLB + 0x028C)
#define ANA_REG_GLB_DCDC_XTL_EN0                        (CTL_BASE_ANA_GLB + 0x0290)
#define ANA_REG_GLB_DCDC_XTL_EN1                        (CTL_BASE_ANA_GLB + 0x0294)
#define ANA_REG_GLB_DCDC_XTL_EN2                        (CTL_BASE_ANA_GLB + 0x0298)
#define ANA_REG_GLB_DCDC_XTL_EN3                        (CTL_BASE_ANA_GLB + 0x029C)
#define ANA_REG_GLB_LDO_XTL_EN0                         (CTL_BASE_ANA_GLB + 0x02A0)
#define ANA_REG_GLB_LDO_XTL_EN1                         (CTL_BASE_ANA_GLB + 0x02A4)
#define ANA_REG_GLB_LDO_XTL_EN2                         (CTL_BASE_ANA_GLB + 0x02A8)
#define ANA_REG_GLB_LDO_XTL_EN3                         (CTL_BASE_ANA_GLB + 0x02AC)
#define ANA_REG_GLB_LDO_XTL_EN4                         (CTL_BASE_ANA_GLB + 0x02B0)
#define ANA_REG_GLB_LDO_XTL_EN5                         (CTL_BASE_ANA_GLB + 0x02B4)
#define ANA_REG_GLB_LDO_XTL_EN6                         (CTL_BASE_ANA_GLB + 0x02B8)
#define ANA_REG_GLB_LDO_XTL_EN7                         (CTL_BASE_ANA_GLB + 0x02BC)
#define ANA_REG_GLB_LDO_XTL_EN8                         (CTL_BASE_ANA_GLB + 0x02C0)
#define ANA_REG_GLB_LDO_XTL_EN9                         (CTL_BASE_ANA_GLB + 0x02C4)
#define ANA_REG_GLB_LDO_XTL_EN10                        (CTL_BASE_ANA_GLB + 0x02C8)
#define ANA_REG_GLB_LDO_XTL_EN11                        (CTL_BASE_ANA_GLB + 0x02CC)
#define ANA_REG_GLB_LDO_XTL_EN12                        (CTL_BASE_ANA_GLB + 0x02D0)
#define ANA_REG_GLB_LDO_XTL_EN16                        (CTL_BASE_ANA_GLB + 0x02D4)
#define ANA_REG_GLB_PWR_ON_CTRL                         (CTL_BASE_ANA_GLB + 0x02D8)
#define ANA_REG_GLB_UVLO_CTRL                           (CTL_BASE_ANA_GLB + 0x02DC)
#define ANA_REG_GLB_EMM_AUTO_PD_SEL                     (CTL_BASE_ANA_GLB + 0x02E0)
#define ANA_REG_GLB_RESERVED_REG21                      (CTL_BASE_ANA_GLB + 0x02E4)
#define ANA_REG_GLB_RESERVED_REG22                      (CTL_BASE_ANA_GLB + 0x02E8)
#define ANA_REG_GLB_STEP_CLK_CTRL                       (CTL_BASE_ANA_GLB + 0x02EC)
#define ANA_REG_GLB_TSX_CTRL1                           (CTL_BASE_ANA_GLB + 0x02F0)
#define ANA_REG_GLB_TSX_CTRL2                           (CTL_BASE_ANA_GLB + 0x02F4)
#define ANA_REG_GLB_TSX_CTRL3                           (CTL_BASE_ANA_GLB + 0x02F8)
#define ANA_REG_GLB_TSX_CTRL4                           (CTL_BASE_ANA_GLB + 0x02FC)
#define ANA_REG_GLB_DCXO_XTL_EN                         (CTL_BASE_ANA_GLB + 0x0300)
#define ANA_REG_GLB_DCDC_XTL_EN5                        (CTL_BASE_ANA_GLB + 0x0304)
#define ANA_REG_GLB_DCDC_XTL_EN6                        (CTL_BASE_ANA_GLB + 0x0308)
#define ANA_REG_GLB_DCDC_XTL_EN7                        (CTL_BASE_ANA_GLB + 0x030C)
#define ANA_REG_GLB_XTL_WAKEUP_MODE_CTRL                (CTL_BASE_ANA_GLB + 0x0310)
#define ANA_REG_GLB_EXT_XTL_TX_CFG                      (CTL_BASE_ANA_GLB + 0x0314)
#define ANA_REG_GLB_RESERVED_REG23                      (CTL_BASE_ANA_GLB + 0x0318)
#define ANA_REG_GLB_RESERVED_REG10                      (CTL_BASE_ANA_GLB + 0x031C)
#define ANA_REG_GLB_DCDC_POWER_ON_STEP_SEL_CTRL         (CTL_BASE_ANA_GLB + 0x0320)
#define ANA_REG_GLB_SLP_PD_CTRL0                        (CTL_BASE_ANA_GLB + 0x0324)
#define ANA_REG_GLB_SLP_PD_CTRL1                        (CTL_BASE_ANA_GLB + 0x0328)
#define ANA_REG_GLB_SLP_PD_CTRL2                        (CTL_BASE_ANA_GLB + 0x032C)
#define ANA_REG_GLB_WAKEUP_CTRL0                        (CTL_BASE_ANA_GLB + 0x0330)
#define ANA_REG_GLB_WAKEUP_CTRL1                        (CTL_BASE_ANA_GLB + 0x0334)
#define ANA_REG_GLB_WAKEUP_CTRL2                        (CTL_BASE_ANA_GLB + 0x0338)
#define ANA_REG_GLB_LP_EN_CTRL0                         (CTL_BASE_ANA_GLB + 0x033C)
#define ANA_REG_GLB_LP_EN_CTRL1                         (CTL_BASE_ANA_GLB + 0x0340)
#define ANA_REG_GLB_LP_EN_CTRL2                         (CTL_BASE_ANA_GLB + 0x0344)
#define ANA_REG_GLB_DCXO_26M_REF_OUT_WAKEUP             (CTL_BASE_ANA_GLB + 0x0348)
#define ANA_REG_GLB_RESERVED_REG_CORE                   (CTL_BASE_ANA_GLB + 0x034C)
#define ANA_REG_GLB_RESERVED_REG_RTC                    (CTL_BASE_ANA_GLB + 0x0350)
#define ANA_REG_GLB_BG_CTRL                             (CTL_BASE_ANA_GLB + 0x0354)
#define ANA_REG_GLB_DCDC_VLG_SEL0                       (CTL_BASE_ANA_GLB + 0x0358)
#define ANA_REG_GLB_DCDC_VLG_SEL1                       (CTL_BASE_ANA_GLB + 0x035C)
#define ANA_REG_GLB_LDO_VLG_SEL0                        (CTL_BASE_ANA_GLB + 0x0360)
#define ANA_REG_GLB_LDO_VLG_SEL1                        (CTL_BASE_ANA_GLB + 0x0364)
#define ANA_REG_GLB_CLK32KSEL_CTRL0                     (CTL_BASE_ANA_GLB + 0x0368)
#define ANA_REG_GLB_CLK32KSEL_CTRL1                     (CTL_BASE_ANA_GLB + 0x036C)
#define ANA_REG_GLB_LDO_VLG_SEL2                        (CTL_BASE_ANA_GLB + 0x0370)
#define ANA_REG_GLB_RESERVED_REG33                      (CTL_BASE_ANA_GLB + 0x0374)
#define ANA_REG_GLB_XTL_WAIT_CTRL0                      (CTL_BASE_ANA_GLB + 0x0378)
#define ANA_REG_GLB_CLK_26M_SEL                         (CTL_BASE_ANA_GLB + 0x037C)
#define ANA_REG_GLB_RGB_CTRL0                           (CTL_BASE_ANA_GLB + 0x0380)
#define ANA_REG_GLB_IB_CTRL                             (CTL_BASE_ANA_GLB + 0x0384)
#define ANA_REG_GLB_KPLED_CTRL0                         (CTL_BASE_ANA_GLB + 0x0388)
#define ANA_REG_GLB_KPLED_CTRL1                         (CTL_BASE_ANA_GLB + 0x038C)
#define ANA_REG_GLB_VIBR_CTRL0                          (CTL_BASE_ANA_GLB + 0x0390)
#define ANA_REG_GLB_AUDIO_CTRL0                         (CTL_BASE_ANA_GLB + 0x0394)
#define ANA_REG_GLB_CHGR_CTRL                           (CTL_BASE_ANA_GLB + 0x0398)
#define ANA_REG_GLB_CHGR_STATUS                         (CTL_BASE_ANA_GLB + 0x039C)
#define ANA_REG_GLB_CHGR_DET_FGU_CTRL                   (CTL_BASE_ANA_GLB + 0x03A0)
#define ANA_REG_GLB_OVLO_CTRL                           (CTL_BASE_ANA_GLB + 0x03A4)
#define ANA_REG_GLB_MIXED_CTRL                          (CTL_BASE_ANA_GLB + 0x03A8)
#define ANA_REG_GLB_POR_RST_MONITOR                     (CTL_BASE_ANA_GLB + 0x03AC)
#define ANA_REG_GLB_WDG_RST_MONITOR                     (CTL_BASE_ANA_GLB + 0x03B0)
#define ANA_REG_GLB_RESERVED_REG36                      (CTL_BASE_ANA_GLB + 0x03B4)
#define ANA_REG_GLB_POR_SRC_FLAG                        (CTL_BASE_ANA_GLB + 0x03B8)
#define ANA_REG_GLB_POR_OFF_FLAG                        (CTL_BASE_ANA_GLB + 0x03BC)
#define ANA_REG_GLB_POR_7S_CTRL                         (CTL_BASE_ANA_GLB + 0x03C0)
#define ANA_REG_GLB_HWRST_RTC                           (CTL_BASE_ANA_GLB + 0x03C4)
#define ANA_REG_GLB_ARCH_EN                             (CTL_BASE_ANA_GLB + 0x03C8)
#define ANA_REG_GLB_MCU_WR_PROT_VALUE                   (CTL_BASE_ANA_GLB + 0x03CC)
#define ANA_REG_GLB_PWR_WR_PROT_VALUE                   (CTL_BASE_ANA_GLB + 0x03D0)
#define ANA_REG_GLB_DCDC_WR_PROT_VALUE                  (CTL_BASE_ANA_GLB + 0x03D4)
#define ANA_REG_GLB_POR_WR_PROT_VALUE                   (CTL_BASE_ANA_GLB + 0x03D8)
#define ANA_REG_GLB_SMPL_CTRL0                          (CTL_BASE_ANA_GLB + 0x03DC)
#define ANA_REG_GLB_SMPL_CTRL1                          (CTL_BASE_ANA_GLB + 0x03E0)
#define ANA_REG_GLB_RTC_RST0                            (CTL_BASE_ANA_GLB + 0x03E4)
#define ANA_REG_GLB_RTC_RST1                            (CTL_BASE_ANA_GLB + 0x03E8)
#define ANA_REG_GLB_RTC_RST2                            (CTL_BASE_ANA_GLB + 0x03EC)
#define ANA_REG_GLB_RTC_CLK_STOP                        (CTL_BASE_ANA_GLB + 0x03F0)
#define ANA_REG_GLB_VBAT_DROP_CNT                       (CTL_BASE_ANA_GLB + 0x03F4)
#define ANA_REG_GLB_SWRST_CTRL0                         (CTL_BASE_ANA_GLB + 0x03F8)
#define ANA_REG_GLB_HW_RST_CTRL                         (CTL_BASE_ANA_GLB + 0x03FC)
#define ANA_REG_GLB_SWRST_CTRL1                         (CTL_BASE_ANA_GLB + 0x0400)
#define ANA_REG_GLB_OTP_CTRL                            (CTL_BASE_ANA_GLB + 0x0404)
#define ANA_REG_GLB_FREE_TIMER_LOW                      (CTL_BASE_ANA_GLB + 0x0408)
#define ANA_REG_GLB_FREE_TIMER_HIGH                     (CTL_BASE_ANA_GLB + 0x040C)
#define ANA_REG_GLB_LOW_PWR_CLK32K_CTRL                 (CTL_BASE_ANA_GLB + 0x0410)
#define ANA_REG_GLB_VOL_TUNE_CTRL_CORE                  (CTL_BASE_ANA_GLB + 0x0414)
#define ANA_REG_GLB_VOL_TUNE_CTRL_CPU2                  (CTL_BASE_ANA_GLB + 0x0418)
#define ANA_REG_GLB_VOL_TUNE_CTRL_GPU                   (CTL_BASE_ANA_GLB + 0x041C)
#define ANA_REG_GLB_VOL_TUNE_CTRL_PUB                   (CTL_BASE_ANA_GLB + 0x0420)
#define ANA_REG_GLB_DCDC_DVFS_EN                        (CTL_BASE_ANA_GLB + 0x0424)
#define ANA_REG_GLB_RESERVED_REG42                      (CTL_BASE_ANA_GLB + 0x0428)
#define ANA_REG_GLB_RESERVED_REG38                      (CTL_BASE_ANA_GLB + 0x042C)
#define ANA_REG_GLB_RESERVED_REG39                      (CTL_BASE_ANA_GLB + 0x0430)
#define ANA_REG_GLB_RESERVED_REG40                      (CTL_BASE_ANA_GLB + 0x0434)
#define ANA_REG_GLB_BC1P2_CTRL_REG1                     (CTL_BASE_ANA_GLB + 0x0438)
#define ANA_REG_GLB_BC1P2_CTRL_REG2                     (CTL_BASE_ANA_GLB + 0x043C)
#define ANA_REG_GLB_DCDC_CPU1_REG0                      (CTL_BASE_ANA_GLB + 0x0440)
#define ANA_REG_GLB_DCDC_CPU1_REG1                      (CTL_BASE_ANA_GLB + 0x0444)
#define ANA_REG_GLB_DCDC_CPU1_REG2                      (CTL_BASE_ANA_GLB + 0x0448)
#define ANA_REG_GLB_DCDC_CPU1_VOL                       (CTL_BASE_ANA_GLB + 0x044C)
#define ANA_REG_GLB_RESERVED_REG8                       (CTL_BASE_ANA_GLB + 0x0450)
#define ANA_REG_GLB_DCDC_VLG_SEL2                       (CTL_BASE_ANA_GLB + 0x0454)
#define ANA_REG_GLB_XTL_WAIT_CTRL1                      (CTL_BASE_ANA_GLB + 0x0458)
#define ANA_REG_GLB_LDO_VDDCAMA2_REG0                   (CTL_BASE_ANA_GLB + 0x0460)
#define ANA_REG_GLB_LDO_VDDCAMA2_REG1                   (CTL_BASE_ANA_GLB + 0x0464)
#define ANA_REG_GLB_RESERVED_REG24                      (CTL_BASE_ANA_GLB + 0x0468)
#define ANA_REG_GLB_LDO_XTL_EN13                        (CTL_BASE_ANA_GLB + 0x046C)
#define ANA_REG_GLB_LDO_XTL_EN14                        (CTL_BASE_ANA_GLB + 0x0470)
#define ANA_REG_GLB_LDO_VLG_SEL3                        (CTL_BASE_ANA_GLB + 0x0474)
#define ANA_REG_GLB_SLP_LDO_PD_CTRL2                    (CTL_BASE_ANA_GLB + 0x0478)
#define ANA_REG_GLB_SLP_LDO_LP_CTRL2                    (CTL_BASE_ANA_GLB + 0x047C)
#define ANA_REG_GLB_LDO_VDDLDO3_REG0                    (CTL_BASE_ANA_GLB + 0x0480)
#define ANA_REG_GLB_LDO_VDDLDO3_REG1                    (CTL_BASE_ANA_GLB + 0x0484)
#define ANA_REG_GLB_RESERVED_REG25                      (CTL_BASE_ANA_GLB + 0x0488)
#define ANA_REG_GLB_LDO_VDDCAMD2_REG0                   (CTL_BASE_ANA_GLB + 0x048C)
#define ANA_REG_GLB_LDO_VDDCAMD2_REG1                   (CTL_BASE_ANA_GLB + 0x0490)
#define ANA_REG_GLB_RESERVED_REG26                      (CTL_BASE_ANA_GLB + 0x0494)
#define ANA_REG_GLB_LDO_VDDRF1V1_REG0                   (CTL_BASE_ANA_GLB + 0x0498)
#define ANA_REG_GLB_LDO_VDDRF1V1_REG1                   (CTL_BASE_ANA_GLB + 0x049C)
#define ANA_REG_GLB_RESERVED_REG27                      (CTL_BASE_ANA_GLB + 0x04A0)
#define ANA_REG_GLB_LDO_VDDRF0V9_REG0                   (CTL_BASE_ANA_GLB + 0x04A4)
#define ANA_REG_GLB_LDO_VDDRF0V9_REG1                   (CTL_BASE_ANA_GLB + 0x04A8)
#define ANA_REG_GLB_RESERVED92                          (CTL_BASE_ANA_GLB + 0x04AC)
#define ANA_REG_GLB_LDO_VDDUFS1V2_REG0                  (CTL_BASE_ANA_GLB + 0x04B0)
#define ANA_REG_GLB_LDO_VDDUFS1V2_REG1                  (CTL_BASE_ANA_GLB + 0x04B4)
#define ANA_REG_GLB_RESERVED_REG28                      (CTL_BASE_ANA_GLB + 0x04B8)
#define ANA_REG_GLB_LDO_XTL_EN15                        (CTL_BASE_ANA_GLB + 0x04BC)
#define ANA_REG_GLB_CHG_IRQ_CLR                         (CTL_BASE_ANA_GLB + 0x04C0)
#define ANA_REG_GLB_RESERVED_REG29                      (CTL_BASE_ANA_GLB + 0x04C4)
#define ANA_REG_GLB_VOL_TUNE_CTRL_CPU1                  (CTL_BASE_ANA_GLB + 0x04C8)
#define ANA_REG_GLB_DCDC_CPU1_REG3                      (CTL_BASE_ANA_GLB + 0x04CC)
#define ANA_REG_GLB_LDO_VDDLDO4_REG0                    (CTL_BASE_ANA_GLB + 0x04D0)
#define ANA_REG_GLB_LDO_VDDLDO4_REG1                    (CTL_BASE_ANA_GLB + 0x04D4)

#define ANA_REG_GLB_ARM_MODULE_EN               ANA_REG_GLB_MODULE_EN0
#define ANA_REG_GLB_RTC_CLK_EN                  ANA_REG_GLB_RTC_CLK_EN0
#define ANA_REG_GLB_ARM_CLK_EN                  ANA_REG_GLB_ARM_CLK_EN0
#define ANA_REG_GLB_XTL_WAIT_CTRL               ANA_REG_GLB_XTL_WAIT_CTRL0

#define ANA_REG_GLB_CLK32KLESS_CTRL0 			0 //this register is not exist

/* bits definitions for REG_CHIP_ID_LOW, [0x00002000] */
#define BIT_CHIP_ID_LOW(x)                      ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_CHIP_ID_HIGH, [0x00002004] */
#define BIT_CHIP_ID_HIGH(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MODULE_EN0, [0x00002008] */
#define BIT_TYPEC_EN                            ( BIT(14) )
#define BIT_PD_EN                               ( BIT(13) )
#define BIT_TMR_EN                              ( BIT(12) )
#define BIT_FAST_CHG_EN                         ( BIT(11) )
#define BIT_BLTC_EN                             ( BIT(9) )
#define BIT_PINREG_EN                           ( BIT(8) )
#define BIT_FGU_EN                              ( BIT(7) )
#define BIT_EFS_EN                              ( BIT(6) )
#define BIT_ADC_EN                              ( BIT(5) )
#define BIT_AUD_EN                              ( BIT(4) )
#define BIT_EIC_EN                              ( BIT(3) )
#define BIT_WDG_EN                              ( BIT(2) )
#define BIT_RTC_EN                              ( BIT(1) )

#define BIT_ANA_WDG_EN                  		 BIT_WDG_EN
#define BIT_ANA_ADC_EN                  		 BIT_ADC_EN
#define BIT_ANA_FGU_EN                  		 BIT_FGU_EN
#define BIT_ANA_EIC_EN                  		 BIT_EIC_EN
#define BIT_ANA_RTC_EN                  		 BIT_RTC_EN
#define BIT_ANA_EFS_EN                   		 BIT_EFS_EN

/* bits definitions for REG_ARM_CLK_EN0, [0x0000200C] */
#define BIT_CLK_PD_SEL                          ( BIT(10) )
#define BIT_CLK_PD_EN                           ( BIT(9) )
#define BIT_CLK_AUD_SCLK_EN                     ( BIT(7) )
#define BIT_CLK_AUXAD_EN                        ( BIT(6) )
#define BIT_CLK_AUXADC_EN                       ( BIT(5) )
#define BIT_CLK_AUD_IF_6P5M_EN                  ( BIT(1) )
#define BIT_CLK_AUD_IF_EN                       ( BIT(0) )

/* bits definitions for REG_RTC_CLK_EN0, [0x00002010] */
#define BIT_RTC_PD_EN                           ( BIT(15) )
#define BIT_RTC_TYPEC_EN                        ( BIT(14) )
#define BIT_RTC_TMR_EN                          ( BIT(13) )
#define BIT_RTC_EFS_EN                          ( BIT(11) )
#define BIT_RTC_BLTC_EN                         ( BIT(7) )
#define BIT_RTC_FGU_EN                          ( BIT(6) )
#define BIT_RTC_FAST_CHG_EN                     ( BIT(4) )
#define BIT_RTC_EIC_EN                          ( BIT(3) )
#define BIT_RTC_WDG_EN                          ( BIT(2) )
#define BIT_RTC_RTC_EN                          ( BIT(1) )
#define BIT_RTC_ARCH_EN                         ( BIT(0) )

/* bits definitions for REG_SOFT_RST0, [0x00002014] */
#define BIT_AUDRX_SOFT_RST                      ( BIT(13) )
#define BIT_AUDTX_SOFT_RST                      ( BIT(12) )
#define BIT_BLTC_SOFT_RST                       ( BIT(9) )
#define BIT_AUD_SOFT_RST                        ( BIT(8) )
#define BIT_EFS_SOFT_RST                        ( BIT(7) )
#define BIT_ADC_SOFT_RST                        ( BIT(6) )
#define BIT_FGU_SOFT_RST                        ( BIT(4) )
#define BIT_EIC_SOFT_RST                        ( BIT(3) )
#define BIT_WDG_SOFT_RST                        ( BIT(2) )
#define BIT_RTC_SOFT_RST                        ( BIT(1) )

/* bits definitions for REG_SOFT_RST1, [0x00002018] */
#define BIT_TYPEC_SOFT_RST                      ( BIT(3) )
#define BIT_PD_SOFT_RST                         ( BIT(2) )
#define BIT_TMR_SOFT_RST                        ( BIT(1) )
#define BIT_FAST_CHG_SOFT_RST                   ( BIT(0) )

/* bits definitions for REG_POWER_PD_SW, [0x0000201C] */
#define BIT_LDO_VDD18_DCXO_PD                   ( BIT(14) )
#define BIT_DCDC_SRAM0_PD                       ( BIT(13) )
#define BIT_DCDC_MEMQ_PD                        ( BIT(12) )
#define BIT_DCDC_PUB_PD                         ( BIT(11) )
#define BIT_DCDC_CPU1_PD                        ( BIT(10) )
#define BIT_LDO_EMM_PD                          ( BIT(9) )
#define BIT_DCDC_GEN0_PD                        ( BIT(8) )
#define BIT_DCDC_GEN1_PD                        ( BIT(7) )
#define BIT_DCDC_MEM_PD                         ( BIT(6) )
#define BIT_DCDC_CORE_PD                        ( BIT(5) )
#define BIT_DCDC_CPU2_PD                        ( BIT(4) )
#define BIT_DCDC_GPU_PD                         ( BIT(3) )
#define BIT_LDO_AVDD18_PD                       ( BIT(2) )
#define BIT_LDO_VDD28_PD                        ( BIT(1) )
#define BIT_BG_PD                               ( BIT(0) )

/* bits definitions for REG_POWER_PD_HW, [0x00002020] */
#define BIT_PWR_OFF_SEQ_EN                      ( BIT(0) )

/* bits definitions for REG_SOFT_RST_HW, [0x00002024] */
#define BIT_REG_SOFT_RST                        ( BIT(0) )

/* bits definitions for REG_AUXAD_VSS_CTRL, [0x00002028] */
#define BIT_AUXAD_VSS_SEL                       ( BIT(0) )

/* bits definitions for REG_ADI_ACK_BIT_OPT_CTRL, [0x0000202C] */
#define BIT_ACK_BIT_OPT                         ( BIT(0) )

/* bits definitions for REG_RESERVED_REG1, [0x00002030] */

/* bits definitions for REG_RESERVED_REG2, [0x00002034] */

/* bits definitions for REG_DCDC_CPU2_REG0, [0x00002038] */
#define BIT_DCDC_CPU2_DEADTIME(x)               ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_CPU2_PDRSLOW(x)                ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_CPU2_PFMB                      ( BIT(2) )
#define BIT_DCDC_CPU2_DCMB                      ( BIT(1) )

/* bits definitions for REG_DCDC_CPU2_REG1, [0x0000203C] */
#define BIT_DCDC_CPU2_CF(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_CPU2_CL_CTRL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_CPU2_REG2, [0x00002040] */
#define BIT_DCDC_CPU2_STBOP(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_CPU2_ZCD(x)                    ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_CPU2_PFMAD(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_CPU2_VOL, [0x00002044] */
#define BIT_FRACTION_DIV_CPU2(x)                ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_INTEGER_DIV_CPU2(x)                 ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_DCDC_CPU2_CTRL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_DCDC_GPU_REG0, [0x00002048] */
#define BIT_DCDC_GPU_DEADTIME(x)                ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_GPU_PDRSLOW(x)                 ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_GPU_PFMB                       ( BIT(2) )
#define BIT_DCDC_GPU_DCMB                       ( BIT(1) )

/* bits definitions for REG_DCDC_GPU_REG1, [0x0000204C] */
#define BIT_DCDC_GPU_CF(x)                      ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_GPU_CL_CTRL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_GPU_REG2, [0x00002050] */
#define BIT_DCDC_GPU_STBOP(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_GPU_ZCD(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_GPU_PFMAD(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_GPU_VOL, [0x00002054] */
#define BIT_FRACTION_DIV_GPU(x)                 ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_INTEGER_DIV_GPU(x)                  ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_DCDC_GPU_CTRL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_DCDC_CORE_REG0, [0x00002058] */
#define BIT_DCDC_CORE_DEADTIME(x)               ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_CORE_PDRSLOW(x)                ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_CORE_PFMB                      ( BIT(2) )
#define BIT_DCDC_CORE_DCMB                      ( BIT(1) )

/* bits definitions for REG_DCDC_CORE_REG1, [0x0000205C] */
#define BIT_DCDC_CORE_CF(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_CORE_CL_CTRL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_CORE_REG2, [0x00002060] */
#define BIT_DCDC_CORE_STBOP(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_CORE_ZCD(x)                    ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_CORE_PFMAD(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_CORE_VOL, [0x00002064] */
#define BIT_FRACTION_DIV_CORE(x)                ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_INTEGER_DIV_CORE(x)                 ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_DCDC_CORE_CTRL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_DCDC_PUB_REG0, [0x00002068] */
#define BIT_DCDC_PUB_DEADTIME(x)                ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_PUB_PDRSLOW(x)                 ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_PUB_PFMB                       ( BIT(2) )
#define BIT_DCDC_PUB_DCMB                       ( BIT(1) )

/* bits definitions for REG_DCDC_PUB_REG1, [0x0000206C] */
#define BIT_DCDC_PUB_CF(x)                      ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_PUB_CL_CTRL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_PUB_REG2, [0x00002070] */
#define BIT_DCDC_PUB_STBOP(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_PUB_ZCD(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_PUB_PFMAD(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_PUB_VOL, [0x00002074] */
#define BIT_FRACTION_DIV_PUB(x)                 ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_INTEGER_DIV_PUB(x)                  ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_DCDC_PUB_CTRL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_DCDC_MEM_REG0, [0x00002078] */
#define BIT_DCDC_MEM_DEADTIME(x)                ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_MEM_PDRSLOW(x)                 ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_MEM_PFMB                       ( BIT(2) )
#define BIT_DCDC_MEM_DCMB                       ( BIT(1) )

/* bits definitions for REG_DCDC_MEM_REG1, [0x0000207C] */
#define BIT_DCDC_MEM_CF(x)                      ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_MEM_CL_CTRL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_MEM_REG2, [0x00002080] */
#define BIT_DCDC_MEM_STBOP(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_MEM_ZCD(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_MEM_PFMAD(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_MEM_VOL, [0x00002084] */
#define BIT_DCDC_MEM_CTRL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_DCDC_MEMQ_REG0, [0x00002088] */
#define BIT_DCDC_MEMQ_DEADTIME(x)               ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_MEMQ_PDRSLOW(x)                ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_MEMQ_PFMB                      ( BIT(2) )
#define BIT_DCDC_MEMQ_DCMB                      ( BIT(1) )

/* bits definitions for REG_DCDC_MEMQ_REG1, [0x0000208C] */
#define BIT_DCDC_MEMQ_CF(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_MEMQ_CL_CTRL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_MEMQ_REG2, [0x00002090] */
#define BIT_DCDC_MEMQ_STBOP(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_MEMQ_ZCD(x)                    ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_MEMQ_PFMAD(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_MEMQ_VOL, [0x00002094] */
#define BIT_DCDC_MEMQ_CTRL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_DCDC_GEN0_REG0, [0x00002098] */
#define BIT_DCDC_GEN0_DEADTIME(x)               ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_GEN0_PDRSLOW(x)                ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_GEN0_PFMB                      ( BIT(2) )
#define BIT_DCDC_GEN0_DCMB                      ( BIT(1) )

/* bits definitions for REG_DCDC_GEN0_REG1, [0x0000209C] */
#define BIT_DCDC_GEN0_CF(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_GEN0_CL_CTRL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_GEN0_REG2, [0x000020A0] */
#define BIT_DCDC_GEN0_STBOP(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_GEN0_ZCD(x)                    ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_GEN0_PFMAD(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_GEN0_VOL, [0x000020A4] */
#define BIT_DCDC_GEN0_CTRL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_DCDC_GEN1_REG0, [0x000020A8] */
#define BIT_DCDC_GEN1_DEADTIME(x)               ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_GEN1_PDRSLOW(x)                ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_GEN1_PFMB                      ( BIT(2) )
#define BIT_DCDC_GEN1_DCMB                      ( BIT(1) )

/* bits definitions for REG_DCDC_GEN1_REG1, [0x000020AC] */
#define BIT_DCDC_GEN1_CF(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_GEN1_CL_CTRL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_GEN1_REG2, [0x000020B0] */
#define BIT_DCDC_GEN1_STBOP(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_GEN1_ZCD(x)                    ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_GEN1_PFMAD(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_GEN1_VOL, [0x000020B4] */
#define BIT_DCDC_GEN1_CTRL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_DCDC_WPA_REG0, [0x000020B8] */
#define BIT_DCDC_WPA_DEADTIME(x)                ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_WPA_PDRSLOW(x)                 ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_WPA_CF(x)                      ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_DCDC_WPA_CL_CTRL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_WPA_REG1, [0x000020BC] */
#define BIT_DCDC_WPA_OS_DET_EN                  ( BIT(15) )
#define BIT_DCDC_WPA_VBAT_DIV(x)                ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_DCDC_WPA_BPEN                       ( BIT(11) )
#define BIT_DCDC_WPA_BPMODE                     ( BIT(10) )
#define BIT_DCDC_WPA_DEGEN                      ( BIT(9) )
#define BIT_DCDC_WPA_APTEN                      ( BIT(8) )
#define BIT_DCDC_WPA_DEBC_SEL(x)                ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_DCDC_WPA_FRTHRD(x)                  ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_WPA_FREN                       ( BIT(3) )
#define BIT_DCDC_WPA_DEG_CUR_SEL                ( BIT(2) )
#define BIT_DCDC_WPA_PFMB                       ( BIT(1) )
#define BIT_DCDC_WPA_APT2P5XEN                  ( BIT(0) )

/* bits definitions for REG_DCDC_WPA_REG2, [0x000020C0] */
#define BIT_DCDC_WPA_PD                         ( BIT(5) )
#define BIT_DCDC_WPA_VREF_CAL(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_DCDC_WPA_REG3, [0x000020C4] */
#define BIT_DCDC_WPA_STBOP(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_WPA_ZCD(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_WPA_PFMAD(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_WPA_VOL, [0x000020C8] */
#define BIT_DCDC_WPA_FR_CUR_CTRL(x)             ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_DCDC_WPA_FR_EMI_CTRL(x)             ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_DCDC_WPA_CTRL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_DCDC_WPA_DCMB, [0x000020CC] */
#define BIT_DCDC_WPA_DCMB                       ( BIT(0) )

/* bits definitions for REG_DCDC_SRAM0_REG0, [0x000020D0] */
#define BIT_DCDC_SRAM0_DEADTIME(x)              ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_SRAM0_PDRSLOW(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_SRAM0_PFMB                     ( BIT(2) )
#define BIT_DCDC_SRAM0_DCMB                     ( BIT(1) )

/* bits definitions for REG_DCDC_SRAM0_REG1, [0x000020D4] */
#define BIT_DCDC_SRAM0_CF(x)                    ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_SRAM0_CL_CTRL(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_SRAM0_REG2, [0x000020D8] */
#define BIT_DCDC_SRAM0_STBOP(x)                 ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_SRAM0_ZCD(x)                   ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_SRAM0_PFMAD(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_SRAM0_VOL, [0x000020DC] */
#define BIT_FRACTION_DIV_SRAM0(x)               ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_INTEGER_DIV_SRAM0(x)                ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_DCDC_SRAM0_CTRL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_RESERVED_REG43, [0x000020E0] */

/* bits definitions for REG_DCDC_CH_CTRL, [0x000020E4] */
#define BIT_DCDC_CAL_SEL(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_CTRL, [0x000020E8] */
#define BIT_DCDC_OSCCLK_OPTION(x)               ( (x) << 11 & (BIT(11)|BIT(12)) )

/* bits definitions for REG_DCDC_CLK_CTRL, [0x000020EC] */
#define BIT_DCDC_6MCLKOUT_EN                    ( BIT(13) )
#define BIT_DCDC_6MFRECAL_SW(x)                 ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_CLK6M_AUTOGATE_DELAY(x)             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_6MCLKOUT_GATE_SW               ( BIT(3) )
#define BIT_DCDC_6MCLKOUT_AUTOGATE_EN           ( BIT(2) )
#define BIT_DCDC_CLK_SP_SEL                     ( BIT(1) )
#define BIT_DCDC_CLK_SP_EN                      ( BIT(0) )

/* bits definitions for REG_RESERVED_REG3, [0x000020F0] */

/* bits definitions for REG_RESERVED_REG4, [0x000020F4] */

/* bits definitions for REG_RESERVED_REG6, [0x000020F8] */

/* bits definitions for REG_RESERVED_REG7, [0x000020FC] */

/* bits definitions for REG_RESERVED_REG5, [0x00002100] */

/* bits definitions for REG_LDO_AVDD18_REG1, [0x00002104] */
#define BIT_LDO_AVDD18_V(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_AVDD18_REG2, [0x00002108] */
#define BIT_LDO_AVDD18_SHPT_PD                  ( BIT(5) )
#define BIT_LDO_AVDD18_REFTRIM(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_LDO_VDDRF1V8_REG0, [0x0000210C] */
#define BIT_LDO_VDDRF1V8_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDRF1V8_REG1, [0x00002110] */
#define BIT_LDO_VDDRF1V8_V(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDRF1V8_REG2, [0x00002114] */
#define BIT_LDO_VDDRF1V8_SHPT_PD                ( BIT(5) )
#define BIT_LDO_VDDRF1V8_REFTRIM(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_LDO_VDDCAMIO_REG0, [0x00002118] */
#define BIT_LDO_VDDCAMIO_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDWCN_REG0, [0x0000211C] */
#define BIT_LDO_VDDWCN_PD                       ( BIT(0) )

/* bits definitions for REG_LDO_VDDWCN_REG1, [0x00002120] */
#define BIT_LDO_VDDWCN_V(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDWCN_REG2, [0x00002124] */
#define BIT_LDO_VDDWCN_SHPT_PD                  ( BIT(5) )
#define BIT_LDO_VDDWCN_REFTRIM(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_LDO_VDDCAMD1_REG0, [0x00002128] */
#define BIT_LDO_VDDCAMD1_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDCAMD1_REG1, [0x0000212C] */
#define BIT_LDO_VDDCAMD1_V(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_LDO_VDDCAMD1_REG2, [0x00002130] */
#define BIT_LDO_VDDCAMD1_SHPT_PD                ( BIT(5) )
#define BIT_LDO_VDDCAMD1_REFTRIM(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_LDO_VDDCAMD0_REG0, [0x00002134] */
#define BIT_LDO_VDDCAMD0_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDCAMD0_REG1, [0x00002138] */
#define BIT_LDO_VDDCAMD0_V(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_LDO_VDDCAMD0_REG2, [0x0000213C] */
#define BIT_LDO_VDDCAMD0_SHPT_PD                ( BIT(5) )
#define BIT_LDO_VDDCAMD0_REFTRIM(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_LDO_VDDCAMMOT1_REG0, [0x00002140] */
#define BIT_LDO_VDDCAMMOT1_PD                   ( BIT(0) )

/* bits definitions for REG_LDO_VDDCAMMOT1_REG1, [0x00002144] */
#define BIT_LDO_VDDCAMMOT1_V(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDCAMMOT1_REG2, [0x00002148] */
#define BIT_LDO_VDDCAMMOT1_SHPT_PD              ( BIT(6) )
#define BIT_LDO_VDDCAMMOT1_REFTRIM(x)           ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_AVDD12_REG0, [0x0000214C] */
#define BIT_LDO_AVDD12_PD                       ( BIT(0) )

/* bits definitions for REG_LDO_AVDD12_REG1, [0x00002150] */
#define BIT_LDO_AVDD12_V(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_LDO_AVDD12_REG2, [0x00002154] */
#define BIT_LDO_AVDD12_SHPT_PD                  ( BIT(5) )
#define BIT_LDO_AVDD12_REFTRIM(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_LDO_VDDCAMA0_REG0, [0x00002158] */
#define BIT_LDO_VDDCAMA0_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDCAMA0_REG1, [0x0000215C] */
#define BIT_LDO_VDDCAMA0_V(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDCAMA0_REG2, [0x00002160] */
#define BIT_LDO_VDDCAMA0_REFTRIM(x)             ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_LDO_VDDCAMA0_SHPT_PD                ( BIT(1) )

/* bits definitions for REG_LDO_VDDCAMA1_REG0, [0x00002164] */
#define BIT_LDO_VDDCAMA1_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDCAMA1_REG1, [0x00002168] */
#define BIT_LDO_VDDCAMA1_V(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDCAMA1_REG2, [0x0000216C] */
#define BIT_LDO_VDDCAMA1_REFTRIM(x)             ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_LDO_VDDCAMA1_SHPT_PD                ( BIT(1) )

/* bits definitions for REG_LDO_VDDCAMMOT0_REG0, [0x00002170] */
#define BIT_LDO_VDDCAMMOT0_PD                   ( BIT(0) )

/* bits definitions for REG_LDO_VDDCAMMOT0_REG1, [0x00002174] */
#define BIT_LDO_VDDCAMMOT0_V(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDCAMMOT0_REG2, [0x00002178] */
#define BIT_LDO_VDDCAMMOT0_SHPT_PD              ( BIT(6) )
#define BIT_LDO_VDDCAMMOT0_REFTRIM(x)           ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDSIM0_REG0, [0x0000217C] */
#define BIT_LDO_VDDSIM0_PD                      ( BIT(0) )

/* bits definitions for REG_LDO_VDDSIM0_REG1, [0x00002180] */
#define BIT_LDO_VDDSIM0_V(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDSIM0_REG2, [0x00002184] */
#define BIT_LDO_VDDSIM0_SHPT_PD                 ( BIT(6) )
#define BIT_LDO_VDDSIM0_REFTRIM(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDSIM1_REG0, [0x00002188] */
#define BIT_LDO_VDDSIM1_PD                      ( BIT(0) )

/* bits definitions for REG_LDO_VDDSIM1_REG1, [0x0000218C] */
#define BIT_LDO_VDDSIM1_V(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDSIM1_REG2, [0x00002190] */
#define BIT_LDO_VDDSIM1_SHPT_PD                 ( BIT(6) )
#define BIT_LDO_VDDSIM1_REFTRIM(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDSIM2_REG0, [0x00002194] */
#define BIT_LDO_VDDSIM2_PD                      ( BIT(0) )

/* bits definitions for REG_LDO_VDDSIM2_REG1, [0x00002198] */
#define BIT_LDO_VDDSIM2_V(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDSIM2_REG2, [0x0000219C] */
#define BIT_LDO_VDDSIM2_SHPT_PD                 ( BIT(6) )
#define BIT_LDO_VDDSIM2_REFTRIM(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDEMMCCORE_REG0, [0x000021A0] */
#define BIT_LDO_VDDEMMCCORE_PD                  ( BIT(0) )

/* bits definitions for REG_LDO_VDDEMMCCORE_REG1, [0x000021A4] */
#define BIT_LDO_VDDEMMCCORE_V(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDEMMCCORE_REG2, [0x000021A8] */
#define BIT_LDO_VDDEMMCCORE_CL_ADJ(x)           ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_LDO_VDDEMMCCORE_SHPT_PD             ( BIT(6) )
#define BIT_LDO_VDDEMMCCORE_REFTRIM(x)          ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDSDCORE_REG0, [0x000021AC] */
#define BIT_LDO_VDDSDCORE_PD                    ( BIT(0) )

/* bits definitions for REG_LDO_VDDSDCORE_REG1, [0x000021B0] */
#define BIT_LDO_VDDSDCORE_V(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDSDCORE_REG2, [0x000021B4] */
#define BIT_LDO_VDDSDCORE_CL_ADJ(x)             ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_LDO_VDDSDCORE_SHPT_PD               ( BIT(6) )
#define BIT_LDO_VDDSDCORE_REFTRIM(x)            ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDSDIO_REG0, [0x000021B8] */
#define BIT_LDO_VDDSDIO_PD                      ( BIT(0) )

/* bits definitions for REG_LDO_VDDSDIO_REG1, [0x000021BC] */
#define BIT_LDO_VDDSDIO_V(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDSDIO_REG2, [0x000021C0] */
#define BIT_LDO_VDDSDIO_SHPT_PD                 ( BIT(6) )
#define BIT_LDO_VDDSDIO_REFTRIM(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDD28_REG0, [0x000021C4] */

/* bits definitions for REG_LDO_VDD28_REG1, [0x000021C8] */
#define BIT_LDO_VDD28_V(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDD28_REG2, [0x000021CC] */
#define BIT_LDO_VDD28_SHPT_PD                   ( BIT(6) )
#define BIT_LDO_VDD28_REFTRIM(x)                ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDWIFIPA_REG0, [0x000021D0] */
#define BIT_LDO_VDDWIFIPA_PD                    ( BIT(0) )

/* bits definitions for REG_LDO_VDDWIFIPA_REG1, [0x000021D4] */
#define BIT_LDO_VDDWIFIPA_V(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDWIFIPA_REG2, [0x000021D8] */
#define BIT_LDO_VDDWIFIPA_CL_ADJ(x)             ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_LDO_VDDWIFIPA_SHPT_PD               ( BIT(6) )
#define BIT_LDO_VDDWIFIPA_REFTRIM(x)            ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_RESERVED_REG9, [0x000021DC] */

/* bits definitions for REG_LDO_VDD18_DCXO_REG1, [0x000021E0] */
#define BIT_LDO_VDD18_DCXO_V(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDD18_DCXO_REG2, [0x000021E4] */
#define BIT_LDO_VDD18_DCXO_REFTRIM_LP(x)        ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_LDO_VDD18_DCXO_SHPT_PD              ( BIT(6) )
#define BIT_LDO_VDD18_DCXO_REFTRIM(x)           ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDUSB33_REG0, [0x000021E8] */
#define BIT_LDO_VDDUSB33_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDUSB33_REG1, [0x000021EC] */
#define BIT_LDO_VDDUSB33_V(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDUSB33_REG2, [0x000021F0] */
#define BIT_LDO_VDDUSB33_SHPT_PD                ( BIT(6) )
#define BIT_LDO_VDDUSB33_REFTRIM(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDLDO0_REG0, [0x000021F4] */
#define BIT_LDO_VDDLDO0_PD                      ( BIT(0) )

/* bits definitions for REG_LDO_VDDLDO0_REG1, [0x000021F8] */
#define BIT_LDO_VDDLDO0_V(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDLDO0_REG2, [0x000021FC] */
#define BIT_LDO_VDDLDO0_SHPT_PD                 ( BIT(6) )
#define BIT_LDO_VDDLDO0_REFTRIM(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDLDO1_REG0, [0x00002200] */
#define BIT_LDO_VDDLDO1_PD                      ( BIT(0) )

/* bits definitions for REG_LDO_VDDLDO1_REG1, [0x00002204] */
#define BIT_LDO_VDDLDO1_V(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDLDO1_REG2, [0x00002208] */
#define BIT_LDO_VDDLDO1_SHPT_PD                 ( BIT(6) )
#define BIT_LDO_VDDLDO1_REFTRIM(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_VDDLDO2_REG0, [0x0000220C] */
#define BIT_LDO_VDDLDO2_PD                      ( BIT(0) )

/* bits definitions for REG_LDO_VDDLDO2_REG1, [0x00002210] */
#define BIT_LDO_VDDLDO2_V(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_LDO_VDDLDO2_REG2, [0x00002214] */
#define BIT_LDO_VDDLDO2_CL_ADJ(x)               ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_LDO_VDDLDO2_SHPT_PD                 ( BIT(6) )
#define BIT_LDO_VDDLDO2_REFTRIM(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_LDO_RTC_CTRL, [0x00002228] */
#define BIT_RC1M_CAL(x)                         ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_LDO_RTC_CAL(x)                      ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_LDO_RTC_V(x)                        ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_VBATBK_V(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_LDO_CH_CTRL, [0x0000222C] */
#define BIT_LDODCDC_CAL_SEL(x)                  ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_LDOA_CAL_SEL(x)                     ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_LDOB_CAL_SEL(x)                     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_RESERVED_REG12, [0x00002230] */

/* bits definitions for REG_RESERVED_REG13, [0x00002234] */

/* bits definitions for REG_RESERVED_REG14, [0x00002238] */

/* bits definitions for REG_RESERVED_REG15, [0x0000223C] */

/* bits definitions for REG_RESERVED_REG16, [0x00002240] */

/* bits definitions for REG_RESERVED_REG17, [0x00002244] */

/* bits definitions for REG_SLP_CTRL, [0x00002248] */
#define BIT_LDO_XTL_EN                          ( BIT(2) )
#define BIT_SLP_IO_EN                           ( BIT(1) )
#define BIT_SLP_LDO_PD_EN                       ( BIT(0) )

/* bits definitions for REG_SLP_DCDC_PD_CTRL, [0x0000224C] */
#define BIT_SLP_DCDCPUB_PD_EN                   ( BIT(10) )
#define BIT_SLP_DCDCMEMQ_PD_EN                  ( BIT(9) )
#define BIT_SLP_DCDCSRAM0_PD_EN                 ( BIT(8) )
#define BIT_SLP_DCDCSRAM0_DROP_EN               ( BIT(7) )
#define BIT_SLP_DCDCPUB_DROP_EN                 ( BIT(6) )
#define BIT_SLP_DCDCGPU_DROP_EN                 ( BIT(5) )
#define BIT_SLP_DCDCCORE_DROP_EN                ( BIT(4) )
#define BIT_SLP_DCDCWPA_PD_EN                   ( BIT(3) )
#define BIT_SLP_DCDCGPU_PD_EN                   ( BIT(2) )
#define BIT_SLP_DCDCGEN1_PD_EN                  ( BIT(0) )

/* bits definitions for REG_SLP_LDO_PD_CTRL0, [0x00002250] */
#define BIT_SLP_LDO_VDDRF1V1_PD_EN              ( BIT(15) )
#define BIT_SLP_LDO_VDDRF1V8_PD_EN              ( BIT(14) )
#define BIT_SLP_LDO_VDDRF0V9_PD_EN              ( BIT(13) )
#define BIT_SLP_LDO_VDDEMMCCORE_PD_EN           ( BIT(12) )
#define BIT_SLP_LDO_VDD18_DCXO_PD_EN            ( BIT(11) )
#define BIT_SLP_LDO_VDDWIFIPA_PD_EN             ( BIT(10) )
#define BIT_SLP_LDO_VDD28_PD_EN                 ( BIT(9) )
#define BIT_SLP_LDO_VDDSDCORE_PD_EN             ( BIT(8) )
#define BIT_SLP_LDO_VDDSDIO_PD_EN               ( BIT(7) )
#define BIT_SLP_LDO_VDDUSB33_PD_EN              ( BIT(6) )
#define BIT_SLP_LDO_VDDCAMMOT0_PD_EN            ( BIT(5) )
#define BIT_SLP_LDO_VDDCAMIO_PD_EN              ( BIT(4) )
#define BIT_SLP_LDO_VDDCAMD0_PD_EN              ( BIT(3) )
#define BIT_SLP_LDO_VDDCAMA0_PD_EN              ( BIT(2) )
#define BIT_SLP_LDO_VDDSIM2_PD_EN               ( BIT(1) )
#define BIT_SLP_LDO_VDDSIM1_PD_EN               ( BIT(0) )

/* bits definitions for REG_SLP_LDO_PD_CTRL1, [0x00002254] */
#define BIT_SLP_LDO_VDDUFS1V2_PD_EN             ( BIT(12) )
#define BIT_SLP_LDO_VDDLDO4_PD_EN               ( BIT(11) )
#define BIT_SLP_LDO_VDDLDO3_PD_EN               ( BIT(10) )
#define BIT_SLP_LDO_VDDCAMMOT1_PD_EN            ( BIT(9) )
#define BIT_SLP_LDO_VDDLDO2_PD_EN               ( BIT(8) )
#define BIT_SLP_LDO_AVDD12_PD_EN                ( BIT(7) )
#define BIT_SLP_LDO_VDDWCN_PD_EN                ( BIT(6) )
#define BIT_SLP_LDO_VDDLDO0_PD_EN               ( BIT(5) )
#define BIT_SLP_LDO_VDDCAMD1_PD_EN              ( BIT(4) )
#define BIT_SLP_LDO_VDDCAMA1_PD_EN              ( BIT(3) )
#define BIT_SLP_LDO_VDDSIM0_PD_EN               ( BIT(2) )
#define BIT_SLP_LDO_AVDD18_PD_EN                ( BIT(1) )
#define BIT_SLP_LDO_VDDLDO1_PD_EN               ( BIT(0) )

/* bits definitions for REG_SLP_DCDC_LP_CTRL, [0x00002258] */
#define BIT_SLP_DCDCSRAM0_LP_EN                 ( BIT(9) )
#define BIT_SLP_DCDCPUB_LP_EN                   ( BIT(8) )
#define BIT_SLP_DCDCMEMQ_LP_EN                  ( BIT(7) )
#define BIT_SLP_DCDCMEM_LP_EN                   ( BIT(6) )
#define BIT_SLP_DCDCGPU_LP_EN                   ( BIT(5) )
#define BIT_SLP_DCDCCORE_LP_EN                  ( BIT(4) )
#define BIT_SLP_DCDCGEN1_LP_EN                  ( BIT(2) )
#define BIT_SLP_DCDCGEN0_LP_EN                  ( BIT(1) )
#define BIT_SLP_DCDCWPA_LP_EN                   ( BIT(0) )

/* bits definitions for REG_SLP_LDO_LP_CTRL0, [0x0000225C] */
#define BIT_SLP_LDO_VDDUFS1V2_LP_EN             ( BIT(15) )
#define BIT_SLP_LDO_VDDRF1V8_LP_EN              ( BIT(14) )
#define BIT_SLP_LDO_VDDRF0V9_LP_EN              ( BIT(13) )
#define BIT_SLP_LDO_VDDEMMCCORE_LP_EN           ( BIT(12) )
#define BIT_SLP_LDO_VDD18_DCXO_LP_EN            ( BIT(11) )
#define BIT_SLP_LDO_VDDWIFIPA_LP_EN             ( BIT(10) )
#define BIT_SLP_LDO_VDD28_LP_EN                 ( BIT(9) )
#define BIT_SLP_LDO_VDDSDCORE_LP_EN             ( BIT(8) )
#define BIT_SLP_LDO_VDDSDIO_LP_EN               ( BIT(7) )
#define BIT_SLP_LDO_VDDUSB33_LP_EN              ( BIT(6) )
#define BIT_SLP_LDO_VDDCAMMOT0_LP_EN            ( BIT(5) )
#define BIT_SLP_LDO_VDDRF1V1_LP_EN              ( BIT(4) )
#define BIT_SLP_LDO_VDDCAMD0_LP_EN              ( BIT(3) )
#define BIT_SLP_LDO_VDDCAMA0_LP_EN              ( BIT(2) )
#define BIT_SLP_LDO_VDDSIM2_LP_EN               ( BIT(1) )
#define BIT_SLP_LDO_VDDSIM1_LP_EN               ( BIT(0) )

/* bits definitions for REG_SLP_LDO_LP_CTRL1, [0x00002260] */
#define BIT_SLP_LDO_VDDLDO4_LP_EN               ( BIT(11) )
#define BIT_SLP_LDO_VDDLDO3_LP_EN               ( BIT(10) )
#define BIT_SLP_LDO_VDDCAMMOT1_LP_EN            ( BIT(9) )
#define BIT_SLP_LDO_VDDLDO2_LP_EN               ( BIT(8) )
#define BIT_SLP_LDO_AVDD12_LP_EN                ( BIT(7) )
#define BIT_SLP_LDO_VDDWCN_LP_EN                ( BIT(6) )
#define BIT_SLP_LDO_VDDCAMD1_LP_EN              ( BIT(5) )
#define BIT_SLP_LDO_VDDCAMA1_LP_EN              ( BIT(4) )
#define BIT_SLP_LDO_VDDLDO0_LP_EN               ( BIT(3) )
#define BIT_SLP_LDO_VDDSIM0_LP_EN               ( BIT(2) )
#define BIT_SLP_LDO_AVDD18_LP_EN                ( BIT(1) )
#define BIT_SLP_LDO_VDDLDO1_LP_EN               ( BIT(0) )

/* bits definitions for REG_DCDC_CORE_SLP_CTRL0, [0x00002264] */
#define BIT_DCDC_CORE_SLP_STEP_DELAY(x)         ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_DCDC_CORE_SLP_STEP_VOL(x)           ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SLP_CORE_CLK6M_SW_EN                ( BIT(1) )
#define BIT_DCDC_CORE_SLP_STEP_EN               ( BIT(0) )

/* bits definitions for REG_DCDC_CORE_SLP_CTRL1, [0x00002268] */
#define BIT_DCDC_CORE_CTRL_DS_SW(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_DCDC_GPU_SLP_CTRL0, [0x0000226C] */
#define BIT_DCDC_GPU_SLP_STEP_DELAY(x)          ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_DCDC_GPU_SLP_STEP_VOL(x)            ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SLP_GPU_CLK6M_SW_EN                 ( BIT(1) )
#define BIT_DCDC_GPU_SLP_STEP_EN                ( BIT(0) )

/* bits definitions for REG_DCDC_GPU_SLP_CTRL1, [0x00002270] */
#define BIT_DCDC_GPU_CTRL_DS_SW(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_RESERVED_REG18, [0x00002274] */

/* bits definitions for REG_RESERVED_REG19, [0x00002278] */

/* bits definitions for REG_DCDC_PUB_SLP_CTRL0, [0x0000227C] */
#define BIT_DCDC_PUB_SLP_STEP_DELAY(x)          ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_DCDC_PUB_SLP_STEP_VOL(x)            ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SLP_PUB_CLK6M_SW_EN                 ( BIT(1) )
#define BIT_DCDC_PUB_SLP_STEP_EN                ( BIT(0) )

/* bits definitions for REG_DCDC_PUB_SLP_CTRL1, [0x00002280] */
#define BIT_DCDC_PUB_CTRL_DS_SW(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_DCDC_SRAM0_SLP_CTRL0, [0x00002284] */
#define BIT_DCDC_SRAM0_SLP_STEP_DELAY(x)        ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_DCDC_SRAM0_SLP_STEP_VOL(x)          ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SLP_SRAM0_CLK6M_SW_EN               ( BIT(1) )
#define BIT_DCDC_SRAM0_SLP_STEP_EN              ( BIT(0) )

/* bits definitions for REG_DCDC_SRAM0_SLP_CTRL1, [0x00002288] */
#define BIT_DCDC_SRAM0_CTRL_DS_SW(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_DCDC_XTL_EN, [0x0000228C] */
#define BIT_DCDC_CORE_EXT_XTL6_EN               ( BIT(14) )
#define BIT_DCDC_CORE_EXT_XTL5_EN               ( BIT(13) )
#define BIT_DCDC_CORE_EXT_XTL4_EN               ( BIT(12) )
#define BIT_DCDC_CORE_EXT_XTL3_EN               ( BIT(11) )
#define BIT_DCDC_CORE_EXT_XTL2_EN               ( BIT(10) )
#define BIT_DCDC_CORE_EXT_XTL1_EN               ( BIT(9) )
#define BIT_DCDC_CORE_EXT_XTL0_EN               ( BIT(8) )
#define BIT_DCDC_WPA_EXT_XTL6_EN                ( BIT(6) )
#define BIT_DCDC_WPA_EXT_XTL5_EN                ( BIT(5) )
#define BIT_DCDC_WPA_EXT_XTL4_EN                ( BIT(4) )
#define BIT_DCDC_WPA_EXT_XTL3_EN                ( BIT(3) )
#define BIT_DCDC_WPA_EXT_XTL2_EN                ( BIT(2) )
#define BIT_DCDC_WPA_EXT_XTL1_EN                ( BIT(1) )
#define BIT_DCDC_WPA_EXT_XTL0_EN                ( BIT(0) )

/* bits definitions for REG_DCDC_XTL_EN0, [0x00002290] */
#define BIT_DCDC_GEN0_EXT_XTL6_EN               ( BIT(14) )
#define BIT_DCDC_GEN0_EXT_XTL5_EN               ( BIT(13) )
#define BIT_DCDC_GEN0_EXT_XTL4_EN               ( BIT(12) )
#define BIT_DCDC_GEN0_EXT_XTL3_EN               ( BIT(11) )
#define BIT_DCDC_GEN0_EXT_XTL2_EN               ( BIT(10) )
#define BIT_DCDC_GEN0_EXT_XTL1_EN               ( BIT(9) )
#define BIT_DCDC_GEN0_EXT_XTL0_EN               ( BIT(8) )
#define BIT_DCDC_SRAM0_EXT_XTL6_EN              ( BIT(6) )
#define BIT_DCDC_SRAM0_EXT_XTL5_EN              ( BIT(5) )
#define BIT_DCDC_SRAM0_EXT_XTL4_EN              ( BIT(4) )
#define BIT_DCDC_SRAM0_EXT_XTL3_EN              ( BIT(3) )
#define BIT_DCDC_SRAM0_EXT_XTL2_EN              ( BIT(2) )
#define BIT_DCDC_SRAM0_EXT_XTL1_EN              ( BIT(1) )
#define BIT_DCDC_SRAM0_EXT_XTL0_EN              ( BIT(0) )

/* bits definitions for REG_DCDC_XTL_EN1, [0x00002294] */
#define BIT_DCDC_GPU_EXT_XTL6_EN                ( BIT(6) )
#define BIT_DCDC_GPU_EXT_XTL5_EN                ( BIT(5) )
#define BIT_DCDC_GPU_EXT_XTL4_EN                ( BIT(4) )
#define BIT_DCDC_GPU_EXT_XTL3_EN                ( BIT(3) )
#define BIT_DCDC_GPU_EXT_XTL2_EN                ( BIT(2) )
#define BIT_DCDC_GPU_EXT_XTL1_EN                ( BIT(1) )
#define BIT_DCDC_GPU_EXT_XTL0_EN                ( BIT(0) )

/* bits definitions for REG_DCDC_XTL_EN2, [0x00002298] */
#define BIT_DCDC_MEM_EXT_XTL6_EN                ( BIT(14) )
#define BIT_DCDC_MEM_EXT_XTL5_EN                ( BIT(13) )
#define BIT_DCDC_MEM_EXT_XTL4_EN                ( BIT(12) )
#define BIT_DCDC_MEM_EXT_XTL3_EN                ( BIT(11) )
#define BIT_DCDC_MEM_EXT_XTL2_EN                ( BIT(10) )
#define BIT_DCDC_MEM_EXT_XTL1_EN                ( BIT(9) )
#define BIT_DCDC_MEM_EXT_XTL0_EN                ( BIT(8) )
#define BIT_DCDC_GEN1_EXT_XTL6_EN               ( BIT(6) )
#define BIT_DCDC_GEN1_EXT_XTL5_EN               ( BIT(5) )
#define BIT_DCDC_GEN1_EXT_XTL4_EN               ( BIT(4) )
#define BIT_DCDC_GEN1_EXT_XTL3_EN               ( BIT(3) )
#define BIT_DCDC_GEN1_EXT_XTL2_EN               ( BIT(2) )
#define BIT_DCDC_GEN1_EXT_XTL1_EN               ( BIT(1) )
#define BIT_DCDC_GEN1_EXT_XTL0_EN               ( BIT(0) )

/* bits definitions for REG_DCDC_XTL_EN3, [0x0000229C] */
#define BIT_DCDC_MEMQ_EXT_XTL6_EN               ( BIT(14) )
#define BIT_DCDC_MEMQ_EXT_XTL5_EN               ( BIT(13) )
#define BIT_DCDC_MEMQ_EXT_XTL4_EN               ( BIT(12) )
#define BIT_DCDC_MEMQ_EXT_XTL3_EN               ( BIT(11) )
#define BIT_DCDC_MEMQ_EXT_XTL2_EN               ( BIT(10) )
#define BIT_DCDC_MEMQ_EXT_XTL1_EN               ( BIT(9) )
#define BIT_DCDC_MEMQ_EXT_XTL0_EN               ( BIT(8) )
#define BIT_DCDC_PUB_EXT_XTL6_EN                ( BIT(6) )
#define BIT_DCDC_PUB_EXT_XTL5_EN                ( BIT(5) )
#define BIT_DCDC_PUB_EXT_XTL4_EN                ( BIT(4) )
#define BIT_DCDC_PUB_EXT_XTL3_EN                ( BIT(3) )
#define BIT_DCDC_PUB_EXT_XTL2_EN                ( BIT(2) )
#define BIT_DCDC_PUB_EXT_XTL1_EN                ( BIT(1) )
#define BIT_DCDC_PUB_EXT_XTL0_EN                ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN0, [0x000022A0] */
#define BIT_LDO_VDDRF0V9_EXT_XTL6_EN            ( BIT(14) )
#define BIT_LDO_VDDRF0V9_EXT_XTL5_EN            ( BIT(13) )
#define BIT_LDO_VDDRF0V9_EXT_XTL4_EN            ( BIT(12) )
#define BIT_LDO_VDDRF0V9_EXT_XTL3_EN            ( BIT(11) )
#define BIT_LDO_VDDRF0V9_EXT_XTL2_EN            ( BIT(10) )
#define BIT_LDO_VDDRF0V9_EXT_XTL1_EN            ( BIT(9) )
#define BIT_LDO_VDDRF0V9_EXT_XTL0_EN            ( BIT(8) )
#define BIT_LDO_VDD28_EXT_XTL6_EN               ( BIT(6) )
#define BIT_LDO_VDD28_EXT_XTL5_EN               ( BIT(5) )
#define BIT_LDO_VDD28_EXT_XTL4_EN               ( BIT(4) )
#define BIT_LDO_VDD28_EXT_XTL3_EN               ( BIT(3) )
#define BIT_LDO_VDD28_EXT_XTL2_EN               ( BIT(2) )
#define BIT_LDO_VDD28_EXT_XTL1_EN               ( BIT(1) )
#define BIT_LDO_VDD28_EXT_XTL0_EN               ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN1, [0x000022A4] */
#define BIT_LDO_VDDRF1V8_EXT_XTL6_EN            ( BIT(14) )
#define BIT_LDO_VDDRF1V8_EXT_XTL5_EN            ( BIT(13) )
#define BIT_LDO_VDDRF1V8_EXT_XTL4_EN            ( BIT(12) )
#define BIT_LDO_VDDRF1V8_EXT_XTL3_EN            ( BIT(11) )
#define BIT_LDO_VDDRF1V8_EXT_XTL2_EN            ( BIT(10) )
#define BIT_LDO_VDDRF1V8_EXT_XTL1_EN            ( BIT(9) )
#define BIT_LDO_VDDRF1V8_EXT_XTL0_EN            ( BIT(8) )
#define BIT_LDO_VDDRF1V1_EXT_XTL6_EN            ( BIT(6) )
#define BIT_LDO_VDDRF1V1_EXT_XTL5_EN            ( BIT(5) )
#define BIT_LDO_VDDRF1V1_EXT_XTL4_EN            ( BIT(4) )
#define BIT_LDO_VDDRF1V1_EXT_XTL3_EN            ( BIT(3) )
#define BIT_LDO_VDDRF1V1_EXT_XTL2_EN            ( BIT(2) )
#define BIT_LDO_VDDRF1V1_EXT_XTL1_EN            ( BIT(1) )
#define BIT_LDO_VDDRF1V1_EXT_XTL0_EN            ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN2, [0x000022A8] */
#define BIT_LDO_VDDSIM0_EXT_XTL6_EN             ( BIT(14) )
#define BIT_LDO_VDDSIM0_EXT_XTL5_EN             ( BIT(13) )
#define BIT_LDO_VDDSIM0_EXT_XTL4_EN             ( BIT(12) )
#define BIT_LDO_VDDSIM0_EXT_XTL3_EN             ( BIT(11) )
#define BIT_LDO_VDDSIM0_EXT_XTL2_EN             ( BIT(10) )
#define BIT_LDO_VDDSIM0_EXT_XTL1_EN             ( BIT(9) )
#define BIT_LDO_VDDSIM0_EXT_XTL0_EN             ( BIT(8) )
#define BIT_LDO_VDDSIM1_EXT_XTL6_EN             ( BIT(6) )
#define BIT_LDO_VDDSIM1_EXT_XTL5_EN             ( BIT(5) )
#define BIT_LDO_VDDSIM1_EXT_XTL4_EN             ( BIT(4) )
#define BIT_LDO_VDDSIM1_EXT_XTL3_EN             ( BIT(3) )
#define BIT_LDO_VDDSIM1_EXT_XTL2_EN             ( BIT(2) )
#define BIT_LDO_VDDSIM1_EXT_XTL1_EN             ( BIT(1) )
#define BIT_LDO_VDDSIM1_EXT_XTL0_EN             ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN3, [0x000022AC] */
#define BIT_LDO_VDDSIM2_EXT_XTL6_EN             ( BIT(14) )
#define BIT_LDO_VDDSIM2_EXT_XTL5_EN             ( BIT(13) )
#define BIT_LDO_VDDSIM2_EXT_XTL4_EN             ( BIT(12) )
#define BIT_LDO_VDDSIM2_EXT_XTL3_EN             ( BIT(11) )
#define BIT_LDO_VDDSIM2_EXT_XTL2_EN             ( BIT(10) )
#define BIT_LDO_VDDSIM2_EXT_XTL1_EN             ( BIT(9) )
#define BIT_LDO_VDDSIM2_EXT_XTL0_EN             ( BIT(8) )
#define BIT_LDO_AVDD12_EXT_XTL6_EN              ( BIT(6) )
#define BIT_LDO_AVDD12_EXT_XTL5_EN              ( BIT(5) )
#define BIT_LDO_AVDD12_EXT_XTL4_EN              ( BIT(4) )
#define BIT_LDO_AVDD12_EXT_XTL3_EN              ( BIT(3) )
#define BIT_LDO_AVDD12_EXT_XTL2_EN              ( BIT(2) )
#define BIT_LDO_AVDD12_EXT_XTL1_EN              ( BIT(1) )
#define BIT_LDO_AVDD12_EXT_XTL0_EN              ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN4, [0x000022B0] */
#define BIT_LDO_VDDCAMMOT0_EXT_XTL6_EN          ( BIT(14) )
#define BIT_LDO_VDDCAMMOT0_EXT_XTL5_EN          ( BIT(13) )
#define BIT_LDO_VDDCAMMOT0_EXT_XTL4_EN          ( BIT(12) )
#define BIT_LDO_VDDCAMMOT0_EXT_XTL3_EN          ( BIT(11) )
#define BIT_LDO_VDDCAMMOT0_EXT_XTL2_EN          ( BIT(10) )
#define BIT_LDO_VDDCAMMOT0_EXT_XTL1_EN          ( BIT(9) )
#define BIT_LDO_VDDCAMMOT0_EXT_XTL0_EN          ( BIT(8) )
#define BIT_LDO_VDDCAMIO_EXT_XTL6_EN            ( BIT(6) )
#define BIT_LDO_VDDCAMIO_EXT_XTL5_EN            ( BIT(5) )
#define BIT_LDO_VDDCAMIO_EXT_XTL4_EN            ( BIT(4) )
#define BIT_LDO_VDDCAMIO_EXT_XTL3_EN            ( BIT(3) )
#define BIT_LDO_VDDCAMIO_EXT_XTL2_EN            ( BIT(2) )
#define BIT_LDO_VDDCAMIO_EXT_XTL1_EN            ( BIT(1) )
#define BIT_LDO_VDDCAMIO_EXT_XTL0_EN            ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN5, [0x000022B4] */
#define BIT_LDO_VDDCAMA0_EXT_XTL6_EN            ( BIT(14) )
#define BIT_LDO_VDDCAMA0_EXT_XTL5_EN            ( BIT(13) )
#define BIT_LDO_VDDCAMA0_EXT_XTL4_EN            ( BIT(12) )
#define BIT_LDO_VDDCAMA0_EXT_XTL3_EN            ( BIT(11) )
#define BIT_LDO_VDDCAMA0_EXT_XTL2_EN            ( BIT(10) )
#define BIT_LDO_VDDCAMA0_EXT_XTL1_EN            ( BIT(9) )
#define BIT_LDO_VDDCAMA0_EXT_XTL0_EN            ( BIT(8) )
#define BIT_LDO_VDDCAMA1_EXT_XTL6_EN            ( BIT(6) )
#define BIT_LDO_VDDCAMA1_EXT_XTL5_EN            ( BIT(5) )
#define BIT_LDO_VDDCAMA1_EXT_XTL4_EN            ( BIT(4) )
#define BIT_LDO_VDDCAMA1_EXT_XTL3_EN            ( BIT(3) )
#define BIT_LDO_VDDCAMA1_EXT_XTL2_EN            ( BIT(2) )
#define BIT_LDO_VDDCAMA1_EXT_XTL1_EN            ( BIT(1) )
#define BIT_LDO_VDDCAMA1_EXT_XTL0_EN            ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN6, [0x000022B8] */
#define BIT_LDO_VDDCAMD0_EXT_XTL6_EN            ( BIT(14) )
#define BIT_LDO_VDDCAMD0_EXT_XTL5_EN            ( BIT(13) )
#define BIT_LDO_VDDCAMD0_EXT_XTL4_EN            ( BIT(12) )
#define BIT_LDO_VDDCAMD0_EXT_XTL3_EN            ( BIT(11) )
#define BIT_LDO_VDDCAMD0_EXT_XTL2_EN            ( BIT(10) )
#define BIT_LDO_VDDCAMD0_EXT_XTL1_EN            ( BIT(9) )
#define BIT_LDO_VDDCAMD0_EXT_XTL0_EN            ( BIT(8) )
#define BIT_LDO_VDDCAMD1_EXT_XTL6_EN            ( BIT(6) )
#define BIT_LDO_VDDCAMD1_EXT_XTL5_EN            ( BIT(5) )
#define BIT_LDO_VDDCAMD1_EXT_XTL4_EN            ( BIT(4) )
#define BIT_LDO_VDDCAMD1_EXT_XTL3_EN            ( BIT(3) )
#define BIT_LDO_VDDCAMD1_EXT_XTL2_EN            ( BIT(2) )
#define BIT_LDO_VDDCAMD1_EXT_XTL1_EN            ( BIT(1) )
#define BIT_LDO_VDDCAMD1_EXT_XTL0_EN            ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN7, [0x000022BC] */
#define BIT_LDO_VDDSDIO_EXT_XTL6_EN             ( BIT(14) )
#define BIT_LDO_VDDSDIO_EXT_XTL5_EN             ( BIT(13) )
#define BIT_LDO_VDDSDIO_EXT_XTL4_EN             ( BIT(12) )
#define BIT_LDO_VDDSDIO_EXT_XTL3_EN             ( BIT(11) )
#define BIT_LDO_VDDSDIO_EXT_XTL2_EN             ( BIT(10) )
#define BIT_LDO_VDDSDIO_EXT_XTL1_EN             ( BIT(9) )
#define BIT_LDO_VDDSDIO_EXT_XTL0_EN             ( BIT(8) )
#define BIT_LDO_VDDSDCORE_EXT_XTL6_EN           ( BIT(6) )
#define BIT_LDO_VDDSDCORE_EXT_XTL5_EN           ( BIT(5) )
#define BIT_LDO_VDDSDCORE_EXT_XTL4_EN           ( BIT(4) )
#define BIT_LDO_VDDSDCORE_EXT_XTL3_EN           ( BIT(3) )
#define BIT_LDO_VDDSDCORE_EXT_XTL2_EN           ( BIT(2) )
#define BIT_LDO_VDDSDCORE_EXT_XTL1_EN           ( BIT(1) )
#define BIT_LDO_VDDSDCORE_EXT_XTL0_EN           ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN8, [0x000022C0] */
#define BIT_LDO_VDDEMMCCORE_EXT_XTL6_EN         ( BIT(14) )
#define BIT_LDO_VDDEMMCCORE_EXT_XTL5_EN         ( BIT(13) )
#define BIT_LDO_VDDEMMCCORE_EXT_XTL4_EN         ( BIT(12) )
#define BIT_LDO_VDDEMMCCORE_EXT_XTL3_EN         ( BIT(11) )
#define BIT_LDO_VDDEMMCCORE_EXT_XTL2_EN         ( BIT(10) )
#define BIT_LDO_VDDEMMCCORE_EXT_XTL1_EN         ( BIT(9) )
#define BIT_LDO_VDDEMMCCORE_EXT_XTL0_EN         ( BIT(8) )
#define BIT_LDO_VDDUSB33_EXT_XTL6_EN            ( BIT(6) )
#define BIT_LDO_VDDUSB33_EXT_XTL5_EN            ( BIT(5) )
#define BIT_LDO_VDDUSB33_EXT_XTL4_EN            ( BIT(4) )
#define BIT_LDO_VDDUSB33_EXT_XTL3_EN            ( BIT(3) )
#define BIT_LDO_VDDUSB33_EXT_XTL2_EN            ( BIT(2) )
#define BIT_LDO_VDDUSB33_EXT_XTL1_EN            ( BIT(1) )
#define BIT_LDO_VDDUSB33_EXT_XTL0_EN            ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN9, [0x000022C4] */
#define BIT_LDO_VDDKPLED_EXT_XTL6_EN            ( BIT(14) )
#define BIT_LDO_VDDKPLED_EXT_XTL5_EN            ( BIT(13) )
#define BIT_LDO_VDDKPLED_EXT_XTL4_EN            ( BIT(12) )
#define BIT_LDO_VDDKPLED_EXT_XTL3_EN            ( BIT(11) )
#define BIT_LDO_VDDKPLED_EXT_XTL2_EN            ( BIT(10) )
#define BIT_LDO_VDDKPLED_EXT_XTL1_EN            ( BIT(9) )
#define BIT_LDO_VDDKPLED_EXT_XTL0_EN            ( BIT(8) )
#define BIT_LDO_VDDVIB_EXT_XTL6_EN              ( BIT(6) )
#define BIT_LDO_VDDVIB_EXT_XTL5_EN              ( BIT(5) )
#define BIT_LDO_VDDVIB_EXT_XTL4_EN              ( BIT(4) )
#define BIT_LDO_VDDVIB_EXT_XTL3_EN              ( BIT(3) )
#define BIT_LDO_VDDVIB_EXT_XTL2_EN              ( BIT(2) )
#define BIT_LDO_VDDVIB_EXT_XTL1_EN              ( BIT(1) )
#define BIT_LDO_VDDVIB_EXT_XTL0_EN              ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN10, [0x000022C8] */
#define BIT_LDO_VDDWCN_EXT_XTL6_EN              ( BIT(14) )
#define BIT_LDO_VDDWCN_EXT_XTL5_EN              ( BIT(13) )
#define BIT_LDO_VDDWCN_EXT_XTL4_EN              ( BIT(12) )
#define BIT_LDO_VDDWCN_EXT_XTL3_EN              ( BIT(11) )
#define BIT_LDO_VDDWCN_EXT_XTL2_EN              ( BIT(10) )
#define BIT_LDO_VDDWCN_EXT_XTL1_EN              ( BIT(9) )
#define BIT_LDO_VDDWCN_EXT_XTL0_EN              ( BIT(8) )
#define BIT_LDO_AVDD18_EXT_XTL6_EN              ( BIT(6) )
#define BIT_LDO_AVDD18_EXT_XTL5_EN              ( BIT(5) )
#define BIT_LDO_AVDD18_EXT_XTL4_EN              ( BIT(4) )
#define BIT_LDO_AVDD18_EXT_XTL3_EN              ( BIT(3) )
#define BIT_LDO_AVDD18_EXT_XTL2_EN              ( BIT(2) )
#define BIT_LDO_AVDD18_EXT_XTL1_EN              ( BIT(1) )
#define BIT_LDO_AVDD18_EXT_XTL0_EN              ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN11, [0x000022CC] */
#define BIT_LDO_VDDLDO0_EXT_XTL6_EN             ( BIT(14) )
#define BIT_LDO_VDDLDO0_EXT_XTL5_EN             ( BIT(13) )
#define BIT_LDO_VDDLDO0_EXT_XTL4_EN             ( BIT(12) )
#define BIT_LDO_VDDLDO0_EXT_XTL3_EN             ( BIT(11) )
#define BIT_LDO_VDDLDO0_EXT_XTL2_EN             ( BIT(10) )
#define BIT_LDO_VDDLDO0_EXT_XTL1_EN             ( BIT(9) )
#define BIT_LDO_VDDLDO0_EXT_XTL0_EN             ( BIT(8) )
#define BIT_LDO_VDDWIFIPA_EXT_XTL6_EN           ( BIT(6) )
#define BIT_LDO_VDDWIFIPA_EXT_XTL5_EN           ( BIT(5) )
#define BIT_LDO_VDDWIFIPA_EXT_XTL4_EN           ( BIT(4) )
#define BIT_LDO_VDDWIFIPA_EXT_XTL3_EN           ( BIT(3) )
#define BIT_LDO_VDDWIFIPA_EXT_XTL2_EN           ( BIT(2) )
#define BIT_LDO_VDDWIFIPA_EXT_XTL1_EN           ( BIT(1) )
#define BIT_LDO_VDDWIFIPA_EXT_XTL0_EN           ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN12, [0x000022D0] */
#define BIT_LDO_VDDLDO2_EXT_XTL6_EN             ( BIT(14) )
#define BIT_LDO_VDDLDO2_EXT_XTL5_EN             ( BIT(13) )
#define BIT_LDO_VDDLDO2_EXT_XTL4_EN             ( BIT(12) )
#define BIT_LDO_VDDLDO2_EXT_XTL3_EN             ( BIT(11) )
#define BIT_LDO_VDDLDO2_EXT_XTL2_EN             ( BIT(10) )
#define BIT_LDO_VDDLDO2_EXT_XTL1_EN             ( BIT(9) )
#define BIT_LDO_VDDLDO2_EXT_XTL0_EN             ( BIT(8) )
#define BIT_LDO_VDDLDO1_EXT_XTL6_EN             ( BIT(6) )
#define BIT_LDO_VDDLDO1_EXT_XTL5_EN             ( BIT(5) )
#define BIT_LDO_VDDLDO1_EXT_XTL4_EN             ( BIT(4) )
#define BIT_LDO_VDDLDO1_EXT_XTL3_EN             ( BIT(3) )
#define BIT_LDO_VDDLDO1_EXT_XTL2_EN             ( BIT(2) )
#define BIT_LDO_VDDLDO1_EXT_XTL1_EN             ( BIT(1) )
#define BIT_LDO_VDDLDO1_EXT_XTL0_EN             ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN16, [0x000022D4] */
#define BIT_LDO_VDD18_DCXO_EXT_XTL6_EN          ( BIT(6) )
#define BIT_LDO_VDD18_DCXO_EXT_XTL5_EN          ( BIT(5) )
#define BIT_LDO_VDD18_DCXO_EXT_XTL4_EN          ( BIT(4) )
#define BIT_LDO_VDD18_DCXO_EXT_XTL3_EN          ( BIT(3) )
#define BIT_LDO_VDD18_DCXO_EXT_XTL2_EN          ( BIT(2) )
#define BIT_LDO_VDD18_DCXO_EXT_XTL1_EN          ( BIT(1) )
#define BIT_LDO_VDD18_DCXO_EXT_XTL0_EN          ( BIT(0) )

/* bits definitions for REG_PWR_ON_CTRL, [0x000022D8] */
#define BIT_PWR_ON_DLY_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_UVLO_CTRL, [0x000022DC] */
#define BIT_UVLO_BATON_EN                       ( BIT(0) )

/* bits definitions for REG_EMM_AUTO_PD_SEL, [0x000022E0] */
#define BIT_LDO_EMM_AUTO_PD_SEL                 ( BIT(0) )

/* bits definitions for REG_RESERVED_REG21, [0x000022E4] */

/* bits definitions for REG_RESERVED_REG22, [0x000022E8] */

/* bits definitions for REG_STEP_CLK_CTRL, [0x000022EC] */
#define BIT_SRAM0_STEP_CLK_SEL                  ( BIT(3) )
#define BIT_PUB_STEP_CLK_SEL                    ( BIT(2) )
#define BIT_CORE_STEP_CLK_SEL                   ( BIT(1) )
#define BIT_GPU_STEP_CLK_SEL                    ( BIT(0) )

/* bits definitions for REG_TSX_CTRL1, [0x000022F0] */
#define BIT_DCXO_26M_REF_OUT3_EXT_XTL1_EN       ( BIT(11) )
#define BIT_DCXO_26M_REF_OUT2_EXT_XTL1_EN       ( BIT(10) )
#define BIT_DCXO_26M_REF_OUT1_EXT_XTL1_EN       ( BIT(9) )
#define BIT_DCXO_26M_REF_OUT0_EXT_XTL1_EN       ( BIT(8) )
#define BIT_DCXO_26M_REF_OUT3_EXT_XTL0_EN       ( BIT(3) )
#define BIT_DCXO_26M_REF_OUT2_EXT_XTL0_EN       ( BIT(2) )
#define BIT_DCXO_26M_REF_OUT1_EXT_XTL0_EN       ( BIT(1) )
#define BIT_DCXO_26M_REF_OUT0_EXT_XTL0_EN       ( BIT(0) )

/* bits definitions for REG_TSX_CTRL2, [0x000022F4] */
#define BIT_DCXO_26M_REF_OUT3_EXT_XTL3_EN       ( BIT(11) )
#define BIT_DCXO_26M_REF_OUT2_EXT_XTL3_EN       ( BIT(10) )
#define BIT_DCXO_26M_REF_OUT1_EXT_XTL3_EN       ( BIT(9) )
#define BIT_DCXO_26M_REF_OUT0_EXT_XTL3_EN       ( BIT(8) )
#define BIT_DCXO_26M_REF_OUT3_EXT_XTL2_EN       ( BIT(3) )
#define BIT_DCXO_26M_REF_OUT2_EXT_XTL2_EN       ( BIT(2) )
#define BIT_DCXO_26M_REF_OUT1_EXT_XTL2_EN       ( BIT(1) )
#define BIT_DCXO_26M_REF_OUT0_EXT_XTL2_EN       ( BIT(0) )

/* bits definitions for REG_TSX_CTRL3, [0x000022F8] */
#define BIT_DCXO_26M_REF_OUT3_EXT_XTL5_EN       ( BIT(11) )
#define BIT_DCXO_26M_REF_OUT2_EXT_XTL5_EN       ( BIT(10) )
#define BIT_DCXO_26M_REF_OUT1_EXT_XTL5_EN       ( BIT(9) )
#define BIT_DCXO_26M_REF_OUT0_EXT_XTL5_EN       ( BIT(8) )
#define BIT_DCXO_26M_REF_OUT3_EXT_XTL4_EN       ( BIT(3) )
#define BIT_DCXO_26M_REF_OUT2_EXT_XTL4_EN       ( BIT(2) )
#define BIT_DCXO_26M_REF_OUT1_EXT_XTL4_EN       ( BIT(1) )
#define BIT_DCXO_26M_REF_OUT0_EXT_XTL4_EN       ( BIT(0) )

/* bits definitions for REG_TSX_CTRL4, [0x000022FC] */
#define BIT_DCXO_26M_REF_OUT3_EXT_XTL6_EN       ( BIT(3) )
#define BIT_DCXO_26M_REF_OUT2_EXT_XTL6_EN       ( BIT(2) )
#define BIT_DCXO_26M_REF_OUT1_EXT_XTL6_EN       ( BIT(1) )
#define BIT_DCXO_26M_REF_OUT0_EXT_XTL6_EN       ( BIT(0) )

/* bits definitions for REG_DCXO_XTL_EN, [0x00002300] */
#define BIT_TSX_XO_EXT_XTL6_EN                  ( BIT(6) )
#define BIT_TSX_XO_EXT_XTL5_EN                  ( BIT(5) )
#define BIT_TSX_XO_EXT_XTL4_EN                  ( BIT(4) )
#define BIT_TSX_XO_EXT_XTL3_EN                  ( BIT(3) )
#define BIT_TSX_XO_EXT_XTL2_EN                  ( BIT(2) )
#define BIT_TSX_XO_EXT_XTL1_EN                  ( BIT(1) )
#define BIT_TSX_XO_EXT_XTL0_EN                  ( BIT(0) )

/* bits definitions for REG_DCDC_XTL_EN5, [0x00002304] */
#define BIT_DCDC_AI_EXT_XTL6_EN                 ( BIT(14) )
#define BIT_DCDC_AI_EXT_XTL5_EN                 ( BIT(13) )
#define BIT_DCDC_AI_EXT_XTL4_EN                 ( BIT(12) )
#define BIT_DCDC_AI_EXT_XTL3_EN                 ( BIT(11) )
#define BIT_DCDC_AI_EXT_XTL2_EN                 ( BIT(10) )
#define BIT_DCDC_AI_EXT_XTL1_EN                 ( BIT(9) )
#define BIT_DCDC_AI_EXT_XTL0_EN                 ( BIT(8) )
#define BIT_DCDC_MODEM_EXT_XTL6_EN              ( BIT(6) )
#define BIT_DCDC_MODEM_EXT_XTL5_EN              ( BIT(5) )
#define BIT_DCDC_MODEM_EXT_XTL4_EN              ( BIT(4) )
#define BIT_DCDC_MODEM_EXT_XTL3_EN              ( BIT(3) )
#define BIT_DCDC_MODEM_EXT_XTL2_EN              ( BIT(2) )
#define BIT_DCDC_MODEM_EXT_XTL1_EN              ( BIT(1) )
#define BIT_DCDC_MODEM_EXT_XTL0_EN              ( BIT(0) )

/* bits definitions for REG_DCDC_XTL_EN6, [0x00002308] */
#define BIT_DCDC_MM_EXT_XTL6_EN                 ( BIT(14) )
#define BIT_DCDC_MM_EXT_XTL5_EN                 ( BIT(13) )
#define BIT_DCDC_MM_EXT_XTL4_EN                 ( BIT(12) )
#define BIT_DCDC_MM_EXT_XTL3_EN                 ( BIT(11) )
#define BIT_DCDC_MM_EXT_XTL2_EN                 ( BIT(10) )
#define BIT_DCDC_MM_EXT_XTL1_EN                 ( BIT(9) )
#define BIT_DCDC_MM_EXT_XTL0_EN                 ( BIT(8) )
#define BIT_DCDC_SRAM2_EXT_XTL6_EN              ( BIT(6) )
#define BIT_DCDC_SRAM2_EXT_XTL5_EN              ( BIT(5) )
#define BIT_DCDC_SRAM2_EXT_XTL4_EN              ( BIT(4) )
#define BIT_DCDC_SRAM2_EXT_XTL3_EN              ( BIT(3) )
#define BIT_DCDC_SRAM2_EXT_XTL2_EN              ( BIT(2) )
#define BIT_DCDC_SRAM2_EXT_XTL1_EN              ( BIT(1) )
#define BIT_DCDC_SRAM2_EXT_XTL0_EN              ( BIT(0) )

/* bits definitions for REG_DCDC_XTL_EN7, [0x0000230C] */
#define BIT_DCDC_BUCKBOOST_EXT_XTL6_EN          ( BIT(6) )
#define BIT_DCDC_BUCKBOOST_EXT_XTL5_EN          ( BIT(5) )
#define BIT_DCDC_BUCKBOOST_EXT_XTL4_EN          ( BIT(4) )
#define BIT_DCDC_BUCKBOOST_EXT_XTL3_EN          ( BIT(3) )
#define BIT_DCDC_BUCKBOOST_EXT_XTL2_EN          ( BIT(2) )
#define BIT_DCDC_BUCKBOOST_EXT_XTL1_EN          ( BIT(1) )
#define BIT_DCDC_BUCKBOOST_EXT_XTL0_EN          ( BIT(0) )

/* bits definitions for REG_XTL_WAKEUP_MODE_CTRL, [0x00002310] */
#define BIT_WAKEUP_EXIT_LOCK_EN                 ( BIT(1) )
#define BIT_XTL_WAKEUP_MODE                     ( BIT(0) )

/* bits definitions for REG_EXT_XTL_TX_CFG, [0x00002314] */
#define BIT_DEBUG_SEND                          ( BIT(11) )
#define BIT_DEBUG_DATA(x)                       ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_DEBUG_MODE                          ( BIT(1) )
#define BIT_ODD_PARITY                          ( BIT(0) )

/* bits definitions for REG_RESERVED_REG23, [0x00002318] */

/* bits definitions for REG_RESERVED_REG10, [0x0000231C] */

/* bits definitions for REG_DCDC_POWER_ON_STEP_SEL_CTRL, [0x00002320] */
#define BIT_DCDC_GPU_ON_STEP_EN                 ( BIT(6) )
#define BIT_DCDC_CPU1_ON_STEP_EN                ( BIT(5) )
#define BIT_DCDC_CPU2_ON_STEP_EN                ( BIT(4) )
#define BIT_DCDC_CPU1_ANASOFT_EN                ( BIT(3) )
#define BIT_DCDC_CPU2_ANASOFT_EN                ( BIT(2) )
#define BIT_DCDC_GPU_ANASOFT_EN                 ( BIT(1) )
#define BIT_DCDC_SRAM0_ANASOFT_EN               ( BIT(0) )

/* bits definitions for REG_SLP_PD_CTRL0, [0x00002324] */
#define BIT_SLP_LDO_VDDUSB33_PD                 ( BIT(15) )
#define BIT_SLP_XTLBUF_PD                       ( BIT(14) )
#define BIT_SLP_DCDCSRAM0_PD                    ( BIT(5) )
#define BIT_SLP_DCDCPUB_PD                      ( BIT(4) )
#define BIT_SLP_DCDCMEMQ_PD                     ( BIT(3) )
#define BIT_SLP_DCDCGEN1_PD                     ( BIT(2) )
#define BIT_SLP_DCDCWPA_PD                      ( BIT(1) )
#define BIT_SLP_DCDCGPU_PD                      ( BIT(0) )

/* bits definitions for REG_SLP_PD_CTRL1, [0x00002328] */
#define BIT_SLP_LDO_AVDD12_PD                   ( BIT(15) )
#define BIT_SLP_LDO_AVDD18_PD                   ( BIT(14) )
#define BIT_SLP_LDO_VDD28_PD                    ( BIT(13) )
#define BIT_SLP_LDO_VDDLDO4_PD                  ( BIT(12) )
#define BIT_SLP_LDO_VDDLDO3_PD                  ( BIT(11) )
#define BIT_SLP_LDO_VDDLDO2_PD                  ( BIT(10) )
#define BIT_SLP_LDO_VDDLDO1_PD                  ( BIT(9) )
#define BIT_SLP_LDO_VDDLDO0_PD                  ( BIT(8) )
#define BIT_SLP_LDO_VDDCAMMOT1_PD               ( BIT(7) )
#define BIT_SLP_LDO_VDDCAMMOT0_PD               ( BIT(6) )
#define BIT_SLP_LDO_VDDCAMD2_PD                 ( BIT(5) )
#define BIT_SLP_LDO_VDDCAMD1_PD                 ( BIT(4) )
#define BIT_SLP_LDO_VDDCAMD0_PD                 ( BIT(3) )
#define BIT_SLP_LDO_VDDCAMA2_PD                 ( BIT(2) )
#define BIT_SLP_LDO_VDDCAMA1_PD                 ( BIT(1) )
#define BIT_SLP_LDO_VDDCAMA0_PD                 ( BIT(0) )

/* bits definitions for REG_SLP_PD_CTRL2, [0x0000232C] */
#define BIT_SLP_LDO_VDDWCN_PD                   ( BIT(15) )
#define BIT_SLP_LDO_VDDUFS1V2_PD                ( BIT(14) )
#define BIT_SLP_LDO_VDDWIFIPA_PD                ( BIT(13) )
#define BIT_SLP_LDO_VDDEMMCCORE_PD              ( BIT(12) )
#define BIT_SLP_LDO_VDDCAMIO_PD                 ( BIT(11) )
#define BIT_SLP_LDO_VDDVIB_PD                   ( BIT(10) )
#define BIT_SLP_LDO_VDDKPLED_PD                 ( BIT(9) )
#define BIT_SLP_LDO_VDD18_DCXO_PD               ( BIT(8) )
#define BIT_SLP_LDO_VDDRF0V9_PD                 ( BIT(7) )
#define BIT_SLP_LDO_VDDRF1V1_PD                 ( BIT(6) )
#define BIT_SLP_LDO_VDDRF1V8_PD                 ( BIT(5) )
#define BIT_SLP_LDO_VDDSDCORE_PD                ( BIT(4) )
#define BIT_SLP_LDO_VDDSDIO_PD                  ( BIT(3) )
#define BIT_SLP_LDO_VDDSIM2_PD                  ( BIT(2) )
#define BIT_SLP_LDO_VDDSIM1_PD                  ( BIT(1) )
#define BIT_SLP_LDO_VDDSIM0_PD                  ( BIT(0) )

/* bits definitions for REG_WAKEUP_CTRL0, [0x00002330] */
#define BIT_LDO_USB33_WAKEUP_N                  ( BIT(15) )
#define BIT_TSX_XO_WAKEUP_N                     ( BIT(11) )
#define BIT_DCDC_BUCKBOOST_WAKEUP_N             ( BIT(10) )
#define BIT_DCDC_AI_WAKEUP_N                    ( BIT(9) )
#define BIT_DCDC_SRAM2_WAKEUP_N                 ( BIT(8) )
#define BIT_DCDC_MM_WAKEUP_N                    ( BIT(7) )
#define BIT_DCDC_MODEM_WAKEUP_N                 ( BIT(6) )
#define BIT_DCDC_SRAM0_WAKEUP_N                 ( BIT(5) )
#define BIT_DCDC_PUB_WAKEUP_N                   ( BIT(4) )
#define BIT_DCDC_MEMQ_WAKEUP_N                  ( BIT(3) )
#define BIT_DCDC_GEN1_WAKEUP_N                  ( BIT(2) )
#define BIT_DCDC_WPA_WAKEUP_N                   ( BIT(1) )
#define BIT_DCDC_GPU_WAKEUP_N                   ( BIT(0) )

/* bits definitions for REG_WAKEUP_CTRL1, [0x00002334] */
#define BIT_LDO_AVDD12_WAKEUP_N                 ( BIT(15) )
#define BIT_LDO_AVDD18_WAKEUP_N                 ( BIT(14) )
#define BIT_LDO_VDD28_WAKEUP_N                  ( BIT(13) )
#define BIT_LDO4_WAKEUP_N                       ( BIT(12) )
#define BIT_LDO3_WAKEUP_N                       ( BIT(11) )
#define BIT_LDO2_WAKEUP_N                       ( BIT(10) )
#define BIT_LDO1_WAKEUP_N                       ( BIT(9) )
#define BIT_LDO0_WAKEUP_N                       ( BIT(8) )
#define BIT_LDO_CAMMOT1_WAKEUP_N                ( BIT(7) )
#define BIT_LDO_CAMMOT0_WAKEUP_N                ( BIT(6) )
#define BIT_LDO_CAMD2_WAKEUP_N                  ( BIT(5) )
#define BIT_LDO_CAMD1_WAKEUP_N                  ( BIT(4) )
#define BIT_LDO_CAMD0_WAKEUP_N                  ( BIT(3) )
#define BIT_LDO_CAMA2_WAKEUP_N                  ( BIT(2) )
#define BIT_LDO_CAMA1_WAKEUP_N                  ( BIT(1) )
#define BIT_LDO_CAMA0_WAKEUP_N                  ( BIT(0) )

/* bits definitions for REG_WAKEUP_CTRL2, [0x00002338] */
#define BIT_LDO_WCN_WAKEUP_N                    ( BIT(15) )
#define BIT_LDO_VDDUFS1V2_WAKEUP_N              ( BIT(14) )
#define BIT_LDO_WIFIPA_WAKEUP_N                 ( BIT(13) )
#define BIT_LDO_EMMCCORE_WAKEUP_N               ( BIT(12) )
#define BIT_LDO_CAMIO_WAKEUP_N                  ( BIT(11) )
#define BIT_LDO_VIB_WAKEUP_N                    ( BIT(10) )
#define BIT_LDO_KPLED_WAKEUP_N                  ( BIT(9) )
#define BIT_LDO_DCXO_WAKEUP_N                   ( BIT(8) )
#define BIT_LDO_RF0V9_WAKEUP_N                  ( BIT(7) )
#define BIT_LDO_RF1V1_WAKEUP_N                  ( BIT(6) )
#define BIT_LDO_RF1V8_WAKEUP_N                  ( BIT(5) )
#define BIT_LDO_SDCORE_WAKEUP_N                 ( BIT(4) )
#define BIT_LDO_SDIO_WAKEUP_N                   ( BIT(3) )
#define BIT_LDO_SIM2_WAKEUP_N                   ( BIT(2) )
#define BIT_LDO_SIM1_WAKEUP_N                   ( BIT(1) )
#define BIT_LDO_SIM0_WAKEUP_N                   ( BIT(0) )

/* bits definitions for REG_LP_EN_CTRL0, [0x0000233C] */
#define BIT_LDO_VDDUSB33_LP_EN                  ( BIT(15) )
#define BIT_DCDC_MEM_LP_EN                      ( BIT(8) )
#define BIT_DCDC_GEN0_LP_EN                     ( BIT(7) )
#define BIT_DCDC_CORE_LP_EN                     ( BIT(6) )
#define BIT_DCDC_SRAM0_LP_EN                    ( BIT(5) )
#define BIT_DCDC_PUB_LP_EN                      ( BIT(4) )
#define BIT_DCDC_MEMQ_LP_EN                     ( BIT(3) )
#define BIT_DCDC_GEN1_LP_EN                     ( BIT(2) )
#define BIT_DCDC_WPA_LP_EN                      ( BIT(1) )
#define BIT_DCDC_GPU_LP_EN                      ( BIT(0) )

/* bits definitions for REG_LP_EN_CTRL1, [0x00002340] */
#define BIT_LDO_AVDD12_LP_EN                    ( BIT(15) )
#define BIT_LDO_AVDD18_LP_EN                    ( BIT(14) )
#define BIT_LDO_VDD28_LP_EN                     ( BIT(13) )
#define BIT_LDO_VDDLDO4_LP_EN                   ( BIT(12) )
#define BIT_LDO_VDDLDO3_LP_EN                   ( BIT(11) )
#define BIT_LDO_VDDLDO2_LP_EN                   ( BIT(10) )
#define BIT_LDO_VDDLDO1_LP_EN                   ( BIT(9) )
#define BIT_LDO_VDDLDO0_LP_EN                   ( BIT(8) )
#define BIT_LDO_VDDCAMMOT1_LP_EN                ( BIT(7) )
#define BIT_LDO_VDDCAMMOT0_LP_EN                ( BIT(6) )
#define BIT_LDO_VDDCAMD2_LP_EN                  ( BIT(5) )
#define BIT_LDO_VDDCAMD1_LP_EN                  ( BIT(4) )
#define BIT_LDO_VDDCAMD0_LP_EN                  ( BIT(3) )
#define BIT_LDO_VDDCAMA2_LP_EN                  ( BIT(2) )
#define BIT_LDO_VDDCAMA1_LP_EN                  ( BIT(1) )
#define BIT_LDO_VDDCAMA0_LP_EN                  ( BIT(0) )

/* bits definitions for REG_LP_EN_CTRL2, [0x00002344] */
#define BIT_LDO_VDDWCN_LP_EN                    ( BIT(15) )
#define BIT_LDO_VDDUFS1V2_LP_EN                 ( BIT(14) )
#define BIT_LDO_VDDWIFIPA_LP_EN                 ( BIT(13) )
#define BIT_LDO_VDDEMMCCORE_LP_EN               ( BIT(12) )
#define BIT_LDO_VDD18_DCXO_LP_EN                ( BIT(8) )
#define BIT_LDO_VDDRF0V9_LP_EN                  ( BIT(7) )
#define BIT_LDO_VDDRF1V1_LP_EN                  ( BIT(6) )
#define BIT_LDO_VDDRF1V8_LP_EN                  ( BIT(5) )
#define BIT_LDO_VDDSDCORE_LP_EN                 ( BIT(4) )
#define BIT_LDO_VDDSDIO_LP_EN                   ( BIT(3) )
#define BIT_LDO_VDDSIM2_LP_EN                   ( BIT(2) )
#define BIT_LDO_VDDSIM1_LP_EN                   ( BIT(1) )
#define BIT_LDO_VDDSIM0_LP_EN                   ( BIT(0) )

/* bits definitions for REG_DCXO_26M_REF_OUT_WAKEUP, [0x00002348] */
#define BIT_DCXO_26M_REF_OUT3_WAKEUP            ( BIT(3) )
#define BIT_DCXO_26M_REF_OUT2_WAKEUP            ( BIT(2) )
#define BIT_DCXO_26M_REF_OUT1_WAKEUP            ( BIT(1) )
#define BIT_DCXO_26M_REF_OUT0_WAKEUP            ( BIT(0) )

/* bits definitions for REG_RESERVED_REG_CORE, [0x0000234C] */
#define BIT_RESERVED_CORE(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_RESERVED_REG_RTC, [0x00002350] */
#define BIT_RESERVED_RTC(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for REG_BG_CTRL, [0x00002354] */
#define BIT_BG_CHOP_EN                          ( BIT(0) )

/* bits definitions for REG_DCDC_VLG_SEL0, [0x00002358] */
#define BIT_DCDC_PUB_PFMAD_SW_SEL               ( BIT(15) )
#define BIT_DCDC_MEMQ_PFMAD_SW_SEL              ( BIT(14) )
#define BIT_DCDC_GPU_PFMAD_SW_SEL               ( BIT(13) )
#define BIT_DCDC_CPU2_PFMAD_SW_SEL              ( BIT(12) )
#define BIT_DCDC_CORE_PFMAD_SW_SEL              ( BIT(11) )
#define BIT_DCDC_GEN1_PFMAD_SW_SEL              ( BIT(10) )
#define BIT_DCDC_GEN0_PFMAD_SW_SEL              ( BIT(9) )
#define BIT_DCDC_MEM_PFMAD_SW_SEL               ( BIT(8) )
#define BIT_DCDC_WPA_PFMAD_SW_SEL               ( BIT(7) )
#define BIT_DCDC_6MFRECAL_SW_SEL                ( BIT(6) )
#define BIT_DCDC_WPA_VREF_CAL_SW_SEL            ( BIT(5) )
#define BIT_DCDC_MEMQ_SW_SEL                    ( BIT(4) )
#define BIT_DCDC_GEN0_SW_SEL                    ( BIT(3) )
#define BIT_DCDC_GEN1_SW_SEL                    ( BIT(2) )
#define BIT_DCDC_CORE_NOR_SW_SEL                ( BIT(0) )

/* bits definitions for REG_DCDC_VLG_SEL1, [0x0000235C] */
#define BIT_DCDC_CPU1_SW_SEL                    ( BIT(6) )
#define BIT_DCDC_SRAM0_PFMAD_SW_SEL             ( BIT(5) )
#define BIT_DCDC_SRAM0_SW_SEL                   ( BIT(4) )
#define BIT_DCDC_PUB_SW_SEL                     ( BIT(3) )
#define BIT_DCDC_MEM_SW_SEL                     ( BIT(2) )
#define BIT_DCDC_GPU_SW_SEL                     ( BIT(1) )
#define BIT_DCDC_CPU2_SW_SEL                    ( BIT(0) )

/* bits definitions for REG_LDO_VLG_SEL0, [0x00002360] */
#define BIT_LDO_VDDSDCORE_CL_ADJ_SW_SEL         ( BIT(15) )
#define BIT_LDO_VDDLDO1_SW_SEL                  ( BIT(14) )
#define BIT_LDO_VDDLDO0_SW_SEL                  ( BIT(13) )
#define BIT_LDO_VDDUSB33_SW_SEL                 ( BIT(12) )
#define BIT_LDO_VDD18_DCXO_SW_SEL               ( BIT(11) )
#define BIT_LDO_VDDWIFIPA_SW_SEL                ( BIT(10) )
#define BIT_LDO_VDD28_SW_SEL                    ( BIT(9) )
#define BIT_LDO_VDDSDIO_SW_SEL                  ( BIT(8) )
#define BIT_LDO_VDDSDCORE_SW_SEL                ( BIT(7) )
#define BIT_LDO_VDDEMMCCORE_SW_SEL              ( BIT(6) )
#define BIT_LDO_VDDSIM2_SW_SEL                  ( BIT(5) )
#define BIT_LDO_VDDSIM1_SW_SEL                  ( BIT(4) )
#define BIT_LDO_VDDSIM0_SW_SEL                  ( BIT(3) )
#define BIT_LDO_VDD18_DCXO_LP_SW_SEL            ( BIT(2) )

/* bits definitions for REG_LDO_VLG_SEL1, [0x00002364] */
#define BIT_LDO_VDDLDO4_SW_SEL                  ( BIT(15) )
#define BIT_LDO_VDDUFS1V2_SW_SEL                ( BIT(14) )
#define BIT_LDO_VDDRF0V9_SW_SEL                 ( BIT(13) )
#define BIT_LDO_VDDLDO3_SW_SEL                  ( BIT(12) )
#define BIT_LDO_VDDLDO2_SW_SEL                  ( BIT(11) )
#define BIT_LDO_RTC_CAL_SW_SEL                  ( BIT(10) )
#define BIT_LDO_VDDKPLED_SW_SEL                 ( BIT(9) )
#define BIT_LDO_VDDVIBR_SW_SEL                  ( BIT(8) )
#define BIT_LDO_AVDD12_SW_SEL                   ( BIT(7) )
#define BIT_LDO_VDDRF1V1_SW_SEL                 ( BIT(6) )
#define BIT_LDO_VDDCAMD2_SW_SEL                 ( BIT(5) )
#define BIT_LDO_VDDCAMD1_SW_SEL                 ( BIT(4) )
#define BIT_LDO_VDDCAMD0_SW_SEL                 ( BIT(3) )
#define BIT_LDO_VDDWCN_SW_SEL                   ( BIT(2) )
#define BIT_LDO_VDDRF1V8_SW_SEL                 ( BIT(1) )
#define BIT_LDO_AVDD18_SW_SEL                   ( BIT(0) )

/* bits definitions for REG_CLK32KSEL_CTRL0, [0x00002368] */
#define BIT_RTC_MODE                            ( BIT(6) )
#define BIT_RC_MODE_WR_ACK_FLAG                 ( BIT(5) )
#define BIT_RC_MODE_WR_ACK_FLAG_CLR             ( BIT(4) )
#define BIT_LDO_VDD18_DCXO_LP_EN_RTCSET         ( BIT(3) )
#define BIT_LDO_VDD18_DCXO_LP_EN_RTCCLR         ( BIT(2) )
#define BIT_RC_32K_SEL                          ( BIT(1) )
#define BIT_RC_32K_EN                           ( BIT(0) )

/* bits definitions for REG_CLK32KSEL_CTRL1, [0x0000236C] */
#define BIT_RC_MODE(x)                          ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_LDO_VLG_SEL2, [0x00002370] */
#define BIT_RC1M_CAL_SW_SEL                     ( BIT(3) )
#define BIT_LDO_VDDLDO2_CL_ADJ_SW_SEL           ( BIT(2) )
#define BIT_LDO_VDDWIFIPA_CL_ADJ_SW_SEL         ( BIT(1) )
#define BIT_LDO_VDDEMMCCORE_CL_ADJ_SW_SEL       ( BIT(0) )

/* bits definitions for REG_RESERVED_REG33, [0x00002374] */

/* bits definitions for REG_XTL_WAIT_CTRL0, [0x00002378] */
#define BIT_SLP_XTLBUF_PD_EN                    ( BIT(9) )
#define BIT_XTL_EN                              ( BIT(8) )
#define BIT_XTL_WAIT(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_CLK_26M_SEL, [0x0000237C] */
#define BIT_CLK_26M_SOURCE_SEL                  ( BIT(0) )

/* bits definitions for REG_RGB_CTRL0, [0x00002380] */
#define BIT_SLP_RGB_PD_EN                       ( BIT(2) )

/* bits definitions for REG_IB_CTRL, [0x00002384] */
#define BIT_BATDET_CUR_EN                       ( BIT(13) )
#define BIT_BATDET_CUR_I(x)                     ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_IB_TRIM(x)                          ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_IB_TRIM_EM_SEL                      ( BIT(1) )
#define BIT_IB_REX_EN                           ( BIT(0) )

/* bits definitions for REG_KPLED_CTRL0, [0x00002388] */
#define BIT_KPLED_V(x)                          ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_KPLED_PD                            ( BIT(11) )
#define BIT_KPLED_PULLDOWN_EN                   ( BIT(10) )

/* bits definitions for REG_KPLED_CTRL1, [0x0000238C] */
#define BIT_LDO_VDDKPLED_PD                     ( BIT(15) )
#define BIT_LDO_VDDKPLED_V(x)                   ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_LDO_VDDKPLED_REFTRIM(x)             ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_SLP_LDO_VDDKPLED_PD_EN              ( BIT(1) )
#define BIT_LDO_VDDKPLED_SHPT_PD                ( BIT(0) )

/* bits definitions for REG_VIBR_CTRL0, [0x00002390] */
#define BIT_SLP_LDO_VDDVIB_PD_EN                ( BIT(14) )
#define BIT_LDO_VDDVIB_PD                       ( BIT(13) )
#define BIT_LDO_VDDVIB_REFTRIM(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_LDO_VDDVIB_V(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AUDIO_CTRL0, [0x00002394] */
#define BIT_CLK_AUD_IF_TX_INV_EN                ( BIT(3) )
#define BIT_CLK_AUD_IF_RX_INV_EN                ( BIT(2) )
#define BIT_CLK_AUD_IF_6P5M_TX_INV_EN           ( BIT(1) )
#define BIT_CLK_AUD_IF_6P5M_RX_INV_EN           ( BIT(0) )

/* bits definitions for REG_CHGR_CTRL, [0x00002398] */
#define BIT_CHGR_PD                             ( BIT(0) )

/* bits definitions for REG_CHGR_STATUS, [0x0000239C] */
#define BIT_CHGR_INT_EN                         ( BIT(13) )
#define BIT_NON_DCP_INT                         ( BIT(12) )
#define BIT_CHG_DET_DONE                        ( BIT(11) )
#define BIT_DP_LOW                              ( BIT(10) )
#define BIT_DCP_DET                             ( BIT(9) )
#define BIT_CHG_DET                             ( BIT(8) )
#define BIT_SDP_INT                             ( BIT(7) )
#define BIT_DCP_INT                             ( BIT(6) )
#define BIT_CDP_INT                             ( BIT(5) )
#define BIT_CHGR_INT                            ( BIT(2) )
#define BIT_DCP_SWITCH_EN                       ( BIT(1) )

/* bits definitions for REG_CHGR_DET_FGU_CTRL, [0x000023A0] */
#define BIT_DP_DM_FC_ENB                        ( BIT(14) )
#define BIT_FGUA_SOFT_RST                       ( BIT(13) )
#define BIT_LDO_FGU_PD                          ( BIT(12) )
#define BIT_CHG_INT_DELAY(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_REDET_DELAY(x)                      ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DP_DM_AUX_EN                        ( BIT(1) )
#define BIT_DP_DM_BC_ENB                        ( BIT(0) )

/* bits definitions for REG_OVLO_CTRL, [0x000023A4] */
#define BIT_VBAT_CRASH_V(x)                     ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_OVLO_EN                             ( BIT(9) )
#define BIT_OVLO_V(x)                           ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_OVLO_T(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MIXED_CTRL, [0x000023A8] */
#define BIT_XOSC32K_CTL                         ( BIT(12) )
#define BIT_BATON_T(x)                          ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_DPDM_DET_VTHSEL                     ( BIT(9) )
#define BIT_BATDET_OK                           ( BIT(8) )
#define BIT_VBAT_OK                             ( BIT(4) )
#define BIT_ALL_GPI_DEB                         ( BIT(3) )
#define BIT_GPI_DEBUG_EN                        ( BIT(2) )
#define BIT_ALL_INT_DEB                         ( BIT(1) )
#define BIT_INT_DEBUG_EN                        ( BIT(0) )

/* bits definitions for REG_POR_RST_MONITOR, [0x000023AC] */
#define BIT_POR_RST_MONITOR(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_WDG_RST_MONITOR, [0x000023B0] */
#define BIT_WDG_RST_MONITOR(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_RESERVED_REG36, [0x000023B4] */

/* bits definitions for REG_POR_SRC_FLAG, [0x000023B8] */
#define BIT_POR_SW_FORCE_ON                     ( BIT(15) )
#define BIT_REG_SOFT_RST_FLG_CLR                ( BIT(14) )
#define BIT_REG_RST_FLG                         ( BIT(13) )
#define BIT_POR_SRC_FLAG(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_POR_OFF_FLAG, [0x000023BC] */
#define BIT_POR_CHIP_PD_FLAG                    ( BIT(13) )
#define BIT_POR_CHIP_PD_FLAG_CLR                ( BIT(12) )
#define BIT_UVLO_CHIP_PD_FLAG                   ( BIT(11) )
#define BIT_UVLO_CHIP_PD_FLAG_CLR               ( BIT(10) )
#define BIT_HARD_7S_CHIP_PD_FLAG                ( BIT(9) )
#define BIT_HARD_7S_CHIP_PD_FLAG_CLR            ( BIT(8) )
#define BIT_SW_CHIP_PD_FLAG                     ( BIT(7) )
#define BIT_SW_CHIP_PD_FLAG_CLR                 ( BIT(6) )
#define BIT_HW_CHIP_PD_FLAG                     ( BIT(5) )
#define BIT_HW_CHIP_PD_FLAG_CLR                 ( BIT(4) )
#define BIT_OTP_CHIP_PD_FLAG                    ( BIT(3) )
#define BIT_OTP_CHIP_PD_FLAG_CLR                ( BIT(2) )

/* bits definitions for REG_POR_7S_CTRL, [0x000023C0] */
#define BIT_PBINT_7S_FLAG_CLR                   ( BIT(15) )
#define BIT_EXT_RSTN_FLAG_CLR                   ( BIT(14) )
#define BIT_CHGR_INT_FLAG_CLR                   ( BIT(13) )
#define BIT_PBINT2_FLAG_CLR                     ( BIT(12) )
#define BIT_PBINT_FLAG_CLR                      ( BIT(11) )
#define BIT_KEY2_7S_RST_EN                      ( BIT(9) )
#define BIT_PBINT_7S_RST_SWMODE                 ( BIT(8) )
#define BITS_PBINT_7S_RST_THRESHOLD(x)           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_EXT_RSTN_MODE                       ( BIT(3) )
#define BIT_PBINT_7S_AUTO_ON_EN                 ( BIT(2) )
#define BIT_PBINT_7S_RST_DISABLE                ( BIT(1) )
#define BIT_PBINT_7S_RST_MODE                   ( BIT(0) )

/* bits definitions for REG_HWRST_RTC, [0x000023C4] */
#define BIT_HWRST_RTC_REG_STS(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_HWRST_RTC_REG_SET(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_ARCH_EN, [0x000023C8] */
#define BIT_ARCH_EN                             ( BIT(0) )

/* bits definitions for REG_MCU_WR_PROT_VALUE, [0x000023CC] */
#define BIT_MCU_WR_PROT                         ( BIT(15) )
#define BIT_MCU_WR_PROT_VALUE(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for REG_PWR_WR_PROT_VALUE, [0x000023D0] */
#define BIT_PWR_WR_PROT                         ( BIT(15) )
#define BITS_PWR_WR_PROT_VALUE(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for REG_DCDC_WR_PROT_VALUE, [0x000023D4] */
#define BIT_DCDC_WR_PROT                        ( BIT(15) )
#define BIT_DCDC_WR_PROT_VALUE(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for REG_POR_WR_PROT_VALUE, [0x000023D8] */
#define BIT_POR_WR_PROT                         ( BIT(15) )
#define BIT_POR_WR_PROT_VALUE(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for REG_SMPL_CTRL0, [0x000023DC] */
#define BIT_SMPL_MODE(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_SMPL_CTRL1, [0x000023E0] */
#define BIT_SMPL_PWR_ON_FLAG                    ( BIT(15) )
#define BIT_SMPL_MODE_WR_ACK_FLAG               ( BIT(14) )
#define BIT_SMPL_PWR_ON_FLAG_CLR                ( BIT(13) )
#define BIT_SMPL_MODE_WR_ACK_FLAG_CLR           ( BIT(12) )
#define BIT_SMPL_PWR_ON_SET                     ( BIT(11) )
#define BIT_SMPL_EN                             ( BIT(0) )

/* bits definitions for REG_RTC_RST0, [0x000023E4] */
#define BIT_RTC_CLK_FLAG_SET(x)                 ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_RTC_RST1, [0x000023E8] */
#define BIT_RTC_CLK_FLAG_CLR(x)                 ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_RTC_RST2, [0x000023EC] */
#define BIT_RTC_CLK_FLAG_RTC(x)                 ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_RTC_CLK_STOP, [0x000023F0] */
#define BIT_RTC_CLK_STOP_FLAG                   ( BIT(7) )
#define BIT_RTC_CLK_STOP_THRESHOLD(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_VBAT_DROP_CNT, [0x000023F4] */
#define BIT_VBAT_DROP_CNT(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for REG_SWRST_CTRL0, [0x000023F8] */
#define BIT_SW_RST_LDO_UFS1V2_PD_EN             ( BIT(12) )
#define BIT_SW_RST_LDOVDD_LDO1_PD_EN            ( BIT(11) )
#define BIT_SW_RST_DCDCSRAM0_PD_EN              ( BIT(9) )
#define BIT_EXT_RSTN_PD_EN                      ( BIT(8) )
#define BIT_PB_7S_RST_PD_EN                     ( BIT(7) )
#define BIT_REG_RST_PD_EN                       ( BIT(6) )
#define BIT_WDG_RST_PD_EN                       ( BIT(5) )
#define BIT_REG_RST_EN                          ( BIT(4) )
#define BIT_SW_RST_PD_THRESHOLD(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_HW_RST_CTRL, [0x000023FC] */
#define BIT_HW_OFF_RST_EN                       ( BIT(0) )

/* bits definitions for REG_SWRST_CTRL1, [0x00002400] */
#define BIT_SW_RST_DCDCGPU_PD_EN                ( BIT(15) )
#define BIT_SW_RST_DCDCPUB_PD_EN                ( BIT(14) )
#define BIT_SW_RST_DCDCMEMQ_PD_EN               ( BIT(13) )
#define BIT_SW_RST_DCDCMEM_PD_EN                ( BIT(12) )
#define BIT_SW_RST_DCDCGEN1_PD_EN               ( BIT(11) )
#define BIT_SW_RST_DCDCGEN0_PD_EN               ( BIT(10) )
#define BIT_SW_RST_DCDCCORE_PD_EN               ( BIT(9) )
#define BIT_SW_RST_LDO_AVDD12_PD_EN             ( BIT(8) )
#define BIT_SW_RST_LDOVDD18_DCXO_PD_EN          ( BIT(7) )
#define BIT_SW_RST_LDO_VDD28_PD_EN              ( BIT(6) )
#define BIT_SW_RST_LDO_AVDD18_PD_EN             ( BIT(5) )
#define BIT_SW_RST_LDOVDD_RF1V8_PD_EN           ( BIT(4) )
#define BIT_SW_RST_LDOVDD_USB33_PD_EN           ( BIT(3) )
#define BIT_SW_RST_LDOVDD_EMMCCORE_PD_EN        ( BIT(2) )
#define BIT_SW_RST_LDOVDD_SDIO_PD_EN            ( BIT(1) )
#define BIT_SW_RST_LDOVDD_SDCORE_PD_EN          ( BIT(0) )

/* bits definitions for REG_OTP_CTRL, [0x00002404] */
#define BIT_EXT_OTP_EN                          ( BIT(3) )
#define BIT_OTP_OP(x)                           ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_OTP_EN                              ( BIT(0) )

/* bits definitions for REG_FREE_TIMER_LOW, [0x00002408] */
#define BIT_TIMER_LOW(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_FREE_TIMER_HIGH, [0x0000240C] */
#define BIT_TIMER_HIGH(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_LOW_PWR_CLK32K_CTRL, [0x00002410] */
#define BIT_LOW_PWR_CLK32K_EN                   ( BIT(0) )

/* bits definitions for REG_VOL_TUNE_CTRL_CORE, [0x00002414] */
#define BIT_CORE_CLK_SEL                        ( BIT(14) )

/* bits definitions for REG_VOL_TUNE_CTRL_CPU2, [0x00002418] */
#define BIT_CPU2_STEP_DELAY(x)                  ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_CPU2_STEP_NUM(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_CPU2_STEP_VOL(x)                    ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_CPU2_VOL_TUNE_START                 ( BIT(2) )
#define BIT_CPU2_VOL_TUNE_FLAG                  ( BIT(1) )
#define BIT_CPU2_VOL_TUNE_EN                    ( BIT(0) )

/* bits definitions for REG_VOL_TUNE_CTRL_GPU, [0x0000241C] */
#define BIT_GPU_STEP_DELAY(x)                   ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_GPU_STEP_NUM(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_GPU_STEP_VOL(x)                     ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_GPU_VOL_TUNE_START                  ( BIT(2) )
#define BIT_GPU_VOL_TUNE_FLAG                   ( BIT(1) )
#define BIT_GPU_VOL_TUNE_EN                     ( BIT(0) )

/* bits definitions for REG_VOL_TUNE_CTRL_PUB, [0x00002420] */
#define BIT_PUB_STEP_DELAY(x)                   ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_STEP_NUM(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_STEP_VOL(x)                     ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_VOL_TUNE_START                  ( BIT(2) )
#define BIT_PUB_VOL_TUNE_FLAG                   ( BIT(1) )
#define BIT_PUB_VOL_TUNE_EN                     ( BIT(0) )

/* bits definitions for REG_DCDC_DVFS_EN, [0x00002424] */
#define BIT_DVFS_CPU1_CLK6M_SW_EN               ( BIT(8) )
#define BIT_DVFS_CPU2_CLK6M_SW_EN               ( BIT(7) )
#define BIT_DVFS_GPU_CLK6M_SW_EN                ( BIT(6) )
#define BIT_DVFS_PUB_CLK6M_SW_EN                ( BIT(5) )
#define BIT_DCDC_CPU1_DVFS_EN                   ( BIT(4) )
#define BIT_DCDC_CPU2_DVFS_EN                   ( BIT(3) )
#define BIT_DCDC_GPU_DVFS_EN                    ( BIT(2) )
#define BIT_DCDC_PUB_DVFS_EN                    ( BIT(0) )

/* bits definitions for REG_RESERVED_REG42, [0x00002428] */

/* bits definitions for REG_RESERVED_REG38, [0x0000242C] */

/* bits definitions for REG_RESERVED_REG39, [0x00002430] */

/* bits definitions for REG_RESERVED_REG40, [0x00002434] */

/* bits definitions for REG_BC1P2_CTRL_REG1, [0x00002438] */
#define BIT_BC1P2_SW_MODE                       ( BIT(7) )
#define BIT_BC1P2_VDP_SRC_EN                    ( BIT(6) )
#define BIT_BC1P2_IDP_SRC_EN                    ( BIT(5) )
#define BIT_BC1P2_IDM_SINK_EN                   ( BIT(4) )
#define BIT_BC1P2_DCP_DET_EN                    ( BIT(3) )
#define BIT_BC1P2_CHG_DET_EN                    ( BIT(2) )
#define BIT_BC1P2_VDM_SRC_EN                    ( BIT(1) )
#define BIT_BC1P2_RDM_DWN_EN                    ( BIT(0) )

/* bits definitions for REG_BC1P2_CTRL_REG2, [0x0000243C] */
#define BIT_BC1P2_REDET                         ( BIT(0) )

/* bits definitions for REG_DCDC_CPU1_REG0, [0x00002440] */
#define BIT_DCDC_CPU1_DEADTIME(x)               ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_DCDC_CPU1_PDRSLOW(x)                ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_DCDC_CPU1_PFMB                      ( BIT(2) )
#define BIT_DCDC_CPU1_DCMB                      ( BIT(1) )

/* bits definitions for REG_DCDC_CPU1_REG1, [0x00002444] */
#define BIT_DCDC_CPU1_CF(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_CPU1_CL_CTRL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DCDC_CPU1_REG2, [0x00002448] */
#define BIT_DCDC_CPU1_STBOP(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_DCDC_CPU1_ZCD(x)                    ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_DCDC_CPU1_PFMAD(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_DCDC_CPU1_VOL, [0x0000244C] */
#define BIT_FRACTION_DIV_CPU1(x)                ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_INTEGER_DIV_CPU1(x)                 ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_DCDC_CPU1_CTRL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_RESERVED_REG8, [0x00002450] */

/* bits definitions for REG_DCDC_VLG_SEL2, [0x00002454] */
#define BIT_DCDC_CPU1_PFMAD_SW_SEL              ( BIT(0) )

/* bits definitions for REG_XTL_WAIT_CTRL1, [0x00002458] */
#define BIT_EXT_XTL6_FOR_26M_EN                 ( BIT(6) )
#define BIT_EXT_XTL5_FOR_26M_EN                 ( BIT(5) )
#define BIT_EXT_XTL4_FOR_26M_EN                 ( BIT(4) )
#define BIT_EXT_XTL3_FOR_26M_EN                 ( BIT(3) )
#define BIT_EXT_XTL2_FOR_26M_EN                 ( BIT(2) )
#define BIT_EXT_XTL1_FOR_26M_EN                 ( BIT(1) )
#define BIT_EXT_XTL0_FOR_26M_EN                 ( BIT(0) )

/* bits definitions for REG_LDO_VDDCAMA2_REG0, [0x00002460] */
#define BIT_LDO_VDDCAMA2_REFTRIM(x)             ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_LDO_VDDCAMA2_SHPT_PD                ( BIT(1) )
#define BIT_LDO_VDDCAMA2_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDCAMA2_REG1, [0x00002464] */
#define BIT_LDO_VDDCAMA2_V(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RESERVED_REG24, [0x00002468] */

/* bits definitions for REG_LDO_XTL_EN13, [0x0000246C] */
#define BIT_LDO_VDDCAMMOT1_EXT_XTL6_EN          ( BIT(14) )
#define BIT_LDO_VDDCAMMOT1_EXT_XTL5_EN          ( BIT(13) )
#define BIT_LDO_VDDCAMMOT1_EXT_XTL4_EN          ( BIT(12) )
#define BIT_LDO_VDDCAMMOT1_EXT_XTL3_EN          ( BIT(11) )
#define BIT_LDO_VDDCAMMOT1_EXT_XTL2_EN          ( BIT(10) )
#define BIT_LDO_VDDCAMMOT1_EXT_XTL1_EN          ( BIT(9) )
#define BIT_LDO_VDDCAMMOT1_EXT_XTL0_EN          ( BIT(8) )
#define BIT_LDO_VDDCAMA2_EXT_XTL6_EN            ( BIT(6) )
#define BIT_LDO_VDDCAMA2_EXT_XTL5_EN            ( BIT(5) )
#define BIT_LDO_VDDCAMA2_EXT_XTL4_EN            ( BIT(4) )
#define BIT_LDO_VDDCAMA2_EXT_XTL3_EN            ( BIT(3) )
#define BIT_LDO_VDDCAMA2_EXT_XTL2_EN            ( BIT(2) )
#define BIT_LDO_VDDCAMA2_EXT_XTL1_EN            ( BIT(1) )
#define BIT_LDO_VDDCAMA2_EXT_XTL0_EN            ( BIT(0) )

/* bits definitions for REG_LDO_XTL_EN14, [0x00002470] */
#define BIT_LDO_VDDCAMD2_EXT_XTL6_EN            ( BIT(14) )
#define BIT_LDO_VDDCAMD2_EXT_XTL5_EN            ( BIT(13) )
#define BIT_LDO_VDDCAMD2_EXT_XTL4_EN            ( BIT(12) )
#define BIT_LDO_VDDCAMD2_EXT_XTL3_EN            ( BIT(11) )
#define BIT_LDO_VDDCAMD2_EXT_XTL2_EN            ( BIT(10) )
#define BIT_LDO_VDDCAMD2_EXT_XTL1_EN            ( BIT(9) )
#define BIT_LDO_VDDCAMD2_EXT_XTL0_EN            ( BIT(8) )
#define BIT_LDO_VDDLDO3_EXT_XTL6_EN             ( BIT(6) )
#define BIT_LDO_VDDLDO3_EXT_XTL5_EN             ( BIT(5) )
#define BIT_LDO_VDDLDO3_EXT_XTL4_EN             ( BIT(4) )
#define BIT_LDO_VDDLDO3_EXT_XTL3_EN             ( BIT(3) )
#define BIT_LDO_VDDLDO3_EXT_XTL2_EN             ( BIT(2) )
#define BIT_LDO_VDDLDO3_EXT_XTL1_EN             ( BIT(1) )
#define BIT_LDO_VDDLDO3_EXT_XTL0_EN             ( BIT(0) )

/* bits definitions for REG_LDO_VLG_SEL3, [0x00002474] */
#define BIT_LDO_VDDCAMA2_SW_SEL                 ( BIT(4) )
#define BIT_LDO_VDDCAMA1_SW_SEL                 ( BIT(3) )
#define BIT_LDO_VDDCAMA0_SW_SEL                 ( BIT(2) )
#define BIT_LDO_VDDCAMMOT1_SW_SEL               ( BIT(1) )
#define BIT_LDO_VDDCAMMOT0_SW_SEL               ( BIT(0) )

/* bits definitions for REG_SLP_LDO_PD_CTRL2, [0x00002478] */
#define BIT_SLP_LDO_VDDCAMD2_PD_EN              ( BIT(4) )
#define BIT_SLP_LDO_VDDCAMA2_PD_EN              ( BIT(3) )

/* bits definitions for REG_SLP_LDO_LP_CTRL2, [0x0000247C] */
#define BIT_SLP_LDO_VDDCAMD2_LP_EN              ( BIT(5) )
#define BIT_SLP_LDO_VDDCAMA2_LP_EN              ( BIT(4) )

/* bits definitions for REG_LDO_VDDLDO3_REG0, [0x00002480] */
#define BIT_LDO_VDDLDO3_SHPT_PD                 ( BIT(6) )
#define BIT_LDO_VDDLDO3_REFTRIM(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )
#define BIT_LDO_VDDLDO3_PD                      ( BIT(0) )

/* bits definitions for REG_LDO_VDDLDO3_REG1, [0x00002484] */
#define BIT_LDO_VDDLDO3_V(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RESERVED_REG25, [0x00002488] */

/* bits definitions for REG_LDO_VDDCAMD2_REG0, [0x0000248C] */
#define BIT_LDO_VDDCAMD2_SHPT_PD                ( BIT(6) )
#define BIT_LDO_VDDCAMD2_REFTRIM(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )
#define BIT_LDO_VDDCAMD2_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDCAMD2_REG1, [0x00002490] */
#define BIT_LDO_VDDCAMD2_V(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_RESERVED_REG26, [0x00002494] */

/* bits definitions for REG_LDO_VDDRF1V1_REG0, [0x00002498] */
#define BIT_LDO_VDDRF1V1_SHPT_PD                ( BIT(6) )
#define BIT_LDO_VDDRF1V1_REFTRIM(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )
#define BIT_LDO_VDDRF1V1_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDRF1V1_REG1, [0x0000249C] */
#define BIT_LDO_VDDRF1V1_V(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_RESERVED_REG27, [0x000024A0] */

/* bits definitions for REG_LDO_VDDRF0V9_REG0, [0x000024A4] */
#define BIT_LDO_VDDRF0V9_SHPT_PD                ( BIT(6) )
#define BIT_LDO_VDDRF0V9_REFTRIM(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )
#define BIT_LDO_VDDRF0V9_PD                     ( BIT(0) )

/* bits definitions for REG_LDO_VDDRF0V9_REG1, [0x000024A8] */
#define BIT_LDO_VDDRF0V9_V(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_RESERVED92, [0x000024AC] */

/* bits definitions for REG_LDO_VDDUFS1V2_REG0, [0x000024B0] */
#define BIT_LDO_VDDUFS1V2_SHPT_PD               ( BIT(6) )
#define BIT_LDO_VDDUFS1V2_REFTRIM(x)            ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )
#define BIT_LDO_VDDUFS1V2_PD                    ( BIT(0) )

/* bits definitions for REG_LDO_VDDUFS1V2_REG1, [0x000024B4] */
#define BIT_LDO_VDDUFS1V2_V(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_RESERVED_REG28, [0x000024B8] */

/* bits definitions for REG_LDO_XTL_EN15, [0x000024BC] */
#define BIT_LDO_VDDLDO4_EXT_XTL6_EN             ( BIT(14) )
#define BIT_LDO_VDDLDO4_EXT_XTL5_EN             ( BIT(13) )
#define BIT_LDO_VDDLDO4_EXT_XTL4_EN             ( BIT(12) )
#define BIT_LDO_VDDLDO4_EXT_XTL3_EN             ( BIT(11) )
#define BIT_LDO_VDDLDO4_EXT_XTL2_EN             ( BIT(10) )
#define BIT_LDO_VDDLDO4_EXT_XTL1_EN             ( BIT(9) )
#define BIT_LDO_VDDLDO4_EXT_XTL0_EN             ( BIT(8) )
#define BIT_LDO_VDDUFS1V2_EXT_XTL6_EN           ( BIT(6) )
#define BIT_LDO_VDDUFS1V2_EXT_XTL5_EN           ( BIT(5) )
#define BIT_LDO_VDDUFS1V2_EXT_XTL4_EN           ( BIT(4) )
#define BIT_LDO_VDDUFS1V2_EXT_XTL3_EN           ( BIT(3) )
#define BIT_LDO_VDDUFS1V2_EXT_XTL2_EN           ( BIT(2) )
#define BIT_LDO_VDDUFS1V2_EXT_XTL1_EN           ( BIT(1) )
#define BIT_LDO_VDDUFS1V2_EXT_XTL0_EN           ( BIT(0) )

/* bits definitions for REG_CHG_IRQ_CLR, [0x000024C0] */
#define BIT_CHG_INT_CLR_ST                      ( BIT(1) )
#define BIT_CHG_IRQ_CLR                         ( BIT(0) )

/* bits definitions for REG_RESERVED_REG29, [0x000024C4] */

/* bits definitions for REG_VOL_TUNE_CTRL_CPU1, [0x000024C8] */
#define BIT_CPU1_STEP_DELAY(x)                  ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_CPU1_STEP_NUM(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_CPU1_STEP_VOL(x)                    ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_CPU1_VOL_TUNE_START                 ( BIT(2) )
#define BIT_CPU1_VOL_TUNE_FLAG                  ( BIT(1) )
#define BIT_CPU1_VOL_TUNE_EN                    ( BIT(0) )

/* bits definitions for REG_DCDC_CPU1_REG3, [0x000024CC] */
#define BIT_DCDC_CPU1_INDP_CTRL(x)              ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_DCDC_CPU1_INSP_CTRL(x)              ( (x) << 7  & (BIT(7)|BIT(8)) )
#define BIT_DCDC_CPU1_DP_EN                     ( BIT(6) )
#define BIT_DCDC_CPU1_REV(x)                    ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_LDO_VDDLDO4_REG0, [0x000024D0] */
#define BIT_LDO_VDDLDO4_SHPT_PD                 ( BIT(6) )
#define BIT_LDO_VDDLDO4_REFTRIM(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )
#define BIT_LDO_VDDLDO4_PD                      ( BIT(0) )

/* bits definitions for REG_LDO_VDDLDO4_REG1, [0x000024D4] */
#define BIT_LDO_VDDLDO4_V(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* vars definitions for controller CTL_ANA */


#endif /* __ANA_H____ */
