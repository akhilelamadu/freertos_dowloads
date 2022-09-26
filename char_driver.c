#include<linux/init.h>

#include<linux/kernel.h>

#include<linux/module.h>

#include<linux/fs.h>





int ch_open(struct inode *pinode,struct file *pfile)

{

	printk(KERN_ALERT "Inside the open Function\n");

	return 0;

}



int ch_close(struct inode *pinode,struct file *pfile)

{

        printk(KERN_ALERT "Inside the Close  Function\n");

	return 0;

}





ssize_t ch_read(struct file *pfile, char __user *buffer,size_t length,loff_t *offset)

{

     printk(KERN_ALERT "Inside Read Function\n");

     return 0;

 }



ssize_t ch_write(struct file *pfile,const  char __user *buffer,size_t length,loff_t *offset)

{

     printk(KERN_ALERT "Inside Write Function\n");

     return 0;

 }



struct file_operations ch_module_file_operations =

{



	.owner = THIS_MODULE,

	.open  = ch_open,

	.read  = ch_read,

	.release = ch_close,



};



int ch_module_init(void)

{

	printk(KERN_ALERT "Inside the Init Function\n");

	register_chrdev(152,"Simple Char Driver", & ch_module_file_operations);

	return 0;

}



void ch_module_exit(void)

{

        printk(KERN_ALERT "Inside the Exit Function\n");

       unregister_chrdev(152,"Simple Char Driver");



}





module_init(ch_module_init);

module_exit(ch_module_exit);



MODULE_LICENSE("GPL");

MODULE_AUTHOR("GAGAN");

MODULE_INFO(test,"A CHAR Module");
