#include "fractol.h"

double ft_atof(const char *str)
{
	int		i;
	double	result;
	double divisor;
	int sign;

	result = 0;
	sign = 1;
	i = 0;
	divisor = 0.1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while ((str[i] >= '0' && str[i] <= '9'))
		{
			result = result + (str[i] - '0') * divisor;
			divisor *= 0.1;
			i++;
		}

	}
		return  (sign * (result));
}

int handle_keys(int key, t_fractal *fractal)
{
	//if (key == 65293)
	//{
	//	mlx_clear_window(fractal->mlx_ptr, fractal->win);
	//	exit(0);
	//	kill_window(fractal);
	//}
	if (key == 65363) //right arrow --> zoom in
		fractal->zoom *= 0.5;
	else if (key == 65361) //left arrow
		fractal->zoom *= 2.0;
	mandelbrot_set(fractal);
	return (0);
}
