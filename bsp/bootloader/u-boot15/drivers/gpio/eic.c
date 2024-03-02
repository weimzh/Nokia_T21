/*
 *  linux/arch/arm/mach-sprd/gpio.c
 *
 *  Generic SPRD GPIO handling
 *
 *  Author:	Yingchun Li(yingchun.li@spreadtrum.com)
 *  Created:	March 10, 2010
 *  Copyright:	Spreadtrum Inc.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */
#include <config.h>
#include <asm/io.h>
#include <asm/arch/sprd_reg.h>
#include <asm/arch/sprd_eic.h>
#include "adi_hal_internal.h"
#include <asm/arch/common.h>
#include <asm/errno.h>
#include <dt-bindings/interrupt-controller/irq.h>


extern int printf(const char *fmt, ...);

#define KERN_WARNING ""
#define WARN(nmu, fmt...) printf(fmt)
#define WARN_ON(num)
#define BUG_ON(__cond__) if(__cond__) printf("%s line: %d bug on\n",\
					__FUNCTION__, __LINE__)
#define pr_err(fmt...) printf(fmt)
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define pr_debug(fmt...) printf(fmt)

#ifdef CONFIG_SPRD_EIC_IRQ
typedef void (*tHandler) (void *int_num);
extern void irq_handler_register(int irq_num,tHandler func);
extern void gic_interrupt_enable (unsigned int interrupt, unsigned int enable);

#define SPRD_EICA_PER_BANK_NR		16
#define SPRD_EICA_BIT(x)			((x) & (SPRD_EICA_PER_BANK_NR - 1))
#define SPRD_EICA_NR		16

#define SPRD_EIC_MAX_BANK		8
#define SPRD_EIC_PER_BANK_NR		8
#define SPRD_EIC_NR			64
#define SPRD_EIC_BIT(x)			((x) & (SPRD_EIC_PER_BANK_NR - 1))
#endif
//#define DEBUG

#ifdef DEBUG
#define GPIO_DBG(fmt...) pr_debug(fmt)
#else
#define GPIO_DBG(fmt...)
#endif

struct eic_info{
	u32 base_addr;
	int die;
	u8  bit_num;
};

enum eic_die {
	A_DIE = 0,
	D_DIE = 1,
};

#ifdef CONFIG_SPRD_EIC_IRQ
typedef void (* EIC_CALLBACK) (u32 eic_num, u32 eic_state);

struct eic_irq{
	unsigned int eicnum;
	int irq;
	EIC_CALLBACK int_table[SPRD_EICA_NR];
}sprd_eic_cfg = {0};

#define EIC_INVALID_ID	(0xff)
#endif

#define INVALID_REG	(~(u32)0)

#define EIC_DATA 0x00
#define EIC_MASK 0x04
#define EIC_IEV  0x14
#define EIC_IE   0x18
#define EIC_RIS  0x1C
#define EIC_MIS  0x20
#define EIC_IC   0x24
#define EIC_TRIG 0x28

#define EIC0_CTL 0x40
#define EIC1_CTL 0x44
#define EIC2_CTL 0x48
#define EIC3_CTL 0x4C
#define EIC4_CTL 0x50
#define EIC5_CTL 0x54
#define EIC6_CTL 0x58
#define EIC7_CTL 0x5C
#define EIC8_CTL 0x60
#define EIC9_CTL 0x64
#define EIC10_CTL 0x68
#define EIC11_CTL 0x6C
#define EIC12_CTL 0x70

#ifdef CONFIG_SPRD_EIC_IRQ
static __inline unsigned long __ffs(unsigned long word)
{
	int num = 0;

	if ((word & 0xffff) == 0) {
		num += 16;
		word >>= 16;
	}
	if ((word & 0xff) == 0) {
		num += 8;
		word >>= 8;
	}
	if ((word & 0xf) == 0) {
		num += 4;
		word >>= 4;
       }
	if ((word & 0x3) == 0) {
		num += 2;
		word >>= 2;
	}
	if ((word & 0x1) == 0)
		num += 1;
	return num;
}

static __inline u32 eic_reg_get (u32 reg_addr, int die)
{
//   	GPIO_DBG("read %s die reg:%x\r\n",
//   			(die == D_DIE) ? "D die" : "A die", reg_addr);
	if (die == D_DIE)
		return __raw_readl (reg_addr);
	else
		return ANA_REG_GET (reg_addr);
}

