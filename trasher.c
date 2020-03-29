/*
 * trasher.c
 *
 * Copyright (C) 2020 dadreamer
 *
 * This is the fjsec LSM disabler for Fujitsu Arrows NX F-01F,
 * Android 4.4.2, build # V10R22A (kernel version 3.4.0)
 */

#include <linux/module.h> /* Needed by all modules */
#include <linux/device.h> /* Needed for KERN_ALERT */
#include <linux/kallsyms.h>

static int __init trasher_init(void)
{
    printk(KERN_INFO "trasher is loaded...\n");

    //writing to fjsec_security_ops doesn't work for some reason
    //mem_text_write_kernel_word(0xC0A2DB98, 0xc0370e44); <- not work

    //so patching each func separately
    mem_text_write_kernel_word(0xC0372198, 0xe3a00000); //fjsec_ptrace_traceme
    mem_text_write_kernel_word(0xC03720FC, 0xe3a00000); //fjsec_ptrace_request_check
    mem_text_write_kernel_word(0xC0373F7C, 0xe3a00000); //fjsec_bprm_set_creds
    mem_text_write_kernel_word(0xC03743B8, 0xe3a00000); //fjsec_sb_mount
    mem_text_write_kernel_word(0xC03745EC, 0xe3a00000); //fjsec_sb_umount
    mem_text_write_kernel_word(0xC0374844, 0xe3a00000); //fjsec_sb_pivotroot
    mem_text_write_kernel_word(0xC0375F70, 0xe3a00000); //fjsec_path_unlink
    mem_text_write_kernel_word(0xC0374B74, 0xe3a00000); //fjsec_path_mkdir
    mem_text_write_kernel_word(0xC0374B38, 0xe3a00000); //fjsec_path_rmdir
    mem_text_write_kernel_word(0xC0375CDC, 0xe3a00000); //fjsec_path_mknod
    mem_text_write_kernel_word(0xC0374AFC, 0xe3a00000); //fjsec_path_truncate
    mem_text_write_kernel_word(0xC0375994, 0xe3a00000); //fjsec_path_symlink
    mem_text_write_kernel_word(0xC03757A0, 0xe3a00000); //fjsec_path_link
    mem_text_write_kernel_word(0xC03754D4, 0xe3a00000); //fjsec_path_rename
    mem_text_write_kernel_word(0xC03751BC, 0xe3a00000); //fjsec_path_chmod
    mem_text_write_kernel_word(0xC0374EA0, 0xe3a00000); //fjsec_path_chown
    mem_text_write_kernel_word(0xC0376180, 0xe3a00000); //fjsec_path_chroot
    mem_text_write_kernel_word(0xC0376778, 0xe3a00000); //fjsec_file_permission
    mem_text_write_kernel_word(0xC0373A34, 0xe3a00000); //fjsec_file_mmap
    mem_text_write_kernel_word(0xC0372838, 0xe3a00000); //fjsec_remap_pfn_range
    mem_text_write_kernel_word(0xC03727E4, 0xe3a00000); //fjsec_ioremap_page_range
    mem_text_write_kernel_word(0xC0372780, 0xe3a00000); //fjsec_insert_page
    mem_text_write_kernel_word(0xC0372714, 0xe3a00000); //fjsec_insert_pfn
    //fjsec_file_mprotect doesn't need a patch, because it's empty: MOV R0, #0; BX LR
    mem_text_write_kernel_word(0xC0376ABC, 0xe3a00000); //fjsec_dentry_open
    //fjsec_init_module doesn't need a patch, because it's just an info func
    mem_text_write_kernel_word(0xC037185C, 0xe3a00000); //fjsec_kernel_load_module
    //fjsec_kernel_delete_module doesn't need a patch, because it's just an info func
    mem_text_write_kernel_word(0xC0373424, 0xe3a00000); //fjsec_task_fix_setuid
    mem_text_write_kernel_word(0xC03733D8, 0xe3a00000); //fjsec_task_fix_setgid

    //likely not needed, but set it anyways
    mem_text_write_kernel_word(0xC0374AA8, 0xe3a00000); //fjsec_check_path_from_path

    printk(KERN_INFO "trasher: the cleaning is done.\n");
    printk(KERN_INFO "trasher: all your phone belongs to you.\n");

    // A non 0 return means init_module failed; module can't be loaded.
    return 0;
}

static void __exit trasher_exit(void)
{
    printk(KERN_INFO "trasher is unloaded.\n");
}

MODULE_DESCRIPTION("Fjsec LSM disabler");
MODULE_AUTHOR("dadreamer");
MODULE_LICENSE("GPL");

module_init(trasher_init);
module_exit(trasher_exit);
