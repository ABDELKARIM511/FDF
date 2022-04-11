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
		getnextline/get_next_line.c getnextline/get_next_line_utils.c imagepixel.c ft_strchr1.c\
		hexatod.c mallopy2.c controlmap.c controlmap2.c ft_putstr.c

BFILES = fdf_bonus.c draw.c draw2.c libft/ft_atoi.c libft/ft_itoa.c libft/ft_split.c\
		getnextline/get_next_line.c getnextline/get_next_line_utils.c imagepixel.c ft_strchr1.c\
		hexatod.c mallopy2.c controlmap.c controlmap2.c ft_putstr.c

INCLUDE = fdf.h

BINCLUDE = fdf_bonus.h

CC = cc 

CFLAGS = -Wall -Wextra -Werror

OBJS = ${FILES:.c=.o}

BOBJS = ${BFILES:.c=.o}

all:$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	@echo "SUUUUUUUUIIIIIII"

bonus : $(BOBJS)
	@$(CC) $(CFLAGS) $(BOBJS) -I $(BINCLUDE) -o fdf_bonus -lmlx -framework OpenGL -framework AppKit
	@echo "SUUUUUUUUIIIIIII"

%.o : %.c $(INCLUDE)
	gcc  $(CFLAGS) -o $@ -c $<

clean:
	@rm -f ${OBJS}
	@rm -f ${BOBJS}
	@echo "SUUUUUUUUIIIIIII"

fclean: clean
	@rm -f ${NAME}
	@rm -f fdf_bonus
	@echo "SUUUUUUUUIIIIIII"

re: fclean all
