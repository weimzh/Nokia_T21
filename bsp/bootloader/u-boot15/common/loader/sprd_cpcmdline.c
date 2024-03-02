#include "sprd_cpcmdline.h"
#include "loader_common.h"
#include "../../board/spreadtrum/ums9230_1h10/board_id.h"

//20220518, Added by zhu_jun for rf boardid begin
int rfboardid;
int rfgpioval;
//20220518, Added by zhu_jun for rf boardid end
char *g_CPcmdlineBuf = NULL;
#if defined( CONFIG_KERNEL_BOOT_CP )
char CPcmdlineBuf[MAX_CP_CMDLINE_LEN];
#endif
//20220525,Added by zhu_jun for serial number related properties begin
int hardware_level;
//20220525,Added by zhu_jun for serial number related properties end

#ifdef CONFIG_ANDROIDBOOT_HARDWARE
#define WIFIMODE 1
#define DATAMODE 1
#define SINGLESIM 1
#endif

static const char *cmd_arr[] = {
	BOOT_MODE,
	CALIBRATION_MODE,
	LTE_MODE,
	AP_VERSION,
	RF_BOARD_ID,
	RF_HW_INFO,
	K32_LESS,
	AUTO_TEST,
	CRYSTAL_TYPE,
	RF_HW_ID,
#ifdef CONFIG_SC9833
	RF_CHIP_ID,
#endif
#ifdef CONFIG_PMIC_CHIP_ID
	PMIC_CHIP_ID,
#endif
	CHIPUID,
	MODEM_BOOT_METHOD,
	WCN_CLK_ID,
	PCB_VERSION,
	CPCMDLINE,
	WIFI_MODE,
	BOARD_TYPE,
	ANDROIDBOOT_HARDWARE,
	DATA_MODE,
	SIM_MODE,
#ifdef CONFIG_GET_HW_VERSION
	HW_VERSION,
#endif
    //20220512, Added by zhu_jun for boardid start
	WT_BOARD_ID,
	WT_SIM_MODE,
	//20220512, Added by zhu_jun for boardid end
	//20220521, Added by zhu_jun for hardware id start
	WT_HARDWARE_ID,
	//20220521, Added by zhu_jun for hardware id end
	NULL
};


static bool is_invalid_cmd(const char *cmd)
{
	int i = 0;
	while(NULL != cmd_arr[i])
	{
		if(0 == strcmp(cmd_arr[i], cmd)){
			return true;
		}
		i++;
	}
	return false;
}

static char *cpcmdline_get_lte_mode(void)
{
	char *ltemode = NULL;

#ifdef CONFIG_SUPPORT_TDLTE
	ltemode = "tcsfb";
#elif defined CONFIG_SUPPORT_WLTE
	ltemode = "fcsfb";
#elif defined CONFIG_SUPPORT_LTE
	ltemode = "lcsfb";
#endif

	return ltemode;
}

static char *cpcmdline_get_modem_boot_method(void)
{
#ifdef CONFIG_DDR_BOOT
	return "ddrboot";
#elif defined CONFIG_EMMC_BOOT
	return "emmcboot";
#elif defined CONFIG_NAND_BOOT
	return "nandboot";
#endif
	return NULL;
}


static void cmdline_prepare(void)
{
#if defined( CONFIG_KERNEL_BOOT_CP )
	g_CPcmdlineBuf = CPcmdlineBuf;
#else
#ifdef CONFIG_MEM_LAYOUT_DECOUPLING
extern void *parse_cpcmdline_addr();
	g_CPcmdlineBuf = (char*)parse_cpcmdline_addr();
#else
#ifdef CALIBRATION_FLAG_CP0
	g_CPcmdlineBuf = (char*)CALIBRATION_FLAG_CP0;
#endif
#ifdef CALIBRATION_FLAG_CP1
	g_CPcmdlineBuf = (char*)CALIBRATION_FLAG_CP1;
#endif
#endif
#endif
	if (g_CPcmdlineBuf)
		memset(g_CPcmdlineBuf, 0, MAX_CP_CMDLINE_LEN);
	debugf("g_CPcmdlineBuf = 0x%p\n" , g_CPcmdlineBuf);
}

static void cmdline_add_cp_cmdline(char *cmd, char* value)
{
	char *p;
	int len;
	//printf("add cmd, cmd = %s, value = %s\n", cmd, value);

	if(!is_invalid_cmd(cmd))return;

	if (NULL == g_CPcmdlineBuf)
		return;

	len = strlen(g_CPcmdlineBuf);
	p = g_CPcmdlineBuf + len;

	snprintf(p, MAX_CP_CMDLINE_LEN - len, "%s=%s ", cmd, value);
	//printf("cmd = %s\n" , p);
}

