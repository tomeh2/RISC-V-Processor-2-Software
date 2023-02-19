#include <types.h>

#define DLR 0		/* Divisor low */
#define DHR 4		/* Divisor high */
#define TXR 8		/* Transmit register */
#define STR 12		/* Status register */

static volatile int32_t* dlr_reg = (volatile int32_t*) (UART_BASE_ADDR + DLR);
static volatile int32_t* dhr_reg = (volatile int32_t*) (UART_BASE_ADDR + DHR);
static volatile int32_t* txr_reg = (volatile int32_t*) (UART_BASE_ADDR + TXR);
static volatile int32_t* str_reg = (volatile int32_t*) (UART_BASE_ADDR + STR);

void serial_init()
{
	// 115200 baud rate @ 100 MHz
	*dlr_reg = (volatile int32_t) 0x64;
	*dhr_reg = (volatile int32_t) 0x03;
	
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
