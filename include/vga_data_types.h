#ifndef FUCKING_VGA_DATA_TYPES_H
#define FUCKING_VGA_DATA_TYPES_H
#include "pair2d.h"

#define FB_COLOR_CODE(x, y) ((fb_color_code) {x, y})
typedef struct 
{
	unsigned char fg;
	unsigned char bg;
}fb_color_code;

struct fb_state
{
	fb_color_code default_color;
	uc_pair2d cursor_pos;
};


#endif
