#ifndef KEYBOAORD_STUFF_H
#define KEYBOAORD_STUFF_H
#include "bool.h"
#include "io.h"
#define KEYBOARD_DATA_PORT 0x60
typedef struct
{
	bool caps;
}Keyboard;

unsigned char keyboard_read_scan_code();

void keyboard_init();
#endif
