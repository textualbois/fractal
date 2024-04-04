#include "./fractol.h"

static int check_mandelbrot(int argc, char **argv)
{
	if (argc >= 3)
	{
		if (ft_isint(argv[2]) == 0)
		{
			printf("second parameter should be int\n");
			return (0);
		}
		else if (argc >= 4)
		{
			printf("Wrong argument count\n0 or 1 extra allowed\n");
			return (0);
		}
	}
	return (1);
}

static int check_julia(int argc, char **argv)
{
	if (argc >= 3)
	{
		if (ft_isint(argv[2]) == 0)
		{
			printf("second parameter should be int\n");
			return (0);
		}
		else if (argc == 4 || argc >= 6)
		{
			printf("Wrong argument count\n0, 1 or 2 extra allowed\n");
			return (0);
		}
		else if (!ft_isdouble(argv[3]) || !ft_isdouble(argv[4]))
		{
			printf("Arguments 3 and 4 have to be of type double or int\n");
			return (0);
		}
	}
	return (2);
}

static int check_debug(int argc, char **argv)
{
	if (argc >= 2)
	{
		return (0);
	}
	return (3);
}

int check_input(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!ft_strncmp(argv[1], "julia\0", 6))
			return (check_julia(argc, argv));
		else if (!ft_strncmp(argv[1], "mandelbrot\0", 10))
			return (check_mandelbrot(argc, argv));
		else if (!ft_strncmp(argv[1], "debug\0", 5))
			return (check_debug(argc, argv));
		else
		{
			printf("Specify fractal in first parameter\n");
			return (0);
		}
	}
	else
	{
		printf("At least 1 parameter required\n");
		return (0);
	}
}
