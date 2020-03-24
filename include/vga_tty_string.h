#ifndef VGA_TTY_STRING_FUCK_H
#define VGA_TTY_STRING_FUCK_H
#include "pair2d.h"
#include "vga_tty.h"
void fb_write_string_direct( uc_pair2d pos, const char* str, const  fb_color_code color_code);
void fb_write_string_direct_noNull( uc_pair2d pos, const char* string, unsigned int len,  fb_color_code color_code);
void fb_write_string_wrap_auto( uc_pair2d pos, const char *str, const  fb_color_code color_code);
void fb_write_string_wrap_auto_cursor( uc_pair2d pos, const char *str, const  fb_color_code color_code);
void fb_write_string_wrap_direct( uc_pair2d pos, const char *str, const  fb_color_code color_code);
void fb_write_string_wrap_safe( uc_pair2d pos, const char *str, const  fb_color_code color_code);
#endif
