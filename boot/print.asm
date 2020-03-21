;Prints string to bios TTY address of the string must be in si and have 9 as the
;null terminator
[bits 16]
print:
pusha
mov ah, 0x0e ; Set bios into TTY mode

.loop:
lodsb
or al, al ; See if zero flag is zero
jz .exit
int 0x10
jmp .loop

.exit:
popa
ret

[bits 32]
print_32:
pusha
mov ebx, 0xb8000 ; VGA address
.loop:
lodsb ; Load data as esi into eax and increment to next chcaracter
or al, al ; see if al is equal to null terminator
jz .exit
or eax, 0xf100 ; bytes: 1 background(blue) 2(foreground(white) 3-4 masks
mov word [ebx], ax ; Write to data
add ebx, 2 ; Move to next VGA cell
jmp .loop

.exit:
popa
ret
