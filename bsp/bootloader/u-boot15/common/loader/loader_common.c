#include "loader_common.h"
#include "custom.h"
#include <mmc.h>
#include <fat.h>
#if defined(CONFIG_OF_LIBFDT)
#include <libfdt.h>
#include <fdt_support.h>
#endif
#include <sprd_common_rw.h>
#include <linux/usb/usb_uboot.h>

#ifdef CONFIG_MINI_TRUSTZONE
#include "trustzone_def.h"
#endif

#ifdef CONFIG_MEM_LAYOUT_DECOUPLING
#include "cp_mem_decoupling.h"
#endif
#include "sprd_cpcmdline.h"
#include <asm/arch/sprd_reg.h>
#include <hwfeature.h>
//20220525,Added by zhu_jun for serial number related properties begin
#include <protect_data_def.h>
//20220525,Added by zhu_jun for serial number related properties end

//20220718,Added by zhu_jun for support read imei from runtimenv begin
#include "dl_operate.h"
//20220718,Added by zhu_jun for support read imei from runtimenv end

#include <bootloader_message.h>

#define DECOUPLING_INFO_PARTITION "modem"
#ifdef CONFIG_SUPPORT_NR
#define DECOUPLING_INFO_PARTITION_NRPHY "nrphy"
#define DECOUPLING_INFO_PARTITION_V3PHY "v3phy"
#define DECOUPLING_INFO_PARTITION_PHY "phy"
#endif
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
#define WT_IMEI_LEN  15
char g_imei1_number[WT_IMEI_LEN];
char g_imei2_number[WT_IMEI_LEN];
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end
unsigned char raw_header[8192];
unsigned int g_charger_mode = 0;
char serial_number_to_transfer[SP15_MAX_SN_LEN];

extern int charger_connected(void);
extern void modem_entry(void);
extern char *bootcause_cmdline;
extern char *pwroffcause_cmdline;
int g_res_spbootcode_info = 0;

//20220525,Added by zhu_jun for serial number related properties begin
extern int hardware_level;
//20220525,Added by zhu_jun for serial number related properties end

#ifdef CONFIG_TIME_STATISTIC
extern u32 tuboot_s;
extern u32 tuboot_e;
#endif

unsigned short calc_checksum(unsigned char *dat, unsigned long len)
{
	unsigned short num = 0;
	unsigned long chkSum = 0;
	while (len > 1) {
		num = (unsigned short)(*dat);
		dat++;
		num |= (((unsigned short)(*dat)) << 8);
		dat++;
		chkSum += (unsigned long)num;
		len -= 2;
	}
	if (len) {
		chkSum += *dat;
	}
	chkSum = (chkSum >> 16) + (chkSum & 0xffff);
	chkSum += (chkSum >> 16);
	return (~chkSum);
}

unsigned char _chkNVEcc(uint8_t *buf, uint64_t size, uint32_t checksum)
{
	uint16_t crc;

	crc = calc_checksum(buf, (unsigned long)size);
	debugf("_chkNVEcc calcout 0x%x, org 0x%x\n", crc, (uint16_t)checksum);
	return (crc == (uint16_t) checksum);
}

//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
#define TEST_IMEI_DATA  0   // use test verify IMEI

#if TEST_IMEI_DATA
// source data :  863408027021113
unsigned char test_imei_buf[]={0xa7,0x5c,0xf3,0xe4,0x3f,0x48,0x6c,0x36,0x82,0xc0,0xa3,0xa1,0xe4,0x85,0xcd,0x60,
	0xfe,0x27,0xab,0xfd,0x52,0x1a,0x6a,0x5d,0x35,0x1b,0x52,0xce,0x21,0x19,0x7c,0x7d,
	0x3e,0x19,0x62,0x44,0xb6,0x42,0xf5,0x3a,0x7d,0x37,0xf1,0x1b,0x2e,0x81,0x14,0x53,
	0x2c,0x3a,0x94,0x7f,0x09,0x9c,0x7b,0x7b,0x28,0x55,0x78,0xa1,0x3a,0xd4,0xc1,0x60,
	0x5b,0x87,0x45,0xef,0xad,0x22,0xee,0x5c,0x96,0x74,0xd7,0x31,0x61,0xf9,0x9c,0x49,
	0x06,0x14,0x5e,0x1f,0x62,0x20,0x91,0x94,0x5a,0x2e,0xff,0x04,0xcd,0xc1,0x55,0xd0,
	0xa8,0x19,0x1f,0x55,0xe5,0xfe,0x7f,0xd2,0xcd,0x75,0xf9,0xc3,0xda,0x46,0x0f,0x0d,
	0xce,0xd9,0xe9,0x05,0x92,0x46,0xc0,0xce,0x1a,0x17,0x1c,0x58,0xe7,0x31,0x83,0x8d,
	0x27,0x54,0xfe,0x7a,0x7f,0xc6,0x21,0x94,0xe9,0xc6,0xba,0x86,0x76,0x9f,0xb3,0xe7,
	0xa1,0x00,0x02,0xea,0x91,0x81,0xa9,0xa6,0x77,0xc5,0x13,0x93,0x69,0x05,0x53,0xb8,
	0xf0,0xcb,0x22,0xb5,0xdd,0xe5,0xf1,0x87,0xa4,0x20,0xe6,0x1a,0xf0,0x5d,0x53,0x1a,
	0xde,0xc7,0x36,0x94,0xb6,0x7f,0x87,0x81,0x6f,0xc4,0x12,0xee,0xca,0xc5,0x15,0xf5,
	0x8d,0xb1,0x7a,0x87,0x1f,0xc7,0x90,0x3f,0x8b,0x84,0x80,0x4d,0x99,0x4a,0xb3,0xad,
	0x33,0x70,0xac,0x4a,0xf7,0x4f,0xe1,0x42,0x85,0x83,0x7e,0xaa,0x6b,0x8a,0x61,0x4a,
	0x00,0xaa,0x48,0x44,0xe7,0x71,0xed,0x60,0xac,0x4a,0x7d,0x02,0xd7,0x5a,0x4f,0xe0,
	0xe6,0xeb,0xa2,0x5f,0x8a,0xa2,0xd5,0x45,0xd0,0x90,0x8b,0x51,0x4e,0xd5,0xa0,0xd2};
