#ifndef __ARCH_ARM_ASM_HW_I2C__
#define __ARCH_ARM_ASM_HW_I2C__

#include <asm/arch/sprd_reg.h>

/* Enable the DCDC chip  */
#define CINFIG_HW_I2C_FOR_DCDC_EN

#define USED_CHANNEL_NUM	2

struct hw_i2c_channel {
	unsigned channel_num;
	unsigned addr;
	unsigned pril;
};

struct sprd_hw_i2c {
	void *apb_base;
	unsigned apb_eb;
	void *base;
	int num;
	struct hw_i2c_channel channel[USED_CHANNEL_NUM];
};

#define DVFS_ADDR(DA, RA)		(((DA) << 8 | (RA)) << 4)
#define SPRD_I2C_NUM		1

#define	DVFS_TX_0_ADDR		DVFS_ADDR(CONFIG_DVFS_ADDR, CINFIG_DVFS_TX_0_REG_ADDR)
#define	DVFS_TX_1_ADDR		DVFS_ADDR(CONFIG_DVFS_ADDR, CINFIG_DVFS_TX_1_REG_ADDR)
#define	DVFS_TX_0_CHNL		5
#define	DVFS_TX_1_CHNL		7
#define	DVFS_TX_0_PRIL		0x0
#define	DVFS_TX_1_PRIL		0x0

struct sprd_hw_i2c sprd_hw_i2c[SPRD_I2C_NUM] = {
	{
		.apb_base = (void *)REG_AON_APB_APB_EB2,
		.apb_eb = BIT_AON_APB_I2C_EB,
		.base = (void *)SPRD_AON_I2C_HW_BASE,
		.num = USED_CHANNEL_NUM,
		.channel[0] = {
			.channel_num = DVFS_TX_0_CHNL,
			.addr = DVFS_TX_0_ADDR,
			.pril = DVFS_TX_0_PRIL
		},
		.channel[1] = {
			.channel_num = DVFS_TX_1_CHNL,
			.addr = DVFS_TX_1_ADDR,
			.pril = DVFS_TX_1_PRIL
		},
	},
};

#endif /*__ARCH_ARM_ASM_HW_I2C__*/
