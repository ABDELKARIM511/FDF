#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>

void	repeatitj2(mlxk window, int size,int osize,t_data img,int color)
{
	double		x;
	double		y1;
	double		y;
	double	m;

	y = window.beginy;
	y1 = 0.1 * (window.beginx - window.mapz) + y - size;
	x = (y -  window.mapz)/3 + window.beginx + size;
	m = ((0.1 * (window.beginx - window.mapz) + window.beginy +  window.mapz - osize) - y1)/(((window.beginy + window.mapz - window.mapz)/3 + window.beginx + osize) - x);
	if(m > 1 || m < -1)
	{
		if (window.beginy + osize < y + window.mapz + size)
		{
			while (window.beginy + osize < y + window.mapz + size)
			{
				my_mlx_pixel_put(&window, ((0.1 * (window.beginx - window.mapz) + window.beginy - size) - y1)/m + x , 0.1 * (window.beginx - window.mapz) + window.beginy - size, color);
				//mlx_pixel_put ( window.mlx, window.mlx_win, ((0.1 * (window.beginx - window.mapz) + window.beginy - size) - y1)/m + x, 0.1 * (window.beginx - window.mapz) + window.beginy - size,16777215);
				window.beginy++;
			}
		}
		else
		{
			while (window.beginy + osize > y + window.mapz + size)
			{
				my_mlx_pixel_put(&window, ((0.1 * (window.beginx - window.mapz) + window.beginy - size) - y1)/m + x , 0.1 * (window.beginx - window.mapz) + window.beginy - size, color);
				//mlx_pixel_put ( window.mlx, window.mlx_win, ((0.1 * (window.beginx - window.mapz) + window.beginy - size) - y1)/m + x, 0.1 * (window.beginx - window.mapz) + window.beginy - size,16777215);
				window.beginy--;
			}
		}
	}
}