#endif

void debugPrintf_Hex(const unsigned char *inBuf, int inLen, const char *cInfo)
{
    int i=0;
    printf("\n============= %s =============\n",cInfo);
    printf("inLen = %d \n",inLen);
    for (i = 0; i < inLen; i++) {
        if((0 == (i%16)) && (0 != i)) printf("\n");
        printf("%02x,",*(inBuf+i));
    }
    printf("\n============= %s =============\n",cInfo);
}

static int fb_verify_imei(unsigned char *encrypt_data, char *imeiNo)
{
    int ret = -1;
    int32_t length = -1;
    unsigned char revice_raw_data[16] = {0};
    unsigned char pub_E[4] = {0x00, 0x01, 0x00, 0x01};

 #if defined  VISION
 printf("\n=============use SHADOWCAT_PLUS key =============\n");
    unsigned char mod_N[256] =
		{0x94,0x4e,0xdb,0x6f,0x37,0xdb,0x69,0xc9,0xb4,0x88,0x23,0xa8,0x50,0x11,0x35,0x27,
		0x27,0x24,0x8b,0x21,0x64,0x35,0x35,0x99,0x53,0x35,0xbf,0xd1,0x75,0xa3,0x4d,0xc9,
		0x9f,0xbe,0x66,0x4e,0xd5,0xec,0xa1,0xaf,0x2d,0xfc,0x38,0x3a,0xa6,0x66,0x3e,0x6d,
		0xbc,0x1d,0x71,0xf4,0x2e,0x5d,0xd4,0x42,0x4c,0x4f,0x21,0xe7,0xf1,0xdc,0x91,0x11,
		0xa3,0xf2,0xac,0x13,0xc1,0xbd,0x06,0x33,0xe5,0x43,0xfb,0x52,0x5b,0x8e,0x48,0x21,
		0xc3,0x34,0x2f,0xd0,0x12,0x21,0x6c,0x0b,0x34,0xeb,0xa2,0x0d,0x97,0xd4,0xf8,0xaf,
		0x4b,0x39,0xd8,0xc2,0xa7,0x35,0x81,0xf6,0x13,0xb6,0x64,0xce,0xc9,0xdb,0x08,0xb3,
		0x05,0xeb,0x2a,0xc4,0xd3,0xff,0x87,0x42,0xc4,0x87,0xc8,0x40,0x5c,0x7d,0x1a,0xa1,
		0xc3,0xa3,0x13,0x7f,0x6d,0x21,0xe1,0x76,0x53,0xac,0xb8,0xea,0xbe,0xa7,0x27,0x29,
		0x8f,0x41,0xb9,0x5c,0x46,0x15,0xa0,0x4a,0x44,0x99,0xec,0x40,0x0e,0x1d,0xf7,0xa8,
		0x81,0x47,0x89,0x61,0xbe,0x42,0x43,0x0a,0x3f,0x93,0x03,0x4c,0x6e,0x72,0xf7,0x75,
		0xa9,0x37,0x52,0x21,0x5c,0x61,0x96,0xd6,0x3b,0x22,0xbd,0x3e,0xad,0x16,0x7d,0xa5,
		0x70,0x5a,0xe2,0x9b,0x28,0xef,0x10,0xa5,0xdf,0x51,0x32,0x85,0x8f,0xf7,0xb4,0xe8,
		0x51,0x33,0x13,0x85,0x15,0xec,0x40,0x4c,0xfe,0x20,0x7d,0x5b,0x69,0x21,0x08,0x96,
		0xb7,0x12,0xc7,0xe8,0x7b,0x87,0xd6,0xab,0xbf,0x5e,0x91,0x0d,0xd7,0xab,0xa0,0x8f,
		0xbf,0x11,0xf2,0x33,0x1b,0xad,0x46,0x7b,0x7f,0xfc,0x20,0x7b,0x79,0xed,0xe2,0x41};

#else  //self  pubkey
 printf("\n=============use TEST key =============\n");
    unsigned char mod_N[256] =
		{0xd3,0x09,0x95,0xb6,0x3d,0x78,0x72,0x7e,0x58,0x51,0x6d,0xc6,0xdb,0x95,0x98,0x16,
		0xb1,0x84,0x75,0xf4,0xf6,0x6c,0xc3,0x94,0x6c,0x33,0xf0,0xa7,0xaf,0x0c,0x5a,0x1b,
		0xb0,0xf1,0x1c,0x38,0xc6,0xaf,0x2e,0xa3,0x9e,0x12,0xcd,0xce,0x26,0x87,0x24,0xde,
		0x1c,0x36,0xe4,0x8a,0x61,0xa1,0x98,0x64,0x74,0xb5,0xae,0xce,0xd0,0x8a,0x5e,0x70,
		0x2b,0x33,0x36,0xd5,0xac,0x9b,0xe3,0x8c,0xde,0xba,0x2b,0xfd,0x4a,0xc5,0xbd,0x0d,
		0x01,0x26,0x1f,0xd8,0xb6,0xf7,0x07,0xfc,0x45,0xb4,0xaf,0xaa,0x12,0xb8,0xfb,0xb5,
		0x89,0x09,0xb6,0x1c,0x69,0xdf,0x10,0x8f,0x9e,0x6b,0xc6,0x0d,0xd7,0xf0,0x82,0xdb,
		0xbc,0xa7,0x2b,0xe2,0xbf,0x7d,0x32,0xd0,0x4f,0x28,0xc5,0x2d,0xb8,0x90,0x54,0xa5,
		0xc9,0x1a,0xd8,0x0e,0x4f,0x54,0x9f,0x9a,0xaa,0x45,0x3c,0x08,0xb8,0x48,0x09,0x9f,
		0xad,0x78,0x92,0x5c,0xa0,0xa4,0xd5,0xa3,0x69,0xcd,0xb9,0x0f,0x10,0xfc,0xff,0x23,
		0x26,0x0f,0xdc,0x9e,0xc9,0x83,0xc9,0x4e,0xc6,0xdd,0xd2,0xe2,0x89,0x56,0xd1,0x5c,
		0xcb,0x43,0xec,0xab,0xb4,0x06,0x41,0x90,0x75,0x60,0xbf,0x71,0x2a,0x22,0x17,0xba,
		0xca,0xe2,0x4e,0x8a,0xac,0xd3,0xd3,0x57,0xd4,0xc9,0x5e,0x95,0x91,0x85,0xaf,0x65,
		0xfa,0x0e,0xb6,0xd8,0xa7,0xaf,0x5c,0xc0,0xf9,0x1d,0x02,0x8f,0x9f,0xdf,0x14,0x66,
		0x2d,0xba,0x62,0x17,0x98,0x9d,0xb7,0x12,0x68,0x37,0xd1,0xd7,0x7a,0x65,0xc3,0x52,
		0xb4,0x69,0xd3,0x0e,0x04,0xb5,0x42,0xc7,0xb2,0xb3,0x3f,0x26,0x3b,0x4f,0xe4,0xbb};
#endif
     //debugPrintf_Hex(encrypt_data, 256, "input  encrypt_data");

    if (NULL == encrypt_data) {
        debugf("input encrypt_data NULL \r\n");
	ret = -1;
        return ret;
    }

    memset(revice_raw_data, 0x0, sizeof(revice_raw_data));
    length = RSA_Verify(pub_E, mod_N, 2048, encrypt_data, revice_raw_data);
    if (0 > length) {
        debugf("rsa verify dec failed err:%d\n", length);
        ret = -1;
        return ret;
    }

    //debugPrintf_Hex(revice_raw_data, length, "Verify return  revice_raw_data");
    dumpHex("revice_raw_data", revice_raw_data, sizeof(revice_raw_data));

    memcpy(imeiNo, revice_raw_data, WT_IMEI_LEN);
    debugf("Verify return imeiNo: %s \r\n",imeiNo);

    ret = 0;
    return ret;
}

