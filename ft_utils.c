#include "ft_printf.h"

void	ft_putuint_pf(unsigned int num, size_t *counter)
{
	char	*str;

	str = ft_aux_pf(num, "0123456789");
	ft_putstr_pf(str, counter);
	free(str);
}

void	ft_putstr_pf(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_pf(*str, counter);
		str++;
	}
}

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_address;

	// Sprawdzenie, czy wskaźnik to NULL
	if (ptr == NULL)
	{
		ft_putstr_pf("0x0", counter);  // Poprawna reprezentacja NULL dla %p
		return;
	}
	ptr_address = (unsigned long)ptr;
	ft_putstr_pf("0x", counter);  // Zaczynamy od "0x"
	str = ft_aux_pf(ptr_address, HEX_LOW_BASE);  // Konwertujemy na system szesnastkowy
	ft_putstr_pf(str, counter);  // Wyświetlamy
	free(str);  // Zwolnienie pamięci
}


void	ft_putnbr_pf(int num, size_t *counter)
{
	if (num == -2147483648)
	{
		ft_putnbr_pf((num / 10), counter);
		ft_putchar_pf('8', counter);
	}
	else if (num < 0)
	{
		ft_putchar_pf('-', counter);
		ft_putnbr_pf(-num, counter);
	}
	else
	{
		if (num > 9)
			ft_putnbr_pf((num / 10), counter);
		ft_putchar_pf(('0' + num % 10), counter);
	}
}

void	ft_puthex_pf(unsigned int num, size_t *counter, char *base)
{
	char	*str;

	str = ft_aux_pf(num, base);
	ft_putstr_pf(str, counter);
	free(str);
}

void	ft_putchar_pf(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}
