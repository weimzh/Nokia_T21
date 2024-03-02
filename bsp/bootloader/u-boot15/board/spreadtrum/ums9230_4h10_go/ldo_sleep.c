#include <asm/arch-sc9630/sci_types.h>
#include <adi_hal_internal.h>
#include <asm/arch/common.h>
#include <asm/arch/sprd_reg.h>
#include "asm/arch-qogirl6/sprd_reg.h"
#include "asm/arch-qogirl6/common.h"
#include <chipram_env.h>

#define REFOUT0_ON	BIT(0)
#define REFOUT1_ON	BIT(1)
#define REFOUT2_ON	BIT(2)
#define REFOUT3_ON	BIT(3)
#define REFOUT4_ON	BIT(4)

void DCDC_ldo_power_on()
{
	//regulator_enable("vddcore");
	//regulator_enable("vddcpu");
	//regulator_enable("vddgpu");
	//regulator_enable("vddmodem");
	//regulator_enable("vddmem");
	//regulator_enable("vddmemq");
	//regulator_enable("vddgen0");
	//regulator_enable("vddgen1");
	//regulator_enable("vddsram");
	//regulator_enable("avdd18");
	//regulator_enable("vddrf1v8");
	//regulator_enable("vddwcn");
	//regulator_enable("vddcamd1");
	//regulator_enable("vddcamd0");
	regulator_enable("vddrf1v25");
	//regulator_enable("avdd12");
	//regulator_enable("vddcama0");
	//regulator_enable("vddcama1");
	//regulator_enable("vddcammot");
	//regulator_enable("vddsim0");
	//regulator_enable("vddsim1");
	//regulator_enable("vddsim2");
	//regulator_enable("vddemmccore");
	//regulator_enable("vddsdcore");
	//regulator_enable("vddsdio");
	//regulator_enable("vdd28");
	//regulator_enable("vddwifipa");
	//regulator_enable("vdddcxo");
	//regulator_enable("vddusb33");
	regulator_enable("vddldo0");
	//regulator_enable("vddldo1");
	regulator_enable("vddldo2");
}

