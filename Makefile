# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 18:01:17 by ubartemi          #+#    #+#              #
#    Updated: 2019/07/15 17:10:25 by aestella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = main_ft_printf.c test_integer_to_string.c pointer.c \
      test_string_char.c test_long.c octal.c \
      test_unsigned.c ft_float.c plus.c minus.c recording_other_flags.c \
      test_float_to_string.c additional_float.c additional_float2.c plus2.c \
      hex_str.c hex_str2.c hex_str3.c octal2.c ft_parse_types.c\
      ft_analyse_flags.c


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