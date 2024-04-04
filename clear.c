#include "./fractol.h"

void free_FractalBounds(t_FractalBounds *bounds)
{
    free(bounds);
}

// Function to free memory allocated for RenderData struct
void free_RenderData(t_RenderData *render_data)
{
    free(render_data->bounds);  // Free the FractalBounds within RenderData
    clear_background_render(render_data);   // Clear background image data
    free(render_data);
}

// Function to free memory allocated for W_R_D struct
void free_W_R_D(t_W_R_D *w_r_d)
{
    free_RenderData(w_r_d->r_data);  // Free the RenderData within W_R_D
    free(w_r_d);
}