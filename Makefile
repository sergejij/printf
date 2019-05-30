# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 18:01:17 by ubartemi          #+#    #+#              #
#    Updated: 2019/05/30 12:04:02 by ubartemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = main_ft_printf.c test_integer_to_string.c test_pointer.c \
        test_string_char.c test_hex_str.c  test_long.c test_octal.c \
        test_unsigned.c


OBJ = $(SRC:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cd ./libft && make
	gcc -c -Wextra -Wall -Werror $(SRC) -I ft_printf.h
	ar rc $(NAME) $(OBJ) libft/*.o 

clean:
	rm -f $(OBJ)
	cd ./libft && make clean

fclean: clean
	rm -f $(NAME)
	cd ./libft && make fclean

re: fclean all