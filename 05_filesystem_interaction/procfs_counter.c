#define pr_fmt(fmt) "procfs_counter: " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/sprintf.h>
#include <linux/uaccess.h>
#include <linux/kstrtox.h>

MODULE_AUTHOR("PRANAV P");
MODULE_DESCRIPTION("COUNTER THROUGH PROCFS");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static ssize_t counter_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t counter_write(struct file *, const char __user *, size_t, loff_t *);

long counter = 0;
static struct proc_ops proc_fops = {
	.proc_read = counter_read,
	.proc_write = counter_write
};

static int __init counter_init(void)
{
	pr_info("Counter module loaded\n");

	proc_create("my_counter", 0666, NULL, &proc_fops);
	return 0;
}

static void __exit counter_exit(void)
{
	remove_proc_entry("my_counter", NULL);
	pr_info("Counter module unloaded\n");
}

// Loops until zero is returned
static ssize_t counter_read(struct file *file, char __user *buffer, size_t length, loff_t *offset)
{
	if (*offset > 0)
		return 0;

	char counter_string[50];
	unsigned long result;

	snprintf(counter_string, 50, "Counter called %ld times\n", ++counter);
	pr_info("%s", counter_string);
	result = copy_to_user(buffer, counter_string, 50);
	if (result > 0) 
		pr_warn("copy_to_user failed with error code: %lu\n", result);
	

	return (*offset = length);
}

// Loops until non-zero value is returned
static ssize_t counter_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset)
{
	if (length == 0) {
		pr_err("Empty string given\n");
		return 1;
	}

	char counter_string[20];
	unsigned long result;
	result = copy_from_user(counter_string, buffer, length);
	if (result) {
		pr_err("copy_from_user failed with error code: %lu\n", result);
		return 1;
	}
	
	result = kstrtol(counter_string, 10, &counter);
	if (result) {
		pr_err("kstrtol failed with error code: %lu\n", result);
		return 1;
	}
	
	pr_info("Counter reset to %ld\n", counter);

	return length;
}

module_init(counter_init);
module_exit(counter_exit);
