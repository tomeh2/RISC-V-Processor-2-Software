volatile unsigned short* led_base = (unsigned short*) 0x30000000;
volatile unsigned char* uart_div_l_reg = (unsigned char*) 0x10000000;
volatile unsigned char* uart_div_h_reg = (unsigned char*) 0x10000001;
volatile unsigned char* uart_tx_data_reg = (unsigned char*) 0x10000002;
volatile unsigned char* uart_status_reg = (unsigned char*) 0x10000003;	//READ ONLY!

char message[64] = "Hello World! But now using SB to store data\n\r\0";

void send(char* buf)
{
	for (unsigned int i = 0; buf[i] != '\0'; i++)
	{
		while(*uart_status_reg == 1);
		*uart_tx_data_reg = buf[i];
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
	int counter = 1;
	while(1)
	{
		send(message);
		*led_base = counter++;
		wait(1000000);
	}
}
