# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 12:13:47 by julieblaye        #+#    #+#              #
#    Updated: 2024/01/19 13:44:26 by jblaye           ###   ########.fr        #
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
			@make -C ./libft --no-print-directory --silent

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(HEADERS) $(SRC) ./libft/libft.a

clean:
			rm -f $(OBJ)
			make -C ./libft clean

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re libft 