#include "./fractol.h"

uint32_t	ft_color_from_seed(int iter, int max_iter)
{
	if (iter == max_iter)
	{
		// Point is in the Mandelbrot set, use background color (black)
		return 0xFF000000; // Black
	}
	else
	{
		double t = (double) 2 * iter / max_iter;
		// Map iter to a color gradient
		int red = (int)(sin(t * 3.14) * 255);
		int green = (int)(sin(t * 3.14) * 255);
		int blue = (int)(sin(t * 3.14) * 255);

		// Combine components into a 32-bit color value (ARGB format)
		return (255 << 24) | (red << 16) | (green << 8) | blue;
	}
}