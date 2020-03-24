#include "terminal.h"
#include "vga_tty_string.h"

void terminal_vga_print(Terminal* terminal, const char* string)
{	
	fb_write_string_wrap_auto_cursor(&terminal->cursor_pos, string, terminal->default_color);
}

