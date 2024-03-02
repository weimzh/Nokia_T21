/*
 * Copyright 2008, Freescale Semiconductor, Inc
 * Andy Fleming
 *
 * Based vaguely on the Linux code
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <common.h>
#include <command.h>
#include <linux/errno.h>
#include <mmc.h>
#include <part.h>
#include <malloc.h>
#include <linux/list.h>
#include <div64.h>
#include "mmc_private.h"
#include <asm/arch/sdio_cfg.h>
#include <asm/arch/common.h>

/* Set block count limit because of 16 bit register limit on some hardware*/
#ifndef CONFIG_SYS_MMC_MAX_BLK_COUNT
#define CONFIG_SYS_MMC_MAX_BLK_COUNT 65535
#endif


static struct list_head mmc_devices;
static int cur_dev_num = -1;
static uint max_erase_size = 0x80000000;//2G Byte

//+hz added,the baiwei 128GB emmc protection problem
int is_baiwei_128GB_emmc = 0;
//-hz added,the baiwei 128GB emmc protection problem
	
struct sdio_base_info *emmc_info;

//add for protect protect_data partition
int mmc_get_wp_grp_size(void)
{
	struct mmc *mmc = find_mmc_device(EMMC);

	if (!mmc) {
		errorf("mmc is null!\n");
		return 0;
	}

	return mmc->hc_wp_grp_size;
}
//add for protect protect_data partition end

int __weak board_mmc_getwp(struct mmc *mmc)
{
	return -1;
}

int mmc_getwp(struct mmc *mmc)
{
	int wp;

	wp = board_mmc_getwp(mmc);

	if (wp < 0) {
		if (mmc->cfg->ops->getwp)
			wp = mmc->cfg->ops->getwp(mmc);
		else
			wp = 0;
	}

	return wp;
}

__weak int board_mmc_getcd(struct mmc *mmc)
{
	return -1;
}

int mmc_send_cmd(struct mmc *mmc, struct mmc_cmd *cmd, struct mmc_data *data)
{
	int ret;

#ifdef CONFIG_MMC_TRACE
	int i;
	u8 *ptr;

	printf("CMD_SEND:%d\n", cmd->cmdidx);
	printf("\t\tARG\t\t\t 0x%08X\n", cmd->cmdarg);
	ret = mmc->cfg->ops->send_cmd(mmc, cmd, data);
	switch (cmd->resp_type) {
	case MMC_RSP_NONE:
		printf("\t\tMMC_RSP_NONE\n");
		break;
	case MMC_RSP_R1:
		printf("\t\tMMC_RSP_R1,5,6,7 \t 0x%08X\n", cmd->response[0]);
		break;
	case MMC_RSP_R1b:
		printf("\t\tMMC_RSP_R1b\t\t 0x%08X\n", cmd->response[0]);
		break;
	case MMC_RSP_R2:
		printf("\t\tMMC_RSP_R2\t\t 0x%08X\n", cmd->response[0]);
		printf("\t\t          \t\t 0x%08X\n", cmd->response[1]);
		printf("\t\t          \t\t 0x%08X\n", cmd->response[2]);
		printf("\t\t          \t\t 0x%08X\n", cmd->response[3]);
		printf("\n");
		printf("\t\t\t\t\tDUMPING DATA\n");
		for (i = 0; i < 4; i++) {
			int j;
			printf("\t\t\t\t\t%03d - ", i * 4);
			ptr = (u8 *)&cmd->response[i];
			ptr += 3;
			for (j = 0; j < 4; j++)
				printf("%02X ", *ptr--);
			printf("\n");
		}
		break;
	case MMC_RSP_R3:
		printf("\t\tMMC_RSP_R3,4\t\t 0x%08X\n", cmd->response[0]);
		break;
	default:
		printf("\t\tERROR MMC rsp not supported\n");
		break;
	}
#else
	ret = mmc->cfg->ops->send_cmd(mmc, cmd, data);
#endif
	return ret;
}

int mmc_send_status(struct mmc *mmc, int timeout)
{
	struct mmc_cmd cmd;
	int err, retries = 20;
#ifdef CONFIG_MMC_TRACE
	int status;
#endif

	cmd.cmdidx = MMC_CMD_SEND_STATUS;
	cmd.resp_type = MMC_RSP_R1;
	if (!mmc_host_is_spi(mmc))
		cmd.cmdarg = mmc->rca << 16;

	while (1) {
		err = mmc_send_cmd(mmc, &cmd, NULL);
		if (!err) {
			if ((cmd.response[0] & MMC_STATUS_RDY_FOR_DATA) &&
			    (cmd.response[0] & MMC_STATUS_CURR_STATE) !=
			     MMC_STATE_PRG)
				break;
			else if (cmd.response[0] & MMC_STATUS_MASK) {
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
				errorf("Status Error: 0x%08x\n",
				       cmd.response[0]);
#endif
				return COMM_ERR;
			}
		} else if (--retries < 0) {
			return err;
		}

		if (timeout-- <= 0)
			break;

		udelay(1000);
	}

#ifdef CONFIG_MMC_TRACE
	status = (cmd.response[0] & MMC_STATUS_CURR_STATE) >> 9;
	debugf("CURR STATE:%d\n", status);
#endif
	if (timeout <= 0) {
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
		debugf("Timeout waiting card ready\n");
#endif
		return TIMEOUT;
	}
	if (cmd.response[0] & MMC_STATUS_SWITCH_ERROR)
		return SWITCH_ERR;

	return 0;
}

int mmc_set_blocklen(struct mmc *mmc, int len)
{
	struct mmc_cmd cmd;

	if (mmc->ddr_mode)
		return 0;

	cmd.cmdidx = MMC_CMD_SET_BLOCKLEN;
	cmd.resp_type = MMC_RSP_R1;
	cmd.cmdarg = len;

	return mmc_send_cmd(mmc, &cmd, NULL);
}

struct mmc *find_mmc_device(int dev_num)
{
	struct mmc *m;
	struct list_head *entry;

	list_for_each(entry, &mmc_devices) {
		m = list_entry(entry, struct mmc, link);

		if (m->block_dev.dev == dev_num)
			return m;
	}

#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
	printf("%s: Don't find %s card.\n", __func__, dev_num ? "sd" : "emmc");
#endif

	return NULL;
}

static ulong mmc_erase_t(struct mmc *mmc, ulong start,
			 lbaint_t blkcnt, uint erase_type)
{
	struct mmc_cmd cmd;
	ulong end;
	int err, start_cmd, end_cmd;

	if (mmc->high_capacity) {
		end = start + blkcnt - 1;
	} else {
		end = (start + blkcnt - 1) * mmc->write_bl_len;
		start *= mmc->write_bl_len;
	}

	if (IS_SD(mmc)) {
		start_cmd = SD_CMD_ERASE_WR_BLK_START;
		end_cmd = SD_CMD_ERASE_WR_BLK_END;
	} else {
		start_cmd = MMC_CMD_ERASE_GROUP_START;
		end_cmd = MMC_CMD_ERASE_GROUP_END;
	}

	cmd.cmdidx = start_cmd;
	cmd.cmdarg = start;
	cmd.resp_type = MMC_RSP_R1;

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err)
		goto err_out;

	cmd.cmdidx = end_cmd;
	cmd.cmdarg = end;

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err)
		goto err_out;

	cmd.cmdidx = MMC_CMD_ERASE;
	cmd.cmdarg = erase_type;
	cmd.resp_type = MMC_RSP_R1b;

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err)
		goto err_out;

	return 0;

err_out:
	puts("mmc erase failed\n");
	return err;
}

static int mmc_switch(struct mmc *mmc, u8 set, u8 index, u8 value)
{
	struct mmc_cmd cmd;
	int timeout = 10000;
	int ret;

	cmd.cmdidx = MMC_CMD_SWITCH;
	cmd.resp_type = MMC_RSP_R1b;
	cmd.cmdarg = (MMC_SWITCH_MODE_WRITE_BYTE << 24) |
			(index << 16) | (value << 8);

	ret = mmc_send_cmd(mmc, &cmd, NULL);
	if (index == 171)
		printf("%s: send EXT_CSD_USER_WP return %d\n", __func__, ret);

	/* Waiting for the ready status */
	if (!ret)
		ret = mmc_send_status(mmc, timeout);
	if (index == 171)
		printf("%s: send status return %d\n", __func__, ret);

	return ret;
}

static int mmc_send_ext_csd(struct mmc *mmc, u8 *ext_csd)
{
	struct mmc_cmd cmd;
	struct mmc_data data;
	int err;

	/* Get the Card Status Register */
	cmd.cmdidx = MMC_CMD_SEND_EXT_CSD;
	cmd.resp_type = MMC_RSP_R1;
	cmd.cmdarg = 0;

	data.dest = (char *)ext_csd;
	data.blocks = 1;
	data.blocksize = MMC_MAX_BLOCK_LEN;
	data.flags = MMC_DATA_READ;

	err = mmc_send_cmd(mmc, &cmd, &data);
	debugf("mmc_send_ext_csd=%d\n", err);

	return err;
}

#ifdef CONFIG_EMMC_WP
/*
 * mmc_set_pwr_wp - set block-oriented emmc write protection.
 * @dev_num: must be 0, instead of emmc device
 * @start: a 32 bit sector(512 B) data address
 * @grp_cnt: the number of write protect group size (grp_cnt <= 32)
 */
ulong mmc_set_pwr_wp(int dev_num, lbaint_t start, int grp_cnt)
{
	int err = 0;
	struct mmc_cmd cmd;
	struct mmc_data data;
	int i;
	lbaint_t cur_start = start;
	ALLOC_CACHE_ALIGN_BUFFER(u8, wp_status, 4);
	ALLOC_CACHE_ALIGN_BUFFER(u8, wp_type, 8);
	unsigned long long actual_type = 0, expected_type = 0;
	uint wp_bits_sts = 0;

	struct mmc *mmc = find_mmc_device(dev_num);
	if (!mmc) {
		printf("%s: no emmc device\n", __func__);
		return -1;
	}

	if (!mmc->wp_enable) {
		printf("emmc power-up write protection never be eanbled\n");
		return -1;
	}

	printf("%s: write protection start addr: 0x" LBAF ", group count: %d\n",
	       __func__, cur_start, grp_cnt);
	for (i = 0; i < grp_cnt; i++) {
		cmd.cmdidx = MMC_CMD_SET_WR_PROT;
		cmd.cmdarg = cur_start;
		cmd.resp_type = MMC_RSP_R1b;
		if (mmc_send_cmd(mmc, &cmd, NULL))
			printf("%s: send CMD%d fail\n", __func__, cmd.cmdidx);

		cur_start += mmc->hc_wp_grp_size;
	}

	cmd.cmdidx = MMC_CMD_SEND_WR_PROT;
	cmd.cmdarg = start;
	cmd.resp_type = MMC_RSP_R1;
	data.dest = (char *)wp_status;
	data.blocks = 1;
	data.blocksize = 4;
	data.flags = MMC_DATA_READ;
	err = mmc_send_cmd(mmc, &cmd, &data);
	if (err)
		printf("%s: send CMD%d fail, return %d\n",
		       __func__, cmd.cmdidx, err);
	for (i = 0; i < 4; i++)
		wp_bits_sts = (wp_bits_sts << 8) + (u8)wp_status[i];
	printf("%s: the status of write protection bits: 0x%x\n",
	       __func__, wp_bits_sts);

	cmd.cmdidx = MMC_CMD_SEND_WR_PROT_TYPE;
	cmd.cmdarg = start;
	cmd.resp_type = MMC_RSP_R1;
	data.dest = (char *)wp_type;
	data.blocks = 1;
	data.blocksize = 8;
	data.flags = MMC_DATA_READ;
	err = mmc_send_cmd(mmc, &cmd, &data);
	if (err)
		printf("%s: send CMD%d fail, return %d\n",
		       __func__, cmd.cmdidx, err);

	for (i = 0; i < 8; i++)
		actual_type = (actual_type << 8) + (u8)wp_type[i];
	printf("%s: the really type of write protection grout: 0x%llx\n",
	       __func__, actual_type);

	for (i = 0; i < grp_cnt; i++)
		expected_type = (expected_type << 2) + 0x2;
	printf("%s: the expected type of write protection group: 0x%llx\n",
	       __func__, expected_type);

	if (actual_type != expected_type) {
		printf("%s: power-on write protection set failed\n", __func__);
		return -1;
	}

	return 0;
}
#endif

unsigned long mmc_berase(int dev_num, lbaint_t start, lbaint_t blkcnt)
{
	int err = 0;
	struct mmc *mmc = find_mmc_device(dev_num);
	lbaint_t blk = 0, blk_r = 0;
	int timeout = 1000;
	lbaint_t max_erase_blk = 0;
	if (!mmc)
		return -1;

	max_erase_blk = max_erase_size / mmc->read_bl_len;

	if (start % mmc->erase_grp_size) {
		blk_r = (blkcnt < (mmc->erase_grp_size -
			start % mmc->erase_grp_size)) ? blkcnt :
			(mmc->erase_grp_size - start % mmc->erase_grp_size);
		err = mmc_erase_t(mmc, start, blk_r, 1);
		if (err)
			return -1;
		blk += blk_r;
		/* Waiting for the ready status */
		if (mmc_send_status(mmc, timeout))
			return 0;
	}

	while (blk < blkcnt) {
		blk_r = ((blkcnt - blk) >= mmc->erase_grp_size) ?
			((blkcnt - blk) & ~(mmc->erase_grp_size - 1)) : (blkcnt - blk);
		if ((blkcnt - blk) >= mmc->erase_grp_size){
			if(blk_r > max_erase_blk){
				err = mmc_erase_t(mmc, start + blk, max_erase_blk, 0);
				blk_r = max_erase_blk;
			}else
				err = mmc_erase_t(mmc, start + blk, blk_r, 0);
		}else
			err = mmc_erase_t(mmc, start + blk, blk_r, 1);
		if (err)
			break;
		blk += blk_r;

		/* Waiting for the ready status */
		if (mmc_send_status(mmc, timeout))
			return 0;
	}

	return blk;
}

