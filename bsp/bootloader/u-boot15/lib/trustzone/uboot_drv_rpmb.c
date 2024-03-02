/*
 * Copyright (c) 2013-2014, spreadtrum.com.
 *
 */

#include "uboot_sec_drv.h"
#include <mmc.h>
#include <sprd_rpmb.h>
#include <common.h>
#include <chipram_env.h>
#include <sprd_ufs.h>

#define RPMB_EKY_SIZE 32

DECLARE_GLOBAL_DATA_PTR;
static u64 rpmb_size __attribute__((aligned(4096)));
static int is_rpmb_key __attribute__((aligned(4096)));
static u8 check_rpmb_key_pac[RPMB_DATA_FRAME_SIZE] __attribute__((aligned(4096)));
static u8 rpmb_key[RPMB_EKY_SIZE] __attribute__((aligned(4096)));


int rpmb_blk_write(char *write_data, uint8_t *key, uint16_t blk_index)
{
	int ret = 0;

#ifdef CONFIG_MMC
	if (gd->boot_device == BOOT_DEVICE_EMMC)
		ret = (int)mmc_rpmb_blk_write(write_data, key, blk_index);
#endif
#ifdef CONFIG_UFS
	if (gd->boot_device == BOOT_DEVICE_UFS)
		ret = (int)ufs_rpmb_blk_write(write_data, key, blk_index);
#endif

	return ret;

}
int rpmb_blk_read(char *blk_data, uint16_t blk_index, uint8_t block_count)
{
	int ret = 0;

#ifdef CONFIG_MMC
	if (gd->boot_device == BOOT_DEVICE_EMMC)
		ret = (int)mmc_rpmb_blk_read(blk_data, blk_index, block_count);
#endif
#ifdef CONFIG_UFS
	if (gd->boot_device == BOOT_DEVICE_UFS)
		ret = (int)ufs_rpmb_blk_read(blk_data, blk_index, block_count);
#endif

	return ret;
}

int check_rpmb_key(uint8_t *package, int package_size)
{
	int ret = 0;

#ifdef CONFIG_MMC
	if (gd->boot_device == BOOT_DEVICE_EMMC)
		ret = check_mmc_rpmb_key(package, package_size);
#endif
#ifdef CONFIG_UFS
	if (gd->boot_device == BOOT_DEVICE_UFS)
		ret = check_ufs_rpmb_key(package, package_size);
#endif

	return ret;
}

int is_wr_rpmb_key(void)
{
	int ret = 0;

#ifdef CONFIG_MMC
	if (gd->boot_device == BOOT_DEVICE_EMMC)
		ret = is_wr_mmc_rpmb_key();
#endif
#ifdef CONFIG_UFS
	if (gd->boot_device == BOOT_DEVICE_UFS)
		ret = is_wr_ufs_rpmb_key();
#endif

	return ret;
}

int uboot_set_rpmb_size()
{
	int ret = 0;
#ifdef CONFIG_MMC
	if (gd->boot_device == BOOT_DEVICE_EMMC)
		rpmb_size = emmc_get_capacity(PARTITION_RPMB);
#endif
#ifdef CONFIG_UFS
	if (gd->boot_device == BOOT_DEVICE_UFS) {
		ret = prepare_rpmb_lu();
		if (ret != UFS_SUCCESS) {
			printf("%s: prepare rpmb lu failed ret =%d\n", __func__, ret);
			return -1;
		}
		rpmb_size = (1 << rpmb_lu_info.log2blksz) *
			    (rpmb_lu_info.blkcnt);
	}
#endif
	printf("%s: rpmb size %lld\n", __func__, rpmb_size);
	smc_param *param = tee_common_call(FUNCTYPE_SET_RPMB_SIZE,
					   (uint32_t)(&rpmb_size),
					   sizeof(rpmb_size));

    return param->a0;
}


int uboot_is_wr_rpmb_key()
{
	is_rpmb_key = -1;
	is_rpmb_key = is_wr_rpmb_key();

	if (0 == is_rpmb_key) {
		printf("%s rpmb unwritten, call tos \n", __func__);
		smc_param *param = tee_common_call(FUNCTYPE_IS_WR_RPMB_KEY,
						   (uint32_t)(&is_rpmb_key),
						   sizeof(is_rpmb_key));
		return param->a0;
	} else {
		return -1;
	}
}

int uboot_check_rpmb_key()
{
	int ret = 0;

	ret = check_rpmb_key(check_rpmb_key_pac, RPMB_DATA_FRAME_SIZE);
	if (0 == ret) {
		printf("%s get rpmb package, call tos to check rpmb key \n", __func__);
		smc_param *param = tee_common_call(FUNCTYPE_CHECK_RPMB_KEY,
						   (uint32_t)check_rpmb_key_pac,
						   RPMB_DATA_FRAME_SIZE);
	return param->a0;
	} else {
		printf("%s get rpmb package fail\n", __func__);
		return -1;
	}
}

int uboot_set_rpmb_device_type()
{
	unsigned long rpmb_device_type = BOOT_DEVICE_EMMC;
#ifdef CONFIG_MMC
	if (gd->boot_device == BOOT_DEVICE_EMMC) {
		rpmb_device_type = gd->boot_device;
	}
#endif
#ifdef CONFIG_UFS
	if (gd->boot_device == BOOT_DEVICE_UFS) {
		rpmb_device_type = gd->boot_device;
	}
#endif
	smc_param *param = tee_common_call(FUNCTYPE_SET_RPMB_DEVICE_TYPE,
					   (uint32_t)(rpmb_device_type),
					   sizeof(rpmb_device_type));

    return param->a0;
}

/*
*reutrn 0 success
*/
int uboot_write_rpmb_key(u8 *key)
{
	smc_param *param = NULL;
	int rc = 0;


	memset((void*)rpmb_key,  0, sizeof(rpmb_key));
	param = tee_common_call(FUNCTYPE_GET_RPMB_KEY, (uint32_t)(rpmb_key), sizeof(rpmb_key));

	if (NULL == param) {
		printf("%s: tee_common_call faile\n", __func__);
		return -1;
	}

	if (0 != param->a0) {
		printf("%s: get rpmb key fail %d.\n", __func__, param->a0);
		return param->a0;
	}

	if (0 != is_wr_rpmb_key()) {
		printf("%s: rpmb key has been written.\n", __func__);
		if (key != NULL) {
			memcpy(key, rpmb_key, sizeof(rpmb_key));
		}
		return 0;
	}


#ifdef CONFIG_MMC
	if (gd->boot_device == BOOT_DEVICE_EMMC)
		rc = mmc_rpmb_write_key(rpmb_key, sizeof(rpmb_key));
#endif
#ifdef CONFIG_UFS
	if (gd->boot_device == BOOT_DEVICE_UFS)
		rc = ufs_rpmb_write_key(rpmb_key, sizeof(rpmb_key));
#endif

	if (0 != rc) {
		printf("%s: write rpmb key fail %d.\n", __func__, rc);
	} else {
		if (key != NULL) {
			memcpy(key, rpmb_key, sizeof(rpmb_key));
		}
	}

	memset((void*)rpmb_key,  0, sizeof(rpmb_key));
	printf("%s: rpmb key write successful.\n", __func__);

	return rc;
}

