#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/skbuff.h>
#include <linux/dma-mapping.h>

 

#define TX_RING_SIZE 16

 

struct priv {
    struct net_device *dev;
    struct sk_buff *tx_skb[TX_RING_SIZE];
    dma_addr_t tx_dma[TX_RING_SIZE];
    int tx_next;
    void __iomem *mmio_base;
};

 

static int my_open(struct net_device *dev);
static int my_stop(struct net_device *dev);
static netdev_tx_t my_start_xmit(struct sk_buff *skb, struct net_device *dev);

 

static const struct net_device_ops netdev_ops = {
    .ndo_open = my_open,
    .ndo_stop = my_stop,
    .ndo_start_xmit = my_start_xmit,
};

 

static int my_open(struct net_device *dev) {
    netif_start_queue(dev);
    return 0;
}

 

static int my_stop(struct net_device *dev) {
    netif_stop_queue(dev);
    return 0;
}

 

static netdev_tx_t my_start_xmit(struct sk_buff *skb, struct net_device *dev) {
    struct priv *priv = netdev_priv(dev);
    int tx_next = priv->tx_next;

    dma_addr_t dma_addr = dma_map_single(&dev->dev, skb->data, skb->len, DMA_TO_DEVICE);
    if (dma_mapping_error(&dev->dev, dma_addr)) {
        dev_kfree_skb(skb);
        return NETDEV_TX_BUSY;
    }

 

    priv->tx_skb[tx_next] = skb;
    priv->tx_dma[tx_next] = dma_addr;

 

    priv->tx_next = (tx_next + 1) % TX_RING_SIZE;

 

    dev_kfree_skb(skb);
    return NETDEV_TX_OK;
}

 

static void my_setup(struct net_device *dev) {
    ether_setup(dev);
    dev->netdev_ops = &netdev_ops;
}

 

static int __init my_init(void) {
    struct net_device *ndev;
    struct priv *priv;

 

    ndev = alloc_etherdev(sizeof(struct priv));
    if (!ndev)
        return -ENOMEM;

 

    my_setup(ndev);
    priv = netdev_priv(ndev);
    priv->dev = ndev;

 

    if (register_netdev(ndev)) {
        free_netdev(ndev);
        return -ENODEV;
    }

 

    return 0;
}

 

static void __exit my_exit(void) {
    struct priv *priv;
    struct net_device *ndev = priv->dev;

 

    unregister_netdev(ndev);
    free_netdev(ndev);
}

 

module_init(my_init);
module_exit(my_exit);

 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sumayya");
MODULE_DESCRIPTION("Simple Network Driver Example");