static ulong mmc_write_blocks(struct mmc *mmc,
	lbaint_t start, lbaint_t blkcnt, const void *src)
{
	struct mmc_cmd cmd;
	struct mmc_data data;
	int timeout = 1000;

	if ((start + blkcnt) > mmc->block_dev.lba) {
		debugf("MMC: block number 0x" LBAF " exceeds max(0x" LBAF ")\n",
		       start + blkcnt, mmc->block_dev.lba);
		return 0;
	}

	if (blkcnt == 0)
		return 0;
	else if (blkcnt == 1)
		cmd.cmdidx = MMC_CMD_WRITE_SINGLE_BLOCK;
	else
		cmd.cmdidx = MMC_CMD_WRITE_MULTIPLE_BLOCK;

	if (mmc->high_capacity)
		cmd.cmdarg = start;
	else
		cmd.cmdarg = start * mmc->write_bl_len;

	cmd.resp_type = MMC_RSP_R1;

	data.src = src;
	data.blocks = blkcnt;
	data.blocksize = mmc->write_bl_len;
	data.flags = MMC_DATA_WRITE;

	if (mmc_send_cmd(mmc, &cmd, &data)) {
		errorf("%s failed\n", __func__);
		return 0;
	}

	/*
	 * SPI multiblock writes terminate using a special
	 * token, not a STOP_TRANSMISSION request.
	 */
	if (!mmc_host_is_spi(mmc) && blkcnt > 1) {
		cmd.cmdidx = MMC_CMD_STOP_TRANSMISSION;
		cmd.cmdarg = 0;
		cmd.resp_type = MMC_RSP_R1b;
		if (mmc_send_cmd(mmc, &cmd, NULL)) {
			errorf("mmc fail to send stop cmd\n");
			return 0;
		}
	}

	/* Waiting for the ready status */
	if (mmc_send_status(mmc, timeout))
		return 0;

	return blkcnt;
}

ulong mmc_bwrite(int dev_num, lbaint_t start, lbaint_t blkcnt, const void *src)
{
	lbaint_t cur, blocks_todo = blkcnt;

	struct mmc *mmc = find_mmc_device(dev_num);
	if (!mmc)
		return 0;

	if (mmc_set_blocklen(mmc, mmc->write_bl_len))
		return 0;

	do {
		cur = (blocks_todo > mmc->cfg->b_max) ?
			mmc->cfg->b_max : blocks_todo;
		if (mmc_write_blocks(mmc, start, cur, src) != cur)
			return 0;
		blocks_todo -= cur;
		start += cur;
		src += cur * mmc->write_bl_len;
	} while (blocks_todo > 0);

	return blkcnt;
}

static ulong mmc_write_blocks_backstage(struct mmc *mmc,
	lbaint_t start, lbaint_t blkcnt, const void *src)
{
	struct mmc_cmd cmd;
	struct mmc_data data;
	if ((start + blkcnt) > mmc->block_dev.lba) {
		errorf("MMC: block number 0x" LBAF " exceeds max(0x" LBAF ")\n",
		       start + blkcnt, mmc->block_dev.lba);
		return 0;
	}
	if (blkcnt == 0)
		return 0;
	else if (blkcnt == 1)
		cmd.cmdidx = MMC_CMD_WRITE_SINGLE_BLOCK;
	else
		cmd.cmdidx = MMC_CMD_WRITE_MULTIPLE_BLOCK;
	if (mmc->high_capacity)
		cmd.cmdarg = start;
	else
		cmd.cmdarg = start * mmc->write_bl_len;

	cmd.resp_type = MMC_RSP_R1;

	data.src = src;
	data.blocks = blkcnt;
	data.blocksize = mmc->write_bl_len;
	data.flags = MMC_DATA_WRITE;
	if (sdhci_send_command_backstage(mmc, &cmd, &data)) {
		errorf("mmc backstage write failed\n");
		return 0;
	}
	return blkcnt;
}

ulong mmc_query_bwrite_backstage(int dev_num, lbaint_t blkcnt, const void *src)
{
	int timeout = 1000;
	//struct mmc_data data;
	//struct mmc_cmd cmd;

	if (blkcnt == 0)
		return 0;
	struct mmc *mmc = find_mmc_device(dev_num);
	if (!mmc) {
		errorf("mmc_query_bwrite_backstage mmc probe fail\n");
		return 0;
	}
#if 0/*there is no need of this action after v6*/
	data.src = src;
	data.blocks = blkcnt;
	data.blocksize = mmc->write_bl_len;
	data.flags = MMC_DATA_WRITE;

	if (sdhci_query_command_backstage(mmc, &data)) {
		errorf("mmc query write result failed\n");
		return 0;
	}
	if (!mmc_host_is_spi(mmc) && blkcnt > 1) {
		cmd.cmdidx = MMC_CMD_STOP_TRANSMISSION;
		cmd.cmdarg = 0;
		cmd.resp_type = MMC_RSP_R1b;
		if (mmc_send_cmd(mmc, &cmd, NULL)) {
			errorf("mmc failed to send stop cmd\n");
			return 0;
		}
	}
#endif
	if (mmc_send_status(mmc, timeout)) {
		errorf("mmc failed to send status cmd\n");
		return 0;
	}

	return blkcnt;
}

ulong mmc_bwrite_backstage(int dev_num, lbaint_t start,
	lbaint_t blkcnt, const void *src)
{
	lbaint_t cur = blkcnt;

	struct mmc *mmc = find_mmc_device(dev_num);
	if (!mmc)
		return 0;

	if (mmc_set_blocklen(mmc, mmc->write_bl_len))
		return 0;

	if (blkcnt > mmc->cfg->b_max) {
		errorf("%s can not support more than <%d> blocks\n",
		       __func__, mmc->cfg->b_max);
		return 0;
	}
	if (mmc_write_blocks_backstage(mmc, start, blkcnt, src) != cur)
		return 0;

	return blkcnt;
}

static int mmc_read_blocks(struct mmc *mmc, void *dst, lbaint_t start,
			   lbaint_t blkcnt)
{
	struct mmc_cmd cmd;
	struct mmc_data data;

	if (blkcnt > 1)
		cmd.cmdidx = MMC_CMD_READ_MULTIPLE_BLOCK;
	else
		cmd.cmdidx = MMC_CMD_READ_SINGLE_BLOCK;

	if (mmc->high_capacity)
		cmd.cmdarg = start;
	else
		cmd.cmdarg = start * mmc->read_bl_len;

	cmd.resp_type = MMC_RSP_R1;

	data.dest = dst;
	data.blocks = blkcnt;
	data.blocksize = mmc->read_bl_len;
	data.flags = MMC_DATA_READ;

	if (mmc_send_cmd(mmc, &cmd, &data))
		return 0;

	if (blkcnt > 1) {
		cmd.cmdidx = MMC_CMD_STOP_TRANSMISSION;
		cmd.cmdarg = 0;
		cmd.resp_type = MMC_RSP_R1b;
		if (mmc_send_cmd(mmc, &cmd, NULL)) {
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
			errorf("mmc fail to send stop cmd\n");
#endif
			return 0;
		}
	}

	return blkcnt;
}

static ulong mmc_bread(int dev_num, lbaint_t start, lbaint_t blkcnt, void *dst)
{
	lbaint_t cur, blocks_todo = blkcnt;

	if (blkcnt == 0)
		return 0;

	struct mmc *mmc = find_mmc_device(dev_num);
	if (!mmc)
		return 0;

	if ((start + blkcnt) > mmc->block_dev.lba) {
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
		debugf("MMC: block number 0x" LBAF " exceeds max(0x" LBAF ")\n",
		       start + blkcnt, mmc->block_dev.lba);
#endif
		return 0;
	}

	if (mmc_set_blocklen(mmc, mmc->read_bl_len))
		return 0;

	do {
		cur = (blocks_todo > mmc->cfg->b_max) ?
			mmc->cfg->b_max : blocks_todo;
		if (mmc_read_blocks(mmc, dst, start, cur) != cur)
			return 0;
		blocks_todo -= cur;
		start += cur;
		dst += cur * mmc->read_bl_len;
	} while (blocks_todo > 0);

	return blkcnt;
}

static int mmc_go_idle(struct mmc *mmc)
{
	struct mmc_cmd cmd;
	int err;

	udelay(1000);

	cmd.cmdidx = MMC_CMD_GO_IDLE_STATE;
	cmd.cmdarg = 0;
	cmd.resp_type = MMC_RSP_NONE;

	err = mmc_send_cmd(mmc, &cmd, NULL);

	if (err)
		return err;

	udelay(2000);

	return 0;
}

static int sd_send_op_cond(struct mmc *mmc)
{
	int timeout = 1000;
	int err;
	struct mmc_cmd cmd;

	while (1) {
		cmd.cmdidx = MMC_CMD_APP_CMD;
		cmd.resp_type = MMC_RSP_R1;
		cmd.cmdarg = 0;

		err = mmc_send_cmd(mmc, &cmd, NULL);

		if (err)
			return err;

		cmd.cmdidx = SD_CMD_APP_SEND_OP_COND;
		cmd.resp_type = MMC_RSP_R3;

		/*
		 * Most cards do not answer if some reserved bits
		 * in the ocr are set. However, Some controller
		 * can set bit 7 (reserved for low voltages), but
		 * how to manage low voltages SD card is not yet
		 * specified.
		 */
		cmd.cmdarg = mmc_host_is_spi(mmc) ? 0 :
			(mmc->cfg->voltages & 0xff8000);

		if (mmc->version == SD_VERSION_2)
			cmd.cmdarg |= OCR_HCS;

		err = mmc_send_cmd(mmc, &cmd, NULL);

		if (err)
			return err;

		if (cmd.response[0] & OCR_BUSY)
			break;

		if (timeout-- <= 0)
			return UNUSABLE_ERR;

		udelay(1000);
	}

	if (mmc->version != SD_VERSION_2)
		mmc->version = SD_VERSION_1_0;

	if (mmc_host_is_spi(mmc)) {	/* read OCR for spi */
		cmd.cmdidx = MMC_CMD_SPI_READ_OCR;
		cmd.resp_type = MMC_RSP_R3;
		cmd.cmdarg = 0;

		err = mmc_send_cmd(mmc, &cmd, NULL);

		if (err)
			return err;
	}

	mmc->ocr = cmd.response[0];

	mmc->high_capacity = ((mmc->ocr & OCR_HCS) == OCR_HCS);
	mmc->rca = 0;

	return 0;
}

static int mmc_send_op_cond_iter(struct mmc *mmc, int use_arg)
{
	struct mmc_cmd cmd;
	int err;

	cmd.cmdidx = MMC_CMD_SEND_OP_COND;
	cmd.resp_type = MMC_RSP_R3;
	cmd.cmdarg = 0;
	if (use_arg && !mmc_host_is_spi(mmc))
		cmd.cmdarg = OCR_HCS |
			(mmc->cfg->voltages &
			(mmc->ocr & OCR_VOLTAGE_MASK)) |
			(mmc->ocr & OCR_ACCESS_MODE);

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err)
		return err;
	mmc->ocr = cmd.response[0];
	return 0;
}

static int mmc_send_op_cond(struct mmc *mmc)
{
	int err, i;

	/* Some cards seem to need this */
	mmc_go_idle(mmc);

	/* Asking to the card its capabilities */
	for (i = 0; i < 100; i++) {
		err = mmc_send_op_cond_iter(mmc, i != 0);
		if (err)
			return err;

		/* exit if not busy (flag seems to be inverted) */
		if (mmc->ocr & OCR_BUSY)
			break;
		mdelay(10);
	}
	mmc->op_cond_pending = 1;

	return 0;
}

static int mmc_complete_op_cond(struct mmc *mmc)
{
	struct mmc_cmd cmd;
	int timeout = 1000;
	uint start;
	int err;

	mmc->op_cond_pending = 0;
	if (!(mmc->ocr & OCR_BUSY)) {
		start = get_timer(0);
		while (1) {
			err = mmc_send_op_cond_iter(mmc, 1);
			if (err)
				return err;
			if (mmc->ocr & OCR_BUSY)
				break;
			if (get_timer(start) > timeout)
				return UNUSABLE_ERR;
			udelay(100);
		}
	}

	if (mmc_host_is_spi(mmc)) {	/* read OCR for spi */
		cmd.cmdidx = MMC_CMD_SPI_READ_OCR;
		cmd.resp_type = MMC_RSP_R3;
		cmd.cmdarg = 0;

		err = mmc_send_cmd(mmc, &cmd, NULL);

		if (err)
			return err;

		mmc->ocr = cmd.response[0];
	}

	mmc->version = MMC_VERSION_UNKNOWN;

	mmc->high_capacity = ((mmc->ocr & OCR_HCS) == OCR_HCS);
	mmc->rca = 1;

	return 0;
}

