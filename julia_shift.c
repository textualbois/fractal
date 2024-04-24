/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:58:21 by isemin            #+#    #+#             */
/*   Updated: 2024/04/24 17:56:15 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static double	x_par(t_RData *r_d, double x_pos)
{
	if (r_d->width == 0)
		return (0.0);
	return (4.0 * (x_pos / r_d->width) - 2.0);
}

static double	y_par(t_RData *r_d, double y_pos)
{
	if (r_d->height == 0)
		return (0.0);
	return (-4.0 * (y_pos / r_d->width) + 2.0);
}

void	julia_shift(double x_pos, double y_pos, void *param)
{
	t_W_R_D	*wrd;

	wrd = (t_W_R_D *)param;
	wrd->r_data->j_params->x = x_par(wrd->r_data, x_pos);
	wrd->r_data->j_params->y = y_par(wrd->r_data, y_pos);

	draw_set(wrd->r_data);
}