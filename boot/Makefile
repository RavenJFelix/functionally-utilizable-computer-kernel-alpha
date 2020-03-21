boot_sect.bin : boot2.asm disk_load.asm
	nasm -f bin $< -o $@

testkernel.o : testkernel.c
	gcc -m32 -ffreestanding -c $< -o $@

loader.o : loader.s
	nasm $< -f elf -o $@

testkernel.bin : loader.o testkernel.o
	ld -o $@ -melf_i386 -Ttext 0x1000 $^ --oformat binary

os-image : boot_sect.bin testkernel.bin blank.img
	cat $^> $@


run: os-image
	qemu-system-x86_64 os-image
