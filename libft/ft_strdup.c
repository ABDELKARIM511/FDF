/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:18:36 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/22 23:20:52 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strdup(const char *source)
{
	char	*s;
	int		i;

	i = 0;
	while (source[i])
		i++;
	s = (char *)malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (source[i])
	{
		s[i] = source[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
