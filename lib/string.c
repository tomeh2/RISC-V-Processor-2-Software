#include <types.h>

static char* hexMap = "0123456789ABCDEF";

/* Returns a hexadecimal representation of the number as a string */
char* itoh(int n, char* buffer)
{
	buffer[8] = '\0';
	int i = 7;
	while (i >= 0)
	{
		buffer[i] = hexMap[n & 0xF];
		n >>= 4;
		i--;
	}
	return buffer;
}

size_t strlen(const char* str)
{
	size_t len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

char* strncat(char* dest, const char* src, size_t size)
{
	while (*dest != '\0') dest++;
		
	while (*src != '\0' && size > 0)
	{
		*dest++ = *src++;
		size--;
	}
	
	*dest = '\0';
	
	return dest;
}

char* strcpy(char* dest, char* src)
{
	while (*src != '\0')
		*dest++ = *src++;
	
	*dest = '\0';
	
	return dest;
}