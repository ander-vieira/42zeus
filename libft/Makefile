# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:23:02 by andeviei          #+#    #+#              #
#    Updated: 2023/12/16 11:45:55 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -D TEST_EVAL

LIBFT = bin/libft.a
TESTUTILS = ../util/bin/testutils.a

NAME = bin/test
SRCS = test.c test_is.c test_to.c test_mem.c test_put.c test_atoi.c
HDRS = test.h
OBJS = $(SRCS:.c=.o)

NAME_BONUS = bin/test_bonus
SRCS_BONUS = test_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(TESTUTILS) $(OBJS)
	ar rcs $(LIBFT) $(OBJS)
	gcc $(CFLAGS) $(LIBFT) $(TESTUTILS) -o $(NAME)

$(OBJS): $(SRCS) $(HDRS)
	gcc $(CFLAGS) -c $(SRCS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(TESTUTILS) $(OBJS_BONUS)
	ar rcs $(LIBFT) $(OBJS_BONUS)
	gcc $(CFLAGS) $(LIBFT) $(TESTUTILS) -o $(NAME_BONUS)

$(OBJS_BONUS): $(SRCS_BONUS) $(HDRS)
	gcc $(CFLAGS) -c $(SRCS_BONUS)

$(LIBFT):
	mkdir bin/
	cp -f ../repo/libft.a bin/

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(LIBFT)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	rmdir bin/

re: fclean all

.PHONY: all clean fclean re