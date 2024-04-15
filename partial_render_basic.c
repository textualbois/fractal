#include "./fractol.h"

static void mlx_store_pixel(uint8_t* pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

// void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color)
// {
// 	MLX_NONNULL(image);
// 	MLX_ASSERT(x < image->width, "Pixel is out of bounds");
// 	MLX_ASSERT(y < image->height, "Pixel is out of bounds");

// 	uint8_t* pixelstart = &image->pixels[(y * image->width + x) * BPP];
// 	mlx_draw_pixel(pixelstart, color);
// }

void outer_render(t_RenderData *r_d, t_PixelBox *rendered_pixels)
{
    double  real;
    double  imag;
    t_Pix   pix;

    pix.x = 0;
    while (pix.x < r_d->Width)
    {
        pix.y = 0;
        while (pix.y < r_d->Height)
        {
            if (pix.x <= rendered_pixels->left_x || pix.x >= rendered_pixels->right_x ||
                pix.y <= rendered_pixels->top_y || pix.y >= rendered_pixels->bottom_y)
            {
                pixel_to_complex(pix, r_d, &real, &imag);
			    r_d->iter_count[pix.y][pix.x] = r_d->set_func(real, imag,\
			        r_d->precision, r_d->j_params);
            }
            place_color(r_d, pix);    
            pix.y++;
        }
        pix.x++;
    }
}

void buffer_segment(t_RenderData *r_d, t_PixelBox *pixel_bounds)
{
    double  real;
    double  imag;
    t_Pix   pix;
    //int     precision;


    pix.x = pixel_bounds->left_x;
    while (pix.x < pixel_bounds->right_x)
    { // goes over x axis pixels
        pix.y = pixel_bounds->top_y;

        while (pix.y < pixel_bounds->bottom_y)
        {
            // Convert pixel position to complex number based on current bounds
            pixel_to_complex(pix, r_d, &real, &imag);

            // Compute color based on Mandelbrot set function
            int color_seed = r_d->set_func(real, imag, r_d->precision, r_d->j_params);
            int color = ft_color_from_seed(color_seed, r_d->precision);
            r_d->buffer_pointer = r_d->pixel_buffer + ((pix.y * r_d->Width + pix.x) * BPP);
            mlx_store_pixel(r_d->buffer_pointer, color);
            pix.y++;
        }
        pix.x++;
    }
    //r_d->set_func(0.0, 0.0, 0, 0);
}

void draw_segment(t_RenderData *r_d, t_PixelBox *pixel_bounds)
{
    double  real;
    double  imag;
    t_Pix   pix;

    pix.x = pixel_bounds->left_x;
    while (pix.x < pixel_bounds->right_x)
    {
        pix.y = pixel_bounds->top_y;
        while (pix.y < pixel_bounds->bottom_y)
        {
            pixel_to_complex(pix, r_d, &real, &imag);
			r_d->iter_count[pix.y][pix.x] = r_d->set_func(real, imag,\
			 r_d->precision, r_d->j_params);
            place_color(r_d, pix);
            pix.y++;
        }
        pix.x++;
    }
}
