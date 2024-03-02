/*
 * Copyright (C) 2021 UNISOC Technologies Co.,Ltd.
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


#include <asm/io.h>
#include <asm/arch-sharkl5pro/pinmap.h>
#include <sprd_pin.h>

static gpio_pin_t gpio_fun_pin[]={
 {1, REG_PIN_RFSDA0},
 {2, REG_PIN_RFSCK0},
 {3, REG_PIN_RFSEN0},
 {6, REG_PIN_SD1_D3},
 {7, REG_PIN_RFCTL16},
 {8, REG_PIN_RFCTL17},
 {9, REG_PIN_GPIO9},
 {10, REG_PIN_RFCTL19},
 {11, REG_PIN_RFCTL20},
 {12, REG_PIN_RFSDA1},
 {13, REG_PIN_RFSCK1},
 {14, REG_PIN_RFSEN1},
 {15, REG_PIN_RFFE1_SCK},
 {16, REG_PIN_RFFE1_SDA},
 {17, REG_PIN_U4TXD},
 {18, REG_PIN_U4RXD},
 {19, REG_PIN_RFCTL0},
 {20, REG_PIN_RFCTL1},
 {21, REG_PIN_RFCTL2},
 {22, REG_PIN_RFCTL3},
 {23, REG_PIN_RFCTL4},
 {24, REG_PIN_RFCTL5},
 {25, REG_PIN_RFCTL6},
 {26, REG_PIN_RFCTL7},
 {27, REG_PIN_RFCTL8},
 {28, REG_PIN_RFCTL9},
 {29, REG_PIN_RFCTL10},
 {30, REG_PIN_RFCTL11},
 {31, REG_PIN_GPIO31},
 {32, REG_PIN_GPIO32},
 {33, REG_PIN_GPIO33},
 {34, REG_PIN_U4CTS},
 {35, REG_PIN_U4RTS},
 {36, REG_PIN_RFFE0_SCK},
 {37, REG_PIN_RFFE0_SDA},
 {38, REG_PIN_U5TXD},
 {39, REG_PIN_U5RXD},
 {40, REG_PIN_CMPD2},
 {41, REG_PIN_CMRST2},
 {42, REG_PIN_CMMCLK0},
 {43, REG_PIN_CMMCLK1},
 {44, REG_PIN_CMRST0},
 {45, REG_PIN_CMRST1},
 {46, REG_PIN_CMPD0},
 {47, REG_PIN_CMPD1},
 {48, REG_PIN_SCL0},
 {49, REG_PIN_SDA0},
 {50, REG_PIN_LCM_RSTN},
 {51, REG_PIN_DSI_TE},
 {52, REG_PIN_SPI2_CSN},
 {53, REG_PIN_SPI2_DO},
 {54, REG_PIN_SPI2_DI},
 {55, REG_PIN_SPI2_CLK},
 {56, REG_PIN_IIS0DI},
 {57, REG_PIN_IIS0DO},
 {58, REG_PIN_IIS0CLK},
 {59, REG_PIN_IIS0LRCK},
 {60, REG_PIN_U0TXD},
 {61, REG_PIN_U0RXD},
 {62, REG_PIN_U0CTS},
 {63, REG_PIN_U0RTS},
 {64, REG_PIN_SD1_CLK},
 {65, REG_PIN_SD1_CMD},
 {66, REG_PIN_SD1_D0},
 {67, REG_PIN_SD1_D1},
 {68, REG_PIN_SD1_D2},
 {70, REG_PIN_U1TXD},
 {71, REG_PIN_U1RXD},
 {74, REG_PIN_SCL1},
 {75, REG_PIN_SDA1},
 {77, REG_PIN_PWMC},
 {78, REG_PIN_EXTINT9},
 {79, REG_PIN_EXTINT10},
 {80, REG_PIN_SCL6},
 {81, REG_PIN_SDA6},
 {82, REG_PIN_MTCK_ARM},
 {83, REG_PIN_MTMS_ARM},
 {84, REG_PIN_GPIO84},
 {85, REG_PIN_GPIO85},
 {86, REG_PIN_GPIO86},
 {87, REG_PIN_GPIO87},
 {88, REG_PIN_GPIO88},
 {90, REG_PIN_SPI0_CSN},
 {91, REG_PIN_SPI0_DO},
 {92, REG_PIN_SPI0_DI},
 {93, REG_PIN_SPI0_CLK},
 {94, REG_PIN_MEMS_MIC_CLK0},
 {95, REG_PIN_MEMS_MIC_DATA0},
 {96, REG_PIN_MEMS_MIC_CLK1},
 {97, REG_PIN_MEMS_MIC_DATA1},
 {98, REG_PIN_EMMC_D0},
 {99, REG_PIN_EMMC_CMD},
 {100, REG_PIN_EMMC_D6},
 {101, REG_PIN_EMMC_D7},
 {102, REG_PIN_EMMC_CLK},
 {103, REG_PIN_EMMC_D5},
 {104, REG_PIN_EMMC_D4},
 {105, REG_PIN_EMMC_DS},
 {106, REG_PIN_EMMC_D3},
 {107, REG_PIN_EMMC_RST},
 {108, REG_PIN_EMMC_D1},
 {109, REG_PIN_EMMC_D2},
 {110, REG_PIN_DNS_D0},
 {111, REG_PIN_DNS_D1},
 {112, REG_PIN_IIS3DI},
 {113, REG_PIN_IIS3DO},
 {114, REG_PIN_IIS3CLK},
 {115, REG_PIN_IIS3LRCK},
 {116, REG_PIN_GPIO116},
 {121, REG_PIN_KEYOUT0},
 {122, REG_PIN_KEYOUT1},
 {123, REG_PIN_KEYOUT2},
 {124, REG_PIN_KEYIN0},
 {125, REG_PIN_KEYIN1},
 {126, REG_PIN_KEYIN2},
 {127, REG_PIN_SCL2},
 {128, REG_PIN_SDA2},
 {129, REG_PIN_CLK_AUX0},
 {130, REG_PIN_IIS1DI},
 {131, REG_PIN_IIS1DO},
 {132, REG_PIN_IIS1CLK},
 {133, REG_PIN_IIS1LRCK},
 {134, REG_PIN_SD2_CLK},
 {135, REG_PIN_SD2_CMD},
 {136, REG_PIN_SD2_D0},
 {137, REG_PIN_SD2_D1},
 {138, REG_PIN_SD2_D2},
 {139, REG_PIN_SD2_D3},
 {143, REG_PIN_CMMCLK2},
 {144, REG_PIN_EXTINT0},
 {145, REG_PIN_EXTINT1},
 {146, REG_PIN_SDA3},
 {147, REG_PIN_SCL3},
 {148, REG_PIN_SD0_D3},
 {149, REG_PIN_SD0_D2},
 {150, REG_PIN_SD0_CMD},
 {151, REG_PIN_SD0_D0},
 {152, REG_PIN_SD0_D1},
 {153, REG_PIN_SD0_CLK},
 {154, REG_PIN_SIMCLK2},
 {155, REG_PIN_SIMDA2},
 {156, REG_PIN_SIMRST2},
 {157, REG_PIN_SIMCLK0},
 {158, REG_PIN_SIMDA0},
 {159, REG_PIN_SIMRST0},
 {160, REG_PIN_SIMCLK1},
 {161, REG_PIN_SIMDA1},
 {162, REG_PIN_SIMRST1},

};

int  gpio_pin_set(unsigned int gpio_id, unsigned int ie_oe, unsigned int pull_down)
{
	u32 i = 0,val = 0;

	for(i = 0; i < sizeof(gpio_fun_pin)/sizeof(gpio_fun_pin[0]); i++) {
		if (gpio_id == gpio_fun_pin[i].gpio_id) {
			/*set gpio function*/
			val = __raw_readl(gpio_fun_pin[i].pin_offset + CTL_PIN_BASE);
			val &= ~PIN_FUNC_MASK;
			val |= 0x30;
			__raw_writel(val, (gpio_fun_pin[i].pin_offset + CTL_PIN_BASE));

			/*set ie/oe and wpu/wpd*/
			val = __raw_readl(gpio_fun_pin[i].pin_offset + CTL_MISC_PIN_BASE);
			val &= ~(BIT_PIN_IE_OE_MASK|BIT_PIN_WPDUS_MASK);
			if (ie_oe > 2 || ie_oe < 0)
				printf("ie_oe error, ie_oe = %d\n", ie_oe);
			val |= ie_oe;
			switch (pull_down) {
				case PIN_NULL:
					break;
				case PIN_DOWN:
					val |= (BIT_PIN_WPD | BIT_PIN_SLP_WPD);
					break;
				case PIN_UP_4_7K:
					val |= (BIT_PIN_WPUS | BIT_PIN_SLP_WPU);
					break;
				case PIN_UP_20K:
					val |= (BIT_PIN_WPU | BIT_PIN_SLP_WPU);
					break;
				case PIN_UP_1_8K:
					val |= (BIT_PIN_WPUS | BIT_PIN_WPU | BIT_PIN_SLP_WPU);
					break;
				default:
					printf("pull_down error, pull_down = %d\n", pull_down);
					return -1;
			}
			__raw_writel(val, (gpio_fun_pin[i].pin_offset + CTL_MISC_PIN_BASE));
			return 0;
		}
	}
	printf("gpio_id error, gpio_id = %d\n", gpio_id);
	return -1;
}
