/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:20:39 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 18:23:28 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

t_PixBox	get_inner_box_from_bounds(t_RData *r_d)
{
	t_PixBox	inner_box;
	double		abs_x;
	double		abs_y;

	abs_x = r_d->bounds->max_r - r_d->bounds->min_r;
	abs_y = r_d->bounds->max_i - r_d->bounds->min_i;
	inner_box.top_y = (int)floor(r_d->Height * \
	(r_d->bounds->max_i - r_d->bounds_temp.max_i) / abs_y);
	inner_box.bottom_y = (int)floor(r_d->Height * \
	(r_d->bounds->max_i - r_d->bounds_temp.min_i) / abs_y);
	inner_box.left_x = (int)floor(r_d->Width * \
	(r_d->bounds->max_r - r_d->bounds_temp.max_r) / abs_x);
	inner_box.right_x = (int)floor(r_d->Width * \
	(r_d->bounds->max_r - r_d->bounds_temp.min_r) / abs_x);
	return (inner_box);
}

t_PixBox	get_inner_box_from_pixels(t_RData *r_d, t_Pix cursor)
{
	t_PixBox	inner_box;
	int			x_shift;
	int			y_shift;

	inner_box.top_y = 0;
	inner_box.bottom_y = r_d->Height * 0.95;
	inner_box.left_x = 0;
	inner_box.right_x = r_d->Width * 0.95;
	y_shift = (cursor.y * (r_d->Height - inner_box.bottom_y) / r_d->Height);
	x_shift = (cursor.x * (r_d->Width - inner_box.right_x) / r_d->Width);
	inner_box.top_y += y_shift;
	inner_box.bottom_y += y_shift;
	inner_box.left_x += x_shift;
	inner_box.right_x += x_shift;
	return (inner_box);
}

t_PixBox	get_outer_box_from_pixels(t_RData *r_d, t_Pix cursor)
{
	t_PixBox	outer_box;
	int			x_shift;
	int			y_shift;

	outer_box.top_y = 0;
	outer_box.bottom_y = r_d->Height * 1.05;
	outer_box.left_x = 0;
	outer_box.right_x = r_d->Width * 1.05;
	x_shift = (cursor.x * (-r_d->Height + outer_box.right_x) / r_d->Height);
	y_shift = (cursor.y * (-r_d->Width + outer_box.bottom_y) / r_d->Width);
	outer_box.top_y += y_shift;
	outer_box.bottom_y += y_shift;
	outer_box.left_x += x_shift;
	outer_box.right_x += x_shift;
	return (outer_box);
}