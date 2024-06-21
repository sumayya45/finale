#include <linux/kernel.h> 
#include <linux/init.h> 
#include <linux/module.h> 



 


 

static int __init my_module_init(void) { 

    printk(KERN_INFO "my_module: Initializing the module\n"); 

    return 0; 

} 

 

static void __exit my_module_exit(void) { 

    printk(KERN_INFO "my_module: Exiting the module\n"); 

} 

 

module_init(my_module_init); 

module_exit(my_module_exit); 

MODULE_LICENSE("GPL"); 

MODULE_AUTHOR("sumi"); 

MODULE_DESCRIPTION("A simple kernel module to demonstrate memory allocation."); 

MODULE_VERSION("0.1"); 
