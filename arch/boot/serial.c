#include <types.h>

#define DLR 0		/* Divisor low */
#define DHR 1		/* Divisor high */
#define TXR 2		/* Transmit register */
#define STR 3		/* Status register */

static volatile int8_t* dlr_reg = (volatile int8_t*) (UART_BASE_ADDR + DLR);
static volatile int8_t* dhr_reg = (volatile int8_t*) (UART_BASE_ADDR + DHR);
static volatile int8_t* txr_reg = (volatile int8_t*) (UART_BASE_ADDR + TXR);
static volatile int8_t* str_reg = (volatile int8_t*) (UART_BASE_ADDR + STR);

void serial_init()
{
	// 115200 baud rate @ 100 MHz
	*dlr_reg = (volatile int8_t) 0x64;
	*dhr_reg = (volatile int8_t) 0x03;
	
	//*dlr_reg = (volatile int8_t) 0x05;
	//*dhr_reg = (volatile int8_t) 0x00;
}

void print(char* str)
{
	for (uint32_t i = 0; str[i] != '\0'; i++)
	{
        while (*str_reg == 1) {}
		*txr_reg = str[i];
	}
}
