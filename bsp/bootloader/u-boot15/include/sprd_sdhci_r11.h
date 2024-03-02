/*
 * Copyright 2011, Marvell Semiconductor Inc.
 * Lei Wen <leiwen@marvell.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 *
 * Back ported to the 8xx platform (from the 8260 platform) by
 * Murray.Jensen@cmst.csiro.au, 27-Jan-01.
 */
#ifndef __SDHCI_HW_H
#define __SDHCI_HW_H

#include <asm/arch/sdio_cfg.h>
#include <asm/io.h>
#include <mmc.h>

/*
 * Controller registers
 */

/* SPRD host controller defined */
#define SDHCI_BLOCK_COUNT	0x00

#define SDHCI_HOST_CONTROL_REG1	0x28
#define SDHCI_HOST_CONTROL_REG2	0x3C

#define SDHCI_REG_16_HOST_CTRL2		0x3E
#define SDHCI_BIT_TIMING_MODE_SDR12		0x0000
#define SDHCI_BIT_TIMING_MODE_SDR25		0x0001
#define SDHCI_BIT_TIMING_MODE_SDR50		0x0002
#define SDHCI_BIT_TIMING_MODE_SDR104	0x0003
#define SDHCI_BIT_TIMING_MODE_DDR50		0x0004
#define SDHCI_BIT_TIMING_MODE_HS200		0x0005
#define SDHCI_BIT_TIMING_MODE_HS400		0x0006
#define SDHCI_BIT_TIMING_MODE_HS400ES	0x0007


#define SDHCI_DMA_ADDRESS_LOW           0x58
#define SDHCI_DMA_ADDRESS_HIGH          0x5C

#define SDHCI_64BIT_ADDR_EN                  0x20000000
#define SDHCI_ADMA2_LEN_MODE              0x4000000
#define SDHCI_DEFAULT_TR_MODE             0x00000003

/* #define SDHCI_DMA_ADDRESS	0x00 */

#define SDHCI_BLOCK_SIZE	0x04
#define  SDHCI_MAKE_BLKSZ(dma, blksz) (((dma & 0x7) << 12) | (blksz & 0xFFF))

/* #define SDHCI_BLOCK_COUNT	0x06 */

#define SDHCI_ARGUMENT		0x08

#define SDHCI_TRANSFER_MODE	0x0C
#define  SDHCI_TRNS_DMA		0x01
#define  SDHCI_TRNS_BLK_CNT_EN	0x02
#define  SDHCI_TRNS_ACMD12	0x04
#define  SDHCI_TRNS_READ	0x10
#define  SDHCI_TRNS_MULTI	0x20

#define SDHCI_COMMAND		0x0E
#define  SDHCI_CMD_RESP_MASK	0x03
#define  SDHCI_CMD_CRC		0x08
#define  SDHCI_CMD_INDEX	0x10
#define  SDHCI_CMD_DATA		0x20
#define  SDHCI_CMD_ABORTCMD	0xC0

#define  SDHCI_CMD_RESP_NONE	0x00
#define  SDHCI_CMD_RESP_LONG	0x01
#define  SDHCI_CMD_RESP_SHORT	0x02
#define  SDHCI_CMD_RESP_SHORT_BUSY 0x03

#define SDHCI_MAKE_CMD(c, f) (((c & 0xff) << 8) | (f & 0xff))
#define SDHCI_GET_CMD(c) ((c>>8) & 0x3f)

#define SDHCI_RESPONSE		0x10

#define SDHCI_BUFFER		0x20

#define SDHCI_PRESENT_STATE	0x24
#define  SDHCI_CMD_INHIBIT	0x00000001
#define  SDHCI_DATA_INHIBIT	0x00000002
#define  SDHCI_DOING_WRITE	0x00000100
#define  SDHCI_DOING_READ	0x00000200
#define  SDHCI_SPACE_AVAILABLE	0x00000400
#define  SDHCI_DATA_AVAILABLE	0x00000800
#define  SDHCI_CARD_PRESENT	0x00010000
#define  SDHCI_CARD_STATE_STABLE	0x00020000
#define  SDHCI_CARD_DETECT_PIN_LEVEL	0x00040000
#define  SDHCI_WRITE_PROTECT	0x00080000

