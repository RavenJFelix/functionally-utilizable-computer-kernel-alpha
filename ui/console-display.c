#include "pair2d.H"
#include "vga_data_types.h"

#include "vga_tty_string.h"


void console_print(struct fb_state *frame_buffer, const char* string)
{
	fb_write_string_wrap_auto(UC_PAIR2D(0, *(frame_buffer).cursor_pos.x), string);
}
