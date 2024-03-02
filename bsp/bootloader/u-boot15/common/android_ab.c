// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (C) 2017 The Android Open Source Project
 */
#include <common.h>
#include <bootloader_message.h>
#include <android_ab.h>
#include <malloc.h>
#include <linux/err.h>
#include <u-boot/crc.h>
#include <chipram_env.h>
#include <boot_mode.h>
#include <part.h>
#include "sprd_common_rw.h"

DECLARE_GLOBAL_DATA_PTR;
extern char *block_dev_get_name(void);
extern int get_buffer_base_size_from_dt(const char *name, unsigned long *basep, unsigned long *sizep);
/**
 * Compute the CRC-32 of the bootloader control struct.
 *
 * Only the bytes up to the crc32_le field are considered for the CRC-32
 * calculation.
 *
 * @param[in] abc bootloader control block
 *
 * @return crc32 sum
 */
static uint32_t ab_control_compute_crc(struct bootloader_control *abc)
{
	return crc32(0, (void *)abc, offsetof(typeof(*abc), crc32_le));
}

/**
 * Initialize bootloader_control to the default value.
 *
 * It allows us to boot all slots in order from the first one. This value
 * should be used when the bootloader message is corrupted, but not when
 * a valid message indicates that all slots are unbootable.
 *
 * @param[in] abc bootloader control block
 *
 * @return 0 on success and a negative on error
 */
static int ab_control_default(struct bootloader_control *abc)
{
	int i;
	const struct slot_metadata metadata = {
		.priority = 15,
		.tries_remaining = 7,
		.successful_boot = 0,
		.verity_corrupted = 0,
		.reserved = 0
	};

	if (!abc)
		return -EFAULT;

	memcpy(abc->slot_suffix, "_a\0\0", 4);
	abc->magic = BOOT_CTRL_MAGIC;
	abc->version = BOOT_CTRL_VERSION;
	abc->nb_slot = NUM_SLOTS;
	memset(abc->reserved0, 0, sizeof(abc->reserved0));
	for (i = 0; i < abc->nb_slot; ++i)
		abc->slot_info[i] = metadata;

	/* It is forbidden to start from slot B during initialization. */
	abc->slot_info[1].tries_remaining = 0;

	/* It is used to resolve the occurrence of the 8th failure to enter calibration mode*/
	abc->slot_info[0].successful_boot = 1;

	memset(abc->reserved1, 0, sizeof(abc->reserved1));
	abc->crc32_le = ab_control_compute_crc(abc);

	return 0;
}

/**
 * Load the boot_control struct from disk into newly allocated memory.
 *
 * @param[in] dev_desc Device where to read the boot_control struct from
 * @param[in] part_info Partition in 'dev_desc' where to read from, normally
 *			the "misc" partition should be used
 * @param[out] pointer to pointer to bootloader_control data
 * @return 0 on success and a negative on error
 */
static int ab_control_create_from_disk(char *partition_name,
				       const disk_partition_t *part_info,
				       struct bootloader_control **abc)
{
	ulong abc_offset, abc_size, ret;

	abc_offset = offsetof(struct bootloader_message_ab, slot_suffix);
	abc_size = sizeof(struct bootloader_control);
	debugf("abc offset: %lu, size: %lu\n", abc_offset, abc_size);

	if (abc_offset + abc_size > part_info->size * part_info->blksz) {
		errorf("ANDROID: boot control partition too small. Need at");
		errorf(" least size %lu but have size "LBAFU" .\n",
			abc_offset + abc_size, part_info->size);
		return -EINVAL;
	}
	*abc = malloc(abc_size);
	if (!*abc)
		return -ENOMEM;

	ret = common_raw_read(partition_name, (u64)abc_size, (u64)abc_offset, (char *)*abc);
	if (ret) {
		errorf("ANDROID: Could not read from boot ctrl partition\n");
		free(*abc);
		return -EIO;
	}

	debugf("ANDROID: Loaded ABC, size: %lu\n", abc_size);

	return 0;
}

/**
 * Store the loaded boot_control block.
 *
 * Store back to the same location it was read from with
 * ab_control_create_from_misc().
 *
 * @param[in] dev_desc Device where we should write the boot_control struct
 * @param[in] part_info Partition on the 'dev_desc' where to write
 * @param[in] abc Pointer to the boot control struct and the extra bytes after
 *                it up to the nearest block boundary
 * @return 0 on success and a negative on error
 */
