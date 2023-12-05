#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>

int irq = 1;

static irqreturn_t interrupt_handler(int irq,void *dev_id)
{
	printk("Interrupt called\n");
	return IRQ_HANDLED;
}


static int interrupt_init(void)
{
	if(request_irq(irq,interrupt_handler,IRQF_SHARED,"bk_interrupt",(void*)(interrupt_handler)))
	{
		return 0;
	}
	return 0;
}

static void interrupt_exit(void)
{


}

module_init(interrupt_init);
module_exit(interrupt_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yashas");
