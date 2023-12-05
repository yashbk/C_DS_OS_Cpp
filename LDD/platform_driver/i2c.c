#include <linux/i2c.h>
#include <linux/module.h>

static struct i2c_client *my_i2c_client; // I2C client structure

static int my_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id) {
    // Perform device initialization/configuration here

    // Save the client structure
    my_i2c_client = client;

    printk(KERN_INFO "My I2C device probed\n");
    return 0; // Return 0 to indicate success
}

static int my_i2c_remove(struct i2c_client *client) {
    // Perform device cleanup here

    printk(KERN_INFO "My I2C device removed\n");
    return 0; // Return 0 to indicate success
}

static const struct i2c_device_id my_i2c_id[] = {
    { "my_i2c_device", 0 }, // Name of your I2C device
    { }
};
MODULE_DEVICE_TABLE(i2c, my_i2c_id);

static struct i2c_driver my_i2c_driver = {
    .driver = {
        .name = "my_i2c_device_driver", // Driver name
    },
    .probe = my_i2c_probe,
    .remove = my_i2c_remove,
    .id_table = my_i2c_id,
};

static int __init my_i2c_init(void) {
    return i2c_add_driver(&my_i2c_driver); // Register the driver with the I2C subsystem
}
module_init(my_i2c_init);

static void __exit my_i2c_exit(void) {
    i2c_del_driver(&my_i2c_driver); // Unregister the driver
}
module_exit(my_i2c_exit);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Basic I2C driver example");
MODULE_LICENSE("GPL");

