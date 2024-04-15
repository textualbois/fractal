#include "./fractol.h"

static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(t_RenderData* r_d)
{
	mlx_image_t	*img;
	t_Pix		pix;
	uint32_t	color;
	uint8_t 	*p;

	img = r_d->image;
	pix.x = 0;
	while (pix.x < r_d->Width)
	{
		pix.y = 0;
		while (pix.y < r_d->Height)
		{
			p = img->pixels + ((pix.y * r_d->Width + pix.x) * BPP);
			if (r_d->iter_count[pix.y][pix.x] != r_d->precision)
			{
				color = ft_pixel(rand() % 0xFF, rand() % 0xFF,\
					rand() % 0xFF, rand() % 0xFF);
				ft_memmove(p, &color, BPP * 3 / 4);
			}
			pix.y++;
		}
		pix.x++;
	}
}

void color_static_hook(void* param)
{
	static int		static_active;
	t_W_R_D*		wrd;

	wrd = (t_W_R_D*)param;
	if (mlx_is_key_down(wrd->window, MLX_KEY_SPACE))
	{
		clear_background_render(wrd->r_data);
		wrd->r_data->render_required = true;
		static_active = true;
		ft_randomize(wrd->r_data);
	}
	else if (static_active)
	{
		draw_from_iter_counts(wrd->r_data);
		static_active = false;
	}
}
