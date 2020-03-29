#ifndef PAGE_UTILITIES_FUCK_YEAH_THIS_WAS_SO_HARD_TO_GET_TO
#define PAGE_UTILITIES_FUCK_YEAH_THIS_WAS_SO_HARD_TO_GET_TO
#define PAGE_TABLE_ENTRIES_SIZE_BYTES 4096
#define PAGE_TABLE_SIZE_BYTES 4096 * 1024
#define PAGE_ENTRY_SIZE  0x1000
#define PAGE_ENTRY_AMOUNT 1024
#define PAGE_TABLE_ENTRY_LINE_INDEX(address) (address/PAGE_TABLE_ENTRIES_SIZE_BYTES)
#define PAGE_DIRECTORY_ENTRY_INDEX(line_index) ((unsigned int) line_index/ (unsigned int) PAGE_ENTRY_AMOUNT)
#define PAGE_TABLE_ENTRY_INDEX(line_index) ((unsigned int) line_index % (unsigned int) PAGE_ENTRY_AMOUNT)

//Mask out all bytes except the 
#define PAGE_TABLE_PRESENT(page_directory_entry) (0xfffffffe & page_directory_entry)
#endif
