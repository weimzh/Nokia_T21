/*
 * Copyright (C) 2013 Spreadtrum Communications Inc.
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
#include <rtc.h>
#include <boot_mode.h>
#include <common.h>
#include <linux/input.h>
#include <linux/mtd/mtd.h>
#include <linux/sizes.h>
#include <asm/arch/check_reboot.h>
#include <mmc.h>
#include <fat.h>
#include <exfat.h>
#include <chipram_env.h>
#include <sprd_common_rw.h>

#ifdef CONFIG_SPRD_LOG
extern LOG_BUFFER *p_log_buffer;
#endif

LOG_REBOOT_TYPE_T lr_cause = LR_NORMAL;

unsigned long get_uboot_log_addr(void)
{
	if (NULL != p_log_buffer)
		return p_log_buffer->addr;
	return 0;
}

uint32_t get_uboot_log_len(void)
{
	if (NULL != p_log_buffer)
		return p_log_buffer->size;
	return 0;
}

#if defined(CONFIG_LOG_2_SD)
int sd_fs_type;  /* file system type on sd card */

void write_log_to_mmc(char *filename, int fs_type,
	void *memaddr, unsigned long memsize)
{
	int ret = 0;
	unsigned long actwrite = 0;

	debugf("writing 0x%lx bytes to sd file %s\n",
		memsize, filename);

	if (fs_type==FS_FAT32)
		ret = file_fat_write(filename, memaddr, 0, memsize, &actwrite);
	else if (fs_type==FS_EXFAT)
		ret = file_exfat_write(filename, memaddr, memsize);
	else
		ret = -1;

	if (ret != 0) {
		debugf("write file %s to SD Card error, and ret = %d !!!\n", filename, ret);
	}

	return;
}


/*
 * Flush log buffer to sd/emmc/nand etc
 */
