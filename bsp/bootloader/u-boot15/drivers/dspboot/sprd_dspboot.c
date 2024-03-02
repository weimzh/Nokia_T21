/*
 * Copyright (C) 2019 Spreadtrum Communications Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#undef DEBUG

#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <fdtdec.h>
#include "dspboot.h"

#include <asm/types.h>
#include <asm/io.h>
#include <common.h>
#include <dm.h>
#include <mapmem.h>
#include <dm/of_access.h>

enum {
	AUDCPBOOT_CTRL_SYS_SHUTDOWN,
	AUDCPBOOT_CTRL_DEEP_SLEEP,
	AUDCPBOOT_CTRL_AUTO_SHUTDOWN,
	AUDCPBOOT_CTRL_BOOTPROTECT,
	AUDCPBOOT_CTRL_BOOTVECTOR,
	AUDCPBOOT_CTRL_BOOTADDRESSSEL,
	AUDCPBOOT_CTRL_SYS_RESET,
	AUDCPBOOT_CTRL_CORE_RESET,
	AUDCPBOOT_CTRL_RESET_SEL,

	AUDCPBOOT_CTRL_MAX,
};

static char * const bootctrl_name[AUDCPBOOT_CTRL_MAX] = {
	[AUDCPBOOT_CTRL_SYS_SHUTDOWN] = "sysshutdown",
	[AUDCPBOOT_CTRL_DEEP_SLEEP] = "deepsleep",
	[AUDCPBOOT_CTRL_AUTO_SHUTDOWN] = "autoshutdown",
	[AUDCPBOOT_CTRL_BOOTPROTECT] = "bootprotect",
	[AUDCPBOOT_CTRL_BOOTVECTOR] = "bootvector",
	[AUDCPBOOT_CTRL_BOOTADDRESSSEL] = "bootaddress_sel",
	[AUDCPBOOT_CTRL_SYS_RESET] = "sysreset",
	[AUDCPBOOT_CTRL_CORE_RESET] = "corereset",
	[AUDCPBOOT_CTRL_RESET_SEL] = "reset_sel",
};

struct dsp_boot_priv {
	struct dspboot_desc desc[AUDCPBOOT_CTRL_MAX];
};

static int dsp_boot_parse_dt(struct udevice *dev)
{
	struct dsp_boot_priv *priv = dev_get_priv(dev);

	return dspboot_read_list(dev, bootctrl_name, AUDCPBOOT_CTRL_MAX, priv->desc);
}

static int dsp_boot_probe(struct udevice *dev)
{
	int ret;

	debug("%s entry\n", __func__);

	ret = dsp_boot_parse_dt(dev);

	if (ret) {
		errorf("dsp_boot_parse_dt fail ret=0x%x\n", ret);
		return ret;
	}

	return 0;
}

int sprd_dspboot_test(void)
{
	int ret;

	/*
	 *	P:18000100|D7E67300D7EE1320                                   mov  ##-0x2811ECE0,r0
	 *	P:18000104|D7E6DB0018000400                                   st   r0,[##0x18000400].dw
	 *	P:18000108|0000                                               nop
	 *	P:18000109|0000                                               nop
	 *	P:1800010A|D7E6730400000000                                   mov  ##0x0,r4
	 *	P:1800010E|D7E6730018000500                                   mov  ##0x18000500,r0
	 *	P:18000112|6A28                                               movd (r0)+,(r4)+
	 *	P:18000113|6A28                                               movd (r0)+,(r4)+
	 *	...
	 *	P:18000127|6A28                                               movd (r0)+,(r4)+
	 *	P:18000128|D7E67300AAAAAAAA                                   mov  ##-0x55555556,r0
	 *	P:1800012C|D7E6DB0018000140                                   st   r0,[##0x18000140].dw
	 *	P:18000130|D7EE1320FFFFFFFC                                   brr{nt}_0x18000130,true
	 *	GOSUB write_boot_code (&CODE_BASE_I)      0xd7ee1320 0xd7e67300 0x18000400 0xd7e6db00
	 *	GOSUB write_boot_code (&CODE_BASE_I+0x10) 0xd7e67304 0x0 0xd7e67300 0x0
	 *	GOSUB write_boot_code (&CODE_BASE_I+0x20) 0x6a286a28 (((&DSP_BASE_I)+0x300)/2) 0x6a286a28 0x6a286a28
	 *	GOSUB write_boot_code (&CODE_BASE_I+0x30) 0x6a286a28 0x6a286a28 0x6a286a28 0x6a286a28
	 *	GOSUB write_boot_code (&CODE_BASE_I+0x40) 0x6a286a28 0x6a286a28 0x6a286a28 0x6a286a28
	 *	;raise the freq for tgdsp
	 *	GOSUB write_boot_code (&CODE_BASE_I+0x50) 0x3 0xd7e67300 (0x015D0020/2) 0xd7e6db00
	 *	;write 0xAAAAAAAA to (&DSP_BASE_I)+0x80)
	 *	GOSUB write_boot_code (&CODE_BASE_I+0x60) 0xAAAAAAAA 0xD7E67300 (((&DSP_BASE_I)+0x80)/2) 0xD7E6DB00
	 *	;while(1)
	 *	GOSUB write_boot_code (&CODE_BASE_I+0x70) 0xFFFFFFFC 0xd7ee1320 0x0 0x0
	 *	;prepare while(1) data
	 *	GOSUB write_boot_code (&CODE_BASE_I+0x300) 0x0000a700 0x0002a700 0x0004a700 0x0006a700
	 *	GOSUB write_boot_code (&CODE_BASE_I+0x310) 0x0008a700 0x000aa700 0x000ca700 0x000ea700
	 *	RETURN
	 */

	static u32 s_dsp_code[1024] = {
		0xd7ee1320, 0xd7e67300, 0/*0x18000400*/, 0xd7e6db00,
		0xd7e67304, 0x0, 0xd7e67300, 0x0,
		0x6a286a28, 0x0/*(((&DSP_BASE_I)+0x300)/2)*/, 0x6a286a28, 0x6a286a28,
		0x6a286a28, 0x6a286a28, 0x6a286a28, 0x6a286a28,
		0x6a286a28, 0x6a286a28, 0x6a286a28, 0x6a286a28,
		0x3, 0xd7e67300, (0x015D0020/2), 0xd7e6db00,
		0xAAAAAAAA, 0xD7E67300, 0/*(((&DSP_BASE_I)+0x80)/2)*/, 0xD7E6DB00,
		0xFFFFFFFC, 0xd7ee1320, 0x0, 0x0,
		0x0000a700, 0x0002a700, 0x0004a700, 0x0006a700,
		0x0008a700, 0x000aa700, 0x000ca700, 0x000ea700,
	};
	const u32 dsp_base = s_dsp_code;
	const u32 check_base = 0xA0;
	u32 check_idx = check_base/sizeof(u32);

	debug("%s entry\n", __func__);

	s_dsp_code[2] = (dsp_base + 0x800)/2;
	s_dsp_code[9] = (dsp_base + 0x80)/2;
	s_dsp_code[26] = (dsp_base + check_base)/2;

	s_dsp_code[64] = 0;
	ret = sprd_dspboot_doboot((u32)s_dsp_code/2);
	if (ret) {
		errorf("sprd_dspboot_doboot fail=%d\n", ret);
		return ret;
	}

	mdelay(1);	/* wait 1ms till dsp boot complete */

	if (s_dsp_code[check_idx]==0xAAAAAAAA) {
		debug("audcp_boot test success!\n");
	} else {
		errorf("audcp_boot test fail! dsp_base[0x%x]=0x%x\n", check_idx, s_dsp_code[check_idx]);
	}

	return 0;
}

