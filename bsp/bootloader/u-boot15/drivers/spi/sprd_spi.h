/******************************************************************************
 ** File Name:    sprd_spi.h                                        *
 ** Author:       mengkai.zhao                                      *
 ** DATE:         2017-08-01                                        *
 ** Copyright:    2017 Spreatrum, Incoporated. All Rights Reserved. *
 ** Description:                                                    *
 ******************************************************************************/
/******************************************************************************
 **                   Edit    History                               *
 **---------------------------------------------------------------------------*
 **    DATE         NAME            DESCRIPTION                    *
 ** 2017-08-01   mengkai.zhao       First Draft
 ** 2020-11-16   rain.zhang         modify for spi work under DM architecture
 ******************************************************************************/

#ifndef __SPRD_SPI_H__
#define __SPRD_SPI_H__

/*design for dcache*/
#define	DCACHE_BYTE_ALIGN	0x3F

/*The register offset*/
#define SPI_TXD			0x0000
#define SPI_CLKD		0x0004
#define SPI_CTL0		0x0008
#define SPI_CTL1		0x000C
#define SPI_CTL2		0x0010
#define SPI_CTL3		0x0014
#define SPI_CTL4		0x0018
#define SPI_CTL5		0x001C
#define SPI_INT_EN		0x0020
#define SPI_INT_CLR		0x0024
#define SPI_INT_RAW_STS		0x0028
#define SPI_INT_MASK_STS	0x002C
#define SPI_STS1		0x0030
#define SPI_STS2		0x0034
#define SPI_DSP_WAIT		0x0038
#define SPI_STS3		0x003C
#define SPI_CTL6		0x0040
#define SPI_STS4		0x0044
#define SPI_FIFO_RST		0x0048
#define SPI_CTL7		0x004C
#define SPI_STS5		0x0050
#define SPI_CTL8		0x0054
#define SPI_CTL9		0x0058
#define SPI_CTL10		0x005C
#define SPI_CTL11		0x0060
#define SPI_CTL12		0x0064
#define SPI_STS6		0x0068
#define SPI_STS7		0x006C
#define SPI_STS8		0x0070
#define SPI_STS9		0x0074

/* Bit define for register INT_RAW_STS */
#define SPI_RX_FIFO_EMPTY_RAW_STS	BIT(1)
#define SPI_TX_FIFO_FULL_RAW_STS	BIT(2)
#define SPI_RX_FIFO_OVERRUN_RAW_STS	BIT(4)
#define SPI_TIME_OUT_RAW_STS		BIT(5)
#define SPI_RX_FIFO_FULL_RAW_STS	BIT(6)
#define SPI_TX_FIFO_EMPTY_RAW_STS	BIT(7)
#define SPI_TX_END_RAW_STS		BIT(8)
#define SPI_RX_END_RAW_STS		BIT(9)

/* Bit define for register INT_CLR */
#define SPI_RX_FIFO_FULL_CLR		BIT(0)
#define SPI_RX_FIFO_EMPTY_CLR		BIT(1)
#define SPI_TX_FIFO_FULL_CLR		BIT(2)
#define SPI_TX_FIFO_EMPTY_CLR		BIT(3)
#define SPI_RX_FIFO_OVERRUN_CLR		BIT(4)
#define SPI_TIME_OUT_CLR		BIT(5)
#define SPI_TX_END_CLR			BIT(8)
#define SPI_RX_END_CLR			BIT(9)
#define SPI_ALL_INT_CLR			0xFFFFFFFF


/* Bit define for register STS2 */
#define SPI_RX_FIFO_FULL		BIT(0)
#define SPI_RX_FIFO_EMPTY		BIT(1)
#define SPI_TX_FIFO_FULL		BIT(2)
#define SPI_TX_FIFO_EMPTY		BIT(3)
#define SPI_RX_FIFO_REALLY_FULL		BIT(4)
#define SPI_RX_FIFO_REALLY_EMPTY	BIT(5)
#define SPI_TX_FIFO_REALLY_FULL		BIT(6)
#define SPI_TX_FIFO_REALLY_EMPTY	BIT(7)
#define SPI_BUSY			BIT(8)

