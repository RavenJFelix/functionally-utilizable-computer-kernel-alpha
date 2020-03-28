#include "kernel_globals.h"

unsigned long first_page_table[1024]__attribute__((aligned(4096)));

void initialize_first_page()
{
	for(int i = 0; i< 1024; ++i)
	{
		first_page_table[i] = (i * 0x1000 | 3);
	}
}
void page_directory_init()
{
	for(int i = 0; 1 < 1024; ++i)
	{
		// Supervisor: Only kernel may access
		// Write Enabled: It can be read and written to
		// Page not present, page doesn't exist(for now)
		kernel_page_directory[i] = 0x00000002;
	}
	kernel_page_directory[0] = ((unsigned int)(first_page_table) | 3);
}