static __inline void eic_reg_set (u32 reg_addr, int die, u32 value)
{
//  GPIO_DBG("set %s die reg:%x, value %x\r\n",
//			(die == D_DIE) ? "D die" : "A die", reg_addr, value);
	if (die == D_DIE) {
		__raw_writel(value, reg_addr);
	}
	else
	{
		ANA_REG_SET (reg_addr,value);
	}
	return;
}
#endif

static void __get_eic_base_info (u32 eic_id, struct eic_info *info)
{
	if (eic_id>=SPRD_ADIE_EIC_START && eic_id<=SPRD_ADIE_EIC_END)
	{
		info->base_addr= SPRD_ANA_EIC_PHYS;
		info->bit_num  = eic_id&0xF;
		info->die	   = A_DIE;

	}
#ifndef CONFIG_SPRD_GPIO_PLUS
	else if (eic_id>=SPRD_DDIE_EIC_START && eic_id<=SPRD_DDIE_EIC_END)
	{
		info->base_addr= SPRD_EIC_PHYS;
		info->bit_num  = eic_id&0x7;
		info->die	   = D_DIE;
	}
#ifdef CONFIG_SPRD_EIC_EXT1
	else if (eic_id>=SPRD_DDIE_EIC1_START && eic_id<=SPRD_DDIE_EIC1_END)
	{
		info->base_addr= SPRD_EIC1_PHYS;
		info->bit_num  = eic_id&0x7;
		info->die	   = D_DIE;
	}
#endif
#ifdef CONFIG_SPRD_EIC_EXT2
	else if (eic_id>=SPRD_DDIE_EIC2_START && eic_id<=SPRD_DDIE_EIC2_END)
	{
		info->base_addr= SPRD_EIC2_PHYS;
		info->bit_num  = eic_id&0x7;
		info->die	   = D_DIE;
	}
#endif
#endif
	else
	{
		info->base_addr = INVALID_REG;
	}
}

static int __eic_get_pin_data (struct eic_info *info)
{
	u32 reg_addr = 0, reg_data;

	if (info->base_addr == INVALID_REG)
	{
		return  -1;
	}

	reg_addr = info->base_addr + EIC_DATA;

	if (info->die == D_DIE)
		reg_data = __raw_readl (reg_addr);
	else
		reg_data = ANA_REG_GET (reg_addr);
	reg_data &= 1<<info->bit_num;

	return !!reg_data;
}

static int __eic_get_data_mask (struct eic_info *info)
{
	u32 reg_addr = 0, reg_data;

	if (info->base_addr == INVALID_REG)
	{
		return  -1;
	}

	reg_addr = info->base_addr + EIC_MASK;

	if (info->die == D_DIE)
		reg_data = __raw_readl (reg_addr);
	else
		reg_data = ANA_REG_GET (reg_addr);
	reg_data &= 1<<info->bit_num;

	return reg_data;
}

/*
	set data mask, the gpio data register can be access
 */
static void __eic_set_data_mask (struct eic_info *info, int b_on)
{
	u32 reg_addr = 0, reg_data;

	reg_addr = info->base_addr + EIC_MASK;

	if (info->base_addr == INVALID_REG)
	{
		return;
	}

	if (info->die == D_DIE)
		reg_data = __raw_readl (reg_addr);
	else
		reg_data = ANA_REG_GET (reg_addr);

	if (b_on)
	{
		if (!(reg_data&(1<<info->bit_num)))
		{
			reg_data |= 1<<info->bit_num;
			if (info->die == D_DIE)
				__raw_writel (reg_data, reg_addr);
			else
				ANA_REG_SET (reg_addr, reg_data);
		}
	}
	else
	{
		if (reg_data&(1<<info->bit_num))
		{
			reg_data &= ~(1<<info->bit_num);
			if (info->die == D_DIE)
				__raw_writel (reg_data, reg_addr);
			else
				ANA_REG_SET (reg_addr, reg_data);
		}
	}
}


int sprd_eic_get(unsigned offset)
{
	unsigned eic_id = offset;
	struct eic_info eic_info;

	__get_eic_base_info (eic_id, &eic_info);

	if (!__eic_get_data_mask (&eic_info)) {
		WARN(1, "GPIO_%d data mask hasn't been opened!\n", eic_id);
	}

	return __eic_get_pin_data (&eic_info);
}

