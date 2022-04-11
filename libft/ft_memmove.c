/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:55:24 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/22 23:19:38 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)dest;
	d = (char *)src;
	if (src != NULL || dest != NULL)
	{
		if (s > d)
		{
			while (n--)
				*(s + n) = *(d + n);
		}
		else
		{
			while (n--)
			{
				*s = *d;
				s++;
				d++;
			}
		}
	}
	return (dest);
}
