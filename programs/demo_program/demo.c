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
		printf("1\n\r", test);
		if (gpio_read_bit(0) && curr_pos > 0)
		{
			printf("2\n\r", test);
			//print(str_right);
			led_val >>= 1;
			curr_pos--;
		}
		else if (gpio_read_bit(1) && curr_pos < 15)
		{
			printf("3\n\r", test);
			//print(str_left);
			led_val <<= 1;
			curr_pos++;
		}
		/*else
		{
			print(idle);
		}*/
		gpio_write(led_val);
		printf("4\n\r", test);
		wait();
		printf("5\n\r", test);
		
		text_out[0] = '\0';
		strncat(text_out, iter, 1000);
		itoh(counter, int_hex_conv);
		printf("6\n\r", test);
		strncat(text_out, int_hex_conv, 1000);
		printf("7\n\r", test);
		strncat(text_out, sep, 1000);
		printf("8\n\r", test);
		strncat(text_out, pos, 1000);
		printf("9\n\r", test);
		itoh(curr_pos, int_hex_conv);
		printf("10\n\r", test);
		strncat(text_out, int_hex_conv, 1000);
		printf("11\n\r", test);
		strncat(text_out, "\n\r\0", 2);
		printf("12\n\r", test);
		print(text_out);
		printf("13\n\r", test);
		counter++;
		
		int x = counter * 3;
		
		printf("14\n\r", test);
		printf("Printf test: %d\n\r\0", test, x);
		printf("15\n\r", test);
	}
	padding[0]++;
}