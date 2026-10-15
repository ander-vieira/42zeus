# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:23:02 by andeviei          #+#    #+#              #
#    Updated: 2026/10/13 18:19:28 by amendibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = gcc
UNAME = $(shell uname)

TESTLIB = ../tlib/tlib.a
LIBFT = libft.a

NAME = test.out
SRCS = src/test.c src/test_is.c src/test_to.c \
src/mem/test_bzero.c src/mem/test_memset.c src/mem/test_memcpy.c src/mem/test_memmove.c src/mem/test_memchr.c src/mem/test_memcmp.c \
src/test_atoi.c src/test_calloc.c \
src/str/test_strlen.c src/str/test_strchr.c src/str/test_strrchr.c src/str/test_strncmp.c src/str/test_strdup.c \
src/str/test_strlcpy.c src/str/test_strlcat.c src/str/test_strnstr.c src/str/test_substr.c src/str/test_strjoin.c \
src/str/test_strtrim.c src/test_split.c src/test_itoa.c src/str/test_strmapi.c src/str/test_striteri.c \
src/put/test_putchar.c src/put/test_putstr.c src/put/test_putendl.c src/put/test_putnbr.c
HDRS = src/test.h

SRCS_BONUS = src_bonus/test_bonus.c src_bonus/taux_lst.c \
src_bonus/test_lstnew.c src_bonus/test_lstadd_front.c src_bonus/test_lstsize.c \
src_bonus/test_lstlast.c src_bonus/test_lstadd_back.c \
src_bonus/test_lstdelone.c src_bonus/test_lstclear.c src_bonus/test_lstiter.c \
src_bonus/test_lstmap.c
HDRS_BONUS = src_bonus/test_bonus.h

SRCS_ALL = $(SRCS) $(SRCS_BONUS)
HDRS_ALL = $(HDRS) $(HDRS_BONUS)

ifeq ($(UNAME), Darwin)
LINKFLAGS = -undefined dynamic_lookup
LIBS = $(LIBFT) $(TESTLIB)
else
LINKFLAGS =
LIBS = -Wl,--whole-archive -L. -l:$(LIBFT) -l:$(TESTLIB) -Wl,--no-whole-archive
endif

define compile_test
	$(CC) $(CFLAGS) $(LINKFLAGS) $(1) $(2) $(LIBS) -o $(3)
endef

all: $(NAME)

$(NAME): tlib libft $(SRCS_ALL) $(HDRS_ALL)
	$(call compile_test,-Isrc -Isrc_bonus,$(SRCS_ALL),$@)

tlib:
	make -C ../tlib all clean

libft:
	cp -f ../repo/libft.a libft.a

clean:
	rm -f $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all tlib libft clean fclean re