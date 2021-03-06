#include "keyboard.h"
#include "keyboard_validification.h"
#include "keyboard_ascii_conversion.h"
#include "keyboard_scanset_1_const.h"

const char ascii_row_1_set[] = {"QWERTYUIOP"};
const char ascii_row_2_set[] = {"ASDFGHJKL"};
const char ascii_row_3_set[] = {"ZXCVBNM"};

const char ascii_number_symbol_set[] ={"!@#$%^&*()"};

void keyboard_scancode_1_call_pressed_and_released_main(void (*func) (unsigned char), unsigned char scan_code)
{
	(*func)(scan_code);
	//For the main block, scanset 1 repeats start at 0x80 for released
	(*func)(scan_code + 0x80);
}

char keyboard_scancode_1_pressed_to_top_row_symbols(unsigned char scan_code)
{
	/* scan set 1 for the number one is 0x02, thus it should be 0
	 * to access the first element and so forth
	 */
	return ascii_number_symbol_set[scan_code - 2];
}
char keyboard_scancode_1_pressed_to_non_top_row_symbols_caps(unsigned char scan_code)
{
	switch(scan_code)
	{
		case KBDSC1_BACK_TICK_P:
			return '~';
		case KBDSC1_MINUS_P:
			return '_';
		case KBDSC1_EQUAL_P:
			return '+';
		case KBDSC1_TAB_P:
			return '\t';
		case KBDSC1_LEFT_BRACKET_P:
			return '{';
		case KBDSC1_RIGHT_BRACKET_P:
			return '}';
		case KBDSC1_BACKSLASH_P:
			return '|';
		case KBDSC1_SEMICOLON_P:
			return ':';
		case KBDSC1_SINGLE_QUOTE_P:
			return '"';
		case KBDSC1_ENTER_P:
			return '\n';
		case KBDSC1_COMMA_P:
			return '<';
		case KBDSC1_PERIOD_P:
			return '>';
		case KBDSC1_FORWARD_SLASH_P:
			return '?';
		case KBDSC1_SPACE_P:
			return ' ';
	}
}
char keyboard_scancode_1_pressed_to_non_top_row_symbols(unsigned char scan_code)
{
	switch(scan_code)
	{
		case KBDSC1_BACK_TICK_P:
			return '`';
		case KBDSC1_MINUS_P:
			return '-';
		case KBDSC1_EQUAL_P:
			return '=';
		case KBDSC1_TAB_P:
			return '\t';
		case KBDSC1_LEFT_BRACKET_P:
			return '[';
		case KBDSC1_RIGHT_BRACKET_P:
			return ']';
		case KBDSC1_BACKSLASH_P:
			return '\\';
		case KBDSC1_SEMICOLON_P:
			return ';';
		case KBDSC1_SINGLE_QUOTE_P:
			return '\'';
		case KBDSC1_ENTER_P:
			return '\n';
		case KBDSC1_COMMA_P:
			return ',';
		case KBDSC1_PERIOD_P:
			return '.';
		case KBDSC1_FORWARD_SLASH_P:
			return '/';
		case KBDSC1_SPACE_P:
			return ' ';
	}
}

char keyboard_scancode_1_pressed_to_ascii(Keyboard *keyboard, unsigned char scan_code)
{

	if(keyboard_scancode_1_is_ascii_number(scan_code))
	{
		if(keyboard->caps)
		{
			return keyboard_scancode_1_pressed_to_top_row_symbols(scan_code);
		}
		else
		{
			return keyboard_scancode_1_pressed_to_ascii_number(scan_code);
		}
	}
	else if(keyboard_scancode_1_is_ascii_letter(scan_code))
	{
		return keyboard_scancode_1_pressed_to_ascii_letter(scan_code, keyboard->caps);
	}
	else
	{
		if(keyboard->caps)
		{
			return keyboard_scancode_1_pressed_to_non_top_row_symbols_caps(scan_code);
		}
		else
		{
			return keyboard_scancode_1_pressed_to_non_top_row_symbols(scan_code);
		}
	}
}

char keyboard_scancode_1_pressed_to_ascii_letter(unsigned char scan_code, bool caps)
{
	if(caps)
	{
		return keyboard_scancode_1_pressed_to_ascii_letter_uppercase(scan_code);
	}
	else
	{
		return keyboard_scancode_1_pressed_to_ascii_letter_lowercase(scan_code);
	}

}
char keyboard_scancode_1_pressed_to_ascii_number(unsigned char scan_code)
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

char keyboard_scancode_1_pressed_to_ascii_letter_lowercase(unsigned char scan_code)
{
	/* Repead after me:
	 * There can be hexadecimal hacks between ascii letters
	 * There can be hexadecimal hacks between ascii letters
	 * There can be hexadecimal hacks between ascii letters
	 * And I should fucking ackwnoledge that and move on.
	 *
	 * Fuck yeahh.
	 * In ascii, A is at 0x41 while a is at 0x61
	 * That equals 0x20
	 */
	return (char)(0x20 + keyboard_scancode_1_pressed_to_ascii_letter_uppercase(scan_code));


}
char keyboard_scancode_1_pressed_to_ascii_letter_uppercase(unsigned char scan_code)
{

	/* Repead after me:
	 * There is no hexademical hacks between scan codes and letters
	 * There is no hexademical hacks between scan codes and letters
	 * There is no hexademical hacks between scan codes and letters
	 * And I should fucking ackwnoledge that and move on.
	 *
	 * Or have a qwert array and then offset the scan codes. Wait.
	 * Time for some hackz!!!
	 * Wait. never mind.
	 * Fuck.
	 *
	 * The above is kept for historical reasons. There is a look
	 * up array. I just have to subract the offset. I am a fucking genius.
	 * And an idiot.
	 */

	/* Letters are grouped in rows wtihin the scan code.
	 * The first letter grouped is QWERTYUIOP
	 * Thus, if one were to subectract them such
	 * that the scancode Q is equal to 0
	 * One could feed that into an array to obtain Q and so forth
	 */
	
	//Check for ascii code row one
	if(KBDSC1_Q_P <= scan_code && scan_code <= KBDSC1_P_P)
	{
		return ascii_row_1_set[scan_code - KBDSC1_Q_P];
	}
	//Check for ascii code row two
	else if(KBDSC1_A_P <= scan_code && scan_code <= KBDSC1_L_P)
	{
		return ascii_row_2_set[scan_code - KBDSC1_A_P];
	}
	else if(KBDSC1_Z_P <= scan_code && scan_code <= KBDSC1_M_P)
	{
		return ascii_row_3_set[scan_code - KBDSC1_Z_P];
	}
}
