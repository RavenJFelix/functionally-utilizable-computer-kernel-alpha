#include "bool.h"

#include "keyboard_scanset_1_const.h"
#include "io.h"
#include "keyboard.h"
void keyboard_init(void)
{
	// )xfd = 11111101 which enables the keyboard)
	outb(0x21, 0xfd);
}

unsigned char keyboard_read_scan_code()
{
	return inb(KEYBOARD_DATA_PORT);
}

bool keyboard_scancode_1_is_ascii(unsigned char scan_code)
{
	if
		(keyboard_scancode_1_is_ascii_number(scan_code) 
		&& keyboard_scancode_1_is_ascii_alphabet_character(scan_code)
	  )
	{
		return true;
	}
	else
	{
		return false;
	}
	//Check if scan code is a number scan code

}

bool keyboard_scancode_1_is_ascii_number(unsigned char scan_code)
{
	if(KBDSC1_1_P <= scan_code && scan_code <= KBDSC1_0_P)
		return true;
	else
		return false;
}
bool keyboard_scancode_1_is_ascii_alphabet_character(unsigned scan_code)
{
	//Certain regiosn of the scan codes are continuous, so as long as the scan
	//code is within the range, it is valid
	//QWERTYUIOP
	if(KBDSC1_Q_P <= scan_code && scan_code <= KBDSC1_P_P)
	{
		return true;
	}
	//ASDFGHJKL
	else if(KBDSC1_A_P <= scan_code && scan_code <= KBDSC1_L_P)
	{
		return true;
	}
	//ZXCVBNM
	else if(KBDSC1_Z_P <= scan_code && scan_code <= KBDSC1_M_P)
	{
		return true;
	}
	else
	{
	return false;
	}

}
