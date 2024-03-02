//Added by wt.yanrenjie for SCT-702,wt hardware info begin

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/hardware_info.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/of.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>

char Lcm_name[HARDWARE_MAX_ITEM_LONGTH];
//Modify by fangzhihua@wingtech.com for SCT-702,add for check panel for second TP FW on 2021-11-12 begin
#ifdef WT_COMPILE_FACTORY_VERSION
EXPORT_SYMBOL_GPL(Lcm_name);
#endif
//Modify by fangzhihua@wingtech.com for SCT-702,add for check panel for second TP FW on 2021-11-12 end
char Tp_info[HARDWARE_MAX_ITEM_LONGTH];
#ifdef WT_COMPILE_FACTORY_VERSION
EXPORT_SYMBOL_GPL(Tp_info);
#endif

char Sar_name[HARDWARE_MAX_ITEM_LONGTH];
char board_type[HARDWARE_MAX_ITEM_LONGTH];
char hardware_id[HARDWARE_MAX_ITEM_LONGTH];
//char bat_id[HARDWARE_MAX_ITEM_LONGTH];
static char hardwareinfo_name[HARDWARE_MAX_ITEM][HARDWARE_MAX_ITEM_LONGTH];

//static unsigned int board_id1;
//static unsigned int board_id2;
//static unsigned int board_id3;

char* hardwareinfo_items[HARDWARE_MAX_ITEM] =
{
	"LCD",
	"TP",
	"MEMORY",
	"FLASH",
	"CAM_FRONT",
	"CAM_BACK",
	"BT",
	"WIFI",
	"GSENSOR",
	"PLSENSOR",
	"GYROSENSOR",
	"SAR",
	"GPS",
	"FM",
	"NFC",
	"BATTERY",
	"CHARGER_IC_INFO",
	"BMS_GAUGE",
	"PA",
	"BOARD_ID",
	"HARDWARE_ID"
};

int hardwareinfo_set_prop(int cmd, const char *name)
{
	if(cmd < 0 || cmd >= HARDWARE_MAX_ITEM)
		return -1;

	strcpy(hardwareinfo_name[cmd], name);

	return 0;
}

int __weak tid_hardware_info_get(char *buf, int size)
{
	snprintf(buf, size, "touch info interface is not ready\n");

	return 0;
}
#ifdef WT_COMPILE_FACTORY_VERSION
EXPORT_SYMBOL_GPL(hardwareinfo_set_prop);
#endif

