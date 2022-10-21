#define WAIT_CYCLES 200

volatile unsigned int* led_base = (unsigned int*) 0x30000000;

void wait(unsigned int iters)
{
	for (volatile int i = 0; i < iters; i++);
}

void incr_led()
{
	for (int j = 0; j < 10; j++)
	{
		*led_base = (unsigned int) j;
		wait(WAIT_CYCLES);
	}
}

void blink_led()
{	
	for (int j = 0; j < 10; j++)
	{
		if ((j & 1) == 0)
		{
			*led_base = 0x0000FFFF;
		}
		else
			*led_base = 0x00000000;
		wait(WAIT_CYCLES);
	}
}

void main()
{
	while(1)
	{
		blink_led();
		wait(WAIT_CYCLES);
		incr_led();
		wait(WAIT_CYCLES);
	}
}
