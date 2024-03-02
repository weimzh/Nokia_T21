/*
 * Copyright (C) 2019 Spreadtrum Communications Inc.
 */

#include <asm-generic/errno.h>
#include <asm/types.h>
#include <asm/arch/sprd_reg.h>
#include <common.h>
#include <misc.h>
#include <dm/device.h>
#include <dm/read.h>
#include <dm/uclass.h>
#include <dm/uclass-id.h>
#include <power/pmic.h>
#include <spi.h>

/* ADC controller registers definition */
#define SC27XX_ADC_CTL			0x0
#define SC27XX_ADC_CH_CFG		0x4
#define SC27XX_ADC_DATA			0x4c
#define SC27XX_ADC_INT_EN		0x50
#define SC27XX_ADC_INT_CLR		0x54
#define SC27XX_ADC_INT_STS		0x58
#define SC27XX_ADC_INT_RAW		0x5c
#define SC27XX_ADC_CTL0                 0xac
#define SC27XX_ADC_CTL1                 0xb0

/* Bits and mask definition for SC27XX_ADC_CTL register */
#define SC27XX_ADC_EN			BIT(0)
#define SC27XX_ADC_CHN_RUN		BIT(1)
#define SC27XX_ADC_12BIT_MODE		BIT(2)
#define SC2720_ADC_OFFSET_CAL_EN	BIT(12)
#define SC2720_ADC_AVERAGE(x)		(((x) & 0x7) << 8)
#define SC27XX_ADC_SW_CH_NUM(x)		((((x) - 1) & 0xF ) << 4)
#define SC27XX_SW_CH_NUM_MSK		0xf0
#define SC27XX_ADC_RUN_NUM_SHIFT	4

/* Bits and mask definition for SC27XX_ADC_CH_CFG register */
#define SC27XX_ADC_CHN_ID_MASK		0x1f
#define SC27XX_ADC_SCALE_MASK		0x600
#define SC2721_ADC_SCALE_MASK		BIT(5)
#define SC27XX_ADC_SCALE_SHIFT		9
#define SC2721_ADC_SCALE_SHIFT		5

/* Bits definitions for SC27XX_ADC_INT_EN registers */
#define SC27XX_ADC_IRQ_EN		BIT(0)

/* Bits definitions for SC27XX_ADC_INT_CLR registers */
#define SC27XX_ADC_IRQ_CLR		BIT(0)

/* Bits definitions for SC27XX_ADC_INT_RAW registers */
#define SC27XX_ADC_IRQ_RAW		BIT(0)

/* Mask definition for SC27XX_ADC_DATA register */
#define SC27XX_ADC_DATA_MASK             0xfff

/* Bits definitions for SC27XX_ADC_CTL0 registers */
#define SC27XX_ADC_CUR_EN          BIT(0)

/* Bits definitions for SC27XX_ADC_CTL1 registers */
#define SC2721_AUXAD_NTC_MUX(x)      (((x) & 0x3) << 0)

/* ADC voltage ratio definition */
#define SC27XX_VOLT_RATIO(n, d)		\
	(((n) << SC27XX_RATIO_NUMERATOR_OFFSET) | (d))
#define SC27XX_RATIO_NUMERATOR_OFFSET	16
#define SC27XX_RATIO_DENOMINATOR_MASK	0xffff
#define SC27XX_CURRENT_CHANNEL		3
#define SC27XX_CURRENT_ISEN		2000

/* ADC calibration efuse block */
#define SC27XX_SMALL_CAL_BLK		19
#define SC27XX_BIG_CAL_BLK		18
#define SC27XX_ADC_CHAN_MAX 		32

/* workround: Currently, udelay does not implement the interface
 * according to the uboot framework, and temporarily uses the
 * interface tmr_udelay.
 */
extern void tmr_udelay (unsigned long usec);

struct sc27xx_adc_linear_graph {
	int volt0;
	int adc0;
	int volt1;
	int adc1;
};

enum sc27xx_adc_type {
	SC2721_ADC,
	SC2720_ADC,
	SC2730_ADC,
};

