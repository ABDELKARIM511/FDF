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
} mlxk;

# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
#include <mlx.h>
#include "./getnextline/get_next_line.h"
#include "./libft/libft.h"
void	repeatitj(mlxk window, int size,int osize,int color);
void	repeatit(mlxk window, int size, int osize,int color);
void	my_mlx_pixel_put(mlxk *data, int x, int y, int color);
#endif
