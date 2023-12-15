# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:23:02 by andeviei          #+#    #+#              #
#    Updated: 2023/12/15 15:42:40 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = bin/test
LIBFT = bin/libft.a
TESTUTILS = ../util/bin/testutils.a

SRCS = test.c test_is.c test_to.c test_mem.c test_put.c
HDRS = test.h
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(TESTUTILS) $(OBJS)
	ar rcs $(LIBFT) $(OBJS)
	gcc $(CFLAGS) $(LIBFT) $(TESTUTILS) -o $(NAME)

$(LIBFT):
	mkdir bin/
	cp -f ../repo/libft.a bin/

$(OBJS): $(SRCS) $(HDRS)
	gcc $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS) $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rmdir bin/

re: fclean all

.PHONY: all clean fclean re