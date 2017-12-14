#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int mod_init(void)
{
  printk(KERN_DEBUG "Good morning ve482!\n");
  return 0;
}

static void mod_exit(void)
{
  printk(KERN_DEBUG "Goodbye ve482.\n");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GNU");
