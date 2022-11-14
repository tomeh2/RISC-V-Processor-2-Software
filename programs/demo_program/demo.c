#include <serial.h>
#include <gpio.h>
#include <string.h>
#include <stdarg.h>

extern int vsprintf(char* s, const char* format, va_list list);

//static char str_left[] = "Moved left\n\r\0"; 
//static char str_right[] = "Moved right\n\r\0"; 
//static char idle[] = "Idle\n\r\0";
static char iter[] = "Iter: \0";
static char pos[] = "Position: \0";
static char sep[] = " | \0";

static char padding[] = "000";

static int printf(const char* format, int p, ...)
{
	char printbuf[256];
	size_t i;
	
	va_list list;
	va_start(list, p);
	i = vsprintf(printbuf, format, list);
	print(printbuf);
	va_end(list);
	return i;
}

void wait()
{
	for (volatile int i = 0; i < 100; i++);
}

void main()
{
	char text_out[64];
	text_out[0] = '\0';
	
	char int_hex_conv[9];
	
	unsigned int curr_pos = 0;
	unsigned int led_val = 1;
	unsigned int test = 0xFAFAFAFA;
	
	unsigned int counter = 0;
	while(1)
	{
		if (gpio_read_bit(0) && curr_pos > 0)
		{
			//print(str_right);
			led_val >>= 1;
			curr_pos--;
		}
		else if (gpio_read_bit(1) && curr_pos < 15)
		{
			//print(str_left);
			led_val <<= 1;
			curr_pos++;
		}
		/*else
		{
			print(idle);
		}*/
		gpio_write(led_val);
		wait();
		
		text_out[0] = '\0';
		strncat(text_out, iter, 1000);
		itoh(counter, int_hex_conv);
		strncat(text_out, int_hex_conv, 1000);
		strncat(text_out, sep, 1000);
		strncat(text_out, pos, 1000);
		itoh(curr_pos, int_hex_conv);
		strncat(text_out, int_hex_conv, 1000);
		strncat(text_out, "\r\n\0", 2);
		print(text_out);
		
		counter++;
		
		printf("Printf test: %x\n\r\0", test, counter);
	}
	padding[0]++;
}