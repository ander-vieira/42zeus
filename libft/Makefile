# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:23:02 by andeviei          #+#    #+#              #
#    Updated: 2023/12/18 21:49:02 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -D TEST_EVAL

LIBFT = bin/libft.a
TESTUTILS = ../util/bin/testutils.a

NAME = bin/test
SRCS = test.c test_is.c test_to.c test_mem.c test_put.c test_atoi.c \
test_calloc.c test_str1.c test_str2.c test_str3.c test_str4.c \
test_itoa.c test_split.c
HDRS = test.h
OBJS = $(SRCS:.c=.o)

NAME_BONUS = bin/test_bonus
SRCS_BONUS = test_bonus.c test_bonus2.c test_bonus3.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: util $(NAME)

$(NAME): libft $(TESTUTILS) $(OBJS)
	ar rcs $(LIBFT) $(OBJS)
	gcc $(CFLAGS) $(LIBFT) $(TESTUTILS) -o $(NAME)

$(OBJS): $(SRCS) $(HDRS)
	gcc $(CFLAGS) -c $(SRCS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): libft $(TESTUTILS) $(OBJS_BONUS)
	ar rcs $(LIBFT) $(OBJS_BONUS)
	gcc $(CFLAGS) $(LIBFT) $(TESTUTILS) -o $(NAME_BONUS)

$(OBJS_BONUS): $(SRCS_BONUS) $(HDRS)
	gcc $(CFLAGS) -c $(SRCS_BONUS)

libft:
	mkdir -p bin/
	cp -f ../repo/libft.a bin/

util:
	make -C ../util all

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(LIBFT)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	rmdir bin/

re: fclean all

.PHONY: all libft util clean fclean re