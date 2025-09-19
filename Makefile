# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axicola- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 19:57:33 by axicola-          #+#    #+#              #
#    Updated: 2025/09/18 19:57:39 by axicola-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Nombre del ejecutable
NAME = get_next_line

# Archivos fuente
SRC = get_next_line.c \
	get_next_line_utils.c \
	main.c\

OBJ = $(SRC:.c=.o)

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Regla principal
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Regla para compilar objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar objetos
clean:
	rm -f $(OBJ)

# Regla para limpiar todo
fclean: clean
	rm -f $(NAME)

# Regla para recompilar desde cero
re: fclean all

.PHONY: all clean fclean re

