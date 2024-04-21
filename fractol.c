/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:39:34 by isemin            #+#    #+#             */
/*   Updated: 2024/04/21 17:40:12 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static mlx_t*	initialize_window(void)
{
	mlx_t	*window;

	printf("initing window\n");
	window = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!window)
		puts(mlx_strerror(mlx_errno));
	return (window);
}

static void	cleanup_and_exit_failure(mlx_t *window, t_W_R_D *w_r_d)
{
	if (w_r_d != NULL)
		free_w_r_d(w_r_d);
	mlx_close_window(window);
	puts(mlx_strerror(mlx_errno));
}

static int	setup_and_draw(mlx_t *window, int fn_id, int argc, char **argv)
{
	t_W_R_D	*w_r_d;

	printf("setting up to draw\n");
	w_r_d = init_all(window, fn_id, argc, argv);
	if (w_r_d == NULL)
		return (0);
	ft_color_from_seed(-1, -1);
	printf("color set ups\n");
	draw_set(w_r_d->r_data);
	if (mlx_image_to_window(window, w_r_d->r_data->image, 0, 0) == -1)
	{
		cleanup_and_exit_failure(window, w_r_d);
		return (0);
	}
	init_loops_n_hooks(w_r_d);
	free_w_r_d(w_r_d);
	return (1);
}

int	main(int argc, char **argv)
{
	mlx_t	*window;
	int		fn_id;

	fn_id = check_input(argc, argv);
	if (fn_id <= 0)
		return (EXIT_SUCCESS);
	window = initialize_window();
	if (!window)
	{
		printf("no window\n");
		return (EXIT_FAILURE);
	}
	printf("got window\n");
	if (!setup_and_draw(window, fn_id, argc, argv))
	{
		printf("setup or draw failed\n");
		cleanup_and_exit_failure(window, NULL);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
