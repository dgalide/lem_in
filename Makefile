# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgalide <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 17:42:00 by dgalide           #+#    #+#              #
#    Updated: 2016/05/31 15:58:45 by dgalide          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRC = main.c

LIBFT = libft/libft.a

SRCO = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror



all: .c.o

re: fclean all

.c.o: 
	make -C libft
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LIBFT)

clean:
	make clean -C libft
	rm -rf $(SRCO)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

.PHONY: all re clean fclean
