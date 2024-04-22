/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:46:46 by isemin            #+#    #+#             */
/*   Updated: 2024/04/22 11:59:27 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	move_right_quick(t_RData *r_d)
{
	double		bounds_l;
	int			shift_offset;

	shift_offset = 10;
	if (r_d->width < 10)
		shift_offset = 1;
	bounds_l = r_d->bounds->max_r - r_d->bounds->min_r;
	r_d->bounds->min_r += bounds_l * ((double)shift_offset / r_d->width);
	r_d->bounds->max_r += bounds_l * ((double)shift_offset / r_d->width);
}

void	move_left_quick(t_RData *r_d)
{
	double		bounds_l;
	int			shift_offset;

	shift_offset = 10;
	if (r_d->width < 10)
		shift_offset = 1;
	bounds_l = r_d->bounds->max_r - r_d->bounds->min_r;
	r_d->bounds->min_r -= bounds_l * ((double)shift_offset / r_d->width);
	r_d->bounds->max_r -= bounds_l * ((double)shift_offset / r_d->width);
}

void	move_down_quick(t_RData *r_d)
{
	double		bounds_l;
	int			shift_offset;

	shift_offset = 10;
	if (r_d->width < 10)
		shift_offset = 1;
	bounds_l = r_d->bounds->max_r - r_d->bounds->min_r;
	r_d->bounds->min_i += bounds_l * ((double)shift_offset / r_d->width);
	r_d->bounds->max_i += bounds_l * ((double)shift_offset / r_d->width);
}

void	move_up_quick(t_RData *r_d)
{
	double	bounds_l;
	int		shift_offset;

	shift_offset = 10;
	if (r_d->width < 10)
		shift_offset = 1;
	bounds_l = r_d->bounds->max_r - r_d->bounds->min_r;
	r_d->bounds->min_i -= bounds_l * ((double)shift_offset / r_d->width);
	r_d->bounds->max_i -= bounds_l * ((double)shift_offset / r_d->width);
}
