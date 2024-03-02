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
#include <common.h>
#include <asm/io.h>
#include <asm/errno.h>
#include <dm.h>
#include <dma-uclass.h>
#include <asm/arch/common.h>
#include <sprd_dma.h>
#include <clk.h>

#define DMA_TAG				"SPRD_DMA"
#define DMA_NUM_MAX		32
#define DMA_CHN_BASE		0

/* dma globle register definition */
#define DMA_GLB_PAUSE			0x0
#define DMA_GLB_FRG_WAIT		0x4
#define DMA_GLB_PEND0_EN		0x8
#define DMA_GLB_PEND1_EN		0xc
#define DMA_GLB_INT_RAW_STS		0x10
#define DMA_GLB_INT_MSK_STS		0x14
#define DMA_GLB_REQ_STS			0x18
#define DMA_GLB_EN_STS			0x1c
#define DMA_GLB_DBG_STS			0x20
#define DMA_GLB_ARB_SEL_STS		0x24
#define DMA_CHN_STR_CHN_GRP1		0x28
#define DMA_CHN_STR_CHN_GRP2		0x2c
#define DMA_CHN_ARPROT			0x30
#define DMA_CHN_AWPROT			0x34
#define DMA_CHN_PROT_FLAG		0x38
#define DMA_GLB_PROT			0x3c
#define DMA_PEND0_PROT			0x40
#define DMA_PEND1_PROT			0x44
#define DMA_REQID0_PROT			0x48
#define DMA_REQID1_PROT			0x4c
#define DMA_SYNC_SEC_N_NORM		0x50
#define DMA_CNT_CHN_SEL			0x54
#define DMA_TRSF_BYTE_CNT1		0x58
#define DMA_TRSF_BYTE_CNT2		0x5c

/* dma channel register definition */
#define DMA_PAUSE				0x0
#define DMA_REQ				0x4
#define DMA_CFG				0x8
#define DMA_INTC				0xc
#define DMA_SRC_ADDR			0x10
#define DMA_DEST_ADDR			0x14
#define DMA_FRG_LEN			0x18
#define DMA_BLK_LEN			0x1c
#define DMA_TRSF_LEN			0x20
#define DMA_TRSF_STEP			0x24
#define DMA_WRAP_PTR			0x28
#define DMA_WRAP_TO			0x2c
#define DMA_LLIST_PTR			0x30
#define DMA_FRG_STEP			0x34
#define DMA_SRC_BLK_STEP		0x38
#define DMA_DEST_BLK_STEP		0x3c

/* DMA_PAUSE */
#define DMA_CHN_PAUSE			BIT(2)

/* DMA_CHN_REQ register definition */
#define DMA_REQ_EN			BIT(0)

/* DMA_CHN_CFG register definition */
#define DMA_CHN_EN			BIT(0)
#define DMA_WAIT_BDONE_OFFSET		24
#define DMA_LLIST_EN_OFFSET		4
#define DMA_CHN_PRI_OFFSET		12

/* DMA_CHN_INTC register definition */
#define DMA_INT_MASK			0x1f
#define DMA_INT_CLR_OFFSET		24
#define DMA_FRAG_INT_EN			BIT(0)
#define DMA_BLK_INT_EN			BIT(1)
#define DMA_TRANS_INT_EN		BIT(2)
#define DMA_LIST_INT_EN			BIT(3)
#define DMA_CFG_ERR_INT_EN		BIT(4)
#define DMA_FRAG_RAW_STS		BIT(8)
#define DMA_BLK_RAW_STS			BIT(9)
#define DMA_TRSC_RAW_STS		BIT(10)
#define DMA_LIST_RAW_STS		BIT(11)
#define DMA_CFGERR_RAW_STS		BIT(12)
#define DMA_FRAG_INT_STS		BIT(16)
#define DMA_BLK_INT_STS			BIT(17)
#define DMA_TRSC_INT_STS		BIT(18)
#define DMA_LIST_INT_STS		BIT(19)
#define DMA_CFGERR_INT_STS		BIT(20)

/* DMA_CHN_FRG_LEN register definition */
#define DMA_SRC_DATAWIDTH_OFFSET	30
#define DMA_DES_DATAWIDTH_OFFSET	28
#define DMA_SWT_MODE_OFFSET		26
#define DMA_REQ_MODE_OFFSET		24
#define DMA_ADDR_WRAP_SEL_OFFSET	23
#define DMA_ADDR_WRAP_EN_OFFSET		22
#define DMA_FIX_SEL_OFFSET		21
#define DMA_FIX_SEL_EN			20
#define DMA_LLIST_END_OFFSET		19
#define DMA_REQ_MODE_MASK		0x3
#define DMA_FRG_LEN_MASK		0x1ffff

