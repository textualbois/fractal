/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:30:09 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 17:31:11 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static void	shift_color(uint8_t *color)
{
	if (*color == 255)
		*color = 0;
	else
		*color = *color + 1;
}

void	ft_apply_color(t_RData *r_d, int offset)
{
	mlx_image_t	*img;
	t_Pix		pix;
	uint8_t		*p;

	img = r_d->image;
	pix.x = 0;
	while (pix.x < r_d->Width)
	{
		pix.y = 0;
		while (pix.y < r_d->Height)
		{
			p = img->pixels + ((pix.y * r_d->Width + pix.x) * BPP);
			if (r_d->iter_count[pix.y][pix.x] != r_d->max_iter)
				shift_color(&(p[offset]));
			pix.y++;
		}
		pix.x++;
	}
}

void	shift_colors(t_RData *r_d, int code)
{
	clear_background_render(r_d);
	ft_color_from_seed(code, -1);
	draw_from_iter_counts(r_d);
}

void	color_shift_hook(void *param)
{
	t_W_R_D	*wrd;

	wrd = (t_W_R_D *)param;
	if (mlx_is_key_down(wrd->window, MLX_KEY_R))
		shift_colors(wrd->r_data, 0);
	else if (mlx_is_key_down(wrd->window, MLX_KEY_G))
		shift_colors(wrd->r_data, 1);
	else if (mlx_is_key_down(wrd->window, MLX_KEY_B))
		shift_colors(wrd->r_data, 2);
	else if (mlx_is_key_down(wrd->window, MLX_KEY_A))
		shift_colors(wrd->r_data, 3);
}
