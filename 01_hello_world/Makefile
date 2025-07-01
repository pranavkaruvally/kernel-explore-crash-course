obj-m += hello_world.o

KERNEL_DIRECTORY=/lib/modules/$(shell uname -r)/build

all:
	make -C $(KERNEL_DIRECTORY) M=$(PWD) modules
clean:
	make -C $(KERNEL_DIRECTORY) M=$(PWD) clean
