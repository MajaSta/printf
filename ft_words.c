/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiszkie <wmiszkie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:37:00 by wmiszkie          #+#    #+#             */
/*   Updated: 2024/07/31 19:37:00 by wmiszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_putcharacter_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}

void	ft_string(char *str, int *length)
{
	size_t		i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putcharacter_length(str[i], length);
		i++;
	}
}