static int dspboot_doboot(struct udevice *dev, u32 boot_vector)
{
	uint32_t index, val;
	uint32_t i = 0;
	struct dsp_boot_priv *priv = dev_get_priv(dev);

	debug("%s entry\n", __func__);

	if (!priv) {
		errorf("priv=NULL!\n");
		return -1;
	}

	/* set sys and core reset bit to 1 */
	index = AUDCPBOOT_CTRL_CORE_RESET;
	sci_glb_set(priv->desc[index].reg_addr+priv->desc[index].offset, priv->desc[index].mask);

	index = AUDCPBOOT_CTRL_SYS_RESET;
	sci_glb_set(priv->desc[index].reg_addr+priv->desc[index].offset, priv->desc[index].mask);

	/* clear audio cp sys force shutdown */
	index = AUDCPBOOT_CTRL_SYS_SHUTDOWN;
	sci_glb_clr(priv->desc[index].reg_addr+priv->desc[index].offset, priv->desc[index].mask);

	/* clear audio cp force deep sleep */
	index = AUDCPBOOT_CTRL_DEEP_SLEEP;
	sci_glb_clr(priv->desc[index].reg_addr+priv->desc[index].offset, priv->desc[index].mask);

	/* clear audio dsp auto shutdown */
	index = AUDCPBOOT_CTRL_AUTO_SHUTDOWN;
	sci_glb_clr(priv->desc[index].reg_addr+priv->desc[index].offset, priv->desc[index].mask);

	/* disable audio cp boot protect */
	index = AUDCPBOOT_CTRL_BOOTPROTECT;
	sci_glb_write(priv->desc[index].reg_addr+priv->desc[index].offset, 0x9620, priv->desc[index].mask);

	/* set boot vector */
	index = AUDCPBOOT_CTRL_BOOTVECTOR;
	sci_glb_write(priv->desc[index].reg_addr+priv->desc[index].offset, boot_vector, priv->desc[index].mask);

	/* set boot address select mode */
	index = AUDCPBOOT_CTRL_BOOTADDRESSSEL;
	sci_glb_set(priv->desc[index].reg_addr+priv->desc[index].offset, priv->desc[index].mask);

	/* release sys and core reset to boot audio cp */
	index = AUDCPBOOT_CTRL_SYS_RESET;
	sci_glb_clr(priv->desc[index].reg_addr+priv->desc[index].offset, priv->desc[index].mask);

	index = AUDCPBOOT_CTRL_CORE_RESET;
	sci_glb_clr(priv->desc[index].reg_addr+priv->desc[index].offset, priv->desc[index].mask);

	index = AUDCPBOOT_CTRL_RESET_SEL;
	sci_glb_clr(priv->desc[index].reg_addr+priv->desc[index].offset, priv->desc[index].mask);

	return 0;
}

