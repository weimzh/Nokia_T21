
#include <common.h>
#include "dl_cmd_proc.h"

#ifdef CONFIG_NAND_BOOT
#include "dl_nand_operate.h"
#else
#include "dl_operate.h"
#endif

#include <boot_mode.h>
#include "asm/arch/check_reboot.h"
#include "otp_helper.h"
#include "asm/arch/common.h"
#include <malloc.h>
#include "root_inspect.h"
#ifdef CONFIG_PCTOOL_AUTHORIZE
#include <crypto/authentication.h>
#endif
#include <sprd_common_rw.h>
#include <u-boot/sha256.h>

#ifdef CONFIG_SPRD_LOG
static int dl_log2pc_not_ready = 1;	/* flags for log2pc could start */
#endif
#include <sprd_wdt.h>

#ifdef CONFIG_PCTOOL_CHECK_WRITE_PROTECT
static int enable_write_flash = 0;
#endif

static root_stat_t root_stat;

#ifdef CONFIG_NAND_BOOT
	 uint64_t	spl_read_size = 0;
#endif

extern uint8_t raw_random_data[32];
static unsigned char g_enable_raw_data_proc = 0;
static uint64_t g_bin_file_size = 0;
static unsigned char g_raw_data_support_check = 0;
static uint8_t dload_sys = 0;

//20220511, Added by zhu_jun for the power-on write protect request start
#ifdef CONFIG_EMMC_WP
#define ENABLE_WRITE_PROTECT	1
#define DISABLE_WRITE_PROTECT	0
extern int g_part_protected;
#endif
//20220511, Added by zhu_jun for the power-on write protect request end

#ifdef CONFIG_PCTOOL_AUTHORIZE
extern int dl_auth_sts;
#endif

static void _decode_packet_data(dl_packet_t *packet, uchar * partition_name, uint64_t * size, uint32_t * checksum)
{
	uint32_t  i = 0;
	uint16_t *data = (uint16_t *) (packet->body.content);
	/* legacy format */
	if (packet->body.size < BIT32_IDLEN_DATA_LENGTH) {
		partition_name[i] = '\0';
		*size = 0;
		return;
	}
	/* 64 proc */
	if (BIT64_IDLEN_DATA_LENGTH <= packet->body.size) {
		*size = *(uint64_t *) (data + MAX_PARTITION_NAME_SIZE);
		/* ID(72)+ LEN(8) +Rev(8) [+CS] */
		if ((NULL != checksum) && (BIT64_IDLEN_DATA_LENGTH < packet->body.size))
			*checksum = *(uint32_t *) (data + MAX_PARTITION_NAME_SIZE + 4 + 4);
	} else {/* 32 proc */
		*size = (uint64_t)*(uint32_t *) (data + MAX_PARTITION_NAME_SIZE);
		/* ID(72)+ LEN(4) [+CS]	*/
		if ((NULL != checksum) && (BIT32_IDLEN_DATA_LENGTH < packet->body.size))
			*checksum = *(uint32_t *) (data + MAX_PARTITION_NAME_SIZE + 2);
	}
	debugf("packet->body.size:0x%x, image size:0x%llx\n", packet->body.size, *size);

	while (('\0' != *(data+i)) && (i < (MAX_PARTITION_NAME_SIZE-1))){
		partition_name[i] = *(data+i) & 0xFF;
		i++;
	}
	partition_name[i] = '\0';

	return;
}

static __inline dl_cmd_type_t convert_operate_status(int err)
{
	switch (err)
	{
		case OPERATE_SUCCESS:
			return BSL_REP_ACK;
		case OPERATE_INVALID_ADDR:
			return BSL_REP_DOWN_DEST_ERROR;
		case OPERATE_INVALID_SIZE:
			return BSL_REP_DOWN_SIZE_ERROR;
		case OPERATE_DEVICE_INIT_ERROR:
			return BSL_UNKNOWN_DEVICE;
		case OPERATE_INVALID_DEVICE_SIZE:
			return BSL_INVALID_DEVICE_SIZE;
		case OPERATE_INCOMPATIBLE_PART:
			return BSL_INCOMPATIBLE_PARTITION;
		case OPERATE_WRITE_ERROR:
			return BSL_WRITE_ERROR;
		case OPERATE_CHECKSUM_DIFF:
			return BSL_CHECKSUM_DIFF;

		default:
		    return BSL_REP_OPERATION_FAILED;
	}
}


static __inline void _send_reply(uint32_t err)
{
	dl_send_ack (convert_operate_status(err));
	return;
}

#ifdef CONFIG_DTS_MEM_LAYOUT
int dl_set_buf_base_size(void)
{
	return set_buf_base_size();
}
#endif

int _parse_repartition_header(uchar * data, REPARTITION_TABLE_INFO * info, uchar ** list)
{
	uchar *  pointer = data;
	/*magic number must be "par:", otherwise it must be the old version packet(version 0)*/
	if (*(uint32_t*)data != REPARTITION_HEADER_MAGIC) {
		info->version = 0;
		/*default unit in version 0 is MB*/
		info->unit = 0;
		*list = data;
		return 0;
	}

	/*   header format:
	  *	|  magic(4Byte) | Version(1Byte) | Unit(1Byte) | table count(1Byte)|Reserved(1Byte) |
	  *	table tag(4) | table offset(2)| table size(2)|
	  */
	pointer += 4;
	info->version = *pointer;
	pointer += 1;
	info->unit = *pointer;
	pointer += 1;
	info->table_count = *pointer;
	pointer += 1;
	info->reserved = *pointer;
	pointer += 1;
	info->table_tag = *(unsigned int *)pointer;
	pointer += 4;
	info->table_offset = *(unsigned short *)pointer;
	pointer += 2;
	info->table_size = *(unsigned short *)pointer;
	pointer += 2;
	printf("%s: version(%d),unit(%d), table_count(%d), table_tag(%d), table_offset(%d), table_size(%d)\n",
		__FUNCTION__, info->version, info->unit, info->table_count, info->table_tag, info->table_offset,
		info->table_size);
	*list = pointer;
	return 0;
}

