/*
 * Copyright (C) 2017 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "sprd_panel.h"
#include "sprd_dsi.h"
#include "sprd_dphy.h"
#include <libfdt.h>
#include <fdtdec.h>

DECLARE_GLOBAL_DATA_PTR;

static uint32_t lcd_id_to_kernel;
static struct panel_driver *panel_drv;


static struct panel_driver lcd_drv;
struct panel_info  panel_device;

#ifdef CONFIG_BACKLIGHT_I2C
void set_backlight(int brightness)
{
	if (panel_drv && panel_drv->ops->set_brightness) {
		panel_drv->ops->set_brightness(brightness);
	}
	pr_info("lcd cabc backlight brightness==%d\n",brightness);
	return;
}
#endif

struct panel_info *panel_info_attach(void)
{
	return panel_drv->info;
}



uint32_t lcd_get_bpix(void)
{
	return panel_info.vl_bpix;
}

const char *lcd_get_name(void)
{
	if (panel_drv && panel_drv->info)
		return panel_drv->info->lcd_name;
	else
		return NULL;
}

uint32_t load_lcd_id_to_kernel(void)
{
	return lcd_id_to_kernel;
}

/* WORKAROUND: to keep the same order with sprdfb_panel.c */
uint32_t load_lcd_width_to_kernel(void)
{
	if (panel_drv && panel_drv->info)
		return panel_drv->info->height;
	else
		return 0;
}

/* WORKAROUND: to keep the same order with sprdfb_panel.c */
uint32_t load_lcd_hight_to_kernel(void)
{
	if (panel_drv && panel_drv->info)
		return panel_drv->info->width;
	else
		return 0;
}

static int panel_if_init(void)
{
	int type = panel_drv->info->type;

	switch (type) {
	case SPRD_PANEL_TYPE_MIPI:
		sprd_dsi_probe();
		sprd_dphy_probe();
		//panel_drv->ops = mipi_ops_attach();
		return 0;

	case SPRD_PANEL_TYPE_SPI:
		panel_drv->ops = spi_ops_attach();
		return 0;

	case SPRD_PANEL_TYPE_RGB:
		return 0;

	default:
		pr_err("doesn't support current interface type %d\n", type);
		return -1;
	}
}

static int panel_slave_if_init(void)
{
	int type = panel_drv->info->type;

	switch (type) {
	case SPRD_PANEL_TYPE_MIPI:
		sprd_dsi_slave_probe();
		sprd_dphy_slave_probe();
		return 0;

	case SPRD_PANEL_TYPE_SPI:
		return 0;

	case SPRD_PANEL_TYPE_RGB:
		return 0;

	default:
		pr_err("doesn't support current interface type %d\n", type);
		return -1;
	}
}

static int panel_if_uinit(void)
{
	int type = panel_drv->info->type;

	switch (type) {
	case SPRD_PANEL_TYPE_MIPI:
		sprd_dphy_suspend(&dphy_device);
		sprd_dsi_suspend(&dsi_device);
		panel_drv->ops = NULL;
		return 0;

	case SPRD_PANEL_TYPE_SPI:
		panel_drv->ops = NULL;
		return 0;

	case SPRD_PANEL_TYPE_RGB:
		return 0;

	default:
		pr_err("doesn't support current interface type %d\n", type);
		return -1;
	}
}

int fdt_getprop_u32(const void *fdt, int off, const char *prop, u32 *dflt)
{
	const void *val;
	int len;

	if (!fdt || !prop) {
		pr_err("fdt or prop is NULL\n");
		return -1;
	}

	val = fdt_getprop(fdt, off, prop, &len);
	if (val) {
		*dflt = fdt32_to_cpu(*((const fdt32_t*)val));
		return 0;
	}

	return -1;
}

