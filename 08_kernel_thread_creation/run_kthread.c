#define pr_fmt(fmt) "run_kthread: " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

MODULE_AUTHOR("PRANAV P");
MODULE_DESCRIPTION("CREATE KTHREAD");
MODULE_LICENSE("0.1");
MODULE_VERSION("GPL");

static struct task_struct *tsk;
static int counter = 0;

static int dummy_threadfn(void *args)
{
	while (!kthread_should_stop()) {
		counter++;
		pr_info("Counter counting %d\n", counter);
		msleep(1000);
	}

	return 0;
}

static ssize_t counter_read(struct file *file, char __user *buffer,
		size_t length, loff_t *offset)
{
	if (*offset > 0) return 0;
	unsigned long result;
	char counter_buffer[50];

	snprintf(counter_buffer, 50, "%d\n", counter);
	if ((result = copy_to_user(buffer, counter_buffer,
					strlen(counter_buffer)))) {
		pr_err("copy_to_user failed\n");
		return -1;
	}

	*offset = length;
	return length;
}

static struct proc_ops proc_fops = {
	.proc_read = counter_read
};

static int __init run_kthread_init(void)
{
	pr_info("Module attached\n");
	proc_create("my_procfile", 0666, NULL, &proc_fops);
	tsk = kthread_run(dummy_threadfn, NULL, "dummy_kthread");
	return 0;
}

static void __exit run_kthread_exit(void)
{
	remove_proc_entry("my_procfile", NULL);
	kthread_stop(tsk);
	pr_info("Module detached\n");
}

module_init(run_kthread_init);
module_exit(run_kthread_exit);
