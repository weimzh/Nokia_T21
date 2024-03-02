/*
 * An sc27xx_led device/driver
 * Copyright (C) 2019 UNISOC Communication Inc
 * Author: Yongzhi Chen <yongzhi.chen@unisoc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <led.h>
#include <asm/io.h>
#include <dm/lists.h>
#include <power/pmic.h>


#define GENMASK(h, l) \
	(((~0UL) << (l)) & (~0UL >> (BITS_PER_LONG - 1 - (h))))

#define SC2731_MODULE_EN0	0xc08
#define SC2731_CLK_EN0		0xc18
#define SC2731_RGB_CTRL		0xebc
#define SC2730_MODULE_EN0       0x1808
#define SC2730_CLK_EN0          0x1810
#define SC2730_RGB_CTRL         0
#define SC2721_MODULE_EN0       0xc08
#define SC2721_CLK_EN0          0xc10
#define SC2721_RGB_CTRL         0xea0

#define SC27XX_BLTC_EN		BIT(9)
#define SC27XX_RTC_EN		BIT(7)
#define SC27XX_RGB_PD		BIT(0)
#define SC2730_RGB_PD		BIT(12)

#define SC27XX_LEDS_CTRL	0x00
#define SC27XX_LEDS_DUTY	0x08
#define SC27XX_LEDS_CURVE0	0x0c
#define SC27XX_LEDS_CURVE1	0x10

#define SC27XX_CTRL_SHIFT	4
#define SC27XX_LED_RUN		BIT(0)
#define SC27XX_LED_TYPE		BIT(1)

#define SC27XX_DUTY_SHIFT	8
#define SC27XX_DUTY_MASK	GENMASK(15, 0)
#define SC27XX_MOD_MASK		GENMASK(7, 0)

#define SC27XX_CURVE_SHIFT	8
#define SC27XX_CURVE_L_MASK	GENMASK(7, 0)
#define SC27XX_CURVE_H_MASK	GENMASK(15, 8)

#define SC27XX_LEDS_OFFSET	0x10

#define SC27XX_LEDS_MAX		3

#define SC27XX_LEDS_PERIOD_MS	10

#define SC27XX_LEDS_MAX_BRIGHTNESS	255

struct sc27xx_led_priv {
	u32 regs;
	u32 line;
};

struct sc27xx_led_data {
	u32 module_en;
	u32 clk_en;
	u32 rgb_ctrl;
};

struct sc27xx_led_data sc2731_data = {
	.module_en = SC2731_MODULE_EN0,
	.clk_en = SC2731_CLK_EN0,
	.rgb_ctrl = SC2731_RGB_CTRL,
};

struct sc27xx_led_data sc2730_data = {
	.module_en = SC2730_MODULE_EN0,
	.clk_en = SC2730_CLK_EN0,
	.rgb_ctrl = SC2730_RGB_CTRL,
};

struct sc27xx_led_data sc2721_data = {
	.module_en = SC2721_MODULE_EN0,
	.clk_en = SC2721_CLK_EN0,
	.rgb_ctrl = SC2721_RGB_CTRL,
};

static int sc27xx_led_init(struct udevice *parent, const struct sc27xx_led_data *data)
{
	struct sc27xx_led_priv *priv = dev_get_priv(parent);
	struct udevice *pmic = dev_get_parent(parent);
	u32 ctrl_base;
	int ret;

	ctrl_base = priv->regs + SC27XX_LEDS_CTRL;
	ret = pmic_clrsetbits(pmic, data->module_en, SC27XX_BLTC_EN, SC27XX_BLTC_EN);
	if (ret != 0)
		return ret;

	ret = pmic_clrsetbits(pmic, data->clk_en, SC27XX_RTC_EN, SC27XX_RTC_EN);
	if (ret != 0) {
		pmic_clrsetbits(pmic, data->module_en, SC27XX_BLTC_EN, 0);
		return ret;
	}

	if (!data->rgb_ctrl)
		return pmic_clrsetbits(pmic, ctrl_base, SC2730_RGB_PD, 0);

	return pmic_clrsetbits(pmic, data->rgb_ctrl, SC27XX_RGB_PD, 0);
}

#ifdef CONFIG_LED_BLINK
static int sc27xx_led_set_period(struct udevice *dev, int period_ms)
{
	struct sc27xx_led_priv *priv = dev_get_priv(dev);
	struct udevice *parent = dev->parent;
	struct udevice *pmic = dev_get_parent(parent);
	u32 base, ctrl_base, hw_rising, hw_high, hw_falling, hw_low;
	u8 ctrl_shift;
	int ret;

	base = priv->regs + SC27XX_LEDS_OFFSET * priv->line;
	ctrl_base = priv->regs + SC27XX_LEDS_CTRL;
	ctrl_shift = SC27XX_CTRL_SHIFT * priv->line;

	hw_rising = period_ms * 2 / 10;
	hw_high = period_ms * 3 / 10;
	hw_falling = period_ms * 2 / 10;
	hw_low = period_ms * 3 / 10;

	ret = pmic_clrsetbits(pmic, base + SC27XX_LEDS_CURVE0,\
				     SC27XX_CURVE_L_MASK, hw_rising);
	if (ret != 0)
		return ret;

	ret = pmic_clrsetbits(pmic, base + SC27XX_LEDS_CURVE0,\
				     SC27XX_CURVE_H_MASK, hw_falling << SC27XX_CURVE_SHIFT);
	if (ret != 0)
		return ret;

	ret = pmic_clrsetbits(pmic, base + SC27XX_LEDS_CURVE1,\
				     SC27XX_CURVE_L_MASK, hw_high);
	if (ret != 0)
		return ret;

	ret = pmic_clrsetbits(pmic, base + SC27XX_LEDS_CURVE1,\
				     SC27XX_CURVE_H_MASK, hw_low << SC27XX_CURVE_SHIFT);
	if (ret != 0)
		return ret;

	ret = pmic_clrsetbits(pmic, base + SC27XX_LEDS_DUTY, SC27XX_DUTY_MASK,\
				     (SC27XX_LEDS_MAX_BRIGHTNESS << SC27XX_DUTY_SHIFT) | SC27XX_MOD_MASK);
	if (ret != 0)
		return ret;

	return pmic_clrsetbits(pmic, ctrl_base, SC27XX_LED_RUN << ctrl_shift,\
				      SC27XX_LED_RUN << ctrl_shift);
}
#endif

static int sc27xx_led_set_state(struct udevice *dev, enum led_state_t state)
{
	struct sc27xx_led_priv *priv = dev_get_priv(dev);
	struct udevice *parent = dev->parent;
	struct udevice *pmic = dev_get_parent(parent);
	u32 base, ctrl_base;
	u8 ctrl_shift;
	int ret;

	base = priv->regs + SC27XX_LEDS_OFFSET * priv->line;
	ctrl_base = priv->regs + SC27XX_LEDS_CTRL;
	ctrl_shift = SC27XX_CTRL_SHIFT * priv->line;
	switch (state) {
	case LEDST_OFF:
		ret = pmic_clrsetbits(pmic, ctrl_base,\
					     (SC27XX_LED_RUN | SC27XX_LED_TYPE) << ctrl_shift, 0);
		if (ret != 0)
			return ret;
		break;

	case LEDST_ON:
		ret = pmic_clrsetbits(pmic, base + SC27XX_LEDS_DUTY, SC27XX_DUTY_MASK,\
					     (SC27XX_LEDS_MAX_BRIGHTNESS << SC27XX_DUTY_SHIFT) | SC27XX_MOD_MASK);
		if (ret != 0)
			return ret;

		ret = pmic_clrsetbits(pmic, ctrl_base, (SC27XX_LED_RUN | SC27XX_LED_TYPE) << ctrl_shift,\
					     (SC27XX_LED_RUN | SC27XX_LED_TYPE) << ctrl_shift);
		if (ret != 0)
			return ret;
		break;

#ifdef CONFIG_LED_BLINK
	case LEDST_BLINK:
		sc27xx_led_set_period(dev, SC27XX_LEDS_PERIOD_MS);
		break;
#endif
	default:
		return -EINVAL;
	}
	return 0;
}

static const struct led_ops sc27xx_led_ops = {
	.set_state = sc27xx_led_set_state,
#ifdef CONFIG_LED_BLINK
	.set_period = sc27xx_led_set_period,
#endif
};

static int sc27xx_led_probe(struct udevice *dev)
{
	struct led_uc_plat *uc_plat = dev_get_uclass_platdata(dev);
	const struct sc27xx_led_data *data;
	struct sc27xx_led_priv *priv;
	int err;

	/* Ignore the top-level LED node */
	if (!uc_plat->label){
		if (device_is_compatible(dev->parent, "sprd,sc2721") ||
		    device_is_compatible(dev->parent, "sprd,sc2720"))
			data = &sc2721_data;
		else if (device_is_compatible(dev->parent, "sprd,sc2730"))
			data = &sc2730_data;
		else if (device_is_compatible(dev->parent, "sprd,sc2731"))
			data = &sc2731_data;
		else
			return -ENODEV;

		err = sc27xx_led_init(dev, data);
		if (err)
			return err;
	} else {
		priv = dev_get_priv(dev);
		priv->regs = (u32)dev_read_addr(dev_get_parent(dev));
		if (!priv->regs)
			return -EINVAL;

		priv->line = dev_read_u32_default(dev, "reg", SC27XX_LEDS_MAX);
		if (priv->line >= SC27XX_LEDS_MAX)
			return -EINVAL;
	}
	return 0;
}

static int sc27xx_led_bind(struct udevice *parent)
{
	ofnode node;

	dev_for_each_subnode(node, parent) {
		struct led_uc_plat *uc_plat;
		struct udevice *dev;
		const char *label;
		int ret;

		label = ofnode_read_string(node, "label");
		if (!label) {
			debug("%s: node %s has no label\n", __func__,
			      ofnode_get_name(node));
			return -EINVAL;
		}

		ret = device_bind_driver_to_node(parent, "sprd-bltc",
						 ofnode_get_name(node),
						 node, &dev);
		if (ret)
			return ret;

		uc_plat = dev_get_uclass_platdata(dev);
		uc_plat->label = label;
	}

	return 0;
}

U_BOOT_DRIVER(sprd_led) = {
	.name = "sprd-bltc",
	.id = UCLASS_LED,
	.bind = sc27xx_led_bind,
	.probe = sc27xx_led_probe,
	.priv_auto_alloc_size = sizeof(struct sc27xx_led_priv),
	.ops = &sc27xx_led_ops,
};
