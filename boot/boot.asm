[bits 16]
[org 0x7c00] ;Where the boot loader is loaded

boot:
mov si, fuck
call print
halt:
cli ; Clear the interrupt flag
hlt ; Hald execution

fuck: db "Fuck oh fuck asdfefiosejfalsdffjsefijaleffjiasel;fijasefljaselfijj", 0

%include "print.asm"

times 510 - ($-$$) db 0 ; Pad any remaining bytes
dw 0xaa55 ; The magic number

