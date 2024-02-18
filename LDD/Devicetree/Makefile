obj-m=extract.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR)  M=`pwd` modules
dt:
	dtc -@ -I dts -O dtb -o my_device.dtbo my_device.dts
clean:
	make -C $(KDIR)  M=`pwd` clean
