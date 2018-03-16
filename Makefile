# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlange <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 12:33:38 by jlange            #+#    #+#              #
#    Updated: 2017/02/22 19:46:05 by jlange           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all, clean, fclean, re

SRC_PATH = src

OBJ_PATH = obj

NAME = libftprintf.a

CC = gcc

HEADER = includes/printf.h

CFLAGS = -g -Wall -Wextra -Werror

CPPFLAGS = -Iincludes

SRC_NAME = check.c					\
		fill_buf.c					\
		fill_width_precision.c 		\
		len1.c						\
		len2.c						\
		len3.c						\
		len4.c						\
		len_buf.c					\
		printf.c					\
		strcat_printf.c				\
		tools1.c					\
		tools2.c					\
		tools3.c					\
		tools4.c					\
		tools5.c					\
		types1.c					\
		types2.c					\
		types3.c					\
		types4.c					\
		uintlen.c					\
		uitoa_base.c				\
		unicode.c					\
		add_precision.c				\
		purcent_padding.c			\

OBJ = $(SRC_NAME:.c=.o)

OBJ_NAME = $(addprefix obj/, $(OBJ))

all: $(NAME)

$(NAME): obj/ $(HEADER) $(OBJ_NAME)
	ar rc $(NAME) $(OBJ_NAME)
	ranlib $(NAME)

obj/:
	mkdir $(OBJ_PATH) 2> /dev/null

obj/%.o: src/%.c
	$(CC) -o $@ $(CPPFLAGS) -c $? $(CFLAGS)

clean:
	rm -rf $(OBJ_PATH)

fclean:
	rm -rf $(NAME) $(OBJ_PATH)

re: fclean all
