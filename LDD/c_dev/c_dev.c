#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/cdev.h>
#include <linux/device.h>

dev_t dev = 0;
static struct class *dev_class;
static struct cdev dev_cdev;

//Function prototypes
static int      dev_open(struct inode *inode, struct file *file);
static int     	dev_release(struct inode *inode, struct file *file);
static ssize_t  dev_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  dev_write(struct file *filp, const char *buf, size_t len, loff_t * off);


static struct file_operations fops =
{
    .owner      = THIS_MODULE,
    .read       = dev_read,
    .write      = dev_write,
    .open       = dev_open,
    .release    = dev_release,
};

/*
** This function will be called when we open the Device file
*/
static int dev_open(struct inode *inode, struct file *file)
{
        pr_info("Driver Open Function Called...!!!\n");
        return 0;
}

/*
** This function will be called when we close the Device file
*/
static int dev_release(struct inode *inode, struct file *file)
{
        pr_info("Driver Release Function Called...!!!\n");
        return 0;
}

/*
** This function will be called when we read the Device file
*/
static ssize_t dev_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Read Function Called...!!!\n");
        return 0;
}

/*
** This function will be called when we write the Device file
*/
static ssize_t dev_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Write Function Called...!!!\n");
        return len;
}

//Module init function
static int __init driver_init_func(void)
{
        /*Allocating Major number dynamically*/
        if((alloc_chrdev_region(&dev, 0, 1, "dev_DEV")) <0){
                pr_err("Cannot allocate major number\n");
                return -1;
        }
        pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));

        /*Creating cdev structure and linking fops with cdev structure*/
        cdev_init(&dev_cdev,&fops);

        /*Adding character device to the system*/
        if((cdev_add(&dev_cdev,dev,1)) < 0){
            pr_err("Cannot add the device to the system\n");
            goto rm_class;
        }

        /*Creating struct class*/
        if(IS_ERR(dev_class = class_create(THIS_MODULE,"dev_class"))){
            pr_err("Cannot create the struct class\n");
            goto rm_class;
        }

        /*Creating device*/
        if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"dev_device"))){
            pr_err("Cannot create the Device 1\n");
            goto rm_device;
        }
        pr_info("Device Driver Inserted...Done!!!\n");
      return 0;

rm_device:
        class_destroy(dev_class);
rm_class:
        unregister_chrdev_region(dev,1);
        return -1;
}

//Module exit function

static void __exit driver_exit_func(void)
{
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&dev_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Removed...Done!!!\n");
}

module_init(driver_init_func);
module_exit(driver_exit_func);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("YASHAS");
MODULE_DESCRIPTION("FILE OPERATION DEMO");
