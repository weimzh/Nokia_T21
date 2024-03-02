/*
 *  sgm41511_chg.c - ETA Solutions sgm41511 charger ic driver
 *
 *  Copyright (C) 2019 Unisoc Communications Inc.
 *  History:
 *      2020-07-08 Jinfeng.Lin1@unisoc.com
 *      Add sgm41511 charger ic driver
 */

#include "sprd_chg_helper.h"
#include "sgm41511_reg.h"
#include <dm.h>
#include <errno.h>
#include <common.h>
#include <fdtdec.h>
#include <asm/io.h>
#include <i2c.h>
#include <clk.h>
#include <chipram_env.h>


#if defined(CHARGE_EN_USE_GPIO)
#define ENABLE_CHARGE 0
#define DISENABLE_CHARGE 1
#endif


#define I2C_SPEED		(100000)
#define SLAVE_ADDR		(0x6b)
#define SGM41511_RESET (0x01 << 7)

static unsigned char sgm41511_get_vendor_id(void);


#ifdef CONFIG_DM_SGM41511
struct sprd_sgm41511_dm_data {
	int i2c_num;
};

static struct sprd_sgm41511_dm_data dm_data = {
	.i2c_num = -1,
};

struct udevice *charger;

static int sprd_dm_sgm41511_i2c_init(void)
{
	int ret;
	u8 value;

	if (dm_data.i2c_num != -1) {
		ret = i2c_get_chip_for_busnum(dm_data.i2c_num,
					      SLAVE_ADDR, 1,
					      &charger);
		if (ret) {
			pr_err("%s: i2c%d failed to get\n",
			       __func__, dm_data.i2c_num);
			return ret;
		}
	} else {
		pr_err("%s:failed to set i2c bus num\n", __func__);
		return -EINVAL;
	}

	ret = dm_i2c_set_bus_speed(dev_get_parent(charger), I2C_SPEED);
	if (ret) {
		pr_err("%s: failed to set i2c%d speed\n",
		       __func__, dm_data.i2c_num);
		return ret;
	}
	return 0;
}

static int sgm41511_write_reg(int reg, u8 val)
{
	dm_i2c_reg_write(charger, reg, val);
	return 0;
}

static int sgm41511_read_reg(int reg, u8 *value)
{
	u8 val;
	int ret;

	ret = dm_i2c_reg_read(charger, reg);
	if (ret < 0) {
		pr_err("%s: reg(0x%x), ret(%d)\n", __func__, reg, ret);
		return ret;
	}

	*value = (u8)ret;
	debugf("######sgm41511 readreg reg = %d value = %d/%x\n", reg, ret, ret);
	return 0;
}
#else
static uint16_t sprd_sgm41511_i2c_init(void)
{
	i2c_set_bus_num(CONFIG_SPRDCHG_I2C_BUS);
	i2c_init(I2C_SPEED, SLAVE_ADDR);
	return 0;
}

static int sgm41511_write_reg(int reg, u8 val)
{
	i2c_reg_write(SLAVE_ADDR,reg,val);
	return 0;
}

static int sgm41511_read_reg(int reg, u8 *value)
{
	int ret;
	ret = i2c_reg_read(SLAVE_ADDR , reg);
	if (ret < 0) {
		printf("%s reg(0x%x), ret(%d)\n", __func__, reg, ret);
		return ret;
	}

	ret &= 0xff;
	*value = ret;
	printf("######sgm41511 readreg reg  = %d value =%d/%x\n",reg, ret, ret);
	return 0;
}

#endif

static void sgm41511_set_value(BYTE reg, BYTE reg_bit,BYTE reg_shift, BYTE val)
{
	BYTE tmp;
	sgm41511_read_reg(reg, &tmp);
	tmp = tmp & (~reg_bit) |(val << reg_shift);
	if ((0x04 == reg) && (SGM41511_RESET != reg_bit)) {
		tmp &= 0x7f;
	}
	sgm41511_write_reg(reg,tmp);
}


static void sgm41511_reset_chip(void)
{
    sgm41511_set_value(SGM4151X_REG_0B, REG0B_REG_RESET_MASK << REG0B_REG_RESET_SHIFT, REG0B_REG_RESET_SHIFT, REG0B_REG_RESET);
}




