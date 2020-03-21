#include "vga_tty_manipulation.h"
#include "pair2d.h"
#include "vga_const.h"
#include "vga_util.h"


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