int dl_cmd_check_handshake_data(dl_packet_t *packet, void *arg)
{

        uint32_t ret = 0;
        unsigned char *data = packet->body.content;


        ret = memcmp(data, raw_random_data, 32);

        if(ret == 0)
                dl_send_ack(BSL_REP_ACK);
	else {
		printf("check packet data error\n");
                dl_send_ack(BSL_CHECK_DATA_ERROR);
                while(1);
        }


        return 0;
}

#ifdef CONFIG_PCTOOL_CHECK_WRITE_PROTECT
void dl_enable_write_flash(void)
{
	printf("enable write flash\n");
	enable_write_flash = 1;
	dl_send_ack(BSL_REP_ACK);
}
#endif

void prepare_buf_recv_raw_data(uint64_t fl_size);

int dl_cmd_write_start (dl_packet_t *packet, void *arg)
{
	uchar partition_name[MAX_PARTITION_NAME_SIZE] = {0};
	uint64_t size;
	uint32_t nv_checksum = 0;
	int32_t  op_res = 1;

	_decode_packet_data(packet, partition_name, &size, &nv_checksum);
	debugf("partition_name=%s,size=0x%llx,checksum=0x%x\n", partition_name, size, nv_checksum);

//20220511, Added by zhu_jun for the power-on write protect request start
#ifdef CONFIG_EMMC_WP
	if (!strcmp((char *)partition_name, "protect_data")) {
		if (ENABLE_WRITE_PROTECT == g_part_protected) {
			if (common_set_powp("protect_data")) {
				errorf("partition protect_data can't be protected,pls check it\n");
				return -1;
			}
			debugf("write start pwp success\n");
			g_part_protected += 2;
		}
	}
#endif
//20220511, Added by zhu_jun for the power-on write protect request end

	#ifdef CONFIG_PCTOOL_CHECK_WRITE_PROTECT
	if(0 == enable_write_flash) {
		debugf(" cannot write flash\n");
		dl_send_ack(BSL_REP_NOT_ENABLE_WRITE_FLASH);
		return 0;
	}
	#endif

	if ((root_stat.root_flag == 1) && !strcmp((char *)partition_name, "system")) {
		debugf("start clear root flag.\n");
		erase_rootflag(&root_stat);
	}
	op_res = dl_download_start(partition_name, size, nv_checksum);
	debugf("operate result =%d,send ack\n", op_res);

	if (g_enable_raw_data_proc) {
		prepare_buf_recv_raw_data(size);
	}
	_send_reply(op_res);
	return 0;
}

int dl_cmd_write_midst(dl_packet_t *packet, void *arg)
{
	int32_t           op_res = 1;

	op_res = dl_download_midst(packet->body.size, (char *)(packet->body.content));
	_send_reply(op_res);
	return 0;
}

int dl_cmd_write_end (dl_packet_t *packet, void *arg)
{
	int32_t           op_res = 1;
	op_res = dl_download_end();
	_send_reply(op_res);
	return 0;
}

int dl_cmd_read_start(dl_packet_t *packet, void *arg)
{
	uchar partition_name[MAX_PARTITION_NAME_SIZE] = {0};
	uint64_t size;
	int32_t           op_res = 0;

	_decode_packet_data(packet, partition_name, &size, NULL);

	debugf("partition_name=%s,size=0x%llx\n", partition_name, size);
#ifdef CONFIG_NAND_BOOT
	if(0 == strcmp(partition_name,"uboot") || 0 == strcmp(partition_name,"splloader"))
		spl_read_size = size;
#endif
	op_res = dl_read_start(partition_name, size);

	debugf("operate result =%d,send ack\n", op_res);
	_send_reply(op_res);
	return 0;
}

int dl_cmd_read_midst(dl_packet_t *packet, void *arg)
{
	uint32_t *data = (uint32_t *) (packet->body.content);
	uint32_t size = *data;
	uint64_t off = 0;
	int32_t           op_res = 0;

	if (BIT64_READ_MIDST_LENGTH == packet->body.size)
		off = *(uint64_t *) (data + 1);
	else
		off = (uint64_t)*(data + 1);

	if (size > MAX_PKT_SIZE) {
		debug("Size:0x%x beyond MAX_PKT_SIZE(0x%x)\n",size,MAX_PKT_SIZE);
		dl_send_ack (BSL_REP_DOWN_SIZE_ERROR);
		return 0;
	}

	op_res = dl_read_midst(size, off, (uchar *)(packet->body.content));
	if (OPERATE_SUCCESS == op_res) {
		packet->body.type = BSL_REP_READ_FLASH;
		packet->body.size = size;
		//debugf("operate result =%d,send pkt size=%d\n", op_res, size);
		dl_send_packet (packet);
	} else {
		debugf("operate result =%d,send ack\n", op_res);
		_send_reply(op_res);
	}
	return 0;
}

int dl_cmd_read_end(dl_packet_t *packet, void *arg)
{
	int32_t op_res =0;

	op_res = dl_read_end();
	_send_reply(op_res);
	return 0;
}

int dl_cmd_erase(dl_packet_t *packet, void *arg)
{
	uchar partition_name[MAX_PARTITION_NAME_SIZE] = {0};
	uint64_t size;
	int32_t op_res =0;

	_decode_packet_data(packet, partition_name, &size, NULL);

	debugf("partition_name=%s,size=0x%llx\n", partition_name, size);
	//20220511, Added by zhu_jun for the power-on write protect request start
	if (strcmp(partition_name, "erase_all") && ENABLE_WRITE_PROTECT == g_part_protected) {
		if (common_set_powp("protect_data")) {
			errorf("partition protect_data can't be protected,pls check it\n");
			return -1;
		}
		debugf("erase pwp success\n");
		g_part_protected += 3;
	}
	//20220511, Added by zhu_jun for the power-on write protect request end
	op_res = dl_erase(partition_name, size);

	debugf("operate result =%d,send ack\n", op_res);
	_send_reply(op_res);
	return 0;
}


