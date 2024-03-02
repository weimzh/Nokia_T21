#include <common.h>
#include <malloc.h>
#include "key_map.h"
#include <boot_mode.h>
#include <asm/arch/mfp.h>
#include <asm/arch/common.h>
#include <asm/arch/sprd_eic.h>

#define SPRD_VOLUMEDOWN_GPIO 124

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
extern int fb_check_secboot_enable(void);
#ifdef CONFIG_ERASE_SPL_AUTO_DOWNLOAD
extern int erase_spl_enter_download_mode(void);
#endif
#endif

void board_keypad_init(void)
{
	sprd_gpio_request(NULL, SPRD_VOLUMEDOWN_GPIO);
	sprd_gpio_direction_input(NULL, SPRD_VOLUMEDOWN_GPIO);

	printf("[gpio keys] init!\n");
	return;
}

unsigned char board_key_scan(void)
{
	uint32_t key_code = KEY_RESERVED;
	int gpio_volumeup = -1;
	int gpio_volumedown = -1;


	sprd_eic_request(EIC_KEY2_7S_RST_EXT_RSTN_ACTIVE);
	udelay(3000);
	gpio_volumeup = sprd_eic_get(EIC_KEY2_7S_RST_EXT_RSTN_ACTIVE);
	debugf("gpio_volumeup = %d\n",gpio_volumeup);
	if(gpio_volumeup < 0)
		errorf("[eic keys] volumeup : sprd_eic_get return ERROR!\n");
	if(gpio_volumeup > 0) {
		key_code = KEY_VOLUMEUP;
		debugf("[eic keys] volumeup pressed!\n");
	 }

	gpio_volumedown = sprd_gpio_get(NULL, SPRD_VOLUMEDOWN_GPIO);
		debugf("gpio_volumedown = %d\n",gpio_volumedown);
	if(gpio_volumedown < 0)
		errorf("[eic keys] volumedown : sprd_eic_get return ERROR!\n");
	if(gpio_volumedown == 0) {
		key_code = KEY_VOLUMEDOWN;
		debugf("[eic keys] volumedown pressed!\n");
	}

	if (KEY_RESERVED == key_code)
		debugf("[gpio keys] no key pressed!\n");

	return key_code;
}

unsigned int check_key_boot(unsigned char key)
{
    /* Fixme, an example of the combination of keys for enter download */
    if(KEY_VOLUMEDOWN == key) {
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
		if (fb_check_secboot_enable()) {
#ifdef CONFIG_ERASE_SPL_AUTO_DOWNLOAD
			if (0 != erase_spl_enter_download_mode()) {
				debugf("erase partition splloader and splloader_bak fail!\n");
				debugf("enter old autodloader_mode!\n");
			} else
#endif
			{
				errorf("not support!!!\n");
			}
		}
#endif
    } else if(KEY_HOME == key)
      return CMD_FASTBOOT_MODE;
    else if(KEY_VOLUMEUP== key)
      return CMD_RECOVERY_MODE;
    else
      return 0;
}

