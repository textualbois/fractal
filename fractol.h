
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/MLX42.h"
//#include "MLX42/MLX42_int.h"
#include "libft/libft.h"

#define other_task_present 0
//#define render_required 1
#define render_not_required 2

#define background_render_not_started 0
#define background_render_started 2
#define WIDTH 800
#define HEIGHT 800
#define BPP sizeof(int32_t)


typedef struct s_Pix{
    int x;
    int y;
}       t_Pix;

typedef struct s_DoublePair{
    double  x;
    double  y;
}           t_DoublePair;

typedef struct s_PixDouble{
    double  x;
    double  y;
}           t_PixDouble;

typedef struct s_Pix32{
    int32_t x;
    int32_t y;
}           t_Pix32;

typedef struct s_FractalBounds{
    double  min_r;
    double  max_r;
    double  min_i;
    double  max_i;
}           t_FractalBounds;

//pixels not to be re_drawn
typedef struct s_PixelBox{
    int left_x;
    int right_x;
    int top_y;
    int bottom_y;
}       t_PixelBox;

typedef struct s_RenderData{
    t_FractalBounds *bounds;
    t_FractalBounds bounds_temp;
    double          zoom;
    int             precision;
    int             Width;
    int             Height;

    int             block_render;
    bool            render_required;
    int             render_status;

    uint8_t         *buffer_pointer;
    uint8_t         *pixel_buffer;
    mlx_image_t     *image;
    t_DoublePair    *j_params;
    int             (*set_func)(double, double, int, void*);
}                   t_RenderData;

typedef struct s_W_R_D{
    mlx_t           *window;
    t_RenderData    *r_data;
}                   t_W_R_D;

//init.c
t_W_R_D *init_all(mlx_t *window, int func_id, int argc, char **argv);
//t_W_R_D *init_all(mlx_t *window, int (*set_func)(double, double, int, void*), void *param);
t_FractalBounds *init_FractalBounds(double min_r, double max_r, double min_i, double max_i);
t_RenderData *init_rData(t_FractalBounds *bounds, mlx_t *window, void *set_func, int precision);
t_W_R_D *init_W_R_D(mlx_t *window, t_RenderData *render_data);

//init_helper.c
t_RenderData *init_mandelbrot(mlx_t *window, int argc, char **argv);
t_RenderData *init_julia(mlx_t *window, int argc, char **argv);
t_RenderData *init_debug(mlx_t *window, int argc, char **argv);

//clear.c
void free_FractalBounds(t_FractalBounds *bounds);
void free_RenderData(t_RenderData *render_data);
void free_W_R_D(t_W_R_D *w_r_d);

/*
//zoom.c
void zoom_in(t_RenderData *r_d, int32_t cursor_x, int32_t cursor_y);
void zoom_out(t_RenderData *r_d, int32_t cursor_x, int32_t cursor_y);
void down_scale(t_RenderData *r_d, t_PixelBox box, double scale);
void ft_zoom(double x_delta, double y_delta, void *param);
*/

//zoom.c
void zoom_in(t_RenderData *r_d, t_Pix cursor);
void stretch(t_RenderData *r_d, t_PixelBox box, double scale_x, double scale_y);
void zoom_out(t_RenderData *r_d, t_Pix cursor);
void down_scale(t_RenderData *r_d, t_PixelBox box, double scale_x, double scale_y);
void ft_zoom(double x_delta, double y_delta, void *param);

//mover.c
void move_left(t_RenderData *r_d);
void move_right(t_RenderData *r_d);
void move_up(t_RenderData  *r_d);
void move_down(t_RenderData *r_d);

//loops_hooks.c
void    ft_exit_button(void *param);
bool    bounds_changed(const t_FractalBounds *old_bounds, const t_FractalBounds *new_bounds);
void    ft_image_shift(void *param);
void    init_loops_n_hooks(t_W_R_D *wrd);
void    background_render(void *param);

void ft_black_out_hook(void *param);

//set_functions.c
int mandelbrot(double real, double imag, int max_precision, void *param);
int julia(double real, double imag, int max_precision, void *param);

int debug_grid(double real, double imag, int max_precision, void *param);


//drawer.c
uint32_t ft_color_from_seed(int iter, int max_iter);
void pixel_to_complex(t_Pix pixel, t_RenderData *r_d, double *real, double *imag);
void draw_set(t_RenderData *r_d);
void black_out(t_W_R_D *w_r_d);

//delayed-drawer.c
int init_background_render(t_RenderData *r_d);
int continue_background_render(t_RenderData *r_d);
void complete_render(t_RenderData *r_d);
void    clear_background_render(t_RenderData *r_d);




//partial_render_basic.c
void outer_render(t_RenderData *r_d, t_PixelBox *rendered_pixels);
void buffer_segment(t_RenderData *r_d, t_PixelBox *pixel_bounds);
void draw_segment(t_RenderData *r_d, t_PixelBox *pixel_bounds);

//shift_basic.c
void    shift_pixels_x_l(t_RenderData *r_d, int shift_offset);
void    shift_pixels_x_r(t_RenderData *r_d, int shift_offset);
void    shift_pixels_y_u(t_RenderData *r_d, int shift_offset);
void    shift_pixels_y_d(t_RenderData *r_d, int shift_offset);

//utils.c
t_FractalBounds *copy_bounds(t_FractalBounds *src);
t_PixelBox get_inner_box_from_bounds(t_RenderData *r_d);
t_PixelBox get_inner_box_from_pixels(t_RenderData *r_d, t_Pix cursor);


//resize.c
void    resize_window(int32_t width, int32_t height, void *param);
