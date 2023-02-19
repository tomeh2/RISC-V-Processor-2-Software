#include <types.h>

static char* hexMap = "0123456789ABCDEF";

void reverse(char* buffer, size_t size)
{
	char temp;
	
	int left = 0;
	int right = size - 1;
	while (right - left > 0)
	{	
		temp = buffer[left];
		buffer[left] = buffer[right];
		buffer[right] = temp;
		
		right--;
		left++;
	}
}

/* Returns a signed integer as a string */
void itoa(int n, char* buffer, int radix)
{
	char* buff_orig = buffer;
	int chars_copied = 0;
	char neg = n < 0 ? 1 : 0;
	
	if (n == 0)
	{
		*buffer++ = '0';
		chars_copied = 1;
	}
	else
	{
		while (n > 0)
		{
			*buffer++ = (n % 10) + 48;
			n /= 10;
			chars_copied++;
		}
	
		if (neg)
		{
			*buffer++ = '-';
			chars_copied++;
		}
	}
	
	*buffer = '\0';
	
	reverse(buff_orig, chars_copied);
}

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