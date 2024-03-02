#include <common.h>
#include <chipram_env.h>
#include <asm/io.h>
#include <asm/arch/sprd_reg.h>
#include "adi_hal_internal.h"
#include <asm/arch/common.h>
#include <otp_helper.h>
#include <sprd_pmic_misc.h>
#include <hwfeature.h>

#define KLT8	0x6B4C5438
#define KL	0x6B4C0000
#define SHAR	0x53686172
#define E2	0x65320000
#define WHAL	0x5768616C

#define BIT_AP_SHIFT_7	 7
#define BIT_AP_SHIFT_16  16
#define BIT_AP_SHIFT_21  21

#define BIT_GPU_SHIFT_18 18
#define BIT_GPU_SHIFT_20 20
#define BIT_DEFAULT      (~0U)

static unsigned int get_chip_bonding(struct hwfeature *phwf)
{
	unsigned int default_code = BIT_DEFAULT;
	typedef enum {
		T616_IC = 0,
		T606_IC,
		T612_IC
	};

	phwf = phwf;

/* Bounding bit	T606	T616	T612	T616(efuse 未烧写)
	 * APCPU
		BIT	7	1		0		1		0
		BIT	21	1		1		0		0
		BIT	16	1		1		1		0

	 * GPU
		BIT	20	1		1		1		0
		BIT	18	1		0		1		0
	 */
	if ((__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_7)) &&
	     (__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_16)) &&
               (__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_21)) &&
	         (__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_GPU_SHIFT_18)) &&
		   (__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_GPU_SHIFT_20)))
		return T606_IC;
	else if ((!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_7))) &&
			(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_16)) &&
				(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_21)) &&
					(!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_GPU_SHIFT_18))) &&
						(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_GPU_SHIFT_20)))
		return T616_IC;
	else if ((__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_7)) &&
			(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_16)) &&
				(!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_21))) &&
					(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_GPU_SHIFT_18)) &&
						(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_GPU_SHIFT_20)))
		return T612_IC;
	else
		return default_code;
}

unsigned int get_soc_bonding(struct hwfeature *phwf)
{
	return get_chip_bonding(phwf);
}

static unsigned int get_chip_id(struct hwfeature *phwf)
{

	int  reg_val;

	typedef enum {
		Sharkl6_AA = 0,
		Sharkl6_AB
	};

	phwf = phwf;

	reg_val = __raw_readl(REG_AON_APB_AON_VER_ID);

	if (reg_val)
		return Sharkl6_AB;
	else
		return Sharkl6_AA;

}

int sprd_get_chipid(int *chip_id, int *version_id)
{

	unsigned int chip_id0 = 0, chip_id1 = 0;
	int ch_id;
	int ver_id;

	chip_id0 = __raw_readl((void *)REG_AON_APB_AON_CHIP_ID0);
	chip_id1 = __raw_readl((void *)REG_AON_APB_AON_CHIP_ID1);

	switch (chip_id1) {
	case SHAR:
		switch (chip_id0) {
		case KL:
			ch_id = 0x9830;
			break;
		case KLT8:
			ch_id = 0x9838;
			break;
		default:
			ch_id = 0;
			break;
		}
		break;

	case WHAL:
		switch (chip_id0) {
		case E2:
			ch_id = 0x9850;
			break;
		default:
			ch_id = 0;
			break;
		}
		break;

	default:
		ch_id = 0;
		break;
	}

	ver_id = __raw_readl((void *)REG_AON_APB_AON_VER_ID);

	if (!chip_id || !version_id) {
		debugf("chip id = 0x%x, VID = 0x%x\n",ch_id, ver_id);
		return 0;
	}

	*chip_id = ch_id;
	*version_id = ver_id;

	return 0;
}

void adi_hwchannel_config(void)
{
	adi_hwchannel_set(DCDC_CORE_VAL_ADI_CHN, DCDC_CORE_VAL_ADDR);
}

void misc_init()
{
	pmic_misc_init();
	adi_hwchannel_config();
	sprd_get_chipid(NULL, NULL);
	hwfeature_hook_get_efuse(get_chip_bonding);
	hwfeature_hook_get_chipid(get_chip_id);
}

typedef struct mem_cs_info
{
	uint32_t cs_number;
	uint32_t cs0_size;//bytes
	uint32_t cs1_size;//bytes
}mem_cs_info_t;
PUBLIC int get_dram_cs_number(void)
{
	mem_cs_info_t *cs_info_ptr = 0x1C00;
	return cs_info_ptr->cs_number;
}
PUBLIC int get_dram_cs0_size(void)
{
	mem_cs_info_t *cs_info_ptr = 0x1C00;
	return cs_info_ptr->cs0_size;
}

boot_device_t get_bootdevice(void)
{
	unsigned int boot_val = 0;

	boot_val = (* (volatile unsigned int *) (REG_AON_APB_BOOT_MODE)) & 0x3;
	if (boot_val == 0x3)
		return BOOT_DEVICE_EMMC;
	else
		return BOOT_DEVICE_UFS;
}

