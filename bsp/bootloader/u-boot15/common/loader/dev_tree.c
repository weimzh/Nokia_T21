/* Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * * Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided
 *  with the distribution.
 *   * Neither the name of The Linux Foundation nor the names of its
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <libfdt.h>
#include <config.h>
#include "dev_tree.h"
#include "common.h"
//#include <lib/ptable.h>
#include <malloc.h>
//#include <qpic_nand.h>
//#include <stdlib.h>
//#include <string.h>
//#include <platform.h>
//#include <board.h>



//extern uint32_t target_dev_tree_mem(void *fdt, uint32_t memory_node_offset);
uint32_t target_dev_tree_mem(void *fdt, uint32_t memory_node_offset)
{
	return -1;
}
#if 0
/* TODO: This function needs to be moved to target layer to check violations
 * against all the other regions as well.
 */
extern int check_aboot_addr_range_overlap(uint32_t start, uint32_t size);

/*
 * Will relocate the DTB to the tags addr if the device tree is found and return
 * its address
 *
 * Arguments:    kernel - Start address of the kernel loaded in RAM
 *               tags - Start address of the tags loaded in RAM
 *               kernel_size - Size of the kernel in bytes
 *
 * Return Value: DTB address : If appended device tree is found
 *               'NULL'         : Otherwise
 */
void *dev_tree_appended(void *kernel, void *tags, uint32_t kernel_size)
{
	uint32_t app_dtb_offset = 0;
	uint32_t size;

	memcpy((void*) &app_dtb_offset, (void*) (kernel + DTB_OFFSET), sizeof(uint32_t));

	/*
	 * Check if we have valid offset for the DTB, if not return error.
	 * If the kernel image does not have appeneded device tree, DTB offset
	 * might contain some random address which is not accessible & cause
	 * data abort. If kernel start + dtb offset address exceed the total
	 * size of the kernel, then we dont have an appeneded DTB.
	 */
	if (app_dtb_offset < kernel_size)
	{
		if (!fdt_check_header((void*) (kernel + app_dtb_offset)))
		{
			void *dtb;
			int rc;

			debugf( "Found Appeneded Flattened Device tree\n");
			dtb = kernel + app_dtb_offset;
			size = fdt_totalsize(dtb);
			if (check_aboot_addr_range_overlap(tags, size))
			{
				debugf("Appended dtb aboot overlap check failed.\n");
				return NULL;
			}
			rc = fdt_open_into(dtb, tags, size);
			if (rc == 0)
			{
				/* clear out the old DTB magic so kernel doesn't find it */
				*((uint32_t *)dtb) = 0;
				return tags;
			}
		}
	}
	else
		debugf( "DTB offset is incorrect, kernel image does not have appended DTB\n");

	return NULL;
}
#endif
/* Function to return the pointer to the start of the correct device tree
 *  based on the platform data.
 */
struct dt_entry * dev_tree_get_entry_ptr(struct dt_table *table)
{
	uint32_t i;
	struct dt_entry *dt_entry_ptr;
	struct dt_entry *latest_dt_entry = NULL;

	dt_entry_ptr = (struct dt_entry *)((char *)table + DEV_TREE_HEADER_SIZE);

	debugf("magic=%x,ver=%d,num=%d\n",table->magic,table->version,table->num_entries);

	for(i = 0; i < table->num_entries; i++)
	{
		debugf("platform_id=%d,v=%x,rev=%x\n",dt_entry_ptr->platform_id,dt_entry_ptr->variant_id,dt_entry_ptr->soc_rev);
		/* DTBs are stored in the ascending order of soc revision.
		 * For eg: Rev0..Rev1..Rev2 & so on.
		 * we pickup the DTB with highest soc rev number which is less
		 * than or equal to actual hardware
		 */
		if((dt_entry_ptr->platform_id == DT_PLATFROM_ID) &&
		   (dt_entry_ptr->variant_id == DT_HARDWARE_ID) &&
		   (dt_entry_ptr->soc_rev == DT_SOC_VER))
			{
				return dt_entry_ptr;
			}
		/* if the exact match not found, return the closest match
		 * assuming it to be the nearest soc version
		 */
		if((dt_entry_ptr->platform_id == DT_PLATFROM_ID) &&
		  (dt_entry_ptr->variant_id == DT_HARDWARE_ID) &&
		  (dt_entry_ptr->soc_rev <= DT_SOC_VER)) {
			latest_dt_entry = dt_entry_ptr;
		}
		dt_entry_ptr++;
	}

	if (latest_dt_entry) {
		debugf( "Loading DTB with SOC version:%x\n", latest_dt_entry->soc_rev);
		return latest_dt_entry;
	}

	return NULL;
}

