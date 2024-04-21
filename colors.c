#include "./fractol.h"

/*
static uint32_t** init_colors(void)
{
	static uint32_t*	colors[11];
	int					i;

    // Dynamically allocate memory for each color set
	i = 0;
	while (i < 11)
	{
		colors[i] = (uint32_t*)malloc(9 * sizeof(uint32_t));
		if (colors[i] == NULL)
		{
			while (i >= 0)
			{
				free(colors[i]);
				i--;
			}
			return (NULL);
		}
		i++;
	}
// Google colors
colors[0] = (uint32_t[]){
0xFF4285F4, // Google Blue
0xFFDB4437, // Google Red
0xFFF4B400, // Google Yellow
0xFF0F9D58, // Google Green
0xFF4285F4, // Google Blue
0xFFDB4437, // Google Red
0xFFF4B400, // Google Yellow
0xFF0F9D58, // Google Green
0xFF4285F4  // Google Blue, again for balance
};


// Wacky clown style
colors[1] = (uint32_t[]){
0xFFFF00FF, // Magenta
0xFF00FFFF, // Cyan
0xFFFFFF00, // Yellow
0xFFFF0000, // Red
0xFF0000FF, // Blue
0xFF00FF00, // Lime
0xFFFF6600, // Orange
0xFF9900FF, // Electric Purple
0xFF00FF7F  // Spring Green
};
// Psychedelic
colors[2] = (uint32_t[]){
0xFF9400D3, // Dark Violet
0xFF4B0082, // Indigo
0xFF0000FF, // Blue
0xFF00FF00, // Green
0xFFFFFF00, // Yellow
0xFFFF7F00, // Orange
0xFFFF0000, // Red
0xFF9400D3, // Dark Violet, again for loop
0xFF4B0082  // Indigo, again for continuity
};
// Set 3: Cool Blues
colors[3] = (uint32_t[]){
0xFF001f3f, // Dark Navy
0xFF0074D9, // Bright Blue
0xFF7FDBFF, // Light Blue
0xFF39CCCC, // Teal
0xFF001f3f, // Dark Navy, again for repetition
0xFF0074D9, // Bright Blue, again for repetition
0xFF7FDBFF, // Light Blue, again for repetition
0xFF39CCCC, // Teal, again for repetition
0xFF001f3f  // Dark Navy, to loop back
};
// Set 4: Sunset
colors[4] = (uint32_t[]){
0xFFFEBF10, // Soft Yellow
0xFFFCAE1E, // Golden Yellow
0xFFFDAE84, // Pale Gold
0xFFFD7E14, // Vibrant Orange
0xFFFC5A11, // Deep Orange
0xFFE95500, // Burnt Orange
0xFFD22E2E, // Sunset Red
0xFF912CEE, // Purple
0xFF4B0082  // Indigo
};
// Set 5: Forest Greens
colors[5] = (uint32_t[]){
0xFF004D00, // Dark Green
0xFF006600, // Medium Dark Green
0xFF008000, // Office Green
0xFF009900, // Medium Green
0xFF00B33C, // Emerald Green
0xFF00CC44, // Light Green
0xFF2EB82E, // Lime Green
0xFF66FF66, // Pale Green
0xFF99FF99  // Very Pale Green
};
// Set 6: Pastels
colors[6] = (uint32_t[]){
0xFFFFB3BA, // Light Coral
0xFFFFDFBA, // Peach
0xFFFFFFBA, // Light Yellow
0xFFBAFFC9, // Mint
0xFFBAE1FF, // Light Blue
0xFFF4BFFF, // Light Purple
0xFFFFE0E0, // Soft Pink
0xFFD9EAD3, // Tea Green
0xFFF5F5DC  // Beige
};
// Set 7: Earth Tones
colors[7] = (uint32_t[]){
0xFF8B4513, // Saddle Brown
0xFFA0522D, // Sienna
0xFFD2B48C, // Tan
0xFFDEB887, // Burlywood
0xFFF4A460, // Sandy Brown
0xFFDAA520, // Goldenrod
0xFFBDB76B, // Dark Khaki
0xFF9ACD32, // Yellow Green
0xFF556B2F  // Dark Olive Green
};
// Set 8: Deep Sea
colors[8] = (uint32_t[]){
0xFF000080, // Navy
0xFF0000CD, // Medium Blue
0xFF00008B, // Dark Blue
0xFF191970, // Midnight Blue
0xFF20B2AA, // Light Sea Green
0xFF48D1CC, // Medium Turquoise
0xFF40E0D0, // Turquoise
0xFF7FFFD4, // Aquamarine
0xFFB0E0E6   // Powder Blue
};
// Set 9: Autumn
colors[9] = (uint32_t[]){
0xFFFF8C00, // Dark Orange
0xFFFFA500, // Orange
0xFFFF4500, // Orange Red
0xFFDC143C, // Crimson
0xFFB22222, // Firebrick
0xFF8B0000, // Dark Red
0xFFDAA520, // Goldenrod
0xFFB8860B, // Dark Goldenrod
0xFFFFD700  // Gold
};
colors[10] = (uint32_t[]){
0xFFFFC0CB, // Pink
0xFFFF6347, // Tomato Red
0xFFFF4500, // OrangeRed
0xFFFFD700, // Gold
0xFFADFF2F, // GreenYellow
0xFF40E0D0, // Turquoise
0xFF9400D3, // Dark Violet
0xFFFF69B4, // Hot Pink
0xFF8A2BE2  // Blue Violet
};


	return colors;
}

uint32_t ft_color_arr(int i)
{
	static int			color_set;
	static uint32_t**	colors;

	if (colors == NULL)
	{
		color_set = 10;
		colors = init_colors();
		if (colors == NULL)
		{
			return (0);
		}
	}
	if (i < 0) {
		color_set = -i;
		if (color_set > 10)
			color_set = 10;
		return (0);
	}

	return (colors[color_set][i % 11]);
}

uint32_t	ft_color_from_seed(int iter, int max_iter)
{
	if (iter == max_iter)
		return (DEFAULT_COLOR); // Black
	else
		return (ft_color_arr(iter % 11));
}

*/
