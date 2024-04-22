/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:08:37 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 19:33:06 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	resize_window(int32_t width, int32_t height, void *param)
{
	static t_Pix32	delta;
	t_W_R_D			*wrd;
	t_RData			*r_d;
	double			dots_pp_x;
	double			dots_pp_y;
	t_Pix			pix;

	//printf("new height is %i\nnew width id %i\n", (int)height, (int)width);
	wrd = (t_W_R_D *)param;
	// if (mlx_is_mouse_down(wrd->window, MLX_MOUSE_BUTTON_LEFT))
	// {
		// printf("mouse button is down\n");
		delta.x = width;
		delta.y = height;
	// }

		// printf("mouse button is not down\n");
		r_d = wrd->r_data;
		clear_background_render(r_d);
		dots_pp_x = (r_d->bounds->max_r - r_d->bounds->min_r) / (double)r_d->width;
		dots_pp_y = (r_d->bounds->max_i - r_d->bounds->min_i) / (double)r_d->height;
		if (!mlx_resize_image(r_d->image, delta.x, delta.y))
			exit(EXIT_FAILURE);
		pix.x = delta.x;
		pix.y = delta.y;
		r_d->iter_count = iter_data_re_alloc(r_d, pix);
		if (r_d->iter_count == NULL)
			exit(EXIT_FAILURE);
		r_d->bounds->max_r += dots_pp_x * (delta.x - r_d->width);
		r_d->bounds->max_i += dots_pp_y * (delta.y - r_d->height);
		r_d->width = delta.x;
		r_d->height = delta.y;
		r_d->render_required = true;
	// }
}