static int of_parse_timing(const void *fdt, int off_set, struct panel_info *info)
{
	uint32_t val;
	int ret;
	int offset, dis_offset;
	struct rgb_timing *ptim = &info->rgb_timing;

	dis_offset = fdt_subnode_offset(fdt, off_set, "display-timings");
	if (dis_offset < 0) {
		pr_info("Can't get display-timings node\n");
		return -1;
	}

	offset = fdt_first_subnode(fdt, dis_offset);
	if (offset < 0) {
		pr_info("Can't get timing0 node\n");
		return -1;
	}

	ret = fdt_getprop_u32(fdt, offset, "clock-frequency", &val);
	if (!ret)
		info->pixel_clk = val;
	else
		pr_err("Can't get clock-frequency\n");

	ret = fdt_getprop_u32(fdt, offset, "hactive", &val);
	if (!ret)
		info->width = val;
	else
		pr_err("Can't get hactive(panel-width)\n");

	ret = fdt_getprop_u32(fdt, offset, "vactive", &val);
	if (!ret)
		info->height = val;
	else
		pr_err("Can't get vactive(panel-height)\n");

	ret = fdt_getprop_u32(fdt, offset, "hback-porch", &val);
	if (!ret)
		ptim->hbp = val;

	ret = fdt_getprop_u32(fdt, offset, "hfront-porch", &val);
	if (!ret)
		ptim->hfp = val;

	ret = fdt_getprop_u32(fdt, offset, "vback-porch", &val);
	if (!ret)
		ptim->vbp = val;

	ret = fdt_getprop_u32(fdt, offset, "vfront-porch", &val);
	if (!ret)
		ptim->vfp = val;

	ret = fdt_getprop_u32(fdt, offset, "hsync-len", &val);
	if (!ret)
		ptim->hsync = val;

	ret = fdt_getprop_u32(fdt, offset, "vsync-len", &val);
	if (!ret)
		ptim->vsync = val;

#ifdef CONFIG_SPRD_PANEL_DEBUG
	pr_info("pixel_clk:%d, hactive(width):%d, vactive(height)%d\n",
		info->pixel_clk, info->width, info->height);
	pr_info("hbp:%d, hfp:%d, hsync:%d\n", ptim->hbp, ptim->hfp, ptim->hsync);
	pr_info("vbp:%d, vfp:%d, vsync:%d\n", ptim->vbp, ptim->vfp, ptim->vsync);
#endif

	return 0;
}

static int of_parse_initdata(const void *fdt, int offset, struct panel_info *info)
{
	int len = 0;
	const void *str = NULL;

	str = fdt_getprop(fdt, offset, "sprd,initial-command", &len);
	if (!str) {
		pr_err("Can't get sprd,initial-command\n");
		return -1;
	}
	info->cmds[CMD_CODE_INIT] = str;
	info->cmds_len[CMD_CODE_INIT] = len;


	str = fdt_getprop(fdt, offset, "sprd,sleep-in-command", &len);
	if (!str) {
		pr_err("can't find sprd,sleep-in-command property\n");
		return -1;
	}
	info->cmds[CMD_CODE_SLEEP_IN] = str;
	info->cmds_len[CMD_CODE_SLEEP_IN] = len;

	str = fdt_getprop(fdt, offset, "sprd,sleep-out-command", &len);
	if (!str) {
		pr_err("can't find sprd,sleep-out-command property\n");
		return -1;
	}
	info->cmds[CMD_CODE_SLEEP_OUT] = str;
	info->cmds_len[CMD_CODE_SLEEP_OUT] = len;

	str = fdt_getprop(fdt, offset, "sprd,use-dcs-write", &len);
	if (str) {
		info->dcs_write_en = true;
		pr_info("Use dcs write\n");
	}

	return 0;
}


