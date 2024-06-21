#include <linux/init.h> 

#include <linux/module.h> 

#include <linux/kernel.h> 

#include <linux/slab.h> // For kmalloc() and kfree() 

#include <linux/vmalloc.h> // For vmalloc() and vfree() 

 

MODULE_LICENSE("GPL"); 

MODULE_AUTHOR("Your Name"); 

MODULE_DESCRIPTION("A simple kernel module to demonstrate memory allocation."); 

MODULE_VERSION("0.1"); 

 

static char *buffer1; 

static char *buffer2; 

 

static int __init my_module_init(void) { 

    printk(KERN_INFO "my_module: Initializing the module\n"); 

 

    buffer1 = kmalloc(1024, GFP_KERNEL); 

    if (!buffer1) { 

        printk(KERN_ALERT "my_module: kmalloc GFP_KERNEL failed!\n"); 

        return -ENOMEM; 

    } 

    printk(KERN_INFO "my_module: kmalloc GFP_KERNEL succeeded\n"); 

 

    buffer2 = kmalloc(1024, GFP_ATOMIC); 

    if (!buffer2) { 

        printk(KERN_ALERT "my_module: kmalloc GFP_ATOMIC failed!\n"); 

        kfree(buffer1); 

        return -ENOMEM; 

    } 

    printk(KERN_INFO "my_module: kmalloc GFP_ATOMIC succeeded\n"); 

 

    return 0; 

} 

 

static void __exit my_module_exit(void) { 

    printk(KERN_INFO "my_module: Exiting the module\n"); 

 

    if (buffer1) { 

        kfree(buffer1); 

        printk(KERN_INFO "my_module: kfree buffer1 succeeded\n"); 

    } 

 

    if (buffer2) { 

        kfree(buffer2); 

        printk(KERN_INFO "my_module: kfree buffer2 succeeded\n"); 

    } 

} 

 

module_init(my_module_init); 

module_exit(my_module_exit);
