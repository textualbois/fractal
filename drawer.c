#include "./fractol.h"

void    black_out(t_W_R_D *w_r_d)
{
   // double  real;
    //double  imag;
   //printf("new render called\n");
   //int i = 0;

    for (int x = 0; x < WIDTH; ++x) { // goes over x axis pixels
        for (int y = 0; y < HEIGHT; ++y) { // goes over y axis pixels
            //pixel_to_complex(x, y, r_d->bounds, &real, &imag);   // takes current pixel (x, y), the bounds of what we are drawing and sets the real and imag vals
           // (void) max_iter;
            ///int color_seed = r_d->set_func(real, imag, r_d->precision); // value from 0 to max_iter
            int color = ft_color_from_seed(1, 1);
            mlx_put_pixel(w_r_d->r_data->image, x, y, color);
        }
    }
    //r_d->set_func(0.0, 0.0, 0);
}

// Function to map pixel coordinates to complex numbers
void	pixel_to_complex(t_Pix pixel, t_RenderData *r_d, double *real, double *imag)
{
	t_FractalBounds *bounds;

	bounds = r_d->bounds;
	*real = bounds->min_r + (pixel.x / (double)r_d->Width) * (bounds->max_r - bounds->min_r);
	*imag = bounds->min_i + (pixel.y / (double)r_d->Height) * (bounds->max_i - bounds->min_i);
}

// Function to draw the Mandelbrot set
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