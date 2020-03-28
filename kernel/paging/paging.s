section .text
global load_page_directory:
load_page_directory:
pusha
mov ebx, [esp + 4]
mov cr3, ebx
popa
ret

global enable_paging
enable_paging:
pusha
mov ebx, cr0
or ebx, 0x80000000
mov cr0, ebx
popa
ret
