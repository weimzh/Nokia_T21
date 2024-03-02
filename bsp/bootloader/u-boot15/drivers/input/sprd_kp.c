#include <boot_mode.h>
#include <sprd_kp.h>

#define KEY_PRESSED		0
#define KEY_NOT_PRESSED		1

#if !defined(CONFIG_FPGA)
void sprd_kp_init(struct key_info *keys)
{
	if (!keys) {
		errorf("[KEY] no key defined!\n");
		return;
	}

	while (keys->keycode != KEY_RESERVED) {
		if (keys->type == TYPE_GPIO) {
			sprd_gpio_request(NULL, keys->offset);
			/* a GPIO pin for key is always used as INPUT pin */
			sprd_gpio_direction_input(NULL, keys->offset);
		}
		keys++;
	}

	printf("[KEY] init!\n");
}
unsigned char sprd_kp_scan(struct key_info *keys)
{
	int val = 0;

	while (keys->keycode != KEY_RESERVED) {
		if (keys->type == TYPE_GPIO) {
			val = sprd_gpio_get(NULL, keys->offset);
		} else if (keys->type == TYPE_EIC) {
			sprd_eic_request(keys->offset);
			udelay(3000);
			val = sprd_eic_get(keys->offset);
		}
		debugf("[KEY] keycode=%u, value=%d\n",
			keys->keycode, val);
		if (val < 0) {
			errorf("[KEY] fail to get value for %s!\n",
				keys->tag);
			continue;
		}
		if (!!val == keys->active)
			break;
		keys++;
	}

	if (keys->keycode == KEY_RESERVED) {
		printf("[KEY] no key pressed!\n");
	} else {
		printf("[KEY] %s pressed!\n", keys->tag);
	}

	return keys->keycode;
}
#endif
unsigned int sprd_kp_checkmode(unsigned char key)
{
	/*if (KEY_VOLUMEUP == key)
		return CMD_FACTORYTEST_MODE;*/
/* no HOME key anymore
	else if(KEY_HOME == key)
		return CMD_FASTBOOT_MODE;
 */
	if (KEY_VOLUMEDOWN== key)
		return CMD_RECOVERY_MODE;
	else
		return CMD_UNDEFINED_MODE;
}

int power_button_pressed(void)
{
	int eic_value,ret;
//maybe get button status from eic API is batter
	sprd_eic_request(EIC_PBINT);
	udelay(3000);
	eic_value = sprd_eic_get(EIC_PBINT);
	debugf("power_button_pressed status %x\n", eic_value);

#ifdef CONFIG_POWERKEY_DEFAULT_HIGH
	if (eic_value == 0)
		ret = KEY_PRESSED;
	else
		ret = KEY_NOT_PRESSED;
#else
	if (eic_value == 0)
		ret = KEY_NOT_PRESSED;
	else
		ret = KEY_PRESSED;
#endif

	return ret;
}
