#include "screen.h"
#include "stringConsts.h"
#include "pair2d.h"
#include "io.h"
#define MAX_ROWS 25
#define MAX_COLS 80
#define FRAME_BUFFER_ADR 0x000b8000
#define FB_CURSE_COMMAND_PORT  0x3D4
#define FB_CURSE_DATA_PORT 0x3d5
#define FB_CURSE_HIGH_COMMAND 14
#define FB_CURSE_LOW_COMMAND 15

#define NULL_TERMIN '\0'

#define FB_LINE_POS(x, y) 2 * (MAX_COLS * y + x)
#define FB_CURSOR_LINE_POS(x, y) (MAX_COLS * y + x)
char *fb = (char*) FRAME_BUFFER_ADR;

//void fb_printWrap_hasNull(const struct uc_pair2d* startPos, const char* str,const struct fb_color_code * colorCode)
//{
//	unsigned int i = 0;
//	while(str[i] != '\0')
//	{
//	}
//}

void fb_write_string_direct(struct uc_pair2d pos, const char* str, const struct fb_color_code color_code)
{
	unsigned int i = 0;
	struct uc_pair2d current_pos = pos;
	while(str[i] != NULL_TERMIN)
	{
		fb_write_char(current_pos, str[i], color_code);
		++current_pos.x;
		++i;
	}
}

void fb_write_string_direct_noNull(struct uc_pair2d pos, const char* string, unsigned int len, struct fb_color_code color_code)
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

void fb_shift_up(unsigned int distance)
{
	//Repeat scrolling until
	for(unsigned int i = 0; i < distance; ++i)
	{
		
		//For each row except the last
		for(int y = 0; y < (MAX_ROWS - 1); y++)
		{
			for(unsigned int x =0; x < MAX_COLS; x++)
			{
				//Copy The corresponding character from the row below
				//struct uc_pair2d pos = {(unsigned char)x,(unsigned char)y};
				unsigned int line_pos_dest = FB_LINE_POS(x, y);
				unsigned int line_pos_source = FB_LINE_POS(x, (y + 1));
				fb[line_pos_dest] = fb[line_pos_source];
				fb[line_pos_dest + 1] = fb[line_pos_source + 1];
				//fb_write_char(pos, 'F', (struct fb_color_code){0, 15});
			}
		}
		fb_clear_line(24);
	}
}

void fb_clear_line(unsigned char line)
{
	for (unsigned int x = 0; x < MAX_COLS; x++)
	{
		unsigned int line_pos  = FB_LINE_POS(x, line);
		fb[line_pos] = ' ';	
	}
}
