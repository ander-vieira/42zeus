# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 14:19:30 by andeviei          #+#    #+#              #
#    Updated: 2023/11/18 17:08:23 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: bin/print_title bin/filter_list

bin/print_title: bin/ src/print_title.c
	gcc src/print_title.c -o bin/print_title

bin/filter_list: bin/ src/filter_list.c
	gcc src/filter_list.c -o bin/filter_list

bin/:
	mkdir bin/

.PHONY: all