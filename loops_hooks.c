/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:46:50 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 18:53:05 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	ft_exit_button(void *param)
{
	t_W_R_D	*wrd;

	wrd = (t_W_R_D *)param;
	if (mlx_is_key_down(wrd->window, MLX_KEY_ESCAPE))
		mlx_close_window(wrd->window);
}

void	ft_image_shift(void *param)
{
	t_W_R_D	*wrd;

	wrd = (t_W_R_D *)param;
	if (mlx_is_key_down(wrd->window, MLX_KEY_DOWN))
	{
		clear_background_render(wrd->r_data);
		move_down(wrd->r_data);
	}
	if (mlx_is_key_down(wrd->window, MLX_KEY_UP))
	{
		clear_background_render(wrd->r_data);
		move_up(wrd->r_data); ////// change this later
		draw_set(wrd->r_data); ////// change this later
	}
	if (mlx_is_key_down(wrd->window, MLX_KEY_LEFT))
	{
		clear_background_render(wrd->r_data);
		move_left(wrd->r_data);
	}
	if (mlx_is_key_down(wrd->window, MLX_KEY_RIGHT))
	{
		clear_background_render(wrd->r_data);
		move_right(wrd->r_data);
	}
}

void	background_render(void *param)
{
	t_W_R_D	*wrd;
	int		row_completed;

	wrd = (t_W_R_D *)param;
	(void)wrd;
	if (wrd->r_data->block_render == true)
	{
		printf("blocked a render\n");
		clear_background_render(wrd->r_data);
		wrd->r_data->render_status = BACKGROUND_RENDER_NOT_STARTED;
	}
	else if (wrd->r_data->render_required == true)
	{
		if (wrd->r_data->render_status == BACKGROUND_RENDER_NOT_STARTED)
			wrd->r_data->render_status = init_background_render(wrd->r_data);
		if (wrd->r_data->render_status == BACKGROUND_RENDER_STARTED)
		{
			row_completed = continue_background_render(wrd->r_data);
			if (row_completed == wrd->r_data->height)
				complete_render(wrd->r_data);
		}
	}
}

void	init_loops_n_hooks(t_W_R_D *wrd)
{
	mlx_loop_hook(wrd->window, ft_exit_button, wrd);
	mlx_loop_hook(wrd->window, ft_image_shift, wrd);
	mlx_scroll_hook(wrd->window, ft_zoom, wrd);
	mlx_resize_hook(wrd->window, resize_window, wrd);
	mlx_loop_hook(wrd->window, max_c_wrapper, wrd);
	mlx_loop_hook(wrd->window, color_psy_hook, wrd);
	mlx_loop_hook(wrd->window, color_static_hook, wrd);
	mlx_loop_hook(wrd->window, color_shift_hook, wrd);
	mlx_loop_hook(wrd->window, background_render, wrd);
	mlx_loop(wrd->window);
	mlx_terminate(wrd->window);
}
