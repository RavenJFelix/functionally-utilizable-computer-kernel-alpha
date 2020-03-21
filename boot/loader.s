[bits 32]
;mov word [0xb8000], 0x1f41
extern kmain
call kmain
jmp $
