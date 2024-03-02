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

#define KLT8	0x6B4C5438
#define KL	0x6B4C0000
#define SHAR	0x53686172
#define E2	0x65320000
#define WHAL	0x5768616C

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

unsigned int get_soc_bonding(struct hwfeature *phwf)
{
        return get_chip_bonding(phwf);
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

