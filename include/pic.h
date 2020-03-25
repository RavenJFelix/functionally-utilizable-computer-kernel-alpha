#ifndef PCI_STUFF
#define PCI_STUFF
#include "io.h"

#define PIC1_PORT_A 0x20
#define PIC2_PORT_A 0xa0

#define PIC1_START_INTERRUPT 0x20
#define PIC2_START_INTERRUPT 0x28
#define PIC2_END_INTERRUPT PIC2_START_INTERRUPT + 7;

#define PIC_ACK 0x20

void pic_remap(int offset1, int offset2);
void pic_send_eoi();
#endif
