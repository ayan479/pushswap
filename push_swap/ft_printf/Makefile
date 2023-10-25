# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayan <mayan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 16:21:47 by mayan             #+#    #+#              #
#    Updated: 2023/09/25 19:07:40 by mayan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putpointer.c \
	   ft_putuns.c ft_puthex.c ft_printf.c \

OBJS = $(SRCS:%.c=%.o)

CC = cc

FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re