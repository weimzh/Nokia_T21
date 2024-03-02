#ifndef __PINCTRL_SPRD_H__
#define __PINCTRL_SPRD_H__

struct pin_info {
	int num;
	u32 offset;
	const char *name;
};

struct pinctrl_info {
	int num;
	u32 val;
	int type;
	const char *pins;
	/*for globle register*/
	int inf_mask;
	int inf_shift;
	int inf_val;
	/*for misc register*/
	int atv_pd;
	int in_out;
	int slp_pd;
	int driver;
	int sl_mode;
};

#define BIT(x) (1 << (x))
#define ARRAY_SIZE(x)		(sizeof(x) / sizeof((x)[0]))

#define ACTIVE_MASK		0x43
#define ACTIVE_SHIFT		6

#define SLEEP_MASK		0x3
#define SLEEP_SHIFT 		2

#define IN_OUT_MASK		0x3
#define IN_OUT_SHIFT 		0

#define SL_MODE_MASK		0x3f
#define SL_MODE_SHIFT 		13

#define DRIVER_MASK		0xF
#define DRIVER_SHIFT 		19

int sprd_pinctrl_core_probe(struct pin_info *pinctr_info,int pins_num,u32 base_addr);

#endif

