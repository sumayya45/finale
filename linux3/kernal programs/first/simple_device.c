#include <linux/module.h> 

#include <linux/fs.h> 

#include <linux/uaccess.h> 

 

#define DEVICE_NAME "simple_device" 

#define MSG_BUFFER_LEN 100 

 

static char msg_buffer[MSG_BUFFER_LEN] = "Hello from kernel space!\n"; 

static int major_num; 

 

ssize_t device_read(struct file *filp, char __user *buffer, size_t len, loff_t *offset) { 

    return copy_to_user(buffer, msg_buffer, strlen(msg_buffer)) ? -EFAULT : strlen(msg_buffer); 

} 

 

static struct file_operations fops = { 

    .read = device_read, 

}; 

 

static int __init simple_module_init(void) { 

    major_num = register_chrdev(0, DEVICE_NAME, &fops); 

    if (major_num < 0) { 

        printk(KERN_ALERT "Failed to register a major number\n"); 

        return major_num; 

    } 

    printk(KERN_INFO "Registered device with major number %d\n", major_num); 

    return 0; 

} 

 

static void __exit simple_module_exit(void) { 

    unregister_chrdev(major_num, DEVICE_NAME); 

    printk(KERN_INFO "Unregistered device\n"); 

} 

 

module_init(simple_module_init); 

module_exit(simple_module_exit); 

MODULE_LICENSE("GPL"); 
