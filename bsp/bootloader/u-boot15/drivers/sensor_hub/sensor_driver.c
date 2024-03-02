#include <asm/io.h>
#include <sprd_sensor.h>

static u32 default_value;

char sensorname[SENSOR_NAME_LEN] = {0};

static void sprd_set_i2c_matrix(void)
{
	default_value = readl(CONFIG_SENSOR_I2C_MATRIX_BASE);
	writel(CONFIG_SENSOR_I2C_MATRIX_VALUE, CONFIG_SENSOR_I2C_MATRIX_BASE);
}

static void sprd_recover_i2c_matrix(void)
{
	writel(default_value, CONFIG_SENSOR_I2C_MATRIX_BASE);
}

void sprd_sensor_init(void)
{
	int index = 0;
	struct udevice *devp;

	while (!uclass_get_device(UCLASS_SENSOR, index++, &devp));

	return 0;
}

static void sprd_sensor_name_to_kernel(void)
{
	static int sensor_num, i;
	u32 value;
	struct sensor_phypara *sensor_phylist_info = NULL;

	sprd_set_i2c_matrix();
	sensor_num = sprd_sensor_bandlist(&sensor_phylist_info);
	for (i = 0; i < sensor_num; i++) {
		value = sprd_sensor_get_id_name(sensor_phylist_info[i].bus_num, sensor_phylist_info[i].sensor_slave_addr,
						sensor_phylist_info[i].sensor_reg);
		if (value == sensor_phylist_info[i].sensor_id) {
			strcat(sensorname,sensor_phylist_info[i].sensor_name);
			strcat(sensorname,",");
		}
	}

	sprd_recover_i2c_matrix();
}

const char *load_sensor_to_kernel(void)
{
	sprd_sensor_name_to_kernel();
	if (sensorname[0])
		return sensorname;
	 else
		return NULL;
}

