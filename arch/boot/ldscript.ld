RAM_BASE_ADDR = 0x20000000;

ENTRY(_start)

SECTIONS 
{
	/* Kernel */

	kern_start_addr = .;

	_text_start = .;
	.text 0 :  AT(0)
	{
		*/boot/entry.S.o (.text*)
		
		*(.text*)
	}
	_text_end = .;
	
	_rodata_rom_start = ADDR(.text) + SIZEOF(.text);
	_rodata_start = .;
	.rodata _rodata_rom_start : AT(_rodata_rom_start)
	{
		*(.rodata*)
	}
	_rodata_end = .;
	
	_data_rom_start = ADDR(.text) + SIZEOF(.text) + SIZEOF(.rodata);
	_data_start = RAM_BASE_ADDR;
	.data RAM_BASE_ADDR : AT(_data_rom_start)
	{
		*(.data* .sdata*)
	}
	_data_end = .;

	_bss_rom_start = ADDR(.text) + SIZEOF(.text) + SIZEOF(.rodata) + SIZEOF(.data);
	_bss_start = RAM_BASE_ADDR + SIZEOF(.data);
	.bss (RAM_BASE_ADDR + SIZEOF(.data)) : 
	{
		*(.bss* .sbss*)
		
		. = ALIGN(4);
	}
	_bss_end = .;
	_bss_size = SIZEOF(.bss);
	
	bss_end_addr = .;
	
	kern_end_addr = .;
}