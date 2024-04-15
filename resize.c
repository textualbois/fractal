#include "./fractol.h"

void    resize_window(int32_t width, int32_t height, void *param)
{
    t_W_R_D *wrd;
    t_RenderData *r_d;
    double      dots_pp_x;
    double      dots_pp_y;
    t_Pix       pix;

    wrd = (t_W_R_D*)param;
    r_d = wrd->r_data;
    clear_background_render(r_d);
    dots_pp_x = (r_d->bounds->max_r - r_d->bounds->min_r) / (double)r_d->Width;
    dots_pp_y = (r_d->bounds->max_i - r_d->bounds->min_i) / (double)r_d->Height;
    if(!mlx_resize_image(r_d->image, width, height))
      exit(EXIT_FAILURE);
    pix.x = width;
    pix.y = height;
    r_d->iter_count = iter_data_re_alloc(r_d, pix);
    if (r_d->iter_count == NULL)
      exit(EXIT_FAILURE);
    r_d->bounds->max_r += dots_pp_x * (width - r_d->Width);
    r_d->bounds->max_i += dots_pp_y * (height - r_d->Height);
    r_d->Width = width;
    r_d->Height = height;
    r_d->render_required = true;
}
