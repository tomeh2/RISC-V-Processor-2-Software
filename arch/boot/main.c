#include <serial.h>

extern int main();

extern char _data_rom_start, _data_start, _data_end, _bss_start, _bss_end;

static void memory_init()
{
		// Copy .data section to RAM
		char* src = &_data_rom_start;
		char* curr = &_data_start;
		
		while (curr < &_data_end)
			*curr++ = *src++;
		
		// Zero .bss
		curr = &_bss_start;
		
		while (curr < &_bss_end)
			*curr++ = 0;
}

void startup(void)
{
	memory_init();
	serial_init();
	
	print("Console initialized\n\r\0");
	
	main();
}