/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psy_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:00:39 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 18:07:38 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	max_c_wrapper(void *param)
{
	t_W_R_D	*wrd;

	wrd = (t_W_R_D *)param;
	if (mlx_is_key_down(wrd->window, MLX_KEY_O))
		ft_max_c(DECREMENT_MAX_C);
}

int	ft_max_c(int signal)
{
	static int	max_c;

	if (signal == DECREMENT_MAX_C)
		max_c--;
	if (max_c <= 0)
		max_c = 56;
	return (max_c);
}

void	ft_psy_flow(t_RData *r_d, int c_code, int max_c)
{
	int			grouping_factor;
	t_Pix		pix;
	uint32_t	color;
	uint8_t		*p;
	t_color		rgba;

	pix.x = 0;
	while (pix.x < r_d->Width)
	{
		pix.y = 0;
		while (pix.y < r_d->Height)
		{
			p = r_d->image->pixels + ((pix.y * r_d->Width + pix.x) * BPP);
			grouping_factor = (r_d->iter_count[pix.y][pix.x] + c_code) % max_c;
			rgba.r = (int)(127.5 * (sin(grouping_factor * 0.2) + 1));
			rgba.g = (int)(127.5 * (cos(grouping_factor * 0.2) + 1));
			rgba.b = (int)(127.5 * (sin(grouping_factor * 0.3) + 1));
			rgba.a = 0xFF;
			color = ft_pixel(r, g, b, a);
			ft_memmove(p, &color, BPP * 3 / 4);
			pix.y++;
		}
		pix.x++;
	}
}

void	color_psy_hook(void *param)
{
	static int	activity_status;
	int			max_c;
	t_W_R_D		*wrd;

	wrd = (t_W_R_D *)param;
	if (mlx_is_key_down(wrd->window, MLX_KEY_P))
	{
		max_c = ft_max_c(GIVE_MAX_C);
		clear_background_render(wrd->r_data);
		wrd->r_data->render_required = true;
		activity_status++;
		if (activity_status >= max_c)
			activity_status = 1;
		ft_psy_flow(wrd->r_data, activity_status, max_c);
	}
	else if (activity_status > 0)
	{
		draw_from_iter_counts(wrd->r_data);
		activity_status = 0;
	}
}
