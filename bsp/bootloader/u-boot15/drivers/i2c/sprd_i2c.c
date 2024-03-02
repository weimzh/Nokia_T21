#include <common.h>
#include <errno.h>
#include <dm.h>
#include <fdtdec.h>
#include <asm/io.h>
#include <i2c.h>
#include <clk.h>
#include <dm/of_access.h>

#define I2C_CTL				0x000
#define I2C_ADDR_CFG			0x004
#define I2C_COUNT			0x008
#define I2C_RX				0x00C
#define I2C_TX				0x010
#define I2C_STATUS			0x014
#define I2C_HSMODE_CFG			0x018
#define I2C_VERSION			0x01C
#define ADDR_DVD0			0x020
#define ADDR_DVD1			0x024
#define ADDR_STA0_DVD			0x028
#define ADDR_RST			0x02C
#define CHNL_EN0			0x060
#define CHNL_EN1			0x064
#define CHNL2_ADDR			0X068

/* I2C_CTL */
#define STP_EN				BIT(20)
#define FIFO_AF_LVL			16
#define FIFO_AE_LVL			12
#define I2C_DMA_EN			BIT(11)
#define FULL_INTEN			BIT(10)
#define EMPTY_INTEN			BIT(9)
#define I2C_DVD_OPT			BIT(8)
#define I2C_OUT_OPT			BIT(7)
#define I2C_TRIM_OPT			BIT(6)
#define I2C_HS_MODE			BIT(4)
#define I2C_MODE			BIT(3)
#define I2C_EN				BIT(2)
#define I2C_INT_EN			BIT(1)
#define I2C_START			BIT(0)

/* I2C_STATUS */
#define SDA_IN				BIT(21)
#define SCL_IN				BIT(20)
#define FIFO_FULL			BIT(4)
#define FIFO_EMPTY			BIT(3)
#define I2C_INT				BIT(2)
#define I2C_RX_ACK			BIT(1)
#define I2C_BUSY			BIT(0)

/* ADDR_RST */
#define I2C_RST				BIT(0)

#define I2C_SRC_CLK			26000000
#define I2C_FIFO_DEEP			15
#define I2C_FIFO_FULL_THLD		8
#define I2C_FIFO_EMPTY_THLD		2
#define I2C_DATA_STEP			8

/* i2c Read/Write mode*/
#define I2C_WRITE_MODE	0
#define I2C_READ_MODE	1

#define I2C_TIMEOUT	1000
/* Absolutely safe for status update at 100 kHz I2C: */
#define I2C_WAIT	200

#define ADDR_DVD0_MASK	0xffff
#define ADDR_DVD1_MASK	0xffff0000

/*  i2c clock rate  */
#define I2C_SPEED_400K	400000
#define I2C_SPEED_100K	100000

/* hardware channel information */
#define CHNLX_ADDR(x)			(CHNL2_ADDR + (((x) - 2) << 2))
#define CHNL_GROUP0_SIZE		32
#define CHN_MAX_CNT			50
#define CHN_START			2

#define I2C_HW_SLAVE_ADDR_MASK	0xff00
#define I2C_HW_SLAVE_REG_MASK	0xff

struct sprd_i2c_bus {
	int node;	/* device tree node */
	int bus_num;	/* i2c bus number */
	u32 src_clk;	/* i2c source clock speed  */
	u32 clock_frequency;	/*  i2c bus speed */
	u8 *buf;
	u32 count;
	void __iomem *base;
	struct clk i2c_enable;
	struct i2c_msg *msg;
	struct udevice *udev;
};

static void sprd_i2c_dump_reg(struct sprd_i2c_bus *i2c_bus)
{
	dev_err(i2c_bus->udev, "=======i2c-%d %s dump=======\n", i2c_bus->bus_num,
			(readl(i2c_bus->base + I2C_CTL) & I2C_MODE) ? "Read" : "Write");
	dev_err(i2c_bus->udev, "I2C_CTL = 0x%x\n", readl(i2c_bus->base + I2C_CTL));
	dev_err(i2c_bus->udev, "I2C_ADDR_CFG = 0x%x\n", readl(i2c_bus->base + I2C_ADDR_CFG));
	dev_err(i2c_bus->udev, "I2C_COUNT = 0x%x\n", readl(i2c_bus->base + I2C_COUNT));
	dev_err(i2c_bus->udev, "I2C_STATUS = 0x%x\n", readl(i2c_bus->base + I2C_STATUS));
	dev_err(i2c_bus->udev, "ADDR_DVD0 = 0x%x\n", readl(i2c_bus->base + ADDR_DVD0));
	dev_err(i2c_bus->udev, "ADDR_DVD1 = 0x%x\n", readl(i2c_bus->base + ADDR_DVD1));
	dev_err(i2c_bus->udev, "ADDR_STA0_DVD = 0x%x\n", readl(i2c_bus->base + ADDR_STA0_DVD));
	dev_err(i2c_bus->udev, "ADDR_STA0_DVD = 0x%x\n", readl(i2c_bus->base + ADDR_STA0_DVD));
	dev_err(i2c_bus->udev, "slave address: 0x%x\n\n",
	       (readl(i2c_bus->base + I2C_ADDR_CFG)) >> 1 );
}

