/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:37:51 by isemin            #+#    #+#             */
/*   Updated: 2024/04/25 20:20:03 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	pixel_to_complex(t_Pix pixel, t_RData *r_d, double *real, double *imag)
{
	t_bounds	*bounds;

	bounds = r_d->bounds;
	*real = bounds->min_r + (pixel.x / (double)r_d->width) \
	* (bounds->max_r - bounds->min_r);
	*imag = bounds->min_i + (pixel.y / (double)r_d->height) \
	* (bounds->max_i - bounds->min_i);
}

void	draw_from_iter_counts(t_RData *r_d)
{
	t_Pix	pixel;

	pixel.x = 0;
	while (pixel.x < r_d->width)
	{
		pixel.y = 0;
		while (pixel.y < r_d->height)
		{
			place_color(r_d, pixel);
			pixel.y++;
		}
		pixel.x++;
	}
	complete_background_render(r_d);
}

void	draw_set(t_RData *r_d)
{
	double	real;
	double	imag;
	t_Pix	pixel;

	pixel.x = 0;
	while (pixel.x < r_d->width)
	{
		pixel.y = 0;
		while (pixel.y < r_d->height)
		{
			pixel_to_complex(pixel, r_d, &real, &imag);
			r_d->iter_count[pixel.y][pixel.x] = r_d->set_f(real, imag, \
			r_d->max_iter, r_d->j_params);
			place_color(r_d, pixel);
			pixel.y++;
		}
		pixel.x++;
	}
	complete_background_render(r_d);
}

void	place_color(t_RData *r_d, t_Pix pos)
{
	int	color;
	int	color_seed;

	color_seed = r_d->iter_count[pos.y][pos.x];
	color = ft_color_from_seed(color_seed, r_d->max_iter);
	mlx_put_pixel(r_d->image, pos.x, pos.y, color);
}
