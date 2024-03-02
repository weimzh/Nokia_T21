#include <common.h>
#include <sprd_ufs.h>
#include <linux/io.h>
#include <asm/arch/sprd_reg.h>

void ufs_phy_controller_init()
{
	CHIP_REG_SET((0x64170000 + 0x80 * (85/16) + 0x04), 0xFF);
	CHIP_REG_SET((0x64170000 + 0x80 * (85/16) + 0x08), 0xFF);

	CHIP_REG_SET((0x64170000 + 0x80 * (85/16)), ~(1 << (85 % 16)));
	udelay(1000);
	CHIP_REG_SET((0x64170000 + 0x80 * (85/16)), (1 << (85 % 16)));
	udelay(1000);
	CHIP_REG_SET((0x64170000 + 0x80 * (85/16)), ~(1 << (85 % 16)));
}

void init_global_reg()
{
	uint32_t base_addr;

	CHIP_REG_AND(0x2001013c, 0xFFFFFFC0);
	CHIP_REG_OR(0x2001013c, 0x1);
	CHIP_REG_AND(0x20010148, 0xFFFFFFC0);
	CHIP_REG_OR(0x20010148, 0x1);

	udelay(3000);

	CHIP_REG_OR(0x20000000, BIT_6);
	CHIP_REG_OR(0x64900004, BIT_15);
	CHIP_REG_OR(0x2000001c, BIT_3 | BIT_2 | BIT_1 | BIT_0);
	CHIP_REG_OR(0x64900004, BIT_12);
	CHIP_REG_OR(0x64900004, BIT_11);
	CHIP_REG_SET(0x642e01c0, 0x30);
	CHIP_REG_OR(0x64900004, BIT_1 | BIT_6);

	CHIP_REG_OR(0x64900004, BIT_6);
	base_addr = 0x64040000 + 2 * 0x20;
	CHIP_REG_SET(base_addr, 0xFFFFFFFF);
	CHIP_REG_SET(base_addr + 0x4, 0x0);
	CHIP_REG_SET(base_addr + 0x14, 0x8);
	CHIP_REG_OR(base_addr + 0x10, BIT_1 | BIT_0);

	ufs_phy_controller_init();

	CHIP_REG_OR(0x20000004, BIT_6);
	CHIP_REG_AND(0x20000004, ~BIT_6);
	CHIP_REG_OR(0x64900010, BIT_15);
	CHIP_REG_AND(0x64900010, ~BIT_15);
}

static int ufshci_enable_bottom(void)
{
	CHIP_REG_SET((0x64170000 + 0x80 * (85/16) + 0x04), 0xFF);
	CHIP_REG_SET((0x64170000 + 0x80 * (85/16) + 0x08), 0xFF);
	CHIP_REG_AND((0x64170000 + 0x80 * (85/16)), ~(1 << (85 % 16)));
	CHIP_REG_OR((0x64170000 + 0x80 * (85/16)), (1 << (85 % 16)));
	CHIP_REG_AND((0x64170000 + 0x80 * (85/16)), ~(1 << (85 % 16)));

	tc_dwc_g240_16nm_config();

	return 0;
}

struct ufs_hba_variant_ops hba_vops = {
	.name = "qogirn6pro",
	.enable_bottom = ufshci_enable_bottom,
};
