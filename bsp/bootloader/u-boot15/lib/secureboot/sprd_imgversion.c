/*
 * Copyright (C) 2017 spreadtrum.com
 */

#include <linux/types.h>
#include <malloc.h>
#include <common.h>
#include <mmc.h>


#include <sprd_imgversion.h>
#include <sprd_rpmb.h>
#include <secureboot/sec_common.h>
#include "sprd_rpmb_blk_rng.h"

#define SPRD_IMGVER_MAGIC 0xA50000A5

struct sprd_img_ver_t {
    uint32_t magic;
    uint32_t system_imgver;
    uint32_t vendor_imgver;
};

struct sprd_modem_img_ver_t {
    uint32_t magic;
    uint32_t l_modem_imgver;
    uint32_t l_ldsp_imgver;
    uint32_t l_lgdsp_imgver;
    uint32_t pm_sys_imgver;
    uint32_t agdsp_imgver;
    uint32_t wcn_imgver;
    uint32_t gps_imgver;
    uint32_t gpu_imgver;
    uint32_t vbmeta_imgver;
    uint32_t boot_imgver;
    uint32_t recovery_imgver;
    uint32_t socko_imgver;
    uint32_t odmko_imgver;
    uint32_t spare_imgver;
    uint32_t spares_imgver;
};

struct sprd_VAB_img_ver_t {
    uint32_t magic;
    uint32_t all_imgver[AVB_MAX_NUMBER_OF_ROLLBACK_INDEX_LOCATIONS];
};

#ifdef CONFIG_SPRD_RPMB
int sprd_get_rpmb_block_cnt(void)
{
    u64 rpmb_size = 0;

    rpmb_size = emmc_get_capacity(PARTITION_RPMB);

    return (rpmb_size / RPMB_DATA_SIZE);
}
#endif


int get_sprdimgver_blk_ind(void)
{
#ifdef CONFIG_SPRD_RPMB
	int ret;

	ret = sprd_get_rpmb_block_cnt();
	if (0 > ret ){
		printf("%s: get rpmb block count error! return code %d \n", __func__, ret);
		return -1;
	}
	//The last two blocks save struct sprd_img_ver_t and are compatible with previous versions
	return ret - 2;

#else
	return SPRD_IMGVERSION_BLK;
#endif
}

int get_sprdmodemimgver_blk_ind(void)
{
#ifdef CONFIG_SPRD_RPMB
	int ret;

	ret = sprd_get_rpmb_block_cnt();
	if (0 > ret ){
		printf("%s: get rpmb block count error! return code %d \n", __func__, ret);
		return -1;
	}

	//The last four blocks save struct sprd_modem_img_ver_t and are compatible with previous versions
	return ret - 4;
#else
	return SPRD_MODEM_IMGVERSION_BLK;
#endif
}

int sprd_get_imgversion(int imgType, unsigned int* swVersion)
{
    struct sprd_VAB_img_ver_t imgver;
    uint8_t data_rd[RPMB_DATA_SIZE]; //change data to 256-size,some emmc do not support size 512 at a time
    uint16_t block_ind, block_count;
    int ret;

    block_ind = get_sprdimgver_blk_ind();

    memset(data_rd, 0x0, sizeof(data_rd));
    block_count = sizeof(data_rd) / RPMB_DATA_SIZE;
    ret = rpmb_blk_read(data_rd, block_ind, block_count);
    if(ret != 0) {
        printf("%s: rpmb read blk %d fail! ret %d \n", __func__, block_ind, ret);
        return ret;
    }

#ifdef IMGVER_DEBUG
    printf("%s: rpmb read blk %d successful \n", __func__, block_ind);
#endif

    memcpy((void *)&imgver, data_rd, sizeof(struct sprd_VAB_img_ver_t));

    if(imgver.magic != SPRD_IMGVER_MAGIC) {
#ifdef IMGVER_DEBUG
        printf("invalid sprd imgversion magic %x exp %x \n",
            imgver.magic, SPRD_IMGVER_MAGIC);
#endif
        return -1;
    }

    if((imgType > 31) || (imgType < 0)) {
        printf("invalid sprd image type %d\n", imgType);
        return -1;
    }

    *swVersion = imgver.all_imgver[imgType];
#ifdef IMGVER_DEBUG
    printf("sprd image type %d, swVersion:0x%x\n", imgType, *swVersion);
#endif
    return 0;
}

