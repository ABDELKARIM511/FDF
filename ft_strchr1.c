/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:48:16 by aer-razk          #+#    #+#             */
/*   Updated: 2022/02/25 14:48:17 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

char	*ft_strchr1(const char *s, int c)
{
	unsigned char	*d;
	int				k;

	k = ft_strlen(s) + 1;
	d = (unsigned char *)s;
	while (k--)
	{
		if ((unsigned char)c == *d)
			return ((char *) d);
		d++;
	}
	return (NULL);
}

void	*ft_free1(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(c[i]);
		i--;
	}
	free(c);
	return (NULL);
}
