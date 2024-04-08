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
			if ((uint32_t)*p != default_color)
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

// static uint8_t*	store_image(t_RenderData *r_d)
// {
// 	uint8_t	*pixels_copy;

// 	pixels_copy = (uint8_t*)malloc(BPP * r_d->Width * r_d->Height);
// 	if (pixels_copy != NULL)
// 		ft_memmove(pixels_copy, r_d->image->pixels, BPP * r_d->Width * r_d->Height);
// 	return (pixels_copy);
// }

void color_static_hook(void* param)
{
//	static int		static_active;
	//static uint8_t	*pixel_copy;
	t_W_R_D*		wrd;

	wrd =  (t_W_R_D*)param;
	if (mlx_is_key_down(wrd->window, MLX_KEY_SPACE))
	{
		clear_background_render(wrd->r_data);
		wrd->r_data->render_required = true;
		//static_active = true;
		ft_randomize(wrd->r_data);
	}
	//else if (static_active)
	// {
    // 	wrd->r_data->render_required = false;
	// 	// ft_memmove(wrd->r_data->image, pixel_copy, BPP * wrd->r_data->)
	// 	// break_static(pixel_copy, wrd->r_data);
	// 	static_active = false;
	// }
}
