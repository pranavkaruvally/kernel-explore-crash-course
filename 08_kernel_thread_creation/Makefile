obj-m += run_kthread.o

KERNEL_DIRECTORY=/usr/lib/modules/$(shell uname -r)

all:
	make -C $(KERNEL_DIRECTORY)/build M=$(PWD) modules
clean:
	make -C $(KERNEL_DIRECTORY)/build M=$(PWD) clean
