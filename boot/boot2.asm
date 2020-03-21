[bits 16]
[org 0x7c00]

boot:
mov ax, 0x2401
int 0x15 ; Enable 20 to access more than 1 megabyte because fuck segment
; addressing

mov ax, 0x3
int 0x10 ; Vega to text mode 3
cli
lgdt [gdt_pointer] ; Load the gdt table
mov eax, cr0
or eax, 0x1 ; set protecteed bit to cr0 because fuck yeah we are in 64 bit bois
mov cr0, eax
jmp CODE_SEG:boot2 ; long jump because those buffers can be dirty at times
;
%include "gdt.asm"
%include "print.asm"

[bits 32]
boot2:
; Have all segment registers reference the data segment addresss
mov ax, DATA_SEG
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax
mov ss, ax ;Wot

mov esi, fuck
call print_32

cli ; Clear all registers
hlt ; Halt execution

fuck: db "FUCK YEAH IN 32 BITS BABY!", 0

times 510 - ($-$$) db 0 ;Pad the rest of the bytes
dw 0xaa55 ; BIOS magik number sorcery

