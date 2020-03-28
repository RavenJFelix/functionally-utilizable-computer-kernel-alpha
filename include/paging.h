#ifndef PAGING_STUFF_H
#define PAGING_STUFF_H
#define PAGE_FREE 0x01
#define PAGE_USED 0x00
typedef void* pageframe_t;

pageframe_t kcontinuous_alloc(unsigned long number_of_continous_frames);
void kfree_frame(pageframe_t page_address);

#endif
