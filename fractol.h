#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx_int.h"
# include "minilibx/mlx.h"
# include <math.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_complex
{
	//real n
	double x;

	//imaginary n
	double y;

} t_complex;

typedef struct	s_image
{
	void	*img_ptr;
	char	*pixel;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win;
	t_image	image;
	char	*name;
	double	first_param;
	double	second_param;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	int		iter;
	int		max_iter;
} t_fractal;

//Window dimensions
# define WIDTH	1000
# define HEIGHT	1000

//Utils
double ft_atof(const char *str);

//Mandelbrot
void my_mlx_pixel_put(int x, int y, t_fractal *fractal, int color);

#endif
