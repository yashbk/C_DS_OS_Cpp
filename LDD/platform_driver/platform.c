#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>

struct my_device_data {
    struct i2c_client *client;
    /* Your device-specific data */
};

static int my_driver_probe(struct platform_device *pdev) {
    struct my_device_data *data;
    struct i2c_adapter *adapter;
    struct i2c_board_info info;
    int ret = 0;

    // Allocate memory for your device data
    data = devm_kzalloc(&pdev->dev, sizeof(struct my_device_data), GFP_KERNEL);
    if (!data)
        return -ENOMEM;

    // Retrieve I2C adapter
    adapter = i2c_get_adapter(0); // Change 0 to the relevant I2C bus number
    if (!adapter)
        return -ENODEV;

    // Initialize the I2C board info
    memset(&info, 0, sizeof(struct i2c_board_info));
    strlcpy(info.type, "my_i2c_device", I2C_NAME_SIZE); // Device name

    // Create an I2C device
    data->client = i2c_new_device(adapter, &info);
    if (!data->client) {
        ret = -ENODEV;
        goto err_adapter_put;
    }

    /* Your device-specific initialization code using data->client */

    // Set the device driver data
    platform_set_drvdata(pdev, data);

    return 0;

err_adapter_put:
    i2c_put_adapter(adapter);
    return ret;
}

static int my_driver_remove(struct platform_device *pdev) {
    struct my_device_data *data = platform_get_drvdata(pdev);

    /* Your device-specific cleanup code using data->client */

    i2c_unregister_device(data->client);
    i2c_put_adapter(data->client->adapter);
    return 0;
}

static struct platform_driver my_platform_driver = {
    .probe = my_driver_probe,
    .remove = my_driver_remove,
    .driver = {
        .name = "my_platform_device",
        .owner = THIS_MODULE,
    },
};

static int __init my_driver_init(void) {
    return platform_driver_register(&my_platform_driver);
}

static void __exit my_driver_exit(void) {
    platform_driver_unregister(&my_platform_driver);
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Sample Platform Driver");

