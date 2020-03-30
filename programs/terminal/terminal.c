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

void terminal_print_hex(Terminal *terminal, unsigned long hex_value)
{
	//The hexadecimmal is a 32 bit number, or an 4 byte number
	//Spanning 8 hexadecimal values
	const  char header[] = {"0x\0"};
	terminal_vga_print(terminal, header);
	unsigned long mask = 0x0000000f;
	for(int i = 0; i < 8; ++i)
	{
		//Take the 4 left-most values
		char number = (hex_value >> ((7-i)* 4)) & mask;

		//If within 0-9, display a numerical value
		if (number <= 9)
		{
			number += 0x30 ;//ASCII 0 starts at 0x30
		}
		else
		{
			number -= 10; //Shift number down so ASCII maps well
			number += 0x41 ;//A starts at 0x41
		}

		terminal_vga_print_char(terminal, number);
	}

}

