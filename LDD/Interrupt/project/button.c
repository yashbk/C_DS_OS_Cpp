#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>

#define BUTTON_GPIO 16
#define LED_GPIO 26

int irq;

static irqreturn_t interrupt_handler(int irq,void *dev_id)
{
	gpio_set_value(LED_GPIO, !gpio_get_value(LED_GPIO));

	printk("Interrupt called\n");
	return IRQ_HANDLED;
}


static int interrupt_init(void)
{
	if(gpio_is_valid(LED_GPIO))
	{
		gpio_request(LED_GPIO,"led");
		gpio_direction_output(LED_GPIO,0);
	}
	if(gpio_is_valid(BUTTON_GPIO))
	{
		gpio_request(BUTTON_GPIO,"BUTTON");
		gpio_direction_input(BUTTON_GPIO);
		irq = gpio_to_irq(BUTTON_GPIO);
	}

	if(request_irq(irq,interrupt_handler,IRQF_TRIGGER_RISING,"bk_interrupt",NULL))
	{
		return 0;
	}
	return 0;
}

static void interrupt_exit(void)
{
	gpio_set_value(LED_GPIO,0);
	gpio_free(LED_GPIO);
	gpio_free(BUTTON_GPIO);
	free_irq(irq,NULL);
	printk("Module unintialized\n");

}

module_init(interrupt_init);
module_exit(interrupt_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yashas");