/**
 * do dsp boot
 *
 * @param boot_vector	boot vector
 */
int sprd_dspboot_doboot(u32 boot_vector, char *str, int strlength, u32 headersize)
{
	struct udevice *dev;
	int ret;

	if (!memcmp(boot_vector, str, strlength))  //0x89000000, "SharkL5_AUDCP"
	{
		debug("%s entry\n", __func__);

		ret = dspboot_bind_driver(0, "sprd_dsp_boot", "name", &dev);
		if (ret) {
			errorf("dspboot_bind_driver fail, ret=0x%d\n", ret);
			return ret;
		}

		return dspboot_doboot(dev, (boot_vector+headersize)/2);   //(boot_vector+headersize)/2 = (0x89000000+0x00000080)/2 = 0x48000040
	}
	else
	{
		debugf("audio cp boot fail, can't find AUDCP section header!\n");
		return -1;
	}
}

static const struct udevice_id dspboot_ids[] = {
	{ .compatible = "dsp-boot" },
	{ }
};

U_BOOT_DRIVER(sprd_dsp_boot) = {
	.name	= "sprd_dsp_boot",
	.id	= UCLASS_DSPBOOT,
	.of_match = dspboot_ids,
	.priv_auto_alloc_size = sizeof(struct dsp_boot_priv),
	.probe	= dsp_boot_probe,
};
