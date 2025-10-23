/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:32:08 by ademarti          #+#    #+#             */
/*   Updated: 2024/06/11 12:40:39 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	blend_with_white(int color, float blend_factor)
{
	int	red;
	int	green;
	int	blue;
	int	white_blend;

	red = get_red(color);
	green = get_green(color);
	blue = color % 256;
	white_blend = (color / 2) % 256;
	blue = (blue + white_blend) / 2;
	red = (int)(red + blend_factor * (255 - red));
	blue = (int)(blue + blend_factor * (255 - blue));
	return (create_trgb(0, red, green, blue));
}

int	get_color(int iter, int max_iter)
{
	int		color;
	float	blend_factor;
	float	distance_factor;

	color = iter * 25;
	color = create_trgb(0, get_red(color), get_green(color), get_blue(color));
	distance_factor = (float)iter / max_iter;
	blend_factor = pow(1.0 - distance_factor, 3.0);
	return (blend_with_white(color, blend_factor));
}
