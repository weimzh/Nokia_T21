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

#include <common.h>
#include <malloc.h>
#include <fdtdec.h>
#include <logo_bin.h>
//20220609, Added by zhu_jun for logo display feature begin
#include <sprd_common_rw.h>
//20220609, Added by zhu_jun for logo display feature end
#include "loader_common.h"
#include "sprd_dispc.h"
#ifdef CONFIG_ROUND_CORNER_SUPPORT
#include "sprd_round_corner.h"
#endif

DECLARE_GLOBAL_DATA_PTR;

int logo_index = 0;
unsigned long bmp_size;
int logo_type;

void *lcd_get_base_addr(void *lcd_base)
{
	return (void *)gd->fb_base;
}

static void logo_flip(void)
{
	struct sprd_dispc *dispc = &dispc_device;
	struct sprd_restruct_config *config;
	struct panel_info *panel = panel_info_attach();
	uint8_t logo_bpp = panel_info.vl_bpix > 16 ? 4 : 2;

	config = malloc(sizeof(struct sprd_restruct_config) +
			sizeof(struct sprd_adf_hwlayer));
	if (config == NULL)
		return;

	config->number_hwlayer = 1;
	config->hwlayers[0].hwlayer_id = 0;
	config->hwlayers[0].iova_plane[0] = gd->fb_base;
	config->hwlayers[0].n_planes = 1;
	config->hwlayers[0].alpha = 0xFF;
	config->hwlayers[0].pitch[0] = panel->width * logo_bpp;
	config->hwlayers[0].dst_w = panel->width;
	config->hwlayers[0].dst_h = panel->height;
	config->hwlayers[0].dst_x = 0;
	config->hwlayers[0].dst_y = 0;
	config->hwlayers[0].start_x = 0;
	config->hwlayers[0].start_y = 0;
	config->hwlayers[0].start_w = 0;
	config->hwlayers[0].start_h = 0;
	config->hwlayers[0].blending = HWC_BLENDING_NONE;
	config->hwlayers[0].compression = 0;
	config->hwlayers[0].format = logo_bpp == 2 ?
		DRM_FORMAT_RGB565 : DRM_FORMAT_ARGB8888;

	sprd_dispc_flip(dispc, config);

	free(config);
}

int get_fb_base_from_dt(void)
{
	int phandle;
	const char *label;
	unsigned long base, size, offset;
	const void *fdt_blob = gd->fdt_blob;
	struct panel_info *panel = panel_info_attach();
	int nodeoffset;

	nodeoffset = fdt_path_offset(fdt_blob, "/ion");
	if (nodeoffset == -FDT_ERR_NOTFOUND) {
		pr_err("Failed to find /ion node\n");
		return -1;
	}

	nodeoffset = fdt_subnode_offset(fdt_blob, nodeoffset, "heap@3");
	if (nodeoffset == -FDT_ERR_NOTFOUND) {
		pr_err("Failed to find heap@3 sub node\n");
		return -1;
	}

	label = fdt_getprop(fdt_blob, nodeoffset, "label", NULL);
	if (label == NULL) {
		pr_err("Failed to decode label property\n");
		return -1;
	}

	phandle = fdtdec_lookup_phandle(fdt_blob, nodeoffset, "memory-region");
	if (phandle == -FDT_ERR_NOTFOUND) {
		pr_err("Failed to decode memory-region property\n");
		return -1;
	}

	if (fdtdec_decode_region(fdt_blob, phandle, "reg", &base, &size)) {
		pr_err("Failed to decode reg property\n");
		return -EINVAL;
	}

	/*
	 * For carveout_logo, it is wb_reserved memory.
	 * Which is not used by kernel ion module. So it
	 * will not be cleared by ion driver.
	 */
	if (!strcmp(label, "carveout_logo")) {
		gd->fb_base = base;
		return 0;
	}

	/*
	 * For carveout_fb, it is fb_reserved memory.
	 * We use the third reserved buffer for uboot logo,
	 * and the first reserved buffer is for write back.
	 */
	offset = panel->width * panel->height * 4 * 2;
	gd->fb_base = ALIGN(base + offset, 32);

	return 0;
}

