# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 19:13:34 by hthunder          #+#    #+#              #
#    Updated: 2019/10/17 16:50:25 by hthunder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIBFT = libft
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L$(LIBFT) -lft
CC = gcc 
SRCS = filechecking.c \
		listmaking.c \
		main.c \
		mapsolver.c \
		support.c
OBJS = $(SRCS:%.c=%.o)
INCLUDES = libft/includes

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all