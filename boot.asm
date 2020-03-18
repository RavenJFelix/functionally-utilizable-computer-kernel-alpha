[org 0x7c00]

mov bp, 0x9000
mov sp, bp

mov bx, MSG_REAL_MODE
call print_string

call switch_to_pm

jmp $

%include "gdt.asm"
%include "print_string.asm"
%include "print_string_pm.asm"
%include "switch_to_pm.asm"

[bits 32]

BEGIN_PM:

mov ebx, MSG_PROT_MODE
call print_string_pm

jmp $

; Messsage Variables
MSG_REAL_MODE db "Started in 16-bit mode"
MSG_PROT_MODE db "I AM IN 32 bits now ahhhhhahaha fuck yeah"

times 510 - ($-$$) db 0
dw 0xaa55
