/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:01:38 by isemin            #+#    #+#             */
/*   Updated: 2024/04/25 19:34:38 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	prepare_image_buffer(t_RData *r_d, uint8_t **temp)
{
	*temp = (uint8_t *)malloc(BPP * r_d->width * r_d->height);
	if (*temp != NULL)
		ft_memmove(*temp, r_d->image->pixels, BPP * r_d->width * r_d->height);
}

void	stretch_image(t_RData *r_d, t_PixBox box, t_DPair scale, uint8_t *temp)
{
	t_Pix		dst;
	t_PixDouble	src;
	int			y_whole;

	dst.y = 0;
	src.y = box.top_y;
	while (dst.y < r_d->height)
	{
		dst.x = 0;
		src.x = box.left_x;
		y_whole = (int)round(src.y);
		while (dst.x < r_d->width)
		{
			ft_memmove(r_d->image->pixels + \
			((int)(dst.y * r_d->width + dst.x) * BPP), temp + ((int)(y_whole * \
			r_d->width + (int)round(src.x)) * BPP), BPP);
			dst.x++;
			src.x += scale.x;
		}
		dst.y++;
		src.y += scale.y;
	}
}

void	perform_downscale(t_RData *r_d, t_PixBox box, t_DPair scale, int **temp)
{
	t_Pix		dst;
	t_PixDouble	src;
	int			y_whole;

	dst.y = box.top_y;
	src.y = 0;
	while (dst.y < box.bottom_y)
	{
		dst.x = box.left_x;
		src.x = 0;
		y_whole = (int)round(src.y);
		while (dst.x < box.right_x)
		{
			r_d->iter_count[dst.y][dst.x] = temp[y_whole][(int)round(src.x)];
			dst.x++;
			src.x += scale.x;
		}
		dst.y++;
		src.y += scale.y;
	}
}
