%include "gdt.asm"
load_gdt:
cli
ldgt[gdt_pointer]
sti
[bits 32]
; Lo
;mov word [0xb8000], 0x1f41
extern kmain
call kmain
jmp $
