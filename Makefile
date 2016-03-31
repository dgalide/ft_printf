# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/02/09 16:12:11 by dgalide          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	main.c 			\
		load_struct.c 	\
		utils.c 		\
		search.c 		\
		get.c 			\
		flag.c 			\
		handlers/decimal_handler.c \
		handlers/percent_handler.c \
		bin_to_dec.c 	\
		ft_putwchar.c 	\
		lib_src/erase_char.c  	\
		lib_src/ft_itoa.c 		\
		lib_src/ft_memdel.c 	\
		lib_src/ft_power.c 		\
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
		lib_src/ft_memset.c
#		handlers/print_hexa.c 	\
#		handlers/print_octal.c 	\
#		handlers/print_ptr.c 	\
#		handlers/print_s.c 		\
#		handlers/print_c.c 		\
#		handlers/print_wchar_t.c \

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