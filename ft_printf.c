/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-be <adiaz-be@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:37:56 by adiaz-be          #+#    #+#             */
/*   Updated: 2022/10/13 15:40:08 by adiaz-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstr_pf(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_putuint_pf(va_arg(va, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_puthex_pf(va_arg(va, unsigned int), counter, HEX_LOW_BASE);
		else
			ft_puthex_pf(va_arg(va, unsigned int), counter, HEX_UPP_BASE);
	}
	else if (*str == '%')
		ft_putchar_pf(*str, counter);
}

int	ft_printf(char const *str, ...)
{
	va_list		va;
	size_t		counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;  // Przechodzimy do kolejnego znaku po '%'
			if (*str)  // Upewniamy się, że znak po '%' istnieje
			{
				ft_format(va, (char *)str, &counter);  // Wywołanie funkcji formatowania
			}
			else
			{
				// Jeśli po '%' nie ma kolejnego znaku, przerywamy, bo to błąd formatu
				break;
			}
		}
		else
		{
			ft_putchar_pf(*str, &counter);  // Zwykły znak, który nie jest formatem
		}
		str++;  // Przejście do następnego znaku
	}
	va_end(va);
	return (counter);  // Zwracamy licznik znaków
}

