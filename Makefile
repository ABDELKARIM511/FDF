# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 20:58:35 by aer-razk          #+#    #+#              #
#    Updated: 2021/11/23 21:34:02 by aer-razk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

ARC = ar rcs

FILES = fdf.c draw.c draw2.cc

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJS = ${FILES:.c=.o}

%.o: %.c
	$(CC) $(FLAGS) -I /usr/local/include -c $< -o $@ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS)

clean: ${OBJS}
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
