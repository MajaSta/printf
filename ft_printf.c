#include "ft_printf.h"

static void ft_printf_checker(char s, va_list *args, int *length)
{
    if (s == 's')
        ft_string(va_arg(*args, char *), length);
    else if (s == 'd' || s == 'i')
        ft_number(va_arg(*args, int), length);
    else if (s == 'u')
        ft_unsigned_int(va_arg(*args, unsigned int), length);
    else if (s == 'x')
        ft_hexadecimal(va_arg(*args, unsigned int), length, 'x');
    else if (s == 'X')
        ft_hexadecimal(va_arg(*args, unsigned int), length, 'X');
    else if (s == 'p')
        ft_pointer(va_arg(*args, unsigned long long), length);
    else if (s == 'c')
        ft_putcharacter_length(va_arg(*args, int), length);
    else if (s == '%')
        ft_putcharacter_length('%', length);
}

int ft_printf(const char *string, ...)
{
    va_list args;
    int i = 0;
    int length = 0;

    va_start(args, string);
    while (string[i] != '\0')
    {
        if (string[i] == '%')
        {
            i++;
            ft_printf_checker(string[i], &args, &length);
            i++;
        }
        else
        {
            ft_putcharacter_length(string[i], &length);
            i++;
        }
    }
    va_end(args);
    return (length);
}
