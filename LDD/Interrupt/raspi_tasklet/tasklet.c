#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

#define GPIO_PIN 17  // Example GPIO pin (change as needed)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Raspberry Pi Interrupt Example");

static unsigned int irq_number;
static struct tasklet_struct my_tasklet;

// Interrupt handler
static irqreturn_t my_interrupt_handler(int irq, void *dev_id) {
    pr_info("Interrupt occurred!\n");

    // Schedule the tasklet to run in the bottom half
    tasklet_schedule(&my_tasklet);
    printk("Tasklet started\n");

    return IRQ_HANDLED;
}

// Tasklet function (bottom half)
static void my_tasklet_function(unsigned long data) {
    pr_info("Tasklet executed!\n");

    // Your bottom half processing goes here

    // For demonstration, we'll print a message
    pr_info("Bottom half processing complete.\n");
}

static int __init my_module_init(void) {
    int result;

    // Request GPIO pin
    result = gpio_request(GPIO_PIN, "my_gpio_interrupt");
    if (result) {
        pr_err("Failed to request GPIO %d\n", GPIO_PIN);
        return result;
    }

    // Set up interrupt
    irq_number = gpio_to_irq(GPIO_PIN);
    result = request_irq(irq_number, my_interrupt_handler, IRQF_TRIGGER_FALLING, "my_interrupt", NULL);
    if (result) {
        pr_err("Failed to request IRQ %d\n", irq_number);
        gpio_free(GPIO_PIN);
        return result;
    }

    // Initialize the tasklet
    tasklet_init(&my_tasklet, my_tasklet_function, 0);

    pr_info("Interrupt handler and tasklet registered successfully\n");
    return 0;
}

static void __exit my_module_exit(void) {
    // Free resources
    tasklet_kill(&my_tasklet);
    free_irq(irq_number, NULL);
    gpio_free(GPIO_PIN);

    pr_info("Interrupt handler and tasklet unregistered\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

