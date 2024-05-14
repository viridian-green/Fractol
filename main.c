#include "fractol.h"

/*The Mandelbrot set binds the points outside infinity. When you
leave it, you enter infinity.
A mandelbrot point always stays bounded within mandelbrot zone/*/

typedef struct s_complex
{
	//real n
	double real;

	//imaginary n
	double i;

} t_complex;

//haha

//for mac, change the flags, include a library to make it work.
int main()
{
	t_complex z;
	t_complex c;
//	double temp;

	z.real = 0;
	z.i = 0;

	c.real = 2;
	c.i = 5;
	void	*mlx;

	mlx = mlx_init();
	void	*mlx_win;
	
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	//int i = 0;
	//while (i < 42)
	//{
	//	temp = (z.real * z.real);
	//}


}
