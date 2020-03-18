#!/bin/sh
nasm -f bin boot.asm -o os.bin
qemu-system-x86_64 -drive format=raw,file=os.bin
