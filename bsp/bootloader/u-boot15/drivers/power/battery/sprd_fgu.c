#include <common.h>
#include <asm/io.h>

#include <regs_adi.h>
#include "adi_hal_internal.h"
#include <asm/arch/sprd_reg.h>
#include <asm/arch/sprd_eic.h>
#include <sprd_battery.h>
#include "sprd_chg_helper.h"
#ifdef DEBUG
#define debugf(fmt, args...) do { printf("fgu:%s(): ", __func__); printf(fmt, ##args); } while (0)
#else
#define debugf(fmt, args...)
#endif
#include <dm.h>

extern int charger_connected(void);
bool charge_first_powr_on;

extern void power_down_devices(unsigned pd_cmd);

#define REGS_FGU_BASE ANA_FGU_BASE
#define REG_FGU_START                   SCI_ADDR(REGS_FGU_BASE, 0x0000)
#define REG_FGU_CONFIG                  SCI_ADDR(REGS_FGU_BASE, 0x0004)
#define REG_FGU_INT_EN                  SCI_ADDR(REGS_FGU_BASE, 0x0010)
#define REG_FGU_INT_CLR                 SCI_ADDR(REGS_FGU_BASE, 0x0014)
#define REG_FGU_INT_RAW                 SCI_ADDR(REGS_FGU_BASE, 0x0018)
#define REG_FGU_VOLT_VAL                SCI_ADDR(REGS_FGU_BASE, 0x0020)
#define REG_FGU_OCV_VAL                 SCI_ADDR(REGS_FGU_BASE, 0x0024)
#define REG_FGU_POCV_VAL                SCI_ADDR(REGS_FGU_BASE, 0x0028)
#define REG_FGU_CURT_VAL                SCI_ADDR(REGS_FGU_BASE, 0x002c)
#define REG_FGU_CURT_OFFSET             SCI_ADDR(REGS_FGU_BASE, 0x0090)
#define BIT_VOLT_H_VALID                ( BIT(12) )
#define BITS_VOLT_DUTY(_x_)             ( (_x_) << 5 & (BIT(5)|BIT(6)) )
#define BIT_VOL_READY_INT				(BIT(6))

#define REG_FGU_USER_AREA_SET             SCI_ADDR(REGS_FGU_BASE, 0x00A0)
#define REG_FGU_USER_AREA_CLEAR             SCI_ADDR(REGS_FGU_BASE, 0x00A4)
#define REG_FGU_USER_AREA_STATUS             SCI_ADDR(REGS_FGU_BASE, 0x00A8)

#define REG_FGU_USER_AREA1_SET             SCI_ADDR(REGS_FGU_BASE, 0x00C0)
#define REG_FGU_USER_AREA1_CLEAR             SCI_ADDR(REGS_FGU_BASE, 0x00C4)
#define REG_FGU_USER_AREA1_STATUS             SCI_ADDR(REGS_FGU_BASE, 0x00C8)

#define SC27XX_FGU_MODE_AREA_MASK	0xf000
#define SC27XX_FGU_CAP_AREA_MASK	0xfff
#define SC27XX_FGU_MODE_AREA_SHIFT	12

#define SC27XX_FGU_FIRST_POWERTON	0xf
#define SC27XX_FGU_DEFAULT_CAP		0xfff

#define SC27XX_FGU_CAP_INTEGER_MASK	0xff
#define SC27XX_FGU_CAP_DECIMAL_MASK	0xf
#define SC27XX_FGU_CAP_DECIMAL_SHIFT	8

#define SC27XX_FGU_RTC2_RESET_VALUE	0xA05


#define BITS_POWERON_TYPE_SHIFT   12
#define BITS_POWERON_TYPE(_x_)           ( (_x_) << 12 & (0xF000))
#define BITS_RTC_AREA_SHIFT     0
#define BITS_RTC_AREA(_x_)           ( (_x_) << 0 & (0xFFF) )
#define BITSINDEX(b, o, w)		((b) * (w) + (o))

#define FIRST_POWERTON  0xF
#define NORMAIL_POWERTON  0x5
#define NORMAL_TO_FIRST_POWERON 0xA
#define WDG_POWERTON  0xA

#define SPRDBAT_FGUADC_CAL_NO         	0
#define SPRDBAT_FGUADC_CAL_NV         	1
#define SPRDBAT_FGUADC_CAL_CHIP		2
#define VOL_READY_INT_THRESHOLD		1000

