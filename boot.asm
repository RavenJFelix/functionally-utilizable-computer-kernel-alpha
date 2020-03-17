;assembly stuff
mov ah, 0x0e

mov bx, fuck
add bx, 0x7c00
mov al, [bx]
int 0x10

jmp $

fuck:
	db 'X'
times 510 - ($-$$) db 0
dw 0xaa55
