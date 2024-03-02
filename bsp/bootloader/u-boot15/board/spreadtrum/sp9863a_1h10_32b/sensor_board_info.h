#ifndef _SENSOR_BOARD_INFO_H_
#define _SENSOR_BOARD_INFO_H_

/*
	I2C2 -> AP_IIC2-config 2
*/
struct sensor_phypara sensor_board_phylist[]={
	{0x69 , 0x75, 0x11 ,"icm20600", 2},
	{0xC, 0x00, 0x48 ,"akm09918", 2},
	{0x23, 0x86, 0x92 ,"ltr553als", 2},
};

#endif //_SENSOR_BOARD_INFO_H_
