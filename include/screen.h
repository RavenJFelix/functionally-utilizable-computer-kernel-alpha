#ifndef SCREEN_H
#define SCREEN_H
#include "vga_data_types.h"
#include "vga_tty_string.h"
#include "vga_const.h"
#include "bool.h"
#include "pair2d.h"

void fb_clear_line(unsigned char line);
void fb_moveCursor(struct uc_pair2d pos);
void fb_shift_down(unsigned int distance);
void fb_shift_up(unsigned int distance);
#endif
