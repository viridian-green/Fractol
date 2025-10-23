/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:32:38 by ademarti          #+#    #+#             */
/*   Updated: 2024/06/11 12:14:54 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include "libft/libft.h"

// real n;
// imaginary n;
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*pixel;
	int		bpp;
	int		size_line;
	int		endian;
	char	*addr;
}	t_image;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win;
	t_image	image;
	char	*name;
	double	param_x;
	double	param_y;
	int		color;
	double	x_max;
	double	offset_y;
	double	offset_x;
	double	move_x;
	double	move_y;
	double	x_min;
	double	y_max;
	double	y_min;
	double	zoom;
	int		iter;
	int		max_iter;
}	t_fractal;

//Window dimensions
# define WIDTH	1450
# define HEIGHT	1450

// Keys
# define KEY_ESC 65307
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_UPWARDS 65362
# define KEY_DOWNWARDS 65364

//Mouse wheel
# define MOUSE_UP 4
# define MOUSE_DOWN 5

//Handle arguments
int		handle_arguments(t_fractal *fractal, char **argv, int argc);
void	get_julia_values(t_fractal *fractal, char **argv, int argc);
int		valid_param(char *argv);

//Utils
double	ft_atof(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

//Initialization
void	init_values(t_fractal *fractal);
int		fractal_init(t_fractal *fractal);

//Render fractol
void	my_mlx_pixel_put(int x, int y, t_fractal *fractal, int color);
void	render_fractal(t_fractal *fractal);
void	mandelbrot(t_complex *comp, t_fractal *fractal);
void	julia(t_complex *comp, t_fractal *fractal);
void	mandel_vs_julia(t_complex *comp, t_fractal *fractal);

//Handle events
int		handle_keys(int key, t_fractal *fractal);
int		handle_mouse(int button, int x, int y, t_fractal *fractal);

//Clean and exit
int		kill_window(t_fractal *fractal);
int		exit_clean(t_fractal *fractal);

//Coloring functions
int		create_trgb(int t, int r, int g, int b);
int		get_red(int trgb);
int		get_green(int trgb);
int		get_blue(int trgb);
int		get_color(int iter, int max_iter);

#endif
