/*
 *  eta6937_chg.c - ETA Solutions eta6937 charger ic driver
 *
 *  Copyright (C) 2019 Unisoc Communications Inc.
 *  History:
 *      2020-07-08 Jinfeng.Lin1@unisoc.com
 *      Add eta6937 charger ic driver
 */
#include "sprd_chg_helper.h"

#if defined(CHARGE_EN_USE_GPIO)
#define ENABLE_CHARGE 0
#define DISENABLE_CHARGE 1
#endif

/******************************************************************************
* Register addresses
******************************************************************************/
#define ETA6937_REG_0			0
#define ETA6937_REG_1			1
#define ETA6937_REG_2			2
#define ETA6937_REG_3			3
#define ETA6937_REG_4			4
#define ETA6937_REG_5			5
#define ETA6937_REG_6			6
#define ETA6937_REG_7			7

/******************************************************************************
* Register bits
******************************************************************************/
/* ETA6937_REG_0 (0x00) status and control reg*/
#define ETA6937_TMR_RST_OTG_STAT		(0x1 << 7)
#define ETA6937_TMR_RST_OTG_STAT_SHIFT		7
#define ETA6937_EN_STAT				(0x01 << 6)
#define ETA6937_EN_STAT_SHIFT			6
#define ETA6937_STAT1_STAT2			(0x3 <<  4)
#define ETA6937_STAT1_STAT2_SHIFT               4
#define ETA6937_BOOST				(0x01 << 3)
#define ETA6937_BOOST_SHIFT			3
#define ETA6937_FAULT				(0x07 << 0)
#define ETA6937_FAULT_SHIFT			0

/* ETA6937_REG_1 (0x01) control reg */
#define ETA6937_IIN_LIMIT_1			(0x03 << 6)
#define ETA6937_IIN_LIMIT_1_SHIFT		6
#define ETA6937_VLOWV				(0x03 << 4)
#define ETA6937_VLOWV_SHIFT			4
#define ETA6937_TE				(0x01 << 3)
#define ETA6937_TE_SHIFT			3
#define ETA6937_NCE				(0x01 << 2)
#define ETA6937_NCEE_SHIFT			2
#define ETA6937_HZ_MODE				(0x01 << 1)
#define ETA6937_HZ_MODE_SHIFT			1
#define ETA6937_OPA_MODE			(0x01 << 0)
#define ETA6937_OPA_MODE_SHIFT			0

/* ETA6937_REG_2 (0x02) control and battery voltage reg*/
#define ETA6937_VOREG				(0x3f << 2)
#define ETA6937_VOREG_SHIFT			2
#define ETA6937_OTG_PL				(0x01 << 1)
#define ETA6937_OTG_PL_SHIFT			1
#define ETA6937_OTG_EN				(0x01 << 0)
#define ETA6937_OTG_EN_SHIFT			0

/* ETA6937_REG_3 (0x03) Vendor/Part/Revision reg */
#define ETA6937_VENDOR_CODE			(0x07 << 5)
#define ETA6937_VENDOR_CODE_SHIFT		5
#define ETA6937_PN_CODE				(0x03 << 3)
#define ETA6937_PN_CODE_SHIFT			3
#define ETA6937_REV_CODE			(0x07 << 0)
#define ETA6937_REV_CODE_SHIFT			0

/* ETA6937_REG_4 (0x04) battery termination and fast charge current reg*/
#define ETA6937_RESET				(0x01 << 7)
#define ETA6937_RESET_SHIFT			7
#define ETA6937_ICHG				(0x07 << 4)
#define ETA6937_ICHG_SHIFT			4
#define ETA6937_ICHG_OFFSET			(0x01 << 3)
#define ETA6937_ICHG_OFFSET_SHIFT		3
#define ETA6937_ITERM				(0x07 << 0)
#define ETA6937_ITERM_SHIFT			0

/* ETA6937_REG_5 (0x05) special charger voltage and enable pin status reg*/
#define ETA6937_ICHG_4				(0x01 << 7)
#define ETA6937_ICHG_4_SHIFT			7
#define ETA6937_ICHG_3				(0x01 << 6)
#define ETA6937_ICHG_3_SHIFT			6
#define ETA6937_LOW_CHG				(0x01 << 5)
#define ETA6937_LOW_CHG_SHIFT			5
#define ETA6937_DPM_STATUS		        (0x01 << 4)
#define ETA6937_DPM_STATUS_SHIFT		4
#define ETA6937_CD_STATUS			(0x01 << 3)
#define ETA6937_CD_STATUS_SHIFT			3
#define ETA6937_VINDPM				(0x07 << 0)
#define ETA6937_VINDPM_SHIFT			0

