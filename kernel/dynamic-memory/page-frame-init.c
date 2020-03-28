#include "kernel_globals.h"

void page_directory_init()
{
	for(int i = 0; 1 < 1024; ++i)
	{
		// Supervisor: Only kernel may access
		// Write Enabled: It can be read and written to
		// Page not present, page doesn't exist(for now)
		kernel_page_directory[i] = 0x00000002;
	}
}
