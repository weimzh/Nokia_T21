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

#ifndef __SPRD_LOG_H__
#define __SPRD_LOG_H__
#ifdef CONFIG_LOG_2_SD
#include "../common/loader/sysdump.h"
#endif

#define LOG_BUFFER_START_ADDR   ALIGN(LOG_BUFFER_ADDR + sizeof(LOG_BUFFER), 8)
#define LOG_BUFFER_SIZE         0x040000 /* 256KB */

#define LOG_FOLDER_NUM		3
#define LOG_FOLDER_NAME		"ylog/ap/uboot"
#define LOG_AUTO_TEST		"ylog/uboot/uboot_log_auto_test.txt"

#define UBOOT_LOG_PARTITION	"uboot_log"
#define LOG_HEAD_MAGIC	        0x0000abcd
#define LOG_VERSION		        1
#define LOG_HEADER_SIZE	        512
#define LOG_BODY_NUM_MAX	12
/* log body num for panic */
#define LOG_PANIC_BODY_NUM	7
/* log body num for cboot */
#define LOG_CBOOT_BODY_NUM	4
#define LOG_FASTBOOT_BODY_NUM	2
#define LOG_DOWNLD_BODY_NUM	2

#define LOG_BODY_SIZE		LOG_BUFFER_SIZE		/* 256KB */

#define SUCESS		1
#define FAILED		0

#define LAST_LOG_PARTITION_OFFSET		(0)
/* log position for panic (0x40000) */
#define PANIC_LOG_PARTITION_OFFSET		(LAST_LOG_PARTITION_OFFSET + LOG_BUFFER_SIZE)
/* log position for cboot (0x200000) */
#define START_LOG_PARTITION_OFFSET		(PANIC_LOG_PARTITION_OFFSET + LOG_BUFFER_SIZE * LOG_PANIC_BODY_NUM)
/* log position for fastboot (0x300000) */
#define FASTBOOT_LOG_PARTITION_OFFSET		(START_LOG_PARTITION_OFFSET + LOG_BUFFER_SIZE * LOG_CBOOT_BODY_NUM)
/* log position for download (0x380000) */
#define DOWNLD_LOG_PARTITION_OFFSET		(FASTBOOT_LOG_PARTITION_OFFSET + LOG_BUFFER_SIZE * 2)

typedef enum {
	LR_NORMAL,
	LR_ABNORMAL,
	LR_LONG_PRESS,
	LR_UNKNOWN,
} LOG_REBOOT_TYPE_T;

typedef enum {
	PANIC_LOG_TYPE = 0,
	START_LOG_TYPE,
	FASTBOOT_LOG_TYPE,
	DOWNLD_LOG_TYPE,
	MAX_LOG_TYPE
} LOG_TYPE_T;

typedef struct _LOG_BUFFER {
	uint64_t magic;		/* 53 50 52 44 75 6c 6f 67 */
	uchar* addr;
	uchar* pointer;
	uint32_t size;
	uint32_t used;
	uint32_t spare;
	uint32_t status;
	uchar* log2pc_start;
} LOG_BUFFER;

typedef struct _LOG_BODY {
	uint32_t p_offset;	/* offset in uboot log partiton */
	uint32_t b_offset;	/* offset in log body, it also indicates the log size in emmc */
	uint32_t size;
} LOG_BODY;

typedef struct _LOG_PARTITION_HEADER {
	uint32_t magic;
	uint32_t len;
	uint32_t boot_count;
	uint32_t body_num;
	uint32_t type;
	uint32_t next_body;
	LOG_BODY body[LOG_BODY_NUM_MAX];
} LOG_PARTITION_HEADER;

typedef struct _LOG_STRUCT {
	int32_t flag;
	uint64_t log_type_p_offset[MAX_LOG_TYPE];
	LOG_PARTITION_HEADER log_par_hdr[MAX_LOG_TYPE];
} LOG_STRUCT;

unsigned long get_uboot_log_addr(void);
uint32_t get_uboot_log_len(void);
void init_log_struct(void);
int init_log_partition_hdr(void);
void flush_log_buffer(void);
void write_uboot_last_log(void);

#ifdef CONFIG_SPRD_LOG
#ifdef DEBUG
# if defined(CONFIG_LOG_2_EMMC) || defined(CONFIG_LOG_2_UFS)
#define init_write_log() do {		\
	init_log_struct();		\
	init_log_partition_hdr();	\
} while(0)

#define reinit_write_log() do {		\
	init_log_partition_hdr();	\
	flush_log_buffer();		\
} while(0)

#define write_log() flush_log_buffer()
#define write_log_last() do {		\
	flush_log_buffer();		\
	write_uboot_last_log();		\
} while(0)

# elif defined(CONFIG_LOG_2_SD)
#define write_log_last() do {		\
	extern int sd_fs_type;		\
	puts("SD:   ");			\
	if (init_mmc_fat(&sd_fs_type)) {	\
		debugf("ERROR: init_mmc_fat,sd_fs_type=%d.\n", sd_fs_type);	\
	}				\
	flush_log_buffer();		\
} while(0)

# endif

#else

#define init_write_log()
#define reinit_write_log()
#define write_log()

# if defined(CONFIG_LOG_2_EMMC) || defined(CONFIG_LOG_2_UFS)
#define write_log_last() do {		\
	init_log_struct();		\
	init_log_partition_hdr();	\
	flush_log_buffer();		\
	write_uboot_last_log();		\
} while(0)

# else
#define write_log_last()
# endif

#endif
#else
#define init_write_log()
#define reinit_write_log()
#define write_log()
#define write_log_last()
#endif

extern LOG_BUFFER *p_log_buffer;
#ifdef CONFIG_DTS_MEM_LAYOUT
extern uint32_t log_buffer_enabled_flag;
#endif
extern LOG_REBOOT_TYPE_T lr_cause;
#endif //__SPRD_LOG_H__
