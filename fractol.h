#ifndef FRACTOL_H
# define FRACTOL_H

# include "/Users/adelemartin/Fractol/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_complex
{
	//real n
	double real;

	//imaginary n
	double i;

} t_complex;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;

} t_data;

//Window dimensions
# define WIDTH	1000
# define HEIGHT	1000

#endif
