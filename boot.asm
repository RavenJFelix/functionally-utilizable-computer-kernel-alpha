mov ah, 0x0e
mov al, 'F'
int 0x10
mov al, 'U'
int 0x10
mov al, 'C'
int 0x10
mov al, 'K'
int 0x10

jmp $ ;asdf

times 510 - ($-$$) db 0
dw 0xaa55