/* ETA6937_REG_6 (0x06) savety limit reg*/
#define ETA6937_IMCHRG				(0x0f << 4)
#define ETA6937_IMCHRG_SHIFT			4
#define ETA6937_VMREG				(0x0f << 0)
#define ETA6937_VMREG_SHIFT			0

/* ETA6937_REG_7 (0x07) etra current limit and DPM Level Setting reg */
#define ETA6937_VINDPM_ADD                      (0x0f << 4)
#define ETA6937_VINDPM_ADD_SHIFT		4
#define ETA6937_EN_ILIM_2			(0x01 << 3)
#define ETA6937_EN_ILIM_2_SHIFT			3
#define ETA6937_IIN_LIMIT_2			(0x07 << 0)
#define ETA6937_IIN_LIMIT_2_SHIFT		0

/******************************************************************************
* bit definitions
******************************************************************************/
/********** ETA6937_REG_0 (0x00) **********/
// EN_STAT [6]
#define ENSTAT 1
#define DISSTAT 0
// TMR_RST [7]
#define RESET32S 1

/********** ETA6937_REG_1 (0x01) **********/
// OPA_MODE [0]
#define CHARGEMODE 0
#define BOOSTMODE 1
//HZ_MODE [1]
#define NOTHIGHIMP 0
#define HIGHIMP 1
// CE/ [2]
#define ENCHARGER 0
#define DISCHARGER 1
// TE [3]
#define DISTE 0
#define ENTE 1
// VLOWV [5:4]
#define VLOWV3P4 0
#define VLOWV3P5 1
#define VLOWV3P6 2
#define VLOWV3P7 3
// IINLIM [7:6]
#define IINLIM100 0
#define IINLIM500 1
#define IINLIM800 2
#define NOLIMIT 3

/********** ETA6937_REG_2 (0x02) **********/
// OTG_EN [0]
#define DISOTG 0
#define ENOTG 1
// OTG_PL [1]
#define OTGACTIVELOW 0
#define OTGACTIVEHIGH 1
// OREG [7:2]
#define VOREG4P2 35
#define VOREG4P4 45
/********** ETA6937_REG_3 (0x03) **********/

/********** ETA6937_REG_4 (0x04) **********/
// ITERM [2:0]
#define ITERM50 0
#define ITERM100 1
#define ITERM150 2
#define ITERM200 3
#define ITERM250 4
#define ITERM300 5
#define ITERM350 6
#define ITERM400 7
// ICHRG_OFFSET[3]
#define ENICHRGOFFSET 1
#define DISICHRGOFFSET 0
// ICHG [6:4] - ICHRGOFFSET = 0
#define ICHG550 0
#define ICHG650 1
#define ICHG750 2
#define ICHG850 3
#define ICHG950 4
#define ICHG1050 5
#define ICHG1150 6
#define ICHG1250 7
// CHG_RESET[7]
#define CHG_RESET 1

/********** ETA6937_REG_5 (0x05) **********/
//ICHG4[7]
#define ICHG_4_1600MA 1
//ICHG3[6]
#define ICHG_3_800MA 1
//LOW_CHG[5] for low chg 550mA
#define FORCE_LOW_CHG 1
#define DIS_LOW_CGH 0

/********** ETA6937_REG_6 (0x06) **********/
// IMCHG [7:4] ICHG_OFFSET = 0
#define IMCHG550 0
#define IMCHG750 1
#define IMCHG950 2
#define IMCHG1150 3
#define IMCHG1350 4
#define IMCHG1550 5
#define IMCHG1750 6
#define IMCHG1950 7
#define IMCHG2150 8
#define IMCHG2350 9
#define IMCHG2550 10
#define IMCHG2750 11
#define IMCHG2950 12
#define IMCHG3050 13
#define IMCHG3050 14
#define IMCHG3050 15

//VMREG[3:0]
#define VMREG4P20 0
#define VMREG4P22 1
#define VMREG4P24 2
#define VMREG4P26 3
#define VMREG4P28 4
#define VMREG4P30 5
#define VMREG4P32 6
#define VMREG4P34 7
#define VMREG4P36 8
#define VMREG4P38 9
#define VMREG4P40 10
#define VMREG4P42 11
#define VMREG4P44 12
#define VMREG4P44 13
#define VMREG4P44 14
#define VMREG4P44 15

/********** ETA6937_REG_7 (0x07) **********/
//VINDPM[7:4]
//EN_ILIM_2[3]
#define EN_ILIM_2 1
#define DIS_ILIM_2 0
//IIN_LIMIT_2[2:0]
#define IINLIMT2_300 0
#define IINLIMT2_500 1
#define IINLIMT2_800 2
#define IINLIMT2_1200 3
#define IINLIMT2_1500 4
#define IINLIMT2_2000 5
#define IINLIMT2_3000 6
#define IINLIMT2_5000 7

static u32 iin_lim_tbl[] = {
	300000,
	500000,
	800000,
	1200000,
	1500000,
	2000000,
	3000000,
	5000000,
};

