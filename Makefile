#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thalme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 16:52:28 by thalme            #+#    #+#              #
#    Updated: 2020/01/17 10:16:21 by thalme           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRCS = srcs/

SRC = 	ft_printf.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_float.c \
		tools.c \
		tools2.c \
		ft_print_base.c \
		\
		ft_atoi.c \
		ft_itoa_base.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strchr.c \
		ft_strcpy.c \
		ft_strcspn.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strnchr.c \
		ft_strndup.c \
		ft_strnew.c \
		ft_strspn.c \
		ft_toupper.c \
		ft_superjoin.c\
		ft_strdup.c

LIB = libft
FLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRC:.c=.o)


all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC) 
	@ar cr $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

cleandup:
	@find . -type f -name '*~' -exec rm -rf {} \;

norme:
	@norminette $(SRC)