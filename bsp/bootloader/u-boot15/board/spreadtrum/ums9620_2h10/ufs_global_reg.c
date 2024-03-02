#include <asm/types.h>
#include <common.h>
#include <linux/types.h>
#include <part.h>
#include <asm/arch-sc9630/sci_types.h>
#include <asm/arch/sprd_reg.h>
#include <asm/io.h>
#include <sprd_ufs.h>

#define ARG1_MIB_SEL(attr, sel) (((sel & 0xFFFF) << 16) | (attr & 0xFFFF))

int ufs_phy_sram_init_done()
{
	uint32 value = 0;
	int retry = 10000;

	do {
		value = CHIP_REG_GET(0x6438000c);
		if ((value & BIT(0)) == BIT(0)) {
			dme_set(0x8116, 0x1c);
			dme_set(0x8117, 0x40);
			dme_set(0x8118, 0x04);
			dme_set(0x8119, 0x00);
			dme_set(0x811c, 0x01);
			dme_set(0xd085, 0x01);

			dme_set(0x8116, 0x1c);
			dme_set(0x8117, 0x41);
			dme_set(0x8118, 0x04);
			dme_set(0x8119, 0x00);
			dme_set(0x811c, 0x01);
			dme_set(0xd085, 0x01);
			return 0;
		} else {
			udelay(1000);
			retry--;
		}
	} while(retry > 0);

	return -1;
}

int ufshci_init_phy()
{
	int ret = 0;

	dme_set(0x8132, 0x90);
	dme_set(0x811f, 0x1);

	dme_set(ARG1_MIB_SEL(0x8009, 4), 0x1);
	dme_set(ARG1_MIB_SEL(0x8009, 5), 0x1);
	dme_set(0xd085, 0x1);

	ret = ufs_phy_sram_init_done();
	if (ret) {
		debugf("ufs phy sram init failed!\n");
		return -1;
	}

	CHIP_REG_OR(0x6438000c, BIT(1));
	dme_set(0xd085, 0x1);
	dme_set(0xd0c1, 0x0);

	return 0;
}

void init_global_reg()
{
	CHIP_REG_OR(REG_AON_CLK_CGM_UFS_AON_SEL_CFG,
		    BIT_AON_CLK_CGM_UFS_AON_SEL(0x5));
	CHIP_REG_OR(REG_AP_AHB_AHB_EB, BIT_AP_AHB_UFS_EB);
	CHIP_REG_OR(REG_AP_AHB_AHB_EB1, BIT_AP_AHB_UFS_CFG_EB);
	CHIP_REG_OR(REG_AON_APB_UFSDEV_REG, BIT_AON_APB_UFSDEV_SOFT_RST);
	CHIP_REG_OR(REG_AP_AHB_AHB_RST, BIT_AP_AHB_UFS_SOFT_RST);

	udelay(1000);

	CHIP_REG_AND(REG_AON_APB_UFSDEV_REG, ~BIT_AON_APB_UFSDEV_SOFT_RST);
	CHIP_REG_AND(REG_AP_AHB_AHB_RST, ~BIT_AP_AHB_UFS_SOFT_RST);
}

int ufshci_enable_bottom()
{
	int ret = 0;

	ret = ufshci_init_phy();
	if (ret)
		return -1;

	return 0;
}

struct ufs_hba_variant_ops hba_vops = {
	.name = "qogirn6pro",
	.enable_bottom = ufshci_enable_bottom,
};
