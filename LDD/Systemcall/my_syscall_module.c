// my_syscall_module.c
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/kallsyms.h>

asmlinkage long my_syscall(void) {
    printk(KERN_INFO "My custom system call executed\n");
    // Your custom functionality here
    return 0; // Return value as an example
}

static void **syscall_table;

#define __NR_my_syscall 333 // Adjust this based on your system call number

// Function to set a new system call in the syscall table
static void set_system_call(int syscall_num, void *new_syscall) {
    write_cr0(read_cr0() & (~0x10000)); // Disable write protection on the page
    syscall_table[syscall_num] = new_syscall;
    write_cr0(read_cr0() | 0x10000); // Enable write protection back
}

static int __init my_syscall_init(void) {
    // Find the address of the syscall table
    syscall_table = (void **)kallsyms_lookup_name("sys_call_table");

    if (!syscall_table) {
        printk(KERN_ERR "Failed to find the syscall table address\n");
        return -1;
    }

    // Register the new system call
    set_system_call(__NR_my_syscall, my_syscall);

    printk(KERN_INFO "My system call module loaded\n");
    return 0;
}

static void __exit my_syscall_exit(void) {
    printk(KERN_INFO "My system call module unloaded\n");
}

module_init(my_syscall_init);
module_exit(my_syscall_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Custom System Call Module");

