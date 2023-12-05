#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>

#define MAJOR_NUMBER 250
#define MINOR_NUMBER_0 0
#define MINOR_NUMBER_1 1

static struct class *my_class;
static dev_t dev_numbers[2];
static struct cdev my_cdev[2];

struct my_device_data {
    int device_id;
    // Add other device-specific data members as needed
};

static int mydriver_open(struct inode *inode, struct file *file) {
    struct my_device_data *data;

    data = kmalloc(sizeof(struct my_device_data), GFP_KERNEL);
    if (!data) {
        return -ENOMEM;
    }

    // Assign device-specific data
    if (iminor(inode) == MINOR_NUMBER_0) {
        data->device_id = 0;
    } else if (iminor(inode) == MINOR_NUMBER_1) {
        data->device_id = 1;
    }

    // Store device-specific data in private_data for later use
    file->private_data = data;

    pr_info("Device %d opened\n", data->device_id);
    return 0;
}

static int mydriver_release(struct inode *inode, struct file *file) {
    struct my_device_data *data = file->private_data;

    pr_info("Device %d released\n", data->device_id);
    kfree(data);
    return 0;
}

static const struct file_operations mydriver_fops = {
    .owner = THIS_MODULE,
    .open = mydriver_open,
    .release = mydriver_release,
    // Add other file operations as needed
};

static int __init mydriver_init(void) {
    int i;

    // Allocate major and minor numbers for the devices
    if (alloc_chrdev_region(dev_numbers, 0, 2, "mydriver") < 0) {
        pr_err("Failed to allocate character device numbers\n");
        return -ENODEV;
    }

    // Create a class
    my_class = class_create(THIS_MODULE, "my_class");
    if (IS_ERR(my_class)) {
        pr_err("Failed to create class\n");
        unregister_chrdev_region(dev_numbers[0], 2);
        return PTR_ERR(my_class);
    }

    // Create devices and register file operations
    for (i = 0; i < 2; ++i) {
        cdev_init(&my_cdev[i], &mydriver_fops);
        my_cdev[i].owner = THIS_MODULE;
        if (cdev_add(&my_cdev[i], dev_numbers[i], 1) < 0) {
            pr_err("Failed to add character device\n");
            device_destroy(my_class, dev_numbers[i]);
            class_destroy(my_class);
            unregister_chrdev_region(dev_numbers[0], 2);
            return -ENODEV;
        }

        // Create devices with parent set to NULL, drvdata set to device-specific data
        device_create(my_class, NULL, dev_numbers[i], &my_cdev[i], "mydevice%d", i);
    }

    pr_info("Driver loaded\n");
    return 0;
}

static void __exit mydriver_exit(void) {
    int i;

    // Remove devices, unregister character devices, and destroy the class
    for (i = 0; i < 2; ++i) {
        device_destroy(my_class, dev_numbers[i]);
        cdev_del(&my_cdev[i]);
    }

    class_destroy(my_class);
    unregister_chrdev_region(dev_numbers[0], 2);

    pr_info("Driver unloaded\n");
}

module_init(mydriver_init);
module_exit(mydriver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Sample Character Device Driver");