static int of_parse_panel(const void *fdt, int offset, struct panel_info *info)
{
	uint32_t val = 0;
	const char *str= NULL;
	int  len = 0, ret = 0;

	str = fdt_get_name(fdt, offset, NULL);
	if (str) {
		info->lcd_name = str;
		pr_info("panel: %s\n", info->lcd_name);
	}

	str = fdt_getprop(fdt, offset, "sprd,lcd_buildin_name", &len);
	if (str) {
		info->lcd_name = (const char*)str;
		pr_info("Lcd has buildin name,change lcd name to buildin name : %s\n", info->lcd_name);
	}

	ret = fdt_getprop_u32(fdt, offset, "sprd,panel-if-type", &val);
	if (!ret)
		info->type = val;
	else
		info->type = SPRD_PANEL_TYPE_MIPI;

	/*************DSI*****************/
	ret = fdt_getprop_u32(fdt, offset, "sprd,dsi-work-mode", &val);
	if (!ret) {
		switch(val) {
			case SPRD_DSI_MODE_CMD:
				info->work_mode = SPRD_MIPI_MODE_CMD;
				info->burst_mode = PANEL_VIDEO_BURST_MODE;
				break;
			case SPRD_DSI_MODE_VIDEO_BURST:
				info->work_mode = SPRD_MIPI_MODE_VIDEO;
				info->burst_mode = PANEL_VIDEO_BURST_MODE;
				break;
			case SPRD_DSI_MODE_VIDEO_SYNC_PULSE:
				info->work_mode = SPRD_MIPI_MODE_VIDEO;
				info->burst_mode = PANEL_VIDEO_NON_BURST_SYNC_PULSES;
				break;
			case SPRD_DSI_MODE_VIDEO_SYNC_EVENT:
				info->work_mode = SPRD_MIPI_MODE_VIDEO;
				info->burst_mode = PANEL_VIDEO_NON_BURST_SYNC_EVENTS;
				break;
			default:
				info->work_mode = SPRD_MIPI_MODE_VIDEO;
				info->burst_mode = PANEL_VIDEO_BURST_MODE;
		}
	} else {
		info->work_mode = SPRD_MIPI_MODE_VIDEO;
		info->burst_mode = PANEL_VIDEO_BURST_MODE;
		pr_err("Can't get sprd,dsi-work-mode, set default value\n");
	}

	ret = fdt_getprop_u32(fdt, offset, "sprd,dsi-lane-number", &val);
	if (!ret)
		info->lane_num = val;
	else {
		info->lane_num = 4;
		pr_err("Can't get sprd,dsi-lane-number, set default value\n");
	}

	ret = fdt_getprop_u32(fdt, offset, "sprd,dual-dsi-en", &val);
	if (!ret)
		info->dual_dsi_en = val;
	else {
		info->dual_dsi_en = 0;
		pr_err("Can't get sprd,dual_dsi_en, set default value\n");
	}


	str = fdt_getprop(fdt, offset, "sprd,dsi-color-format", &len);
	if (str) {
		if (strncmp((const char*)str, "rgb888", 6) == 0)
			info->bpp = 24;
		else if (strncmp((const char*)str, "dsc", 3) == 0) {
			info->bpp = 24;
			info->dsc_en = 1;
			ret = fdt_getprop_u32(fdt, offset, "sprd,dsc-mode", &val);
			if (!ret)
				info->dsc_mode = val;
			else {
				info->dsc_mode = 0;
				pr_err("Can't get sprd,dsc_mode, set default value\n");
			}
		} else
			info->bpp = 16;
	} else {
		info->bpp = 24;
		pr_err("Can't get sprd,dsi-color-format, set default value\n");
	}

	ret = fdt_getprop_u32(fdt, offset, "sprd,non-coninuous-clk-en", &val);
	if (!ret)
		info->nc_clk_en = val;

	/************DPHY*******************/
	ret = fdt_getprop_u32(fdt, offset, "sprd,phy-bit-clock", &val);
	if (!ret)
		info->phy_freq = val;
	else
		pr_err("Can't get sprd,phy-bit-clock\n");

	str = fdt_getprop(fdt, offset, "sprd,reset-on-sequence", &len);
	if (str) {
		u32* seq_on_buf = NULL;

		if(len % sizeof(struct gpio_timing)) {
			pr_err("%s: invaild sprd,reset-on-sequence  lenght:%d \n", __func__, len);
		}

		seq_on_buf = (u32*)malloc(len);

		ret = fdtdec_get_int_array(fdt, offset, "sprd,reset-on-sequence", seq_on_buf, len/sizeof(int));
		if(ret) {
			pr_err("%s: get sprd,reset-on-sequence fail, ret:%d \n", __func__, ret);
		}

		info->power_on_seq.items = len/sizeof(struct gpio_timing);
		info->power_on_seq.timing = (struct gpio_timing*) seq_on_buf;

	} else
		pr_err("Can't get sprd,reset-on-sequence\n");

	str = fdt_getprop(fdt, offset, "sprd,reset-off-sequence", &len);
	if (str) {
		u32* seq_off_buf = NULL;

		if(len % sizeof(struct gpio_timing)) {
			pr_err("%s: invaild sprd,reset-off-sequence  lenght:%d \n", __func__, len);
		}

		seq_off_buf = (u32*)malloc(len);

		ret = fdtdec_get_int_array(fdt, offset, "sprd,reset-off-sequence", seq_off_buf, len/sizeof(int));
		if(ret) {
			pr_err("%s: get sprd,reset-off-sequence fail, ret:%d \n", __func__, ret);
		}

		info->power_off_seq.items = len/sizeof(struct gpio_timing) ;
		info->power_off_seq.timing = (struct gpio_timing*) seq_off_buf;

	} else
		pr_err("Can't get sprd,reset-off-sequence\n");

	/***********READ ID**************/
	str = fdt_getprop(fdt, offset, "sprd,lcd-id-register", &len);
	if (str) {
		int* val_len_array = NULL;
		info->lcm_id.reg_seq = (const uint8_t*)str;
		info->lcm_id.reg_items = len;

		val_len_array  = (int*)malloc(info->lcm_id.reg_items *sizeof(int));
		ret = fdtdec_get_int_array(fdt, offset, "sprd,lcd-id-value-len", val_len_array, info->lcm_id.reg_items);
		if(ret) {
			int t = 0;
			pr_err("%s: get sprd,lcd-id-value-len fail, ret:%d, use default config \n", __func__, ret);
			for ( t= 0; t< info->lcm_id.reg_items; t++ ) {
				val_len_array[t] = 1;
			}
		}

		info->lcm_id.val_len_array = val_len_array;
	}

	str = fdt_getprop(fdt, offset, "sprd,lcd-id-value", &len);
	if (str) {
		info->lcm_id.val_seq = (const uint8_t*) str;
		info->lcm_id.val_items = len;
	}

	ret = fdt_getprop_u32(fdt, offset, "sprd,lcd-id-gpio-value", &val);
	if (!ret)
		info->lcm_id.gpio_value = val;

	str = fdt_getprop(fdt, offset, "sprd,lcd-id-command", &len);
	if (str) {
		info->cmds[CMD_CODE_READ_ID] = (const void*) str;
		info->cmds_len[CMD_CODE_READ_ID] = len;
	}

	ret = fdt_getprop_u32(fdt, offset, "sprd,lcd-id-tokernel", &val);
	if (!ret)
		info->lcd_id = val;
	else
		pr_err("Can't get sprd,lcd-id-tokernel\n");

	/*------Bias Power-------*/
	ret = fdt_getprop_u32(fdt, offset, "sprd,power-i2c-bus", &val);
	if (!ret) {
		info->bias_volt.i2c_bus = val;

		ret = fdt_getprop_u32(fdt, offset, "sprd,power-i2c-addr", &val);
		if (!ret)
			info->bias_volt.i2c_addr = val;
		else
			pr_err("Can't get sprd,power-i2c-addr\n");

		str = fdt_getprop(fdt, offset, "sprd,power-i2c-reg", &len);
		if (str) {
			info->bias_volt.i2c_reg = (const uint8_t*)str;
			info->bias_volt.i2c_items = len;
		} else
			pr_err("Can't get sprd,power-i2c-reg\n");

		str = fdt_getprop(fdt, offset, "sprd,power-i2c-val", &len);
		if (str)
			info->bias_volt.i2c_val = (const uint8_t*)str;
		else
			pr_err("Can't get sprd,power-i2c-val\n");

		ret = fdt_getprop_u32(fdt, offset, "sprd,power-i2c-speed", &val);
		if (!ret)
			info->bias_volt.i2c_speed = val;
	}

	/*------If Use Panel internal backlight-------*/
	ret = fdt_getprop_u32(fdt, offset, "sprd,bl-i2c-bus", &val);
	if (!ret) {
		info->panel_bl.i2c_bus = val;

		ret = fdt_getprop_u32(fdt, offset, "sprd,bl-i2c-addr", &val);
		if (!ret)
			info->panel_bl.i2c_addr = val;
		else
			pr_err("Can't get sprd,bl-i2c-addr\n");

		str = fdt_getprop(fdt, offset, "sprd,bl-i2c-reg", &len);
		if (str) {
			info->panel_bl.i2c_reg = (const uint8_t*)str;
			info->panel_bl.i2c_items = len;
		} else
			pr_err("Can't get sprd,bl-i2c-reg\n");

		str = fdt_getprop(fdt, offset, "sprd,bl-i2c-val", &len);
		if (str)
			info->panel_bl.i2c_val = (const uint8_t*)str;
		else
			pr_err("Can't get sprd,bl-i2c-val\n");

		ret = fdt_getprop_u32(fdt, offset, "sprd,bl-i2c-speed", &val);
		if (!ret)
			info->panel_bl.i2c_speed = val;
	}

	ret = fdt_getprop_u32(fdt, offset, "sprd,dsi-switch", &val);
        if (!ret)
                info->is_dsi_switch = val;

	ret = fdt_getprop_u32(fdt, offset, "sprd,dpi-clk-div", &val);
	if (!ret)
		info->dpi_clk_div = val;
	else
		info->dpi_clk_div = 0;

	ret = fdt_getprop_u32(fdt, offset, "sprd,power-gpio-delay", &val);
	if (!ret)
		info->power_gpio_delay = val;
	else
		info->power_gpio_delay = 10;

	ret = fdt_getprop_u32(fdt, offset, "sprd,video-lp-cmd-enable", &val);
	if (!ret)
		info->video_lp_cmd_enable = val;
	else
		info->video_lp_cmd_enable = 0;
	ret = fdt_getprop_u32(fdt, offset, "sprd,hporch-lp-disable", &val);
	if (!ret)
		info->hporch_lp_disable = val;
	else
		info->hporch_lp_disable = 0;

	return 0;
}

