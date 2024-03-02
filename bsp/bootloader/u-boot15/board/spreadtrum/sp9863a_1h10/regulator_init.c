#include <asm/arch/common.h>
#include <asm/arch/sprd_reg.h>
#include <adi_hal_internal.h>
#include <asm/io.h>
#include <secureboot/sec_efuse_sharkl3.h>

#define DCDC_CORE_SS	950		//SS bin vol set
#define EFUSE_BLOCK_SS	38		//SS bin EFUSE BLOCK
#define BIT_GPU_BIN	0x0f000000	//SS bin bit shift
#define L3R_VERSION	0x00000a00	//L3R version

static int power_on_voltage_init(void)
{
	unsigned long MFT_ID_READ;
	MFT_ID_READ = __raw_readl(REG_AON_APB_AON_MFT_ID);
	printf("version read val is :%d\n",MFT_ID_READ);

	regulator_set_voltage("vddsim2",2800);

	if (MFT_ID_READ == L3R_VERSION) { //L3R version
		u32 block, val;
		block = sprd_ap_efuse_read(EFUSE_BLOCK_SS);
		val = ((block & BIT_GPU_BIN) >> 24);
		if (val == 0x02)
			regulator_set_voltage("vddcore",DCDC_CORE_SS);//GPU SS BIN
	}

	return 0;
}

int regulator_init(void)
{
	power_on_voltage_init();
	return 0;
}
