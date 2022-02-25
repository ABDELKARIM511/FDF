/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:40:26 by aer-razk          #+#    #+#             */
/*   Updated: 2022/02/25 15:40:27 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	moveright(mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->beginy = params->beginy + 50;
	drawmap(*params, params->c, params);
}

void	movedown(mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->beginx = params->beginx + 50;
	drawmap(*params, params->c, params);
}

void	moveleft(mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->beginy = params->beginy - 50;
	drawmap(*params, params->c, params);
}

void	moveup(mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->beginx = params->beginx - 50;
	drawmap(*params, params->c, params);
}

int	controlmap(int key, mlxk *params)
{
	if (key == 126)
		moveright(params);
	if (key == 123)
		movedown(params);
	if (key == 125)
		moveleft(params);
	if (key == 124)
		moveup(params);
	if (key == 12)
		zoomin(params);
	if (key == 13)
		zoomout(params);
	if (key == 53)
	{
		mlx_destroy_window(params->mlx, params->mlx_win);
		exit(0);
	}
	return (0);
}
