#include <linux/module.h>
#include <linux/platform_device.h>
#include <init.h>


struct platform_device platform_pcdev1 = {
    .name = "char-dev1"
    .id = 0
};

struct platform_device platform_pcdev2 = {
    .name = "char-dev2",
    .id = 1
};

static int __init platform_init(void)
{
    //registering device
    platform_device_register(&platform_pcdev1);
    platform_device_register(&platform_pcdev2);
    return 0;
}

static void __exit platform_exit(void)
{
    platform_device_unregister(&platform_pcdev1);
    platform_device_unregister(&platform_pcdev2);
}

module_init(platform_init);
module_exit(platform_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yashas");