/* DMA_CHN_BLK_LEN register definition */
#define DMA_BLK_LEN_MASK		0x1ffff

/* DMA_CHN_TRSC_LEN register definition */
#define DMA_TRSC_LEN_MASK		0xfffffff

/* DMA_CHN_TRSF_STEP register definition */
#define DMA_DEST_TRSF_STEP_OFFSET	16
#define DMA_SRC_TRSF_STEP_OFFSET	0
#define DMA_TRSF_STEP_MASK		0xffff

/* DMA_WRAP register definition */
#define DMA_WRAP_ADDR_MASK		0xfffffff
#define DMA_HADDR_MASK			0xf0000000

/* LLIST_PTR register definition */
#define DMA_LLIST_PTR_CFG_OFFSET	0x10

#define SPRD_DMA_REQ_CID(base, uid)	(base + 0x2000 + 0x4 * (uid - 1))

#define SPRD_DMA_DESCRIPTORS		64
#define SPRD_DMA_CHN_OFFSET		0x40
#define SPRD_DMA_CHN_BASE		0x1000
#define SPRD_DMA_MEMCPY_MIN_SIZE	64
#define SPRD_DMA_CFG_COUNT		32
#define SPRD_DMA_NAME_SIZE		32

/*define error number*/
#define SPRD_DMA_SUCCESS	    (0UL)
#define NO_ERROR                0

/* dma channel register definition */
struct sprd_dma_chn_reg {
	u32 pause;
	u32 req;
	u32 cfg;
	u32 intc;
	u32 src_addr;
	u32 des_addr;
	u32 frg_len;
	u32 blk_len;
	u32 trsc_len;
	u32 trsf_step;
	u32 wrap_ptr;
	u32 wrap_to;
	u32 llist_ptr;
	u32 frg_step;
	u32 src_blk_step;
	u32 des_blk_step;
};

/* dma channel description */
struct sprd_dma_chn {
	int chn_num;
	u32 dev_id;
	enum dma_chn_status chn_status;
	void __iomem *dma_chn_base;
	char chn_name[SPRD_DMA_NAME_SIZE];
	int trsf_done;
	struct sprd_dma_dev *sdev;
	enum dma_direction dir;
};

/**
* dma config struct for normal and linklist mode
* for normal mode: dma_cfg_cnt=1;
* for linklist mode: dma_cfg_cnt > 1;
*/
struct dma_cfg_group_t {
	u32 dma_cfg_cnt;
	struct sprd_dma_cfg dma_cfg[SPRD_DMA_CFG_COUNT];
};

/* dma device */
struct sprd_dma_dev {
	struct device *dev;
	struct clk clk;
	void *dma_glb_base;
	u32 dma_chn_cnt;
	struct dma_cfg_group_t dma_cfg_group;
	struct sprd_dma_chn *channels;
};

static void sprd_dma_glb_state_check(struct sprd_dma_dev *sdev)
{
	dev_info(sdev->dev, "Gbl dbg reg:\n pause=0x%x\n raw_sts=0x%x\n"
		" msk_sts=0x%x\n req_sts=0x%x\n en_sts=0x%x\n debug sts=0x%x\n",
		readl(sdev->dma_glb_base + DMA_GLB_PAUSE),
		readl(sdev->dma_glb_base + DMA_GLB_INT_RAW_STS),
		readl(sdev->dma_glb_base + DMA_GLB_INT_MSK_STS),
		readl(sdev->dma_glb_base + DMA_GLB_REQ_STS),
		readl(sdev->dma_glb_base + DMA_GLB_EN_STS),
		readl(sdev->dma_glb_base + DMA_GLB_DBG_STS));
}

static void sprd_dma_chn_reg_check(struct sprd_dma_dev *sdev, u32 dma_chn)
{
	struct sprd_dma_chn *mchan = &(sdev->channels[dma_chn]);

	dev_info(sdev->dev, "chn dbg reg:\n cfg=0x%x\n int=0x%x\n"
		" src=0x%x\n dest=0x%x\n frg_cfg=0x%x\n blk_len=0x%x\n"
		" trsf_len=0x%x\n trsf_step=0x%x\n llist_ptr=0x%x\n",
		readl(mchan->dma_chn_base + DMA_CFG),
		readl(mchan->dma_chn_base + DMA_INTC),
		readl(mchan->dma_chn_base + DMA_SRC_ADDR),
		readl(mchan->dma_chn_base + DMA_DEST_ADDR),
		readl(mchan->dma_chn_base + DMA_FRG_LEN),
		readl(mchan->dma_chn_base + DMA_BLK_LEN),
		readl(mchan->dma_chn_base + DMA_TRSF_LEN),
		readl(mchan->dma_chn_base + DMA_TRSF_STEP),
		readl(mchan->dma_chn_base + DMA_LLIST_PTR));
}

