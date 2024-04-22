/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_router.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:49:03 by isemin            #+#    #+#             */
/*   Updated: 2024/04/22 12:03:14 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	quick_draw(t_W_R_D	*wrd)
{
	if (mlx_is_key_down(wrd->window, MLX_KEY_DOWN))
	{
		complete_background_render(wrd->r_data);
		move_down_quick(wrd->r_data);
		draw_set(wrd->r_data);
	}
	if (mlx_is_key_down(wrd->window, MLX_KEY_UP))
	{
		complete_background_render(wrd->r_data);
		move_up_quick(wrd->r_data);
		draw_set(wrd->r_data);
	}
	if (mlx_is_key_down(wrd->window, MLX_KEY_LEFT))
	{
		complete_background_render(wrd->r_data);
		move_left_quick(wrd->r_data);
		draw_set(wrd->r_data);
	}
	if (mlx_is_key_down(wrd->window, MLX_KEY_RIGHT))
	{
		complete_background_render(wrd->r_data);
		move_right_quick(wrd->r_data);
		draw_set(wrd->r_data);
	}
}

void	smart_draw(t_W_R_D	*wrd)
{
	if (mlx_is_key_down(wrd->window, MLX_KEY_DOWN))
	{
		clear_background_render(wrd->r_data);
		move_down(wrd->r_data);
	}
	if (mlx_is_key_down(wrd->window, MLX_KEY_UP))
	{
		clear_background_render(wrd->r_data);
		move_up(wrd->r_data);
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