//20220718,Added by zhu_jun for support read imei from runtimenv begin
static int findItem(uint32_t id, uint8_t * nvBuf, uint32_t nvLength, uint32_t * itemSize, uint32_t * itemPos)
{
    uint32_t offset = 4;
    uint16_t tmp[2];
    while (1) {
      if (*(uint16_t *) (nvBuf + offset) == 0xffff) {
        errorf("NV:findItem find the tail\n");
        break;
      }
      if (offset + sizeof(tmp) > nvLength) {
        errorf("NV:findItem Surpass the boundary of the part\r\n");
        break;
      }
      memcpy(tmp, nvBuf + offset, sizeof(tmp));
      offset += sizeof(tmp);
      if (id == (uint32_t) tmp[0]) {
        *itemSize = (uint32_t) tmp[1];
        *itemPos = offset;
        debugf("NV:findItem id = 0x%x\n", id);
        return 1;
      }
      offset += tmp[1];
      offset = (offset + 3) & 0xFFFFFFFC;
  }
  return 0;
}

void imeiConvNV2Str(unsigned char *nvImei, unsigned char *szImei) {
  int i;

  for (i = 0; i < 7; i++) {
    szImei[2 * i + 0] = ((nvImei[i] & 0xF0) >> 4) + '0';
    szImei[2 * i + 1] = (nvImei[i + 1] & 0x0F) + '0';
  }

  szImei[14] = ((nvImei[7] & 0xF0) >> 4) + '0';
}

