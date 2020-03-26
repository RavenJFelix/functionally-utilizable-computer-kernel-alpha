#include "terminal.h"
#include "interrupt.h"
#include "pic.h"
#include "bool.h"
#include "keyboard.h"
#include "kernel_globals.h"
#include "keyboard_validification.h"
#include "ring_buffer.h"
void kernel_main()
{
	kernel_globals_init();	
	idt_init();
	keyboard_init();
	char fuck[] = "FUCK\nASDF\nFOIAJEFPAOIJSEFFPAIJSE\0";
	char testnew[] = "\nHELLO:";
	
	while(true)
	{
		if(!uc_ring_buffer_empty(&kernel_keyboard_buffer))
		{
			unsigned char scan_code = uc_ring_buffer_dequeue(&kernel_keyboard_buffer);
			if(keyboard_scancode_1_is_ascii_number(scan_code))
			{
				terminal_vga_print_char(&main_terminal, scan_code + 0x2f);
			}

		}
	}
	
	terminal_vga_print(&main_terminal, fuck);
	//terminal_new_line(&term);
	

}
