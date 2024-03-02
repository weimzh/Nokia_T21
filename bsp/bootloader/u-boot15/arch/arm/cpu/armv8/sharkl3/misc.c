#include <common.h>
#include <asm/io.h>
#include <asm/arch/sprd_reg.h>
#include "adi_hal_internal.h"
#include <asm/arch/common.h>
#include <otp_helper.h>
#include <sprd_pmic_misc.h>
#include <asm/arch-sharkl3/pinmap.h>
#include "notifier.h"
#include "sprd_reset.h"
#include <hwfeature.h>

#define	Shar	0x53686172
#define	kL3	0x6b4c3300

static struct notifier_block notify_arch_off;

static unsigned int get_chip_bonding(struct hwfeature *phwf)
{
        typedef enum {
                SHARKL3R = 0,
                SHARKL3
        };

        phwf = phwf;

        if (__raw_readl(REG_AON_APB_AON_MFT_ID) == 0x00000a00)
                return SHARKL3R;
        else
                return SHARKL3;
}

void rf_sen_gpio_init()
{
	sprd_gpio_request(NULL, 1);
	sprd_gpio_direction_output(NULL,1,0);
	sprd_gpio_request(NULL, 2);
	sprd_gpio_direction_output(NULL,2,0);
	sprd_gpio_request(NULL,3);
	sprd_gpio_direction_output(NULL,3,0);
	sprd_gpio_request(NULL,12);
	sprd_gpio_direction_output(NULL,12,0);
	sprd_gpio_request(NULL,13);
	sprd_gpio_direction_output(NULL,13,0);
	sprd_gpio_request(NULL,14);
	sprd_gpio_direction_output(NULL,14,0);
}

static int sharkl3_poweroff(struct notifier_block *nb, unsigned long action, void *data)
{
	if (action != NOTIFY_RESET_ACTION_POWEROFF)
		return 0;

	__raw_writel(0x30, CTL_PIN_BASE + REG_PIN_RFSDA1);
	__raw_writel(0x30, CTL_PIN_BASE + REG_PIN_RFSCK1);
	__raw_writel(0x30, CTL_PIN_BASE + REG_PIN_RFSEN1);
	__raw_writel(0x30, CTL_PIN_BASE + REG_PIN_RFSDA0);
	__raw_writel(0x30, CTL_PIN_BASE + REG_PIN_RFSCK0);
	__raw_writel(0x30, CTL_PIN_BASE + REG_PIN_RFSEN0);

	return 0;
}

int sprd_get_chipid(int *chip_id, int *version_id)
{
	int chip_id0 = 0, chip_id1 = 0;
	int ver_id;

	chip_id0 = __raw_readl((void *)REG_AON_APB_AON_CHIP_ID0);
	chip_id1 = __raw_readl((void *)REG_AON_APB_AON_CHIP_ID1);

	if ((chip_id1 == Shar) && (chip_id0 == kL3)) {
		chip_id1 = 0x73703938;
		chip_id0 = 0x36336100;
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

unsigned int get_soc_bonding(struct hwfeature *phwf)
{
        return get_chip_bonding(phwf);
}

static unsigned int get_chip_id(struct hwfeature *phwf)
{
	int reg_val;

	phwf = phwf;
	reg_val = __raw_readl(REG_AON_APB_AON_VER_ID);

	return reg_val;
}

void sprd_get_manufacturel_id(void)
{
	int mft_id = 0;
	mft_id = CHIP_REG_GET(REG_AON_APB_AON_MFT_ID);
	debugf("manufacturel_id is : 0x%x \n", mft_id);
}

void misc_init()
{
	pmic_misc_init();
	sprd_get_chipid(NULL, NULL);
	sprd_get_manufacturel_id();
	rf_sen_gpio_init();

	notify_arch_off.name = "sharkl3_poweroff";
	notify_arch_off.notifier_call = sharkl3_poweroff;
	notify_arch_off.priority = NOTIFY_RESET_POWEROFF_PRIORITY_ARCH_OFF;
	notifier_reset_register(&notify_arch_off, NOTIFY_RESET_TYPE_POWEROFF);

	hwfeature_hook_get_efuse(get_chip_bonding);
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

