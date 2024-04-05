#include "./fractol.h"

void move_right(t_RenderData *r_d)
{
    double r_delta;
    int shift_offset;
   // double render_offset;
    t_PixelBox rendered_pixels;


    r_delta = (r_d->bounds->max_r - r_d->bounds->min_r) * 0.02;
    shift_offset = r_d->Width * 0.02;
   // render_offset = r_d->bounds->max_r - r_delta;
    r_d->bounds->min_r += r_delta;
    r_d->bounds->max_r += r_delta;
    shift_pixels_x_l(r_d, shift_offset);
    rendered_pixels.left_x = 0;
    rendered_pixels.right_x = r_d->Width - 1 - shift_offset; // Entire width minus one for 0-based index
    rendered_pixels.top_y = 0;
    rendered_pixels.bottom_y = r_d->Height - 1; // Entire height minus one for 0-based index


    outer_render(r_d, &rendered_pixels);
}

void move_left(t_RenderData *r_d)
{
    double r_delta;
    int shift_offset;
    t_PixelBox rendered_pixels;

    r_delta = (r_d->bounds->max_r - r_d->bounds->min_r) * 0.02;
    shift_offset = r_d->Width * 0.02;
    r_d->bounds->min_r -= r_delta;
    r_d->bounds->max_r -= r_delta;
    shift_pixels_x_r(r_d, shift_offset);
    rendered_pixels.left_x = shift_offset;
    rendered_pixels.right_x = r_d->Width - 1;
    rendered_pixels.top_y = 0;
    rendered_pixels.bottom_y = r_d->Height - 1;


    outer_render(r_d, &rendered_pixels);
}

void move_down(t_RenderData *r_d)
{
    double i_delta;
    int shift_offset;
    t_PixelBox rendered_pixels;

    i_delta = (r_d->bounds->max_i - r_d->bounds->min_i) * 0.02;
    shift_offset = r_d->Height * 0.02;
    r_d->bounds->min_i += i_delta;
    r_d->bounds->max_i += i_delta;
    shift_pixels_y_u(r_d, shift_offset);
    rendered_pixels.left_x = 0;
    rendered_pixels.right_x = r_d->Width - 1;
    rendered_pixels.top_y = 0;
    rendered_pixels.bottom_y = r_d->Height - 1 - shift_offset;
    outer_render(r_d, &rendered_pixels);
}

void move_up(t_RenderData *r_d)
{
    double i_delta;

    i_delta = (r_d->bounds->max_i - r_d->bounds->min_i) * 0.02;
    r_d->bounds->min_i -= i_delta;
    r_d->bounds->max_i -= i_delta;
}