static int sprd_i2c_clk_enable(struct sprd_i2c_bus *i2c_bus)
{
	int ret;

	ret = clk_enable(&i2c_bus->i2c_enable);
	if (ret) {
		dev_err(i2c_bus->udev, "enable clock failed!\n");
		return ret;
	}

	return 0;
}

static int sprd_i2c_clk_disable(struct sprd_i2c_bus *i2c_bus)
{
	int ret;

	ret = clk_disable(&i2c_bus->i2c_enable);
	if(ret) {
		dev_err(i2c_bus->udev, "disable clock failed!\n");
		return ret;
	}

	return 0;
}

static void sprd_i2c_set_count(struct sprd_i2c_bus *i2c_bus, u32 count)
{
	writel(count, i2c_bus->base + I2C_COUNT);
}

static void sprd_i2c_send_stop(struct sprd_i2c_bus *i2c_bus, bool stop)
{
	u32 tmp = readl(i2c_bus->base + I2C_CTL);

	if (stop)
		writel(tmp & ~STP_EN, i2c_bus->base + I2C_CTL);
	else
		writel(tmp | STP_EN, i2c_bus->base + I2C_CTL);
}

static void sprd_i2c_clear_start(struct sprd_i2c_bus *i2c_bus)
{
	u32 tmp = readl(i2c_bus->base + I2C_CTL);

	writel(tmp & ~I2C_START, i2c_bus->base + I2C_CTL);
}

static void sprd_i2c_clear_ack(struct sprd_i2c_bus *i2c_bus)
{
	u32 tmp = readl(i2c_bus->base + I2C_STATUS);

	writel(tmp & ~I2C_RX_ACK, i2c_bus->base + I2C_STATUS);
}

static void sprd_i2c_clear_int(struct sprd_i2c_bus *i2c_bus)
{
	u32 tmp = readl(i2c_bus->base + I2C_STATUS);

	writel(tmp & ~I2C_INT, i2c_bus->base + I2C_STATUS);
}

static void sprd_i2c_reset_fifo(struct sprd_i2c_bus *i2c_bus)
{
	writel(I2C_RST, i2c_bus->base + ADDR_RST);
}

static void sprd_i2c_set_devaddr(struct sprd_i2c_bus *i2c_bus,
				 struct i2c_msg *m)
{
	writel(m->addr << 1, i2c_bus->base + I2C_ADDR_CFG);
}

static void sprd_i2c_write_bytes(struct sprd_i2c_bus *i2c_bus, u8 *buf, u32 len)
{
	u32 i;

	for (i = 0; i < len; i++)
		writel(buf[i], i2c_bus->base + I2C_TX);
}

static void sprd_i2c_read_bytes(struct sprd_i2c_bus *i2c_bus, u8 *buf, u32 len)
{
	u32 i;

	for (i = 0; i < len; i++)
		buf[i] = (u8)readl(i2c_bus->base + I2C_RX);
}

static void sprd_i2c_opt_start(struct sprd_i2c_bus *i2c_bus)
{
	u32 tmp = readl(i2c_bus->base + I2C_CTL);

	writel(tmp | I2C_START, i2c_bus->base + I2C_CTL);
}

static void sprd_i2c_opt_mode(struct sprd_i2c_bus *i2c_bus, int rw)
{
	u32 cmd = readl(i2c_bus->base + I2C_CTL) & ~I2C_MODE;

	writel((cmd | rw << 3), i2c_bus->base + I2C_CTL);
}

static int sprd_i2c_wait_for_int(struct sprd_i2c_bus *i2c_bus)
{
	int timeout = I2C_TIMEOUT;
	u32 status;

	do {
		udelay(I2C_WAIT);
		status = readl(i2c_bus->base + I2C_STATUS);
	} while (!(status & I2C_INT) && timeout--);

	if (timeout <= 0) {
		dev_err(i2c_bus->udev, "Timed out in wait_for_int: status=%04x\n",
			status);
		sprd_i2c_dump_reg(i2c_bus);
          	sprd_i2c_clear_start(i2c_bus);
		return -ETIMEDOUT;
	}

	status = readl(i2c_bus->base + I2C_STATUS);
	sprd_i2c_clear_int(i2c_bus);
	sprd_i2c_clear_ack(i2c_bus);
	sprd_i2c_clear_start(i2c_bus);

	return !!(status & I2C_RX_ACK) ? -1 : 0;
}