/*
 * Since different PMICs of SC27xx series can have different
 * address and ratio, we should save ratio config and base
 * in the device data structure.
 */
struct sc27xx_adc_variant_data {
	u32 scale_shift;
	u32 scale_mask;
	const struct sc27xx_adc_linear_graph *bscale_cal;
	const struct sc27xx_adc_linear_graph *sscale_cal;
	void (*init_scale)(struct sc27xx_adc *data);
	int (*get_ratio)(int channel, int scale);
};

struct sc27xx_adc {
	enum sc27xx_adc_type type;
	const struct sc27xx_adc_variant_data *var;
	struct udevice *dev;
	int channel_scale[SC27XX_ADC_CHAN_MAX];
	u32 base;
};

/*
 * According to the datasheet, we can convert one ADC value to one voltage value
 * through 2 points in the linear graph. If the voltage is less than 1.2v, we
 * should use the small-scale graph, and if more than 1.2v, we should use the
 * big-scale graph.
 */
static struct sc27xx_adc_linear_graph big_scale_graph = {
	4200, 3310,
	3600, 2832,
};

static struct sc27xx_adc_linear_graph small_scale_graph = {
	1000, 3413,
	100, 341,
};

static const struct sc27xx_adc_linear_graph sc2721_big_scale_graph_calib = {
	4200, 850,
	3600, 728,
};

static const struct sc27xx_adc_linear_graph sc2721_small_scale_graph_calib = {
	1000, 838,
	100, 84,
};

static const struct sc27xx_adc_linear_graph sc2720_big_scale_graph_calib = {
	4200, 856,
	3600, 733,
};

static const struct sc27xx_adc_linear_graph sc2720_small_scale_graph_calib = {
	1000, 833,
	100, 80,
};

static int sc27xx_adc_reg_read(struct udevice *dev, u32 offset, u32 *value)
{
	u32 tmp;
	int ret;

	ret = pmic_read(dev->parent, offset, (uint8_t *)&tmp, sizeof(tmp));
	if (ret) {
		dev_err(dev, "uboot sc27xx adc get fail, ret is %d\n", ret);
		return ret;
	}

	*value = tmp;

	return 0;
}

static int sc27xx_adc_reg_update_bits(struct udevice *dev, u32 reg, u32 clr, u32 set)
{
	return pmic_clrsetbits(dev->parent, reg, clr, set);
}

static int sc27xx_adc_get_calib_data(u32 calib_data, int calib_adc)
{
	return ((calib_data & 0xff) + calib_adc - 128) * 4;
}

static int sc27xx_adc_get_efuse(u32 blk, u32 *val)
{
	struct udevice *dev;
	int ret;

	ret = uclass_get_device_by_driver(UCLASS_MISC, DM_GET_DRIVER(pmic_efuse), &dev);
	if (ret)
		return ret;

	return misc_read(dev, blk, val, 16);
}

static int sc27xx_adc_scale_calibration(struct sc27xx_adc *adc,
					bool big_scale)
{
	const struct sc27xx_adc_linear_graph *calib_graph;
	struct sc27xx_adc_linear_graph *graph;
	u32 blk, calib_data = 0;
	int ret;

	if (big_scale) {
		calib_graph = adc->var->bscale_cal;
		graph = &big_scale_graph;
		blk = SC27XX_BIG_CAL_BLK;
	} else {
		calib_graph = adc->var->sscale_cal;
		graph = &small_scale_graph;
		blk = SC27XX_SMALL_CAL_BLK;
	}

	ret = sc27xx_adc_get_efuse(blk, &calib_data);
	if (ret)
		return ret;
	/* Only need to calibrate the adc values in the linear graph. */
	graph->adc0 = sc27xx_adc_get_calib_data(calib_data, calib_graph->adc0);
	graph->adc1 = sc27xx_adc_get_calib_data(calib_data >> 8, calib_graph->adc1);

	return 0;
}

