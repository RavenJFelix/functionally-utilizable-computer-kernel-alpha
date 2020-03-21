;Prints string to bios TTY address of the string must be in si and have 9 as the
;null terminator
print:
pusha
mov ah, 0x0e ; Set bios into TTY mode

.loop
lodsb
or al, al ; See if zero flag is zero
jz .exit
int 0x10
jmp .loop

.exit:
popa
ret
