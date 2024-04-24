/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:18:07 by isemin            #+#    #+#             */
/*   Updated: 2024/04/24 17:32:07 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	mandelbrot(double real, double imag, int max_iter, void *param)
{
	int		iter;
	double	r;
	double	i;
	double	r2;
	double	i2;

	(void)param;
	r = real;
	i = imag;
	iter = -1;
	while (iter++ < max_iter)
	{
		r2 = r * r;
		i2 = i * i;
		if (r2 + i2 > 4.0)
			return (iter);
		i = 2 * r * i + imag;
		r = r2 - i2 + real;
	}
	return (max_iter);
}

int	julia(double real, double imag, int max_iter, void *param)
{
	int			iter;
	double		r2;
	double		i2;
	t_DPair		*c;

	c = (t_DPair *)param;
	iter = -1;
	while (iter++ < max_iter)
	{
		r2 = real * real;
		i2 = imag * imag;
		if (r2 + i2 > 4.0)
			return (iter);
		imag = 2 * real * imag + c->y;
		real = r2 - i2 + c->x;
	}
	return (max_iter);
}

int	burning_ship(double real, double imag, int max_iter, void *param)
{
	int		iter;
	double	r;
	double	i;
	double	r2;
	double	i2;

	(void)param;
	r = real;
	i = imag;
	iter = -1;
	while (iter++ < max_iter)
	{
		r2 = r * r;
		i2 = i * i;
		if (r2 + i2 > 4.0)
			return (iter);
		r = fabs(r);
		i = fabs(i);
		i = 2 * r * i + imag;
		r = r * r - i * i + real;
	}
	return (max_iter);
}

int	debug_grid(double real, double imag, int max_iter, void *param)
{
	int	real_x3;
	int	imag_x3;

	real_x3 = (int)(real * 100);
	imag_x3 = (int)(imag * 100);
	(void)param;
	if ((int)real_x3 % 5 == 0 || (int)imag_x3 % 5 == 0)
		return (max_iter);
	else
		return (255);
}