static void sc27xx_adc_volt_ratio(struct sc27xx_adc *adc,
				  int channel, int scale,
				  u32 *div_numerator, u32 *div_denominator)
{
	u32 ratio;

	ratio = adc->var->get_ratio(channel, scale);
	*div_numerator = ratio >> SC27XX_RATIO_NUMERATOR_OFFSET;
	*div_denominator = ratio & SC27XX_RATIO_DENOMINATOR_MASK;
}

static int sc27xx_adc_to_volt(struct sc27xx_adc_linear_graph *graph,
			      int raw_adc)
{
	int tmp;

	tmp = (graph->volt0 - graph->volt1) * (raw_adc - graph->adc1);
	tmp /= (graph->adc0 - graph->adc1);
	tmp += graph->volt1;

	return tmp < 0 ? 0 : tmp;
}

static int sc2721_adc_get_ratio(int channel, int scale)
{
	switch (channel) {
	case 1:
	case 2:
	case 3:
	case 4:
		return scale ? SC27XX_VOLT_RATIO(400, 1025) :
			SC27XX_VOLT_RATIO(1, 1);
	case 5:
		return SC27XX_VOLT_RATIO(7, 29);
	case 7:
	case 9:
		return scale ? SC27XX_VOLT_RATIO(100, 125) :
			SC27XX_VOLT_RATIO(1, 1);
	case 14:
		return SC27XX_VOLT_RATIO(68, 900);
	case 16:
		return SC27XX_VOLT_RATIO(48, 100);
	case 19:
		return SC27XX_VOLT_RATIO(1, 3);
	default:
		return SC27XX_VOLT_RATIO(1, 1);
	}
	return SC27XX_VOLT_RATIO(1, 1);
}

static int sc2720_adc_get_ratio(int channel, int scale)
{
	switch (channel) {
	case 14:
		switch (scale) {
		case 0:
			return SC27XX_VOLT_RATIO(68, 900);
		case 1:
			return SC27XX_VOLT_RATIO(68, 1760);
		case 2:
			return SC27XX_VOLT_RATIO(68, 2327);
		case 3:
			return SC27XX_VOLT_RATIO(68, 3654);
		default:
			return SC27XX_VOLT_RATIO(1, 1);
		}
	case 16:
		switch (scale) {
		case 0:
			return SC27XX_VOLT_RATIO(48, 100);
		case 1:
			return SC27XX_VOLT_RATIO(480, 1955);
		case 2:
			return SC27XX_VOLT_RATIO(480, 2586);
		case 3:
			return SC27XX_VOLT_RATIO(48, 406);
		default:
			return SC27XX_VOLT_RATIO(1, 1);
		}
	case 21:
	case 22:
	case 23:
		switch (scale) {
		case 0:
			return SC27XX_VOLT_RATIO(3, 8);
		case 1:
			return SC27XX_VOLT_RATIO(375, 1955);
		case 2:
			return SC27XX_VOLT_RATIO(375, 2586);
		case 3:
			return SC27XX_VOLT_RATIO(300, 3248);
		default:
			return SC27XX_VOLT_RATIO(1, 1);
		}
	default:
		switch (scale) {
		case 0:
			return SC27XX_VOLT_RATIO(1, 1);
		case 1:
			return SC27XX_VOLT_RATIO(1000, 1955);
		case 2:
			return SC27XX_VOLT_RATIO(1000, 2586);
		case 3:
			return SC27XX_VOLT_RATIO(100, 406);
		default:
			return SC27XX_VOLT_RATIO(1, 1);
		}
	}
	return SC27XX_VOLT_RATIO(1, 1);
}

