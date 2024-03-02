/******************************************************************************

  Copyright (C) 2019 Unisoc Communications Inc.

 ******************************************************************************
  File Name     : sprd_dm_spi.c
  Version       : 1.0 Beta
  Author        : rain.zhang
  Created       : 2019/11/28
  Last Modified :
  Description   : This file provides spi transmit under DM architecture.
  Function List : NA
  History       :
  1.Date        : 2019/11/28
  Author        : rain.zhang
  Modification  : Created file
******************************************************************************/

#include <common.h>
#include <asm/io.h>
#include <asm/errno.h>
#include <ubi_uboot.h>
#include <malloc.h>
#include <dm.h>
#include <spi.h>
#include <fdtdec.h>
#include <clk.h>
#include <dma.h>
#include "sprd_spi.h"
#include "sprd_dma.h"
//#include "../dma/sprd_dma.h"

static struct spi_init_param {									//use for spi work mode and related setting
	enum spi_sck_sel sck_sel;									//spi clock reverse--spi_ctl0[13]
	enum spi_tx_edge tx_edge;									//spi data shift out at clock neg/pos-- spi_ctl0[1]
	enum spi_rx_edge rx_edge;									//spi data shift in at clock neg/pos-- spi_ctl0[0]
	enum spi_msb_lsb_sel msb_lsb_sel;							//spi data shift dout and in from msb/lsb-- spi_ctl0[7]
	enum spi_transfer_mode tx_rx_mode;							//spi work in tx/rx/rxt mode-- spi_ctl1[13:12]
	enum spi_operate_mode op_mode;								//spi work in master/slave mode-- spi_ctl2[5]
	unsigned int data_width;									//spi transmit data bit number-- spi_ctl0[6:2]
	unsigned int max_speed;										//spi work speed--spi_clkd
	unsigned long base;											//spi ctl base addr
}sprd_spi_init_param;

static struct spi_transfer {
	enum spi_transfer_mode rt_mode;
	enum spi_dma_en_sel dma_en;
	unsigned int *tx_buf;
	unsigned int *rx_buf;
	unsigned int data_len;
	unsigned int dma_step;
	int  (*read_bufs)(struct sprd_spi_priv *priv, u32 block_num);//spi read function, support 8bit/16bit/32bit at the moment
	int  (*write_bufs)(struct sprd_spi_priv *priv, u32 block_num);//spi write function, support 8bit/16bit/32bit at the moment
	unsigned int dma_id[2];
}transfer;

static void sprd_spi_dump_regs(unsigned long spi_base)
{
	printf("SPI_CLKD:0x%x\n", readl(spi_base + SPI_CLKD));
	printf("SPI_CTL0:0x%x\n", readl(spi_base + SPI_CTL0));
	printf("SPI_CTL1:0x%x\n", readl(spi_base + SPI_CTL1));
	printf("SPI_CTL2:0x%x\n", readl(spi_base + SPI_CTL2));
	printf("SPI_CTL3:0x%x\n", readl(spi_base + SPI_CTL3));
	printf("SPI_CTL4:0x%x\n", readl(spi_base + SPI_CTL4));
	printf("SPI_CTL5:0x%x\n", readl(spi_base + SPI_CTL5));
	printf("SPI_INT_RAW_STS:0x%x\n", readl(spi_base + SPI_INT_RAW_STS));
	printf("SPI_INT_EN:0x%x\n", readl(spi_base + SPI_INT_EN));
	printf("SPI_STS2:0x%x\n", readl(spi_base + SPI_STS2));
	printf("SPI_DSP_WAIT:0x%x\n", readl(spi_base + SPI_DSP_WAIT));
	printf("SPI_CTL6:0x%x\n", readl(spi_base + SPI_CTL6));
	printf("SPI_CTL7:0x%x\n", readl(spi_base + SPI_CTL7));
	printf("SPI_CTL8:0x%x\n", readl(spi_base + SPI_CTL8));
	printf("SPI_CTL9:0x%x\n", readl(spi_base + SPI_CTL9));
	printf("SPI_CTL10:0x%x\n", readl(spi_base + SPI_CTL10));
	printf("SPI_CTL11:0x%x\n", readl(spi_base + SPI_CTL11));
	printf("SPI_STS6:0x%x\n", readl(spi_base + SPI_STS6));
	printf("SPI_STS7:0x%x\n", readl(spi_base + SPI_STS7));
	printf("SPI_STS8:0x%x\n", readl(spi_base + SPI_STS8));
	printf("SPI_STS9:0x%x\n", readl(spi_base + SPI_STS9));
}

void sprd_spi_set_cs(unsigned long spi_base, unsigned int spi_sel_csx, unsigned int is_low)
{
	unsigned int reg_val = readl((spi_base + SPI_CTL0));

	if (is_low)
		reg_val &= ~((1<<spi_sel_csx)<<SPI_SEL_CS_SHIFT);
	else
		reg_val |= ((1<<spi_sel_csx)<<SPI_SEL_CS_SHIFT);
	writel(reg_val, (spi_base + SPI_CTL0));
}