void pmic_lowpower_config(uint32_t gen_para)
{
#if defined(CONFIG_ADIE_SC2730)
	uint32_t ddie_id;
	uint32_t adie_id;

	ddie_id = CHIP_REG_GET(REG_AON_APB_AON_VER_ID);
	adie_id = ANA_REG_GET(ANA_REG_GLB_CHIP_ID_LOW);

	ANA_REG_SET(ANA_REG_GLB_PWR_WR_PROT_VALUE,0x6e7f);
	while( (ANA_REG_GET(ANA_REG_GLB_PWR_WR_PROT_VALUE) & 0x8000) != 0x8000 );

	ANA_REG_SET(ANA_REG_GLB_POWER_PD_SW,
		//BIT_DCDC_SRAM_PD |
		//BIT_DCDC_MEMQ_PD |
		//BIT_DCDC_MODEM_PD |
		//BIT_LDO_VDD18_DCXO_PD |
		//BIT_LDO_EMM_PD |
		//BIT_DCDC_GEN0_PD |
		//BIT_DCDC_GEN1_PD |
		//BIT_DCDC_MEM_PD |
		//BIT_DCDC_CORE_PD |
		//BIT_DCDC_CPU_PD |
		//BIT_DCDC_GPU_PD |
		//BIT_LDO_AVDD18_PD |
		//BIT_LDO_VDD28_PD |
		//BIT_BG_PD |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_PWR_WR_PROT_VALUE,0x0000);

	ANA_REG_SET(ANA_REG_GLB_SLP_CTRL,
		BIT_LDO_XTL_EN |
		BIT_SLP_IO_EN |
		BIT_SLP_LDO_PD_EN |
		0
	);

	if (get_bootdevice() == BOOT_DEVICE_UFS) {
		ANA_REG_SET(ANA_REG_GLB_SLP_DCDC_PD_CTRL,
			BIT_SLP_DCDCMODEM_PD_EN |
			BIT_SLP_DCDCMEMQ_PD_EN |
			BIT_SLP_DCDCSRAM_PD_EN |
			//BIT_SLP_DCDCSRAM_DROP_EN |
			//BIT_SLP_DCDCMODEM_DROP_EN |
			//BIT_SLP_DCDCGPU_DROP_EN |
			BIT_SLP_DCDCCORE_DROP_EN |
			//BIT_SLP_DCDCWPA_PD_EN |
			BIT_SLP_DCDCGPU_PD_EN |
			BIT_SLP_DCDCCPU_PD_EN |
			//BIT_SLP_DCDCGEN1_PD_EN |
			0
		);

		ANA_REG_SET(ANA_REG_GLB_SLP_LDO_PD_CTRL0,
			BIT_SLP_LDO_VDDRF1V8_PD_EN |
			BIT_SLP_LDO_VDDRF1V25_PD_EN |
			//BIT_SLP_LDO_VDDEMMCCORE_PD_EN |
			//BIT_SLP_LDO_VDD18_DCXO_PD_EN |
			//BIT_SLP_LDO_VDDWIFIPA_PD_EN |
			//BIT_SLP_LDO_VDD28_PD_EN |
			//BIT_SLP_LDO_VDDSDCORE_PD_EN |
			//BIT_SLP_LDO_VDDSDIO_PD_EN |
			//BIT_SLP_LDO_VDDUSB33_PD_EN |
			//BIT_SLP_LDO_VDDCAMMOT_PD_EN |
			//BIT_SLP_LDO_VDDCAMIO_PD_EN |
			//BIT_SLP_LDO_VDDCAMD0_PD_EN |
			//BIT_SLP_LDO_VDDCAMA0_PD_EN |
			//BIT_SLP_LDO_VDDSIM2_PD_EN |
			//BIT_SLP_LDO_VDDSIM1_PD_EN |
			0
		);

		ANA_REG_SET(ANA_REG_GLB_SLP_LDO_PD_CTRL1,
			//BIT_SLP_LDO_VDDLDO2_PD_EN |
			//BIT_SLP_LDO_AVDD12_PD_EN |
			//BIT_SLP_LDO_VDDWCN_PD_EN |
			BIT_SLP_LDO_VDDLDO0_PD_EN |
			//BIT_SLP_LDO_VDDCAMD1_PD_EN |
			//BIT_SLP_LDO_VDDCAMA1_PD_EN |
			//BIT_SLP_LDO_VDDSIM0_PD_EN |
			//BIT_SLP_LDO_AVDD18_PD_EN |
			//BIT_SLP_LDO_VDDLDO1_PD_EN |
			0
		);
	} else {
		ANA_REG_SET(ANA_REG_GLB_SLP_DCDC_PD_CTRL,
			BIT_SLP_DCDCMODEM_PD_EN |
			BIT_SLP_DCDCMEMQ_PD_EN |
			BIT_SLP_DCDCSRAM_PD_EN |
			//BIT_SLP_DCDCSRAM_DROP_EN |
			//BIT_SLP_DCDCMODEM_DROP_EN |
			//BIT_SLP_DCDCGPU_DROP_EN |
			BIT_SLP_DCDCCORE_DROP_EN |
			//BIT_SLP_DCDCWPA_PD_EN |
			BIT_SLP_DCDCGPU_PD_EN |
			BIT_SLP_DCDCCPU_PD_EN |
			BIT_SLP_DCDCGEN1_PD_EN |
			0
		);

		ANA_REG_SET(ANA_REG_GLB_SLP_LDO_PD_CTRL0,
			BIT_SLP_LDO_VDDRF1V8_PD_EN |
			BIT_SLP_LDO_VDDRF1V25_PD_EN |
			//BIT_SLP_LDO_VDDEMMCCORE_PD_EN |
			//BIT_SLP_LDO_VDD18_DCXO_PD_EN |
			//BIT_SLP_LDO_VDDWIFIPA_PD_EN |
			//BIT_SLP_LDO_VDD28_PD_EN |
			//BIT_SLP_LDO_VDDSDCORE_PD_EN |
			//BIT_SLP_LDO_VDDSDIO_PD_EN |
			//BIT_SLP_LDO_VDDUSB33_PD_EN |
			//BIT_SLP_LDO_VDDCAMMOT_PD_EN |
			//BIT_SLP_LDO_VDDCAMIO_PD_EN |
			//BIT_SLP_LDO_VDDCAMD0_PD_EN |
			//BIT_SLP_LDO_VDDCAMA0_PD_EN |
			//BIT_SLP_LDO_VDDSIM2_PD_EN |
			//BIT_SLP_LDO_VDDSIM1_PD_EN |
			0
		);

		ANA_REG_SET(ANA_REG_GLB_SLP_LDO_PD_CTRL1,
			//BIT_SLP_LDO_VDDLDO2_PD_EN |
			BIT_SLP_LDO_AVDD12_PD_EN |
			//BIT_SLP_LDO_VDDWCN_PD_EN |
			BIT_SLP_LDO_VDDLDO0_PD_EN |
			//BIT_SLP_LDO_VDDCAMD1_PD_EN |
			//BIT_SLP_LDO_VDDCAMA1_PD_EN |
			//BIT_SLP_LDO_VDDSIM0_PD_EN |
			BIT_SLP_LDO_AVDD18_PD_EN |
			//BIT_SLP_LDO_VDDLDO1_PD_EN |
			0
		);
	}

	if(adie_id < 0xB000) {
		ANA_REG_SET(ANA_REG_GLB_SLP_DCDC_LP_CTRL,
			BIT_SLP_DCDCSRAM_LP_EN |
			BIT_SLP_DCDCMODEM_LP_EN |
			BIT_SLP_DCDCMEMQ_LP_EN |
			BIT_SLP_DCDCMEM_LP_EN |
			//BIT_SLP_DCDCGPU_LP_EN |
			//BIT_SLP_DCDCCORE_LP_EN |
			BIT_SLP_DCDCCPU_LP_EN |
			BIT_SLP_DCDCGEN1_LP_EN |
			BIT_SLP_DCDCGEN0_LP_EN |
			BIT_SLP_DCDCWPA_LP_EN |
			0
		);
	} else {
		ANA_REG_SET(ANA_REG_GLB_SLP_DCDC_LP_CTRL,
			BIT_SLP_DCDCSRAM_LP_EN |
			BIT_SLP_DCDCMODEM_LP_EN |
			BIT_SLP_DCDCMEMQ_LP_EN |
			BIT_SLP_DCDCMEM_LP_EN |
			BIT_SLP_DCDCGPU_LP_EN |
			BIT_SLP_DCDCCORE_LP_EN |
			BIT_SLP_DCDCCPU_LP_EN |
			BIT_SLP_DCDCGEN1_LP_EN |
			BIT_SLP_DCDCGEN0_LP_EN |
			BIT_SLP_DCDCWPA_LP_EN |
			0
		);
	}

	ANA_REG_SET(ANA_REG_GLB_SLP_LDO_LP_CTRL0,
		BIT_SLP_LDO_VDDRF1V8_LP_EN |
		//BIT_SLP_LDO_VDDRF1V25_LP_EN |
		//BIT_SLP_LDO_VDDEMMCCORE_LP_EN |
		BIT_SLP_LDO_VDD18_DCXO_LP_EN |
		//BIT_SLP_LDO_VDDWIFIPA_LP_EN |
		BIT_SLP_LDO_VDD28_LP_EN |
		//BIT_SLP_LDO_VDDSDCORE_LP_EN |
		//BIT_SLP_LDO_VDDSDIO_LP_EN |
		//BIT_SLP_LDO_VDDUSB33_LP_EN |
		//BIT_SLP_LDO_VDDCAMMOT_LP_EN |
		//BIT_SLP_LDO_VDDCAMD0_LP_EN |
		//BIT_SLP_LDO_VDDCAMA0_LP_EN |
		//BIT_SLP_LDO_VDDSIM2_LP_EN |
		//BIT_SLP_LDO_VDDSIM1_LP_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_SLP_LDO_LP_CTRL1,
		BIT_SLP_LDO_VDDLDO2_LP_EN |
		//BIT_SLP_LDO_AVDD12_LP_EN |
		//BIT_SLP_LDO_VDDWCN_LP_EN |
		//BIT_SLP_LDO_VDDCAMD1_LP_EN |
		//BIT_SLP_LDO_VDDCAMA1_LP_EN |
		//BIT_SLP_LDO_VDDLDO0_LP_EN |
		//BIT_SLP_LDO_VDDSIM0_LP_EN |
		BIT_SLP_LDO_AVDD18_LP_EN |
		//BIT_SLP_LDO_VDDLDO1_LP_EN |
		0
	);

	// EXT_XTL_EN config
	ANA_REG_SET(ANA_REG_GLB_DCDC_XTL_EN,
		BIT_DCDC_CORE_EXT_XTL0_EN |
		//BIT_DCDC_CORE_EXT_XTL1_EN |
		BIT_DCDC_CORE_EXT_XTL2_EN |
		//BIT_DCDC_CORE_EXT_XTL3_EN |              //WCN Lopower request
		//BIT_DCDC_CORE_EXT_XTL4_EN |
		//BIT_DCDC_CORE_EXT_XTL5_EN |
		//BIT_DCDC_WPA_EXT_XTL0_EN |
		//BIT_DCDC_WPA_EXT_XTL1_EN |
		//BIT_DCDC_WPA_EXT_XTL2_EN |
		//BIT_DCDC_WPA_EXT_XTL3_EN |
		//BIT_DCDC_WPA_EXT_XTL4_EN |
		//BIT_DCDC_WPA_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_DCDC_XTL_EN0,
		BIT_DCDC_GEN0_EXT_XTL0_EN |
		//BIT_DCDC_GEN0_EXT_XTL1_EN |
		BIT_DCDC_GEN0_EXT_XTL2_EN |
		BIT_DCDC_GEN0_EXT_XTL3_EN |
		//BIT_DCDC_GEN0_EXT_XTL4_EN |
		//BIT_DCDC_GEN0_EXT_XTL5_EN |
		BIT_DCDC_SRAM_EXT_XTL0_EN |
		//BIT_DCDC_SRAM_EXT_XTL1_EN |
		//BIT_DCDC_SRAM_EXT_XTL2_EN |
		//BIT_DCDC_SRAM_EXT_XTL3_EN |
		//BIT_DCDC_SRAM_EXT_XTL4_EN |
		//BIT_DCDC_SRAM_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_DCDC_XTL_EN1,
		//BIT_DCDC_CPU_EXT_XTL0_EN |
		//BIT_DCDC_CPU_EXT_XTL1_EN |
		//BIT_DCDC_CPU_EXT_XTL2_EN |
		//BIT_DCDC_CPU_EXT_XTL3_EN |
		//BIT_DCDC_CPU_EXT_XTL4_EN |
		//BIT_DCDC_CPU_EXT_XTL5_EN |
		//BIT_DCDC_GPU_EXT_XTL0_EN |
		//BIT_DCDC_GPU_EXT_XTL1_EN |
		//BIT_DCDC_GPU_EXT_XTL2_EN |
		//BIT_DCDC_GPU_EXT_XTL3_EN |
		//BIT_DCDC_GPU_EXT_XTL4_EN |
		//BIT_DCDC_GPU_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_DCDC_XTL_EN2,
		BIT_DCDC_MEM_EXT_XTL0_EN |
		//BIT_DCDC_MEM_EXT_XTL1_EN |
		//BIT_DCDC_MEM_EXT_XTL2_EN |
		BIT_DCDC_MEM_EXT_XTL3_EN |
		//BIT_DCDC_MEM_EXT_XTL4_EN |
		//BIT_DCDC_MEM_EXT_XTL5_EN |
		//BIT_DCDC_GEN1_EXT_XTL0_EN |
		//BIT_DCDC_GEN1_EXT_XTL1_EN |
		//BIT_DCDC_GEN1_EXT_XTL2_EN |
		BIT_DCDC_GEN1_EXT_XTL3_EN |
		//BIT_DCDC_GEN1_EXT_XTL4_EN |
		//BIT_DCDC_GEN1_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_DCDC_XTL_EN3,
		BIT_DCDC_MEMQ_EXT_XTL0_EN |
		//BIT_DCDC_MEMQ_EXT_XTL1_EN |
		//BIT_DCDC_MEMQ_EXT_XTL2_EN |
		BIT_DCDC_MEMQ_EXT_XTL3_EN |
		//BIT_DCDC_MEMQ_EXT_XTL4_EN |
		//BIT_DCDC_MEMQ_EXT_XTL5_EN |
		BIT_DCDC_MODEM_EXT_XTL0_EN |
		//BIT_DCDC_MODEM_EXT_XTL1_EN |
		//BIT_DCDC_MODEM_EXT_XTL2_EN |
		//BIT_DCDC_MODEM_EXT_XTL3_EN |
		//BIT_DCDC_MODEM_EXT_XTL4_EN |
		//BIT_DCDC_MODEM_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN0,
		BIT_LDO_VDD18_DCXO_EXT_XTL0_EN |
		//BIT_LDO_VDD18_DCXO_EXT_XTL1_EN |
		//BIT_LDO_VDD18_DCXO_EXT_XTL2_EN |
		BIT_LDO_VDD18_DCXO_EXT_XTL3_EN |             // WCN for vdd18 dcxo
		//BIT_LDO_VDD18_DCXO_EXT_XTL4_EN |
		//BIT_LDO_VDD18_DCXO_EXT_XTL5_EN |
		BIT_LDO_VDD28_EXT_XTL0_EN |
		//BIT_LDO_VDD28_EXT_XTL1_EN |
		BIT_LDO_VDD28_EXT_XTL2_EN |
		BIT_LDO_VDD28_EXT_XTL3_EN |                   //WCN for Pad pin
		//BIT_LDO_VDD28_EXT_XTL4_EN |
		//BIT_LDO_VDD28_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN1,
		//BIT_LDO_VDDRF1V8_EXT_XTL0_EN |
		//BIT_LDO_VDDRF1V8_EXT_XTL1_EN |
		//BIT_LDO_VDDRF1V8_EXT_XTL2_EN |
		//BIT_LDO_VDDRF1V8_EXT_XTL3_EN |
		//BIT_LDO_VDDRF1V8_EXT_XTL4_EN |
		//BIT_LDO_VDDRF1V8_EXT_XTL5_EN |
		//BIT_LDO_VDDRF1V25_EXT_XTL0_EN |
		//BIT_LDO_VDDRF1V25_EXT_XTL1_EN |
		//BIT_LDO_VDDRF1V25_EXT_XTL2_EN |
		//BIT_LDO_VDDRF1V25_EXT_XTL3_EN |
		//BIT_LDO_VDDRF1V25_EXT_XTL4_EN |
		//BIT_LDO_VDDRF1V25_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN2,
		//BIT_LDO_VDDSIM0_EXT_XTL0_EN |
		//BIT_LDO_VDDSIM0_EXT_XTL1_EN |
		//BIT_LDO_VDDSIM0_EXT_XTL2_EN |
		//BIT_LDO_VDDSIM0_EXT_XTL3_EN |
		//BIT_LDO_VDDSIM0_EXT_XTL4_EN |
		//BIT_LDO_VDDSIM0_EXT_XTL5_EN |
		//BIT_LDO_VDDSIM1_EXT_XTL0_EN |
		//BIT_LDO_VDDSIM1_EXT_XTL1_EN |
		//BIT_LDO_VDDSIM1_EXT_XTL2_EN |
		//BIT_LDO_VDDSIM1_EXT_XTL3_EN |
		//BIT_LDO_VDDSIM1_EXT_XTL4_EN |
		//BIT_LDO_VDDSIM1_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN3,
		//BIT_LDO_VDDSIM2_EXT_XTL0_EN |
		//BIT_LDO_VDDSIM2_EXT_XTL1_EN |
		//BIT_LDO_VDDSIM2_EXT_XTL2_EN |
		BIT_LDO_VDDSIM2_EXT_XTL3_EN |
		//BIT_LDO_VDDSIM2_EXT_XTL4_EN |
		//BIT_LDO_VDDSIM2_EXT_XTL5_EN |
		//BIT_LDO_AVDD12_EXT_XTL0_EN |
		//BIT_LDO_AVDD12_EXT_XTL1_EN |
		//BIT_LDO_AVDD12_EXT_XTL2_EN |
		//BIT_LDO_AVDD12_EXT_XTL3_EN |
		//BIT_LDO_AVDD12_EXT_XTL4_EN |
		//BIT_LDO_AVDD12_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN4,
		//BIT_LDO_VDDCAMMOT_EXT_XTL0_EN |
		//BIT_LDO_VDDCAMMOT_EXT_XTL1_EN |
		//BIT_LDO_VDDCAMMOT_EXT_XTL2_EN |
		//BIT_LDO_VDDCAMMOT_EXT_XTL3_EN |
		//BIT_LDO_VDDCAMMOT_EXT_XTL4_EN |
		//BIT_LDO_VDDCAMMOT_EXT_XTL5_EN |
		//BIT_LDO_VDDCAMIO_EXT_XTL0_EN |
		//BIT_LDO_VDDCAMIO_EXT_XTL1_EN |
		//BIT_LDO_VDDCAMIO_EXT_XTL2_EN |
		//BIT_LDO_VDDCAMIO_EXT_XTL3_EN |
		//BIT_LDO_VDDCAMIO_EXT_XTL4_EN |
		//BIT_LDO_VDDCAMIO_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN5,
		//BIT_LDO_VDDCAMA0_EXT_XTL0_EN |
		//BIT_LDO_VDDCAMA0_EXT_XTL1_EN |
		//BIT_LDO_VDDCAMA0_EXT_XTL2_EN |
		//BIT_LDO_VDDCAMA0_EXT_XTL3_EN |
		//BIT_LDO_VDDCAMA0_EXT_XTL4_EN |
		//BIT_LDO_VDDCAMA0_EXT_XTL5_EN |
		//BIT_LDO_VDDCAMA1_EXT_XTL0_EN |
		//BIT_LDO_VDDCAMA1_EXT_XTL1_EN |
		//BIT_LDO_VDDCAMA1_EXT_XTL2_EN |
		//BIT_LDO_VDDCAMA1_EXT_XTL3_EN |
		//BIT_LDO_VDDCAMA1_EXT_XTL4_EN |
		//BIT_LDO_VDDCAMA1_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN6,
		//BIT_LDO_VDDCAMD0_EXT_XTL0_EN |
		//BIT_LDO_VDDCAMD0_EXT_XTL1_EN |
		//BIT_LDO_VDDCAMD0_EXT_XTL2_EN |
		//BIT_LDO_VDDCAMD0_EXT_XTL3_EN |
		//BIT_LDO_VDDCAMD0_EXT_XTL4_EN |
		//BIT_LDO_VDDCAMD0_EXT_XTL5_EN |
		//BIT_LDO_VDDCAMD1_EXT_XTL0_EN |
		//BIT_LDO_VDDCAMD1_EXT_XTL1_EN |
		//BIT_LDO_VDDCAMD1_EXT_XTL2_EN |
		//BIT_LDO_VDDCAMD1_EXT_XTL3_EN |
		//BIT_LDO_VDDCAMD1_EXT_XTL4_EN |
		//BIT_LDO_VDDCAMD1_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN7,
		//BIT_LDO_VDDSDIO_EXT_XTL0_EN |
		//BIT_LDO_VDDSDIO_EXT_XTL1_EN |
		//BIT_LDO_VDDSDIO_EXT_XTL2_EN |
		//BIT_LDO_VDDSDIO_EXT_XTL3_EN |
		//BIT_LDO_VDDSDIO_EXT_XTL4_EN |
		//BIT_LDO_VDDSDIO_EXT_XTL5_EN |
		//BIT_LDO_VDDSDCORE_EXT_XTL0_EN |
		//BIT_LDO_VDDSDCORE_EXT_XTL1_EN |
		//BIT_LDO_VDDSDCORE_EXT_XTL2_EN |
		//BIT_LDO_VDDSDCORE_EXT_XTL3_EN |
		//BIT_LDO_VDDSDCORE_EXT_XTL4_EN |
		//BIT_LDO_VDDSDCORE_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN8,
		//BIT_LDO_VDDEMMCCORE_EXT_XTL0_EN |
		//BIT_LDO_VDDEMMCCORE_EXT_XTL1_EN |
		//BIT_LDO_VDDEMMCCORE_EXT_XTL2_EN |
		//BIT_LDO_VDDEMMCCORE_EXT_XTL3_EN |
		//BIT_LDO_VDDEMMCCORE_EXT_XTL4_EN |
		//BIT_LDO_VDDEMMCCORE_EXT_XTL5_EN |
		//BIT_LDO_VDDUSB33_EXT_XTL0_EN |
		//BIT_LDO_VDDUSB33_EXT_XTL1_EN |
		//BIT_LDO_VDDUSB33_EXT_XTL2_EN |
		//BIT_LDO_VDDUSB33_EXT_XTL3_EN |
		//BIT_LDO_VDDUSB33_EXT_XTL4_EN |
		//BIT_LDO_VDDUSB33_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN9,
		//BIT_LDO_VDDKPLED_EXT_XTL0_EN |
		//BIT_LDO_VDDKPLED_EXT_XTL1_EN |
		//BIT_LDO_VDDKPLED_EXT_XTL2_EN |
		//BIT_LDO_VDDKPLED_EXT_XTL3_EN |
		//BIT_LDO_VDDKPLED_EXT_XTL4_EN |
		//BIT_LDO_VDDKPLED_EXT_XTL5_EN |
		//BIT_LDO_VDDVIB_EXT_XTL0_EN |
		//BIT_LDO_VDDVIB_EXT_XTL1_EN |
		//BIT_LDO_VDDVIB_EXT_XTL2_EN |
		//BIT_LDO_VDDVIB_EXT_XTL3_EN |
		//BIT_LDO_VDDVIB_EXT_XTL4_EN |
		//BIT_LDO_VDDVIB_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN10,
		//BIT_LDO_VDDWCN_EXT_XTL0_EN |
		//BIT_LDO_VDDWCN_EXT_XTL1_EN |
		//BIT_LDO_VDDWCN_EXT_XTL2_EN |
		//BIT_LDO_VDDWCN_EXT_XTL3_EN |
		//BIT_LDO_VDDWCN_EXT_XTL4_EN |
		//BIT_LDO_VDDWCN_EXT_XTL5_EN |
		BIT_LDO_AVDD18_EXT_XTL0_EN |
		//BIT_LDO_AVDD18_EXT_XTL1_EN |
		//BIT_LDO_AVDD18_EXT_XTL2_EN |
		BIT_LDO_AVDD18_EXT_XTL3_EN |
		//BIT_LDO_AVDD18_EXT_XTL4_EN |
		//BIT_LDO_AVDD18_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN11,
		//BIT_LDO_VDDLDO0_EXT_XTL0_EN |
		//BIT_LDO_VDDLDO0_EXT_XTL1_EN |
		//BIT_LDO_VDDLDO0_EXT_XTL2_EN |
		//BIT_LDO_VDDLDO0_EXT_XTL3_EN |
		//BIT_LDO_VDDLDO0_EXT_XTL4_EN |
		//BIT_LDO_VDDLDO0_EXT_XTL5_EN |
		//BIT_LDO_VDDWIFIPA_EXT_XTL0_EN |
		//BIT_LDO_VDDWIFIPA_EXT_XTL1_EN |
		//BIT_LDO_VDDWIFIPA_EXT_XTL2_EN |
		//BIT_LDO_VDDWIFIPA_EXT_XTL3_EN |
		//BIT_LDO_VDDWIFIPA_EXT_XTL4_EN |
		//BIT_LDO_VDDWIFIPA_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_LDO_XTL_EN12,
		//BIT_LDO_VDDLDO2_EXT_XTL0_EN |
		//BIT_LDO_VDDLDO2_EXT_XTL1_EN |
		//BIT_LDO_VDDLDO2_EXT_XTL2_EN |
		//BIT_LDO_VDDLDO2_EXT_XTL3_EN |
		//BIT_LDO_VDDLDO2_EXT_XTL4_EN |
		//BIT_LDO_VDDLDO2_EXT_XTL5_EN |
		//BIT_LDO_VDDLDO1_EXT_XTL0_EN |
		//BIT_LDO_VDDLDO1_EXT_XTL1_EN |
		//BIT_LDO_VDDLDO1_EXT_XTL2_EN |
		//BIT_LDO_VDDLDO1_EXT_XTL3_EN |
		//BIT_LDO_VDDLDO1_EXT_XTL4_EN |
		//BIT_LDO_VDDLDO1_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_DCXO_XTL_EN,
		BIT_TSX_XO_EXT_XTL0_EN |                   //AUDCP TSX XO
		BIT_TSX_XO_EXT_XTL1_EN |                   //HW DETECT TSX XO
		//BIT_TSX_XO_EXT_XTL2_EN |
		BIT_TSX_XO_EXT_XTL3_EN |                   //WCN TSX XO
		//BIT_TSX_XO_EXT_XTL4_EN |
		//BIT_TSX_XO_EXT_XTL5_EN |
		BIT_XO_EXT_XTL0_EN |
		BIT_XO_EXT_XTL1_EN |
		//BIT_XO_EXT_XTL2_EN |
		BIT_XO_EXT_XTL3_EN |
		//BIT_XO_EXT_XTL4_EN |
		//BIT_XO_EXT_XTL5_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_TSX_CTRL1,
		//BIT_DCXO_26M_REF_OUT0_EXT_XTL0_EN |
		//BIT_DCXO_26M_REF_OUT1_EXT_XTL0_EN |
		//BIT_DCXO_26M_REF_OUT2_EXT_XTL0_EN |
		BIT_DCXO_26M_REF_OUT3_EXT_XTL0_EN |
		//BIT_DCXO_26M_REF_OUT4_EXT_XTL0_EN |
		//BIT_DCXO_26M_REF_OUT0_EXT_XTL1_EN |
		//BIT_DCXO_26M_REF_OUT1_EXT_XTL1_EN |
		//BIT_DCXO_26M_REF_OUT2_EXT_XTL1_EN |
		BIT_DCXO_26M_REF_OUT3_EXT_XTL1_EN |
		//BIT_DCXO_26M_REF_OUT4_EXT_XTL1_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_TSX_CTRL2,
		//BIT_DCXO_26M_REF_OUT0_EXT_XTL2_EN |
		//BIT_DCXO_26M_REF_OUT1_EXT_XTL2_EN |
		//BIT_DCXO_26M_REF_OUT2_EXT_XTL2_EN |
		//BIT_DCXO_26M_REF_OUT3_EXT_XTL2_EN |
		//BIT_DCXO_26M_REF_OUT4_EXT_XTL2_EN |
		//BIT_DCXO_26M_REF_OUT0_EXT_XTL3_EN |
		BIT_DCXO_26M_REF_OUT1_EXT_XTL3_EN |
		//BIT_DCXO_26M_REF_OUT2_EXT_XTL3_EN |
		//BIT_DCXO_26M_REF_OUT3_EXT_XTL3_EN |
		//BIT_DCXO_26M_REF_OUT4_EXT_XTL3_EN |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_TSX_CTRL3,
		//BIT_DCXO_26M_REF_OUT0_EXT_XTL4_EN |
		//BIT_DCXO_26M_REF_OUT1_EXT_XTL4_EN |
		//BIT_DCXO_26M_REF_OUT2_EXT_XTL4_EN |
		//BIT_DCXO_26M_REF_OUT3_EXT_XTL4_EN |
		//BIT_DCXO_26M_REF_OUT4_EXT_XTL4_EN |
		//BIT_DCXO_26M_REF_OUT0_EXT_XTL5_EN |
		//BIT_DCXO_26M_REF_OUT1_EXT_XTL5_EN |
		//BIT_DCXO_26M_REF_OUT2_EXT_XTL5_EN |
		//BIT_DCXO_26M_REF_OUT3_EXT_XTL5_EN |
		//BIT_DCXO_26M_REF_OUT4_EXT_XTL5_EN |
		BIT_SLP_DCXO_LP_EN |
		//BIT_DCXO_CORE_AML_CAL_EN |
		BITS_CLK_DCXO_SEL(0x00) |
		0
	);

	//32K lp config
	ANA_REG_OR(ANA_REG_GLB_CLK32KLESS_CTRL0, BIT_SLP_XO_LOW_CUR_EN);

	//Refout config
	ANA_REG_SET(ANA_REG_GLB_TSX_CTRL0,
		//BIT_DCXO_26M_REF_OUT4_PIN_EXT_XTL0_EN |
		//BIT_DCXO_26M_REF_OUT4_PIN_EXT_XTL1_EN |
		//BIT_DCXO_26M_REF_OUT4_PIN_EXT_XTL2_EN |
		//BIT_DCXO_26M_REF_OUT4_PIN_EXT_XTL3_EN |
		//BIT_DCXO_26M_REF_OUT4_PIN_EXT_XTL4_EN |
		//BIT_DCXO_26M_REF_OUT4_PIN_EXT_XTL5_EN |
		//BIT_SLP_DCXO_26M_REF_OUT0_EN |
		//BIT_SLP_DCXO_26M_REF_OUT1_EN |
		BIT_SLP_DCXO_26M_REF_OUT2_EN |
		BIT_SLP_DCXO_26M_REF_OUT3_EN |
		//BIT_SLP_DCXO_26M_REF_OUT4_EN |
		BITS_DCXO_26M_REF_OUT_EN(REFOUT2_ON | REFOUT3_ON) |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_TSX_CTRL14,
		//BIT_DCXO_CORE_BUF_MODE_SEL |
		//BIT_DCXO_26M_REF_BUF2_DIV_MODE_SEL |
		//BIT_DCXO_26M_REF_BUF3_DIV_MODE_SEL |
		//BIT_DCXO_26M_REF_BUF4_DIV_MODE_SEL |
		//BIT_DCXO_LP_CAL_EN |
		BITS_DCXO_26M_REF_BUF_OUTPUT_BYPASS(0x11) |
		BITS_DCXO_26M_REF_BUF0_DRV_LEVEL_CTRL(0x7) |
		BITS_DCXO_26M_REF_BUF1_DRV_LEVEL_CTRL(0x6) |
		0
	);

	ANA_REG_SET(ANA_REG_GLB_TSX_CTRL4,
		BITS_DCXO_26M_REF_BUF2_DRV_LEVEL_CTRL(0x5) |
		BITS_DCXO_26M_REF_BUF3_DRV_LEVEL_CTRL(0x7) |
		BIT_DCXO_32K_DIV_MODE_SEL |
		//BIT_DCXO_32K_CLKIN_26M_INV_CTRL |
		BITS_DCXO_CORE_AML_CTRL(0x8) |
		//BIT_DCXO_CORE_AML_CAL_OK_FLAG |
		BITS_DCXO_26M_REF_BUF4_DRV_LEVEL_CTRL(0x7) |
		0
	);

	//Pin exit slp config
	ANA_REG_SET(ANA_REG_GLB_XTL_WAIT_CTRL0,
		//BIT_EXT_XTL5_FOR_26M_EN |
		//BIT_EXT_XTL4_FOR_26M_EN |
		BIT_EXT_XTL3_FOR_26M_EN |
		BIT_EXT_XTL2_FOR_26M_EN |
		BIT_EXT_XTL1_FOR_26M_EN |
		BIT_EXT_XTL0_FOR_26M_EN |
		BIT_SLP_XTLBUF_PD_EN |
		BIT_XTL_EN |
		BITS_XTL_WAIT(0x32) |
		0
	);

	/*when bring up we power on all dcdc & ldo*/
	DCDC_ldo_power_on();
#endif
}

void sprd_pmu_lowpower_init(void)
{
#ifdef CONFIG_FPGA
	return;
#endif
	pmic_lowpower_config(0x00000000);
	CSP_Init(0x50001800);
}
