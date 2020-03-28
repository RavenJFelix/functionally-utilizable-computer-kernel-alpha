#include "paging.h"

#include "kernel_globals.h"
static pageframe_t kalloc_frame_int()
{
	unsigned long i = 0;
	while(kernel_frame_map[i] != PAGE_FREE)
	{
		++i;
		//If there are no available pages we are fucked
		if(i == KERNEL_DYNAMIC_MEMORY_PAGES)
		{
			//We are fucked.
			return 0;
		}
	}
	kernel_frame_map[i] = PAGE_USED;
	return(FIRST_FRAME_ADDRESS + (i * 0x1000));
}

pageframe_t kalloc_frame()
{
	static unsigned char allocate =1 ;
	static unsigned char pframe = 0;
	static pageframe_t pre_frames[20];
	pageframe_t ret;

	if(pframe == 20)
	{
		allocate = 1;
	}

	if(allocate == 1)
	{
		for(int i = 0; i < 20; ++i)
		{
			pre_frames[i] = kalloc_frame_int();
		}
	}
	ret = pre_frames[pframe];
	++pframe;
	return ret;
}

void kfree_frame(pageframe_t page_address)
{
	page_address = (void*)(page_address - FIRST_FRAME_ADDRESS);
	unsigned long index;
	if(page_address == 0)
	{
		index = (unsigned long) page_address;
	}
	else
	{
		index = (unsigned long)((unsigned long)page_address /0x1000);
	}
	kernel_frame_map[index] = PAGE_FREE;
}
