# Character Device Driver

1. Write a kernel module that registers a character device using `register_chrdev`.
2. Compile and load the module. Create a device file: `sudo mknod /dev/my_device c <major> 0`.
3. Test by writing to and reading from the device: `echo "Test" > /dev/my_device`, `cat /dev/my_device`.
4. Check `dmesg` for logs and handle any errors

# References

- [`register_dev` prototype](https://elixir.bootlin.com/linux/v6.15.4/source/include/linux/fs.h#L2927)
- [`struct file_operations` definition](https://elixir.bootlin.com/linux/v6.15.4/source/include/linux/fs.h#L2129)
- [`unregister_chrdev` definition](https://elixir.bootlin.com/linux/v6.15.4/source/include/linux/fs.h#L2933)
