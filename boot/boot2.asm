[bits 16]
[org 0x7c00]
KERNEL_OFFSET equ 0x1000

boot:

mov [BOOT_DRIVE], dl
mov bp, 0x9000
;mov si, LOAD_KERNEL_MSG
;call print
mov sp, bp

;mov ax, 0x3
;int 0x10 ; Vega to text mode 3
call load_kernel

mov si, fuck
call print
call switch_to_pm
;mov ax, 0x2401
;int 0x15 ; Enable 20 to access more than 1 megabyte because fuck segment
;; addressing
;
;cli
;lgdt [gdt_pointer] ; Load the gdt table
;mov eax, cr0
;or eax, 0x1 ; set protecteed bit to cr0 because fuck yeah we are in 64 bit bois
;mov cr0, eax
;jmp CODE_SEG:boot2 ; long jump because those buffers can be dirty at times
;

load_kernel:
pusha
mov bx, KERNEL_OFFSET
mov dh, 12

mov dl, [BOOT_DRIVE]

call disk_load
mov si, LOAD_KERNEL_MSG
call print

popa

ret
;
%include "disk_load.asm"
%include "gdt.asm"
%include "print.asm"
%include "pm_switch.asm"

[bits 32]
boot2:
; Have all segment registers reference the data segment addresss
mov ax, DATA_SEG
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax
mov ss, ax ;Wot

mov si, fuck
call print_32

call KERNEL_OFFSET

BOOT_DRIVE: db 0
fuck: db "FUCK YEAH IN 32 BITS BABY!", 0
LOAD_KERNEL_MSG: db "LOADING THE FOKING KERNEL", 0

times 510 - ($-$$) db 0 ;Pad the rest of the bytes
dw 0xaa55 ; BIOS magik number sorcery

