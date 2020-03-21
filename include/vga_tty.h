#include "screen.h"

struct fb_state
{
	struct fb_color_code default_color;
	struct uc_pair2d cursor_pos;
};


