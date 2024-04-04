#include "./fractol.h"




int check_input(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!ft_strncmp(argv[1], "julia\0", 6))
		return (check_julia(argc, argv));
	else if (!ft_strncmp(argv[1], "mandelbrot\0", 10))
		return (check_mandelbrot(argc, argv));
	else if (!ft_strncmp(argv[1], "debug\0", 5))
		return (check_debug(argc, argv));
	else
		return (0);
}
