#include "screen.h"
#include "stringConsts.h"
#include "pair2d.h"
#include "io.h"
#define FRAME_BUFFER_ADR 0x000b8000
#define FB_CURSE_COMMAND_PORT  0x3D4
#define FB_CURSE_DATA_PORT 0x3d5
#define FB_CURSE_HIGH_COMMAND 14
#define FB_CURSE_LOW_COMMAND 15

#define NULL_TERMIN '\0'

#define FB_LINE_POS(x, y) 2 * (FB_MAX_COLS * y + x)
#define FB_CURSOR_LINE_POS(x, y) (FB_MAX_COLS * y + x)
#define FB_COLOR_CODE_STRUCT_TO_UCHAR(fg, bg) ((fg & 0x0f) << 4) | (bg & 0x0f) //Takes two unsigned chars
char *fb = (char*) FRAME_BUFFER_ADR;


//void fb_printWrap_hasNull(const struct uc_pair2d* startPos, const char* str,const struct fb_color_code * colorCode)
//{
//	unsigned int i = 0;
//	while(str[i] != '\0')
//	{
//	}
//}

/** Same as fb_write_char but uses two structs to pass data in a more intuitive
 * manner
 */
void fb_write_string_direct(struct uc_pair2d pos, const char* str, const struct fb_color_code color_code)
{
	unsigned int i = 0;
	struct uc_pair2d current_pos = pos;
	while(str[i] != NULL_TERMIN)
	{
		fb_write_char_abstract(current_pos, str[i], color_code);
		++current_pos.x;
		++i;
	}
}

void fb_write_string_direct_noNull(struct uc_pair2d pos, const char* string, unsigned int len, struct fb_color_code color_code)
{
	struct uc_pair2d position =pos;
	for(unsigned int i = 0;i < len;i++)
	{
		fb_write_char_abstract(position, string[i], color_code);
		position.x++;
	}
}

void fb_write_char(unsigned int line_pos, char c, unsigned char color_code)
{
	// Mask first four bits of fg and bg, move fg to first four bits of bg
	
	//Write character to first byte of cell
	fb[line_pos] = c;
	//Write character to the second byte of the cell
	fb[line_pos + 1] = color_code;
}

void fb_write_char_abstract(struct uc_pair2d pos, char c, struct fb_color_code color_code)
{
	// Mask first four bits of fg and bg, move fg to first four bits of bg
	fb_write_char(FB_LINE_POS(pos.x, pos.y), c, FB_COLOR_CODE_STRUCT_TO_UCHAR(color_code.fg, color_code.bg));
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
		for(int y = 0; y < (FB_MAX_ROWS - 1); y++)
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
	for (unsigned int x = 0; x < FB_MAX_COLS; x++)
	{
		unsigned int line_pos  = FB_LINE_POS(x, line);
		fb[line_pos] = ' ';	
	}
}
