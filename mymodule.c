#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int itemp = 99;			

module_param(itemp, int, 0); /* name, type, associated file permition */
MODULE_PARM_DESC(itemp, "Integer"); /* name, description for modinfo */

int myinit(void)
{
	printk("\nHello world form kernel module\n");
	return 0;
}

void moduleBodyFn(void)
{
        printk("\nhii from kernel module body\n");
}

void myexit(void)
{
	moduleBodyFn();
	printk("\nbye bye from kernel module\n");
}

module_init(myinit);
module_exit(myexit);

MODULE_LICENSE("Dual MIT/GPL");
MODULE_AUTHOR ("chai.bpt@gmail.com");
MODULE_DESCRIPTION ("study");

