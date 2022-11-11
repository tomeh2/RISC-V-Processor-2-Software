#include <console.h>
#include <gpio.h>

static char str_left[] = "Moved left\n\r\0"; 
static char str_right[] = "Moved right\n\r\0"; 
static char idle[] = "Idle\n\r\0";

void wait()
{
	for (volatile int i = 0; i < 250000; i++);
}

void main()
{
	unsigned int curr_pos = 0;
	unsigned int led_val = 1;
	while(1)
	{
		if (gpio_read_bit(0) && curr_pos > 0)
		{
			print(str_right);
			led_val >>= 1;
			curr_pos--;
		}
		else if (gpio_read_bit(1) && curr_pos < 15)
		{
			print(str_left);
			led_val <<= 1;
			curr_pos++;
		}
		else
		{
			print(idle);
		}
		gpio_write(led_val);
		wait();
	}
}