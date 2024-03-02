#include <common.h>
#include <asm/io.h>

#include <regs_adi.h>
#include "adi_hal_internal.h"
#include <asm/arch/sprd_reg.h>
#include <asm/arch/sprd_eic.h>
#include <sprd_battery.h>
#include <asm/arch/check_reboot.h>
#include <chipram_env.h>
#include <sprd_pmic_misc.h>
#include "sprd_chg_helper.h"
#include "sprd_common_rw.h"

#define BAT_ID		1
#define BAT_GPIO	170

#ifdef DEBUG
#define debugf(fmt, args...); \
	do { printf("bat:%s(): ", __func__); printf(fmt, ##args); } while (0)
#else
#define debugf(fmt, args...);
#endif

#define BAT_VOL    3100
#define IBUS_LOW_CUR    2100000
#define IBAT_LOW_CUR    1500000
#define IBUS_CUR    2100000
#define IBAT_CUR    1500000
#define PRE_CHG_CUR 240
 
#ifndef MISCDATA_ADDRESS_BASE
#define MISCDATA_ADDRESS_BASE 0
#endif
#ifndef MISCDATA_MAGIC_OFFSET
#define MISCDATA_MAGIC_OFFSET 0
#endif
#ifndef MISCDATA_MAGIC_SIZE
#define MISCDATA_MAGIC_SIZE 0
#endif
#ifndef MISCDATA_RTC_TIME_OFFSET
#define MISCDATA_RTC_TIME_OFFSET 0
#endif
#ifndef MISCDATA_RTC_TIME_SIZE
#define MISCDATA_RTC_TIME_SIZE 0
#endif
#ifndef MISCDATA_CHARGE_CYCLE_OFFSET
#define MISCDATA_CHARGE_CYCLE_OFFSET 0
#endif
#ifndef MISCDATA_CHARGE_CYCLE_SIZE
#define MISCDATA_CHARGE_CYCLE_SIZE 0
#endif
#ifndef MISCDATA_BASP_OFFSET
#define MISCDATA_BASP_OFFSET 0
#endif
#ifndef MISCDATA_BASP_SIZE
#define MISCDATA_BASP_SIZE 0
#endif
#ifndef BAT_ID
#define BAT_ID  0
#endif
#ifndef MISCDATA_CAPACITY_OFFSET
#define MISCDATA_CAPACITY_OFFSET	0
#endif
#ifndef MISCDATA_CAPACITY_SIZE
#define MISCDATA_CAPACITY_SIZE		0
#endif
#ifndef MISCDATA_CAPACITY_CHECK_OFFSET
#define MISCDATA_CAPACITY_CHECK_OFFSET	0
#endif
#ifndef MISCDATA_CAPACITY_CHECK_SIZE
#define MISCDATA_CAPACITY_CHECK_SIZE	0
#endif
#ifndef MISCDATA_SHUTDOWN_CHARGE_FLAG_OFFSET
#define MISCDATA_SHUTDOWN_CHARGE_FLAG_OFFSET 0
#endif
#ifndef MISCDATA_SHUTDOWN_CHARGE_FLAG_SIZE
#define MISCDATA_SHUTDOWN_CHARGE_FLAG_SIZE 0
#endif


#define CAPACITY_TRACK_CAP_KEY0	0x20160726
#define CAPACITY_TRACK_CAP_KEY1	0x15211517

/* 30min = 30*60*1000ms*/
#define DEAD_DETECT_MS	(30 * 60 * 1000)
#define DEAD_DETECT_CNT	((DEAD_DETECT_MS) / (SPRDBAT_CHG_POLLING_T))
#define DEAD_DETECT_VOL	2000	/* 2000mv */
#define ENABLE_CHARGE_DOWNLOAD_THRESHOLD      3700
#define SPRD_BATTERY_MAGIC_NUM	0x5a5aa5a5

extern chipram_env_t* get_chipram_env(void);

extern void power_down_devices(unsigned pd_cmd);
extern int sprd_eic_request(unsigned offset);
extern int sprd_eic_get(unsigned offset);

static int pre_cur,chg_cur,limit_cur;
static const struct sprdchg_ic_operations *sprd_chg_ic_op;
static int count;

extern bool charge_first_powr_on;
extern unsigned long sprd_rtc_get_sec(void);
extern int sprd_get_batid(void);

/*return gpio for BAT_ID, 0 for GY436596PL, 1 for HT-T-0205*/
static unsigned int gpio_state(unsigned int GPIO_NUM)
{
	int value = 0 ;

	sprd_gpio_request(NULL, GPIO_NUM);
	sprd_gpio_direction_input(NULL, GPIO_NUM);
	value = sprd_gpio_get(NULL,GPIO_NUM);

	return value > 0;
}


int sprd_get_bat_id(void)
{
	unsigned int gpio_val = 0;

	gpio_val = gpio_state(BAT_GPIO);
	return gpio_val;
}

static void sprdchg_timer_callback(void)
{
	if (!sprd_chg_ic_op)
		return;

	count ++;
	if(count == 50){
		count = 0;
		sprd_chg_ic_op->timer_callback();
	}
}

void sprdbat_lowbat_chg(void)
{
	unsigned int vbat_vol = sprdfgu_read_vbat_vol();
	static unsigned int polling_cnt = 0;
	static int dead_bat_flag = 0;

	if (!sprd_chg_ic_op)
		return;

	debugf("sprdbat_lowbat_chg vbat_vol:%d\n", vbat_vol);
	if (vbat_vol < BAT_VOL) {
		limit_cur = IBUS_LOW_CUR;
		chg_cur = IBAT_LOW_CUR;
	} else {
		enum sprd_adapter_type charger;
		limit_cur = IBUS_CUR;
		chg_cur = IBAT_CUR;

		charger = sprdchg_charger_is_adapter();
		if (charger == ADP_TYPE_DCP) {
			#ifdef DCP_LIMIT_CUR
			limit_cur = DCP_LIMIT_CUR;
			#endif

			#ifdef DCP_CHG_CUR
			chg_cur = DCP_CHG_CUR;
			#endif
		}
	}

	#ifdef PRE_CHG_CUR
	pre_cur = PRE_CHG_CUR;
	sprd_chg_ic_op->chg_cmd(CHG_SET_PRE_CURRENT,pre_cur);
	#endif

	sprd_chg_ic_op->chg_cmd(CHG_SET_LIMIT_CURRENT,limit_cur);
	sprd_chg_ic_op->chg_cmd(CHG_SET_CURRENT,chg_cur);
	sprd_chg_ic_op->chg_start(0)

	debugf("chg_cur:%d,limit_cur:%d\n",chg_cur,limit_cur);
	sprdchg_timer_callback();

	debugf("vbat_vol:%d\n", vbat_vol);

	/* dead battery detect */
	if (dead_bat_flag) {
		printf("ERR!!!:Dead battery,disable charge!!!\n");
	} else {
		polling_cnt ++;

		if (vbat_vol > DEAD_DETECT_VOL) {
			debugf("polling_cnt:%d clear,DEAD_DETECT_VOL:%d\n",
			    polling_cnt,DEAD_DETECT_VOL);
			polling_cnt = 0;
		}

		if(polling_cnt > DEAD_DETECT_CNT) {
			printf("ERR!!!:Dead battery shutdown charge now!!!\n");
			dead_bat_flag = 1;
			sprd_chg_ic_op->chg_stop(1);
		}
	}
}

void sprdchg_register_ops(const struct sprdchg_ic_operations *ops)
{
	sprd_chg_ic_op = ops;
}

const struct sprdchg_ic_operations *sprdchg_ic_ops_get(void)
{
	return sprd_chg_ic_op;
}

int charger_connected(void)
{
	static int i = 0;

	sprd_eic_request(EIC_CHG_INT);
	udelay(3000);

	if (!(i++ % 100))
		debugf("eica status %x\n", sprd_eic_get(EIC_CHG_INT));

	return !!sprd_eic_get(EIC_CHG_INT);
}

int get_mode_from_gpio(void)
{
	int ret = 0;
	unsigned hw_rst_mode;

	hw_rst_mode = ANA_REG_GET(ANA_REG_GLB_POR_SRC_FLAG);
	ret = (hw_rst_mode & HW_PBINT2_STATUS) && !charger_connected();

	return ret;
}

void sprdbat_init(void)
{
	boot_mode_t boot_role;
	unsigned int keep_charge;
	chipram_env_t* cr_env = get_chipram_env();

	boot_role = cr_env->mode;
	keep_charge = cr_env->keep_charge;

	sprdbat_help_init();
	sprdfgu_init();
	if (!sprd_chg_ic_op) {
		printf("ERR!!!:chg op is NULL....\n");
		printf("ERR!!!:chg op is NULL....\n");
		printf("ERR!!!:chg op is NULL....\n");
		printf("ERR!!!:chg op is NULL....\n");
		printf("ERR!!!:chg op is NULL....\n");
		printf("ERR!!!:chg op is NULL....\n");
		printf("ERR!!!:chg op is NULL....\n");
		return;
	}

	sprd_chg_ic_op->ic_init();

	/* if it's BOOTLOADER_MODE_DONLOAD, donot check battery is connect or not, return. */
	if(boot_role == BOOTLOADER_MODE_DOWNLOAD){
		limit_cur = 500000;
		sprd_chg_ic_op->chg_cmd(CHG_SET_LIMIT_CURRENT,limit_cur);
		sprd_chg_ic_op->chg_stop(0);
		if(!keep_charge) {
			if (sprdfgu_read_vbat_vol() < ENABLE_CHARGE_DOWNLOAD_THRESHOLD)
				sprd_chg_ic_op->chg_start(0);
			else
				sprd_chg_ic_op->chg_stop(0);

		}
		return;
	}

	if (charger_connected()) {
		enum sprd_adapter_type charger;

		limit_cur = IBUS_CUR;
		chg_cur = IBAT_CUR;

		charger = sprdchg_charger_is_adapter();
		if (charger == ADP_TYPE_DCP) {
			#ifdef DCP_LIMIT_CUR
			limit_cur = DCP_LIMIT_CUR;
			#endif

			#ifdef DCP_CHG_CUR
			chg_cur = DCP_CHG_CUR;
			#endif
		}

		debugf("chg_cur:%d,limit_cur:%d\n",chg_cur,limit_cur);

		sprd_chg_ic_op->chg_cmd(CHG_SET_LIMIT_CURRENT,limit_cur);
		sprd_chg_ic_op->chg_cmd(CHG_SET_CURRENT,chg_cur);
		sprd_chg_ic_op->chg_start(0);
	}

	//if battery do NOT connect, shutdown charge,maybe system poweroff
	if (!sprdbat_is_battery_connected()) {
		printf("battery unconnected shutdown charge!!!!!\n");
		sprd_chg_ic_op->chg_stop(0);
	}

	sprdfgu_late_init();
}

static int sprdbat_write_miscdata_data(char *in, unsigned int address, unsigned int len)
{
	if (0 != common_raw_write("miscdata", len, (uint64_t)0,
				  (uint64_t)(MISCDATA_ADDRESS_BASE + address), in)) {
		printf("Fail to set address[%d] to %s\n", address, in);
		return -1;
	}

	return 0;
}

static int sprdbat_read_miscdata_data(char *out, unsigned int address, unsigned int len)
{
	if (0 != common_raw_read("miscdata", len,
				 (uint64_t)(MISCDATA_ADDRESS_BASE + address), out)) {
		printf("sprdbat Fail to read address[%d]\n", address);
		return -1;
	}

	return 0;
}

static void sprdbat_reset_miscdata_parameters(char *out, unsigned int address, unsigned int len)
{
	int ret;

	if (address != 0 && len != 0) {
		ret = sprdbat_write_miscdata_data(out, address, len);
		if (ret)
			printf("sprdbat fail to reset address = %d, len = %d\n", address, len);
	}
}

static void sprdbat_reset_shutdown_rtc_time()
{
	s64 rtc_time = -1;
	rtc_time = sprd_rtc_get_sec();
	printf("sprdbat reset rtc time = %lld\n", rtc_time);
	sprdbat_reset_miscdata_parameters((char *)(&rtc_time),
					  MISCDATA_RTC_TIME_OFFSET,
					  MISCDATA_RTC_TIME_SIZE);
}

static void sprdbat_reset_shutdown_charge_flag(void)
{
	u32 charging_flag = 0;

	/* reset charging flag to zero */
	sprdbat_reset_miscdata_parameters((char *)(&charging_flag),
					  MISCDATA_SHUTDOWN_CHARGE_FLAG_OFFSET,
					  MISCDATA_SHUTDOWN_CHARGE_FLAG_SIZE);
}

static void sprdbat_reset_miscdata(void)
{
	int magic_num = SPRD_BATTERY_MAGIC_NUM;
	int charge_cycle = -1;
	int basp = -1;
	int total_mah = -1;
	int check_mah = -1;
	int ret;

	/* reset magic number to 0x5a5aa5a5 */
	if (MISCDATA_MAGIC_OFFSET == 0 && MISCDATA_MAGIC_SIZE != 0) {
		ret = sprdbat_write_miscdata_data((char *)(&magic_num),
						  MISCDATA_MAGIC_OFFSET,
						  MISCDATA_MAGIC_SIZE);
		if (ret != 0)
			printf("sprdbat Fail to reset charge magic num\n");
	}

	/* reset rtc to current time */
	sprdbat_reset_shutdown_rtc_time();

	/* reset charge cycle to zero */
	sprdbat_reset_miscdata_parameters((char *)(&charge_cycle),
					  MISCDATA_CHARGE_CYCLE_OFFSET,
					  MISCDATA_CHARGE_CYCLE_SIZE);

	/* reset basp to zero */
	sprdbat_reset_miscdata_parameters((char *)(&basp),
					  MISCDATA_BASP_OFFSET,
					  MISCDATA_BASP_SIZE);

	/* reset total_mah to zero */
	sprdbat_reset_miscdata_parameters((char *)(&total_mah),
					  MISCDATA_CAPACITY_OFFSET,
					  MISCDATA_CAPACITY_SIZE);

	/* reset check_mah to zero */
	sprdbat_reset_miscdata_parameters((char *)(&check_mah),
					  MISCDATA_CAPACITY_CHECK_OFFSET,
					  MISCDATA_CAPACITY_CHECK_SIZE);

	/* reset charging flag to zero */
	sprdbat_reset_shutdown_charge_flag();
}

static void sprdbat_format_cmdline(u8 *fdt, char *buf)
{
	int ret;

	ret = fdt_chosen_bootargs_append(fdt, buf, 1);
	if (ret < 0)
		printf("sprdbat Fail to append shutdown_rtc_time to bootargs\n");
}

int sprdbat_get_shutdown_charge_flag(void)
{
	int flag = 1;

	if ((!MISCDATA_ADDRESS_BASE) || (!MISCDATA_SHUTDOWN_CHARGE_FLAG_OFFSET) ||
	    (!MISCDATA_SHUTDOWN_CHARGE_FLAG_SIZE)) {
		printf("the function is not defined and enters the shutdown charging mode!\n");
		return flag;
	}
	sprdbat_read_miscdata_data((char *)(&flag),
				   MISCDATA_SHUTDOWN_CHARGE_FLAG_OFFSET,
				   MISCDATA_SHUTDOWN_CHARGE_FLAG_SIZE);
	sprdbat_reset_shutdown_charge_flag();

	return flag;
}

int fdt_fixup_charger_parameters(u8 *fdt)
{
	char buf[256] = {0};
	int charge_cycle = -1;
	s64 rtc_time = -1;
	int magic_num = -1;
	int basp = -1;
	int total_mah = -1;
	int check_mah = -1;
	int ret;

	if (MISCDATA_ADDRESS_BASE == 0)
		return 0;

	memset(buf, '\0', sizeof(buf));

	if (charge_first_powr_on) {
		rtc_time = -1;
		charge_cycle = -1;
		basp = -1;
		total_mah = -1;
		printf("sprdbat first power on, reset miscdata\n");
		sprdbat_reset_miscdata();
		goto format_cmdline;
	}

	if (MISCDATA_MAGIC_OFFSET == 0 && MISCDATA_MAGIC_SIZE != 0) {
		ret = sprdbat_read_miscdata_data((char *)(&magic_num),
						 MISCDATA_MAGIC_OFFSET,
						 MISCDATA_MAGIC_SIZE);
		if (ret != 0 || magic_num != SPRD_BATTERY_MAGIC_NUM) {
			printf("sprdbat Fail to read charge magic num = %d\n", magic_num);
			magic_num = -1;
		}
	}

	if (magic_num == -1) {
		rtc_time = -1;
		charge_cycle = -1;
		basp = -1;
		total_mah = -1;
		goto format_cmdline;
	}

	/* Read shutdown rtc time */
	if (MISCDATA_RTC_TIME_OFFSET != 0 && MISCDATA_RTC_TIME_SIZE != 0) {
		ret = sprdbat_read_miscdata_data((char *)(&rtc_time),
						 MISCDATA_RTC_TIME_OFFSET,
						 MISCDATA_RTC_TIME_SIZE);
		if (ret) {
			printf("sprdbat Fail to read rtc time\n");
			rtc_time = -1;
		}
	}

	/* Read charge cycle */
	if (MISCDATA_CHARGE_CYCLE_OFFSET != 0 && MISCDATA_CHARGE_CYCLE_SIZE != 0) {
		ret = sprdbat_read_miscdata_data((char *)(&charge_cycle),
						 MISCDATA_CHARGE_CYCLE_OFFSET,
						 MISCDATA_CHARGE_CYCLE_SIZE);
		if (ret) {
			printf("sprdbat Fail to read charge_cycle\n");
			charge_cycle = -1;
		}
	}

	/* Read BASP */
	if (MISCDATA_BASP_OFFSET != 0 && MISCDATA_BASP_SIZE != 0) {
		ret = sprdbat_read_miscdata_data((char *)(&basp),
						 MISCDATA_BASP_OFFSET,
						 MISCDATA_BASP_SIZE);
		if (ret) {
			printf("sprdbat Fail to read basp\n");
			basp = -1;
		}
	}

	/* Read Total mah */
	if (MISCDATA_CAPACITY_OFFSET != 0 && MISCDATA_CAPACITY_SIZE != 0) {
		ret = sprdbat_read_miscdata_data((char *)(&total_mah),
						 MISCDATA_CAPACITY_OFFSET,
						 MISCDATA_CAPACITY_SIZE);
		if (ret) {
			printf("sprdbat Fail to read total_mah\n");
			total_mah = -1;
		}
	}

	/* Read Check mah */
	if (MISCDATA_CAPACITY_CHECK_OFFSET != 0 && MISCDATA_CAPACITY_CHECK_SIZE != 0) {
		ret = sprdbat_read_miscdata_data((char *)(&check_mah),
						 MISCDATA_CAPACITY_CHECK_OFFSET,
						 MISCDATA_CAPACITY_CHECK_SIZE);
		if (ret) {
			printf("sprdbat Fail to read check_mah\n");
			check_mah = -1;
		}
	}

format_cmdline:
	printf("sprdbat rtc_time = %lld, charge_cycle = %d, charge magic num = 0x%x, "
	       "basp = %d, total_mah = %d\n",
	       rtc_time, charge_cycle, magic_num, basp, total_mah);

	if ((total_mah ^ CAPACITY_TRACK_CAP_KEY0) != (check_mah ^ CAPACITY_TRACK_CAP_KEY1)) {
		printf("sprdbat total_mah != check_mah, total_mah = %d, check_mah = %d\n",
		       total_mah ^ CAPACITY_TRACK_CAP_KEY0, check_mah ^ CAPACITY_TRACK_CAP_KEY1);
			total_mah = -1;
	}

	/* Parse shutdown rtc time to kernel */
	sprintf(buf, "charge.shutdown_rtc_time=%lld ", rtc_time);
	sprdbat_format_cmdline(fdt, buf);

	/* Parse shutdown charge cycle to kernel */
	memset(buf, '\0', sizeof(buf));
	sprintf(buf, "charge.charge_cycle=%d ", charge_cycle);
	sprdbat_format_cmdline(fdt, buf);

	/* Parse basp to kernel */
	memset(buf, '\0', sizeof(buf));
	sprintf(buf, "charge.basp=%d ", basp);
	sprdbat_format_cmdline(fdt, buf);

	/* Parse capacity to kernel */
	memset(buf, '\0', sizeof(buf));
	sprintf(buf, "charge.total_mah=%d ", total_mah);
	sprdbat_format_cmdline(fdt, buf);

	/* reset rtc to current time */
	sprdbat_reset_shutdown_rtc_time();

	return 0;
}

int fdt_fixup_battery_id_parameters(u8 *fdt)
{
	char buf[256] = {0};
	int batid;

	if (!BAT_ID)
		return 0;

	/* Parse bat id to kernel */
	memset(buf, '\0', sizeof(buf));
	batid = sprd_get_bat_id();
	sprintf(buf, "bat.id=%d ", batid);
	sprdbat_format_cmdline(fdt, buf);

	return 0;
}
