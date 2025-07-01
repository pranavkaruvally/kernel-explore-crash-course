#include <linux/init.h>
#include <linux/module.h>

MODULE_AUTHOR("PRANAV P");
MODULE_DESCRIPTION("HELLOWORLD MODULE");
MODULE_LICENSE("GPL 2.0");
MODULE_VERSION("0.1");

static int __init hello_world_init(void)
{
	printk(KERN_INFO "Hello, World!\n");
	return 0;
}

static void __exit hello_world_exit(void)
{
	printk(KERN_INFO "Goodbye, World!\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);
