#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx_int.h"
# include "minilibx/mlx.h"
# include <math.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_complexss
{
	//real n
	double real;

	//imaginary n
	double i;

} t_complex;

typedef struct s_fractal
{
	void *mlx_ptr;
	void *win;
	t_img img;
} t_fractal;

//Window dimensions
# define WIDTH	1000
# define HEIGHT	1000

#endif
