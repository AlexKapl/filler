# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 11:15:59 by akaplyar          #+#    #+#              #
#    Updated: 2017/06/09 17:05:20 by akaplyar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = filler.h

LIB_HEADER = $(LIB_PATH)libft.h

CC = @gcc

LIB_PATH = ./libft/

CFLAGS = -Wall -Wextra -Werror

MAKE_LIB = $(MAKE) -C $(LIB_PATH)

OBJ = main.o reader.o checker.o placer.o

.PHONY: clean fclean re

NAME = filler

all:  lib $(OBJ) $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(OBJ) -I $(HEADER) $(LIB_PATH)libft.a
	@echo "\x1B[32m\0filler created\x1B[0m\0"

fill:
	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ./filler

fil:
	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ./filler_bonus/filler

$(OBJ): $(HEADER)

lib:
#	$(MAKE_LIB)

clean:
#	$(MAKE_LIB) clean
	@rm -rf $(OBJ)
	@echo "\x1B[31m\0filler objects cleared\x1B[0m\0"

fclean: clean
#	$(MAKE_LIB) fclean
	@rm -rf $(NAME)
	@echo "\x1B[31m\0filler deleted\x1B[0m\0"

re: fclean all
