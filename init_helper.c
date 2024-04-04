#include "./fractol.h"

t_RenderData *init_mandelbrot(mlx_t *window, int argc, char **argv)
{
	t_FractalBounds *bounds;
	t_RenderData	*render_data;
	int				precision;

	bounds = init_FractalBounds(-2.0, 2.0, -2.0, 2.0);
	if (!bounds)
		return (NULL);
	if (argc >= 3)
		precision = ft_atoi(argv[2]);
	else
		precision = 300;
	render_data = init_rData(bounds, window, &mandelbrot, precision);
	if (!render_data)
	{
		free(bounds);
		return (NULL);
	}
	return (render_data);
}

static void init_j_params(void *bounds, t_DoublePair *c, int argc, char **argv)
{
	if (argc == 4 || argc > 5)
	{
		write(1, "bad input\n", 10);
		return (NULL);
	}

	bounds = init_FractalBounds(-2.0, 2.0, -2.0, 2.0);
	if (!bounds)
		return (NULL);

	c = (t_DoublePair *)malloc(sizeof(t_DoublePair));
	if (c != NULL)
	{
		c->x = ft_atoi(argv[3]);
		c->y = ft_atoi(argv[4]);
	}
	else
	{
		free(bounds);
		return (NULL);
	}
	if (c->x == 0)



}


t_RenderData *init_julia(mlx_t *window, int argc, char **argv)
{
	t_FractalBounds *bounds;
	t_RenderData	*render_data;
	t_DoublePair	*c;
	int				precision;

	bounds = init_FractalBounds(-2.0, 2.0, -2.0, 2.0);
	if (!bounds)
		return (NULL);

	if (argc >= 3)
		precision = ft_atoi(argv[2]);
	else
		precision = 300;

	init_j_params(bounds, c, argc, argv);
	if (argc >= 5 && precision != 0)
	{
		c = (t_DoublePair *)malloc(sizeof(t_DoublePair));
		if (c == NULL)
		{
			free(bounds);
			return (NULL);
		}
		else
		{
			c->x = ft_atoi(argv[3]);
			c->y = ft_atoi(argv[4]);
		}
	}
	else


	render_data = init_rData(bounds, window, &mandelbrot, precision);
	if (!render_data)
	{
		free(bounds);
		return (NULL);
	}
	render_data->j_params = c;
	return (render_data);
}

t_RenderData *init_debug(mlx_t *window, int argc, char **argv)
{
	t_FractalBounds *bounds;
	t_RenderData	*render_data;
	int				precision;

	bounds = init_FractalBounds(-2.0, 2.0, -2.0, 2.0);
	if (!bounds)
		return (NULL);
	if (argc == 3)
	{
		precision = ft_atoi(argv[2]);
	}
	else
		precision = 300;
	render_data = init_rData(bounds, window, &mandelbrot, precision);
	if (!render_data)
	{
		free(bounds);
		return (NULL);
	}
	return (render_data);
}