#define I2C_SPEED		(100000)
#define SLAVE_ADDR		(0x6a)

#define VENDOR_ETA6937		(0x2)

#define ETA6937_CHG_IMIN		500000
#define ETA6937_CHG_ISTEP		50000
#define ETA6937_CHG_IMAX		3050000

static unsigned char eta6937_get_vendor_id(void);

static uint16_t sprd_eta6937_i2c_init(void)
{
	i2c_set_bus_num(CONFIG_SPRDCHG_I2C_BUS);
	i2c_init(I2C_SPEED, SLAVE_ADDR);
	return 0;
}
static int eta6937_write_reg(int reg, u8 val)
{
	i2c_reg_write(SLAVE_ADDR,reg,val);
	return 0;
}

static int eta6937_read_reg(int reg, u8 *value)
{
	int ret;
	ret = i2c_reg_read(SLAVE_ADDR , reg);
	if (ret < 0) {
		printf("%s reg(0x%x), ret(%d)\n", __func__, reg, ret);
		return ret;
	}

	ret &= 0xff;
	*value = ret;
	printf("######eta6937 readreg reg  = %d value =%d/%x\n",reg, ret, ret);
	return 0;
}

static void eta6937_set_value(BYTE reg, BYTE reg_bit,BYTE reg_shift, BYTE val)
{
	BYTE tmp;
	eta6937_read_reg(reg, &tmp);
	tmp = tmp & (~reg_bit) |(val << reg_shift);
	if ((0x04 == reg) && (ETA6937_RESET != reg_bit)) {
		tmp &= 0x7f;
	}
	eta6937_write_reg(reg,tmp);
}

static BYTE eta6937_get_value(BYTE reg, BYTE reg_bit, BYTE reg_shift)
{
	BYTE data = 0;
	BYTE ret = 0 ;
	ret = eta6937_read_reg(reg, &data);
	ret = (data & reg_bit) >> reg_shift;

	return ret;
}

static void sprdchg_eta6937_start_chg(int type)
{
	printf("start charge\n");
#if defined(CHARGE_EN_USE_GPIO)
	sprd_gpio_request(NULL,CHARGE_EN_GPIO);
	sprd_gpio_direction_output(NULL,CHARGE_EN_GPIO, ENABLE_CHARGE);
#else
	sprd_charge_pd_control(true);
#endif
}
static void sprdchg_eta6937_stop_charging(int value)
{
	printf("stop charge\n");
#if defined(CHARGE_EN_USE_GPIO)
	sprd_gpio_request(NULL,CHARGE_EN_GPIO);
	sprd_gpio_direction_output(NULL,CHARGE_EN_GPIO, DISENABLE_CHARGE);
#else
	sprd_charge_pd_control(false);
#endif
}
static void  eta6937_sw_reset(void)
{
	printf("eta6937_sw_reset\n");
	eta6937_set_value(ETA6937_REG_4, ETA6937_RESET, ETA6937_RESET_SHIFT, CHG_RESET);
}
static void sprdchg_eta6937_ic_init(void)
{
	unsigned char vendor_id;
	vendor_id = eta6937_get_vendor_id();
	sprd_eta6937_i2c_init();
	eta6937_sw_reset();
	//reg 6
	//VMREG = 4.44V
	eta6937_set_value(ETA6937_REG_6, ETA6937_VMREG, ETA6937_VMREG_SHIFT, VMREG4P44);
	//IMCHRG = 2A
	eta6937_set_value(ETA6937_REG_6, ETA6937_IMCHRG, ETA6937_IMCHRG_SHIFT, IMCHG1950);

	//reg 1
	//VLOW = 3.4V
	eta6937_set_value(ETA6937_REG_1, ETA6937_VLOWV, ETA6937_VLOWV_SHIFT, VLOWV3P4);
	//IINLIMIT_1 = NO LIMIT
	eta6937_set_value(ETA6937_REG_1, ETA6937_IIN_LIMIT_1, ETA6937_IIN_LIMIT_1_SHIFT, NOLIMIT);
	//reg 7
	//IINLIMIT_2 = 2A
	eta6937_set_value(ETA6937_REG_7, ETA6937_IIN_LIMIT_2, ETA6937_IIN_LIMIT_2_SHIFT, IINLIMT2_2000);
	//EN_LIMIT SET BY IINLIMIT_2
	eta6937_set_value(ETA6937_REG_7, ETA6937_EN_ILIM_2, ETA6937_EN_ILIM_2_SHIFT, EN_ILIM_2);
	//reg 2
	//VOREG = 4.4
	eta6937_set_value(ETA6937_REG_2, ETA6937_VOREG, ETA6937_VOREG_SHIFT, VOREG4P4);
	//reg 4
	//ICHRG_OFFSET = 0
	eta6937_set_value(ETA6937_REG_4, ETA6937_ICHG_OFFSET, ETA6937_ICHG_OFFSET_SHIFT, 0);
}

