# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 20:58:35 by aer-razk          #+#    #+#              #
#    Updated: 2021/11/23 22:21:49 by aer-razk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror

ARC = ar rc

FILES = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
		ft_strlcat.c ft_atoi.c ft_substr.c ft_putchar_fd.c\
		ft_strlcpy.c ft_tolower.c ft_bzero.c  ft_strlen.c ft_putstr_fd.c\
		ft_toupper.c ft_calloc.c ft_memchr.c ft_isalnum.c ft_striteri.c ft_putendl_fd.c\
		ft_memcmp.c ft_split.c ft_strncmp.c ft_putnbr_fd.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
		ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_itoa.c ft_strmapi.c


OBJS = $(FILES:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

%.o : %.c
	gcc $(CFLAGS) -o $@ -c $^

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: re fclean clean all