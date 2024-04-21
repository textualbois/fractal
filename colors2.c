/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:34:36 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 17:34:37 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static uint8_t	shift_color(uint8_t color, double modifier)
{
	if (color * modifier >= 255)
		return (0);
	else
		return (color + 1);
}

static void	set_rgba(t_color *rgba, int code)
{
	if (code == -1)
	{
		rgba->r = (uint8_t)255;
		rgba->g = (uint8_t)150;
		rgba->b = (uint8_t)100;
		rgba->a = (uint8_t)255;
	}
	if (code == 0)
		rgba->r = shift_color(rgba->r, 1);
	if (code == 1)
		rgba->g = shift_color(rgba->g, 1);
	if (code == 2)
		rgba->b = shift_color(rgba->b, 1);
	if (code == 3)
		rgba->a = shift_color(rgba->a, 1);
}

uint32_t	ft_color_from_seed(int iter, int max_iter)
{
	static t_color		rgba;
	double				modifier;

	modifier = log(iter + 1) / log(max_iter + iter);
	if (max_iter == -1)
		set_rgba(&rgba, iter);
	else
	{
		if (iter == max_iter)
			return (DEFAULT_COLOR);
		else
		{
			return ((rgba.r << 24) | \
			(rgba.g << 16) | \
			(rgba.b << 8) | \
			(int)(rgba.a * modifier));
		}
	}
	return (iter);
}
