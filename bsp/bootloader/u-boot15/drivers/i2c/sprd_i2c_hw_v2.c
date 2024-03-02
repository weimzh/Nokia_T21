/*
 * Basic I2C functions
 *
 * Copyright (c) 2015 Texas Instruments
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Author: xulinhua linhua.xu@spreadtrum.com, Texas Instruments
 *
 * Adapted for sprd I2C
 */

#include <asm/arch/hw_i2c/sprd_hw_i2c.h>
#include <asm/io.h>
#include <common.h>

#define I2C_CTL 			0x00
#define CHNL_TX_BASEADDR		0x4C
#define CHNL_TX_ADDR(x)			(CHNL_TX_BASEADDR + (((x) - 5) << 1))
#define CHNL_RX_BASEADDR		0x7C
#define CHNL_RX_ADDR(x)			(CHNL_RX_BASEADDR + (((x) - 6) << 1))
#define CHN_MAX_CNT			50
#define CHN_START			2

#define CHN_TX_START		5
#define CHN_TX_MAX_CNT		27

#define CHN_RX_START		6
#define CHN_RX_MAX_CNT		28

/*I2C_CTL*/
#define I2C_EN				BIT(2)
#define I2C_HW_EN			BIT(0)

/* HW_CHNL_PRIL  */

void hw_i2c_chnl_pril_set(unsigned int chn, unsigned int config, int n)
{
	u32 val;

	if (chn < CHN_START || chn >= CHN_MAX_CNT)
                return -1;

	if ((chn <= CHN_TX_MAX_CNT || chn >= CHN_TX_START) & (chn % 2)) {
		val = __raw_readl(sprd_hw_i2c[n].base + CHNL_TX_ADDR(chn));
		val |= config;
		__raw_writel(val, sprd_hw_i2c[n].base + CHNL_TX_ADDR(chn));
	}

	if ((chn <= CHN_RX_MAX_CNT || chn >= CHN_RX_START) & !(chn % 2)) {
		val = __raw_readl(sprd_hw_i2c[n].base + CHNL_TX_ADDR(chn));
		val |= config;
		__raw_writel(val, sprd_hw_i2c[n].base + CHNL_TX_ADDR(chn));
	}
}

void hw_i2c_clk_enable(int n)
{
        u32 val = __raw_readl(sprd_hw_i2c[n].apb_base);

        val |= sprd_hw_i2c[n].apb_eb;
        __raw_writel(val, sprd_hw_i2c[n].apb_base);

	val = __raw_readl(sprd_hw_i2c[n].base);
        val |= I2C_EN;
        __raw_writel(val, sprd_hw_i2c[n].base);
}

int i2c_hwchannel_set(unsigned int chn, unsigned int config, int n)
{
        u32 val;

        if (chn < CHN_START || chn >= CHN_MAX_CNT)
                return -1;

	if ((chn <= CHN_TX_MAX_CNT || chn >= CHN_TX_START) & (chn % 2)) {
		config |= I2C_HW_EN;
		__raw_writel(config, sprd_hw_i2c[n].base + CHNL_TX_ADDR(chn));
	}

	if ((chn <= CHN_RX_MAX_CNT || chn >= CHN_RX_START) & !(chn % 2)) {
		config |= I2C_HW_EN;
		__raw_writel(config, sprd_hw_i2c[n].base + CHNL_RX_ADDR(chn));
	}
	val = __raw_readl(sprd_hw_i2c[n].base + CHNL_TX_ADDR(chn));
        return 0;
}

void i2c_dvfs_hwchn_init(void)
{
	int i, j;
	for(i = 0; i < SPRD_I2C_NUM; i++){
		hw_i2c_clk_enable(i);

		for(j = 0; j < sprd_hw_i2c[i].num; j++){
			i2c_hwchannel_set(sprd_hw_i2c[i].channel[j].channel_num,
				sprd_hw_i2c[i].channel[j].addr, i);

			hw_i2c_chnl_pril_set(sprd_hw_i2c[i].channel[j].channel_num,
				sprd_hw_i2c[i].channel[j].pril, i);
		}
	}

}
