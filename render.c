/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:32:21 by ademarti          #+#    #+#             */
/*   Updated: 2024/06/10 14:22:28 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Mimicks the mlx_pixel_put function
//Writes the pixels in a 2d image: colors each pixel at x and y coordinates

void	my_mlx_pixel_put(int x, int y, t_fractal *fractal, int color)
{
	int	offset;

	offset = (y * fractal->image.size_line) + ((fractal->image.bpp / 8) * x);
	*(unsigned int *)(fractal->image.pixel + offset) = color;
}

t_complex	map_pixel(t_complex *comp, int x, int y, t_fractal *fractal)
{
	comp->x = ((x * (fractal->x_max - fractal->x_min) \
	/ WIDTH) + fractal->x_min) * fractal->zoom + fractal->move_x;
	comp->y = ((y * (fractal->y_max - fractal->y_min) \
	/ HEIGHT) + fractal->y_min) * fractal->zoom + fractal->move_y;
	return (*comp);
}

void	mandel_vs_julia(t_complex *comp, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		mandelbrot(comp, fractal);
	else if (ft_strncmp(fractal->name, "julia", 10) == 0)
		julia(comp, fractal);
}

void	render_fractal(t_fractal *fractal)
{
	t_complex	comp;
	int			x;
	int			y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			comp = map_pixel(&comp, x, y, fractal);
			mandel_vs_julia(&comp, fractal);
			if (fractal->iter == fractal->max_iter)
				my_mlx_pixel_put(x, y, fractal, 0x000000);
			else
				my_mlx_pixel_put(x, y, fractal, \
				get_color(fractal->iter, fractal->max_iter));
		}
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win, \
	fractal->image.img_ptr, 0, 0);
}