int low_bat;
static int fgu_nv_4200mv = 2752;
static int fgu_nv_3600mv = 2374;

struct sprdfgu_cal {
	int vol_1000mv_adc;
	int vol_offset;
	int cal_type;
};

#ifdef CONFIG_DM_FGU
struct sprd_fgu_dm_data {
	unsigned int blk_index;
};

struct sprd_fgu_dm_data fgu_dm_data;

/*sc2720 sc2721 sc2730 sc2731 */
#define EFUSE_BLOCK_WIDTH		16
#define EFUSE_BIT_INDEX			48
#define EFUSE_FGU_BIT_LENGTH		9
#endif

static struct sprdfgu_cal fgu_cal =
	{ 2872, 0, SPRDBAT_FGUADC_CAL_NO};

static u32 sprdfgu_adc2vol_mv(int adc)
{
	return ((adc + fgu_cal.vol_offset) * 1000)
		/ fgu_cal.vol_1000mv_adc;
}

static  int sprdfgu_reg_get(unsigned long reg)
{
	int old_value = sci_adi_read(reg);
	int new_value, times = 1000;

	while ((old_value != (new_value = sci_adi_read(reg))) &&
		(times > 0)) {
		old_value = new_value;
		times--;
	}
	return new_value;
}

uint32_t sprdfgu_read_vbat_vol(void)
{
	int cur_vol_raw;
	uint32_t temp;

	cur_vol_raw = sprdfgu_reg_get(REG_FGU_VOLT_VAL);
	temp = sprdfgu_adc2vol_mv(cur_vol_raw);
	return temp;
}


static bool sc27xx_fgu_is_first_poweron(void)
{
	int status, cap, mode;

	status = sci_adi_read(REG_FGU_USER_AREA_STATUS);

	/*
	 * We use low 4 bits to save the last battery capacity and high 12 bits
	 * to save the system boot mode.
	 */
	mode = (status & SC27XX_FGU_MODE_AREA_MASK) >> SC27XX_FGU_MODE_AREA_SHIFT;
	cap = status & SC27XX_FGU_CAP_AREA_MASK;

	/*
	 * When FGU has been powered down, the user area registers became
	 * default value (0xffff), which can be used to valid if the system is
	 * first power on or not.
	 */
	if (mode == SC27XX_FGU_FIRST_POWERTON || cap == SC27XX_FGU_DEFAULT_CAP)
		return true;

	return false;
}

static int sc27xx_fgu_save_last_cap(int cap)
{
	u32 value;

	ANA_REG_MSK_OR(REG_FGU_USER_AREA_CLEAR, SC27XX_FGU_CAP_AREA_MASK, SC27XX_FGU_CAP_AREA_MASK);

	/*
	 * Since the user area registers are put on power always-on region,
	 * then these registers changing time will be a little long. Thus
	 * here we should delay 200us to wait until values are updated
	 * successfully.
	 */
	udelay(200);

	value = (cap / 10) & SC27XX_FGU_CAP_INTEGER_MASK;
	value |= ((cap % 10) & SC27XX_FGU_CAP_DECIMAL_MASK) << SC27XX_FGU_CAP_DECIMAL_SHIFT;

	ANA_REG_MSK_OR(REG_FGU_USER_AREA_SET, value, SC27XX_FGU_CAP_AREA_MASK);

	/*
	 * Since the user area registers are put on power always-on region,
	 * then these registers changing time will be a little long. Thus
	 * here we should delay 200us to wait until values are updated
	 * successfully.
	 */
	udelay(200);

	ANA_REG_MSK_OR(REG_FGU_USER_AREA_CLEAR, 0, SC27XX_FGU_CAP_AREA_MASK);

}

/*
 * We get the percentage at the current temperature by multiplying
 * the percentage at normal temperature by the temperature conversion
 * factor, and save the percentage before conversion in the rtc register
 */