int dl_cmd_repartition(dl_packet_t *pakcet, void *arg)
{
	uint16_t total_partition_num = 0;
	int32_t op_res =1;
	uint16_t size = pakcet->body.size;
	uchar * raw_data = pakcet->body.content;
	REPARTITION_TABLE_INFO rp_info;
	uchar * p_part_list = NULL;
	uint32_t part_cell_length = 0;

	#ifdef CONFIG_PCTOOL_CHECK_WRITE_PROTECT
	if(0 == enable_write_flash) {
		debugf(" cannot repartition flash\n");
		dl_send_ack(BSL_REP_NOT_ENABLE_WRITE_FLASH);
		return 0;
	}
	#endif

	_parse_repartition_header(raw_data, &rp_info, &p_part_list);

	if (0 == rp_info.version) {
		part_cell_length = REPARTITION_UNIT_LENGTH;
	} else {
		part_cell_length = REPARTITION_UNIT_LENGTH_V1;
		size = rp_info.table_size;
	}

	if (0 != (size % part_cell_length)) {
		printf("%s:recvd packet size(%d) error \n", __FUNCTION__,size);
		dl_send_ack(BSL_INCOMPATIBLE_PARTITION);
		return 0;
	}
	total_partition_num = size / part_cell_length;
	debugf("Partition total num:%d \n", total_partition_num);
	op_res = dl_repartition(p_part_list, total_partition_num, rp_info.version, rp_info.unit);
	_send_reply(op_res);

//20220511, Added by zhu_jun for the power-on write protect request start
#ifdef CONFIG_EMMC_WP
	if (ENABLE_WRITE_PROTECT == g_part_protected) {
		if (common_set_powp("protect_data")) {
			errorf("partition protect_data can't be protected,pls check it\n");
			return -1;
		}
		debugf("repartition pwp success\n");
		g_part_protected += 1;
	}
#endif
//20220511, Added by zhu_jun for the power-on write protect request end

	/* in download mode, write log must be after repartiton action */
	reinit_write_log();

	return 0;
}

//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 begin
void dl_set_chargeflag(void)
{
	unsigned short flag = 2;
	char *flag2 = "0";
	if (0 != common_raw_write("miscdata",OFF_MODE_CHARGE_FLAG_LEN, (uint64_t)0, (uint64_t)OFF_MODE_CHARGE_FLAG_OFFSET, (char *)&flag)) {
		errorf("write default off-mode-charge-flag fail\n");
		return -1;
	} else {
		debugf("write default off-mode-charge-flag success\n");
	}
	if (0 != common_raw_write("miscdata",HMD_OFF_MODE_CHARGE_FLAG_LEN, (uint64_t)0, (uint64_t)HMD_OFF_MODE_CHARGE_FLAG_OFFSET, flag2)) {
		errorf("write default app off-mode-charge-flag fail\n");
		return -1;
	} else {
		debugf("write default app off-mode-charge-flag success\n");
	}
	return 0;
}
//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 end

//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
extern int download_mode_flag;
//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end

void clear_download_signature()
{
//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
#ifndef WT_COMPILE_FACTORY_VERSION
	unsigned int lcs = 0;
	sprd_get_lcs(&lcs);
	if(download_mode_flag && (5 == lcs)) {
		printf(" download finish, erase download auth data\n");
		if (common_raw_erase("miscdata", HMD_DOWNLOAD_MODE_SIGNATURE_LEN, HMD_DOWNLOAD_MODE_SIGNATURE_OFFSET)) {
			errorf("erase the download auth data fail\n");
		}
	}
	//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end
#else
	printf(" download finish, erase download auth data\n");
	if (common_raw_erase("miscdata", HMD_DOWNLOAD_MODE_SIGNATURE_LEN, HMD_DOWNLOAD_MODE_SIGNATURE_OFFSET)) {
		errorf("erase the download auth data fail\n");
	}
#endif

}

int dl_cmd_reboot (dl_packet_t *pakcet, void *arg)
{
	int32_t op_res = OPERATE_SUCCESS;
	//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 begin
	dl_set_chargeflag();
	//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 end
	char buf[WDTEN_DATA_LEN] = {0};
	debugf("before reboot ,send ack(%d)\n", op_res);
	_send_reply(op_res);
#ifdef DEBUG
	strcpy(buf, "disable");
#else
	strcpy(buf, "enabled");
#endif
	if (0 != common_raw_write("miscdata", WDTEN_DATA_LEN, 0, WDTEN_DATA_OFFSET, buf)) {
		errorf("write default WDT enable flag fail\n");
		return OPERATE_WRITE_ERROR;
	} else {
		debugf("write default WDT enable flag success\n");
	}
	if (0 != common_raw_write("miscdata", DSWDTEN_DATA_LEN, 0, DSWDTEN_DATA_OFFSET, "disable")) {
		errorf("write default DSWDT enable flag fail\n");
		return OPERATE_WRITE_ERROR;
	} else {
		debugf("write default DSWDT enable flag success\n");
	}
	clear_download_signature();
	reset_to_normal(CMD_NORMAL_MODE);
	return 0;
}

int dl_powerdown_device(dl_packet_t *packet, void *arg)
{

	int32_t op_res = OPERATE_SUCCESS;
	char buf[WDTEN_DATA_LEN] = {0};
	//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 begin
	dl_set_chargeflag();
	//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 end

	_send_reply(op_res);

#ifdef DEBUG
	strcpy(buf, "disable");
#else
	strcpy(buf, "enabled");
#endif
	if (0 != common_raw_write("miscdata", WDTEN_DATA_LEN, 0, WDTEN_DATA_OFFSET, buf)) {
		errorf("write default WDT enable flag fail\n");
        return OPERATE_WRITE_ERROR;
    } else {
        debugf("write default WDT enable flag success\n");
    }
	if (0 != common_raw_write("miscdata", DSWDTEN_DATA_LEN, 0, DSWDTEN_DATA_OFFSET, "disable")) {
		errorf("write default DSWDT enable flag fail\n");
		return OPERATE_WRITE_ERROR;
	} else {
		debugf("write default DSWDT enable flag success\n");
	}

	/* Wait until all characters are sent out. */
	udelay(200);

	/* Wait until the charger unconnected. */
	while(charger_connected());
	debugf("download end power down device\n");
	clear_download_signature();
	power_down_devices(0);
	while(1);
	return 0;
}

