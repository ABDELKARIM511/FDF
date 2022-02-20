#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>

void	repeatit2(mlxk window, int size, int osize,t_data img,int color)
{
	double		x;
	double		x1;
	double		y;
	double	m;

	x = window.beginx;
	y = 0.1 * (x - window.mapz) + window.beginy - size;
	x1 = (window.beginy - window.mapz)/3 + x + size;
	m = ((0.1 * (x - window.mapz + window.mapz) + window.beginy - osize) - y)/(((window.beginy - window.mapz)/3 + window.beginx + window.mapz + osize) - x1);
	if ((m <= 1 && m > 0) || (m < 0 && m >= -1))
	{
		if (window.beginx + size < x + window.mapz + osize)
		{
			while (window.beginx + size < x + window.mapz + osize)
			{
				my_mlx_pixel_put(&window, (window.beginy - window.mapz)/3 + window.beginx + size , (m * (((window.beginy - window.mapz)/3 + window.beginx + size ) - x1)) + y, color);
				window.beginx++;
			}
		}
		else
		{
			while (window.beginx + size > x + window.mapz + osize)
			{
				my_mlx_pixel_put(&window, (window.beginy - window.mapz)/3 + window.beginx + size , (m * (((window.beginy - window.mapz)/3 + window.beginx + size ) - x1)) + y, color);
				window.beginx--;
			}
		}
	}
}