static int mmc_change_freq(struct mmc *mmc)
{
	ALLOC_CACHE_ALIGN_BUFFER(u8, ext_csd, MMC_MAX_BLOCK_LEN);
	char cardtype;
	int err;

	mmc->card_caps = 0;

	if (mmc_host_is_spi(mmc))
		return 0;

	/* Only version 4 supports high-speed */
	if (mmc->version < MMC_VERSION_4)
		return 0;
	mmc->card_caps |= MMC_MODE_4BIT | MMC_MODE_8BIT;

/*
 * Somebody found that the value of ext_csd couldn't be obtained in
 * FPGA platform by calling mmc_send_ext_csd() one time. However,
 * this phenomenon never happen in VP or real phone platform. So we
 * add the macro *CONFIG_FPGA* to handle it.
 * If anybody find the code is redandunt in FPGA, please remove it.
 */
#ifndef CONFIG_FPGA
	err = mmc_send_ext_csd(mmc, ext_csd);
#else
	int temp = 0;
	/* check  ext_csd version and capacity */
	for (temp = 0; temp < 10; temp++) {
		err = mmc_send_ext_csd(mmc, ext_csd);
		if (!err)
			break;
	}

	if (temp == 10) {
		errorf("get  ext_csd  error\n");
		err = -1;
	}
#endif
	if (err)
		return err;

	cardtype = ext_csd[EXT_CSD_CARD_TYPE] & 0xf;

	err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL, EXT_CSD_HS_TIMING, 1);

	if (err)
		return err == SWITCH_ERR ? 0 : err;

	/* Now check to see that it worked */
#ifndef CONFIG_FPGA
	err = mmc_send_ext_csd(mmc, ext_csd);
#else
	/* check ext_csd version and capacity */
	for (temp = 0; temp < 10; temp++) {
		err = mmc_send_ext_csd(mmc, ext_csd);
		if (!err)
			break;
	}

	if (temp == 10) {
		errorf("%s get ext_csd error\n", __func__);
		err = -1;
	}
#endif
	if (err)
		return err;

	/* No high-speed support */
	if (!ext_csd[EXT_CSD_HS_TIMING])
		return 0;

	/* High Speed is set, there are two types: 52MHz and 26MHz */
	if (cardtype & EXT_CSD_CARD_TYPE_52) {
		if (cardtype & EXT_CSD_CARD_TYPE_DDR_1_8V)
			mmc->card_caps |= MMC_MODE_DDR_52MHz;
		mmc->card_caps |= MMC_MODE_HS_52MHz | MMC_MODE_HS;
	} else {
		mmc->card_caps |= MMC_MODE_HS;
	}
	debugf("emmc type:%d card_caps:0x%x\n", cardtype, mmc->card_caps);

	return 0;
}

static int mmc_set_capacity(struct mmc *mmc, int part_num)
{
	debugf("capacity -user: 0x%llx, -boot: 0x%llx, -rpmb: 0x%llx\n",
	       mmc->capacity_user, mmc->capacity_boot, mmc->capacity_rpmb);

	switch (part_num) {
	case 0:
		mmc->capacity = mmc->capacity_user;
		break;
	case 1:
	case 2:
		mmc->capacity = mmc->capacity_boot;
		break;
	case 3:
		mmc->capacity = mmc->capacity_rpmb;
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		mmc->capacity = mmc->capacity_gp[part_num - 4];
		break;
	default:
		return -1;
	}

	mmc->block_dev.lba = lldiv(mmc->capacity, mmc->read_bl_len);

	return 0;
}

int mmc_select_hwpart(int dev_num, int hwpart)
{
	struct mmc *mmc = find_mmc_device(dev_num);
	int ret;

	if (!mmc)
		return -ENODEV;

	if (mmc->part_num == hwpart)
		return 0;

	if (mmc->part_config == MMCPART_NOAVAILABLE) {
		printf("Card doesn't support part_switch\n");
		return -EMEDIUMTYPE;
	}

	ret = mmc_switch_part(dev_num, hwpart);
	if (ret)
		return ret;

	mmc->part_num = hwpart;

	return 0;
}


int mmc_switch_part(int dev_num, unsigned int part_num)
{
	struct mmc *mmc = find_mmc_device(dev_num);
	int ret;

	if (!mmc)
		return -1;

/*
 * We must write EXT_CSD_BOOT_PARTITION_ENABLE to EXT_CSD_PART_CONF,
 * if not, the device can't boot partition 1.
 */
	ret = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL, EXT_CSD_PART_CONF,
			(mmc->part_config & ~PART_ACCESS_MASK) |
			(part_num & PART_ACCESS_MASK) |
			EXT_CSD_BOOT_PARTITION_ENABLE);

	/*
	 * Set the capacity if the switch succeeded or was intended
	 * to return to representing the raw device.
	 */
	if ((ret == 0) || ((ret == -ENODEV) && (part_num == 0)))
		ret = mmc_set_capacity(mmc, part_num);

	return ret;
}

int mmc_hwpart_config(struct mmc *mmc,
		      const struct mmc_hwpart_conf *conf,
		      enum mmc_hwpart_conf_mode mode)
{
	u8 part_attrs = 0;
	u32 enh_size_mult;
	u32 enh_start_addr;
	u32 gp_size_mult[4];
	u32 max_enh_size_mult;
	u32 tot_enh_size_mult = 0;
	u8 wr_rel_set;
	int i, pidx, err;
	ALLOC_CACHE_ALIGN_BUFFER(u8, ext_csd, MMC_MAX_BLOCK_LEN);

	if (mode > MMC_HWPART_CONF_COMPLETE)
		return -EINVAL;

	if (IS_SD(mmc) || (mmc->version < MMC_VERSION_4_41)) {
		printf("eMMC >= 4.4 required for enhanced user data area\n");
		return -EMEDIUMTYPE;
	}

	if (!(mmc->part_support & PART_SUPPORT)) {
		printf("Card does not support partitioning\n");
		return -EMEDIUMTYPE;
	}

	if (!mmc->hc_wp_grp_size) {
		printf("Card does not define HC WP group size\n");
		return -EMEDIUMTYPE;
	}

	/* check partition alignment and total enhanced size */
	if (conf->user.enh_size) {
		if (conf->user.enh_size % mmc->hc_wp_grp_size ||
		    conf->user.enh_start % mmc->hc_wp_grp_size) {
			printf("User data enhanced area not HC WP group "
			       "size aligned\n");
			return -EINVAL;
		}
		part_attrs |= EXT_CSD_ENH_USR;
		enh_size_mult = conf->user.enh_size / mmc->hc_wp_grp_size;
		if (mmc->high_capacity)
			enh_start_addr = conf->user.enh_start;
		else
			enh_start_addr = (conf->user.enh_start << 9);
	} else {
		enh_size_mult = 0;
		enh_start_addr = 0;
	}
	tot_enh_size_mult += enh_size_mult;

	for (pidx = 0; pidx < 4; pidx++) {
		if (conf->gp_part[pidx].size % mmc->hc_wp_grp_size) {
			printf("GP%i partition not HC WP group size aligned\n",
			       pidx+1);
			return -EINVAL;
		}
		gp_size_mult[pidx] =
			conf->gp_part[pidx].size / mmc->hc_wp_grp_size;
		if (conf->gp_part[pidx].size && conf->gp_part[pidx].enhanced) {
			part_attrs |= EXT_CSD_ENH_GP(pidx);
			tot_enh_size_mult += gp_size_mult[pidx];
		}
	}

	if (part_attrs && !(mmc->part_support & ENHNCD_SUPPORT)) {
		printf("Card does not support enhanced attribute\n");
		return -EMEDIUMTYPE;
	}

	err = mmc_send_ext_csd(mmc, ext_csd);
	if (err)
		return err;

	max_enh_size_mult =
		(ext_csd[EXT_CSD_MAX_ENH_SIZE_MULT+2] << 16) +
		(ext_csd[EXT_CSD_MAX_ENH_SIZE_MULT+1] << 8) +
		ext_csd[EXT_CSD_MAX_ENH_SIZE_MULT];
	if (tot_enh_size_mult > max_enh_size_mult) {
		printf("Total enhanced size exceeds maximum (%u > %u)\n",
		       tot_enh_size_mult, max_enh_size_mult);
		return -EMEDIUMTYPE;
	}

	/* The default value of EXT_CSD_WR_REL_SET is device
	 * dependent, the values can only be changed if the
	 * EXT_CSD_HS_CTRL_REL bit is set. The values can be
	 * changed only once and before partitioning is completed. */
	wr_rel_set = ext_csd[EXT_CSD_WR_REL_SET];
	if (conf->user.wr_rel_change) {
		if (conf->user.wr_rel_set)
			wr_rel_set |= EXT_CSD_WR_DATA_REL_USR;
		else
			wr_rel_set &= ~EXT_CSD_WR_DATA_REL_USR;
	}
	for (pidx = 0; pidx < 4; pidx++) {
		if (conf->gp_part[pidx].wr_rel_change) {
			if (conf->gp_part[pidx].wr_rel_set)
				wr_rel_set |= EXT_CSD_WR_DATA_REL_GP(pidx);
			else
				wr_rel_set &= ~EXT_CSD_WR_DATA_REL_GP(pidx);
		}
	}

	if (wr_rel_set != ext_csd[EXT_CSD_WR_REL_SET] &&
	    !(ext_csd[EXT_CSD_WR_REL_PARAM] & EXT_CSD_HS_CTRL_REL)) {
		puts("Card does not support host controlled partition write "
		     "reliability settings\n");
		return -EMEDIUMTYPE;
	}

	if (ext_csd[EXT_CSD_PARTITION_SETTING] &
	    EXT_CSD_PARTITION_SETTING_COMPLETED) {
		printf("Card already partitioned\n");
		return -EPERM;
	}

	if (mode == MMC_HWPART_CONF_CHECK)
		return 0;

	/* Partitioning requires high-capacity size definitions */
	if (!(ext_csd[EXT_CSD_ERASE_GROUP_DEF] & 0x01)) {
		err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
				 EXT_CSD_ERASE_GROUP_DEF, 1);

		if (err)
			return err;

		ext_csd[EXT_CSD_ERASE_GROUP_DEF] = 1;

		/* update erase group size to be high-capacity */
		mmc->erase_grp_size =
			ext_csd[EXT_CSD_HC_ERASE_GRP_SIZE] * 1024;
	}

	/* all OK, write the configuration */
	for (i = 0; i < 4; i++) {
		err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
				 EXT_CSD_ENH_START_ADDR+i,
				 (enh_start_addr >> (i*8)) & 0xFF);
		if (err)
			return err;
	}
	for (i = 0; i < 3; i++) {
		err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
				 EXT_CSD_ENH_SIZE_MULT+i,
				 (enh_size_mult >> (i*8)) & 0xFF);
		if (err)
			return err;
	}
	for (pidx = 0; pidx < 4; pidx++) {
		for (i = 0; i < 3; i++) {
			err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
					 EXT_CSD_GP_SIZE_MULT+pidx*3+i,
					 (gp_size_mult[pidx] >> (i*8)) & 0xFF);
			if (err)
				return err;
		}
	}
	err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
			 EXT_CSD_PARTITIONS_ATTRIBUTE, part_attrs);
	if (err)
		return err;

	if (mode == MMC_HWPART_CONF_SET)
		return 0;

	/* The WR_REL_SET is a write-once register but shall be
	 * written before setting PART_SETTING_COMPLETED. As it is
	 * write-once we can only write it when completing the
	 * partitioning. */
	if (wr_rel_set != ext_csd[EXT_CSD_WR_REL_SET]) {
		err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
				 EXT_CSD_WR_REL_SET, wr_rel_set);
		if (err)
			return err;
	}

	/* Setting PART_SETTING_COMPLETED confirms the partition
	 * configuration but it only becomes effective after power
	 * cycle, so we do not adjust the partition related settings
	 * in the mmc struct. */

	err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
			 EXT_CSD_PARTITION_SETTING,
			 EXT_CSD_PARTITION_SETTING_COMPLETED);
	if (err)
		return err;

	return 0;
}

int mmc_getcd(struct mmc *mmc)
{
	int cd;

	cd = board_mmc_getcd(mmc);

	if (cd < 0) {
		if (mmc->cfg->ops->getcd)
			cd = mmc->cfg->ops->getcd(mmc);
		else
			cd = 1;
	}

	return cd;
}

static int sd_switch(struct mmc *mmc, int mode, int group, u8 value, u8 *resp)
{
	struct mmc_cmd cmd;
	struct mmc_data data;

	/* Switch the frequency */
	cmd.cmdidx = SD_CMD_SWITCH_FUNC;
	cmd.resp_type = MMC_RSP_R1;
	cmd.cmdarg = (mode << 31) | 0xffffff;
	cmd.cmdarg &= ~(0xf << (group * 4));
	cmd.cmdarg |= value << (group * 4);

	data.dest = (char *)resp;
	data.blocksize = 64;
	data.blocks = 1;
	data.flags = MMC_DATA_READ;

	return mmc_send_cmd(mmc, &cmd, &data);
}

