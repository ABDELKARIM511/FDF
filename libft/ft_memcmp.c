/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:04:28 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/14 16:05:34 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str3;
	unsigned char	*str4;

	i = 0;
	str3 = (unsigned char *)str1;
	str4 = (unsigned char *)str2;
	if (str1 != NULL || str2 != NULL)
	{
		while (n--)
		{
			if (*str3 != *str4)
				return (*str3 - *str4);
			str4++;
			str3++;
		}
	}
	return (0);
}
