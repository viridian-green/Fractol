#include "fractol.h"

//Mimicks the mlx_pixel_put function
//Writes the pixels in a 2d image: colors each pixel at x and y coordinates
void my_mlx_pixel_put(int x, int y, t_fractal *fractal, int color)
{
	int	offset;

	offset = (y * fractal->image.size_line) + ((fractal->image.bpp / 8) * x);
	*(unsigned int *)(fractal->image.pixel + offset) = color;
}


//Convert the pixels into complex numbers on the plane
t_complex	map_pixel(t_complex *comp, int x, int y, t_fractal *fractal)
{
	comp->x = (x * (fractal->x_max - fractal->x_min) / WIDTH) + fractal->x_min;
	comp->y = (y * (fractal->y_max - fractal->y_min) / HEIGHT) + fractal->y_min;
	return (*comp);
}

void init_values(t_fractal *fractal)
{
	fractal->x_max = 2.0;
	fractal->x_min = -2.0;
	fractal->y_max = 2.0;
	fractal->y_min = -2.0;
	fractal->max_iter = 1000; //Change this value to see if it still works
}

void math(t_complex *comp, int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	double temp;

	z.x = 0.0;
	z.y = 0.0;
	c.x = comp->x; //add move_y and move_x later for the zoom
	c.y = comp->y;
	fractal->iter = 0;
	while (++fractal->iter < fractal->max_iter)
	{
		temp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y; //making sure the imaginary part of the complex number is adequatily computed
		z.x = temp;
		if ((z.x * z.x) + (z.y * z.y) >= 4) //this means the point escapes to infinity and is outside the set
			break;
	}
	if (fractal->iter == fractal->max_iter)
		my_mlx_pixel_put(x, y, fractal, 0x000000); //Case 2
	else
		my_mlx_pixel_put(x, y, fractal, 0xFFFFFF); //Case 1

}

void mandelbrot_set(t_fractal *fractal)
{
	t_complex comp;
	int x;
	int y;

	x = -1;
	y = -1;

	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			comp = map_pixel(&comp, x, y, fractal);
			math(&comp, x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win, fractal->image.img_ptr, 0, 0);
	mlx_loop(fractal->mlx_ptr);
} 