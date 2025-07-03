obj-m += char_driver.o

CFLAGS="-g -DDEBUG"
KERNEL_DIRECTORY=/usr/lib/modules/$(shell uname -r)

all:
	make CFLAGS=$(CFLAGS) -C $(KERNEL_DIRECTORY)/build M=$(PWD) modules
clean:
	make CFLAGS=$(CFLAGS) -C $(KERNEL_DIRECTORY)/build M=$(PWD) clean
