;%macro no_error_code_interrupt_handler %1
;global interrupt_handler_%1
;interrupt_handler_%1:
;push dword 0 ; 0 as error code
;push dword %1 ;Push the interrupt number
;jmp common_interrupt_handler
;%endmacro
;
;%macro error_code_interrupt_handler %1
;global interrupt_handler_%1
;interrupt_handler_%1:
;push dword %1
;jmp common_interrupt_handler
;%endmacro
;
;common_interrupt_handler:
;; save the registers
;pusha
;call interrupt_handler
;popa
;add esp, 8 ; Restore the esp because two dwords wre pushed
;iret ; return to code
;no_error_interrupt_handler 0
;no_error_interrupt_handler 1
;no_error_interrupt_handler 2
;no_error_interrupt_handler 3
;no_error_interrupt_handler 4
;no_error_interrupt_handler 5
;no_error_interrupt_Handler 6
;error_code_handler 7
;
;global load_idt
;; loads the interrupt descriptor table
;; stack: [esp + 4], the address of the rist entry of the idk
;;        resp, the return adress
;load_idt:
;mov eax,[esp+4]
;lidt eax ; Load the idk
;ret ; Return to the aclling function
