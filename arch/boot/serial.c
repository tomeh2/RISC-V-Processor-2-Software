#include <types.h>

#define DLR 0		/* Divisor low */
#define DHR 4		/* Divisor high (write) | RX reg (read) */
#define TXR 8		/* Transmit register */
#define STR 12		/* Status register */

static volatile int32_t* dlr_reg = (volatile int32_t*) (UART_BASE_ADDR + DLR);
static volatile int32_t* dhr_rxr_reg = (volatile int32_t*) (UART_BASE_ADDR + DHR);
static volatile int32_t* txr_reg = (volatile int32_t*) (UART_BASE_ADDR + TXR);
static volatile int32_t* str_reg = (volatile int32_t*) (UART_BASE_ADDR + STR);

void serial_init()
{
	// 115200 baud rate @ 100 MHz
	*dlr_reg = (volatile int32_t) 0x64;
	*dhr_rxr_reg = (volatile int32_t) 0x03;
	
	//*dlr_reg = (volatile int8_t) 0x05;
	//*dhr_rxr_reg = (volatile int8_t) 0x00;
}

void print(char* str)
{
	for (uint32_t i = 0; str[i] != '\0'; i++)
	{
        while (*str_reg == 1) {}
		*txr_reg = str[i];
	}
}

int write_byte(char* data)
{
	if (*str_reg & 0x1)		// TX Active
		return 0;
	*txr_reg = *data;
	return 1;
}

int read_byte(char* data)
{
	if (*str_reg & 0x2)
	{
		*data = *dhr_rxr_reg;
		return 1;
	}
	return 0;
}