
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/MLX42.h"
//#include "MLX42/MLX42_int.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

#define OTHER_TASK_PRESENT 0
//#define render_required 1
#define RENDER_NOT_REQUIRED 2

#define DECREMENT_MAX_C 1
#define GIVE_MAX_C 0
#define BACKGROUND_RENDER_NOT_STARTED 0
#define BACKGROUND_RENDER_STARTED 2
#define WIDTH 800
#define HEIGHT 800
#define BPP sizeof(int32_t)
#define MANDEL 1
#define JUL 2
#define B_SHIP 3
#define DEFAULT_COLOR 0x000000FF

typedef struct s_color{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_color;

typedef struct s_Pix{
	int	x;
	int	y;
}	t_Pix;

typedef struct t_DPair{
	double	x;
	double	y;
}	t_DPair;

typedef struct s_PixDouble{
	double	x;
	double	y;
}	t_PixDouble;

typedef struct s_Pix32{
	int32_t	x;
	int32_t	y;
}	t_Pix32;

typedef struct s_FBounds{
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
}	t_bounds;

//pixels not to be re_drawn
typedef struct s_PixBox{
	int	left_x;
	int	right_x;
	int	top_y;
	int	bottom_y;
}		t_PixBox;

typedef struct s_RData{
	t_bounds	*bounds;
	t_bounds	bounds_temp;
	double		zoom;
	int			max_iter;
	int			width;
	int			height;

	int			block_render;
	bool		render_required;
	int			render_status;
	bool		static_active;
	bool		psy_active;

	int			**iter_count;
	uint8_t		*buffer_pointer;
	uint8_t		*pixel_buffer;
	mlx_image_t	*image;
	t_DPair		*j_params;
	int			f_code;
	int			(*set_f)(double, double, int, void*);
}				t_RData;

typedef struct s_W_R_D{
	mlx_t	*window;
	t_RData	*r_data;
}	t_W_R_D;

//init.c
t_W_R_D		*init_all(mlx_t *window, int func_id, int argc, char **argv);
t_bounds	*initbounds(double min_r, double max_r, double min_i, double max_i);
t_RData		*init_rdata(t_bounds *bounds, mlx_t *window, void *set_f, int max_iter);
t_W_R_D		*init_w_r_d(mlx_t *window, t_RData *render_data);

//init_helper.c
t_RData		*init_mandelbrot(mlx_t *window, int argc, char **argv, int f_id);
t_RData		*init_julia(mlx_t *window, int argc, char **argv);
t_RData		*init_debug(mlx_t *window, int argc, char **argv);

//init_img_meta.c
int			**iter_data(int width, int height);
int			**iter_data_re_alloc(t_RData *r_d, t_Pix new_window);
void		clear_iter_data(int **iter_data, int row_max);
int			**iter_data_copy(t_RData *r_d);

//clear.c
void		free_fbounds(t_bounds *bounds);
void		free_rdata(t_RData *render_data);
void		free_w_r_d(t_W_R_D *w_r_d);

/*
//zoom.c
void zoom_in(t_RData *r_d, int32_t cursor_x, int32_t cursor_y);
void zoom_out(t_RData *r_d, int32_t cursor_x, int32_t cursor_y);
void down_scale(t_RData *r_d, t_PixBox box, double scale);
void ft_zoom(double x_delta, double y_delta, void *param);
*/

//zoom.c
void		zoom_in(t_RData *r_d, t_Pix cursor);
void		stretch(t_RData *r_d, t_PixBox box, double scale_x, double scale_y);
void		zoom_out(t_RData *r_d, t_Pix cursor);
void		down_scale(t_RData *r_d, t_PixBox box, double scale_x, double scale_y);
void		ft_zoom(double x_delta, double y_delta, void *param);

//draw_router.c
void	quick_draw(t_W_R_D	*wrd);
void	smart_draw(t_W_R_D	*wrd);

//mover.c
void		move_left(t_RData *r_d);
void		move_right(t_RData *r_d);
void		move_up(t_RData *r_d);
void		move_down(t_RData *r_d);

//mover_quick.c
void		move_left_quick(t_RData *r_d);
void		move_right_quick(t_RData *r_d);
void		move_up_quick(t_RData *r_d);
void		move_down_quick(t_RData *r_d);

//loops_hooks.c
void		ft_exit_button(void *param);
void		ft_image_shift(void *param);
void		init_loops_n_hooks(t_W_R_D *wrd);
void		background_render(void *param);

// void ft_black_out_hook(void *param);

//set_ftions.c
int			mandelbrot(double real, double imag, int max_max_iter, void *param);
int			julia(double real, double imag, int max_max_iter, void *param);
int			burning_ship(double real, double imag, int max_max_iter, void *param);
int			debug_grid(double real, double imag, int max_max_iter, void *param);

//color_shift.c
void		color_shift_hook(void *param);
void		ft_apply_color(t_RData *r_d, int offset);
void		shift_colors(t_RData *r_d, int code);

//color_static.c
void		color_static_hook(void *param);
void		ft_randomize(t_RData *r_d);

//psy_color.c
void		max_c_wrapper(void *param);
int			ft_max_c(int signal);
void		color_psy_hook(void *param);
void		ft_psy_flow(t_RData *r_d, int activity_status, int max_activity_status);

//colors.c
uint32_t	ft_color_from_seed(int iter, int max_iter);
uint32_t	ft_color_arr(int i);

//drawer.c
void		pixel_to_complex(t_Pix pixel, t_RData *r_d, double *real, double *imag);
void		draw_from_iter_counts(t_RData *r_d);
void		draw_set(t_RData *r_d);
void		place_color(t_RData *r_d, t_Pix pos);

//delayed-drawer.c
int			init_background_render(t_RData *r_d);
int			continue_background_render(t_RData *r_d);
void		complete_background_render(t_RData *r_d);
void		clear_background_render(t_RData *r_d);

//partial_render_basic.c
void		outer_render(t_RData *r_d, t_PixBox *rendered_pix);
void		buffer_segment(t_RData *r_d, t_PixBox *pixel_bounds);
void		draw_segment(t_RData *r_d, t_PixBox *pixel_bounds);

//shift_basic.c
void		shift_pixels_x_l(t_RData *r_d, int shift_offset);
void		shift_pixels_x_r(t_RData *r_d, int shift_offset);
void		shift_pixels_y_u(t_RData *r_d, int shift_offset);
void		shift_pixels_y_d(t_RData *r_d, int shift_offset);

//utils.c
t_PixBox	get_inner_box_from_bounds(t_RData *r_d);
t_PixBox	get_inner_box_from_pixels(t_RData *r_d, t_Pix cursor);

//atod.c
double		ft_atod(const char *nptr);

//check_input.c
int			check_input(int argc, char **argv);

//check_input_helpers.c
int			ft_isdouble(char *str);
int			ft_isint(char *str);

//resize.c
void		resize_window(int32_t width, int32_t height, void *param);

//show_inputs.c
void	show_inputs(void);
