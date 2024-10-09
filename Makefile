NAME = libftprintf.a

SRCS =	src/ft_printf.c \
		src/ft_parse.c \
		src/ft_print.c \
		src/ft_print2.c \
		src/ft_utils.c \
		src/ft_utils2.c

MAIN =	src/main.c

OBJS =	$(SRCS:.c=.o)

OBJSM = $(MAIN:.c=.o)

CC =	gcc

CFLAGS = -Wall -Wextra -Werror -I./include

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

mclean: clean fclean
	$(RM) $(OBJSM)

exe:	$(EXE)

$(EXE): $(OBJS) $(OBJSM)
	$(CC) $(CFLAGS) $(OBJS) $(OBJSM) -o $(EXE)

.PHONY:	all clean fclean re
