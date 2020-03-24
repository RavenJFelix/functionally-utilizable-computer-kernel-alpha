#ifndef VGA_COLOR_CONSTANTS_H
#define VGA_COLOR_CONSTANTS_H
#include "vga_util.h"
#define VGA_BLACK  0
#define VGA_BLUE  1
#define VGA_GREEN  2
#define VGA_CYAN  3
#define VGA_RED  4
#define VGA_MAGENTA  5
#define VGA_BROWN  6
#define VGA_LIGHT_GREY  7
#define VGA_DARK_GREY  8
#define VGA_LIGHT_BLUE  9
#define VGA_LIGHT_GREEN  10
#define VGA_LIGHT_CYAN  11
#define VGA_LIGHT_RED  12
#define VGA_LIGHT_MAGENTA  13
#define VGA_LIGHT_BROWN  14
#define VGA_WHITE  15

#define FB_WHITE_BLACK FB_COLOR_CODE(VGA_WHITE, VGA_BLACK)
#define FB_MATRIX_COLORZ FB_COLOR_CODE(VGA_BLACK, VGA_LIGHT_GREEN)
#define FB_BSOD FB_COLOR_CODE(VGA_WHITE, VGA_BLUE)
//Convenience constants
#endif
