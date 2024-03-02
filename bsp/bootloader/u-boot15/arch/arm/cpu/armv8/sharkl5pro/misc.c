#include <common.h>
#include <asm/io.h>
#include <asm/arch/sprd_reg.h>
#include "adi_hal_internal.h"
#include <asm/arch/common.h>
#include <otp_helper.h>
#include <sprd_pmic_misc.h>
#include <hwfeature.h>

#define	Shar	0x53686172
#define	kL5P	0x6b4c3550

#define BIT_AP_SHIFT_7	 7
#define BIT_AP_SHIFT_16  16
#define BIT_AP_SHIFT_18  18
#define BIT_AP_SHIFT_20  20
#define BIT_AP_SHIFT_21  21

#define BIT_DEFAULT (~0U)

static unsigned int get_chip_bonding(struct hwfeature *phwf)
{

	unsigned int default_code = BIT_DEFAULT;
	typedef enum {
		T618_IC = 0,
		T610_IC,
		T700_IC
	};

	phwf = phwf;

	if ((!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_7))) &&
		(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_16)) &&
			(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_18)) &&
				(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_20)) &&
					(!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_21))))
		return T610_IC;
	else if ((!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_16))) &&
			(!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_18))) &&
				(!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_20))) &&
					(!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_21))))
		return T618_IC;
	else if ((__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_16)) &&
			(!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_18))) &&
				(!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_20))) &&
					(!(__raw_readl(REG_AON_APB_BOND_OPT0) & (1 << BIT_AP_SHIFT_21))))
		return T700_IC;
	else
		return BIT_DEFAULT;
}

unsigned int get_soc_bonding(struct hwfeature *phwf)
{
	return get_chip_bonding(phwf);
}

static unsigned int get_chip_id(struct hwfeature *phwf)
{

	int  reg_val;

	phwf = phwf;

	reg_val = __raw_readl(REG_AON_APB_AON_VER_ID);

        return reg_val;
}



int sprd_get_chipid(int *chip_id, int *version_id)
{
	int chip_id0 = 0, chip_id1 = 0;
	int ver_id;

	chip_id0 = __raw_readl((void *)REG_AON_APB_AON_CHIP_ID0);
	chip_id1 = __raw_readl((void *)REG_AON_APB_AON_CHIP_ID1);

	if ((chip_id1 == Shar) && (chip_id0 == kL5P)) {
		chip_id1 = 0x756d7335;
		chip_id0 = 0x31320000;
	}
	else {
		chip_id1 = 0;
		chip_id0 = 0;
	}

	ver_id = __raw_readl((void *)REG_AON_APB_AON_VER_ID);

	if (!chip_id || !version_id) {
		debugf("chip id = 0x%x%x, VID = 0x%x\n",chip_id1, chip_id0, ver_id);
		return 0;
	}


	*chip_id = chip_id1;
	*(chip_id + 1) = chip_id0;
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


