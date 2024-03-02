#include<linux/module.h>
#include<linux/init.h>
#include<linux/device.h>
#include<linux/of_device.h>
#include<linux/of.h>

MODULE_AUTHOR("Shian.Wang");
MODULE_LICENSE("GPL");

static const char *sprd_soc_model;
static const char *sprd_soc_manufacturer;

static int init_manufacturer_model(void)
{
	struct device_node *root;
	int ret;

	root = of_find_node_by_path("/");
	if (root) {
		ret = of_property_read_string(root, "soc-module",
						&sprd_soc_model);
		if (ret)
			sprd_soc_model = NULL;
		ret = of_property_read_string(root, "soc-manufacturer",
						&sprd_soc_manufacturer);
		if (ret)
			sprd_soc_manufacturer = NULL;
	}
	return 0;
}

static ssize_t soc_model_show(struct kobject *kobj, struct kobj_attribute *attr,
				char *buf)
{
	return (ssize_t) sprintf(buf, "soc_model: %s \n", sprd_soc_model);
}

static ssize_t soc_manufacturer_show(struct kobject *kobj, struct kobj_attribute *attr,
				char *buf)
{
	return (ssize_t) sprintf(buf, "soc_model: %s \n", sprd_soc_manufacturer);
}

int off_mode_charge;
extern void off_mode_charge_test(int value);
extern u32 off_mode_charge_value(void);
static ssize_t off_mode_charge_show(struct kobject *kobj, struct kobj_attribute *attr,
				char *buf)
{
	if(off_mode_charge == 1)
		return sprintf(buf, "%s\n", "1");
	else if(off_mode_charge == 2)
		return sprintf(buf, "%s\n", "2");
	else
		return sprintf(buf, "%s\n", "0");
}
static ssize_t  off_mode_charge_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
	printk("sqw %s :buf =%s\n",__func__,buf);
	if(!strncmp(buf, "1",1))
		off_mode_charge = 1;
	else if(!strncmp(buf, "2",1))
		off_mode_charge = 2;
	else
		off_mode_charge = 0;
	off_mode_charge_test(off_mode_charge);
	printk("sqw %s :off_mode_charge =%d\n",__func__,off_mode_charge);
	return 	count;
}

static struct kobj_attribute kobj_soc_model = {
	.attr = {.name = __stringify(soc_model),
		.mode = VERIFY_OCTAL_PERMISSIONS(S_IRUGO) },
	.show = soc_model_show,
};

static struct kobj_attribute kobj_soc_manufacturer = {
	.attr = {.name = __stringify(soc_manufacturer),
		.mode = VERIFY_OCTAL_PERMISSIONS(S_IRUGO) },
	.show = soc_manufacturer_show,
};

static struct kobj_attribute kobj_off_mode_charge = {
	.attr = {.name = __stringify(off_mode_charge),
		.mode = VERIFY_OCTAL_PERMISSIONS(S_IRUGO|S_IWUSR) },
	.show = off_mode_charge_show,
	.store = off_mode_charge_store,
};

static struct attribute *default_attrs[] = {
	&kobj_soc_model.attr,
	&kobj_soc_manufacturer.attr,
	NULL
};

static struct attribute *default_pro_attrs[] = {
	&kobj_off_mode_charge.attr,
	NULL
};

static const struct attribute_group soc_attr_group = {
	.attrs = default_attrs,
	.name = "soc0"
};

static const struct attribute_group proinfo_attr_group = {
	.attrs = default_pro_attrs,
	.name = "proinfo"
};

static int sprd_manufacturer_model(void)
{
	static struct device sprd_manufacturer_model_dev;
	static struct device *pdev = (struct device *) &sprd_manufacturer_model_dev;
	u32 value;
	device_initialize(pdev);

	sysfs_create_group(&pdev->kobj.kset->kobj, &proinfo_attr_group);
	value = off_mode_charge_value();
	if(value == 0x66)
		off_mode_charge = 1;
	else
		off_mode_charge = 2;
	if(!sysfs_create_group(&pdev->kobj.kset->kobj, &soc_attr_group))
		return 0;

	return -1;
}

static int __init manufacturer_model_init(void)
{
	int err;

	init_manufacturer_model();
	err = sprd_manufacturer_model();
	if (!err)
		printk(KERN_ALERT"Init manufacturer_model mudule successfully\n");
	else
		printk(KERN_ALERT"Init manufacturer_model mudule failed\n");

	return 0;
}

static void __exit manufacturer_model_exit(void)
{
	printk(KERN_ALERT"Exit manufacturer_model mudule...\n");
}


module_init(manufacturer_model_init);
module_exit(manufacturer_model_exit);