static BYTE sgm41511_get_value(BYTE reg, BYTE reg_bit, BYTE reg_shift)
{
	BYTE data = 0;
	BYTE ret = 0 ;
	ret = sgm41511_read_reg(reg, &data);
	ret = (data & reg_bit) >> reg_shift;

	return ret;
}

static void sprdchg_sgm41511_start_chg(int type)
{
    BYTE tmp;
	printf("start charge\n");
#if defined(CHARGE_EN_USE_GPIO)
	sprd_gpio_request(NULL,CHARGE_EN_GPIO);
	sprd_gpio_direction_output(NULL,CHARGE_EN_GPIO, ENABLE_CHARGE);
#else
	sprd_charge_pd_control(true);
#endif
    sgm41511_set_value(SGM4151X_REG_01, REG01_CHG_CONFIG_MASK << REG01_CHG_CONFIG_SHIFT, REG01_CHG_CONFIG_SHIFT, REG01_CHG_ENABLE);
    sgm41511_read_reg(0x00, &tmp);
    sgm41511_read_reg(0x01, &tmp);
    sgm41511_read_reg(0x02, &tmp);
    sgm41511_read_reg(0x03, &tmp);
    sgm41511_read_reg(0x04, &tmp);
    sgm41511_read_reg(0x05, &tmp);
    sgm41511_read_reg(0x06, &tmp);
    sgm41511_read_reg(0x07, &tmp);
    sgm41511_read_reg(0x08, &tmp);
    sgm41511_read_reg(0x09, &tmp);
    sgm41511_read_reg(0x0a, &tmp);
    sgm41511_read_reg(0x0b, &tmp);

}
static void sprdchg_sgm41511_stop_charging(int value)
{
	printf("stop charge\n");
#if defined(CHARGE_EN_USE_GPIO)
	sprd_gpio_request(NULL,CHARGE_EN_GPIO);
	sprd_gpio_direction_output(NULL,CHARGE_EN_GPIO, DISENABLE_CHARGE);
#else
	sprd_charge_pd_control(false);
#endif

    sgm41511_set_value(SGM4151X_REG_01, REG01_CHG_CONFIG_MASK << REG01_CHG_CONFIG_SHIFT, REG01_CHG_CONFIG_SHIFT, REG01_CHG_DISABLE);
}

static void sprdchg_sgm41511_ic_init(void)
{
#ifdef CONFIG_DM_SGM41511
    sprd_dm_sgm41511_i2c_init();
#else
    sprd_sgm41511_i2c_init();
#endif
    sgm41511_reset_chip();
    int reg_val; 
    //REG06 VINDPM 4.5
    reg_val = (4500 - REG06_VINDPM_BASE) / REG06_VINDPM_LSB;
    sgm41511_set_value(SGM4151X_REG_06, REG06_VINDPM_MASK << REG06_VINDPM_SHIFT, REG06_VINDPM_SHIFT,reg_val);

    //REG00 limit current  2A
    reg_val = (2000 - REG00_IINLIM_BASE) / REG00_IINLIM_LSB;
    sgm41511_set_value(SGM4151X_REG_00, REG00_IINLIM_MASK << REG00_IINLIM_SHIFT, REG00_IINLIM_SHIFT,reg_val);

    //VLOW  = 3.4v 
    sgm41511_set_value(SGM4151X_REG_01, REG01_SYS_MINV_MASK << REG01_SYS_MINV_SHIFT, REG01_SYS_MINV_SHIFT,0x4);


    reg_val = (4400 - REG04_VREG_BASE)/REG04_VREG_LSB;
    sgm41511_set_value(SGM4151X_REG_04, REG04_VREG_MASK << REG04_VREG_SHIFT, REG04_VREG_SHIFT, 0x4);

}

static void sprdchg_sgm41511_reset_timer(void)
{
    printf("sgm41511 reset rimer\n");
    sgm41511_set_value(SGM4151X_REG_07, REG07_TMR2X_EN_MASK << REG07_TMR2X_EN_SHIFT,
            REG07_TMR2X_EN_SHIFT, REG07_TMR2X_ENABLE);
}


