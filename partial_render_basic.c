/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partial_render_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:49:06 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 18:53:05 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static void	mlx_store_pixel(uint8_t *pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

void	outer_render(t_RData *r_d, t_PixBox *rendered_pix)
{
	double	real;
	double	imag;
	t_Pix	pix;

	pix.x = 0;
	while (pix.x < r_d->width)
	{
		pix.y = 0;
		while (pix.y < r_d->height)
		{
			if (pix.x <= rendered_pix->left_x || \
				pix.x >= rendered_pix->right_x || \
				pix.y <= rendered_pix->top_y || pix.y >= rendered_pix->bottom_y)
			{
				pixel_to_complex(pix, r_d, &real, &imag);
				r_d->iter_count[pix.y][pix.x] = r_d->set_f(real, imag, \
					r_d->max_iter, r_d->j_params);
			}
			place_color(r_d, pix);
			pix.y++;
		}
		pix.x++;
	}
}

void	buffer_segment(t_RData *r_d, t_PixBox *pixel_bounds)
{
	int		color_seed;
	int		color;
	t_DPair	point;
	t_Pix	pix;

	pix.x = pixel_bounds->left_x;
	while (pix.x < pixel_bounds->right_x)
	{
		pix.y = pixel_bounds->top_y;
		while (pix.y < pixel_bounds->bottom_y)
		{
			pixel_to_complex(pix, r_d, &point.x, &point.y);
			color_seed = r_d->set_f(point.x, point.y, \
			r_d->max_iter, r_d->j_params);
			color = ft_color_from_seed(color_seed, r_d->max_iter);
			r_d->buffer_pointer = r_d->pixel_buffer + \
			((pix.y * r_d->width + pix.x) * BPP);
			mlx_store_pixel(r_d->buffer_pointer, color);
			pix.y++;
		}
		pix.x++;
	}
}

void	draw_segment(t_RData *r_d, t_PixBox *pixel_bounds)
{
	double	real;
	double	imag;
	t_Pix	pix;

	pix.x = pixel_bounds->left_x;
	while (pix.x < pixel_bounds->right_x)
	{
		pix.y = pixel_bounds->top_y;
		while (pix.y < pixel_bounds->bottom_y)
		{
			pixel_to_complex(pix, r_d, &real, &imag);
			r_d->iter_count[pix.y][pix.x] = r_d->set_f(real, imag, \
			r_d->max_iter, r_d->j_params);
			place_color(r_d, pix);
			pix.y++;
		}
		pix.x++;
	}
}
