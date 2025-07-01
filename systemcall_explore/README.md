# System Call Exploration

1. Write a user-space program that uses the `getpid()` system call and trace its execution using `strace` (`strace -o trace.log ./program`).
2. Locate the `getpid` system call implementation in the kernel source (`kernel/sys.c`)
3. Modify the `hello_world` kernel module to hook into a simple system call (e.g., print a message when `getpid` is called, using a basic kernel tracing mechanism like `ftrace` or a custom wrapper if comfortable).
4. Rebuild and test the modified kernel in QEMU


# Reference

- syscall name for `getpid` to be used in `ftrace_set_filter` was found through `cat /sys/kernel/debug/tracing/available_filter_functions | grep getpid`
- Refer this [website](https://nixhacker.com/hooking-syscalls-in-linux-using-ftrace/) to check on hooking-syscalls-in-linux-using-ftrace
- `__attribute__((unused))`: This attribute, attached to a function, means that the function is meant to be possibly unused. GCC does not produce a warning for this function. 
- The main entry point for `xyzzy(2)` system call will be called `sys_xyzzy()`, but you add this entry point with the appropriate `SYSCALL_DEFINEn()` macro rather than explicitly. The ‘n’ indicates the number of arguments to the system call, and the macro takes the system call name followed by the `(type, name)` pairs for the parameters as arguments. ([reference](https://www.kernel.org/doc/html/latest/process/adding-syscalls.html))
- RCU: [What is RCU?](https://docs.kernel.org/RCU/whatisRCU.html)
