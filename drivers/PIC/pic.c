#include "io.h"
#include "pic.h"
#define PIC1_PORT_A 0x20
#define PIC2_PORT_A 0xa0


#define PIC1_COMMAND PIC1_PORT_A
#define PIC1_DATA (PIC1_PORT_A+1)
#define PIC2_COMMAND PIC2_PORT_A
#define PIC2_DATA (PIC2_PORT_A+1)
#define PIC1_START_INTERRUPT 0x20
#define PIC2_START_INTERRUPT 0x28
#define PIC2_END_INTERRUPT PIC2_START_INTERRUPT + 7;

#define ICW1_ICW4 0x01
#define ICW1_SINGLE 0x02
#define ICW1_INTERVAL4 0x04
#define ICW1_LEVEL 0x08
#define ICW1_INIT 0x10

#define ICW4_8086 0x01
#define ICW4_AUTO 0x02
#define ICW4_BUF_SLAVE 0x08
#define ICW4_BUF_MASTER 0x0c
#define ICW4_SUPPORT_FULLY_NESTED 0x10

#define PIC_ACK 0x20



void pic_remap(int offset1, int offset2)
{
	unsigned char a1;
	unsigned char a2;

	a1 = inb(PIC1_DATA);
	a2 = inb(PIC2_DATA);

	outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
	outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

	outb(PIC1_DATA, offset1);
	outb(PIC2_DATA, offset2);

	outb(PIC1_DATA, 4);
	outb(PIC2_DATA, 2);

	outb(PIC1_DATA, ICW4_8086);

	outb(PIC2_DATA, ICW4_8086);

	outb(PIC1_DATA, a1);
	outb(PIC2_DATA, a2);
}