/* #define SDHCI_HOST_CONTROL	0x28 */
#define  SDHCI_CTRL_LED		0x01
#define  SDHCI_CTRL_4BITBUS	0x02
#define  SDHCI_CTRL_HISPD	0x04
#define  SDHCI_CTRL_DMA_MASK	0x18
#define   SDHCI_CTRL_SDMA	0x00
#define   SDHCI_CTRL_ADMA1	0x08
#define   SDHCI_CTRL_ADMA32	0x10
#define   SDHCI_CTRL_ADMA64	0x18
#define  SDHCI_CTRL_8BITBUS	0x20
#define  SDHCI_CTRL_CD_TEST_INS	0x40
#define  SDHCI_CTRL_CD_TEST	0x80

#define SDHCI_POWER_CONTROL	0x29
#define  SDHCI_POWER_ON		0x01
#define  SDHCI_POWER_180	0x0A
#define  SDHCI_POWER_300	0x0C
#define  SDHCI_POWER_330	0x0E

#define SDHCI_BLOCK_GAP_CONTROL	0x2A

#define SDHCI_WAKE_UP_CONTROL	0x2B
#define  SDHCI_WAKE_ON_INT	0x01
#define  SDHCI_WAKE_ON_INSERT	0x02
#define  SDHCI_WAKE_ON_REMOVE	0x04

#define SDHCI_CLOCK_CONTROL	0x2C
#define  SDHCI_DIVIDER_SHIFT	8
#define  SDHCI_DIVIDER_HI_SHIFT	6
#define  SDHCI_DIV_MASK	0xFF
#define  SDHCI_DIV_MASK_LEN	8
#define  SDHCI_DIV_HI_MASK	0x300
#define  SDHCI_CLOCK_CARD_EN	0x0004
#define  SDHCI_CLOCK_INT_STABLE	0x0002
#define  SDHCI_CLOCK_INT_EN	0x0001

#define SDHCI_TIMEOUT_CONTROL	0x2E

#define SDHCI_SOFTWARE_RESET	0x2F
#define  SDHCI_RESET_ALL	0x01
#define  SDHCI_RESET_CMD	0x02
#define  SDHCI_RESET_DATA	0x04

#define SDHCI_INT_STATUS	0x30
#define SDHCI_INT_ENABLE	0x34
#define SDHCI_SIGNAL_ENABLE	0x38
#define  SDHCI_INT_RESPONSE	0x00000001
#define  SDHCI_INT_DATA_END	0x00000002
#define  SDHCI_INT_DMA_END	0x00000008
#define  SDHCI_INT_SPACE_AVAIL	0x00000010
#define  SDHCI_INT_DATA_AVAIL	0x00000020
#define  SDHCI_INT_CARD_INSERT	0x00000040
#define  SDHCI_INT_CARD_REMOVE	0x00000080
#define  SDHCI_INT_CARD_INT	0x00000100
#define  SDHCI_INT_ERROR	0x00008000
#define  SDHCI_INT_TIMEOUT	0x00010000
#define  SDHCI_INT_CRC		0x00020000
#define  SDHCI_INT_END_BIT	0x00040000
#define  SDHCI_INT_INDEX	0x00080000
#define  SDHCI_INT_DATA_TIMEOUT	0x00100000
#define  SDHCI_INT_DATA_CRC	0x00200000
#define  SDHCI_INT_DATA_END_BIT	0x00400000
#define  SDHCI_INT_BUS_POWER	0x00800000
#define  SDHCI_INT_ACMD12ERR	0x01000000
#define  SDHCI_INT_ADMA_ERROR	0x02000000

#define  SDHCI_INT_NORMAL_MASK	0x00007FFF
#define  SDHCI_INT_ERROR_MASK	0xFFFF8000

#define  SDHCI_INT_CMD_MASK	(SDHCI_INT_RESPONSE | SDHCI_INT_TIMEOUT | \
		SDHCI_INT_CRC | SDHCI_INT_END_BIT | SDHCI_INT_INDEX)
#define  SDHCI_INT_DATA_MASK	(SDHCI_INT_DATA_END | SDHCI_INT_DMA_END | \
		SDHCI_INT_DATA_AVAIL | SDHCI_INT_SPACE_AVAIL | \
		SDHCI_INT_DATA_TIMEOUT | SDHCI_INT_DATA_CRC | \
		SDHCI_INT_DATA_END_BIT | SDHCI_INT_ADMA_ERROR)
