#include "terminal.h"
#include "bool.h"
void kernel_main()
{
	char fuck[] = "FUCK\nASDF\nFOIAJEFPAOIJSEFFPAIJSE";
	char testnew[] = "\nHELLO:";
	Terminal term = TERMINAL_DEFAULT;
	terminal_vga_print(&term, testnew);
	//terminal_new_line(&term);
	

}
