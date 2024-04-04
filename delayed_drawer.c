#include "./fractol.h"

int init_background_render(t_RenderData *r_d)
{
    (void) r_d;
    // if (r_d->pixel_buffer != NULL)
    // {
    //     printf("oops, pixel buffer should be null\n");
    //     clear_background_render(r_d);
    // }
    // r_d->pixel_buffer = (uint8_t*)malloc(BPP * r_d->Width * r_d->Height);
    // if (r_d->pixel_buffer != NULL)
    // {
        
//        r_d->buffer_pointer = r_d->pixel_buffer;
        return (background_render_started);
    // }
    // return (background_render_not_started);
    
}

int continue_background_render(t_RenderData *r_d)
{
    static t_Pix pix;
    t_PixelBox segment;

    if (r_d == NULL)
    {
        pix.y = 0;
        pix.x = 0;
    }
    else
    {
        segment.top_y = pix.y;
        segment.bottom_y = pix.y + 1;
        segment.left_x = pix.x;
        segment.right_x = r_d->Width;
        draw_segment(r_d, &segment);
        pix.y++;
        
    }
    return (pix.y);
}

void complete_render(t_RenderData *r_d)
{
  //  ft_memmove(r_d->image->pixels,
    //    r_d->pixel_buffer,
      //  r_d->Height * r_d-> Width * BPP);
    r_d->render_status = background_render_not_started;
    r_d->render_required = false;
    clear_background_render(r_d);
}

void    clear_background_render(t_RenderData *r_d)
{

  //  double      dots_pp_x;
    // if (r_d->pixel_buffer != NULL)
    //     free(r_d->pixel_buffer);
    // r_d->buffer_pointer = NULL;
    // r_d->pixel_buffer = NULL;
    r_d->render_status = background_render_not_started;
    continue_background_render(NULL);
   // dots_pp_x = (r_d->bounds->max_r - r_d->bounds->min_r) / (double)r_d->Width;
     //printf("after background rendering the pp_x is: %lf\n", dots_pp_x);
}