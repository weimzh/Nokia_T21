#include <common.h>
#include <asm/io.h>
#include <asm/arch/sprd_reg.h>
#include "adi_hal_internal.h"
#include <asm/arch/common.h>
#include <otp_helper.h>
#include <sprd_pmic_misc.h>
#include "notifier.h"
#include "sprd_reset.h"

#define PBINT_7S_HW_FLAG (BIT(7))	//Only Hard 7s reset flag
#define PBINT_7S_SW_FLAG (BIT(12))	//All 7S reset flag,HW OR SW
#define CONFIG_7S_WR_CONTROL_EN		0x03991		//control 7s register read and writer
#define CONFIG_7S_WR_CONTROL_DISABLE	0x03990		//control 7s register can't read and writer

static u32 pbint_7s_flag = 0;
static struct notifier_block notify_pimc27xx_poweroff;
extern char *pwroffcause_cmdline;

int is_7s_reset(void)
{
	return pbint_7s_flag & PBINT_7S_SW_FLAG;
}

int is_7s_reset_for_systemdump(void)
{
	int val;
	int mask = PBINT_7S_SW_FLAG | PBINT_7S_HW_FLAG;

	val = pbint_7s_flag & mask;

	return (val == PBINT_7S_SW_FLAG);
}

#ifdef CONFIG_ADIE_UMP9620
static inline int por_wr_7s_control_enable(uint32_t enable)
{
	if(enable){
		sci_adi_write(ANA_REG_GLB_POR_WR_PROT_VALUE, CONFIG_7S_WR_CONTROL_EN,BIT_POR_WR_PROT_VALUE(~0));
	}
	else{
		sci_adi_write(ANA_REG_GLB_POR_WR_PROT_VALUE, CONFIG_7S_WR_CONTROL_DISABLE,BIT_POR_WR_PROT_VALUE(~0));
	}
	return sci_adi_read(ANA_REG_GLB_POR_WR_PROT_VALUE) & BIT_POR_WR_PROT;
}
#endif
static inline int pbint_7s_rst_disable(uint32_t disable)
{
	if (disable) {
		sci_adi_set(ANA_REG_GLB_POR_7S_CTRL, BIT_PBINT_7S_RST_DISABLE);
	} else {
		sci_adi_clr(ANA_REG_GLB_POR_7S_CTRL, BIT_PBINT_7S_RST_DISABLE);
	}
	return 0;
}

static inline int pbint_7s_rst_set_2keymode(uint32_t mode)
{
#if defined CONFIG_ADIE_SC2723S || defined CONFIG_ADIE_SC2723
	if (!mode) {
		sci_adi_set(ANA_REG_GLB_SWRST_CTRL, BIT_KEY2_7S_RST_EN);
	} else {
		sci_adi_clr(ANA_REG_GLB_SWRST_CTRL, BIT_KEY2_7S_RST_EN);
	}
#elif defined(CONFIG_ADIE_SC2721) || defined(CONFIG_ADIE_SC2720) || defined(CONFIG_ADIE_SC2730) || defined(CONFIG_ADIE_UMP9620)
	if (!mode) {
		sci_adi_set(ANA_REG_GLB_POR_7S_CTRL, BIT_KEY2_7S_RST_EN);
	} else {
		sci_adi_clr(ANA_REG_GLB_POR_7S_CTRL, BIT_KEY2_7S_RST_EN);
	}
#else
	if (!mode) {
		sci_adi_set(ANA_REG_GLB_SWRST_CTRL0, BIT_KEY2_7S_RST_EN);
	} else {
		sci_adi_clr(ANA_REG_GLB_SWRST_CTRL0, BIT_KEY2_7S_RST_EN);
	}
#endif
	return 0;
}
static inline int pbint_7s_rst_set_sw(uint32_t mode)
{
	if (mode) {
		sci_adi_set(ANA_REG_GLB_POR_7S_CTRL, BIT_PBINT_7S_RST_MODE);
	} else {
		sci_adi_clr(ANA_REG_GLB_POR_7S_CTRL, BIT_PBINT_7S_RST_MODE);
	}
	return 0;
}

static inline int pbint_7s_rst_set_swmode(uint32_t mode)
{
	if (mode) {
		sci_adi_set(ANA_REG_GLB_POR_7S_CTRL, BIT_PBINT_7S_RST_SWMODE);
	} else {
		sci_adi_clr(ANA_REG_GLB_POR_7S_CTRL, BIT_PBINT_7S_RST_SWMODE);
	}
	return 0;
}