static int sd_change_freq(struct mmc *mmc)
{
	int err;
	struct mmc_cmd cmd;
	ALLOC_CACHE_ALIGN_BUFFER(uint, scr, 2);
	ALLOC_CACHE_ALIGN_BUFFER(uint, switch_status, 16);
	struct mmc_data data;
	int timeout;

	mmc->card_caps = 0;

	if (mmc_host_is_spi(mmc))
		return 0;

	/* Read the SCR to find out if this card supports higher speeds */
	cmd.cmdidx = MMC_CMD_APP_CMD;
	cmd.resp_type = MMC_RSP_R1;
	cmd.cmdarg = mmc->rca << 16;

	err = mmc_send_cmd(mmc, &cmd, NULL);

	if (err)
		return err;

	cmd.cmdidx = SD_CMD_APP_SEND_SCR;
	cmd.resp_type = MMC_RSP_R1;
	cmd.cmdarg = 0;

	timeout = 3;

retry_scr:
	data.dest = (char *)scr;
	data.blocksize = 8;
	data.blocks = 1;
	data.flags = MMC_DATA_READ;

	err = mmc_send_cmd(mmc, &cmd, &data);

	if (err) {
		if (timeout--)
			goto retry_scr;

		return err;
	}

	mmc->scr[0] = __be32_to_cpu(scr[0]);
	mmc->scr[1] = __be32_to_cpu(scr[1]);

	switch ((mmc->scr[0] >> 24) & 0xf) {
	case 0:
		mmc->version = SD_VERSION_1_0;
		break;
	case 1:
		mmc->version = SD_VERSION_1_10;
		break;
	case 2:
		mmc->version = SD_VERSION_2;
		if ((mmc->scr[0] >> 15) & 0x1)
			mmc->version = SD_VERSION_3;
		break;
	default:
		mmc->version = SD_VERSION_1_0;
		break;
	}

	if (mmc->scr[0] & SD_DATA_4BIT)
		mmc->card_caps |= MMC_MODE_4BIT;

	/* Version 1.0 doesn't support switching */
	if (mmc->version == SD_VERSION_1_0)
		return 0;

	timeout = 4;
	while (timeout--) {
		err = sd_switch(mmc, SD_SWITCH_CHECK, 0, 1,
				(u8 *)switch_status);

		if (err)
			return err;

		/* The high-speed function is busy.  Try again */
		if (!(__be32_to_cpu(switch_status[7]) & SD_HIGHSPEED_BUSY))
			break;
	}

	/* If high-speed isn't supported, we return */
	if (!(__be32_to_cpu(switch_status[3]) & SD_HIGHSPEED_SUPPORTED))
		return 0;

	/*
	 * If the host doesn't support SD_HIGHSPEED, do not switch card to
	 * HIGHSPEED mode even if the card support SD_HIGHSPPED.
	 * This can avoid furthur problem when the card runs in different
	 * mode between the host.
	 */
	if (!((mmc->cfg->host_caps & MMC_MODE_HS_52MHz) &&
	      (mmc->cfg->host_caps & MMC_MODE_HS)))
		return 0;

	err = sd_switch(mmc, SD_SWITCH_SWITCH, 0, 1, (u8 *)switch_status);

	if (err)
		return err;

	if ((__be32_to_cpu(switch_status[4]) & 0x0f000000) == 0x01000000)
		mmc->card_caps |= MMC_MODE_HS;

	return 0;
}

/* frequency bases */
/* divided by 10 to be nice to platforms without floating point */
static const int fbase[] = {
	10000,
	100000,
	1000000,
	10000000,
};

/* Multiplier values for TRAN_SPEED.  Multiplied by 10 to be nice
 * to platforms without floating point.
 */
static const int multipliers[] = {
	0,			/* reserved */
	10,
	12,
	13,
	15,
	20,
	25,
	30,
	35,
	40,
	45,
	50,
	55,
	60,
	70,
	80,
};

static void mmc_set_ios(struct mmc *mmc)
{
	if (mmc->cfg->ops->set_ios)
		mmc->cfg->ops->set_ios(mmc);
}

void mmc_set_clock(struct mmc *mmc, uint clock)
{
	if (clock > mmc->cfg->f_max)
		clock = mmc->cfg->f_max;

	if (clock < mmc->cfg->f_min)
		clock = mmc->cfg->f_min;

	mmc->clock = clock;

	mmc_set_ios(mmc);
}

static void mmc_set_bus_width(struct mmc *mmc, uint width)
{
	debugf("mmc_set_bus_width width=%x\n", width);

	mmc->bus_width = width;

	mmc_set_ios(mmc);
}

#ifdef CONFIG_EMMC_HAS_DDR_MODE
static void mmc_set_timing(struct mmc *mmc, uint timing)
{
	debugf("set ddr52 mode\n");

	mmc->timing = timing;
	mmc_set_ios(mmc);
}
#endif

struct mode_width_tuning {
	enum bus_mode mode;
	uint widths;
#ifdef CONFIG_MMC_SUPPORTS_TUNING
	uint tuning;
#endif
};

static const struct ext_csd_bus_width {
	uint cap;
	bool is_ddr;
	uint ext_csd_bits;
} ext_csd_bus_width[] = {
	{MMC_MODE_8BIT, true, EXT_CSD_DDR_BUS_WIDTH_8},
	{MMC_MODE_4BIT, true, EXT_CSD_DDR_BUS_WIDTH_4},
	{MMC_MODE_8BIT, false, EXT_CSD_BUS_WIDTH_8},
	{MMC_MODE_4BIT, false, EXT_CSD_BUS_WIDTH_4},
	{MMC_MODE_1BIT, false, EXT_CSD_BUS_WIDTH_1},
};

const char *mmc_mode_name(enum bus_mode mode)
{
	static const char *const names[] = {
	      [MMC_LEGACY]	= "MMC legacy",
	      [MMC_HS]		= "MMC High Speed (26MHz)",
	      [SD_HS]		= "SD High Speed (50MHz)",
	      [UHS_SDR12]	= "UHS SDR12 (25MHz)",
	      [UHS_SDR25]	= "UHS SDR25 (50MHz)",
	      [UHS_SDR50]	= "UHS SDR50 (100MHz)",
	      [UHS_SDR104]	= "UHS SDR104 (208MHz)",
	      [UHS_DDR50]	= "UHS DDR50 (50MHz)",
	      [MMC_HS_52]	= "MMC High Speed (52MHz)",
	      [MMC_DDR_52]	= "MMC DDR52 (52MHz)",
	      [MMC_HS_200]	= "HS200 (200MHz)",
	      [MMC_HS_400]	= "HS400 (200MHz)",
	      [MMC_HS_400_ES]	= "HS400ES (200MHz)",
	};

	if (mode >= MMC_MODES_END)
		return "Unknown mode";
	else
		return names[mode];
}

static uint mmc_mode2freq(struct mmc *mmc, enum bus_mode mode)
{
	static const int freqs[] = {
	      [MMC_LEGACY]	= 25000000,
	      [MMC_HS]		= 26000000,
	      [SD_HS]		= 50000000,
	      [MMC_HS_52]	= 52000000,
	      [MMC_DDR_52]	= 52000000,
	      [UHS_SDR12]	= 25000000,
	      [UHS_SDR25]	= 50000000,
	      [UHS_SDR50]	= 100000000,
	      [UHS_DDR50]	= 50000000,
	      [UHS_SDR104]	= 208000000,
	      [MMC_HS_200]	= 200000000,
	      [MMC_HS_400]	= 200000000,
	      [MMC_HS_400_ES]	= 200000000,
	};

	if (mode == MMC_LEGACY)
		return mmc->legacy_speed;
	else if (mode >= MMC_MODES_END)
		return 0;
	else
		return freqs[mode];
}

static inline bool mmc_is_mode_ddr(enum bus_mode mode)
{
	if (mode == MMC_DDR_52)
		return true;
	else
		return false;
}

static int mmc_select_mode(struct mmc *mmc, enum bus_mode mode)
{
	mmc->selected_mode = mode;
	mmc->tran_speed = mmc_mode2freq(mmc, mode);
	mmc->ddr_mode = mmc_is_mode_ddr(mode);

	debugf("selecting mode %s (freq : %d MHz)\n", mmc_mode_name(mode),
		 mmc->tran_speed / 1000000);

	return 0;
}

static int mmc_set_card_speed(struct mmc *mmc, enum bus_mode mode,
			      bool hsdowngrade)
{
	int err;
	int speed_bits;

	ALLOC_CACHE_ALIGN_BUFFER(u8, test_csd, MMC_MAX_BLOCK_LEN);

	switch (mode) {
	case MMC_HS:
	case MMC_HS_52:
	case MMC_DDR_52:
		speed_bits = EXT_CSD_TIMING_HS;
		break;
#ifdef CONFIG_MMC_HS200_SUPPORT
	case MMC_HS_200:
		speed_bits = EXT_CSD_TIMING_HS200;
		break;
#endif
	case MMC_LEGACY:
		speed_bits = EXT_CSD_TIMING_LEGACY;
		break;
	default:
		return -EINVAL;
	}

	err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL, EXT_CSD_HS_TIMING,
			   speed_bits);
	if (err)
		return err;

#if defined(CONFIG_MMC_HS200_SUPPORT)
	/*
	 * In case the eMMC is in HS200/HS400 mode and we are downgrading
	 * to HS mode, the card clock are still running much faster than
	 * the supported HS mode clock, so we can not reliably read out
	 * Extended CSD. Reconfigure the controller to run at HS mode.
	 */
	if (hsdowngrade) {
		mmc_select_mode(mmc, MMC_HS);
		mmc_set_clock(mmc, mmc_mode2freq(mmc, MMC_HS));
	}
#endif

	if ((mode == MMC_HS) || (mode == MMC_HS_52)) {
		/* Now check to see that it worked */
		err = mmc_send_ext_csd(mmc, test_csd);
		if (err)
			return err;

		/* No high-speed support */
		if (!test_csd[EXT_CSD_HS_TIMING])
			return -ENOTSUPP;
	}

	return 0;
}

static const struct mode_width_tuning mmc_modes_by_pref[] = {
#ifdef CONFIG_MMC_HS200_SUPPORT
		{
			.mode = MMC_HS_200,
			.widths = MMC_MODE_8BIT | MMC_MODE_4BIT,
#ifdef CONFIG_MMC_SUPPORTS_TUNING
			.tuning = MMC_CMD_SEND_TUNING_BLOCK_HS200
#endif
		},
#endif
		{
			.mode = MMC_HS_52,
			.widths = MMC_MODE_8BIT | MMC_MODE_4BIT | MMC_MODE_1BIT,
		},
		{
			.mode = MMC_HS,
			.widths = MMC_MODE_8BIT | MMC_MODE_4BIT | MMC_MODE_1BIT,
		},
		{
			.mode = MMC_LEGACY,
			.widths = MMC_MODE_8BIT | MMC_MODE_4BIT | MMC_MODE_1BIT,
		}
	};

#define for_each_mmc_mode_by_pref(caps, mwt) \
	for (mwt = mmc_modes_by_pref;\
	    mwt < mmc_modes_by_pref + ARRAY_SIZE(mmc_modes_by_pref);\
	    mwt++) \
		if (caps & MMC_CAP(mwt->mode))

#define for_each_supported_width(caps, ddr, ecbv) \
	for (ecbv = ext_csd_bus_width;\
	    ecbv < ext_csd_bus_width + ARRAY_SIZE(ext_csd_bus_width);\
	    ecbv++) \
		if ((ddr == ecbv->is_ddr) && (caps & ecbv->cap))

static inline int bus_width(uint cap)
{
	if (cap == MMC_MODE_8BIT)
		return 8;
	if (cap == MMC_MODE_4BIT)
		return 4;
	if (cap == MMC_MODE_1BIT)
		return 1;

	error("invalid bus witdh capability 0x%x\n", cap);
	return 0;
}

#ifdef CONFIG_MMC_SUPPORTS_TUNING
static const u8 tuning_blk_pattern_4bit[] = {
	0xff, 0x0f, 0xff, 0x00, 0xff, 0xcc, 0xc3, 0xcc,
	0xc3, 0x3c, 0xcc, 0xff, 0xfe, 0xff, 0xfe, 0xef,
	0xff, 0xdf, 0xff, 0xdd, 0xff, 0xfb, 0xff, 0xfb,
	0xbf, 0xff, 0x7f, 0xff, 0x77, 0xf7, 0xbd, 0xef,
	0xff, 0xf0, 0xff, 0xf0, 0x0f, 0xfc, 0xcc, 0x3c,
	0xcc, 0x33, 0xcc, 0xcf, 0xff, 0xef, 0xff, 0xee,
	0xff, 0xfd, 0xff, 0xfd, 0xdf, 0xff, 0xbf, 0xff,
	0xbb, 0xff, 0xf7, 0xff, 0xf7, 0x7f, 0x7b, 0xde,
};

static const u8 tuning_blk_pattern_8bit[] = {
	0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00,
	0xff, 0xff, 0xcc, 0xcc, 0xcc, 0x33, 0xcc, 0xcc,
	0xcc, 0x33, 0x33, 0xcc, 0xcc, 0xcc, 0xff, 0xff,
	0xff, 0xee, 0xff, 0xff, 0xff, 0xee, 0xee, 0xff,
	0xff, 0xff, 0xdd, 0xff, 0xff, 0xff, 0xdd, 0xdd,
	0xff, 0xff, 0xff, 0xbb, 0xff, 0xff, 0xff, 0xbb,
	0xbb, 0xff, 0xff, 0xff, 0x77, 0xff, 0xff, 0xff,
	0x77, 0x77, 0xff, 0x77, 0xbb, 0xdd, 0xee, 0xff,
	0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00,
	0x00, 0xff, 0xff, 0xcc, 0xcc, 0xcc, 0x33, 0xcc,
	0xcc, 0xcc, 0x33, 0x33, 0xcc, 0xcc, 0xcc, 0xff,
	0xff, 0xff, 0xee, 0xff, 0xff, 0xff, 0xee, 0xee,
	0xff, 0xff, 0xff, 0xdd, 0xff, 0xff, 0xff, 0xdd,
	0xdd, 0xff, 0xff, 0xff, 0xbb, 0xff, 0xff, 0xff,
	0xbb, 0xbb, 0xff, 0xff, 0xff, 0x77, 0xff, 0xff,
	0xff, 0x77, 0x77, 0xff, 0x77, 0xbb, 0xdd, 0xee,
};

