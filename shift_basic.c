#include "./fractol.h"

//shift left in real plain
void    shift_pixels_x_l(t_RenderData *r_d, int shift_offset)
{
    int y;

    y = 0;
    while (y < r_d->Height)  // goes over y axis pixels
    {
        ft_memmove(r_d->iter_count[y],\
            r_d->iter_count[y] + shift_offset,\
            (r_d->Width - shift_offset) * sizeof(int));
        y++;
    }
}

//shift right in real plain
void    shift_pixels_x_r(t_RenderData *r_d, int shift_offset)
{
    int y;

    y = 0;
    while (y < r_d->Height)  // goes over y axis pixels
    {
        ft_memmove(r_d->iter_count[y] + shift_offset,\
            r_d->iter_count[y],\
            (r_d->Width - shift_offset) * sizeof(int));
        y++;
    }
}

//shift up in imaginary plain
void    shift_pixels_y_u(t_RenderData *r_d, int shift_offset)
{
    int y;

    y = 0;
    while (y + shift_offset < r_d->Height)
    {
        ft_memmove(r_d->iter_count[y],\
            r_d->iter_count[y + shift_offset],\
            r_d->Width * sizeof(int));
        y++;
    }
}

//shift down in imaginary plain
void    shift_pixels_y_d(t_RenderData *r_d, int shift_offset)
{
    int y;

    y = r_d->Height - 1;
    while (y - shift_offset >= 0)
    {
        ft_memmove(r_d->iter_count[y],\
            r_d->iter_count[y - shift_offset],\
            r_d->Width * sizeof(int));
        y--;
    }
}
