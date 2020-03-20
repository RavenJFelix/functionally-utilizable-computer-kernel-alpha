#include "screen.h"
#include "pair2d.h"
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

void kmain()
{
	line_pos_conversion_test();
}


