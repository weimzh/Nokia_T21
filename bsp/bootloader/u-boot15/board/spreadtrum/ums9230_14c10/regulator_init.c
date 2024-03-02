#include <asm/arch/common.h>
#include <asm/arch/sprd_reg.h>
#include <adi_hal_internal.h>

static int power_on_voltage_init(void)
{
	regulator_set_voltage("vddsram", 850);
	regulator_set_voltage("vddrf1v25",1250);
	return 0;
}

int regulator_init(void)
{
	power_on_voltage_init();
	return 0;
}
