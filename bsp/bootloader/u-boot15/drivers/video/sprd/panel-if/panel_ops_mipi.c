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
#include "dsi/mipi_dsi_api.h"
#include "sprd_dphy.h"
#include "panel_ops_mipi.h"
#include <i2c.h>
#include <dm.h>

#ifdef CONFIG_BACKLIGHT_I2C_KTZ8866
#include "ktz8866_bl.h"
#endif

#ifndef CONFIG_SYS_I2C
struct udevice* dev = NULL;
#endif

static void dump_panel_info(struct panel_info*  info_data)
{
	int i = 0;
	struct panel_info*  info = info_data;
	if(!info) {
		pr_err("%s: Invaild Panel information !\n", __func__);
		return;
	}

	pr_info("----Success attached lcd name:%s, id: 0x%x-----\n", info->lcd_name, info->lcd_id);
	pr_info("lcd: type:%u, bpp:%u, width:%u, height:%u \n", info->type, info->bpp, info->width, info->height);

	pr_info("lcd: gpio_reset: %d \n", info->power_pin.gpio_reset);
	if(info->power_pin.gpio_avdd && info->power_pin.gpio_avee) {

		pr_info("gpio_avdd: %d,  gpio_avee: %d \n", info->power_pin.gpio_avdd, info->power_pin.gpio_avee);
	}

	pr_info("lcd: gpio_lcm1v8en: %d \n", info->power_pin.gpio_lcm1v8en);

	pr_info("========sprd,reset-on-sequence ======== \n");
	for(i = 0; i < info->power_on_seq.items; i++)
	{
		pr_info("lcd: index:%d, level: %u, delay: %u \n", i, info->power_on_seq.timing[i].level, info->power_on_seq.timing[i].delay);
	}

	pr_info("========sprd,reset-off-sequence ======== \n");
	for(i = 0; i < info->power_off_seq.items; i++)
	{
		pr_info("lcd: index:%d, level: %u, delay: %u \n", i, info->power_off_seq.timing[i].level, info->power_off_seq.timing[i].delay);
	}

	if(info->bias_volt.i2c_bus) {
		pr_info("===========Bias Power I2C Config============ \n");
		pr_info("Bus Number:%d, addr: 0x%02x, speed:%u \n", info->bias_volt.i2c_bus,info->bias_volt.i2c_addr, info->bias_volt.i2c_speed);
		for( i = 0; i < info->bias_volt.i2c_items; i++) {
			pr_info("Reg[0x%02x] = 0x%02x; \n",info->bias_volt.i2c_reg[i], info->bias_volt.i2c_val[i]);
		}
	}


	if(info->panel_bl.i2c_bus) {
		pr_info("===========Backlight I2C Config============= \n");
		pr_info("BackLight GPIO:%d, Bus Number:%d, addr: 0x%02x, speed:%u \n", info->panel_bl.gpio_bl_en, info->panel_bl.i2c_bus,info->panel_bl.i2c_addr, info->panel_bl.i2c_speed);
		for( i = 0; i < info->panel_bl.i2c_items; i++) {
			pr_info("Reg[0x%02x] = 0x%02x; \n",info->panel_bl.i2c_reg[i], info->panel_bl.i2c_val[i]);
		}
	}

	pr_info("---------------------------------------\n");

}

static int mipi_dsi_send_cmds(struct sprd_dsi *dsi, void *data, int size)
{
	uint16_t len;
	struct panel_info *info = &panel_device;
	struct dsi_cmd_desc *cmds = (struct dsi_cmd_desc *)data;
	int (*mipi_write)(struct sprd_dsi *dsi, u8 *param, u16 len) =
		mipi_dsi_gen_write;

	if ((cmds == NULL) || (dsi == NULL))
		return -1;

	if (info->dcs_write_en) {
		mipi_write = mipi_dsi_dcs_write;
	}

	while (size > 0) {
		len = (cmds->wc_h << 8) | cmds->wc_l;
		mipi_write(dsi, cmds->payload, len);
		if (cmds->wait)
			msleep(cmds->wait);
		cmds = (struct dsi_cmd_desc *)(cmds->payload + len);
		size -= (len + 4);
	}
	return 0;
}

