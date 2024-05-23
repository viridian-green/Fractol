#include "fractol.h"

/*

void pixels_to_screen(t_fractal *fractal)
{
	int x;
	int y;

	x = -1;
	y = -1;

	while (++y < HEIGHT)
	{
		while (++x < WIDTH)
		{

		}
	}

}
*/

double ft_atof(const char *str)
{
	int	i;
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

void mandelbrot_set(t_fractal *fractal, double x_min, double x_max, double y_min, double y_max)
{
	//a + bi
	double x0 = 0;
	double y0 = 0;
	double x0 = x_min + (x_max - x_min) * px / WIDTH;
	double y0 = y_min + (y_max - y_min) * py / HEIGHT;
	//(a + bi)² or (a + bi) * (a + bi)
}

int handle_arguments(t_fractal *fractal, char **argv)
{
	fractal->name = argv[1];
	if (ft_strncmp(fractal->name, "mandelbrot", 10))
		return (1);
	else if (ft_strncmp(fractal->name, "julia", 5))
	{
		if (argv[2] && argv[3])
		{
			fractal->first_param = argv[2];
			fractal->second_param = argv[3];
		}
		return (1);
	}
	else
		return (0);
}

int fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		return (1);

	fractal->win = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, "fractal window");
	if (fractal->win == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		return (1);
	}
	//creates a blank image to be drawn into
	fractal->image.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	//protect it here

	//allows us to modify the image later
	fractal->image.pixel = mlx_get_data_addr(fractal->image.img_ptr,
	&fractal->image.bpp, &fractal->image.line_len, &fractal->image.endian);

	return (0);
}

int main(int argc, char **argv)
{
	t_fractal	fractal;
	//if (handle_arguments(&fractal, argv) == 0)
	//	return (0);
	fractal_init(&fractal);
	mandelbrot_set(&fractal, -2, 2, -2, 2);
	//pixels_to_screen(&fractal);
	//mlx_loop(fractal.mlx_ptr);
	(void)argv;
	mlx_destroy_window(fractal.mlx_ptr, fractal.win);
	mlx_destroy_display(fractal.mlx_ptr);
	free(fractal.mlx_ptr);
	if (argc == 1)
		ft_putstr_fd("Missing input.\n Available fractal sets are\n 'mandelbrot'\n 'julia'\n", 1);
}