#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>

static double x2(mlxk window, int osize)
{
	return (window.beginy /3 + window.beginx + osize);
}
static double y2(mlxk window, int osize)
{
	return(0.1 * (window.beginx - window.mapz) + window.beginy + window.mapz - osize);
}

static double ft_tan(double x0, double y0,mlxk window,int osize)
{
	return ((y2(window, osize) - y0)/(x2(window, osize) - x0));
}

void	repeatitj(mlxk window, int size,int osize,int color)
{
	double	x0;
	double	y0;
	double	m;
	double	j;

	y0 = 0.1 * (window.beginx - window.mapz) + window.beginy - size;
	x0 = (window.beginy -  window.mapz)/3 + window.beginx + size;
	m = ft_tan(x0, y0, window,osize);
	j = y2(window, osize);
	while ((int)y0 != (int)j)
	{
		my_mlx_pixel_put(&window, x0 , y0, color);
		if(m >= 1 || m <= -1)
		{
			y0++;
			x0 = x0 + 1/m;
		}
		else
		{
			x0++;
			y0 = y0 + m;
		}
	}
}