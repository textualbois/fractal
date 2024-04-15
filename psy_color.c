#include "./fractol.h"

static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
void    max_c_wrapper(void *param)
{
	t_W_R_D*    wrd;

	wrd = (t_W_R_D*)param;
    if (mlx_is_key_down(wrd->window, MLX_KEY_O))
        ft_max_c(DECREMENT_MAX_C);
}

int ft_max_c(int signal)
{
    static int max_c;

    if (signal == DECREMENT_MAX_C)
        max_c--;
    if (max_c <= 0)
        max_c = 56;
    return (max_c);
}

void ft_psy_flow(t_RenderData* r_d, int c_code, int max_c)
{
	mlx_image_t	*img;
	t_Pix		pix;
	uint32_t	color;
	uint8_t 	*p;

	img = r_d->image;
	for (pix.x = 0; pix.x < r_d->Width; pix.x++)
	{
		for (pix.y = 0; pix.y < r_d->Height; pix.y++)
		{
			p = img->pixels + ((pix.y * r_d->Width + pix.x) * BPP);
			int grouping_factor = (r_d->iter_count[pix.y][pix.x] + c_code) % max_c;
			int r = (int)(127.5 * (sin(grouping_factor * 0.2) + 1));
			int g = (int)(127.5 * (cos(grouping_factor * 0.2) + 1));
			int b = (int)(127.5 * (sin(grouping_factor * 0.3) + 1));
			int a = 0xFF;
			color = ft_pixel(r, g, b, a);
			ft_memmove(p, &color, BPP * 3 / 4);
		}
	}
}

void color_psy_hook(void* param)
{
	static int		activity_status;
    int             max_c;
	t_W_R_D*		wrd;

	wrd = (t_W_R_D*)param;
	if (mlx_is_key_down(wrd->window, MLX_KEY_P))
	{
        max_c = ft_max_c(GIVE_MAX_C);
		clear_background_render(wrd->r_data);
		wrd->r_data->render_required = true;
		activity_status++;
        if (activity_status >= max_c)
            activity_status = 1;
		ft_psy_flow(wrd->r_data, activity_status, max_c);
	}
	else if (activity_status > 0)
	{
		draw_from_iter_counts(wrd->r_data);
		activity_status = 0;
	}
}