static int sc27xx_fgu_save_normal_temperature_cap(int cap)
{
	u32 value;

	ANA_REG_MSK_OR(REG_FGU_USER_AREA1_CLEAR, SC27XX_FGU_CAP_AREA_MASK, SC27XX_FGU_CAP_AREA_MASK);

	/*
	 * Since the user area registers are put on power always-on region,
	 * then these registers changing time will be a little long. Thus
	 * here we should delay 200us to wait until values are updated
	 * successfully.
	 */
	udelay(200);

	value = (cap / 10) & SC27XX_FGU_CAP_INTEGER_MASK;
	value |= ((cap % 10) & SC27XX_FGU_CAP_DECIMAL_MASK) << SC27XX_FGU_CAP_DECIMAL_SHIFT;

	ANA_REG_MSK_OR(REG_FGU_USER_AREA1_SET, value, SC27XX_FGU_CAP_AREA_MASK);

	/*
	 * Since the user area registers are put on power always-on region,
	 * then these registers changing time will be a little long. Thus
	 * here we should delay 200us to wait until values are updated
	 * successfully.
	 */
	udelay(200);

	ANA_REG_MSK_OR(REG_FGU_USER_AREA1_CLEAR, 0, SC27XX_FGU_CAP_AREA_MASK);
}

static int sc27xx_fgu_read_last_cap(void)
{
	int value = 0, cap = 0;
	value = sci_adi_read(REG_FGU_USER_AREA_STATUS);

	cap = (value & SC27XX_FGU_CAP_INTEGER_MASK) * 10;
	cap += (value >> SC27XX_FGU_CAP_DECIMAL_SHIFT) & SC27XX_FGU_CAP_DECIMAL_MASK;

	return cap;
}

static int sc27xx_fgu_read_normal_temperature_cap(void)
{
	int value = 0, normal_temp_cap = 0;

	value = sci_adi_read(REG_FGU_USER_AREA1_STATUS);

	normal_temp_cap = (value & SC27XX_FGU_CAP_INTEGER_MASK) * 10;
	normal_temp_cap += (value >> SC27XX_FGU_CAP_DECIMAL_SHIFT) & SC27XX_FGU_CAP_DECIMAL_MASK;

	return normal_temp_cap;
}

/*
 * When system boots on, we can not read battery capacity from coulomb
 * registers, since now the coulomb registers are invalid. So we should
 * calculate the battery open circuit voltage, and get current battery
 * capacity according to the capacity table.
 */
void sc27xx_fgu_get_boot_capacity(struct sc27xx_fgu_data data)
{
	uint32_t ocv;
	bool is_first_poweron = sc27xx_fgu_is_first_poweron();

	/*
	 * If system is not the first power on, we should use the last saved
	 * battery capacity as the initial battery capacity. Otherwise we should
	 * re-calculate the initial battery capacity.
	 */
	if (!is_first_poweron) {
		data.boot_cap = sc27xx_fgu_read_last_cap();
		printf("boot_cap:%d\n", data.boot_cap);
		data.normal_temp_cap = sc27xx_fgu_read_normal_temperature_cap();
		printf("normal_temp_cap:%d\n",data.normal_temp_cap);

	}
	if(data.normal_temp_cap < 300 || data.boot_cap < 300)
		low_bat = 1;
	else
		low_bat = 0;
	printf("boot_cap:%d,normal_temp_cap:%d,is_first_poweron =%d,low_bat = %d\n", data.boot_cap,  data.normal_temp_cap,is_first_poweron,low_bat);

}

static void sprdfgu_rtc_reg_write(uint32_t val)
{
	sci_adi_write(REG_FGU_USER_AREA_CLEAR, BITS_RTC_AREA(~val),
		      BITS_RTC_AREA(~0));
	sci_adi_write(REG_FGU_USER_AREA_SET, BITS_RTC_AREA(val),
		      BITS_RTC_AREA(~0));
}

static uint32_t sprdfgu_rtc_reg_read(void)
{
	return (sci_adi_read(REG_FGU_USER_AREA_STATUS) & BITS_RTC_AREA(~0)) >>
	    BITS_RTC_AREA_SHIFT;
}

static void sprdfgu_poweron_type_write(uint32_t val)
{
	sci_adi_write(REG_FGU_USER_AREA_CLEAR, BITS_POWERON_TYPE(~val),
		      BITS_POWERON_TYPE(~0));
	sci_adi_write(REG_FGU_USER_AREA_SET, BITS_POWERON_TYPE(val),
		      BITS_POWERON_TYPE(~0));
}

static uint32_t sprdfgu_poweron_type_read(void)
{
	return (sci_adi_read(REG_FGU_USER_AREA_STATUS) & BITS_POWERON_TYPE(~0))
	    >> BITS_POWERON_TYPE_SHIFT;
}

