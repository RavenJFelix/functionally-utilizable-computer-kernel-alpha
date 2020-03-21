#include "vga_tty_cell.h"
#include "bool.h"
#include "screen.h"
#include "pair2d.h"
#include "io.h"
#include "vga_util.h"
#define FB_CURSE_COMMAND_PORT  0x3d4
#define FB_CURSE_DATA_PORT 0x3d5
#define FB_CURSE_HIGH_COMMAND 14

#define FB_CURSE_LOW_COMMAND 15

void fb_moveCursor(struct uc_pair2d pos)
{
	unsigned short line_pos = FB_CURSOR_LINE_POS(pos.x, pos.y);

	outb(FB_CURSE_COMMAND_PORT, FB_CURSE_HIGH_COMMAND);
	//Shift the get the highest 8 bits of lineb_pos and send it to FB
	outb(FB_CURSE_DATA_PORT, ((line_pos >> 8) & 0x0ff));
	outb(FB_CURSE_COMMAND_PORT, FB_CURSE_LOW_COMMAND);
	//Take lowest 8 bits of line_pos
	outb(FB_CURSE_DATA_PORT, line_pos & 0x0ff);
}

void fb_shift_up(unsigned int distance)
{
	//Repeat scrolling until
	for(unsigned int i = 0; i < distance; ++i)
	{
		
		//For each row except the last
		for(int y = 0; y < (FB_MAX_ROWS - 1); y++)
		{
			for(unsigned int x =0; x < FB_MAX_COLS; x++)
			{
				//Copy The corresponding character from the row below
				//struct uc_pair2d pos = {(unsigned char)x,(unsigned char)y};
				unsigned int line_pos_dest = FB_LINE_POS(x, y);
				unsigned int line_pos_source = FB_LINE_POS(x, (y + 1));
				FB_CELL(line_pos_dest) = FB_CELL(line_pos_source);
				FB_CELL(line_pos_dest + 1) = FB_CELL(line_pos_source + 1);
			}
		}
		fb_clear_line(24);
	}
}

void fb_clear_line(unsigned char line)
{
	for (unsigned int x = 0; x < FB_MAX_COLS; x++)
	{
		unsigned int line_pos  = FB_LINE_POS(x, line);
		FB_CELL(line_pos) = ' ';	
	}
}
