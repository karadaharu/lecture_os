#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kazumasa Kaneko");

static short int myshort = 1;
/* static int myint = 420; */
/* static long int mylogn = 9999; */
/* static char *mystring = "blah"; */
/* static int myintArray[2] = { -1, -1 }; */
/* static int arr_argc = 0; */

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort , "A short integer");

static int __init init_hello_5(void)
{
  printk(KERN_INFO "Hello, world4\n ========== \n");
  printk(KERN_INFO "myshort is a short integer: %hd\n", myshort);
  return 0;
}

static void __exit cleanup_hello_5(void)
{
  printk(KERN_INFO "Goodbye, world5\n");
}

module_init(init_hello_5);
module_exit(cleanup_hello_5);