char *find_nv_value_by_id(uint32_t id)
{
    char partition_name[64] = "l_fixnv1";
    uint8_t header_buf[NV_HEAD_LEN] = {0x00};
    nv_header_t     *nv_header_p = NULL;
    uint32_t nv_size = 0;
    int ret = 0;
    char *nv_buf = NULL;
    char imei_nvbuf[8] = {0};
    char imei_str[15] = {0};
    char backup_partition_name[64] = "l_fixnv2";
    uint32_t nv_item_size, nv_pos;

    #ifdef CONFIG_ANDROID_AB
      struct bootloader_control abc = {0};
      ulong abc_offset, abc_size;
      abc_offset = offsetof(struct bootloader_message_ab, slot_suffix);
      abc_size = sizeof(struct bootloader_control);
      ret = common_raw_read("misc", (u64)abc_size, (u64)abc_offset, (char *)&abc);
      if (ret < 0) {
        errorf("NV ANDROID: Could not read from boot ctrl partition\n");
        return NULL;
      }
      memset(partition_name, 0, sizeof(partition_name));
      sprintf(partition_name, "l_fixnv1%c%c", abc.slot_suffix[0], abc.slot_suffix[1]);
      memset(backup_partition_name, 0, sizeof(backup_partition_name));
      sprintf(backup_partition_name, "l_fixnv2%c%c", abc.slot_suffix[0], abc.slot_suffix[1]);
    #endif
    debugf("nv partition_name=%s,backup_partition_name=%s\n",partition_name,backup_partition_name);
    memset(imei_nvbuf, 0, sizeof(imei_nvbuf));
    memset(imei_str, 0, sizeof(imei_str));
    memset(header_buf, 0x00, NV_HEAD_LEN);
    if(common_raw_read(partition_name, NV_HEAD_LEN, (uint64_t)0, header_buf)) {
      ret = -1;
      errorf("fail to read nv header!, ret=%d\n",ret);
      return NULL;
    }

    nv_header_p = header_buf;
    if( nv_header_p->magic == NV_HEAD_MAGIC && nv_header_p->version == NV_VERSION) {
      nv_size = nv_header_p->len;
      nv_buf = malloc(nv_size);
      if (NULL == nv_buf) {
        ret = -2;
	errorf("no enough space for nv buffer,ret=%d\n",ret);
	return NULL;
      }

      memset(nv_buf, 0x0, nv_size);
      debugf("nv_size 0x%x\n", nv_size);
      common_raw_read(partition_name, (uint64_t)(nv_size), NV_HEAD_LEN, nv_buf);
      if(TRUE != fdl_check_crc(nv_buf, nv_size, nv_header_p->checksum)) {
        debugf("main nv partition %s is damaged!\n", partition_name);
        memset(header_buf, 0x00, NV_HEAD_LEN);
	if (common_raw_read(backup_partition_name, NV_HEAD_LEN, (uint64_t)0, header_buf)) {
          ret = -3;
          errorf("fail to read nv header!\n");
	  free(nv_buf);
          return NULL;
        }
        nv_header_p = header_buf;
        if( nv_header_p->magic == NV_HEAD_MAGIC && nv_header_p->version == NV_VERSION) {
          free(nv_buf);
          nv_size = nv_header_p->len;
          nv_buf = malloc(nv_size);
	  if (NULL == nv_buf) {
            ret = -4;
            errorf("no enough space for nv buffer, ret=%d\n",ret);
            return NULL;
	  }

	  if (common_raw_read(backup_partition_name, (uint64_t)(nv_size), NV_HEAD_LEN, nv_buf)){
            free(nv_buf);
            ret = -5;
            errorf("fail to read backup nv header!,ret=%d\n",ret);
            return NULL;
          }

          if(TRUE != fdl_check_crc(nv_buf, nv_size, nv_header_p->checksum)) {
            free(nv_buf);
            ret = -6;
            errorf("main nv partition and bakup nv partition is damaged!,ret=%d\n",ret);
            return NULL;
          }
        } else {
          free(nv_buf);
          ret = -7;
          errorf("back up nv partition header error!magic = %#x,version = %d, ret=%d\n",
                          nv_header_p->magic, nv_header_p->version,ret);
          return NULL;
        }
      }

    } else {
      free(nv_buf);
      ret = -8;
      debugf("The current nv partition is empty!,ret=%d\n",ret);
      return NULL;
    }

    nv_item_size = 0; nv_pos = 0;
    if (findItem(id, nv_buf, nv_size, &nv_item_size, &nv_pos)) {
      memcpy(imei_nvbuf, nv_buf + nv_pos, nv_item_size);
      debugf("The current nv value=%s\n",imei_nvbuf);
      imeiConvNV2Str(imei_nvbuf, imei_str);
      debugf("The current imei_str=%s\n",imei_str);
    }

  free(nv_buf);
  return imei_str;
}

char *get_product_imei1(void)
{
  return find_nv_value_by_id(0x5);
}

char *get_product_imei2(void)
{
  return find_nv_value_by_id(0x179);
}
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end
//20220718,Added by zhu_jun for support read imei from runtimenv end

