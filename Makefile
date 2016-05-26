# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/05/01 16:01:10 by dgalide          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	main.c 			\
		load_struct.c 	\
		utils.c 		\
		search.c 		\
		get.c 			\
		func.c 			\
		handlers/unsigned_decimal_handler.c \
		handlers/decimal_handler.c \
		handlers/percent_handler.c \
		handlers/hexadecimal_handler.c \
		handlers/wchar_handler.c \
		handlers/wstring_handler.c \
		handlers/octal_handler.c \
		handlers/string_handler.c 	\
		handlers/char_handler.c \
		handlers/pointer_handler.c \
		lib_src/erase_char.c  	\
		lib_src/ft_itoa.c 		\
		lib_src/ft_memdel.c 	\
		lib_src/ft_power.c 		\
		lib_src/ft_strcmp.c 	\
		lib_src/ft_memcmp.c 	\
		lib_src/ft_strstr.c 	\
		lib_src/ft_strcat.c 	\
		lib_src/ft_putchar.c 	\
		lib_src/ft_putendl.c 	\
		lib_src/ft_putnbr.c 	\
		lib_src/ft_strdup.c 	\
		lib_src/ft_strjoin.c 	\
		lib_src/ft_strnew.c 	\
		lib_src/ft_strsub.c 	\
		lib_src/ft_memalloc.c 	\
		lib_src/ft_atoi.c 		\
		lib_src/ft_bzero.c 		\
		lib_src/ft_strlen.c 	\
		lib_src/ft_putstr.c 	\
		lib_src/ft_putnbr_fd.c 	\
		lib_src/ft_putchar_fd.c \
		lib_src/ft_memcpy.c 	\
		lib_src/ft_isdigit.c 	\
		lib_src/ft_unsigned_itoa.c \
		lib_src/ft_memset.c \

SRCO = $(SRC:.c=.o)

INC = includes/ft_printf.h

FLAG = -Wall -Werror -Wextra

all: $(NAME)

re: fclean all

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC)

$(NAME): $(SRCO)
	ar rc $@ $^
	ranlib $@

clean:
	rm -rf $(SRCO)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean
