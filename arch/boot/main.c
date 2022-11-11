#include <console.h>

extern int main();

void startup(void)
{
	console_init();
	
	print("Console initialized\n\r\0");
	
	main();
}