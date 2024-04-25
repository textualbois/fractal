/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:47:32 by isemin            #+#    #+#             */
/*   Updated: 2024/04/25 19:39:06 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	free_fbounds(t_bounds *bounds)
{
	free(bounds);
}

void	free_rdata(t_RData *render_data)
{
	free(render_data->bounds);
	clear_background_render(render_data);
	if (render_data->f_code == JUL)
		free(render_data->j_params);
	if (render_data->iter_count != NULL)
		clear_iter_data(render_data->iter_count, render_data->height - 1);
	free(render_data);
}

void	free_w_r_d(t_W_R_D *w_r_d)
{
	free_rdata(w_r_d->r_data);
	free(w_r_d);
}