/*modif to support the sp15 64 bit sn NO */
//20220525,Added by zhu_jun for serial number related properties begin
char *get_product_sn(void)
{
	const char *type = "serial";
    char value_buf[PHONE_SN_LEN] = {};
	unsigned char *buf_sn = value_buf;
		
    if(hardware_level > 0)
    {
		memset(serial_number_to_transfer, 0x0, PHONE_SN_LEN);
	    strcpy(serial_number_to_transfer, "0123456789ABCDEF000");
	    if(!read_protect_data_ex(type,buf_sn,PHONE_SN_LEN)){
		    if(0 != buf_sn[0]){
			    memcpy(serial_number_to_transfer, buf_sn, PHONE_SN_LEN);
		    }
	    }
	    return serial_number_to_transfer;
    }
/*modif to support the sp15 64 bit sn NO */
//char *get_product_sn(void)
    else
    {
	SP09_PHASE_CHECK_T phase_check_sp09;
	SP15_PHASE_CHECK_T phase_check_sp15;
	uint32_t magic;
	bool bprotect = false;

	memset(serial_number_to_transfer, 0x0, SP15_MAX_SN_LEN);

	strcpy(serial_number_to_transfer, "0123456789ABCDEF");
	if (0 != common_raw_read(PRODUCTINFO_FILE_PATITION, sizeof(magic), (uint64_t)0, (char *)&magic)) {
		errorf("read miscdata error.\n");
		return serial_number_to_transfer;
	}
	debugf("%s: magic= %d\n", __func__, magic);

	if(!read_protect_data_ex(type,buf_sn,PHONE_SN_LEN)){
		if(0 != buf_sn[0]){
			memcpy(serial_number_to_transfer, buf_sn, PHONE_SN_LEN);
			bprotect = true;
		}
	}
	
	if(magic == SP09_SPPH_MAGIC_NUMBER){
		if(common_raw_read(PRODUCTINFO_FILE_PATITION,sizeof(phase_check_sp09), (uint64_t)0, (char *)&phase_check_sp09)){
			debugf("sp09 read miscdata error.\n");
			return serial_number_to_transfer;
		}
		//debugf("%s: magic= SP09_SPPH_MAGIC_NUMBER, [%s],[%s]\n", __func__,phase_check_sp09.SN1, phase_check_sp09.SN2);
		if ( !bprotect ) {
			if(strlen(phase_check_sp09.SN2)){
				memcpy(serial_number_to_transfer, phase_check_sp09.SN2, SP09_MAX_SN2_LEN);
			} else {
				memcpy(serial_number_to_transfer, phase_check_sp09.SN1, SP09_MAX_SN_LEN);
			}
		}
	}else if(magic == SP15_SPPH_MAGIC_NUMBER){
		if(common_raw_read(PRODUCTINFO_FILE_PATITION, sizeof(phase_check_sp15), (uint64_t)0 ,(char *)&phase_check_sp15)){
			debugf("sp15 read miscdata error.\n");
			return serial_number_to_transfer;
		}
	        //debugf("%s: magic= SP15_SPPH_MAGIC_NUMBER, [%s]\n", __func__, phase_check_sp15.SN2);
		if ( !bprotect ) {
			if(strlen(phase_check_sp15.SN2)){
				memcpy(serial_number_to_transfer, phase_check_sp15.SN2, SP15_MAX_SN2_LEN);
			} else {
				memcpy(serial_number_to_transfer, phase_check_sp15.SN1, SP15_MAX_SN_LEN);
			}
		}
	}
	return serial_number_to_transfer;
    }
}
//20220525,Added by zhu_jun for serial number related properties end

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
int set_product_sn(char *psn, int len)
{
	static const char *serialno_def = "0123456789ABCDEF";
	SP09_PHASE_CHECK_T phase_check_sp09;
	SP15_PHASE_CHECK_T phase_check_sp15;
	uint32_t magic;
    int maxlen;

	if (len < 0 || (len && !psn))
		return -1;

	if (0 != common_raw_read(PRODUCTINFO_FILE_PATITION, sizeof(magic),
			(uint64_t)0, (char *)&magic)) {
		errorf("read miscdata error.\n");
		return -1;
	}

	if (magic == SP09_SPPH_MAGIC_NUMBER) {
		if (common_raw_read(PRODUCTINFO_FILE_PATITION, sizeof(phase_check_sp09),
				(uint64_t)0, (char *)&phase_check_sp09)) {
			errorf("sp09 read miscdata error.\n");
			return -1;
		}

        	maxlen = sizeof(phase_check_sp09.SN2);
        	if ( maxlen > SP09_MAX_SN2_LEN ) {
        		maxlen = SP09_MAX_SN2_LEN;
        	}

		if (len > maxlen ) {
			errorf("set length(%d) is larger than sp09 limit.\n", len);
			return -1;
		}

		memset(phase_check_sp09.SN2, 0, sizeof(phase_check_sp09.SN2));
		if (!len)
			memcpy(phase_check_sp09.SN2, serialno_def, strlen(serialno_def));
		else
			memcpy(phase_check_sp09.SN2, psn, len);
		
		// write protect_data
		repair_set_key(TYPE_PROTECT_DATA, PROTECTDATA_SN_OFFSET, phase_check_sp09.SN2, SP09_MAX_SN2_LEN);
		
		// write miscdata
		if (common_raw_write(PRODUCTINFO_FILE_PATITION, sizeof(phase_check_sp09),
				(uint64_t)0, (uint64_t)0, (char *)&phase_check_sp09)) {
			errorf("sp09 write miscdata error.\n");
			return -1;
		}

		return 0;
	} else if(magic == SP15_SPPH_MAGIC_NUMBER) {
		if (common_raw_read(PRODUCTINFO_FILE_PATITION, sizeof(phase_check_sp15),
				(uint64_t)0 ,(char *)&phase_check_sp15)) {
			errorf("sp15 read miscdata error.\n");
			return -1;
		}

        	maxlen = sizeof(phase_check_sp15.SN2);
        	if ( maxlen > SP15_MAX_SN2_LEN ) {
        		maxlen = SP15_MAX_SN2_LEN;
        	}

		if (len > maxlen ) {
			errorf("set length(%d) is larger than sp15 limit.\n", len);
			return -1;
		}

		memset(phase_check_sp15.SN2, 0, sizeof(phase_check_sp15.SN2));
		if (!len)
			memcpy(phase_check_sp15.SN2, serialno_def, strlen(serialno_def));
		else
			memcpy(phase_check_sp15.SN2, psn, len);

		// write protect_data
		repair_set_key(TYPE_PROTECT_DATA, PROTECTDATA_SN_OFFSET, phase_check_sp15.SN2, SP15_MAX_SN2_LEN);

		if (common_raw_write(PRODUCTINFO_FILE_PATITION, sizeof(phase_check_sp15),
				(uint64_t)0, (uint64_t)0, (char *)&phase_check_sp15)) {
			errorf("sp15 write miscdata error.\n");
			return -1;
		}

		return 0;
	} else {
		errorf("unsupport magic %x.\n", magic);
	}

	return -1;
}
#endif

