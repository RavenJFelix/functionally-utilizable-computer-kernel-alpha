[bits 32]

VIDEO_MEMORY equ 0xb8000 ;VGA video location
WHITE_ON_BLACK equ 0x0f ; Color

print_string_pm:
pusha
mov edx, VIDEO_MEMORY

.loop:
mov al, [ebx] ; Place character in ebx in AL
mov ah, WHITE_ON_BLACK ; storee attributes for character

cmp al, 0 ;Check for null terminator
je .done

mov  [edx], ax

add ebx, 1 ; Move ebx to next character
add edx, 2 ; Movev to the next character cell

jmp .loop

.done:
popa
ret

