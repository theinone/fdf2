# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theinone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 11:51:41 by theinone          #+#    #+#              #
#    Updated: 2020/02/20 15:16:28 by theinone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   fdf
CC		=	gcc
CFLAGS  =   -Werror -Wextra -Wall
SRC     =	main.c ft_readfile.c ft_draw.c ft_create_element.c ft_list_push_front.c 
OBJ     =   $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -L mlx/ -lmlx -framework OpenGL -framework Appkit -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	make re -C ./libft/

clean:
	rm -f $(OBJ)
	make clean -C ./libft/
fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
re: fclean all

