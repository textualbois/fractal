#include "./fractol.h"

int main(int argc, char **argv)
{
    mlx_t       *window;
    t_W_R_D     *w_r_d;

	w_r_d = NULL;
	if (argc > 1)
	{
    	if (!(window = mlx_init(WIDTH, HEIGHT, "Fractol", true)))
		{
        	puts(mlx_strerror(mlx_errno));
        	return EXIT_FAILURE;
    	}
		if (!ft_strncmp(argv[1], "julia\0", 6) && argc == 4)
			w_r_d = init_all(window, 2, argc, argv);
		else if (!ft_strncmp(argv[1], "mandelbrot\0", 10))
			w_r_d = init_all(window, 1, argc, argv);
		else if (!ft_strncmp(argv[1], "debug\0", 5))
			w_r_d = init_all(window, 0, argc, argv);
		else
			printf("bad input\n");

    	if (w_r_d == NULL)
    	{
        	mlx_close_window(window);
        	return EXIT_FAILURE;
    	}

    	draw_set(w_r_d->r_data);

    	if (mlx_image_to_window(window, w_r_d->r_data->image, 0, 0) == -1) {
        	mlx_close_window(window);
        	puts(mlx_strerror(mlx_errno));
        	return EXIT_FAILURE;
    	}

    	init_loops_n_hooks(w_r_d);
    	free_W_R_D(w_r_d);
	}
    return EXIT_SUCCESS;
}



int check_input(int argc, char **argv)
{
	int f_id;

	if (argc == 1)
		return (0);
	if (!ft_strncmp(argv[1], "julia\0", 6))
		f_id = 2;
	else if (!ft_strncmp(argv[1], "mandelbrot\0", 10))
		f_id = 1;
	else if (!ft_strncmp(argv[1], "debug\0", 5))
		f_id = 3;
	else
		f_id = 0;
	if (f_id == 2)
		return (check_julia(int argc, char **argv))
	if (f_id == 1 &&)



}
