#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

int myinit(void)
{
	printk("\nHello world form kernel module\n");
	return 0;
}

void myexit(void)
{
	printk("\nbye bye from kernel kernel\n");
}

module_init(myinit);
module_exit(myexit);

MODULE_LICENSE("Dual MIT/GPL");