static char* boardid_get(void)
{
	char* s1= "androidboot.board_id=";
	char* s2="not found";
	struct device_node *cmdline_node = NULL;
	const char *cmdline;
	char *match, *match_end;
	int len, match_str_len, ret;
	//int board_id1_value = 0;
	//int board_id2_value = 0;
	//int board_id3_value = 0;
	memset(board_type, '\0', sizeof(board_type));
	match_str_len = strlen(s1);

	cmdline_node = of_find_node_by_path("/chosen");
	if (!cmdline_node) {
		printk("%s:line%d: NULL pointer!!!\n", __func__, __LINE__);
		return s2;
	}

	ret = of_property_read_string(cmdline_node, "bootargs", &cmdline);
	if (ret) {
		printk("%s failed to read bootargs\n", __func__);
		return s2;
	}

	match = strstr(cmdline, s1);
	if (!match) {
		printk("Mmatch: %s fail in cmdline\n", s1);
		return s2;
	}

	match_end = strstr((match + match_str_len), " ");
	if (!match_end) {
		printk("Match end of : %s fail in cmdline\n", s1);
		return s2;
	}

	len = match_end - (match + match_str_len);
	if (len < 0 || len > sizeof(board_type)) {
		printk("Match cmdline :%s fail, len = %d\n", s1, len);
		return s2;
	}

	memcpy(board_type, (match + match_str_len), len);
	s1 = board_type;

	hardwareinfo_set_prop(HARDWARE_BOARD_ID, board_type);

#if 0
	board_id1_value = __gpio_get_value(board_id1); //32GB
	board_id2_value = __gpio_get_value(board_id2); //64GB
	board_id3_value = __gpio_get_value(board_id3); //128GB
	pr_info("board id value: %d, %d, %d\n", board_id1_value, board_id2_value, board_id3_value);

	if(strcmp(board_type, "row") == 0) {
		if(board_id2_value)
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616CA1");
		else
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616CA1");
		if(board_id3_value)
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616DA1");
		else
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616CA1");
	} else if(strcmp(board_type, "latam") == 0) {
		if(board_id2_value)
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616EA1");
		else
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616EA1");
		if(board_id3_value)
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616FA1");
		else
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616EA1");
	} else if(strcmp(board_type, "wifi_only") == 0) {
		if(board_id1_value)
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616GA1");
		else
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616HA1");
		if(board_id2_value)
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616HA1");
		else
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616HA1");
		if(board_id3_value)
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616IA1");
		else
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616HA1");
	} else if(strcmp(board_type, "row_nfc") == 0) {
		if(board_id2_value)
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616AA1");
		else
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616AA1");
		if(board_id2_value)
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616BA1");
		else
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616AA1");
	} else {
		hardwareinfo_set_prop(HARDWARE_BOARD_ID, "P19616XXX");	
	}
#endif

	return s1;
}
#if 0
static char* batid_get(void)
{
	char* s1= "";
	char* s2="not found";
	char *ptr =NULL;

	s1 = strstr(saved_command_line, "bat.id=");
	if(!s1) {
		printk("bat.id not found in cmdline\n");
		return s2;
	}
	s1 += strlen("bat.id=");
	ptr=s1;
	while(*ptr != ' ' && *ptr != '\0') {
		ptr++;
	}
	strncpy(bat_id, (const char *)s1,ptr-s1);
	bat_id[ptr-s1]='\0';
	s1 = bat_id;

	return s1;
}
#endif

static char* hwid_get(void)
{
	char* s1= "";
	char* s2="not found";
	char *ptr =NULL;

	s1 = strstr(saved_command_line, "hardware_id=");
	if(!s1) {
		printk("hardware_id not found in cmdline\n");
		return s2;
	}
	s1 += strlen("hardware_id=");
	ptr=s1;
	while(*ptr != ' ' && *ptr != '\0') {
		ptr++;
	}
	strncpy(hardware_id, (const char *)s1,ptr-s1);
	hardware_id[ptr-s1]='\0';
	printk("hardware_id found in cmdline : %s\n", hardware_id);
	/*if (strncmp(hardware_id, "EVT", strlen("hardware_id")) == 0)
	{
		strcpy(hardware_id, "REV0.1");
	}
	else if (strncmp(hardware_id, "EVT2", strlen("hardware_id")) == 0)
	{
		strcpy(hardware_id, "REV0.2");
	}
	else if (strncmp(hardware_id, "DVT", strlen("hardware_id")) == 0)
	{
		strcpy(hardware_id, "REV0.3");
	}
	else if (strncmp(hardware_id, "PVT", strlen("hardware_id")) == 0)
	{
		strcpy(hardware_id, "REV0.4");
	}
	else if (strncmp(hardware_id, "MP", strlen("hardware_id")) == 0)
	{
		strcpy(hardware_id, "MP1.0");
	}
	else
	{
		return s2;
	}*/
	s1 = hardware_id;

	return s1;
}

int mmi_tp_version = 0;
#ifdef WT_COMPILE_FACTORY_VERSION
EXPORT_SYMBOL_GPL(mmi_tp_version);
#endif
static char tp_version[20];

