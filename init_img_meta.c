/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_meta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:40:48 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 18:53:05 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static void	clear_rows(int **iter_data, int row_max)
{
	while (row_max >= 0)
	{
		printf("freeing row %i\n", row_max);
		free(iter_data[row_max]);
		iter_data[row_max] = NULL;
		row_max--;
	}
}

void	clear_iter_data(int **iter_data, int row_max)
{
	if (iter_data)
	{
		clear_rows(iter_data, row_max);
		free(iter_data);
		iter_data = NULL;
	}
}

int	**iter_data(int width, int height)
{
	int	**res;
	int	i;

	res = malloc(height * sizeof(int *));
	if (res)
	{
		i = 0;
		while (i < height)
		{
			res[i] = malloc(width * sizeof(int));
			if (res[i] == NULL)
			{
				clear_iter_data(res, i - 1);
				return (NULL);
			}
			i++;
		}
	}
	return (res);
}

int	**iter_data_re_alloc(t_RData *r_d, t_Pix new_window)
{
	int		**iter_dat;
	t_Pix	i;

	iter_dat = iter_data(new_window.x, new_window.y);
	if (iter_dat == NULL)
		return (NULL);
	i.y = 0;
	while (i.y < new_window.y && i.y < r_d->height)
	{
		i.x = 0;
		while (i.x < new_window.x && i.x < r_d->width)
			i.x++;
		ft_memmove(iter_dat[i.y], r_d->iter_count[i.y], i.x * sizeof(int));
		i.y++;
	}
	clear_iter_data(r_d->iter_count, r_d->height - 1);
	return (iter_dat);
}

int	**iter_data_copy(t_RData *r_d)
{
	int		**iter_dat;
	t_Pix	i;

	iter_dat = iter_data(r_d->width, r_d->height);
	if (iter_dat == NULL)
		return (NULL);
	i.y = 0;
	while (i.y < r_d->height)
	{
		i.x = r_d->height;
		ft_memmove(iter_dat[i.y], r_d->iter_count[i.y], i.x * sizeof(int));
		i.y++;
	}
	return (iter_dat);
}
