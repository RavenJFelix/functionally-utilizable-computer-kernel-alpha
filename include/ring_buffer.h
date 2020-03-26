#ifndef FUCKING_AWESOME_RING_BUFFERS_YEAH
#define FUCKING_AWESOME_RING_BUFFERS_YEAH
#include "bool.h"
typedef struct 
{
	unsigned int length;
	unsigned char *data;//
	unsigned int front;//Array location to be written to when enqueue
	unsigned int back;//Array index for dequeue to access

}uc_ring_buffer;

unsigned int buffer_wrapped_increment(unsigned int index, unsigned int max_length);

void uc_ring_buffer_enqueue(uc_ring_buffer *buffer, unsigned char incoming);
unsigned char uc_ring_buffer_dequeue(uc_ring_buffer *buffer);
bool uc_ring_buffer_empty(uc_ring_buffer *buffer);
bool uc_ring_buffer_full(uc_ring_buffer *buffer);
unsigned char uc_ring_buffer_read_front(uc_ring_buffer *buffer);
unsigned char uc_ring_buffer_read_back(uc_ring_buffer *buffer);
#endif
