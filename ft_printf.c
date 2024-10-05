#include "ft_printf.h"

// Główna funkcja ft_printf obsługująca wszystkie konwersje
int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
                ft_print_char(va_arg(args, int));
            else if (format[i] == 's')
                ft_print_str(va_arg(args, char *));
            else if (format[i] == 'p')
                ft_print_pointer((unsigned long)va_arg(args, void *));
            else if (format[i] == 'd' || format[i] == 'i')
                ft_print_int(va_arg(args, int));
            else if (format[i] == 'u')
                ft_print_unsigned(va_arg(args, unsigned int));
            else if (format[i] == 'x')
                ft_print_hex(va_arg(args, unsigned int), 0);
            else if (format[i] == 'X')
                ft_print_hex(va_arg(args, unsigned int), 1);
            else if (format[i] == '%')
                ft_print_percent();
        }
        else
            write(1, &format[i], 1);
        i++;
    }

    va_end(args);
    return count;
}
