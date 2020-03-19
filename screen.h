#ifndef SCREEN_H
#define SCREEN_H
#include "pair2d.h"
void fb_write_char_pos(struct uc_pair2d pos, char c, unsigned char fg, unsigned char bg);
void fb_write_char(unsigned char x, unsigned char y, char c, unsigned char fg, unsigned char bg);
void fb_moveCursor(struct uc_pair2d pos);
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