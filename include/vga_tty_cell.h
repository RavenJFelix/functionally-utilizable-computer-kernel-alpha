#ifndef VGA_TTY_CHAR_H
#define VGA_TTY_CHAR_H
#include "screen.h"
/** Writes to cell like fb_write_cell() but uses structs for a better interface
 */
void fb_write_cell_abstract(struct uc_pair2d pos, char c, struct fb_color_code color_code);
/** Writes character to framebuffer with color
 */
void fb_write_cell(unsigned int line_pos, char c, unsigned char color_code);
/** Writes character but does not change the background
 */
void fb_write_char(unsigned int cell_line_pos, char c);
/** Changes cell's color to the color code
 */
void fb_write_color(unsigned int cell_line_pos, unsigned char color_code);
#endif
