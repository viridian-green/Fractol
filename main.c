#include "fractol.h"

/*The Mandelbrot set binds the points outside infinity. When you
leave it, you enter infinity.
A mandelbrot point always stays bounded within mandelbrot zone/*/

void function()
{
	//t_complex z;
//	double temp;

	//z.real = 0;
	//z.i = 0;

	//c.real = 2;
	//c.i = 5;

	//int i = 0;
	//while (i < 42)
	//{
	//	temp = (z.real * z.real);
	//}

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
	//fractal->img.image = mlx_
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("Please enter a parameter.", 1);
	}
	t_fractal fractal;

	fractal_init(&fractal);
	/*
	*/
	(void)argv;
	mlx_destroy_window(fractal.mlx_ptr, fractal.win);
	mlx_destroy_display(fractal.mlx_ptr);
	free(fractal.mlx_ptr);
}
