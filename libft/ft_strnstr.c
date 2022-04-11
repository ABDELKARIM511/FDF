/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:40:17 by aer-razk          #+#    #+#             */
/*   Updated: 2021/12/01 11:14:01 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		k;
	size_t	i;

	k = 0;
	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	while (i < len && i < ft_strlen(haystack))
	{
		while (haystack[i] != needle[k] && haystack[i] && needle[k] && i < len)
			i++;
		while (haystack[i] == needle[k] && haystack[i] && needle[k] && i < len)
		{
			i++;
			k++;
		}
		if (needle[k] == '\0')
			return ((char *) haystack + i - k);
		i = i - (k - 1);
		k = 0;
	}
	return (NULL);
}
