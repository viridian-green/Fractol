/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:15:36 by ademarti          #+#    #+#             */
/*   Updated: 2024/06/10 15:25:36 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_complex *comp, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		temp;

	z.x = 0;
	z.y = 0;
	c.x = comp->x + fractal->move_x;
	c.y = comp->y + fractal->move_y;
	fractal->iter = 0;
	while (++(fractal->iter) < fractal->max_iter)
	{
		temp = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ;
	}
}
