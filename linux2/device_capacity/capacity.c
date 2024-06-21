#include <linux/module.h>

#include <linux/fs.h>

#include <linux/blkdev.h>

#include <linux/hdreg.h>

#include <linux/bio.h>

#include <linux/vmalloc.h>

#include <linux/genhd.h>

#define DEVICE_NAME "my_block"

#define DEVICE_CAPACITY 1024 // Capacity in sectors (512 bytes per sector)

static int major_num = 0;

static struct request_queue *queue;

static unsigned char *dev_data;

struct my_block_device {

    struct request_queue *queue;

    unsigned char *data;

    unsigned capacity;

    spinlock_t lock;

};

static struct my_block_device mybdev;

static int my_open(struct block_device *bdev, fmode_t mode) {

    pr_info(DEVICE_NAME ": Device opened\n");

    return 0;

}

static void my_release(struct block_device *bdev, fmode_t mode) {

    pr_info(DEVICE_NAME ": Device closed\n");

}

static int my_ioctl(struct block_device *bdev, fmode_t mode, unsigned cmd, unsigned long arg) {

    return -ENOTTY; // No ioctls supported

}

static struct block_device_operations fops = {

    .owner = THIS_MODULE,

    .open = my_open,

    .release = my_release,

    .ioctl = my_ioctl

};

static void my_request(struct request_queue *q) {

    struct request *req;

    while ((req = blk_fetch_request(q)) != NULL) {

        struct bio_vec bvec;

        struct req_iterator iter;

        sector_t pos = blk_rq_pos(req);

        void *disk_mem = dev_data + pos * 512;

        rq_for_each_segment(bvec, req, iter) {

            unsigned long len = bvec.bv_len;

            void *buffer = page_address(bvec.bv_page) + bvec.bv_offset;

            if (rq_data_dir(req) == READ) {

                memcpy(buffer, disk_mem, len);

            } else {

                memcpy(disk_mem, buffer, len);

            }

            disk_mem += len;

        }

        __blk_end_request_all(req, 0);

    }

}

static int __init my_init(void) {

    major_num = register_blkdev(0, DEVICE_NAME);

    if (major_num <= 0) {

        pr_err(DEVICE_NAME ": register_blkdev failed\n");

        return -EBUSY;

    }

    queue = blk_init_queue(my_request, &mybdev.lock);

    if (!queue) {

        unregister_blkdev(major_num, DEVICE_NAME);

        pr_err(DEVICE_NAME ": blk_init_queue failed\n");

        return -ENOMEM;

    }

    dev_data = vmalloc(DEVICE_CAPACITY * 512);

    if (!dev_data) {

        blk_cleanup_queue(queue);

        unregister_blkdev(major_num, DEVICE_NAME);

        pr_err(DEVICE_NAME ": vmalloc failed\n");

        return -ENOMEM;

    }

    mybdev.queue = queue;

    mybdev.data = dev_data;

    mybdev.capacity = DEVICE_CAPACITY;

    spin_lock_init(&mybdev.lock);

    pr_info(DEVICE_NAME ": Module loaded\n");

    return 0;

}

static void __exit my_exit(void) {

    blk_cleanup_queue(queue);

    unregister_blkdev(major_num, DEVICE_NAME);

    vfree(dev_data);

    pr_info(DEVICE_NAME ": Module unloaded\n");

}

module_init(my_init);

module_exit(my_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR("Your Name");

MODULE_DESCRIPTION("A simple block device driver");
