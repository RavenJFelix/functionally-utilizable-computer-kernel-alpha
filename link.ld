ENTRY(loader) /* name of the entry label*/
SECTIONS
{
	. = 0x00100000; /*Load the coad at 1mb */

	.text ALIGN (0x1000) :
	{
		*(.text) /*Put all text sections here*/
	}

	.rodata ALIGN(0x1000): 
	{
		*(.rodata*)
	}


	.data ALIGN(0x1000):
	{
		*(.data)
	}

	.bss ALIGN(0x1000):
	{
		*(COMMON)
		*(.bss)
	}
}
