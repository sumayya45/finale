#include <linux/init.h> 

#include <linux/module.h> 

#include <linux/kernel.h> 

#include <linux/vmalloc.h> // For vmalloc() and vfree() 

 

MODULE_LICENSE("GPL"); 

MODULE_AUTHOR("Your Name"); 

MODULE_DESCRIPTION("A simple kernel module to demonstrate memory allocation."); 

MODULE_VERSION("0.1"); 

 

static char *vbuffer; 

 

static int __init my_module_init(void) { 

    printk(KERN_INFO "my_module: Initializing the module\n"); 

 

    vbuffer = vmalloc(1024 * 1024); // Allocate 1MB 

    if (!vbuffer) { 

        printk(KERN_ALERT "my_module: vmalloc failed!\n"); 

        return -ENOMEM; 

    } 

    printk(KERN_INFO "my_module: vmalloc succeeded\n"); 

    return 0; 

} 

 

static void __exit my_module_exit(void) { 

    printk(KERN_INFO "my_module: Exiting the module\n"); 

 

    if (vbuffer) { 

        vfree(vbuffer); 

        printk(KERN_INFO "my_module: vfree succeeded\n"); 

    } 

} 

 

module_init(my_module_init); 

module_exit(my_module_exit); 
