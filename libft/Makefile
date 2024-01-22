# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:23:02 by andeviei          #+#    #+#              #
#    Updated: 2024/01/22 16:09:32 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -D TEST_EVAL
UNAME = $(shell uname)

TESTLIB = ../testlib/testlib.a
LIBFT = libft.a

NAME = test.out
SRCS = src/test.c src/test_is1.c src/test_is2.c src/test_to.c \
src/test_mem1.c src/test_memcpy.c src/test_memmove.c src/test_mem3.c \
src/test_put.c src/test_atoi.c src/test_calloc.c \
src/test_str1.c src/test_str2.c src/test_substr.c src/test_str3.c \
src/test_str4.c src/test_itoa.c src/test_split.c \
src/taux_split.c
HDRS = src/test.h

NAME_BONUS = test_bonus.out
SRCS_BONUS = src_bonus/test_bonus.c src_bonus/test_bonus2.c \
src_bonus/test_bonus3.c \
src_bonus/taux_lst.c
HDRS_BONUS = src_bonus/test_bonus.h

all: $(NAME)

$(NAME): testlib libft $(SRCS) $(HDRS)
ifeq ($(UNAME), Darwin)
	gcc $(CFLAGS) -undefined dynamic_lookup $(SRCS) $(LIBFT) $(TESTLIB) -o $(NAME)
else
	gcc $(CFLAGS) $(SRCS) -Wl,--whole-archive -L. -l:$(LIBFT) -l:$(TESTLIB) -Wl,--no-whole-archive -o $(NAME)
endif

bonus: $(NAME_BONUS)

$(NAME_BONUS): testlib libft $(SRCS_BONUS) $(HDRS_BONUS)
ifeq ($(UNAME), Darwin)
	gcc $(CFLAGS) -undefined dynamic_lookup $(SRCS_BONUS) $(LIBFT) $(TESTLIB) -o $(NAME_BONUS)
else
	gcc $(CFLAGS) $(SRCS_BONUS) -Wl,--whole-archive -L. -l:$(LIBFT) -l:$(TESTLIB) -Wl,--no-whole-archive -o $(NAME_BONUS)
endif

testlib:
	make -C ../testlib all clean

libft:
	cp -f ../repo/libft.a libft.a

clean:
	rm -f $(LIBFT)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all testlib libft clean fclean re