static void sprd_spi_set_tx_length(unsigned long spi_base, unsigned int data_len, unsigned int dummy_bit_len)
{
	unsigned int reg_val = readl((spi_base + SPI_CTL8));

	data_len &= TX_MAX_LEN_MASK;
	dummy_bit_len &= TX_DUMY_LEN_MASK;
	reg_val &= ~((TX_DUMY_LEN_MASK << SPI_TX_DUMY_LEN_SHIFT) | TX_DATA_LEN_H_MASK);
	reg_val |= ((dummy_bit_len << SPI_TX_DUMY_LEN_SHIFT) | (data_len >> SPI_TX_DATA_LEN_H_SHIFT));
	writel(reg_val, (spi_base + SPI_CTL8));
	writel((data_len & TX_DATA_LEN_L_MASK), (spi_base + SPI_CTL9));
}

static void sprd_spi_set_rx_length(unsigned long spi_base, unsigned int data_len, unsigned int dummy_bit_len)
{
	unsigned int reg_val = readl((spi_base + SPI_CTL10));

	data_len &= RX_MAX_LEN_MASK;
	dummy_bit_len &= RX_DUMY_LEN_MASK;

	reg_val &= ~((RX_DUMY_LEN_MASK << SPI_RX_DUMY_LEN_SHIFT) | RX_DATA_LEN_H_MASK);
	reg_val |= ((dummy_bit_len << SPI_RX_DUMY_LEN_SHIFT) | (data_len >> SPI_RX_DATA_LEN_H_SHIFT));
	writel(reg_val, (spi_base + SPI_CTL10));
	writel((data_len & RX_DATA_LEN_L_MASK), (spi_base + SPI_CTL11));
}

static int sprd_spi_wait_tx_finish(unsigned long spi_base)
{
	unsigned int reg_val = 0;
	unsigned int timeout = 0;

	reg_val = readl(spi_base + SPI_STS2);
	while (!(reg_val & SPI_TX_FIFO_REALLY_EMPTY)) {
		if (++timeout > SPI_TIME_OUT) {
			debug("%s: spi wait tx error, spi fifo really empty timeout\n", __func__);
			sprd_spi_dump_regs(spi_base);
			return SPI_TRANS_TIMEOUT_ERROR;
		}
		reg_val = readl(spi_base + SPI_STS2);
	}
	timeout = 0;
	reg_val = readl(spi_base + SPI_STS2);
	while ((reg_val & SPI_BUSY)) {
		if (++timeout > SPI_TIME_OUT) {
			debug("%s: spi wait tx error, spi busy timeout\n", __func__);
			sprd_spi_dump_regs(spi_base);
			return SPI_TRANS_TIMEOUT_ERROR;
		}
		reg_val = readl(spi_base + SPI_STS2);
	}
	return 0;
}

static int sprd_spi_wait_rx_finish(unsigned long spi_base)
{
	unsigned int timeout = 0;

	while (!(readl(spi_base + SPI_INT_RAW_STS) & SPI_RX_END_RAW_STS)) {
		if (++timeout > SPI_TIME_OUT) {
			debug("%s: spi wait rx error, spi rx end timeout\n", __func__);
			sprd_spi_dump_regs(spi_base);
			return SPI_TRANS_TIMEOUT_ERROR;
		}
	}
	writel(SPI_RX_END_CLR, (spi_base + SPI_INT_CLR));
	timeout = 0;
	while(readl(spi_base + SPI_STS2) & SPI_BUSY) {
		if (++timeout > SPI_TIME_OUT) {
			debug("%s: spi wait rx error, spi busy timeout\n", __func__);
			sprd_spi_dump_regs(spi_base);
			return SPI_TRANS_TIMEOUT_ERROR;
		}
	}
	return 0;
}

static void sprd_spi_fifo_rst(unsigned long spi_base)
{
	writel(0x1, (spi_base + SPI_FIFO_RST));
	writel(0x0, (spi_base + SPI_FIFO_RST));
}

static void sprd_spi_set_rtx_md(unsigned long spi_base, unsigned int rtx_md)
{
	unsigned int reg_val = readl((spi_base + SPI_CTL1));

	reg_val &= ~(SPI_RTX_MODE_MASK);
	if (rx_mode == rtx_md)
		reg_val |= SPI_RX_MODE;
	else if(tx_mode == rtx_md)
		reg_val |= SPI_TX_MODE;
	else if(rx_tx_mode == rtx_md)
		reg_val |= (SPI_RX_MODE|SPI_TX_MODE);
	writel(reg_val, (spi_base + SPI_CTL1));
}

