/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:08:37 by isemin            #+#    #+#             */
/*   Updated: 2024/04/22 19:07:42 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	resize_window(int32_t width, int32_t height, void *param)
{
	t_W_R_D	*wrd;
	t_RData	*r_d;
	double	dots_pp_x;
	double	dots_pp_y;
	t_Pix	pix;

	wrd = (t_W_R_D *)param;
	r_d = wrd->r_data;
	clear_background_render(r_d);
	dots_pp_x = (r_d->bounds->max_r - r_d->bounds->min_r) / (double)r_d->width;
	dots_pp_y = (r_d->bounds->max_i - r_d->bounds->min_i) / (double)r_d->height;
	if (!mlx_resize_image(r_d->image, width, height))
		exit(EXIT_FAILURE);
	pix.x = width;
	pix.y = height;
	r_d->iter_count = iter_data_re_alloc(r_d, pix);
	if (r_d->iter_count == NULL)
		exit(EXIT_FAILURE);
	r_d->bounds->max_r += dots_pp_x * (width - r_d->width);
	r_d->bounds->max_i += dots_pp_y * (height - r_d->height);
	r_d->width = width;
	r_d->height = height;
	r_d->render_required = false;
	draw_set(r_d);
}
