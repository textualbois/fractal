/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:21:48 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 20:53:07 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	show_inputs(void)
{
	ft_printf("Allowed fractals:\n\n	mandelbrot: p1 - precision\n\n\
	julia: p1 - precision; p2-3 - modifiers\n\n\
	burning ship: p1 - precision\n\n\n\
	controls:\n\
	r - boost red color\n\
	g - boost green color\n\
	b - boost blue color\n\
	a - boost intensity of all colors\n\
	space bar - add static effect\n\
	p - add acid effect\n\
	o - change acid effect parameters\n\
	scroll wheel - zoom\n\
	arrow keys - movement");
}
