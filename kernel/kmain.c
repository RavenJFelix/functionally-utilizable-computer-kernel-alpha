#include "screen.h"
void kmain()
{
	//const int frame_adr = 0x000b8000;
	//char *frame_buffer = (char*)frame_adr;
	struct fb_color_code wb = {0, 15};

	char fuck[] = {"FUCK OH FUCK OH FUCK\0"};
	fb_moveCursor( (struct uc_pair2d){0,0});
	struct uc_pair2d pos = {0,24};

	fb_write_char((struct uc_pair2d){0,0}, 'A', wb);
	fb_write_char((struct uc_pair2d){79,24}, 'B', wb);
	fb_write_char((struct uc_pair2d){0,24}, 'C', wb);
	fb_write_char((struct uc_pair2d){79,0}, 'C', wb);

	fb_write_string_direct(pos, fuck, wb);
	//fb_shift_up(1);
	fb_shift_up(1);
	//for(int i = 0 ; i < 10; ++i)
	//{
	//	fb_shift_up(1);
	//	fb_write_char(pos, 'Z', wb);
	//	fb_write_char(pos2, 'X', wb);
	//}
}
