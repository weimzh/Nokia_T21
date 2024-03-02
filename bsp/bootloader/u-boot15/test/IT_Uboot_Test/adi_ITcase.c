#include <common.h>
#include <asm/io.h>
#include <asm/errno.h>
#include <ubi_uboot.h>
#include <linux/sizes.h>
#include <adi.h>
#include <fdtdec.h>
#include <asm/arch/common.h>
#include <asm/arch/sprd_reg.h>
#include <command.h>

#define TEST_DATA1		0xa5a5
#define TEST_DATA2		0x5a5a
#define TEST_DATA3		0x5555
#define TEST_DATA4		0x5
#if defined(CONFIG_ADIE_SC2721)
#define PMIC_ID		0x2721
#define RW_REG1		(SPRD_ADISLAVE_PHYS + 0xd94)
#define RW_REG2		(SPRD_ADISLAVE_PHYS + 0xe38)
#define RW_REG3		(SPRD_ADISLAVE_PHYS + 0xe3c)
#elif defined(CONFIG_ADIE_SC2720)
#define PMIC_ID		0x2720
#define RW_REG1		(SPRD_ADISLAVE_PHYS + 0xde4)
#define RW_REG2		(SPRD_ADISLAVE_PHYS + 0xe24)
#define RW_REG3		(SPRD_ADISLAVE_PHYS + 0xe4c)
#elif defined(CONFIG_ADIE_SC2730)
#define PMIC_ID		0x2730
#define RW_REG1		(SPRD_ADISLAVE_PHYS + 0x1b4c)
#define RW_REG2		(SPRD_ADISLAVE_PHYS + 0x1b50)
#define RW_REG3		(SPRD_ADISLAVE_PHYS + 0x1c30)
#else
#warning "PMIC_ID is not defined!"
#endif

int adi_read_pmic_chipid_test(int argc, char *const argv[])
{
	u32 val = 0;
	sci_adi_init();
	val = sci_get_adie_chip_id();

	debug("read pmic chipid : 0x%x \n",(val&0xffff0000)>>16);

	if ((val&0xffff0000)>>16 != PMIC_ID)
		return -1;

	return 0;
}

int adi_write_test(int argc, char *const argv[])
{
	u16 or_msk = 0xf000, clear_msk = 0xf;
	u32 val = 0;

	sci_adi_raw_write(RW_REG1, TEST_DATA4);
	val = sci_adi_read(RW_REG1);
	debug("write test: RW_REG1 = 0x%x , DATA = 0x%x , val = 0x%x\n", RW_REG1,TEST_DATA4,val);
	if (val != TEST_DATA4)
		return -1;
	sci_adi_write(RW_REG1, or_msk, clear_msk);
	val = sci_adi_read(RW_REG1);
	debug("write test: RW_REG1 = 0x%x, val = 0x%x\n", RW_REG1,TEST_DATA4,val);
	if(val != ((TEST_DATA4 & ~clear_msk) | or_msk))
		return -1;
	return 0;
}

int adi_read_write_test(int argc, char *const argv[])
{
	u16 val = 0, data = 0;
	u32 reg = 0;
	if (argv[3] != NULL) {
		reg = simple_strtol(argv[3], NULL, 10);
		data = simple_strtol(argv[4], NULL, 10);

		debug("write test: reg = 0x%x , val = 0x%x \n", reg, data);
		sci_adi_raw_write(reg, data);
		val = sci_adi_read(reg);
		if (val != data)
			return -1;
	} else {
		debug("write test: reg = 0x%x , val = 0xa5a5 \n", RW_REG1);
		sci_adi_raw_write(RW_REG1, TEST_DATA1);
		val = sci_adi_read(RW_REG1);
		if (val != TEST_DATA1)
			return -1;
		sci_adi_raw_write(RW_REG2, TEST_DATA2);
		val = sci_adi_read(RW_REG2);
		if (val != TEST_DATA2)
			return -1;
		sci_adi_raw_write(RW_REG3, TEST_DATA3);
		val = sci_adi_read(RW_REG3);
		if (val != TEST_DATA3)
			return -1;
	}

	return 0;
}

U_BOOT_IT_TEST_REGISTER(adi_tc1000_read_pmic_chipid_test, adi_read_pmic_chipid_test, "this tc function is read pmic chipid");
U_BOOT_IT_TEST_REGISTER(adi_tc1001_write_test, adi_write_test, "this tc function is write data");
U_BOOT_IT_TEST_REGISTER(adi_tc1002_read_write_test, adi_read_write_test, "this tc function is read write data");
