#include <linux/module.h>
#include  <linux/fs.h>
#include <linux/init.h>
#include <linux/cdev.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("YASHAS B K");

static int __init sample_driver_init(void)
{
	printk(KERN_INFO "Sample driver init function\n");
	return 0;
}

static void __exit sample_driver_exit(void)
{
	printk(KERN_INFO "Sample driver exit function\n");
}

module_init(sample_driver_init);
module_exit(sample_driver_exit);
