# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pthorell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 21:25:55 by pthorell          #+#    #+#              #
#    Updated: 2018/08/06 22:15:26 by pthorell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror -I minilibx_macos -I libft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -pthread -O3

LIB1DIR = libft/
LIB1 = $(LIB1DIR)libft.a

LIB2DIR = minilibx_macos/
LIB2 = $(LIB2DIR)libmlx.a

SRC = src/main.c \
	  src/exit.c \
	  src/input_handler.c \
	  src/color.c \
	  src/draw.c \
	  src/color_scheme.c \
	  src/mandelbrot.c \
	  src/fractol_util.c

all: $(NAME)

$(NAME): $(SRC)
	make -C $(LIB1DIR)
	make -C $(LIB2DIR)
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIB1) $(LIB2)

clean:
	make clean -C $(LIB1DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB1DIR)
	make clean -C $(LIB2DIR)

re: fclean all
