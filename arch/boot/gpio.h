#pragma once

#include <types.h>

void gpio_write(uint32_t val);
uint32_t gpio_read();
uint32_t gpio_read_bit(uint32_t pos);