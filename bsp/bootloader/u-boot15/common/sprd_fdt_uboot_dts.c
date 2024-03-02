/*
 * Copyright (C) 2018 Spreadtrum Communications Inc.
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
#include <fdtdec.h>
#include <errno.h>
#include <stdlib.h>

DECLARE_GLOBAL_DATA_PTR;

int get_buffer_base_size_from_dt(const char *name, unsigned long *basep, unsigned long *sizep)
{
	int phandle = 0;
	const void *fdt_blob = gd->fdt_blob;
	int nodeoffset = fdt_path_offset(fdt_blob, "/ion");

	//debugf("ion node offset = %d\n", nodeoffset);
	if (nodeoffset == -FDT_ERR_NOTFOUND)
		return -1;

	nodeoffset = fdt_subnode_offset(fdt_blob, nodeoffset, name);
	//debugf("%s node offset = %d\n", name, nodeoffset);
	if (nodeoffset == -FDT_ERR_NOTFOUND)
		return -1;

	phandle = fdtdec_lookup_phandle(fdt_blob, nodeoffset, "memory-region");
	//debugf("memory-region phandle = %d\n", phandle);
	if (phandle == -FDT_ERR_NOTFOUND)
		return -1;

	if (fdtdec_decode_region(fdt_blob, phandle, "reg", basep, sizep)) {
		errorf("Failed to decode reg property \n");
		return -EINVAL;
	}

	return 0;
}

#ifdef CONFIG_UBOOT_MULTI_DTB_SUPPORT
extern int sprd_get_dtboinfo(void);

static unsigned long udtb_copy_done = 0x5a5a0001;

__weak int board_pre_init(void)
{
	return -1;
}

unsigned int get_size_uboot_dtb(void)
{
	void *fdt = gd->fdt_blob;
	unsigned int fdt_offset = 0;

	do {
		if (fdt_check_header(fdt))
			break;
		fdt_offset += ALIGN(fdt_totalsize(fdt), 16);
		fdt = (char *)gd->fdt_blob + fdt_offset;
		debugf("fdt: %p fdt_offset %x\n", fdt, fdt_offset);
	} while (1);

	return fdt_offset;
}

void copy_udtb_to_dlbuf(void)
{
	unsigned long buf_base, buf_size;
	void *fdt = gd->fdt_blob;
	unsigned int total_sz;

#ifdef CONFIG_DTS_MEM_LAYOUT
	get_buffer_base_size_from_dt("heap@4", &buf_base, &buf_size);
#else
	buf_base = 0x82000000;
#endif
	total_sz = get_size_uboot_dtb();
	memcpy((void *)buf_base, fdt, total_sz);
	gd->fdt_blob = buf_base;
	udtb_copy_done = 1;
}

void choose_uboot_dtb(void)
{
	void *fdt = gd->fdt_blob;
	unsigned int fdt_offset = 0;
	char *scid_str = NULL, scid_str_buf[64], *tmp;
	char *hwid_str = NULL;
	char delim[] = " ";
	int node_offset;
	int board_id;
	char board_id_str[32];

	if (board_pre_init())
		return;

	board_id = sprd_get_dtboinfo();
	debugf("got board id %d\n", board_id);

try_next:
	fdt = (char *)fdt + fdt_offset;
	if (fdt_offset != 0 && fdt_check_header(fdt))
		goto out;

	fdt_offset = ALIGN(fdt_totalsize(fdt), 16);
	node_offset = fdt_path_offset(fdt, "/");
	if (node_offset == -FDT_ERR_NOTFOUND)
		goto try_next;

	/* Warning!!! could't use malloc before board_init_r */
	scid_str = fdt_getprop(fdt, node_offset, "sprd,sc-id", NULL);
	if (!scid_str)
		goto try_next;

	strncpy(scid_str_buf, scid_str, sizeof(scid_str_buf) - 1);
	scid_str_buf[sizeof(scid_str_buf) - 1] = '\0';
	tmp = scid_str_buf;

	hwid_str = strsep(&tmp, delim);
	if (hwid_str)
		hwid_str = strsep(&tmp, delim);

	if (!hwid_str)
		goto try_next;

	debugf("got hardware id %s from fdt\n", hwid_str);
	sprintf(board_id_str, "%d", board_id);
	if (strcmp(board_id_str, hwid_str))
		goto try_next;

	debugf("uboot dtb boardid find success %s,%s\n", board_id_str, hwid_str);
	/* found, update gd->fdt_blob point */
	if (fdt != gd->fdt_blob) {
		gd->fdt_blob = fdt;
		gd->fdt_size = fdt_totalsize(fdt);
		printf("found dtb %p size %d\n", gd->fdt_blob, gd->fdt_size);
	}

out:
	return;
}
#endif
