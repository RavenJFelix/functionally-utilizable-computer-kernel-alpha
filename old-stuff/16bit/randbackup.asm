[org 0x7c00]
  mov [BOOT_DRIVE], dl

  mov bp, 0x8000
  mov sp, bp    
  
  mov bx, 0xa000
  mov es, bx
  mov bx, 0x9000
  mov dh, 2

  call disk_load

  mov dx, [0x9000]
  call print_hex

  mov dx, [0x9000 + 512]
  call print_hex

  jmp $

%include "print_string.asm"
%include "print_hex.asm"

 disk_load:
  pusha
  push dx;push to stack so it can be recalled
  
  mov ah, 0x02 ; Bios read sctor function
  mov al, dh   ; Jump of sectors to read
  mov ch, 0x00 ; Cylinder 0
  mov dh, 0x00 ; Head 0
  mov cl, 2  ; Second sector

  int 0x13     ; BIOS interrupt

  jc disk_error ;Check for carry flag
  
  pop dx
  ;cmp dh, al ; See if the number of sectors read are equal
  ;jne disk_error
  ret

disk_error:
  mov bx, DISK_ERROR_MSG
  call print_string
  jmp $

 
DISK_ERROR_MSG: db "FUCK THE DISK READ BROKE", 0

BOOT_DRIVE: db 0

times 510-($-$$) db 0
dw 0xaa55
times 256 dw 0xdada
times 256 dw 0xface
