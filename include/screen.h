#ifndef SCREEN_H
#define SCREEN_H
#include "vga_const.h"
#include "bool.h"
#include "pair2d.h"

#define FB_BYTE(x) *((char*) FRAME_BUFFER_ADR + x)
#define FB_LINE_POS(x, y) 2 * (FB_MAX_COLS * y + x)
#define FB_CURSOR_LINE_POS(x, y) (FB_MAX_COLS * y + x)
#define FB_COLOR_CODE_STRUCT_TO_UCHAR(fg, bg) ((fg & 0x0f) << 4) | (bg & 0x0f) //Takes two unsigned chars

struct fb_color_code
{
	unsigned char fg;
	unsigned char bg;
};

bool line_pos_exceeds_max(unsigned int line_pos);
struct uc_pair2d fb_char_line_pos_to_pos(unsigned int line_pos);
struct uc_pair2d fb_char_line_pos_to_pos(unsigned int line_pos);
void fb_clear_line(unsigned char line);
void fb_moveCursor(struct uc_pair2d pos);
void fb_shift_down(unsigned int distance);
void fb_shift_up(unsigned int distance);
void fb_write_char(unsigned int line_pos, char c, unsigned char color_code);
void fb_write_char_abstract(struct uc_pair2d pos, char c, struct fb_color_code color_code);
void fb_write_char_fast(unsigned char x, unsigned char y, char c, unsigned char fg, unsigned char bg);
void fb_write_char_simp(unsigned int line_pos, char c);
void fb_write_string_direct(struct uc_pair2d pos, const char* str, const struct fb_color_code color_code);
void fb_write_string_direct_noNull(struct uc_pair2d pos, const char* string, unsigned int len, struct fb_color_code color_code);
void fb_write_string_wrap_auto(struct uc_pair2d pos, const char *str, const struct fb_color_code color_code);
void fb_write_string_wrap_direct(struct uc_pair2d pos, const char *str, const struct fb_color_code color_code);
void fb_write_string_wrap_safe(struct uc_pair2d pos, const char *str, const struct fb_color_code color_code);

void fb_write_string_direct(struct uc_pair2d pos, const char* str, const struct fb_color_code color_code);
#endif
