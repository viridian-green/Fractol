#include "fractol.h"

//Mimicks the mlx_pixel_put function
//Writes the pixels in a 2d image: colors each pixel at x and y coordinates

void my_mlx_pixel_put(int x, int y, t_fractal *fractal, int color)
{
	int offset;

	offset = (y * fractal->image.size_line) + ((fractal->image.bpp / 8) * x);
	*(unsigned int *)(fractal->image.pixel + offset) = color;
}

//Convert the pixels into complex numbers on the plane
t_complex	map_pixel(t_complex *comp, int x, int y, t_fractal *fractal)
{
	comp->x = ((x * (fractal->x_max - fractal->x_min) / WIDTH) + fractal->x_min) * fractal->zoom;
	comp->y = ((y * (fractal->y_max - fractal->y_min) / HEIGHT) + fractal->y_min) * fractal->zoom;
	return (*comp);
}

void init_values(t_fractal *fractal)
{
	fractal->x_max = 2.0;
	fractal->x_min = -2.0;
	fractal->y_max = 2.0;
	fractal->y_min = -2.0;
	fractal->color = 0XFFB6CB;
	fractal->zoom = 1.0;
	fractal->max_iter = 50; //Change this value to see if it still works
}

void mandelbrot(t_complex *comp, int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	double temp;
	int i;

	z.x = 0;
	z.y = 0;
	c.x = comp->x; // c is the point in plane which corresponds to pixel
	c.y = comp->y;
	i = 0;
	while (++i < fractal->max_iter)
	{
		temp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ; //this means the point escapes to infinity and is outside the set
	}
	return (i);
}

void julia(t_complex *comp, int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	double temp;
	int i;

	z.x = comp->x;
	z.y = comp->y;
	c.x = fractal->first_param; // c is the point in plane which corresponds to pixel
	c.y = fractal->second_param;
	fractal->iter = 0;
	while (++fractal->iter < fractal->max_iter)
	{
		temp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ; //this means the point escapes to infinity and is outside the set
	}
	return (fractal->iter);
}

int kill_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win);
	mlx_destroy_display(fractal->mlx_ptr);
	exit(0);
	return (0);
}

void mandel_vs_julia(t_complex *comp, int x, int y, t_fractal *fractal)
{
	if (fractal->name == "mandelbrot")
		mandelbrot(&comp, x, y, fractal);
	else if (fractal->name == "julia")
		julia(&comp, x, y, fractal);
}

void render_fractal(t_fractal *fractal)
{
	t_complex comp;
	int x;
	int y;
	int iter;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			comp = map_pixel(&comp, x, y, fractal);
			mandel_vs_julia((&comp, x, y, fractal));
			if (fractal->iter == fractal->max_iter)
				my_mlx_pixel_put(x, y, fractal, 0x000000);
			else
				my_mlx_pixel_put(x, y, fractal,  get_color(fractal->iter));
		}
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win, fractal->image.img_ptr, 0, 0);
}