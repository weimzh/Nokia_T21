/*
* Copyright (c) 2019, Spreadtrum Communications.
*
* The above copyright notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __SPRD_DMA_H__
#define __SPRD_DMA_H__

#define DMA_UID_SOFTWARE		0

enum dma_datawidth {
	BYTE_WIDTH,
	SHORT_WIDTH,
	WORD_WIDTH,
};

enum dma_step {
	NONE_STEP,
	BYTE_STEP = BIT(0),
	SHORT_STEP = BIT(1),
	WORD_STEP = BIT(2),
	DWORD_STEP = BIT(3),
};

enum dma_link_type {
	LINK_CTN,
	LINK_END,
	LINK_CYCLE,
};

enum dma_request_mode {
	FRAG_REQ_MODE,
	BLOCK_REQ_MODE,
	TRANS_REQ_MODE,
	LIST_REQ_MODE,
};

enum dma_int_type {
	NO_INT,
	FRAG_DONE,
	BLK_DONE,
	BLOCK_FRAG_DONE,
	TRANS_DONE,
	TRANS_FRAG_DONE,
	TRANS_BLOCK_DONE,
	TRANS_BLOCK_FRAG_DONE,
	LIST_DONE,
	CONFIG_ERR = 0x10,
};

enum dma_pri_level {
	DMA_PRI_0,
	DMA_PRI_1,
	DMA_PRI_2,
	DMA_PRI_3,
};

enum dma_wait_bdone {
	DMA_WAIT_BDONE,
	DMA_DONOT_WAIT_BDONE,
};

enum dma_cmd {
	SET_IRQ_TYPE,
	SET_WRAP_MODE,
	SET_REQ_MODE,
	SET_CHN_PRIO,
	SET_INT_TYPE,
};

enum group_idx{
	DMA_CHN_GROUP_1,
	DMA_CHN_GROUP_2,
	MAX_CHN_GROUP
};

enum dma_switch_mode {
	DATA_ABCD,
	DATA_DCBA,
	DATA_BADC,
	DATA_CDAB,
};

enum dma_chn_status {
	NO_USED,
	USED,
};

enum dma_link_list {
	LINKLIST,
	NO_LINKLIST,
};

enum request_mode {
	SOFTWARE_REQ,
	HARDWARE_REQ,
};

enum dma_flags {
	DMA_CFG_FLAG = BIT(0),
	DMA_HARDWARE_FLAG = BIT(1),
	DMA_SOFTWARE_FLAG = BIT(2),
	DMA_GROUP1_SRC = BIT(3),
	DMA_GROUP1_DST = BIT(4),
	DMA_GROUP2_SRC = BIT(5),
	DMA_GROUP2_DST = BIT(6),
	DMA_MUTL_FRAG_DONE = BIT(7),
	DMA_MUTL_BLK_DONE = BIT(8),
	DMA_MUTL_TRANS_DONE = BIT(9),
	DMA_MUTL_LIST_DONE = BIT(10),
};

struct sprd_dma_cfg {
	uint32_t dev_id;
	unsigned long src_addr;
	unsigned long des_addr;
	uint32_t src_step;
	uint32_t des_step;
	uint32_t fragmens_len;
	uint32_t block_len;
	uint32_t transcation_len;
	enum dma_datawidth datawidth;
	enum dma_request_mode req_mode;
	enum dma_int_type irq_mode;
	enum dma_pri_level chn_pri;
	enum dma_switch_mode swt_mode;
	unsigned long link_cfg_p;
	uint32_t ptr_end;
	uint32_t wrap_ptr;
	uint32_t wrap_to;
};
#endif
