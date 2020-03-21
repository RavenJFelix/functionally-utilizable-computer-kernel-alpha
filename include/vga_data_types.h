#ifndef FUCKING_VGA_DATA_TYPES_H
#define FUCKING_VGA_DATA_TYPES_H
#include "pair2d.h"

#define FB_COLOR_CODE(x, y) ((struct fb_color_code) {x, y})
struct fb_color_code
{
	unsigned char fg;
	unsigned char bg;
};

struct fb_state
{
	struct fb_color_code default_color;
	struct uc_pair2d cursor_pos;
};


#endif
