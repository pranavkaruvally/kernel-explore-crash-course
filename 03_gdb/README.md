# Debugging with GDB

1. Enable `CONFIG_KGDB` in your kernel configuration (`make menuconfig`).
2. Rebuild the kernel and boot it in QEMU with debugging enabled: `qemu-system-x86_64 -s -S`
3. Connect to the kernel using gdb: `gdb vmlinux`, then `target remote :1234`
4. Set a breakpoint in your kernel module’s init function (e.g., `break hello_init`) and step through its execution.

# References

- On your debugging target, find out the base address of the module; try `sudo grep -e "^your_module" /proc/modules`
- In your gdb session, you can now load in the module by `(gdb) add-symbol-file your_module.ko 0xAddressFromProc`
- [More reference](https://sam4k.com/patching-instrumenting-debugging-linux-kernel-modules/)
