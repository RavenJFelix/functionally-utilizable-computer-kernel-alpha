CSOURCES =$(wildcard kernel/*.c drivers/*.c drivers/*/*.c) 
COBJ := $(CSOURCES:.c=.o)
ASOURCES = $(wildcard kernel/*.s drivers/*.s)
AOBJ = $(filter-out boot/boot.o, ${ASOURCES:.s=.o})
HEADERS = $(wildcard *.h */*.h */*/*.h */*/*/*.h */*/*/*/*.h)
CINCLUDES = ./include
CC = i686-elf-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -melf_i386 -Ttext 0x1000 --oformat binary -T link.ld
AS = nasm
ASFLAGS = -felf32
LINKER = i686-elf-ld
LFLAGS = -T linker.ld  -O2 -nostdlib 

all : os.iso
boot/boot.o: boot/boot.s
	nasm $< $(ASFLAGS) -o $@

kernel.bin : boot/boot.o $(COBJ) $(AOBJ) 
	$(info $(CSOURCES:.c=.o))
	$(info $(AOBJ))
	$(LINKER) -o $@ $(LFLAGS) boot/boot.o $(COBJ) $(AOBJ)

os.iso: boot_sect.bin kernel.bin
	mkdir -p iso/boot/grub
	mv kernel.bin iso/boot/
	cp grub.cfg iso/boot/grub
	grub2-mkrescue -o $@ iso/
	
run: os.iso
	#qemu-system-x86_64 $<
	qemu-system-x86_64 -drive format=raw,file=$<

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -I $(CINCLUDES) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

boot_sect.bin: boot/boot2.asm boot/disk_load.asm
	(cd boot; nasm -f bin boot2.asm -o ../$@)
	
clean:
	rm -rf *.o kernel.elf os.iso kernel.bin
	find . -type f -name '*.o' -delete
