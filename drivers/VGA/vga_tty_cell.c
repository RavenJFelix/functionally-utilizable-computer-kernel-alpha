#include "vga_tty_cell.h"

void fb_write_cell(unsigned int line_pos, char c, unsigned char color_code)
{
	fb_write_char(line_pos, c);
	fb_write_color(line_pos, color_code);
}

void fb_write_cell_abstract(
		struct uc_pair2d pos,
	   	char c,
	   	struct fb_color_code color_code
		)
{
	// Mask first four bits of fg and bg, move fg to first four bits of bg
	fb_write_cell(
			FB_LINE_POS(pos.x, pos.y),
		   	c,
		   	FB_COLOR_CODE_TO_UCHAR(color_code.fg, color_code.bg)
			);
}

void fb_write_char(unsigned int cell_line_pos, char c)
{
	FB_BYTE(cell_line_pos) = c;
}

void fb_write_color(unsigned int cell_line_pos, unsigned char color_code)
{
	FB_BYTE(cell_line_pos + 1) = color_code; //The color code resides in the second byte
}