int mmc_send_tuning(struct mmc *mmc, u32 opcode, int *cmd_error)
{
	struct mmc_cmd cmd;
	struct mmc_data data;
	const u8 *tuning_block_pattern;
	int size, err;

	if (mmc->bus_width == MMC_MODE_8BIT) {
		tuning_block_pattern = tuning_blk_pattern_8bit;
		size = sizeof(tuning_blk_pattern_8bit);
	} else if (mmc->bus_width == MMC_MODE_4BIT) {
		tuning_block_pattern = tuning_blk_pattern_4bit;
		size = sizeof(tuning_blk_pattern_4bit);
	} else
		return -EINVAL;

	ALLOC_CACHE_ALIGN_BUFFER(u8, data_buf, size);

	cmd.cmdidx = opcode;
	cmd.resp_type = MMC_RSP_R1;
	cmd.cmdarg = 0;

	data.dest = data_buf;
	data.blocks = 1;
	data.blocksize = size;
	data.flags = MMC_DATA_READ;

	err = mmc_send_cmd(mmc, &cmd, &data);
	if (err)
		return err;

	if (memcmp(data_buf, tuning_block_pattern, size))
		return -EIO;

	return 0;
}

static int mmc_execute_tuning(struct mmc *mmc, uint opcode)
{
	if (!mmc->cfg->ops->execute_tuning)
		return -ENOSYS;

	return mmc->cfg->ops->execute_tuning(mmc, opcode);
}
#endif

/*
 * read the compare the part of ext csd that is constant.
 * This can be used to check that the transfer is working
 * as expected.
 */
static int mmc_read_and_compare_ext_csd(struct mmc *mmc)
{
	int err;
	const u8 *ext_csd = mmc->ext_csd;
	ALLOC_CACHE_ALIGN_BUFFER(u8, test_csd, MMC_MAX_BLOCK_LEN);

	if (mmc->version < MMC_VERSION_4)
		return 0;

	err = mmc_send_ext_csd(mmc, test_csd);
	if (err)
		return err;

	/* Only compare read only fields */
	if (ext_csd[EXT_CSD_PARTITIONING_SUPPORT]
		== test_csd[EXT_CSD_PARTITIONING_SUPPORT] &&
	    ext_csd[EXT_CSD_HC_WP_GRP_SIZE]
		== test_csd[EXT_CSD_HC_WP_GRP_SIZE] &&
	    ext_csd[EXT_CSD_REV]
		== test_csd[EXT_CSD_REV] &&
	    ext_csd[EXT_CSD_HC_ERASE_GRP_SIZE]
		== test_csd[EXT_CSD_HC_ERASE_GRP_SIZE] &&
	    memcmp(&ext_csd[EXT_CSD_SEC_CNT],
		   &test_csd[EXT_CSD_SEC_CNT], 4) == 0)
		return 0;

	return -EBADMSG;
}

static int mmc_select_mode_and_width(struct mmc *mmc, uint card_caps)
{
	int err = 0;
	const struct mode_width_tuning *mwt;
	const struct ext_csd_bus_width *ecbw;

	if (mmc_host_is_spi(mmc)) {
		mmc_set_bus_width(mmc, 1);
		mmc_select_mode(mmc, MMC_LEGACY);
		mmc_set_clock(mmc, mmc->tran_speed);
		return 0;
	}

	/* Restrict card's capabilities by what the host can do */
	card_caps &= mmc->host_caps;

	/* Only version 4 of MMC supports wider bus widths */
	if (mmc->version < MMC_VERSION_4)
		return 0;

	if (!mmc->ext_csd) {
		error("No ext_csd found!\n"); /* this should enver happen */
		return -ENOTSUPP;
	}

#if defined(CONFIG_MMC_HS200_SUPPORT)
	/*
	 * In case the eMMC is in HS200/HS400 mode, downgrade to HS mode
	 * before doing anything else, since a transition from either of
	 * the HS200/HS400 mode directly to legacy mode is not supported.
	 */
	if (mmc->selected_mode == MMC_HS_200)
		mmc_set_card_speed(mmc, MMC_HS, true);
	else
#endif
		mmc_set_clock(mmc, mmc->legacy_speed);

	for_each_mmc_mode_by_pref(card_caps, mwt) {
		for_each_supported_width(card_caps & mwt->widths,
					 mmc_is_mode_ddr(mwt->mode), ecbw) {
			debug("trying mode %s width %d (at %d MHz)\n",
				 mmc_mode_name(mwt->mode),
				 bus_width(ecbw->cap),
				 mmc_mode2freq(mmc, mwt->mode) / 1000000);

			/* configure the bus width (card + host) */
			err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
				    EXT_CSD_BUS_WIDTH,
				    ecbw->ext_csd_bits & ~EXT_CSD_DDR_FLAG);
			if (err)
				goto error;
			mmc_set_bus_width(mmc, bus_width(ecbw->cap));

			/* configure the bus speed (card) */
			err = mmc_set_card_speed(mmc, mwt->mode, false);
			if (err)
				goto error;

			/*
			 * configure the bus width AND the ddr mode
			 * (card). The host side will be taken care
			 * of in the next step
			 */
			if (ecbw->ext_csd_bits & EXT_CSD_DDR_FLAG) {
				err = mmc_switch(mmc,
						 EXT_CSD_CMD_SET_NORMAL,
						 EXT_CSD_BUS_WIDTH,
						 ecbw->ext_csd_bits);
				if (err)
					goto error;
			}

			/* configure the bus mode (host) */
			mmc_select_mode(mmc, mwt->mode);
			mmc_set_clock(mmc, mmc->tran_speed);
#ifdef CONFIG_MMC_SUPPORTS_TUNING
			/* execute tuning if needed */
			if (mwt->tuning) {
				err = mmc_execute_tuning(mmc,
							 mwt->tuning);
				if (err) {
					errorf("tuning failed : %d\n", err);
					goto error;
				}
			}
#endif

			/* do a transfer to check the configuration */
			err = mmc_read_and_compare_ext_csd(mmc);
			if (!err)
				return 0;

error:
			/* if an error occurred, revert to a safer bus mode */
			mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
				   EXT_CSD_BUS_WIDTH, EXT_CSD_BUS_WIDTH_1);
			mmc_select_mode(mmc, MMC_LEGACY);
			mmc_set_bus_width(mmc, 1);
		}
	}

	errorf("unable to select a mode : %d\n", err);

	return -ENOTSUPP;
}

static int mmc_get_capabilities(struct mmc *mmc)
{
	u8 *ext_csd = mmc->ext_csd;
	char cardtype;

	mmc->card_caps = MMC_MODE_1BIT | MMC_CAP(MMC_LEGACY);

	if (mmc_host_is_spi(mmc))
		return 0;

	/* Only version 4 supports high-speed */
	if (mmc->version < MMC_VERSION_4)
		return 0;

	if (!ext_csd) {
		errorf("No ext_csd found!\n"); /* this should enver happen */
		return -ENOTSUPP;
	}

	mmc->card_caps |= MMC_MODE_4BIT | MMC_MODE_8BIT;

	cardtype = ext_csd[EXT_CSD_CARD_TYPE];
	mmc->cardtype = cardtype;

#if defined(CONFIG_MMC_HS200_SUPPORT)
	if (cardtype & (EXT_CSD_CARD_TYPE_HS200_1_2V |
			EXT_CSD_CARD_TYPE_HS200_1_8V)) {
		mmc->card_caps |= MMC_MODE_HS200;
	}
#endif
	if (cardtype & EXT_CSD_CARD_TYPE_26)
		mmc->card_caps |= MMC_MODE_HS;

	return 0;
}



static int mmc_startup(struct mmc *mmc)
{
	int err, i;
	uint mult, freq;
	u64 cmult, csize, capacity;
	struct mmc_cmd cmd;
	ALLOC_CACHE_ALIGN_BUFFER(u8, ext_csd, MMC_MAX_BLOCK_LEN);
	ALLOC_CACHE_ALIGN_BUFFER(u8, test_csd, MMC_MAX_BLOCK_LEN);
	int timeout = 1000;
	bool has_parts = false;
	bool part_completed;

	debugf("entry\n");
#ifdef CONFIG_MMC_SPI_CRC_ON
	if (mmc_host_is_spi(mmc)) {	/* enable CRC check for spi */
		cmd.cmdidx = MMC_CMD_SPI_CRC_ON_OFF;
		cmd.resp_type = MMC_RSP_R1;
		cmd.cmdarg = 1;
		err = mmc_send_cmd(mmc, &cmd, NULL);

		if (err)
			return err;
	}
#endif

	/* Put the Card in Identify Mode */
	cmd.cmdidx = mmc_host_is_spi(mmc) ? MMC_CMD_SEND_CID :
		MMC_CMD_ALL_SEND_CID;	/* cmd not supported in spi */
	cmd.resp_type = MMC_RSP_R2;
	cmd.cmdarg = 0;

#ifndef CONFIG_FPGA
	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err) {
		errorf("mmc_send_cmd MMC_CMD_SEND_CID err=%x\n", err);
		return err;
	}

#else
	int times = 0;
	/* check  ext_csd version and capacity */
	for (times = 0; times < 10; times++) {
		udelay(500);
		err = mmc_send_cmd(mmc, &cmd, NULL);
		if (!err)
			break;
	}

	if (times == 10) {
		errorf("mmc_send_cmd MMC_CMD_SEND_CID fail !   err=%x\n", err);
		return err;
	}
