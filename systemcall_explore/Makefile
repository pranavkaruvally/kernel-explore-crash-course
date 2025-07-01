CONFIG_MODULE_SIG=n
obj-m += attach_topid.o

KERNEL_DIRECTORY=/usr/lib/modules/$(shell uname -r)

all:
	make -C $(KERNEL_DIRECTORY)/build M=$(PWD) modules
clean:
	make -C $(KERNEL_DIRECTORY)/build M=$(PWD) clean