void fdt_fixup_all(u8 *fdt_blob)
{
	uint32_t fdt_size;
	boot_img_hdr *hdr = raw_header;
	int err;
	char  *boot_mode_type_str;

	if (fdt_check_header(fdt_blob) != 0) {
		errorf("image is not a fdt\n");
	}

#ifdef CONFIG_SPLASH_SCREEN
	fdt_fixup_lcdid(fdt_blob);
	fdt_fixup_lcdname(fdt_blob);
	fdt_fixup_lcdbase(fdt_blob);
	fdt_fixup_lcdsize(fdt_blob);

	fdt_fixup_lcdbpix(fdt_blob);
	fdt_fixup_battery_id_parameters(fdt_blob);
#endif

	//fdt_fixup_dram_training(fdt_blob);
	fdt_fixup_ddr_size(fdt_blob);
	fdt_fixup_ro_boot_ramsize(fdt_blob);
	fdt_fixup_ddrsize_range(fdt_blob);
	fdt_fixup_hwfeature(fdt_blob);
	fdt_fixup_cpuinfo_hwfeature(fdt_blob);
	fdt_fixup_soc_module(fdt_blob);
	fdt_fixup_sysdump_uboot(fdt_blob);
	fdt_fixup_sysdump_magic(fdt_blob);
#ifdef CONFIG_SECURE_BOOT
	fdt_fixup_secureboot_param(fdt_blob);
#endif
	fdt_fixup_wdten(fdt_blob);
	fdt_fixup_dswdten(fdt_blob);
#ifdef CONFIG_NAND_BOOT
	fdt_fixup_mtd(fdt_blob);
#ifdef CONFIG_UBI_ATTACH_MTD
	fdt_fixup_ubi_ai(fdt_blob);
#endif
#endif
#ifdef CONFIG_MEM_LAYOUT_DECOUPLING
	char *modem_part = DECOUPLING_INFO_PARTITION;
#ifdef CONFIG_ANDROID_AB
	char temp[128];
	char *ab_slot = getenv("slot");
	if (ab_slot) {
		snprintf(temp, ARRAY_SIZE(temp), "%s%s", DECOUPLING_INFO_PARTITION, ab_slot);
		modem_part = temp;
	}
#endif
	fdt_fixup_cp_coupling_info(fdt_blob, modem_part);
#ifdef CONFIG_SUPPORT_NR
	fdt_fixup_cp_coupling_info(fdt_blob, DECOUPLING_INFO_PARTITION_NRPHY);
	fdt_fixup_cp_coupling_info(fdt_blob, DECOUPLING_INFO_PARTITION_V3PHY);
	fdt_fixup_cp_coupling_info(fdt_blob, DECOUPLING_INFO_PARTITION_PHY);
#endif
#endif

#if defined (CONFIG_SP_DDR_BOOT) && defined (CONFIG_MEM_LAYOUT_DECOUPLING)
	/* sp ddr boot info */
	g_res_spbootcode_info = fdt_fixup_sp_info(fdt_blob);
#endif

	/*max let cp_cmdline_fixup befor fdt_fixup_cp_boot*/
	cp_cmdline_fixup();
	fdt_fixup_cp_boot(fdt_blob);

	//20220531,Added by zhu_jun for get hdm product info begin
	fdt_fixup_hmd_productinfo(fdt_blob);
	//20220531,Added by zhu_jun for get hdm product info end

	boot_mode_type_str = getenv("bootmode");
	if (NULL != boot_mode_type_str)
	{
		if(!strncmp(boot_mode_type_str, "sprdisk", 7)) {
			fdt_fixup_memleakon(fdt_blob);
		}
	}

	/*for verified boot*/
	fdt_fixup_verified_boot(fdt_blob);
	fdt_fixup_flash_lock_state(fdt_blob);
	fdt_fixup_serialno(fdt_blob);
//Added by q, set efuse property on rpmb stats on 20220513
	fdt_fixup_rpmb(fdt_blob);
//Added by qiu_hai.hoperun, set efuse property on 20220513

//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin
	fdt_fixup_hef(fdt_blob);
//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) end
	//added by dongming, for miscdata india flag, 20221018
        fdt_fixup_india_flag(fdt_blob);
	//end added, for miscdata india flag, 20221018
	fdt_fixup_secureboot(fdt_blob);
    //20220531,Added by zhu_jun for Set ZeroFlag related property begin
    fdt_fixup_zeroflag(fdt_blob);
    //20220531,Added by zhu_jun for Set ZeroFlag related property end
	//20220607, Added by zhu_jun for set the property of powp begin
    fdt_fixup_powp(fdt_blob);
	//20220607, Added by zhu_jun for set the property of powp end

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	fdt_fixup_oem_repair(fdt_blob);
#endif
	fdt_fixup_chosen_bootargs_board_private(fdt_blob);

#ifdef CONFIG_SANSA_SECBOOT
	//fdt_fixup_socid(fdt_blob);
#endif

	/* for non iq mode, remove reserved iq memory from dtb */
	fdt_fixup_iq_reserved_mem(fdt_blob);

#ifdef CONFIG_BOARD_KERNEL_CMDLINE
	/* board kernel cmdline in header of boot.img */
	fdt_fixup_board_kernel_cmdline(fdt_blob);
	/* board kernel cmdline in header of vendorboot.img */
	fdt_fixup_board_kernel_cmdline_from_vendorboot(fdt_blob);
#endif

	fdt_fixup_dtbo_index(fdt_blob);
	/* if enabled, set loglevel = 7*/
	fdt_fixup_loglevel(fdt_blob);
	fdt_fixup_system_mount_part_num(fdt_blob);

	fdt_fixup_switch_storage_probe(fdt_blob);

#if (defined(CONFIG_GET_CPU_SERIAL_NUMBER) || defined(CONFIG_GET_CPU_SERIAL_NUMBER_NO_WD))
	fdt_fixup_cpu_serial_number(fdt_blob);
#endif

#ifdef DEBUG
	fdt_fixup_selinux_switch(fdt_blob);
#endif

#ifdef CONFIG_VBOOT_V2
    fdt_fixup_vboot(fdt_blob);
#endif

#ifdef CONFIG_ANDROID_AB
	fdt_fixup_add_slot_suffix(fdt_blob);
	fdt_fixup_add_force_mode(fdt_blob);
#endif

#if defined(CONFIG_UFS) && defined(CONFIG_MMC)
	fdt_fixup_boot_device(fdt_blob);
#endif

	fdt_fixup_first_mode(fdt_blob);
	fdt_fixup_bootcause(fdt_blob);

//20220511, Added by zhu_jun for the power-on write protect request start
#ifdef CONFIG_EMMC_WP
	fdt_fixup_protect_part(fdt_blob);
#endif
//20220511, Added by zhu_jun for the power-on write protect request end

	fdt_fixup_pwroffcause(fdt_blob);
	fdt_fixup_charger_parameters(fdt_blob);
	fdt_fixup_battery_id_parameters(fdt_blob);
//#ifdef DISABLE_UART // 20220615, Added by zhu_jun for disable UART for shipment version
	extern int con_en;
	if(!con_en)
		fdt_close_console(fdt_blob);
//#endif  // 20220615, Added by zhu_jun for disable UART for shipment version

#ifdef CONFIG_SENSOR_HUB_UBOOT
	fdt_fixup_sensor_name(fdt_blob);
#endif

	if(reboot_mode_check() != CMD_TOS_PANIC_MODE)
		fdt_fixup_tee_reserved_mem(fdt_blob);

	fdt_fixup_uboot_log_reserved(fdt_blob);

	fdt_fixup_startup_core(fdt_blob);

	fdt_fixup_vendor_init_flag(fdt_blob);

#ifdef CONFIG_CREATE_KASLR_SEED
	fdt_fixup_kaslr_seed(fdt_blob);
#endif
	return;
}

