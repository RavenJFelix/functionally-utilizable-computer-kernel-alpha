#include "io.h"

// I/O ports
//
/* All io ports are relative to the data port
 * All serial poorts have their ports iin the same
 * oroder but different value
 */

#define SERIAL_COM1_BASE 0x3f8 //COM1 base port
#define SERIAL_DATA_PORT(base) (base)
#define SERIAL_FIFO_COMMAND_PORT(base) (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base) (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base) (base + 5)

/* SERIAL_LINE_DLAB
 * Tells the serial port to expec the highest 8 bits,
 * after that, the lower bits will follow
 */
#define SERIAL_LINE_ENABLE_DLAB 0x80

/**serial_configure_baud_rate
 * Sets the speed of the data being sent. The default speed
 * is 115,000 bits/s The argument divides the number
 * If the input sent is 4, then the transmission speed
 * is 115,200 / 4
 */

void serial_configure_baud_rate(unsigned short com_port, unsigned short divisor)
{
	outb(SERIAL_LINE_COMMAND_PORT(com_port), SERIAL_LINE_ENABLE_DLAB); //Tells to expend the first 8 bits
	outb(SERIAL_DATA_PORT(com_port), (divisor >> 8) & 0x00ff);
	outb(SERIAL_DATA_PORT(com_port), (divisor & 0x00ff));
}


void serial_configure_line_default(unsigned short com)
{
	/* Bit 7 8 5 4 3 2 1 0
		Cond  b prty  s dl
		Val 0 0 0 0 0 0 1 1 = 0x03
	*/
		outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

