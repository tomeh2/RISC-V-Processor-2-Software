#include <serial.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

static char printbuf[BUFSIZE];

extern int vsprintf(char* s, const char* format, va_list list);

int printf(const char* format, int p, ...)
{
	size_t i;
	
	va_list list;
	va_start(list, p);
	i = vsprintf(printbuf, format, list);
	print(printbuf);
	va_end(list);
	return i;
}