static int sprd_i2c_wait_for_fifo_empty(struct sprd_i2c_bus *i2c_bus)
{
	int timeout = I2C_TIMEOUT;
	int status = readl(i2c_bus->base + I2C_STATUS);

	while (!(status & FIFO_EMPTY) && timeout--) {
		udelay(1);
		status = readl(i2c_bus->base + I2C_STATUS);
	}
	return status;
}

static int sprd_wait_for_data_ready(struct sprd_i2c_bus *i2c_bus)
{
	int timeout = I2C_TIMEOUT;
	int status;

	do {
		udelay(I2C_WAIT);
		status = readl(i2c_bus->base + I2C_STATUS);
	} while (!((status & I2C_INT) || status & FIFO_FULL) && timeout--);

	if (timeout <= 0) {
		dev_err(i2c_bus->udev,
			"Timed out in wait_for_data_ready: status=%04x\n",
			status);
		sprd_i2c_dump_reg(i2c_bus->base);
		return -ETIMEDOUT;
	}

	return 0;
}

static void sprd_i2c_write_reg_addr(struct sprd_i2c_bus *i2c_bus, u8 *reg)
{
	sprd_i2c_write_bytes(i2c_bus,reg, 1);
}

static int sprd_i2c_read(struct sprd_i2c_bus *i2c_bus, struct i2c_msg *msg,
			 bool is_last_msg)
{
	int len = msg->len;
	int get_len = 0, ret = 0;
	u8 *buf = msg->buf;

	if (!buf) {
		dev_err(i2c_bus->udev, "I2C read: NULL pointer buffer\n");
		return -EINVAL;
	}

	sprd_i2c_reset_fifo(i2c_bus);
	sprd_i2c_set_devaddr(i2c_bus, msg);
	sprd_i2c_opt_mode(i2c_bus, I2C_READ_MODE);
	sprd_i2c_set_count(i2c_bus, len);
	sprd_i2c_send_stop(i2c_bus, !!is_last_msg);
	sprd_i2c_opt_start(i2c_bus);

	while (len) {
		ret = sprd_wait_for_data_ready(i2c_bus);
          	if (ret < 0)
                  return -EINVAL;

		get_len = len < I2C_FIFO_DEEP ? len : I2C_FIFO_DEEP;
		sprd_i2c_read_bytes(i2c_bus, buf, get_len);
		len -= get_len;
		msg->buf += get_len;
		sprd_i2c_clear_int(i2c_bus);
	}

	sprd_i2c_clear_start(i2c_bus);

	return ret;
}

static int sprd_i2c_write(struct sprd_i2c_bus *i2c_bus, struct i2c_msg *msg,
			  bool is_last_msg)
{
	int ret, send_len;
	int len = msg->len;

	sprd_i2c_reset_fifo(i2c_bus);
	sprd_i2c_set_devaddr(i2c_bus, msg);
	sprd_i2c_opt_mode(i2c_bus, I2C_WRITE_MODE);

	sprd_i2c_write_reg_addr(i2c_bus, (uchar *)&msg->buf[0]);
	msg->buf++;

	sprd_i2c_set_count(i2c_bus, len);
	sprd_i2c_send_stop(i2c_bus, !!is_last_msg);
	sprd_i2c_opt_start(i2c_bus);

	while (len) {
		send_len = len < I2C_FIFO_DEEP ? len : I2C_FIFO_DEEP;
		sprd_i2c_write_bytes(i2c_bus, msg->buf, send_len);
		len -= send_len;
		msg->buf += send_len;

		sprd_i2c_wait_for_fifo_empty(i2c_bus);
	}

	return  sprd_i2c_wait_for_int(i2c_bus);
}

static int sprd_i2c_handle_msg(struct udevice *dev, struct i2c_msg *msg,
			 bool is_last_msg)
{
	struct sprd_i2c_bus *i2c_bus = dev_get_priv(dev);
	int ret;

	if (msg->flags & I2C_M_RD)
		ret = sprd_i2c_read(i2c_bus, msg, is_last_msg);
	else
		ret = sprd_i2c_write(i2c_bus, msg, is_last_msg);

	return ret;
}

