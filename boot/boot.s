
KERNEL_VIRTUAL_BASE equ 0xc0000000
KERNEL_PAGE_NUMBER equ (KERNEL_VIRTUAL_BASE >> 22) ; Index
; Declare constants for the multiboot header

KERNEL_OFFSET equ 0xC0000000
MBALIGN equ 1 << 0 ; Align modules on these page boundaries
MEMINFO equ 1 << 1 ; provide a memory map plz
FLAGS   equ MBALIGN | MEMINFO ; The flag field for the multiboot stuff
MAGIC equ 0x1badb002 ; The magic number
CHECKSUM equ -(MAGIC + FLAGS)

%include "boot/gdt2.asm"
%include "boot/page_initialization.s"
[bits 32]
; Place the signature in it's own header so it must been within the 8Kib of the
; kernel file yaaas
section .multiboot
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM

;section .bss
;align 4096
;boot_page_directory:
;resb 4096
;boot_page_table1:
;resb 4096

section .data
align 4096
boot_page_directory:
;times 1024 dd 0x00000002
dd 0x00000083
times (KERNEL_PAGE_NUMBER - 1) dd 0
dd 0x00000083
;Rest of the entries for the kernel
times (1024 - KERNEL_PAGE_NUMBER - 1) dd 0


section  .bss
align 16
stack_bottom:
resb 16384 ; 16 KiB
stack_top:

; Linker script specifies the entry point to the kernel
section .text
global _start:function (_start.end - _start)
_start:
;.asdf:


;.hang: hlt
;jmp .hang
jmp reset_cs
.end:

reset_cs:
boot_page_init:
; Identity map the first 4MiB
;mov eax, 0x00000083
;mov [boot_page_directory], eax
;mov [boot_page_directory + 767], eax

;Enable physical address extension
mov eax, cr4
or eax, 0x00000010
mov cr4, eax

mov ecx, (boot_page_directory - KERNEL_VIRTUAL_BASE)
mov cr3, ecx

;Enable the paging stuff
mov eax, cr0
or eax, 0x80000001
mov cr0, eax


lea ecx, [higher_half]

jmp ecx

higher_half:
lgdt [gdt_desc]
jmp 0x0008:higher_reset
higher_reset:
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

