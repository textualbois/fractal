#include "./fractol.h"

void	pixel_to_complex(t_Pix pixel, t_RenderData *r_d, double *real, double *imag)
{
	t_FractalBounds *bounds;

	bounds = r_d->bounds;
	*real = bounds->min_r + (pixel.x / (double)r_d->Width) * (bounds->max_r - bounds->min_r);
	*imag = bounds->min_i + (pixel.y / (double)r_d->Height) * (bounds->max_i - bounds->min_i);
}

// Function to draw the Mandelbrot set
void	draw_from_iter_counts(t_RenderData *r_d)
{
	t_Pix   pixel;

	pixel.x = 0;
	while (pixel.x < r_d->Width)
	{
		pixel.y = 0;
		while (pixel.y < r_d->Height)
		{
			place_color(r_d, pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}

void	draw_set(t_RenderData *r_d)
{
	double  real;
	double  imag;
	t_Pix   pixel;

	//printf("new render called. bounds (min_x, max_x)(min_i, max_i) (%f, %f)(%f, %f)\n", r_d->bounds->min_r, r_d->bounds->max_r,r_d->bounds->min_i,r_d->bounds->max_i);
	pixel.x = 0;
	while (pixel.x < r_d->Width)
	{
		pixel.y = 0;
		while (pixel.y < r_d->Height)
		{
			pixel_to_complex(pixel, r_d, &real, &imag);
			r_d->iter_count[pixel.y][pixel.x] = r_d->set_func(real, imag,\
			 r_d->precision, r_d->j_params);
			place_color(r_d, pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}

void	place_color(t_RenderData *r_d, t_Pix pos)
{
	int color;
	int	color_seed;

	color_seed = r_d->iter_count[pos.y][pos.x];
	color = ft_color_from_seed(color_seed, r_d->precision);
	mlx_put_pixel(r_d->image, pos.x, pos.y, color);
}