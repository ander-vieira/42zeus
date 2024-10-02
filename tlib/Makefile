# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 14:19:30 by andeviei          #+#    #+#              #
#    Updated: 2024/10/02 23:02:02 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tlib.a

SRCS = tlib_mockmalloc.c tlib_printf.c tlib_test.c
HDRS = tlib.h
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