#ifndef	HOLY_SHIT_THESE_ARE_GLOBAL_VARIABLES_USED_BY_THE_KERNEL_FUCK_OH_FUCK_THE_MAGICNESS_
#define	HOLY_SHIT_THESE_ARE_GLOBAL_VARIABLES_USED_BY_THE_KERNEL_FUCK_OH_FUCK_THE_MAGICNESS_
#include "terminal.h"
#include "keyboard.h"
#include "ring_buffer.h"
#define KERNEL_KEYBOARD_BUFFER_SIZE 256
void kernel_globals_init();
extern Terminal main_terminal;
extern uc_ring_buffer kernel_keyboard_buffer;
extern unsigned char kernel_keyboard_buffer_data[KERNEL_KEYBOARD_BUFFER_SIZE];
extern Keyboard kernel_keyboard;
#endif
