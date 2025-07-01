#define pr_fmt(fmt) "getpid hook: " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/ftrace.h>

MODULE_AUTHOR("PRANAV P");
MODULE_DESCRIPTION("SYSCALL HOOK");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

void say_piiiid(unsigned long, unsigned long,
		struct ftrace_ops*, struct ftrace_regs*);

struct ftrace_ops ops = {
	.func = say_piiiid,
	.flags = FTRACE_OPS_FL_SAVE_REGS | FTRACE_OPS_FL_RECURSION
};

void say_piiiid(unsigned long ip, unsigned long parent_ip,
		struct ftrace_ops *op, struct ftrace_regs *regs)
{
	pr_info("Someone just called getpid\n");
}

static int __init hello_world_init(void)
{
	int err;
	pr_info("Loading Module\n");

	err = ftrace_set_filter(&ops, "__do_sys_getpid", strlen("__do_sys_getpid"), 0);
	if (err) {
		pr_err("ftrace_set_filter failed: %d\n", err);
		return err;
	}
	err = register_ftrace_function(&ops);
	if (err) {
		pr_err("register_ftrace_function failed: %d\n", err);
		return err;
	}

	return 0;
}

static void __exit hello_world_exit(void)
{
	pr_info("Unloading Module\n");
	unregister_ftrace_function(&ops);
	ftrace_set_filter(&ops, NULL, 0, 1);
}

module_init(hello_world_init);
module_exit(hello_world_exit);
