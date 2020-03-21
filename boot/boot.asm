[bits 16]
[org 0x7c00] ;Where the boot loader is loaded

boot:
mov si, fuck
mov ah, 0x0e

.loop:
lodsb ; Loads the byte at ds:si to al and increments si
or al,al ; See if al=0
jz halt ; Jump if Zero
int 0x10 ; Print character
jmp .loop

halt:
cli ; Clear the interrupt flag
hlt ; Hald execution

fuck: db "Fuck oh fuck asdfefiosejfalsdffjsefijaleffjiasel;fijasefljaselfijj", 0

times 510 - ($-$$) db 0 ; Pad any remaining bytes
dw 0xaa55 ; The magic number