static inline int pbint_7s_rst_set_threshold(uint32_t th)
{
#if defined CONFIG_ADIE_SC2723S || defined CONFIG_ADIE_SC2723
	th = (th - 1)/2;
#else
	if (th > 2) th--;
#endif
	sci_adi_write(ANA_REG_GLB_POR_7S_CTRL, BITS_PBINT_7S_RST_THRESHOLD(th), BITS_PBINT_7S_RST_THRESHOLD(~0));
	return 0;
}

int pbint_7s_rst_cfg(uint32_t en, uint32_t sw_rst, uint32_t short_rst)
{
	pbint_7s_flag = sci_adi_read(ANA_REG_GLB_POR_SRC_FLAG);
	sci_adi_set(ANA_REG_GLB_POR_7S_CTRL, BIT_PBINT_7S_FLAG_CLR);
	udelay(10);
	sci_adi_clr(ANA_REG_GLB_POR_7S_CTRL, BIT_PBINT_7S_FLAG_CLR); //it is necessary,

	/* ignore sw_rst, please refer to config.h */
	if (en) {
		pbint_7s_rst_set_threshold(CONFIG_7S_RST_THRESHOLD);
		pbint_7s_rst_set_sw(!sw_rst);

		pbint_7s_rst_set_swmode(short_rst);

		pbint_7s_rst_set_2keymode(CONFIG_7S_RST_2KEY_MODE);
	}
	return pbint_7s_rst_disable(!en);
}

void enable_ext_reset_mode(void)
{
	sci_adi_set(ANA_REG_GLB_POR_7S_CTRL, BIT_EXT_RSTN_MODE);
}

int sprd_get_pmic_chipid(void)
{
	unsigned int  chip_id = 0;

	chip_id = sci_adi_read(ANA_REG_GLB_CHIP_ID_HIGH) & 0xffff;

	return chip_id;
}

int is_hw_smpl_enable(void)
{
	return !!(sci_adi_read(ANA_REG_GLB_SMPL_CTRL1) & BIT_SMPL_EN);
}

int is_smpl_bootup(void)
{
	int ret = sci_adi_read(ANA_REG_GLB_SMPL_CTRL1) & BIT_SMPL_PWR_ON_FLAG;

	sci_adi_set(ANA_REG_GLB_SMPL_CTRL1, BIT_SMPL_PWR_ON_FLAG_CLR);

	return ret;

}
#define CONFIG_SMPL_EN_KEY			0x1935
#ifdef CONFIG_SMPL_EN
static int smpl_config(void)
{
	u32 val = BITS_SMPL_ENABLE(CONFIG_SMPL_EN_KEY);

	debugf("smpl_config\n");

	val |= BITS_SMPL_MODE(CONFIG_SMPL_THRESHOLD);

	return sci_adi_write(ANA_REG_GLB_SMPL_CTRL0, val, ~0);
}
#endif

static int pmic27xx_poweroff_cpu(struct notifier_block *nb, unsigned long action, void *data)
{
	int v;

	if (action != NOTIFY_RESET_ACTION_POWEROFF)
		return 0;

	v = 0x1000000;
	while (v--); // log delay

#if defined(CONFIG_ADIE_SC2723)
	sci_adi_set(ANA_REG_GLB_DCDC_SLP_CTRL0,  BIT_PWR_OFF_SEQ_EN); //auto poweroff by chip
#else
	sci_adi_write(ANA_REG_GLB_PWR_WR_PROT_VALUE,BITS_PWR_WR_PROT_VALUE(0x6e7F),BITS_PWR_WR_PROT_VALUE(~0));

	while (!(sci_adi_read(ANA_REG_GLB_PWR_WR_PROT_VALUE)&BIT_PWR_WR_PROT))printf("powerdown wait key\n");

	sci_adi_set(ANA_REG_GLB_POWER_PD_HW,  BIT_PWR_OFF_SEQ_EN); //auto poweroff by chip
#endif

	return 0;
}

int pmic_ver_get(int chipid_reg)
{
	int ver;

	ver = ANA_REG_GET(chipid_reg);
	return ver;
}

