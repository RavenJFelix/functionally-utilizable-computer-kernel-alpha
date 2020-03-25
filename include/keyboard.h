#ifndef KEYBOAORD_STUFF_H
#define KEYBOAORD_STUFF_H
#include "io.h"
#define KEYBOARD_DATA_PORT 0x60

unsigned char read_scan_code();

void keyboard_init();
#endif
