#ifndef FUCKING_AWESOME_RING_BUFFERS_YEAH
#define FUCKING_AWESOME_RING_BUFFERS_YEAH

typedef struct 
{
	unsigned int length;
	unsigned char *data;//
	unsigned int front;//Array location to be written to when enqueue
	unsigned int back;//Array index for dequeue to access

}uc_ring_buffer;

unsigned int buffer_wrapped_increment(unsigned int index, unsigned int max_length);
#endif
