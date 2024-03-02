/*
 * Copyright 2011, Marvell Semiconductor Inc.
 * Lei Wen <leiwen@marvell.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 *
 * Back ported to the 8xx platform (from the 8260 platform) by
 * Murray.Jensen@cmst.csiro.au, 27-Jan-01.
 */

/*
 * TODO: Now this code only support 64-bit system address and host controller
 * version 4.10.
 * If we want to support other case, these codes must be changed.
 */

#include <common.h>
#include <malloc.h>
#include <mmc.h>
#include <sprd_sdhci_r11.h>
#include <asm/arch/common.h>
#include <linux/errno.h>

uint32_t (*sdhci_get_delay)(uint32_t device_type) = NULL;

#if defined(CONFIG_FIXED_SDHCI_ALIGNED_BUFFER)
void *aligned_buffer = (void *)CONFIG_FIXED_SDHCI_ALIGNED_BUFFER;
#else
void *aligned_buffer;
#endif

static void sdhci_reset(struct sdhci_host *host, u8 mask)
{
	unsigned long timeout;
	u8 tmp = 0;
	/* Wait max 100 ms */
	timeout = 100;
	tmp = sdhci_readb(host, SDHCI_SOFTWARE_RESET);
	tmp |= mask;
	sdhci_writeb(host, tmp, SDHCI_SOFTWARE_RESET);
	while (sdhci_readb(host, SDHCI_SOFTWARE_RESET) & mask) {
		if (timeout == 0) {
			printf("%s: Reset 0x%x never completed.\n",
			       __func__, (int)mask);
			return;
		}
		timeout--;
		udelay(1000);
	}
}

static void sdhci_cmd_done(struct sdhci_host *host, struct mmc_cmd *cmd)
{
	int i;
	if (cmd->resp_type & MMC_RSP_136) {
		/* CRC is stripped so we need to do some shifting. */
		for (i = 0; i < 4; i++) {
			cmd->response[i] = sdhci_readl(host,
					SDHCI_RESPONSE + (3 - i) * 4) << 8;
			if (i != 3)
				cmd->response[i] |=
					sdhci_readb(host, SDHCI_RESPONSE +
						    (3 - i) * 4 - 1);
		}
	} else {
		cmd->response[0] = sdhci_readl(host, SDHCI_RESPONSE);
	}
}

static void sdhci_transfer_pio(struct sdhci_host *host, struct mmc_data *data)
{
	int i;
	char *offs;
	for (i = 0; i < data->blocksize; i += 4) {
		offs = data->dest + i;
		if (data->flags == MMC_DATA_READ)
			*(u32 *)offs = sdhci_readl(host, SDHCI_BUFFER);
		else
			sdhci_writel(host, *(u32 *)offs, SDHCI_BUFFER);
	}
}

static int sdhci_transfer_data(struct sdhci_host *host, struct mmc_data *data,
				unsigned int start_addr)
{
	unsigned int stat, rdy, mask, timeout, block = 0;
#ifdef CONFIG_MMC_SDMA
	unsigned char ctrl;
	ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL_REG1);
	ctrl &= ~SDHCI_CTRL_DMA_MASK;
	sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL_REG1);
#endif

	/*
	 * TODO:
	 * Maybe 'timeout = 1000000' is okay, but someone change it to
	 * '90000000'. It's better if he or she can tell us what happend?
	 */
	timeout = 90000000;
	rdy = SDHCI_INT_SPACE_AVAIL | SDHCI_INT_DATA_AVAIL;
	mask = SDHCI_DATA_AVAILABLE | SDHCI_SPACE_AVAILABLE;

	do {
		stat = sdhci_readl(host, SDHCI_INT_STATUS);
		if (stat & SDHCI_INT_ERROR) {
			printf("%s: Error detected in status(0x%X)!\n",
			       __func__, stat);
			return -1;
		}
		if (stat & rdy) {
			if (!(sdhci_readl(host, SDHCI_PRESENT_STATE) & mask))
				continue;
			sdhci_writel(host, rdy, SDHCI_INT_STATUS);
			sdhci_transfer_pio(host, data);
			data->dest += data->blocksize;
			if (++block >= data->blocks)
				break;
		}
#ifdef CONFIG_MMC_SDMA
		if (stat & SDHCI_INT_DMA_END) {
			sdhci_writel(host, SDHCI_INT_DMA_END, SDHCI_INT_STATUS);
			start_addr &= ~(SDHCI_DEFAULT_BOUNDARY_SIZE - 1);
			start_addr += SDHCI_DEFAULT_BOUNDARY_SIZE;
			sdhci_writel(host,
				     (u32)(((u64)start_addr) & 0xFFFFFFFF),
				      SDHCI_DMA_ADDRESS_LOW);
			sdhci_writel(host,
				     (u32)(((u64)start_addr >> 32) &
				     0xFFFFFFFF), SDHCI_DMA_ADDRESS_HIGH);
		}
#endif
		if (timeout-- > 0)
			udelay(10);
		else
			return -1;
	} while (!(stat & SDHCI_INT_DATA_END));

	return 0;
}

/*
 * No command will be sent by driver if card is busy, so driver must wait
 * for card ready state.
 * Every time when card is busy after timeout then (last) timeout value will be
 * increased twice but only if it doesn't exceed global defined maximum.
 * Each function call will use last timeout value. Max timeout can be redefined
 * in board config file.
 */
#ifndef CONFIG_SDHCI_CMD_MAX_TIMEOUT
#define CONFIG_SDHCI_CMD_MAX_TIMEOUT		32000
#endif
#define CONFIG_SDHCI_CMD_DEFAULT_TIMEOUT	1000

static int sdhci_send_command(struct mmc *mmc, struct mmc_cmd *cmd,
	struct mmc_data *data)
{
	struct sdhci_host *host = mmc->priv;
	unsigned int stat = 0;
	int ret = 0;
	int trans_bytes = 0, is_aligned = 1;
	u32 mask, flags, mode;
	unsigned int time = 0;
	unsigned long start_addr = 0;
	int mmc_dev = mmc->block_dev.dev;

