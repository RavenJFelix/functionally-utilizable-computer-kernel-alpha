#include "screen.h"
void kmain()
{
	//const int frame_adr = 0x000b8000;
	//char *frame_buffer = (char*)frame_adr;
	struct fb_color_code wb = {0, 15};

	char fuck[] = {"FUCK OH FUCK OH FUCK"};
	fb_moveCursor( (struct uc_pair2d){1,1});
	struct uc_pair2d pos = {0,0};

	fb_write_string_direct(pos, fuck, 20, wb);
}
