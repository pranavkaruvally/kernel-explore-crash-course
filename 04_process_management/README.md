# Process Management

1. Write a kernel module that lists all running processes by iterating over the `task_struct` linked list (use `for_each_process` macro in `<linux/sched.h>`).
2. Load the module and verify output in `dmesg`. Compare with `ps` command output.
3. Modify the module to filter processes by state (e.g., `TASK_RUNNING`).
