/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delayed_drawer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:34:42 by isemin            #+#    #+#             */
/*   Updated: 2024/04/24 18:23:56 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	init_background_render(t_RData *r_d)
{
	(void)r_d;
	return (BACKGROUND_RENDER_STARTED);
}

int	continue_background_render(t_RData *r_d)
{
	static t_Pix	pix;
	t_PixBox		segment;

	if (r_d == NULL)
	{
		pix.y = 0;
		pix.x = 0;
	}
	else
	{
		segment.top_y = pix.y;
		segment.bottom_y = pix.y + 1;
		segment.left_x = pix.x;
		segment.right_x = r_d->width;
		draw_segment(r_d, &segment);
		pix.y++;
	}
	return (pix.y);
}

void	complete_background_render(t_RData *r_d)
{
	r_d->render_status = BACKGROUND_RENDER_NOT_STARTED;
	r_d->render_required = false;
	clear_background_render(r_d);
}

void	clear_background_render(t_RData *r_d)
{
	r_d->render_status = BACKGROUND_RENDER_NOT_STARTED;
	continue_background_render(NULL);
}
