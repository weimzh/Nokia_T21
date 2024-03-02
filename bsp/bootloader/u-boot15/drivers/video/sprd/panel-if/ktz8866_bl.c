#include "sprd_panel.h"
#include "ktz8866_bl.h"
#include "sprd_dsi.h"
#include "sprd_dphy.h"
#include "dsi/mipi_dsi_api.h"
#include "panel_ops_mipi.h"
#include <i2c.h>
#include <dm.h>

static int last_brightness = 0;

#define BL_REG_CFG1			0x02
#define BL_REG_CFG2			0x03
#define BL_REG_LEDLSB			0x04
#define BL_REG_LEDMSB			0x05
#define BL_REG_BL_EN			0x08
#define BL_REG_RAMP			0x14
#define BL_REG_LEDCURRENT		0x15

#define BL_POWER_PWM_ADDRESS		0x06
#define BL_POWER_TURNON_RAMP_ADDRESS	0x07
#define BL_POWER_CONFIG_ADDRESS		0x09
#define LCD_POWER_BIAS_ADDRESS		0x0C
#define LCD_POWER_VPOS_ADDRESS		0x0D
#define LCD_POWER_VNEG_ADDRESS		0x0E
#define LCD_POWER_I2C_ADDRESS		0x11
#define LCD_POWER_CTL_ADDRESS		0xFF

int ktz8866_set_brightness(int level)
{
	struct panel_backlight *bl = &panel_device.panel_bl;
	static uint32_t bl_addr = 0;
	uint32_t i = 0;
	uint8_t brt_LSB = 0,brt_MSB = 0;
	static int bl_init_flag = 0;

	pr_err( "%s level:%d\n", __func__, level);
	if(!bl_init_flag) {
		sprd_gpio_request(NULL, bl->gpio_bl_pwr_en);
		sprd_gpio_direction_output(NULL, bl->gpio_bl_pwr_en, 1);
		sprd_gpio_request(NULL, bl->gpio_bl_en);
		sprd_gpio_direction_output(NULL, bl->gpio_bl_en, 1);
		mdelay(10);
#ifdef CONFIG_LCD_I2C_DM
		bl_addr = sprd_dm_lcd_init(bl->i2c_bus, bl->i2c_speed, bl->i2c_addr);
#else
		bl_addr = Panel_I2C_Init(bl->i2c_bus, bl->i2c_speed, bl->i2c_addr);
#endif
		bl_init_flag = 1;
	}

	if(last_brightness == level) {
		pr_err( "%s same brightness level: %d, return!\n", __func__, level);
		return 0;
	}

	if (bl_addr) {
		if(level > 0) {
			brt_LSB &= ~0x07;
			brt_LSB |= level & 0x07;
			brt_MSB &= ~0xff;
			brt_MSB |= (level>>3) & 0xff;

			Panel_I2C_Write(bl_addr, BL_REG_CFG1, 0xFA);		/*** REG02  OVP:40V linear  DEFAULT*/
			Panel_I2C_Write(bl_addr, BL_REG_CFG2, 0x8D);		/*** REG03  transition ramp  DEFAULT*/
			Panel_I2C_Write(bl_addr, BL_REG_RAMP, 0x44);		/*** REG14  turn on/off ramp  DEFAULT  */
			Panel_I2C_Write(bl_addr, BL_REG_LEDCURRENT, 0x98);   /*** REG15  Full-scale current:25.2mA(0xC8);20.4mA(0x98)*/

			Panel_I2C_Write(bl_addr, BL_REG_LEDLSB, brt_LSB);    /*** REG04  LOW3BIT = 111b */
			Panel_I2C_Write(bl_addr, BL_REG_LEDLSB, brt_MSB);    /*** REG05  HIGH8BIT */

			Panel_I2C_Write(bl_addr, BL_REG_BL_EN, 0x7F);        /*** REG08  Enable Backlight,Enable CH1,CH2,CH3,CH4,CH5,CH6 */
			mdelay(50);
		} else {
			Panel_I2C_Write(bl_addr, BL_REG_BL_EN, 0x3F);        /*** REG08  Disable Backlight */
			pr_err( "Close Panel LCD backlight...\n");
		}
	}

	last_brightness = level;

	return 0;
}

void panel_bl_bias_power(void)
{
	struct panel_info *info = &panel_device;
	struct power_gpio *io = &info->power_pin;
	struct panel_backlight *bl = &panel_device.panel_bl;
	static uint32_t bl_addr = 0;

	sprd_gpio_request(NULL, bl->gpio_bl_en);
	sprd_gpio_direction_output(NULL, bl->gpio_bl_en, 1);

	sprd_gpio_request(NULL, bl->gpio_bl_pwr_en);
	sprd_gpio_direction_output(NULL, bl->gpio_bl_pwr_en, 1);
	mdelay(5);

#ifdef CONFIG_LCD_I2C_DM
	bl_addr = sprd_dm_lcd_init(bl->i2c_bus, bl->i2c_speed, bl->i2c_addr);
#else
	bl_addr = Panel_I2C_Init(bl->i2c_bus, bl->i2c_speed, bl->i2c_addr);
#endif

	Panel_I2C_Write(bl_addr, LCD_POWER_BIAS_ADDRESS, 0x28);         /*** REG0C  //BOOST_CFG*/
	Panel_I2C_Write(bl_addr, LCD_POWER_VPOS_ADDRESS, 0x1E);         /*** REG0D  //OUTP voltage*/
	mdelay(3);
	Panel_I2C_Write(bl_addr, LCD_POWER_VNEG_ADDRESS, 0x1C);         /*** REG0E  //VNEG voltage*/
	Panel_I2C_Write(bl_addr, BL_POWER_CONFIG_ADDRESS, 0x99);        /*** REG09  //use externel enables*/

}
