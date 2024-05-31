#include "fractol.h"

void	init_values(t_fractal *fractal)
{
	fractal->mlx_ptr = NULL;
	fractal->win = NULL;
	fractal->image.img_ptr = NULL;
	fractal->image.pixel = NULL;
	fractal->image.bpp = 0;
	fractal->image.size_line = 0;
	fractal->image.endian = 0;
	fractal->x_max = -2.0;
	fractal->x_min = 1.5;
	fractal->y_max = -2.0;
	fractal->y_min = 1.5;
	fractal->color = 0XFFB6CB;
	fractal->zoom = 1.0;
	fractal->max_iter = 50; //Change this value to see if it still works

}

int	fractal_init(t_fractal *fractal)
{
	init_values(fractal);
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
	{
		exit_clean(fractal);
	}
	fractal->win = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, "I <3 fractals");
	if (!fractal->win)
	{
		exit_clean(fractal);
	}
	fractal->image.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->image.img_ptr)
	{
		exit_clean(fractal);
	}
	fractal->image.pixel = mlx_get_data_addr(fractal->image.img_ptr,
	&fractal->image.bpp, &fractal->image.size_line, &fractal->image.endian);
	return (0);
}