/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:50:56 by aer-razk          #+#    #+#             */
/*   Updated: 2021/12/07 21:50:57 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)dest;
	d = (char *)src;
	if (src != NULL || dest != NULL)
	{
		while (n--)
		{
			*s = *d;
			s++;
			d++;
		}
	}
	return (dest);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*x;
	int		y;

	y = num * size;
	x = malloc(y);
	if (!x)
		return (NULL);
	while (y--)
		x[y] = 0;
	return (x);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	*d;
	int				k;

	k = ft_strlen(s) + 1;
	d = (unsigned char *)s;
	while (k--)
	{
		if ((unsigned char)c == *d)
		{
			d++;
			return ((char *) d);
		}
		d++;
	}
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start < i)
	{
		if ((i - start) < len)
			str = ft_calloc(i - start + 1, 1);
		else
			str = ft_calloc(len + 1, 1);
		if (!str)
			return (NULL);
		i = 0;
		while (i < len && s[start])
			str[i++] = s[start++];
		str[i] = 0;
		free(s);
		return (str);
	}
	free(s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	s = ft_calloc(i + 1, 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, ft_strlen(s1));
	ft_memcpy(s + ft_strlen(s1), s2, ft_strlen(s2));
	s[i] = 0;
	free(s1);
	return (s);
}
