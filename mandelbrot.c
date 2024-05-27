#include "fractol.h"

//Mimicks the mlx_pixel_put function
//Writes the pixels in a 2d image: colors each pixel at x and y coordinates


void my_mlx_pixel_put(int x, int y, t_fractal *fractal, int color)
{
	int offset;

	offset = (y * fractal->image.size_line) + ((fractal->image.bpp / 8) * x);
	*(unsigned int *)(fractal->image.pixel + offset) = color;
	//char	*dst;

	//dst = fractal->image.addr + (y * fractal->image.size_line + x * (fractal->image.bpp / 8));

	//if (dst < fractal->image.addr || dst >= fractal->image.addr + (HEIGHT * fractal->image.size_line)) {
    //    return;
    //}
	//*(unsigned int *)dst = color;
}

void math(t_complex *comp, int x, int y, t_fractal *fractal) {
    t_complex z;
    t_complex c;
    double temp;

    z.x = 0.0;
    z.y = 0.0;
    c.x = comp->x + fractal->move_y; // add move_y and move_x later for the zoom
    c.y = comp->y + fractal->move_x;

    int i;
    for (i = 0; i < fractal->max_iter; i++) {
        temp = z.x * z.x - z.y * z.y + c.x;
        z.y = 2 * z.x * z.y + c.y;
        z.x = temp;
        if (z.x * z.x + z.y * z.y > 4) {
            my_mlx_pixel_put(x, y, fractal, 0xFFFFFF * i); // Coloring based on iteration count
            return;
        }
    }
    my_mlx_pixel_put(x, y, fractal, 0x000000); // Pixel is inside the Mandelbrot set
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
	fractal->color = 0XFFB6CB;
	fractal->max_iter = 50; //Change this value to see if it still works
}

/*
void math(t_complex *comp, int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	double temp;

	z.x = 0.0;
	z.y = 0.0;
	c.x = comp->x + fractal->move_y; //add move_y and move_x later for the zoom
	c.y = comp->y + fractal->move_x;
	fractal->iter = 0;
	while (++(fractal->iter) < fractal->max_iter)
	{
		temp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ; //making sure the imaginary part of the complex number is adequatily computed
 //this means the point escapes to infinity and is outside the set
	}
	if (fractal->iter == fractal->max_iter)
		my_mlx_pixel_put(x, y, fractal, 0x000000); //Case 2
	else
		my_mlx_pixel_put(x, y, fractal,  0XFFFFFF * fractal->iter); //Case 1
}
*/


int kill_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win);
	mlx_destroy_display(fractal->mlx_ptr);
	exit(0);
	return (0);
}

/*
int handle_mouse(int button, int x, int y, t_fractal *fractal)
{
    double mouse_x = (double)x / WIDTH * (fractal->x_max - fractal->x_min) + fractal->x_min;
    double mouse_y = (double)y / HEIGHT * (fractal->y_max - fractal->y_min) + fractal->y_min;
    double zoom_factor;

    if (button == 4) // Scroll up (zoom in)
    {
        zoom_factor = ZOOM_IN_FACTOR;
    }
    else if (button == 5) // Scroll down (zoom out)
    {
        zoom_factor = ZOOM_OUT_FACTOR;
    }
    else
    {
        return (0);
    }        return (0);
}
*/
void mandelbrot_set(t_fractal *fractal)
{
	t_complex comp;
	int x;
	int y;

	x = 0;
	y = 0;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			comp = map_pixel(&comp, x, y, fractal);
			math(&comp, x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win, fractal->image.img_ptr, 0, 0);
} 