#ifndef FUCKING_COOL_SCREEN_MANIPULATION_STUFF_H 
#define FUCKING_COOL_SCREEN_MANIPULATION_STUFF_H 

void fb_clear_line(unsigned char line);
void fb_shift_up(unsigned int distance);
void fb_shift_up_cursor(unsigned int distance, struct uc_pair2d cursor_pos);
//void fb_shift_down(unsigned int distance);
#endif
