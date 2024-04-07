
#include "./fractol.h"

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void color_shift_hook(void* param)
{
	t_W_R_D* wrd;

	wrd =  (t_W_R_D*)param;

	if (mlx_is_key_down(wrd->window, MLX_KEY_R))
		shift_red(wrd);
	if (mlx_is_key_down(wrd->window, MLX_KEY_G))
		shift_green(wrd);
	if (mlx_is_key_down(wrd->window, MLX_KEY_B))
		shift_blue(wrd);
	if (mlx_is_key_down(wrd->window, MLX_KEY_A))
		shift_a(wrd);
	if (mlx_is_key_down(wrd->window, MLX_KEY_SPACE))
		ft_randomize();
}
