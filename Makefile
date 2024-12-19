# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmorente <mmorente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 09:21:10 by mmorente          #+#    #+#              #
#    Updated: 2024/12/19 10:32:57 by mmorente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

LIB = ar rcs

SRC = ft_print_dec_numb.c ft_print_hex_may.c ft_print_hex.c ft_print_ptr.c ft_printf.c \
		ft_printnb.c ft_printstr.c ft_putchar.c

INCLUDE = ft_printf.h

# Define la carpeta para los archivos objeto
OBJ_DIR = obj

# Genera la lista de objetos en la carpeta 'obj'
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Regla por defecto
all: $(OBJ_DIR) $(NAME)

# Generación del archivo final
$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

# Regla para compilar cada archivo fuente en su objeto correspondiente
$(OBJ_DIR)/%.o: %.c $(INCLUDE)
	cc $(CFLAGS) -c $< -o $@

# Regla para crear la carpeta 'obj' si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpiar los archivos objeto
clean:
	rm -fr $(OBJ_DIR)

# Limpiar el archivo ejecutable y los objetos
fclean: clean
	rm -f $(NAME)

# Recompilar todo (limpia y luego compila todo de nuevo)
re: fclean all

# Especifica que estas reglas no son archivos reales
.PHONY: all clean fclean re
