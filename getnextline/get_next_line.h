/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:21:05 by aer-razk          #+#    #+#             */
/*   Updated: 2021/12/07 21:32:20 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>

# define BUFFER_SIZE 500

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*mallopy(char *source, char *del);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t num, size_t size);
char	*show_the_line(char *buffer, char *line, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(char *s, int c);
int		ft_end(char *s, int k);
#endif
