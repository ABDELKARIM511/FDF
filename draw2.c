#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>

double x2(mlxk window, int osize)
{
	return ((window.beginy - window.mapz)/3 + window.beginx + window.mapz + osize);
}
double y2(mlxk window, int osize)
{
	return(0.1 * window.beginx + window.beginy - osize);
}

double ft_tan(double x0, double y0,mlxk window,int osize)
{
	return ((y2(window, osize) - y0)/(x2(window, osize) - x0));
}

void	repeatit(mlxk window, int size, int osize,int color)
{
	double	x0;
	double	y0;
	double	m;
	double j;

	y0 = 0.1 * (window.beginx - window.mapz) + window.beginy - size;
	x0 = (window.beginy - window.mapz)/3 + window.beginx + size;
	m = ft_tan(x0, y0, window, osize);
	j = x2(window, osize);
	while ((int)x0 != (int)j)
	{
		my_mlx_pixel_put(&window,x0, y0, color);
		if ((m <= 1 && m > 0) || (m < 0 && m >= -1))
		{
			x0++;
			y0 = y0 + m;
		}
		else
		{
			y0++;
			x0 = x0 + 1/m;
		}
	}
}
