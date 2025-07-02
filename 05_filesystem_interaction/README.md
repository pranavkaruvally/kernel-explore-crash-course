# File System Interaction

1. Create a kernel module that registers a `/proc` file to display custom data (e.g., a counter incremented on each read).
2. Load the module and read the file (`cat /proc/my_counter`). 
3. Modify the module to allow writing to the `/proc` file to update the counter.

# References
- [Linux Device Driver Tutorial Part 9 – Procfs in Linux](https://embetronicx.com/tutorials/linux/device-drivers/procfs-in-linux/)