uint32_t Panel_I2C_Init(unsigned int bus_no, int speed, int slaveaddr)
{
#ifdef  CONFIG_SYS_I2C
	i2c_set_bus_num(bus_no);
	if (speed)
		i2c_init(speed, slaveaddr);

	return (uint32_t)slaveaddr;
#else
	int ret = 0;

	ret = i2c_get_chip_for_busnum(bus_no, slaveaddr, 1, &dev);
	if (ret) {
		pr_err("%s: i2c%d failed to get\n", __func__, bus_no);
		return ret;
	}

	if (dev && speed)
		ret =  dm_i2c_set_bus_speed(dev_get_parent(dev), speed);

	return ret ? 0 : (uint32_t)dev;
#endif
}

#ifdef  CONFIG_LCD_I2C_DM
static uint32_t sprd_dm_lcd_init(unsigned int bus_no, int speed, int slaveaddr)
{
	struct udevice *devp;
	uint32_t ret;

	ret = (uint32_t)uclass_get_device(UCLASS_LCD, 0, &devp);
	if (ret) {
		pr_err("%s:failed to get device ret = %d", __func__, ret);
		return ret;
	}

	return Panel_I2C_Init(bus_no, speed, slaveaddr);
}

#endif

int Panel_I2C_Write(uint32_t addr,  uint32_t reg, uint32_t val)
{
	if(!addr) {
		pr_err("%s: addr is NULL \n", __func__);
		return -1;
	}
#ifdef  CONFIG_SYS_I2C
	i2c_reg_write(addr, reg, val);
	return 0;
#else
	return dm_i2c_reg_write((struct udevice*)addr, reg, val);
#endif
}

int Panel_I2C_Read(uint32_t addr, uint32_t reg)
{
	if(!addr) {
		pr_err("%s: addr is NULL \n", __func__);
		return -1;
	}

#ifdef  CONFIG_SYS_I2C
	return i2c_reg_read(addr, reg);
#else
	return dm_i2c_reg_read((struct udevice*)addr, reg);
#endif
}


static int panel_init(void)
{
	struct sprd_dsi *dsi = &dsi_device;
	struct sprd_dphy *dphy = &dphy_device;
	struct panel_info *info = &panel_device;

	dump_panel_info(info);

	mipi_dsi_lp_cmd_enable(dsi, true);

	mipi_dsi_send_cmds(dsi, info->cmds[CMD_CODE_INIT], info->cmds_len[CMD_CODE_INIT]);

	if (info->work_mode == SPRD_MIPI_MODE_CMD)
		mipi_dsi_set_work_mode(dsi, SPRD_MIPI_MODE_CMD);
	else {
		mipi_dsi_set_work_mode(dsi, SPRD_MIPI_MODE_VIDEO);
		if (info->video_lp_cmd_enable)
			mipi_dsi_lp_cmd_enable(dsi, true);
	}

	mipi_dsi_state_reset(dsi);
	mipi_dphy_hs_clk_en(dphy, true);

	pr_info("Download Panel Init Data Success!\n");

	return 0;
}

