# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 16:59:45 by ktiomico          #+#    #+#              #
#    Updated: 2024/10/12 15:49:34 by ktiomico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS =	src/ft_printf.c \
		src/ft_printf_utils.c \
		src/ft_printf_utils2.c \
		src/parsing.c \
		src/render_char.c \
		src/render_str.c \
		src/render_unint.c \
		src/render_hex.c \
		src/render_add.c \
		src/render_nbr.c \
		libft/ft_memset.c \
		libft/ft_strlen.c

MAIN =	main.c
OBJS =	$(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF_DIR = ./
OBJSM = $(MAIN:.c=.o)
INCLUDE = -I./include -I./libft
CC =	gcc

CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

RM =	rm -rf

EXE =	ft_printf_test

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

mclean: clean fclean
	$(RM) $(EXE)

exe:	$(EXE)

$(EXE): $(MAIN)
	$(CC) $(CFLAGS) -g $(INCLUDE) -o ft_printf_test $(MAIN) $(LIBFTPRINTF_DIR)libftprintf.a $(LIBFT_DIR)/libft.a

.PHONY:	all clean fclean re
