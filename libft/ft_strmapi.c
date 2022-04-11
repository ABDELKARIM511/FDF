/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_strmapi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:50:20 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/22 16:58:58 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*c;
	int		k;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	c = malloc(i + 1);
	if (!c)
		return (NULL);
	k = 0;
	while (k < i)
	{
		c[k] = f(k, s[k]);
		k++;
	}
	c[k] = 0;
	return (c);
}
