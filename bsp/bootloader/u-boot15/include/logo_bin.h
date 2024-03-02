#ifndef _LOGO_BIN_H_
#define _LOGO_BIN_H_

#include <boot_mode.h>

#define LOGO_NORMAL_POWER 		3
#define LOGO_LOW_VOL 			0
#define LOGO_LOW_BATTERY_CHARGING	1

#define LOGO_TYPE_BMP 			0
#define LOGO_TYPE_BIN 			1
#define LOGO_MAX_BPP 			4

#define LOW_VOL_DISPLAY_DELAY_TIME 	3000

#define LCD_DISPLAY_ENABLE		1

extern int logo_type;
extern int logo_index;

struct header_info {
    char signature[2];
    uint16_t file_number;
    uint32_t reserved_num[5];
    uint32_t gz_size[0];
};

void logo_display(int index, int backlight_value, int lcd_enable);
int get_bmp_base_from_dt(void **bmp_base);
int get_gzip_base_from_dt(void **gzip_base);
int logo_mem_init(void);
int get_logo_bin_info(u8 *bmp, uchar *logo_part_name);

#endif