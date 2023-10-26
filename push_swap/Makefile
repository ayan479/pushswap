# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayan <mayan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 20:53:20 by mayan             #+#    #+#              #
#    Updated: 2023/10/25 20:28:28 by mayan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c\
			radix.c\
			utils/utils1.c\
			utils/parse.c\
			utils/ft_atoi.c\
			utils/ft_substr.c\
			utils/ft_split.c\
			utils/ft_calloc.c\
			utils/smallsort.c\
			operations/pa.c\
			operations/pb.c\
			operations/ra.c\
			operations/rb.c\
			operations/rr.c\
			operations/rra.c\
			operations/rrb.c\
			operations/rrr.c\
			operations/sa.c\
			operations/sb.c\
			operations/ss.c\

OBJ	= $(addprefix obj/, $(SRC:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: obj $(NAME)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(OBJ) $(PRINTF) -o $(NAME)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -rf obj
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re obj