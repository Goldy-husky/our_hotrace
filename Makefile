# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 17:18:15 by sbethoua          #+#    #+#              #
#    Updated: 2013/12/15 00:09:07 by sbethoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I ./includes/
HEADERFILES = includes/hotrace.h includes/getnextline.h
SRCSDIR = ./srcs/
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
SRCSFILES = crc32.c \
			get_next_line.c \
			list_insert.c \
			main.c \
			set_and_find.c \
			utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERFILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re