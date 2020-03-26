#include "keyboard_ascii_conversion.h"
#include "keyboard_scanset_1_const.h"

char keyboard_scancode_1_to_ascii_number(unsigned char scan_code)
{
	if(scan_code == KBDSC1_0_P)
	{
		return '0';
	}
	else
	{
		/* Ascii numbers start from 0 at 0x30
		 * However, the first scan set is number 1
		 * is starting from 0x02
		 * 
		 * Therefore 0x2f+0x02 = 0x31
		 * i.e. '1'
		 */
		return (scan_code + 0x2f);
	}
}
