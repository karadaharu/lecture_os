/*
 * Demonstrating the module_init() and module_exit() macros.
 * This is preferred over using init_module() and cleanup_module().
 */
#include <linux/module.h> /* needed by all modules*/
#include <linux/kernel.h> /*needed for kern_info*/
#include <linux/init.h> /*needed for the macros*/

static int hello3_data __initdata = 3;

static int __init hello_2_init(void)
{
	printk(KERN_INFO "Hello, world %d\n", hello3_data);
	return 0;
}

static void __exit hello_2_exit(void)
{
	printk(KERN_INFO "Goodbye, world 2\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);