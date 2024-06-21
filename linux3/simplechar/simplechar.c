#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simple_char_dev"
#define BUFFER_SIZE 1024

static int major_number;
static char message[BUFFER_SIZE] = {0};
static short message_size;
static int number_opens = 0;

static int dev_open(struct inode *inodep, struct file *filep) {
    number_opens++;
    printk(KERN_INFO "simple_char_dev: Device has been opened %d time(s)\n", number_opens);
    return 0;
}

static int dev_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "simple_char_dev: Device successfully closed\n");
    return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    int error_count = 0;

    if (*offset >= message_size) {
        return 0; // End of buffer
    }

    if (*offset + len > message_size) {
        len = message_size - *offset;
    }

    error_count = copy_to_user(buffer, message + *offset, len);

    if (error_count == 0) {
        *offset += len;
        printk(KERN_INFO "simple_char_dev: Sent %zu characters to the user\n", len);
        return len;
    } else {
        printk(KERN_INFO "simple_char_dev: Failed to send %d characters to the user\n", error_count);
        return -EFAULT; // Failed -- return a bad address message
    }
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    if (len > BUFFER_SIZE - 1) {
        len = BUFFER_SIZE - 1;
    }

    if (copy_from_user(message, buffer, len)) {
        return -EFAULT;
    }

    message[len] = '\0';
    message_size = strlen(message);
    printk(KERN_INFO "simple_char_dev: Received %zu characters from the user\n", len);
    return len;
}

static struct file_operations fops = {
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .release = dev_release,
};

static int __init simple_char_driver_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "simple_char_dev failed to register a major number\n");
        return major_number;
    }

    printk(KERN_INFO "simple_char_dev: registered correctly with major number %d\n", major_number);
    return 0;
}

static void __exit simple_char_driver_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "simple_char_dev: unregistered correctly\n");
}

module_init(simple_char_driver_init);
module_exit(simple_char_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux char driver");
MODULE_VERSION("0.1");