int dl_cmd_read_mcptype(dl_packet_t *packet, void *arg)
{
#ifdef CONFIG_NAND_BOOT
	unsigned int pagesize;
	unsigned int blocksize;
	unsigned int size ;
	char temp[sizeof(struct MCP_TYPE)];
	struct mtd_info *nand ;
	struct MCP_TYPE mcp_type;
	int i =0,j=0;
	nand = _get_cur_nand();
	pagesize  = nand->writesize;
	blocksize = nand->erasesize;
	mcp_type.flag = 0;
	mcp_type.pagesize  = pagesize;
	mcp_type.blocksize = blocksize;
	size = sizeof(struct MCP_TYPE);
	packet->body.type = BSL_REP_READ_MCP_TYPE;
	packet->body.size = 12;
	memcpy(packet->body.content, &mcp_type, size);
	for(i=0 ; i<size ;i++)
		temp[i] = packet->body.content[i];
	for(i=0; i <size; i++){
		if((i%4) == 0)
			j=i+4;
		packet->body.content[i]=temp[--j];
	}
	  dl_send_packet (packet);
#else

#endif
	return 1;


}

int dl_cmd_check_rootflag(dl_packet_t *packet, void *arg)
{
	u32 result;
	int32_t op_res = OPERATE_SUCCESS;

	result = get_rootflag(&root_stat);
	if(result == 0) {
		debugf("this phone have not been rooted from now.\n");
		_send_reply(op_res);
	} else {
		debugf("phone was brushed,rootflag:%d\n", result);
		dl_send_ack(BSL_PHONE_ROOTFLAG);
	}

	return 1;
}
#ifdef CONFIG_SPRD_UID
int dl_cmd_get_chip_uid(dl_packet_t *packet, void *arg)
{
	uint32_t *uid = (unsigned int *) (packet->body.content);
	int ret=0,tmp=0;
	char p[64];

	memset(p, 0, sizeof(p));
#if defined(CONFIG_GET_CPU_SERIAL_NUMBER_NO_WD)
	char serial_num[16];

	memset(serial_num, 0, sizeof(serial_num));
	ret = sprd_get_chip_hex_uid(serial_num);

	memcpy(p, serial_num, strlen(serial_num));
#elif defined(CONFIG_GET_CPU_SERIAL_NUMBER)
	u32 cnt = 0;
	char serial_num[16];
	char raw_serial_num[32];
	char mask_serial_num[65];

	memset(serial_num, 0, sizeof(serial_num));
	ret = sprd_get_chip_hex_uid(serial_num);

	memset(raw_serial_num, 0, sizeof(raw_serial_num));
	sha256_csum_wd_sw((unsigned char *)serial_num, strlen(serial_num),
		(unsigned char *)raw_serial_num, 0);

	memset(mask_serial_num, 0, sizeof(mask_serial_num));
	for (cnt = 0; cnt < sizeof(raw_serial_num); cnt++) {
		sprintf(mask_serial_num + cnt * 2, "%02x", raw_serial_num[cnt]);
	}

	memcpy(p, mask_serial_num, strlen(mask_serial_num));
#else
	ret = sprd_get_chip_uid(p);
#endif

	if(ret ==0){
		tmp = strlen(p);
		tmp = (tmp+1)/2*2;
		if (8 == tmp) tmp+=2;
		memset(uid,0,64);
		memcpy(uid, p, strlen(p));
		packet->body.size = tmp;
		packet->body.type = BSL_REP_READ_CHIP_UID;
		dl_send_packet (packet);

	}else{
		packet->body.type = BSL_REP_READ_CHIP_UID;
		packet->body.size = 64;
		memset(uid,0,64);
		dl_send_packet (packet);
	}

	return 0;
}
#else
#ifdef CONFIG_X86
int dl_cmd_get_uid_x86(dl_packet_t *packet, void *arg)
{
	uint32_t block0, block1, block5, block;
	uint32_t block0_int, block0_bit, block1_int, block1_bit;
	uint32_t *uid = (unsigned int *) (packet->body.content);
	char *p = (char *)malloc(20);
	if (p == NULL) {
		errorf("uid read malloc error\n");
	} else {
		block0 = sprd_ap_efuse_read(0);
		block1 = sprd_ap_efuse_read(1);
		block5 = sprd_ap_efuse_read(5);
		block0_int = (block0 >> 2) & 0xffffff;
		block0_bit = ((block0 & 0x3)<<2);
		block1_int = block1 & 0xfffffff;
		block1_bit = (block1 & 0x30000000) >> 28;
		block = block0_bit | block1_bit;
		block5 &= 0xfff;

		debugf("uid is %x%x%x%x\n", block5, block0_int, block, block1_int);
		sprintf(p, "%03x%06x%01x%07x", block5, block0_int, block, block1_int);

		memset(uid,0,18);
		memcpy(uid, p, strlen(p));
	}
	packet->body.type = BSL_REP_READ_CHIP_UID;
	packet->body.size = 18;
	dl_send_packet (packet);
	if(p != NULL)
		free(p);
	return 0;
}

#else
int dl_cmd_get_uid(dl_packet_t *packet, void *arg)
{
	uint32_t efuse_blk0 = 0;
	uint32_t efuse_blk1 = 0;
	uint32_t * uid = (unsigned int *) (packet->body.content);

	efuse_blk0 = sprd_ap_efuse_read(0);
	efuse_blk0 &= ~(BIT_31);
	efuse_blk1 = sprd_ap_efuse_read(1);
	efuse_blk1 &= ~(BIT_31);
	debugf("Read efuse_blk0 = 0x%x, efuse_blk1 = 0x%x\n", efuse_blk0, efuse_blk1);

	packet->body.type = BSL_REP_READ_CHIP_UID;
	packet->body.size = 0x8;
	*uid = efuse_blk0;
	uid ++;
	*uid = efuse_blk1;
	dl_send_packet (packet);
	return 0;
}
#endif
#endif

