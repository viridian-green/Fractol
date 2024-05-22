#include "fractol.h"

void mandelbrot_set(t_fractal *fractal, double x_min, double x_max, double y_min, double y_max)
{
	//a + bi
	while (z < 41)
	{
		z = (z * z)
	}
	//(a + bi)² or (a + bi) * (a + bi)
}

int handle_arguments(t_fractal *fractal, char **argv)
{
	fractal->name = av[1];

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
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	//protect it here

	//allows us to modify the image later
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img_ptr,
	&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);

	return (0);
}

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

int main(int argc, char **argv)
{
	t_fractal	fractal;
	if (argc == 2)
	{
	handle_arguments(&argv, &fractal);
	fractal_init(&fractal);
	mandelbrot_set(&fractal, -2, 2, -2, 2);
	//pixels_to_screen(&fractal);
	(void)argv;
	mlx_destroy_window(fractal.mlx_ptr, fractal.win);
	mlx_destroy_display(fractal.mlx_ptr);
	free(fractal.mlx_ptr);
	}
	else
		ft_putstr_fd("Missing input.\n Available fractals are\n 'mandelbrot'\n 'julia'\n If you chose 'Julia' please enter two paremeters", 1);
}

//entering float values at command line