/* Bit define for register ctl0 */
#define SPI_SCK_REV_SHIFT		13
#define SPI_NG_TX_SHIFT			1

/* Bit define for register ctl1 */
#define SPI_RTX_MODE_SHIFT		12
#define SPI_RTX_MODE_MASK		(0x3<<SPI_MODE_SHIFT)
#define SPI_RX_MODE			BIT(12)
#define SPI_TX_MODE			BIT(13)

/* Bit define for register ctl2 */
#define SPI_DMA_REQ_SEL			BIT(10)
#define SPI_DMA_EN			BIT(6)

/* Bit define for register ctl3 */
#define RX_EMPTY_THLD_DEFAULT_VALUE	2
#define RX_EMPTY_THLD_SHIFT		8
#define RX_FULL_THLD_DEFAULT_VALUE	16

/* Bit define for register ctl4 */
#define SPI_START_RX			BIT(9)
#define SPRD_SPI_FIFO_SIZE		32
#define SPRD_DMA_STEP_LEN		16
#define SPRD_SPI_MAX_RECV_BLK		0x1FF

/* Bit define for register ctl6 */
#define TX_EMPTY_THLD_DEFAULT_VALUE	2
#define TX_EMPTY_THLD_SHIFT		8
#define TX_FULL_THLD_DEFAULT_VALUE	16

/* Bit define for register ctl8 */
#define TX_DUMY_LEN_MASK		0x3F
#define SPI_TX_DUMY_LEN_SHIFT		4
#define TX_DATA_LEN_H_MASK		0xF
#define SPI_TX_DATA_LEN_H_SHIFT		16

/* Bit define for register ctl8 */
#define RX_DUMY_LEN_MASK		0x3F
#define SPI_RX_DUMY_LEN_SHIFT		4
#define RX_DATA_LEN_H_MASK		0xF
#define SPI_RX_DATA_LEN_H_SHIFT		16


#define SPRD_SPI_CHIP_CS_NUM		0x4
#define MAX_BITS_PER_WORD		32
#define CHNL_LEN_MASK			0x007C
#define SPI_TIME_OUT			0xFF0000
#define TX_MAX_LEN_MASK			0xFFFFF
#define TX_DATA_LEN_L_MASK		0xFFFF

#define RX_MAX_LEN_MASK			0xFFFFF
#define RX_DATA_LEN_L_MASK		0xFFFF

/* Register ctl5, for master, transmit data interval */
#define ITVL_NUM			0x9

/* Define the SPI interface mode for LCM */
#define SPIMODE_DISABLE			0
#define SPIMODE_3WIRE_9BIT_SDA		1	/* 3 wire 9 bit, cd bit, SDI/SDO share  one IO */
#define SPIMODE_3WIRE_9BIT_SDIO		2	/* 3 wire 9 bit, cd bit, SDI, SDO */
#define SPIMODE_4WIRE_8BIT_SDA		3	/* 4 wire 8 bit, cd pin, SDI/SDO share one IO */
#define SPIMODE_4WIRE_8BIT_SDIO		4	/* 4 wire 8 bit, cd pin, SDI, SDO */

#define SPI_CD_MASK			BIT(15)
#define SPI_MODE_SHIFT			3
#define SPI_MODE_MASK			(0x7<<SPI_MODE_SHIFT)
#define SW_RX_REQ_MASK			BIT(0)
#define SW_TX_REQ_MASK			BIT(1)

/* Define the clk src for SPI mode */
#define SPICLK_SEL_192M			3
#define SPICLK_SEL_154M			2
#define SPICLK_SEL_128M			1
#define SPICLK_SEL_26M			0