static int of_parse_panel_power(const void *fdt, int offset, struct panel_info *info)
{
	uint32_t val = 0;
	int ret = 0;

	if( !fdt || !info || (offset < 0)) {
		pr_err("Invaild parameter !\n");
		return -1;
	}

	ret =  fdt_getprop_u32(fdt, offset, "sprd,lcd-iovdd-gpio", &val);
	if(!ret)
		info->power_pin.gpio_iovdd = val;

	ret = fdt_getprop_u32(fdt, offset, "sprd,lcd-avdd-gpio", &val);
	if (!ret)
		info->power_pin.gpio_avdd = val;

	ret = fdt_getprop_u32(fdt, offset, "sprd,lcd-avee-gpio", &val);
	if (!ret)
		info->power_pin.gpio_avee = val;

	ret = fdt_getprop_u32(fdt, offset, "sprd,lcd-lcm1v8en-gpio", &val);
	if (!ret)
		info->power_pin.gpio_lcm1v8en = val;
	ret = fdt_getprop_u32(fdt, offset, "sprd,lcd-3v3en-gpio", &val);
	if (!ret)
		info->power_pin.gpio_3v3en = val;

	ret = fdt_getprop_u32(fdt, offset, "sprd,lcd-id-gpio", &val);
	if (!ret)
		info->power_pin.gpio_id = val;

	ret = fdt_getprop_u32(fdt, offset, "sprd,lcd-reset-gpio", &val);
	if (!ret)
		info->power_pin.gpio_reset = val;
	else
		pr_err("There is no sprd,gpio-reset\n");

	return  0;
}


