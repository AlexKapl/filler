LIB     = libft/
NAME    = filler
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

SRCS    = main.c ft_parsing_filler.c ft_pars_detect_figure.c \
            ft_put_figure.c ft_analiz.c ft_do_shield.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@$(CC) $(CFLAGS) $(SRCS) $(LIB)libftprintf.a -o $(NAME)
	@cp $(NAME) resources/players/

.c.o:
	@printf "[CC] %s                                                  \r" $<
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@make -C $(LIB) clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C $(LIB) fclean
	@rm -rf $(NAME)

re: fclean all