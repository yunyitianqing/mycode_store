//#include<init.h>
#include<libyasm/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
	printk(KERN_ALERT "hello");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "bye");
}

module_init(hello_init);
module_exit(hello_exit);
