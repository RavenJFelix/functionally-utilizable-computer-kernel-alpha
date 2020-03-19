#include "pair2d.h"
#include "io.h"
#define MAX_ROWS 25
#define MAX_COLS 80
#define FRAME_BUFFER_ADR 0x000b8000
#define FB_CURSE_COMMAND_PORT  0x3D4
#define FB_CURSE_DATA_PORT 0x3d5
#define FB_CURSE_HIGH_COMMAND 14
#define FB_CURSE_LOW_COMMAND 15

#define FB_LINE_POS(x, y) 2 * (MAX_COLS * y + x)
char *fb = (char*) FRAME_BUFFER_ADR;

void fb_write_char(unsigned char x, unsigned char y, char c, unsigned char fg, unsigned char bg)
{
	unsigned int line_pos = FB_LINE_POS(x, y);
	// Mask first four bits of fg and bg, move fg to first four bits of bg
	char color_code = ((fg & 0x0f) << 4) | (bg & 0x0f);
	
	//Write character to first byte of cell
	fb[line_pos] = c;
	//Write character to the second byte of the cell
	fb[line_pos + 1] = color_code;
}

void fb_write_char_pos(struct uc_pair2d pos, char c, unsigned char fg, unsigned char bg)
{
	unsigned int line_pos = FB_LINE_POS(pos.x, pos.y);
	// Mask first four bits of fg and bg, move fg to first four bits of bg
	char color_code = ((fg & 0x0f) << 4) | (bg & 0x0f);
	
	//Write character to first byte of cell
	fb[line_pos] = c;
	//Write character to the second byte of the cell
	fb[line_pos + 1] = color_code;
}

void fb_moveCursor(struct uc_pair2d pos)
{
	unsigned short line_pos = FB_LINE_POS(pos.x, pos.y);

	outb(FB_CURSE_COMMAND_PORT, FB_CURSE_HIGH_COMMAND);
	//Shift the get the highest 8 bits of lineb_pos and send it to FB
	outb(FB_CURSE_DATA_PORT, ((line_pos >> 8) & 0x0ff));
	outb(FB_CURSE_COMMAND_PORT, FB_CURSE_LOW_COMMAND);
	//Take lowest 8 bits of line_pos
	outb(FB_CURSE_DATA_PORT, line_pos & 0x0ff);
}