static int ab_control_store(struct blk_desc *dev_desc,
			    const disk_partition_t *part_info,
			    struct bootloader_control *abc)
{
	ulong abc_offset, abc_size, ret;

	abc_offset = offsetof(struct bootloader_message_ab, slot_suffix);
	abc_size = sizeof(struct bootloader_control);
	ret = common_raw_write("misc", (u64)abc_size, 0, (u64)abc_offset, (char *)abc);
	if (ret) {
		errorf("ANDROID: Could not write back the misc partition\n");
		return -EIO;
	}

	return 0;
}

/**
 * Compare two slots.
 *
 * The function determines slot which is should we boot from among the two.
 *
 * @param[in] a The first bootable slot metadata
 * @param[in] b The second bootable slot metadata
 * @return Negative if the slot "a" is better, positive of the slot "b" is
 *         better or 0 if they are equally good.
 */
static int ab_compare_slots(const struct slot_metadata *a,
			    const struct slot_metadata *b)
{
	/* Higher priority is better */
	if (a->priority != b->priority)
		return b->priority - a->priority;

	/* Higher successful_boot value is better, in case of same priority */
	if (a->successful_boot != b->successful_boot)
		return b->successful_boot - a->successful_boot;

	/* Higher tries_remaining is better to ensure round-robin */
	if (a->tries_remaining != b->tries_remaining)
		return b->tries_remaining - a->tries_remaining;

	return 0;
}

/**
 * roll back spl.
 *
 * This function is used to roll back the SPL after a failed upgrade.
 *
 * @return 0 on success and a negative on error
 */
static int ab_slot_rollback(void)
{
	char *ifname;
	unsigned long rb_base = 0, rb_size = 0;
	uint64_t total_part_size = 0;

	ifname = block_dev_get_name();
	if (get_buffer_base_size_from_dt("heap@4", &rb_base, &rb_size) < 0)
		return -1;
	if ((total_part_size = get_devsize_hwpart(ifname, BOOT_PART2)) == 0)
		return -1;

	if (0 != common_raw_read("splloader_bak", (uint64_t)total_part_size, (uint64_t)0, (char *) rb_base)) {
		errorf("splloader_bak read error\n");
		return -1;
	}
	if (0 != common_raw_write("splloader", (uint64_t)total_part_size, (uint64_t)0, (uint64_t)0, (char *) rb_base)) {
		errorf("splloader write error\n");
		return -1;
	}
	reboot_devices(CMD_NORMAL_MODE);
	return 0;
}

/**
 * clear spl adjust flag.
 *
 * This function is used to clear spl adjust flag.
 *
 * @return 0 on success and a negative on error
 */

static int ab_slot_clear_spl_adjust_flag(void)
{
	struct bootloader_control *abc = NULL;
	u32 crc32_le;
	int slot, i, ret;
	bool store_needed = false;
	char slot_suffix[4];
	disk_partition_t part_info = {0};
	int rb_slot;
	uint8_t temp = 0;

	ret = get_img_partition_info("misc", &part_info);
	if (ret) {
		return ret;
	}

	ret = ab_control_create_from_disk("misc", &part_info, &abc);
	if (ret < 0) {
		/*
		 * This condition represents an actual problem with the code or
		 * the board setup, like an invalid partition information.
		 * Signal a repair mode and do not try to boot from either slot.
		 */
		return ret;
	}

	crc32_le = ab_control_compute_crc(abc);
	if (abc->crc32_le != crc32_le) {
		debugf("ANDROID: Invalid CRC-32 (expected %.8x, found %.8x),",
			crc32_le, abc->crc32_le);
		debugf("re-initializing A/B metadata.\n");

		ret = ab_control_default(abc);
		if (ret < 0) {
			free(abc);
			return -ENODATA;
		}
		store_needed = true;
	}

	if (abc->magic != BOOT_CTRL_MAGIC) {
		errorf("ANDROID: Unknown A/B metadata: %.8x\n", abc->magic);
		free(abc);
		return -ENODATA;
	}

	if (abc->version > BOOT_CTRL_VERSION) {
		errorf("ANDROID: Unsupported A/B metadata version: %.8x\n",
			abc->version);
		free(abc);
		return -ENODATA;
	}

	/*
	 * At this point a valid boot control metadata is stored in abc,
	 * followed by other reserved data in the same block. We select a with
	 * the higher priority slot that
	 *  - is not marked as corrupted and
	 *  - either has tries_remaining > 0 or successful_boot is true.
	 * If the selected slot has a false successful_boot, we also decrement
	 * the tries_remaining until it eventually becomes unbootable because
	 * tries_remaining reaches 0. This mechanism produces a bootloader
	 * induced rollback, typically right after a failed update.
	 */

	/* Safety check: limit the number of slots. */
	if (abc->nb_slot > ARRAY_SIZE(abc->slot_info)) {
		abc->nb_slot = ARRAY_SIZE(abc->slot_info);
		store_needed = true;
	}

	if (abc->reserved0[0] == 1) {
		debugf("do clear adjust spl flag in misc.\n");
		memset(abc->reserved0, 0, sizeof(abc->reserved0));
		store_needed = true;
	}

	if (get_boot_role() == BOOTLOADER_MODE_LOAD && store_needed) {
		abc->crc32_le = ab_control_compute_crc(abc);
		ab_control_store(NULL, &part_info, abc);
	}
	free(abc);

	return 0;
}