static long hardwareinfo_ioctl(struct file *file, unsigned int cmd,unsigned long arg)
{
	int ret = 0, hardwareinfo_num = HARDWARE_MAX_ITEM;
	void __user *data = (void __user *)arg;
	//char info[HARDWARE_MAX_ITEM_LONGTH];

	switch (cmd) {
	case HARDWARE_LCD_GET:
		hardwareinfo_set_prop(HARDWARE_LCD, "TA4RUS07VOFMZTB");
		hardwareinfo_num = HARDWARE_LCD;
		break;
	case HARDWARE_TP_GET:
		sprintf(tp_version,"HX83102_0x%x\n",mmi_tp_version);
		//printk("sqw tp_version=%s\n",tp_version);
		hardwareinfo_set_prop(HARDWARE_TP, tp_version);
		hardwareinfo_num = HARDWARE_TP;
		//strcpy(hardwareinfo_name[HARDWARE_TP],Tp_info);
		//tid_hardware_info_get(hardwareinfo_name[hardwareinfo_num],
		//ARRAY_SIZE(hardwareinfo_name[0]));
		break;
	case HARDWARE_FLASH_GET:
		hardwareinfo_set_prop(HARDWARE_FLASH, "OCP8110");
		hardwareinfo_num = HARDWARE_FLASH;
		break;
	case HARDWARE_FRONT_CAM_GET:
		hardwareinfo_set_prop(HARDWARE_FRONT_CAM, "HI846");
		hardwareinfo_num = HARDWARE_FRONT_CAM;
		break;
	case HARDWARE_BACK_CAM_GET:
		hardwareinfo_set_prop(HARDWARE_BACK_CAM, "HI846");
		hardwareinfo_num = HARDWARE_BACK_CAM;
		break;
	case HARDWARE_BT_GET:
		hardwareinfo_set_prop(HARDWARE_BT, "UMW2631");
		hardwareinfo_num = HARDWARE_BT;
		break;
	case HARDWARE_WIFI_GET:
		hardwareinfo_set_prop(HARDWARE_WIFI, "UMW2631");
		hardwareinfo_num = HARDWARE_WIFI;
		break;
	case HARDWARE_ACCELEROMETER_GET:
		hardwareinfo_set_prop(HARDWARE_ACCELEROMETER, "MXC6655");
		hardwareinfo_num = HARDWARE_ACCELEROMETER;
		break;
	case HARDWARE_ALSPS_GET:
		hardwareinfo_set_prop(HARDWARE_ALSPS, "STK3329-35B");
		hardwareinfo_num = HARDWARE_ALSPS;
		break;
	case HARDWARE_GYROSCOPE_GET:
		hardwareinfo_num = HARDWARE_GYROSCOPE;
		break;
	case HARDWARE_SAR_GET:
		//hardwareinfo_set_prop(HARDWARE_SAR, Sar_name);
		hardwareinfo_num = HARDWARE_SAR;
		break;
	case HARDWARE_GPS_GET:
		hardwareinfo_set_prop(HARDWARE_GPS, "UMW2631");
	    hardwareinfo_num = HARDWARE_GPS;
		break;
	case HARDWARE_FM_GET:
		hardwareinfo_set_prop(HARDWARE_FM, "UMW2631");
	    hardwareinfo_num = HARDWARE_FM;
		break;
	case HARDWARE_NFC_GET:
		/* Modify by hz for hardward infomation on 20220718 begin */
		//hardwareinfo_set_prop(HARDWARE_NFC, "ST45J");
		hardwareinfo_num = HARDWARE_NFC;
		/* Modify by hz for hardward infomation on 20220718 end */
		break;
	case HARDWARE_BATTERY_ID_GET:
		//batid_get();
		hardwareinfo_set_prop(HARDWARE_BATTERY_ID, "FHPV2890101P");
		hardwareinfo_num = HARDWARE_BATTERY_ID;
		break;
	case HARDWARE_CHARGER_IC_INFO_GET:
		hardwareinfo_set_prop(HARDWARE_CHARGER_IC_INFO, "SGM41513A");
		hardwareinfo_num = HARDWARE_CHARGER_IC_INFO;
		break;
	case HARDWARE_BMS_GAUGE_GET:
		hardwareinfo_set_prop(HARDWARE_BMS_GAUGE, "SC27XX");
		hardwareinfo_num = HARDWARE_BMS_GAUGE;
		break;
	case HARDWARE_BOARD_ID_GET:
		boardid_get();
		hardwareinfo_set_prop(HARDWARE_BOARD_ID, board_type);
		hardwareinfo_num = HARDWARE_BOARD_ID;
		break;

    case HARDWARE_SMARTPA_IC_INFO_GET:
		hardwareinfo_set_prop(HARDWARE_SMARTPA_IC_INFO, "AW88394");
		hardwareinfo_num = HARDWARE_SMARTPA_IC_INFO;
		break;

	case HARDWARE_HARDWARE_ID_GET:
		hwid_get();
		hardwareinfo_set_prop(HARDWARE_HARDWARE_ID, hardware_id);
		hardwareinfo_num = HARDWARE_HARDWARE_ID;
		break;
	case HARDWARE_BACK_CAM_MOUDULE_ID_GET:
		hardwareinfo_set_prop(HARDWARE_BACK_CAM_MOUDULE_ID, "TA8H3RC");
		hardwareinfo_num = HARDWARE_BACK_CAM_MOUDULE_ID;
		break;
	case HARDWARE_FRONT_CAM_MODULE_ID_GET:
		hardwareinfo_set_prop(HARDWARE_FRONT_CAM_MOUDULE_ID, "TF8H5UA");
		hardwareinfo_num = HARDWARE_FRONT_CAM_MOUDULE_ID;
		break;
	case HARDWARE_HALL_GET:
		hardwareinfo_set_prop(HARDWARE_HALL, "AS1810AD4RN");
		hardwareinfo_num = HARDWARE_HALL;
		break;
	//Modify by huangmiao@wingtech.com for SCT-702  add hardware info for factory on start(2021.9.9)
	case HARDWARE_CAMERA_INFO_SET:
	{
		camera_info hardware;
		memset(&hardware, 0, sizeof(camera_info));
		if(copy_from_user(&hardware, data, sizeof(camera_info)))
		{
			pr_err("copy_from_user HARDWARE_CAMERA_INFO_SET error");
			ret =  -EINVAL;
		}
		else
		{
			strncpy(hardwareinfo_name[hardware.param], hardware.str, hardware.lenth);
			pr_info("copy_from_user HARDWARE_CAMERA_INFO_SET %d, %s", hardware.param, hardwareinfo_name[hardware.param]);
		}
		goto set_ok;
		break;
	}
	//Modify by huangmiao@wingtech.com for SCT-702  add hardware info for factory on end(2021.9.9)
	default:
		ret = -EINVAL;
		goto err_out;
	}
	//memset(data, 0, HARDWARE_MAX_ITEM_LONGTH);//clear the buffer
	if (copy_to_user(data, hardwareinfo_name[hardwareinfo_num], strlen(hardwareinfo_name[hardwareinfo_num]))){
		//printk("%s, copy to usr error\n", __func__);
		ret =  -EINVAL;
	}
set_ok:
err_out:
	return ret;
}

