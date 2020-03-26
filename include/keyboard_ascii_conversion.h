#ifndef KEYBOARD_ASCII_CONVERSION_RANDOMNESS_STUFF
#define KEYBOARD_ASCII_CONVERSION_RANDOMNESS_STUFF
#include "bool.h"
#include "keyboard.h"
char keyboard_scancode_1_pressed_to_ascii_number(unsigned char scan_code);
char keyboard_scancode_1_pressed_to_ascii_letter_uppercase(unsigned char scan_code);
char keyboard_scancode_1_pressed_to_ascii_letter_lowercase(unsigned char scan_code);
char keyboard_scancode_1_pressed_to_ascii_letter(unsigned char scan_code, bool caps);
char keyboard_scancode_1_pressed_to_ascii(Keyboard *keyboard, unsigned char scan_code);
char keyboard_scancode_1_pressed_to_ascii_letter_uppercase(unsigned char scan_code);
#endif
