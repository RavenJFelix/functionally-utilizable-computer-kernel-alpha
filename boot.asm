[org 0x7c00]
mov bx, FUCK_MSG
call print_string

jmp $

%include "print_string.asm"

FUCK_MSG:
db 'FUCK O FUCK OH FUCK', 0
;stuff
times  510-($-$$) db 0
dw 0xaa55