	unsigned int ultemp = 0;

	/* Timeout unit - ms */
	static unsigned int cmd_timeout = CONFIG_SDHCI_CMD_DEFAULT_TIMEOUT;

	unsigned start = get_timer(0);
	unsigned int timeout = 0;

	sdhci_writel(host, SDHCI_INT_ALL_MASK, SDHCI_INT_STATUS);
	mask = SDHCI_CMD_INHIBIT | SDHCI_DATA_INHIBIT;

	udelay(1000);
	/* We shouldn't wait for data inihibit for stop commands, even
	   though they might use busy signaling */
	if (cmd->cmdidx == MMC_CMD_STOP_TRANSMISSION)
		mask &= ~SDHCI_DATA_INHIBIT;

	while (sdhci_readl(host, SDHCI_PRESENT_STATE) & mask) {
		if (time >= cmd_timeout) {
			printf("%s: MMC: %d busy ", __func__, mmc_dev);
			if (2 * cmd_timeout <= CONFIG_SDHCI_CMD_MAX_TIMEOUT) {
				cmd_timeout += cmd_timeout;
				printf("timeout increasing to: %u ms.\n",
				       cmd_timeout);
				sdio_dump(host->ioaddr);
			} else {
				printf("timeout.\n");
				sdio_dump(host->ioaddr);
				return COMM_ERR;
			}
		}
		time++;
		udelay(10000);
	}

	mask = SDHCI_INT_RESPONSE;
	if (!(cmd->resp_type & MMC_RSP_PRESENT)) {
		flags = SDHCI_CMD_RESP_NONE;
	} else if (cmd->resp_type & MMC_RSP_136) {
		flags = SDHCI_CMD_RESP_LONG;
	} else if (cmd->resp_type & MMC_RSP_BUSY) {
		flags = SDHCI_CMD_RESP_SHORT_BUSY;
		mask |= SDHCI_INT_DATA_END;
	} else {
		flags = SDHCI_CMD_RESP_SHORT;
	}

	if (cmd->resp_type & MMC_RSP_CRC)
		flags |= SDHCI_CMD_CRC;
	if (cmd->resp_type & MMC_RSP_OPCODE)
		flags |= SDHCI_CMD_INDEX;
	if (data)
		flags |= SDHCI_CMD_DATA;

	sdhci_writew(host, 0x080e, SDHCI_TIMEOUT_CONTROL);

	/* Set Transfer mode regarding to data flag */
	if (data != 0) {
		mode = SDHCI_TRNS_BLK_CNT_EN;
		trans_bytes = data->blocks * data->blocksize;
		if (data->blocks > 1)
			mode |= SDHCI_TRNS_MULTI;

		if (data->flags == MMC_DATA_READ)
			mode |= SDHCI_TRNS_READ;

#ifdef CONFIG_MMC_SDMA
		if (data->flags == MMC_DATA_READ)
			start_addr = (unsigned long)data->dest;
		else
			start_addr = (unsigned long)data->src;

		if ((host->quirks & SDHCI_QUIRK_32BIT_DMA_ADDR) &&
		    (start_addr & 0x7) != 0x0) {
			is_aligned = 0;
			start_addr = (unsigned long)aligned_buffer;
			if (data->flags != MMC_DATA_READ)
				memcpy(aligned_buffer, data->src, trans_bytes);
		}

#if defined(CONFIG_FIXED_SDHCI_ALIGNED_BUFFER)
		/*
		 * Always use this bounce-buffer when
		 * CONFIG_FIXED_SDHCI_ALIGNED_BUFFER is defined
		 */
		is_aligned = 0;
		start_addr = (unsigned long)aligned_buffer;
		if (data->flags != MMC_DATA_READ)
			memcpy(aligned_buffer, data->src, trans_bytes);
#endif
		/*
		 * TODO:
		 * Now this code only support 64-bit system address and host
		 * controller version 4.10. If we want to support other cases,
		 * these codes must be changed.
		 */
		sdhci_writel(host, (u32) (((u64) start_addr) & 0xFFFFFFFF),
			     SDHCI_DMA_ADDRESS_LOW);
		sdhci_writel(host, (u32) (((u64)start_addr >> 32) & 0xFFFFFFFF),
			     SDHCI_DMA_ADDRESS_HIGH);

		mode |= SDHCI_TRNS_DMA;
#endif
		sdhci_writew(host,
			     SDHCI_MAKE_BLKSZ(SDHCI_DEFAULT_BOUNDARY_ARG,
			     data->blocksize),
			     SDHCI_BLOCK_SIZE);
		sdhci_writel(host, data->blocks, SDHCI_BLOCK_COUNT);
		ultemp = mode | (SDHCI_MAKE_CMD(cmd->cmdidx, flags) << 16);
	} else {
		ultemp = SDHCI_DEFAULT_TR_MODE;
		ultemp = ultemp | (SDHCI_MAKE_CMD(cmd->cmdidx, flags) << 16);
	}

	sdhci_writel(host, cmd->cmdarg, SDHCI_ARGUMENT);

#ifdef CONFIG_MMC_SDMA
/* flush cache operation is different between X86 and ARM */
#ifndef CONFIG_X86
	flush_cache(start_addr, trans_bytes);
#else
	if (!data)
		flush_dcache_range((unsigned long)start_addr,
				   (unsigned long)(start_addr+trans_bytes));
#endif
#endif /* CONFIG_MMC_SDMA */

	sdhci_writel(host, ultemp, SDHCI_TRANSFER_MODE);
	if(cmd->cmdidx == MMC_CMD_ERASE)
		timeout = 10 * 1000; /* erase timeout 10s */
	else
		timeout = 3 * 1000; /* others timeout 3s */