#endif

	memcpy(mmc->cid, cmd.response, 16);

	/*
	 * For MMC cards, set the Relative Address.
	 * For SD cards, get the Relatvie Address.
	 * This also puts the cards into Standby State
	 */

	if (!mmc_host_is_spi(mmc)) {	/* cmd not supported in spi */
		cmd.cmdidx = SD_CMD_SEND_RELATIVE_ADDR;
		cmd.cmdarg = mmc->rca << 16;
		cmd.resp_type = MMC_RSP_R6;
		err = mmc_send_cmd(mmc, &cmd, NULL);
		if (err)
			return err;
		if (IS_SD(mmc))
			mmc->rca = (cmd.response[0] >> 16) & 0xffff;
	}

	/* Get the Card-Specific Data */
	cmd.cmdidx = MMC_CMD_SEND_CSD;
	cmd.resp_type = MMC_RSP_R2;
	cmd.cmdarg = mmc->rca << 16;

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err) {
		errorf("mmc_send_cmd SEND_CSD err=%x\n", err);
		return err;
	}

	/* Waiting for the ready status */
	err = mmc_send_status(mmc, timeout);
	if (err) {
		errorf("mmc_send_status err=%x\n", err);
		return err;
	}

	mmc->csd[0] = cmd.response[0];
	mmc->csd[1] = cmd.response[1];
	mmc->csd[2] = cmd.response[2];
	mmc->csd[3] = cmd.response[3];

	printf("csd register(128 bit): ");
	for (i = 0; i < 4; i++)
		printf("%08x ", cmd.response[i]);
	printf("\n");
	debugf("mmc->version =0x%x\n", mmc->version);

	if (mmc->version == MMC_VERSION_UNKNOWN) {
		int version = (cmd.response[0] >> 26) & 0xf;

		switch (version) {
		case 0:
			mmc->version = MMC_VERSION_1_2;
			break;
		case 1:
			mmc->version = MMC_VERSION_1_4;
			break;
		case 2:
			mmc->version = MMC_VERSION_2_2;
			break;
		case 3:
			mmc->version = MMC_VERSION_3;
			break;
		case 4:
			mmc->version = MMC_VERSION_4;
			break;
		default:
			mmc->version = MMC_VERSION_1_2;
			break;
		}
	}
	debugf("%s mmc->version=0x%x\n", __func__, mmc->version);

	/* divide frequency by 10, since the mults are 10x bigger */
	freq = fbase[(cmd.response[0] & 0x7)];
	mult = multipliers[((cmd.response[0] >> 3) & 0xf)];

	mmc->tran_speed = freq * mult;

	mmc->dsr_imp = ((cmd.response[1] >> 12) & 0x1);
	mmc->read_bl_len = 1 << ((cmd.response[1] >> 16) & 0xf);

	if (IS_SD(mmc))
		mmc->write_bl_len = mmc->read_bl_len;
	else
		mmc->write_bl_len = 1 << ((cmd.response[3] >> 22) & 0xf);

	if (mmc->high_capacity) {
		csize = (mmc->csd[1] & 0x3f) << 16
			| (mmc->csd[2] & 0xffff0000) >> 16;
		cmult = 8;
	} else {
		csize = (mmc->csd[1] & 0x3ff) << 2
			| (mmc->csd[2] & 0xc0000000) >> 30;
		cmult = (mmc->csd[2] & 0x00038000) >> 15;
	}

	mmc->capacity_user = (csize + 1) << (cmult + 2);
	mmc->capacity_user *= mmc->read_bl_len;
	mmc->capacity_boot = 0;
	mmc->capacity_rpmb = 0;
	mmc->rel_wr_sec_c = 1;

	for (i = 0; i < 4; i++)
		mmc->capacity_gp[i] = 0;

	if (mmc->read_bl_len > MMC_MAX_BLOCK_LEN)
		mmc->read_bl_len = MMC_MAX_BLOCK_LEN;

	if (mmc->write_bl_len > MMC_MAX_BLOCK_LEN)
		mmc->write_bl_len = MMC_MAX_BLOCK_LEN;

	if ((mmc->dsr_imp) && (0xffffffff != mmc->dsr)) {
		cmd.cmdidx = MMC_CMD_SET_DSR;
		cmd.cmdarg = (mmc->dsr & 0xffff) << 16;
		cmd.resp_type = MMC_RSP_NONE;
		if (mmc_send_cmd(mmc, &cmd, NULL))
			errorf("MMC: SET_DSR failed\n");
	}

	/* Select the card, and put it into Transfer Mode */
	if (!mmc_host_is_spi(mmc)) {	/* cmd not supported in spi */
		cmd.cmdidx = MMC_CMD_SELECT_CARD;
		cmd.resp_type = MMC_RSP_R1;
		cmd.cmdarg = mmc->rca << 16;
		err = mmc_send_cmd(mmc, &cmd, NULL);

		if (err) {
			debugf("MMC_CMD_SELECT_CARD ######=%d\n", err);
			return err;
		}
	}

	/*
	 * For SD, its erase group is always one sector
	 */
	mmc->erase_grp_size = 1;
	mmc->part_config = MMCPART_NOAVAILABLE;
	if (!IS_SD(mmc) && (mmc->version >= MMC_VERSION_4)) {
		/* check  ext_csd version and capacity */

#ifndef CONFIG_FPGA
		err = mmc_send_ext_csd(mmc, ext_csd);
		if (err)
			return err;
		if (ext_csd[EXT_CSD_REV] >= 2) {
#else
		int temp_loop = 0;

		for (temp_loop = 0; temp_loop < 5; temp_loop++) {
			err = mmc_send_ext_csd(mmc, ext_csd);
			if (!err)
				break;
		}
		if (temp_loop == 5)
			err = -1;
		if (!err && (ext_csd[EXT_CSD_REV] >= 2)) {
#endif
			/*
			 * According to the JEDEC Standard, the value of
			 * ext_csd's capacity is valid if the value is more
			 * than 2GB
			 */
			capacity = (ext_csd[EXT_CSD_SEC_CNT] << 0 &
				    0x00000000000000ff)
					| (ext_csd[EXT_CSD_SEC_CNT + 1] << 8 &
					   0x000000000000ff00)
					| (ext_csd[EXT_CSD_SEC_CNT + 2] << 16 &
					   0x0000000000ff0000)
					| (ext_csd[EXT_CSD_SEC_CNT + 3] << 24 &
					   0x00000000ff000000);
			capacity *= MMC_MAX_BLOCK_LEN;
			if ((capacity >> 20) > 2 * 1024)
				mmc->capacity_user = capacity;
		}

#ifdef CONFIG_MMC_TRACE
		printf("\n============== ext_csd ================\n");
		for (i = 0; i < 512; i++) {
			if (i % 10 == 0)
				printf("\n%4d:   ", i);
			printf("0x%02x    ", ext_csd[i]);
		}
		printf("\n");
#endif
		mmc->rel_wr_sec_c = ext_csd[EXT_CSD_REL_WR_SEC_C];

		switch (ext_csd[EXT_CSD_REV]) {
		case 1:
			mmc->version = MMC_VERSION_4_1;
			break;
		case 2:
			mmc->version = MMC_VERSION_4_2;
			break;
		case 3:
			mmc->version = MMC_VERSION_4_3;
			break;
		case 5:
			mmc->version = MMC_VERSION_4_41;
			break;
		case 6:
			mmc->version = MMC_VERSION_4_5;
			break;
		case 7:
			mmc->version = MMC_VERSION_5_0;
			break;
		}
		debugf("%s mmc->version2=0x%x\n", __func__, mmc->version);
		/*
		 * The partition data may be non-zero but it is only
		 * effective if PARTITION_SETTING_COMPLETED is set in
		 * EXT_CSD, so ignore any data if this bit is not set,
		 * except for enabling the high-capacity group size
		 * definition (see below).
		 */
		part_completed = !!(ext_csd[EXT_CSD_PARTITION_SETTING] &
				    EXT_CSD_PARTITION_SETTING_COMPLETED);

		/* store the partition info of emmc */
		mmc->part_support = ext_csd[EXT_CSD_PARTITIONING_SUPPORT];
		if ((ext_csd[EXT_CSD_PARTITIONING_SUPPORT] & PART_SUPPORT) ||
		    ext_csd[EXT_CSD_BOOT_MULT])
			mmc->part_config = ext_csd[EXT_CSD_PART_CONF];
		if (part_completed &&
		    (ext_csd[EXT_CSD_PARTITIONING_SUPPORT] & ENHNCD_SUPPORT))
			mmc->part_attr = ext_csd[EXT_CSD_PARTITIONS_ATTRIBUTE];

		mmc->capacity_boot = ext_csd[EXT_CSD_BOOT_MULT] << 17;

		mmc->capacity_rpmb = ext_csd[EXT_CSD_RPMB_MULT] << 17;

		for (i = 0; i < 4; i++) {
			int idx = EXT_CSD_GP_SIZE_MULT + i * 3;
			uint mult = (ext_csd[idx + 2] << 16) +
				(ext_csd[idx + 1] << 8) + ext_csd[idx];
			if (mult)
				has_parts = true;
			if (!part_completed)
				continue;
			mmc->capacity_gp[i] = mult;
			mmc->capacity_gp[i] *=
				ext_csd[EXT_CSD_HC_ERASE_GRP_SIZE];
			mmc->capacity_gp[i] *= ext_csd[EXT_CSD_HC_WP_GRP_SIZE];
			mmc->capacity_gp[i] <<= 19;
		}

		if (part_completed) {
			mmc->enh_user_size =
				(ext_csd[EXT_CSD_ENH_SIZE_MULT+2] << 16) +
				(ext_csd[EXT_CSD_ENH_SIZE_MULT+1] << 8) +
				ext_csd[EXT_CSD_ENH_SIZE_MULT];
			mmc->enh_user_size *= ext_csd[EXT_CSD_HC_ERASE_GRP_SIZE];
			mmc->enh_user_size *= ext_csd[EXT_CSD_HC_WP_GRP_SIZE];
			mmc->enh_user_size <<= 19;
			mmc->enh_user_start =
				((u64)ext_csd[EXT_CSD_ENH_START_ADDR+3] << 24) +
				((u64)ext_csd[EXT_CSD_ENH_START_ADDR+2] << 16) +
				((u64)ext_csd[EXT_CSD_ENH_START_ADDR+1] << 8) +
				(u64)ext_csd[EXT_CSD_ENH_START_ADDR];
			if (mmc->high_capacity)
				mmc->enh_user_start <<= 9;
		}

		/*
		 * Host needs to enable ERASE_GRP_DEF bit if device is
		 * partitioned. This bit will be lost every time after a reset
		 * or power off. This will affect erase size.
		 */
		if (part_completed)
			has_parts = true;
		if ((ext_csd[EXT_CSD_PARTITIONING_SUPPORT] & PART_SUPPORT) &&
		    (ext_csd[EXT_CSD_PARTITIONS_ATTRIBUTE] & PART_ENH_ATTRIB))
			has_parts = true;
		if (has_parts) {
			err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
				EXT_CSD_ERASE_GROUP_DEF, 1);

			if (err) {
				debugf("enable high-capacity erase unit size "
				       "fail, return %d\n", err);
				return err;
			} else {
				ext_csd[EXT_CSD_ERASE_GROUP_DEF] = 1;
			}
		}

		if (ext_csd[EXT_CSD_ERASE_GROUP_DEF] & 0x01) {
			/* Read out group size from ext_csd */
			mmc->erase_grp_size =
				ext_csd[EXT_CSD_HC_ERASE_GRP_SIZE] * 1024;
			/*
			 * if high capacity and partition setting completed
			 * SEC_COUNT is valid even if it is smaller than 2 GiB
			 * JEDEC Standard JESD84-B45, 6.2.4
			 */
			if (mmc->high_capacity && part_completed) {
				capacity = (ext_csd[EXT_CSD_SEC_CNT] << 0 &
				    0x00000000000000ff)
					| (ext_csd[EXT_CSD_SEC_CNT + 1] << 8 &
					   0x000000000000ff00)
					| (ext_csd[EXT_CSD_SEC_CNT + 2] << 16 &
					   0x0000000000ff0000)
					| (ext_csd[EXT_CSD_SEC_CNT + 3] << 24 &
					   0x00000000ff000000);
				capacity *= MMC_MAX_BLOCK_LEN;
				mmc->capacity_user = capacity;
			}
		} else {
			/* Calculate the group size from the csd value. */
			int erase_gsz, erase_gmul;
			erase_gsz = (mmc->csd[2] & 0x00007c00) >> 10;
			erase_gmul = (mmc->csd[2] & 0x000003e0) >> 5;
			/*
			 * The size of (ERASE_GRP_SIZE + 1) *
			 * (ERASE_GRP_MULT + 1) is given as minimum number of
			 * write blocks that can be erased in a signal erase
			 * command. If the size is multiply by 2, the erase
			 * performace may improve greater than 3 times.
			 */
			mmc->erase_grp_size = (erase_gsz + 1)
				* (erase_gmul + 1) * 2;
		}

		mmc->hc_wp_grp_size = 1024
			* ext_csd[EXT_CSD_HC_ERASE_GRP_SIZE]
			* ext_csd[EXT_CSD_HC_WP_GRP_SIZE];

		mmc->wr_rel_set = ext_csd[EXT_CSD_WR_REL_SET];
		debugf("mmc->part_num = %x, erase_grp_size = 0x%x\n",
		       mmc->part_num, mmc->erase_grp_size);

#ifdef CONFIG_EMMC_RST_N_FUNCTION
		if (ext_csd[EXT_CSD_RST_N_FUNCTION] == 0) {
			debugf("RST_n signal is will be permanently enabled\n");
			mmc_set_rst_n_function(mmc, 0x1);
		} else if (ext_csd[EXT_CSD_RST_N_FUNCTION] == 1) {
			debugf("RST_n signal(0x%x) has already be permanently enabled\n",
			       ext_csd[EXT_CSD_RST_N_FUNCTION]);
		} else if (ext_csd[EXT_CSD_RST_N_FUNCTION] == 2) {
			debugf("The eMMC RST_n signal is permanently disnabled\n");
		}
#endif

#ifdef CONFIG_EMMC_WP
		err = mmc_enable_pwr_wp(mmc);
		if (err)
			printf("%s: emmc power-up protection can't be eanbled\n",
			       __func__);
		mmc->wp_enable = !err;
#endif

#ifdef CONFIG_MMC_TEST
		mmc->erase_mem_cont = ext_csd[EXT_CSD_ERASE_MEM_CONT];
#endif
	}

	err = mmc_set_capacity(mmc, mmc->part_num);
	if (err) {
		errorf("mmc_set_capacityerr=%x\n", err);
		return err;
	}
#ifndef CONFIG_MMC_1BIT_BUS_MODE
	if (IS_SD(mmc)) {
		err = sd_change_freq(mmc);
		debugf("sd_change_freq=%d\n", err);
	} else {
		err = mmc_change_freq(mmc);
		debugf("mmc_change_freq=%d\n", err);
	}
	if (err)
		return err;
#endif
	/* Restrict card's capabilities by what the host can do */
	mmc->card_caps &= mmc->cfg->host_caps;

	if (IS_SD(mmc)) {
		if (mmc->card_caps & MMC_MODE_4BIT) {
			cmd.cmdidx = MMC_CMD_APP_CMD;
			cmd.resp_type = MMC_RSP_R1;
			cmd.cmdarg = mmc->rca << 16;

			err = mmc_send_cmd(mmc, &cmd, NULL);
			if (err)
				return err;

			cmd.cmdidx = SD_CMD_APP_SET_BUS_WIDTH;
			cmd.resp_type = MMC_RSP_R1;
			cmd.cmdarg = 2;
			err = mmc_send_cmd(mmc, &cmd, NULL);
			if (err)
				return err;

			mmc_set_bus_width(mmc, 4);
		}

		if (mmc->card_caps & MMC_MODE_HS)
			mmc->tran_speed = 50000000;
		else
			mmc->tran_speed = 25000000;

		mmc_select_mode(mmc, SD_HS);
		mmc_set_clock(mmc, mmc->tran_speed);
	} else {
		mmc->ext_csd = ext_csd;
		err = mmc_get_capabilities(mmc);
		if (err)
			return err;

		mmc->host_caps = mmc->cfg->host_caps;

		err = mmc_select_mode_and_width(mmc, mmc->card_caps);
		if (err)
			return err;

	printf("mmc speed mode: %s (freq : %d MHz)\n",
			mmc_mode_name(mmc->selected_mode), mmc->tran_speed / 1000000);
	}
