#include "pair2d.h"
#define MAX_ROWS 25
#define MAX_COLS 80
#define FRAME_BUFFER_ADR  0x000b8000
char *fb = (char*) FRAME_BUFFER_ADR;

void fb_write_char(unsigned char x, unsigned char y, char c, unsigned char fg, unsigned char bg)
{
	unsigned int line_pos = 2 * ( (MAX_ROW_INDEX * y) + x);
	// Mask first four bits of fg and bg, move fg to first four bits of bg
	char color_code = ((fg & 0x0f) << 4) | (bg & 0x0f);
	
	//Write character to first byte of cell
	fb[line_pos] = c;
	//Write character to the second byte of the cell
	fb[line_pos + 1] = color_code;
}

void fb_write_char_pos(struct uc_pair2d pos, char c, unsigned char fg, unsigned char bg)
{
	unsigned int line_pos = 2 * ( (MAX_ROW_INDEX) * pos.y + pos.x);
	// Mask first four bits of fg and bg, move fg to first four bits of bg
	char color_code = ((fg & 0x0f) << 4) | (bg & 0x0f);
	
	//Write character to first byte of cell
	fb[line_pos] = c;
	//Write character to the second byte of the cell
	fb[line_pos + 1] = color_code;
}

#define fb_line_pos(x, y) 2 * (MAX_COLS * y + x)
