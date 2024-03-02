#include <asm/io.h>
#include <common.h>
#include <errno.h>
#include <linux/pci/pcie_sprd.h>

#define SPRD_PCIE_BASE				0x2b100000
#define PCIE_PHY_DBG_R1				0x72c
#define PCIE_PHY_DBG_R1_LINK_UP			(0x1 << 4)
#define PCIE_PHY_DBG_R1_LINK_IN_TRAINING	(0x1 << 29)

#define PCIE_MISC_CTRL1_OFF	0x8bc
#define PCIE_DBI_RO_WR_EN	(0x1 << 0)

#define SPRD_PCIE_DBI2	0x8000
#define PCIE_BAR0	0x10
#define PCIE_BAR_EN	0x1

#define BAR_NUM		0x6

#define PCIE_RESIZABLE_BAR_EXTENDED_CAP_HEADER	0x260
#define PCIE_RESIZABLE_BAR_EXTENDED_CAPID		0x15
/* Resizable BAR Capability Register */
#define PCIE_RESIZABLE_BAR0		0x264
#define PCIE_RESIZABLE_BAR2		0x26c
#define PCIE_RESIZABLE_BAR4		0x274
#define BAR_SUPPORT_2MB (0x1 << 5)
#define BAR_SUPPORT_4MB (0x1 << 6)
#define BAR_SUPPORT_8MB (0x1 << 7)
/* Resizable BAR Control Register */
#define PCIE_RESIZABLE_BAR0_CTL		0x268
#define PCIE_RESIZABLE_BAR2_CTL		0x270
#define PCIE_RESIZABLE_BAR4_CTL		0x278
/* bit[13:8] is bar size */
#define PCIE_RESIZABLE_BAR_SIZE_MASK 0x3F00
#define PCIE_RESIZABLE_2MB		(0x1 << 8)
#define PCIE_RESIZABLE_4MB		(0x2 << 8)
#define PCIE_RESIZABLE_8MB		(0x3 << 8)

#define SIZE(val) ((~(val & 0xFFFFFFF0)) + 1)
#define LINK_WAIT_MAX_RETRIES 100

static int sprd_pcie_linkup(void)
{
	u32 val;

	val = readl(SPRD_PCIE_BASE + PCIE_PHY_DBG_R1);
	return ((val & PCIE_PHY_DBG_R1_LINK_UP) &&
		(!(val & PCIE_PHY_DBG_R1_LINK_IN_TRAINING)));
}

static void sprd_pcie_dbi_ro_wr_en(void)
{
	u32 val;

	val = readl(SPRD_PCIE_BASE + PCIE_MISC_CTRL1_OFF);
	val |= PCIE_DBI_RO_WR_EN;
	writel(val, SPRD_PCIE_BASE + PCIE_MISC_CTRL1_OFF);
}

static void sprd_pcie_dbi_ro_wr_dis(void)
{
	u32 val;

	val = readl(SPRD_PCIE_BASE + PCIE_MISC_CTRL1_OFF);
	val &= ~PCIE_DBI_RO_WR_EN;
	writel(val, SPRD_PCIE_BASE + PCIE_MISC_CTRL1_OFF);
}

/* split one 64 bit BAR into two 32 bit BARs */
int sprd_pcie_split_bar(void)
{
	u32 val, bar_offset;
	int i;

	if (!sprd_pcie_linkup())
		printf("%s: pcie link fail, ignore it and go on...\n",
			__func__);

	for (i = 0; i < BAR_NUM; i++) {
		bar_offset = PCIE_BAR0 + (i * 4);
		val = readl(SPRD_PCIE_BASE + bar_offset);
		if (val & 0x4) {
			val &= ~0x4;
			sprd_pcie_dbi_ro_wr_en();
			writel(val, SPRD_PCIE_BASE + bar_offset);
			sprd_pcie_dbi_ro_wr_dis();
			/*
			 * enable the new BAR:
			 * e.g. BAR0 -> BAR0 + BAR1, enable BAR1)
			 */
			writel(PCIE_BAR_EN, (SPRD_PCIE_BASE +
					     SPRD_PCIE_DBI2 + bar_offset + 4));
		}

		val = readl(SPRD_PCIE_BASE + bar_offset);
		if (val & 0x4) {
			printf("%s: split bar%d fail, please check!\n",
				__func__, i);
			return -EINVAL;
		}
	}

	return 0;
}

/* resize bar */
int sprd_pcie_resize_bar(void)
{
	u32 val;
	u32 backup;
	u32 i;
	int retries;

	/* check if the link is up or not */
	for (retries = 0; retries < LINK_WAIT_MAX_RETRIES; retries++) {
		if (sprd_pcie_linkup()) {
			printf("%s: pcie link up\n", __func__);
			break;
		}
		mdelay(100);
	}

	val = readl(SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR_EXTENDED_CAP_HEADER);
	if ((val & PCIE_RESIZABLE_BAR_EXTENDED_CAPID) !=
	     PCIE_RESIZABLE_BAR_EXTENDED_CAPID)
		printf("%s: pcie device not support resize bar\n", __func__);

	val = BAR_SUPPORT_2MB | BAR_SUPPORT_8MB;
	sprd_pcie_dbi_ro_wr_en();
	writel(readl(SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR0) | val,
		   SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR0);
	writel(readl(SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR2) | val,
		   SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR2);
	writel(readl(SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR4) | val,
		   SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR4);
	sprd_pcie_dbi_ro_wr_dis();

	val = readl(SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR0_CTL);
	writel(val & (~PCIE_RESIZABLE_BAR_SIZE_MASK) | PCIE_RESIZABLE_8MB,
		   SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR0_CTL);
	val = readl(SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR2_CTL);
	writel(val & (~PCIE_RESIZABLE_BAR_SIZE_MASK) | PCIE_RESIZABLE_2MB,
		   SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR2_CTL);
	val = readl(SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR4_CTL);
	writel(val & (~PCIE_RESIZABLE_BAR_SIZE_MASK) | PCIE_RESIZABLE_2MB,
		   SPRD_PCIE_BASE + PCIE_RESIZABLE_BAR4_CTL);

	for (i = 0; i < BAR_NUM; i++) {
		backup = readl(SPRD_PCIE_BASE + PCIE_BAR0 + i * 4);
		writel(0xFFFFFFFF, SPRD_PCIE_BASE + PCIE_BAR0 + i * 4);
		val = readl(SPRD_PCIE_BASE + PCIE_BAR0 + i * 4);
		writel(backup, SPRD_PCIE_BASE + PCIE_BAR0 + i * 4);
		printf("%s: bar%d size 0x%x\n", __func__, i, SIZE(val));
	}

	printf("%s: resize bar success\n", __func__);

	return 0;
}
