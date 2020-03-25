#ifndef INTERRUPT_STUFF_H
#define INTERRUPT_STUFF_H
typedef struct
{
	unsigned short int offset_lowerbit;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type_attr;
} idt_entry;
typedef struct
{
	unsigned int eax;
	unsigned int ecx;
	unsigned int edx;
	unsigned int ebx;
	unsigned int esp;
	unsigned int ebp;
	unsigned int esi;
	unsigned int edi;

}__attribute__((packed)) cpu_state;

typedef struct
{
	unsigned int error_code;
	unsigned int eip;
	unsigned int cs;
	unsigned int eflags;
}__attribute__((packed)) stack_state;

void interrupt_handler(cpu_state cpu, stack_state stack, unsigned int interrupt);
#endif
