[org 0x7c00]

KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl ;Bios contains the boot drive in dl
mov bp, 0x9000
mov sp, bp ; Initialize stack

mov bx, MSG_REAL_MODE
call print_string

call load_kernel

call switch_to_pm

jmp $

%include "print_string.asm"
%include "disk_load.asm"
%include "gdt.asm"
%include "print_string_pm.asm"
%include "switch_to_pm.asm"

[bits 16]

load_kernel:
mov bx, MSG_LOAD_KERNEL
call print_string

mov bx, KERNEL_OFFSET ; Set up for disk load routine
mov dh, 15 ;Load the first 15 sectors
mov dl, [BOOT_DRIVE]
call disk_load

ret

[bits 32]
BEGIN_PM:

mov ebx, MSG_PROT_MODE ; Announce we are in bois
call print_string_pm
call KERNEL_OFFSET     ; Call the kernel modes
jmp $                  ; Hang up cuz we can

BOOT_DRIVE db 0
MSG_REAL_MODE db "STILL IN NORMIE LAND FUCK", 0
MSG_PROT_MODE db "WE ARE IN BOIZ", 0
MSG_LOAD_KERNEL db "THE KERNEL IS IN FUCK OH FUCK YEAH MMORE PLEASE", 0

; bootsector padding
times 510-($-$$) db 0
dw 0xaa55