static int sc2730_adc_get_ratio(int channel, int scale)
{
	switch (channel) {
	case 14:
		switch (scale) {
		case 0:
			return SC27XX_VOLT_RATIO(68, 900);
		case 1:
			return SC27XX_VOLT_RATIO(68, 1760);
		case 2:
			return SC27XX_VOLT_RATIO(68, 2327);
		case 3:
			return SC27XX_VOLT_RATIO(68, 3654);
		default:
			return SC27XX_VOLT_RATIO(1, 1);
		}
	case 15:
		switch (scale) {
		case 0:
			return SC27XX_VOLT_RATIO(1, 3);
		case 1:
			return SC27XX_VOLT_RATIO(1000, 5865);
		case 2:
			return SC27XX_VOLT_RATIO(500, 3879);
		case 3:
			return SC27XX_VOLT_RATIO(500, 6090);
		default:
			return SC27XX_VOLT_RATIO(1, 1);
		}
	case 16:
		switch (scale) {
		case 0:
			return SC27XX_VOLT_RATIO(48, 100);
		case 1:
			return SC27XX_VOLT_RATIO(480, 1955);
		case 2:
			return SC27XX_VOLT_RATIO(480, 2586);
		case 3:
			return SC27XX_VOLT_RATIO(48, 406);
		default:
			return SC27XX_VOLT_RATIO(1, 1);
		}
	case 21:
	case 22:
	case 23:
		switch (scale) {
		case 0:
			return SC27XX_VOLT_RATIO(3, 8);
		case 1:
			return SC27XX_VOLT_RATIO(375, 1955);
		case 2:
			return SC27XX_VOLT_RATIO(375, 2586);
		case 3:
			return SC27XX_VOLT_RATIO(300, 3248);
		default:
			return SC27XX_VOLT_RATIO(1, 1);
		}
	default:
		switch (scale) {
		case 0:
			return SC27XX_VOLT_RATIO(1, 1);
		case 1:
			return SC27XX_VOLT_RATIO(1000, 1955);
		case 2:
			return SC27XX_VOLT_RATIO(1000, 2586);
		case 3:
			return SC27XX_VOLT_RATIO(1000, 4060);
		default:
			return SC27XX_VOLT_RATIO(1, 1);
		}
	}
	return SC27XX_VOLT_RATIO(1, 1);
}

static int sc27xx_adc_convert_volt(struct sc27xx_adc *adc, int channel,
				   int scale, int raw_adc)
{
	u32 numerator, denominator;
	u32 volt;

	/*
	 * Convert ADC values to voltage values according to the linear graph,
	 * and channel 5 and channel 1 has been calibrated, so we can just
	 * return the voltage values calculated by the linear graph. But other
	 * channels need be calculated to the real voltage values with the
	 * voltage ratio.
	 */
	switch (channel) {
	case 5:
		return sc27xx_adc_to_volt(&big_scale_graph, raw_adc);

	case 1:
		return sc27xx_adc_to_volt(&small_scale_graph, raw_adc);

	default:
		volt = sc27xx_adc_to_volt(&small_scale_graph, raw_adc);
		break;
	}

	sc27xx_adc_volt_ratio(adc, channel, scale, &numerator, &denominator);

	return (volt * denominator + numerator / 2) / numerator;
}

static int sc27xx_adc_read(struct udevice *dev, int chan, int scale, int *val)
{
	int ret, status = 0, count = 3000;
	u32 rawdata, tmp;
	struct sc27xx_adc *adc = dev_get_priv(dev);

	if (adc == NULL)
		return -EINVAL;

	ret = sc27xx_adc_reg_update_bits(dev, adc->base + SC27XX_ADC_INT_CLR,
					SC27XX_ADC_IRQ_CLR, SC27XX_ADC_IRQ_CLR);
	if (ret)
		return ret;

	/* Configure the channel id and scale */
	tmp = (scale << adc->var->scale_shift) & adc->var->scale_mask;
	tmp |= chan & SC27XX_ADC_CHN_ID_MASK;
	ret = sc27xx_adc_reg_update_bits(dev, adc->base + SC27XX_ADC_CH_CFG,
				 	SC27XX_ADC_CHN_ID_MASK |
				 	adc->var->scale_mask,
				 	tmp);
	if (ret)
		return ret;

	/* Select 12bit conversion mode, and only sample 1 time */
	tmp = SC27XX_ADC_12BIT_MODE;
	tmp |= (0 << SC27XX_ADC_RUN_NUM_SHIFT) & SC27XX_SW_CH_NUM_MSK;
	ret = sc27xx_adc_reg_update_bits(dev, adc->base + SC27XX_ADC_CTL,
				 	SC27XX_SW_CH_NUM_MSK | SC27XX_ADC_12BIT_MODE,
				 	tmp);
	if (ret)
		return ret;

	ret = sc27xx_adc_reg_update_bits(dev, adc->base + SC27XX_ADC_CTL,
				 	SC27XX_ADC_CHN_RUN, SC27XX_ADC_CHN_RUN);
	if (ret)
		return ret;

	/* wait adc complete */
	while (!status && count--) {
		sc27xx_adc_reg_read(dev, adc->base + SC27XX_ADC_INT_RAW, &status);
		status &= SC27XX_ADC_IRQ_RAW;
		tmr_udelay(10);
	}
	if (count <= 0) {
		dev_err(dev, "sc27xx adc read value timeout\n");
		return -ETIMEDOUT;
	}

	ret = sc27xx_adc_reg_read(dev, adc->base + SC27XX_ADC_DATA, &rawdata);
	rawdata &= SC27XX_ADC_DATA_MASK;
	if (!ret)
		*val = rawdata;

	return ret;
}

