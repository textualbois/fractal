NAME = fractol

SRCS_NAME = fractol.c init.c init_helper.c clear.c zoom.c mover.c loops_hooks.c \
			drawer.c set_functions.c check_input.c check_input_helpers.c atod.c\
			shift_basic.c partial_render_basic.c utils.c delayed_drawer.c resize.c\
			colors2.c color_shift.c color_static.c init_img_meta.c psy_color.c\
			show_inputs.c mover_quick.c draw_router.c julia_shift.c zoom_helpers.c
SRCS_PATH = ./
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

MLX_PATH = ./MLX42/
MLX_INCL = -I $(MLX_PATH)include
MLX = $(MLX_PATH)build/libmlx42.a

LIBFT_PATH = ./libft/
LIBFT_INCL = -I $(LIBFT_PATH)
LIBFT_LIB = $(LIBFT_PATH)libft.a

FT_PRINTF_PATH = ./ft_printf/
FT_PRINTF_INCL = -I $(FT_PRINTF_PATH)
FT_PRINTF_LIB = $(FT_PRINTF_PATH)ft_printf.a

MLX_LIB = -L$(MLX_PATH)build -lmlx42
#GLFW_LIB = -L"/usr/local/Cellar/glfw/3.3.9/lib/" -lglfw
#GLFW_LIB = -L"/usr/local/Cellar/glfw/3.4/lib/" -lglfw
GLFW_LIB = -L"/Users/isemin/.brew/Cellar/glfw/3.4" -lglfw
#LSAN_LIB = -L"/Users/isemin/Documents/all_study/LeakSanitizer" -llsan
LIBS = $(MLX_LIB) $(GLFW_LIB) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf -lm

FRAMEWORKS = -framework OpenGL -framework IOKit -framework AppKit
DEPENDENCIES = $(LIBS) $(FRAMEWORKS)

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS_NAME:.c=.o))

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

all: $(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX) $(NAME)
	@echo "all DONE"

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)
	@echo "LIBFT DONE"

$(FT_PRINTF_LIB):
	@make -C $(FT_PRINTF_PATH)
	@echo "FT_PRINTF DONE"

$(MLX):
	@cmake $(MLX_PATH) -B $(MLX_PATH)/build && make -C $(MLX_PATH)/build -j4
	@echo "MLX DONE"

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DEPENDENCIES) -o $(NAME)
	@echo "NAME DONE"

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) $(MLX_INCL) -c $< -o $@
	@echo "o:c DONE"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "OBJ_DIR DONE"

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FT_PRINTF_PATH)
	@echo "CLEAN DONE"

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_PATH)build
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(FT_PRINTF_PATH)
	@echo "fclean DONE"

re: fclean all
	@echo "re DONE"

.PHONY: all clean fclean re
