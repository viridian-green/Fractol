/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:06:49 by ademarti          #+#    #+#             */
/*   Updated: 2024/06/10 12:07:12 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_clean(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win);
	mlx_destroy_display(fractal->mlx_ptr);
	mlx_loop_end(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	free(fractal);
	exit(0);
}

int	kill_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(0);
	return (0);
}
