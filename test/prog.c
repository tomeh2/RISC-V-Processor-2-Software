#define WAIT_CYCLES 200

void main()
{
	volatile unsigned int* led_base = (unsigned int*) 0x00000000;
	int i = 0;
	while (1)
	{
		if ((i & 0x7) == 0)
		{
			*led_base = 0x00000000;
		}
		else if ((i & 0x7) == 1)
		{
			*led_base = 0x00001111;
		}			
		else if ((i & 0x7) == 2)
		{
			*led_base = 0x00002222;
		}
		else if ((i & 0x7) == 3)
		{
			*led_base = 0x00003333;
		}
		else if ((i & 0x7) == 4)
		{
			*led_base = 0x00004444;
		}
		else if ((i & 0x7) == 5)
		{
			*led_base = 0x00005555;
		}
		else if ((i & 0x7) == 6)
		{
			*led_base = 0x00006666;
		}
		else if ((i & 0x7) == 7)
		{
			*led_base = 0x00007777;
		}

		
		for (volatile int j = 0; j < WAIT_CYCLES; j++);
		i++;
	}
}
