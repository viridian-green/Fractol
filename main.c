#include "fractol.h"

int handle_arguments(t_fractal *fractal, char **argv)
{
	fractal->name = argv[1];
	if (ft_strncmp(fractal->name, "mandelbrot", 10))
		return (1);
	else if (ft_strncmp(fractal->name, "julia", 5))
	{
		if (argv[2] && argv[3])
		{
			fractal->first_param = ft_atof(argv[2]);
			fractal->second_param = ft_atof(argv[3]);
		}
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