static void sprdchg_eta6937_reset_timer(void)
{
	printf("eta6937 reset rimer\n");
	eta6937_set_value(ETA6937_REG_0, ETA6937_TMR_RST_OTG_STAT,
			  ETA6937_TMR_RST_OTG_STAT_SHIFT, RESET32S);
}

static unsigned char eta6937_get_vendor_id(void)
{
	return eta6937_get_value(ETA6937_REG_3, ETA6937_VENDOR_CODE, ETA6937_VENDOR_CODE_SHIFT);
}

static void eta6937_set_chg_current(unsigned char reg_val)
{
	eta6937_set_value(ETA6937_REG_4, ETA6937_ICHG, ETA6937_ICHG_SHIFT, (reg_val & 0x7));
	eta6937_set_value(ETA6937_REG_5, ETA6937_ICHG_3, ETA6937_ICHG_3_SHIFT, ((reg_val & 0x8)) >> 3);
	eta6937_set_value(ETA6937_REG_5, ETA6937_ICHG_4, ETA6937_ICHG_4_SHIFT, ((reg_val & 0x10)) >> 4);
}

static void eta6937_set_input_current(unsigned char reg_val)
{
	if (reg_val == 0)
		eta6937_set_value(ETA6937_REG_7, ETA6937_IIN_LIMIT_2,
				  ETA6937_IIN_LIMIT_2_SHIFT, IINLIMT2_500);
	else
		eta6937_set_value(ETA6937_REG_7, ETA6937_IIN_LIMIT_2,
				  ETA6937_IIN_LIMIT_2_SHIFT, reg_val);
}

static unsigned char sprdchg_eta6937_chg_cur2reg(uint32_t cur)
{
	unsigned char reg_val;

	/* mA to uA */
	cur *= 1000;

	if (cur > ETA6937_CHG_IMAX)
		cur = ETA6937_CHG_IMAX;
	else if (cur < ETA6937_CHG_IMIN)
		cur = ETA6937_CHG_IMIN;

	reg_val = (cur - ETA6937_CHG_IMIN) / ETA6937_CHG_ISTEP;

	return reg_val;
}

static unsigned char sprdchg_eta6937_input_cur2reg(uint32_t cur)
{
	unsigned char reg_val, i = 0;

	/* mA to uA */
	cur *= 1000;

	for (i = 1; i < ARRAY_SIZE(iin_lim_tbl); ++i)
		if (cur < iin_lim_tbl[i])
			break;

	/* When the val is less than the judgment value,
	 * so to set last judgment cur value.
	 */
	reg_val = i - 1;

	return reg_val;
}

static void sprdchg_eta6937_set_chg_cur(uint32_t cur)
{
	unsigned char reg_val = 0, vendor_id = 0;

	debugf("%s,chg cur limit:%d\n",__func__, cur);

	reg_val = sprdchg_eta6937_chg_cur2reg(cur);

	eta6937_set_chg_current(reg_val);
}

static void sprdchg_eta6937_set_input_cur(uint32_t cur)
{
	unsigned char reg_val = 0, vendor_id = 0;

	debugf("%s,input cur limit:%d\n",__func__, cur);

	reg_val = sprdchg_eta6937_input_cur2reg(cur);

	eta6937_set_input_current(reg_val);
}


static int sprdchg_eta6937_cmd(enum sprdchg_cmd cmd,int value)
{
	switch (cmd) {
	case CHG_SET_CURRENT:
		sprdchg_eta6937_set_chg_cur(value);
		break;
	case CHG_SET_LIMIT_CURRENT:
		sprdchg_eta6937_set_input_cur(value);
		break;
	default:
		break;
	}

	return 0;
}

static struct sprdchg_ic_operations sprd_extic_op ={
	.ic_init = sprdchg_eta6937_ic_init,
	.chg_start = sprdchg_eta6937_start_chg,
	.chg_stop = sprdchg_eta6937_stop_charging,
	.timer_callback = sprdchg_eta6937_reset_timer,
	.chg_cmd = sprdchg_eta6937_cmd,
};

void sprdchg_eta6937_init(void)
{
	BYTE data = 0;
	unsigned char vendor_id = 0;

	printf("eta6937 charger driver init\n");

	sprd_eta6937_i2c_init();

	vendor_id = eta6937_get_vendor_id();
	if (vendor_id == 0x0) {
		vendor_id = eta6937_get_vendor_id();
	}
	if (vendor_id != VENDOR_ETA6937) {
		printf("eta6937 is not found,not register ops!!!\n");
		return;
	}
	printf("eta6937 register charge ops!\n");
	sprdchg_register_ops(&sprd_extic_op);
}