static int sprd_spi_write_bufs_u8(struct sprd_spi_priv *priv, u32 block_num)
{
	int i;
	unsigned long spi_base = priv->base;
	u8 *tx_p = (u8 *)priv->transfer->tx_buf;

	for (i = 0; i < block_num; i++, tx_p++)
		writel(*tx_p, spi_base + SPI_TXD);
	priv->transfer->tx_buf = (unsigned int *)tx_p;
	return i;
}
static int sprd_spi_write_bufs_u16(struct sprd_spi_priv *priv, u32 block_num)
{
	int i;
	unsigned long spi_base = priv->base;
	u16 *tx_p = (u16 *)priv->transfer->tx_buf;

	for (i = 0; i < block_num; i++, tx_p++)
		writel(*tx_p, spi_base + SPI_TXD);
	priv->transfer->tx_buf = (unsigned int *)tx_p;
	return (i << 1);
}
static int sprd_spi_write_bufs_u32(struct sprd_spi_priv *priv, u32 block_num)
{
	int i;
	unsigned long spi_base = priv->base;
	u32 *tx_p = (u32 *)priv->transfer->tx_buf;

	for (i = 0; i < block_num; i++, tx_p++)
		writel(*tx_p, spi_base + SPI_TXD);
	priv->transfer->tx_buf = (unsigned int *)tx_p;
	return (i << 2);
}

static int sprd_spi_read_bufs_u8(struct sprd_spi_priv *priv, u32 block_num)
{
	int i;
	unsigned long spi_base = priv->base;
	u8 *rx_p = (u8 *)priv->transfer->rx_buf;

	for (i = 0; i < block_num; i++, rx_p++){
		while ((readl(spi_base + SPI_STS2) & SPI_RX_FIFO_REALLY_EMPTY));
		*rx_p = readl(spi_base + SPI_TXD);
	}
	priv->transfer->rx_buf = (unsigned int *)rx_p;
	return i;
}

static int sprd_spi_read_bufs_u16(struct sprd_spi_priv *priv, u32 block_num)
{
	int i;
	unsigned long spi_base = priv->base;
	u16 *rx_p = (u16 *)priv->transfer->rx_buf;

	for (i = 0; i < block_num; i++, rx_p++){
		while ((readl(spi_base + SPI_STS2) & SPI_RX_FIFO_REALLY_EMPTY));
		*rx_p = readl(spi_base + SPI_TXD);
	}
	priv->transfer->rx_buf = (unsigned int *)rx_p;
	return (i << 1);
}

static int sprd_spi_read_bufs_u32(struct sprd_spi_priv *priv, u32 block_num)
{
	int i;
	unsigned long spi_base = priv->base;
	u32 *rx_p = (u32 *)priv->transfer->rx_buf;

	for (i = 0; i < block_num; i++, rx_p++){
		while ((readl(spi_base + SPI_STS2) & SPI_RX_FIFO_REALLY_EMPTY));
		*rx_p = readl(spi_base + SPI_TXD);
	}
	priv->transfer->rx_buf = (unsigned int *)rx_p;
	return (i << 2);
}

static void sprd_spi_init(struct sprd_spi_priv *priv)
{
	unsigned long spi_base = priv->base;
	unsigned int reg_val;
	unsigned int clk_div;

	reg_val = (priv->sprd_spi_init_param->sck_sel << SPI_SCK_REV_SHIFT) | (SPI_SEL_NONE << SPI_SEL_CS_SHIFT)
				| ((priv->sprd_spi_init_param->data_width & SPI_CHNL_LEN_MASK) << SPI_CHNL_LEN_SHIFT)
				| (priv->sprd_spi_init_param->tx_edge << SPI_NG_TX_SHIFT) | (priv->sprd_spi_init_param->rx_edge);
	writel(reg_val, (spi_base + SPI_CTL0));
	writel(0x0, (spi_base + SPI_CTL1));
	writel(0x0, (spi_base + SPI_CTL2));
	writel((RX_EMPTY_THLD_DEFAULT_VALUE << RX_EMPTY_THLD_SHIFT) | RX_FULL_THLD_DEFAULT_VALUE, (spi_base + SPI_CTL3));
	writel(0x0, (spi_base + SPI_CTL4));
	writel(ITVL_NUM, (spi_base + SPI_CTL5));
	writel(0x0, (spi_base + SPI_INT_EN));
	writel(SPI_ALL_INT_CLR, (spi_base + SPI_INT_CLR));
	writel((TX_EMPTY_THLD_DEFAULT_VALUE << TX_EMPTY_THLD_SHIFT) | TX_FULL_THLD_DEFAULT_VALUE, (spi_base + SPI_CTL6));
	priv->sprd_spi_init_param->data_width = Default_BITS_PER_WORD;
	priv->transfer->dma_step = 1;
	priv->transfer->read_bufs = sprd_spi_read_bufs_u8;
	priv->transfer->write_bufs = sprd_spi_write_bufs_u8;
	clk_div = priv->spi_source_clk/(priv->sprd_spi_init_param->max_speed << 1) - 1;
	writel(clk_div, (spi_base + SPI_CLKD));
	sprd_spi_fifo_rst(spi_base);
}

