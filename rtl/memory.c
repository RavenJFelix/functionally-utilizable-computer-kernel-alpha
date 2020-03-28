#include "memory.h"
#include "paging.h"
#include "math.h"

pageframe_t memalloc(unsigned long amount_of_bytes)
{
	double frames_needed = CEILING((double)amount_of_bytes /0x1000);
	return kcontinuous_alloc(frames_needed);
}

void memfree(pageframe_t first_address)
{
	kfree_frame(first_address);
}
void memfree_cont(pageframe_t first_address, unsigned long amount_of_bytes)
{

	double frames_needed = CEILING((double)amount_of_bytes /0x1000);
	kfree_frames(first_address, frames_needed);
}
