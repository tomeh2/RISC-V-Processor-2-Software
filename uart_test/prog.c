#define WAIT_CYCLES 1000000

//The CPU does not yes support halfword and byte bus transfers so we have to live with 32-bit types and unaligned transfers
volatile unsigned int* led_base = (unsigned int*) 0x30000000;
volatile unsigned int* uart_div_l_reg = (unsigned int*) 0x10000000;
volatile unsigned int* uart_div_h_reg = (unsigned int*) 0x10000001;
volatile unsigned int* uart_tx_data_reg = (unsigned int*) 0x10000002;
volatile unsigned int* uart_status_reg = (unsigned int*) 0x10000003;	//READ ONLY!

char message[16] = "Hello World!\n\r\0\0";

void sendByte(unsigned int byte)
{
	while (*uart_status_reg != 0);
	
	*uart_tx_data_reg = byte;
}

void sendMessage()
{
	unsigned int* messagePtr = (unsigned int*) message;	//Needed to avoid generation of lbu instructions and to generate lw instead
	unsigned int curr_char;
	for (int i = 0; i < 4; i++)
	{
		curr_char = *messagePtr++;
		for (int j = 0; j < 4; j++)
		{
			sendByte(curr_char);
			curr_char >>= 8;
		}
	}
}

void initUART()
{
	*uart_div_l_reg = 0x0000009F;
	*uart_div_h_reg = 0x00000024;
}

void wait(unsigned int iters)
{
	for (volatile int i = 0; i < iters; i++);
}

void main()
{
	initUART();
	while(1)
	{
		sendMessage();
		wait(WAIT_CYCLES);
	}
}
