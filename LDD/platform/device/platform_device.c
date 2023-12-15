#include <linux/module.h>
#include <linux/platform_device.h>
#include "platform.h"


void pcdev_release(struct device *dev)
{
	printk("Device release function called\n");
}

struct pcdev_platform_data pcdev_pdata[2] =
{
	[0] = {.size = 512,.perm = RDWR, .serial_number = "PCDEVABC1111"},
	[1] = {.size = 1024,.perm = RDWR, .serial_number = "PCDEVXYZ2222"}
};

struct platform_device platform_pcdev1 = {
    .name = "pseudo-char-device",
    .id = 22,
    .dev = {
	    .platform_data = &pcdev_pdata[0],
	    .release = pcdev_release
    }
};

struct platform_device platform_pcdev2 = {
    .name = "pseudo-char-device",
    .id = 44,
    .dev = {
	    .platform_data = &pcdev_pdata[1],
	    .release = pcdev_release
    }
};

static int __init platform_init(void)
{
    //registering device
    platform_device_register(&platform_pcdev1);
    platform_device_register(&platform_pcdev2);
    printk("Device module loaded\n");
    return 0;
}

static void __exit platform_exit(void)
{
    platform_device_unregister(&platform_pcdev1);
    platform_device_unregister(&platform_pcdev2);
    printk("Device module unloaded\n");
}

module_init(platform_init);
module_exit(platform_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yashas");