void ver_misc_config (void)
{
	int ver;

#ifdef CONFIG_ADIE_UMP9620
	ANA_REG_SET(ANA_REG_GLB_RESERVED_REG_CORE, BIT_RESERVED_CORE(0x40));

	ver = pmic_ver_get(ANA_REG_GLB_CHIP_ID_LOW);
	debugf("ump9620 ver is 0x%x\n", ver);

	ANA_REG_SET(ANA_REG_GLB_DCDC_WR_PROT_VALUE, BIT_DCDC_WR_PROT_VALUE(0x2017));
	if (ver == 0xa001) {
		ANA_REG_SET(ANA_REG_GLB_DCDC_PUB_REG1, BIT_DCDC_PUB_CF(0x1));
		ANA_REG_SET(ANA_REG_GLB_DCDC_MEMQ_REG1 ,BIT_DCDC_MEMQ_CF(0x1));
	}
	ANA_REG_SET(ANA_REG_GLB_DCDC_WR_PROT_VALUE, BIT_DCDC_WR_PROT_VALUE(0x0));
	ver = 0;
#endif

#ifdef CONFIG_ADIE_UMP9621
	ver = pmic_ver_get(REG_ANA_UMP9621_CHIP_ID_LOW);
	debugf("ump9621 ver is 0x%x\n", ver);

	if (ver <= 0xa001) {
		ANA_REG_SET(REG_ANA_UMP9621_DCDC_WR_PROT_VALUE,
			    BIT_ANA_UMP9621_DCDC_WR_PROT_VALUE(0x2017));
		ANA_REG_SET(REG_ANA_UMP9621_DCDC_MM_REG3, 0x85);
		ANA_REG_SET(REG_ANA_UMP9621_DCDC_WR_PROT_VALUE,
			    BIT_ANA_UMP9621_DCDC_WR_PROT_VALUE(0x0));
	}
#endif

#ifdef CONFIG_ADIE_UMP9622
	ver = pmic_ver_get(REG_ANA_UMP9622_CHIP_ID_LOW);
	debugf("ump9622 ver is 0x%x\n", ver);

	if (ver == 0xa000)
		ANA_REG_SET(REG_ANA_UMP9622_RESERVED_REG_RTC, BIT_ANA_UMP9622_RESERVED_RTC(0x80));
#endif
}

void check_poweroff_mode(void)
{
	unsigned pwroff_reason= 0;

	pwroff_reason = ANA_REG_GET(ANA_REG_GLB_POR_OFF_FLAG);
	printf("last shutdown flag ANA_REG_GLB_POR_OFF_FLAG:0x%x\n",pwroff_reason);

	sci_adi_set(ANA_REG_GLB_POR_OFF_FLAG, 0xffff);	//clear power off flag

	if(pwroff_reason == HWOFF_STATUS_PD )
		pwroffcause_cmdline = "device power down";
	else if(pwroff_reason == HWOFF_STATUS_OTP)
		pwroffcause_cmdline = "otp pwroff";
	else if(pwroff_reason == HWOFF_STATUS_HW)
		pwroffcause_cmdline = "write pwroff";
	else if(pwroff_reason == HWOFF_STATUS_HW_OTP)
		pwroffcause_cmdline = "otp & write pwroff";
	else if(pwroff_reason == HWOFF_STATUS_7S)
		pwroffcause_cmdline = "7s pwroff";
	else if(pwroff_reason == HWOFF_STATUS_7S_OTP)
		pwroffcause_cmdline = "7s & otp pwroff";
	else if(pwroff_reason == HWOFF_STATUS_7S_HW)
		pwroffcause_cmdline = "7s & write pwroff";
	else if(pwroff_reason == HWOFF_STATUS_7S_HW_OTP)
		pwroffcause_cmdline = "7s & write & otp pwroff";
	else if(pwroff_reason == HWOFF_STATUS_OVLO)
		pwroffcause_cmdline = "ovlo pwroff";
	else if(pwroff_reason == HWOFF_STATUS_OVLO_OTP)
		pwroffcause_cmdline = "ovlo & otp pwroff";
	else if(pwroff_reason == HWOFF_STATUS_OVLO_HW)
		pwroffcause_cmdline = "ovlo & write pwroff";
	else if(pwroff_reason == HWOFF_STATUS_OVLO_HW_OTP)
		pwroffcause_cmdline = "ovlo & write & otp pwroff";
	else if(pwroff_reason == HWOFF_STATUS_OVLO_7S)
		pwroffcause_cmdline = "ovlo and 7s pwroff";
	else if(pwroff_reason == HWOFF_STATUS_OVLO_7S_OTP)
		pwroffcause_cmdline = "ovlo & 7s & otp pwroff";
	else if(pwroff_reason == HWOFF_STATUS_OVLO_7S_HW)
		pwroffcause_cmdline = "ovlo & 7s & write pwroff";
	else if(pwroff_reason == HWOFF_STATUS_OVLO_7S_HW_OTP)
		pwroffcause_cmdline = "ovlo & 7s & write & otp pwroff";
	else if(pwroff_reason == HWOFF_STATUS_UVLO)
		pwroffcause_cmdline = "uvlo pwroff";
	else if(pwroff_reason == HWOFF_STATUS_UVLO_OTP)
		pwroffcause_cmdline = "uvlo & otp pwroff";
	else if(pwroff_reason == HWOFF_STATUS_UVLO_HW)
		pwroffcause_cmdline = "uvlo & write pwroff";
	else if(pwroff_reason == HWOFF_STATUS_UVLO_HW_OTP)
		pwroffcause_cmdline = "uvlo & write & otp pwroff";
	else if(pwroff_reason == HWOFF_STATUS_UVLO_7S)
		pwroffcause_cmdline = "uvlo and 7s pwroff";
	else if(pwroff_reason == HWOFF_STATUS_UVLO_7S_OTP)
		pwroffcause_cmdline = "uvlo & 7s & otp pwroff";
	else if(pwroff_reason == HWOFF_STATUS_UVLO_7S_HW)
		pwroffcause_cmdline = "uvlo & 7s & write pwroff";
	else if(pwroff_reason == HWOFF_STATUS_UVLO_7S_HW_OTP)
		pwroffcause_cmdline = "uvlo & 7s & write & otp pwroff";
	else
		printf("Unknown power off failure cause");
}

