%include "gdt.asm"
load_gdt:
;cli
;ldgt[gdt_pointer]
sti
ret
[bits 32]
; Lo
;mov word [0xb8000], 0x1f41
call load_gdt
jextern kmain
call kmain
jmp $
