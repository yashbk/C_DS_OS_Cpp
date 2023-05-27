#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/err.h>


//Function declarations;
static int my_open(struct inode *inode,struct file *file);
static int my_release(struct inode *inode, struct file *file);
static ssize_t my_read(struct file *filp,char __user *buf, size_t len, loff_t *off);
static ssize_t my_write(struct file *filp,const char __user *buf, size_t len, loff_t *off);


dev_t dev_num = 0;
static struct class *my_class;
static struct cdev *my_cdev;
static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_open,
	.release = my_release,
	.read = my_read,
	.write = my_write
};
uint8_t * buffer = NULL;


static int __init my_driver_init(void)
{
	//Assigning major and minor number
	if(alloc_chrdev_region(&dev_num,0,1,"my_driver")<0)
		pr_info("allocation failed\n");
	pr_info("Major number is %d and minor number is %d\n",MINOR(dev_num),MAJOR(dev_num));

	//Creating device file
	//Creating class
	if(IS_ERR(my_class = class_create(THIS_MODULE,"my_class_driver")))
	{
		pr_err("Class creation failed\n");
		unregister_chrdev_region(dev_num,1);
		return -1;
	}


	//Creating device
	if(IS_ERR(device_create(my_class,NULL,dev_num,NULL,"my_device")))
	{
		pr_err("Device creation failed\n");
		class_destroy(my_class);
		return -1;
	}


	my_cdev = cdev_alloc();
	my_cdev->ops = &fops;
	
	if((cdev_add(my_cdev,dev_num,1)<0))
	{
		pr_err("Cannot link cdev to VFS\n");
		device_destroy(my_class,dev_num);
		return -1;
	}


	if(buffer = kmalloc(1024,GFP_KERNEL) == NULL)
	{
		pr_info("Buffer creation failed\n");
	}

	strcpy(buffer,"Hello yashas");


	pr_info("Device driver installed\n");

	return 0;

}

static void __exit my_driver_exit(void)
{
	kfree(buffer);
	cdev_del(my_cdev);
	device_destroy(my_class,dev_num);
	class_destroy(my_class);
	unregister_chrdev_region(dev_num,1);
	pr_info("Device driver removed\n");
}



static int my_open(struct inode *inode,struct file *file)
{
	pr_info("Driver open\n");
	return 0;
}

static int my_release(struct inode *inode,struct file *file)
{
	pr_info("Driver close\n");
	return 0;
}

static ssize_t my_read(struct file *filp,char __user *buf, size_t len, loff_t *off)
{
	if(copy_to_user(buf,buffer,1024))
	{
		pr_err("Could not copy\n");
	pr_info("Driver read function called\n");
	return 0;
}

static ssize_t my_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
	if(copy_from_user(buffer,buf,len))
	{
		pr_err("Could not write to kernel memory\n");
	pr_info("Driver write function called\n");
	return 0;
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("YASHAS");
