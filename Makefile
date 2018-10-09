# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecalimac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 19:21:37 by ecalimac          #+#    #+#              #
#    Updated: 2018/01/12 18:22:26 by vistrate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = *.c
OBJ = $(SRC:%.c=%.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME)
$(OBJ): $(SRC)
	gcc $(FLAGS) -I. -c $(SRC)
clean:
	make -C libft/ clean
	rm -f $(OBJ)
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
