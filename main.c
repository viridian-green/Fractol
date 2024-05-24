#include "fractol.h"

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

	fractal->win = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, "I <3 fractals");
	if (fractal->win == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		return (1);
	}
	//creates a blank image to be drawn into
	fractal->image.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (fractal->image.img_ptr  == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		return (1);
	}
	//allows us to modify the image later
	fractal->image.pixel = mlx_get_data_addr(fractal->image.img_ptr,
	&fractal->image.bpp, &fractal->image.size_line, &fractal->image.endian);

	return (0);
}

int main(int argc, char **argv)
{
	t_fractal	fractal;
	//if (handle_arguments(&fractal, argv) == 0)
	//	return (0);
	fractal_init(&fractal);
	init_values(&fractal);
	mandelbrot_set(&fractal);
	mlx_loop(fractal.mlx_ptr);
	(void)argv;
	mlx_destroy_window(fractal.mlx_ptr, fractal.win);
	mlx_destroy_display(fractal.mlx_ptr);
	free(fractal.mlx_ptr);
	if (argc == 1)
		ft_putstr_fd("Missing input.\n Available fractal sets are\n 'mandelbrot'\n 'julia'\n", 1);
}