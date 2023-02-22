#include <types.h>
#include <string.h>
#include <stdarg.h>

int vsnprintf(char* s, size_t n, const char* format, va_list list)
{
	size_t bytes_written = 0;
	while (n > 0 && *format != '\0')
	{
		if (*format != '%') 
			*s++ = *format++;
		else
		{
			char number_str[16];
			format++;
			switch (*format)
			{
				case 'x':
					itoh(va_arg(list, int32_t), number_str);
					s = strcpy(s, number_str);
					break;
				case 'd':
					itoa(va_arg(list, int32_t), number_str, 10);
					s = strcpy(s, number_str);
					break;
				case 'c':
					*s++ = (int8_t) va_arg(list, int32_t);
					break;
				default:
					*s++ = '0';
			}
			format++;
		}
		
		bytes_written++;
		n--;
	}
	*s = '\0';
	
	return bytes_written;
}

int vsprintf(char* s, const char* format, va_list list)
{
	return vsnprintf(s, UINT_MAX, format, list);
}