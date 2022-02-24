/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:40:23 by aer-razk          #+#    #+#             */
/*   Updated: 2022/01/06 14:40:25 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	my_mlx_pixel_put(mlxk *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < 1920) && (y > 0 && y < 1080))
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
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

static	void	*ft_free1(char **c)
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

int	hexatod(char *c)
{
	int	decimal;
	int	i;
	int	hexa;

	i = ft_strlen(c) - 1;
	decimal = 0;
	hexa = 1;
	while (i > 2)
	{
		if (c[i] >= '0' && c[i] <= '9')
			decimal += (c[i] - 48) * hexa;
		else if (c[i] >= 'A' && c[i] <= 'Z')
			decimal += (c[i] - 55) * hexa;
		else if (c[i] >= 'a' && c[i] <= 'z')
			decimal += (c[i] - 87) * hexa;
		hexa *= 16;
		i--;
	}
	return (decimal);
}

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

int	*mallopy2(char *source, int l, mlxk *window)
{
	int		*s;
	int		i;
	int		j;
	int		k;
	char	**d;

	i = 0;
	j = 0;
	k = 0;
	d = ft_split(source, ' ');
	if (!d)
		return (NULL);
	while (d[i])
	{
		if (d[i][0] != '\n')
			k++;
		i++;
	}
	s = ft_calloc(k, sizeof(int));
	window -> color[l] = ft_calloc(k ,sizeof(int));
	i = 0;
	while (i < k)
	{
		s[j] = ft_atoi(d[i]);
		if (ft_strchr1(d[i], ','))
			 window -> color[l][j] = hexatod(ft_strchr1(d[i], ','));
		else
			window -> color[l][j] = 16777215;
		j++;
		i++;
	}
	window -> x = k;
	free(source);
	ft_free1(d);
	return (s);
}

int	**twodimensions(char *arv, mlxk *windowim)
{
	int		**c;
	int		fd;
	int		i;
	int		d;

	fd = open(arv, O_RDWR);
	c = ft_calloc(sizeof(int *), windowim -> l);
	windowim->color = ft_calloc(sizeof(int *), windowim -> l);
	i = 0;
	d = 0;
	while (i < windowim -> l)
	{
		windowim -> x = 0;
		c[i] = mallopy2(get_next_line(fd), i, windowim);
		if (d > windowim -> x && d != 0)
		{
			printf("Found wrong line length. Exiting.\n");
			exit(0);
		}
		d = windowim -> x;
		i++;
	}
	return (c);
}

void	fdfinfo(mlxk window)
{
	char	*c;

	c = ft_itoa(window.beginx);
	mlx_string_put(window.mlx, window.mlx_win, 10, 5,
		16777215, "ESC : Exit.");
	mlx_string_put(window.mlx, window.mlx_win, 10, 25,
		16777215, "Q : Zoom In.");
	mlx_string_put(window.mlx, window.mlx_win, 10, 45,
		16777215, "W : Zoom Out.");
	mlx_string_put(window.mlx, window.mlx_win, 900, 25,
		16777215, "The Best FDF");
	mlx_string_put(window.mlx, window.mlx_win, 200, 5,
		16777215, "Arrows : Move.");
	mlx_string_put(window.mlx, window.mlx_win, 200, 25, 16777215, "Latitude :");
	mlx_string_put(window.mlx, window.mlx_win, 310, 25, 16777215, c);
	free(c);
	c = ft_itoa(window.beginy);
	mlx_string_put(window.mlx, window.mlx_win, 200, 45,
		16777215, "Longitude :");
	mlx_string_put(window.mlx, window.mlx_win, 320, 45, 16777215, c);
	free(c);
	c = ft_itoa(window.mapz);
	mlx_string_put(window.mlx, window.mlx_win, 390, 5, 16777215, "Zoom :");
	mlx_string_put(window.mlx, window.mlx_win, 460, 5, 16777215, c);
	free(c);
}

void	drawmap(mlxk window, int **c, mlxk *windowim)
{
	int		i;
	int		j;
	int		d;

	i = 0;
	j = 0;
	d = window.beginx;
	fdfinfo(window);
	windowim->img = mlx_new_image(window.mlx, 1920, 1080);
	window.addr = mlx_get_data_addr(windowim->img, &window.bits_per_pixel, &window.line_length, &window.endian);
	while (i < window.l)
	{
		j = 0;
		window.beginx = d;
		while (j < window.x)
		{
			if (j + 1 < window.x)
				repeatit(window,c[i][j] * 2,c[i][j + 1] * 2,window.color[i][j]);
			if (i + 1 < window.l)
				repeatitj(window,c[i][j] * 2,c[i + 1][j] * 2,window.color[i][j]);
			window.beginx+=window.mapz;
			j++;
		}
		window.beginy+=window.mapz;
		i++;
	}
	mlx_put_image_to_window(window.mlx,window.mlx_win,windowim->img,0,70);
}

int write1(int key,mlxk *params)
{
	if (key == 126)
	{
		mlx_destroy_image(params->mlx, params->img);
		mlx_clear_window(params->mlx, params->mlx_win);
		params->beginy = params->beginy + 50;
		drawmap(*params, params->c,params);
	}
	if (key == 123)
	{
		mlx_destroy_image(params->mlx, params->img);
		mlx_clear_window(params->mlx, params->mlx_win);
		params->beginx = params->beginx + 50;
		drawmap(*params, params->c, params);
	}
	if (key == 125)
	{
		mlx_destroy_image(params->mlx, params->img);
		mlx_clear_window(params->mlx, params->mlx_win);
		params->beginy = params->beginy - 50;
		drawmap(*params, params->c,params);
	}
	if (key == 124)
	{
		mlx_destroy_image(params->mlx,params->img);
		mlx_clear_window(params->mlx,params->mlx_win);
		params->beginx = params->beginx - 50;
		drawmap(*params,params->c,params);
	}
	if (key == 12)
	{
		mlx_destroy_image(params->mlx,params->img);
		mlx_clear_window(params->mlx,params->mlx_win);
		params->mapz = params->mapz + 10;
		drawmap(*params,params->c,params);
	}
	if (key == 13)
	{
		if (params->mapz - 10 > 0)
		{
			mlx_destroy_image(params->mlx,params->img);
			mlx_clear_window(params->mlx,params->mlx_win);
			params->mapz = params->mapz - 10;
			drawmap(*params,params->c,params);
		}
		else
			mlx_string_put(params->mlx,params->mlx_win,840,50,16711680,"You can't zoom out anymore.");
	}
	if (key == 53)
	{
		mlx_destroy_window(params->mlx,params->mlx_win);
		exit(0);
	}
	return 0;
}

int	main(int arc,char **arv)
{
	mlxk window;
	int	i = 0;
	int	j = 0;

	(void)arc;
	window.l = countlines(arv[1]);
	window.c = twodimensions(arv[1], &window);
	window.mapz = 2;
	window.beginy = 50;
	window.beginx = 50;
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, 1920, 1080, "FDF");
	drawmap(window, window.c, &window);
	mlx_hook(window.mlx_win, 2, 0, write1, &window);
	mlx_loop(window.mlx);
	exit(0);
}