int dl_cmd_read_ref_info(dl_packet_t *packet, void *arg)
{
	debugf("begin\n");
	char *buf = NULL;
	unsigned short size = packet->body.size;
	packet->body.type = BSL_REP_READ_REFINFO;
	buf = malloc((size_t)size);
	if (buf == NULL) {
		errorf("malloc error, size = 0x%x \n", size);
	} else {
		memcpy(buf, packet->body.content, (size_t)size);
		debugf("memcpy\n");
		dl_read_ref_info("miscdata", size, (uint64_t)REF_INFO_OFF, buf,
			(char *)packet->body.content);
	}
	dl_send_packet (packet);
	if(buf != NULL)
		free(buf);
	return 0;
}

int dl_cmd_end_process(dl_packet_t *packet, void *arg)
{
	debugf("enter the end process\n");
	dl_send_ack(BSL_REP_ACK);
	return 0;
}

int dl_cmd_disable_hdlc(dl_packet_t *packet, void *arg)
{
	dl_send_ack(BSL_REP_ACK);
	FDL_DisableHDLC(1);
	return 0;
}

int dl_cmd_write_datetime(dl_packet_t *packet, void *arg)
{
	int32_t op_res = OPERATE_SUCCESS;
	uint64_t size =(uint64_t)packet->body.size;
	uchar * raw_data =(uchar *) packet->body.content;

	op_res = dl_record_pacdatetime(raw_data,size);
	_send_reply(op_res);
	return 0;
}

int dl_cmd_set_debuginfo(dl_packet_t *packet, void *arg)
{
	int32_t op_res = OPERATE_SUCCESS;
	uint64_t debuginfo_size, offset;
	char debuginfo_buf[DEBUG_INFO_LEN] = "enable";

	uint64_t size = (uint64_t)packet->body.size;
	uchar * raw_data = (uchar *)packet->body.content;

	if(size == 0){
		uint64_t debuginfo_size = (uint64_t)strlen(debuginfo_buf) + 1;
                if(0 != common_raw_write("miscdata", debuginfo_size, (uint64_t)0, (uint64_t)DEBUG_INFO_OFFSET, debuginfo_buf)){
                        op_res = OPERATE_WRITE_ERROR;
                }
	}else if(size > 0 && size < DEBUG_INFO_LEN){
			memcpy(debuginfo_buf, raw_data, size);
			debuginfo_buf[size] = '\0';
			debuginfo_size = size + 1;

			/* fixbug SPCSS00552570, packet BSL_CMD_ENABLE_DEBUG_MODE use for loglevel handle only */
			debugf("get debuginfo {%s}\n", debuginfo_buf);
			offset = DEBUG_INFO_OFFSET;
			if(0 != common_raw_write("miscdata", debuginfo_size, (uint64_t)0, offset, debuginfo_buf)){
				op_res = OPERATE_WRITE_ERROR;
			}
		}else{
			errorf("debug info size cannot over %d Bytes!\n", (DEBUG_INFO_LEN-1));
			op_res = OPERATE_INVALID_SIZE;
		}
	_send_reply(op_res);
	return 0;
}

#ifdef CONFIG_PCTOOL_CHECK_MULTI_FIXNV
int dl_cmd_check_NV_type(dl_packet_t *packet, void *arg)
{
	uint32_t size ;
	uint8_t type;
	char temp[4];
	int i = 0,j = 4;
	memset(temp,0,4);
	type = DRV_RF_Get_Type();
	debugf("id = %d\n",type);
	size = (uint32_t)type;
	memcpy(temp,&size,4);

	if(0xff == type){
		dl_send_ack(BSL_REP_OPERATION_FAILED);
	}else{
		memcpy(packet->body.content,temp,sizeof(temp));
		packet->body.type= BSL_CHECK_NV_TYPE;
		packet->body.size = 4;
		dl_send_packet (packet);
	}

	return 1;
}
#endif

#ifdef CONFIG_EMMC_DDR_CHECK_TYPE
/* just for special customer */
int dl_cmd_read_flashtype(dl_packet_t *packet, void *arg)
{
        uint16_t size ;

        dl_get_flashtype(packet->body.content, &size);
        packet->body.type= BSL_REP_READ_FLASH_TYPE;
        packet->body.size = size;
        dl_send_packet (packet);

        return 1;
}
#endif

int dl_set_first_mode(dl_packet_t *packet, void *arg)
{
	u32 set_first_mode = 0;
	u32 op_res = OPERATE_SUCCESS;

	set_first_mode = *(packet->body.content);
	debugf("set_first_mode: 0x%x\n", set_first_mode);

	set_first_mode += SET_FIRST_MODE_MAGIC;

	if(0 != common_raw_write("miscdata", (uint64_t)(sizeof(set_first_mode)), (uint64_t)0,
				(uint64_t)SET_FIRST_MODE_OFFSET, (char *)&set_first_mode)){
		op_res = OPERATE_WRITE_ERROR;
	}

	_send_reply(op_res);

	return 0;
}

/* raw data proc */
ALTER_BUFFER_ATTR *raw_cur_buf = NULL;
ALTER_BUFFER_ATTR raw_buf1;
ALTER_BUFFER_ATTR raw_buf2;

uint32_t read_raw_packet_start(unsigned char *buf, unsigned int len)
{
	FDL_StartRxRawPacket(buf, len);
	return 0;
}

uint32_t read_raw_packet_finish(unsigned int len)
{
	return (uint32_t)FDL_FinishRxRawPacket(NULL, len);
}

OPERATE_STATUS prepare_raw_data_buf(unsigned char *pdata)
{
	if (NULL == pdata) {
		printf("%s raw data buf pointer is NULL\r\n", __func__);
		return OPERATE_INVALID_ADDR;
	}

	raw_buf1.addr = pdata;
	raw_buf1.size = HALF_PKT_SIZE;
	raw_buf1.used = 0;
	raw_buf1.status = BUFFER_CLEAN;
	raw_buf1.next = &raw_buf2;

	raw_buf2.addr = pdata + HALF_PKT_SIZE;
	raw_buf2.size = HALF_PKT_SIZE;
	raw_buf2.used = 0;
	raw_buf2.status = BUFFER_CLEAN;
	raw_buf2.next = &raw_buf1;

	raw_cur_buf = &raw_buf1;

	return OPERATE_SUCCESS;
}