	start = get_timer(0);
	do {
		stat = sdhci_readl(host, SDHCI_INT_STATUS);
		if (stat & SDHCI_INT_ERROR)
			break;
	} while (((stat & mask) != mask) &&
		 (get_timer(start) < timeout));

	if (get_timer(start) >= timeout) {
		if (host->quirks & SDHCI_QUIRK_BROKEN_R1B)
			return 0;
		else {
			printf("%s: Timeout %lu for status update!\n",
				__func__, get_timer(start));
			sdio_dump(host->ioaddr);
			return TIMEOUT;
		}
	}

	if ((stat & (SDHCI_INT_ERROR | mask)) == mask) {
		sdhci_cmd_done(host, cmd);
		sdhci_writel(host, mask, SDHCI_INT_STATUS);
	} else {
		printf("%s: ret = -1, interrupt status: 0x%x\n", __func__, stat);
		ret = -1;
	}

	if (!ret && data)
		ret = sdhci_transfer_data(host, data, start_addr);

	/*
	 * TODO:
	 * Someone change dealy value from 1000 to 800000, we don't know why.
	 * Maybe we can try 1000 instead of 800000.
	 */
	if (host->quirks & SDHCI_QUIRK_WAIT_SEND_CMD)
		udelay(800000);

	stat = sdhci_readl(host, SDHCI_INT_STATUS);
	sdhci_writel(host, SDHCI_INT_ALL_MASK, SDHCI_INT_STATUS);
	if (!ret) {
		if ((host->quirks & SDHCI_QUIRK_32BIT_DMA_ADDR) &&
		    !is_aligned && (data->flags == MMC_DATA_READ))
			memcpy(data->dest, aligned_buffer, trans_bytes);
		if (data->flags == MMC_DATA_READ)
			invalidate_dcache_range(start_addr, start_addr + trans_bytes);
		return 0;
	}
	sdhci_reset(host, SDHCI_RESET_CMD);
	sdhci_reset(host, SDHCI_RESET_DATA);
	printf("%s interrupt status: 0x%x, CMD%d, delay: 0x%x\n", __func__,
		stat, cmd->cmdidx, sdhci_readl(host, SDHCI_DLL_DLY));
	if (stat & SDHCI_INT_TIMEOUT)
		return TIMEOUT;
	else
		return COMM_ERR;
	}


int sdhci_send_command_backstage(struct mmc *mmc, struct mmc_cmd *cmd,
		       struct mmc_data *data)
{
	struct sdhci_host *host = (struct sdhci_host *)mmc->priv;
	unsigned int stat = 0;
	int trans_bytes = 0;
	u32 mask, flags, mode;
	unsigned int time = 0;
	unsigned long start_addr = 0;
	unsigned int retry = 8000000;
	int mmc_dev = mmc->block_dev.dev;

	unsigned int ultemp = 0;

	/* Timeout unit - ms */
	static unsigned int cmd_timeout = CONFIG_SDHCI_CMD_DEFAULT_TIMEOUT;

	sdhci_writel(host, SDHCI_INT_ALL_MASK, SDHCI_INT_STATUS);
	mask = SDHCI_CMD_INHIBIT | SDHCI_DATA_INHIBIT;

	udelay(1000);
	/*
	 * We shouldn't wait for data inihibit for stop commands, even
	 * though they might use busy signaling
	 */
	if (cmd->cmdidx == MMC_CMD_STOP_TRANSMISSION)
		mask &= ~SDHCI_DATA_INHIBIT;

	while (sdhci_readl(host, SDHCI_PRESENT_STATE) & mask) {
		if (time >= cmd_timeout) {
			debugf("%s: MMC: %d busy ", __func__, mmc_dev);
			if (2 * cmd_timeout <= CONFIG_SDHCI_CMD_MAX_TIMEOUT) {
				cmd_timeout += cmd_timeout;
				debugf("timeout increasing to: %u ms.\n",
				       cmd_timeout);
				sdio_dump(host->ioaddr);
			} else {
				errorf("timeout.\n");
				sdio_dump(host->ioaddr);
				return COMM_ERR;
			}
		}
		time++;
		udelay(10000);
	}

	mask = SDHCI_INT_RESPONSE;
	if (!(cmd->resp_type & MMC_RSP_PRESENT)) {
		flags = SDHCI_CMD_RESP_NONE;
	} else if (cmd->resp_type & MMC_RSP_136) {
		flags = SDHCI_CMD_RESP_LONG;
	} else if (cmd->resp_type & MMC_RSP_BUSY) {
		flags = SDHCI_CMD_RESP_SHORT_BUSY;
		mask |= SDHCI_INT_DATA_END;
	} else {
		flags = SDHCI_CMD_RESP_SHORT;
	}

	if (cmd->resp_type & MMC_RSP_CRC)
		flags |= SDHCI_CMD_CRC;
	if (cmd->resp_type & MMC_RSP_OPCODE)
		flags |= SDHCI_CMD_INDEX;
	if (data)
		flags |= SDHCI_CMD_DATA;

	sdhci_writew(host, 0x080e, SDHCI_TIMEOUT_CONTROL);

