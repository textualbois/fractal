/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:23:34 by isemin            #+#    #+#             */
/*   Updated: 2024/04/24 19:32:03 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	zoom_in(t_RData *r_d, t_Pix cursor)
{
	t_PixBox	rendered_pixels;
	t_DPair		dotspp;
	t_DPair		scale;

	dotspp.x = (r_d->bounds->max_r - r_d->bounds->min_r) / r_d->width;
	dotspp.y = (r_d->bounds->max_i - r_d->bounds->min_i) / r_d->height;
	rendered_pixels = get_inner_box_from_pixels(r_d, cursor);
	r_d->zoom /= (0.95 * 0.95);
	r_d->bounds->min_r += rendered_pixels.left_x * dotspp.x;
	r_d->bounds->max_r -= ((double) \
	(r_d->width - rendered_pixels.right_x)) * dotspp.x;
	r_d->bounds->min_i += rendered_pixels.top_y * dotspp.y;
	r_d->bounds->max_i -= ((double) \
	(r_d->height - rendered_pixels.bottom_y)) * dotspp.y;
	scale.x = ((double)(rendered_pixels.right_x - rendered_pixels.left_x) \
	/ (double)r_d->width);
	scale.y = ((double)(rendered_pixels.bottom_y - rendered_pixels.top_y) \
	/ (double)r_d->height);
	stretch(r_d, rendered_pixels, scale);
}

void	stretch(t_RData *r_d, t_PixBox box, t_DPair scale)
{
	uint8_t		*temp;

	temp = NULL;
	prepare_image_buffer(r_d, &temp);
	if (temp == NULL)
		draw_set(r_d);
	else
	{
		stretch_image(r_d, box, scale, temp);
		free(temp);
	}
}

void	zoom_out(t_RData *r_d, t_Pix cursor)
{
	t_PixBox	rendered_pixels;
	t_DPair		dotspp;
	t_DPair		scale;

	rendered_pixels = get_inner_box_from_pixels(r_d, cursor);
	dotspp.x = (r_d->bounds->max_r - r_d->bounds->min_r) / \
	(rendered_pixels.right_x - rendered_pixels.left_x);
	dotspp.y = (r_d->bounds->max_i - r_d->bounds->min_i) / \
	(rendered_pixels.bottom_y - rendered_pixels.top_y);
	r_d->zoom *= (0.95 * 0.95);
	r_d->bounds->min_r -= rendered_pixels.left_x * dotspp.x;
	r_d->bounds->max_r += ((double) \
	(r_d->width - rendered_pixels.right_x)) * dotspp.x;
	r_d->bounds->min_i -= rendered_pixels.top_y * dotspp.y;
	r_d->bounds->max_i += ((double) \
	(r_d->height - rendered_pixels.bottom_y)) * dotspp.y;
	scale.x = ((double)r_d->width) / \
	(double)(rendered_pixels.right_x - rendered_pixels.left_x);
	scale.y = ((double)r_d->height) / \
	(double)(rendered_pixels.bottom_y - rendered_pixels.top_y);
	down_scale(r_d, rendered_pixels, scale);
	outer_render(r_d, &rendered_pixels);
}

void	down_scale(t_RData *r_d, t_PixBox box, t_DPair scale)
{
	int	**temp;

	temp = iter_data_copy(r_d);
	if (temp == NULL)
		draw_set(r_d);
	else
	{
		perform_downscale(r_d, box, scale, temp);
		clear_iter_data(temp, r_d->height - 1)
	}

}

void	ft_zoom(double x_delta, double y_delta, void *param)
{
	t_W_R_D	*wrd;
	t_Pix	cursor;

	wrd = (t_W_R_D *)param;
	mlx_get_mouse_pos(wrd->window, &cursor.x, &cursor.y);
	(void)x_delta;
	if (y_delta > 0)
	{
		clear_background_render(wrd->r_data);
		wrd->r_data->render_required = true;
		zoom_in(wrd->r_data, cursor);
	}
	else if (y_delta < 0)
	{
		clear_background_render(wrd->r_data);
		wrd->r_data->render_required = true;
		zoom_out(wrd->r_data, cursor);
	}
}
