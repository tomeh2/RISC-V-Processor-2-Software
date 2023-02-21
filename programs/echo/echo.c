#include <stdio.h>
#include <serial.h>

static char padding[] = "00";

int main()
{
	char uart_rx_byte;
	while (1)
	{
		
		while (!read_byte(&uart_rx_byte));
		while (!write_byte(&uart_rx_byte));
	}
	padding[0]++;
}