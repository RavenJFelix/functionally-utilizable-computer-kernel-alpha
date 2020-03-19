#ifndef IO_H
#define IO_H

/** outb:
 * Sends byte to the the I/O port
 * Definition in out.s
 * @param port 
 * @param data
 */
void  outb(unsigned short port, unsigned char data);

#endif
