#include "./fractol.h"

//shift left in real plain
void    shift_pixels_x_l(t_RenderData *r_d, int shift_offset)
{
   // double  real;
   // double  imag;
    int     x;
    int     y;

    x = 0;
    while (x + shift_offset < r_d->Width)  // goes over x axis pixels
    {
        y = 0;
        while (y < r_d->Height)  // goes over y axis pixels
        {
            ft_memmove(&r_d->image->pixels[(y * r_d->Width + x) * BPP],
                &r_d->image->pixels[(y * r_d->Width + x + shift_offset) * BPP],
                BPP);
            y++;
        }
        x++;
    }
   // r_d->set_func(0.0, 0.0, 0, 0);
}

//shift right in real plain
void    shift_pixels_x_r(t_RenderData *r_d, int shift_offset)
{
   // double  real;
   // double  imag;
    int     x;
    int     y;

    x = r_d->Width - 1;
    while (x >= shift_offset)  // goes over x axis pixels
    {
        y = 0;
        while (y < r_d->Height)  // goes over y axis pixels
        {
            ft_memmove(&r_d->image->pixels[(y * r_d->Width + x) * BPP],
                &r_d->image->pixels[(y * r_d->Width + x - shift_offset) * BPP],
                BPP);
            y++;
        }
        x--;
    }
    // r_d->set_func(0.0, 0.0, 0, 0);
}

//shift up in imaginary plain
void    shift_pixels_y_u(t_RenderData *r_d, int shift_offset)
{
    // double  real;
    // double  imag;
    int     x;
    int     y;

    x = 0;
    while (x < r_d->Width)  // goes over x axis pixels
    {
        y = 0;
        while (y + shift_offset < r_d->Height)  // goes over y axis pixels
        {
            ft_memmove(&r_d->image->pixels[(y * r_d->Width + x) * BPP],
                &r_d->image->pixels[((y + shift_offset) * r_d->Width + x) * BPP],
                BPP);
            y++;
        }
        x++;
    }
    // r_d->set_func(0.0, 0.0, 0, 0);
}

//shift down in imaginary plain
void    shift_pixels_y_d(t_RenderData *r_d, int shift_offset)
{
  //  double  real;
  //  double  imag;
    int     x;
    int     y;

    x = 0;
    while (x < r_d->Width)  // goes over x axis pixels
    {
        y = r_d->Height - 1;
        while (y - shift_offset >= 0)  // goes over y axis pixels
        {
            ft_memmove(&r_d->image->pixels[(y * r_d->Width + x) * BPP],
                &r_d->image->pixels[((y - shift_offset) * r_d->Width + x) * BPP],
                BPP);
            y--;
        }
        x++;
    }
    // r_d->set_func(0.0, 0.0, 0, 0);
}