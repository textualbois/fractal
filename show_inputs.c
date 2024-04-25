/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:21:48 by isemin            #+#    #+#             */
/*   Updated: 2024/04/24 20:17:58 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	show_inputs(void)
{
	ft_printf("Allowed fractals:\n\n\
	mandelbrot: <max_iterations>\n\n\
	julia: <max_iterations> <modifier_1 modifier_2>\n\n\
	burning ship: <max_iterations>\n\n\n\
	controls:\n\
	r - boost red color\n\
	g - boost green color\n\
	b - boost blue color\n\
	a - boost opacity\n\
	space bar - add static effect\n\
	p - add acid effect\n\
	o - change acid effect parameters\n\
	scroll wheel - zoom\n\
	arrow keys - movement");
}