/**
 * roll back spl partition only.
 *
 * This function is used to roll back the SPL after a failed upgrade.
 *
 * @return 0 on success and a negative on error
 */
int ab_slot_rollback_spl(bool update_misc)
{
        char *ifname;
        unsigned long rb_base = 0, rb_size = 0;
        uint64_t total_part_size = 0;
	char magicdata[4];
	u8 i = 0;

        ifname = block_dev_get_name();
        if (get_buffer_base_size_from_dt("heap@4", &rb_base, &rb_size) < 0)
                return -1;
        if ((total_part_size = get_devsize_hwpart(ifname, BOOT_PART1)) == 0)
                return -1;

        if (0 != common_raw_read("splloader", (uint64_t)total_part_size, (uint64_t)0, (char *) rb_base)) {
                errorf("splloader read error\n");
                return -1;
        }
	memcpy(magicdata, (char *) rb_base, 4);
        printf("original splloader magic data :%02x %02x %02x %02x\n",
            magicdata[0], magicdata[1], magicdata[2], magicdata[3]);

	for (i=0; i<4; i++) {
		magicdata[i] ^= 0xFF;
	}

	if (magicdata[0] == 0x44 && magicdata[1] == 0x48
		&& magicdata[2] == 0x54 && magicdata[3] == 0x42) {
		memcpy((char *) rb_base, magicdata, 4);
		if (0 != common_raw_write("splloader", (uint64_t)total_part_size, (uint64_t)0, (uint64_t)0, (char *) rb_base)) {
			errorf("splloader write error\n");
			return -1;
		}
		if (update_misc == true)
			ab_slot_clear_spl_adjust_flag();
		reboot_devices(CMD_NORMAL_MODE);
		return 0;
	} else {
		errorf("original splloader magic data error.");
		return -1;
	}
}