#define SDHCI_INT_ALL_MASK	((unsigned int)-1)

#define SDHCI_ACMD12_ERR	0x3C

/* only for DDR52 mode*/
#define SDHCI_HOST_CONTROL2	0x3E
/*
 * The other modes(e.g. SDR12/SDR25/SDR104) are't be used,
 * but we'd better to reserve them.
 */
#define SDHCI_TIMING_MODE_DDR52	0x4


/* 3E-3F reserved */

#define SDHCI_CAPABILITIES	0x40
#define  SDHCI_TIMEOUT_CLK_MASK	0x0000003F
#define  SDHCI_TIMEOUT_CLK_SHIFT 0
#define  SDHCI_TIMEOUT_CLK_UNIT	0x00000080
#define  SDHCI_CLOCK_BASE_MASK	0x00003F00
#define  SDHCI_CLOCK_V3_BASE_MASK	0x0000FF00
#define  SDHCI_CLOCK_BASE_SHIFT	8
#define  SDHCI_MAX_BLOCK_MASK	0x00030000
#define  SDHCI_MAX_BLOCK_SHIFT  16
#define  SDHCI_CAN_DO_8BIT	0x00040000
#define  SDHCI_CAN_DO_ADMA2	0x00080000
#define  SDHCI_CAN_DO_ADMA1	0x00100000
#define  SDHCI_CAN_DO_HISPD	0x00200000
#define  SDHCI_CAN_DO_SDMA	0x00400000
#define  SDHCI_CAN_VDD_330	0x01000000
#define  SDHCI_CAN_VDD_300	0x02000000
#define  SDHCI_CAN_VDD_180	0x04000000
#define  SDHCI_CAN_64BIT	0x10000000

#define SDHCI_CAPABILITIES_1	0x44

#define SDHCI_MAX_CURRENT	0x48

/* 4C-4F reserved for more max current */

#define SDHCI_SET_ACMD12_ERROR	0x50
#define SDHCI_SET_INT_ERROR	0x52

#define SDHCI_ADMA_ERROR	0x54

/* 55-57 reserved */

#define SDHCI_ADMA_ADDRESS	0x58

/* 60-FB reserved */

#define SDHCI_SLOT_INT_STATUS	0xFC

#define SDHCI_HOST_VERSION	0xFE
#define  SDHCI_VENDOR_VER_MASK	0xFF00
#define  SDHCI_VENDOR_VER_SHIFT	8
#define  SDHCI_SPEC_VER_MASK	0x00FF
#define  SDHCI_SPEC_VER_SHIFT	0
#define   SDHCI_SPEC_100	0
#define   SDHCI_SPEC_200	1
#define   SDHCI_SPEC_300	2
#define   SDHCI_SPEC_400	3
#define   SDHCI_SPEC_410	4

#define SDHCI_GET_VERSION(x) (x->version & SDHCI_SPEC_VER_MASK)

/* The register is defined by spreadtrum self, only for DDR52 mode */
#define SDHCI_DLL_DLY	0x204
#define SDHCI_REG_32_DLL_CFG	0x200
#define SDHCI_DLL_WAIT_CNT		0xC0000000
#define SDHCI_DLL_ALL_CPST_EN	0x0F040000
#define SDHCI_DLL_EN		0x00200000
#define	SDHCI_DLL_CLR		0X00100000
#define SDHCI_DLL_HALF_MODE		0x00010000
#define	SDHCI_DLL_CPST_THRES	0x00000020
#define SDHCI_DLL_INIT_COUNT	0x00000c00
#define SDHCI_DLL_PHA_INTERNAL	0x00000003

#define SDHCI_REG_32_DLL_DLY	0x204
#define SDHCI_REG_8_DATWR_DLY	0x204
#define SDHCI_REG_8_CMDRD_DLY	0x205
#define SDHCI_REG_8_POSRD_DLY	0x206
#define SDHCI_REG_8_NEGRD_DLY	0x207

#define SDHCI_REG_32_DLL_STS0	0x210
#define SDHCI_REG_32_DLL_STS1	0x214
#define SDHCI_DLL_ERROR		0x00020000
#define SDHCI_DLL_LOCKED		0x00040000

