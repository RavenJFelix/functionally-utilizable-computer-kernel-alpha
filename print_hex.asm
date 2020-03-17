%include "print_string.asm"
print_hex:

  pusha             ; save the register values to the stack for later



  mov cx,4          ; Start the counter: we want to print 4 characters

                    ; 4 bits per char, so we're printing a total of 16 bits



char_loop:

  dec cx            ; Decrement the counter



  mov ax,dx         ; copy bx into ax so we can mask it for the last chars

  shr dx,4          ; shift bx 4 bits to the right

  and ax,0xf        ; mask ah to get the last 4 bits



  mov bx, HEX_OUT   ; set bx to the memory address of our string

  add bx, 2         ; skip the '0x'

  add bx, cx        ; add the current counter to the address



  cmp ax,0xa        ; Check to see if it's a letter or number

  jl set_letter     ; If it's a number, go straight to setting the value

  add byte [bx],7   ; If it's a letter, add 7

                    ; Why this magic number? ASCII letters start 17

                    ; characters after decimal numbers. We need to cover that

                    ; distance. If our value is a 'letter' it's already

                    ; over 10, so we need to add 7 more.

  jl set_letter


