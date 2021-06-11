# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmelkony <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 16:08:44 by vmelkony          #+#    #+#              #
#    Updated: 2021/06/11 18:21:03 by vmelkony         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c

OBJS		= $(SRC:.c=.o)

CC			= gcc

INCLUDES	= -Imlx

FLAGS		= -Wall -Wextra -Werror

NAME		= mlxdemo

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C ./mlx
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f a.out

re:			fclean all

norm:
	norminette $(SRC)
