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
#define SPRD_GPIO_DATA		0x0
#define SPRD_GPIO_DMSK		0x4
#define SPRD_GPIO_DIR		0x8
#define SPRD_GPIO_INEN		0x28

#define SPRD_GPIO_NR		256
#define SPRD_GPIO_BANK_NR	16
#define SPRD_GPIO_BANK_SIZE	0x80
#define SPRD_GPIO_BIT(x)	((x) & (SPRD_GPIO_BANK_NR - 1))

static inline void __iomem *sprd_gpio_bank_base(struct udevice *dev,
						u32 bank)
{
	return dev->priv + SPRD_GPIO_BANK_SIZE * bank;
}

static void sprd_gpio_update(struct udevice *dev,
			     u32 offset, u16 reg, int value)
{
	void __iomem *base = sprd_gpio_bank_base(dev, offset / SPRD_GPIO_BANK_NR);
	u32 tmp;

	tmp = __raw_readl(base + reg);

	if (value)
		tmp |= BIT(SPRD_GPIO_BIT(offset));
	else
		tmp &= ~BIT(SPRD_GPIO_BIT(offset));

	__raw_writel(tmp, base + reg);
}

static int sprd_gpio_read(struct udevice *dev, u32 offset, u16 reg)
{
	void __iomem *base = sprd_gpio_bank_base(dev, offset / SPRD_GPIO_BANK_NR);

	return !!(__raw_readl(base + reg) & BIT(SPRD_GPIO_BIT(offset)));
}

static int sprd_gpio_request(struct udevice *dev, u32 offset, const char *label)
{
	sprd_gpio_update(dev, offset, SPRD_GPIO_DMSK, 1);

	return 0;
}

static int sprd_gpio_free(struct udevice *dev, u32 offset)
{
	sprd_gpio_update(dev, offset, SPRD_GPIO_DMSK, 0);

	return 0;
}

static int sprd_gpio_direction_input(struct udevice *dev, u32 offset)
{
	sprd_gpio_update(dev, offset, SPRD_GPIO_DIR, 0);
	sprd_gpio_update(dev, offset, SPRD_GPIO_INEN, 1);

	return 0;
}

static int sprd_gpio_direction_output(struct udevice *dev, u32 offset,
				      int value)
{
	sprd_gpio_update(dev, offset, SPRD_GPIO_DIR, 1);
	sprd_gpio_update(dev, offset, SPRD_GPIO_INEN, 0);
	sprd_gpio_update(dev, offset, SPRD_GPIO_DATA, !!value);

	return 0;
}

static int sprd_gpio_get_value(struct udevice *dev, u32 offset)
{
	return sprd_gpio_read(dev, offset, SPRD_GPIO_DATA);
}

static int sprd_gpio_set_value(struct udevice *dev, u32 offset,
			       int value)
{
	sprd_gpio_update(dev, offset, SPRD_GPIO_DATA, !!value);

	return 0;
}

static const struct dm_gpio_ops sprd_gpio_ops = {
	.request		= sprd_gpio_request,
	.free			= sprd_gpio_free,
	.direction_input	= sprd_gpio_direction_input,
	.direction_output	= sprd_gpio_direction_output,
	.get_value		= sprd_gpio_get_value,
	.set_value		= sprd_gpio_set_value,
};

static int sprd_gpio_probe(struct udevice *dev)
{
	struct gpio_dev_priv *uc_priv = dev_get_uclass_priv(dev);

	/* Tell the uclass how many GPIOs we have */
	uc_priv->gpio_count = SPRD_GPIO_NR;
	uc_priv->bank_name = fdt_getprop(gd->fdt_blob, dev_of_offset(dev),
				"gpio-bank-name", NULL);

	dev->priv = dev_read_addr_ptr(dev);

	return 0;
}

static const struct udevice_id sprd_gpio_ids[] = {
	{ .compatible = "sprd,pike2-gpio" },
	{ }
};

U_BOOT_DRIVER(gpio_sprd) = {
	.name	= "gpio_sprd",
	.id	= UCLASS_GPIO,
	.of_match = sprd_gpio_ids,
	.probe	= sprd_gpio_probe,
	.ops	= &sprd_gpio_ops,
};
