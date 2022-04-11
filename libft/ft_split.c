/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:56:52 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/22 16:19:36 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_free(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	while (--i >= 0)
		free(c[i]);
	free(c);
	return (NULL);
}

int	ft_count(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		if (j > 0)
		{
			k++;
			j = 0;
		}
	}
	return (k);
}

int	ft_calculatr(char *s, int i, char c)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

char	**ft_fill(char **str, char *s, char c, int m)
{
	int	i;
	int	j;
	int	k;
	int	l;

	k = 0;
	i = 0;
	while (k < m)
	{
		l = 0;
		i = ft_calculatr(s, i, c);
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (k < m)
		{
			str[k] = malloc(i - j + 1);
			if (!str[k])
				return (ft_free(str));
			while (j < i)
				str[k][l++] = s[j++];
			str[k++][l] = 0;
		}
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	if (!s[0])
	{
		str = malloc(sizeof(char *));
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	str = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!str)
		return (NULL);
	str[ft_count(s, c)] = 0;
	return (ft_fill(str, (char *)s, c, ft_count(s, c)));
}
