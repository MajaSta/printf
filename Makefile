CC = gcc

CFLAGS = -g 

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
