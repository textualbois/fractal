/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:08:48 by isemin            #+#    #+#             */
/*   Updated: 2024/04/24 18:48:32 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

t_bounds	*initbounds(double min_r, double max_r, double min_i, double max_i)
{
	t_bounds	*bounds;

	bounds = (t_bounds *)malloc(sizeof(t_bounds));
	if (bounds == NULL)
		return (NULL);
	bounds->min_r = min_r;
	bounds->max_r = max_r;
	bounds->min_i = min_i;
	bounds->max_i = max_i;
	return (bounds);
}

// Function to initialize RenderData struct
t_RData	*init_rdata(t_bounds *bounds, mlx_t *window, void *set_f, int max_iter)
{
	t_RData	*render_data;

	render_data = (t_RData *)malloc(sizeof(t_RData));
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
	render_data->max_iter = max_iter;
	render_data->width = WIDTH;
	render_data->height = HEIGHT;
	render_data->iter_count = iter_data(WIDTH, HEIGHT);
	if (render_data->iter_count == NULL)
	{
		puts(mlx_strerror(mlx_errno));
		free_rdata(render_data);
		return (NULL);
	}
	render_data->set_f = set_f;
	return (render_data);
}

t_W_R_D	*init_w_r_d(mlx_t *window, t_RData *render_data)
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
	t_RData	*render_data;
	t_W_R_D	*w_r_d;

	if (func_id == MANDEL || func_id == B_SHIP)
		render_data = init_mandelbrot(window, argc, argv, func_id);
	else if (func_id == JUL)
		render_data = init_julia(window, argc, argv);
	else
		render_data = init_debug(window, argc, argv);
	if (render_data == NULL)
		return (NULL);
	render_data->f_code = func_id;
	w_r_d = init_w_r_d(window, render_data);
	if (w_r_d == NULL)
		free_rdata(render_data);
	return (w_r_d);
}