void prepare_buf_recv_raw_data(uint64_t fl_size)
{

	unsigned char *pdata = NULL;

	extern __attribute__((aligned (64)))  unsigned char usb_out_endpoint_buf[];
	pdata = (unsigned char *) &usb_out_endpoint_buf;
	prepare_raw_data_buf(pdata);

	g_bin_file_size = fl_size;
}

uint32_t get_remain_packet_size(uint64_t *size)
{
	uint64_t packet_len;

	if (*size > HALF_PKT_SIZE) {
		packet_len = (uint64_t)HALF_PKT_SIZE;
	} else {
		packet_len = *size;
	}

	*size -= packet_len;

	return (uint32_t)packet_len;
}

OPERATE_STATUS dload_whole_raw_file(uint64_t part_size)
{
	OPERATE_STATUS op_res = 1;
	uint64_t recv_total_size = 0x0;
	uint32_t packet_len = 0x0;
	uint64_t remain_size = part_size;
	uint32_t recv_length = 0x0;

	if (!part_size) {
		errorf("error bin file size:%llx\r\n", part_size);
		return OPERATE_INVALID_SIZE;
	}

RAW_DATA_RECV_CMD:
	if (packet_len != 0x0) {
		recv_length = read_raw_packet_finish(packet_len);
		if ((uint32_t)recv_length != packet_len) {
			errorf("Packet length received err!!!,recv_length:%x, packet_len:%x\n",
			recv_length, packet_len);
			return OPERATE_INVALID_SIZE;
		}
		raw_cur_buf->used = packet_len;
		recv_total_size += (uint64_t)recv_length;
	}

	if (remain_size)
		_send_reply(OPERATE_SUCCESS);

	if (remain_size == part_size) {
		packet_len = get_remain_packet_size(&remain_size);
		read_raw_packet_start(raw_cur_buf->addr, packet_len);
		goto RAW_DATA_RECV_CMD;
	} else if (remain_size != 0x0) {
		packet_len = get_remain_packet_size(&remain_size);
		read_raw_packet_start(raw_cur_buf->next->addr, packet_len);
	}

	op_res = dl_download_midst(raw_cur_buf->used, (char *)raw_cur_buf->addr);
	if (op_res != OPERATE_SUCCESS) {
		errorf("Download write err!!!, stop!!!\n");
		return op_res;
	}

	raw_cur_buf->used = 0x0;
	raw_cur_buf = raw_cur_buf->next;

	if (recv_total_size != part_size)
		goto RAW_DATA_RECV_CMD;
	else
		return OPERATE_SUCCESS;
}

OPERATE_STATUS dload_one_raw_packet(uint32_t packet_len)
{
	uint32_t recv_length;
	OPERATE_STATUS  op_res = 1;

	read_raw_packet_start(raw_cur_buf->addr, packet_len);
	recv_length = read_raw_packet_finish(packet_len);
	if (recv_length != packet_len) {
		errorf("Packet length received err!!!,recv_length:%x, packet_len:%x\n",
		recv_length, packet_len);
		return OPERATE_INVALID_SIZE;
	}
	raw_cur_buf->used = packet_len;

	if (!g_raw_data_support_check) {
		op_res = OPERATE_SUCCESS;
		_send_reply(op_res);
		op_res = dl_download_midst((uint32_t)raw_cur_buf->used, (char *)raw_cur_buf->addr);
		if (op_res != OPERATE_SUCCESS) {
			errorf("Download write err!!!, stop!!!\n");
			return op_res;
		}
		raw_cur_buf->used = 0x0;
	}
	return OPERATE_SUCCESS;
}

#if !defined(CONFIG_NAND_BOOT) && !defined(CONFIG_DDR_BOOT)
int dl_cmd_check_partition(dl_packet_t *packet, void *arg)
{
	int i;
	int j;
	int ret;
	int total;

	OPERATE_STATUS op_res;

	disk_partition_t info[GPT_ENTRY_NUMBERS];
	tool_partition_t tool_info[GPT_ENTRY_NUMBERS];

	memset(info, 0x0, sizeof(disk_partition_t) * GPT_ENTRY_NUMBERS);
	memset(tool_info, 0x0, sizeof(tool_partition_t) * GPT_ENTRY_NUMBERS);

	ret = get_partition_information(info, &total);
	if (ret) {
		errorf("get partition information error!\n");
		dl_send_ack(BSL_REP_OPERATION_FAILED);
		return 0;
	}

	for (i = 0; i < total; i++) {
		for (j = 0; j < strlen(info[i].name); j++) {
			tool_info[i].name[2 * j] = info[i].name[j];
		}

		tool_info[i].size = info[i].size >> 1;
	}

	packet->body.type = BSL_REP_READ_PARTITION;
	packet->body.size = sizeof(tool_partition_t) * total;
	memcpy(packet->body.content, &tool_info[0], packet->body.size);

	dl_send_packet (packet);

	return 0;
}
#endif

/*
 *  Download optimization of the second stage: start once per
 * file(raw data). used ping pong buffer and concurrent transmission
 * to cache, return after finishing downloading one whole bin file.
 */
int dl_cmd_whole_raw_file_start(dl_packet_t *packet, void *arg)
{
	OPERATE_STATUS op_res = 1;

	op_res = dload_whole_raw_file(g_bin_file_size);
	_send_reply(op_res);

	return 0;
}

/*
 *  Download optimization of the first stage: One start commond for
 * each 2MB packet raw data,return after finishing downloading one
 * packet raw data.
 */
int dl_cmd_per_raw_packet_start(dl_packet_t *packet, void *arg)
{
	OPERATE_STATUS op_res = 1;
	uint32_t packet_len;

	_send_reply(OPERATE_SUCCESS);
	packet_len = get_remain_packet_size(&g_bin_file_size);

	op_res = dload_one_raw_packet(packet_len);
	if (op_res != OPERATE_SUCCESS) {
		_send_reply(op_res);
		errorf("rawdata write err\n");
	}
	return 0;
}

/*  Only match the optimization of the first stage, Take effect
 * just when get pc tool information of sha256 check before
 * start to download raw data
 */