void pmic_misc_init(void)
{
	debugf("pmic_misc_init\n");
	ver_misc_config();
#ifdef CONFIG_ADIE_UMP9620
	if(por_wr_7s_control_enable(CONFIG_7S_RST_MODULE_EN)){
#endif
		pbint_7s_rst_cfg(CONFIG_7S_RST_MODULE_EN,
					CONFIG_7S_RST_SW_MODE,
					CONFIG_7S_RST_SHORT_MODE);
#ifdef CONFIG_ADIE_UMP9620
		por_wr_7s_control_enable(~CONFIG_7S_RST_MODULE_EN);
	}
#endif

#ifdef CONFIG_SMPL_EN
	smpl_config();
#endif

#if defined (CONFIG_ADIE_UMP9620)
	sci_adi_write(ANA_REG_GLB_OTP_CTRL,
		      (BIT_EXT_OTP_EN | BIT_OTP_OP(0) | BIT_OTP_EN),
		      (BIT_EXT_OTP_EN | BIT_OTP_OP(3) | BIT_OTP_EN));//enable otp
#endif

#if defined (CONFIG_ADIE_UMP9621)
	sci_adi_write(REG_ANA_UMP9621_OTP_CTRL,
		      (BIT_ANA_UMP9621_OTP_EN | BIT_ANA_UMP9621_OTP_OP(0)),
		     (BIT_ANA_UMP9621_OTP_EN | BIT_ANA_UMP9621_OTP_OP(3)));//enable otp
#endif

#if defined CONFIG_ADIE_SC2723S || defined CONFIG_ADIE_SC2723
	sci_adi_set(ANA_REG_GLB_LDO_SHPT_PD2, BIT_LDO_VIBR_SHPT_PD);	//close vibr short protection
#endif

#if defined(CONFIG_ADIE_SC2731) || defined(CONFIG_ADIE_SC2721) \
	|| defined(CONFIG_ADIE_SC2720) || defined(CONFIG_ADIE_SC2730)
	sci_adi_write(ANA_REG_GLB_OTP_CTRL, (BIT_OTP_EN|BITS_OTP_OP(0)), (BIT_OTP_EN|BITS_OTP_OP(3)));	//open otp and set 135C
#endif

#if defined(CONFIG_ADIE_SC2721) || defined(CONFIG_ADIE_SC2720) \
	|| defined(CONFIG_ADIE_SC2730) || defined(CONFIG_ADIE_UMP9620)
	check_poweroff_mode();
#endif
	regulator_pmic_init();

	notify_pimc27xx_poweroff.name = "pmic27xx_poweroff";
	notify_pimc27xx_poweroff.notifier_call = pmic27xx_poweroff_cpu;
	notify_pimc27xx_poweroff.priority = NOTIFY_RESET_POWEROFF_PRIORITY_LAST;
	notifier_reset_register(&notify_pimc27xx_poweroff, NOTIFY_RESET_TYPE_POWEROFF);
}

