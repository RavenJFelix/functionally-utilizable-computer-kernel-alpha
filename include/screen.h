#ifndef SCREEN_H
#define SCREEN_H
#include "bool.h"
#include "pair2d.h"
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

#define FB_MAX_ROWS 25
#define FB_MAX_COLS 80

#define FRAME_BUFFER_ADR 0x000b8000
#define FB_BYTE(x) *((char*) FRAME_BUFFER_ADR + x)
#define FB_LINE_POS(x, y) 2 * (FB_MAX_COLS * y + x)
#define FB_CURSOR_LINE_POS(x, y) (FB_MAX_COLS * y + x)
#define FB_COLOR_CODE_STRUCT_TO_UCHAR(fg, bg) ((fg & 0x0f) << 4) | (bg & 0x0f) //Takes two unsigned chars

#define FB_MAX_LINE_POS (FB_LINE_POS(79, 24))
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


void fb_write_string_wrap_auto(struct uc_pair2d pos, const char *str, const struct fb_color_code color_code);
void fb_write_string_wrap_safe(struct uc_pair2d pos, const char *str, const struct fb_color_code color_code);
struct uc_pair2d fb_char_line_pos_to_pos(unsigned int line_pos);
void fb_write_char_simp(unsigned int line_pos, char c);
bool line_pos_exceeds_max(unsigned int line_pos);
void fb_write_string_wrap_direct(struct uc_pair2d pos, const char *str, const struct fb_color_code color_code);
struct uc_pair2d fb_char_line_pos_to_pos(unsigned int line_pos);
void fb_write_char(unsigned int line_pos, char c, unsigned char color_code);
void fb_write_char_fast(unsigned char x, unsigned char y, char c, unsigned char fg, unsigned char bg);
void fb_write_char_abstract(struct uc_pair2d pos, char c, struct fb_color_code color_code);
void fb_moveCursor(struct uc_pair2d pos);
void fb_write_string_direct_noNull(struct uc_pair2d pos, const char* string, unsigned int len, struct fb_color_code color_code);
void fb_write_string_direct(struct uc_pair2d pos, const char* str, const struct fb_color_code color_code);
void fb_shift_up(unsigned int distance);
void fb_shift_down(unsigned int distance);
void fb_clear_line(unsigned char line);

void fb_write_string_direct(struct uc_pair2d pos, const char* str, const struct fb_color_code color_code);
#endif
