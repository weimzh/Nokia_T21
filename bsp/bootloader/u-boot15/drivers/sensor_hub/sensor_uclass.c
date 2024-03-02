#include <common.h>
#include <errno.h>
#include <malloc.h>
#include <asm/io.h>
#include <stdio_dev.h>
#include <linux/ctype.h>
#include <linux/types.h>
#include <i2c.h>
#include <dm.h>
#include <sprd_sensor.h>

#ifdef CONFIG_DM_SPRD_I2C
static struct udevice *dev;

static uint32_t sprd_dm_sensor_i2c_init(unsigned int bus_no,
	int speed, int slaveaddr)
{
	int ret = 0;

	ret = i2c_get_chip_for_busnum(bus_no, slaveaddr, 1, &dev);
	asm("dsb sy");
	if (ret) {
		pr_err("%s: i2c%d failed to get\n", __func__, bus_no);
		return ret;
	}

	if (dev && speed) {
		ret =  dm_i2c_set_bus_speed(dev_get_parent(dev), speed);
		if (ret) {
			pr_err("%s: failed to set i2c%d speed\n",
			       __func__, bus_no);
			return ret;
		}
	}

	return 0;
}

unsigned int sprd_sensor_get_id_name(int bus_num, u32 addr, u32 reg)
{
	u32 value, bias_addr = 0;

	bias_addr = sprd_dm_sensor_i2c_init(bus_num, I2C_SPEED, addr);
	if (bias_addr < 0)
		return bias_addr;

	value = dm_i2c_reg_read(dev, reg);

	return value;
}

static int sprd_sensor_bind(struct udevice *dev)
{
	return 0;
}

static const struct udevice_id sprd_sensor_ids[] = {
	{.compatible = "sprd-sensorhub-uboot"},
	{ }
};

U_BOOT_DRIVER(sprd_sensor) = {
	.name = "sensorhub",
	.id = UCLASS_SENSOR,
	.of_match = sprd_sensor_ids,
	.bind = sprd_sensor_bind,
};

UCLASS_DRIVER(sensor)= {
	.name = "sensorhub",
	.id = UCLASS_SENSOR,
};
#else
static void sprd_sensor_i2c_init(int speed, u32 slaveaddr, int bus_num)
{
	i2c_set_bus_num(bus_num);
	i2c_init(speed, slaveaddr);
}

unsigned int sprd_sensor_get_id_name(int bus_num, u32 addr, u32 reg)
{
	u32 value;
	sprd_sensor_i2c_init(I2C_SPEED, addr, bus_num);
	value = i2c_reg_read(addr, reg);

	return value;
}
#endif