void flush_log_buffer(void)
{
	struct rtc_time tm;
	dir_entry *dentptr = NULL;
	char fnbuf[72] = {0}, fnbuf_rename[72] = {0};
	int i, j, ret;
	int auto_test_flag = 0;

	if (sd_fs_type == FS_FAT32) {
		int mod, key_code;
		unsigned long max_size = 0;

		debugf("FileSystem is FAT32 !!!\n");
		max_size = p_log_buffer->size;

		mod = fat_checksys(max_size);
		if (mod &(FSFATAL | FSNOSPACE)) {
			int nospace_flag = 1;
			if (mod & FSFATAL) {
				debugf("\nHello Baby: SD Card is demaged !!!");
			}
			else if (mod & FSNOSPACE) {
				for (i = 1; i <= LOG_FOLDER_NUM; i++) {
					sprintf(fnbuf, LOG_FOLDER_NAME"/%d", i);
					fnbuf[strlen(fnbuf)] = '\0';
					dentptr = check_folder_flag(fnbuf);
					if(dentptr == NULL)
						break;
				}
				if (i != 1) {
					for(j = i; j != 1;) {
						sprintf(fnbuf, LOG_FOLDER_NAME"/%d", --j);
						fnbuf[strlen(fnbuf)] = '\0';
						ret = delete_folder(fnbuf);
						if(ret == -1) {
							debugf("ERROR: delete files or folder failed !!!\n");
							goto FINISH;
						}
						mod = fat_checksys(max_size);
						if (!(mod & FSNOSPACE)) {
							nospace_flag = 0;
							break;
						}
					}
				}
				if (nospace_flag) {
					debugf("\nHello Baby: SD Card have not enough space !!!");
				}
			}
			if (nospace_flag) {
				debugf("need to format SD Card !!!\n");
				goto FINISH;

			}
		}

		if(do_new_folder(LOG_FOLDER_NAME)) {
			debugf("ERROR: creat %s folder failed !!!\n", LOG_FOLDER_NAME);
			goto FINISH;
		}

		if(check_folder_flag(LOG_AUTO_TEST)) {
			auto_test_flag = 1;
			debugf("Now has existed uboot_log_auto_test.txt!!!\n");
		}

		for (i = 1; i <= LOG_FOLDER_NUM; i++) {
			sprintf(fnbuf, LOG_FOLDER_NAME"/%d", i);
			fnbuf[strlen(fnbuf)] = '\0';
			dentptr = check_folder_flag(fnbuf);
			if(dentptr == NULL)
				break;
		}

		if (i > LOG_FOLDER_NUM) {
			debugf("there existed %d history log !!!\n", LOG_FOLDER_NUM);
			i --;
			sprintf(fnbuf, LOG_FOLDER_NAME"/%d", i);
			fnbuf[strlen(fnbuf)] = '\0';
			ret = delete_folder(fnbuf);
			if(ret == -1) {
				debugf("ERROR: delete files or folder failed !!!\n");
				goto FINISH;
			}
		}

		for(j = i - 1; j > 0 && i != 1; j = j - 2) {
				sprintf(fnbuf, LOG_FOLDER_NAME"/%d", j++);
				fnbuf[strlen(fnbuf)] = '\0';
				sprintf(fnbuf_rename, LOG_FOLDER_NAME"/%d", j);
				fnbuf_rename[strlen(fnbuf_rename)] ='\0';
				debugf("rename folder from %s to %s !!!\n", fnbuf, fnbuf_rename);
				ret = rename_folder(fnbuf, fnbuf_rename);
				if (ret == -1) {
					debugf("ERROR: rename folder failed !!!\n");
					break;
				}
			}

		sprintf(fnbuf, LOG_FOLDER_NAME"/%d", 1);

		if(do_new_folder(fnbuf)) {
			debugf("ERROR: creat %s folder failed !!!\n", fnbuf);
			goto FINISH;
		}
	}
	else if (sd_fs_type == FS_EXFAT) {
		int mod, key_code;
		unsigned long max_size;

		debugf("FileSystem is exFAT !!!\n");
		max_size = p_log_buffer->size;
		debugf("ExFAT max space size is %lx\n",max_size);

		mod = exfat_checksys(max_size);
		if (mod & FSSMSIZE) {
			debugf("SD card volume size is smaller then dumped size. Skip write !!!\n");
			goto FINISH;
		}

		if (mod &(FSFATAL | FSNOSPACE)) {
			if (mod & FSFATAL)
				debugf("\nHello Baby: SD Card is demaged !!!");
			else if (mod & FSNOSPACE)
				debugf("\nHello Baby: SD Card has not enough space !!!");

			debugf("\npress volumedown to format SD Card !!!\n");
		}
	}
	else {
		debugf("Invalid file system... Write will be skipped !!!\n");
		goto FINISH;
	}

	sprintf(fnbuf, LOG_FOLDER_NAME"/1/uboot_log_%04d_%02d_%02d_%02d_%02d_%02d.txt", \
			tm.tm_year, tm.tm_mon, tm.tm_mday, \
			tm.tm_hour, tm.tm_min, tm.tm_sec);

	debugf("time is %04d.%02d.%02d_%02d:%02d:%02d\n", tm.tm_year, tm.tm_mon, \
			tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	write_log_to_mmc(fnbuf, sd_fs_type,
			(uchar *)p_log_buffer->addr, p_log_buffer->used);

FINISH:
	debugf ("Write  finish or happen abnormally!!!\n");
#if (defined CONFIG_X86) && (defined CONFIG_MOBILEVISOR)
		reset_to_normal(CMD_NORMAL_MODE);
#endif

	return;
}

#elif defined(CONFIG_LOG_2_EMMC) || defined(CONFIG_LOG_2_UFS)
extern int panic_cnt;
LOG_STRUCT log_st;

void init_log_struct(void)
{
	memset(&log_st, 0, sizeof(LOG_STRUCT));
}

int init_log_partition_hdr(void)
{
	int i;
	int cur_body; /* current log body */
	uint8_t hdr_buf[LOG_HEADER_SIZE];
	LOG_PARTITION_HEADER *p_hdr = hdr_buf;
	const uint64_t log_p_offset[MAX_LOG_TYPE] = {
		PANIC_LOG_PARTITION_OFFSET,
		START_LOG_PARTITION_OFFSET,
		FASTBOOT_LOG_PARTITION_OFFSET,
		DOWNLD_LOG_PARTITION_OFFSET,
	};
	const int log_body_count[MAX_LOG_TYPE] = {
		LOG_PANIC_BODY_NUM,
		LOG_CBOOT_BODY_NUM,
		LOG_FASTBOOT_BODY_NUM,
		LOG_DOWNLD_BODY_NUM,
	};
	LOG_TYPE_T t;

	for (t = PANIC_LOG_TYPE; t < MAX_LOG_TYPE; t++) {
		debugf("init log type %d\n", t);

		memset(hdr_buf, 0, sizeof(hdr_buf));
		if (0 != common_raw_read(UBOOT_LOG_PARTITION, (uint64_t)LOG_HEADER_SIZE, log_p_offset[t], hdr_buf)) {
			errorf("read hdr error\n");
			log_st.flag = FAILED;
			return -1;
		}

		if (p_hdr->magic != LOG_HEAD_MAGIC/* || p_hdr->next_body > log_body_count[t]*/) {
			debugf("reset log partition header\n");
			p_hdr->magic = LOG_HEAD_MAGIC;
			p_hdr->len = LOG_HEADER_SIZE;
			p_hdr->boot_count = 1;
			p_hdr->body_num = log_body_count[t];
			p_hdr->type = t;
			p_hdr->next_body = 1;

			for (i = 0; i < p_hdr->body_num; i++) {
				if (i == 0) {
					p_hdr->body[i].p_offset = LOG_HEADER_SIZE;
					p_hdr->body[i].size = LOG_BODY_SIZE - LOG_HEADER_SIZE;	//the same as buffer size
				} else {
					p_hdr->body[i].p_offset = i * LOG_BODY_SIZE;
					p_hdr->body[i].size = LOG_BODY_SIZE;
				}
				p_hdr->body[i].b_offset = 0;
			}

			if (0 != common_raw_write(UBOOT_LOG_PARTITION, (uint64_t)LOG_HEADER_SIZE, (uint64_t)0,
									  log_p_offset[t], hdr_buf)) {
				errorf("write hdr error\n");
				log_st.flag = FAILED;
				return -1;
			}
		} else {
			p_hdr->boot_count += 1;
			p_hdr->next_body += 1;
			if (p_hdr->next_body > p_hdr->body_num)
				p_hdr->next_body = 1;

			/* reset the body offset  */
			p_hdr->body[p_hdr->next_body - 1].b_offset = 0;
		}

		log_st.log_type_p_offset[t] = log_p_offset[t];
		memcpy(&log_st.log_par_hdr[t], p_hdr, sizeof(LOG_PARTITION_HEADER));
		if (t == START_LOG_TYPE)
			printf("bootup init log success on %d times\n", p_hdr->boot_count);
		else if (t == PANIC_LOG_TYPE)
			printf("boot count %d\n", p_hdr->boot_count);
	}

	log_st.flag = SUCESS; /* set sucess flag */
	return 0;
}

void flush_log_buffer(void)
{
	int cur_body; /* current log body */
	int64_t buf_size;
	uint64_t p_offset;
	uint8_t hdr_buf[LOG_HEADER_SIZE];
	uint8_t *buf;
	LOG_BUFFER *p_log;
	LOG_PARTITION_HEADER *p_hdr;
	LOG_BODY *body;
	boot_mode_t mode;
	char *boot_mode;

	if (log_st.flag != SUCESS) {
		return;
	}

	/* choose the right log partition */
	if (panic_cnt || lr_cause == LR_ABNORMAL || lr_cause == LR_LONG_PRESS
			|| lr_cause == LR_UNKNOWN)
		p_hdr = &log_st.log_par_hdr[PANIC_LOG_TYPE];
	else {
#ifdef CONFIG_ZEBU
		mode = BOOTLOADER_MODE_LOAD;
#else
		mode = get_boot_role();
#endif
		if (mode == BOOTLOADER_MODE_DOWNLOAD)
			p_hdr = &log_st.log_par_hdr[DOWNLD_LOG_TYPE];
		else {
			boot_mode = getenv("bootmode");
			if (boot_mode && !strcmp(boot_mode, "fastboot"))
				p_hdr = &log_st.log_par_hdr[FASTBOOT_LOG_TYPE];
			else
				p_hdr = &log_st.log_par_hdr[START_LOG_TYPE];
		}
	}

	if (p_hdr->type >= MAX_LOG_TYPE) {
		errorf("error log type %d\n", p_hdr->type);
	}

	cur_body = ((p_hdr->next_body > p_hdr->body_num) || !p_hdr->next_body) ? 0 : p_hdr->next_body - 1;
	body = &p_hdr->body[cur_body];
	p_log = p_log_buffer;

	buf = p_log->addr + body->b_offset;
	buf_size = p_log->used - body->b_offset;
	if (buf_size > body->size - body->b_offset) /* FIXME */
		buf_size = body->size - body->b_offset;

	if (buf_size <= 0) /* there is no more log in buf or no more space on flash */
		return;

	p_offset = body->p_offset + body->b_offset;

	if (body->b_offset == 0) {
		if (0 != common_raw_erase(UBOOT_LOG_PARTITION, (uint64_t)body->size,
								  log_st.log_type_p_offset[p_hdr->type] + body->p_offset)) {
			errorf("erase %llx size %x error\n", log_st.log_type_p_offset[p_hdr->type] + body->p_offset,
				   body->size);
			return;
		}
	}

	if (NULL != getenv("bootmode") && !strcmp(getenv("bootmode"), "fastboot"))
		body->b_offset = 0;
	else
		body->b_offset = p_log->used; /* must place this sentence before any printf until wirte to emmc */

	/* write log */
	if (0 != common_raw_write(UBOOT_LOG_PARTITION, (uint64_t)buf_size, (uint64_t)0,
							  log_st.log_type_p_offset[p_hdr->type] + p_offset, buf)) {
		errorf("write log 2 emmc failed\n");
		return;
	}

	memset((void *)hdr_buf, 0, LOG_HEADER_SIZE);
	memcpy((void *)hdr_buf, p_hdr, sizeof(LOG_PARTITION_HEADER));
	/* write back to header */
	if (0 != common_raw_write(UBOOT_LOG_PARTITION, (uint64_t)LOG_HEADER_SIZE, (uint64_t)0,
							  log_st.log_type_p_offset[p_hdr->type], hdr_buf)) {
		errorf("write header 2 emmc failed\n");
		return;
	}
}

void write_uboot_last_log(void)
{
	boot_mode_t mode;

	mode = get_boot_role();
	if (mode == BOOTLOADER_MODE_DOWNLOAD)
		return;

	/* write current log to last log location */
	if (0 != common_raw_write(UBOOT_LOG_PARTITION, (uint64_t)p_log_buffer->size, (uint64_t)0,
						LAST_LOG_PARTITION_OFFSET, p_log_buffer->addr)) {
		errorf("save current log as last log failed\n");
		return;
	}
}

#endif

