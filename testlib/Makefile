# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 14:19:30 by andeviei          #+#    #+#              #
#    Updated: 2024/01/26 15:15:09 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = testlib.a

SRCS = testlib_alloc.c testlib_malloc.c testlib_printf.c testlib_test.c
HDRS = testlib.h
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(HDRS)
	gcc -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re