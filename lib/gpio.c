static volatile unsigned int* gpio_i_reg = (unsigned int*) 0x30000000;		// IN ONLY
static volatile unsigned int* gpio_o_reg = (unsigned int*) 0x30000000;		// OUT ONLY

void gpio_write(unsigned int val)
{
	*gpio_o_reg = val;
}

unsigned int gpio_read()
{
	return *gpio_i_reg;
}

unsigned int gpio_read_bit(unsigned int bit_num)
{
	return (*gpio_i_reg >> bit_num) & 1;
}