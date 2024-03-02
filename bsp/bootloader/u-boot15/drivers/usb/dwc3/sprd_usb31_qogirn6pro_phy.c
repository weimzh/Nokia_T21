/**
 * sprd_usb31_phy.c - UNISOC USB31 PHY config file
 *
 * Copyright (C) 2020 UNISOC  - http://www.unisoc.com
 *
 * Authors: Westbobo.zhou <westbobo.zhou@unisoc.com>,
 *
 * SPDX-License-Identifier:     GPL-2.0
 */

#include <common.h>
#include <malloc.h>
#include <asm/arch/sprd_reg.h>
#include <asm/io.h>
#include <sprd_regulator.h>
#include "linux-compat.h"

#define USBDP_APB_SLV		(0x31810000)
#define USB_DPTX_REG		(0x31890000)
#define USB_TCA_REG		(0x25310000)

#define DISPC1_GLB_APB		(0x31800000)
#define DISPC1_GLB_APB_EB	(DISPC1_GLB_APB)
#define DISPC1_GLB_APB_RST	(DISPC1_GLB_APB + 0x4)

#define TOP_DVFS_BASE		(0x64940000)
#define TOP_DVFS_CFG0		(TOP_DVFS_BASE + 0xe08)
#define TOP_DVFS_CFG1		(TOP_DVFS_BASE + 0xe0c)

#define PHY_INIT_TIMEOUT 500

