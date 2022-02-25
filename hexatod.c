/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexatod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:49:27 by aer-razk          #+#    #+#             */
/*   Updated: 2022/02/25 14:49:28 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

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