#define SDHCI_WR_DLY_MASK		0xff
#define SDHCI_CMD_DLY_MASK		(0xff << 8)
#define SDHCI_POSRD_DLY_MASK		(0xff << 16)
#define SDHCI_NEGRD_DLY_MASK		(0xff << 24)
#define SDHCI_SDHC_DLY_TIMING(wr_dly, cmd_dly, posrd_dly, negrd_dly) \
		((wr_dly) | ((cmd_dly) << 8) | \
		((posrd_dly) << 16) | ((negrd_dly) << 24))

#define SDHCI_REG_32_DLL_DLY_OFFSET	0x208
#define SDHCI_BIT_WR_DLY_INV		(1 << 5)
#define SDHCI_BIT_CMD_DLY_INV		(1 << 13)
#define SDHCI_BIT_POSRD_DLY_INV		(1 << 21)
#define SDHCI_BIT_NEGRD_DLY_INV		(1 << 29)

/*
 * End of controller registers.
 */

#define SDHCI_MAX_DIV_SPEC_200	256
#define SDHCI_MAX_DIV_SPEC_300	2046

/*
 * quirks
 */
#define SDHCI_QUIRK_32BIT_DMA_ADDR	(1 << 0)
#define SDHCI_QUIRK_REG32_RW		(1 << 1)
#define SDHCI_QUIRK_BROKEN_R1B		(1 << 2)
#define SDHCI_QUIRK_NO_HISPD_BIT	(1 << 3)
#define SDHCI_QUIRK_BROKEN_VOLTAGE	(1 << 4)
#define SDHCI_QUIRK_NO_CD		(1 << 5)
#define SDHCI_QUIRK_WAIT_SEND_CMD	(1 << 6)
#define SDHCI_QUIRK_NO_SIMULT_VDD_AND_POWER (1 << 7)
#define SDHCI_QUIRK_USE_WIDE8		(1 << 8)

/*
 * invert
 */
#define SPRD_SDHC_REG_32_DLL_DLY_OFFSET	0x208
#define SPRD_SDHC_BIT_WR_DLY_INV		(1 << 5)
#define SPRD_SDHC_BIT_CMD_DLY_INV		(1 << 13)
#define SPRD_SDHC_BIT_POSRD_DLY_INV		(1 << 21)
#define SPRD_SDHC_BIT_NEGRD_DLY_INV		(1 << 29)


#define SDHCI_REG_16_CLK_CTRL	0x2C
#define SDHCI_BIT_IN_CLK_EN		0x0001
#define SDHCI_BIT_IN_CLK_STABLE	0x0002
#define SDHCI_BIT_SD_CLK_IN_EN	0x0004
#define SDHCI_CLK_MAX_DIV		0x3FF

#define SDHCI_WR_DLY_MASK		0xff
#define SDHCI_CMD_DLY_MASK		(0xff << 8)
#define SDHCI_POSRD_DLY_MASK		(0xff << 16)
#define SDHCI_NEGRD_DLY_MASK		(0xff << 24)

/* to make gcc happy */
struct sdhci_host;

/*
 * Host SDMA buffer boundary. Valid values from 4K to 512K in powers of 2.
 */
#define SDHCI_DEFAULT_BOUNDARY_SIZE	(512 * 1024)
#define SDHCI_DEFAULT_BOUNDARY_ARG	(7)

struct ranges_t {
	int start;
	int end;
};

struct sdhci_host {
	char *name;
	void *ioaddr;
	unsigned int quirks;
	unsigned int host_caps;
	unsigned int version;
	unsigned int clock;
	struct mmc *mmc;
	int index;

	int bus_width;

	void (*set_control_reg)(struct sdhci_host *host);
	void (*set_clock)(int dev_index, unsigned int div);
	uint	voltages;

	struct mmc_config cfg;

	u32 dll_cnt;
	u32 mid_dll_cnt;
	struct ranges_t *ranges;
	u32 dll_dly;
};

#ifndef CONFIG_MMC_SDHCI_IO_ACCESSORS
static inline void sdhci_writel(struct sdhci_host *host, u32 val, int reg)
{
	writel(val, host->ioaddr + reg);
}

static inline void sdhci_writew(struct sdhci_host *host, u16 val, int reg)
{
	writew(val, host->ioaddr + reg);
}

