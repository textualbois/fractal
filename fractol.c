/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:39:34 by isemin            #+#    #+#             */
/*   Updated: 2024/04/25 19:34:45 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

static mlx_t	*initialize_window(void)
{
	mlx_t	*window;

	window = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!window)
		ft_printf("error making window.\n");
	return (window);
}

static void	cleanup_and_exit_failure(mlx_t *window, t_W_R_D *w_r_d)
{
	if (w_r_d != NULL)
		free_w_r_d(w_r_d);
	mlx_close_window(window);
	ft_printf("failed to draw image to window\n");
}

static int	setup_and_draw(mlx_t *window, int fn_id, int argc, char **argv)
{
	t_W_R_D	*w_r_d;

	w_r_d = init_all(window, fn_id, argc, argv);
	if (w_r_d == NULL)
		return (0);
	ft_color_from_seed(-1, -1);
	draw_set(w_r_d->r_data);
	if (mlx_image_to_window(window, w_r_d->r_data->image, 0, 0) == -1)
		return (0);
	init_loops_n_hooks(w_r_d);
	free_w_r_d(w_r_d);
	return (1);
}

void leaks()
{
	system("leaks fractol");
}

int	main(int argc, char **argv)
{
	mlx_t	*window;
	int		fn_id;

	atexit(leaks);
	fn_id = check_input(argc, argv);
	if (fn_id <= 0)
	{
		show_inputs();
		return (EXIT_SUCCESS);
	}
	window = initialize_window();
	if (!window)
		return (EXIT_FAILURE);
	if (!setup_and_draw(window, fn_id, argc, argv))
	{
		cleanup_and_exit_failure(window, NULL);
		return (EXIT_FAILURE);
	}
	mlx_close_window(window);
	return (EXIT_SUCCESS);
}


// void cleanup()
// {
// 	char command[100];
// 	pid_t pid = getpid();
// 	sprintf(command, "leaks %d", pid);
// 	system(command);
// }

	// atexit(cleanup);