int get_bmp_base_from_dt(void **bmp_base)
{
	int phandle;
	const char *label;
	unsigned long base, size;
	const void *fdt_blob = gd->fdt_blob;
	int nodeoffset;

	nodeoffset = fdt_path_offset(fdt_blob, "/ion");
	if (nodeoffset == -FDT_ERR_NOTFOUND) {
		pr_err("Failed to find /ion node\n");
		return -1;
	}

	nodeoffset = fdt_subnode_offset(fdt_blob, nodeoffset, "heap@9");
	if (nodeoffset == -FDT_ERR_NOTFOUND) {
		pr_err("Failed to find heap@9 sub node\n");
		return -1;
	}

	label = fdt_getprop(fdt_blob, nodeoffset, "label", NULL);
	if (label == NULL) {
		pr_err("Failed to decode label property\n");
		return -1;
	}

	phandle = fdtdec_lookup_phandle(fdt_blob, nodeoffset, "memory-region");
	if (phandle == -FDT_ERR_NOTFOUND) {
		pr_err("Failed to decode memory-region property\n");
		return -1;
	}

	if (fdtdec_decode_region(fdt_blob, phandle, "reg", &base, &size)) {
		pr_err("Failed to decode reg property\n");
		return -EINVAL;
	}

	if (strcmp(label, "carveout_bmp")) {
		pr_err("Error label %s, we need carveout_bmp\n", label);
		return -ENOMEM;
	}

	*bmp_base = base;
	bmp_size = size;

	return 0;
}

static int sprdfb_probe(void)
{
	sprd_panel_probe();
	sprd_dispc_probe();

	return 0;
}

void lcd_disable(void)
{
	pr_info("lcd disable\n");
}

void lcd_enable(void)
{
#ifdef CONFIG_ROUND_CORNER_SUPPORT
	struct panel_info *panel = panel_info_attach();
	dispc_logo_show_corner(panel->height, panel->width, gd->fb_base);
	lcd_set_flush_dcache(TRUE);
	lcd_sync();
#endif
	pr_info("start flip\n");
	logo_flip();
}

void lcd_ctrl_init(void *lcdbase)
{
	int ret;

	sprdfb_probe();

	ret = logo_mem_init();
	if (ret) {
		printf("logo memory init failed.\n");
		return;
	}

	printf("logo memory init success.\n");
	lcd_set_flush_dcache(TRUE);
}

int logo_mem_init(void)
{
	u32 bmp_header_size = 8192;
	char *s;
	ulong addr;
	void *temp_logo_addr;

	get_fb_base_from_dt();
	bmp_size = panel_info.vl_col * panel_info.vl_row * panel_info.vl_bpix / 8 + bmp_header_size;
	printf("bmp_size = %lu.\n", bmp_size);
	if (get_bmp_base_from_dt(&temp_logo_addr)) {
		pr_err("can not found bmp_reserved node in dts, use malloc instead\n");
		temp_logo_addr = malloc(bmp_size);
	}

	if (!temp_logo_addr) {
		pr_err("failed to alloc bmp space\n");
		return -1;
	}

	setenv_hex("splashimage", (ulong)temp_logo_addr);
	s = getenv("splashimage");
	if(s == NULL){
		pr_err("splashimage addr is NULL\n");
		setenv("splashimage",NULL);
		free(temp_logo_addr);
		return -1;
	}

	addr = simple_strtoul(s, NULL, 16);
	pr_info("splashimage addr is 0x%p, fb size is 0x%x\n", (void *)addr, bmp_size);

	return 0;
}