int sprd_get_all_imgversion(VbootVerInfo* vboot_ver_info)
{
	struct sprd_VAB_img_ver_t imgver;
	uint8_t data_rd[RPMB_DATA_SIZE]; //change data to 256-size,some emmc do not support size 512 at a time
	uint16_t block_ind, block_count;
	int ret, i;
	uint32_t ab_slot_flag = 0;

	ab_slot_flag = vboot_ver_info->ab_slot_flag;
	printf("%s: ab_slot_flag is %d \n", __func__, ab_slot_flag);

	if(0 == ab_slot_flag){// a slot or NO_AB
		block_ind = get_sprdimgver_blk_ind();
	}else{
		block_ind = get_sprdmodemimgver_blk_ind();
	}
	memset(data_rd, 0x0, sizeof(data_rd));
	block_count = sizeof(data_rd) / RPMB_DATA_SIZE;
	ret = rpmb_blk_read(data_rd, block_ind, block_count);
	if(ret != 0) {
		printf("%s: rpmb read blk %d fail! ret %d \n", __func__, block_ind, ret);
		return ret;
	}

#ifdef IMGVER_DEBUG
	printf("%s: rpmb read blk %d successful \n", __func__, block_ind);
#endif
	memcpy((void *)&imgver, data_rd, sizeof(struct sprd_VAB_img_ver_t));

	if(imgver.magic != SPRD_IMGVER_MAGIC) {
#ifdef IMGVER_DEBUG
		printf("invalid sprd imgversion magic %x exp %x \n",
				imgver.magic, SPRD_IMGVER_MAGIC);
#endif
		return -1;
	} else {
		for(i = 0; i < 32; i++){
			vboot_ver_info->img_ver[i] = imgver.all_imgver[i];
		}
//		memcpy(vboot_ver_info->img_ver, imgver.all_imgver, AVB_MAX_NUMBER_OF_ROLLBACK_INDEX_LOCATIONS);
	}
#ifdef IMGVER_DEBUG
	for(ret = 0; ret < AVB_MAX_NUMBER_OF_ROLLBACK_INDEX_LOCATIONS; ret++) {
		printf("vboot_ver_info->img_ver[%d] = 0x%x\n", ret, vboot_ver_info->img_ver[ret]);
	}
#endif

	return 0;
}

int sprd_init_all_imgversion(uint8_t *rpmb_key)
{
    struct sprd_img_ver_t imgver;
    struct sprd_modem_img_ver_t modem_imgver;
    uint8_t data_wr[RPMB_DATA_SIZE]; //change data to 256-size,some emmc do not support size 512 at a time
    uint16_t block_ind;
    int ret;

    memset(data_wr, 0x0, sizeof(data_wr));
    memset(&imgver, 0x0, sizeof(imgver));
    imgver.magic = SPRD_IMGVER_MAGIC;
    memcpy((void *)data_wr, &imgver, sizeof(imgver));

    block_ind = get_sprdimgver_blk_ind();
    ret = rpmb_blk_write(data_wr, rpmb_key, block_ind);
    if(ret != 0) {
        printf("%s: init imgversion fail,rpmb write blk %d fail! ret %d \n", __func__, block_ind, ret);
        return ret;
    }
    printf("%s: init imgversion susseccful,rpmb write blk %d \n", __func__, block_ind);


    memset(data_wr, 0x0, sizeof(data_wr));
    memset(&modem_imgver, 0x0, sizeof(modem_imgver));
    modem_imgver.magic = SPRD_IMGVER_MAGIC;
    memcpy((void *)data_wr, &modem_imgver, sizeof(modem_imgver));

    block_ind = get_sprdmodemimgver_blk_ind();
    ret = rpmb_blk_write(data_wr, rpmb_key, block_ind);
    if(ret != 0) {
        printf("%s: init modemimgver fail,rpmb write blk %d fail! ret %d \n", __func__, block_ind, ret);
        return ret;
    }
    printf("%s: init modemimgver susseccful,rpmb write blk %d \n", __func__, block_ind);

    return 0;
}

