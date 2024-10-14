# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 16:59:45 by ktiomico          #+#    #+#              #
#    Updated: 2024/10/14 13:10:20 by ktiomico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	src/ft_printf.c \
		src/ft_printf_utils.c \
		src/ft_printf_utils2.c \
		src/ft_printf_utils3.c \
		src/parsing.c \
		src/render_char.c \
		src/render_str.c \
		src/render_str2.c \
		src/render_unint.c \
		src/render_hex.c \
		src/render_add.c \
		libft/ft_memset.c \
		libft/ft_strlen.c \
		src/render_nbr.c \
		libft/ft_itoa.c \
		libft/ft_memcmp.c \
		libft/ft_strncmp.c

MAIN =	main.c

OBJS =	$(SRCS:.c=.o)

OBJSM = $(MAIN:.c=.o)

CC =	gcc

CFLAGS = -Wall -Wextra -Werror -g -I./include

RM =	rm -rf

EXE =	ft_printf

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	clean fclean all

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME) $(EXE)

re:	fclean all

mclean: clean fclean
	$(RM) $(OBJSM)

exe:	$(EXE)

$(EXE): $(OBJS) $(OBJSM)
	$(CC) $(CFLAGS) $(OBJS) $(OBJSM) -o $(EXE)

.PHONY:	all clean fclean re
