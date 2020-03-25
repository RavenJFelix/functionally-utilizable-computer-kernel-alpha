#include "terminal.h"
#include "pic.h"
#include "bool.h"
void kernel_main()
{
	pic_remap(0x20, 0x28);
	char fuck[] = "FUCK\nASDF\nFOIAJEFPAOIJSEFFPAIJSE";
	char testnew[] = "\nHELLO:";
	
	Terminal term = TERMINAL_DEFAULT;
	terminal_vga_print(&term, testnew);
	//terminal_new_line(&term);
	

}
