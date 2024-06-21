#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int value,arr_value[4];
char *name;
int cb_value=0;

module_param(value,int,S_IRUSR|S_IWUSR);
module_param(name,charp,S_IRUSR|S_IWUSR);
module_param_array(arr_value,int,NULL,S_IRUSR|S_IWUSR);

static int __init entering(void)
{
	int i;
	printk(KERN_INFO "VALUE =%d \n",value);
	printk(KERN_INFO "name =%s \n",name);
	for(i=0;i<(sizeof arr_value / sizeof(int)); i++)
	{
		printk(KERN_INFO "arr_value[%d] =%d\n",i,arr_value[i]);
	}
	printk(KERN_INFO "MODULE SIUCCESFULLY INSERTED");
	return 0;
}

static void __exit exiting(void)
{
	printk(KERN_INFO "MODULE SIUCCESFULLY remocved");	
}

module_init(entering);
module_exit(exiting);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("SUMAYYA");
MODULE_DESCRIPTION("THIS IS A PARAMETERS PASSINGS");













