#include "screen.h"
void kmain()
{
	const int frame_adr = 0x000b8000;
	char *frame_buffer = (char*)frame_adr;

	frame_buffer[0] = 'F';
	struct uc_pair2d pos = {1,2};
	fb_write_char(0, 0, 'F', 0, 15);
	fb_write_char_pos(pos, 'U', 0, 15);
	fb_moveCursor( (struct uc_pair2d){1,0});
}
