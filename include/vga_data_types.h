#ifndef FUCKING_VGA_DATA_TYPES_H
#define FUCKING_VGA_DATA_TYPES_H
#include "pair2d.h"
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