/*for sc2731/sc2721/2720 if set 1.25uA, parameter isen is 125uA */
static int sc27xx_adc_isen_set(int isen)
{
	int isen_set = 0;

	switch (isen) {
	case 125:
		isen_set = 0x0;
		break;
	case 250:
		isen_set = 0x1;
		break;
	case 500:
		isen_set = 0x2;
		break;
	case 1000:
		isen_set = 0x3;
		break;
	case 2000:
		isen_set = 0x4;
		break;
	case 4000:
		isen_set = 0x5;
		break;
	case 8000:
		isen_set = 0x6;
		break;
	case 16000:
		isen_set = 0x7;
		break;
	default:
		isen_set = 0x0;
		break;
	}
	return isen_set;
}

static int sc27xx_adc_set_current(struct udevice *dev, bool enable, int isen)
{
	int isen_bit, ret;
	struct sc27xx_adc *adc = dev_get_priv(dev);

	if (adc == NULL)
		return -EINVAL;

	if (enable) {
		isen_bit = sc27xx_adc_isen_set(isen);
		ret = sc27xx_adc_reg_update_bits(dev, ANA_REG_GLB_IB_CTRL,
						BIT_IB_REX_EN, 0);
		if (ret)
			return ret;

		ret = sc27xx_adc_reg_update_bits(dev, ANA_REG_GLB_IB_CTRL,
						BIT_BATDET_CUR_EN , BIT_BATDET_CUR_EN);
		if (ret)
			return ret;

		ret = sc27xx_adc_reg_update_bits(dev, ANA_REG_GLB_IB_CTRL,
						BITS_BATDET_CUR_I(isen_bit), BITS_BATDET_CUR_I(isen_bit));
		if (ret)
			return ret;
		tmr_udelay(150);

		ret = sc27xx_adc_reg_update_bits(dev, adc->base + SC27XX_ADC_CTL0,
						SC27XX_ADC_CUR_EN, SC27XX_ADC_CUR_EN);
	} else {

		ret = sc27xx_adc_reg_update_bits(dev, adc->base + SC27XX_ADC_CTL0,
						SC27XX_ADC_CUR_EN, 0);
		if (ret)
			return ret;

		ret = sc27xx_adc_reg_update_bits(dev, ANA_REG_GLB_IB_CTRL,
						BITS_BATDET_CUR_I(~0), 0);
		if (ret)
			return ret;

		ret = sc27xx_adc_reg_update_bits(dev, ANA_REG_GLB_IB_CTRL,
						BIT_BATDET_CUR_EN, 0);
	}

	return ret;
}

static int sc27xx_adc_get_rawdata_by_current(struct udevice *dev, int chan,
					    int scale, int isen, int *val)
{
	int ret;

	sc27xx_adc_set_current(dev, true, isen);
	ret = sc27xx_adc_read(dev, chan, scale, val);
	sc27xx_adc_set_current(dev, false, 0);

	return ret;
}

