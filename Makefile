# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 12:13:47 by julieblaye        #+#    #+#              #
#    Updated: 2024/01/15 11:27:04 by jblaye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = main.c utils.c

HEADERS = -I pipex.h

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

.C.O: 
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

all:		libft $(NAME)

libft:	
			make -C ./libft

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(HEADERS) $(SRC) ./libft/libft.a

clean:
			rm -f $(OBJS)
			make -C ./libft clean

fclean:		clean
			rm -f $(NAME)
			make -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re libft 