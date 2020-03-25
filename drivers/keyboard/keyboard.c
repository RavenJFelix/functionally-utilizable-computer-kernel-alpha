#include "io.h"
#include "keyboard.h"
void keyboard_init(void)
{
	// )xfd = 11111101 which enables the keyboard)
	outb(0x21, 0xfd);
}
