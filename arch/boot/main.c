#include <serial.h>

extern int main();

void startup(void)
{
	serial_init();
	
	print("Console initialized\n\r\0");
	
	main();
}