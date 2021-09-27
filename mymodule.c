#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void)
{
	printk("\nHello world form kernel module\n");
	return 0;
}

void cleanup_module(void)
{
	printk("\nbye bye from kernel kernel\n");
}

MODULE_LICENSE("Dual MIT/GPL");

