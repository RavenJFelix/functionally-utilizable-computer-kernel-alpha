#ifndef FUCKING_COOL_SCREEN_MANIPULATION_STUFF_H 
#define FUCKING_COOL_SCREEN_MANIPULATION_STUFF_H 
#include "pair2d.h"
void fb_clear_line(unsigned char line);
void fb_shift_up(unsigned int distance);
void fb_shift_up_cursor(unsigned int distance, uc_pair2d cursor_pos);
//void fb_shift_down(unsigned int distance);
#endif
