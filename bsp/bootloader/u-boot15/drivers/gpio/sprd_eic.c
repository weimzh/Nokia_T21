#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <malloc.h>
#include <asm/errno.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include <asm-generic/gpio.h>
#include <dt-bindings/gpio/gpio.h>

/* EIC registers definition */
#define SPRD_EIC_DBNC_DATA		0x0
#define SPRD_EIC_DBNC_DMSK		0x4

#define SPRD_EIC_MAX_BANK		8
#define SPRD_EIC_PER_BANK_NR		8
#define SPRD_EIC_NR			64
#define SPRD_EIC_BIT(x)			((x) & (SPRD_EIC_PER_BANK_NR - 1))

struct sprd_eic_priv {
	void __iomem *reg_base[SPRD_EIC_MAX_BANK];
};

static inline void __iomem *sprd_eic_bank_base(struct sprd_eic_priv *priv,
					       u32 bank)
{
	return priv->reg_base[bank];
}

static void sprd_eic_update(struct sprd_eic_priv *priv, u32 offset,
			    u16 reg, int value)
{
	void __iomem *base = sprd_eic_bank_base(priv, offset / SPRD_EIC_PER_BANK_NR);
	u32 tmp;

	tmp = __raw_readl(base + reg);

	if (value)
		tmp |= BIT(SPRD_EIC_BIT(offset));
	else
		tmp &= ~BIT(SPRD_EIC_BIT(offset));

	__raw_writel(tmp, base + reg);
}

static int sprd_eic_read(struct sprd_eic_priv *priv, u32 offset, u16 reg)
{
	void __iomem *base = sprd_eic_bank_base(priv, offset / SPRD_EIC_PER_BANK_NR);

	return !!(__raw_readl(base + reg) & BIT(SPRD_EIC_BIT(offset)));
}

static int sprd_eic_request(struct udevice *dev, u32 offset, const char *label)
{
	struct sprd_eic_priv *priv = dev_get_priv(dev);

	sprd_eic_update(priv, offset, SPRD_EIC_DBNC_DMSK, 1);

	return 0;
}

static int sprd_eic_free(struct udevice *dev, u32 offset)
{
	struct sprd_eic_priv *priv = dev_get_priv(dev);

	sprd_eic_update(priv, offset, SPRD_EIC_DBNC_DMSK, 0);

	return 0;
}

static int sprd_eic_direction_input(struct udevice *dev, u32 offset)
{
	/* no need to realize, but need to define a dummy function if configure
	 * input flags
	 */
	return 0;
}

static int sprd_eic_get_value(struct udevice *dev, u32 offset)
{
	struct sprd_eic_priv *priv = dev_get_priv(dev);

	return sprd_eic_read(priv, offset, SPRD_EIC_DBNC_DATA);
}

static const struct dm_gpio_ops sprd_eic_ops = {
	.request		= sprd_eic_request,
	.free			= sprd_eic_free,
	.get_value		= sprd_eic_get_value,
	.direction_input	= sprd_eic_direction_input,
};

static int sprd_eic_probe(struct udevice *dev)
{
	struct gpio_dev_priv *uc_priv = dev_get_uclass_priv(dev);
	struct sprd_eic_priv *priv;
	int i;

	/* Tell the uclass how many EICs we have */
	uc_priv->gpio_count = SPRD_EIC_NR;
	uc_priv->bank_name = fdt_getprop(gd->fdt_blob, dev_of_offset(dev),
				"gpio-bank-name", NULL);

	priv = calloc(1, sizeof(*priv));
	if (!priv) {
		dev_err(dev, "calloc eic private data failed.\n");
		return -ENOMEM;
	}

	for (i = 0; i < SPRD_EIC_MAX_BANK; i++) {
		priv->reg_base[i] = dev_read_addr_index(dev, i);
		if (priv->reg_base[i] == FDT_ADDR_T_NONE)
			break;
	}

	dev->priv = priv;

	return 0;
}

static const struct udevice_id sprd_eic_ids[] = {
	{ .compatible = "sprd,pike2-eic-debounce" },
	{ }
};

U_BOOT_DRIVER(eic_sprd) = {
	.name	= "eic_sprd",
	.id	= UCLASS_GPIO,
	.of_match = sprd_eic_ids,
	.probe	= sprd_eic_probe,
	.ops	= &sprd_eic_ops,
	.priv_auto_alloc_size = sizeof(struct sprd_eic_priv),
};
