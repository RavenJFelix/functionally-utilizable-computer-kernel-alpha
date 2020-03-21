CSOURCES =$(wildcard kernel/*.c drivers/*.c drivers/*/*.c) 
COBJ := $(CSOURCES:.c=.o)
ASOURCES = $(wildcard kernel/*.s drivers/*.s)
AOBJ = $(filter-out kernel/loader.o, ${ASOURCES:.s=.o})
CINCLUDES = ./include
CC = gcc
CFLAGS = -m32 -ffreestanding -c
LDFLAGS = -melf_i386 -Ttext 0x1000 --oformat binary
AS = nasm
ASFLAGS = -f elf

all : os.iso
boot/loader.o: boot/loader.s
	nasm $< -f elf -o $@

kernel.bin : boot/loader.o $(COBJ) $(AOBJ) 
	$(info $(CSOURCES:.c=.o))
	$(info $(AOBJ))
	ld $(LDFLAGS) boot/loader.o $(COBJ) $(AOBJ) -o $@

os.iso: boot_sect.bin kernel.bin
	cat boot_sect.bin kernel.bin > $@
	
run: os.iso
	#qemu-system-x86_64 $<
	qemu-system-x86_64 -drive format=raw,file=$<

%.o: %.c
	$(CC) $(CFLAGS) -I $(CINCLUDES) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

boot_sect.bin: boot/boot2.asm boot/disk_load.asm
	(cd boot; nasm -f bin boot2.asm -o ../$@)
	
clean:
	rm -rf *.o kernel.elf os.iso
	find . -type f -name '*.o' -delete