int load_dtb(uint64_t addr,void* dt_img_adr)
{
	struct dt_table *table;
	struct dt_entry *dt_entry_ptr;

	/* offset now point to start of dt.img */
	table = (struct dt_table*)dt_img_adr;

	/* Restriction that the device tree entry table should be less than a page*/
	//ASSERT(((table->num_entries * sizeof(struct dt_entry))+ DEV_TREE_HEADER_SIZE) < hdr->page_size);

	/* Validate the device tree table header */
	if((table->magic != DEV_TREE_MAGIC) && (table->version != DEV_TREE_VERSION)) {
		debugf("ERROR: Cannot validate Device Tree Table \n");
		return -1;
	}

	/* Calculate the offset of device tree within device tree table */
	if((dt_entry_ptr = dev_tree_get_entry_ptr(table)) == NULL){
		debugf("ERROR: Getting device tree address failed\n");
		return -1;
	}

	/* Validate and Read device device tree in the "tags_add */
	//if (check_aboot_addr_range_overlap(hdr->tags_addr, dt_entry_ptr->size))
	//{
	//      debugf("Device tree addresses overlap with aboot addresses.\n");
	//      return -1;
	//}

	memcpy((void*)addr,(const void*)(dt_img_adr +  dt_entry_ptr->offset), dt_entry_ptr->size);

	return 0;
}


#if 0
/* Function to add the first RAM partition info to the device tree.
 * Note: The function replaces the reg property in the "/memory" node
 * with the addr and size provided.
 */
int dev_tree_add_first_mem_info(uint32_t *fdt, uint32_t offset, uint32_t addr, uint32_t size)
{
	int ret;

	ret = fdt_setprop_u32(fdt, offset, "reg", addr);

	if (ret)
	{
		debugf( "Failed to add the memory information addr: %d\n",
				ret);
	}


	ret = fdt_appendprop_u32(fdt, offset, "reg", size);

	if (ret)
	{
		debugf( "Failed to add the memory information size: %d\n",
				ret);
	}

	return ret;
}

/* Function to add the subsequent RAM partition info to the device tree. */
int dev_tree_add_mem_info(void *fdt, uint32_t offset, uint32_t addr, uint32_t size)
{
	static int mem_info_cnt = 0;
	int ret;

	if (!mem_info_cnt)
	{
		/* Replace any other reg prop in the memory node. */
		ret = fdt_setprop_u32(fdt, offset, "reg", addr);
		mem_info_cnt = 1;
	}
	else
	{
		/* Append the mem info to the reg prop for subsequent nodes.  */
		ret = fdt_appendprop_u32(fdt, offset, "reg", addr);
	}

	if (ret)
	{
		debugf( "Failed to add the memory information addr: %d\n",
				ret);
	}


	ret = fdt_appendprop_u32(fdt, offset, "reg", size);

	if (ret)
	{
		debugf( "Failed to add the memory information size: %d\n",
				ret);
	}

	return ret;
}

/* Top level function that updates the device tree. */
int update_device_tree(void *fdt, const char *cmdline,
					   void *ramdisk, uint32_t ramdisk_size)
{
	int ret = 0;
	uint32_t offset;

	/* Check the device tree header */
	ret = fdt_check_header(fdt);
	if (ret)
	{
		debugf( "Invalid device tree header \n");
		return ret;
	}

	/* Add padding to make space for new nodes and properties. */
	ret = fdt_open_into(fdt, fdt, fdt_totalsize(fdt) + DTB_PAD_SIZE);
	if (ret!= 0)
	{
		debugf( "Failed to move/resize dtb buffer: %d\n", ret);
		return ret;
	}

	/* Get offset of the memory node */
	ret = fdt_path_offset(fdt, "/memory");
	if (ret < 0)
	{
		debugf( "Could not find memory node.\n");
		return ret;
	}

	offset = ret;

	ret = target_dev_tree_mem(fdt, offset);
	if(ret)
	{
		debugf( "ERROR: Cannot update memory node\n");
		return ret;
	}

	/* Get offset of the chosen node */
	ret = fdt_path_offset(fdt, "/chosen");
	if (ret < 0)
	{
		debugf("Could not find chosen node.\n");
		return ret;
	}

	offset = ret;
	/* Adding the cmdline to the chosen node */
	ret = fdt_setprop_string(fdt, offset, (const char*)"bootargs", (const void*)cmdline);
	if (ret)
	{
		debugf( "ERROR: Cannot update chosen node [bootargs]\n");
		return ret;
	}

	/* Adding the initrd-start to the chosen node */
	ret = fdt_setprop_u32(fdt, offset, "linux,initrd-start", (uint32_t)ramdisk);
	if (ret)
	{
		debugf( "ERROR: Cannot update chosen node [linux,initrd-start]\n");
		return ret;
	}

	/* Adding the initrd-end to the chosen node */
	ret = fdt_setprop_u32(fdt, offset, "linux,initrd-end", ((uint32_t)ramdisk + ramdisk_size));
	if (ret)
	{
		debugf( "ERROR: Cannot update chosen node [linux,initrd-end]\n");
		return ret;
	}

	fdt_pack(fdt);

	return ret;
}
#endif
