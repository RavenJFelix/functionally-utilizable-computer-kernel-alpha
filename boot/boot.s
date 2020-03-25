; Declare constants for the multiboot header

MBALIGN equ 1 << 0 ; Align modules on these page boundaries
MEMINFO equ 1 << 1 ; provide a memory map plz
FLAGS   equ MBALIGN | MEMINFO ; The flag field for the multiboot stuff
MAGIC equ 0x1badb002 ; The magic number
CHECKSUM equ -(MAGIC + FLAGS)

%include "boot/gdt2.asm"
[bits 32]
; Place the signature in it's own header so it must been within the 8Kib of the
; kernel file yaaas
section .multiboot
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM

section  .bss
align 16
stack_bottom:
resb 16384 ; 16 KiB
stack_top:

; Linker script specifies the entry point to the kernel
section .text
global _start:function (_start.end - _start)
_start:
lgdt [gdt_desc]
jmp 0x0008:reset_cs
.asdf:


.hang: hlt
jmp .hang
.end:

reset_cs:
mov ax, 0x0010
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax
mov ss, ax
mov esp, stack_top   ;set stack pointer
extern kernel_main
call kernel_main
jmp $   ;halt the CPU
