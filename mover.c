/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:46:46 by isemin            #+#    #+#             */
/*   Updated: 2024/04/22 10:01:31 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	move_right(t_RData *r_d)
{
	double		bounds_l;
	//double		r_delta;
	int			shift_offset;
	t_PixBox	rendered_pixels;

	//r_delta = (r_d->bounds->max_r - r_d->bounds->min_r) * 0.02;
	shift_offset = 10;
	if (r_d->width < 10)
		shift_offset = 1;
	bounds_l = r_d->bounds->max_r - r_d->bounds->min_r;
	r_d->bounds->min_r += bounds_l * ((double)shift_offset / r_d->width);
	r_d->bounds->max_r += bounds_l * ((double)shift_offset / r_d->width);
	shift_pixels_x_l(r_d, shift_offset);
	rendered_pixels.left_x = 0;
	rendered_pixels.right_x = r_d->width - 1 - shift_offset;
	rendered_pixels.top_y = 0;
	rendered_pixels.bottom_y = r_d->height - 1;
	outer_render(r_d, &rendered_pixels);
}

void	move_left(t_RData *r_d)
{
	double		bounds_l;
//	double		r_delta;
	int			shift_offset;
	t_PixBox	rendered_pixels;

	shift_offset = 10;
	if (r_d->width < 10)
		shift_offset = 1;
	bounds_l = r_d->bounds->max_r - r_d->bounds->min_r;
	//r_delta = (r_d->bounds->max_r - r_d->bounds->min_r) * 0.02;
	//shift_offset = r_d->width * 0.02;
	r_d->bounds->min_r -= bounds_l * ((double)shift_offset / r_d->width);
	r_d->bounds->max_r -= bounds_l * ((double)shift_offset / r_d->width);
	shift_pixels_x_r(r_d, shift_offset);
	rendered_pixels.left_x = shift_offset;
	rendered_pixels.right_x = r_d->width - 1;
	rendered_pixels.top_y = 0;
	rendered_pixels.bottom_y = r_d->height - 1;
	outer_render(r_d, &rendered_pixels);
}

void	move_down(t_RData *r_d)
{
	double		bounds_l;
	//double		i_delta;
	int			shift_offset;
	t_PixBox	rendered_pixels;

	shift_offset = 10;
	if (r_d->width < 10)
		shift_offset = 1;
	bounds_l = r_d->bounds->max_r - r_d->bounds->min_r;
	//i_delta = (r_d->bounds->max_i - r_d->bounds->min_i) * 0.02;
	//shift_offset = r_d->height * 0.02;
	r_d->bounds->min_i += bounds_l * ((double)shift_offset / r_d->width);
	r_d->bounds->max_i += bounds_l * ((double)shift_offset / r_d->width);
	shift_pixels_y_u(r_d, shift_offset);
	rendered_pixels.left_x = 0;
	rendered_pixels.right_x = r_d->width - 1;
	rendered_pixels.top_y = 0;
	rendered_pixels.bottom_y = r_d->height - 1 - shift_offset;
	outer_render(r_d, &rendered_pixels);
}

void	move_up(t_RData *r_d)
{
	//double	i_delta;
	double	bounds_l;
	int		shift_offset;

	shift_offset = 10;
	if (r_d->width < 10)
		shift_offset = 1;
	bounds_l = r_d->bounds->max_r - r_d->bounds->min_r;
	//i_delta = (r_d->bounds->max_i - r_d->bounds->min_i) * 0.02;
	r_d->bounds->min_i -= bounds_l * ((double)shift_offset / r_d->width);
	r_d->bounds->max_i -= bounds_l * ((double)shift_offset / r_d->width);
}