	/* Set Transfer mode regarding to data flag */
	if (data != 0) {
		mode = SDHCI_TRNS_BLK_CNT_EN;
		trans_bytes = data->blocks * data->blocksize;
		if (data->blocks > 1)
			mode |= SDHCI_TRNS_MULTI;

		if (data->flags == MMC_DATA_READ)
			mode |= SDHCI_TRNS_READ;

#ifdef CONFIG_MMC_SDMA
		if (data->flags == MMC_DATA_READ)
			start_addr = (unsigned long)data->dest;
		else
			start_addr = (unsigned long)data->src;
		if ((host->quirks & SDHCI_QUIRK_32BIT_DMA_ADDR) &&
		    (start_addr & 0x7) != 0x0) {
			start_addr = (unsigned long)aligned_buffer;
			if (data->flags != MMC_DATA_READ)
				memcpy(aligned_buffer, data->src, trans_bytes);
		}

		sdhci_writel(host, (u32) (((u64) start_addr) & 0xFFFFFFFF),
			     SDHCI_DMA_ADDRESS_LOW);
		sdhci_writel(host, (u32) (((u64)start_addr >> 32) & 0xFFFFFFFF),
			     SDHCI_DMA_ADDRESS_HIGH);

		mode |= SDHCI_TRNS_DMA;
#endif
		sdhci_writew(host,
			     SDHCI_MAKE_BLKSZ(SDHCI_DEFAULT_BOUNDARY_ARG,
			     data->blocksize),
			     SDHCI_BLOCK_SIZE);
		sdhci_writel(host, data->blocks, SDHCI_BLOCK_COUNT);
		ultemp = mode | (SDHCI_MAKE_CMD(cmd->cmdidx, flags) << 16);
	} else {
		ultemp = SDHCI_DEFAULT_TR_MODE;
		ultemp = ultemp | (SDHCI_MAKE_CMD(cmd->cmdidx, flags) << 16);
	}
	if(MMC_CMD_WRITE_MULTIPLE_BLOCK == cmd->cmdidx)//auto send stop cmd for multiple_block_write
		ultemp |= SDHCI_TRNS_ACMD12;

	sdhci_writel(host, cmd->cmdarg, SDHCI_ARGUMENT);

#ifdef CONFIG_MMC_SDMA
/* flush cache operation is different between X86 and ARM */
#ifndef CONFIG_X86
	flush_cache(start_addr, trans_bytes);
#else
	if (!data)
		flush_dcache_range((unsigned long)start_addr,
				   (unsigned long)(start_addr + trans_bytes));
#endif
#endif /* CONFIG_MMC_SDMA */

	sdhci_writel(host, ultemp, SDHCI_TRANSFER_MODE);
	do {
		stat = sdhci_readl(host, SDHCI_INT_STATUS);
		if (stat & SDHCI_INT_ERROR)
			break;
		if (--retry == 0)
			break;
	} while ((stat & mask) != mask);

	if (retry == 0) {
		if (host->quirks & SDHCI_QUIRK_BROKEN_R1B) {
			return 0;
		} else {
			errorf("%s: Timeout for status update!\n", __func__);
			sdio_dump(host->ioaddr);
			return TIMEOUT;
		}
	}

	if ((stat & (SDHCI_INT_ERROR | mask)) == mask) {
		sdhci_cmd_done(host, cmd);
		sdhci_writel(host, mask, SDHCI_INT_STATUS);
		/*do not wait for transfer complete*/
		return 0;
	}

	if (host->quirks & SDHCI_QUIRK_WAIT_SEND_CMD)
		udelay(800000);

	stat = sdhci_readl(host, SDHCI_INT_STATUS);
	sdhci_writel(host, SDHCI_INT_ALL_MASK, SDHCI_INT_STATUS);

	if (stat & SDHCI_INT_TIMEOUT) {
		sdhci_reset(host, SDHCI_RESET_CMD);
		sdhci_reset(host, SDHCI_RESET_DATA);
		return TIMEOUT;
	} else {
		sdhci_reset(host, SDHCI_RESET_CMD);
		sdhci_reset(host, SDHCI_RESET_DATA);
		return COMM_ERR;
	}
}


int sdhci_query_command_backstage(struct mmc *mmc, struct mmc_data *data)
{
	struct sdhci_host *host = (struct sdhci_host *)mmc->priv;
	unsigned int start_addr = 0;
	int ret = 0;
	unsigned int stat = 0;

	if (NULL == data)
		return -1;

	ret = sdhci_transfer_data(host, data, start_addr);

	start_addr = (unsigned int)data->src;

	stat = sdhci_readl(host, SDHCI_INT_STATUS);
	sdhci_writel(host, SDHCI_INT_ALL_MASK, SDHCI_INT_STATUS);
	if (!ret)
		return 0;

	if (stat & SDHCI_INT_TIMEOUT) {
		sdhci_reset(host, SDHCI_RESET_CMD);
		sdhci_reset(host, SDHCI_RESET_DATA);
		return TIMEOUT;
	} else {
		sdhci_reset(host, SDHCI_RESET_CMD);
		sdhci_reset(host, SDHCI_RESET_DATA);
		return COMM_ERR;
	}
}

static int sdhci_set_clock(struct mmc *mmc, unsigned int clock)
{
	struct sdhci_host *host = mmc->priv;
	unsigned int div, clk, timeout;

	sdhci_writew(host, 0, SDHCI_CLOCK_CONTROL);

	if (clock == 0)
		return 0;

	if (SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300) {
		/* Version 3.00 divisors must be a multiple of 2. */
		if (mmc->cfg->f_max <= clock) {
			div = 1;
		} else {
			for (div = 2; div < SDHCI_MAX_DIV_SPEC_300; div += 2) {
				if ((mmc->cfg->f_max / div) <= clock)
					break;
			}
		}
	} else {
		/* Version 2.00 divisors must be a power of 2. */
		for (div = 1; div < SDHCI_MAX_DIV_SPEC_200; div *= 2) {
			if ((mmc->cfg->f_max / div) <= clock)
				break;
		}
	}
	div >>= 1;

	if (host->set_clock)
		host->set_clock(host->index, div);

	clk = (div & SDHCI_DIV_MASK) << SDHCI_DIVIDER_SHIFT;
	clk |= ((div & SDHCI_DIV_HI_MASK) >> SDHCI_DIV_MASK_LEN)
	    << SDHCI_DIVIDER_HI_SHIFT;
	clk |= SDHCI_CLOCK_INT_EN;
	sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);

	/* Wait max 20 ms */
	timeout = 2000;
	while (!((clk = sdhci_readw(host, SDHCI_CLOCK_CONTROL))
		 & SDHCI_CLOCK_INT_STABLE)) {
		if (timeout == 0) {
			printf("%s: Internal clock never stabilised.\n",
			       __func__);
			return -1;
		}
		timeout--;
		udelay(1000);
	}

	clk |= SDHCI_CLOCK_CARD_EN;
	sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
	return 0;
}

