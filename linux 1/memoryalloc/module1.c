#include <linux/init.h> 

#include <linux/module.h> 

#include <linux/kernel.h> 

#include <linux/slab.h> // For kmem_cache_create() and kmem_cache_alloc() 

#include <linux/vmalloc.h> // For vmalloc() and vfree() 

 

MODULE_LICENSE("GPL"); 

MODULE_AUTHOR("Your Name"); 

MODULE_DESCRIPTION("A kernel module to demonstrate high memory and memory pool API."); 

MODULE_VERSION("0.1"); 

 

struct my_struct { 

    int data; 

    char name[50]; 

}; 

 

static struct kmem_cache *my_cache; 

static struct my_struct *cache_object; 

static char *vbuffer; 

 

static int __init my_module_init(void) { 

    printk(KERN_INFO "my_module: Initializing the module\n"); 

 

    vbuffer = vmalloc(1024 * 1024); // Allocate 1MB 

    if (!vbuffer) { 

        printk(KERN_ALERT "my_module: vmalloc failed!\n"); 

        return -ENOMEM; 

    } 

    printk(KERN_INFO "my_module: vmalloc succeeded\n"); 

 

    my_cache = kmem_cache_create("my_cache", sizeof(struct my_struct), 0, SLAB_HWCACHE_ALIGN, NULL); 

    if (!my_cache) { 

        printk(KERN_ALERT "my_module: kmem_cache_create failed!\n"); 

        vfree(vbuffer); 

        return -ENOMEM; 

    } 

    printk(KERN_INFO "my_module: kmem_cache_create succeeded\n"); 

 

    cache_object = kmem_cache_alloc(my_cache, GFP_KERNEL); 

    if (!cache_object) { 

        printk(KERN_ALERT "my_module: kmem_cache_alloc failed!\n"); 

        kmem_cache_destroy(my_cache); 

        vfree(vbuffer); 

        return -ENOMEM; 

    } 

    printk(KERN_INFO "my_module: kmem_cache_alloc succeeded\n"); 

 

    cache_object->data = 123; 

    snprintf(cache_object->name, 50, "Example"); 

 

    printk(KERN_INFO "my_module: Object created: data=%d, name=%s\n", cache_object->data, cache_object->name); 

 

    return 0; 

} 

 

static void __exit my_module_exit(void) { 

    printk(KERN_INFO "my_module: Exiting the module\n"); 

 

    if (cache_object) { 

        kmem_cache_free(my_cache, cache_object); 

        printk(KERN_INFO "my_module: kmem_cache_free succeeded\n"); 

    } 

 

    if (my_cache) { 

        kmem_cache_destroy(my_cache); 

        printk(KERN_INFO "my_module: kmem_cache_destroy succeeded\n"); 

    } 

 

    if (vbuffer) { 

        vfree(vbuffer); 

        printk(KERN_INFO "my_module: vfree succeeded\n"); 

    } 

} 

 

module_init(my_module_init); 

module_exit(my_module_exit); 

 