static int sprd_spi_read(struct sprd_spi_priv *priv)
{
	unsigned long spi_base = priv->base;
	struct spi_transfer *transfer = priv->transfer;
	unsigned int block_num = transfer->data_len;
	unsigned int reg_val = 0;
	unsigned int trans_num = 0;
	unsigned int read_num = 0;

	sprd_spi_set_rtx_md(spi_base, rx_mode);
	reg_val = readl(spi_base + SPI_CTL4);
	reg_val &= ~(SPI_START_RX | SPRD_SPI_MAX_RECV_BLK);
	writel(reg_val, (spi_base + SPI_CTL4));
	while (block_num) {
		sprd_spi_fifo_rst(spi_base);
		trans_num = block_num > SPRD_SPI_FIFO_SIZE ? SPRD_SPI_FIFO_SIZE : block_num;
		reg_val = readl(spi_base + SPI_CTL4);
		reg_val |= trans_num;
		writel(reg_val, (spi_base + SPI_CTL4));
		reg_val = readl(spi_base + SPI_CTL4);
		reg_val |= SPI_START_RX;
		writel(reg_val, (spi_base + SPI_CTL4));
		read_num += priv->transfer->read_bufs(priv, trans_num);
		block_num -= trans_num;
		reg_val = readl(spi_base + SPI_CTL4);
		reg_val &= ~(SPI_START_RX | SPRD_SPI_MAX_RECV_BLK);
		writel(reg_val, (spi_base + SPI_CTL4));
	}
	return 0;
}

static int sprd_spi_write_read(struct sprd_spi_priv *priv)
{
	unsigned long spi_base = priv->base;
	struct spi_transfer *transfer = priv->transfer;
	unsigned int write_num = 0;
	unsigned int read_num = 0;
	unsigned int trans_num = 0;
	unsigned int block_num = transfer->data_len;
	u32 *tmp_txbuf = NULL;

	if (rx_mode == transfer->rt_mode) {
		tmp_txbuf = malloc(transfer->data_len);
		memset(tmp_txbuf, 0 , transfer->data_len);
		priv->transfer->tx_buf = tmp_txbuf;
	}

	while (block_num) {
		trans_num = block_num > SPRD_SPI_FIFO_SIZE ? SPRD_SPI_FIFO_SIZE : block_num;
		if (tx_mode == transfer->rt_mode) {
			/* The SPI device is used for TX mode only.*/
			sprd_spi_set_rtx_md(spi_base, tx_mode);
			sprd_spi_set_tx_length(spi_base, trans_num, 0);
			write_num += priv->transfer->write_bufs(priv, trans_num);
			if (SPI_TRANS_TIMEOUT_ERROR == sprd_spi_wait_tx_finish(spi_base))
				return SPI_TRANS_TIMEOUT_ERROR;
		}
		else if (rx_mode == transfer->rt_mode) {
			/* The SPI device is used for RX mode only.*/
			sprd_spi_set_rtx_md(spi_base, rx_mode);
			sprd_spi_set_tx_length(spi_base, trans_num, 0);
			sprd_spi_set_rx_length(spi_base, trans_num, 0);
			write_num += priv->transfer->write_bufs(priv, trans_num);
			if (SPI_TRANS_TIMEOUT_ERROR == sprd_spi_wait_rx_finish(spi_base))
				return SPI_TRANS_TIMEOUT_ERROR;
			read_num += priv->transfer->read_bufs(priv, trans_num);
		}
		else {
			/* The SPI device is used for both TX and RX mode.*/
			sprd_spi_set_rtx_md(spi_base, rx_tx_mode);
			sprd_spi_set_tx_length(spi_base, trans_num, 0);
			sprd_spi_set_rx_length(spi_base, trans_num, 0);
			write_num += priv->transfer->write_bufs(priv, trans_num);
			if (SPI_TRANS_TIMEOUT_ERROR == sprd_spi_wait_rx_finish(spi_base))
				return SPI_TRANS_TIMEOUT_ERROR;
			read_num += priv->transfer->read_bufs(priv, trans_num);
		}
		block_num -= trans_num;
	}

	if (rx_mode == transfer->rt_mode) {
		free(tmp_txbuf);
		priv->transfer->tx_buf = NULL;
	}

	return 0;
}

