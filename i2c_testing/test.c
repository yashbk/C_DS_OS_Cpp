#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/of.h>
#include <linux/gpio/consumer.h>

static int my_remove(struct i2c_client *client)
{
	printk("Remove function called\n");
}

static int ssd1306_probe(struct i2c_client *client, const struct i2c_device_id *id) {
    struct device_node *np = client->dev.of_node;
    struct gpio_desc *reset_gpio = NULL;

    // Retrieve and handle GPIO for reset (if specified in Device Tree)
    reset_gpio = devm_gpiod_get_optional(&client->dev, "reset", GPIOD_OUT_LOW);
    if (IS_ERR(reset_gpio)) {
        dev_err(&client->dev, "Failed to get reset GPIO\n");
        return PTR_ERR(reset_gpio);
    }

    pr_info("SSD1306 device matched: %s, address 0x%02x\n", client->name, client->addr);
    printk("Probe function called\n");

    // Perform device-specific initialization and operations here
    // Example: Writing commands/data to SSD1306 display

    return 0; // Success
}

static const struct of_device_id ssd1306_dt_ids[] = {
    { .compatible = "solomon,ssd1306" },
    { }
};
MODULE_DEVICE_TABLE(of, ssd1306_dt_ids);

static struct i2c_driver ssd1306_driver = {
    .probe = ssd1306_probe,
    .remove = my_remove,
    .driver = {
        .name = "ssd1306",
        .of_match_table = of_match_ptr(ssd1306_dt_ids),
    },
};

static int __init ssd1306_init(void) {
    return i2c_add_driver(&ssd1306_driver);
}

static void __exit ssd1306_exit(void) {
    i2c_del_driver(&ssd1306_driver);
}

module_init(ssd1306_init);
module_exit(ssd1306_exit);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("SSD1306 I2C Driver with Device Tree support");
MODULE_LICENSE("GPL");
