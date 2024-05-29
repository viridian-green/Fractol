#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
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
	int		size_line;
	int		endian;
	char *addr;
}	t_image;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win;
	t_image	image;
	char	*name;
	char	*first_param;
	char 	*second_param;
	int color;
	double	x_max;
	double offset_y;
	double offset_x;
	double move_x;
	double move_y;
	double	x_min;
	double	y_max;
	double	y_min;
	double zoom;
	int		iter;
	int		max_iter;
} t_fractal;

//Window dimensions
# define WIDTH	1000
# define HEIGHT	1000

//Utils
double ft_atof(const char *str);

//Initialization
void init_values(t_fractal *fractal);

//Mandelbrot
void my_mlx_pixel_put(int x, int y, t_fractal *fractal, int color);
void mandelbrot_set(t_fractal *fractal);
void math(t_complex *comp, int x, int y, t_fractal *fractal);

int handle_keys(int key, t_fractal *fractal);
int handle_mouse(int button, int x, int y, t_fractal *fractal);

//Clean and exit
int kill_window(t_fractal *fractal);
#endif
