#ifndef VGA_TTY_STRING_FUCK_H
#define VGA_TTY_STRING_FUCK_H
#include "pair2d.h"
#include "vga_tty.h"
void fb_write_string_direct(struct uc_pair2d pos, const char* str, const struct fb_color_code color_code);
void fb_write_string_direct_noNull(struct uc_pair2d pos, const char* string, unsigned int len, struct fb_color_code color_code);
void fb_write_string_wrap_auto(struct uc_pair2d pos, const char *str, const struct fb_color_code color_code);
void fb_write_string_wrap_direct(struct uc_pair2d pos, const char *str, const struct fb_color_code color_code);
void fb_write_string_wrap_safe(struct uc_pair2d pos, const char *str, const struct fb_color_code color_code);
#endif
