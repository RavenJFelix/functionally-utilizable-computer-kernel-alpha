print_string:
	pusha
	mov ah, 0x0e ; int 10/ah = 0eh ->scrolling teletype BIOS routine
.loop:
	cmp byte [bx], 0 ;Check if the character is null terminated
	je exit
	mov al, [bx] ; If not, move the character to al
	int 0x10 ; Print chraracter
	add byte bx, 1
	jmp .loop
exit:
	popa
	ret
