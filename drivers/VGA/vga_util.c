#include "vga_util.h"
#include "vga_const.h"

#include "bool.h"

bool fb_line_pos_exceeds_max(unsigned int line_pos)
{
	return (line_pos > FB_MAX_LINE_POS);
}

struct uc_pair2d fb_char_line_pos_to_pair2d(unsigned int line_pos)
{
	unsigned char x = (char) (((line_pos/2) % FB_MAX_COLS)) ;
	unsigned char y = (char) ( ( ((line_pos/2) / FB_MAX_COLS)));
	return (struct uc_pair2d){x,y};
}
