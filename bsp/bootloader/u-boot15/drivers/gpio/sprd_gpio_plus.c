#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <malloc.h>
#include <asm/errno.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include <asm-generic/gpio.h>
#include <dt-bindings/gpio/gpio.h>

/* GPIO registers definition */
#define GPIO0_CRL		0x0
#define GPIO_CRL(n)		(GPIO0_CRL + (n) * 0x4)

#define BIT_GPIO_DATA		BIT(0)
#define BIT_GPIO_ODATA		BIT(1)
#define BIT_GPIO_ENABLE		BIT(2)
#define BIT_GPIO_DIR		BIT(3)

#define SPRD_GPIO_PLUS_NR	256

static void sprd_gpio_plus_update(struct udevice *dev,
				  u32 reg, u32 mask, int value)
{
	void __iomem *base = dev->priv;
	u32 shift;
	u32 tmp;

	if (mask)
		shift = ffs(mask) - 1;
	else
		shift = 0;

	tmp = __raw_readl(base + reg);

	tmp &= ~mask;
	tmp |= (value << shift) & mask;

	__raw_writel(tmp, base + reg);
}

static int sprd_gpio_plus_read(struct udevice *dev, u32 reg, u32 mask)
{
	void __iomem *base = dev->priv;
	u32 shift;
	u32 value;

	if (mask)
		shift = ffs(mask) - 1;
	else
		shift = 0;

	value = __raw_readl(base + reg);
	value &= mask;

	return value >>= shift;
}

static int sprd_gpio_plus_request(struct udevice *dev, u32 offset,
				  const char *label)
{
	sprd_gpio_plus_update(dev, GPIO_CRL(offset), BIT_GPIO_ENABLE, 1);

	return 0;
}

static int sprd_gpio_plus_free(struct udevice *dev, u32 offset)
{
	sprd_gpio_plus_update(dev, GPIO_CRL(offset), BIT_GPIO_ENABLE, 0);

	return 0;
}

static int sprd_gpio_plus_direction_input(struct udevice *dev, u32 offset)
{
	sprd_gpio_plus_update(dev, GPIO_CRL(offset), BIT_GPIO_DIR, 0);

	return 0;
}

static int sprd_gpio_plus_direction_output(struct udevice *dev,
					   u32 offset, int value)
{
	sprd_gpio_plus_update(dev, GPIO_CRL(offset), BIT_GPIO_DIR, 1);
	sprd_gpio_plus_update(dev, GPIO_CRL(offset), BIT_GPIO_DATA, !!value);

	return 0;
}

static int sprd_gpio_plus_get_value(struct udevice *dev, u32 offset)
{
	return sprd_gpio_plus_read(dev, GPIO_CRL(offset), BIT_GPIO_DATA);
}

static int sprd_gpio_plus_set_value(struct udevice *dev, u32 offset, int value)
{
	sprd_gpio_plus_update(dev, GPIO_CRL(offset), BIT_GPIO_DATA, !!value);

	return 0;
}

static const struct dm_gpio_ops sprd_gpio_plus_ops = {
	.request		= sprd_gpio_plus_request,
	.free			= sprd_gpio_plus_free,
	.direction_input	= sprd_gpio_plus_direction_input,
	.direction_output	= sprd_gpio_plus_direction_output,
	.get_value		= sprd_gpio_plus_get_value,
	.set_value		= sprd_gpio_plus_set_value,
};

static int sprd_gpio_plus_probe(struct udevice *dev)
{
	struct gpio_dev_priv *uc_priv = dev_get_uclass_priv(dev);

	/* Tell the uclass how many GPIOs we have */
	uc_priv->gpio_count = SPRD_GPIO_PLUS_NR;
	uc_priv->bank_name = fdt_getprop(gd->fdt_blob, dev_of_offset(dev),
				"gpio-bank-name", NULL);

	dev->priv = dev_read_addr_ptr(dev);

	return 0;
}

static const struct udevice_id sprd_gpio_plus_ids[] = {
	{ .compatible = "sprd,sharkl3-gpio-plus" },
	{ }
};

U_BOOT_DRIVER(gpio_sprd) = {
	.name	= "gpio_plus_sprd",
	.id	= UCLASS_GPIO,
	.of_match = sprd_gpio_plus_ids,
	.probe	= sprd_gpio_plus_probe,
	.ops	= &sprd_gpio_plus_ops,
};

