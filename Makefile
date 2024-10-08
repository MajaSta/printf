# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmiszkie <wmiszkie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 12:56:40 by wmiszkie          #+#    #+#              #
#    Updated: 2024/04/22 15:08:47 by wmiszkie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftprintf.a

SRCS	= ./sources/ft_printf.c \
	   	./sources/ft_numbers.c \
		./sources/ft_words.c \

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