static inline void sdhci_writeb(struct sdhci_host *host, u8 val, int reg)
{
	writeb(val, host->ioaddr + reg);
}
static inline u32 sdhci_readl(struct sdhci_host *host, int reg)
{
	return readl(host->ioaddr + reg);
}

static inline u16 sdhci_readw(struct sdhci_host *host, int reg)
{
	return readw(host->ioaddr + reg);
}

static inline u8 sdhci_readb(struct sdhci_host *host, int reg)
{
	return readb(host->ioaddr + reg);
}

#else
static inline void sdhci_writel(struct sdhci_host *host, u32 val, int reg)
{
	writel(val, host->ioaddr + reg);
}

static inline void sdhci_writew(struct sdhci_host *host, u16 val, int reg)
{
	u32 addr;
	u32 value;
	u32 ofst;

	ofst = (reg & 0x2) << 3;
	addr = (reg & 0xFFFFFFFC);
	value = readl(host->ioaddr + addr);
	value &= ~(0xFFFF << ofst);
	value |= (val&0xFFFF) << ofst;
	writel(value, host->ioaddr + addr);
}

static inline void sdhci_writeb(struct sdhci_host *host, u8 val, int reg)
{
	u32 addr;
	u32 value;
	u32 ofst;

	ofst = (reg & 0x3) << 3;
	addr = (reg & 0xFFFFFFFC);
	value = readl(host->ioaddr + addr);
	value &= ~(0xFF << ofst);
	value |= (val & 0xFF) << ofst;
	writel(value, host->ioaddr + addr);
}

static inline u32 sdhci_readl(struct sdhci_host *host, int reg)
{
	return readl(host->ioaddr + reg);
}

static inline u16 sdhci_readw(struct sdhci_host *host, int reg)
{
	u32 ofst;
	u16  temp = 0;
	u32 addr;
	u32 value;

	ofst = (reg & 0x2) << 3;
	addr = (reg & 0xFFFFFFFC);
	value = readl(host->ioaddr + addr);
	temp = (u16)(value >> ofst);
	return temp;
}

static inline u8 sdhci_readb(struct sdhci_host *host, int reg)
{
	u32 ofst;
	u8  temp;
	u32 addr;
	u32 value;

	ofst = (reg & 0x3) << 3;
	addr = (reg & 0xFFFFFFFC);
	value = readl(host->ioaddr + addr);
	temp = (u8)(value >> ofst);
	return temp;
}
#endif

static inline void
sdhc_set_dll_invert(struct sdhci_host *host, u32 mask, int enable)
{
	u32 dll_dly_offset;

	dll_dly_offset = sdhci_readl(host, SDHCI_REG_32_DLL_DLY_OFFSET);
	if (enable)
		dll_dly_offset |= mask;
	else
		dll_dly_offset &= ~mask;

	sdhci_writel(host, dll_dly_offset, SDHCI_REG_32_DLL_DLY_OFFSET);
}

int add_sdhci(struct sdhci_host *host, u32 max_clk, u32 min_clk);
void sdio_dump(void *addr);

static inline void
sprd_sdhc_set_uhs_mode(struct sdhci_host *host, u8 mode)
{
	u16 tmp;

	tmp = sdhci_readw(host, SDHCI_REG_16_HOST_CTRL2);
	tmp &= 0xfff8;
	tmp |= mode;
	sdhci_writew(host, tmp, SDHCI_REG_16_HOST_CTRL2);
}

static inline void sprd_sdhc_sd_clk_on(struct sdhci_host *host)
{
	u16 ctrl = 0;

	ctrl = sdhci_readw(host, SDHCI_REG_16_CLK_CTRL);
	ctrl |= SDHCI_BIT_SD_CLK_IN_EN;
	sdhci_writew(host, ctrl, SDHCI_REG_16_CLK_CTRL);
}

static inline void sprd_sdhc_sd_clk_off(struct sdhci_host *host)
{
	u16 ctrl = 0;

	ctrl = sdhci_readw(host, SDHCI_REG_16_CLK_CTRL);
	ctrl &= (~SDHCI_BIT_SD_CLK_IN_EN);
	sdhci_writew(host, ctrl, SDHCI_REG_16_CLK_CTRL);
}

#endif /* __SDHCI_HW_H */