CSOURCES =$(wildcard kernel/*.c drivers/*.c */*/*.c) 
COBJ := $(CSOURCES:.c=.o)
ASOURCES = $(wildcard kernel/*.s drivers/*.s)
AOBJ = $(filter-out kernel/loader.o, ${ASOURCES:.s=.o})
CINCLUDES = include
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
		 -nostartfiles -nodefaultlibs -Wall -Wextra -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all : kernel.elf

kernel.elf : kernel/loader.o $(COBJ) $(AOBJ) 
	$(info $(CSOURCES:.c=.o))
	ld $(LDFLAGS) kernel/loader.o $(COBJ) $(AOBJ) -o $@

os.iso: kernel.elf
	cp $< iso/boot/$<
	genisoimage -R \
		-b boot/grub/stage2_eltorito \
		-no-emul-boot \
		-boot-load-size 4 \
		-A os \
		-input-charset utf8 \
		-quiet \
		-boot-info-table \
		-o os.iso \
		iso
run: os.iso
	bochs -f bochsrc.txt -q

%.o: %.c
	$(CC) $(CFLAGS) -I $(CINCLUDES) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf os.iso
	find . -type f -name '*.o' -delete
