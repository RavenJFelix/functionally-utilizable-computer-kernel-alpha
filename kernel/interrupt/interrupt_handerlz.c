#include "vga_tty_cell.h"

#include "interrupt.h"
#include "pic.h"
#include "vga_const_color.h"
#include "kernel_globals.h"
#include "keyboard.h"
#include "terminal.h"
#include "keyboard_validification.h"
const char FUCK[] = {"hello fucking fucksdfefiajesf;ailsjef"};
void irq0_handler()
{
	pic_send_eoi();
}

void irq1_handler()
{
	//fb_write_char(0, 'F');
	unsigned char scan_code = keyboard_read_scan_code();
	if( keyboard_scancode_1_is_ascii_number(scan_code))
	{
		char asdf = (char)(scan_code + 0x2f);
		terminal_vga_print_char(&main_terminal, asdf);
	}
	pic_send_eoi();
}

void irq2_handler()
{
	pic_send_eoi();
}

void irq3_handler()
{
	pic_send_eoi();
}

void irq4_handler()
{
	pic_send_eoi();
}

void irq5_handler()
{
	pic_send_eoi();
}

void irq6_handler()
{
	pic_send_eoi();
}

void irq7_handler()
{
	pic_send_eoi();
}

void irq8_handler()
{
	pic_send_eoi();
}

void irq9_handler()
{
	pic_send_eoi();
}

void irq10_handler()
{
	pic_send_eoi();
}

void irq11_handler()
{
	pic_send_eoi();
}

void irq12_handler()
{
	pic_send_eoi();
}

void irq13_handler()
{
	pic_send_eoi();
}

void irq14_handler()
{
	pic_send_eoi();
}

void irq15_handler()
{
	pic_send_eoi();
}