void logo_display(int index, int backlight_value, int lcd_enable)
{
	extern uint32_t uboot_start_time;
	uint32_t lcd_init_time;
	uint32_t backlight_on_time;
	uint32_t uboot_consume_time;

	//20220609, Added by zhu_jun for logo display feature begin
	char strSkuid[12] = {0};

	get_hmd_product_info(HMDINFO_SKUID, strSkuid, sizeof(strSkuid)-1);
	printf("logo_display: index=%d, skuid=%s \n", index, strSkuid);
	if(!strcmp(strSkuid,"600RU") && (index==LOGO_NORMAL_POWER)) {
		logo_index = index + 1;
	}
	else {
		logo_index = index;
	}
	//20220609, Added by zhu_jun for logo display feature end

#ifdef CONFIG_SPLASH_SCREEN
	lcd_init_time = SCI_GetTickCount();
	printf("lcd start init time:%dms\n", lcd_init_time);
 	if(lcd_enable) {
		extern void lcd_enable(void);
		debug("[LCD] Drawing the logo...\n");
		drv_lcd_init();
		lcd_splash(LOGO_PART);
		lcd_enable();
	}
#ifdef CONFIG_SPRD_SOC_SP9853I
	else {
		/*if no lcd in cali mode, turn off the cam_eb bit*/
		char *boot_mode_type_str;

		boot_mode_type_str = getenv("bootmode");
		if(!strncmp(boot_mode_type_str, "cali", 4)) {
			sci_glb_clr(REG_AON_APB_APB_EB1, BIT_AON_APB_AON_CAM_EB);
		}
	}
#endif
	set_backlight(backlight_value);
	backlight_on_time = SCI_GetTickCount();
	lcd_init_time= backlight_on_time - lcd_init_time;
	uboot_consume_time = backlight_on_time - uboot_start_time;
	printf("uboot consume time:%dms, lcd init consume:%dms, backlight on time:%dms \n", \
		uboot_consume_time, lcd_init_time, backlight_on_time);
#endif
}

int get_logo_bin_info(u8 *bmp, uchar *logo_part_name)
{
	u8 bpix;
	u32 in_size = 0;
	u32 header_size = 128;
	unsigned long inout_size;
	int ret, i, count;
	u8 *s;
	u8 *bmp_addr;
	u8 *gz_addr;
	u32 offset = 0;
	struct header_info *header;

	struct bmp_image *temp_bmp = (struct bmp_image*)bmp;
	if ((temp_bmp->header.signature[0] == 'B') && (temp_bmp->header.signature[1] == 'M')) {
		bpix = bmp_get_bpix(bmp);
		logo_type = LOGO_TYPE_BMP;
		debug("logo type: bmp file .\n");
	} else {
		header = (struct header_info*)bmp;
		count = header->file_number;
		header_size = count * sizeof(uint32_t) + sizeof(struct header_info);
		if (0 != common_raw_read(logo_part_name, (uint64_t)header_size, (uint64_t)0, (u8 *)header)) {
			debug("failed to read logo partition:%s\n", logo_part_name);
			return -1;
		}

		in_size = header->gz_size[logo_index];
		gz_addr = malloc(in_size);
		offset += header_size;
		for (i = 0; i < logo_index; i++) {
			offset += header->gz_size[i];
		}

		s = getenv("splashimage");
		if (!s) {
			debugf("failed to get env from splashimage\n");
			return -1;
		}

		bmp_addr = (u8 *) simple_strtoul(s, NULL, 16);
		if (0 != common_raw_read(logo_part_name, (uint64_t)in_size, (uint64_t)offset, gz_addr)) {
			debug("failed to read logo partition:%s\n", logo_part_name);
			return -1;
		}

		inout_size = in_size;
		ret = gunzip((void *)bmp_addr, bmp_size, (void *)gz_addr, &inout_size);
		free(gz_addr);
		if (ret != 0) {
			debugf("gunzip failed %d.\n", ret);
			return -1;
		}

		temp_bmp = (struct bmp_image*)bmp_addr;
		bpix = temp_bmp->header.bit_count;
		printf("temp_bmp->header.bit_count :%d.\n", bpix);
		logo_type = LOGO_TYPE_BIN;
		debug("logo type: bin file .\n");
	}

	return bpix;
}