static void sprd_dma_set_uid(struct sprd_dma_dev *sdev,
			      struct sprd_dma_chn *mchan, u32 dev_id)
{
	if (DMA_UID_SOFTWARE != dev_id)
		writel((mchan->chn_num + 1),
			SPRD_DMA_REQ_CID(sdev->dma_glb_base, dev_id));
}

static void sprd_dma_unset_uid(struct sprd_dma_dev *sdev,
				struct sprd_dma_chn *mchan, u32 dev_id)
{
	if (DMA_UID_SOFTWARE != dev_id)
		writel(0x0, SPRD_DMA_REQ_CID(sdev->dma_glb_base, dev_id));
}

static void sprd_dma_int_clr(struct sprd_dma_chn *mchan)
{
	writel(DMA_INT_MASK << DMA_INT_CLR_OFFSET,
		mchan->dma_chn_base + DMA_INTC);
}

static void sprd_dma_int_dis(struct sprd_dma_chn *mchan)
{
	writel(DMA_INT_MASK << DMA_INT_CLR_OFFSET,
		mchan->dma_chn_base + DMA_INTC);
	writel(0, mchan->dma_chn_base + DMA_INTC);
}

static void sprd_dma_chn_enable(struct sprd_dma_chn *mchan)
{
	u32 val = readl(mchan->dma_chn_base + DMA_CFG);

	writel(val | DMA_CHN_EN, mchan->dma_chn_base + DMA_CFG);
}

static void sprd_dma_soft_request(struct sprd_dma_chn *mchan)
{
	writel(DMA_REQ_EN, mchan->dma_chn_base + DMA_REQ);
}

static void sprd_dma_stop_and_disable(struct device *dev, struct sprd_dma_chn *mchan)
{
	u32 cfg_val, timeout = 0x2000;
	u32 pause;

	if (!(readl(mchan->dma_chn_base + DMA_CFG) & 0x1))
		return;

	writel(0x1, mchan->dma_chn_base + DMA_PAUSE);

	do {
		pause = readl(mchan->dma_chn_base + DMA_PAUSE);
		if (pause & DMA_CHN_PAUSE)
			break;
	} while (--timeout > 0);

	if (timeout == 0) {
		sprd_dma_glb_state_check(mchan->sdev);
		dev_err(dev, "pause DMA[%d] failed!\n",	mchan->chn_num);
		return;
	}

	cfg_val = readl(mchan->dma_chn_base + DMA_CFG);
	cfg_val &= ~DMA_CHN_EN;

	writel(cfg_val, mchan->dma_chn_base + DMA_CFG);
	writel(0x0, mchan->dma_chn_base + DMA_PAUSE);
}

/* get dma source reg addr */
static u64 sprd_dma_get_src_addr(struct sprd_dma_chn *mchan)
{
	void *addr = mchan->dma_chn_base;
	u64 addr_val;

	addr_val = (u64)(readl(addr + DMA_SRC_ADDR));
	addr_val |= (u64)(readl(addr + DMA_WRAP_PTR) & DMA_HADDR_MASK) << 4;

	return addr_val;
}

/* get dma dest reg addr */
static u64 sprd_dma_get_dst_addr(struct sprd_dma_chn *mchan)
{
	void *addr = mchan->dma_chn_base;
	u64 addr_val;

	addr_val = (u64)(readl(addr + DMA_DEST_ADDR));
	addr_val |= (u64)(readl(addr + DMA_WRAP_TO) & DMA_HADDR_MASK) << 4;

	return addr_val;
}

static void sprd_dma_stop(struct sprd_dma_chn *chan)
{
	sprd_dma_unset_uid(chan->sdev, chan, chan->dev_id);
	sprd_dma_stop_and_disable(chan->sdev->dev, chan);
	sprd_dma_int_clr(chan);
}

static bool sprd_dma_check_cfg(struct sprd_dma_cfg *cfg)
{
	if (!cfg->src_addr || !cfg->des_addr ||
		cfg->fragmens_len > cfg->block_len ||
		cfg->block_len > cfg->transcation_len ||
		cfg->src_step > DWORD_STEP ||
		cfg->des_step > DWORD_STEP)
		return false;

	return true;
}

static enum dma_int_type sprd_dma_check_raw_type(struct sprd_dma_chn *chan)
{
	u32 mask_val = readl(chan->dma_chn_base + DMA_INTC);

	if (mask_val & DMA_CFGERR_RAW_STS)
		return CONFIG_ERR;
	else if (mask_val & DMA_LIST_RAW_STS)
		return LIST_DONE;
	else if (mask_val & DMA_TRSC_RAW_STS)
		return TRANS_DONE;
	else if (mask_val & DMA_BLK_RAW_STS)
		return BLK_DONE;
	else if (mask_val & DMA_FRAG_RAW_STS)
		return FRAG_DONE;
	else
		return NO_INT;
}

