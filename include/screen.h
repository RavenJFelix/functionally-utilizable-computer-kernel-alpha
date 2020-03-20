#ifndef SCREEN_H
#define SCREEN_H
#include "pair2d.h"
#define FB_MAX_ROWS 25
#define FB_MAX_COLS 80
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

void fb_write_char(unsigned int line_pos, char c, unsigned char color_code);
void fb_write_char_fast(unsigned char x, unsigned char y, char c, unsigned char fg, unsigned char bg);
void fb_write_char_abstract(struct uc_pair2d pos, char c, struct fb_color_code color_code);
void fb_moveCursor(struct uc_pair2d pos);
void fb_write_string_direct_noNull(struct uc_pair2d pos, const char* string, unsigned int len, struct fb_color_code color_code);
void fb_write_string_direct(struct uc_pair2d pos, const char* str, const struct fb_color_code color_code);
void fb_shift_up(unsigned int distance);
void fb_shift_down(unsigned int distance);
void fb_clear_line(unsigned char line);


#define FB_BLACK  0;
#define FB_BLUE = 1;
#define FB_GREEN = 2;
#define FB_CYAN = 3;
#define FB_RED = 4;
#define FB_MAGENTA = 5;
#define FB_BROWN = 6;
#define FB_LIGHT_GREY = 7;
#define FB_DARK_GREY = 8;
#define FB_LIGHT_BLUE = 9;
#define FB_LIGHT_GREEN = 10;
#define FB_LIGHT_CYAN = 11;
#define FB_LIGHT_RED = 12;
#define FB_LIGHT_MAGENTA = 13;
#define FB_LIGHT_BROWN = 14;
#define FB_WHITE = 15;
#endif
