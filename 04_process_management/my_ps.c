#define pr_fmt(fmt) "my_ps: " fmt
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

MODULE_AUTHOR("PRANAV P");
MODULE_DESCRIPTION("LOOPING TASK STRUCT");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static int __init my_ps_init(void)
{
	pr_info("Attaching module my_ps\n");

	struct task_struct *p;
	pr_info("PID\tCOMMAND");
	for_each_process(p) {
		pr_info("%d\t%s\n", p->pid, p->comm);
	}

	return 0;
}

static void __exit my_ps_exit(void)
{
	pr_info("Dettaching module my_ps\n");
}

module_init(my_ps_init);
module_exit(my_ps_exit);
