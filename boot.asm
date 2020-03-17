mov ah, 0x0e
mov bx, 4
cmp bx, 4
je then_block
mov al, "!"
jmp then_else

then_block:
mov al, "="
then_else:
int 0x10

jmp $

times 510 - ($-$$) db 0
dw 0xaa55