static int sprd_spi_read_write_dma(struct udevice *dev, struct sprd_spi_priv *priv)
{
	struct udevice *bus = dev->parent;
	unsigned long spi_base = priv->base;
	struct spi_transfer *transfer = priv->transfer;
	struct dma dma_tx, dma_rx;
	struct sprd_dma_cfg chancfg[2] ={{0},{0}};
	unsigned int txtmp[1];
	unsigned int trans_len = (transfer->data_len + SPRD_DMA_STEP_LEN - 1) / SPRD_DMA_STEP_LEN * SPRD_DMA_STEP_LEN;
	unsigned int fragmens_len =
		trans_len > SPRD_DMA_STEP_LEN ? SPRD_DMA_STEP_LEN : trans_len;
	unsigned int val_spi_ctrl2;
	int spi_dma_byte_len = 0, dam_datawidth = 0;
	int ret = 0;
	u32 *spi_dma_rx_buf_v = NULL;
	u32 *spi_dma_tx_buf_v = NULL;

	printf("dma_mode_transfer bengin\n");
	/* malloc rx_buf*/
	spi_dma_rx_buf_v = malloc(trans_len);

	/* malloc tx_buf*/
	spi_dma_tx_buf_v = malloc(trans_len);
	memset(spi_dma_tx_buf_v, 0 , trans_len);

	/* memcopy tx_buf to malloc tx_buf*/
	if(transfer->tx_buf){
		memcpy(spi_dma_tx_buf_v, transfer->tx_buf, transfer->data_len);
	}

	/* spi disable dma */
	val_spi_ctrl2 = readl(spi_base + SPI_CTL2);
	val_spi_ctrl2 &= ~SPI_DMA_REQ_SEL;
	val_spi_ctrl2 &= ~SPI_DMA_EN;
	writel(val_spi_ctrl2, (spi_base + SPI_CTL2));

	switch (priv->sprd_spi_init_param->data_width) {
		case 8:
			dam_datawidth = BYTE_WIDTH;
			spi_dma_byte_len = 1;
			break;
		case 16:
			dam_datawidth = SHORT_WIDTH;
			spi_dma_byte_len = 2;
			break;
		case 32:
			dam_datawidth = WORD_WIDTH;
			spi_dma_byte_len = 4;
			break;
		default:
			debug("%s: Invalid argument bits_per_word = %d\n\r\n", __func__, priv->sprd_spi_init_param->data_width);
			return SPI_BIT_WIDTH_ERROR;
	}
	if(tx_mode != transfer->rt_mode){
		if(rx_mode == transfer->rt_mode)
			sprd_spi_set_rtx_md(spi_base, rx_mode);
		else
			sprd_spi_set_rtx_md(spi_base, rx_tx_mode);

	/* rx */
		sprd_spi_set_rx_length(spi_base, trans_len, 0);

		if (dma_get_by_name(bus, "rx-chn", &dma_rx)){
			debug("%s: DMA alloc RX channel failed!\r\n", __func__);
			return SPI_GET_RX_CHN_ERROR;
		}
		if (dma_enable(&dma_rx)){
			debug("%s: DMA enable RX channel failed!\r\n", __func__);
			return SPI_ENABLE_RX_ERROR;
		}
		chancfg[0].dev_id = transfer->dma_id[0];
		chancfg[0].src_addr = (spi_base + SPI_TXD);
		chancfg[0].des_addr = spi_dma_rx_buf_v;
		chancfg[0].src_step = SPI_DMA_0_BYTE;
		chancfg[0].des_step = spi_dma_byte_len;
		chancfg[0].fragmens_len = fragmens_len;
		chancfg[0].block_len = trans_len;
		chancfg[0].transcation_len = trans_len;
		chancfg[0].datawidth = dam_datawidth;
		chancfg[0].req_mode = FRAG_REQ_MODE;
		chancfg[0].irq_mode = TRANS_DONE;
		chancfg[0].chn_pri = DMA_PRI_0;
		chancfg[0].swt_mode = DATA_ABCD;
		if (dma_receive(&dma_rx, transfer->rx_buf, &chancfg[0])){
			debug("%s: DMA set RX channel failed!\r\n", __func__);
			return SPI_CONFIG_RX_CHN_ERROR;
		}
	}
	else
		sprd_spi_set_rtx_md(spi_base, tx_mode);

	if(rx_mode != transfer->rt_mode){
		flush_dcache_range(((unsigned int)spi_dma_tx_buf_v) & (~DCACHE_BYTE_ALIGN),
			(((unsigned int)spi_dma_tx_buf_v) + trans_len + DCACHE_BYTE_ALIGN) & (~DCACHE_BYTE_ALIGN));
	}

	/* tx */
	sprd_spi_set_tx_length(spi_base, trans_len, 0);
	if (dma_get_by_name(bus, "tx-chn", &dma_tx)){
		debug("%s: DMA alloc TX channel failed!\r\n", __func__);
		return SPI_GET_TX_CHN_ERROR;
	}
	if (dma_enable(&dma_tx)){
		debug("%s: DMA enable TX channel failed!\r\n", __func__);
		return SPI_ENABLE_TX_ERROR;
	}

	chancfg[1].dev_id = transfer->dma_id[1];
	if(rx_mode == transfer->rt_mode)
		chancfg[1].src_addr = txtmp;
	else
		chancfg[1].src_addr = spi_dma_tx_buf_v;
	chancfg[1].des_addr = (spi_base + SPI_TXD);
	if(rx_mode == transfer->rt_mode)
		chancfg[1].src_step = SPI_DMA_0_BYTE;
	else
		chancfg[1].src_step = spi_dma_byte_len;
	chancfg[1].des_step = SPI_DMA_0_BYTE;
	chancfg[1].fragmens_len = fragmens_len;
	chancfg[1].block_len = trans_len;
	chancfg[1].transcation_len = trans_len;
	chancfg[1].datawidth = dam_datawidth;
	chancfg[1].req_mode = FRAG_REQ_MODE;
	chancfg[1].irq_mode = TRANS_DONE;
	chancfg[1].chn_pri = DMA_PRI_0;
	chancfg[1].swt_mode = DATA_ABCD;
	if(dma_send(&dma_tx, chancfg[1].src_addr, trans_len, &chancfg[1])){
		debug("%s: DMA enable TX channel failed!\r\n", __func__);
		return SPI_CONFIG_TX_CHN_ERROR;
	}

	writel((RX_EMPTY_THLD_DEFAULT_VALUE << RX_EMPTY_THLD_SHIFT) | (RX_FULL_THLD_DEFAULT_VALUE), (spi_base + SPI_CTL3));
	writel((TX_EMPTY_THLD_DEFAULT_VALUE << TX_EMPTY_THLD_SHIFT) | (TX_FULL_THLD_DEFAULT_VALUE), (spi_base + SPI_CTL6));

	if(tx_mode != transfer->rt_mode)
		invalidate_dcache_range(((unsigned int)spi_dma_rx_buf_v) & (~DCACHE_BYTE_ALIGN),
			(((unsigned int)spi_dma_rx_buf_v) + trans_len + DCACHE_BYTE_ALIGN) & (~DCACHE_BYTE_ALIGN));

	/* spi enable dma */
	val_spi_ctrl2 |= SPI_DMA_EN;
	writel(val_spi_ctrl2, (spi_base + SPI_CTL2));

	/*wait for dma finish*/
	if(tx_mode != transfer->rt_mode){
		if (dma_wait_transfer_done(&dma_rx,NULL)){
			debug("%s: DMA rx timeout!\r\n", __func__);
			return SPI_RX_TIMEOUT_ERROR;
		}
		if (dma_disable(&dma_rx)){
			debug("%s: DMA disable rx channel fail!\r\n", __func__);
			return SPI_DISABLE_RX_ERROR;
		}
		if (dma_free(&dma_rx)){
			debug("%s: DMA free rx channel fail!\r\n", __func__);
			return SPI_FREE_RX_ERROR;
		}
	}
	if (dma_wait_transfer_done(&dma_tx,NULL)){
		debug("%s: DMA tx timeout!\r\n", __func__);
		return SPI_TX_TIMEOUT_ERROR;
	}
	if (dma_disable(&dma_tx)){
		debug("%s: DMA disable tx channel fail!\r\n", __func__);
		return SPI_DISABLE_TX_ERROR;
	}
	if (dma_free(&dma_tx)){
		debug("%s: DMA free tx channel fail!\r\n", __func__);
		return SPI_FREE_TX_ERROR;
	}

	/*wait spi trans finish*/
	if (SPI_TRANS_TIMEOUT_ERROR == sprd_spi_wait_tx_finish(spi_base)){
		free(spi_dma_rx_buf_v);
		free(spi_dma_tx_buf_v);
		debug("%s: SPI TRANS TIMEOUT!\r\n", __func__);
		return SPI_TRANS_TIMEOUT_ERROR;
	}

	if(tx_mode != transfer->rt_mode){
		/* memcopy malloc_rx_buf to rx_buf for rx and rtx mode*/
		memcpy(transfer->rx_buf, spi_dma_rx_buf_v, transfer->data_len);
	}

	free(spi_dma_rx_buf_v);
	free(spi_dma_tx_buf_v);

	/* spi disable dma */
	val_spi_ctrl2 = readl(spi_base + SPI_CTL2);
	val_spi_ctrl2 &= ~SPI_DMA_REQ_SEL;
	val_spi_ctrl2 &= ~SPI_DMA_EN;
	writel(val_spi_ctrl2, (spi_base + SPI_CTL2));
}