static void sprdchg_sgm41511_set_chg_cur(uint32_t cur)
{
    u8 ichg;

	debugf("%s,chg cur limit:%d\n",__func__, cur);
    if (cur < REG02_ICHG_BASE)
        cur = REG02_ICHG_BASE;
    ichg = (cur - REG02_ICHG_BASE)/REG02_ICHG_LSB;
    sgm41511_set_value(SGM4151X_REG_02, REG02_ICHG_MASK << REG02_ICHG_SHIFT,
            REG02_ICHG_SHIFT, ichg);

}

static void sprdchg_sgm41511_set_input_cur(uint32_t cur)
{



    u8 reg_val;
    int ret;
	debugf("%s,input cur limit:%d\n",__func__, cur);
    if (cur < REG00_IINLIM_BASE)
        cur = REG00_IINLIM_BASE;
    reg_val = (cur - REG00_IINLIM_BASE) / REG00_IINLIM_LSB;
    sgm41511_set_value(SGM4151X_REG_00, REG00_IINLIM_MASK << REG00_IINLIM_SHIFT,
            REG00_IINLIM_SHIFT, reg_val);
}


static int sprdchg_sgm41511_cmd(enum sprdchg_cmd cmd,int value)
{
	switch (cmd) {
	case CHG_SET_CURRENT:
		sprdchg_sgm41511_set_chg_cur(value);
		break;
	case CHG_SET_LIMIT_CURRENT:
		sprdchg_sgm41511_set_input_cur(value);
		break;
	default:
		break;
	}

	return 0;
}



static int SGM4151x_detect_device()
{
    int ret;
    u8 data;
    ret = sgm41511_read_reg(SGM4151X_REG_0B, &data);

    return ret;
}


static struct sprdchg_ic_operations sprd_extic_op ={
	.ic_init = sprdchg_sgm41511_ic_init,
	.chg_start = sprdchg_sgm41511_start_chg,
	.chg_stop = sprdchg_sgm41511_stop_charging,
	.timer_callback = sprdchg_sgm41511_reset_timer,
	.chg_cmd = sprdchg_sgm41511_cmd,
};
#ifdef CONFIG_DM_SGM41511
static int sprd_sgm41511_probe(struct udevice *dev)
{
	u32 i2c_id;
	int ret;

	ret = dev_read_u32(dev, "sprd,sgm41511-i2c-bus", &i2c_id);
	if (ret) {
		pr_err("%s:failed to get i2c-bus ret = %d!\n", __func__, ret);
		return ret;
	}
	debugf("i2c_id = %d\n", i2c_id);
	dm_data.i2c_num = i2c_id;
	return 0;
}

static int sprd_dm_sgm41511_init(void)
{
	struct udevice *devp;
	int ret;

	ret = uclass_get_device(UCLASS_CHARGER, 0, &devp);
	if (ret) {
		pr_err("%s:failed to get device ret = %d", __func__, ret);
		return ret;
	}
	ret = sprd_dm_sgm41511_i2c_init();
  	if (ret) {
          	pr_err("%s:failed to init dm i2c ret = %d", __func__, ret);
		return ret;
        }
	return 0;
}
#endif


void sprdchg_sgm41511_init(void)
{

    int ret;

    printf("sgm41511 charger driver init\n");
   // ret = SGM4151x_detect_device();
   // if(ret)
   // {
   //     printf("No SGM41511 device found!\n");
   //     return;
   // }

#ifdef CONFIG_DM_SGM41511
	ret = sprd_dm_sgm41511_init();
#else
	ret = sprd_sgm41511_i2c_init();
#endif

    printf("sgm41511 register charge ops!\n");
    sprdchg_register_ops(&sprd_extic_op);
}


#ifdef CONFIG_DM_SGM41511
static const struct udevice_id sprd_sgm41511_ids[] = {
	{.compatible = "sprd,sgm41511-charger"},
	{ }
};

U_BOOT_DRIVER(sgm41511) = {
	.name = "sprd-sgm41511",
	.id = UCLASS_CHARGER,
	.of_match = sprd_sgm41511_ids,
	.probe = sprd_sgm41511_probe,
};

UCLASS_DRIVER(charger)= {
	.name = "charger",
	.id = UCLASS_CHARGER,
};
#endif
