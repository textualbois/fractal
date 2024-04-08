#include "./fractol.h"

// void    resize_window(int32_t width, int32_t height, void *param)
// {
//     t_W_R_D *wrd;
//     t_RenderData *r_d;
//     double      dots_pp_x;
//     double      dots_pp_y;

//     wrd = (t_W_R_D*)param;
//     r_d = wrd->r_data;
//     dots_pp_x = (r_d->bounds->max_r - r_d->bounds->min_r) / r_d->Width;
//     dots_pp_y = (r_d->bounds->max_i - r_d->bounds->min_i) / r_d->Height;

//     clear_background_render(r_d);
//     mlx_delete_image(wrd->window, r_d->image);
//     if (!(r_d->image = mlx_new_image(wrd->window, width, height)))
//     {
//         puts(mlx_strerror(mlx_errno));
//         exit(EXIT_FAILURE);
//     }
//     r_d->bounds->max_r += dots_pp_x * (width - r_d->Width);
//     r_d->bounds->max_i += dots_pp_y * (height - r_d->Height);
//     r_d->Width = width;
//     r_d->Height = height;
//     draw_set(r_d);
//         if (mlx_image_to_window(wrd->window, r_d->image, 0, 0) == -1) {
//         mlx_close_window(wrd->window);
//         puts(mlx_strerror(mlx_errno));
//         exit(EXIT_FAILURE);
//     }
// }

void    resize_window(int32_t width, int32_t height, void *param)
{
    t_W_R_D *wrd;
    t_RenderData *r_d;
    double      dots_pp_x;
    double      dots_pp_y;
	static int c;

	printf("resizing number %i\n", c);
	c++;

    wrd = (t_W_R_D*)param;
    r_d = wrd->r_data;
    clear_background_render(r_d);
    dots_pp_x = (r_d->bounds->max_r - r_d->bounds->min_r) / (double)r_d->Width;
    dots_pp_y = (r_d->bounds->max_i - r_d->bounds->min_i) / (double)r_d->Height;

   // printf("initial pp_x was: %lf\n", dots_pp_x);
    mlx_resize_image(r_d->image, width, height);
   // printf("old width: %i\nnew width: %i\n",  r_d->Width, width);
    r_d->bounds->max_r += dots_pp_x * (width - r_d->Width);
    r_d->bounds->max_i += dots_pp_y * (height - r_d->Height);
    r_d->Width = width;
    r_d->Height = height;
  //   dots_pp_x = (r_d->bounds->max_r - r_d->bounds->min_r) / (double)r_d->Width;
  //   printf("new pp_x is: %lf\n", dots_pp_x);
  //  printf("bounds are (min_r, max_r)(min_i, max_i) = (%lf, %lf)(%lf, %lf)\n",\
  //   r_d->bounds->min_r, r_d->bounds->max_r, r_d->bounds->min_i, r_d->bounds->max_i);
    r_d->render_required = true;
    //draw_set(r_d);
    //     if (mlx_image_to_window(wrd->window, r_d->image, 0, 0) == -1) {
    //     mlx_close_window(wrd->window);
    //     puts(mlx_strerror(mlx_errno));
    //     exit(EXIT_FAILURE);
    // }
}
