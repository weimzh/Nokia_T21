#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <malloc.h>
#include <spi.h>
#include <asm/errno.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include <asm-generic/gpio.h>
#include <dt-bindings/gpio/gpio.h>

/* EIC registers definition */
#define SPRD_PMIC_EIC_DATA		0x0
#define SPRD_PMIC_EIC_DMSK		0x4

#define SPRD_PMIC_EIC_NR		16
#define SPRD_PMIC_EIC_BIT(x)		((x) & (SPRD_PMIC_EIC_NR - 1))

struct sprd_pmic_eic_priv {
	u32 reg_base;
};

static int sprd_pmic_eic_update(struct udevice *dev, u32 offset,
				 u16 reg, int value)
{
	u32 reg_addr, reg_val;
	u32 shift = SPRD_PMIC_EIC_BIT(offset);
	struct sprd_pmic_eic_priv *priv = dev_get_priv(dev);
	int ret;

	reg_addr = priv->reg_base + reg;
	ret = pmic_read(dev->parent, reg_addr, (uint8_t *)&reg_val, 0);
	if (ret) {
		dev_err(dev, "pmic read fail, %d\n", ret);
		return ret;
	}

	reg_addr = priv->reg_base + reg;
	if (value)
		reg_val = BIT(shift) | reg_val;
	else
		reg_val = ~BIT(shift) & reg_val;

	ret = pmic_write(dev->parent, reg_addr, (uint8_t *)&reg_val, 0);
	if (ret)
		dev_err(dev, "pmic write fail, %d\n", ret);

	return ret;
}

static int sprd_pmic_eic_read(struct udevice* dev, u32 offset, u16 reg)
{
	struct sprd_pmic_eic_priv *priv = dev_get_priv(dev);
	u32 reg_addr = priv->reg_base + reg;
	u32 reg_val;
	int ret;

	ret = pmic_read(dev->parent, reg_addr, (uint8_t *)&reg_val, 0);
	if (ret) {
		dev_err(dev, "pmic read fail, %d\n", ret);
		return ret;
	}

	return !!(reg_val & BIT(SPRD_PMIC_EIC_BIT(offset)));
}

static int sprd_pmic_eic_request(struct udevice *dev, u32 offset,
				 const char *label)
{
	return sprd_pmic_eic_update(dev, offset, SPRD_PMIC_EIC_DMSK, 1);
}

static int sprd_pmic_eic_free(struct udevice *dev, u32 offset)
{
	return sprd_pmic_eic_update(dev, offset, SPRD_PMIC_EIC_DMSK, 0);
}

static int sprd_pmic_eic_get_value(struct udevice *dev, u32 offset)
{
	return sprd_pmic_eic_read(dev, offset, SPRD_PMIC_EIC_DATA);
}

static int sprd_pmic_eic_direction_input(struct udevice *dev, u32 offset)
{
	/* no need to realize, but need to define a dummy function if
	 * configure input flags
	 */
	return 0;
}

static const struct dm_gpio_ops sprd_pmic_eic_ops = {
	.request		= sprd_pmic_eic_request,
	.free			= sprd_pmic_eic_free,
	.get_value		= sprd_pmic_eic_get_value,
	.direction_input        = sprd_pmic_eic_direction_input,
};

static int sprd_pmic_eic_probe(struct udevice *dev)
{
	struct sprd_pmic_eic_priv *priv;

	struct gpio_dev_priv *uc_priv = dev_get_uclass_priv(dev);

	/* Tell the uclass how many PMIC EICs we have */
	uc_priv->gpio_count = SPRD_PMIC_EIC_NR;
	uc_priv->bank_name = fdt_getprop(gd->fdt_blob, dev_of_offset(dev),
				"gpio-bank-name", NULL);

	priv = (struct sprd_pmic_eic_priv *)dev_get_priv(dev);

	priv->reg_base = dev_read_addr(dev);

	return 0;
}

static const struct udevice_id sprd_pmic_eic_ids[] = {
	{ .compatible = "sprd,sc2731-eic" },
	{ }
};

U_BOOT_DRIVER(pmic_eic_sprd) = {
	.name	= "pmic_eic_sprd",
	.id	= UCLASS_GPIO,
	.of_match = sprd_pmic_eic_ids,
	.probe	= sprd_pmic_eic_probe,
	.ops	= &sprd_pmic_eic_ops,
	.priv_auto_alloc_size = sizeof(struct sprd_pmic_eic_priv),
};
