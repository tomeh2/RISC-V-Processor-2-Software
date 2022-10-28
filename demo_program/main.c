static char str_left[] = "Moved left\n\r\0"; 
static char str_right[] = "Moved right\n\r\0"; 
static char idle[] = "Idle\n\r\0";

extern void init_uart();
extern unsigned int gpio_read_bit(unsigned int);
extern void gpio_write(unsigned int);
extern void send_string(char*);

void wait()
{
	for (volatile int i = 0; i < 500000; i++);
}

void main()
{
	init_uart();
	
	unsigned int curr_pos = 0;
	unsigned int led_val = 1;
	while(1)
	{
		if (gpio_read_bit(0) && curr_pos > 0)
		{
			send_string(str_right);
			led_val >>= 1;
			curr_pos--;
		}
		else if (gpio_read_bit(1) && curr_pos < 15)
		{
			send_string(str_left);
			led_val <<= 1;
			curr_pos++;
		}
		else
		{
			send_string(idle);
		}
		gpio_write(led_val);
		wait();
	}
}