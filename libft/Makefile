# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adalenco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/27 21:24:43 by adalenco          #+#    #+#              #
#    Updated: 2016/11/27 21:24:44 by adalenco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

PATH =	srcs/

FCHC =	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcmpi.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_realloc.c

FCHO =	$(FCHC:.c=.o)

COMP = gcc -Wall -Wextra -Werror

INC = ./includes


all: $(NAME)

$(NAME): $(FCHO)
		@ar rc $(NAME) $(FCHO)
		@ranlib $(NAME)
		@echo "\033[33;32mlibrary created"

$(FCHO):
		@$(COMP) -c $(FCHC) -I $(INC)
		@echo "\033[33;32mobjects created"

clean:
		@rm -rf $(FCHO)
		@echo "\033[33;31m Files .o deleted"

fclean: clean
		@rm -rf $(NAME)
		@echo "\033[33;31m $(NAME) deleted"

re: fclean all

.PHONY: clean fclean all re