obj-m += test_module.o
obj-m += test_module_2.o
obj-m += chardev.o

all :
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean :
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	
