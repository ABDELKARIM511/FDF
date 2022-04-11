/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:43:30 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/22 22:53:51 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			i;
	long int	k;

	k = n;
	i = ft_count(n);
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		k = -k;
	}
	s[i] = 0;
	while (i && (k != 0 || n == 0))
	{
		s[--i] = (k % 10) + 48;
		k = k / 10;
	}
	return (s);
}
