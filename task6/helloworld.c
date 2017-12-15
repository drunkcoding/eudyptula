#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/errno.h>

#define MESG "ve482hobby!\n"
#define MESG_LEN 12

static ssize_t dev_read(struct file *file, char __user *buf, size_t len, loff_t *offset)
{
	return simple_read_from_buffer(buf, len, offset, MESG, MESG_LEN);
}

static ssize_t dev_write(struct file *file, char const __user *buf, size_t len, loff_t *offset)
{
	char *msg_promt = MESG;
	char input[MESG_LEN];
	if ((len != MESG_LEN - 1) ||
		(copy_from_user(input, buf, MESG_LEN)) ||
		(strncmp(msg_promt, input, MESG_LEN - 2)))
		return -EINVAL;
	else
		return len;
}

static const struct file_operations chrdev_fops = {
	.owner = THIS_MODULE,
	.read = dev_read,
	.write = dev_write};

static struct miscdevice chr_dev = {
	MISC_DYNAMIC_MINOR,
	"hobby",
	&chrdev_fops};

static int __init mod_init(void)
{
	printk(KERN_DEBUG "Good morning ve482!\n");
	return misc_register(&chr_dev);
	;
}

static void __exit mod_exit(void)
{
	printk(KERN_DEBUG "Goodbye ve482.\n");
	misc_deregister(&chr_dev);
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
