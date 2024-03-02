#include "common.h"
#include <malloc.h>
#include <asm/arch/chip_releted_def.h>
#include "dl_common.h"
#include "dl_operate.h"
#include <ext_common.h>
#include <part.h>
#include <sparse_format.h>
#include <sprd_common_rw.h>
#include <sprd_rpmb.h>
#include <mmc.h>
#include <sprd_ufs.h>

#include <secure_boot.h>
#include <secureboot/sec_common.h>
#include <otp_helper.h>
#include <chipram_env.h>
#include <mpflag_def.h>
#include "../../fs/f2fs-tools/include/f2fs_fs.h"
#include <uboot_sec_drv.h>
#include "crypto/nv_aes_gcm.h"
#include "../loader/oem_fastboot_cmd.h"
#define INVALID_ID   0xffff
#define PRINT_NV_DATA 0

//added by dongming, for wipe userdata in factory, 20221013
extern int fastboot_mode_flag;
//end added

DECLARE_GLOBAL_DATA_PTR;
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
extern int fb_require_reboot_edl(int on);
extern int fb_check_reboot_edl(void *ptr);
#endif

static DL_EMMC_FILE_STATUS g_status;
static DL_EMMC_STATUS g_dl_eMMCStatus;

static unsigned long g_checksum;
static unsigned long g_sram_addr;
static unsigned int img_backup_flag = 0;
static unsigned int g_download_part_count = 0;
static unsigned long g_sparse_size = 0, g_raw_size = 0;

extern fastboot_image_size;

# ifndef CONFIG_DTS_MEM_LAYOUT
#ifdef CONFIG_X86
#ifdef CONFIG_SPRD_SOC_SP9853I
unsigned char *g_eMMCBuf = (unsigned char *)0x00800000;
#else
unsigned char *g_eMMCBuf = (unsigned char *)0x35000000;
#endif
#else
unsigned char *g_eMMCBuf = (unsigned char *)0x82000000;
#endif
uint64_t  emmc_buf_size = SZ_256M;

# else
unsigned char *g_eMMCBuf = NULL;
uint64_t  emmc_buf_size = 0;
# endif

extern char *get_slot_ab(char * ab_part_name);