static int sc27xx_adc_init(struct sc27xx_adc *adc)
{
	int ret;

	/* ADC channel scales' calibration from nvmem device */
	ret = sc27xx_adc_scale_calibration(adc, true);
	if (ret)
		dev_err(adc->dev, "sc27xx adc big scale efuse cal error");

	ret = sc27xx_adc_scale_calibration(adc, false);
	if (ret)
		dev_err(adc->dev, "sc27xx adc small scale efuse cal error");

	ret = sc27xx_adc_reg_update_bits(adc->dev, ANA_REG_GLB_XTL_WAIT_CTRL,
					BIT_XTL_EN, BIT_XTL_EN);
	if (ret)
		return ret;

	ret = sc27xx_adc_reg_update_bits(adc->dev, ANA_REG_GLB_ARM_MODULE_EN,
					BIT_ANA_ADC_EN, BIT_ANA_ADC_EN);
	if (ret)
		return ret;

	ret = sc27xx_adc_reg_update_bits(adc->dev, ANA_REG_GLB_ARM_CLK_EN,
					BIT_CLK_AUXAD_EN | BIT_CLK_AUXADC_EN,
				   	BIT_CLK_AUXAD_EN | BIT_CLK_AUXADC_EN);
	if (ret)
		return ret;

	ret = sc27xx_adc_reg_update_bits(adc->dev, adc->base + SC27XX_ADC_CTL,
					SC27XX_ADC_EN | SC27XX_ADC_12BIT_MODE,
					SC27XX_ADC_EN | SC27XX_ADC_12BIT_MODE);
	if (ret)
		return ret;

	if (device_is_compatible(adc->dev->parent, "sprd,sc2721")) {
		ret = sc27xx_adc_reg_update_bits(adc->dev, adc->base + SC27XX_ADC_CTL1,
						SC2721_AUXAD_NTC_MUX(0x1),
						SC2721_AUXAD_NTC_MUX(0x1));
	} else {
		ret = sc27xx_adc_reg_update_bits(adc->dev, adc->base + SC27XX_ADC_CTL,
						SC2720_ADC_AVERAGE(~0) | SC2720_ADC_OFFSET_CAL_EN,
						SC2720_ADC_AVERAGE(0x3) | SC2720_ADC_OFFSET_CAL_EN);
	}

	return ret;
}

int sc27xx_adc_read_vol(struct udevice *dev, int chan, int *val, int size)
{
	struct sc27xx_adc *adc = dev_get_priv(dev);
	int ret, rawdata, scale;

	if (chan >= SC27XX_ADC_CHAN_MAX ) {
		dev_err(dev, "sc27xx adc channel invaild %d\n", chan);
		return -EINVAL;
	}
	scale = adc->channel_scale[chan];

	if (chan == SC27XX_CURRENT_CHANNEL)
		ret = sc27xx_adc_get_rawdata_by_current(dev, chan, scale, SC27XX_CURRENT_ISEN, &rawdata);
	else
		ret = sc27xx_adc_read(dev, chan, scale, &rawdata);
	if (ret)
		return ret;

	*val = sc27xx_adc_convert_volt(adc, chan, scale, rawdata);

	/* workround: The print log interface is not implemented according to the standard.
	 * debugf interface is temporarily used and can be modified after the interface
	 * is unified.
	 */
	debugf("sc27xx adc chan %d, rawdata %d, vol %d\n", chan, rawdata, *val);

	return 0;
}

int sc27xx_adc_read_current_vol(struct udevice *dev, int chan, int *val, int isen)
{
	struct sc27xx_adc *adc = dev_get_priv(dev);
	int ret, rawdata, scale;

	if (chan >= SC27XX_ADC_CHAN_MAX ) {
		dev_err(dev, "sc27xx adc channel invaild %d\n", chan);
		return -EINVAL;
	}
	scale = adc->channel_scale[chan];

	ret = sc27xx_adc_get_rawdata_by_current(dev, chan, scale, isen, &rawdata);
	if (ret)
		return ret;

	*val = sc27xx_adc_convert_volt(adc, chan, scale, rawdata);
	/* workround: The print log interface is not implemented according to the standard.
	 * debugf interface is temporarily used and can be modified after the interface
	 * is unified.
	 */
	debugf("sc27xx adc chan %d, isen %d, rawdata %d, vol %d\n", chan, isen, rawdata, *val);

	return 0;
}