void cp_cmdline_fixup(void)
{
	char *value = NULL;
	int boardid = 0;
	unsigned int pmicid = 0;
	int value_less = 0;
	char buf[30] = {0};
	unsigned char v32kless;
	int value_wifimode = 0;
	int value_datamode = 0;
	char value_simmode = 0;
	int value_wifi_gpio = 0;
	//20220521, Added by zhu_jun for hardware id start
	int level = 0;
	//20220521, Added by zhu_jun for hardware id end
	cmdline_prepare();

	// androd boot mode
	value = getenv("bootmode");
	if (NULL != value)
	{
		cmdline_add_cp_cmdline(BOOT_MODE, value);
	}

	// calibration parameters
	value = get_calibration_parameter();
	if (NULL != value)
	{
		if (NULL != strstr(value, CALIBRATION_MODE))
		{
			// "calibration=%d,%d,146 ", must skipp calibration=
			value += strlen(CALIBRATION_MODE) + 1;
			cmdline_add_cp_cmdline(CALIBRATION_MODE, value);
		} else if (NULL != strstr(value, AUTO_TEST)) {
			// "autotest=1", must skipp autotest=
			value += strlen(AUTO_TEST) + 1;
			cmdline_add_cp_cmdline(AUTO_TEST, value);
		}
	}

	// lte mode
	value = cpcmdline_get_lte_mode();
	if(NULL != value)
	{
		cmdline_add_cp_cmdline(LTE_MODE, value);
	}

	//chip uid
#ifdef CONFIG_READ_UID
	{
		unsigned int block0;
		unsigned int block1;
		get_efuse_uid_ex(&block0,&block1);
		sprintf(buf,"0x%08x,0x%08x",block0,block1);
		cmdline_add_cp_cmdline(CHIPUID,buf);
	}
#endif
/* crystal and rf band auto adaption used on some platforms, such as sharkl, pike series */
/* Using RF band adaption in each board configuration and print information in cpcmdline*/
#if (defined(CONFIG_BOARD_ID) || defined(CONFIG_BAND_DETECT))
	//rf band auto adaption
	boardid = sprd_get_bandinfo();
	rfboardid = boardid;
	rfgpioval = board_id_arr[rfboardid].rf_boardid;
	
    switch (boardid) {
    	case BOARD_TYPE_ROW:
	case BOARD_TYPE_ROW_INDIA:
	    sprintf(buf,"%s", BOARD_TYPE_ROW_NAME);
	    break;
    case BOARD_TYPE_LATAM:
		sprintf(buf,"%s", BOARD_TYPE_LATAM_NAME);
	    break;
    case BOARD_TYPE_WIFIONLY:
    case BOARD_TYPE_WIFIONLY_INDIA:
		sprintf(buf,"%s", BOARD_TYPE_WIFIONLY_NAME);
	    break;
    case BOARD_TYPE_ROW_NFC:
    case BOARD_TYPE_ROW_NFC_INDIA:
		sprintf(buf,"%s", BOARD_TYPE_ROW_NFC_NAME);
	    break;
    default:
		sprintf(buf,"%s", "unknow");
        break;
    }
    	cmdline_add_cp_cmdline(BOARD_TYPE, buf);

	// sku1 row and sku4 row nfc CA are same, so rfboard.id=1 are same.
	if(boardid == BOARD_TYPE_ROW_NFC ||boardid == BOARD_TYPE_ROW_INDIA ||boardid == BOARD_TYPE_ROW_NFC_INDIA) 
		boardid = BOARD_TYPE_ROW;
	// sku3 row and sku4 row nfc CA are same, so rfboard.id=1 are same.
	if(boardid == BOARD_TYPE_WIFIONLY_INDIA) 
		boardid = BOARD_TYPE_WIFIONLY;
	sprintf(buf,"%d",boardid);
	cmdline_add_cp_cmdline(RF_BOARD_ID, buf);
	
#ifdef CONFIG_GET_HW_VERSION
	sprintf(buf,"%d", get_hw_version());
	cmdline_add_cp_cmdline(HW_VERSION, buf);
#endif
#endif
/* Printing the clock and crystal type in cpcmdline by clk & crystal adaption */
#if (defined(CONFIG_BOARD_ID) || defined(CONFIG_ADIE_SC2730))
	//board id
	value_less=sprd_get_boardid();
	sprintf(buf,"%d",value_less);
	cmdline_add_cp_cmdline(RF_HW_ID, buf);

	//26m crystal auto adaption
	sprintf(buf,"%d", sprd_get_crystal());
	cmdline_add_cp_cmdline(CRYSTAL_TYPE, buf);
#endif
	//32k crystal auto adaption
	sprintf(buf,"%d", sprd_get_32k());
	cmdline_add_cp_cmdline(K32_LESS, buf);
#ifdef CONFIG_WCN_DETECT
	//wcn crystal auto adaption
	sprintf(buf,"%d", sprd_get_wcn_crystal());
	cmdline_add_cp_cmdline(WCN_CLK_ID,buf);
#endif
#ifdef CONFIG_PCB_VERSION
	sprintf(buf,"%d",sprd_get_pcbversion());
	cmdline_add_cp_cmdline(PCB_VERSION, buf);
#endif
#ifdef CONFIG_ANDROIDBOOT_HARDWARE
	//value_wifi_gpio = sprd_get_wifi_mode();
	
	if(BOARD_TYPE_WIFIONLY == sprd_get_bandinfo() || BOARD_TYPE_WIFIONLY_INDIA== sprd_get_bandinfo()){
		value_wifi_gpio = 1;
		sprintf(buf,"%d", value_wifi_gpio);
		cmdline_add_cp_cmdline(WIFI_MODE, buf);
		sprintf(buf,"%s","wifionly");
                cmdline_add_cp_cmdline(ANDROIDBOOT_HARDWARE, buf);
	} else {
		value_wifi_gpio = 0;
        }
	#if 0
	value_datamode = sprd_get_data_mode();
	sprintf(buf,"%d", value_datamode);
	cmdline_add_cp_cmdline(DATA_MODE, buf);
	value_simmode = sprd_get_sim();

	if (value_wifi_gpio == WIFIMODE) {
		if (value_datamode == DATAMODE || value_simmode == SINGLESIM) {
			debugf("error config: value_wifi_gpio = %d, value_datamode = %d, value_simmode = %d \n",
			value_wifi_gpio, value_datamode, value_simmode);
		}
		else {
			sprintf(buf,"%s","wifionly");
			cmdline_add_cp_cmdline(ANDROIDBOOT_HARDWARE, buf);
		}
	}
	else if (value_datamode == DATAMODE || value_simmode == SINGLESIM) {
		if (value_datamode == DATAMODE && value_simmode == SINGLESIM)
			sprintf(buf,"%s","dataonly_singlesim");
		else
			sprintf(buf,"%s",(value_simmode?"singlesim":"dataonly"));
		cmdline_add_cp_cmdline(ANDROIDBOOT_HARDWARE, buf);
	}
	#endif
#endif
#ifdef CONFIG_SC9833
	{
		extern u8 DRV_RF_Get_Type(void);

		u8 type = DRV_RF_Get_Type();
		sprintf(buf, "%d", type);
		cmdline_add_cp_cmdline(RF_CHIP_ID, buf);
	}
#endif

#ifdef CONFIG_PMIC_CHIP_ID
	/* get pmic chipid */
	extern int sprd_get_pmic_chipid(void);
	pmicid = sprd_get_pmic_chipid();
	sprintf(buf,"%x",pmicid);
	cmdline_add_cp_cmdline(PMIC_CHIP_ID, buf);
#endif

	// modem boot method
	value = cpcmdline_get_modem_boot_method();
	if(NULL != value)
	{
		cmdline_add_cp_cmdline(MODEM_BOOT_METHOD, value);
	}

	//20220512, Added by zhu_jun for boardid start
	//boardid = target_get_boardid();
	//cmdline_add_cp_cmdline(WT_BOARD_ID, board_id_arr[boardid].board_name);
	//cmdline_add_cp_cmdline(WT_SIM_MODE, board_id_arr[boardid].dual_or_single_sim);
	//20220512, Added by zhu_jun for boardid end
	//20220521, Added by zhu_jun for hardware id start
	level = sprd_get_hardwareid_info();
	//20220525,Added by zhu_jun for serial number related properties begin
	hardware_level = level;
	//20220525,Added by zhu_jun for serial number related properties end
	cmdline_add_cp_cmdline(WT_HARDWARE_ID, hardware_id_arr[level].hardwareid_name);
	//20220521, Added by zhu_jun for hardware id end
        cmdline_add_cp_cmdline(CPCMDLINE,"end");
	debugf("cp cmdline: %s\n", g_CPcmdlineBuf);
}

char *cp_getcmdline(void)
{
	return g_CPcmdlineBuf;
}

//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
void get_status_simslot(char *outBuf, unsigned int *outBufLen)
{
	int boardid = 0;

	boardid = target_get_boardid();

	if (!strcmp(board_id_arr[boardid].dual_or_single_sim,"singlesim")) {
		snprintf(outBuf, sizeof("single"), "single");
		*outBufLen = sizeof("single");
	}
	else if (!strcmp(board_id_arr[boardid].dual_or_single_sim,"dualsim")) {
		snprintf(outBuf, sizeof("dual"), "dual");
		*outBufLen = sizeof("dual");
	}
	else{
		memset(outBuf, 0x0, strlen(outBuf));

	}
}
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end