static int panel_slave_init(void)
{
	struct sprd_dsi *dsi = &dsi_slave_device;
	struct sprd_dphy *dphy = &dphy_slave_device;
	struct panel_info *info = &panel_device;

	dump_panel_info(info);

	mipi_dsi_lp_cmd_enable(dsi, true);

	//mipi_dsi_send_cmds(dsi, info->cmds[CMD_CODE_INIT], info->cmds_len[CMD_CODE_INIT]);

	if (info->work_mode == SPRD_MIPI_MODE_CMD)
		mipi_dsi_set_work_mode(dsi, SPRD_MIPI_MODE_CMD);
	else
		mipi_dsi_set_work_mode(dsi, SPRD_MIPI_MODE_VIDEO);

	mipi_dsi_state_reset(dsi);
	mipi_dphy_hs_clk_en(dphy, true);

	pr_info("Set Slave Status Success!\n");

	return 0;
}
#define MAX_ID_REG_SIZE  8
static int panel_readid(void)
{
	struct sprd_dsi *dsi = &dsi_device;
	struct panel_info *info = &panel_device;
	struct panel_id *id = &info->lcm_id;
	struct bias_power *bp = &info->bias_volt;
	struct power_gpio *pg = &info->power_pin;
	uint8_t read_buf[MAX_ID_REG_SIZE] = {0xff};
	int i = 0;
	int offset = 0;
	int read_len = 0;
	int value = 0;

// add for bias by hz
	if (bp->i2c_addr) {
		uint32_t bias_addr = 0;

		pr_err("Set Dual Output LCD Bias Power!\n");

		bias_addr = Panel_I2C_Init(bp->i2c_bus, bp->i2c_speed, bp->i2c_addr);

		if (bias_addr &&
			(bp->i2c_val[0] != Panel_I2C_Read(bias_addr, bp->i2c_reg[0]))) {

			for (i = 0; i < bp->i2c_items; i++) {
				Panel_I2C_Write(bias_addr, bp->i2c_reg[i], bp->i2c_val[i]);
			}

			mdelay(50);
		}
	}
	if (0xFFFF == info->lcd_id) {
		pr_info("Dummy LCD\n");
		return 0;
	}

	if (!id->reg_items) {
		pr_err("There is no lcd-id-register config!\n");
		return -1;
	}

	mipi_dsi_lp_cmd_enable(dsi, true);

	if (info->cmds_len[CMD_CODE_READ_ID]) {
		pr_info("Download Read Id Cmd\n");
		mipi_dsi_gen_write(dsi, info->cmds[CMD_CODE_READ_ID], info->cmds_len[CMD_CODE_READ_ID]);
	}

	mipi_dsi_set_max_return_size(dsi, id->val_items);

	//Read LCM Register ID
	for( i= 0;  i < id->reg_items; i++) {
		int t = 0;
		memset(read_buf, 0xff, sizeof(read_buf));
		read_len = mipi_dsi_dcs_read(dsi, id->reg_seq[i], read_buf, MAX_ID_REG_SIZE);
		if(read_len <= 0) {
			pr_err("mipi dsi read no data: %d\n",  read_len);
			return -1;
		}

		pr_info("reg items:%d, cmd:0x%02x, val_en:%d >> ", id->reg_items, id->reg_seq[i], id->val_len_array[i]);
		for( t = 0; t < id->val_len_array[i]; t++) {
			printf("R:0x%02x, D:0x%02x; ", read_buf[t], id->val_seq[offset]);
			if (id->val_seq[offset] != read_buf[t]) {
				printf("\n");
				pr_err("Error: Read ID register data error: [0]=0x%02x, [1]=0x%02x, [2]=0x%02x, [3]=0x%02x\n", read_buf[0], read_buf[1], read_buf[2], read_buf[3]);
				return -1;
			}

			offset++;
			if( offset > id->val_items) {
				printf("\n");
				pr_err("Error: The realy ID register value number %d is outof dts config %d !\n", offset,  id->val_items);
				return -1;
			}
		}
		printf("\n");
	}

	if (id->gpio_value) {
		value = sprd_gpio_get(NULL, pg->gpio_id);
		if (value != id->gpio_value) {
			pr_err("Error: The gpio value is not equal to dts config!\n");
			return -1;
		}
	}
	printf("\n");

	if (bp->i2c_addr) {
		uint32_t bias_addr = 0;

		pr_info("Set Dual Output LCD Bias Power!\n");

#ifdef CONFIG_LCD_I2C_DM
		bias_addr = sprd_dm_lcd_init(bp->i2c_bus, bp->i2c_speed, bp->i2c_addr);
#else
		bias_addr = Panel_I2C_Init(bp->i2c_bus, bp->i2c_speed, bp->i2c_addr);
#endif

		if (bias_addr &&
			(bp->i2c_val[0] != Panel_I2C_Read(bias_addr, bp->i2c_reg[0]))) {

			for (i = 0; i < bp->i2c_items; i++) {
				Panel_I2C_Write(bias_addr, bp->i2c_reg[i], bp->i2c_val[i]);
			}

			mdelay(50);
		}
	}

	pr_info("LCD Read Id Success!!!\n");
	return 0;
}