static void sdhci_set_power(struct sdhci_host *host, unsigned short power)
{
	u8 pwr = 0;
	if (power != (unsigned short)-1) {
		switch (1 << power) {
		case MMC_VDD_165_195:
			pwr = SDHCI_POWER_180;
			break;
		case MMC_VDD_29_30:
		case MMC_VDD_30_31:
			pwr = SDHCI_POWER_300;
			break;
		case MMC_VDD_32_33:
		case MMC_VDD_33_34:
			pwr = SDHCI_POWER_330;
			break;
		}
	}

	if (pwr == 0) {
		sdhci_writeb(host, 0, SDHCI_POWER_CONTROL);
		return;
	}

	if (host->quirks & SDHCI_QUIRK_NO_SIMULT_VDD_AND_POWER)
		sdhci_writeb(host, pwr, SDHCI_POWER_CONTROL);

	pwr |= SDHCI_POWER_ON;

	sdhci_writeb(host, pwr, SDHCI_POWER_CONTROL);
}

static void sprd_sdhc_enable_dpll(struct sdhci_host *host)
{
	u32 tmp = 0;

	tmp = sdhci_readl(host, SDHCI_REG_32_DLL_CFG);
	tmp &= ~(SDHCI_DLL_EN | SDHCI_DLL_ALL_CPST_EN |
		SDHCI_DLL_HALF_MODE);
	sdhci_writel(host, tmp, SDHCI_REG_32_DLL_CFG);
	mdelay(1);

	tmp = sdhci_readl(host, SDHCI_REG_32_DLL_CFG);
	tmp |= SDHCI_DLL_WAIT_CNT | SDHCI_DLL_ALL_CPST_EN |
		 SDHCI_DLL_INIT_COUNT | SDHCI_DLL_PHA_INTERNAL |
		 SDHCI_DLL_CPST_THRES | SDHCI_DLL_HALF_MODE;
	sdhci_writel(host, tmp, SDHCI_REG_32_DLL_CFG);
	mdelay(1);

	tmp = sdhci_readl(host, SDHCI_REG_32_DLL_CFG);
	tmp |= SDHCI_DLL_EN;
	sdhci_writel(host, tmp, SDHCI_REG_32_DLL_CFG);
	mdelay(1);

	while ((sdhci_readl(host, SDHCI_REG_32_DLL_STS0) &
		SDHCI_DLL_LOCKED) != SDHCI_DLL_LOCKED) {
		debugf("dpll locked faile!\n");
		debugf("DLL_STS0 : 0x%x, DLL_CFG : 0x%x\n",
			 sdhci_readl(host, SDHCI_REG_32_DLL_STS0),
			 sdhci_readl(host, SDHCI_REG_32_DLL_CFG));
		debugf("DLL_DLY : 0x%x, DLL_STS1 : 0x%x\n",
			 sdhci_readl(host, SDHCI_REG_32_DLL_DLY),
			 sdhci_readl(host, SDHCI_REG_32_DLL_STS1));
		mdelay(1);
	}

	debugf("dpll locked done\n");
}

static void sdhci_set_ios(struct mmc *mmc)
{
	u32 ctrl;
	u8 clkchg_flag = 0;
	struct sdhci_host *host = mmc->priv;
#ifdef CONFIG_EMMC_HAS_DDR_MODE
	u32 timing_mode = 0;
#endif
	uint32_t delay;

	/*
	 * Someone remove this callback, which may be fix some bugs.
	 * But we don't know why.
	 */
	if (host->set_control_reg)
		host->set_control_reg(host);
	if (mmc->clock != host->clock) {
		sdhci_set_clock(mmc, mmc->clock);
		clkchg_flag = 1;
		if (mmc->selected_mode == SD_HS || mmc->selected_mode == MMC_HS_52) {
			if(sdhci_get_delay && (mmc->clock == mmc->tran_speed)) {
				delay = sdhci_get_delay(mmc->block_dev.dev);
				sdhci_writel(host, delay, SDHCI_DLL_DLY);
			}
		} else {
			delay = 0;
			sdhci_writel(host, delay, SDHCI_DLL_DLY);
		}
	}
	/* Set bus width */
	ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL_REG1);
	if (mmc->bus_width == 8) {
		ctrl &= ~SDHCI_CTRL_4BITBUS;
		if ((SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300) ||
		    (host->quirks & SDHCI_QUIRK_USE_WIDE8))
			ctrl |= SDHCI_CTRL_8BITBUS;
	} else {
		if ((SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300) ||
		    (host->quirks & SDHCI_QUIRK_USE_WIDE8))
			ctrl &= ~SDHCI_CTRL_8BITBUS;
		if (mmc->bus_width == 4)
			ctrl |= SDHCI_CTRL_4BITBUS;
		else
			ctrl &= ~SDHCI_CTRL_4BITBUS;
	}

#ifdef CONFIG_EMMC_HAS_DDR_MODE
	if (mmc->timing == MMC_MODE_DDR_52MHz) {
		timing_mode = sdhci_readw(host, SDHCI_HOST_CONTROL2);
		timing_mode |= SDHCI_TIMING_MODE_DDR52;
		sdhci_writew(host, timing_mode, SDHCI_HOST_CONTROL2);
		/*
		 * The timing delay value may be not same in different SOC.
		 * In sp9860, it's better to set the value to 0x1414753f which
		 * means as follows:
		 * clock data write line delay value is 0x3f,
		 * clock read command line delay value is 0x75,
		 * clock read data posedge delay value is 0x14,
		 * clock read data negedge delay value is 0x14.
		 */
		sdhci_writel(host, 0x1414753f, SDHCI_DLL_DLY);
	}
