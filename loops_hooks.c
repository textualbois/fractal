#include "./fractol.h"

void	ft_exit_button(void *param)
{
	t_W_R_D *wrd;

	wrd = (t_W_R_D *)param;
	if (mlx_is_key_down(wrd->window, MLX_KEY_ESCAPE))
		mlx_close_window(wrd->window);
}

void	ft_black_out_hook(void *param)
{
	t_W_R_D *wrd;

	wrd = (t_W_R_D *)param;
	if (mlx_is_key_down(wrd->window, MLX_KEY_R))
		black_out(wrd);
}

bool	bounds_changed(const t_FractalBounds *old_bounds, const t_FractalBounds *new_bounds)
{
	return old_bounds->min_r != new_bounds->min_r ||
			old_bounds->max_r != new_bounds->max_r ||
			old_bounds->min_i != new_bounds->min_i ||
			old_bounds->max_i != new_bounds->max_i;
}

void	ft_image_shift(void *param)
{
	t_W_R_D *wrd;
	//size_t  previous_inst;
	//t_FractalBounds old_bounds;
	// int direction;

	wrd = (t_W_R_D *)param;
	//previous_inst = wrd->r_data->image->count - 1;
	//old_bounds = *(wrd->r_data->bounds);
	if (mlx_is_key_down(wrd->window, MLX_KEY_DOWN))
	{
		clear_background_render(wrd->r_data);
		move_down(wrd->r_data);
	}
	if (mlx_is_key_down(wrd->window, MLX_KEY_UP))
	{
		clear_background_render(wrd->r_data);
		move_up(wrd->r_data); ////// change this later
		draw_set(wrd->r_data); ////// change this later
	}
	if (mlx_is_key_down(wrd->window, MLX_KEY_LEFT))
	{
		clear_background_render(wrd->r_data);
		move_left(wrd->r_data);
	}
	if (mlx_is_key_down(wrd->window, MLX_KEY_RIGHT))
	{
		clear_background_render(wrd->r_data);
		move_right(wrd->r_data);
		//mlx_image_to_window(wrd->window, wrd->r_data->image, 0, 0);
		//wrd->r_data->image->instances[previous_inst].enabled = false;
	}
}

void	background_render(void *param)
{
	t_W_R_D *wrd;
	int row_completed;

	wrd = (t_W_R_D *)param;
	(void)wrd;
	if (wrd->r_data->block_render == true)
	{
		printf("blocked a render\n");
		clear_background_render(wrd->r_data);
		wrd->r_data->render_status = background_render_not_started;
	}
	else if (wrd->r_data->render_required == true)
	{
		if (wrd->r_data->render_status == background_render_not_started)
			wrd->r_data->render_status = init_background_render(wrd->r_data);
		if (wrd->r_data->render_status == background_render_started)
		{
			row_completed = continue_background_render(wrd->r_data);
			if (row_completed == wrd->r_data->Height)
				complete_render(wrd->r_data);
		}
	}
	//printf("loop_passed\n");
}

void	init_loops_n_hooks(t_W_R_D *wrd)
{
	mlx_loop_hook(wrd->window, ft_exit_button, wrd);
	mlx_loop_hook(wrd->window, ft_image_shift, wrd);
	mlx_loop_hook(wrd->window, ft_black_out_hook, wrd);
	mlx_scroll_hook(wrd->window, ft_zoom, wrd);
	mlx_resize_hook(wrd->window, resize_window, wrd);
	mlx_loop_hook(wrd->window, color_shift_hook, wrd);
	mlx_loop_hook(wrd->window, background_render, wrd);
	//mlx_loop_hook(window, ft_zoom, window);

	mlx_loop(wrd->window);
	mlx_terminate(wrd->window);
}
