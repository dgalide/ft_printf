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
		cut.c 			\
		utils.c 		\
		print_d.c 		\
		search.c 		\
		get.c 			\
		flag.c 			\
		print_hexa.c 	\
		print_octal.c 	\
		print_ptr.c 	\
		print_s.c 		\
		print_c.c 		\
		print_wchar_t.c \
		bin_to_dec.c 	\
		ft_putwchar.c 	\
		erase_char.c  	\
		ft_itoa.c 		\
		ft_memdel.c 	\
		ft_power.c 		\
		ft_putchar.c 	\
		ft_putendl.c 	\
		ft_putnbr.c 	\
		ft_strdup.c 	\
		ft_strjoin.c 	\
		ft_strlen.c 	\
		ft_strnew.c 	\
		ft_strsub.c 	\
		ft_memalloc.c 	\
		ft_atoi.c 		\
		ft_bzero.c 		\
		ft_putstr.c 	\
		ft_putnbr_fd.c 	\
		ft_putchar_fd.c \
		ft_memcpy.c 	\
		ft_memset.c

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