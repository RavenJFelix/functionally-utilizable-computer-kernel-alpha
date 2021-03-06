#include "terminal.h"
#include "string_const.h"
#include "vga_cursor.h"
#include "vga_tty_manipulation.h"
#include "vga_tty_string.h"
#include "vga_util.h"

void terminal_new_line(Terminal *terminal)
{

	if (terminal->cursor_pos.y >= FB_MAX_ROWS)
	{
		fb_shift_up(1);
	}
	else //There is room to move down
	{
		++terminal->cursor_pos.y;
	}
	terminal->cursor_pos.x = 0; //Regardless, the cursor should be on the first column
	terminal_update_cursor(terminal);
}

void termina_vga_new_line(Terminal *terminal, const char c)
{
	fb_write_cell(
			FB_LINE_POS(terminal->cursor_pos.x, terminal->cursor_pos.y),
		   	c, 
			(FB_COLOR_CODE_TO_UCHAR(terminal->default_color.fg, terminal->default_color.bg))); 


}

void terminal_vga_print_char(Terminal *terminal, const char c)
{
	unsigned int line_pos =  FB_LINE_POS(terminal->cursor_pos.x, terminal->cursor_pos.y);
	
	fb_write_cell(line_pos,
		   	c,
		   	FB_COLOR_CODE_TO_UCHAR(terminal->default_color.fg,
			   	terminal->default_color.bg)
			);
	line_pos += 2;
	if(line_pos > FB_MAX_LINE_POS)
	{
		fb_shift_up(1);
		terminal->cursor_pos = UC_PAIR2D(0, 24); //Set cursor to bottom left
	}
	else
	{
		terminal->cursor_pos = fb_char_line_pos_to_pair2d(line_pos);
	}

	terminal_update_cursor(terminal);
}

void terminal_vga_print(Terminal* terminal, const char* str)
{	
	 unsigned int str_index = 0;
	 char current_char = str[str_index];
	while(current_char != STRING_NULL_TERMINATOR)
	{
		if (current_char == '\n')
		{
			terminal_new_line(terminal);
		}
		else
		{
			terminal_vga_print_char(terminal, current_char);
		}
		++str_index;
		current_char = str[str_index];
	}
	terminal_update_cursor(terminal);
}


void terminal_update_cursor(Terminal *terminal)
{
	fb_move_cursor(terminal->cursor_pos);
}

void terminal_set_cursor(Terminal *terminal, const uc_pair2d *cursor_pos)
{
	terminal->cursor_pos = *cursor_pos;
}

