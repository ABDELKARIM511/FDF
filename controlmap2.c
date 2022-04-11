/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlmap2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:41:27 by aer-razk          #+#    #+#             */
/*   Updated: 2022/02/25 15:41:28 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	zoomin(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	params->mapz = params->mapz + 10;
	drawmap(*params, params->c, params);
}

void	zoomout(t_mlxk *params)
{
	if (params->mapz - 10 > 0)
	{
		mlx_destroy_image(params->mlx, params->img);
		mlx_clear_window(params->mlx, params->mlx_win);
		params->mapz = params->mapz - 10;
		drawmap(*params, params->c, params);
	}
	else
		mlx_string_put(params->mlx, params->mlx_win,
			840, 50, 16711680, "You can't zoom out anymore.");
}

void	tailleplus(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	changetaille(params, 5);
	drawmap(*params, params->c, params);
}

void	taillemoin(t_mlxk *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_clear_window(params->mlx, params->mlx_win);
	changetaille(params, -5);
	drawmap(*params, params->c, params);
}

int	exitit(int key, t_mlxk *params)
{
	if (key == 53)
	{
		mlx_destroy_window(params->mlx, params->mlx_win);
		exit(0);
	}
	return (0);
}
