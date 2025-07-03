#define pr_fmt(fmt) "timer_interrupt: " fmt
#define IRQ_NO 15
/* In my system 15 was an edge triggered interrupt */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_AUTHOR("PRANAV P");
MODULE_DESCRIPTION("INTERRUPT HANDLING");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static int counter = 0;
static irqreturn_t irq_handler(int, void*);

static int __init timer_irqh_init(void)
{
	int result;
	pr_info("Module loaded\n");
	if ((result = request_irq(IRQ_NO, irq_handler, IRQF_TIMER | IRQF_SHARED, "timer_interrupt", (void *)(irq_handler)))) {
		pr_err("interrupt failed with error code %d\n", result);
		free_irq(IRQ_NO, (void *)(irq_handler));
	}
	
	return 0;
}

static void __exit timer_irqh_exit(void)
{
	free_irq(IRQ_NO, (void *)(irq_handler));
	pr_info("Module unloaded\n");
}

static irqreturn_t irq_handler(int irq, void *dev_id)
{
	pr_info("Interrupted %d times\n", ++counter);
	return IRQ_HANDLED;
}

module_init(timer_irqh_init);
module_exit(timer_irqh_exit);