#endif

	/*
	 * SPRD MMC controller can not be set high speed mode, this bit must
	 * be set to zero regardless of what is the frequency of the MMC.
	 */
	ctrl &= ~SDHCI_CTRL_HISPD;
	ctrl &= ~SDHCI_CTRL_DMA_MASK;
	if (host->quirks & SDHCI_QUIRK_NO_HISPD_BIT)
		ctrl &= ~SDHCI_CTRL_HISPD;

	sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL_REG1);

	if (mmc->clock != host->clock) {
		sprd_sdhc_sd_clk_off(host);
		switch (mmc->selected_mode) {
		case MMC_HS:
		case SD_HS:
			ctrl = SDHCI_BIT_TIMING_MODE_SDR25;
			break;
		case UHS_SDR12:
			ctrl = SDHCI_BIT_TIMING_MODE_SDR12;
			break;
		case UHS_SDR25:
			ctrl = SDHCI_BIT_TIMING_MODE_SDR25;
			break;
		case UHS_SDR50:
			ctrl = SDHCI_BIT_TIMING_MODE_SDR50;
			break;
		case UHS_SDR104:
			ctrl = SDHCI_BIT_TIMING_MODE_SDR104;
			break;
		case UHS_DDR50:
			ctrl = SDHCI_BIT_TIMING_MODE_DDR50;
			break;
		case MMC_DDR_52:
			ctrl = SDHCI_BIT_TIMING_MODE_DDR50;
			break;
		case MMC_HS_200:
			ctrl = SDHCI_BIT_TIMING_MODE_HS200;
			break;
		case MMC_HS_400:
			ctrl = SDHCI_BIT_TIMING_MODE_HS400;
			break;
		case MMC_HS_400_ES:
			ctrl = SDHCI_BIT_TIMING_MODE_HS400;
		default:
			break;
		}
		sprd_sdhc_set_uhs_mode(host, ctrl);

		/* 3 open SD clock */
		sprd_sdhc_sd_clk_on(host);
		host->clock = mmc->clock;
	}

	if (mmc->clock <= 400000 || mmc->selected_mode == MMC_HS ||
			mmc->selected_mode == SD_HS || mmc->selected_mode == MMC_LEGACY ||
			mmc->selected_mode == MMC_HS_52) {
		sdhc_set_dll_invert(host, SPRD_SDHC_BIT_CMD_DLY_INV |
				SPRD_SDHC_BIT_POSRD_DLY_INV, 1);
	} else {
		sdhc_set_dll_invert(host, SPRD_SDHC_BIT_CMD_DLY_INV |
				SPRD_SDHC_BIT_POSRD_DLY_INV, 0);
	}

	if ((mmc->clock > 52000000) && (clkchg_flag == 1)) {
		sprd_sdhc_enable_dpll(host);
	}
}

int sdhci_init(struct mmc *mmc)
{
	u32 temp = 0;
	struct sdhci_host *host = mmc->priv;

	if ((host->quirks & SDHCI_QUIRK_32BIT_DMA_ADDR) && !aligned_buffer) {
		aligned_buffer = memalign(8, 512 * 1024);
		if (!aligned_buffer) {
			printf("%s: Aligned buffer alloc failed!!!\n",
			       __func__);
			return -1;
		}
	}

	sdhci_set_power(host, fls(mmc->cfg->voltages) - 1);

	if (host->quirks & SDHCI_QUIRK_NO_CD) {
		unsigned int status;

		sdhci_writel(host, SDHCI_CTRL_CD_TEST_INS | SDHCI_CTRL_CD_TEST,
			     SDHCI_HOST_CONTROL_REG1);

		status = sdhci_readl(host, SDHCI_PRESENT_STATE);
		while ((!(status & SDHCI_CARD_PRESENT)) ||
			(!(status & SDHCI_CARD_STATE_STABLE)) ||
			(!(status & SDHCI_CARD_DETECT_PIN_LEVEL)))
			status = sdhci_readl(host, SDHCI_PRESENT_STATE);
	}

	/*
	 * TODO:
	 * Now this code only support 64-bit system address and host controller
	 * version 4.10.
	 * If we want to support other case, these codes must be changed.
	 */
	temp = sdhci_readl(host, SDHCI_HOST_CONTROL_REG2);
	temp |= SDHCI_64BIT_ADDR_EN;
	sdhci_writel(host, temp, SDHCI_HOST_CONTROL_REG2);

	/* Enable only interrupts served by the SD controller */
	sdhci_writel(host, SDHCI_INT_DATA_MASK | SDHCI_INT_CMD_MASK,
		     SDHCI_INT_ENABLE);
	/*
	 * TODO:
	 * We should write '0' to SDHCI_SIGNAL_ENABLE, but somebody write
	 * other value to SDHCI_SIGNAL_ENABLE. Maybe it fixed some bugs,
	 * however, what are the bugs?
	 * It's better if someone can interpret this.
	 */
	/* Mask all sdhci interrupt sources */
	sdhci_writel(host, SDHCI_INT_DATA_MASK |
		SDHCI_INT_CMD_MASK | SDHCI_INT_ERROR, SDHCI_SIGNAL_ENABLE);

	return 0;
}

