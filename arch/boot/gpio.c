#include <types.h>

static volatile uint32_t* gpio_i_reg = (volatile uint32_t*) GPIO_BASE_ADDR;
static volatile uint32_t* gpio_o_reg = (volatile uint32_t*) GPIO_BASE_ADDR;		

void gpio_write(uint32_t val)
{
	*gpio_o_reg = val;
}

uint32_t gpio_read()
{
	return *gpio_i_reg;
}

uint32_t gpio_read_bit(uint32_t bit_num)
{
	return (*gpio_i_reg >> bit_num) & 1;
}