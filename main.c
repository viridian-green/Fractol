#include "fractol.h"
void get_julia_values(t_fractal *fractal, char **argv, int argc)
{
	if (argc > 2 && argv[2] && argv[3])
		{
			fractal->param_x = ft_atof(argv[2]);
			fractal->param_y = ft_atof(argv[3]);
		}
	else if (argc == 2)
	{
		fractal->param_x = ft_atof(argv[2]);
		fractal->param_y = ft_atof(argv[3]);
	}

}
int handle_arguments(t_fractal *fractal, char **argv, int argc)
{
	fractal->name = argv[1];
	if (ft_strncmp(fractal->name, "mandelbrot", 10))
		return (1);
	else if (ft_strncmp(fractal->name, "julia", 5))
	{
		get_julia_values(fractal, argv, argc);
		return (1);
	}
	else
		return (0);
}

int main(int argc, char **argv)
{
	t_fractal	fractal;
	if (handle_arguments(&fractal, argv) == 0)
		return (0);
	fractal_init(&fractal);
	render_fractal(&fractal);
	mlx_key_hook(fractal.win, handle_keys, &fractal);
	//mlx_hook(fractal.win, handle_mouse, &fractal);
	mlx_hook(fractal.win, DestroyNotify,
	StructureNotifyMask, kill_window, &fractal);
	mlx_loop(fractal.mlx_ptr);
	(void)argv;
	mlx_destroy_window(fractal.mlx_ptr, fractal.win);
	mlx_destroy_display(fractal.mlx_ptr);
	free(fractal.mlx_ptr);
	if (argc == 1)
		ft_putstr_fd("Missing input.\n Available fractal sets are\n 'mandelbrot'\n 'julia'\n", 1);
}