#ifdef CONFIG_MMC_SUPPORTS_TUNING
static int sprd_calc_tuning_range(struct sdhci_host *host, int *value_t)
{
	int i;
	int prev_vl = 0;
	int range_count = 0;
	u32 dll_cnt = host->dll_cnt;
	u32 mid_dll_cnt = host->mid_dll_cnt;
	struct ranges_t *ranges = host->ranges;

	/*
	 * first: 0 <= i < mid_dll_cnt
	 * tuning range: (0 ~ mid_dll_cnt) && (dll_cnt ~ dll_cnt + mid_dll_cnt)
	 */
	for (i = 0; i < mid_dll_cnt; i++) {
		if ((!prev_vl) && value_t[i] && value_t[i + dll_cnt]) {
			range_count++;
			ranges[range_count - 1].start = i;
		}

		if (value_t[i] && value_t[i + dll_cnt]) {
			ranges[range_count - 1].end = i;
			debugf("recalculate tuning ok: %d\n", i);
		} else
			debugf("recalculate tuning fail: %d\n", i);

		prev_vl = value_t[i] && value_t[i + dll_cnt];
	}

	/*
	 * second: mid_dll_cnt <= i < dll_cnt
	 * tuning range: mid_dll_cnt ~ dll_cnt
	 */
	for (i = mid_dll_cnt; i < dll_cnt; i++) {
		if ((!prev_vl) && value_t[i]) {
			range_count++;
			ranges[range_count - 1].start = i;
		}

		if (value_t[i]) {
			ranges[range_count - 1].end = i;
			debugf("recalculate tuning ok: %d\n", i);
		} else
			debugf("recalculate tuning fail: %d\n", i);

		prev_vl = value_t[i];
	}

	host->ranges = ranges;

	return range_count;
}

extern const struct sdio_base_info sdio_ctrl_info[2];
uint32_t get_delay_value_hs200(uint32_t device_type)
{
	return sdio_ctrl_info[device_type].hs200_dly;
}

extern int mmc_send_tuning(struct mmc *mmc, u32 opcode, int *cmd_error);
static sdhci_execute_tuning(struct mmc *mmc, uint opcode)
{
	struct sdhci_host *host = mmc->priv;

	unsigned long flags;
	int err = 0;
	int i = 0;
	bool value, first_vl, prev_vl = 0;
	int *value_t;
	struct ranges_t *ranges;

	int length = 0;
	unsigned int range_count = 0;
	int longest_range_len = 0;
	int longest_range = 0;
	int mid_step;
	int final_phase = 0;
	u32 dll_cfg = 0;
	u32 mid_dll_cnt = 0;
	u32 dll_cnt = 0;
	u32 dll_dly = 0;

	sdhci_reset(host, SDHCI_RESET_CMD | SDHCI_RESET_DATA);

	dll_cfg = sdhci_readl(host, SDHCI_REG_32_DLL_CFG);
	dll_cfg &= ~(0xf << 24);
	sdhci_writel(host, dll_cfg, SDHCI_REG_32_DLL_CFG);
	dll_cnt = sdhci_readl(host, SDHCI_REG_32_DLL_STS0) & 0xff;
	dll_cnt = dll_cnt << 1;
	length = (dll_cnt * 150) / 100;
	printf("dll config 0x%08x, dll count %d, tuning length: %d\n",
		 dll_cfg, dll_cnt, length);

	ranges = malloc((length + 1) * sizeof(*ranges));
	if (!ranges)
		return -ENOMEM;

	value_t = malloc((length + 1) * sizeof(*value_t));
	if (!value_t) {
		free(ranges);
		return -ENOMEM;
	}

	do {
		dll_dly = get_delay_value_hs200(0);
		host->dll_dly = dll_dly;
		dll_dly &= ~(SDHCI_CMD_DLY_MASK | SDHCI_POSRD_DLY_MASK);
		dll_dly |= (((i << 8) & SDHCI_CMD_DLY_MASK) |
				((i << 16) & SDHCI_POSRD_DLY_MASK));
		sdhci_writel(host, dll_dly, SDHCI_REG_32_DLL_DLY);

		value = !mmc_send_tuning(mmc, opcode, NULL);

		if ((!prev_vl) && value) {
			range_count++;
			ranges[range_count - 1].start = i;
		}

		if (value) {
			debugf("tuning ok: %d\n", i);
			ranges[range_count - 1].end = i;
			value_t[i] = value;
		} else {
			debugf("tuning fail: %d\n", i);
			value_t[i] = value;
		}

		prev_vl = value;
	} while (++i <= length);

	mid_dll_cnt = length - dll_cnt;
	host->dll_cnt = dll_cnt;
	host->mid_dll_cnt = mid_dll_cnt;
	host->ranges = ranges;

	first_vl = (value_t[0] && value_t[dll_cnt]);
	range_count = sprd_calc_tuning_range(host, value_t);

	if (range_count == 0) {
		errorf("all tuning phases fail!\n");
		err = -EIO;
		goto out;
	}

	if ((range_count > 1) && first_vl && value) {
		ranges[0].start = ranges[range_count - 1].start;
		range_count--;

		if (ranges[0].end >= mid_dll_cnt)
			ranges[0].end = mid_dll_cnt;
	}

	for (i = 0; i < range_count; i++) {
		int len = (ranges[i].end - ranges[i].start + 1);

		if (len < 0)
			len += dll_cnt;

		debugf("good tuning phase range %d ~ %d\n",
			 ranges[i].start, ranges[i].end);

		if (longest_range_len < len) {
			longest_range_len = len;
			longest_range = i;
		}

	}
	printf("the best tuning step range %d-%d(the length is %d)\n",
		 ranges[longest_range].start, ranges[longest_range].end,
		 longest_range_len);

	mid_step = ranges[longest_range].start + longest_range_len / 2;
	mid_step %= dll_cnt;

	dll_cfg |= 0xf << 24;
	sdhci_writel(host, dll_cfg, SDHCI_REG_32_DLL_CFG);

	if (mid_step <= dll_cnt)
		final_phase = (mid_step * 256) / dll_cnt;
	else
		final_phase = 0xff;

	host->dll_dly &= ~(SDHCI_CMD_DLY_MASK | SDHCI_POSRD_DLY_MASK);
	host->dll_dly |= (((final_phase << 8) & SDHCI_CMD_DLY_MASK) |
			((final_phase << 16) & SDHCI_POSRD_DLY_MASK));

	printf("the best step %d, phase 0x%02x, delay value 0x%08x\n",
		 mid_step, final_phase, host->dll_dly);
	sdhci_writel(host, host->dll_dly, SDHCI_REG_32_DLL_DLY);
	err = 0;

out:
	free(ranges);
	free(value_t);
	return err;
}
#endif

