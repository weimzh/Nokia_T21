#ifndef __SPRD_SENDOR_H__
#define __SPRD_SENSOR_H__

#include <common.h>

#define I2C_SPEED		(100000)
#define SENSOR_NAME_LEN		320
#define SENSOR_LEN_MAX		8
#define  SENSOR_I2C_MAX		2

struct sensor_phypara {
	u32 sensor_slave_addr;
	u32 sensor_reg;
	u32 sensor_id;
	const char *sensor_name;
	u32 bus_num;
};

void sprd_sensor_init(void);
int sprd_sensor_bandlist(struct sensor_phypara **sensorlist);
unsigned int sprd_sensor_get_id_name(int bus_num, u32 addr, u32 reg);

#endif
