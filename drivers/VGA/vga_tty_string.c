#include "vga_tty_string.h"
#include "vga_tty.h"
#include "vga_util.h"
#include "pair2d.h"
#include "string_const.h"
void fb_write_string_direct(
		struct uc_pair2d pos,
	   	const char* str,
	   	const struct fb_color_code color_code
		)
{
	unsigned int i = 0;
	struct uc_pair2d current_pos = fb_char_line_pos_to_pos(FB_LINE_POS(pos.x, pos.y));
	while(str[i] != STRING_NULL_TERMINATOR)
	{
		fb_write_cell_abstract(current_pos, str[i], color_code);
		++current_pos.x;
		++i;
	}
}

void fb_write_string_direct_noNull(
		struct uc_pair2d pos,
	   	const char* string,
	   	unsigned int len,
	   	struct fb_color_code color_code
		)
{
	struct uc_pair2d position = pos;
	for(unsigned int i = 0;i < len;i++)
	{
		fb_write_cell_abstract(position, string[i], color_code);
		position.x++;
	}
}
void fb_write_string_wrap_auto(
		struct uc_pair2d pos, 
		const char *str, 
		const struct fb_color_code color_code
		)
{
	unsigned int str_index = 0;
	unsigned int current_vga_cell = FB_LINE_POS(pos.x, pos.y);
	char current_char = str[str_index];

	while(current_char != STRING_NULL_TERMINATOR)
	{
		fb_write_cell(
				current_vga_cell,
			   	current_char, 
				(FB_COLOR_CODE_TO_UCHAR(color_code.fg, color_code.bg))); 

		current_vga_cell += 2; //Vga character cells are two bytes in length
		++str_index;
		current_char = str[str_index];

		if (fb_line_pos_exceeds_max(current_vga_cell))
		{
			fb_shift_up(1);
			current_vga_cell -= 2 * FB_MAX_COLS; // Multiply by two since cells take up two bytes
		}
	}
}

void fb_write_string_wrap_direct(
		struct uc_pair2d pos,
	   	const char *str,
	   	const struct fb_color_code color_code
		)
{
	unsigned int str_index = 0;
	unsigned int current_vga_cell = FB_LINE_POS(pos.x, pos.y);
	char current_char = str[str_index];
	while(current_char != STRING_NULL_TERMINATOR)
	{
		//fb_write_cell_abstract(pos, 'F', (struct fb_color_code){0, 15});
		
		fb_write_cell(
				current_vga_cell,
			   	current_char, 
				FB_COLOR_CODE_TO_UCHAR(color_code.fg, color_code.bg)
				);
		current_vga_cell += 2; //Vga character cells are two bytes in length
		++str_index;
		current_char = str[str_index];
	}
}

void fb_write_string_wrap_safe(
		struct uc_pair2d pos,
		const char *str,
	   	const struct fb_color_code color_code
		)
{
	unsigned int str_index = 0;
	unsigned int current_vga_cell = FB_LINE_POS(pos.x, pos.y);
	char current_char = str[str_index];
	while(current_char != STRING_NULL_TERMINATOR && ! fb_line_pos_exceeds_max(current_vga_cell))
	{
		fb_write_cell(
				current_vga_cell,
			   	current_char,
			   	FB_COLOR_CODE_TO_UCHAR(color_code.fg, color_code.bg)
				);
		current_vga_cell += 2; //Vga character cells are two bytes in length
		++str_index;
		current_char = str[str_index];
	}
}
