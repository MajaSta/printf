#include "ft_printf.h"

void ft_number(int number, int *length)
{
    if (number == -2147483648)
    {
        write(1, "-2147483648", 11);
        (*length) += 11;
        return;
    }
    if (number < 0)
    {
        ft_putcharacter_length('-', length);
        ft_number(-number, length);
    }
    else
    {
        if (number > 9)
            ft_number(number / 10, length);
        ft_putcharacter_length(number % 10 + '0', length);
    }
}

void ft_unsigned_int(unsigned int u, int *length)
{
    if (u >= 10)
        ft_unsigned_int(u / 10, length);
    ft_putcharacter_length(u % 10 + '0', length);
}

void ft_hexadecimal(unsigned int x, int *length, char x_or_x)
{
    char *base_character = (x_or_x == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
    if (x == 0)
    {
        ft_putcharacter_length('0', length);
        return;
    }
    if (x > 0)
    {
        ft_hexadecimal(x / 16, length, x_or_x);
        ft_putcharacter_length(base_character[x % 16], length);
    }
}

void ft_pointer(unsigned long long pointer, int *length)
{
    char string[25];
    int i = 0;
    char *base_character = "0123456789abcdef";

    if (!pointer)
    {
        *length += write(1, "(nil)", 5);
        return;
    }
    write(1, "0x", 2);
    (*length) += 2;
    while (pointer != 0)
    {
        string[i++] = base_character[pointer % 16];
        pointer = pointer / 16;
    }
    while (i--)
    {
        ft_putcharacter_length(string[i], length);
    }
}
