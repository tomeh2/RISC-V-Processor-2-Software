#define WAIT_CYCLES 1000000
#define NUM_ITER 8

//The CPU does not yes support halfword and byte bus transfers so we have to live with 32-bit types and unaligned transfers
volatile unsigned int* led_base = (unsigned int*) 0x30000000;
volatile unsigned int* uart_div_l_reg = (unsigned int*) 0x10000000;
volatile unsigned int* uart_div_h_reg = (unsigned int*) 0x10000001;
volatile unsigned int* uart_tx_data_reg = (unsigned int*) 0x10000002;
volatile unsigned int* uart_status_reg = (unsigned int*) 0x10000003;	//READ ONLY!

volatile int* ram_32 = (int*) 0x20000000;							//SW & LW
volatile short* ram_16 = (short*) 0x20000000;						//SH & LH
volatile unsigned short* ram_u16 = (unsigned short*) 0x20000000;	//SH & LHU
volatile  char* ram_8 = (char*) 0x20000000;		//SB & LB
volatile unsigned char* ram_u8 = (unsigned char*) 0x20000000;		//SB & LBU

void test_32()
{
	for (int i = 0; i < NUM_ITER; i++)
	{
		*(ram_32 + i) = i + 1;
	}
	
	for (int i = 0; i < NUM_ITER; i++)
	{
		*(ram_32 + i) = *(ram_32 + i) + 100;
	}
}

void test_16()
{
	for (int i = 0; i < NUM_ITER; i++)
	{
		*(ram_16 + i) = i - 100;
	}
	
	for (int i = 0; i < NUM_ITER; i++)
	{
		*(ram_16 + i) = *(ram_16 + i) + 1000;
	}
}

void test_u16()
{
	for (int i = 0; i < NUM_ITER; i++)
	{
		*(ram_u16 + i) = i + 1;
	}
	
	for (int i = 0; i < NUM_ITER; i++)
	{
		*(ram_u16 + i) = *(ram_u16 + i) + 100;
	}
}

void test_8()
{
	for (int i = 0; i < NUM_ITER; i++)
	{
		*(ram_8 + i) = i + 1;
	}
	
	for (int i = 0; i < NUM_ITER; i++)
	{
		*(ram_8 + i) = *(ram_8 + i) + 100;
	}
}

void test_u8()
{
	for (int i = 0; i < NUM_ITER; i++)
	{
		*(ram_u8 + i) = i + 1;
	}
	
	for (int i = 0; i < NUM_ITER; i++)
	{
		*(ram_u8 + i) = *(ram_u8 + i) + 200;
	}
}

void main()
{
	while (1)
	{
		*led_base = 0x00000001;
		test_32();
		*led_base = 0x00000002;
		test_16();
		*led_base = 0x00000003;
		test_u16();
		*led_base = 0x00000004;
		test_8();
		*led_base = 0x00000005;
		test_u8();
		*led_base = 0x00000006;
	}
}