static int sprd_spi_claim_bus(struct udevice *dev)
{
	struct sprd_spi_priv *priv = dev->parent->priv;
	unsigned long spi_base = priv->base;
	unsigned int spi_sel_csx = priv->chip_select;
	unsigned int is_low = 1;

	sprd_spi_set_cs(spi_base, spi_sel_csx, is_low);
	return 0;
}

static int sprd_spi_release_bus(struct udevice *dev)
{
	struct sprd_spi_priv *priv = dev->parent->priv;
	unsigned long spi_base = priv->base;
	unsigned int spi_sel_csx = priv->chip_select;
	unsigned int is_low = 0;

	sprd_spi_set_cs(spi_base, spi_sel_csx, is_low);
	return 0;
}

static int sprd_spi_set_wordlen(struct udevice *dev, unsigned int wordlen)
{
	struct sprd_spi_priv *priv = dev->parent->priv;
	unsigned long spi_base = priv->base;
	unsigned int reg_val = readl((spi_base + SPI_CTL0));

	reg_val &= ~((SPI_CHNL_LEN_MASK) << SPI_CHNL_LEN_SHIFT);
	reg_val |= ((wordlen & SPI_CHNL_LEN_MASK) << SPI_CHNL_LEN_SHIFT);
	writel(reg_val, (spi_base + SPI_CTL0));
	priv->sprd_spi_init_param->data_width = wordlen;
	switch (wordlen) {
	case 8:
		priv->transfer->dma_step = 1;
		priv->transfer->read_bufs = sprd_spi_read_bufs_u8;
		priv->transfer->write_bufs = sprd_spi_write_bufs_u8;
		break;
	case 16:
		priv->transfer->dma_step = 2;
		priv->transfer->read_bufs = sprd_spi_read_bufs_u16;
		priv->transfer->write_bufs = sprd_spi_write_bufs_u16;
		break;
	case 32:
		priv->transfer->dma_step = 4;
		priv->transfer->read_bufs = sprd_spi_read_bufs_u32;
		priv->transfer->write_bufs = sprd_spi_write_bufs_u32;
		break;
	default:
		debug("%s: Invalid argument bits_per_word = %d\n\r\n", __func__, wordlen);
		return SPI_BIT_WIDTH_ERROR;
	}
	return 0;
}

