#include <linux/module.h>
#include <linux/i2c.h>

static struct i2c_adapter *my_adapter;  // Assuming you have the adapter reference

static int ssd1306_probe(struct i2c_client *client, const struct i2c_device_id *id) {
    pr_info("SSD1306 Probe function called for device at address 0x%02x\n", client->addr);

    // Perform SSD1306-specific initialization and operations here
    // Example: Setting up display parameters, initializing the display

    return 0;  // Success
}

static const struct i2c_device_id ssd1306_id[] = {
    { "ssd1306", 0 }, // Example device ID
    { }
};
MODULE_DEVICE_TABLE(i2c, ssd1306_id);

static struct i2c_driver ssd1306_driver = {
    .probe = ssd1306_probe,
    .driver = {
        .name = "ssd1306_driver",
        .owner = THIS_MODULE,
    },
    .id_table = ssd1306_id,
};

static int __init ssd1306_init(void) {
    struct i2c_adapter *adapter;
    struct i2c_board_info info;

    my_adapter = i2c_get_adapter(1); // Use the appropriate adapter number

    if (!my_adapter) {
        pr_err("Failed to get I2C adapter\n");
        return -ENODEV;
    }

    adapter = my_adapter;

    for (u16 address = 0x08; address <= 0x77; ++address) {
        memset(&info, 0, sizeof(struct i2c_board_info));
        strlcpy(info.type, "ssd1306", I2C_NAME_SIZE);
        info.addr = address;

        if (i2c_new_client_device(adapter, &info)) {
            pr_info("Detected SSD1306 display at address 0x%x\n", address);
        }
    }

    return i2c_add_driver(&ssd1306_driver);
}

static void __exit ssd1306_exit(void) {
    i2c_del_driver(&ssd1306_driver);
}

module_init(ssd1306_init);
module_exit(ssd1306_exit);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("SSD1306 OLED I2C driver for Raspberry Pi");
MODULE_LICENSE("GPL");
