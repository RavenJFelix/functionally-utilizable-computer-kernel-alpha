#include "terminal.h"
#include "bool.h"
void kernel_main()
{
	Terminal term = TERMINAL_DEFAULT;
	terminal_vga_print(&term, "Fuck");

}
