#pragma once

#include <types.h>

void reverse(char* buffer, size_t size);
char* itoh(int n, char* buffer);
void itoa(int n, char* buffer, int radix);
size_t strlen(const char* str);
char* strncat(char* dest, const char* src, size_t size);
char* strcpy(char* dest, char* src);