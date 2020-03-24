#ifndef SOME_FUCKING_AWESOME_VGA_UTILITIES
#define SOME_FUCKING_AWESOME_VGA_UTILITIES

#include "pair2d.h"
#include "vga_data_types.h"

#include "bool.h"

#define FB_CELL(cell_line_pos) *((char*) FRAME_BUFFER_ADR + cell_line_pos)
#define FB_LINE_POS(x, y) 2 * (FB_MAX_COLS * y + x)
#define FB_CURSOR_LINE_POS(x, y) (FB_MAX_COLS * y + x)
#define FB_COLOR_CODE_TO_UCHAR(fg, bg) ((fg & 0x0f) << 4) | (bg & 0x0f) //Takes two unsigned chars


uc_pair2d fb_char_line_pos_to_pair2d(unsigned int line_pos);

bool fb_line_pos_exceeds_max(unsigned int line_pos);



#endif
