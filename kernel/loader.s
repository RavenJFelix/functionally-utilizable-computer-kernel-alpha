global loader ; entry for ELF
[extern kmain]

MAGIC_NUMBER equ 0x1BADB002
KERNEL_STACK_SIZE equ 4096
FLAGS equ 0x0
CHECKSUM equ -MAGIC_NUMBER

section .text: ;start of the code
align 4        ;algin to 4 b byts
dd MAGIC_NUMBER;write the magic number to the code
dd FLAGS       ;set the flacks
dd CHECKSUM    ;and the checksum

loader:
mov esp, kernel_stack + KERNEL_STACK_SIZE
mov eax, 0xCAFEBABE 
call kmain
jmp $ ; infinite loop

section .bss
align 4
kernel_stack:
resb KERNEL_STACK_SIZE

