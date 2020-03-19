gdt_start:

gdt_null:

dd 0x0 ; Null descriptor
dd 0x0 ; Make 4 bytes of 0's

gdt_code:
; base 0x0, limit 0xffffff
dw 0xffff ; Limit (bits 0-15
dw 0x0 ; Base (bits 0-15
db 0x0 ; Base bits 16-23
db 10011010b 
; 1st flags, type flats : (present:1 privilenge: 00, descriptor type 0
db 11001111b ; Second flags, Limit(bits 16-19)
db 0x0 ; base (bits 24-31)

gdt_data:
dw 0xffff
dw 0x0
db 0x0
db 10010010b
db 11001111b
db 0x0

gdt_end:

gdt_descriptor:
dw gdt_end - gdt_start - 1

dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