static enum dma_int_type sprd_dma_check_int_type(struct sprd_dma_chn *chan)
{
	u32 mask_val = readl(chan->dma_chn_base + DMA_INTC);

	if (mask_val & DMA_CFGERR_INT_STS)
		return CONFIG_ERR;
	else if (mask_val & DMA_LIST_INT_STS)
		return LIST_DONE;
	else if (mask_val & DMA_TRSC_INT_STS)
		return TRANS_DONE;
	else if (mask_val & DMA_BLK_INT_STS)
		return BLK_DONE;
	else if (mask_val & DMA_FRAG_INT_STS)
		return FRAG_DONE;
	else
		return NO_INT;
}

static enum dma_request_mode sprd_dma_check_req_type(struct sprd_dma_chn *chan)
{
	u32 req_val = readl(chan->dma_chn_base + DMA_FRG_LEN);

	req_val = (req_val >> DMA_REQ_MODE_OFFSET) & DMA_REQ_MODE_MASK;

	return req_val;
}

/* check if the dma trsf is done */
static int sprd_dma_wait_noirq_done(struct sprd_dma_dev *sdev, u32 dma_chn, int timeout)
{
	struct sprd_dma_chn *mchan = &sdev->channels[dma_chn];
	enum dma_int_type int_type;
	enum dma_request_mode req_type;
	int cnt = timeout ? timeout: 20000;

	req_type = sprd_dma_check_req_type(mchan);

	do {
		int_type = sprd_dma_check_raw_type(mchan);
		if ((unsigned int)int_type >= ((unsigned int)(1 << req_type)))
			break;
		udelay(100);
	} while(cnt--);

	if (cnt <= 0) {
		dev_err(sdev->dev, "dma wait transfer done timeout!\n");
		return -ETIMEDOUT;
	}

	return 0;
}

static int sprd_dma_config(struct sprd_dma_chn *mchan,
		struct sprd_dma_cfg *cfg, struct sprd_dma_chn_reg *list_base)
{
	u32 cfg_base, reg_val;
	u32 fix_mode = 0, fix_en = 0, wrap_en = 0, wrap_mode = 0;
	u32 list_end = 0, llist_en = 0, irq_mode = 0;

	/* check dma fix mode */
	if ((cfg->src_step != 0 && cfg->des_step != 0)  ||
		((cfg->src_step | cfg->des_step) == 0)) {
		fix_en = 0x0;
	} else {
		fix_en = 0x1;
		if (cfg->src_step)
			fix_mode = 0x1;
		else
			fix_mode = 0x0;
	}

	/* check dma wrap mode */
	if (cfg->wrap_ptr && cfg->wrap_to) {
		wrap_en = 0x1;
		if (cfg->wrap_to == (u32)cfg->src_addr) {
			wrap_mode = 0x0;
		} else {
			if (cfg->wrap_to == (u32)cfg->des_addr)
				wrap_mode = 0x1;
			else {
				dev_err(mchan->sdev->dev, "check wrap config failed\n");
				return -EINVAL;
			}
		}
	}

	/* linklist configuration */
	if (cfg->link_cfg_p) {
		llist_en = 0x1;
		if (cfg->ptr_end)
			list_end = 0x1;
		else
			list_end = 0;
	}

	irq_mode = cfg->irq_mode;

	/* aligned src/des step with datawith, both of their uint is byte */
	if (cfg->src_step % (1 << cfg->datawidth)) {
		dev_err(mchan->sdev->dev, "Source step is not aligned!");
		return -EINVAL;
	}

	if (cfg->des_step % (1 << cfg->datawidth)) {
		dev_err(mchan->sdev->dev,  "Destination step is not aligned!");
		return -EINVAL;
	}

	mchan->dev_id = cfg->dev_id;

	if (list_base != NULL)
		cfg_base = (u32)list_base;
	else
		cfg_base = (u32)mchan->dma_chn_base;

	memset((void *)cfg_base, 0, 0x40);

	/* set default priority = 1 */
	reg_val = cfg->chn_pri << DMA_CHN_PRI_OFFSET |
		    llist_en << DMA_LLIST_EN_OFFSET |
		    DMA_DONOT_WAIT_BDONE << DMA_WAIT_BDONE_OFFSET;
	writel(reg_val, cfg_base + DMA_CFG);

	/* intc*/
	writel(irq_mode | CONFIG_ERR, cfg_base + DMA_INTC);

