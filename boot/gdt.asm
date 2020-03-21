[bits 16]
gdt_start:
dq 0x0 ; The lowest
gdt_code:
dw 0xffff ; first 8 bits of limit
dw 0x0 ; first 8 bits of segment base
db 0x0 ; next 4 bits of segment base
db 10011010b  ; present(must be 1) 2-3 ring level: 0 4: constant
; 5:executable: 1 6 direction: 0(segment grows up) 7 read-write: 1 8 accessed
db 11001111b ; 1 granularity 1(limit multiplied by 4096) 2 size: 1 (32-bit)
; 3-4 00 4 limit_high(last 4 bits of the limit
db 0x0

gdt_data:
dw 0xffff ; first 8 bits of limit
dw 0x0 ; first 8 bits of segment base
db 0x0 ; next 4 bits of segment base
db 10010010b  ; present(must be 1) 2-3 ring level: 0 4: constant
; 5:executable: 1 6 direction: 0(segment grows up) 7 read-write: 1 8 accessed
db 11001111b ; 1 granularity 1(limit multiplied by 4096) 2 size: 1 (32-bit)
; 3-4 00 4 limit_high(last 4 bits of the limit
db 0x0

gdt_end:

gdt_pointer:
dw gdt_end - gdt_start ; Size of the gdt
dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