void fdt_fixup_all_x86(u8 *fdt_blob)
{
	uint32_t fdt_size;
	boot_img_hdr *hdr = raw_header;
	int err;
	char  *boot_mode_type_str;

	if (fdt_check_header(fdt_blob) != 0) {
		errorf("image is not a fdt\n");
	}

#ifdef CONFIG_SPLASH_SCREEN
	fdt_fixup_lcdid(fdt_blob);
	fdt_fixup_lcdname(fdt_blob);
	fdt_fixup_lcdbase(fdt_blob);
	fdt_fixup_lcdsize(fdt_blob);

	fdt_fixup_lcdbpix(fdt_blob);
#endif

	fdt_fixup_serialno(fdt_blob);

#ifdef CONFIG_MEM_LAYOUT_DECOUPLING
	fdt_fixup_cp_coupling_info(fdt_blob, DECOUPLING_INFO_PARTITION);
#ifdef CONFIG_SUPPORT_NR
	fdt_fixup_cp_coupling_info(fdt_blob, DECOUPLING_INFO_PARTITION_NRPHY);
	fdt_fixup_cp_coupling_info(fdt_blob, DECOUPLING_INFO_PARTITION_V3PHY);
	fdt_fixup_cp_coupling_info(fdt_blob, DECOUPLING_INFO_PARTITION_PHY);
#endif
#endif

	/*max let cp_cmdline_fixup befor fdt_fixup_cp_boot*/
	cp_cmdline_fixup();

	fdt_fixup_cp_boot(fdt_blob);

	/*for verified boot*/
	fdt_fixup_verified_boot(fdt_blob);
	fdt_fixup_flash_lock_state(fdt_blob);

	/* for non iq mode, remove reserved iq memory from dtb */
	fdt_fixup_iq_reserved_mem(fdt_blob);

	fdt_fixup_pmic_wa(fdt_blob);

#ifdef CONFIG_BOARD_KERNEL_CMDLINE
	/* board kernel cmdline in header of boot.img */
	fdt_fixup_board_kernel_cmdline(fdt_blob);
	/* board kernel cmdline in header of vendorboot.img */
	fdt_fixup_board_kernel_cmdline_from_vendorboot(fdt_blob);
#endif

	/* if enabled, set loglevel = 7*/
	fdt_fixup_loglevel(fdt_blob);
	fdt_fixup_system_mount_part_num(fdt_blob);

#ifdef CONFIG_VBOOT_V2
    fdt_fixup_vboot(fdt_blob);
#endif
}

#ifdef CONFIG_X86
static int start_linux_x86()
{
	struct boot_params *base_ptr;
	struct boot_img_hdr *boot_hdr = (void *)raw_header;
	uint64_t load_address = 0;
	char *bzImage_addr = KERNEL_ADR;
	ulong bzImage_size = 0;
	ulong initrd_addr = RAMDISK_ADR;
	ulong initrd_size = PAD_SIZE(boot_hdr->ramdisk_size, KERNL_PAGE_SIZE);
	int image_64bit = 0;

	debugf("initrd_size: 0x%lx\n", initrd_size);
	disable_interrupts();
	wbinvd();

#ifndef CONFIG_ZEBU
	/*start modem CP */
	modem_entry();
#endif

	/* Setup board for maximum PC/AT Compatibility */
	setup_pcat_compatibility();
	/* Lets look for */
	base_ptr = load_zimage(bzImage_addr, bzImage_size, &load_address);

	if (!base_ptr) {
		puts("## Kernel loading failed ...\n");
		return -1;
	}
	if (setup_zimage(base_ptr, (char *)base_ptr + COMMAND_LINE_OFFSET,
			0, initrd_addr, initrd_size)) {
		puts("Setting up boot parameters failed ...\n");
		return -1;
	}
	image_64bit = image_check64(base_ptr);
	/* we assume that the kernel is in place */
	return boot_linux_kernel((ulong)base_ptr, load_address, image_64bit);
}
#endif