	/* src/dest & wrap ptr/to */
	writel((u32)cfg->src_addr, cfg_base + DMA_SRC_ADDR);
	writel((u32)cfg->des_addr, cfg_base + DMA_DEST_ADDR);

	if (wrap_en) {
		/* the hight 4 bits are reserved in 32 bit DMA SoC */
		reg_val = (cfg->wrap_ptr & DMA_WRAP_ADDR_MASK) |
			(u32)((cfg->src_addr >> 4) & DMA_HADDR_MASK);
		writel(reg_val, cfg_base + DMA_WRAP_PTR);
		reg_val = (cfg->wrap_to & DMA_WRAP_ADDR_MASK) |
			(u32)((cfg->des_addr >> 4) & DMA_HADDR_MASK);
		writel(reg_val, cfg_base + DMA_WRAP_TO);
	} else {
		reg_val = (u32)((cfg->src_addr >> 4) & DMA_HADDR_MASK);
		writel(reg_val, cfg_base + DMA_WRAP_PTR);
		reg_val = (u32)((cfg->des_addr >> 4) & DMA_HADDR_MASK);
		writel(reg_val, cfg_base + DMA_WRAP_TO);
	}

	/* frag len */
	reg_val = (cfg->datawidth << DMA_SRC_DATAWIDTH_OFFSET) |
		(cfg->datawidth << DMA_DES_DATAWIDTH_OFFSET) |
		(cfg->swt_mode << DMA_SWT_MODE_OFFSET) |
		(cfg->req_mode << DMA_REQ_MODE_OFFSET) |
		(wrap_mode << DMA_ADDR_WRAP_SEL_OFFSET) |
		(wrap_en << DMA_ADDR_WRAP_EN_OFFSET) |
		(fix_mode << DMA_FIX_SEL_OFFSET) |
		(fix_en << DMA_FIX_SEL_EN) |
		(list_end << DMA_LLIST_END_OFFSET) |
		(cfg->fragmens_len & DMA_FRG_LEN_MASK);
	writel(reg_val, cfg_base + DMA_FRG_LEN);

	/* blk len */
	writel(cfg->block_len & DMA_FRG_LEN_MASK, cfg_base + DMA_BLK_LEN);

	if (!cfg->transcation_len)
		reg_val = cfg->block_len & DMA_TRSC_LEN_MASK;
	else
		reg_val = cfg->transcation_len & DMA_TRSC_LEN_MASK;
	writel(reg_val, cfg_base + DMA_TRSF_LEN);

	/* transf step */
	reg_val = (cfg->des_step & DMA_TRSF_STEP_MASK)
			<< DMA_DEST_TRSF_STEP_OFFSET |
		    (cfg->src_step & DMA_TRSF_STEP_MASK)
			<< DMA_SRC_TRSF_STEP_OFFSET;
	writel(reg_val, cfg_base + DMA_TRSF_STEP);

	/* linklist ptr */
	reg_val = (u32)((cfg->link_cfg_p >> 4) & DMA_HADDR_MASK);
	writel(reg_val, cfg_base + DMA_SRC_BLK_STEP);
	reg_val = (u32)cfg->link_cfg_p;
	writel(reg_val, cfg_base + DMA_LLIST_PTR);

	return 0;
}

/* config dma linklist */
static int sprd_dma_config_linklist(struct device *dev, struct sprd_dma_chn *mchan,
			 struct sprd_dma_cfg *cfg_list, u32 node_size)
{
	struct sprd_dma_chn_reg *dma_reg_list;
	struct sprd_dma_cfg list_first;
	u32 i;
	int ret;

	if (node_size < 2) {
		dev_err(dev, "linklist config node less than 2!\n");
		return -EINVAL;
	}

	/* check dma linklist node memory */
	if (cfg_list[0].link_cfg_p == 0) {
		dev_err(dev, "Haven't allocated memory for list node!\n");
		return -EINVAL;
	}

	/* get linklist node virtual addr and physical addr */
	dma_reg_list = (struct sprd_dma_chn_reg *)cfg_list[0].link_cfg_p;

	memcpy((void *)&list_first, cfg_list, sizeof(list_first));

	dev_info(dev, "llist: alloc addr phys: 0x%lx\n", list_first.link_cfg_p);

	/* linklist configuration */
	for (i = 0; i < node_size; i++) {
		/* linklist pointer ptr point to next node */
		cfg_list[i].link_cfg_p = (list_first.link_cfg_p +
					  ((i + 1) % node_size) * sizeof(struct sprd_dma_chn_reg)
					  + DMA_LLIST_PTR_CFG_OFFSET);

		ret = sprd_dma_config(mchan, cfg_list + i, dma_reg_list + i);
		if (ret < 0) {
			dev_err(dev, "Linklist configuration error!\n");
			return -EINVAL;
		}

		dev_info(dev, "Configuration the link list!0x%x\n",
		       (u32)cfg_list[i].link_cfg_p);
	}

