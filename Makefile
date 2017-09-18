# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adalenco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 17:12:17 by adalenco          #+#    #+#              #
#    Updated: 2017/09/15 16:16:39 by adalenco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = $(addprefix $(SRCPATH)/,$(FC))

SRCPATH =	./src

FC =		main.c \
			key_funct.c \
			ft_image.c \
			get_next_line.c \
			ft_opencld.c

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
