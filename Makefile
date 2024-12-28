# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmorente <mmorente@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 09:21:10 by mmorente          #+#    #+#              #
#    Updated: 2024/12/28 12:33:06 by mmorente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

LIB = ar rcs

SRC = ft_print_uns_numb.c ft_print_hex_may.c ft_print_hex.c ft_print_ptr.c ft_printf.c \
		ft_printnb.c ft_printstr.c ft_putchar.c

INCLUDE = ft_printf.h

OBJ_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c $(INCLUDE)
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -fr $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