	list_first.link_cfg_p += DMA_LLIST_PTR_CFG_OFFSET;

	return sprd_dma_config(mchan, &list_first, NULL);
}

static int sprd_dma_prepare_cfg(struct sprd_dma_dev *sdev , u32 chn,
			 struct sprd_dma_cfg *cfg_list)
{
	struct sprd_dma_chn *mchan = &sdev->channels[chn];
	struct sprd_dma_cfg *dma_cfg = &sdev->dma_cfg_group.dma_cfg[0];
	struct sprd_dma_cfg *cfg_check = cfg_list;
	int cnt, ret;

	if (chn >= sdev->dma_chn_cnt)
		return -EINVAL;

	if (!cfg_list->link_cfg_p) {
		/* normal configuration */
		memcpy(dma_cfg, cfg_list, sizeof(struct sprd_dma_cfg));
		sdev->dma_cfg_group.dma_cfg_cnt = 1;
	} else {
		/* linklist configuration */
		for (cnt = 0; cnt < SPRD_DMA_CFG_COUNT; cnt++) {
			if (!sprd_dma_check_cfg(cfg_check))
				break;
			cfg_check++;
		}
		if (cnt >= SPRD_DMA_CFG_COUNT)
			return -EINVAL;

		memcpy(dma_cfg, cfg_list, sizeof(struct sprd_dma_cfg) * cnt);
		sdev->dma_cfg_group.dma_cfg_cnt = cnt;
	}

	if (sdev->dma_cfg_group.dma_cfg_cnt == 1)
		/* config into dma reg */
		ret = sprd_dma_config(mchan, dma_cfg, NULL);
	else
		/* config linklist memory */
		ret = sprd_dma_config_linklist(sdev->dev, mchan, dma_cfg,
					       sdev->dma_cfg_group.dma_cfg_cnt);

	if (ret < 0) {
		dev_err(sdev->dev, "Configuration is error!\n");
		return ret;
	}

	return 0;
}

char *dma_strncpy(char *dest, char const *src, size_t count)
{
	char *tmp = dest;
	size_t max_index = count - 1;

	while (count-- && (*dest++ = *src++) != '\0')
		;
	if(count == 0)
		tmp[max_index] = '\0';

	return tmp;
}

static int sprd_dma_alloc_chn(struct sprd_dma_dev *sdev, const char *chn_name)
{
	u32 chn;

	if ((chn_name == NULL) || (sdev->dma_glb_base == NULL)) {
		dev_err(sdev->dev, "DMA %s request chn failed,check name and glb_base!\n", chn_name);
		return -EINVAL;
	}

	/* enable dma */
	for (chn = 0; chn < sdev->dma_chn_cnt; chn++) {
		if (sdev->channels[chn].chn_status == NO_USED)
			break;
	}
	if (chn < sdev->dma_chn_cnt) {
		sdev->channels[chn].chn_status = USED;
		dma_strncpy((char *)&sdev->channels[chn].chn_name, chn_name,
			SPRD_DMA_NAME_SIZE);
	} else {
		dev_err(sdev->dev, "DMA %s request chn failed, all chnnel busy!\n", chn_name);
		return -EINVAL;
	}

	return chn;
}

static int sprd_dma_free_chn(struct sprd_dma_dev *sdev, u32 chn)
{
	struct sprd_dma_chn *chan;
	u32 i;

	if ((chn >= sdev->dma_chn_cnt) || (sdev->dma_glb_base == NULL))
		return -EINVAL;

	chan = &sdev->channels[chn];
	if (chan->chn_status == USED) {
		/* stop and disable dma */
		sprd_dma_stop(chan);
		strcpy((char *)chan->chn_name, "free-dma-channel");
		chan->chn_status = NO_USED;
	} else {
		dev_info(sdev->dev, "DMA %s chn %d had freed!\n",sdev->channels[chn].chn_name, chn);
	}

	for (i = 0; i < sdev->dma_chn_cnt; i++) {
		chan = &sdev->channels[i];
		if (chan->chn_status == USED)
			break;
	}
	if (i == sdev->dma_chn_cnt)
		clk_disable(&sdev->clk);

	return 0;
}

static void sprd_dma_submit(struct sprd_dma_dev *sdev, int chn)
{
	struct sprd_dma_chn *chan = &sdev->channels[chn];

	sprd_dma_set_uid(sdev, chan, chan->dev_id);
	sprd_dma_chn_enable(chan);

	if (DMA_UID_SOFTWARE == chan->dev_id)
		sprd_dma_soft_request(chan);
}

