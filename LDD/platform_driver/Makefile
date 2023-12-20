obj-m=pcd_device_setup.o pcd_platform_driver.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR)  M=`pwd` modules
clean:
	make -C $(KDIR)  M=`pwd` clean
