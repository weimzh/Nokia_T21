#ifndef __ARCH_ARM_ASM_SHARKL5_I2C__
#define __ARCH_ARM_ASM_SHARKL5_I2C__

#include <asm/arch/sprd_reg.h>
#include <asm/io.h>
#include <common.h>
#include <i2c.h>

static void sprd_i2c_init(struct i2c_adapter *adap, int speed, int slaveadd);
static int sprd_i2c_read(struct i2c_adapter *adap, uchar chip, uint addr,
			   int alen, uchar *buffer, int len);
static int sprd_i2c_write(struct i2c_adapter *adap, uchar chip, uint addr,
			    int alen, uchar *buffer, int len);

struct sprd_i2c {
	void *apb_base;
	unsigned apb_eb;
	void *base;
};

#define SPRD_I2C_NUM		10

struct sprd_i2c sprd_i2c[SPRD_I2C_NUM] = {
	{
		.apb_base =  (void *)REG_AP_AHB_AHB_EB,
		.apb_eb = BIT_AP_APB_I2C0_EB,
		.base = (void *)SPRD_I2C0_PHYS,
	}, {
		.apb_base =  (void *)REG_AP_AHB_AHB_EB,
		.apb_eb = BIT_AP_APB_I2C1_EB,
		.base = (void *)SPRD_I2C1_PHYS,
	}, {
		.apb_base =  (void *)REG_AP_AHB_AHB_EB,
		.apb_eb = BIT_AP_APB_I2C2_EB,
		.base = (void *)SPRD_I2C2_PHYS,
	}, {
		.apb_base =  (void *)REG_AP_AHB_AHB_EB,
		.apb_eb = BIT_AP_APB_I2C3_EB,
		.base = (void *)SPRD_I2C3_PHYS,
	}, {
		.apb_base =  (void *)REG_AP_AHB_AHB_EB,
		.apb_eb = BIT_AP_APB_I2C4_EB,
		.base = (void *)SPRD_I2C4_PHYS,
	} , {
		.apb_base =  (void *)REG_AP_AHB_AHB_EB,
		.apb_eb = BIT_AP_APB_I2C5_EB,
		.base = (void *)SPRD_I2C5_PHYS,
	} , {
		.apb_base =  (void *)REG_AP_AHB_AHB_EB,
		.apb_eb = BIT_AP_APB_I2C6_EB,
		.base = (void *)SPRD_I2C6_PHYS,
	} , {
		.apb_base =  (void *)REG_AP_AHB_AHB_EB,
		.apb_eb = BIT_AP_APB_I2C7_EB,
		.base = (void *)SPRD_I2C7_PHYS,
	} , {
		.apb_base =  (void *)REG_AP_AHB_AHB_EB,
		.apb_eb = BIT_AP_APB_I2C8_EB,
		.base = (void *)SPRD_I2C8_PHYS,
	} , {
		.apb_base =  (void *)REG_AP_AHB_AHB_EB,
		.apb_eb = BIT_AP_APB_I2C9_EB,
		.base = (void *)SPRD_I2C9_PHYS,
	} ,
};

#define SPRD_BOARD_REGISTER(n, speed) \
	U_BOOT_I2C_ADAP_COMPLETE(sprd_r8p0_i2c##n, \
		sprd_i2c_init, NULL, \
		sprd_i2c_read, sprd_i2c_write, NULL, 	\
		(speed), 0, I2C_##n)

SPRD_BOARD_REGISTER(0, 100000)
SPRD_BOARD_REGISTER(1, 100000)
SPRD_BOARD_REGISTER(2, 100000)
SPRD_BOARD_REGISTER(3, 100000)
SPRD_BOARD_REGISTER(4, 100000)
SPRD_BOARD_REGISTER(5, 100000)
SPRD_BOARD_REGISTER(6, 100000)
SPRD_BOARD_REGISTER(7, 100000)
SPRD_BOARD_REGISTER(8, 100000)
SPRD_BOARD_REGISTER(9, 100000)

#endif /*__ARCH_ARM_ASM_QOGIRN6Pro_I2C__*/
