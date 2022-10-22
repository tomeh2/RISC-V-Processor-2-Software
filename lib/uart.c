static volatile unsigned char* uart_div_l_reg = (unsigned char*) 0x10000000;
static volatile unsigned char* uart_div_h_reg = (unsigned char*) 0x10000001;
static volatile unsigned char* uart_tx_data_reg = (unsigned char*) 0x10000002;
static volatile unsigned char* uart_status_reg = (unsigned char*) 0x10000003;

// Hardcoded for 9600 baud @ 90 MHz
void init_uart()
{
	*uart_div_l_reg = 0x9F;
	*uart_div_h_reg = 0x24;
	
	//*uart_div_l_reg = 0x03;
	//*uart_div_h_reg = 0x00;
}

void send_char(char c)
{
	while (*uart_status_reg == 1);
	*uart_tx_data_reg = c;
}

int send_char_nonblock(char c)
{
	if (uart_status_reg == 0)
	{
		*uart_tx_data_reg = c;
		return 0;
	}
	else
		return -1;
}

void send_string(char* str)
{
	for (unsigned int i = 0; str[i] != '\0'; i++)
        send_char(str[i]);
}