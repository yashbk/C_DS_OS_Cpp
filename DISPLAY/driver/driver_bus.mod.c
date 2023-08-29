#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xfe990052, "gpio_free" },
	{ 0x8196066c, "i2c_del_adapter" },
	{ 0x92997ed8, "_printk" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
	{ 0x5e9e3342, "gpio_to_desc" },
	{ 0x15ac2962, "gpiod_direction_input" },
	{ 0x532543ff, "gpiod_get_raw_value" },
	{ 0x85f2e527, "gpiod_direction_output_raw" },
	{ 0x74cb8fc9, "gpiod_set_raw_value" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x110a017d, "i2c_bit_add_numbered_bus" },
	{ 0xc84d16dc, "module_layout" },
};

MODULE_INFO(depends, "i2c-algo-bit");


MODULE_INFO(srcversion, "C09E39530A60BF6B60C7A40");
