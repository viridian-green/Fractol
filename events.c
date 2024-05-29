#include "fractol.h"

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
	render_fractal(fractal);
	return (0);
}

/*
int handle_mouse(int button, int x, int y, t_fractal *fractal)
{
    if (button == 4)
    {
        fractal->zoom =
    }
    else if (button == 5)
    {
        fractal->zoom =
    }
    else
    {
        return (0);
    }        return (0);
}
*/