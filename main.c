/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:06:24 by ademarti          #+#    #+#             */
/*   Updated: 2024/06/11 12:47:05 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_param(char *argv)
{
	while (*argv)
	{
		if ((*argv >= '0' && *argv <= '9') || *argv == '+'
			|| *argv == '-' || *argv == '.' || *argv == ' ')
			argv++;
		else
		{
			ft_putstr_fd("The valid format is a sign followed by a number\n", 1);
			exit(1);
		}
	}
	return (1);
}

void	get_julia_values(t_fractal *fractal, char **argv, int argc)
{
	if (argc >= 4 && argv[2] && argv[3])
	{
		if ((valid_param(argv[2]) == 1) && (valid_param(argv[3]) == 1))
		{
			fractal->param_x = ft_atof(argv[2]);
			fractal->param_y = ft_atof(argv[3]);
		}
	}
	else if (argc == 2)
	{
		fractal->param_x = -0.7269;
		fractal->param_y = 0.1889;
	}
	else
	{
		ft_putstr_fd("Invalid input. Please enter <./fractal> and a fractal set.\n \
		 Available fractal sets are 'mandelbrot' and 'julia'.\n", 1);
		exit(1);
	}
}

int	handle_arguments(t_fractal *fractal, char **argv, int argc)
{
	fractal->name = argv[1];
	if ((ft_strcmp(fractal->name, "mandelbrot") == 0) && argc == 2)
		return (1);
	else if ((ft_strcmp(fractal->name, "julia") == 0))
	{
		get_julia_values(fractal, argv, argc);
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc < 2 || handle_arguments(&fractal, argv, argc) == 0)
	{
		ft_putstr_fd("Invalid input.Please enter <./fractal> and a fractal set.\n \
		Available fractal sets are 'mandelbrot' and 'julia'.\n", 1);
		exit(1);
	}
	fractal_init(&fractal);
	render_fractal(&fractal);
	mlx_key_hook(fractal.win, handle_keys, &fractal);
	mlx_mouse_hook(fractal.win, handle_mouse, &fractal);
	mlx_hook(fractal.win, DestroyNotify, \
	StructureNotifyMask, kill_window, &fractal);
	mlx_loop(fractal.mlx_ptr);
	exit_clean(&fractal);
}
