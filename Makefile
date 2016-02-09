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

NAME = printf

LIB = Libft/libft.a

SRC =	main.c 			\
		load_struct.c 	\
		cut.c 			\
		utils.c 		\
		print_d.c 		\
		search.c 		\
		get.c 			\
		flag.c 			

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C Libft
	gcc -g -o $(NAME) $(FLAG) $(SRC) $(LIB)

clean:
	make -C Libft clean

fclean: clean
	make -C Libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
