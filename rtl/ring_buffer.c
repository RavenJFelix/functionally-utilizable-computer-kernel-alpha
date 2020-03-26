#include "bool.h"
#include "ring_buffer.h"

void uc_ring_buffer_increment_front(uc_ring_buffer *buffer)
{
	buffer->front = buffer_wrapped_increment(buffer->front, buffer->length);
}

void uc_ring_buffer_increment_back(uc_ring_buffer *buffer)
{

	buffer->back = buffer_wrapped_increment(buffer->back, buffer->length);
}

void uc_ring_buffer_enqueue(uc_ring_buffer *buffer, unsigned char incoming)
{
	buffer->data[buffer->front] = incoming;
	uc_ring_buffer_increment_front(buffer);
}

unsigned char uc_ring_buffer_dequeue(uc_ring_buffer *buffer)
{
	unsigned char outgoing = buffer->data[buffer->back];
	uc_ring_buffer_increment_back(buffer);
	return outgoing;
}

bool uc_ring_buffer_empty(uc_ring_buffer *buffer)
{
	return (buffer->front == buffer->back);
}

bool uc_ring_buffer_full(uc_ring_buffer *buffer)
{
	unsigned int new_back = buffer_wrapped_increment(buffer->back, buffer->length);
	return (new_back == buffer->front);
}

unsigned int buffer_wrapped_increment(unsigned int index, unsigned int max_length)
{
	return (++index) % max_length;
}