static int sprd_dma_memcpy(struct sprd_dma_dev *sdev, int chn_num,
			   void *dst, void *src, size_t len)
{
	struct sprd_dma_cfg chancfg = {0};
	int ret;
	struct sprd_dma_chn *chan;
	u32 i;

	chancfg.dev_id = 0;
	chancfg.src_addr = src;
	chancfg.des_addr = dst;
	chancfg.src_step = 4;
	chancfg.des_step = 4;
	chancfg.fragmens_len = len;
	chancfg.block_len = len;
	chancfg.transcation_len = len;
	chancfg.datawidth = WORD_WIDTH;
	chancfg.req_mode = TRANS_REQ_MODE;
	chancfg.irq_mode = TRANS_DONE;
	chancfg.chn_pri = DMA_PRI_0;
	chancfg.swt_mode = DATA_ABCD;

	ret = clk_enable(&sdev->clk);
	if (ret) {
		dev_err(dma->dev, "dma module enable failed %d \n", ret);
		return ret;
	}

	ret = sprd_dma_prepare_cfg(sdev, chn_num, (struct sprd_dma_cfg *)(&chancfg));
	if (ret) {
		dev_err(dma->dev, "sprd_dma_prepare_cfg failed %d \n", ret);
		goto failed;
	}

	sprd_dma_submit(sdev, chn_num);

	ret = sprd_dma_wait_noirq_done(sdev, chn_num, 0);
	if (ret) {
		dev_err(dma->dev, "sprd_dma_wait_noirq_done failed %d \n", ret);
		goto failed;
	}
	return 0;

failed:
	for (i = 0; i < sdev->dma_chn_cnt; i++) {
		chan = &sdev->channels[i];
		if (chan->chn_status == USED)
			break;
	}
	if (i == sdev->dma_chn_cnt)
		clk_disable(&sdev->clk);

	return ret;
}

static int sprd_dma_transfer(struct udevice *dev, int direction,
			 void *dst, void *src, size_t len)
{
	struct sprd_dma_dev *sdev = dev_get_priv(dev);
	int chn_num = sprd_dma_alloc_chn(sdev, "memcpy");

	if (chn_num < 0) {
		return -EINVAL;
	}

	switch (direction) {
	case DMA_MEM_TO_MEM:
		sprd_dma_memcpy(sdev, chn_num, dst, src, len);
		break;
	default:
		dev_err(dev, "Transfer type not implemented in DMA driver\n");
		break;
	}

	return sprd_dma_free_chn(sdev, chn_num);
}

static int sprd_dma_request(struct dma *dma)
{
	struct sprd_dma_dev *sdev = dev_get_priv(dma->dev);
	struct sprd_dma_chn *chan;

	if (dma->id >= sdev->dma_chn_cnt) {
		dev_err(dma->dev, "invalid dma ch_id %lu\n", dma->id);
		return -EINVAL;
	}
	chan=&sdev->channels[dma->id];
	chan->chn_status = USED;

	return 0;
}

static int sprd_dma_enable(struct dma *dma)
{
	struct sprd_dma_dev *sdev = dev_get_priv(dma->dev);
	int ret = 0;

	if (dma->id >= sdev->dma_chn_cnt) {
		dev_err(dma->dev, "invalid dma ch_id %lu\n", dma->id);
		return -EINVAL;
	}

	ret = clk_enable(&sdev->clk);
	if (ret)
		dev_err(dma->dev, "dma module enable failed %d \n", ret);

	return ret;
}

static int sprd_dma_disable(struct dma *dma)
{
	struct sprd_dma_dev *sdev = dev_get_priv(dma->dev);
	struct sprd_dma_chn *chan;

	if (dma->id >= sdev->dma_chn_cnt) {
		dev_err(dma->dev, "invalid dma ch_id %lu\n", dma->id);
		return -EINVAL;
	}

	chan = &sdev->channels[dma->id];
	sprd_dma_stop(chan);
	chan->chn_status = NO_USED;

	return 0;
}

static int sprd_dma_free(struct dma *dma)
{
	struct sprd_dma_dev *sdev = dev_get_priv(dma->dev);

	return sprd_dma_free_chn(sdev, dma->id);
}

static int sprd_dma_send(struct dma *dma, void *src, size_t len, void *metadata)
{
	struct sprd_dma_dev *sdev = dev_get_priv(dma->dev);

	if (dma->id >= sdev->dma_chn_cnt) {
		dev_err(dma->dev, "invalid dma ch_id %lu\n", dma->id);
		return -EINVAL;
	}

	if (!metadata) {
		dev_err(dma->dev, "Dma ch_id %lu doesn't has dma config struct\n", dma->id);
		return -EINVAL;
	}

	sprd_dma_prepare_cfg(sdev, dma->id, (struct sprd_dma_cfg *)metadata);
	sprd_dma_submit(sdev, dma->id);

	return 0;
}