static int of_parse_panel_backlight(const void *fdt, int offset, struct panel_info *info)
{
	uint32_t val = 0;
	int ret = 0;

	if( !fdt || !info || (offset < 0)) {
		pr_err("Invaild parameter !\n");
		return -1;
	}

	ret = fdt_getprop_u32(fdt, offset, "sprd,lcd-backlight-gpio", &val);
	if (!ret)
		info->panel_bl.gpio_bl_en = val;

	ret = fdt_getprop_u32(fdt, offset, "sprd,lcd-bl-pwr-gpio", &val);
	if (!ret) {
		info->panel_bl.gpio_bl_pwr_en = val;
	}
	return 0;
}

int sprd_panel_probe(void)
{
	struct panel_info *info;
	struct panel_ops *ops;
	const void *fdt = gd->fdt_blob;
	uint8_t *info_addr;
	int lcd_offset, offset;
	int ret = -1;
	int lcd_panel_offset = 0;
	int info_size;

	if (!fdt) {
		pr_err("fdt is NULL, can't parse dts\n");
		return -1;
	}

	lcd_panel_offset = fdt_path_offset(fdt, "/lcd-panel");
	if (lcd_panel_offset < 0) {
		pr_err("Error: Can not get lcd-panel node: %s\n", fdt_strerror(lcd_panel_offset));
		return -1;
	}

	lcd_drv.info = &panel_device;
	panel_drv = &lcd_drv;
	info = panel_drv->info;

	memset((uint8_t*)info, 0, sizeof(*info));

	info_addr = (uint8_t*)info + sizeof(struct power_gpio) + sizeof(struct panel_backlight);
	info_size = sizeof(*info) - sizeof(struct power_gpio) - sizeof(struct panel_backlight);

	if (of_parse_panel_power(fdt, lcd_panel_offset, info)) {
		pr_err("lcd panel power parse error!!!\n");
		return -1;
	}

	if (of_parse_panel_backlight(fdt, lcd_panel_offset, info)) {
		pr_err("lcd panel backlight parse error!!!\n");
		return -1;
	}

	lcd_offset = fdt_path_offset(fdt, "/lcds");
	if (lcd_offset < 0) {
		pr_err("get lcds node error: %s\n", fdt_strerror(lcd_offset));
		return -1;
	}

	for (offset = fdt_first_subnode(fdt, lcd_offset);
		offset >= 0; offset = fdt_next_subnode(fdt, offset)) {

		if(info) {
			memset((uint8_t*)info_addr, 0, info_size);
			of_parse_panel(fdt, offset, info);
			of_parse_timing(fdt, offset, info);
		}

		panel_drv->ops = mipi_ops_attach();
		ops = panel_drv->ops;

		if (ops && ops->power)
			ops->power(true);
		
		panel_if_init();
				
		if (ops && ops->read_id) {
			ret = ops->read_id();
			if (!ret) {
				of_parse_initdata(fdt, offset, info);
				pr_info("attach panel 0x%x success\n",
					info->lcd_id);
				break;
			}
		}
		if (ops && ops->power)
			ops->power(false);

		panel_if_uinit();

		pr_err("Try to attach panel 0x%x failed, try next...\n",
			info->lcd_id);

	}

	if (ret) {
		pr_err("No Panel Attached!\n");
		return -1;
	}

	if (info->dual_dsi_en)
		panel_slave_if_init();

	if (ops && ops->init)
		ops->init();

	if (info->dual_dsi_en)
		ops->slave_init();

	panel_info.vl_row = info->height;
	panel_info.vl_col = info->width;
	panel_info.vl_bpix = info->bpp;
	lcd_id_to_kernel = info->lcd_id;

	return 0;
}
