global outb
; out - Send byte to I/O port
; stack: [esp + 8] the data byte
;        [esp + 4 The port byte)
outb:
mov al, [esp + 8] ; 
mov dx, [esp + 4] ; Address of port to dx
out dx, al        ; Send data in al to dx
ret               ; return to caller