static int sprd_dma_receive(struct dma *dma, void **dst, void *metadata)
{
	struct sprd_dma_dev *sdev = dev_get_priv(dma->dev);
	struct sprd_dma_cfg chancfg = {0};

	if (dma->id >= sdev->dma_chn_cnt) {
		dev_err(dma->dev, "invalid dma ch_id %lu\n", dma->id);
		return -EINVAL;
	}

	if (!metadata) {
		dev_err(dma->dev, "Dma ch_id %lu doesn't has dma config struct\n", dma->id);
		return -EINVAL;
	}

	*dst = ((struct sprd_dma_cfg *)metadata)->des_addr;
	sprd_dma_prepare_cfg(sdev, dma->id, (struct sprd_dma_cfg *)metadata);
	sprd_dma_submit(sdev, dma->id);

	return 0;
}

static int sprd_dma_polling_trsf_done(struct dma *dma, int timeout)
{
	struct sprd_dma_dev *sdev = dev_get_priv(dma->dev);

	if (dma->id >= sdev->dma_chn_cnt) {
		dev_err(dma->dev, "invalid dma ch_id %lu\n", dma->id);
		return -EINVAL;
	}
	return sprd_dma_wait_noirq_done(sdev, dma->id, timeout);
}

static int sprd_dma_probe(struct udevice *dev)
{
	struct dma_dev_priv *uc_priv = dev_get_uclass_priv(dev);
	struct sprd_dma_dev *sdev = dev_get_priv(dev);
	struct sprd_dma_chn *dma_chan;
	int ret, i;
	u32 tmp = 0;

	uc_priv->supported = DMA_SUPPORTS_MEM_TO_MEM | DMA_SUPPORTS_MEM_TO_DEV |
		DMA_SUPPORTS_DEV_TO_MEM;

	sdev->dev = dev;
	sdev->dma_glb_base = dev_read_addr_ptr(dev);
	if (!sdev->dma_glb_base) {
		dev_err(dev, "get dma reg base failed\n");
		return -EINVAL;
	}

	sdev->dma_chn_cnt = dev_read_u32_default(dev, "#dma-channels", 0);
	if (!sdev->dma_chn_cnt) {
		dev_err(dev, "get dma channels count failed\n");
		return -EINVAL;
	}

	ret = clk_get_by_name(dev, "enable", &sdev->clk);
	if (ret) {
		dev_err(dev, "Can't get sprd dma clock: %d\n",ret);
		return ret;;
	}

	sdev->channels = devm_kcalloc(dev, sdev->dma_chn_cnt,
				      sizeof(struct sprd_dma_chn), GFP_KERNEL);
	if (!sdev->channels) {
		dev_err(dev, "alloc dma channels memory failed\n");
		return -ENOMEM;
	}

	/*initial dma_cfg_group */
	memset(&sdev->dma_cfg_group, 0x0, sizeof(struct dma_cfg_group_t));

	/*initial sprd_dma_chn  */
	for (i = 0; i < sdev->dma_chn_cnt; i++) {
		dma_chan = &sdev->channels[i];
		dma_chan->dma_chn_base = sdev->dma_glb_base + SPRD_DMA_CHN_BASE +
			i * SPRD_DMA_CHN_OFFSET;
		dma_chan->chn_num =  i;
		dma_chan->sdev = sdev;
		dma_chan->dir = DMA_MEM_TO_MEM|DMA_MEM_TO_DEV|DMA_DEV_TO_MEM;
	}

	dev_info(dev, "sprd dma probe ok!\n");

	return 0;
}
static const struct dma_ops sprd_dma_ops = {
	.transfer	= sprd_dma_transfer,
	.request	= sprd_dma_request,
	.free		= sprd_dma_free,
	.enable		= sprd_dma_enable,
	.disable	= sprd_dma_disable,
	.send		= sprd_dma_send,
	.receive	= sprd_dma_receive,
	.wait_transfer_done = sprd_dma_polling_trsf_done,
};

static const struct udevice_id sprd_dma_ids[] = {
	{ .compatible = "sprd,sharkl5pro-dma" },
	{ .compatible = "sprd,sharkl3-dma"},
	{ .compatible = "sprd,sharkle-dma"},
	{ .compatible = "sprd,pike2-dma"},
	{},
};

U_BOOT_DRIVER(sprd_dma) = {
	.name	= "sprd_dma",
	.id	= UCLASS_DMA,
	.of_match = sprd_dma_ids,
	.ops	= &sprd_dma_ops,
	.probe	= sprd_dma_probe,
	.priv_auto_alloc_size = sizeof(struct sprd_dma_dev),
};
