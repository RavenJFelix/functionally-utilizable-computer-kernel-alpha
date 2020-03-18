C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers*.h)
OBJ = ${C_SOURCES:.c=.o}

all: os-image


run: os-image
	qemu-system-x86_64 -drive format=raw,file=$<


kernel.o : kernel.c
	gcc --freestanding -m32 -c $< -o $@

kernel.bin : kernel/kernel_entry.o ${OBJ}
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

os-image: boot_sect.bin kernel.bin
	cat $^ > $@

boot_sect.bin : boot/boot_sect.asm
	nasm $< -f bin -I "./utils/" -o $@

%.o : %.c
	gcc -ffreestanding -m32 -c $< -o $@


%.o : %.asm
	nasm $< -f elf -o $@

%.bin : %.asm
	nasm $< -f bin -I "./utils" -o $@
kernel.dis : kernel.bin
	ndisasm -b 32 $ < > $@

clean:
	rm -rf *.o *.dis *.o os-image *.map
	rm -rf kernel/*.o boot/*.bin drivers/*.o


