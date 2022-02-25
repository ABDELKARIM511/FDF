/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagepixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:48:31 by aer-razk          #+#    #+#             */
/*   Updated: 2022/02/25 14:48:32 by aer-razk         ###   ########.fr       */
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