static const struct mmc_ops sdhci_ops = {
	.send_cmd	= sdhci_send_command,
	.set_ios	= sdhci_set_ios,
	.init		= sdhci_init,
#ifdef CONFIG_MMC_SUPPORTS_TUNING
	.execute_tuning	= sdhci_execute_tuning,
#endif
};

int add_sdhci(struct sdhci_host *host, u32 max_clk, u32 min_clk)
{
	unsigned int caps;

	host->cfg.name = host->name;
	host->cfg.ops = &sdhci_ops;

	caps = sdhci_readl(host, SDHCI_CAPABILITIES);

	/*
	 * The default value of Capabilities Register bit[25] (Voltage
	 * Support 3.0V) is 0 in SPRD host controller. So we must set
	 * this bit value manually.
	 * If the value of Voltage Support 3.0 is 0, the value of
	 * host->cfg.voltage is also 0. And then the argument of CMD41
	 * (SD_CMD_APP_SEND_OP_COND) of SD card will be 0. In this case,
	 * the OCR value of SD card can't be obtaind.
	 */
	caps |= SDHCI_CAN_VDD_300;

#ifdef CONFIG_MMC_SDMA
	if (!(caps & SDHCI_CAN_DO_SDMA)) {
		printf("%s: Your controller doesn't support SDMA!!\n",
		       __func__);
		return -1;
	}
#endif

	if (max_clk) {
		host->cfg.f_max = max_clk;
	} else {
		if (SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300)
			host->cfg.f_max = (caps & SDHCI_CLOCK_V3_BASE_MASK)
				>> SDHCI_CLOCK_BASE_SHIFT;
		else
			host->cfg.f_max = (caps & SDHCI_CLOCK_BASE_MASK)
				>> SDHCI_CLOCK_BASE_SHIFT;
		host->cfg.f_max *= 1000000;
	}
	if (host->cfg.f_max == 0) {
		printf("%s: Hardware doesn't specify base clock frequency\n",
		       __func__);
		return -1;
	}
	if (min_clk) {
		host->cfg.f_min = min_clk;
	} else {
		if (SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300)
			host->cfg.f_min = host->cfg.f_max /
				SDHCI_MAX_DIV_SPEC_300;
		else
			host->cfg.f_min = host->cfg.f_max /
				SDHCI_MAX_DIV_SPEC_200;
	}

	host->cfg.voltages = 0;
	if (caps & SDHCI_CAN_VDD_330)
		host->cfg.voltages |= MMC_VDD_32_33 | MMC_VDD_33_34;
	if (caps & SDHCI_CAN_VDD_300)
		host->cfg.voltages |= MMC_VDD_29_30 | MMC_VDD_30_31;
	if (caps & SDHCI_CAN_VDD_180)
		host->cfg.voltages |= MMC_VDD_165_195;

	if (host->quirks & SDHCI_QUIRK_BROKEN_VOLTAGE)
		host->cfg.voltages |= host->voltages;

	host->cfg.host_caps = MMC_MODE_HS | MMC_MODE_HS_52MHz | MMC_MODE_4BIT;
#ifdef CONFIG_EMMC_HAS_DDR_MODE
	host->cfg.host_caps |= MMC_MODE_DDR_52MHz;
#endif
#ifdef CONFIG_MMC_HS200_SUPPORT
	host->cfg.host_caps |= MMC_MODE_HS200;
#endif
	if (SDHCI_GET_VERSION(host) >= SDHCI_SPEC_300) {
		if (caps & SDHCI_CAN_DO_8BIT)
			host->cfg.host_caps |= MMC_MODE_8BIT;
	}
	if (host->host_caps)
		host->cfg.host_caps |= host->host_caps;

	host->cfg.b_max = CONFIG_SYS_MMC_MAX_BLK_COUNT;

	sdhci_reset(host, SDHCI_RESET_ALL);

	host->mmc = mmc_create(&host->cfg, host);
	if (host->mmc == NULL) {
		printf("%s: mmc create fail!\n", __func__);
		return -1;
	}

	return 0;
}

static char *SPRD_SDHCI_NAME = "sprd_sdhci";
int sprd_sdhci_init(u32 regbase, u32 max_clk, u32 min_clk, u32 quirks)
{
	struct sdhci_host *host = NULL;

	host = (struct sdhci_host *)malloc(sizeof(struct sdhci_host));
	if (!host) {
		printf("sdh_host malloc fail!\n");
		return 1;
	}

	/*
	 * The allocate memory of host struct must be filled with zero,
	 * if not, some member of host may point a dirty value, e.g.
	 * *host->control_reg* may be not NULL.
	 */
	memset(host, 0, sizeof(*host));

	host->name = SPRD_SDHCI_NAME;
	host->ioaddr = (void *)regbase;
	host->quirks = quirks;
	host->set_clock = NULL;
	host->version = sdhci_readw(host, SDHCI_HOST_VERSION);
	printf("%s: host version: %d\n", __func__, host->version);

	return add_sdhci(host, max_clk, min_clk);
}

void sdio_dump(void *addr)
{
	u32  i, regbase;

	printf("*****SDIO REGISTER DUMP*****\n");
	regbase = (u32)addr;
	for (i = 0; i < 8; i++) {
		printf("0x%08x, 0x%08x, 0x%08x, 0x%08x\n",
		       CHIP_REG_GET(regbase + i * 16 + 0),
		       CHIP_REG_GET(regbase + i * 16 + 4),
		       CHIP_REG_GET(regbase + i * 16 + 8),
		       CHIP_REG_GET(regbase + i * 16 + 0xc));
	}
}