static int sprd_i2c_xfer(struct udevice *dev, struct i2c_msg *msgs,
			    int nmsgs)
{
	int im, ret;
	struct sprd_i2c_bus *i2c_bus = dev_get_priv(dev);
	struct i2c_msg *msgs_p = msgs;

	ret = sprd_i2c_clk_enable(i2c_bus);
	if (ret)
		return ret;

	for (im = 0; im < nmsgs -1; im++) {
		ret = sprd_i2c_handle_msg(dev, &msgs[im], 0);
		if (ret < 0) {
			sprd_i2c_clk_disable(i2c_bus);
			return ret;
		}
	}

	ret = sprd_i2c_handle_msg(dev, &msgs[im++], 1);

	sprd_i2c_clk_disable(i2c_bus);

	return ret < 0 ? ret : im;
}

static int sprd_i2c_set_bus_speed(struct udevice *dev, unsigned int speed)
{
	struct sprd_i2c_bus *i2c_bus = dev_get_priv(dev);
	int ret;
	u32 APB_clk = I2C_SRC_CLK;
	u32 i2c_dvd = APB_clk / (4 * speed) - 1;
	u32 high = ((i2c_dvd << 1) * 2) / 5;
	u32 low = ((i2c_dvd << 1) * 3) / 5;
	u32 div0 = (high & ADDR_DVD0_MASK) << 16 | (low & ADDR_DVD0_MASK);
	u32 div1 =  (high & ADDR_DVD1_MASK) | ((low & ADDR_DVD1_MASK) >> 16);

	ret = sprd_i2c_clk_enable(i2c_bus);
	if (ret)
		return ret;

	writel(div0, i2c_bus->base+ ADDR_DVD0);
	writel(div1, i2c_bus->base + ADDR_DVD1);

	if (speed == I2C_SPEED_400K)
		writel(((6 * APB_clk) / 10000000),
			i2c_bus->base + ADDR_STA0_DVD);
	else if (speed == I2C_SPEED_100K)
		writel(((4 * APB_clk) / 1000000),
			i2c_bus->base + ADDR_STA0_DVD);
	sprd_i2c_clk_disable(i2c_bus);

	return 0;
}

static int sprd_i2c_get_clk(struct udevice *dev)
{
	struct sprd_i2c_bus *i2c_bus = dev_get_priv(dev);
	struct clk clk_i2c, clk_source, i2c_clk_enable;
	int ret;

	ret  = clk_get_by_name(dev, "i2c", &clk_i2c);
	if (ret) {
		dev_err(dev, "Can't get i2c-%d clock: %d\n",
			i2c_bus->bus_num, ret);
		return ret;
	}

	ret  = clk_get_by_name(dev, "source", &clk_source);
	if (ret) {
		dev_err(dev, "Can't get i2c-%d source clock: %d\n",
			i2c_bus->bus_num, ret);
		return ret;
	}

	ret = clk_set_parent(&clk_i2c, &clk_source);
	if (ret) {
		dev_err(dev, "Can't clk_set_parent i2c-%d: %d\n",
			i2c_bus->bus_num, ret);
		return ret;
	}

	ret  = clk_get_by_name(dev, "enable", &i2c_bus->i2c_enable);
	if (ret) {
		dev_err(dev, "Can't get i2c-%d enable clock: %d\n",
			i2c_bus->bus_num, ret);
		return ret;
	}

	return 0;
}

static int sprd_i2c_probe_chip(struct udevice *dev, uint chip, uint chip_flags)
{
	/*
	 * When probe a slave device, we should attach it by send the slave
	 * address whit any data, and than check the ACK, but the unisoc i2c
	 * controller didn't  support send the slave address only, so it just
	 * return normal here.
	 */
	return 0;
}

static int sprd_i2c_init(struct udevice *dev)
{
	struct sprd_i2c_bus *i2c_bus = dev_get_priv(dev);
	u32 tmp;
	int ret ;

	ret = sprd_i2c_clk_enable(i2c_bus);
	if (ret)
		return ret;

	i2c_bus->base = dev_read_addr_ptr(dev);
	dev_info(dev, "i2c-%d base address: 0x%x\n", i2c_bus->bus_num,
		 (unsigned int)i2c_bus->base);

	tmp = readl(i2c_bus->base + I2C_CTL);
	tmp = tmp & ~(I2C_EN | I2C_TRIM_OPT | (0xF << FIFO_AF_LVL) |
		(0xF << FIFO_AE_LVL));

	tmp |= I2C_INT_EN;
	tmp |= (I2C_FIFO_FULL_THLD << FIFO_AF_LVL) |
		(I2C_FIFO_EMPTY_THLD << FIFO_AE_LVL);

	writel(tmp, i2c_bus->base + I2C_CTL);

	sprd_i2c_reset_fifo(i2c_bus);
	sprd_i2c_clear_int(i2c_bus);

	tmp = readl(i2c_bus->base  + I2C_CTL);
	writel(tmp | (I2C_EN), i2c_bus->base  + I2C_CTL);

	sprd_i2c_clk_disable(i2c_bus);

	return 0;
}

