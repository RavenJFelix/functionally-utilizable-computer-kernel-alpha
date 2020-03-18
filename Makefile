all: os-image

run: os-image
	qemu-system-x86_64 -drive format=raw,file=$<


kernel.o : kernel.c
	gcc --freestanding -m32 -c $< -o $@

kernel.bin : kernel_entry.o kernel.o
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

kernel_entry.o : kernel_entry.asm
	nasm $< -f elf -o $@

os-image: boot_sect.bin kernel.bin
	cat $^ > $@

boot_sect.bin : boot_sect.asm
	nasm $< -f bin -I "./utils/" -o $@

kernel.dis : kernel.bin
	ndisasm -b 32 $ < > $@

clean:
	rm -rf *.o *.dis *.o os-image *.map