#ifdef CONFIG_DM_FGU
static int sprdfgu_dm_cal_get(unsigned int *p_cal_data)
{
	unsigned int data = 0;

	debugf("###:blk index = %d\n", fgu_dm_data.blk_index);

	data |= sprd_pmic_efuse_read(fgu_dm_data.blk_index);
	data >>= (EFUSE_BIT_INDEX & (EFUSE_BLOCK_WIDTH - 1));
	data &= BIT(EFUSE_FGU_BIT_LENGTH) - 1;

	debugf("###:fgu_dm_cal_get 4.2 data data: 0x%x\n", data);
	p_cal_data[0] = (data + 6963) - 4096 - 256;

	return 0;
}
#else
static int sprdfgu_cal_get(unsigned int *p_cal_data)
{
	unsigned int data;

#if defined(CONFIG_ADIE_SC2723)
	data = sprd_pmic_efuse_read_bits(BITSINDEX(12, 0, 8), 9);
	debugf("fgu_cal_get 4.2 data data: 0x%x\n", data);
	p_cal_data[0] = (data + 6963) - 4096 - 256;

	return 0;

#elif defined(CONFIG_ADIE_SC2731) || defined(CONFIG_ADIE_SC2721)|| defined(CONFIG_ADIE_SC2720) || defined(CONFIG_ADIE_SC2730)
	data = sprd_pmic_efuse_read_bits(BITSINDEX(3, 0, 16), 9);
	debugf("fgu_cal_get 4.2 data data: 0x%x\n", data);
	p_cal_data[0] = (data + 6963) - 4096 - 256;

	return 0;

#elif defined(CONFIG_ADIE_UMP9620)
	data = sprd_pmic_efuse_read_bits(BITSINDEX(38, 7, 16), 9);
	debugf("ump9620 fgu_cal_get 4.2 data data: 0x%x\n", data);
	p_cal_data[0] = (data + 6963) - 4096 - 256;

	return 0;
#else
	data = sprd_pmic_efuse_read_bits(BITSINDEX(3, 0, 16), 9);
	debugf("fgu_cal_get 4.2 data data: 0x%x\n", data);
	p_cal_data[0] = (data + 6963) - 4096 - 256;

	return 0;
#endif
}
#endif

#ifdef CONFIG_DM_FGU
static int sprd_dm_fgu_init(void)
{
	struct udevice *devp;
	int ret;

	ret = uclass_get_device(UCLASS_FGU, 0, &devp);
	if (ret) {
		pr_err("###%s:failed to get dev ret = %d\n", __func__, ret);
		return ret;
	}

	return 0;
}
#endif

static void sprdfgu_cal_init(void)
{
	if (fgu_nv_3600mv == 0) {
		fgu_cal.vol_1000mv_adc =
		    DIV_ROUND_CLOSEST((fgu_nv_4200mv) * 10, 42);
		fgu_cal.vol_offset = 0;
	} else {
		fgu_cal.vol_1000mv_adc =
		    DIV_ROUND_CLOSEST((fgu_nv_4200mv - fgu_nv_3600mv) * 10, 6);
		fgu_cal.vol_offset =
		    0 - (fgu_nv_4200mv * 10 - fgu_cal.vol_1000mv_adc * 42) / 10;
	}

	debugf("4200mv=%d, 3600mv=%d\n", fgu_nv_4200mv, fgu_nv_3600mv);

	debugf("fgu_cal.vol_1000mv_adc=%d, vol_offset=%d\n",
		fgu_cal.vol_1000mv_adc, fgu_cal.vol_offset);
}

#define mdelay(_ms) udelay(_ms*1000)

static int sprdfgu_cal_from_chip(void)
{
	unsigned int fgu_data[4] = { 0 };

#ifdef CONFIG_DM_FGU
		if (sprdfgu_dm_cal_get(fgu_data)) {
			pr_err("###%s:dm efuse no cal data\n", __func__);
			return 1;
		}
#else
	if (sprdfgu_cal_get(fgu_data)) {
		debugf("efuse no cal data\n");
		return 1;
	}
#endif

	debugf("fgu_data: 0x%x\n", fgu_data[0]);

	fgu_nv_4200mv = fgu_data[0];
	fgu_nv_3600mv = 0;
	fgu_cal.cal_type = SPRDBAT_FGUADC_CAL_CHIP;
	debugf("sprdfgu: one point\n");
	return 0;
}


