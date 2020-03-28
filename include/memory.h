#ifndef FUCKING_AWESOME_DYNAMIC_MEMORY_SHIT_THAT_EVERYONE_OWES_ME_FOR_IMPLEMENTING
#define FUCKING_AWESOME_DYNAMIC_MEMORY_SHIT_THAT_EVERYONE_OWES_ME_FOR_IMPLEMENTING
#include "page_frame.h"

pageframe_t memalloc(unsigned long amount_of_bytes);
void memfree(pageframe_t first_address);
void memfree_cont(pageframe_t first_address, unsigned long amount_of_bytes);
#endif
