#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/hid.h>

static int plug_in(struct usb_interface *interface, const struct usb_device_id *id)
{
  //printk(KERN_DEBUG "Good morning ve482!\n");
  return 0;
}

static void plug_out(struct usb_interface *interface)
{
  //printk(KERN_DEBUG "Goodbye ve482.\n");
}

static const struct usb_device_id id_table[] = {
    {USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT, USB_INTERFACE_PROTOCOL_KEYBOARD)},
    {},
};

MODULE_DEVICE_TABLE(usb, id_table);

static struct usb_driver usb_driver = {
    .name = "new-usb",
    .probe = plug_in,
    .disconnect = plug_out,
    .id_table = id_table,
};

static int __init mod_init(void)
{
  printk(KERN_DEBUG "Good morning ve482!\n");
  return usb_register(&usb_driver);
}

static void __exit mod_exit(void)
{
  printk(KERN_DEBUG "Goodbye ve482.\n");
  usb_deregister(&usb_driver);
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
