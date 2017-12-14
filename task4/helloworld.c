#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int hello_init(void)
{
  printk(KERN_DEBUG "Hello World!\n");
  return 0;
}

static void hello_exit(void)
{
  printk(KERN_DEBUG "Exit Hello.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GNU");
