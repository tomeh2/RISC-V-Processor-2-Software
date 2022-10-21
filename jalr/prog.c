#define WAIT_CYCLES 100

void main()
{
	volatile unsigned int* led_base = (unsigned int*) 0x00000000;
	int i = 0;
	while (1)
	{
		if (i & 0x1)
		{
			*led_base = 0xFFFF;
		}
		else
		{
			*led_base = 0xAAAA;
		}
		
		for (volatile int i = 0; i < WAIT_CYCLES; i++);
		i++;
	}
}
