[bits 16]

switch_to_pm:

cli ; Switch off interrupts or else bad shit happens
lgdt [gdt_pointer]

mov eax, cr0
or eax, 0x1
mov cr0, eax

jmp CODE_SEG:boot2