int dl_cmd_write_flush_raw_data(dl_packet_t *packet, void *arg)
{
	OPERATE_STATUS op_res = 1;

	if (!g_raw_data_support_check) {
		errorf("don't support flush data check\n");
		dl_send_ack(BSL_REP_OPERATION_FAILED);
		return 0;
	}

	/* check sha256 value */
	op_res = dl_download_flush_data(raw_cur_buf->used, raw_cur_buf->addr,
			packet->body.size, (unsigned char *)packet->body.content);
	if (op_res != OPERATE_SUCCESS) {
		printf("Sha256 check err!!!\r\n");
		_send_reply(op_res);
	} else {
		op_res = dl_download_midst(raw_cur_buf->used, (char *)raw_cur_buf->addr);
		if (op_res != OPERATE_SUCCESS) {
			printf("Download write err!!!, stop!!!\r\n");
		}
		_send_reply(op_res);
		raw_cur_buf->used = 0x0;
		raw_cur_buf->status = BUFFER_CLEAN;
	}
	return 0;
}

void usb_set_dload_sys_linux(uint8_t dload_sys_flag)
{
	dload_sys = dload_sys_flag;
}

uint8_t usb_get_dload_sys_linux(void)
{
	return dload_sys;
}

int dl_cmd_write_raw_data_enable(dl_packet_t *packet, void *arg)
{
	int32_t	op_res = 1;
	g_enable_raw_data_proc = 1;
	_send_reply(op_res);
	if (packet->body.size == MUSB_DLOAD_FOR_LINUX_FLAG)
		usb_set_dload_sys_linux(MUSB_DLOAD_FOR_LINUX);

	return 0;
}

int dl_cmd_disable_selinux(dl_packet_t *packet, void *arg)
{
	int op_res = OPERATE_SUCCESS;
	int ret;
	u64 size = (u64)packet->body.size;
	char* temp_buf = (char *)packet->body.content;
	char selinux_buf[SELINUX_INFO_LEN] = {0};

	if (size > SELINUX_INFO_LEN) {
		errorf("The size exceeds the buff size!\n");
		dl_send_ack(BSL_REP_OPERATION_FAILED);
		return 0;
	}

	memcpy(selinux_buf, temp_buf, size);

	debugf("%s!\n", selinux_buf);

	ret = common_raw_write("miscdata", (u64)SELINUX_INFO_LEN,
			(u64)0, (u64)SELINUX_SWITCH_OFFSET, selinux_buf);
	if (ret) {
		op_res = OPERATE_WRITE_ERROR;
		errorf("Write miscdata selinux fail!\n");
	}

	_send_reply(op_res);

	return 0;
}

int dl_cmd_get_timestamp(u64 *timestamp)
{
	u32 *magic;
	u8 buf[12];

	if (common_raw_read("miscdata", (u64)sizeof(buf), (u64)SET_TIMESTAMP_OFFSET,
			(char *)buf)) {
		errorf("read miscdata timestamp error.\n");
		return -1;
	}

	magic = (u32 *)buf;
	if (*magic != SET_TIMESTAMP_MAGIC) {
		errorf("read timestamp magic(%x) incorrect.\n", *magic);
		return -2;
	}

	*timestamp = *(u64 *)(buf + sizeof(u32));
	return 0;
}

int dl_cmd_set_timestamp(dl_packet_t *packet, void *arg)
{
	u64 *timestamp = (u64 *)packet->body.content;
	OPERATE_STATUS op_res = OPERATE_SUCCESS;
	char buf[12];
	u32 *magic;

	debugf("timestamp: 0x%llx\n", *timestamp);

	magic = (u32 *)buf;
	*magic = SET_TIMESTAMP_MAGIC;
	memcpy(buf + sizeof(*magic), timestamp, sizeof(*timestamp));
	if (common_raw_write("miscdata", (u64)sizeof(buf), (u64)0,
				(u64)SET_TIMESTAMP_OFFSET, buf)) {
		op_res = OPERATE_WRITE_ERROR;
	}

	_send_reply(op_res);
	return 0;
}

#ifdef CONFIG_SPRD_LOG
int dl_cmd_set_log2pc_start(dl_packet_t *packet, void *arg)
{
	dl_log2pc_not_ready = 0;
	_send_reply(1);
	return 0;
}

/* reserved 0x1000bytes for HDLC format escape */
#define DL_RESP_MAX_PKT_SIZE	(MAX_PKT_SIZE - 0x1000 - 2)
static int dl_cmd_resp_log(char *log, int len)
{
	dl_packet_t *packet;
	int *log_type;
	int i;

#ifdef FPGA_TRACE_DOWNLOAD
	return -1;
#endif
	if (dl_log2pc_not_ready)
		return -1;

	packet = FDL_MallocPacket();
	if (!packet)
		return -1;

	log_type = (int *)packet->body.content;
	while (len > 0) {
		/* update rep log type as serial log */
		*log_type = 0;

		i = len > DL_RESP_MAX_PKT_SIZE ? DL_RESP_MAX_PKT_SIZE : len;
		memcpy(packet->body.content + 4, log , i);
		/* adjuct length to even and fill pad if necessary */
		if (i % 2) {
			packet->body.content[i + 4] = '\0';
			i++;
		}
		packet->body.type = BSL_REP_LOG;
		packet->body.size = i + 4;
		dl_send_packet(packet);

		len -= i;
		log += i;
	}

	dl_free_packet(packet);
	return 0;
}

__used int log2pc(char *log, int len)
{
	return dl_cmd_resp_log(log, len);
}

int dl_cmd_dump_log(dl_packet_t *packet, void *arg)
{
	static int sendout = 0;
	char *log = (char *)p_log_buffer->addr + sendout;
	int len = (int)p_log_buffer->used - sendout;
	dl_packet_t *packet_rsp;
	int *nstatus;
	int i;

#ifdef FPGA_TRACE_DOWNLOAD
	return -1;
#endif

#ifdef CONFIG_DTS_MEM_LAYOUT
	if (log_buffer_enabled_flag != 1)
		return -2;
#endif

	if (!log || !len)
		return -3;

	packet_rsp = FDL_MallocPacket();
	if (!packet_rsp)
		return -4;

	nstatus = (int *)packet_rsp->body.content;
	do {
		i = len > DL_RESP_MAX_PKT_SIZE ? DL_RESP_MAX_PKT_SIZE : len;
		memcpy(packet_rsp->body.content + 4, log , i);
		/* adjuct length to even and fill pad if necessary */
		if (i % 2) {
			packet_rsp->body.content[i + 4] = '\0';
			i++;
		}
		packet_rsp->body.type = BSL_REP_DUMP_UBOOT_LOG;
		packet_rsp->body.size = i + 4;
		len -= i;
		log += i;
		sendout += i;

		if (len <= 0) {
			*nstatus = 0;	/* finish */
			sendout = 0;
		} else
			*nstatus = 1;

		dl_send_packet(packet_rsp);
	} while (0);

	dl_free_packet(packet_rsp);
	return 0;
}

