#include "paging.h"
#include "kernel_globals.h"

#define PAGE_FRAME_ADDRESS(i) (FIRST_FRAME_ADDRESS + (i * 0x1000))
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

void kfree_frames(pageframe_t first_page_address, unsigned long total_to_free)
{
	for(unsigned long i = 0; i < total_to_free; ++i)
	{
		kfree_frame((i * 0x1000) + first_page_address);

	}
}

pageframe_t kcontinuous_alloc(unsigned long number_of_continous_frames)
{
	pageframe_t first_frame;

	unsigned long continuous_frames_left = number_of_continous_frames;
	unsigned long index = 0;
	while(continuous_frames_left > 0)
	{
		if(index == KERNEL_DYNAMIC_MEMORY_PAGES)
		{
			//We've fucked up if this happens
			return 0;
		}
		if(kernel_frame_map[index] == PAGE_FREE)
		{
			if(continuous_frames_left == number_of_continous_frames)
			{
				first_frame = PAGE_FRAME_ADDRESS(index);
			}
			else
			{
				--continuous_frames_left;
			}
		}
		else
		{
			continuous_frames_left = number_of_continous_frames;
		}
	}
	return first_frame;
}
