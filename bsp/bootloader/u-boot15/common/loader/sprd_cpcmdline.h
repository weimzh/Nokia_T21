#ifndef _MODEM_COMMON_H_
#define _MODEM_COMMON_H_

#include <config.h>
#include <common.h>
#include <linux/string.h>

//20220521, Added by zhu_jun for hardware id start
#define MAX_CP_CMDLINE_LEN  (300)
//20220521, Added by zhu_jun for hardware id end

/*cp cmd define */

#define BOOT_MODE        "androidboot.mode"
#define CALIBRATION_MODE "calibration"
#define LTE_MODE         "ltemode"
#define AP_VERSION       "apv"
#define RF_BOARD_ID      "rfboard.id"
#define RF_HW_INFO       "hardware.version"
#define K32_LESS         "32k.less"
#define AUTO_TEST        "autotest"
#define CRYSTAL_TYPE    "crystal"
#define RF_HW_ID       "rfhw.id"
#define MODEM_BOOT_METHOD         "modemboot.method"
#define WCN_CLK_ID      "marlin.clktype"
#define CPCMDLINE       "cpcmdline"
#define PCB_VERSION	"pcb.version"
#define WIFI_MODE	"wifionly"
#define ANDROIDBOOT_HARDWARE		"androidboot.product.hardware.sku"
#define DATA_MODE	"dataonly"
#define SIM_MODE    "androidboot.product.hardware.sku"
#ifdef CONFIG_GET_HW_VERSION
#define HW_VERSION		"hw.version"
#endif
//20220512, Added by zhu_jun for boardid start
#define WT_BOARD_ID   "androidboot.board_id"
#define WT_SIM_MODE  "androidboot.product.hardware.sku"
//20220512, Added by zhu_jun for boardid end
//20220521, Added by zhu_jun for hardware id start
#define WT_HARDWARE_ID  "androidboot.hardware_id"
//20220521, Added by zhu_jun for hardware id end
#ifdef CONFIG_PMIC_CHIP_ID
#define PMIC_CHIP_ID        "androidboot.pmic.chipid"
#endif

#define CHIPUID          "chip.uid"
#define INVALID_BOARD_ID 0xFF

#ifdef CONFIG_SC9833
#define RF_CHIP_ID       "rf.type"
#endif

#define BOARD_TYPE	"androidboot.board_type"

#define BOARD_TYPE_ROW      1
#define BOARD_TYPE_LATAM    0
#define BOARD_TYPE_WIFIONLY 2
#define BOARD_TYPE_ROW_NFC 3

#define BOARD_TYPE_ROW_INDIA      4
#define BOARD_TYPE_WIFIONLY_INDIA  5
#define BOARD_TYPE_ROW_NFC_INDIA  6

#define BOARD_TYPE_ROW_NAME      "row"
#define BOARD_TYPE_LATAM_NAME    "latam"
#define BOARD_TYPE_WIFIONLY_NAME "wifi_only"
#define BOARD_TYPE_ROW_NFC_NAME "row_nfc"

void cp_cmdline_fixup(void);
char *cp_getcmdline(void);
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
void get_status_simslot(char *outBuf, unsigned int *outBufLen);
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end

#endif // _MODEM_COMMON_H_

