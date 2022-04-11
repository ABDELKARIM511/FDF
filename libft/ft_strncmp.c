/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:48:10 by aer-razk          #+#    #+#             */
/*   Updated: 2021/11/22 23:24:32 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	if (s3 != NULL || s4 != NULL)
	{
		while ((s3[i] != '\0' || s4[i] != '\0')
			&& i != n)
		{
			if (s3[i] != s4[i])
				return (s3[i] - s4[i]);
			i++;
		}
	}
	return (0);
}
