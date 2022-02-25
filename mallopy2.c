/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallopy2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:09:51 by aer-razk          #+#    #+#             */
/*   Updated: 2022/02/25 15:09:52 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int	counttable(char **d)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (d[i])
	{
		if (d[i][0] != '\n')
			k++;
		i++;
	}
	return (k);
}

int	*mallopy2(char *source, int l, mlxk *window)
{
	int		*s;
	int		i;
	int		j;
	int		k;
	char	**d;

	i = -1;
	j = -1;
	d = ft_split(source, ' ');
	k = counttable(d);
	s = ft_calloc(k, sizeof(int));
	window -> color[l] = ft_calloc(k, sizeof(int));
	while (++i < k)
	{
		s[++j] = ft_atoi(d[i]);
		if (ft_strchr1(d[i], ','))
			window -> color[l][j] = hexatod(ft_strchr1(d[i], ','));
		else
			window -> color[l][j] = 16777215;
	}
	window -> x = k;
	free(source);
	ft_free1(d);
	return (s);
}

int	countlines(char *arv)
{
	int		fd;
	char	*d;
	int		l;

	fd = open(arv, O_RDWR);
	if (read(fd, NULL, 0) < 0)
	{
		printf("No file %s", arv);
		exit(0);
	}
	d = get_next_line(fd);
	l = 0;
	while (d)
	{
		free(d);
		d = get_next_line(fd);
		l++;
	}
	free(d);
	return (l);
}

int	**twodimensions(char *arv, mlxk *windowim)
{
	int	**c;
	int	fd;
	int	i;
	int	d;

	fd = open(arv, O_RDWR);
	c = ft_calloc(sizeof(int *), windowim -> l);
	windowim->color = ft_calloc(sizeof(int *), windowim -> l);
	i = -1;
	d = 0;
	while (++i < windowim -> l)
	{
		windowim -> x = 0;
		c[i] = mallopy2(get_next_line(fd), i, windowim);
		if (d > windowim -> x && d != 0)
		{
			printf("Found wrong line length. Exiting.\n");
			exit(0);
		}
		d = windowim -> x;
	}
	return (c);
}
