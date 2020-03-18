[bits 16]

switch_to_pm:
cli ; Switch off interrupts
lgdt [gdt_descriptor]
mov eax, cr0
or eax, 0x1
mov cr0, eax

jmp CODE_SEG:init_pm ;Far jump to new segment and force cpu to jump cache

[bits 32]

init_pm:

mov ax, DATA_SEG
mov ds, ax
mov ss, ax
mov ss, ax
mov es, ax
mov fs, ax
mov gs, ax

mov ebp, 0x90000
mov esp, ebp

call BEGIN_PM
