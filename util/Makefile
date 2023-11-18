# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 14:19:30 by andeviei          #+#    #+#              #
#    Updated: 2023/11/18 16:40:46 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: bin/print_title bin/filter_list

bin/print_title: src/print_title.c
	gcc src/print_title.c -o bin/print_title

bin/filter_list: src/filter_list.c
	gcc src/filter_list.c -o bin/filter_list

.PHONY: all