static ssize_t show_boardinfo(struct device *dev, struct device_attribute *attr, char *buf)
{
	int i = 0;
	char temp_buffer[HARDWARE_MAX_ITEM_LONGTH];
	int buf_size = 0;

	for(i = 0; i < HARDWARE_MAX_ITEM; i++)
	{
		memset(temp_buffer, 0, HARDWARE_MAX_ITEM_LONGTH);
		if(i == HARDWARE_LCD)
		{
			sprintf(temp_buffer, "%s : %s\n", hardwareinfo_items[i], "TA4RUS07VOFMZTB");
		}
		else if(i == HARDWARE_BT || i == HARDWARE_WIFI || i == HARDWARE_GPS || i == HARDWARE_FM)
		{
			sprintf(temp_buffer, "%s : %s\n", hardwareinfo_items[i], "Qualcomm");
		}
		else if(i == HARDWARE_BOARD_ID){
			boardid_get();
			hardwareinfo_set_prop(HARDWARE_BOARD_ID, board_type);
			sprintf(temp_buffer, "%s : %s\n", hardwareinfo_items[i], hardwareinfo_name[i]);
		}
		else if(i == HARDWARE_HARDWARE_ID)
		{
			hwid_get();
			hardwareinfo_set_prop(HARDWARE_HARDWARE_ID, hardware_id);
			sprintf(temp_buffer, "%s : %s\n", hardwareinfo_items[i], hardwareinfo_name[i]);
		}
		else
		{
			sprintf(temp_buffer, "%s : %s\n", hardwareinfo_items[i], hardwareinfo_name[i]);
		}
		strcat(buf, temp_buffer);
		buf_size +=strlen(temp_buffer);
	}

	return buf_size;
}
static DEVICE_ATTR(boardinfo, S_IRUGO, show_boardinfo, NULL);


