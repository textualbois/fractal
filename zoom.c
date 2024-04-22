/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:23:34 by isemin            #+#    #+#             */
/*   Updated: 2024/04/22 18:39:25 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	zoom_in(t_RData *r_d, t_Pix cursor)
{
	t_PixBox	rendered_pixels;
	double		dots_pp_x;
	double		dots_pp_y;

	dots_pp_x = (r_d->bounds->max_r - r_d->bounds->min_r) / r_d->width;
	dots_pp_y = (r_d->bounds->max_i - r_d->bounds->min_i) / r_d->height;
	rendered_pixels = get_inner_box_from_pixels(r_d, cursor);
	r_d->zoom /= (0.95 * 0.95);
	r_d->bounds->min_r += rendered_pixels.left_x * dots_pp_x;
	r_d->bounds->max_r -= ((double) \
	(r_d->width - rendered_pixels.right_x)) * dots_pp_x;
	r_d->bounds->min_i += rendered_pixels.top_y * dots_pp_y;
	r_d->bounds->max_i -= ((double) \
	(r_d->height - rendered_pixels.bottom_y)) * dots_pp_y;
	stretch(r_d, rendered_pixels, ((double)(rendered_pixels.right_x - \
	rendered_pixels.left_x) / (double)r_d->width), \
	((double)(rendered_pixels.bottom_y - rendered_pixels.top_y) \
	/ (double)r_d->height));
}

void	stretch(t_RData *r_d, t_PixBox box, double scale_x, double scale_y)
{
	uint8_t		*pixels_copy;
	t_Pix		dst;
	t_PixDouble	src;
	int			y_whole;

	pixels_copy = (uint8_t *)malloc(BPP * r_d->width * r_d->height);
	if (pixels_copy != NULL)
	{
		ft_memmove(pixels_copy, r_d->image->pixels, BPP * r_d->width * r_d->height);
		dst.y = 0;
		src.y = box.top_y;
		while (dst.y < r_d->height)
		{
			dst.x = 0;
			src.x = box.left_x;
			y_whole = (int)round(src.y);
			while (dst.x < r_d->width)
			{
				ft_memmove(r_d->image->pixels + ((int)(dst.y * r_d->width + dst.x) * BPP), \
				pixels_copy + ((int)(y_whole * r_d->width + (int)round(src.x)) * BPP), BPP);
				dst.x++;
				src.x += scale_x;
			}
			dst.y++;
			src.y += scale_y;
		}
		free(pixels_copy);
	}
	else
		draw_set(r_d);
}

void	zoom_out(t_RData *r_d, t_Pix cursor)
{
	t_PixBox	rendered_pixels;
	double		dots_pp_x;
	double		dots_pp_y;

	rendered_pixels = get_inner_box_from_pixels(r_d, cursor);
	dots_pp_x = (r_d->bounds->max_r - r_d->bounds->min_r) / \
	(rendered_pixels.right_x - rendered_pixels.left_x);
	dots_pp_y = (r_d->bounds->max_i - r_d->bounds->min_i) / \
	(rendered_pixels.bottom_y - rendered_pixels.top_y);
	r_d->zoom *= (0.95 * 0.95);

	r_d->bounds->min_r -= rendered_pixels.left_x * dots_pp_x;
	r_d->bounds->max_r += ((double) \
	(r_d->width - rendered_pixels.right_x)) * dots_pp_x;
	r_d->bounds->min_i -= rendered_pixels.top_y * dots_pp_y;
	r_d->bounds->max_i += ((double) \
	(r_d->height - rendered_pixels.bottom_y)) * dots_pp_y;
	printf("about to downscale\n");
	down_scale(r_d, rendered_pixels, ((double)r_d->width) / \
	(double)(rendered_pixels.right_x - rendered_pixels.left_x), \
	((double)r_d->height) / \
	(double)(rendered_pixels.bottom_y - rendered_pixels.top_y));
	outer_render(r_d, &rendered_pixels);
}

void	down_scale(t_RData *r_d, t_PixBox box, double scale_x, double scale_y)
{
	int			**pixels_copy;
	t_Pix		dst;
	t_PixDouble	src;
	int			y_whole;


	printf("window:\nHeight(y) - %i, Width(x) - %i\n", r_d->height, r_d->width);
	printf("repositioning image to:\n%i - %i, %i - %i", box.top_y, box.bottom_y, box.left_x, box.right_x);
	//when the window is larger than default it draws artefacts
	//when the window is smaller than default it aborts
	dst.y = r_d->height;
	dst.x = r_d->width;
	pixels_copy = iter_data_copy(r_d); //takes current image meta and makes a copy
	if (pixels_copy != NULL)
	{

		printf("pixels_copy_malloc ok\n");
		dst.y = box.top_y;
		src.y = 0;
		while (dst.y < box.bottom_y)
		{
			dst.x = box.left_x;
			src.x = 0;
			y_whole = (int)round(src.y);
			while (dst.x < box.right_x)
			{
				r_d->iter_count[dst.y][dst.x] = \
				pixels_copy[y_whole][(int)round(src.x)];
				dst.x++;
				src.x += scale_x;
			}
			dst.y++;
			src.y += scale_y;
		}
		clear_iter_data(pixels_copy, r_d->height - 1);
	}
	else
		draw_set(r_d);
}

void	ft_zoom(double x_delta, double y_delta, void *param)
{
	t_W_R_D	*wrd;
	t_Pix	cursor;

	printf("zoom triggered\n");
	wrd = (t_W_R_D *)param;
	mlx_get_mouse_pos(wrd->window, &cursor.x, &cursor.y);
	(void)x_delta;
	if (y_delta > 0)
	{
		clear_background_render(wrd->r_data);
		wrd->r_data->render_required = true;
		zoom_in(wrd->r_data, cursor);
	}
	else if (y_delta < 0)
	{
		clear_background_render(wrd->r_data);
		wrd->r_data->render_required = true;
		zoom_out(wrd->r_data, cursor);
	}
}
