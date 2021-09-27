#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int itemp = 99;			
static char* cpString = "default";

module_param(itemp, int, 0); /* name, type, associated file permition */
MODULE_PARM_DESC(itemp, "Integer"); /* name, description for modinfo */

module_param(cpString, charp, 0);
MODULE_PARM_DESC (cpString, "String");

int myinit(void)
{
	printk("\nHello world form kernel module\n");
	printk("\nmyinit::itemp = %d\n",itemp);
	printk("\nmyinit::cpString = %s\n",cpString);
	return 0;
}

void moduleBodyFn(void)
{
        printk("\nhii from kernel module body\n");
	printk("\nmoduleBodyFn::itemp = %d\n",itemp);
	printk("\nmoduleBodyFn::cpString = %s\n",cpString);
}

void myexit(void)
{
	moduleBodyFn();
	printk("\nmyexit::itemp = %d\n",itemp);
	printk("\nmyexit::cpString = %s\n",cpString);
	printk("\nbye bye from kernel module\n");
}

module_init(myinit);
module_exit(myexit);

MODULE_LICENSE("Dual MIT/GPL");
MODULE_AUTHOR ("chai.bpt@gmail.com");
MODULE_DESCRIPTION ("study");