static int sprd_spi_set_speed(struct udevice *bus, uint speed)
{
	struct sprd_spi_priv *priv = dev_get_priv(bus);
	unsigned long spi_base = priv->base;
	unsigned int clk_div;

	clk_div = priv->spi_source_clk/(speed << 1) - 1;
	writel(clk_div, (spi_base + SPI_CLKD));
	return 0;
}

static int sprd_spi_set_mode(struct udevice *bus, uint mode)
{
	struct sprd_spi_priv *priv = dev_get_priv(bus);
	unsigned long spi_base = priv->base;
	uint32_t reg;

	reg = readl(spi_base + SPI_CTL0);
	reg &= (~SCK_REV_MASK)&(~NG_TX_MASK)&(~NG_RX_MASK);
	reg |= (priv->sprd_spi_init_param->sck_sel << SPI_SCK_REV_SHIFT) | (priv->sprd_spi_init_param->tx_edge << SPI_NG_TX_SHIFT) | (priv->sprd_spi_init_param->rx_edge);
	writel(reg, (spi_base + SPI_CTL0));
	return 0;
}

static int sprd_spi_xfer(struct udevice *dev, unsigned int bitlen,
			   const void *dout, void *din, unsigned long flags)
{
	struct sprd_spi_priv *priv = dev->parent->priv;
	unsigned long spi_base = priv->base;
	struct spi_transfer *transfer = priv->transfer;

	transfer->tx_buf = dout;
	transfer->rx_buf = din;
	if(transfer->tx_buf && transfer->rx_buf)
		transfer->rt_mode = rx_tx_mode;
	else if (transfer->rx_buf)
		transfer->rt_mode = rx_mode;
	else if (transfer->tx_buf)
		transfer->rt_mode = tx_mode;
	else{
		transfer->rt_mode = idle_mode;
		return SPI_BUFFER_ERROR;
	}
	if (bitlen % (priv->sprd_spi_init_param->data_width)) {
		debug("%s: bitlen not aligned! bitlen:%x, bitperword:%x \r\n", __func__, bitlen, priv->sprd_spi_init_param->data_width);
		return SPI_BITLEN_ERROR;
	}
	transfer->data_len = bitlen/(priv->sprd_spi_init_param->data_width);
	sprd_spi_fifo_rst(spi_base);
	if (transfer->dma_en)
		return sprd_spi_read_write_dma(dev, priv);
	else
		return sprd_spi_write_read(priv);

	return 0;
}

static int sprd_spi_probe(struct udevice *dev)
{
	struct sprd_spi_priv *priv = dev_get_priv(dev);
	struct clk spi_clk, clk_parent, clk_parent_freq;

	if (!priv->sprd_spi_is_init){
		if (clk_get_by_index(dev, 0, &spi_clk) < 0){
			priv->sprd_spi_is_init = 1;
			return 0;
		}
		clk_enable(&spi_clk);
		if (clk_get_by_index(dev, 1, &clk_parent) < 0){
			priv->sprd_spi_is_init = 1;
			return 0;
		}
		if (clk_get_by_index(dev, 2, &clk_parent_freq) < 0){
			priv->sprd_spi_is_init = 1;
			return 0;
		}
		if (clk_set_parent(&clk_parent, &clk_parent_freq) < 0){
			priv->sprd_spi_is_init = 1;
			return 0;
		};
		if (device_has_children(dev))
			sprd_spi_init(priv);
		priv->sprd_spi_is_init = 1;
	}
	return 0;
}

