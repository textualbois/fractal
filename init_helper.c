/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:41:21 by isemin            #+#    #+#             */
/*   Updated: 2024/04/24 18:50:05 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

t_RData	*init_mandelbrot(mlx_t *window, int argc, char **argv, int f_id)
{
	t_bounds	*bounds;
	t_RData		*render_data;
	int			max_iter;

	bounds = initbounds(-2.0, 2.0, -2.0, 2.0);
	if (!bounds)
		return (NULL);
	if (argc == 3)
		max_iter = ft_atoi(argv[2]);
	else
		max_iter = 300;
	if (f_id == MANDEL)
		render_data = init_rdata(bounds, window, &mandelbrot, max_iter);
	else
		render_data = init_rdata(bounds, window, &burning_ship, max_iter);
	if (!render_data)
	{
		free(bounds);
		return (NULL);
	}
	return (render_data);
}

static void	init_j_p_s(t_bounds **bounds, t_DPair **c, int argc, char **argv)
{
	*bounds = initbounds(-2.0, 2.0, -2.0, 2.0);
	if (*bounds != NULL)
	{
		*c = (t_DPair *)malloc(sizeof(t_DPair));
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

t_RData	*init_julia(mlx_t *window, int argc, char **argv)
{
	t_bounds		*bounds;
	t_RData			*render_data;
	t_DPair			*c;
	int				max_iter;

	bounds = NULL;
	c = NULL;
	if (argc >= 3)
		max_iter = ft_atoi(argv[2]);
	else
		max_iter = 300;
	init_j_p_s(&bounds, &c, argc, argv);
	if (bounds == NULL)
		return (NULL);
	render_data = init_rdata(bounds, window, &julia, max_iter);
	if (render_data == NULL)
	{
		free(bounds);
		free(c);
		return (NULL);
	}
	render_data->j_params = c;
	return (render_data);
}

t_RData	*init_debug(mlx_t *window, int argc, char **argv)
{
	t_bounds		*bounds;
	t_RData			*render_data;
	int				max_iter;

	bounds = initbounds(-2.0, 2.0, -2.0, 2.0);
	if (!bounds)
		return (NULL);
	if (argc == 3)
	{
		max_iter = ft_atoi(argv[2]);
	}
	else
		max_iter = 300;
	render_data = init_rdata(bounds, window, &mandelbrot, max_iter);
	if (!render_data)
	{
		free(bounds);
		return (NULL);
	}
	return (render_data);
}