static int panel_power(int on)
{
#ifndef CONFIG_FPGA
	int i;
	struct gpio_timing *timing;
	struct panel_info *info = &panel_device;
	struct power_gpio *io = &info->power_pin;

	if (!io->gpio_reset) {
		pr_err("gpio_reset is NULL\n");
		return -1;
	}

	if (on) {
		if (io->gpio_lcm1v8en) {
			sprd_gpio_request(NULL, io->gpio_lcm1v8en);
			sprd_gpio_direction_output(NULL, io->gpio_lcm1v8en, 1);
			mdelay(20);
		}
		if(io->gpio_iovdd){
			sprd_gpio_request(NULL, io->gpio_iovdd);
			sprd_gpio_direction_output(NULL, io->gpio_iovdd, 1);
			mdelay(10);
		}

		if (io->gpio_avdd) {
			sprd_gpio_request(NULL, io->gpio_avdd);
			sprd_gpio_direction_output(NULL, io->gpio_avdd, 1);
			mdelay(info->power_gpio_delay);
		}

		if (io->gpio_avee) {
			sprd_gpio_request(NULL, io->gpio_avee);
			sprd_gpio_direction_output(NULL, io->gpio_avee, 1);
			mdelay(20);
		}
#ifdef CONFIG_BACKLIGHT_I2C_KTZ8866
		panel_bl_bias_power();

		if (io->gpio_3v3en) {
			sprd_gpio_request(NULL, io->gpio_3v3en);
			sprd_gpio_direction_output(NULL, io->gpio_3v3en, 1);
			mdelay(20);
		}
#endif

		if (io->gpio_id) {
			sprd_gpio_request(NULL, io->gpio_id);
			sprd_gpio_direction_input(NULL, io->gpio_id);
		}

		sprd_gpio_request(NULL, io->gpio_reset);
		timing = info->power_on_seq.timing;
		for (i = 0; i < info->power_on_seq.items; i++) {
			timing = &info->power_on_seq.timing[i];
			sprd_gpio_direction_output(NULL, io->gpio_reset, timing->level);
			mdelay(timing->delay);
		}
	} else {
		timing = info->power_off_seq.timing;
		for (i = 0; i < info->power_off_seq.items; i++) {
			timing = &info->power_off_seq.timing[i];
			sprd_gpio_direction_output(NULL, io->gpio_reset, timing->level);
			mdelay(timing->delay);
		}
	}
#endif
	return 0;
}

static int panel_set_brightness(int level)
{
		struct panel_backlight *bl = &panel_device.panel_bl;
		uint32_t bl_addr = 0;
		uint32_t  i =0;

		sprd_gpio_request(NULL, bl->gpio_bl_en);
		sprd_gpio_direction_output(NULL, bl->gpio_bl_en, 1);
		mdelay(40);

#ifdef CONFIG_LCD_I2C_DM
		bl_addr = sprd_dm_lcd_init(bl->i2c_bus, bl->i2c_speed, bl->i2c_addr);
#else
		bl_addr = Panel_I2C_Init(bl->i2c_bus, bl->i2c_speed, bl->i2c_addr);
#endif

		if (bl_addr) {

			for (i = 0; i < bl->i2c_items; i++) {
				Panel_I2C_Write(bl_addr, bl->i2c_reg[i], bl->i2c_val[i]);
				if(bl->i2c_val[i] != Panel_I2C_Read(bl_addr, bl->i2c_reg[i])) {
					pr_err( "Error: Set Panel LCD backlight reg: 0x02%x \n", bl->i2c_reg[i]);
				}
			}

			mdelay(50);
		}

		return 0;
}

static struct panel_ops mipi_ops = {
	.init = panel_init,
	.slave_init = panel_slave_init,
	.read_id = panel_readid,
	.power = panel_power,
#ifdef CONFIG_BACKLIGHT_I2C_KTZ8866
	.set_brightness = ktz8866_set_brightness,
#else
	.set_brightness = panel_set_brightness,
#endif
};

struct panel_ops *mipi_ops_attach(void)
{
	return &mipi_ops;
}

#ifdef CONFIG_LCD_I2C_DM
struct sprd_lcd_dm_data {
	int i2c_num;
};

static struct sprd_lcd_dm_data dm_data = {
	.i2c_num = -1,
};

static int sprd_lcd_i2c_probe(struct udevice *dev)
{
	u32 i2c_id;
	int ret;

	ret = dev_read_u32(dev, "sprd,lcd-i2c-bus", &i2c_id);
	if (ret) {
		pr_err("%s:failed to get i2c-bus ret = %d!\n", __func__, ret);
		return ret;
	}
	debugf("i2c_id = %d\n", i2c_id);
	dm_data.i2c_num = i2c_id;
	return 0;
}

static const struct udevice_id sprd_lcd_i2c_ids[] = {
	{.compatible = "sprd,lcd-i2c"},
	{ }
};

U_BOOT_DRIVER(lcd_i2c) = {
	.name = "sprd-lcd",
	.id = UCLASS_LCD,
	.of_match = sprd_lcd_i2c_ids,
	.probe = sprd_lcd_i2c_probe,
};

UCLASS_DRIVER(lcd)= {
	.name = "lcd-i2c",
	.id = UCLASS_LCD,
};

#endif