/**
	partitions not for raw data or normal usage(e.g. nv and prodinfo) should config here.
	partitions not list here mean raw data/normal usage.
*/
SPECIAL_PARTITION_CFG const s_special_partition_cfg[] = {
	{{"fixnv1"}, {"fixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"runtimenv1"}, {"runtimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"tdfixnv1"}, {"tdfixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"tdruntimenv1"}, {"tdruntimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"g_fixnv1"}, {"g_fixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"g_runtimenv1"}, {"g_runtimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"nr_fixnv1"}, {"nr_fixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
#ifdef CONFIG_ANDROID_AB
	{{"nr_fixnv1_a"}, {"nr_fixnv2_a"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"nr_fixnv1_b"}, {"nr_fixnv2_b"}, IMG_RAW, PARTITION_PURPOSE_NV},
#endif
	{{"nr_runtimenv1"}, {"nr_runtimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"l_fixnv1"}, {"l_fixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
#ifdef CONFIG_ANDROID_AB
	{{"l_fixnv1_a"}, {"l_fixnv2_a"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"l_fixnv1_b"}, {"l_fixnv2_b"}, IMG_RAW, PARTITION_PURPOSE_NV},
#endif
	{{"l_runtimenv1"}, {"l_runtimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"tl_fixnv1"}, {"tl_fixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"tl_runtimenv1"}, {"tl_runtimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"lf_fixnv1"}, {"lf_fixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"lf_runtimenv1"}, {"lf_runtimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"wfixnv1"}, {"wfixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"wruntimenv1"}, {"wruntimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"w_fixnv1"}, {"w_fixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
#ifdef CONFIG_ANDROID_AB
	{{"w_fixnv1_a"}, {"w_fixnv2_a"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"w_fixnv1_b"}, {"w_fixnv2_b"}, IMG_RAW, PARTITION_PURPOSE_NV},
#endif
	{{"w_runtimenv1"}, {"w_runtimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"wl_fixnv1"}, {"wl_fixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
#ifdef CONFIG_ANDROID_AB
	{{"wl_fixnv1_a"}, {"wl_fixnv2_a"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"wl_fixnv1_b"}, {"wl_fixnv2_b"}, IMG_RAW, PARTITION_PURPOSE_NV},
#endif
	{{"wl_runtimenv1"}, {"wl_runtimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"wcnfixnv1"}, {"wcnfixnv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"wcnruntimenv1"}, {"wcnruntimenv2"}, IMG_RAW, PARTITION_PURPOSE_NV},
	{{"uboot"},{"uboot_bak"}, IMG_RAW, PARTITION_PURPOSE_NORMAL},
	{{"system"}, NULL, IMG_RAW, PARTITION_PURPOSE_NORMAL},
	{{"userdata"}, NULL, IMG_WITH_SPARSE, PARTITION_PURPOSE_NORMAL},
	{{"cache"}, NULL, IMG_WITH_SPARSE, PARTITION_PURPOSE_NORMAL},
	{{"prodnv"}, NULL, IMG_RAW, PARTITION_PURPOSE_NORMAL},
	{{"splloader"},{"splloader_bak"}, IMG_RAW, PARTITION_PURPOSE_NORMAL},
	{NULL, NULL, IMG_TYPE_MAX, PARTITION_PURPOSE_MAX}
};

enum {
	PARTITION_CONFIG_EXIST = 0x1,
	GPT_HEADER_EXIST = 0x2,
	RPMB_KEY_EXIST = 0x4,
};

ALTER_BUFFER_ATTR alter_buffer1;
ALTER_BUFFER_ATTR alter_buffer2;
ALTER_BUFFER_ATTR* current_buffer;
typedef struct _RUNNV_HEADER {
    uint32_t magic;
    uint32_t timestamp;
    uint16_t minid;
    uint16_t maxid;
    uint16_t totalSector;
    uint16_t bytesPerSector;
    uint16_t dirCount;
    uint16_t dirSize;
    uint32_t nextBlock;
    uint32_t nextDataOffset;
} runnv_header_t;

typedef struct _DIR_STRUCT{
    uint16_t itemSize;
    uint16_t checksum;
    uint32_t offset;
    uint32_t status;
    uint32_t reserved;
} nv_dir_t;
/***********************************************************/
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
static int dl_check_reboot_edl(void)
{
	static int by = 0;

	if (by)
		return 0;

	/*
	 * operation was not allow when requirement was not from edl,
	 * or factory download
	 */
	if (fb_check_reboot_edl(NULL)) {
		return -1; /* return BSL_REP_OPERATION_FAILED to pctool */
	}

	by = 1;
	return 0;
}
#endif


#ifdef CONFIG_DTS_MEM_LAYOUT

#define SET_DOWNLOAD_BUFFER_BASE_SIZE(basep, sizep)		get_buffer_base_size_from_dt("heap@5", basep, sizep)
#define SET_ALT_BUFFER1_BASE_SIZE(basep, sizep)			get_buffer_base_size_from_dt("heap@6", basep, sizep)
#define SET_ALT_BUFFER2_BASE_SIZE(basep, sizep)			get_buffer_base_size_from_dt("heap@7", basep, sizep)

/* fulldump2internal define start */
int sysdumpdb_erase_flag = 0;
int fulldumpdb_erase_flag = 0;
int prestatus_recored_flag = 0; // incicate pre-status when flush the hole pac
disk_partition_t *partition_info_bk;
uint16_t total_partition_num_bk;
int non_total_pac_handle_flag = 0;
#define MISCDATA_DUMP_DATA_START (9 * 1024 + 32)
#define MISCDATA_DUMP_DATA_END (9 * 1024 + 288)
#define FULLDUMP_PARTITION_MAGIC "FULLDUMP" //"FULLDUMP"
#define FULLDUMP_PARTITION_MAGIC_LEN 10
#define DOWNLOAD_TOTAL_PAC_LEVEL  20 // if there are more than 20 image need downlaod , we set it as total pac
#define SYSDUMPDB_PARTITION_NAME "sysdumpdb"
#define SYSDUMPDB_PARTITION_DUMP_FLAG_SIZE 8
#define SYSDUMPDB_PARTITION_DUMP_FLAG_OFFSET   (16) /* bit 16 ~23  'Y' */
/* fulldump2internal define end */
int get_ab_partition(char *temp)
{
#ifdef CONFIG_ANDROID_AB
	int cnt;

	if (!temp)
		return -1;

	strcpy(temp, g_dl_eMMCStatus.curUserPartitionName);
	cnt = strlen(temp);
	if ((*(temp + cnt - 1) == 'a') && (*(temp + cnt - 2) == '_')) {
		*(temp + cnt -1) = 'b';
//		debugf("get partition slot: %s\n", temp);
		return 0;
	} else if ((*(temp + cnt - 1) == 'b') && (*(temp + cnt - 2) == '_')) {
		*(temp + cnt -1) = 'a';
//		debugf("get partition slot: %s\n", temp);
		return 0;
	}
#endif
	return 1;
}

int set_buf_base_size(void)
{
	unsigned long buf_base, alt_buf1_base, alt_buf2_base;

	if (SET_DOWNLOAD_BUFFER_BASE_SIZE(&buf_base, &emmc_buf_size) < 0) {
		errorf("set download buffer error\n");
		return -1;
	}

	if (SET_ALT_BUFFER1_BASE_SIZE(&alt_buf1_base, &alter_buffer1.size) < 0) {
		errorf("set download alt buffer1 error\n");
		return -1;
	}

	if (SET_ALT_BUFFER2_BASE_SIZE(&alt_buf2_base, &alter_buffer2.size) < 0) {
		errorf("set download alt buffer2 error\n");
		return -1;
	}

	g_eMMCBuf = (unsigned char *)ALIGN(buf_base , 8);
	alter_buffer1.addr = (unsigned char *)ALIGN(alt_buf1_base , 8);
	alter_buffer2.addr = (unsigned char *)ALIGN(alt_buf2_base , 8);

	debugf("download buffer base %p, size %llx\nalter buffer1 base %p, size %x\nalter buffer2 base %p, size %x\n",
			g_eMMCBuf, emmc_buf_size,
			alter_buffer1.addr, alter_buffer1.size,
			alter_buffer2.addr, alter_buffer2.size);

	return 0;
}
#endif

uint16_t eMMCCheckSum(const uint32_t * src, int32_t len)
{
	uint32_t sum = 0;
	unsigned short *src_short_ptr = NULL;

	while (len > 3) {
		sum += *src++;
		len -= 4;
	}

	src_short_ptr = (uint16_t *) src;

	if (0 != (len & 0x2)) {
		sum += *(src_short_ptr);
		src_short_ptr++;
	}

	if (0 != (len & 0x1)) {
		sum += *((unsigned char *)(src_short_ptr));
	}

	sum = (sum >> 16) + (sum & 0x0FFFF);
	sum += (sum >> 16);

	return (uint16_t) (~sum);
}

#ifdef CONFIG_MMC
uint8_t emmc_2ndhand_detect()
{
	char part_config;
	block_dev_desc_t *dev_desc;
	gpt_entry *pgpt_pte = NULL;
	int rpmb_key_result;
	uint8_t result = 0x0;
	struct mmc *mmc = find_mmc_device(0);
	dev_desc = get_dev_hwpart("mmc", 0, PARTITION_USER);
	ALLOC_CACHE_ALIGN_BUFFER_PAD(gpt_header, gpt_head, 1, dev_desc->blksz);

	/* judge the partition config */
	part_config = mmc->part_config;
	/* spreadtrum do not use BOOT_ACK,if the BOOT_ACK is 1,the emmc is used by other vendor */
	if (((part_config >> 6) & 0x1) == 0x1) {
		printf("The Emmc partition config was used\n");
		result |= PARTITION_CONFIG_EXIST;
	}

#ifdef CONFIG_EFI_PARTITION
	if (test_part_efi(dev_desc) == 0) {
		printf("Find gpt header from user partition,emmc was used\n");
		result |= GPT_HEADER_EXIST;
	}
#endif

	rpmb_key_result = is_wr_rpmb_key();
	if (rpmb_key_result != 0) {
		printf("The Emmc rpmb partition was used\n");
		result |= RPMB_KEY_EXIST;
	}

	return result;
}

uint8_t emmc_2ndhand_fix(uint8_t detect_result)
{
	struct mmc *mmc = find_mmc_device(0);

	/* clear the partition_boot_ack bit */
	if (detect_result & PARTITION_CONFIG_EXIST)
		mmc->part_config &= 0x3F;

	return 0;
}
#endif

uint32_t get_pad_data(const uint32_t * src, int32_t len, int32_t offset, uint16_t sum)
{
	uint32_t sum_tmp;
	uint32_t sum1 = 0;
	uint32_t pad_data;
	uint32_t i;
	sum = ~sum;
	sum_tmp = sum & 0xffff;
	sum1 = 0;
	for (i = 0; i < offset; i++) {
		sum1 += src[i];
	}
	for (i = (offset + 1); i < len; i++) {
		sum1 += src[i];
	}
	pad_data = sum_tmp - sum1;
	return pad_data;
}

void splFillCheckData(uchar * splBuf)
{
	EMMC_BootHeader *header;
	uint32_t pad_data;
	uint32_t w_len;
	uint32_t w_offset;
	uchar * buf = splBuf + BOOTLOADER_HEADER_OFFSET + sizeof(EMMC_BootHeader);
	w_len = (SPL_CHECKSUM_LEN - (BOOTLOADER_HEADER_OFFSET + sizeof(*header))) / 4;
	w_offset = w_len - 1;

	/* pad the data inorder to make check sum to 0 */
	pad_data = get_pad_data((uint32_t *)buf, w_len, w_offset, 0);
	debugf("splloader fill pad_data=0x%x\n", pad_data);
	*(volatile unsigned int *)(splBuf + SPL_CHECKSUM_LEN - 4) = pad_data;
	header = (EMMC_BootHeader *) (splBuf + BOOTLOADER_HEADER_OFFSET);
	header->version = 0;
	header->magicData = MAGIC_DATA;
	header->checkSum = (uint32_t) eMMCCheckSum(splBuf + BOOTLOADER_HEADER_OFFSET + sizeof(*header),
						   SPL_CHECKSUM_LEN - (BOOTLOADER_HEADER_OFFSET + sizeof(*header)));
#ifdef CONFIG_SECURE_BOOT
	header->hashLen = CONFIG_SPL_HASH_LEN >> 2;
#else
	header->hashLen = 0;
#endif
}


int _parser_repartition_cfg_v0(disk_partition_t * partition_info, const uchar * partition_cfg, uint16_t total_partition_num)
{
	uint16_t i = 0;
	uint16_t j = 0;
	uint32_t partition_size_m = 0;
	lbaint_t partition_start_lba = 0;
	int32_t blksz = 0;
	uint32_t lbas_per_m = 0;

	blksz = common_get_lba_size();
	if (-1 == blksz)
		return -1;

	lbas_per_m = SZ_1M / blksz;

	/* first 1 MB will be reserved, no partition can located here */
	partition_start_lba = SZ_1M / blksz;

	/* Decode String: Partition Name(72Byte)+SIZE(4Byte)+... */
	for (i = 0; i < total_partition_num; i++) {
		partition_info[i].blksz = (ulong)blksz;
		strcpy(partition_info[i].type, "U-boot");	/*not useful */

		partition_size_m = *(uint32_t *) (partition_cfg + 76 * (i + 1) - 4);
		/* the last partition and partition_size_m is 0xFFFFFFFF means this partition use all the spare lba */
		if ((i == total_partition_num - 1) && (MAX_SIZE_FLAG == partition_size_m)) {
			/* size=0 represent use all the spare lba */
			partition_info[i].size = 0;
		} else {
			/* calc the partition size of lba , raw data unit is Mb */
			partition_info[i].size = (lbaint_t) partition_size_m * lbas_per_m;
		}

		/* in raw data rcv from download tool,partition_name is 38 uint16_t length;
		 **in part.h ,disk_partition_t.name is 32 uchar length;
		 **in part_efi.h ,gpt_entry.partition_name is 36 uint16_t length,
		 **we convert raw data to disk_partition_t format here , gpt_fill_pte() in part_efi.c will
		 **convert disk_partition_t to gpt_entry */
		for (j = 0; j < 32 - 1; j++) {
			/* transform 64 bytes uint16_t to 32 bytes uchar ,and discard the last 8 bytes */
			partition_info[i].name[j] = *((uint16_t *) partition_cfg + 38 * i + j) & 0xFF;
		}
		partition_info[i].name[j] = '\0';
		partition_info[i].start = partition_start_lba;

		partition_start_lba += partition_info[i].size;
#ifdef CONFIG_PARTITION_UUIDS
		uuid_bin_to_str(partition_info[i].name, partition_info[i].uuid, UUID_STR_FORMAT_GUID);
#endif

		debugf("partition name:%s,partition_size:0x"LBAF",partiton_start:0x"LBAF",\n", partition_info[i].name, partition_info[i].size,
		       partition_info[i].start);
	}

	return 0;
}


int _parser_repartition_cfg_v1(disk_partition_t * partition_info, uchar* partition_cfg, uint16_t total_partition_num,
									uchar size_unit)
{
	int i, j;

	uint64_t partition_size_raw;
	uint64_t partition_size_lba;
	/* attention here, we use int64 instead of uint64 to support minus gap size, such as "-2048" */
	int64_t gap_raw;
	int64_t gap_lba;
	uint64_t partition_start_lba = 0;
	int32_t blksz = 0;

	blksz = common_get_lba_size();
	if (-1 == blksz)
		return -1;

	/* V1 partition table format: Partition Name(72Byte)+SIZE(8Byte)+GAP(8Byte).. .*/
	for (i = 0; i < total_partition_num; i++) {
		partition_size_raw = *(uint64_t *)(partition_cfg + 88 * (i + 1) - 16);
		gap_raw = *(int64_t *)(partition_cfg + 88 * (i + 1) - 8);
		debugf("partition_size_raw = 0x%llx, gap_raw = 0x%llx\n", partition_size_raw, gap_raw);

		switch (size_unit) {
		/* unit is MB */
		case 0:
			partition_size_lba = partition_size_raw * SZ_1M / blksz;
			gap_lba = gap_raw * SZ_1M / blksz;
			break;
		/* unit is 512K */
		case 1:
			partition_size_lba = partition_size_raw * SZ_512K / blksz;
			gap_lba = gap_raw * SZ_512K / blksz;
			break;
		/* unit is KB */
		case 2:
			partition_size_lba = PAD_SIZE(partition_size_raw * SZ_1K, blksz) / blksz;
			if (0 == gap_raw)
				gap_lba = 0;
			else
				gap_lba = PAD_SIZE(gap_raw * SZ_1K, blksz) / blksz;
			break;
		/* unit is bytes, min partition unit supported is lba(512byte), so we pad it if neccessary */
		case 3:
			partition_size_lba = PAD_SIZE(partition_size_raw, blksz) / blksz;
			if (0 == gap_raw)
				gap_lba = 0;
			else
				gap_lba = PAD_SIZE(gap_raw, blksz) / blksz;
			break;
		/* unit is sector */
		case 4:
			partition_size_lba = partition_size_raw;
			gap_lba = gap_raw;
			break;
		/* unsupported unit we consider it as MB */
		default:
			partition_size_lba = partition_size_raw * SZ_1M / blksz;
			gap_lba = gap_raw * SZ_1M / blksz;
			break;
		}

		/* check the gap of the first partition */
		if (0 == i) {
			if (0 == gap_lba) {
				/* first 1 MB will be reserved, no partition can located here */
				gap_lba = SZ_1M / blksz;
			} else if (gap_lba < FIRST_USABLE_LBA_FOR_PARTITION) {
				errorf("%s: FATAL ERROR, gap of the first partition counted in lba CAN NOT less than 34\n", __FUNCTION__);
				return -1;
			}
		}

		/* all the 8 bytes are 0xFF in the packet, but to compatible with the old version,
			we only consider the lower 4 bytes. */
		if (MAX_SIZE_FLAG == (partition_size_raw & MAX_SIZE_FLAG)) {
			partition_size_lba = 0;
			debugf("the last partition use all the left lba\n");
		}
		partition_start_lba += gap_lba;
		partition_info[i].blksz = (ulong)blksz;
		partition_info[i].start = (lbaint_t)partition_start_lba;
		partition_info[i].size = (lbaint_t)partition_size_lba;
		if (0 != partition_size_lba)
			partition_start_lba += partition_size_lba;

		strcpy(partition_info[i].type, "U-boot");	/* not useful */

		for (j = 0; j < 32 - 1; j++)
			partition_info[i].name[j] = *((uint16_t *)partition_cfg + 44 * i + j) & 0xFF;

		debugf("partition name:%s,partition_size:0x"LBAF", partition_offset:0x"LBAF"\n",
			partition_info[i].name, partition_info[i].size, partition_info[i].start);
	}
	return 0;
}

int _parser_repartition_cfg(disk_partition_t * partition_info, const uchar* partition_cfg, uint16_t total_partition_num,
								unsigned char version, unsigned char size_unit)
{
	int ret = 0;

	switch (version) {
	case 0:
		debugf("Handle repartition packet version 0  \n");
		ret = _parser_repartition_cfg_v0(partition_info, partition_cfg, total_partition_num);
		break;
	case 1:
	default:
		debugf("Handle repartition packet version 1  \n");
		ret = _parser_repartition_cfg_v1(partition_info, partition_cfg, total_partition_num, size_unit);
		break;
	}
	return ret;
}



/**
	Get the backup partition name
*/
uchar *_get_backup_partition_name(uchar * partition_name)
{
	int i = 0;

	for (i = 0; s_special_partition_cfg[i].partition != NULL; i++) {
		if (0 == strcmp(partition_name, s_special_partition_cfg[i].partition)) {
			return s_special_partition_cfg[i].bak_partition;
		}
	}

	return NULL;
}


void prepare_alternative_buffers(void)
{
#ifndef CONFIG_DTS_MEM_LAYOUT
	alter_buffer1.addr = g_eMMCBuf + emmc_buf_size+ALTERNATIVE_BUFFER_SIZE;
	alter_buffer1.size = ALTERNATIVE_BUFFER_SIZE;

	alter_buffer2.addr = alter_buffer1.addr + 2*ALTERNATIVE_BUFFER_SIZE;
	alter_buffer2.size = ALTERNATIVE_BUFFER_SIZE;
#endif
	alter_buffer1.pointer = alter_buffer1.addr;
	alter_buffer1.used = 0;
	alter_buffer1.spare = alter_buffer1.size;
	alter_buffer1.status = BUFFER_CLEAN;
	alter_buffer1.next = &alter_buffer2;

	alter_buffer2.pointer = alter_buffer2.addr;
	alter_buffer2.used = 0;
	alter_buffer2.spare = alter_buffer2.size;
	alter_buffer2.status = BUFFER_CLEAN;
	alter_buffer2.next = &alter_buffer1;

	current_buffer = &alter_buffer1;
	return;
}

int speedup_download_process(uint32_t size, char *buf)
{
	uint32_t blk_count = 0;
	uint32_t tot_buf_size = current_buffer->size;
	uint32_t last_size = 0;
	char temp[32] = {0};
	int v_ab_flag = !get_ab_partition(temp);

	if (current_buffer->spare > size)  {
		memcpy(current_buffer->pointer, buf, size);
		current_buffer->used += size;
		current_buffer->spare -= size;
		current_buffer->pointer += size;

		if (g_status.total_recv_size == g_status.total_size) {
			if (BUFFER_DIRTY == current_buffer->next->status)
				if (v_ab_flag) {
					if (0 != common_query_backstage(temp,
						tot_buf_size, current_buffer->next->addr)) {
						errorf("last query backstage %s fail, offset=0x%llx\n", temp, g_dl_eMMCStatus.offset);
						return OPERATE_WRITE_ERROR;
					}
				} else {
					if (0 != common_query_backstage(g_dl_eMMCStatus.curUserPartitionName,
						tot_buf_size, current_buffer->next->addr)) {
						errorf("last query backstage %s fail, offset=0x%llx\n", g_dl_eMMCStatus.curUserPartitionName, g_dl_eMMCStatus.offset);
						return OPERATE_WRITE_ERROR;
					}
				}

			if (0 != common_raw_write(g_dl_eMMCStatus.curUserPartitionName,
				(uint64_t)(current_buffer->used), (uint64_t)0, (uint64_t)(g_dl_eMMCStatus.offset), current_buffer->addr)) {
				errorf("last write fail, offset=0x%llx\n", g_dl_eMMCStatus.offset);
				return OPERATE_WRITE_ERROR;
			}

			if (v_ab_flag) {
				debugf("download slot: %s\n", temp);
				if (0 != common_raw_write(temp,
					(uint64_t)(current_buffer->used), (uint64_t)0, (uint64_t)(g_dl_eMMCStatus.offset), current_buffer->addr)) {
					errorf("last write fail, offset=0x%llx\n", g_dl_eMMCStatus.offset);
					return OPERATE_WRITE_ERROR;
				}
			}
			g_status.unsave_recv_size = 0;
		}
	} else {
		memcpy(current_buffer->pointer, buf, current_buffer->spare);
		last_size = size - current_buffer->spare;
		if (BUFFER_DIRTY == current_buffer->next->status)
			if (v_ab_flag) {
				if (0 != common_query_backstage(temp,
					tot_buf_size, current_buffer->next->addr)) {
					errorf("last query backstage %s fail, offset=0x%llx\n", temp, g_dl_eMMCStatus.offset);
					return OPERATE_WRITE_ERROR;
				}
			} else {
				if (0 != common_query_backstage(g_dl_eMMCStatus.curUserPartitionName,
					tot_buf_size, current_buffer->next->addr)) {
					errorf("last query backstage %s fail, offset=0x%llx\n", g_dl_eMMCStatus.curUserPartitionName, g_dl_eMMCStatus.offset);
					return OPERATE_WRITE_ERROR;
				}
			}
		if (0 != common_write_backstage(g_dl_eMMCStatus.curUserPartitionName,
			tot_buf_size, g_dl_eMMCStatus.offset, current_buffer->addr)) {
			errorf("write backstage %s fail, offset=0x%llx\n", g_dl_eMMCStatus.curUserPartitionName, g_dl_eMMCStatus.offset);
			return OPERATE_WRITE_ERROR;
		}
		if (v_ab_flag) {
			if (0 != common_query_backstage(g_dl_eMMCStatus.curUserPartitionName,
					tot_buf_size, current_buffer->next->addr)) {
					errorf("last query backstage %s fail, offset=0x%llx\n", g_dl_eMMCStatus.curUserPartitionName, g_dl_eMMCStatus.offset);
					return OPERATE_WRITE_ERROR;
				}
			if (0 != common_write_backstage(temp,
				tot_buf_size, g_dl_eMMCStatus.offset, current_buffer->addr)) {
				errorf("write backstage %s fail, offset=0x%llx\n", temp, g_dl_eMMCStatus.offset);
				return OPERATE_WRITE_ERROR;
			}
		}
		g_dl_eMMCStatus.offset += tot_buf_size;
		if (0 != last_size)
			memcpy(current_buffer->next->addr, buf + current_buffer->spare, last_size);
		current_buffer->used = 0;
		current_buffer->spare = current_buffer->size;
		current_buffer->pointer = current_buffer->addr;
		current_buffer->status = BUFFER_DIRTY;

		current_buffer = current_buffer->next;
		current_buffer->pointer = current_buffer->addr + last_size;
		current_buffer->used = last_size;
		current_buffer->spare = current_buffer->size - last_size;
		if (g_status.total_recv_size == g_status.total_size) {
			if (v_ab_flag) {
				if (0 != common_query_backstage(temp,
					tot_buf_size, current_buffer->next->addr)) {
					errorf("last cross query backstage %s fail, offset=0x%llx\n", temp, g_dl_eMMCStatus.offset);
					return OPERATE_WRITE_ERROR;
				}
			} else {
				if (0 != common_query_backstage(g_dl_eMMCStatus.curUserPartitionName,
					tot_buf_size, current_buffer->next->addr)) {
					errorf("last cross query backstage %s fail, offset=0x%llx\n", g_dl_eMMCStatus.curUserPartitionName, g_dl_eMMCStatus.offset);
					return OPERATE_WRITE_ERROR;
				}
			}

			if (0 != current_buffer->used) {
				if (0 != common_raw_write(g_dl_eMMCStatus.curUserPartitionName,
					(uint64_t)(current_buffer->used), (uint64_t)0, (uint64_t)(g_dl_eMMCStatus.offset), current_buffer->addr)) {
					errorf("last cross write fail, offset=0x%llx\n", g_dl_eMMCStatus.offset);
					return OPERATE_WRITE_ERROR;
				}

				if (v_ab_flag) {
					debugf("download slot: %s\n", temp);
					if (0 != common_raw_write(temp,
						(uint64_t)(current_buffer->used), (uint64_t)0, (uint64_t)(g_dl_eMMCStatus.offset), current_buffer->addr)) {
						errorf("last cross write fail, offset=0x%llx\n", g_dl_eMMCStatus.offset);
						return OPERATE_WRITE_ERROR;
					}
				}
			}
			g_status.unsave_recv_size = 0;
		}
	}

	return OPERATE_SUCCESS;
}


void _get_partition_attribute(uchar * partition_name)
{
	int i;

	for (i = 0; s_special_partition_cfg[i].partition != NULL; i++) {
		if (0 == strcmp(s_special_partition_cfg[i].partition, partition_name)) {
			g_dl_eMMCStatus.curImgType = s_special_partition_cfg[i].imgattr;
			g_dl_eMMCStatus.partitionpurpose = s_special_partition_cfg[i].purpose;
			debugf("partition %s image type is %d,partitionpurpose:%d\n", partition_name, g_dl_eMMCStatus.curImgType,
			       g_dl_eMMCStatus.partitionpurpose);
			return;
		}
	}

	/* default type is IMG_RAW */
	g_dl_eMMCStatus.curImgType = IMG_RAW;
	g_dl_eMMCStatus.partitionpurpose = PARTITION_PURPOSE_NORMAL;
	debugf("partition %s image type is RAW, normal partition!\n", partition_name);

	return;
}

OPERATE_STATUS _img_write_with_backup(uchar *partition)
{
	uint64_t write_size = 0;
	char temp[32] = {0};

	if (0 == strcmp("splloader",  partition)) {
		write_size = max(g_status.total_recv_size, SPL_CHECKSUM_LEN);
		if (0 != common_raw_write(partition, write_size, (uint64_t)0, (uint64_t)0, g_eMMCBuf))
			return OPERATE_WRITE_ERROR;
		strcat(partition, "_bak");
		if (0 != common_raw_write(partition, write_size, (uint64_t)0, (uint64_t)0, g_eMMCBuf))
			return OPERATE_WRITE_ERROR;
	} else if (0 == strcmp("uboot",  partition)
		|| 0 == strcmp("trustos",partition)
		|| 0 == strcmp("teecfg",partition)
		|| 0 == strcmp("sml",partition)
		|| 0 == strcmp("vbmeta",partition)) {
		write_size = g_status.total_recv_size;
		if (0 != common_raw_write(partition, write_size, (uint64_t)0, (uint64_t)0, g_eMMCBuf))
			return OPERATE_WRITE_ERROR;
		if (!get_ab_partition(temp))
			partition = (uchar *)temp;
		else
			strcat(partition, "_bak");
		if (0 != common_raw_write(partition, write_size, (uint64_t)0, (uint64_t)0, g_eMMCBuf))
			return OPERATE_WRITE_ERROR;
	} else {
		return OPERATE_IGNORE;
	}

	g_status.unsave_recv_size = 0;
	return OPERATE_SUCCESS;
}

int is_f2fs_filesystem(uchar *part_name)
{
	__le32 f2fs_magic = 0;
	if (strcmp(part_name, "userdata"))
		return 0;
	if (0 != common_raw_read(part_name, (uint64_t)sizeof(f2fs_magic), (uint64_t)0x400, &f2fs_magic)) {
		return 0;
	}
	if (F2FS_SUPER_MAGIC == f2fs_magic)
		return 1;
	return 0;
}

int f2fs_write_callback(void* handle, uint64_t size, uint64_t offset, void *buf)
{
	if (0 != common_raw_write((char*)handle, size, (uint64_t)0, offset,  buf)) {
		return -1;
	}
	return 0;
}

int f2fs_read_callback(void* handle, uint64_t size, uint64_t offset, void *buf)
{
	if (0 != common_raw_read((char*)handle, size, offset, buf)) {
		return -1;
	}
	return 0;
}

PARTITION_PURPOSE dl_get_partition_purpose(unsigned char *part_name)
{
	PARTITION_PURPOSE partition_purpose = PARTITION_PURPOSE_NORMAL;
	int i;

	/* get the special partition info */
	for (i = 0; NULL != s_special_partition_cfg[i].partition; i++) {
		if (!strcmp(s_special_partition_cfg[i].partition, part_name)) {
			partition_purpose = s_special_partition_cfg[i].purpose;
			break;
		}
	}

	return partition_purpose;
}

OPERATE_STATUS dl_secboot_verify(ulong *strip, unsigned char *part_name,
	uint64_t rcv_size, uint64_t total_size, unsigned char *buf)
{
	boot_mode_t boot_role = get_boot_role();
	VERIFY_RESULT verify_res;
	char *mode;

	if (BOOTLOADER_MODE_DOWNLOAD == boot_role) {
		/* for normal download mode, use dl_secure_process_flow verify */
		verify_res = dl_secure_process_flow(strip,
			part_name,
			rcv_size, total_size, buf);
	} else {
		/* for autodloader mode, use fb_secure_process_flow verify */
		mode = getenv("bootmode");
		if (mode != NULL && !strcmp(mode, "autodloader"))
			fastboot_image_size = rcv_size;

		verify_res = fb_secure_process_flow(strip,
			part_name,
			rcv_size, total_size, buf);
	}
	switch (verify_res) {
	case VERIFY_FAIL:
		if (!strcmp("system", part_name)) {
			if (0 != common_raw_erase(part_name, 0, 0))
			return OPERATE_WRITE_ERROR;
		}
		return OPERATE_SYSTEM_ERROR;
	/* for future extension */
	case VERIFY_STOP_WRITE:
	case VERIFY_NO_NEED:
	case VERIFY_OK:
	default:
		break;
	}

	return OPERATE_SUCCESS;
}

/* clear g_status.unsave_recv_size before return if necessary */
OPERATE_STATUS dl_backup(char *part_name, uint64_t rcv_size,
	unsigned char *buf)
{
	static const char *part_bk[] = {
		"splloader",
		"uboot",
		"trustos",
		"teecfg",
		"sml",
		"vbmeta",
	};
	char part_name_bak[PARTNAME_SZ + 8];
	int i;

	for (i = sizeof(part_bk) / sizeof(part_bk[0]) - 1; i >= 0; i--) {
		if (!strcmp(part_bk[i], part_name)) {
			sprintf(part_name_bak, "%s_bak", part_name);
			if (0 != common_raw_write(part_name_bak, rcv_size, (uint64_t)0,
						(uint64_t)0, buf))
				return OPERATE_WRITE_ERROR;

			break;
		}
	}

	if (i < 0)
		return OPERATE_IGNORE;

	return OPERATE_SUCCESS;
}

OPERATE_STATUS dl_check_nv_img(void)
{
	uint32_t fix_nv_checksum;

	fix_nv_checksum = Get_CheckSum((uchar *)g_eMMCBuf, g_status.total_recv_size);
	if (fix_nv_checksum != g_checksum) {
		/* may data transfer error */
		debugf("nv data transfer error,checksum error!\n");
		return -OPERATE_CHECKSUM_DIFF;
	}

	return OPERATE_SUCCESS;
}

#ifdef NV_ENCRYPTION

void hexdump(uint32_t title, uint8_t * data, int len)
{
    int i, j;
    int N = len / 16 + 1;
    printf("nv id :0x%x, ", title);
    printf("hexdump:%d bytes", len);
    for (i = 0; i < N; i++) {
        for (j = 0; j < 16; j++) {
            if (i * 16 + j >= len)
                goto end;
            printf("%02x ", data[i * 16 + j]);
        }
    }

end:
    printf("\n");
}

int decryptFixnvPartition(uint8_t* ori_buf)
{
	uint32_t id = -1;
	uint32_t itemSize = -1;
	uint32_t itemPos = -1;
	uint32_t offset = 4;
	uint16_t tmp[2];
	uint8_t *databuf = NULL;
	uint32_t tempsize;
	uint32_t printsize = 0;

	debugf("decrptFixnvPartition enter\n");
	while (1) {
		if (*(uint16_t *) (ori_buf + offset) == INVALID_ID) {
			debugf("findItem find the tail\n");
			break;
		}
		if (offset + sizeof(tmp) > FIXNV_SIZE) {
			debugf("findItem Surpass the boundary of the part\r\n");
			break;
		}
		memcpy(tmp, ori_buf + offset, sizeof(tmp));
		offset += sizeof(tmp);
		id = (uint32_t) tmp[0];
		itemSize = (uint32_t) tmp[1];
		itemPos = offset;
#ifdef PRINT_NV_DATA
		debugf("id = 0x%x, itemSize = 0x%x, itemPos = 0x%x. \n", id, itemSize, itemPos);
#endif
		databuf = malloc(sizeof(char) *itemSize);
		if(databuf == NULL) {
			debugf("malloc databuf error\n");
			return -1;
		}
		memset(databuf, 0x0, itemSize);
#ifdef PRINT_NV_DATA
		printsize = itemSize>32 ? 32 : itemSize;
		hexdump(id, ori_buf+itemPos, printsize);
#endif
		nv_aes_gcm(ori_buf+itemPos, itemSize, databuf, &tempsize);
#ifdef PRINT_NV_DATA
		hexdump(id, databuf, printsize);
#endif
		memcpy(ori_buf+itemPos, databuf, itemSize);

		offset += tmp[1];
		offset = (offset + 3) & 0xFFFFFFFC;
		free(databuf);
	}
	return 0;
}

int encryptFixnvPartition(uint8_t* ori_buf){
    uint32_t id = -1;
    uint32_t itemSize = -1;
    uint32_t itemPos = -1;
    uint32_t offset = 4;
    uint16_t tmp[2];
    uint8_t *databuf = NULL;
    uint32_t tempsize;
    uint32_t printsize = 0;
    debugf("encryptFixnvPartition enter\n");
    while (1) {
        if (*(uint16_t *) (ori_buf + offset) == INVALID_ID) {
            debugf("findItem find the tail\n");
            break;
        }
        if (offset + sizeof(tmp) > FIXNV_SIZE) {
            debugf("findItem Surpass the boundary of the part\r\n");
            break;
        }
        memcpy(tmp, ori_buf + offset, sizeof(tmp));
        offset += sizeof(tmp);
        id = (uint32_t) tmp[0];
        itemSize = (uint32_t) tmp[1];
        itemPos = offset;
#ifdef PRINT_NV_DATA
        debugf("id = 0x%x, itemSize = 0x%x, itemPos = 0x%x. \n", id, itemSize, itemPos);
#endif
        databuf = malloc(sizeof(char) *itemSize);
        if(databuf == NULL){
        	debugf("malloc databuf error\n");
        	return -1;
        }
        memset(databuf, 0x0, itemSize);
#ifdef PRINT_NV_DATA
        printsize = itemSize>32 ? 32 : itemSize;
        debugf("before encrypt \n");
        hexdump(id, ori_buf+itemPos, printsize);
#endif
        nv_aes_gcm(ori_buf+itemPos, itemSize, databuf, &tempsize);
#ifdef PRINT_NV_DATA
        debugf("after encrypt, output len= 0x%x\n", tempsize);
        hexdump(id, databuf, printsize);
#endif
        memcpy(ori_buf+itemPos, databuf, itemSize);

        offset += tmp[1];
        offset = (offset + 3) & 0xFFFFFFFC;
        free(databuf);
    }
    debugf("fixnv encrypt success\n");
    return 0;
}

int decryptRunnvPartition(uint8_t* ori_buf){
    uint32_t id = -1;
    uint32_t itemSize = -1;
    uint32_t itemPos = -1;
    uint16_t tmp[2];
    uint8_t *databuf = NULL;
    nv_dir_t dir;
    uint32_t dir_offset = SECTOR_SIZE * 2;
    uint32_t bak_dir_offset = 0;
    uint32_t offset = dir_offset;
    runnv_header_t npb, bak_npb;
    uint32_t printsize = 0;
    uint32_t tempsize = 0;

// get npb data
    memcpy(&npb, ori_buf, sizeof(npb));
#ifdef PRINT_NV_DATA
    debugf("npb: magic=0x%x, timestamp=0x%x, minid=0x%x, maxid=0x%x\n",
        npb.magic, npb.timestamp, npb.minid, npb.maxid);
    debugf("npb: totalSector=0x%x, bytesPerSector=0x%x, dirCount=0x%x, dirSize=0x%x\n",
        npb.totalSector, npb.bytesPerSector, npb.dirCount, npb.dirSize);
// get bak npb data
    memcpy(&bak_npb, ori_buf+SECTOR_SIZE, sizeof(bak_npb));
    debugf("bak_npb: magic=0x%x, timestamp=0x%x, minid=0x%x, maxid=0x%x\n",
        bak_npb.magic, bak_npb.timestamp, bak_npb.minid, bak_npb.maxid);
    debugf("bak_npb: totalSector=0x%x, bytesPerSector=0x%x, dirCount=0x%x, dirSize=0x%x\n",
        bak_npb.totalSector, bak_npb.bytesPerSector, bak_npb.dirCount, bak_npb.dirSize);
#endif
// calu dir offset

// calu bak dir offset
    if((npb.dirCount * npb.dirSize)%SECTOR_SIZE == 0)
        bak_dir_offset = (uint32_t)(npb.dirCount * npb.dirSize) + dir_offset;
    else
        bak_dir_offset = (uint32_t)((npb.dirCount * npb.dirSize)/SECTOR_SIZE) * SECTOR_SIZE + SECTOR_SIZE  + dir_offset;;

    while (offset < bak_dir_offset) {
        if (*(uint16_t *) (ori_buf + offset) == 0) {
            debugf("item size = 0, get next dir\n");
            offset += sizeof(nv_dir_t);
            continue;
        }
        memcpy(&dir, ori_buf+offset, sizeof(dir));
#ifdef PRINT_NV_DATA
        debugf("nv dir:itemSize=0x%x, checksum=0x%x, offset=0x%x, status=0x%x\n",
                dir.itemSize, dir.checksum, dir.offset, dir.status);
#endif
        if (dir.offset + sizeof(tmp) > 0x120000) {
            debugf(" ___findItem Surpass the boundary of the part\r\n");
            break;
        }

        memcpy(tmp, ori_buf + dir.offset, sizeof(tmp));
        id = (uint32_t) tmp[0];
        itemSize = (uint32_t) tmp[1];
        itemPos = dir.offset + sizeof(tmp);
#ifdef PRINT_NV_DATA
        debugf("id = 0x%x, itemSize = 0x%x, itemPos = 0x%x. \n", id, itemSize, itemPos);
#endif
// check id/len/checksum
        if(id < npb.minid || id > npb.maxid){
            debugf("id is invalid\n");
            break;
        }

        if(itemSize != dir.itemSize){
            debugf("itemSize is diff with dir\n");
            break;
        }
//TODO calc checksum
        if(fdl_calc_checksum(ori_buf+itemPos, itemSize) != dir.checksum){
            debugf("nvid :0x%x checksum error from dir", id);
        }

        databuf = malloc(sizeof(char) *itemSize);
        if(databuf == NULL){
        	debugf("malloc databuf error\n");
        	break;
        }
        memset(databuf, 0x0, itemSize);
#ifdef PRINT_NV_DATA
// get data & encrypt
        printsize = itemSize>32 ? 32 : itemSize;
        debugf("before decrypt \n");
        hexdump(id, ori_buf+itemPos, printsize);
#endif
        nv_aes_gcm(ori_buf+itemPos, itemSize, databuf, &tempsize);
#ifdef PRINT_NV_DATA
        debugf("after decrypt, output len = 0x%x \n", tempsize);
        hexdump(id, databuf, printsize);
#endif
        memcpy(ori_buf+itemPos, databuf, itemSize);

// calu checksum afte encrypt
        dir.checksum = fdl_calc_checksum(databuf, itemSize);
        memcpy(ori_buf+offset, &dir, sizeof(dir));
        memcpy(ori_buf+(bak_dir_offset+offset-dir_offset), &dir, sizeof(dir));
        offset += sizeof(dir);
    }
    if(offset < bak_dir_offset){
        debugf("runnv encrypt exception");
        return -1;
    }
    return 0;
}

#endif

/* clear g_status.unsave_recv_size before return if necessary */
OPERATE_STATUS dl_write_nv_img(unsigned char *part_name, unsigned char *buf,
	uint64_t size)
{
	unsigned char *part_name_bak = NULL;
	uint8_t header_buf[NV_HEADER_SIZE];
	nv_header_t *nv_header_p = NULL;
#ifdef CONFIG_ANDROID_AB
	char temp[MAX_PARTITION_NAME_SIZE] = {0};
#endif
#ifdef NV_ENCRYPTION
	encryptFixnvPartition(buf);
#endif
	memset(header_buf, 0x00, NV_HEADER_SIZE);
	nv_header_p = header_buf;
	nv_header_p->magic = NV_HEAD_MAGIC;
	nv_header_p->len = size;
	nv_header_p->checksum = (uint32_t)fdl_calc_checksum(buf, size);
	nv_header_p->version = NV_VERSION;

	debugf("Start to write first block of NV partition(%s)\n", part_name);
	if (0 != common_raw_write(part_name, NV_HEADER_SIZE, (uint64_t)0,
				(uint64_t)0, header_buf))
		return OPERATE_WRITE_ERROR;

	debugf("Start to write remain blocks of NV partition\n");
	if (0 != common_raw_write(part_name, (uint64_t)size, (uint64_t)0,
				NV_HEADER_SIZE, buf))
		return OPERATE_WRITE_ERROR;

	/* write the backup partition */
	part_name_bak = _get_backup_partition_name(part_name);
	if (NULL == part_name_bak) {
		errorf(" get backup partition name fail\n");
		return OPERATE_WRITE_ERROR;
	}
	if (0 != common_raw_write(part_name_bak, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, header_buf))
		return OPERATE_WRITE_ERROR;

	if (0 != common_raw_write(part_name_bak, (uint64_t)size, (uint64_t)0, NV_HEADER_SIZE, buf))
		return OPERATE_WRITE_ERROR;

#ifdef CONFIG_ANDROID_AB
	/* write the slot-b and slot-b backup */
	if (!get_ab_partition(temp)) {
		if (0 != common_raw_write(temp, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, header_buf))
			return OPERATE_WRITE_ERROR;

		if (0 != common_raw_write(temp, (uint64_t)size, (uint64_t)0, NV_HEADER_SIZE, buf))
			return OPERATE_WRITE_ERROR;

		part_name_bak = _get_backup_partition_name(temp);
		if (NULL == part_name_bak) {
			errorf(" get slotb backup partition name fail\n");
			return OPERATE_WRITE_ERROR;
		}
		if (0 != common_raw_write(part_name_bak, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, header_buf))
			return OPERATE_WRITE_ERROR;

		if (0 != common_raw_write(part_name_bak, (uint64_t)size, (uint64_t)0, NV_HEADER_SIZE, buf))
			return OPERATE_WRITE_ERROR;
	}
#endif
	return OPERATE_SUCCESS;
}

static PARTITION_IMG_TYPE dl_get_partition_image_type(char *part_name,
	unsigned char *buf, ulong sechdr_offset)
{
	return g_dl_eMMCStatus.curImgType;
}

static int sparse_resize_check(uint8_t *buf)
{
	sparse_header_t *sparse_header = (sparse_header_t *)buf;

	g_sparse_size = sparse_header->total_blks * (uint64_t)sparse_header->blk_sz;
	debugf("sparse_real_size is %ld, emmc_buf_size is %ld\n", g_sparse_size, emmc_buf_size);
	if (g_sparse_size * 2 < emmc_buf_size) {
		g_resize_config.buffer_begin = g_eMMCBuf + emmc_buf_size - g_sparse_size;
		debugf("reserved address start at %ld, end at %ld!\n", g_resize_config.buffer_begin, g_resize_config.buffer_end);
		memset(g_resize_config.buffer_begin, 0, g_sparse_size);
		return 0;
	}
	return -1;
}

/**
 * fail return (< 0), otherwise return the remaining count
 */
int dl_image_write(char *part_name, uint64_t write_size, uint64_t write_offset,
	uint64_t buf_max_size, unsigned char *buf, PARTITION_IMG_TYPE img_format,
	PARTITION_PURPOSE part_purpose)
{
	uint64_t total_size = 0;
	int retval = 0, i;
	char temp[32] = {0};
	int v_ab_flag = !get_ab_partition(temp);
	int succ;
	boot_mode_t boot_role = get_boot_role();

	/* Reserved buffer used to save a copy of userdata img which is resized in memory directly. */
	f2fs_init_resize_configuration();
        g_resize_config.buffer_end = g_eMMCBuf + emmc_buf_size;

	/* Do not sync userdata to emmc if it can be resized in memory. */
	if (IMG_WITH_SPARSE == img_format) {
		if (!strcmp(part_name, "userdata"))
			/* Check wheather userdata img with sparse can be resized in memory directly. */
			g_resize_config.resize_flag = (sparse_resize_check(buf) < 0) ? DONT_RESIZE : RESIZE_IN_MEM;

		succ = 0;
#ifdef CONFIG_WR_SPARSE
		if (boot_role == BOOTLOADER_MODE_LOAD) {/* only fastboot mode */
			debugf("flush the saving of image partition %s\n", part_name);
			retval = wr_sparse_flush();
			if (retval == -1) {
				debugf("wr sparse not enable\n");
			} else if (retval < 0) {
				errorf("%s flush fail\n", part_name);
				return 0;
			} else {
				succ = 1;
				debugf("flush success\n");
			}
		}
#endif
		if (!succ) {
			debugf("Handle the saving of image with sparse,name=%s,buf start at 0x%p,size=0x%llx\n",
			       part_name, buf, write_size);
			retval = write_sparse_img(part_name, buf, (ulong)write_size);
			if (-1 == retval) {
				errorf("Write sparse img fail\n");
				return -1;
			}
		}
	} else if (PARTITION_PURPOSE_NV == part_purpose) {
		if (OPERATE_SUCCESS != dl_write_nv_img(part_name, buf, FIXNV_SIZE)) {
			errorf("Write nv img fail\n");
			return -2;
		}
	/* Try to resize userdata in memory when cmmc_buf_size is larger than twice size of userdata raw image */
	} else if (!strcmp(part_name, "userdata") && g_status.total_size * 2 < emmc_buf_size) {
		/* We need to reserve a copy in memory to prevent something wrong happens during resize phase */
		g_resize_config.buffer_begin = g_eMMCBuf + emmc_buf_size - g_status.total_size;
		memcpy(g_resize_config.buffer_begin + write_offset, g_eMMCBuf, write_size);
		g_raw_size += write_size;
		g_resize_config.resize_flag = RESIZE_IN_MEM;
	} else {
		/* Download the image to emmc directly if it does not satisfy the resize condition */
		if (0 != common_raw_write(part_name, (uint64_t)write_size, (uint64_t)0, (uint64_t)write_offset, buf)) {
			errorf("write %s size 0x%llx offset 0x%llx fail\n", part_name, write_size, write_offset);
			g_status.unsave_recv_size = 0;
				return -3;
		} else if (!strcmp(part_name, "userdata")) {
			g_resize_config.resize_flag = DONT_RESIZE;
			errorf("small buffer, skip resize, please check dts!\n");
		}
		if (v_ab_flag) {
			debugf("download slot: %s\n", temp);
			if (0 != common_raw_write(temp, (uint64_t)write_size, (uint64_t)0,
							(uint64_t)write_offset, buf)) {
				errorf("write %s size 0x%llx offset 0x%x fail\n", temp, write_size, 0);
				return -4;
			}
		}
	}
	return retval;
}

OPERATE_STATUS _download_image(void)
{
	unsigned char *part_name = g_dl_eMMCStatus.curUserPartitionName;
	PARTITION_IMG_TYPE img_format = IMG_RAW;
	OPERATE_STATUS status = OPERATE_SUCCESS;
	PARTITION_PURPOSE part_purpose;
	ulong strip_header = 0;
	uint32_t write_size = 0;
	uchar * write_start = NULL;
	uint64_t total_size = 0;
	int32_t retval = 0, i = 0;
	uint64_t img_resize_size = 0;

#if defined (CONFIG_SECURE_BOOT) ||defined (CONFIG_SECBOOT)
	/* secboot verify */
	debugf("SECUREBOOT_ENABLE!\n");
	status = dl_secboot_verify(&strip_header,
				part_name,
				g_status.unsave_recv_size, g_status.total_size, g_eMMCBuf);
	if (OPERATE_SUCCESS != status)
		return status;

        if (strncmp(part_name, "vbmeta", 6) ==0) {
		//OPERATE_STATUS dl_erase(unsigned char *part_name, uint64_t size);
		uint64_t total_size = 0;
		get_img_partition_size(part_name, &total_size);
		if (OPERATE_SUCCESS != dl_erase(part_name, total_size)) {
			errorf("erase vbmeta partition fail\n");
			return OPERATE_WRITE_ERROR;
		}
	}
#endif

	/* verify nv image */
	part_purpose = dl_get_partition_purpose(part_name);
	if ((PARTITION_PURPOSE_NV == part_purpose)
			&& (OPERATE_SUCCESS != dl_check_nv_img())) {
		errorf("Verify NV image fail\n");
		return OPERATE_WRITE_ERROR;
	}

	img_format = dl_get_partition_image_type(part_name, g_eMMCBuf, 0);
	write_size = g_status.unsave_recv_size;
	write_start = g_eMMCBuf;

	/* image write */
	retval = dl_image_write(part_name, write_size, g_dl_eMMCStatus.offset, emmc_buf_size,
				write_start, img_format, part_purpose);
	if (retval < 0) {
		g_status.unsave_recv_size = 0;
		errorf("Write sparse img fail\n");
		return OPERATE_WRITE_ERROR;
	} else if (retval > 0) {
		memmove(g_eMMCBuf, write_start + retval, write_size - retval);
		g_status.unsave_recv_size = write_size - retval;
		debugf("After simg , unsave_recv_size=%lld, saved value=%d\n", g_status.unsave_recv_size, retval);
	} else { /* write success */
	/* backup */
		status = dl_backup(part_name, write_size, write_start);
		if (OPERATE_WRITE_ERROR == status) {
			errorf("Write backup(%s) img fail\n", part_name);
			return status;
		} else {
			status = OPERATE_SUCCESS;
		}

		if (img_format == IMG_RAW) {
			g_dl_eMMCStatus.offset += write_size;
		}
		g_status.unsave_recv_size = 0;
	}

	if (!strcmp("userdata", part_name) && (g_status.total_recv_size == g_status.total_size)) {
		if (g_resize_config.resize_flag != DONT_RESIZE) {
			debugf("write %s size 0x%x ok\n", part_name, write_size);
			total_size = 0;
			get_img_partition_size(part_name, &total_size);
			img_resize_size = (IMG_WITH_SPARSE == img_format) ? g_sparse_size : g_raw_size;
			i = f2fs_resize_main(total_size,
				512,
				f2fs_write_callback,
				f2fs_read_callback,
				(void*)part_name,
				write_start,
				emmc_buf_size,
				img_resize_size);
			if (i == 0) {
				debugf("resize usedata ok\n");
			} else {
				debugf("resize usedata error\n");
			}
		} else {
			debugf("buffer is too small, skip resize!\n");
		}
	}
	return status;
}

OPERATE_STATUS regular_download_process(uint32_t size, char *buf)
{
	uint32_t lastSize;
	OPERATE_STATUS ret;
	uint64_t buf_size = emmc_buf_size > SZ_256M ? SZ_256M : emmc_buf_size;

	if (buf_size >= (g_status.unsave_recv_size + size)) {
		memcpy((uchar *) g_sram_addr, buf, size);
		g_sram_addr += size;
		g_status.unsave_recv_size += size;

		if (g_status.total_recv_size == g_status.total_size) {
			ret = _download_image();
			return ret;
		}
	} else {
		lastSize = buf_size - g_status.unsave_recv_size;
		debugf("Unsaved buf size overflow the whole buffer size,lastsize=%u,unsavedsize=%llu\n", lastSize, g_status.unsave_recv_size);
		if (0 != lastSize)
			memcpy((unsigned char *)g_sram_addr, buf, lastSize);

		g_status.unsave_recv_size = buf_size;

		ret = _download_image();
		if (OPERATE_SUCCESS != ret)
			return ret;

		g_sram_addr = (unsigned long) (g_eMMCBuf + g_status.unsave_recv_size);
		memcpy((uchar *) g_sram_addr, (char *)(&buf[lastSize]), size - lastSize);
		g_status.unsave_recv_size += size - lastSize;
		g_sram_addr = (unsigned long) (g_eMMCBuf + g_status.unsave_recv_size);
		debugf("After write,unsaved recv size=%lld\n", g_status.unsave_recv_size);

		if (g_status.total_recv_size == g_status.total_size) {
			ret = _download_image();
			return ret;
		}

	}
	return OPERATE_SUCCESS;
}

static void merge_fulldumpdb_to_data(void)
{

	disk_partition_t partition_entry_tmp;
	int i = 0;
	int res = 0;
	int need_write = 0;

	if (partition_info_bk == NULL) {
		errorf("partition_info_bk is NULL, do nothing !\n");
		return;
	}

	for (i = 0; i < total_partition_num_bk;i++) {
		if (0 == strcmp(partition_info_bk[i].name, "fulldumpdb")) {
			memcpy((void *)&partition_entry_tmp, (void *)&partition_info_bk[i], sizeof(disk_partition_t));
			memcpy((void *)&partition_info_bk[i], (void *)&partition_info_bk[i + 1], sizeof(disk_partition_t));
			memset((void *)&partition_info_bk[i + 1], 0, sizeof(disk_partition_t));
			partition_info_bk[i].start = partition_entry_tmp.start;
			printf("merge_fulldumpdb_to_data ok !\n\n");
			total_partition_num_bk -= 1;
			need_write = 1;
			break;
		}
	}
	if (need_write == 1) {
		res = common_repartition(partition_info_bk, (int)total_partition_num_bk);
		if (0 != res)
			errorf("merge_fulldumpdb_to_data write error !\n\n");
		free(partition_info_bk);
		partition_info_bk = NULL;
	}
}

OPERATE_STATUS dl_erase(unsigned char *part_name, uint64_t size)
{
	uchar *part_name_bak = NULL;

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
		/*
		 * operation was not allow when requirement was not from edl,
		 * or factory download
		 */
		if (dl_check_reboot_edl()) {
			return OPERATE_SYSTEM_ERROR; /* return BSL_REP_OPERATION_FAILED to pctool */
		}
#endif
	printf("%s: fastboot_mode_flag = %d\n", __func__, fastboot_mode_flag);
	if ( 0 == wt_check_download_permission() 
#ifndef WT_COMPILE_FACTORY_VERSION
#ifdef WT_FINAL_RELEASE
		&& (check_efused() > 0 && fastboot_mode_flag != MODE_FASTBOOT_FACTORY) 
#endif
#endif
	    ) {
            return OPERATE_SYSTEM_ERROR;
        }

	if ((0 == strcmp(part_name, "erase_all")) && (0xffffffff == size)) {
		debugf("Erase all!\n");
		if (0 != common_raw_erase(part_name, 0, 0))
			return OPERATE_WRITE_ERROR;
	}
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	else if(0 == strcmp(part_name, "config")){
		part_name = "persist";
		if(0 != common_raw_erase(part_name, size, 0)){
			return OPERATE_WRITE_ERROR;
		}
	}
#endif

	else {
		debugf("erase partition %s!\n", part_name);

		if (0 == strcmp(part_name, "fulldumpdb")) {
			debugf("mark fulldumpdb erase partition flag!\n");
			fulldumpdb_erase_flag = 1;
			/*will merge partition later , do not need erase it */
			return OPERATE_SUCCESS;
		}
		if (0 == strcmp(part_name, "sysdumpdb")) {
			debugf("mark sysdumpdb erase partition flag!\n");
			sysdumpdb_erase_flag = 1;
#ifdef CONFIG_FULLDUMP_INTERNAL_ENABLE
			if(fulldumpdb_erase_flag == 1) {
		/* sysdumpdb erase operation means must be tatol pac, fulldumpdb_erase_flag = 0 means do not need fulldumpdb   */
				printf("erase sysdumpdb, fulldumpdb means do not need fulldumpdb\n");
				merge_fulldumpdb_to_data();
			}
#else
		/*	fulldump internal disable, must merge partition	*/
				merge_fulldumpdb_to_data();
#endif
		}
		if (0 != common_raw_erase(part_name, size, 0)) {
			return OPERATE_WRITE_ERROR;
		}

		part_name_bak = _get_backup_partition_name(part_name);

		if (NULL != part_name_bak) {
			if (0 != common_raw_erase(part_name_bak, size, 0))
				return OPERATE_WRITE_ERROR;
		}

		if(0 == strcmp(part_name, UBOOT_LOG_PARTITION)) {
		/* in download mode, initialize log if uboot log partition is erased */
			reinit_write_log();
		}
	}

	return OPERATE_SUCCESS;
}

static int fixnv_ab_status = 0;
static int partition_fixnv_ab_exist_check(uchar *partition_name)
{
	char write_temp[4] = {0};
	char temp[MAX_PARTITION_NAME_SIZE] = {0};
	uchar partition_without_ab[MAX_PARTITION_NAME_SIZE] = {0};
	uchar partition_with_ab[MAX_PARTITION_NAME_SIZE] = {0};
	size_t string_size = 0;
	int ret = 0;

	string_size = strlen(g_dl_eMMCStatus.curUserPartitionName);
	/* Used to check whether the pac fixnv is used vab partition */
	if (!get_ab_partition(temp)) {
		strncpy(partition_without_ab, g_dl_eMMCStatus.curUserPartitionName, string_size - strlen("_a"));
		strcpy(partition_with_ab, g_dl_eMMCStatus.curUserPartitionName);
		fixnv_ab_status |= PAC_WITH_SLOT_AB;
	} else {
		strcpy(partition_without_ab, g_dl_eMMCStatus.curUserPartitionName);
		snprintf(partition_with_ab, string_size + 3, "%s%s", g_dl_eMMCStatus.curUserPartitionName, "_a");
		fixnv_ab_status |= PAC_WITHOUT_SLOT_AB;
	}
	/* Used to check whether the local partition fixnv is used vab */
	if (0 != common_raw_read(partition_with_ab, (uint64_t) ARRAY_SIZE(write_temp), 0, write_temp)) {
		fixnv_ab_status |= DEVICE_WITHOUT_SLOT_AB;
	} else {
		fixnv_ab_status |= DEVICE_WITH_SLOT_AB;
		strcpy(partition_with_ab, get_slot_ab(partition_without_ab));
	}
	switch(fixnv_ab_status) {
		case PAC_WITH_SLOT_AB | DEVICE_WITH_SLOT_AB:
			debugf("fixnv download status:PAC_WITH_SLOT_AB | DEVICE_WITH_SLOT_AB\n");
			strcpy(partition_name, partition_with_ab);
			break;
		case PAC_WITH_SLOT_AB | DEVICE_WITHOUT_SLOT_AB:
			debugf("fixnv download status:PAC_WITH_SLOT_AB | DEVICE_WITHOUT_SLOT_AB\n");
			strcpy(partition_name, partition_without_ab);
			break;
		case PAC_WITHOUT_SLOT_AB | DEVICE_WITH_SLOT_AB:
			debugf("fixnv download status:PAC_WITHOUT_SLOT_AB | DEVICE_WITH_SLOT_AB\n");
			strcpy(partition_name, partition_with_ab);
			break;
		case PAC_WITHOUT_SLOT_AB | DEVICE_WITHOUT_SLOT_AB:
			debugf("fixnv download status:PAC_WITHOUT_SLOT_AB | DEVICE_WITHOUT_SLOT_AB\n");
			strcpy(partition_name, partition_without_ab);
			break;
		default:
			errorf("Cannot be analyzed the status of fixnv partition\n");
			return -1;
	}
	return 0;
}

int32_t _read_repair_nv_img(uchar * partition_name, uchar * buf)
{
	uchar *backup_partition_name = NULL;
	uchar header_buf[NV_HEADER_SIZE];
	uchar backup_header_buf[NV_HEADER_SIZE];
	nv_header_t *header_p = header_buf;
	nv_header_t *backup_header_p = backup_header_buf;
	uchar * backup_nv_buf = NULL;
	int status = ORIGIN_BACKUP_NV_OK;
	int ret = 0;
#ifdef CONFIG_ANDROID_AB
	uchar slotb_partition_name[MAX_PARTITION_NAME_SIZE] = {0};
	uchar *slotb_backup_partition_name = NULL;
	uchar *buf_temp = NULL;
	uchar *header_buf_temp = NULL;
	uint32_t len_temp = 0;
#endif
	uchar partition_check[MAX_PARTITION_NAME_SIZE] = {0};
	backup_nv_buf = buf + SZ_16M;

#ifdef CONFIG_ANDROID_AB
	if  (0 != partition_fixnv_ab_exist_check(partition_check))
		return -1;
#else
	strcpy(partition_check, partition_name);
#endif
	debugf("repair nv img with partition : %s\n", partition_check);

	do {
		/*read origin image header */
		if (0 != common_raw_read(partition_check, NV_HEADER_SIZE, (uint64_t)0, header_buf)) {
			errorf("read origin nv image header failed\n");
			status |= ORIGIN_NV_DAMAGED;
			break;
		}

		if (NV_HEAD_MAGIC != header_p->magic) {
			errorf("nv header magic error, wrong magic=0x%x\n", header_p->magic);
			status |= ORIGIN_NV_DAMAGED;
			break;
		}

		/*read origin image */
		if (0 != common_raw_read(partition_check, (uint64_t)(header_p->len), NV_HEADER_SIZE, buf)) {
			errorf("read origin nv image failed\n");
			status |= ORIGIN_NV_DAMAGED;
			break;
		}

		/*check crc */
		if (fdl_check_crc(buf, header_p->len, header_p->checksum)) {
#ifdef CONFIG_ANDROID_AB
			buf_temp = buf;
			header_buf_temp = header_buf;
			len_temp = header_p->len;
#endif
			debugf("read origin nv image success and crc correct\n");
		} else {
			errorf("check origin nv image crc wrong\n");
			status |= ORIGIN_NV_DAMAGED;
		}
	} while(0);

	/*get the backup partition name */
	backup_partition_name = _get_backup_partition_name(partition_check);
	if (NULL == backup_partition_name){
#ifdef NV_ENCRYPTION
		debugf("partition_name is %s\n", partition_check);
		if(strstr(partition_check, "fix")!= NULL){
			decryptFixnvPartition(buf);
		}else if(strstr(partition_check, "run")!= NULL){
			decryptRunnvPartition(buf);
		}
		debugf("partition_name is %s,decrypt success\n", partition_name);
#endif
		return 0;
	}

	do {
		/*read backup header */
		if (0 != common_raw_read(backup_partition_name, NV_HEADER_SIZE, (uint64_t)0, backup_header_buf)) {
			errorf("read backup nv image header failed\n");
			status |= BACKUP_NV_DAMAGED;
			break;
		}

		if (NV_HEAD_MAGIC != backup_header_p->magic) {
			errorf("backup nv header magic error, wrong magic=0x%x\n", backup_header_p->magic);
			status |= BACKUP_NV_DAMAGED;
			break;
		}

		/*read bakup image */
		if (0 != common_raw_read(backup_partition_name, (uint64_t)(backup_header_p->len), NV_HEADER_SIZE, backup_nv_buf)) {
			errorf("read backup nv image failed\n");
			status |= BACKUP_NV_DAMAGED;
			break;
		}

		/*check crc */
		if (fdl_check_crc(backup_nv_buf, backup_header_p->len, backup_header_p->checksum)) {
#ifdef CONFIG_ANDROID_AB
			buf_temp = backup_nv_buf;
			header_buf_temp = backup_header_buf;
			len_temp = backup_header_p->len;
#endif
			debugf("read backup nv image success and crc correct\n");
		} else {
			errorf("check backup nv image crc wrong\n");
			status |= BACKUP_NV_DAMAGED;
		}
	} while(0);

	switch (status) {
	case ORIGIN_BACKUP_NV_OK :
		debugf("both org and bak nv partition are ok\n");
#ifdef CONFIG_ANDROID_AB
		if (fixnv_ab_status == (PAC_WITH_SLOT_AB | DEVICE_WITH_SLOT_AB) && !get_ab_partition(slotb_partition_name))
			goto write_slot_b;
#endif
		ret = 1;
		break;
	case ORIGIN_NV_DAMAGED :
		memcpy(buf, backup_nv_buf, backup_header_p->len);
		if (0 != common_raw_write(partition_check, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, backup_header_buf)) {
			ret = 0;
			break;
		}
		debugf("Start to write remain blocks of origin NV partition\n");
		if (0 != common_raw_write(partition_check, (uint64_t)(backup_header_p->len), (uint64_t)0, NV_HEADER_SIZE, backup_nv_buf)) {
			ret = 0;
			break;
		}
#ifdef CONFIG_ANDROID_AB
		if (fixnv_ab_status == (PAC_WITH_SLOT_AB | DEVICE_WITH_SLOT_AB) && !get_ab_partition(slotb_partition_name))
			goto write_slot_b;
#endif
		ret = 1;
		break;
	case BACKUP_NV_DAMAGED :
		if (0 != common_raw_write(backup_partition_name, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, header_buf)) {
			ret = 0;
			break;
		}
		debugf("Start to write remain blocks of backup NV partition\n");
		if (0 != common_raw_write(backup_partition_name, (uint64_t)(header_p->len), (uint64_t)0, NV_HEADER_SIZE, buf)) {
			ret = 0;
			break;
		}
#ifdef CONFIG_ANDROID_AB
		if (fixnv_ab_status == (PAC_WITH_SLOT_AB | DEVICE_WITH_SLOT_AB) && !get_ab_partition(slotb_partition_name))
			goto write_slot_b;
#endif
		ret = 1;
		break;
	case ORIGIN_NV_DAMAGED | BACKUP_NV_DAMAGED :
		errorf("both org and bak partition are damaged!\n");
		ret = 0;
		break;
	}
#ifdef NV_ENCRYPTION
	debugf("partition_name is %s\n", partition_name);
	if(strstr(partition_name, "fixnv")!= NULL){
		decryptFixnvPartition(buf);
	}else if(strstr(partition_name, "runtimenv")!= NULL){
		decryptRunnvPartition(buf);
	}
	debugf("partition_name is %s,decrypt success\n", partition_name);
#endif
	return ret;

#ifdef CONFIG_ANDROID_AB
write_slot_b:
	if (0 != common_raw_write(slotb_partition_name, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, header_buf_temp))
		return 0;
	debugf("SLOTB_ORIGIN_NV_write:Start to write remain blocks of backup NV partition\n");
	if (0 != common_raw_write(slotb_partition_name, (uint64_t)len_temp, (uint64_t)0, NV_HEADER_SIZE, buf_temp))
		return 0;
	slotb_backup_partition_name = _get_backup_partition_name(slotb_partition_name);
	if (NULL == slotb_backup_partition_name) {
		errorf(" get slotb backup partition name fail\n");
		return 0;
	}
	if (0 != common_raw_write(slotb_backup_partition_name, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, header_buf_temp))
		return 0;
	debugf("SLOTB_BACKUP_NV_write:Start to write remain blocks of backup NV partition\n");
	if (0 != common_raw_write(slotb_backup_partition_name, (uint64_t)len_temp, (uint64_t)0, NV_HEADER_SIZE, buf_temp))
		return 0;
#ifdef NV_ENCRYPTION
	debugf("partition_name is %s\n", partition_name);
	if(strstr(partition_name, "fixnv") != NULL){
		decryptFixnvPartition(buf);
	}else if(strstr(partition_name, "runtimenv")!= NULL){
		decryptRunnvPartition(buf);
	}
	debugf("partition_name is %s,decrypt success\n", partition_name);
#endif
	return 1;
#endif
}


OPERATE_STATUS dl_read_start(uchar * partition_name, uint64_t size)
{
	size_t sblock_size = 0;
	struct ext2_sblock *sblock = NULL;

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	/*
	 * operation was not allow when requirement was not from edl,
	 * or factory download
	 */
	if (dl_check_reboot_edl()) {
		return OPERATE_SYSTEM_ERROR; /* return BSL_REP_OPERATION_FAILED to pctool */
	}
#endif
	debugf("partition_name is %s,starting......\n", partition_name);
        if ( 0 == wt_check_download_permission() ) {
            return OPERATE_SYSTEM_ERROR;
        }

	strcpy(g_dl_eMMCStatus.curUserPartitionName, partition_name);
	/*get special partition attr */
	_get_partition_attribute(partition_name);

	if (PARTITION_PURPOSE_NV == g_dl_eMMCStatus.partitionpurpose) {
		if (!_read_repair_nv_img(g_dl_eMMCStatus.curUserPartitionName, g_eMMCBuf))
			return OPERATE_SYSTEM_ERROR;
	}


	if (0 == strcmp("prodnv", g_dl_eMMCStatus.curUserPartitionName)) {
		sblock_size = sizeof(struct ext2_sblock);
		sblock = malloc(sblock_size);
		if (NULL == sblock) {
			errorf("malloc sblock failed\n");
			goto err;
		}

		if (0 != common_raw_read(g_dl_eMMCStatus.curUserPartitionName, (uint64_t)sblock_size, (uint64_t)1024, sblock)) {
			errorf("read prodnv super block fail\n");
			goto err;
		}

		if (sblock->magic != EXT2_MAGIC) {
			errorf("bad prodnv image magic(0x%x)\n", sblock->magic);
			goto err;
		}
		free(sblock);
	}

	return OPERATE_SUCCESS;
err:
	if (NULL != sblock)
		free(sblock);
	return OPERATE_SYSTEM_ERROR;
}

OPERATE_STATUS dl_read_midst(uint32_t size, uint64_t off, uchar * buf)
{
	if (PARTITION_PURPOSE_NV == g_dl_eMMCStatus.partitionpurpose) {
		memcpy(buf, (uchar *) (g_eMMCBuf + off), size);
	} else {
		if (0 != common_raw_read(g_dl_eMMCStatus.curUserPartitionName, (uint64_t)size, (uint64_t)off, buf)) {
			errorf("read error!\n");
			return OPERATE_SYSTEM_ERROR;
		}
	}

	return OPERATE_SUCCESS;
}

OPERATE_STATUS dl_read_end(void)
{
	return OPERATE_SUCCESS;
}
int get_prestatus_recored_flag(void)
{
	int dump_flag = 0;


	if (0 != common_raw_read(SYSDUMPDB_PARTITION_NAME, (uint64_t)sizeof(dump_flag), (uint64_t)SYSDUMPDB_PARTITION_DUMP_FLAG_SIZE, &dump_flag)) {
		printf("common_raw_read %s  parttition fail\n",SYSDUMPDB_PARTITION_NAME);
		return 0;
	}
	if('Y' == (dump_flag >> SYSDUMPDB_PARTITION_DUMP_FLAG_OFFSET) & 0xff)
		return 1;
	return 0;
}

int fulldumpdb_non_total_pac(void)
{
	int32_t res = 0;
	if(!fulldumpdb_erase_flag) {
		if(!sysdumpdb_erase_flag) {
			/* here just run one time*/
			if(non_total_pac_handle_flag == 1)
				return;
			/* the two flag are all 0 means ,  all of these are not selected */
			/* fulldumpdb exsit status shoulde be  set as prestatus */
			prestatus_recored_flag = get_prestatus_recored_flag();
			if(!prestatus_recored_flag) {
				printf("%s:  prestatus not exsit,  need merge parttition \n", __func__);
				merge_fulldumpdb_to_data();
			} else {
				printf("%s:prestatus  exsit , do not need merge parttition \n",__func__);
			}
			non_total_pac_handle_flag = 1;
		}
	}
}

OPERATE_STATUS dl_download_start(uchar * partition_name, uint64_t size, uint32_t nv_checksum)
{
	int i = 0;
	uint32_t size_in_lba = 0;
	int32_t res = 0;
#ifdef CONFIG_FULLDUMP_INTERNAL_ENABLE
	fulldumpdb_non_total_pac();
#endif
	g_status.total_size = size;
	strcpy(g_dl_eMMCStatus.curUserPartitionName, partition_name);
	g_dl_eMMCStatus.offset = 0;

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	/*
	 * operation was not allow when requirement was not from edl,
	 * or factory download
	 */
	if (dl_check_reboot_edl()) {
		return OPERATE_SYSTEM_ERROR; /* return BSL_REP_OPERATION_FAILED to pctool */
	}
#endif
        if ( 0 == wt_check_download_permission() ) {
            return OPERATE_SYSTEM_ERROR;
        }
	/*get special partition attr */
	_get_partition_attribute(partition_name);

	if (PARTITION_PURPOSE_NV == g_dl_eMMCStatus.partitionpurpose) {
		debugf("partition purpose is NV\n");
		if (size > FIXNV_SIZE) {
			errorf("size(0x%llx) beyond FIXNV_SIZE:0x%x !\n", size, FIXNV_SIZE);
			return OPERATE_INVALID_SIZE;
		}
		memset(g_eMMCBuf, 0xff, FIXNV_SIZE + NV_HEADER_SIZE);
		g_checksum = nv_checksum;
	} else if (0 == strcmp("splloader", partition_name)) {
		memset(g_eMMCBuf, 0xff, SPL_CHECKSUM_LEN);
	}

	g_status.total_recv_size = 0;
	g_status.unsave_recv_size = 0;
	g_sram_addr = (void *) g_eMMCBuf;

	prepare_alternative_buffers();
	return OPERATE_SUCCESS;
}

OPERATE_STATUS dl_download_midst(uint32_t size, char *buf)
{
	uint32_t lastSize;
	uint32_t nSectorCount;
	uint32_t fix_nv_checksum;
	int ret = 0;
	ulong sec_offset = 0;
	uint64_t total_size = 0;

	int local_buf_index;
	sparse_header_t sparse_header_test_head;

	/*adjust the image type via the header magic*/
	if (0 == g_status.total_recv_size ) {
#ifdef CONFIG_SECURE_BOOT
		if (0 == strcmp(buf, HEADER_NAME))
			sec_offset = KEY_INFO_SIZ + VLR_INFO_SIZ;
#endif
#ifdef CONFIG_SECBOOT
		if (IMG_BAK_HEADER == ((sys_img_header *)buf)->mMagicNum)
			sec_offset = SYS_HEADER_SIZE;
#endif
		memset(&sparse_header_test_head, 0, sizeof(sparse_header_t));
		memcpy(&sparse_header_test_head, buf + sec_offset, sizeof(sparse_header_test_head));

		if (sparse_header_test_head.magic != SPARSE_HEADER_MAGIC)
			g_dl_eMMCStatus.curImgType = IMG_RAW;
		else
			g_dl_eMMCStatus.curImgType = IMG_WITH_SPARSE;
		/* Just erase the emmc when download first part of userdata. */
		if (!strcmp(g_dl_eMMCStatus.curUserPartitionName, "userdata")
			&& !get_img_partition_size(g_dl_eMMCStatus.curUserPartitionName, &total_size) && g_download_part_count == 0) {
			debugf("userdata img_format(%d),erase size (%lld/100)\n", g_dl_eMMCStatus.curImgType, total_size);
			common_raw_erase(g_dl_eMMCStatus.curUserPartitionName, total_size / 100, (uint64_t)0LL);
			g_download_part_count += 1;
		}
	}

	g_status.total_recv_size += size;

#if defined (CONFIG_SECURE_BOOT) ||defined (CONFIG_SECBOOT)

#ifdef CONFIG_SYSTEM_VERIFY
	ret = regular_download_process(size, buf);
#else
	if ((IMG_RAW == g_dl_eMMCStatus.curImgType) &&
                ((0 == strcmp("system", g_dl_eMMCStatus.curUserPartitionName)) || (0 == strcmp("super", g_dl_eMMCStatus.curUserPartitionName))))
		ret = speedup_download_process(size, buf);
	else
		ret = regular_download_process(size, buf);
#endif

#else
	if ((IMG_RAW == g_dl_eMMCStatus.curImgType)
	     && ((PARTITION_PURPOSE_NV != g_dl_eMMCStatus.partitionpurpose)
		  && (g_status.total_size > ALTERNATIVE_BUFFER_SIZE)))
		ret = speedup_download_process(size, buf);
	else
		ret = regular_download_process(size, buf);
#endif

	return ret;

}

OPERATE_STATUS dl_download_flush_data(uint32_t total_len, unsigned char *total_buf,
						uint16_t size, unsigned char *buf)
{
	unsigned char *pdata = (unsigned char *)total_buf;
	unsigned char hash[32];
	unsigned char Cnt;

	if (0x20 != size)
		return OPERATE_INVALID_SIZE;

	sha256_csum_wd((const unsigned char*)pdata, (uint32_t)total_len, hash, 0);

	if (memcmp(hash, buf, 32))
		return OPERATE_CHECKSUM_DIFF;

	return OPERATE_SUCCESS;
}

OPERATE_STATUS dl_download_end(void)
{
	char buf[WDTEN_DATA_LEN] = {0};
	if(!strcmp(g_dl_eMMCStatus.curUserPartitionName,"miscdata")){
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
		/* restore reboot-edl flags if necessary */
		if (!dl_check_reboot_edl()) {
			if (!fb_check_secboot_enable() && fb_require_reboot_edl(1)) {
				errorf("restore reboot edl flags fail\n");
				return OPERATE_SYSTEM_ERROR;
			}
		}
#endif

		int efused = check_efused();
		printf("%s: efused=%d\n", __func__, efused);
        if ( check_fastboot_edl() ) {
            if ( efused > 0 ) {
	            unsigned char fastboot_reboot_edl[2] = {0};
	            fastboot_reboot_edl[0] = 1;

	            oem_repair_write_mmc_ex("fastboot_reboot_edl", fastboot_reboot_edl);
		        printf("%s: restore reboot edl flags ...\n", __func__);
			}
        }

		if(0 != common_raw_erase(g_dl_eMMCStatus.curUserPartitionName, DATETIME_LEN, DATETIME_OFFSET))
			return OPERATE_WRITE_ERROR;
		if(0 != common_raw_erase(g_dl_eMMCStatus.curUserPartitionName, DEBUG_INFO_LEN, DEBUG_INFO_OFFSET))
			return OPERATE_WRITE_ERROR;

#ifdef DEBUG
		strcpy(buf, "disable");
#else
		strcpy(buf, "enable");
#endif
		if (0 != common_raw_write(g_dl_eMMCStatus.curUserPartitionName, WDTEN_DATA_LEN, 0, WDTEN_DATA_OFFSET, buf)) {
			errorf("write default WDT enable flag fail\n");
                  	return OPERATE_WRITE_ERROR;
		} else {
			debugf("write default WDT enable flag success\n");
		}
	}
	if (g_status.unsave_recv_size != 0) {
		debugf("unsaved size is not zero!\n");
		return OPERATE_SYSTEM_ERROR;
	}

	g_status.total_size = 0;

	if (0 != common_partition_sync(g_dl_eMMCStatus.curUserPartitionName))
		return OPERATE_WRITE_ERROR;

	return OPERATE_SUCCESS;
}

OPERATE_STATUS dl_repartition(uchar * partition_cfg, uint16_t total_partition_num,
									uchar version, uchar size_unit)
{
	disk_partition_t *partition_info;
	int32_t res = 0;

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	/*
	 * operation was not allow when requirement was not from edl,
	 * or factory download
	 */
	if (dl_check_reboot_edl()) {
		return OPERATE_SYSTEM_ERROR; /* return BSL_REP_OPERATION_FAILED to pctool */
	}
#endif
        if ( 0 == wt_check_download_permission() ) {
            return OPERATE_SYSTEM_ERROR;
        }
	/*prepare mem to store <total_partition_num> partitions' info */
	partition_info = malloc(sizeof(disk_partition_t) * total_partition_num);
	if (NULL == partition_info) {
		errorf("No space to store partition_info!\n");
		return OPERATE_SYSTEM_ERROR;
	}

	res = _parser_repartition_cfg(partition_info, partition_cfg, total_partition_num, version, size_unit);
	if (res < 0) {
		free(partition_info);
		return OPERATE_SYSTEM_ERROR;
	}

	if (partition_info_bk != NULL) {
		errorf("partition_info_bk is not NULL!\n");
		free(partition_info_bk);
	}
	partition_info_bk = malloc(sizeof(disk_partition_t) * total_partition_num);
	if (NULL == partition_info_bk) {
		errorf("No space to store partition_info!\n");
		return OPERATE_SYSTEM_ERROR;
	}
	memcpy(partition_info_bk, partition_info, sizeof(disk_partition_t) * total_partition_num);
	total_partition_num_bk = total_partition_num;
	printf("partition_info backup !\n");

	res = common_repartition(partition_info, (int)total_partition_num);
	free(partition_info);

	if (0 == res)
		return OPERATE_SUCCESS;
	else
		return OPERATE_SYSTEM_ERROR;
}

OPERATE_STATUS dl_read_ref_info(char *part_name, uint16_t size, uint64_t offset,
	char *receive_buf, char  *transmit_buf)
{
	if(0 != common_raw_read(part_name, (uint64_t)size, offset, transmit_buf)) {
		/* read old info from flash fail, transmit the receive info back to tool */
		debugf("read old info from flash fail\n");
		memcpy(transmit_buf, receive_buf, (size_t)size);
	}
	/* update receive ref info to flash */
	if(0 != common_raw_write(part_name, (uint64_t)size, (uint64_t)0, offset, receive_buf)){
		debugf("update receive ref info to flash fail\n");
		return  OPERATE_SYSTEM_ERROR;
	}
	return OPERATE_SUCCESS;
}

OPERATE_STATUS dl_record_pacdatetime(uchar * buf, uint64_t size)
{
	if(0 != common_raw_write(DATATIME_PARTNAME, size, (uint64_t)0, DATETIME_OFFSET, buf)){
		return OPERATE_WRITE_ERROR;
	}
	return OPERATE_SUCCESS;
}

#ifdef CONFIG_EMMC_DDR_CHECK_TYPE
static uint32_t flash_ddr_size_tab[] = {128, 256, 512, 1*1024, 2*1024, 3*1024, 4*1024, \
                6*1024, 8*1024, 16*1024, 32*1024, 64*1024, 128*1024, 256*1024, 512*1024};

uint32_t get_correct_size(uint32_t size)
{
	uint32_t i = 0;
	uint32_t diff_size = 50;
	uint32_t read_size = size;

	for(i = 0; i < sizeof(flash_ddr_size_tab)/sizeof(uint32_t); i++) {
		if(i < 3)
			diff_size = 50;
		else diff_size = 100;
		if(flash_ddr_size_tab[i]) {
			if(abs(flash_ddr_size_tab[i] - size) < diff_size) {
				read_size = flash_ddr_size_tab[i];
				break;
			}

		}
	}
	printf("correct size:%u\r\n", read_size);
	return read_size;
}

OPERATE_STATUS dl_get_flashtype(uchar * content, uint16_t * size)
{
	struct FLASH_TYPE flash_type;
	char temp[sizeof(struct FLASH_TYPE)];
	int i = 0;
	int j = 0;

	memset(&flash_type, 0, sizeof(struct FLASH_TYPE));

	/* dram size */
	int dram_size_inMB = 0;
	printf("get real ram size: 0x%lx\n", get_real_ram_size());
	dram_size_inMB = ((get_real_ram_size()/1024/1024)+5);
	printf("dram_size_inMB:%u\n", dram_size_inMB);
	flash_type.mid = get_correct_size(dram_size_inMB);

	/* calculate emmc size in GB */
	int mem_size = 0, size_inMB = 0;
	if (gd->boot_device == BOOT_DEVICE_EMMC) {
		mem_size = emmc_get_capacity(PARTITION_USER)/1000/1000;
		size_inMB = (mem_size+500)/1000*1024;
		debugf("emmc_size:%llu Byte, (%d MByte)\n",
			emmc_get_capacity(PARTITION_USER), size_inMB);
	}
#ifdef CONFIG_UFS
	if (gd->boot_device == BOOT_DEVICE_UFS) {
		mem_size = ufs_info.dev_total_cap * 512 / 1000 / 1000;
		size_inMB = (mem_size + 500) / 1000 * 1024;
		debugf("ufs_size:%llu Byte, (%d MByte)\n",
			ufs_info.dev_total_cap * 512, size_inMB);
	}
#endif

	/* did field is used for emmc size */
	flash_type.did = get_correct_size(size_inMB);

	*size = sizeof(struct FLASH_TYPE);
	memcpy(temp, &flash_type, *size);
	for (i = 0; i < *size; i++) {
		if ((i % 4) == 0)
			j = i + 4;
		content[i] = temp[--j];
	}
	return 1;
}
#endif

#ifdef CONFIG_WR_SPARSE
#define WR_UNP_CK_MAX	128
typedef struct {
	struct list_head node;
	__le16 type;						/* unprocess chunk type */
	u64 offset;							/* current offset on flush which next to be write */
	u64 chunk_len;						/* length of this chunk */
	u32 fill_val;						/* fill data if chunk type is FILL */
} wr_unp_ck_t;
#define WR_BUF_MAX		(SZ_8M)			/* write buffer size */
#define WR_LMAX_LIMIT	(SZ_8M)			/* write buffer max */
typedef struct {
	u8 wr_addr[WR_BUF_MAX];				/* write buffer */
	u8 wr_tmp[WR_BUF_MAX];				/* temp buffer */
	wr_unp_ck_t cks[WR_UNP_CK_MAX];		/* unprocess chunk nodes */
	char pname[PARTNAME_SZ];			/* unprocessed partition name */
	u64	wr_offset;						/* offset of flash for write buffer */
	u32 wr_len;							/* length of data in write buffer */
	u32 wr_lmax;						/* max length limit of write buffer */
	int free_cnt;						/* free chunks nodes available */
} wr_sparse_mgt_t;
static wr_sparse_mgt_t *g_wr_sparse;
static LIST_HEAD(unp_chunk_list);		/* unprocessed chunk list */
static LIST_HEAD(unp_free_list);		/* unprocessed free list */

#ifdef CONFIG_WRBG_SPARSE
static int wrbg_sparse_raw(wr_sparse_mgt_t *mgt, char *pname,
	u64 size, u64 offset, char *buf)
{
	u32 blk_count = 0;
	u32 tot_buf_size = current_buffer->size;
	u32 last_size = 0;

	if (current_buffer->spare > size) {
		memcpy(current_buffer->pointer, buf, size);
		current_buffer->used += size;
		current_buffer->spare -= size;
		current_buffer->pointer += size;
	} else {
		if (current_buffer->spare)
			memcpy(current_buffer->pointer, buf, current_buffer->spare);

		last_size = size - current_buffer->spare;
		if (BUFFER_DIRTY == current_buffer->next->status) {
			if (0 != common_query_backstage(pname,
						tot_buf_size, current_buffer->next->addr)) {
				errorf("%s query bg fail, next->addr=%p\n",
					pname, current_buffer->next->addr);
				return -2;
			}
		}

		wr_raw_dbg("%s wr bg write, current_buffer->addr:%p wr_offset:0x%llx, tot_buf_size:%llx\n",
			pname, current_buffer->addr, mgt->wr_offset, tot_buf_size);
		if (0 != common_write_backstage(pname,
			tot_buf_size, mgt->wr_offset, current_buffer->addr)) {
			errorf("%s write bg fail, wr_offset %llx addr %p\n", pname, mgt->wr_offset,
				current_buffer->addr);
			return -3;
		}

		mgt->wr_offset += tot_buf_size;

		if (last_size > current_buffer->size) {
			errorf("%s write bg fail, last_size %x current_buffer->size %x\n",
				pname, last_size, current_buffer->size);
			return -4;
		} else if (last_size) {
			memcpy(current_buffer->next->addr, buf + current_buffer->spare,
				last_size);
		}

		current_buffer->used = 0;
		current_buffer->spare = current_buffer->size;
		current_buffer->pointer = current_buffer->addr;
		current_buffer->status = BUFFER_DIRTY;

		current_buffer = current_buffer->next;
		current_buffer->pointer = current_buffer->addr + last_size;
		current_buffer->used = last_size;
		current_buffer->spare = current_buffer->size - last_size;
	}

	return 0;
}

static void wrbg_sparse_rest_alt(void)
{
	alter_buffer1.addr = g_wr_sparse->wr_addr;
	alter_buffer1.size = sizeof(g_wr_sparse->wr_addr) / 2;

	alter_buffer2.addr = g_wr_sparse->wr_addr + alter_buffer1.size;
	alter_buffer2.size = alter_buffer1.size;

	alter_buffer1.pointer = alter_buffer1.addr;
	alter_buffer1.used = 0;
	alter_buffer1.spare = alter_buffer1.size;
	alter_buffer1.status = BUFFER_CLEAN;
	alter_buffer1.next = &alter_buffer2;

	alter_buffer2.pointer = alter_buffer2.addr;
	alter_buffer2.used = 0;
	alter_buffer2.spare = alter_buffer2.size;
	alter_buffer2.status = BUFFER_CLEAN;
	alter_buffer2.next = &alter_buffer1;
	current_buffer = &alter_buffer1;
}

int wrbg_sparse_flush(char *pname)
{
	wr_sparse_mgt_t *mgt = g_wr_sparse;

	if (!mgt)
		return -1;

	if (BUFFER_DIRTY == current_buffer->next->status) {
		if (0 != common_query_backstage(pname,
					current_buffer->size, current_buffer->next->addr)) {
			errorf("%s flush query backstage fail, current_buffer->size: %x,"
				"current_buffer->next->addr %p\n",
				pname, current_buffer->size, current_buffer->next->addr);
			return -2;
		}
	}

	if (current_buffer->used) {
		if (0 != common_raw_write(pname,
					(u64)(current_buffer->used), (u64)0, mgt->wr_offset,
					current_buffer->addr)) {
			errorf("%s last cross write fail, current_buffer->used: %x"
				"wr_offset:%llx current_buffer->addr:%p\n",
				pname, current_buffer->used, mgt->wr_offset, current_buffer->addr);
			return -3;
		}

		/* update wr_offset */
		mgt->wr_offset += current_buffer->used;

	}
	/* reset alt buffer */
	wrbg_sparse_rest_alt();
	return 0;
}
#endif

int wr_sparse_raw(char *pname, u64 chunk_len, u64 offset, char *buf)
{
	wr_sparse_mgt_t *mgt = g_wr_sparse;
#ifdef CONFIG_WRBG_SPARSE
	const int wr_align_sz = SZ_2M;
	u64 align_offset = 0, sz = 0;
#else
	int spare;
#endif

	if (!mgt)
		return -1;

#ifdef CONFIG_WRBG_SPARSE
	if ((!alter_buffer1.used && !alter_buffer2.used) /* alt buffer is empty */
			&& (offset & (wr_align_sz - 1))) {
		/* flush backstage write */
		if (wrbg_sparse_flush(pname) < 0) {
			return -2;
		}

		align_offset = ALIGN(offset, wr_align_sz);
		sz = chunk_len > align_offset - offset ? align_offset - offset : chunk_len;

		wr_raw_dbg("wr align chunk_len %llx offset %llx wr_align_sz %x "
			"align_offset %llx sz %llx\n",
			chunk_len, offset, wr_align_sz, align_offset, sz);
		if (0 != common_raw_write(pname, sz, (u64)0, offset, buf)) {
			errorf("wr write fail, chunk_len:%llx sz:%llx offset:0x%llx, buf:%p\n",
				chunk_len, sz, offset, buf);
			return -3;
		}

		/* update wr_offset */
		mgt->wr_offset += sz;

		chunk_len -= sz;
		offset += sz;
	}

	if (chunk_len) {
		if (wrbg_sparse_raw(mgt, pname, chunk_len, offset, buf + sz) < 0) {
			errorf("%s chunk_len %llx offset %llx wr_offset %llx buf %p\n",
				pname, chunk_len, offset, mgt->wr_offset, buf + sz);
			return -4;
		}
	}
#else
	spare = mgt->wr_lmax - mgt->wr_len;
	if (spare < 0) {
		errorf("wr_lmax %lx < wr_len %lx\n", mgt->wr_lmax, mgt->wr_len);
		return -2;
	}

	if (mgt->wr_len + chunk_len > mgt->wr_lmax) {
		memcpy(mgt->wr_addr + mgt->wr_len, buf, spare);
		mgt->wr_len += spare;
		chunk_len -= spare;
	} else {
		memcpy(mgt->wr_addr + mgt->wr_len, buf, chunk_len);
		mgt->wr_len += chunk_len;
		chunk_len = 0;
	}

	if (mgt->wr_len == mgt->wr_lmax) {
		wr_raw_dbg("wr write, wr_addr:%p wr_offset:0x%llx, wr_len:%lx offset:%llx chunk_len:%llx\n",
				mgt->wr_addr, mgt->wr_offset, mgt->wr_len, offset, chunk_len);
		if (0 != common_raw_write(pname, mgt->wr_len, (uint64_t)0,
				mgt->wr_offset, mgt->wr_addr)) {
			errorf("wr write fail, wr_addr:%p wr_offset:0x%llx, wr_len:%lx\n",
				mgt->wr_addr, mgt->wr_offset, mgt->wr_len);
			return -3;
		}
		mgt->wr_offset += mgt->wr_len;
		mgt->wr_len = 0;
	}

	if (chunk_len) {
		if (chunk_len > mgt->wr_lmax) {
			errorf("wr write fail, chunk_len %llx > wr_lmax:%lx\n",
				chunk_len, mgt->wr_lmax);
			return -4;
		}
		memcpy(mgt->wr_addr, buf + spare, chunk_len);
		mgt->wr_len += chunk_len;
	}
#endif
	return 0;
}

int wr_sparse_fill(char *pname, s16 chunk_type, u64 size, u64 offset,
	u32 fill_val)
{
	wr_sparse_mgt_t *mgt = g_wr_sparse;
	int spare;
	wr_unp_ck_t *uc = NULL;
	int i, j;
	u32 *fillbuf = NULL;
	u32 filllen;

	if (!mgt)
		return -1;

#ifdef CONFIG_WRBG_SPARSE
	/* fill one alter buffer only */
	if (current_buffer->spare)
		spare = current_buffer->spare;
	else {
		wr_fill_dbg("current_buffer.spare %x,"
			"alter_buffer1.size %x alter_buffer1.used %x,"
			"alter_buffer2.size %x alter_buffer2.used %x\n",
			current_buffer->spare,
			alter_buffer1.size, alter_buffer1.used,
			alter_buffer2.size, alter_buffer2.used);
		if (wrbg_sparse_flush(pname) < 0) {
			return -2;
		}
		spare = 0;
	}
#else
	if (mgt->wr_offset + mgt->wr_len != offset) {
		errorf("wr_offset + wr_len (%llx + %lx) != fill offset %llx\n",
			mgt->wr_offset, mgt->wr_len, offset);
		return -2;
	}

	spare = mgt->wr_lmax - mgt->wr_len;
	if (spare < 0) {
		errorf("wr_lmax %lx < wr_len %lx\n", mgt->wr_lmax,
			mgt->wr_len);
		return -3;
	}
#endif

	fillbuf = (u32 *)mgt->wr_tmp;
	filllen = 0;
	if (spare >= size) {
		for (i = 0; i < size / sizeof(fill_val); i++) {
			fillbuf[i] = fill_val;
		}
		filllen = size;
		size = 0;
	} else if (spare) {
		for (i = 0; i < spare / sizeof(fill_val); i++) {
			fillbuf[i] = fill_val;
		}
		filllen = spare;
		size -= spare;
	}

	if (filllen) {
		//flush wr buffer
		if (wr_sparse_raw(pname, filllen, offset, fillbuf)) {
			errorf("fill write fill buf%p fail, offset %llx filllen %x\n",
				fillbuf, offset, filllen);
			return -4;
		}

		offset += filllen;
	}

	if (size) {
#ifdef CONFIG_WRBG_SPARSE
		if (alter_buffer1.used && alter_buffer2.used) {
			errorf("err alter_buffer1.used %x or alter_buffer2.used %x not zero\n",
				alter_buffer1.used, alter_buffer2.used);
			return -5;
		}
#else
		if (mgt->wr_len != 0) {
			errorf("err wr_len%x not zero\n", mgt->wr_len);
			return -5;
		}
#endif

		if (mgt->free_cnt <= 0) {
			errorf("unprocess node was exhausted, free_cnt%d\n", mgt->free_cnt);
			return -6;
		}

		uc = list_first_entry(unp_free_list.next, wr_unp_ck_t, node);
		__list_del(uc->node.prev, uc->node.next);
		mgt->free_cnt--;

		if ((chunk_type == (s16)CHUNK_TYPE_FILL) && (fill_val == 0)) {
			chunk_type = (s16)CHUNK_TYPE_DONT_CARE;
		}

		uc->type = chunk_type;
		uc->offset = offset;
		uc->chunk_len = size;
		uc->fill_val = fill_val;

		list_add_tail(&uc->node, &unp_chunk_list);

		//update wr_offset
		mgt->wr_offset += size;
	}
	return 0;
}

int wr_sparse_dontcare(char *pname, u64 size, u64 offset)
{
	wr_sparse_mgt_t *mgt = g_wr_sparse;

	if (!mgt)
		return -1;

#ifdef CONFIG_WRBG_SPARSE
	if (wrbg_sparse_flush(pname) < 0) {
		return -2;
	}
#else
	if (mgt->wr_len) {
		wr_raw_dbg("wr write, wr_addr:%p wr_offset:0x%llx, wr_len:%lx\n",
				mgt->wr_addr, mgt->wr_offset, mgt->wr_len);
		if (0 != common_raw_write(pname, mgt->wr_len, (uint64_t)0,
				mgt->wr_offset, mgt->wr_addr)) {
			errorf("wr flush before dont care fail"
				"wr_addr:%p wr_offset:0x%llx, wr_len:%lx\n",
				mgt->wr_addr, mgt->wr_offset, mgt->wr_len);
			return -2;
		}
		mgt->wr_offset += mgt->wr_len;
		mgt->wr_len = 0;
	}
#endif

	mgt->wr_offset = offset + size;
	wr_dontcare_dbg("%s dont care reset wr_offset %llx\n", pname, mgt->wr_offset);
	return 0;
}

int wr_sparse_flush(void)
{
	wr_sparse_mgt_t *mgt = g_wr_sparse;
	char *pname = mgt->pname;
	wr_unp_ck_t *pos, *n;
	int i;
	u32 *fillbuf = NULL;
	u32 fill_val, filllen;
	u64 offset;

	if (!mgt || !strlen(pname))
		return -1;

#ifdef CONFIG_WRBG_SPARSE
	if (wrbg_sparse_flush(pname) < 0) {
		return -2;
	}
#else
	if (mgt->wr_len) {
		wr_raw_dbg("%s flush wr buffer, wr_addr %llx wr_offset %llx wr_len %x\n",
					pname, mgt->wr_addr, mgt->wr_offset, mgt->wr_len);
		if (common_raw_write(pname, mgt->wr_len, (uint64_t)0,
				mgt->wr_offset, mgt->wr_addr)) {
			errorf("%s wr write fail, wr_addr:%p offset:0x%llx, wr_len:%lx\n",
				pname, mgt->wr_addr, mgt->wr_offset, mgt->wr_len);
			return -2;
		}
		mgt->wr_offset += mgt->wr_len;
		mgt->wr_len = 0;
	}
#endif

	list_for_each_entry_safe(pos, n, &unp_chunk_list, node) {
		switch (pos->type) {
		case CHUNK_TYPE_FILL:
			wr_fill_dbg("%s flush fill, chunk_len %llx offset %llx\n",
				pname, pos->chunk_len, pos->offset);
			fillbuf = (u32 *)mgt->wr_tmp;
			for (i = 0; i < (mgt->wr_lmax / sizeof(pos->fill_val)); i++)
				fillbuf[i] = pos->fill_val;

			filllen = pos->chunk_len;
			offset = pos->offset;
			while (filllen) {
				i = (filllen > mgt->wr_lmax) ? mgt->wr_lmax : filllen;
				if (0 != common_raw_write(pname, (uint64_t)i, (uint64_t)0,
					offset, fillbuf)) {
					errorf("%s flush write fill fail, i:%x, offset:%llx,"
						"fillbuf:%p\n", pname, i, offset, fillbuf);
					return -3;
				}
				offset += i;
				filllen -= i;
			}
			break;
		case CHUNK_TYPE_DONT_CARE:
			wr_dontcare_dbg("%s flush dont care, chunk_len %llx offset %llx\n",
				pname, pos->chunk_len, pos->offset);
			if (0 != common_raw_erase(pname, pos->chunk_len, pos->offset)) {
				errorf("%s flush erase fail, chunk_len %llx, offset %llx\n",
					pname, pos->chunk_len, pos->offset);
				return -4;
			}
			break;
		default:
			break;
		}

		__list_del(pos->node.prev, pos->node.next);
		list_add_tail(&pos->node, &unp_free_list);
		mgt->free_cnt++;
	}

	wr_dbg("%s flush free_cnt %d\n", pname, mgt->free_cnt);
	return 0;
}

void wr_sparse_rest(char *pname)
{
	wr_sparse_mgt_t *mgt = g_wr_sparse;
	int i;

	if (!mgt)
		return;

	INIT_LIST_HEAD(&unp_chunk_list);
	INIT_LIST_HEAD(&unp_free_list);

	memset(mgt, 0, sizeof(*mgt));
	mgt->wr_lmax = WR_LMAX_LIMIT;
	mgt->free_cnt = WR_UNP_CK_MAX;

	for (i = mgt->free_cnt - 1; i > 0; i--)
		list_add_tail(&mgt->cks[i].node, &unp_free_list);

	if (pname)
		strcpy(mgt->pname, pname);

#ifdef CONFIG_WRBG_SPARSE
	wrbg_sparse_rest_alt();
#endif
	wr_dbg("rest pname %s\n", mgt->pname);
}

int wr_sparse_prepare(u8 *base_address, u64 *max_size)
{
	wr_sparse_mgt_t *mgt;
	u64 sz = *max_size;
	const u32 lmin = SZ_128M;

	if (sz < lmin + sizeof(*mgt)) {
		return -1;
	}

	mgt = (wr_sparse_mgt_t *)(base_address + lmin);
	g_wr_sparse = mgt;
	wr_sparse_rest(NULL);

	wr_dbg("[%s,%d] mgt %p lmin %x\n", __func__, __LINE__, mgt, lmin);

	*max_size = lmin;
	return 0;
}

#endif

