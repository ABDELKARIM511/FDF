/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:57:45 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/22 23:20:23 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strchr(const char *s, int c)
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
