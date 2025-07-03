# Kernel Thread Creation

1. Write a kernel module that creates a kernel thread using `kthread_run`.
2. Load the module and monitor thread activity via dmesg.
3. Modify the thread to perform a simple task (e.g., increment a counter and expose it via `/proc`).
4. Test thread termination and ensure clean exit.

# References

1. [`kthread_run` prototype](https://elixir.bootlin.com/linux/v6.15.4/source/include/linux/kthread.h#L42)
2. [`kthread_stop` prototype](https://elixir.bootlin.com/linux/v6.15.4/source/kernel/kthread.c#L763)
3. [Kernel Thread - Linux Device Drivers Tutorial](https://embetronicx.com/tutorials/linux/device-drivers/linux-device-drivers-tutorial-kernel-thread/)
