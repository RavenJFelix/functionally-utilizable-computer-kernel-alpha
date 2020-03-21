#ifndef VGA_CONST_H
#define VGA_CONST_H
#include "screen.h"
//Vga color codes
#define FB_COLOR_CODE(x, y) ((struct fb_color_code) {x, y})

#define FB_MAX_ROWS 25
#define FB_MAX_COLS 80

//Deal with vga device
#define FB_CURSE_COMMAND_PORT  0x3d4
#define FB_CURSE_DATA_PORT 0x3d5
//When placed into the command port, tells VGA whether it's the high bits or
//lower bits of the data placed into the data port
#define FB_CURSE_HIGH_COMMAND 14
#define FB_CURSE_LOW_COMMAND 15


//The final memory address that can be written to the fb
#define FB_MAX_LINE_POS (FB_LINE_POS(79, 24))

#define FRAME_BUFFER_ADR 0x000b8000
#endif
