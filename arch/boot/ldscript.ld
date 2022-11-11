ENTRY(_start)

SECTIONS 
{
	.kern_start_addr = .;

	.kern_code_start_addr = .;

	.code 0 :
	{
		*/boot/entry.S.o (.text*)
		
		*(.text*)
	}
	.kern_code_end_addr = .;
	
	.kern_data_start_addr = .;
	.data :
	{
		*(.rodata* .data*)
	}
	.kern_data_end_addr = .;
	
	.kern_bss_start_addr = .;
	.bss :
	{
		*(.bss*)
		
		. = ALIGN(4);
	}
	.kern_bss_end_addr = .;
	
	.kern_end_addr = .;
}