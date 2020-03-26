#include "keyboard.h"
#include "keyboard_validification.h"
#include "keyboard_ascii_conversion.h"
#include "keyboard_scanset_1_const.h"

char keyboard_scancode_1_to_ascii(Keyboard *keyboard, unsigned char scan_code)
{
	if(keyboard_scancode_1_is_ascii_number(scan_code))
	{
		return keyboard_scancode_1_to_ascii_number(scan_code);
	}
	else if(keyboard_scancode_1_is_ascii_letter(scan_code))
	{
		return keyboard_scancode_1_to_ascii_letter(scan_code, keyboard->caps);
	}
}

char keyboard_scancode_1_to_ascii_letter(unsigned char scan_code, bool caps)
{
	if(caps)
	{
		return keyboard_scancode_1_to_ascii_letter_uppercase(scan_code);
	}
	else
	{
		return keyboard_scancode_1_to_ascii_letter_lowercase(scan_code);
	}

}
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

char keyboard_scancode_1_to_ascii_letter_lowercase(unsigned char scan_code)
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
	return 0x20 + keyboard_scancode_1_to_ascii_letter_uppercase(scan_code);


}
char keyboard_scancode_1_to_ascii_letter_uppercase(unsigned char scan_code)
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
	 */

	switch(scan_code)
	{
		case KBDSC1_A_P:
		return 'A';

		case KBDSC1_B_P:
		return 'B';

		case KBDSC1_C_P:
		return 'C';

		case KBDSC1_D_P:
		return 'D';
		
		case KBDSC1_E_P:
		return 'E';
		
		case KBDSC1_F_P:
		return 'F';

		case KBDSC1_G_P:
		return 'G';

		case KBDSC1_H_P:
		return 'H';

		case KBDSC1_I_P:
		return 'I';

		case KBDSC1_J_P:
		return 'J';

		case KBDSC1_K_P:
		return 'K';

		case KBDSC1_L_P:
		return 'L';

		case KBDSC1_M_P:
		return 'M';

		case KBDSC1_N_P:
		return 'N';
		
		case KBDSC1_O_P:
		return 'O';

		case KBDSC1_P_P:
		return 'P';

		case KBDSC1_Q_P:
		return 'Q';

		case KBDSC1_R_P:
		return 'R';

		case KBDSC1_S_P:
		return 'S';

		case KBDSC1_T_P:
		return 'T';

		case KBDSC1_U_P:
		return 'U';

		case KBDSC1_V_P:
		return 'V';

		case KBDSC1_W_P:
		return 'W';

		case KBDSC1_X_P:
		return 'X';

		case KBDSC1_Y_P:
		return 'Y';

		case KBDSC1_Z_P:
		return 'Z';
	}

}
