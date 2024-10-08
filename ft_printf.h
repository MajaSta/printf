#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *format, ...);

void ft_putcharacter_length(char character, int *length);
void ft_string(char *str, int *length);
void ft_number(int number, int *length);
void ft_unsigned_int(unsigned int u, int *length);
void ft_hexadecimal(unsigned int x, int *length, char x_or_x);
void ft_pointer(unsigned long long pointer, int *length);

#endif

