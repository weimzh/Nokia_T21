#ifndef _SENSOR_BOARD_INFO_H_
#define _SENSOR_BOARD_INFO_H_

/*I2C2 -> AP_IIC0-config 0
  I2C5 -> AP_IIC1-config 1
*/
struct sensor_phypara sensor_board_phylist[]={
	{0x6B , 0x0F, 0x6A ,"lsm6dsm", 0},
	{0xC, 0x00, 0x48, "akm09918", 0},
	{0x53, 0x06, 0xB1, "ltr578als", 0},
	{0x39, 0x92, 0xDC, "tcs34303", 0},
};

#endif //_SENSOR_BOARD_INFO_H_
