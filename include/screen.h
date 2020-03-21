#ifndef SCREEN_H
#define SCREEN_H
#include "vga_data_types.h"
#include "vga_tty_string.h"
#include "vga_const.h"
#include "bool.h"
#include "pair2d.h"

#define FB_BYTE(x) *((char*) FRAME_BUFFER_ADR + x)
#define FB_LINE_POS(x, y) 2 * (FB_MAX_COLS * y + x)
#define FB_CURSOR_LINE_POS(x, y) (FB_MAX_COLS * y + x)
#define FB_COLOR_CODE_TO_UCHAR(fg, bg) ((fg & 0x0f) << 4) | (bg & 0x0f) //Takes two unsigned chars

bool line_pos_exceeds_max(unsigned int line_pos);
struct uc_pair2d fb_char_line_pos_to_pos(unsigned int line_pos);
struct uc_pair2d fb_char_line_pos_to_pos(unsigned int line_pos);
void fb_clear_line(unsigned char line);
void fb_moveCursor(struct uc_pair2d pos);
void fb_shift_down(unsigned int distance);
void fb_shift_up(unsigned int distance);
#endif
