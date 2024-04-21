/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:18:43 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 18:53:05 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

//shift left in real plain
void	shift_pixels_x_l(t_RData *r_d, int shift_offset)
{
	int	y;

	y = 0;
	while (y < r_d->height)
	{
		ft_memmove(r_d->iter_count[y],\
			r_d->iter_count[y] + shift_offset,\
			(r_d->width - shift_offset) * sizeof(int));
		y++;
	}
}

//shift right in real plain
void	shift_pixels_x_r(t_RData *r_d, int shift_offset)
{
	int	y;

	y = 0;
	while (y < r_d->height)
	{
		ft_memmove(r_d->iter_count[y] + shift_offset, \
			r_d->iter_count[y],\
			(r_d->width - shift_offset) * sizeof(int));
		y++;
	}
}

//shift up in imaginary plain
void	shift_pixels_y_u(t_RData *r_d, int shift_offset)
{
	int	y;

	y = 0;
	while (y + shift_offset < r_d->height)
	{
		ft_memmove(r_d->iter_count[y],\
			r_d->iter_count[y + shift_offset], \
			r_d->width * sizeof(int));
		y++;
	}
}

//shift down in imaginary plain
void	shift_pixels_y_d(t_RData *r_d, int shift_offset)
{
	int	y;

	y = r_d->height - 1;
	while (y - shift_offset >= 0)
	{
		ft_memmove(r_d->iter_count[y],\
			r_d->iter_count[y - shift_offset], \
			r_d->width * sizeof(int));
		y--;
	}
}