#endif

int dl_cmd_read_vcur(dl_packet_t *packet, void *arg)
{
	dl_packet_t *v_packet;
	char version_temp[PAC_VERSION_SIZE] = {0};
	int i = 0;
	uint16_t temp[PAC_VERSION_SIZE * 2] = {0};
	uint32_t string_size = 0;

	v_packet = FDL_MallocPacket();
	if (NULL == v_packet) {
		errorf("malloc version packet fail\n");
		return -1;
	}
	debugf("start read vcur...\n");
	if (0 != common_raw_read("miscdata", (uint64_t) PAC_VERSION_SIZE, (uint64_t) PAC_VERSION_OFFSET, version_temp)) {
		debugf("read miscdata vcur error.\n");
		dl_free_packet(v_packet);
		return -1;
	}
	version_temp[PAC_VERSION_SIZE - 1] = '\0';
	debugf("vcur version string : %s\n", version_temp);
	for (i = 0; i < strlen(version_temp); i++)
		temp[i] = (uint16_t)version_temp[i];
	temp[i] = '\0';

	string_size = (strlen(version_temp) + 1) * sizeof(uint16_t);
	memcpy(v_packet->body.content, temp, string_size);

	v_packet->body.type = BSL_REP_READ_VCUR_DATA;
	v_packet->body.size = (unsigned short)string_size;
	dl_send_packet(v_packet);
	dl_free_packet(v_packet);

	return 0;
}

int dl_cmd_write_vcur(dl_packet_t *packet, void *arg)
{
	uint32_t op_res = OPERATE_SUCCESS;
	uint16_t *data = (uint16_t *) (packet->body.content);
	uint32_t  i = 0;
	uchar vcur[PAC_VERSION_SIZE];

	debugf("start write vcur...\n");
	if (PAC_VERSION_SIZE < packet->body.size) {
		errorf("version packet size was larger than %d\n", PAC_VERSION_SIZE);
		return -1;
	}
	while (('\0' != *(data+i)) && (i < (packet->body.size/sizeof(uint16_t) - 1))) {
		vcur[i] = *(data+i) & 0xFF;
		i++;
	}
	vcur[i] = '\0';
	debugf("vcur version string : %s\n", vcur);

	if (0 != common_raw_write("miscdata", (uint64_t) (strlen(vcur) + 1), (uint64_t) 0, (uint64_t) PAC_VERSION_OFFSET, vcur)){
		op_res = OPERATE_WRITE_ERROR;
		debugf("write miscdata vpac error.\n");
	}

	_send_reply(op_res);

	return 0;
}

#ifdef CONFIG_PCTOOL_AUTHORIZE
/**
 * - double check if we need to authorize pctool
 * Return: 0, no; other yes
 */
int dl_need_to_authorize(void)
{
	return 1;	/* need authorize */
}

/**
 * - update project information for m1
 * Notice:
 *   the length is limited to 32bytes
 */
static void update_project_info(uint8_t *buf)
{
	uint8_t project[32];

	/* update project info */
	memset(project, 0, sizeof(project));
	strcpy(project, "S6301");
	memcpy(buf, project, sizeof(project));
}

int dl_cmd_auth_request(dl_packet_t *packet, void *arg)
{
	dl_packet_t *pk_rsp;
	FDL_OT_Auth_ack_t ack;
	int len = 0;

	if ((len = authentication(ack.M1, 1)) <= 0) {
		errorf("auth fail return %d\n", len);
		goto fail;
	}

	/* alloc response packet */
	pk_rsp = FDL_MallocPacket();
	if (!pk_rsp) {
		errorf("malloc packet fail\n");
		goto fail;
	}

	pk_rsp->body.type = BSL_REP_AUTH_M1_DATA;
	pk_rsp->body.size = (unsigned short)sizeof(ack);
	if (!dl_need_to_authorize())
		ack.mStatus = 1;
	else
		ack.mStatus = 0;
	update_project_info(ack.ProjectName);
	memcpy(pk_rsp->body.content, &ack, sizeof(ack));

	dl_send_packet(pk_rsp);
	dl_free_packet(pk_rsp);

	if (1 == ack.mStatus)
		dl_auth_sts = DL_SECURE_VERIFY_PASS;
	else
		dl_auth_sts = DL_AUTH_REQ;
	return 0;

fail:
	_send_reply(OPERATE_SYSTEM_ERROR);
	return -1;
}

int dl_cmd_secure_verify(dl_packet_t *packet, void *arg)
{
	if (dl_auth_sts != DL_AUTH_REQ) {
		goto fail;
	}

	if (authentication(packet->body.content, 0) < 0) {
		goto fail;
	}

	_send_reply(OPERATE_SUCCESS);
	dl_auth_sts = DL_SECURE_VERIFY_PASS;
	return 0;

fail:
	_send_reply(OPERATE_SYSTEM_ERROR);
	dl_auth_sts = DL_AUTH_INIT;
	return -1;
}
#endif

int dl_cmd_start_wdg(dl_packet_t *packet, void *arg)
{
	uint32_t timeout = *(uint32_t *)packet->body.content;

	printf("start wdg timeout %dms\n", timeout);
	start_watchdog((uint64_t)timeout);
	_send_reply(OPERATE_SUCCESS);
	return 0;
}

int dl_cmd_stop_wdg(dl_packet_t *packet, void *arg)
{
	printf("stop wdg\n");
	stop_watchdog();
	_send_reply(OPERATE_SUCCESS);
	return 0;
}