int sprd_eic_request(unsigned offset)
{
	unsigned eic_id = offset;
	struct eic_info eic_info;

	__get_eic_base_info (eic_id, &eic_info);
	__eic_set_data_mask (&eic_info, 1);
	return 0;
}

static void sprd_eic_free(unsigned int offset)
{
	unsigned eic_id = offset;
	struct eic_info eic_info;

	__get_eic_base_info (eic_id, &eic_info);
	__eic_set_data_mask (&eic_info, 0);
	return;
}

#ifdef CONFIG_SPRD_EIC_IRQ
#if 0
static int sprd_eic_set_debounce(unsigned int offset,
				 unsigned int debounce)
{
	unsigned eic_id = offset;
	struct eic_info eic_info;
	u32 reg, value;

	__get_eic_base_info (eic_id, &eic_info);

	if (eic_info.die == D_DIE)
		reg = EIC0_CTL + SPRD_EIC_BIT(offset) * 0x4;
	else
		reg = EIC0_CTL + SPRD_EICA_BIT(offset) * 0x4;

	value = eic_reg_get(eic_info.base_addr + reg, eic_info.die) & ~SPRD_EIC_DBNC_DMSK;

	value |= (debounce / 1000) & SPRD_EIC_DBNC_DMSK;
	eic_reg_set(value, eic_info.die, eic_info.base_addr + reg);

	return 0;
}
#endif

int sprd_eic_irq_sts(unsigned offset)
{
	unsigned eic_id = offset;
	struct eic_info eic_info;

	__get_eic_base_info (eic_id, &eic_info);

	if (!__eic_get_data_mask (&eic_info)) {
		WARN(1, "GPIO_%d data mask hasn't been opened!\n", eic_id);
		return 0;
	}

	if (eic_info.die == D_DIE)
		return !!(eic_reg_get(eic_info.base_addr + EIC_MIS, eic_info.die)
	                     & BIT(SPRD_EIC_BIT(offset)));
	else
		return !!(eic_reg_get(eic_info.base_addr + EIC_MIS, eic_info.die)
					 & BIT(SPRD_EICA_BIT(offset)));

}

static void sprd_eic_reg_update(unsigned int offset,
			    u16 reg, unsigned int val)
{
	struct eic_info eic_info;
	unsigned eic_id = offset;
	u32 tmp;

	__get_eic_base_info (eic_id, &eic_info);

	tmp = eic_reg_get(eic_info.base_addr + reg, eic_info.die);
	if (eic_info.die == D_DIE) {
		if (val)
			tmp |= BIT(SPRD_EIC_BIT(offset));
		else
			tmp &= ~BIT(SPRD_EIC_BIT(offset));
	} else {
		if (val)
			tmp |= BIT(SPRD_EICA_BIT(offset));
		else
			tmp &= ~BIT(SPRD_EICA_BIT(offset));
	}

	eic_reg_set(eic_info.base_addr + reg, eic_info.die, tmp);
}

