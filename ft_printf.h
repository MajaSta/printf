#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// Prototyp funkcji ft_printf
int ft_printf(const char *format, ...);

// Funkcje pomocnicze dla poszczególnych konwersji
void ft_print_char(char c);
void ft_print_str(char *str);
void ft_print_pointer(unsigned long ptr);
void ft_print_int(int n);
void ft_print_unsigned(unsigned int n);
void ft_print_hex(unsigned int num, int uppercase);
void ft_print_percent(void);

#endif