/*
	Define the timing mode for SPI
	the first number is tx mode,
	the second number is rx mode
	Mode 0 CPOL=0, CPHA=0
	Mode 1 CPOL=0, CPHA=1
	Mode 2 CPOL=1, CPHA=0
	Mode 3 CPOL=1, CPHA=1
	CPOL stands for clk status while spi idle(0:clk is low, 1:clk is high)
	CPHA stands for tx/rx sample at whilch clk edage(0:sample at first clk edage, 1:sample at second clk edage)
*/
#define SPI_MODE3_3			7
#define SPI_MODE3_2			6
#define SPI_MODE2_3			5
#define SPI_MODE2_2			4
#define SPI_MODE1_1			3
#define SPI_MODE1_0			2
#define SPI_MODE0_1			1
#define SPI_MODE0_0			0
#define SCK_REV_MASK			BIT(13)
#define NG_TX_MASK			BIT(1)
#define NG_RX_MASK			BIT(0)

/* SPI CS select in master mode */
#define SPI_SEL_CS0			0xE	/* 2'B1110 */
#define SPI_SEL_CS1			0xD	/* 2'B1101 */
#define SPI_SEL_CS2			0xB	/* 2'B1011 */
#define SPI_SEL_CS3			0x7	/* 2'B0111 */
#define	SPI_SEL_NONE			0XF	/* 2'B1111 */
#define SPI_SEL_CS_SHIFT		8

/* SPI data width*/
#define MAX_BITS_PER_WORD		32
#define Default_BITS_PER_WORD		8
#define SPI_CHNL_LEN_MASK		0x1F
#define SPI_CHNL_LEN_SHIFT		2

/*DMA channel for SPI*/
#define	SPI_DMA_0_BYTE 0
#define	SPI_DMA_4_BYTE 4

/*Structure Definition*/
enum spi_sck_sel {
	sck_default = 0,
	sck_reverse,
};

enum spi_tx_edge {
	tx_pos_edge = 0,
	tx_neg_edge,
};

enum spi_rx_edge {
	rx_pos_edge = 0,
	rx_neg_edge,
};

enum spi_msb_lsb_sel {
	tx_rx_msb = 0,
	tx_rx_lsb,
};

enum spi_transfer_mode {
	idle_mode = 0,
	rx_mode,
	tx_mode,
	rx_tx_mode,
};

enum spi_operate_mode {
	master_mode = 0,
	slave_mode,
};

enum spi_dma_en_sel {
	sprd_spi_dma_disable = 0,
	sprd_spi_dma_enable,
};

enum spi_cs_signal {
	cd_low = 0,
	cd_high,
};

#ifndef CONFIG_DM_SPI
struct spi_init_param {
	enum spi_sck_sel sck_sel;
	enum spi_tx_edge tx_edge;
	enum spi_rx_edge rx_edge;
	enum spi_msb_lsb_sel msb_lsb_sel;
	enum spi_transfer_mode tx_rx_mode;
	enum spi_operate_mode op_mode;
	unsigned int data_width;
	unsigned int max_speed;
};

struct spi_transfer {
	enum spi_transfer_mode rt_mode;
	enum spi_dma_en dma_en;
	unsigned int *tx_buf;
	unsigned int *rx_buf;
	unsigned int data_len;
};
#endif


struct sprd_spi_platdata{
	struct spi_init_param *sprd_spi_init_param;
	unsigned int base;
	unsigned int spi_mode_in;
	unsigned int spi_mode_out;
	struct spi_transfer *transfer;
};

struct sprd_spi_priv {
	unsigned int mode;
	int spi_mode_in;
	int spi_mode_out;
	struct spi_init_param *sprd_spi_init_param;
	unsigned int base;
	unsigned int chip_select;
	unsigned long spi_source_clk;
	struct spi_transfer *transfer;
	int sprd_spi_is_init;
};

