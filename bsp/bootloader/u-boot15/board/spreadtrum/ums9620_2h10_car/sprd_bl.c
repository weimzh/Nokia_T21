#include <pwm.h>

void set_backlight(unsigned int brightness)
{
	pwm_config(0, brightness, 255);

	return;
}
