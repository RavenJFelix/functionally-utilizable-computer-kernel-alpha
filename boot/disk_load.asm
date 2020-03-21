[bits 16]
disk_load:
pusha
push dx

mov ah, 0x02 ; BIOS read sector function

mov al, dh ; Read DH sectors
mov ch, 0x00 ; Cylinder 0
mov dh, 0x00 ; Head 0
mov cl, 0x02 ; Start reading from the second sector

int 0x13

jc .disk_error ; Jump if there was a laoding error

pop dx       ; 
cmp dh, al
jne .disk_error
popa
ret

.disk_error:
mov si, DISK_ERROR_MSG
call print

hlt ; Halt execution

DISK_ERROR_MSG: db "There is read error!!!", 0
