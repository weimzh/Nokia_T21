#include <common.h>
#include <malloc.h>
#include "key_map.h"
#include <boot_mode.h>
#include <asm/arch/mfp.h>
#include <asm/arch/common.h>
#include <asm/arch/sprd_eic.h>

#define SPRD_VOLUMEDOWN_GPIO 124

int lcd_low_bat;
extern int low_bat;
void board_keypad_init(void)
{

	sprd_gpio_request(NULL, SPRD_VOLUMEDOWN_GPIO);
	sprd_gpio_direction_input(NULL, SPRD_VOLUMEDOWN_GPIO);
/*
	sprd_gpio_request(NULL, 125);
	sprd_gpio_direction_input(NULL, 125);
*/
	printf("[gpio keys] init skip!\n");
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
	/*if (KEY_VOLUMEUP == key)
		return CMD_FACTORYTEST_MODE;*/
	if (KEY_VOLUMEDOWN == key) {
	    if(1 == low_bat)
	    {
		lcd_low_bat = 1;
		return 0;	
	    }  
	    return CMD_FASTBOOT_MODE;
    } 
    else {
      debugf("check_key_boot not key (%d)\n", key);
      return 0;
    }
}

