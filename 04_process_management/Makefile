obj-m += my_ps.o

KERNEL_DIRECTORY=/usr/lib/modules/$(shell uname -r)
CFLAGS="-g -DDEBUG"

all:
	make CFLAGS=$(CFLAGS) -C $(KERNEL_DIRECTORY)/build M=$(PWD) modules
clean:
	make CFLAGS=$(CFLAGS) -C $(KERNEL_DIRECTORY)/build M=$(PWD) clean
