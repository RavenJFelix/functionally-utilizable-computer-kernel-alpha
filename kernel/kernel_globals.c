#include "kernel_globals.h"
#include "terminal.h"

#include "vga_const.h"
#include "vga_const_color.h"
Terminal main_terminal = {{0,0}, {FB_MAX_COLS, FB_MAX_ROWS}, FB_MATRIX_COLORZ };