#ifdef CONFIG_ARM
static int start_linux(uchar *dt_addr)
{
#ifdef CONFIG_OF_LIBFDT
	void (*theKernel) (int zero, int arch, u32 params);
	theKernel = (void (*)(void *, int, int, int))KERNEL_ADR;

	/*disable all caches */
	cleanup_before_linux();

	/*start modem CP */
#ifndef CONFIG_ZEBU
	modem_entry();
#endif

#ifdef CONFIG_MINI_TRUSTZONE
	trustzone_entry(TRUSTZONE_ADR + 0x200);
#endif

#ifdef CONFIG_TIME_STATISTIC
	tuboot_e = SCI_GetTickCount();
	/* append to bootargs */
	if (fdt_fixup_timeconsuming(dt_addr)) {
		errorf("failed to append timeconsuming to bootargs\n");
	}
#endif

	/* jump to kernel with register set */
	theKernel(0, machine_arch_type, (u32)dt_addr);
#else
	void (*theKernel) (int zero, int arch, u32 params);
	u32 machine_type = 0;

	machine_type = machine_arch_type;	/* get machine type */
	theKernel = (void (*)(int, int, u32))KERNEL_ADR;	/* set the kernel address */

	/*start modem CP */
	cp_cmdline_fixup();

	/*disable all caches */
	cleanup_before_linux();

	/*start modem CP */
	modem_entry();

#ifdef CONFIG_TIME_STATISTIC
	tuboot_e = SCI_GetTickCount();
	/* append to bootargs */
	if (fdt_fixup_timeconsuming(dt_addr)) {
		errorf("failed to append timeconsuming to bootargs\n");
	}
#endif

	/* jump to kernel with register set */
	theKernel(0, machine_type, VLX_TAG_ADDR);
#endif /*CONFIG_OF_LIBFDT */
	while (1) ;
	return 0;
}
#endif
static int start_linux_armv8(uchar *dt_addr)
{
	void (*theKernel) (void *dtb_addr, int zero, int arch, int reserved);
	theKernel = (void (*)(void *, int, int, int))KERNEL_ADR;

	/*before switch to el2,flush all cache */
	/*FIXME: cleanup_before_linux() will cause panic here, we need to find the solution*/
	flush_dcache_range(CONFIG_SYS_SDRAM_BASE, CONFIG_SYS_SDRAM_END);
#ifdef CONFIG_DUAL_DDR
	flush_dcache_range(CONFIG_SYS_SDRAM_BASE2, CONFIG_SYS_SDRAM_END2);
#endif

	/*sharkle and sharklj1 need disable mmu and cache before jump into kernel*/
	cleanup_before_linux();

#ifndef CONFIG_ZEBU
	/*start modem CP */
	modem_entry();
#endif

#ifdef CONFIG_MINI_TRUSTZONE
	trustzone_entry(TRUSTZONE_ADR + 0x200);
#endif

#ifdef CONFIG_TIME_STATISTIC
	tuboot_e = SCI_GetTickCount();
	/* append to bootargs */
	if (fdt_fixup_timeconsuming(dt_addr)) {
		errorf("failed to append timeconsuming to bootargs\n");
	}
#endif

	/*kernel must run in el2, so here switch to el2 */
	armv8_switch_to_el2();
	theKernel(dt_addr, 0, 0, 0);

	/*never enter here*/
	while (1) ;
	return 0;
}

extern uint32_t uboot_start_time;
extern int read_mux_cfg_flag(void);

void vlx_entry(uchar *dt_addr)
{
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	/* clear reboot-edl flag if necessary */
	if (!fb_check_reboot_edl(NULL)) {
		(void)fb_require_reboot_edl(0);
	}
#endif
//#ifdef WT_FINAL_RELEASE
    wt_clear_edl();
//#endif
	char *bootmode = getenv("bootmode");
	uint32_t consume_time;

	consume_time = SCI_GetTickCount() - uboot_start_time;
	printf("enter mode %s, consume time: %dms, boot_reason: %s,pwroff_reason: %s\n",
		!bootmode ? "normal" : bootmode, consume_time,
		!bootcause_cmdline ? "Bootcause hasn't been set yet" : bootcause_cmdline,
		!pwroffcause_cmdline ? "pwroffcause hasn't been set yet" : pwroffcause_cmdline);

	/* the last time to write log */
	write_log_last();

#ifdef DFS_ON_ARM7
	cp_dfs_param_for_arm7();
#endif

	/*shutdown usb ldo, can't shutdown it in the ldo_sleep.c because download mode must use usb */
	/*if USB opens Pin mux config in chipram, can't shutdown usb ldo */

#ifdef CONFIG_USBPINMUX
	if (!read_mux_cfg_flag()) {
		usb_driver_exit();
		printf("usb_pin_mux config is closed!\n");
	}
#else
	usb_driver_exit();
#endif

#ifdef CONFIG_ARM64
	smp_kick_all_cpus();
	start_linux_armv8(dt_addr);
#endif
#ifdef CONFIG_ARM
	start_linux(dt_addr);
#endif
#ifdef CONFIG_X86
	start_linux_x86();
#endif
}
