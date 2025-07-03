#define pr_fmt(fmt) "char_driver: " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

MODULE_AUTHOR("PRANAV P");
MODULE_DESCRIPTION("CHARACTER DEVICE DRIVER");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

ssize_t char_driver_read(struct file *, char __user *, size_t, loff_t *);
ssize_t char_driver_write(struct file *, const char __user *, size_t, loff_t *);

static unsigned int major_number = 265;
static struct file_operations fops = {
	.read = char_driver_read,
	.write = char_driver_write
};

static int __init char_driver_init(void)
{
	int result;
	pr_info("Driver loaded\n");
	if ((result = register_chrdev(major_number, "my_device", &fops))) {
			pr_err("register_chrdev failed with error %d\n",
					result);
			return -1;
	}
	return 0;
}

static void __exit char_driver_exit(void)
{
	unregister_chrdev(major_number, "my_device");
	pr_info("Driver unloaded\n");
}

ssize_t char_driver_read(struct file *file, char __user *buffer,
		size_t len, loff_t *offset)
{
	if (*offset > 0) return 0;

	char *message = "my_device: read initiated\n";
	unsigned long result;

	pr_info("%s", message);
	if ((result = copy_to_user(buffer, message, strlen(message)))) {
		pr_err("copy_to_user failed with err: %lu\n", result);
		return -1;
	}
	*offset = len;
	return len;
}

ssize_t char_driver_write(struct file *file, const char __user *buffer,
		size_t len, loff_t *offset)
{
	if (!len) return -1;
	pr_info("my_device: write initiated\n");
	return len;
}

module_init(char_driver_init);
module_exit(char_driver_exit);
