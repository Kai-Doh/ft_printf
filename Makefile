# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 16:59:45 by ktiomico          #+#    #+#              #
#    Updated: 2024/10/09 01:19:48 by ktiomico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS =	src/ft_printf_hex.c \
		src/ft_printf_pointer.c \
		src/ft_printf.c \
		src/ft_printf_utils.c \
		libft/ft_itoa.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c

OBJS =	$(SRCS:.c=.o)

CC =	gcc

CFLAGS = -Wall -Wextra -Werror -g -I./include

RM =	rm -rf

EXE =	ft_printf

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) $(EXE)

re:	fclean all

exe:	$(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

.PHONY:	all clean fclean re
