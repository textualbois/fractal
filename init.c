#include "./fractol.h"

t_FractalBounds	*init_FractalBounds(double min_r, double max_r, double min_i, double max_i)
{
	t_FractalBounds	*bounds;

	bounds = (t_FractalBounds *)malloc(sizeof(t_FractalBounds));
	if (bounds == NULL)
		return (NULL);
	bounds->min_r = min_r;
	bounds->max_r = max_r;
	bounds->min_i = min_i;
	bounds->max_i = max_i;
	return (bounds);
}

// Function to initialize RenderData struct
t_RenderData	*init_rData(t_FractalBounds *bounds, mlx_t *window, void *set_func, int precision)
{
	t_RenderData	*render_data;

	render_data = (t_RenderData *)malloc(sizeof(t_RenderData));
	if (render_data == NULL)
		return (NULL);
	render_data->image = mlx_new_image(window, WIDTH, HEIGHT);
	if (!(render_data->image))
	{
		puts(mlx_strerror(mlx_errno));
		return (NULL);
	}
	render_data->bounds = bounds;
	render_data->zoom = 1.0;
	render_data->precision = precision;
	render_data->Width = WIDTH;
	render_data->Height = HEIGHT;
	render_data->iter_count = iter_data(WIDTH, HEIGHT);
	if (render_data->iter_count == NULL)
	{
		puts(mlx_strerror(mlx_errno));
		free_RenderData(render_data);
		return (NULL);
	}
	render_data->set_func = set_func;
	return (render_data);
}

// Function to initialize W_R_D struct
t_W_R_D	*init_W_R_D(mlx_t *window, t_RenderData *render_data)
{
	t_W_R_D	*w_r_d;

	w_r_d = (t_W_R_D *)malloc(sizeof(t_W_R_D));
	if (w_r_d == NULL)
		return (NULL);
	w_r_d->window = window;
	w_r_d->r_data = render_data;
	return (w_r_d);
}


t_W_R_D	*init_all(mlx_t *window, int func_id, int argc, char **argv)
{
	t_RenderData	*render_data;
	t_W_R_D			*w_r_d;

	if (func_id == mandel)
		render_data = init_mandelbrot(window, argc, argv);
	else if (func_id == jul)
	{
		printf("initing julia\n");
		render_data = init_julia(window, argc, argv);
	}
	else
		render_data = init_debug(window, argc, argv);
	if (render_data == NULL)
		return (NULL);
		render_data->f_code = func_id;
	w_r_d = init_W_R_D(window, render_data);
	if (w_r_d == NULL)
		free_RenderData(render_data);
	return (w_r_d);
}
