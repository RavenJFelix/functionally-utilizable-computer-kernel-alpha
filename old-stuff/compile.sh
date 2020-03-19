#!/bin/sh
nasm -f bin boot_sect.asm -o boot_sect.bin
gcc -ffreestanding -c kernel.c -o kernel.o
ld -o kernel.bin -Ttext 0x1000 kernel.o --oformat binary
cat boot_sect.bin kernel.bin > os-image
qemu-system-x86_64 -drive format=raw,file=os-image
