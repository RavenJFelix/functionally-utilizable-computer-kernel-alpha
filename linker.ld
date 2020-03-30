ENTRY(_start)

SECTIONS
{
	/*pUT SECTIONS AT 1 MiB
	 It's a cool place to loa */
	. = 0xC0100000;
	 _virtual_kernel_start = .;
	 _physical_kernel_start = . - 0xC0000000;

	.text ALIGN(0x1000): AT(ADDR(.text) - 0xC0000000)
	{
		*(.multiboot)
		*(.text)
	}

	.rodata ALIGN(0x1000): AT(ADDR(.rodata) - 0xC0000000)

	{
		*(.rodata)
	}

	.data  ALIGN(0x1000):  AT(ADDR(.data) - 0xC0000000)
	{
		*(.data)
	}

	.bss ALIGN(0x1000): AT(ADDR(.bss) - 0xC0000000)
	{
		*(COMMON)
		*(.bss)
		_virtual_kernel_end = .;
		_physical_kernel_end = . - 0xC0000000;
	}
}
