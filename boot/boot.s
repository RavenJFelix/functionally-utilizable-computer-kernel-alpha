; Declare constants for the multiboot header

MBALIGN equ 1 << 0 ; Align modules on these page boundaries
MEMINFO equ 1 << 1 ; provide a memory map plz
FLAGS   equ MBALIGN | MEMINFO ; The flag field for the multiboot stuff
MAGIC equ 0x1badb002 ; The magic number
CHECKSUM equ -(MAGIC + FLAGS)

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
mov esp, stack_top ; Initialize stack

extern kernel_main
call kernel_main


cli
.hang: hlt
jmp .hang
.end:

