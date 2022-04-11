/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:52:19 by aer-razk          #+#    #+#             */
/*   Updated: 2021/12/07 21:52:20 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(char *s, int c);
#endif