static void sc2720_adc_scale_init(struct sc27xx_adc *data)
{
	int i;

	for (i = 0; i < SC27XX_ADC_CHAN_MAX; i++) {
		switch (i) {
		case 5:
			data->channel_scale[i] = 3;
			break;
		case 7:
		case 9:
			data->channel_scale[i] = 2;
			break;
		case 13:
			data->channel_scale[i] = 1;
			break;
		case 19:
		case 30:
		case 31:
			data->channel_scale[i] = 3;
			break;
		default:
			data->channel_scale[i] = 0;
			break;
		}
	}
}

static void sc2721_adc_scale_init(struct sc27xx_adc *data)
{
	int i;

	for (i = 0; i < SC27XX_ADC_CHAN_MAX; i++) {
		if (i == 5)
			data->channel_scale[i] = 1;
		else
			data->channel_scale[i] = 0;
	}
}

static void sc2730_adc_scale_init(struct sc27xx_adc *data)
{
	int i;

	for (i = 0; i < SC27XX_ADC_CHAN_MAX; i++) {
		if (i == 5 || i == 10 || i == 19 || i == 30 || i == 31)
			data->channel_scale[i] = 3;
		else if (i == 7 || i == 9)
			data->channel_scale[i] = 2;
		else if (i == 13)
			data->channel_scale[i] = 1;
		else
			data->channel_scale[i] = 0;
	}
}

static const struct sc27xx_adc_variant_data sc2721_data = {
	.scale_shift = SC2721_ADC_SCALE_SHIFT,
	.scale_mask = SC2721_ADC_SCALE_MASK,
	.bscale_cal = &sc2721_big_scale_graph_calib,
	.sscale_cal = &sc2721_small_scale_graph_calib,
	.init_scale = sc2721_adc_scale_init,
	.get_ratio = sc2721_adc_get_ratio,
};

static const struct sc27xx_adc_variant_data sc2720_data = {
	.scale_shift = SC27XX_ADC_SCALE_SHIFT,
	.scale_mask = SC27XX_ADC_SCALE_MASK,
	.bscale_cal = &sc2720_big_scale_graph_calib,
	.sscale_cal = &sc2720_small_scale_graph_calib,
	.init_scale = sc2720_adc_scale_init,
	.get_ratio = sc2720_adc_get_ratio,
};

static const struct sc27xx_adc_variant_data sc2730_data = {
	.scale_shift = SC27XX_ADC_SCALE_SHIFT,
	.scale_mask = SC27XX_ADC_SCALE_MASK,
	.bscale_cal = &sc2720_big_scale_graph_calib,
	.sscale_cal = &sc2720_small_scale_graph_calib,
	.init_scale = sc2730_adc_scale_init,
	.get_ratio = sc2730_adc_get_ratio,
};

static int sc27xx_adc_probe(struct udevice *dev)
{
	struct sc27xx_adc *adc;
	int ret;

	adc = (struct sc27xx_adc *)dev_get_priv(dev);
	if (adc == NULL)
		return -ENOMEM;

	if (device_is_compatible(dev->parent, "sprd,sc2721"))
		adc->var = &sc2721_data;
	else if (device_is_compatible(dev->parent, "sprd,sc2720"))
		adc->var = &sc2720_data;
	else if (device_is_compatible(dev->parent, "sprd,sc2730"))
		adc->var = &sc2730_data;
	else
		return -ENODEV;

	adc->base = (u32)dev_read_addr(dev);
	adc->dev = dev;
	adc->var->init_scale(adc);

	return sc27xx_adc_init(adc);
}

static const struct misc_ops sc27xx_adc_ops = {
	.read = sc27xx_adc_read_vol,
};

U_BOOT_DRIVER(pmic_adc) = {
	.name = "pmic_adc",
	.id = UCLASS_MISC,
	.ops = &sc27xx_adc_ops,
	.priv_auto_alloc_size = sizeof(struct sc27xx_adc),
	.probe = sc27xx_adc_probe,
};
