#include "./fractol.h"

int mandelbrot(double real, double imag, int max_precision, void *param)
{
    // static int iter_count;
    int     iter;
    double  r;
    double  i;

    (void)param;
    r = real;
    i = imag;
    for (iter = 0; iter < max_precision; ++iter)
    {
        double r2 = r * r;
        double i2 = i * i;
        if (r2 + i2 > 25.0)
            return (iter);
        i = 2 * r * i + imag;
        r = r2 - i2 + real;
    }
    return (max_precision);
}

int julia(double real, double imag, int max_precision, void *param)
{
    int             iter;
    double          r2;
    double          i2;
    t_DoublePair    *c;

    c = (t_DoublePair*)param;
    for (iter = 0; iter < max_precision; ++iter)
    {
        r2 = real * real;
        i2 = imag * imag;

        // The escape condition for the Julia set
        if (r2 + i2 > 25.0)
            return (iter);

        // The main difference for the Julia set is in the iteration formula,
        // which uses the constant complex number (cr, ci)
        imag = 2 * real * imag + c->y;
        real = r2 - i2 + c->x;
    }
    return (max_precision);
}

int debug_grid(double real, double imag, int max_precision, void *param) {
    int real_x3 = (int)(real * 100);
    int imag_x3 = (int)(imag * 100);

	(void)param;
    if ((int)real_x3 % 5 == 0 || (int)imag_x3 % 5 == 0) {
        return max_precision;
    } else {
        return 255;
    }
}
