#include "fractol.h"

/*The Mandelbrot set binds the points outside infinity. When you
leave it, you enter infinity.
A mandelbrot point always stays bounded within mandelbrot zone/*/

/*https://pulgamecanica.herokuapp.com/posts/mlx42-intro*/

void function()
{
	t_complex z;
	t_complex c;
//	double temp;

	z.real = 0;
	z.i = 0;

	c.real = 2;
	c.i = 5;

	//int i = 0;
	//while (i < 42)
	//{
	//	temp = (z.real * z.real);
	//}

}

//for mac, change the flags, include a library to make it work.
int main()
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init(WIDTH, HEIGHT, "Fractol", false);
	if (!mlx_ptr)
	{
		return (1);
		exit(1);
	}
	mlx_texture_t* texture = mlx_load_png("./images/menu_bg.png")

	//mlx_delete_image(mlx_ptr, img);
}
