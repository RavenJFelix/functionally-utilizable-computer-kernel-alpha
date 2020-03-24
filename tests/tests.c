#include "pair2d.h"
#include "vga_util.h"
#include "vga_data_types.h"
void line_pos_conversion_test()
{
	struct uc_pair2d test_pos = {10, 21};
	unsigned int line_pos = FB_LINE_POS(test_pos.x, test_pos.y);
	struct uc_pair2d new_pos = fb_char_line_pos_to_pos(line_pos);

	const char pass[] = "Fuck, the position conversion functions are fucked\0";
	if(!(new_pos.x == test_pos.x) && (new_pos.x == test_pos.x))
	{
		fb_write_string_direct((struct uc_pair2d) {0,0}, pass, (struct fb_color_code) {0, 15});
	}
}

void vga_test_loop()
{
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

}

void kmain()
{
	line_pos_conversion_test();
}


