//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically begin
#ifndef __BOARD_ID_H__
#define __BOARD_ID_H__


#define WT_GPIO_BOARD_ID1 95
#define WT_GPIO_BOARD_ID2 94
#define WT_GPIO_BOARD_ID3 97

#define WT_GPIO_BOARD_ID4 83
#define WT_GPIO_BOARD_ID5 82


//20220531,Added by zhu_jun for get hdm product info begin
struct hardwareid_information
{
	int hardware_gpio_value;
	char hardwareid_name[16];
};

static struct hardwareid_information hardware_id_arr[]=
{
	{0x00, "EVT"},
	{0x01, "DVT"},
	{0x02, "PVT"},
	{0x03, "MP"},
	{0xff, "unknown"}
};

//20220518, Added by zhu_jun for rf boardid begin
//20220512, Added by zhu_jun for boardid start
struct boarid_information
{
	int board_gpio_value;
	int board_voltage;
	char board_name[16];
	char dual_or_single_sim[16];
	int rf_boardid;
};

static struct boarid_information board_id_arr[]=
{
	{0x12,  0, "P19616CA1", "dualsim", 1},//row 4+64GB
	{0x14,  0, "P19616DA1", "dualsim", 1},//row 4+128GB
	{0x10,  0, "P19616CA1", "dualsim", 1},//row EVT default

	{0x02,  0, "P19616EA1", "dualsim", 0},//latam 4+64GB
	{0x04,  0, "P19616FA1", "dualsim", 0},//latam 4+128GB
	{0x00,  0, "P19616EA1", "dualsim", 0},//latam EVT default
	
	{0x21,  0, "P19616GA1", "nosim", 2},//wifi 3+32GB
	{0x22,  0, "P19616HA1", "nosim", 2},//wifi 4+64GB
	{0x24,  0, "P19616IA1", "nosim", 2},//wifi  4+128GB
	{0x20,  0, "P19616HA1", "nosim", 2},//wifi EVT default
	
	{0x32,  0, "P19616AA1", "dualsim", 3},//row+nfc 4+64GB
	{0x34,  0, "P19616BA1", "dualsim", 3},//row+nfc 4+128GB
	{0x30,  0, "P19616AA1", "dualsim", 3},//row+nfc EVT default

	{0x42,  0, "P19616CA1_CH_IN", "dualsim", 4},//india row 4+64GB
	{0x52,  0, "P19616HA1_CH_IN", "nosim", 5},//india wifi 4+64GB
	{0x62,  0, "P19616AA1_CH_IN", "dualsim", 6},//india row+nfc 4+64GB
	
	{0xff, 0, "unknown"    , 0, 0},
};
//20220512, Added by zhu_jun for boardid end
//20220518, Added by zhu_jun for rf boardid end
#endif
//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically end