int sprd_eic_irq_set_type(unsigned int offset, unsigned int flow_type)
{
	switch (flow_type) {
	case IRQ_TYPE_LEVEL_HIGH:
		sprd_eic_reg_update(offset, EIC_IEV, 1);
		break;
	case IRQ_TYPE_LEVEL_LOW:
		sprd_eic_reg_update(offset, EIC_IEV, 0);
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

int sprd_eic_direction_input(unsigned int offset)
{
	/* EICs are always input, nothing need to do here. */
	return 0;
}

void sprd_eic_irq_mask(unsigned int offset)
{
	sprd_eic_reg_update(offset, EIC_IE, 0);
	sprd_eic_reg_update(offset, EIC_TRIG, 0);
}

void sprd_eic_irq_unmask(unsigned int offset)
{
	sprd_eic_reg_update(offset, EIC_IE, 1);
	sprd_eic_reg_update(offset, EIC_TRIG, 1);
}

void sprd_eic_irq_ack(unsigned int offset)
{
	sprd_eic_reg_update(offset, EIC_IC, 1);
}

void sprd_eica_int_reg(unsigned int eic_num,EIC_CALLBACK eic_callback)
{
	if (eic_num <= SPRD_ADIE_EIC_START && eic_num >= SPRD_ADIE_EIC_END)
	{
		WARN(1, "EIC_%d not adie eic!!\n", eic_num);
		return;
	}

	if(sprd_eic_cfg.int_table[eic_num - SPRD_ADIE_EIC_START] == NULL)
		sprd_eic_cfg.int_table[eic_num - SPRD_ADIE_EIC_START] = eic_callback;
}

static int sprd_eica_irq_handler(void)
{
	unsigned int n, state, eic_id;
	struct eic_info eic_info = {0};
	unsigned long value;

	__get_eic_base_info (SPRD_ADIE_EIC_START, &eic_info);
	if (eic_info.base_addr == INVALID_REG) {
		WARN(1, "ERR:Get EIC base_addr\n");
		return 0;
	}

	value = eic_reg_get(eic_info.base_addr + EIC_MIS, eic_info.die);

	while(value){
		n = __ffs(value);
		value &= ~(1UL<<n);
		eic_id = SPRD_ADIE_EIC_START + n;
		sprd_eic_irq_ack(eic_id);
		sprd_eic_irq_mask(eic_id);
		state = sprd_eic_get(eic_id);
		if(sprd_eic_cfg.int_table[n] != NULL)
			(*(sprd_eic_cfg.int_table[n]))(eic_id, state);
		else
			printf("eica:%d isr callback is null!\n", eic_id);
		sprd_eic_irq_unmask(eic_id);
	}
	return 0;
}

void EICA_EnableInt()
{
	gic_interrupt_enable(sprd_eic_cfg.irq, 1);
}

void EICA_DisableInt()
{
	gic_interrupt_enable(sprd_eic_cfg.irq, 0);
}

void EIC_Enable(u32 eic_num)
{
	sprd_eic_request(eic_num);
}

void EIC_Disable(u32 eic_num)
{
	sprd_eic_free(eic_num);
}

int EIC_GetValue(u32 eic_num)
{
	return sprd_eic_get(eic_num);
}

void EIC_ClrIntSts(u32 eic_num)
{
	sprd_eic_irq_ack(eic_num);
}

u32 EIC_GetPol(u32 eic_num)
{
	struct eic_info eic_info;

	__get_eic_base_info (eic_num, &eic_info);

	if (!__eic_get_data_mask (&eic_info)) {
		WARN(1, "EIC_%d data mask hasn't been opened!\n", eic_num);
		return 0;
	}

	if (eic_info.die == D_DIE)
		return !!(eic_reg_get(eic_info.base_addr + EIC_IEV, eic_info.die)
			                     & BIT(SPRD_EIC_BIT(eic_num)));
	else
		return !!(eic_reg_get(eic_info.base_addr + EIC_IEV, eic_info.die)
						 & BIT(SPRD_EICA_BIT(eic_num)));
}

void EIC_GetMskIntSts(u32 eic_num)
{
	return sprd_eic_irq_sts(eic_num);
}

void EIC_SetIntSense(u32 eic_num,int sense_type)
{
	sprd_eic_irq_set_type(eic_num,sense_type);
}

void EIC_EnableIntCtl(u32 eic_num)
{
	sprd_eic_irq_unmask(eic_num);
}

void EIC_DisableIntCtl(u32 eic_num)
{
	sprd_eic_irq_mask(eic_num);
}

u32 EICA_AddCallbackToIntTable(u32 eic_num,EIC_CALLBACK eic_callback_fun)
{
	sprd_eica_int_reg(eic_num, eic_callback_fun);
	EIC_EnableIntCtl(eic_num);
	return 0;
}
#endif

void sprd_eic_init(void)
{
#ifdef REG_EIC_EB
	REG32(REG_EIC_EB) |= BIT_EIC_EB;
#else
	REG32(REG_AON_APB_APB_EB0) |= BIT_EIC_EB;
#endif

	REG32(REG_AON_APB_APB_RTC_EB) |= BIT_EIC_RTC_EB|BIT_EIC_RTCDV5_EB;
	ANA_REG_OR(ANA_REG_GLB_ARM_MODULE_EN, BIT_ANA_EIC_EN);
	ANA_REG_OR(ANA_REG_GLB_RTC_CLK_EN,    BIT_RTC_EIC_EN);
#ifdef CONFIG_SPRD_EIC_IRQ
	sprd_eic_cfg.irq = TB_EICA_INT;
	irq_handler_register(sprd_eic_cfg.irq, sprd_eica_irq_handler);
	EICA_EnableInt();
#endif
}

