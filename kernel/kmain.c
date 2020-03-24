#include "bool.h"
#include "screen.h"
#include "vga_tty_manipulation.h"
#include "vga_const.h"
#include "vga_tty_string.h"
void kernel_main()
{
	char *fb = (char*) 0xb8000;
	fb_clear_line(0);
	 fb_color_code wb = {0, 15};
	char *frame_buffer = (char*) FRAME_BUFFER_ADR;
	//char fuck_more[] = {"FFUFF$FFCK OH FFUCK OH FFUCK OH FFUCK OHFUCK OH FUCK OH FUCK\0"};
	//char fuck[] = {"FUCK FUCK FUCK"};

	char fuck_longer[] = {"THIasdlfjase;flkjae;lkja;selfjas;slekfjfas;lsekfjfaseskfjhaseklgjhasslkjehgS IS A LOT OF FUCKING TEST MASTERS GIVE ME MORE YES PLEASE AHHHH YES I LIKE IT I WANT MORE MAGIC NUMBERS SHOVE THEM UP MY USB PORT AND THROUGH MY SKULL \0"};

	//fb_write_char_abstract(( uc_pair2d){0,24}, 'C', wb);
	//fb_write_char_abstract(( uc_pair2d){79,0}, 'C', wb);
	fb_write_string_wrap_auto_cursor(UC_PAIR2D(0,24), fuck_longer, FB_COLOR_CODE(0, 15));
	


	//fb_shift_up(1);
	 fb_color_code col = {0, 120};
	 uc_pair2d pos = {0, 24};
	bool right = true;
	int move_length = 60;
	int x_val = 0;
	int wait = 1;
	int wait_time = 10000000;
	char fuck[] = {"FUCK OH FUCK OH FUCK"};

	while(true)
	{
		if(wait == 0)
		{
			fb_write_string_direct(pos, fuck, col);

			if(right)
			{
				x_val++;
				if(x_val >= move_length)
				{
					right = false;
				} }
			else
			{
				x_val--;
				if(x_val <= 0)
				{
					right = true;
				}
			}

			pos.x = x_val;
			fb_shift_up(1);
			wait = wait_time;
			++col.bg;
			++col.fg;
		}
		else
		{
			wait--;
		}
	}
	//for(int i = 0 ; i < 10; ++i)
	//{
	//	fb_shift_up(1);
	//	fb_write_char(pos, 'Z', wb);
	//	fb_write_char(pos2, 'X', wb);
	//}

}
