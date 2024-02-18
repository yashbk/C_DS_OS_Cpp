#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>

static int __init my_sensor_init(void)
{
    struct device_node *np;
    int temperature;

    np = of_find_node_by_name(NULL, "sensor@0");
    if (!np) {
        pr_err("Device Tree node not found\n");
        return -ENODEV;
    }

    if (of_property_read_u32(np, "temperature", &temperature)) {
        pr_err("Failed to read temperature property\n");
        return -EINVAL;
    }

    pr_info("Temperature: %d degrees Celsius\n", temperature);

    return 0;
}

static void __exit my_sensor_exit(void)
{
    // Cleanup, if needed
}

module_init(my_sensor_init);
module_exit(my_sensor_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("My Temperature Sensor Driver");

