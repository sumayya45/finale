#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

static int __init entering(void)
{
	printk(KERN_INFO "welcome sumayya\n");
	printk(KERN_INFO "this is simple kernal module\n");
	printk(KERN_INFO "kernal module executed succesfully\n");
	return 0;
}
static void __exit exiting(void){
printk(KERN_INFO "kernal module removed succesfully");
}
module_init(entering);
module_exit(exiting);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SUMAYYA");
MODULE_DESCRIPTION("THIS IS JUST A BASIC KERNAL INTRO PROGRAM");