static int sprd_i2c_hw_chn_init(struct udevice *dev)
{
	struct sprd_i2c_bus *i2c_bus = dev_get_priv(dev);
	int ret, size, chn_cnt, i;
	const __be32 *chn_list;
	u32 chn_num, chn_config, tmp;

	chn_list = ofnode_get_property(dev->node, "sprd,hw-channels", &size);
	if (!chn_list || !size) {
		dev_warn(dev,
			"i2c-%d didn't have hardware channel, or didn't config it.\n",
			i2c_bus->bus_num);
		return 0;
	}

	ret = sprd_i2c_clk_enable(i2c_bus);
	if (ret)
		return ret;

	chn_cnt = size / 8;
	for (i = 0; i < chn_cnt; i++) {
		chn_num = be32_to_cpu(*chn_list++);
		chn_config = be32_to_cpu(*chn_list++);

		if (chn_num < CHN_START || chn_num >= CHN_MAX_CNT) {
			dev_err(dev, "illegal channel number: %d\n", chn_num);
			return -1;
		}

		chn_config = ( (chn_config & I2C_HW_SLAVE_ADDR_MASK)
			       | (chn_config & I2C_HW_SLAVE_REG_MASK) ) << 2;

		writel(chn_config, i2c_bus->base + CHNLX_ADDR(chn_num));
		if (chn_num < CHNL_GROUP0_SIZE) {
			tmp = __raw_readl(i2c_bus->base + CHNL_EN0);
			tmp |= BIT(chn_num);
			__raw_writel(tmp, i2c_bus->base + CHNL_EN0);
		} else {
			tmp = __raw_readl(i2c_bus->base + CHNL_EN1);
			tmp |= BIT(chn_num - CHNL_GROUP0_SIZE);
			__raw_writel(tmp, i2c_bus->base + CHNL_EN1);
		}
	}
	return 0;
}

static int sprd_i2c_ofdata_to_platdata(struct udevice *dev)
{
	const void *blob = gd->fdt_blob;
	struct sprd_i2c_bus *i2c_bus = dev_get_priv(dev);
	int node = dev_of_offset(dev);

	i2c_bus->base = dev_read_addr_ptr(dev);
	i2c_bus->clock_frequency = fdtdec_get_int(blob, node,
					      "clock-frequency", I2C_SPEED_100K);
	i2c_bus->node = node;
	i2c_bus->bus_num = dev->seq;

	dev_info(dev, "%s: sprd_i2c-%d : base: 0x%x, clock_frequency: %d\n",
		 __func__, i2c_bus->bus_num,(unsigned int)i2c_bus->base,
			i2c_bus->clock_frequency);

	return 0;
}

static int sprd_i2c_probe(struct udevice *dev)
{
	int ret;
	struct sprd_i2c_bus *i2c_bus = dev_get_priv(dev);

	i2c_bus->udev = dev;

	ret = sprd_i2c_get_clk(dev);
	if (ret)
		return ret;

	ret = sprd_i2c_init(dev);
	if(ret)
		return ret;

	return  sprd_i2c_hw_chn_init(dev);
}

static const struct dm_i2c_ops sprd_i2c_ops = {
	.xfer		= sprd_i2c_xfer,
	.probe_chip	= sprd_i2c_probe_chip,
	.set_bus_speed	= sprd_i2c_set_bus_speed,
};

static const struct udevice_id sprd_i2c_ids[] = {
	{ .compatible = "sprd,sharkl5pro-i2c", },
	{ .compatible = "sprd,qogirl6-i2c", },
	{ .compatible = "sprd,qogirn6pro-i2c", },
	{ }
};

U_BOOT_DRIVER(sprd_i2c) = {
	.name = "i2c_sprd",
	.id = UCLASS_I2C,
	.of_match = sprd_i2c_ids,
	.probe = sprd_i2c_probe,
	.ofdata_to_platdata = sprd_i2c_ofdata_to_platdata,
	.priv_auto_alloc_size = sizeof(struct sprd_i2c_bus),
	.ops	= &sprd_i2c_ops,
	.flags = DM_FLAG_PRE_RELOC,
};