static int sprd_spi_ofdata_to_platdata(struct udevice *bus)
{
	struct sprd_spi_priv *priv = dev_get_priv(bus);
	const void *blob = gd->fdt_blob;
	ofnode node = bus->node;
	int subnode;
	int of_offset = node.of_offset;
	if(bus->parent_platdata)
		return 0;
	priv->base = (struct exynos_spi *)fdtdec_get_addr(blob, of_offset, "reg");
	if(!(priv->base))
		return SPI_OFDATA_TO_PLATDATA_ERROR;
	priv->sprd_spi_init_param = &sprd_spi_init_param;
	priv->transfer = &transfer;
	/* Use 26MHz as a suitable default */
	priv->spi_source_clk = fdtdec_get_int(blob, of_offset, "spi-source-clk", 26000000);
	priv->transfer->dma_en = fdtdec_get_int(blob, of_offset, "sprd,dma-mode", 0);
	if(priv->transfer->dma_en){
		priv->transfer->dma_id[0] = fdtdec_get_int(blob, of_offset, "sprd,rx-dma", 0);
		priv->transfer->dma_id[1] = fdtdec_get_int(blob, of_offset, "sprd,tx-dma", 0);
	}
	subnode = fdt_first_subnode(blob, of_offset);
	priv->sprd_spi_init_param->max_speed = fdtdec_get_int(blob, subnode, "spi-max-frequency", 26000000);
	priv->spi_mode_in = fdtdec_get_int(blob, subnode, "spi-mode-in", 0);
	priv->spi_mode_out = fdtdec_get_int(blob, subnode, "spi-mode-out", 0);
	switch(priv->spi_mode_out){
		case SPI_MODE0_0:
			priv->sprd_spi_init_param->sck_sel = 0;
			priv->sprd_spi_init_param->tx_edge = 0;
			priv->sprd_spi_init_param->rx_edge = 0;
			break;
		case SPI_MODE0_1:
			priv->sprd_spi_init_param->sck_sel = 0;
			priv->sprd_spi_init_param->tx_edge = 0;
			priv->sprd_spi_init_param->rx_edge = 1;
			break;
		case SPI_MODE1_0:
			priv->sprd_spi_init_param->sck_sel = 0;
			priv->sprd_spi_init_param->tx_edge = 1;
			priv->sprd_spi_init_param->rx_edge = 0;
			break;
		case SPI_MODE1_1:
			priv->sprd_spi_init_param->sck_sel = 0;
			priv->sprd_spi_init_param->tx_edge = 1;
			priv->sprd_spi_init_param->rx_edge = 1;
			break;
		case SPI_MODE2_2:
			priv->sprd_spi_init_param->sck_sel = 1;
			priv->sprd_spi_init_param->tx_edge = 1;
			priv->sprd_spi_init_param->rx_edge = 1;
			break;
		case SPI_MODE2_3:
			priv->sprd_spi_init_param->sck_sel = 1;
			priv->sprd_spi_init_param->tx_edge = 1;
			priv->sprd_spi_init_param->rx_edge = 0;
			break;
		case SPI_MODE3_2:
			priv->sprd_spi_init_param->sck_sel = 1;
			priv->sprd_spi_init_param->tx_edge = 0;
			priv->sprd_spi_init_param->rx_edge = 1;
			break;
		case SPI_MODE3_3:
			priv->sprd_spi_init_param->sck_sel = 1;
			priv->sprd_spi_init_param->tx_edge = 0;
			priv->sprd_spi_init_param->rx_edge = 0;
			break;
		default:
			priv->sprd_spi_init_param->sck_sel = 0;
			priv->sprd_spi_init_param->tx_edge = 0;
			priv->sprd_spi_init_param->rx_edge = 0;
			debug("%s: not define spi mode, set to default value: sck_sel = 0, tx_edge = 0, rx_edge = 0\r\n", __func__);
			return -EINVAL;
	}
	priv->sprd_spi_init_param->data_width = Default_BITS_PER_WORD&CHNL_LEN_MASK;
	priv->sprd_spi_is_init = 0;
	priv->chip_select = 0;

	return 0;
}

static const struct dm_spi_ops sprd_spi_ops = {
	.claim_bus		= sprd_spi_claim_bus,					/*this function is not as what uclass defined, it's used for set cs to low*/
	.release_bus	= sprd_spi_release_bus,					/*this function is not as what uclass defined, it's used for set cs to high*/
	.set_wordlen	= sprd_spi_set_wordlen,
	.xfer			= sprd_spi_xfer,
	.set_speed		= sprd_spi_set_speed,
	.set_mode		= sprd_spi_set_mode,
	//.cs_info		= sprd_spi_cs_info
};


static const struct udevice_id sprd_spi_ids[] = {
	{
		.compatible = "sprd,sc9860-spi"
	},
	{
		.compatible = "sprd,sc9863-spi"
	},
	{
		.compatible = "sprd,sc9832-spi"
	},
	{
		.compatible = "sprd,sharkl5-spi",
	},
	{
		.compatible = "sprd,sharkl5pro-spi",
	}
};

U_BOOT_DRIVER(sprd_spi) = {
	.name = "sprd_spi",
	.id = UCLASS_SPI,
	.of_match = sprd_spi_ids,
	.ops = &sprd_spi_ops,
	.ofdata_to_platdata = sprd_spi_ofdata_to_platdata,
	.priv_auto_alloc_size = sizeof(struct sprd_spi_priv),
	//.per_child_auto_alloc_size = sizeof(struct spi_slave),
	.probe = sprd_spi_probe,
};