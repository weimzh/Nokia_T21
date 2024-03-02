#include <common.h>
#include <sprd_adc.h>
#include "otp_helper.h"
#include "adi_hal_internal.h"
#include <asm/arch/sprd_reg.h>

#define M26_DCXO_32KLESS 0x8018
#define M26_TCXO_32K 0x8
#define M26_TSX_32KLESS 0x8010
#define M52_TCXO_32K 0xc
#define NO_USE_32KLESS 0x10

#define M52_DCXO_CRYSTAL_STYLE 0x0
#define M52_TSX_CRYSTAL_STYLE 0x2000
#define M52_TCXO_CRYSTAL_STYLE 0x4000
#define NO_USE_CRYSTAL_STYLE 0x6000
#define DCXO_CRYSTAL_FLAG 0x6000

#define K_STYLE 0x0
#define KLESS_STYLE 0x40
#define CLK32KSEL_FLAG 0x40

#define option3_check  BIT(2)
#define option4_check  BIT(3)
#define option5_check  BIT(15)
#define option6_check  BIT(4)

typedef enum k_less {
	K32 = 0,
	K_LESS,
}k_less_t;

typedef enum crystal_type {
	VCTCXO = 0,
	DCXO,
	TSX,
	TCXO,
	M26_TCXO,
	M52_TCXO,
	M26_TSX,
	M52_TSX,
	M26_DCXO,
	M52_DCXO,
	NO_USE
}crystal_type_t;

struct clock_table {
	k_less_t k32_less_data;
	crystal_type_t crystal_data;
};

#if defined(CONFIG_ADIE_UMP9622)

static const struct clock_table clock_table[] = {
	{K32, M52_DCXO},
	{K_LESS, M52_TSX},
	{K_LESS, M52_TCXO},
	{K_LESS, NO_USE}
};

static int get_clockid(void)
{
	int reg_val = 0;

	reg_val = ANA_REG_GET(REG_ANA_UMP9622_TSX_CTRL15);

	return reg_val;
}

static int get_32ksel_id(void)
{
	int reg_val = 0;

	reg_val = ANA_REG_GET(ANA_REG_GLB_CLK32KSEL_CTRL0);

	return reg_val;
}

static int get_id(void)
{
	int id = -1;
	int value = get_clockid();
	value &= DCXO_CRYSTAL_FLAG;

	if(value == M52_DCXO_CRYSTAL_STYLE)
		id = 0;
	else if(value == M52_TSX_CRYSTAL_STYLE)
		id = 1;
	else if(value == M52_TCXO_CRYSTAL_STYLE)
		id = 2;
	else if(value == NO_USE_CRYSTAL_STYLE)
		id = 3;

	return id;

}

static int get_32k_id(void)
{
	int id = -1;
	int value = get_32ksel_id();

	value &= CLK32KSEL_FLAG;

	if(value == K_STYLE)
		id = 0;
	else if(value == KLESS_STYLE)
		id = 1;

	return id;
}

#else

static const struct clock_table clock_table[] = {
	{K32, M26_TCXO},
	{K_LESS, M26_TSX},
	{K_LESS, M26_DCXO},
	{K32, M52_TCXO},
	{K_LESS, NO_USE}
};

static int get_clockid(void)
{
	int reg_val = 0;

	reg_val = ANA_REG_GET(ANA_REG_GLB_CLK32KLESS_CTRL0);

	return reg_val;
}

static int clk_crystal_data(void)
{
	int clk_crystal = 0;
	int option3, option4, option5, option6;
	int data = get_clockid();

	option3 = data & option3_check;
	option4 = data & option4_check;
	option5 = data & option5_check;
	option6 = data & option6_check;

	clk_crystal = option3 + option4 + option5 + option6;

	return clk_crystal;
}

static int get_id(void)
{

	int id;
	int value = clk_crystal_data();

	if(value != M26_TCXO_32K && value != M26_TSX_32KLESS && \
	   value != M26_DCXO_32KLESS && value != M52_TCXO_32K && \
	   value != NO_USE_32KLESS){
		errorf("option value is error\n");
		return -1;
	}

	if(value == M26_TCXO_32K)
		id = 0;
	else if(value == M26_TSX_32KLESS)
		id = 1;
	else if(value == M26_DCXO_32KLESS)
		id = 2;
	else if(value == M52_TCXO_32K)
		id = 3;
	else if(value == NO_USE_32KLESS)
		id = 4;

	return id;

}

#endif

/* Return crystal type */
int sprd_get_crystal(void)
{
	int value = get_id();

	if (value < 0){
		errorf("get err id\n");
		return -1;
	}

	return clock_table[value].crystal_data;
}

/* Return 32k less or not */
int sprd_get_32k(void)
{
/* sw auto-adaption */
#if defined(CONFIG_ADIE_UMP9622)
	int value = get_32k_id();
#else
	int value = get_id();
#endif
	if (value >= 0) {
		return clock_table[value].k32_less_data;
	} else {
		errorf("Failed to get_id for value.\n");
		return -1;
	}
}

/* Return board id */
int sprd_get_boardid(void)
{
	#ifdef CONFIG_SOC_ORCA
		return sprd_get_versionid();
	#endif

	return get_clockid();
}
