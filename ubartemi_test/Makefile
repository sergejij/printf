# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 18:01:17 by ubartemi          #+#    #+#              #
#    Updated: 2019/05/21 18:17:56 by ubartemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = test.c

OBJ = $(SRC:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cd ./libft && make
	gcc -c -Wextra -Wall -Werror $(SRC)
	ar rc $(NAME) test.o libft/*.o 

clean:
	rm -f $(OBJ)
	cd ./libft && make clean

fclean: clean
	rm -f $(NAME)
	cd ./libft && make fclean

re: fclean all