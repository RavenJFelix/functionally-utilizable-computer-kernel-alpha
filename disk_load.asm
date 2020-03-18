disk_load:
push dx

mov ah, 0x02
mov al, dh
mov ch, 0x00 ; Cylinder 0
mov dh, 0x00 ; Head 0
mov cl, 0x02 ; Start reading from the second sector

int 0x13     ;BIOS interrupt

jc disk_error

pop dx ; Restore dx from the stack
cmp dl, dh
jne disk_error
ret

disk_error:
mov bx, DISK_ERROR_MSG
call print_string
jmp $

DISK_ERROR_MSG: db "FUCK OH FUCK", 0
