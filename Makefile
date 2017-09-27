# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adalenco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 17:12:17 by adalenco          #+#    #+#              #
#    Updated: 2017/09/27 17:07:51 by adalenco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = $(addprefix $(SRCPATH)/,$(FC))

SRCPATH =	./src

FC =		main.c \
			key_funct.c \
			opencl_init.c \
			key_opt.c \
			key_specials.c \
			opencl_calc.c

FCO =	$(FC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FLAGS2 = -framework OpenGL -framework AppKit

INC = ./includes/
LIBFT = ./libft/

all: $(NAME)

$(NAME): $(SRC)
	@gcc $(FLAGS2) $(FCO) ./libft/libft.a ./minilibx_macos/libmlx.a -o $(NAME) -framework OpenCL

$(SRC): makelib
	@gcc $(FLAGS)  -c $(SRC) -I $(INC) -I $(LIBFT)

makelib:
	@make -C ./libft
	@make -C ./minilibx_macos/

clean:
	@rm -f $(FCO)
	@make -C ./libft clean
	@make -C ./minilibx_macos clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
