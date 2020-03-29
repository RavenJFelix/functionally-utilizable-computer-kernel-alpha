#include "kernel_globals.h"
#include "memory.h"
#include "paging_util.h"

//This will allocate and not stop. it will overwite anything and everything
//including those you love. If there is nothing to write on, it will make sure
//there will be something to write on. And if not, you are fucked.
void kpage_allocate_range_direct(unsigned long virtual_address_start, unsigned long virtual_address_end, unsigned long physical_address_start)
{
	//These determine the stop and start in the virtual tablez
	unsigned long page_index_start = PAGE_TABLE_ENTRY_LINE_INDEX(virtual_address_start);
	unsigned long page_index_end = PAGE_TABLE_ENTRY_LINE_INDEX(virtual_address_end);

	unsigned long current_linear_page_index = page_index_start;
	do
	{
		//Multiply by 0x1000 because that's the size of the pagez
		unsigned long current_physical_address = physical_address_start + ((current_linear_page_index - page_index_start) * 0x1000); 
		//These are the indicies that the page table and page
		//directory will access
		unsigned int page_directory_index =  PAGE_DIRECTORY_ENTRY_INDEX(current_linear_page_index);
		unsigned page_table_index = PAGE_TABLE_ENTRY_INDEX(current_linear_page_index);
		
		//If there's nothing to write to. Make somemthing to write to.
		if(!PAGE_TABLE_PRESENT(kernel_page_directory[page_directory_index] ))
		{
			unsigned long *page_table_address =(unsigned long*) memalloc(PAGE_TABLE_SIZE_BYTES);
			unsigned long new_directory_entry = (unsigned long)page_table_address | 0x3;
		
			kernel_page_directory[page_directory_index] = new_directory_entry;
		}

		unsigned long *page_table =(unsigned long*) (kernel_page_directory[page_directory_index] & 0xfffff000);
		page_table[page_table_index] = current_physical_address ;

		++current_linear_page_index;
	}while(current_linear_page_index <= page_index_end);

}	
