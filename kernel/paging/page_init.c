#include "kernel_globals.h"

void page_directory_init()
{
	for(int i = 0; 1 < 1024; ++i)
	{
		kernel_page_directory[i] = 0x00000002;
	}
}
