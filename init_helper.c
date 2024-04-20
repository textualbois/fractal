#include "./fractol.h"

t_RenderData	*init_mandelbrot(mlx_t *window, int argc, char **argv, int f_id)
{
	t_FractalBounds	*bounds;
	t_RenderData	*render_data;
	int				precision;

	bounds = init_FractalBounds(-2.0, 2.0, -2.0, 2.0);
	if (!bounds)
		return (NULL);
	if (argc == 3)
		precision = ft_atoi(argv[2]);
	else
		precision = 300;
	if (f_id == mandel)
		render_data = init_rData(bounds, window, &mandelbrot, precision);
	else
		render_data = init_rData(bounds, window, &burning_ship, precision);
	if (!render_data)
	{
		free(bounds);
		return (NULL);
	}
	return (render_data);
}

static void	init_j_params(t_FractalBounds **bounds, t_DoublePair **c, int argc, char **argv)
{
	*bounds = init_FractalBounds(-2.0, 2.0, -2.0, 2.0);
	if (*bounds != NULL)
	{
		*c = (t_DoublePair *)malloc(sizeof(t_DoublePair));
		if (*c != NULL)
		{
			if (argc == 5)
			{
				(*c)->x = ft_atod(argv[3]);
				(*c)->y = ft_atod(argv[4]);
			}
			else
			{
				(*c)->x = 0;
				(*c)->y = 0;
			}
		}
		else
		{
			free(bounds);
			bounds = NULL;
		}
	}
}

t_RenderData *init_julia(mlx_t *window, int argc, char **argv)
{
	t_FractalBounds *bounds;
	t_RenderData	*render_data;
	t_DoublePair	*c;
	int				precision;

	bounds = NULL;
	c = NULL;
	if (argc >= 3)
		precision = ft_atoi(argv[2]);
	else
		precision = 300;
	init_j_params(&bounds, &c, argc, argv);
	if (bounds == NULL)
		return (NULL);
	render_data = init_rData(bounds, window, &julia, precision);
	if (render_data == NULL)
	{
		free(bounds);
		free(c);
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
