#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int get_color(int iter, int max_iter)
{
    int color;
    color = iter * 25;
	(void)max_iter;
	//int r = (int)(9 * (1 - t) * t * t * t * 255);
    //int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    //int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    //return create_trgb(0, r, g, b);
	return(create_trgb(get_t(color), get_r(color), get_g(color), get_b(color)));
}