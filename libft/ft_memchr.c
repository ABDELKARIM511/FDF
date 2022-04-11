/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:51:44 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/21 19:54:53 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)str;
	while (n--)
	{
		if ((unsigned char)c == *d)
			return ((char *)d);
		d++;
	}
	return (NULL);
}
