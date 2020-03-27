#ifndef KEYBOARD_VALIDIFICATION_SHIT_H
#define KEYBOARD_VALIDIFICATION_SHIT_H

#include "bool.h"

bool keyboard_scancode_1_is_ascii(unsigned char scan_code);

bool keyboard_scancode_1_is_ascii_number(unsigned char scan_code);

bool keyboard_scancode_1_is_ascii_letter(unsigned char scan_code);

bool keyboard_scancode_1_pressed_is_ascii_non_top_row_symbol(unsigned char scan_code);
#endif
