mov ah, 0x02 ;BIOS 0x13 read sector function

mov dl, 0 ;First drive
mov ch, 3 ; Cylinder 3
mov dh, 1 ; 4th Sector

mov cl, 4 ;4th Sector

mov al, 5 ;Read 5 sectors

mov bx, 0xa000
mov es, bx


