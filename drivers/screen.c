#include "screen.h"
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
#define FB_CURSOR_LINE_POS(x, y) (MAX_COLS * y + x)
char *fb = (char*) FRAME_BUFFER_ADR;

void fb_write_string_direct(struct uc_pair2d pos, const char* string, unsigned int len, struct fb_color_code color_code)
{
	struct uc_pair2d position =pos;
	for(unsigned int i = 0;i < len;i++)
	{
		fb_write_char(position, string[i], color_code);
		position.x++;
	}
}

void fb_write_char_fast(unsigned char x, unsigned char y, char c, unsigned char fg, unsigned char bg)
{
	unsigned int line_pos = FB_LINE_POS(x, y);
	// Mask first four bits of fg and bg, move fg to first four bits of bg
	char color_code = ((fg & 0x0f) << 4) | (bg & 0x0f);
	
	//Write character to first byte of cell
	fb[line_pos] = c;
	//Write character to the second byte of the cell
	fb[line_pos + 1] = color_code;
}

void fb_write_char(struct uc_pair2d pos, char c, struct fb_color_code color_code)
{
	unsigned int line_pos = FB_LINE_POS(pos.x, pos.y);
	// Mask first four bits of fg and bg, move fg to first four bits of bg
	char binary_color_code = ((color_code.fg & 0x0f) << 4) | (color_code.bg & 0x0f);
	
	//Write character to first byte of cell
	fb[line_pos] = c;
	//Write character to the second byte of the cell
	fb[line_pos + 1] = binary_color_code;
}

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
