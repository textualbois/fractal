#include "./fractol.h"

// static uint32_t ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
// {
// 	return (r << 24 | g << 16 | b << 8 | a);
// }

static void shift_color(uint8_t *color)
{
	if (*color == 255)
		*color = 0;
	else
		*color = *color + 1;
}


void ft_apply_color(t_RenderData* r_d, int offset)
{
	mlx_image_t	*img;
	t_Pix		pix;
	uint8_t 	*p;
	//uint8_t		p_lil;

	img = r_d->image;
	pix.x = 0;
	while (pix.x < r_d->Width)
	{
		pix.y = 0;
		while (pix.y < r_d->Height)
		{
			p = img->pixels + ((pix.y * r_d->Width + pix.x) * BPP);
			if ((uint32_t)*p != default_color)
				shift_color(&(p[offset]));
			pix.y++;
		}
		pix.x++;
	}
}



void shift_colors(t_RenderData *r_d, int code)
{

	clear_background_render(r_d);
	ft_color_from_seed(code, -1);
	ft_apply_color(r_d, code);
}

void color_shift_hook(void* param)
{
	t_W_R_D*		wrd;

	wrd =  (t_W_R_D*)param;

	if (mlx_is_key_down(wrd->window, MLX_KEY_R))
		shift_colors(wrd->r_data, 0);
	else if (mlx_is_key_down(wrd->window, MLX_KEY_G))
		shift_colors(wrd->r_data, 1);
	else if (mlx_is_key_down(wrd->window, MLX_KEY_B))
		shift_colors(wrd->r_data, 2);
	else if (mlx_is_key_down(wrd->window, MLX_KEY_A))
		shift_colors(wrd->r_data, 3);
}
