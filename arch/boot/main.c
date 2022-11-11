#include <console.h>

int main(void)
{
	console_init();
	print("Hello World!\0");
	
	while(1);
}