/*
 * TODO:
 * This code dedicates to spreadtrum emmc host controller version r7p0.
 * We must change it, as it too complicate to understand.
 * Maybe we can use dts to handle the clock related problem.
 */

	debugf("mmc->tran_speed:%d,blksz:%d\n",
	       mmc->tran_speed, mmc->read_bl_len);

	/* Fix the block length for DDR mode */
	if (mmc->ddr_mode) {
		mmc->read_bl_len = MMC_MAX_BLOCK_LEN;
		mmc->write_bl_len = MMC_MAX_BLOCK_LEN;
	}

	/* fill in device description */
	mmc->block_dev.lun = 0;
	mmc->block_dev.type = 0;
	mmc->block_dev.blksz = mmc->read_bl_len;
	mmc->block_dev.log2blksz = LOG2(mmc->block_dev.blksz);
	mmc->block_dev.lba = lldiv(mmc->capacity, mmc->read_bl_len);
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
	sprintf(mmc->block_dev.vendor, "Man %06x Snr %04x%04x",
		mmc->cid[0] >> 24, (mmc->cid[2] & 0xffff),
		(mmc->cid[3] >> 16) & 0xffff);
	sprintf(mmc->block_dev.product, "%c%c%c%c%c%c", mmc->cid[0] & 0xff,
		(mmc->cid[1] >> 24), (mmc->cid[1] >> 16) & 0xff,
		(mmc->cid[1] >> 8) & 0xff, mmc->cid[1] & 0xff,
		(mmc->cid[2] >> 24) & 0xff);
	sprintf(mmc->block_dev.revision, "%d.%d", (mmc->cid[2] >> 20) & 0xf,
		(mmc->cid[2] >> 16) & 0xf);
#else
	mmc->block_dev.vendor[0] = 0;
	mmc->block_dev.product[0] = 0;
	mmc->block_dev.revision[0] = 0;
#endif
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBDISK_SUPPORT)
	init_part(&mmc->block_dev);
#endif
	debugf("mmc startup end\n");

	return 0;
}

static int mmc_send_if_cond(struct mmc *mmc)
{
	struct mmc_cmd cmd;
	int err;

	cmd.cmdidx = SD_CMD_SEND_IF_COND;
	/* We set the bit if the host supports voltages between 2.7 and 3.6 V */
	cmd.cmdarg = ((mmc->cfg->voltages & 0xff8000) != 0) << 8 | 0xaa;
	cmd.resp_type = MMC_RSP_R7;

	err = mmc_send_cmd(mmc, &cmd, NULL);

	if (err)
		return err;

	if ((cmd.response[0] & 0xff) != 0xaa)
		return UNUSABLE_ERR;
	else
		mmc->version = SD_VERSION_2;

	return 0;
}

/* not used any more */
int __deprecated mmc_register(struct mmc *mmc)
{
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
	printf("%s is deprecated! use mmc_create() instead.\n", __func__);
#endif
	return -1;
}

struct mmc *mmc_create(const struct mmc_config *cfg, void *priv)
{
	struct mmc *mmc;

	/* quick validation */
	if (cfg == NULL || cfg->ops == NULL || cfg->ops->send_cmd == NULL ||
	    cfg->f_min == 0 || cfg->f_max == 0 || cfg->b_max == 0)
		return NULL;

	mmc = calloc(1, sizeof(*mmc));
	if (mmc == NULL)
		return NULL;

	mmc->cfg = cfg;
	mmc->priv = priv;

	/* the following chunk was mmc_register() */

	/* Setup dsr related values */
	mmc->dsr_imp = 0;
	mmc->dsr = 0xffffffff;
	/* Setup the universal parts of the block interface just once */
	mmc->block_dev.if_type = IF_TYPE_MMC;
	mmc->block_dev.dev = cur_dev_num++;
	mmc->block_dev.removable = 1;
	mmc->block_dev.block_read = mmc_bread;
	mmc->block_dev.block_write = mmc_bwrite;
	mmc->block_dev.block_erase = mmc_berase;
	mmc->block_dev.block_sync = NULL;
	mmc->block_dev.backstage_block_write = emmc_write_backstage;
	mmc->block_dev.backstage_write_query = emmc_query_backstage;
#ifdef CONFIG_EMMC_WP
	mmc->block_dev.block_pwr_wp = mmc_set_pwr_wp;
#endif

	/* setup initial part type */
	mmc->block_dev.part_type = mmc->cfg->part_type;

	INIT_LIST_HEAD(&mmc->link);

	list_add_tail(&mmc->link, &mmc_devices);

	return mmc;
}

void mmc_destroy(struct mmc *mmc)
{
	/* only freeing memory for now */
	free(mmc);
}

#ifdef CONFIG_PARTITIONS
block_dev_desc_t *mmc_get_dev(int dev)
{
	struct mmc *mmc = find_mmc_device(dev);
	if (!mmc || mmc_init(mmc))
		return NULL;

	return &mmc->block_dev;
}
#endif

/* board-specific MMC power initializations. */
__weak void board_mmc_power_init(void)
{
}

int mmc_start_init(struct mmc *mmc)
{
	int err;

	/* we pretend there's no card when init is NULL */
	if (mmc_getcd(mmc) == 0 || mmc->cfg->ops->init == NULL) {
		mmc->has_init = 0;
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
		errorf("MMC: no card present\n");
#endif
		return NO_CARD_ERR;
	}

	if (mmc->has_init)
		return 0;

#ifdef CONFIG_FSL_ESDHC_ADAPTER_IDENT
	mmc_adapter_card_type_ident();
#endif
	board_mmc_power_init();

	/* made sure it's not NULL earlier */
	err = mmc->cfg->ops->init(mmc);

	if (err)
		return err;

	mmc->ddr_mode = 0;
	mmc_set_bus_width(mmc, 1);
	mmc_set_clock(mmc, 1);

	/* Reset the Card */
	err = mmc_go_idle(mmc);
	if (err)
		return err;

	/* The internal partition reset to user partition(0) at every CMD0 */
	mmc->part_num = 0;

	/* Test for SD version 2 */
	err = mmc_send_if_cond(mmc);

	/* Now try to get the SD card's operating condition */
	err = sd_send_op_cond(mmc);
	/* If the command timed out, we check for an MMC card */
	if (err == TIMEOUT) {
		err = mmc_send_op_cond(mmc);

		if (err) {
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
			errorf("Card did not respond to voltage select!\n");
#endif
			return UNUSABLE_ERR;
		}
	}

	if (!err)
		mmc->init_in_progress = 1;

	return err;
}

static int mmc_complete_init(struct mmc *mmc)
{
	int err = 0;

	mmc->init_in_progress = 0;
	if (mmc->op_cond_pending)
		err = mmc_complete_op_cond(mmc);

	if (!err)
		err = mmc_startup(mmc);
	if (err)
		mmc->has_init = 0;
	else
		mmc->has_init = 1;
	return err;
}

int mmc_init(struct mmc *mmc)
{
	int err = 0;
	unsigned start;

	if (mmc->has_init)
		return 0;

	start = get_timer(0);

	if (!mmc->init_in_progress)
		err = mmc_start_init(mmc);

	if (!err)
		err = mmc_complete_init(mmc);
	printf("%s: %d, time %lu\n", __func__, err, get_timer(start));
	return err;
}

int mmc_set_dsr(struct mmc *mmc, u16 val)
{
	mmc->dsr = val;
	return 0;
}

/* CPU-specific MMC initializations */
__weak int cpu_mmc_init(bd_t *bis)
{
	return -1;
}


#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)

void print_mmc_devices(char separator)
{
	struct mmc *m;
	struct list_head *entry;
	char *mmc_type;

	list_for_each(entry, &mmc_devices) {
		m = list_entry(entry, struct mmc, link);

		if (m->has_init)
			mmc_type = IS_SD(m) ? "SD" : "eMMC";
		else
			mmc_type = NULL;

		debugf("%s: %d", m->cfg->name, m->block_dev.dev);
		if (mmc_type)
			printf(" (%s)", mmc_type);

		if (entry->next != &mmc_devices) {
			debugf("%c", separator);
			if (separator != '\n')
				puts(" ");
		}
	}

	debugf("\n");
}

#else
void print_mmc_devices(char separator) { }
#endif

void set_dev_num(int num)
{
	cur_dev_num = num;
}

int get_mmc_num(void)
{
	return cur_dev_num;
}

void mmc_set_preinit(struct mmc *mmc, int preinit)
{
	mmc->preinit = preinit;
}

static void do_preinit(void)
{
	struct mmc *m;
	struct list_head *entry;

	list_for_each(entry, &mmc_devices) {
		m = list_entry(entry, struct mmc, link);

#ifdef CONFIG_FSL_ESDHC_ADAPTER_IDENT
		mmc_set_preinit(m, 1);
#endif
		if (m->preinit)
			mmc_start_init(m);
	}
}

#ifdef CONFIG_MMC_TEST
int board_mmc_test(struct mmc *mmc)
{
	int i, j;
	ulong err = 0;
	lbaint_t start = 0x800000;	/* start data address: 4GB */
	uint mrw_size = MMC_MAX_BLOCK_LEN * 16;		/* 8MByte */
	int wp_cnt = 2;	/* wp_cnt <= 32 (32 * 8Mbyte) */
	u8 cont;
	u8 srd_tst_dat = 0xa5;
	u8 mrd_tst_dat = 0xaa;

	ALLOC_CACHE_ALIGN_BUFFER(u8, wr_buf, MMC_MAX_BLOCK_LEN);
	ALLOC_CACHE_ALIGN_BUFFER(u8, rd_buf, MMC_MAX_BLOCK_LEN);
	ALLOC_CACHE_ALIGN_BUFFER(u8, mrw_buf, mrw_size);

#ifdef CONFIG_EMMC_WP
	lbaint_t wp_start;
	u8 wp_tst_dat = 0x11;	/* can't be equal to mrd_tst_dat */

	wp_start = start;
#endif

	printf("%s: test start addr: 0x" LBAF "\n", __func__, start);
	for (i = 0; i < MMC_MAX_BLOCK_LEN; i++) {
		wr_buf[i] = srd_tst_dat;
		rd_buf[i] = 0;
	}

	/* single block erase test */
	printf("%s: emmc erased memory content shall be 0x%x\n",
	       __func__, mmc->erase_mem_cont);
	if (mmc->erase_mem_cont)
		cont = 0xff;
	else
		cont = 0;

	mmc->block_dev.block_write(EMMC, start, 1, wr_buf);
	mmc->block_dev.block_erase(EMMC, start, 1);
	mmc->block_dev.block_read(EMMC, start, 1, rd_buf);
	for (i = 0, err = 0; i < MMC_MAX_BLOCK_LEN; i++) {
		if (rd_buf[i] != cont) {
			printf("single block erase test fail\n");
			err = 1;
			break;
		}
	}
	if (!err)
		printf("%s: single block erase test is successful\n", __func__);

	/* single block read test */
	mmc->block_dev.block_write(EMMC, start, 1, wr_buf);
	mmc->block_dev.block_read(EMMC, start, 1, rd_buf);
	for (i = 0, err = 0; i < MMC_MAX_BLOCK_LEN; i++) {
		if (rd_buf[i] != srd_tst_dat) {
			printf("single block read test fail\n");
			err = 1;
			break;
		}
	}
	if (!err)
		printf("%s: single block read test is successful\n", __func__);

	/* multiple block read test */
	for (i = 0; i < wp_cnt; i++) {
		memset(mrw_buf, mrd_tst_dat, mrw_size);
		mmc->block_dev.block_write(EMMC, start , 16, mrw_buf);
		mmc->block_dev.block_read(EMMC, start, 16, mrw_buf);
		for (j = 0; j < mrw_size; j++) {
			if (mrw_buf[j] != mrd_tst_dat)
				goto mul_fail;
		}
		start += 0x4000;
	}
	printf("%s: multiple block read test is successful\n", __func__);

#ifdef CONFIG_EMMC_WP
	/* emmc power-on write protection test */
	printf("%s: emm write protection test start addr: 0x" LBAF "\n",
	       __func__, wp_start);
	err = mmc->block_dev.block_pwr_wp(EMMC, wp_start, wp_cnt);
	if (err) {
		printf("emmc power-on write protection set fail\n");
		goto wp_fail;
	}

	for (i = 0; i < wp_cnt; i++) {
		memset(mrw_buf, wp_tst_dat, mrw_size);
		mmc->block_dev.block_write(EMMC, wp_start , 16, mrw_buf);
		mmc->block_dev.block_read(EMMC, wp_start, 16, mrw_buf);
		for (j = 0; j < mrw_size; j++) {
			if (mrw_buf[j] != mrd_tst_dat)
				goto wp_fail;
		}
		wp_start += 0x4000;
	}
	printf("%s: emmc write protect test is successful\n", __func__);
#endif

	return 0;

mul_fail:
	printf("%s: emmc multiple block read/write test fail\n", __func__);
#ifdef CONFIG_EMMC_WP
wp_fail:
	printf("%s: emmc power-on write protection test fail\n", __func__);
#endif
	return -1;
}
#endif /* CONFIG_MMC_TEST */

