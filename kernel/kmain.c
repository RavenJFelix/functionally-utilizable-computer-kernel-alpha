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
	char fuck[] = "FUCK\nASDF\nFOIAJEFPAOIJSEFFPAIJSE";
	char testnew[] = "\nHELLO:";
	
	terminal_vga_print(&main_terminal, testnew);
	terminal_vga_print(&main_terminal, testnew);
	//terminal_new_line(&term);
	

}
