#include <common.h>
#include <dm.h>
#include <asm/arch/hardware.h>
#include <asm/io.h>
#include <clk.h>
#include <asm/arch/sprd_reg.h>
#include <boot_mode.h>

#define NUM_PWM		4
#define PWM_REGS_SHIFT	14
#define PWM_PRESCALE	(0x0000)
#define PWM_MOD		(0x0004)
#define PWM_DUTY	(0x0008)
#define PWM_DIV		(0x000c)
#define PWM_PAT_LOW	(0x0010)
#define PWM_PAT_HIGH	(0x0014)
#define PWM_ENABLE	(0x0018)
#define PWM_VERSION	(0x001c)

#define PWM_REG_MSK	0xffff
#define PWM_CLK_PARENT	"clk_parent"
#define PWM_CLK		"clk_pwm"
struct pwm_sprd_priv {
	struct clk clk_source;
	struct clk clk_pwm[NUM_PWM];
	struct clk clk_eb[NUM_PWM];
	void *base;
};
static struct pwm_sprd_priv *priv = NULL;
static int probe_flag = 0;

static inline uint32_t pwm_read(int index, uint32_t reg)
{
	return __raw_readl(priv->base + (index << PWM_REGS_SHIFT) + reg);
}

static void pwm_write(int index, uint32_t value, uint32_t reg)
{
	__raw_writel(value, priv->base + (index << PWM_REGS_SHIFT) + reg);
}

static void __raw_bits_or(unsigned int v, unsigned int a)
{
	__raw_writel((__raw_readl(a) | v), a);
}

int pwm_config(int pwm_id,int duty,int period)
{
#ifdef CONFIG_DM
	if(!probe_flag) {
		struct udevice *pwm = NULL;
		uclass_get_device(UCLASS_PWM, 0, &pwm);
        }
#endif

	if(!probe_flag) {
		dev_err(priv->udev, "pwm get data failed!\n");
		return -1;
	}

	int index = pwm_id;
	int ret = 0;

	ret = clk_set_parent(&priv->clk_pwm[index], &priv->clk_source);//ext_26m select
	if(ret) {
		dev_err(priv->udev, "pwm select clk failed!\n");
		return ret;
	}

	ret = clk_enable(&priv->clk_eb[index]);//PWMx EN
	if(ret) {
		dev_err(priv->udev, "pwm set clk failed!\n");
		return ret;
	}

	if (0 == duty) {
		pwm_write(index, 0, PWM_ENABLE);
		dev_info(priv->udev, "pwm sprd backlight power off. pwm_index=%d  duty=%d\n", index, duty);
	} else {
		pwm_write(index, period, PWM_MOD);
		pwm_write(index, duty, PWM_DUTY);
		pwm_write(index, PWM_REG_MSK, PWM_PAT_LOW);
		pwm_write(index, PWM_REG_MSK, PWM_PAT_HIGH);
		pwm_write(index, 1, PWM_ENABLE);
		dev_info(priv->udev, "pwm sprd backlight power on. pwm_index=%d  brightness=%d\n", index, duty);
	}

	return 0;
}

#ifdef CONFIG_DM
static int pwm_sprd_ofdata_to_platdata(struct udevice *dev)
{
	int ret;
	char clk_name[64];
	int i;

	priv = dev_get_priv(dev);
	if (priv == NULL)
		return -ENOMEM;

	dev_info(dev, "pwm_ofdata_to_platdata\n");

	priv->base = dev_read_addr_ptr(dev);

	ret = clk_get_by_name(dev, PWM_CLK_PARENT, &priv->clk_source);
	if (ret) {
		dev_err(dev, "Can't get clk_parent: %d\n", ret);
		return ret;
	}

	for (i = 0; i < NUM_PWM; i++) {
		memset(clk_name, 0, sizeof(clk_name));
		snprintf(clk_name, sizeof(clk_name) - 1, PWM_CLK"%d", i);
		ret = clk_get_by_name(dev, clk_name, &priv->clk_pwm[i]);
		if (ret) {
			dev_err(dev, "Can't get %s clock\n", clk_name);
			return ret;
		}

		memset(clk_name, 0, sizeof(clk_name));
		snprintf(clk_name, sizeof(clk_name) - 1, PWM_CLK"%d_eb", i);
		ret = clk_get_by_name(dev, clk_name, &priv->clk_eb[i]);
		if (ret) {
			dev_err(dev, "Can't get %s clock\n", clk_name);
			return ret;
		}
	}

	probe_flag = 1;
	return 0;
}

static int pwm_sprd_probe(struct udevice *dev)
{
	dev_info(priv->udev, "pwm_sprd_probe\n");
	return 0;
}

static const struct udevice_id pwm_sprd_ids[] = {
	{ .compatible = "qogirn6pro-pwm-sprd" },
	{ }
};

U_BOOT_DRIVER(pwm_sprd) = {
	.name = "pwm_sprd",
	.id = UCLASS_PWM,
	.of_match = pwm_sprd_ids,
	.ofdata_to_platdata = pwm_sprd_ofdata_to_platdata,
	.probe = pwm_sprd_probe,
	.priv_auto_alloc_size = sizeof(struct pwm_sprd_priv),
};

UCLASS_DRIVER(sprd_pwm) = {
	.id = UCLASS_PWM,
	.name = "sprd_pwm",
};
#endif