int sprd_host_init(int sdio_type)
{
	uint32_t ret;
	struct sdio_base_info *sprd_host_info;

#ifdef CONFIG_SPRD_NO_SD
	if(sdio_type==1)
		return NULL;
#endif

	sprd_host_info = get_sdcontrol_info(sdio_type);
	if (sprd_host_info->ldo_core != 0)
		regulator_enable(sprd_host_info->ldo_core);
	if (sprd_host_info->ldo_io != 0)
		regulator_enable(sprd_host_info->ldo_io);

#ifndef CONFIG_FPGA
	CHIP_REG_SET(sprd_host_info->baseclk_reg, sprd_host_info->baseclk_mask);
#endif

	debugf("mmc ldo_core:%s, ldo_io:%s\n",
	       sprd_host_info->ldo_core, sprd_host_info->ldo_io);
	udelay(1000);
	CHIP_REG_OR(sprd_host_info->ahb_enable_reg,
		    sprd_host_info->ahb_enable_bit);
	CHIP_REG_OR(sprd_host_info->ahb_reset_reg,
		    sprd_host_info->ahb_reset_bit);
	CHIP_REG_AND(sprd_host_info->ahb_reset_reg,
		     ~(sprd_host_info->ahb_reset_bit));
	if (sprd_host_info->aon_clk_reg != 0)
		CHIP_REG_OR(sprd_host_info->aon_clk_reg,
			    sprd_host_info->aon_clk_bit);
	else
		debugf("%s, no aon_clk_reg\n", __func__);
	ret = sprd_sdhci_init(sprd_host_info->regbase,
		sprd_host_info->maxclk, sprd_host_info->minclk, 0);

	debugf("%s return %d\n", __func__, ret);
	return ret;
}

void sprd_mmc_exit(int sdio_type)
{
	struct sdio_base_info *sprd_host_info = get_sdcontrol_info(sdio_type);
	struct mmc *mmc = find_mmc_device(sdio_type);

	/* TODO:  Now only support SD card power off */
	if (!mmc || (mmc && sdio_type != SD))
		return;

	mmc_set_bus_width(mmc, 1);
	mmc_set_clock(mmc, 0);

	if (sprd_host_info) {
		regulator_disable(sprd_host_info->ldo_core);
		regulator_disable(sprd_host_info->ldo_io);
	}
	printf("%s: sd power off\n", __func__);
}

struct mmc *board_sd_init(void)
{
	struct mmc *mmc;
	int ret, sd_dev;

	/*
	 * 1: sd, 0: emmc
	 * Setting cur_dev_num to 1 is used for nand.
	 * We need a good idea to deal with the cur_dev_num for nand.
	 */
	cur_dev_num = 1;
	sd_dev = cur_dev_num;
	sprd_host_init(sd_dev);
	mmc = find_mmc_device(sd_dev);
	if (mmc) {
		ret = mmc_init(mmc);
		if (ret < 0) {
			debugf("sdcard init failed %d\n", ret);
			return NULL;
		}
	} else {
		debugf("no sdcard found\n");
		return NULL;
	}

	return mmc;
}

int board_mmc_init(bd_t *bis)
{
	struct mmc *mmc;
	uint32_t ret;

	sprd_host_init(EMMC);
	mmc = find_mmc_device(EMMC);
	if (mmc)
		ret = mmc_init(mmc);
	else {
		debugf("no emmc found\n");
		return -1;
	}

	/* code as below for emmc test */
	if (!ret)
		mmc_switch_part(EMMC, 0);

#ifdef CONFIG_MMC_TEST
	board_mmc_test(mmc);
#endif

	return 0;
}

int board_mmc_initialize(bd_t *bis)
{
	debugf("%s entry\n", __func__);

	if (board_mmc_init(bis) < 0)
		cpu_mmc_init(bis);

#ifndef CONFIG_SPL_BUILD
	print_mmc_devices(',');
#endif

	do_preinit();

	return 0;
}

int mmc_initialize(bd_t *bis)
{
	INIT_LIST_HEAD(&mmc_devices);
	cur_dev_num = 0;

	return 0;
}

/*
 * Modify EXT_CSD[162] which is RST_n_FUNCTION based on the given value
 * for enable.  Note that this is a write-once field for non-zero values.
 *
 * Returns 0 on success.
 */
int mmc_set_rst_n_function(struct mmc *mmc, u8 enable)
{
	return mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL, EXT_CSD_RST_N_FUNCTION,
			  enable);
}

/* Enable emmc power-up write protection */
int mmc_enable_pwr_wp(struct mmc *mmc)
{
	int err = 0;
	ALLOC_CACHE_ALIGN_BUFFER(u8, ext_csd, MMC_MAX_BLOCK_LEN);

	err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL,
			 EXT_CSD_ERASE_GROUP_DEF, 1);
	if (err) {
		printf("%s: set EXT_CSD_ERASE_GROUP_DEF fail, err: %d\n",
		       __func__, err);
		goto out;
	}

	err = mmc_send_ext_csd(mmc, ext_csd);
	if (err) {
		printf("%s-->mmc_send_ext_csd fail, err: %d\n", __func__, err);
		goto out;
	}
	if (ext_csd[EXT_CSD_USER_WP] & EXT_CSD_US_PWR_WP_DIS) {
		printf("%s: power-on protection can't be enabled\n", __func__);
		goto out;
	}

//+hz added,the baiwei 128GB emmc protection problem
         sprintf(mmc->block_dev.product, "%c%c%c%c%c%c", mmc->cid[0] & 0xff,
             (mmc->cid[1] >> 24), (mmc->cid[1] >> 16) & 0xff,
             (mmc->cid[1] >> 8) & 0xff, mmc->cid[1] & 0xff,
             (mmc->cid[2] >> 24) & 0xff);
         //printf("%s: power-on protection : mmc->block_dev.product =%s\n", __func__, mmc->block_dev.product);
	if(strncmp(mmc->block_dev.product, "ARV21X", strlen("ARV21X")) == 0) {
		printf("%s: power-on protection ignore if use BAIWEI 128GB\n", __func__);
		is_baiwei_128GB_emmc = 1;
	}
//-hz added,the baiwei 128GB emmc protection problem

	err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL, EXT_CSD_USER_WP,
					EXT_CSD_US_PWR_WP_EN);
	if (err) {
		printf("%s-->mmc_switch fail, err: %d\n", __func__, err);
		goto out;
	}

	err = mmc_send_ext_csd(mmc, ext_csd);
	if (err) {
		printf("%s-->mmc_send_ext_csd fail, err: %d\n", __func__, err);
		goto out;
	}

	mmc->hc_wp_grp_size = 1024 *
		ext_csd[EXT_CSD_HC_ERASE_GRP_SIZE] *
		ext_csd[EXT_CSD_HC_WP_GRP_SIZE];

	printf("%s: emmc write protection group size: 0x%x\n",
	       __func__, mmc->hc_wp_grp_size);

out:
	return err;
}

/*
 * This function changes the size of boot partition and the size of rpmb
 * partition present on EMMC devices.
 *
 * Input Parameters:
 * struct *mmc: pointer for the mmc device strcuture
 * bootsize: size of boot partition
 * rpmbsize: size of rpmb partition
 *
 * Returns 0 on success.
 */

int mmc_boot_partition_size_change(struct mmc *mmc, unsigned long bootsize,
				unsigned long rpmbsize)
{
	int err;
	struct mmc_cmd cmd;

	/* Only use this command for raw EMMC moviNAND. Enter backdoor mode */
	cmd.cmdidx = MMC_CMD_RES_MAN;
	cmd.resp_type = MMC_RSP_R1b;
	cmd.cmdarg = MMC_CMD62_ARG1;

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err) {
		debug("mmc_boot_partition_size_change: Error1 = %d\n", err);
		return err;
	}

	/* Boot partition changing mode */
	cmd.cmdidx = MMC_CMD_RES_MAN;
	cmd.resp_type = MMC_RSP_R1b;
	cmd.cmdarg = MMC_CMD62_ARG2;

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err) {
		debug("mmc_boot_partition_size_change: Error2 = %d\n", err);
		return err;
	}
	/* boot partition size is multiple of 128KB */
	bootsize = (bootsize * 1024) / 128;

	/* Arg: boot partition size */
	cmd.cmdidx = MMC_CMD_RES_MAN;
	cmd.resp_type = MMC_RSP_R1b;
	cmd.cmdarg = bootsize;

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err) {
		debug("mmc_boot_partition_size_change: Error3 = %d\n", err);
		return err;
	}
	/* RPMB partition size is multiple of 128KB */
	rpmbsize = (rpmbsize * 1024) / 128;
	/* Arg: RPMB partition size */
	cmd.cmdidx = MMC_CMD_RES_MAN;
	cmd.resp_type = MMC_RSP_R1b;
	cmd.cmdarg = rpmbsize;

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err) {
		debug("mmc_boot_partition_size_change: Error4 = %d\n", err);
		return err;
	}
	return 0;
}

/*
 * Modify EXT_CSD[177] which is BOOT_BUS_WIDTH
 * based on the passed in values for BOOT_BUS_WIDTH, RESET_BOOT_BUS_WIDTH
 * and BOOT_MODE.
 *
 * Returns 0 on success.
 */
int mmc_set_boot_bus_width(struct mmc *mmc, u8 width, u8 reset, u8 mode)
{
	int err;

	err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL, EXT_CSD_BOOT_BUS_WIDTH,
			 EXT_CSD_BOOT_BUS_WIDTH_MODE(mode) |
			 EXT_CSD_BOOT_BUS_WIDTH_RESET(reset) |
			 EXT_CSD_BOOT_BUS_WIDTH_WIDTH(width));

	if (err)
		return err;
	return 0;
}

/*
 * Modify EXT_CSD[179] which is PARTITION_CONFIG (formerly BOOT_CONFIG)
 * based on the passed in values for BOOT_ACK, BOOT_PARTITION_ENABLE and
 * PARTITION_ACCESS.
 *
 * Returns 0 on success.
 */
int mmc_set_part_conf(struct mmc *mmc, u8 ack, u8 part_num, u8 access)
{
	int err;

	err = mmc_switch(mmc, EXT_CSD_CMD_SET_NORMAL, EXT_CSD_PART_CONF,
			 EXT_CSD_BOOT_ACK(ack) |
			 EXT_CSD_BOOT_PART_NUM(part_num) |
			 EXT_CSD_PARTITION_ACCESS(access));

	if (err)
		return err;
	return 0;
}

/*
 * This function shall form and send the commands to open / close the
 * boot partition specified by user.
 *
 * Input Parameters:
 * ack: 0x0 - No boot acknowledge sent (default)
 *	0x1 - Boot acknowledge sent during boot operation
 * part_num: User selects boot data that will be sent to master
 *	0x0 - Device not boot enabled (default)
 *	0x1 - Boot partition 1 enabled for boot
 *	0x2 - Boot partition 2 enabled for boot
 * access: User selects partitions to access
 *	0x0 : No access to boot partition (default)
 *	0x1 : R/W boot partition 1
 *	0x2 : R/W boot partition 2
 *	0x3 : R/W Replay Protected Memory Block (RPMB)
 *
 * Returns 0 on success.
 */
int mmc_boot_part_access(struct mmc *mmc, u8 ack, u8 part_num, u8 access)
{
	int err;
	struct mmc_cmd cmd;

	/* Boot ack enable, boot partition enable , boot partition access */
	cmd.cmdidx = MMC_CMD_SWITCH;
	cmd.resp_type = MMC_RSP_R1b;

	cmd.cmdarg = (MMC_SWITCH_MODE_WRITE_BYTE << 24) |
			(EXT_CSD_PART_CONF << 16) |
			((EXT_CSD_BOOT_ACK(ack) |
			EXT_CSD_BOOT_PART_NUM(part_num) |
			EXT_CSD_PARTITION_ACCESS(access)) << 8);

	err = mmc_send_cmd(mmc, &cmd, NULL);
	if (err) {
		if (access)
			debug("mmc boot partition#%d open fail:Error1 = %d\n",
			      part_num, err);
		else
			debug("mmc boot partition#%d close fail:Error = %d\n",
			      part_num, err);

		return err;
	}

	if (access) {
		/* 4bit transfer mode at booting time. */
		cmd.cmdidx = MMC_CMD_SWITCH;
		cmd.resp_type = MMC_RSP_R1b;

		cmd.cmdarg = (MMC_SWITCH_MODE_WRITE_BYTE << 24) |
				(EXT_CSD_BOOT_BUS_WIDTH << 16) |
				((1 << 0) << 8);

		err = mmc_send_cmd(mmc, &cmd, NULL);
		if (err) {
			debug("mmc boot partition#%d open fail:Error2 = %d\n",
			      part_num, err);
			return err;
		}
	}

	return 0;
}

ulong emmc_write_backstage(char part_num, uint32_t start_block,
			uint32_t num, uint8_t *buf)
{
	struct mmc *mmc = find_mmc_device(EMMC);
	int ret = 0;

	if (!mmc)
		return 0;

	if (mmc->part_num != part_num)
		mmc_switch_part(EMMC, part_num);

	mmc->part_num = part_num;
	ret = mmc_bwrite_backstage(EMMC, start_block, num, buf);

	return ret;
}

ulong emmc_query_backstage(char part_num, uint32_t num, uint8_t *buf)
{
	struct mmc *mmc = find_mmc_device(EMMC);
	int ret = 0;

	if (!mmc)
		return 0;

	if (mmc->part_num != part_num)
		mmc_switch_part(EMMC, part_num);

	mmc->part_num = part_num;

	ret = mmc_query_bwrite_backstage(EMMC, num, buf);
	if (part_num) {
		mmc->part_num = 0;
		mmc_switch_part(EMMC, 0);
	 }

	return ret;
}

u64 emmc_get_capacity(char part_num)
{
	struct mmc *mmc = find_mmc_device(EMMC);
	if (!mmc)
		return 0;

	switch (part_num) {
	case 0:
		return mmc->capacity_user;
	case 1:
	case 2:
		return mmc->capacity_boot;
	case 3:
		return mmc->capacity_rpmb;
	default:
		return 0;
	}
}

u64 mmc_get_hwpartsize(int hwpart)
{
	return emmc_get_capacity((char)hwpart);
}
