VERSION = 3
PATCHLEVEL = 4
SUBLEVEL = 0
EXTRAVERSION =
NAME = Saber-toothed Squirrel

obj-m := trasher.o
PWD := $(shell pwd)
default:
	$(MAKE) ARCH=arm CROSS_COMPILE=~/kernel/prebuilt/linux-x86/toolchain/arm-eabi-4.6/bin/arm-eabi- -C ~/F01F/kernel SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) clean
