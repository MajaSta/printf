void	ft_pointer(unsigned long long pointer, int *length)
{
	char	string[25];
	int		i;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	if (!pointer)
	{
		*length += write(1, "(nil)", 5);
		return ;
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
}ft_hexadecimal(unsigned int x, int *length, char x_or_x)
{
	char	string[25];
	char	*base_character;
	int		i;

	if (x_or_x == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putcharacter_length('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putcharacter_length(string[i], length);
}

void	ft_unsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, length);
	ft_putcharacter_length(u % 10 + '0', length);
}# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmiszkie <wmiszkie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 12:56:40 by          #+#    #+#              #
#    Updated: 2024/04/         ###   ########.fr        #
#                                                                              #
# ******************************NAME	= libftprintf.a

SRCS	= ft_printf.c \
f	  ft_numbers.c \
		ft_words.c \

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
