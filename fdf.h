/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:51:43 by aer-razk          #+#    #+#             */
/*   Updated: 2022/01/06 15:51:45 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<mlx.h>
# include"./getnextline/get_next_line.h"
# include"./libft/libft.h"

typedef struct mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		mapz;
	char	**buffer;
	char	*addr;
	int		l;
	int		x;
	int		beginx;
	int		beginy;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		**c;
	int		**color;
}	t_mlxk;

void	repeatitj(t_mlxk window, int size, int osize, int color);
void	repeatit(t_mlxk window, int size, int osize, int color);
void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color);
void	my_mlx_pixel_put(t_mlxk *data, int x, int y, int color);
char	*ft_strchr1(const char *s, int c);
int		hexatod(char *c);
void	fdfinfo(t_mlxk window);
void	*ft_free1(char **c);
int		*mallopy2(char *source, int l, t_mlxk *window);
int		countlines(char *arv);
int		**twodimensions(char *arv, t_mlxk *windowim);
int		controlmap(int key, t_mlxk *params);
void	zoomout(t_mlxk *params);
void	zoomin(t_mlxk *params);
void	drawmap(t_mlxk window, int **c, t_mlxk *windowim);
void	ft_putstr(char *c);
void	changetaille(t_mlxk *widnow, int add);
void	tailleplus(t_mlxk *params);
void	taillemoin(t_mlxk *params);
#endif