/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:36:24 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/23 01:19:51 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize >= i && dstsize > 0)
	{
		while (src[j] && (i + j) < dstsize - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = 0;
		while (src[j])
			j++;
		return (i + j);
	}
	while (src[j])
		j++;
	return (j + dstsize);
}
