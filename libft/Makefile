# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 15:37:29 by jblaye            #+#    #+#              #
#    Updated: 2024/01/19 15:22:31 by jblaye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS = ft_atoi.c ft_itoa.c ft_lstsize.c ft_putendl_fd.c ft_split.c ft_strncmp.c \
		ft_bzero.c ft_lstadd_back.c ft_memchr.c ft_putnbrbasecount_fd.c ft_strchr.c ft_strnstr.c \
		ft_calloc.c ft_lstadd_front.c ft_memcmp.c ft_putnbrcount_fd.c ft_strdup.c ft_strrchr.c \
		ft_fsplit.c ft_lstclear.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strtrim.c \
		ft_isalnum.c ft_lstdelone.c ft_memmove.c ft_putnbrupbasecount_fd.c ft_strjoin.c ft_substr.c \
		ft_isalpha.c ft_lstiter.c ft_memset.c ft_putptrcount_fd.c ft_strlcat.c ft_tolower.c \
		ft_isascii.c ft_lstlast.c ft_printf.c ft_putstrcount_fd.c ft_strlcpy.c ft_toupper.c \
		ft_isdigit.c ft_lstmap.c ft_putcharcount_fd.c ft_putstr_fd.c ft_strlen.c \
		ft_isprint.c ft_lstnew.c ft_putchar_fd.c ft_putuicount_fd.c ft_strmapi.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c \
		ft_dprintf.c ft_printtab.c \
		get_next_line.c get_next_line_utils.c

HEADERS = ./libft.h

OBJS	= $(SRCS:.c=.o)

CC = cc
CFLAGS	= -Wall -Wextra -Werror -I
RM = rm -f
AR = ar rcs

.c.o:
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
