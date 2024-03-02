#include <common.h>
#include <chipram_env.h>
#include <asm/io.h>
#include <asm/arch/sprd_reg.h>
#include "adi_hal_internal.h"
#include <asm/arch/common.h>
#include <otp_helper.h>
#include <sprd_pmic_misc.h>
#include <hwfeature.h>
#include <secureboot/sec_efuse_sharkl6pro.h>

#define KLT8	0x6B4C5438
#define KL	0x6B4C0000
#define SHAR	0x53686172
#define E2	0x65320000
#define WHAL	0x5768616C

/* efuse soc_version and bin_version block index */
#define EFUSE_AP_CPU_INDEX      71
#define EFUSE_LIT_BIN_INDEX     73
#define EFUSE_MED_BIN_INDEX     74
#define EFUSE_BIG_BIN_INDEX     75

/* chip version mask */

#define CHIP_BONDING_MASK       0x7F

#define CHIP_CPU_MASK           ((1 << 24) | (1 << 25 ) |(1 << 26))
#define CHIP_AI_GPU_MASK        ((1 << 27) | (1 << 28 ) |(1 << 29))

#define NEW_CHIP_GPU_MASK       ((1 << 8)  | (1 << 9)   |(1 << 10))
#define NEW_CHIP_AI_MASK        ((1 << 11) | (1 << 12 ) |(1 << 13))
/* Bounding     bit     T760    T770    T790(others)
* APCPU
         BIT     0       1       1       0
         BIT     1       1       0       0
         BIT     2       0       0       0

* GPU
         BIT     3       1       1       0
         BIT     4       1       0       0
* AI
         BIT     5       1       1       0
         BIT     6       1       0       0
*/

#define T760_IC_VALUE    ((1 << 0) | (1 << 1) | (1 << 3) | (1 << 4) | (1 << 5)| (1 << 6))
#define T770_IC_VALUE    ((1 << 0) | (1 << 3) | (1 << 5))

static void emmc_dev_powerdown_mphy_core(void);

static unsigned int get_chip_bonding(struct hwfeature *phwf)
{
	typedef enum {
		T760_IC = 0,
		T770_IC,
		T790_IC,
		SIGN_OFF
	};

	phwf = phwf;
	u32  lit_reg = sprd_ap_efuse_read(EFUSE_LIT_BIN_INDEX);
	u32  med_reg = sprd_ap_efuse_read(EFUSE_MED_BIN_INDEX);
	u32  big_reg = sprd_ap_efuse_read(EFUSE_BIG_BIN_INDEX);
	u32  block71 = sprd_ap_efuse_read(EFUSE_AP_CPU_INDEX);

	u32 lit_cpu = lit_reg & CHIP_CPU_MASK;
	u32 med_cpu = med_reg & CHIP_CPU_MASK;
	u32 big_cpu = big_reg & CHIP_CPU_MASK;
	u32 gpu = big_reg  & CHIP_AI_GPU_MASK;
	u32 ai  = lit_reg  & CHIP_AI_GPU_MASK;

	u32 new_gpu = block71 & NEW_CHIP_GPU_MASK;
	u32 new_ai = block71 & NEW_CHIP_AI_MASK;

	if ((lit_cpu && med_cpu && big_cpu && gpu && ai) || (new_gpu && new_ai)) {
		u32  cpu = block71 & CHIP_BONDING_MASK;
		return cpu == T760_IC_VALUE ? T760_IC : cpu == T770_IC_VALUE ? T770_IC : T790_IC;
	} else
		return SIGN_OFF;
}

unsigned int get_soc_bonding(struct hwfeature *phwf)
{
	return get_chip_bonding(phwf);
}

static unsigned int get_chip_id(struct hwfeature *phwf)
{

	int  reg_val;

	typedef enum {
		qogirn6pro_AA = 0,
		qogirn6pro_AB
	};

	phwf = phwf;

	reg_val = __raw_readl(REG_AON_APB_AON_VER_ID);

	if (reg_val)
		return qogirn6pro_AB;
	else
		return qogirn6pro_AA;

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

/* Close PAD_CLK26M_SINOUT_PCIE_1P8 */
void disable_pad_clk26M_sinout_pcie_1P8(void)
{
        u32 temp, val, ana_eb = 0;

        /* Check ANA_EB*/
        if(CHIP_REG_GET(REG_AON_APB_APB_EB1) & BIT_AON_APB_ANA_EB)
                ana_eb = 1;
        else
                CHIP_REG_OR(REG_AON_APB_APB_EB1, BIT_AON_APB_ANA_EB);

        temp = CHIP_REG_GET(REG_ANLG_PHY_G1_ANALOG_BB_TOP_SINE_DRV_CTRL);
        val = temp & ~(BIT_ANLG_PHY_G1_ANALOG_BB_TOP_SINDRV_26M_ENA_PCIE);
        CHIP_REG_SET(REG_ANLG_PHY_G1_ANALOG_BB_TOP_SINE_DRV_CTRL, val);

        if(!ana_eb)
		CHIP_REG_AND(REG_AON_APB_APB_EB1, ~(BIT_AON_APB_ANA_EB));
}

void misc_init()
{
	pmic_misc_init();
	adi_hwchannel_config();
	sprd_get_chipid(NULL, NULL);
	hwfeature_hook_get_efuse(get_chip_bonding);
	hwfeature_hook_get_chipid(get_chip_id);
	bypass_ufs_powergate();
	pub_qos_cfg();
	ap_qos_cfg();
	disable_pad_clk26M_sinout_pcie_1P8();
	emmc_dev_powerdown_mphy_core();
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

void bypass_ufs_powergate(void)
{
	if (get_bootdevice() == BOOT_DEVICE_EMMC)
		CHIP_REG_OR(REG_PMU_APB_UFS_PWR_GATE_BYP_CFG,
					   BIT_PMU_APB_UFS_PWR_GATE_BYP);
}

/*
 * EMMC device deletes UFS probe, and MPHY is in the high power consumption state after power-on.
 * Therefore, MPHY needs to be set to disable state.
 */
static void emmc_dev_powerdown_mphy_core(void)
{
	if (get_bootdevice() == BOOT_DEVICE_EMMC)
		CHIP_REG_OR(SPRD_AON_ANLG_PHY_G12_PHYS, 0x2000);
}
