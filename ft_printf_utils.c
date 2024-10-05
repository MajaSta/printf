#include "ft_printf.h"

// Funkcja drukująca pojedynczy znak
void ft_print_char(char c)
{
    write(1, &c, 1);
}


// Funkcja drukująca łańcuch znaków
void ft_print_str(char *str)
{
    if (!str)
        str = "(null)";
    while (*str)
        write(1, str++, 1);
}

#include "ft_printf.h"

// Funkcja drukująca adres wskaźnika w formacie heksadecymalnym
void ft_print_pointer(unsigned long ptr)
{
    write(1, "0x", 2);
    ft_print_hex(ptr, 0);
}
#include "ft_printf.h"

// Funkcja drukująca liczbę całkowitą
void ft_print_int(int n)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        ft_print_int(n / 10);
    char c = (n % 10) + '0';
    write(1, &c, 1);
}
#include "ft_printf.h"

#include "ft_printf.h"

// Funkcja drukująca liczbę bez znaku
void ft_print_unsigned(unsigned int n)
{
    if (n >= 10)
        ft_print_unsigned(n / 10);
    char c = (n % 10) + '0';
    write(1, &c, 1);
}
#include "ft_printf.h"

// Funkcja drukująca liczbę w formacie heksadecymalnym
void ft_print_hex(unsigned int num, int uppercase)
{
    const char *base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (num >= 16)
        ft_print_hex(num / 16, uppercase);
    write(1, &base[num % 16], 1);
}
#include "ft_printf.h"

// Funkcja drukująca znak procentu
void ft_print_percent(void)
{
    write(1, "%", 1);
}