static void usb_enable(void)
{
	u32 val;
	u32 reg;
	int retries;

	/*enable analog:0x64900004*/
	val = readl(REG_AON_APB_APB_EB1);
	val |= BIT_AON_APB_AON_USB2_TOP_EB | BIT_AON_APB_OTG_PHY_EB | BIT_AON_APB_ANA_EB;
	writel(val, REG_AON_APB_APB_EB1);

	/* select aon usb or ipa usb
		1:ipa usb
		0:aon usb
	*/
	val = readl(REG_AON_APB_AON_SOC_USB_CTRL);
	val |= BIT_AON_APB_USB20_CTRL_MUX_REG;
	writel(val, REG_AON_APB_AON_SOC_USB_CTRL);

	/* bit0:1 dpu dpi clock enable
	   bit1:1 dptx enable
	   bit3:1 combphy tca enable
	   bit4:1 usb31 pll enable
		0x0x31800000
	*/
	val = readl(DISPC1_GLB_APB_EB);
	val |= BIT(0) | BIT(1) | BIT(3) | BIT(4);
	writel(val, DISPC1_GLB_APB_EB);

	/* utmisrp_bvalid  sys vbus valid:0x64900D14*/
	val = readl(REG_AON_APB_USB31DPCOMBPHY_CTRL);
	val |= BIT_AON_APB_SYS_VBUSVALID;
	writel(val, REG_AON_APB_USB31DPCOMBPHY_CTRL);

	/*  usb eb and usb ref eb :0x25000004*/
	val = readl(REG_IPA_APB_IPA_EB);
	val |= BIT_IPA_APB_USB_EB | BIT_IPA_APB_USB_REF_EB;
	writel(val, REG_IPA_APB_IPA_EB);

	/* usb suspend eb :0x64900138*/
	val = readl(REG_AON_APB_CGM_REG1);
	val |= BIT_AON_APB_CGM_USB_SUSPEND_EN;
	writel(val, REG_AON_APB_CGM_REG1);

	/* set phy0 sram bypass */
	val = readl(USBDP_APB_SLV + 0x48);
	val |= BIT(24);
	writel(val, USBDP_APB_SLV + 0x48);

	retries = PHY_INIT_TIMEOUT;
	do {
		/* wait phy_sram init down check bit2=1 */
		val = readl(USBDP_APB_SLV + 0x74);
		if ((val & BIT(2)) == BIT(2)) {
			debugf("phy sram init successfully\n");
			break;
		} else {
			udelay(1000);
		}
	} while(--retries);
	if (!retries)
		debugf("USB PHY SRAM init failed\n");

	/* REG_TYPEC_CTRL: TYPEC_DISABLE_ACK */
	val = readl(USB_DPTX_REG + 0xc08);
	val |= BIT(0);
	writel(val, USB_DPTX_REG + 0xc08);

	/* TCA GCFG
	bit1:0 => 2b01 op_mode = controller synced mode
	bit3:2 => 2b00 reserved
	bit4 = 1 => USB device mode
	Bit31:5 => 0x0
	*/
	val = readl(USB_TCA_REG + 0x010);
	val &= ~(0xffffffc0);
	writel(val, USB_TCA_REG + 0x010);
	val = readl(USB_TCA_REG + 0x010);
	val |= BIT(0) | BIT(4);
	writel(val, USB_TCA_REG + 0x010);

	/* TCA CTRLSYNCMODE CFG0 */
	val = readl(USB_TCA_REG + 0x20);
	val |= BIT(1) | BIT(2);
	writel(val, USB_TCA_REG + 0x20);

	/*  TCA CTRLSYNCMODE CFG1 */
	val = 0x3d090;
	writel(val, USB_TCA_REG + 0x24);

	/* clear TCA int status */
	val = 0xffff;
	writel(val, USB_TCA_REG + 0x08);

	/* TCA INT EN
	xa_ack_event_en =1
	xa_timeout_event_en=1
	*/
	val = readl(USB_TCA_REG + 0x04);
	val |= BIT(0) | BIT(1);
	writel(val, USB_TCA_REG + 0x04);

	/* usb3 switch port */
	reg = readl(REG_AON_APB_BOOT_MODE);
	val = readl(USB_TCA_REG + 0x14);
	if ( (reg & BIT(10)) == BIT(10)) {
		val &= ~(BIT(1) | BIT(2) | BIT(3));
		val |= BIT(0) | BIT(4);
	} else {
		val &= ~(BIT(1) | BIT(3));
		val |= BIT(0) | BIT(2) | BIT(4);
	}
	writel(val, USB_TCA_REG + 0x14);

	retries = PHY_INIT_TIMEOUT;
	do {
		/* wait tca interrupt */
		val = readl(USB_TCA_REG + 0x08);
		if ((val & BIT(0)) == BIT(0) || (val & BIT(1)) == BIT(1)) {
			writel(0xffff, USB_TCA_REG + 0x08);
			debugf("tca interrupt ready\n");
			break;
		} else {
			udelay(1000);
		}
	} while (--retries);
	if (!retries)
		debugf("tca interrupt not ready\n");

	/* TCA VBUS CTRL */
	val = readl(USB_TCA_REG + 0x40);
	val &= ~(BIT(0) | BIT(2));
	val |= BIT(1) | BIT(3);
	writel(val, USB_TCA_REG + 0x40);

	/* PMA power off */
	/* phy_reset 50ns  */
	reg = readl(DISPC1_GLB_APB_RST);
	reg |= BIT(4);
	writel(reg, DISPC1_GLB_APB_RST);

	/* PHY_TEST_POWERDOWN:0x64900d14 */
	reg = readl(REG_AON_APB_USB31DPCOMBPHY_CTRL);
	reg |= BIT(1);
	writel(reg, REG_AON_APB_USB31DPCOMBPHY_CTRL);

	/* PMA power on */
	/* phy_reset 50ns  */
	reg = readl(DISPC1_GLB_APB_RST);
	reg |= BIT(4);
	writel(reg, DISPC1_GLB_APB_RST);
	/* PHY_TEST_POWERDOWN:0x64900d14 */
	reg = readl(REG_AON_APB_USB31DPCOMBPHY_CTRL);
	reg &= ~BIT(1);
	writel(reg, REG_AON_APB_USB31DPCOMBPHY_CTRL);
	/* keep 0 10us */
	udelay(10);
	reg = readl(DISPC1_GLB_APB_RST);
	reg &= ~BIT(4);
	writel(reg, DISPC1_GLB_APB_RST);
}

static void usb_disable()
{
	u32 val;

	/* bit0:0 dpu dpi clock disable
	   bit1:0 dptx disable
	   bit3:0 combphy tca disable
	   bit4:0 usb31 pll disable
	*/
	val = readl(DISPC1_GLB_APB_EB);
	val &= ~(BIT(0) | BIT(1) | BIT(3) | BIT(4));
	writel(val, DISPC1_GLB_APB_EB);

	/*  usb eb and usb ref eb */
	val = readl(REG_IPA_APB_IPA_EB);
	val &= ~(BIT_IPA_APB_USB_EB | BIT_IPA_APB_USB_REF_EB);
	writel(val, REG_IPA_APB_IPA_EB);

}

void usb_phy_enable(u32 is_on)
{
	if (is_on) {
		usb_enable();
	} else {
		usb_disable();
	}
}

