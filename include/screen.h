#ifndef SCREEN_H
#define SCREEN_H
#include "pair2d.h"
struct fb_color_code
{
	unsigned char fg;
	unsigned char bg;
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


/*
const unsigned char BLACK =  0;
const unsigned char BLUE = 1;
const unsigned char GREEN = 2;
const unsigned char CYAN = 3;
const unsigned char RED = 4;
const unsigned char MAGENTA = 5;
const unsigned char BROWN = 6;
const unsigned char LIGHT_GREY = 7;
const unsigned char DARK_GREY = 8;
const unsigned char LIGHT_BLUE = 9;
const unsigned char LIGHT_GREEN = 10;
const unsigned char LIGHT_CYAN = 11;
const unsigned char LIGHT_RED = 12;
const unsigned char LIGHT_MAGENTA = 13;
const unsigned char LIGHT_BROWN = 14;
const unsigned char WHITE = 15;
*/
#endif