void sprdfgu_init(void)
{
	int cnt = VOL_READY_INT_THRESHOLD;
	int ret;

	sci_adi_set(ANA_REG_GLB_ARM_MODULE_EN, BIT_ANA_FGU_EN);
#if defined(CONFIG_ADIE_SC2721) || defined(CONFIG_ADIE_SC2720)  || defined(CONFIG_ADIE_SC2730) || defined(CONFIG_ADIE_UMP9620)
	sci_adi_set(ANA_REG_GLB_RTC_CLK_EN, BIT_RTC_FGU_EN);
#else
	sci_adi_set(ANA_REG_GLB_RTC_CLK_EN, BIT_RTC_FGU_EN | BIT_RTC_FGUA_EN);
#endif
	sci_adi_clr(REG_FGU_INT_EN, 0xFFFF);	//disable int after watchdog reset
	sci_adi_set(REG_FGU_INT_CLR, 0xFFFF);
	sci_adi_write(REG_FGU_CURT_OFFSET, 0, ~0);	//init offset after watchdog reset

	/* When the symbol position BIT_VOL_READY_INT is 1,
	 * the FGU voltage can be picked up
	 */
	while (!(sci_adi_read(REG_FGU_INT_RAW) & BIT_VOL_READY_INT) && cnt--){
		mdelay(2);
	}

	if (cnt <= 0)
		printf("error!!! fgu voltage not ready!");

#ifdef CONFIG_DM_FGU
	ret = sprd_dm_fgu_init();
	if (ret) {
		pr_err("###%s: failed to get dts para ret = %d", __func__, ret);
		return;
	}
#endif

	sprdfgu_cal_from_chip();
	sprdfgu_cal_init();
}

void fastboot_init_power_mode(void)
{
        if ((FIRST_POWERTON == sprdfgu_poweron_type_read())
	    || (sprdfgu_rtc_reg_read() == 0xFFF)) {
		sprdfgu_rtc_reg_write(0xFF);
		mdelay(1);
		sprdfgu_poweron_type_write(NORMAL_TO_FIRST_POWERON);
		printf("fast boot set power mode to NORMAL_TO_FIRST_POWERON !!!!!\n");
	}

	return;
}


void sprdfgu_late_init(void)
{
	if (charger_connected() && sprdbat_is_battery_connected()) {
		if ((NORMAL_TO_FIRST_POWERON != sprdfgu_poweron_type_read()) &&
		    ((FIRST_POWERTON == sprdfgu_poweron_type_read()) ||
		     (sprdfgu_rtc_reg_read() == 0xFFF))) {
			charge_first_powr_on = true;
			sprdfgu_rtc_reg_write(0xFF);
			mdelay(1);
			sprdfgu_poweron_type_write(NORMAIL_POWERTON);
			printf("charge first poweron reset!!!!!\n");
			mdelay(3);
			power_down_devices(0);
		}
	}

	if (sprdfgu_rtc_reg_read() == 0xFF) {
		charge_first_powr_on = true;
		printf("secend poweron !!!!!\n");
		sprdfgu_poweron_type_write(NORMAL_TO_FIRST_POWERON);
		mdelay(1);
		sprdfgu_rtc_reg_write(0xFFF);
	}

	if ((FIRST_POWERTON == sprdfgu_poweron_type_read()) ||
	    (sprdfgu_rtc_reg_read() == 0xFFF)) {
		charge_first_powr_on = true;
		printf("charge first poweron!!!!!\n");
	}
}

#ifdef CONFIG_DM_FGU
/*
 *sc2721 sc2720 sc2731 sc2730: blk_index: 3
 *this must config carefully,or it will lowpower ,can't power on
 */
static int sprd_fgu_probe(struct udevice *dev)
{
	int ret;

	ret = dev_read_u32(dev, "sprd,fgu-blk-index", &fgu_dm_data.blk_index);
	if (ret) {
		pr_err("###%s:failed to get fgu_blk_index ret=%d\n",
		       __func__, ret);
		return ret;
	}

	return 0;
}

static const struct udevice_id sprd_fgu_ids[] = {
	{.compatible = "sprd,sc2731-fgu"},
	{.compatible = "sprd,sc2730-fgu"},
	{.compatible = "sprd,sc2721-fgu"},
	{.compatible = "sprd,sc2720-fgu"},
	{ }
};

U_BOOT_DRIVER(sprd_fgu) = {
	.name = "sprd-fgu",
	.id = UCLASS_FGU,
	.of_match = sprd_fgu_ids,
	.probe = sprd_fgu_probe,
};

UCLASS_DRIVER(fgu) = {
	.name = "fgu",
	.id = UCLASS_FGU,
};
#endif

