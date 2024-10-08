/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiszkie <wmiszkie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:56:32 by wmiszkie          #+#    #+#             */
/*   Updated: 2024/04/22 15:08:48 by wmiszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putcharacter_length(char character, int *length);
void	ft_string(char *args, int *length);
void	ft_number(int number, int *length);
void	ft_hexadecimal(unsigned int x, int *length, char x_or_x);
void	ft_unsigned_int(unsigned int u, int *length);
void	ft_pointer(unsigned long long pointer, int *length);

int		ft_printf(const char *string, ...);

#endif
