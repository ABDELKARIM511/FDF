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

NAME = fdf

FILES = fdf.c draw.c draw2.c libft/ft_atoi.c libft/ft_itoa.c libft/ft_split.c\
		getnextline/get_next_line.c getnextline/get_next_line_utils.c

INCLUDE = fdf.h

CC = cc 

CFLAGS = -Wall -Wextra -Werror

OBJS = ${FILES:.c=.o}

all:$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	@echo "SUUUUUUUUIIIIIII"

clean:
	@rm -f ${OBJS}
	@echo "SUUUUUUUUIIIIIII"

fclean: clean
	@rm -f ${NAME}
	@echo "SUUUUUUUUIIIIIII"

re: fclean all
