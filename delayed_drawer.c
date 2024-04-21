/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delayed_drawer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:34:42 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 17:37:31 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	init_background_render(t_RData *r_d)
{
	(void)r_d;
    // if (r_d->pixel_buffer != NULL)
    // {
    //     printf("oops, pixel buffer should be null\n");
    //     clear_background_render(r_d);
    // }
    // r_d->pixel_buffer = (uint8_t*)malloc(BPP * r_d->Width * r_d->Height);
    // if (r_d->pixel_buffer != NULL)
    // {
	//    r_d->buffer_pointer = r_d->pixel_buffer;
	return (background_render_started);
    // }
    // return (background_render_not_started);
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
		segment.right_x = r_d->Width;
		draw_segment(r_d, &segment);
		pix.y++;
	}
	return (pix.y);
}

void	complete_render(t_RData *r_d)
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