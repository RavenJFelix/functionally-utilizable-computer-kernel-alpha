mov bx, 40

cmp bx, 4
jle if_true
cmp bx, 40
jl else_if_1
mov al, 'C'
jmp if_end


if_true:
mov al, 'A'
jmp if_end
else_if_1:
mov al, 'B'
jmp if_end

if_end:
mov ah, 0x0e
int 0x10

jmp $

times 510 - ($-$$) db 0
dw 0xaa55