static int boardinfo_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	//struct device_node *node;
	int rc = 0;
	//node = pdev->dev.of_node;

	printk("%s: start\n", __func__);

	//board_id1 = of_get_named_gpio(node, "boardid1-gpio", 0);
	//board_id2 = of_get_named_gpio(node, "boardid2-gpio", 0);
	//board_id3 = of_get_named_gpio(node, "boardid3-gpio", 0);
	//rc=gpio_request(board_id1, "board_id1");
	//if(rc<0)
	//	printk("board_id1 request failed\n");
	//rc=gpio_request(board_id2, "board_id2");
	//if(rc<0)
	//	printk("board_id2 request failed\n");
	//rc=gpio_request(board_id3, "board_id3");
	//if(rc<0)
	//	printk("board_id3 request failed\n");
	//
	//gpio_direction_input(board_id1);
	//gpio_direction_input(board_id2);
	//gpio_direction_input(board_id3);

	rc = device_create_file(dev, &dev_attr_boardinfo);
	if (rc < 0)
		return rc;

	dev_info(dev, "%s: ok\n", __func__);

	return 0;
}

static int boardinfo_remove(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;

	device_remove_file(dev, &dev_attr_boardinfo);
	dev_info(&pdev->dev, "%s\n", __func__);
	return 0;
}


static struct file_operations hardwareinfo_fops = {
	.owner = THIS_MODULE,
	.open = simple_open,
	.unlocked_ioctl = hardwareinfo_ioctl,
	.compat_ioctl = hardwareinfo_ioctl,
};

static struct miscdevice hardwareinfo_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "hardwareinfo",
	.fops = &hardwareinfo_fops,
};

#if 1
static const struct of_device_id boardinfo_of_match[] = {
	{
		.compatible = "wt-boardinfo",
	},
	{}
};
MODULE_DEVICE_TABLE(of, boardinfo_of_match);

static const struct platform_device_id boardinfo_id[] = {
	{"wt-boardinfo",0},
	{}
};
MODULE_DEVICE_TABLE(platform, boardinfo_id);
#endif

static struct platform_driver boardinfo_driver = {
	.driver = {
		.name	= "wt-boardinfo",
		.owner	= THIS_MODULE,
		.of_match_table = boardinfo_of_match,
	},
	.id_table	= boardinfo_id,
	.probe		= boardinfo_probe,
	.remove		= boardinfo_remove,
};



static int __init hardwareinfo_init_module(void)
{
	int ret, i;

	for(i = 0; i < HARDWARE_MAX_ITEM; i++)
		strcpy(hardwareinfo_name[i], "NULL");
	ret = misc_register(&hardwareinfo_device);
	if(ret < 0){
		return -ENODEV;
	}

	ret = platform_driver_register(&boardinfo_driver);
	if(ret != 0)
	{
		return -ENODEV;
	}

	return 0;
}

static void __exit hardwareinfo_exit_module(void)
{
	misc_deregister(&hardwareinfo_device);
}

module_init(hardwareinfo_init_module);
module_exit(hardwareinfo_exit_module);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ming He <heming@wingtech.com>");
//Added by wt.yanrenjie for SCT-702,wt hardware info end


