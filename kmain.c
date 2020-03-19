#include "screen.h"
void kmain()
{
	char *frame_buffer = (char*)0x000b8000;

	frame_buffer[162] = 'F';
	frame_buffer[2] = 'U';
	//Have the caharcter point to the first text cell
	//of the video memory
	// Store the character F at the top left 
	struct uc_pair2d pos = {1,2};
	
	fb_write_char(0, 0, 'F', 0, 15);
	fb_write_char_pos(pos, 'U', 0, 15);
}