/*Function Propertype*/
#ifndef CONFIG_DM_SPI
void sprd_spi_enable(unsigned int spi_id);
void sprd_spi_disable(unsigned int spi_id);
void sprd_spi_reset(unsigned int spi_id);
void sprd_spi_clk_set(unsigned int spi_id, unsigned int clk_src, unsigned int clk_div);
void sprd_spi_clk_div(unsigned int speed);
void sprd_spi_set_cs(unsigned int spi_sel_csx, unsigned int is_low);
void sprd_spi_set_cd(unsigned int cd);
void sprd_spi_set_spi_mode(unsigned int spi_mode);
void sprd_spi_set_data_width(unsigned int data_width);
void sprd_spi_init(struct spi_init_param *spi_param);
int sprd_spi_transfer(struct spi_transfer *transfer);
int sprd_spi_write_data(unsigned int *pbuf, unsigned int data_len, unsigned int dummy_bit_len);
int sprd_spi_read_data(unsigned int *pbuf, unsigned int data_len, unsigned int dummy_bit_len);
#else
void sprd_spi_set_cs(unsigned long spi_base, unsigned int spi_sel_csx, unsigned int is_low);
#endif

enum spi_data_width{
	width_8=8,
	width_12=12,
	width_16=16,
	width_32=32,
};
//note: max freq should less than 48M
enum spi_clk_freq_div{
	/*clock source: 26M   match source_clk_26m*/
	freq_div0=325000,
	freq_div1=650000,
	freq_div2=1300000,
	freq_div3=2600000,
	freq_div4=3250000,
	freq_div5=6500000,
	freq_div6=13000000, //13M
	/*clock source: 128M   match source_clk_128m*/
	freq_div7=4000000,
	freq_div8=8000000,
	freq_div9=16000000,
	freq_div10=32000000,//32M
	/*clock source: 153.6M   match source_clk_153_6m*/
	freq_div11=6400000,
	freq_div12=12800000,
	freq_div13=19200000,
	freq_div14=25600000,
	freq_div15=38400000,//38.4M
	/*clock source: 192M   match source_clk_192m*/
	freq_div16=2000000,
	freq_div17=3000000,
	freq_div18=4000000,
	freq_div19=6000000,
	freq_div20=8000000,
	freq_div21=9600000,
	freq_div22=12000000,
	freq_div23=16000000,
	freq_div24=24000000,
	freq_div25=48000000,//48M
};
enum spi_clk_source{
	source_clk_26m=0,
	source_clk_128m,
	source_clk_153_6m,
	source_clk_192m,
};
//default:div0
enum spi_clk_source_div{
	source_div_default=0,
	source_div1,
	source_div2,
};
//spi return message
enum spi_return_message{
	SPI_SUCESS=0,
	SPI_PROBE_ERROR=-1,
	SPI_OFDATA_TO_PLATDATA_ERROR = -2,
	SPI_BIT_WIDTH_ERROR = -3,//bit per word not 8/16/32
	SPI_BUFFER_ERROR = -4,//no tx_buf or rx_buf
	SPI_BITLEN_ERROR = -5,//bitlen not an integer multiper of bit_per_word
	SPI_GET_RX_CHN_ERROR = -6,
	SPI_ENABLE_RX_ERROR = -7,
	SPI_CONFIG_RX_CHN_ERROR = -8,
	SPI_GET_TX_CHN_ERROR = -9,
	SPI_ENABLE_TX_ERROR = -10,
	SPI_CONFIG_TX_CHN_ERROR = -11,
	SPI_RX_TIMEOUT_ERROR = -12,
	SPI_DISABLE_RX_ERROR = -13,
	SPI_FREE_RX_ERROR = -13,
	SPI_TX_TIMEOUT_ERROR = -14,
	SPI_DISABLE_TX_ERROR = -15,
	SPI_FREE_TX_ERROR = -16,
	SPI_TRANS_TIMEOUT_ERROR = -17,
};

#endif /*_SPRD_SPI_H*/
