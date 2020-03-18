[bits 16]
[org 0x7c00]
KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl
mov bp, 0x9000
mov sp, bp

mov bx, MSG_REAL_MODE
call print_string

call load_kernel

call switch_to_pm

jmp $

%include "print_hex.asm"
%include "gdt.asm"
%include "boot_load.asm"
%include "print_string.asm"
%include "print_string_pm.asm"
%include "switch_to_pm.asm"

[bits 16]
load_kernel:
mov bx, MSG_LOAD_KERNEL
call print_string
mov bx, KERNEL_OFFSET
mov dh, 2
mov dl, [BOOT_DRIVE]
call disk_load
ret
[bits 32]

BEGIN_PM:

mov ebx, MSG_PROT_MODE
call print_string_pm
call KERNEL_OFFSET
jmp $

; Messsage Variables
BOOT_DRIVE db 0
MSG_REAL_MODE db "Started in 16-bit mode", 0
MSG_PROT_MODE db "I AM IN 32 bits now ahhhhhahaha fuck yeah", 0
MSG_LOAD_KERNEL db "YES PLEASE LOAD ME MOORRE", 0

times 510 - ($-$$) db 0
dw 0xaa55
