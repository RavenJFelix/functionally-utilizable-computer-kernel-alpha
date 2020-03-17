%include "print_string.asm"
mov ah, 0x02 ;BIOS 0x13 read sector function

mov dl, 0 ;First drive
mov ch, 3 ; Cylinder 3
mov dh, 1 ; 4th Sector

mov cl, 4 ;4th Sector

mov al, 5 ;Read 5 sectors
mov bx, 0xa000
mov es, bx
mov bx, 0x1234

int 0x13

jc disk_error
jmp after_error

disk_error:
mov	bx, DISK_ERROR_MSG
call print_string
after_error:
jmp $

DISK_ERROR_MSG: db "Disk error fuck", 0

times 510-($-$$) db 0
dw 0xaa55
