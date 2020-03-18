all: os-image

kernel.o : kernel.c
	gcc --freestanding -m32 -c $< -o $@

kernel.bin : kernel_entry.o kernel.o
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

kernel_entry.o : kernel_entry.asm
	nasm $< -f elf -o $@
os-image: boot_sect.bin kernel.bin
	cat $^ > $@

boot_sect.bin : boot_sect.asm
	nasm $< -f bin -o
clean:
	rm *.o


