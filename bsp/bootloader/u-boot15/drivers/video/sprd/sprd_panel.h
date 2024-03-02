/*
 *Copyright (C) 2017 Spreadtrum Communications Inc.
 *
 *This software is licensed under the terms of the GNU General Public
 *License version 2, as published by the Free Software Foundation, and
 *may be copied, distributed, and modified under those terms.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 */

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

//==================================================================
#include <common.h>
#include <asm/io.h>
#include <asm/errno.h>
#include <asm/arch/common.h>
#include <asm/arch/sprd_reg.h>
#include <linux/compat.h>
#include <linux/types.h>
#include <lcd.h>


#ifndef bool
typedef int bool;
#endif
#ifndef false
#define false 0
#endif
#ifndef true
#define true 1
#endif


#define pr_err(fmt, args...) do { printf("[sprdfb][%s] ", __func__); printf(fmt, ##args); } while (0)
#define pr_info(fmt, args...) do { printf("[sprdfb][%s] ", __func__); printf(fmt, ##args); } while (0)
#define pr_emerg(fmt, args...) do { printf("[sprdfb][%s]", __func__); printf(fmt, ##args); } while (0)
#define pr_debug(fmt, args...) do { } while (0)

#define msleep(a)	udelay(a * 1000)
#define CMD_END		0
//==================================================================
enum {
	SPRD_MAINLCD_ID = 0,
	SPRD_SUBLCD_ID,
	SPRD_MAX_LCD_ID,
};

/* LCD supported FPS */
#define LCD_MAX_FPS 70
#define LCD_MIN_FPS 0

enum {
	CMD_CODE_INIT = 0,
	CMD_CODE_SLEEP_IN,
	CMD_CODE_SLEEP_OUT,
	CMD_CODE_READ_ID,
	CMD_OLED_BRIGHTNESS,
	CMD_OLED_REG_LOCK,
	CMD_OLED_REG_UNLOCK,
	CMD_CODE_RESERVED0,
	CMD_CODE_RESERVED1,
	CMD_CODE_RESERVED2,
	CMD_CODE_RESERVED3,
	CMD_CODE_RESERVED4,
	CMD_CODE_RESERVED5,
	CMD_CODE_MAX,
};

enum {
	SPRD_DSI_MODE_CMD = 0,
	SPRD_DSI_MODE_VIDEO_BURST,
	SPRD_DSI_MODE_VIDEO_SYNC_PULSE,
	SPRD_DSI_MODE_VIDEO_SYNC_EVENT,
};

enum {
	SPRD_PANEL_TYPE_MCU = 0,
	SPRD_PANEL_TYPE_RGB,
	SPRD_PANEL_TYPE_MIPI,
	SPRD_PANEL_TYPE_SPI,
	SPRD_PANEL_TYPE_LVDS,
	SPRD_PANEL_TYPE_LIMIT
};

enum {
	SPRD_POLARITY_POS = 0,
	SPRD_POLARITY_NEG,
	SPRD_POLARITY_LIMIT
};

enum {
	SPRD_RGB_BUS_TYPE_I2C = 0,
	SPRD_RGB_BUS_TYPE_SPI,
	SPRD_RGB_BUS_TYPE_LVDS,
	SPRD_RGB_BUG_TYPE_LIMIT
};

enum {
	SPRD_MIPI_MODE_CMD = 0,
	SPRD_MIPI_MODE_VIDEO,
	SPRD_MIPI_MODE_LIMIT
};

enum {
	PANEL_VIDEO_NON_BURST_SYNC_PULSES = 0,
	PANEL_VIDEO_NON_BURST_SYNC_EVENTS,
	PANEL_VIDEO_BURST_MODE
};

struct rgb_timing {
	uint16_t hfp;		/*unit: pixel */
	uint16_t hbp;
	uint16_t hsync;
	uint16_t vfp;		/*unit: line */
	uint16_t vbp;
	uint16_t vsync;
};

struct dsi_cmd_header {
	uint8_t data_type;
	uint8_t wait;
	uint8_t wc_l;
	uint8_t wc_h;
} __packed;

struct dsi_cmd_desc {
	uint8_t data_type;
	uint8_t wait;
	uint8_t wc_h;
	uint8_t wc_l;
	uint8_t payload[];
};

struct gpio_timing {
	uint32_t level;
	uint32_t delay;
};

struct reset_sequence {
	uint32_t items;
	struct gpio_timing *timing;
};

struct power_gpio {
	uint8_t gpio_avdd;
	uint8_t gpio_avee;
	uint8_t gpio_lcm1v8en;
	uint8_t gpio_reset;
	uint8_t gpio_iovdd;
	uint8_t gpio_id;
	uint8_t gpio_3v3en;
	uint8_t reserved_1;
	uint8_t reserved_2;

};

struct bias_power {
	uint8_t i2c_bus;
	uint8_t i2c_addr;
	const uint8_t *i2c_reg;
	const uint8_t *i2c_val;
	uint8_t i2c_items;
	uint32_t i2c_speed;
};

struct panel_id {
	const uint8_t *reg_seq;
	const uint8_t *val_seq;
	uint8_t reg_items;
	uint8_t val_items;
	int*  val_len_array;
	uint8_t gpio_value;
};

struct panel_backlight {
		uint32_t  gpio_bl_en;
		uint32_t  gpio_bl_pwr_en;
		uint8_t i2c_bus;
		uint8_t i2c_addr;
		const uint8_t *i2c_reg;
		const uint8_t *i2c_val;
		uint8_t i2c_items;
		uint32_t i2c_speed;
};

/* LCD abstraction */
struct panel_info {
	struct power_gpio power_pin;
	struct panel_backlight panel_bl;
	/* common parameters */
	const char *lcd_name;
	uint8_t type;
	uint8_t bpp;
//	uint8_t fps;
	uint16_t width;
	uint16_t height;
	uint32_t lcd_id;
	struct panel_id lcm_id;
	struct bias_power bias_volt;
	struct reset_sequence power_on_seq;
	struct reset_sequence power_off_seq;
	const void *cmds[CMD_CODE_MAX];
	uint32_t cmds_len[CMD_CODE_MAX];
	int dpi_clk_div;
	int power_gpio_delay;
	bool video_lp_cmd_enable;
	bool hporch_lp_disable;

	/* DPI specific parameters */
	uint32_t pixel_clk;
	uint16_t h_sync_pol;
	uint16_t v_sync_pol;
	uint16_t de_pol;
	uint16_t te_pol;
	struct rgb_timing rgb_timing;
	bool dcs_write_en;

	/* MIPI DSI specific parameters */
	uint32_t phy_freq;
	uint8_t lane_num;
	uint8_t work_mode;	/*command_mode, video_mode */
	uint8_t burst_mode;	/*burst, non-burst */
	bool nc_clk_en;

	/* platform specific parameters */
	bool dsc_en;
	int  dsc_mode;
	bool bv3_en;
	bool is_oled;
	bool is_dsi_switch;
	bool dual_dsi_en;
};

struct panel_ops {
	int (*init)(void);
	int (*slave_init)(void);
	int (*read_id)(void);
	int (*power)(int on);
	int (*set_brightness)(int level);
};

struct panel_driver {
	struct panel_info *info;
	struct panel_ops *ops;
};

extern struct panel_info panel_device;

struct panel_info *panel_info_attach(void);
struct panel_ops *mipi_ops_attach(void);
struct panel_ops *spi_ops_attach(void);
int sprd_panel_probe(void);

#endif
