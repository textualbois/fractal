#include "./fractol.h"
/*
uint32_t ft_color_from_seed(int iter, int max_iter)
{
	static int color_offset;

	if (max_iter < 0)
		color_offset = iter;
	else
	{
		if (iter == max_iter)
			return (0xFF000000); // Black
		else
		{
			double t = (double) 4 * iter / max_iter;
			// Map iter to a color gradient
			int red = (int)(sin(t * 3.14) * 255);
			int green = (int)(sin(t * 3.14) * 255);
			int blue = (int)(sin(t * 3.14) * 255);
		// Combine components into a 32-bit color value (ARGB format)
			return (255 << 24) | (red << 16) | (green << 8) | blue;
		}
	}
	return (iter);
}
*/

static void shift_color(uint8_t *color)
{
	if (*color == 255)
		*color = 0;
	else
		*color = *color + 1;
}

static void set_rgba(t_color *rgba, int code)
{
	if (code == -1)
	{
		rgba->r = (uint8_t)255;
		rgba->g = (uint8_t)150;
		rgba->b = (uint8_t)100;
		rgba->a = (uint8_t)255;
	}
	if (code == 0)
		shift_color(&rgba->r);
	if (code == 1)
		shift_color(&rgba->g);
	if (code == 2)
		shift_color(&rgba->b);
	if (code == 3)
		shift_color(&rgba->a);

}

uint32_t ft_color_from_seed(int iter, int max_iter)
{
	static t_color rgba;

	if (max_iter == -1)
		set_rgba(&rgba, iter);
	else
	{
		if (iter == max_iter)
			return (default_color);
		else
		{
			return ((rgba.r << 24) |\
			 (rgba.g << 16) |\
			  (rgba.b << 8) |\
			   (int)(rgba.a * log(iter + 1) / log(max_iter + iter)));
		}
	}
	return (iter);
}

// uint32_t ft_color_from_seed(int iter, int max_iter)
// {
// 	static t_color rgba;

// 	if (max_iter == -1)
// 		set_rgba(&rgba, iter);
// 	else
// 	{
// 		if (iter == max_iter)
// 			return (0xFF000000);
// 		else
// 		{
// 			double t = (double) 4 * iter / max_iter;
// 			r = (int)(sin(t) * 127 + 128);
// 			g = (int)(sin(t) * 127 + 128);
// 			b = (int)(sin(t) * 127 + 128);
// 			return ((r << 24) | (g << 16) | (b << 8) | rgba.a);
// 		}
// 	}
// 	return (iter);
// }


// uint32_t ft_color_from_seed(int iter, int max_iter)
// {
// 	static int color_offset;

// 	if (max_iter < 0)
// 		color_offset = iter;
// 	else
// 	{
// 		if (iter == max_iter)
// 			return (0xFF000000); // Black
// 		else
// 		{
// 			double t = (double) 4 * iter / max_iter;
// 			// Map iter to a color gradient
// 			int red = (int)(sin(t * 3.14) * 127 + 1);
// 			int green = (int)(sin(t * 3.14) * 127 + 1);
// 			int blue = (int)(sin(t * 3.14) * 127 + 1);
// 			(void)red;
// 			(void)green;
// 			(void)blue;
// 		// Combine components into a 32-bit color value (ARGB format)
// 			return ((255 << 24) | (255 << 16) | (255 << 8) | 64);
// 		}
// 	}
// 	return (iter);
// }
