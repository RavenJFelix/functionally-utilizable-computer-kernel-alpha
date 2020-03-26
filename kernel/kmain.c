#include "terminal.h"
#include "interrupt.h"
#include "pic.h"
#include "bool.h"
#include "keyboard.h"
#include "kernel_globals.h"
void kernel_main()
{

	
	idt_init();
	keyboard_init();
	char fuck[] = "FUCK\nASDF\nFOIAJEFPAOIJSEFFPAIJSE\0";
	char testnew[] = "\nHELLO:";
	
	terminal_vga_print(&main_terminal, fuck);
	//terminal_new_line(&term);
	

}