int ab_select_slot(void)
{
	struct bootloader_control *abc = NULL;
	u32 crc32_le;
	int slot, i, ret;
	bool store_needed = false;
	char slot_suffix[4];
	disk_partition_t part_info = {0};
	int rb_slot;
	uint8_t temp = 0;

	ret = get_img_partition_info("misc", &part_info);
	if (ret) {
		return ret;
	}

	ret = ab_control_create_from_disk("misc", &part_info, &abc);
	if (ret < 0) {
		/*
		 * This condition represents an actual problem with the code or
		 * the board setup, like an invalid partition information.
		 * Signal a repair mode and do not try to boot from either slot.
		 */
		return ret;
	}

	crc32_le = ab_control_compute_crc(abc);
	if (abc->crc32_le != crc32_le) {
		debugf("ANDROID: Invalid CRC-32 (expected %.8x, found %.8x),",
			crc32_le, abc->crc32_le);
		debugf("re-initializing A/B metadata.\n");

		ret = ab_control_default(abc);
		if (ret < 0) {
			free(abc);
			return -ENODATA;
		}
		store_needed = true;
	}

	if (abc->magic != BOOT_CTRL_MAGIC) {
		errorf("ANDROID: Unknown A/B metadata: %.8x\n", abc->magic);
		free(abc);
		return -ENODATA;
	}

	if (abc->version > BOOT_CTRL_VERSION) {
		errorf("ANDROID: Unsupported A/B metadata version: %.8x\n",
			abc->version);
		free(abc);
		return -ENODATA;
	}

	/*
	 * At this point a valid boot control metadata is stored in abc,
	 * followed by other reserved data in the same block. We select a with
	 * the higher priority slot that
	 *  - is not marked as corrupted and
	 *  - either has tries_remaining > 0 or successful_boot is true.
	 * If the selected slot has a false successful_boot, we also decrement
	 * the tries_remaining until it eventually becomes unbootable because
	 * tries_remaining reaches 0. This mechanism produces a bootloader
	 * induced rollback, typically right after a failed update.
	 */

	/* Safety check: limit the number of slots. */
	if (abc->nb_slot > ARRAY_SIZE(abc->slot_info)) {
		abc->nb_slot = ARRAY_SIZE(abc->slot_info);
		store_needed = true;
	}

	slot = -1;
	rb_slot = -1;
	for (i = 0; i < abc->nb_slot; ++i) {
		if (abc->slot_info[i].verity_corrupted ||
		    !abc->slot_info[i].tries_remaining) {
			debugf("ANDROID: unbootable slot %d tries: %d, ",
				  i, abc->slot_info[i].tries_remaining);
			debugf("corrupt: %d\n",
				  abc->slot_info[i].verity_corrupted);
			rb_slot = i;
			continue;
		}
		debugf("ANDROID: bootable slot %d pri: %d, tries: %d, ",
			  i, abc->slot_info[i].priority,
			  abc->slot_info[i].tries_remaining);
		debugf("corrupt: %d, successful: %d\n",
			  abc->slot_info[i].verity_corrupted,
			  abc->slot_info[i].successful_boot);

		if (!abc->slot_info[i].successful_boot &&
		    abc->slot_info[i].tries_remaining == 1) {
			errorf("ANDROID: check rollback slot %d tries: %d\n",
				  i, abc->slot_info[i].tries_remaining);
			rb_slot = i;
			continue;
		}

		if (slot < 0 ||
		    ab_compare_slots(&abc->slot_info[i],
				     &abc->slot_info[slot]) < 0) {
			slot = i;
		}
	}

	if (rb_slot >= 0 && slot >= 0
		&& abc->slot_info[rb_slot].priority > abc->slot_info[slot].priority
		&& get_boot_role() == BOOTLOADER_MODE_LOAD) {
		debugf("ANDROID: slot %d booted fail, rolling back spl and reboot\n", rb_slot);
		temp = abc->slot_info[rb_slot].priority;
		abc->slot_info[rb_slot].priority = abc->slot_info[slot].priority;
		abc->slot_info[slot].priority = temp;
		abc->slot_info[rb_slot].successful_boot = 0;
		abc->crc32_le = ab_control_compute_crc(abc);
		ab_control_store(NULL, &part_info, abc);
		if(-1 == ab_slot_rollback_spl(false)) {
			errorf("ANDROID: slot %d rolling back fail, stop reboot\n", rb_slot);
			return -1;
		} else {
			errorf("ANDROID: slot %d rolling back success, reboot device\n", rb_slot);
			while(1);
		}
	}

	if (slot >= 0 && !abc->slot_info[slot].successful_boot) {
		debugf("ANDROID: Attempting slot %c, tries remaining %d\n",
			BOOT_SLOT_NAME(slot),
			abc->slot_info[slot].tries_remaining);
		abc->slot_info[slot].tries_remaining--;
		store_needed = true;
	}

	if (slot >= 0) {
		/*
		 * Legacy user-space requires this field to be set in the BCB.
		 * Newer releases load this slot suffix from the command line
		 * or the device tree.
		 */
		memset(slot_suffix, 0, sizeof(slot_suffix));
		slot_suffix[0] = '_';
		slot_suffix[1] = BOOT_SLOT_NAME(slot);
		if (memcmp(abc->slot_suffix, slot_suffix,
			   sizeof(slot_suffix))) {
			memcpy(abc->slot_suffix, slot_suffix,
			       sizeof(slot_suffix));
			store_needed = true;
		}
	}

	if (get_boot_role() == BOOTLOADER_MODE_LOAD && store_needed) {
		abc->crc32_le = ab_control_compute_crc(abc);
		ab_control_store(NULL, &part_info, abc);
	}
	free(abc);

	if (slot < 0)
		return -EINVAL;

	return slot;
}
