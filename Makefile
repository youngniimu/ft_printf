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
SRC_DIR = src/
SRC_FILES = 	\
			ft_set_flags.c \
			ft_parse_format.c \
			ft_printf.c \
			ft_print_char.c \
			ft_print_str.c \
			ft_print_float.c \
			tools.c \
			tools2.c \
			ft_print_base.c
INCLUDES = include/
SOURCES = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIB = libft/
FLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRC_FILES:.c=.o)

all: $(NAME)
$(NAME):
			@make -C $(LIB)
			@cp $(LIB)/libft.a ./$(NAME)
			@gcc $(FLAGS) -c $(SOURCES) 
			@ar rc $(NAME) $(OBJECTS)
			@ranlib $(NAME)
clean:
			@rm -f $(OBJECTS)
			@make -C $(LIB) clean
fclean: clean
			@rm -f $(NAME)
			@make -C $(LIB) fclean
re: fclean all

cleandup:
			@find . -type f -name '*~' -exec rm -rf {} \;
norme:
			@norminette $(SRC)